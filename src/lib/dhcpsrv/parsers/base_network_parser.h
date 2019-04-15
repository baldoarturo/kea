// Copyright (C) 2019 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef BASE_NETWORK_PARSER_H
#define BASE_NETWORK_PARSER_H

#include <cc/data.h>
#include <cc/simple_parser.h>
#include <dhcpsrv/network.h>

namespace isc {
namespace dhcp {

/// @brief Common configuration parser for shared networks
/// and subnets.
class BaseNetworkParser : public data::SimpleParser {
protected:

    /// @brief Parses common DHCP timers.
    ///
    /// The parsed parameters are:
    /// - renew-timer,
    /// - rebind-timer,
    /// - valid-lifetime
    ///
    /// @param shared_network_data Data element holding shared network
    /// configuration to be parsed.
    /// @param [out] network Pointer to a network in which parsed data is
    /// to be stored.
    void parseCommonTimers(const data::ConstElementPtr& network_data,
                           NetworkPtr& network);

    /// @brief Parses parameters related to "percent" timers settngs.
    ///
    /// The parsed parameters are:
    /// - calculate-tee-times,
    /// - t1-percent,
    /// - t2-percent.
    ///
    /// @param network_data Data element holding shared network
    /// configuration to be parsed.
    /// @param [out] network Pointer to a network in which parsed data is
    /// to be stored.
    ///
    /// @throw DhcpConfigError if configuration of these parameters is
    /// invalid.
    void parseTeePercents(const data::ConstElementPtr& network_data,
                          NetworkPtr& network);

    /// @brief Parses host reservation mode.
    //
    /// @param network_data Data element holding shared network
    /// configuration to be parsed.
    /// @param [out] network Pointer to a network in which parsed data is
    /// to be stored.
    void parseHostReservationMode(const data::ConstElementPtr& network_data,
                                  NetworkPtr& network);
};

} // end of namespace isc::dhcp
} // end of namespace isc

#endif
