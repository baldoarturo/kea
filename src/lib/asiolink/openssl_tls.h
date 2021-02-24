// Copyright (C) 2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENSSL_TLS_H
#define OPENSSL_TLS_H

#ifdef WITH_OPENSSL

#include <asiolink/asio_wrapper.h>
#include <asiolink/io_asio_socket.h>
#include <asiolink/io_service.h>

#include <boost/asio/ssl.hpp>

namespace isc {
namespace asiolink {

/// @brief OpenSSL TLS context.
class TlsContext : public TlsContextBase {
public:

    /// @brief Destructor.
    virtual ~TlsContext() { }

    /// @brief Create a fresh context.
    ///
    /// @param role The TLS role client or server.
    explicit TlsContext(TlsRole role);

    /// @brief Return a reference to the underlying context.
    ///
    /// Boost ASIO uses a move constructor which "eats" the context,
    /// this updates the OpenSSL reference count so the object is not freed.
    boost::asio::ssl::context& getContext();

    /// @brief Return the pointer to the SSL_CTX object.
    ///
    /// Currently used only for tests. Please note that since OpenSSL 1.1
    /// The SSL_CTX type is not fully publicly defined.
    ::SSL_CTX* getNativeContext();

    /// @brief Set the peer certificate requirement mode.
    ///
    /// @param cert_required True if peer certificates are required,
    /// false if they are optional.
    virtual void setCertRequired(bool cert_required);

    /// @brief Get the peer certificate requirement mode.
    ///
    /// @return True if peer certificates are required, false if they
    /// are optional.
    virtual bool getCertRequired() const;

    /// @brief Load the trust anchor aka certificate authority.
    ///
    /// @param ca_file The certificate file name.
    virtual void loadCaFile(const std::string& ca_file);

    /// @brief Load the trust anchor aka certificate authority.
    ///
    /// @param ca_path The certificate directory name.
    virtual void loadCaPath(const std::string& ca_path);

    /// @brief Load the certificate file.
    ///
    /// @param cert_file The certificate file name.
    virtual void loadCertFile(const std::string& cert_file);

    /// @brief Load the private key file name.
    ///
    /// @param key_file The private key file name.
    virtual void loadKeyFile(const std::string& key_file);

protected:
    /// @brief Cached cert_required value.
    bool cert_required_;

    /// @brief Boost ASIO SSL object.
    boost::asio::ssl::context context_;
};

/// @brief The type of shared pointers to TlsContext objects.
///
/// @note Not clear we need shared pointers but they covers more use cases...
typedef boost::shared_ptr<TlsContext> TlsContextPtr;

/// @brief The type of underlying TLS streams.
typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> TlsStreamImpl;

/// @brief The type of X509 certificates.
typedef ::X509 TlsCertificate;

/// @brief OpenSSL TLS stream.
///
/// @param callback The callback.
template <typename Callback>
class TlsStream : public TlsStreamImpl {
public:

    /// @brief Constructor.
    ///
    /// @param service I/O Service object used to manage the stream.
    /// @param context Pointer to the TLS context.
    /// @note The caller must not provide a null pointer to the TLS context.
    TlsStream(IOService& service, TlsContextPtr context)
        : TlsStreamImpl(service.get_io_service(), context->getContext()),
          role_(context->role_) {
    }

    /// @brief Destructor.
    virtual ~TlsStream() { }

    /// @brief Handshake.
    ///
    virtual void handshake(Callback& callback) {
        using namespace boost::asio::ssl;
        if (role_ == SERVER) {
            async_handshake(stream_base::server, callback);
        } else {
            async_handshake(stream_base::client, callback);
        }
    }

    /// @brief Clear the SSL object.
    virtual void clear() {
        static_cast<void>(::SSL_clear(this->native_handle()));
    }

    /// @brief Return the peer certificate.
    ///
    /// @note The native_handle() method is used so it can't be made const.
    /// @note Do not forget to free it when no longer used.
    virtual TlsCertificate* getPeerCert() {
        return (::SSL_get_peer_certificate(this->native_handle()));
    }

    /// @brief The role i.e. client or server.
    TlsRole role_;

    /// @break Return the commonName part of the subjectName of
    /// the peer certificate.
    ///
    /// First commonName when there are more than one, in UTF-8.
    ///
    /// @return The commonName part of the subjectName or the empty string.
    std::string getSubject() {
        TlsCertificate* cert = getPeerCert();
        if (!cert) {
            return ("");
        }
        ::X509_NAME *name = ::X509_get_subject_name(cert);
        int loc = ::X509_NAME_get_index_by_NID(name, NID_commonName, -1);
        ::X509_NAME_ENTRY* ne = ::X509_NAME_get_entry(name, loc);
        if (!ne) {
            ::X509_free(cert);
            return ("");
        }
        unsigned char* buf = 0;
        int len = ::ASN1_STRING_to_UTF8(&buf, ::X509_NAME_ENTRY_get_data(ne));
        if (len < 0) {
            ::X509_free(cert);
            return ("");
        }
        std::string ret(reinterpret_cast<char*>(buf), static_cast<size_t>(len));
        ::OPENSSL_free(buf);
        ::X509_free(cert);
        return (ret);
    }

    /// @break Return the commonName part of the issuerName of
    /// the peer certificate.
    ///
    /// First commonName when there are more than one, in UTF-8.
    ///
    /// @return The commonName part of the issuerName or the empty string.
    std::string getIssuer() {
        TlsCertificate* cert = getPeerCert();
        if (!cert) {
            return ("");
        }
        ::X509_NAME *name = ::X509_get_issuer_name(cert);
        int loc = ::X509_NAME_get_index_by_NID(name, NID_commonName, -1);
        ::X509_NAME_ENTRY* ne = ::X509_NAME_get_entry(name, loc);
        if (!ne) {
            ::X509_free(cert);
            return ("");
        }
        unsigned char* buf = 0;
        int len = ::ASN1_STRING_to_UTF8(&buf, ::X509_NAME_ENTRY_get_data(ne));
        if (len < 0) {
            ::X509_free(cert);
            return ("");
        }
        std::string ret(reinterpret_cast<char*>(buf), static_cast<size_t>(len));
        ::OPENSSL_free(buf);
        ::X509_free(cert);
        return (ret);
    }
};

} // namespace asiolink
} // namespace isc

#endif // WITH_OPENSSL

#endif // OPENSSL_TLS_H
