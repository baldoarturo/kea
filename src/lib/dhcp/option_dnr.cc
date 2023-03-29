// Copyright (C) 2018-2023 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <dhcp/option_dnr.h>

namespace isc {
namespace dhcp {

OptionDNR6::OptionDNR6(const uint16_t type) : Option(Universe::V6, type) {
}

OptionDNR6::OptionDNR6(const uint16_t type,
                       OptionBufferConstIter begin,
                       OptionBufferConstIter end) : Option(Universe::V6, type)  {
    unpack(begin, end);
}

OptionPtr
OptionDNR6::clone() const {
    return Option::clone();
}

void
OptionDNR6::pack(util::OutputBuffer& buf, bool check) const {
    Option::pack(buf, check);
}

void
OptionDNR6::unpack(OptionBufferConstIter begin, OptionBufferConstIter end) {
    Option::unpack(begin, end);
}

std::string
OptionDNR6::toText(int indent) const {
    return Option::toText(indent);
}

uint16_t
OptionDNR6::len() const {
    return Option::len();
}

OptionDNR4::OptionDNR4(const uint16_t type) : Option(V4, type) {
}

OptionDNR4::OptionDNR4(const uint16_t type,
                       OptionBufferConstIter begin,
                       OptionBufferConstIter end) : Option(V4, type) {
    unpack(begin, end);
}

OptionPtr
OptionDNR4::clone() const {
    return Option::clone();
}

void
OptionDNR4::pack(util::OutputBuffer& buf, bool check) const {
    Option::pack(buf, check);
}

void
OptionDNR4::unpack(OptionBufferConstIter begin, OptionBufferConstIter end) {
    Option::unpack(begin, end);
}

std::string
OptionDNR4::toText(int indent) const {
    return Option::toText(indent);
}

uint16_t
OptionDNR4::len() const {
    return Option::len();
}

}  // namespace dhcp
}  // namespace isc
