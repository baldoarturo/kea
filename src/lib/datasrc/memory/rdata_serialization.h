// Copyright (C) 2012  Internet Systems Consortium, Inc. ("ISC")
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

#ifndef DATASRC_MEMORY_RDATA_ENCODER_H
#define DATASRC_MEMORY_RDATA_ENCODER_H 1

#include <exceptions/exceptions.h>

#include <dns/labelsequence.h>
#include <dns/rdata.h>
#include <dns/rrclass.h>
#include <dns/rrtype.h>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

#include <vector>

namespace isc {
namespace datasrc {
namespace memory {

/// \brief General error in RDATA encoding.
///
/// This is thrown when \c RdataEncoder encounters a rare, unsupported
/// situation. a method is called for a name or RRset which
/// is not in or below the zone.
class RdataEncodingError : public Exception {
public:
    RdataEncodingError(const char* file, size_t line, const char* what) :
        Exception(file, line, what) {}
};

/// \brief RDATA encoder.
///
/// This class provides interfaces to encode a set of RDATA of a specific
/// RR class and type, possibly with their RRSIG RDATAs, in a memory-efficient
/// format.  In many cases these sets of RDATA come from a specific (signed
/// or unsigned) RRset.
///
/// It is expected for a single \c RdataEncoder object to be used multiple
/// times for different sets of RDATA, such as in loading an entire zone
/// into memory.  Each encoding session begins with the \c start() method,
/// which sets the context for the specific RR class and type to be encoded.
/// Any number of calls to \c addRdata() or \c addSIGRdata() follow, each
/// of which updates the internal state of the encoder with the encoding
/// information for the given RDATA or RRSIG RDATA, respectively.
/// The \c addRdata() is expected to be called with an
/// \c isc::dns::rdata::Rdata object
/// of the specified class and type, and \c addRdata() checks the consistency
/// for the purpose of encoding (but it's not completely type safe; for
/// example, it wouldn't distinguish TXT RDATA and HINFO RDATA.
/// Likewise, an \c isc::dns::rdata::Rdata given to \c addSIGRdata() is
/// expected to be of RRSIG, but the method does not check the assumption).
///
/// After passing the complete set of RDATA and their RRSIG, the application
/// is expected to call \c getStorageLength() to know the size of storage
/// that is sufficient to store all encoded data.  Normally the application
/// would allocate a memory region of that size, and then call \c encode()
/// with the prepared region.  The \c encode() method dumps encoded data
/// to the given memory region.
///
/// The caller can reuse the \c RdataEncoder object for another set of RDATA
/// by repeating the session from \c start().
class RdataEncoder : boost::noncopyable {
public:
    /// \brief Default constructor.
    RdataEncoder();

    /// \brief The destrcutor.
    ~RdataEncoder();

    /// \brief Start the encoding session.
    ///
    /// It re-initializes the internal encoder state for a new encoding
    /// session.  The \c rrclass and \c rrtype parameters specify the
    /// type of RDATA to be encoded in the new session.  Note that if the
    /// set of RDATA is signed, \c rrtype always specifies the "signed" type;
    /// it must not be RRSIG.
    ///
    /// \throw BadValue RRSIG is specified for rrtype.
    ///
    /// \param rrclass The RR class of RDATA to be encoded in the session.
    /// \param rrtype The RR type of RDATA to be encoded in the session.
    void start(dns::RRClass rrclass, dns::RRType rrtype);

