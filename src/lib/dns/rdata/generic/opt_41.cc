// Copyright (C) 2010-2013  Internet Systems Consortium, Inc. ("ISC")
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

#include <util/buffer.h>
#include <dns/messagerenderer.h>
#include <dns/rdata.h>
#include <dns/rdataclass.h>

using namespace std;
using namespace isc::util;

// BEGIN_ISC_NAMESPACE
// BEGIN_RDATA_NAMESPACE

/// \brief Constructor from string.
///
/// This constructor cannot be used, and always throws an exception.
///
/// \throw InvalidRdataText OPT RR cannot be constructed from text.
OPT::OPT(const std::string&) {
    isc_throw(InvalidRdataText, "OPT RR cannot be constructed from text");
}

/// \brief Constructor with a context of MasterLexer.
///
/// This constructor cannot be used, and always throws an exception.
///
/// \throw InvalidRdataText OPT RR cannot be constructed from text.
OPT::OPT(MasterLexer&, const Name*,
       MasterLoader::Options, MasterLoaderCallbacks&)
{
    isc_throw(InvalidRdataText, "OPT RR cannot be constructed from text");
}

OPT::OPT(InputBuffer& buffer, size_t rdata_len) {
    // setPosition() will throw against a short buffer anyway, but it's safer
    // to check it explicitly here.
    if (buffer.getLength() - buffer.getPosition() < rdata_len) {
        isc_throw(InvalidRdataLength, "RDLEN of OPT is too large");
    }

    // This simple implementation ignores any options
    buffer.setPosition(buffer.getPosition() + rdata_len);
}

OPT::OPT(const OPT&) : Rdata() {
    // there's nothing to copy in this simple implementation.
}

std::string
OPT::toText() const {
    // OPT records do not have a text format.
    return ("");
}

void
OPT::toWire(OutputBuffer&) const {
    // nothing to do, as this simple version doesn't support any options.
}

void
OPT::toWire(AbstractMessageRenderer&) const {
    // nothing to do, as this simple version doesn't support any options.
}

int
OPT::compare(const Rdata& other) const {
    //const OPT& other_opt = dynamic_cast<const OPT&>(other);
    // right now we don't need other_opt:
    static_cast<void>(dynamic_cast<const OPT&>(other));

    return (0);
}

// END_RDATA_NAMESPACE
// END_ISC_NAMESPACE
