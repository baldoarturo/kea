// Copyright (C) 2011  Internet Systems Consortium, Inc. ("ISC")
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#include <config.h>

#include <unistd.h>             // for some IPC/network system calls
#include <sys/socket.h>
#include <netinet/in.h>

#include <boost/bind.hpp>
#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <dns/message.h>
#include <dns/messagerenderer.h>
#include <dns/opcode.h>
#include <dns/rcode.h>
#include <log/dummylog.h>
#include <log/logger.h>

#include <asio.hpp>
#include <asio/deadline_timer.hpp>

#include <asiolink/asiodef.h>
#include <asiolink/io_address.h>
#include <asiolink/io_asio_socket.h>
#include <asiolink/io_endpoint.h>
#include <asiolink/io_fetch.h>
#include <asiolink/io_service.h>
#include <asiolink/tcp_endpoint.h>
#include <asiolink/tcp_socket.h>
#include <asiolink/udp_endpoint.h>
#include <asiolink/udp_socket.h>

using namespace asio;
using namespace isc::dns;
using namespace isc::log;
using namespace std;

namespace asiolink {

/// Use the ASIO logger

isc::log::Logger logger("asio");

/// \brief IOFetch Data
///
/// The data for IOFetch is held in a separate struct pointed to by a
/// shared_ptr object.  This is because the IOFetch object will be copied
/// often (it is used as a coroutine and passed as callback to many
/// async_*() functions) and we want keep the same data).  Organising the
/// data in this way keeps copying to a minimum.
struct IOFetchData {

    // The first two members are shared pointers to a base class because what is
    // actually instantiated depends on whether the fetch is over UDP or TCP,
    // which is not known until construction of the IOFetch.  Use of a shared
    //pointer here is merely to ensure deletion when the data object is deleted.
    boost::shared_ptr<IOAsioSocket<IOFetch> > socket;
                                            ///< Socket to use for I/O
    boost::shared_ptr<IOEndpoint> remote;   ///< Where the fetch was sent
    isc::dns::Question          question;   ///< Question to be asked
    isc::dns::OutputBufferPtr   msgbuf;     ///< Wire buffer for question
    isc::dns::OutputBufferPtr   buffer;     ///< Received data held here
    boost::shared_array<char>   data;       ///< Temporary array for data
    IOFetch::Callback*          callback;   ///< Called on I/O Completion
    size_t                      cumulative; ///< Cumulative received amount
    bool                        stopped;    ///< Have we stopped running?
    asio::deadline_timer        timer;      ///< Timer to measure timeouts
    int                         timeout;    ///< Timeout in ms
    IOFetch::Origin             origin;     ///< Origin of last asynchronous I/O