    /// \brief Add an RDATA for encoding.
    ///
    /// This method updates internal state of the \c RdataEncoder() with the
    /// given RDATA so it will be part of the encoded data in a subsequent
    /// call to \c encode().
    ///
    /// The given \c rdata must be of the RR class and type specified at
    /// the prior call to \c start().  This method checks the assumption
    /// to some extent, but the check is not complete; this is generally
    /// the responsibility of the caller.
    ///
    /// The caller can destroy \c rdata after this call is completed.
    ///
    /// \note This implementation does not support RDATA (or any subfield of
    /// it) whose size exceeds 65535 bytes (max uint16_t value).  Such RDATA
    /// may not necessarily be considered invalid in terms of protocol
    /// specification, but in practice it's mostly useless because the
    /// corresponding RR won't fit in any valid DNS message.
    ///
    /// As long as the \c rdata is of the correct type and its size is normal,
    /// this method should normally be exception free.  If it throws, however,
    /// it doesn't always provide the strong exception guarantee.  In general,
    /// the caller needs to either destroy the encoder object or restart a
    /// new session from \c start() should this method throws an exception.
    ///
    /// \throw InvalidOperation called before start().
    /// \throw BadValue inconsistent data found.
    /// \throw RdataEncodingError A very unusual case, such as over 64KB RDATA.
    /// \throw std::bad_alloc Internal memory allocation failure.
    ///
    /// \param rdata An RDATA to be encoded in the session.
    void addRdata(const dns::rdata::Rdata& rdata);

    /// \brief Add an RRSIG RDATA for encoding.
    ///
    /// This method updates internal state of the \c RdataEncoder() with the
    /// given RDATA, which is assumed to be of type RRSIG that covers the
    /// type specified at the time of \c start() for the encoding session.
    /// The corresponding data for the RRSIG RDATA will be encoded in a
    /// subsequent call to \c encode().
    ///
    /// The passed \c sig_rdata is expected to be of type RRSIG and cover
    /// the RR type specified at the call to \c start() to this encoding
    /// session.  But this method does not check if it is the case at all;
    /// it could even accept any type of RDATA as opaque data.  It's caller's
    /// responsibility to ensure the assumption.
    ///
    /// The caller can destroy \c rdata after this call is completed.
    ///
    /// \note Like addRdata(), this implementation does not support
    /// RRSIG RDATA whose size (in the form of wire format) exceeds 65535
    /// bytes.
    ///
    /// The same note about exception safety as \c addRdata() applies.
    ///
    /// \throw InvalidOperation called before start().
    /// \throw RdataEncodingError A very unusual case, such as over 64KB RDATA.
    /// \throw std::bad_alloc Internal memory allocation failure.
    ///
    /// \param sig_rdata An RDATA to be encoded in the session.  Supposed to
    /// be of type RRSIG.
    void addSIGRdata(const dns::rdata::Rdata& sig_rdata);

    /// \brief Return the length of space for encoding for the session.
    ///
    /// It returns the size of the encoded data that would be generated for
    /// the set of RDATA (and RRSIGs) in the encoder at the call of this
    /// method.  It's ensured that a buffer of that size can be safely passed
    /// to \c encode() unless there's no other "add" method is called by then.
    ///
    /// As long as this method is called after start(), it never throws.
    ///
    /// \throw InvalidOperation called before start().
    ///
    /// \return The expected size of the encoded data at the time of the call.
    size_t getStorageLength() const;

