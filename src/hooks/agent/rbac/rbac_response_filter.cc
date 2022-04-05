// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <rbac.h>
#include <rbac_log.h>
#include <rbac_response_filter.h>
#include <cc/command_interpreter.h>

using namespace isc;
using namespace isc::config;
using namespace isc::data;
using namespace isc::log;
using namespace isc::rbac;
using namespace std;

namespace isc {
namespace rbac {

ResponseFilterTable responseFilterTable;

void
ResponseFilter::initResponseFilterTable() {
    responseFilterTable.clear();
    responseFilterTable["list-commands"] =
        ResponseFilterPtr(new ListCommandsResponseFilter);
    responseFilterTable["control-config"] =
        ResponseFilterPtr(new ConfigResponseFilter);
}

ResponseFilterList
ResponseFilter::parse(ConstElementPtr cfg) {
    if (!cfg) {
        isc_throw(BadValue, "parse null response filter list");
    }
    if (cfg->getType() != Element::list) {
        isc_throw(BadValue, "response filter list is not a list");
    }
    ResponseFilterList filters;
    for (auto const& elem : cfg->listValue()) {
        if (elem->getType() != Element::string) {
            isc_throw(BadValue, "response filter name is not a string");
        }
        const string& name = cfg->stringValue();
        if (name.empty()) {
            isc_throw(BadValue, "response filter name is empty");
        }
        auto it = responseFilterTable.find(name);
        if (it == responseFilterTable.end()) {
            isc_throw(BadValue, "unknown response filter '" << name << "'");
        }
        filters.push_back(it->second);
    }
    return (filters);
}

bool
ListCommandsResponseFilter::filter(const string& role, ConstElementPtr body) {
    if (!body || (body->getType() != Element::map)) {
        return (false);
    }
    ConstElementPtr command = body->get(CONTROL_COMMAND);
    if (!command || (command->getType() != Element::string)) {
        return (false);
    }
    if (command->stringValue() != "list-commands") {
        // Add a log here.
        return (false);
    }
    isc_throw(NotImplemented, "ListCommandsResponseFilter::filter("
              << body->str() << ")");
}

bool
ConfigResponseFilter::filter(const string&, ConstElementPtr body) {
    if (!body || (body->getType() != Element::map)) {
        return (false);
    }
    ConstElementPtr command = body->get(CONTROL_COMMAND);
    if (!command || (command->getType() != Element::string)) {
        return (false);
    }
    if (command->stringValue() != "config-get") {
        // Add a log here.
        return (false);
    }
    isc_throw(NotImplemented, "ConfigResponseFilter::filter("
              << body->str() << ")");
}

} // end of namespace rbac
} // end of namespace isc
