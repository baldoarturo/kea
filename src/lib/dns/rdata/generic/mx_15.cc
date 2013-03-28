// Copyright (C) 2010  Internet Systems Consortium, Inc. ("ISC")
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

#include <string>

#include <boost/lexical_cast.hpp>

#include <exceptions/exceptions.h>

#include <util/buffer.h>
#include <dns/name.h>
#include <dns/messagerenderer.h>
#include <dns/rdata.h>
#include <dns/rdataclass.h>

#include <dns/rdata/generic/detail/lexer_util.h>

using namespace std;
using boost::lexical_cast;
using namespace isc::util;
using isc::dns::rdata::generic::detail::createNameFromLexer;

// BEGIN_ISC_NAMESPACE
// BEGIN_RDATA_NAMESPACE

MX::MX(InputBuffer& buffer, size_t) :
    preference_(buffer.readUint16()), mxname_(buffer)
{
    // we don't need rdata_len for parsing.  if necessary, the caller will
    // check consistency.
}

/// \brief Constructor from string.
///
/// The given string must represent a valid MX RDATA.  There can be extra
/// space characters at the beginning or end of the text (which are simply
/// ignored), but other extra text, including a new line, will make the
/// construction fail with an exception.
///
/// The EXCHANGE name must be absolute since there's no parameter that
/// specifies the origin name; if it is not absolute, \c MissingNameOrigin
/// exception will be thrown. It must not be represented as a quoted
/// string.
///
/// See the construction that takes \c MasterLexer for other fields.
///
/// \throw Others Exception from the Name and RRTTL constructors.
/// \throw InvalidRdataText Other general syntax errors.
MX::MX(const std::string& mx_str) :
    // Fill in dummy name and replace them soon below.
    preference_(0), mxname_(Name::ROOT_NAME())
{
    try {
        std::istringstream ss(mx_str);
        MasterLexer lexer;
        lexer.pushSource(ss);

        constructFromLexer(lexer, NULL);

        if (lexer.getNextToken().getType() != MasterToken::END_OF_FILE) {
            isc_throw(InvalidRdataText, "extra input text for MX: "
                      << mx_str);
        }
    } catch (const MasterLexer::LexerError& ex) {
        isc_throw(InvalidRdataText, "Failed to construct MX from '" <<
                  mx_str << "': " << ex.what());
    }
}

/// \brief Constructor with a context of MasterLexer.
///
/// The \c lexer should point to the beginning of valid textual representation
/// of an MX RDATA.  The EXCHANGE field can be non-absolute if \c origin
/// is non-NULL, in which case \c origin is used to make it absolute.
/// It must not be represented as a quoted string.
///
/// The PREFERENCE field must be a valid decimal representation of an
/// unsigned 16-bit integer.
///
/// \throw MasterLexer::LexerError General parsing error such as missing field.
/// \throw Other Exceptions from the Name and RRTTL constructors if
/// construction of textual fields as these objects fail.
///
/// \param lexer A \c MasterLexer object parsing a master file for the
/// RDATA to be created
/// \param origin If non NULL, specifies the origin of EXCHANGE when it
/// is non-absolute.
MX::MX(MasterLexer& lexer, const Name* origin,
       MasterLoader::Options, MasterLoaderCallbacks&) :
    preference_(0), mxname_(Name::ROOT_NAME())
{
    constructFromLexer(lexer, origin);
}

void
MX::constructFromLexer(MasterLexer& lexer, const Name* origin) {
    const uint32_t num = lexer.getNextToken(MasterToken::NUMBER).getNumber();
    if (num > 65535) {
        isc_throw(InvalidRdataText, "Invalid MX preference: " << num);
    }
    preference_ = static_cast<uint16_t>(num);

    mxname_ = createNameFromLexer(lexer, origin);
}

MX::MX(uint16_t preference, const Name& mxname) :
    preference_(preference), mxname_(mxname)
{}

MX::MX(const MX& other) :
    Rdata(), preference_(other.preference_), mxname_(other.mxname_)
{}

void
MX::toWire(OutputBuffer& buffer) const {
    buffer.writeUint16(preference_);
    mxname_.toWire(buffer);
}

void
MX::toWire(AbstractMessageRenderer& renderer) const {
    renderer.writeUint16(preference_);
    renderer.writeName(mxname_);
}

string
MX::toText() const {
    return (lexical_cast<string>(preference_) + " " + mxname_.toText());
}

int
MX::compare(const Rdata& other) const {
    const MX& other_mx = dynamic_cast<const MX&>(other);

    if (preference_ < other_mx.preference_) {
        return (-1);
    } else if (preference_ > other_mx.preference_) {
        return (1);
    }

    return (compareNames(mxname_, other_mx.mxname_));
}

const Name&
MX::getMXName() const {
    return (mxname_);
}

uint16_t
MX::getMXPref() const {
    return (preference_);
}

// END_RDATA_NAMESPACE
// END_ISC_NAMESPACE