    /// \brief Encode RDATAs of the session to a buffer.
    ///
    /// This method dumps encoded data for the stored set of RDATA and
    /// their RRSIGs to a given buffer.  The buffer must have a size
    /// at least as large as the return value of a prior call to
    /// \c getStorageLength() (it may be larger than that).
    ///
    /// The given buffer must be aligned at the natural boundary for
    /// 16-bit integers.  The method doesn't check this condition; it's
    /// caller's responsibility to ensure that.  Note: the alignment
    /// requirement may change in a future version of this implementation.
    ///
    /// As long as this method is called after start() and the buffer is
    /// valid with a sufficient size, this method never throws.
    ///
    /// \throw InvalidOperation called before start().
    /// \throw BadValue buffer is NULL or it's too short for the encoded data.
    ///
    /// \param buf A pointer to the buffer to which encoded data are to be
    /// dumped.
    /// \param buf_len The size of the buffer in bytes.
    void encode(void* buf, size_t buf_len) const;

private:
    struct RdataEncoderImpl;
    RdataEncoderImpl* impl_;
};

/// \brief Attributes of domain name fields of encoded RDATA.
///
/// The enum values define special traits of the name that can affect how
/// it should be handled in rendering or query processing.
enum RdataNameAttributes {
    NAMEATTR_NONE = 0,          ///< No special attributes
    NAMEATTR_COMPRESSIBLE = 1,  ///< Name should be compressed when rendered
    NAMEATTR_ADDITIONAL = (NAMEATTR_COMPRESSIBLE << 1) ///< Name requires
                                                      ///< Additional section
                                                      ///< handling
};

class RdataEncodeSpec;

/// \brief Class to read serialized rdata
///
/// This class allows you to read the data encoded by RdataEncoder.
/// It is rather low-level -- it provides sequence of data fields.
/// Each field is either opaque data, passed as a pointer and length,
/// or a name, in the form of dns::LabelSequence (which is always
/// absolute) and attributes.
///
/// Conceptually, these fields correspond to consecutive regions in
/// wire-format representation of the RDATA, varying the type of above
/// two cases depending on whether the region corresponds to a domain
/// name or other data.  For example, for an MX RDATA the field
/// sequence will be
/// - 2 bytes of opaque data (which corresponds to the MX preference)
/// - a domain name (which corresponds to the MX name)
///
/// If the encoded data contain multiple MX RDATAs, the same type of
/// sequence continues for the number of RDATAs.  Note that the opaque
/// data field does not always corresponds to a specific RDATA field
/// as is the 2-byte preference field of MX.  For example, the field
/// sequence for an SOA RDATA in terms of RdataEncoder will be:
/// - a domain name (which corresponds to the SOA MNAME)
/// - a domain name (which corresponds to the SOA RNAME)
/// - 20 bytes of opaque data (for the rest of fields)
///
/// So, if you want to construct a general purpose dns::Rdata object
/// from the field sequence, you'll need to build the complete
/// wire-format data, and then construct a dns::Rdata object from it.
///
/// To use it, contstruct it with the data you got from RDataEncoder,
/// provide it with callbacks and then iterate through the data.
/// The callbacks are called with the data fields contained in the
/// data.
///
/// \code
/// void handleName(const dns::LabelSequence& labels, unsigned int flags) {
///     ...
/// }
/// void handleData(const void* data, size_t size) {
///     ...
/// }
///
/// RdataReader reader(RRClass::IN(), RRType::AAAA(), size, data,
///                    &handleName, &handleData);
/// reader.iterate();
/// \endcode
///
/// \note It is caller's responsibility to pass valid data here. This means
///     the data returned by RdataEncoder and the corresponding class and type.
///     If this is not the case, all the kinds of pointer hell might get loose.
class RdataReader {
public:
    /// \brief Function called on each name encountered in the data.
    typedef boost::function<void(const dns::LabelSequence&,
                                 RdataNameAttributes)> NameAction;
    /// \brief Function called on each data field in the data.
    typedef boost::function<void(const void*, size_t)> DataAction;

    /// \brief Constructor
    ///
    /// This constructs the reader on top of some serialized data.
    /// It does not copy the data, you have to make sure the data
    /// is valid for the whole life of this object and that they
    /// don't change.
    ///
    /// \param rrclass The class the encoded rdata belongs to.
    /// \param rrtype The type of the encode rdata.
    /// \param data The actual data.
    /// \param rdata_count The number of Rdata encoded in the data.
    /// \param sig_count The number of RRSig rdata bundled with the data.
    /// \param name_action The callback to be called on each encountered name.
    /// \param data_action The callback to be called on each data chunk.
    RdataReader(const dns::RRClass& rrclass, const dns::RRType& rrtype,
                const void* data, size_t rdata_count, size_t sig_count,
                const NameAction& name_action, const DataAction& data_action);

    /// \brief Result of next() and nextSig()
    ///
    /// This specifies if there's any boundary in the data at the
    /// place where the corresponding call to next() or nextSig()
    /// finished.
    enum Boundary {
        NO_BOUNDARY,    ///< It is in the middle of Rdata
        RDATA_BOUNDARY, ///< At the end of single Rdata
        RRSET_BOUNDARY  ///< At the end of the RRset (past the end)
    };