    /// \brief Constructor
    ///
    /// Just fills in the data members of the IOFetchData structure
    ///
    /// \param protocol Either IOFetch::TCP or IOFetch::UDP
    /// \param service I/O Service object to handle the asynchronous
    ///     operations.
    /// \param query DNS question to send to the upstream server.
    /// \param address IP address of upstream server
    /// \param port Port to use for the query
    /// \param buff Output buffer into which the response (in wire format)
    ///     is written (if a response is received).
    /// \param cb Callback object containing the callback to be called
    ///     when we terminate.  The caller is responsible for managing this
    ///     object and deleting it if necessary.
    /// \param wait Timeout for the fetch (in ms).
    ///
    /// TODO: May need to alter constructor (see comment 4 in Trac ticket #554)
    IOFetchData(IOFetch::Protocol protocol, IOService& service,
        const isc::dns::Question& query, const IOAddress& address,
        uint16_t port, isc::dns::OutputBufferPtr& buff, IOFetch::Callback* cb,
        int wait)
        :
        socket((protocol == IOFetch::UDP) ?
            static_cast<IOAsioSocket<IOFetch>*>(
                new UDPSocket<IOFetch>(service)) :
            static_cast<IOAsioSocket<IOFetch>*>(
                new TCPSocket<IOFetch>(service))
            ),
        remote((protocol == IOFetch::UDP) ?
            static_cast<IOEndpoint*>(new UDPEndpoint(address, port)) :
            static_cast<IOEndpoint*>(new TCPEndpoint(address, port))
            ),
        question(query),
        msgbuf(new isc::dns::OutputBuffer(512)),
        buffer(buff),
        data(new char[IOFetch::MIN_LENGTH]),
        callback(cb),
        cumulative(0),
        stopped(false),
        timer(service.get_io_service()),
        timeout(wait),
        origin(IOFetch::NONE)
    {}
};


/// IOFetch Constructor - just initialize the private data

IOFetch::IOFetch(Protocol protocol, IOService& service,
    const isc::dns::Question& question, const IOAddress& address, uint16_t port,
    OutputBufferPtr& buff, Callback* cb, int wait)
    :
    data_(new IOFetchData(protocol, service, question, address,
        port, buff, cb, wait))
{
}

/// The function operator is implemented with the "stackless coroutine"
/// pattern; see internal/coroutine.h for details.

void
IOFetch::operator()(asio::error_code ec, size_t length) {
    std::cerr << "IOFetch::operator() [" << this << "], origin = " <<
        data_->origin << ", coroutine = " << get_value() << "\n";
    if (data_->stopped) {
        return;
    } else if (ec) {
        logIOFailure(ec);
        return;
    }

    CORO_REENTER (this) {

        /// Generate the upstream query and render it to wire format
        /// This is done in a different scope to allow inline variable
        /// declarations.
        {
            Message msg(Message::RENDER);
            
            // TODO: replace with boost::random or some other suitable PRNG
            msg.setQid(0);
            msg.setOpcode(Opcode::QUERY());
            msg.setRcode(Rcode::NOERROR());
            msg.setHeaderFlag(Message::HEADERFLAG_RD);
            msg.addQuestion(data_->question);
            MessageRenderer renderer(*data_->msgbuf);
            msg.toWire(renderer);

            // As this is a new fetch, clear the amount of data received
            data_->cumulative = 0;

            dlog("Sending " + msg.toText() + " to " +
                data_->remote->getAddress().toText());
        }

        // If we timeout, we stop, which will shutdown everything and
        // cancel all other attempts to run inside the coroutine
        if (data_->timeout != -1) {
            data_->timer.expires_from_now(boost::posix_time::milliseconds(
                data_->timeout));
            data_->timer.async_wait(boost::bind(&IOFetch::stop, *this,
                TIME_OUT));
        }

        // Open a connection to the target system.  For speed, if the operation
        // was completed synchronously (i.e. UDP operation) we bypass the yield.
        
        data_->origin = OPEN;
        if (data_->socket->isOpenSynchronous()) {
            std::cerr << "IOFetch: Opening socket synchronously\n";
            data_->socket->open(data_->remote.get(), *this);
        } else {
            std::cerr << "IOFetch: Opening socket asynchronously and yeilding\n";
            CORO_YIELD data_->socket->open(data_->remote.get(), *this);
            std::cerr << "IOFetch: Resuming after Opening socket asynchronously\n";
        }

        // Begin an asynchronous send, and then yield.  When the send completes
        // send completes, we will resume immediately after this point.
        // Note: A TCP message may not be sent in one piece (depends on the
        // implementation in TCP socket).  Therefore there may be
        data_->origin = SEND;
        std::cerr << "IOFetch: asynchronous send\n";
        CORO_YIELD data_->socket->asyncSend(data_->msgbuf->getData(),
            data_->msgbuf->getLength(), data_->remote.get(), *this);
        std::cerr << "IOFetch: resuming after asynchronous send\n";
        // Now receive the response.  Since TCP may not receive the entire
        // message in one operation, we need to loop until we have received
        // it. (This can't be done within the asyncReceive() method because
        // each I/O operation will be done asynchronously and between each one
        // we need to yield ... and we *really* don't want to set up another
        // coroutine within that method.)  So after each receive (and yield),
        // we check if the operation is complete and if not, loop to read again.
        data_->origin = RECEIVE;
        do {
            std::cerr << "IOFetch: asynchronous receive\n";
            CORO_YIELD data_->socket->asyncReceive(data_->data.get(),
                static_cast<size_t>(MIN_LENGTH), data_->cumulative,
                data_->remote.get(), *this);
             std::cerr << "IOFetch: resuming after asynchronous receive\n";
        } while (!data_->socket->receiveComplete(data_->data.get(), length,
            data_->cumulative));

        // The message is not rendered yet, so we can't print it easily
        dlog("Received response from " + data_->remote->getAddress().toText());

        /// Copy the answer into the response buffer.  (TODO: If the
        /// OutputBuffer object were made to meet the requirements of
        /// a MutableBufferSequence, then it could be written to directly
        /// by async_receive_from() and this additional copy step would
        /// be unnecessary.)
        data_->buffer->writeData(data_->data.get(), length);

        // Finished with this socket, so close it.
        data_->origin = CLOSE;
        std::cerr << "IOFetch: close\n";
        data_->socket->close();

        /// We are done
        stop(SUCCESS);
    }
}

// Function that stops the coroutine sequence.  It is called either when the
// query finishes or when the timer times out.  Either way, it sets the
// "stopped_" flag and cancels anything that is in progress.
//
// As the function may be entered multiple times as things wind down, the
// stopped_ flag checks if stop() has already been called.  If it has,
// subsequent calls are no-ops.

void
IOFetch::stop(Result result) {

    if (!data_->stopped) {

        // Mark the fetch as stopped to prevent other completion callbacks
        // (invoked because of the calls to cancel()) from executing the
        // cancel calls again.
        //
        // In a single threaded environment, the callbacks won't be invoked
        // until this one completes. In a multi-threaded environment, they may
        // well be, in which case the testing (and setting) of the stopped_
        // variable should be done inside a mutex (and the stopped_ variable
        // declared as "volatile").
        //
        // The numeric arguments indicate the debug level, with the lower
        // numbers indicating the most important information.  The relative
        // values are somewhat arbitrary.
        //
        // Although Logger::debug checks the debug flag internally, doing it
        // below before calling Logger::debug avoids the overhead of a string
        // conversion in the common paths and in the common case when debug is
        // not enabled.
        //
        // TODO: Update testing of stopped_ if threads are used.
        data_->stopped = true;

        switch (result) {
            case TIME_OUT:
                if (logger.isDebugEnabled(1)) {
                    logger.debug(1, ASIO_RECVTMO,
                                 data_->remote->getAddress().toText().c_str());
                }
                break;

            case SUCCESS:
                if (logger.isDebugEnabled(50)) {
                    logger.debug(50, ASIO_FETCHCOMP,
                                 data_->remote->getAddress().toText().c_str());
                }
                break;

            case STOPPED:
                // Fetch has been stopped for some other reason.  This is
                // allowed but as it is unusual it is logged, but with a lower
                // debug level than a timeout (which is totally normal).
                logger.debug(10, ASIO_FETCHSTOP,
                             data_->remote->getAddress().toText().c_str());
                break;

            default:
                logger.error(ASIO_UNKRESULT, static_cast<int>(result),
                             data_->remote->getAddress().toText().c_str());
        }

        // Stop requested, cancel and I/O's on the socket and shut it down,
        // and cancel the timer.
        data_->socket->cancel();
        data_->socket->close();

        data_->timer.cancel();

        // Execute the I/O completion callback (if present).
        if (data_->callback) {
            (*(data_->callback))(result);
        }

        // Mark that stop() has now been called.

    }
}

// Log an error - called on I/O failure

void IOFetch::logIOFailure(asio::error_code ec) {

    // Get information that will be in all messages
    static const char* PROTOCOL[2] = {"TCP", "UDP"};
    const char* prot = (data_->remote->getProtocol() == IPPROTO_TCP) ?
                        PROTOCOL[0] : PROTOCOL[1];

    int errcode = ec.value();

    std::string str_address = data_->remote->getAddress().toText();
    const char* address = str_address.c_str();

    switch (data_->origin) {
    case OPEN:
        logger.error(ASIO_OPENSOCK, errcode, prot, address);
        break;

    case SEND:
        logger.error(ASIO_SENDSOCK, errcode, prot, address);
        break;

    case RECEIVE:
        logger.error(ASIO_RECVSOCK, errcode, prot, address);
        break;

    default:
        logger.error(ASIO_UNKORIGIN, errcode, prot, address);
    }
}

} // namespace asiolink