    /// \brief Step to next data field.
    ///
    /// Iterate over the next field and call appropriate hook (name_action
    /// or data_action, depending on the type) as passed to the constructor.
    ///
    /// \return It returns NO_BOUNDARY if the next call to next() will process
    ///     data of the same rdata as this one. RDATA_BOUNDARY is returned when
    ///     this field is the last of the current rdata. If there are no more
    ///     data to process, no hook is called and RRSET_BOUNDARY is returned.
    ///     Therefore, at the end of the whole data, once it processes the last
    ///     field and returns RDATA_BOUNDARY and then it returns RRSET_BOUNDARY
    ///     on the next call.
    Boundary next();

    /// \brief Call next() until the end.
    ///
    /// This is just convenience method to iterate through all the data.
    /// It calls next until it reaches the end (it does not rewind beforehand,
    /// therefore if you already called next() yourself, it does not start
    /// at the beginning).
    void iterate() {
        while (nextInternal(name_action_, data_action_) != RRSET_BOUNDARY) {}
    }

    /// \brief Call next() until the end of current rdata.
    ///
    /// This is a convenience method to iterate until the end of current
    /// rdata. Notice this may cause more than one field being processed,
    /// as some rrtypes are more complex.
    ///
    /// \return If there was Rdata to iterate through.
    bool iterateRdata() {
        while (true) {
            switch (nextInternal(name_action_, data_action_)) {
                case NO_BOUNDARY: break;
                case RDATA_BOUNDARY: return (true);
                case RRSET_BOUNDARY: return (false);
            }
        }
    }

    /// \brief Step to next field of RRSig data.
    ///
    /// This is almost the same as next(), but it iterates through the
    /// associated RRSig data, not the data for the given RRType.
    Boundary nextSig();

    /// \brief Iterate through all RRSig data.
    ///
    /// This is almost the same as iterate(), but it iterates through the
    /// RRSig data instead.
    void iterateAllSigs() {
        while (nextSig() != RRSET_BOUNDARY) {}
    }

    /// \brief Iterate through the current RRSig Rdata.
    ///
    /// This is almote the same as iterateRdata, except it is for single
    /// signature Rdata.
    ///
    /// In practice, this should process one DATA field.
    bool iterateSingleSig() {
        while (true) {
            switch (nextSig()) {
                case NO_BOUNDARY:
                    isc_throw(isc::Unexpected, "NO_BOUNDARY inside an RRSig. "
                              "Data corruption? Bug inside RdataReader?");
                case RDATA_BOUNDARY: return (true);
                case RRSET_BOUNDARY: return (false);
            }
        }
    }

    /// \brief Rewind the iterator to the beginnig of data.
    ///
    /// The following next() and nextSig() will start iterating from the
    /// beginning again.
    void rewind();

    /// \brief Returns the size of associated data.
    ///
    /// This should be the same as the return value of
    /// RdataEncoder::getStorageLength() for the same set of data.
    /// The intended use of this method is to tell the caller the size of
    /// data that were possibly dynamically allocated so that the caller can
    /// use it for deallocation.
    ///
    /// This method only uses the parameters given at the construction of the
    /// object, and does not rely on or modify other mutable states.
    /// In practice, when the caller wants to call this method, that would be
    /// the only purpose of that RdataReader object (although it doesn't have
    /// to be so).
    size_t getSize() const;
private:
    const NameAction name_action_;
    const DataAction data_action_;
    const RdataEncodeSpec& spec_;
    // Total number of var-length fields, count of signatures
    const size_t var_count_total_, sig_count_, spec_count_;
    // Pointer to the beginning of length fields
    const uint16_t* const lengths_;
    // Pointer to the beginning of the data (after the lengths)
    const uint8_t* const data_;
    // Pointer to the first data signature
    // Will be computed during the normal RR iteration
    const uint8_t* sigs_;
    // The positions in data.
    size_t data_pos_, spec_pos_, length_pos_;
    size_t sig_pos_, sig_data_pos_;
    Boundary nextInternal(const NameAction& name_action,
                          const DataAction& data_action);
};

} // namespace memory
} // namespace datasrc
} // namespace isc

#endif // DATASRC_MEMORY_RDATA_ENCODER_H

// Local Variables:
// mode: c++
// End:
