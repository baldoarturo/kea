// Copyright (C) 2018-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#define KEATEST_MODULE
#include <yang/yang_revisions.h>

#include <sysrepo-cpp/Connection.hpp>
#include <sysrepo-cpp/Session.hpp>

#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;
using namespace sysrepo;
using namespace isc::yang;

using libyang::Context;
using libyang::Module;

const string REPOSITORY = SYSREPO_REPO;

/// @brief Returns nicely formed error message if module is missing
///
/// @param name name of the YANG module to complain about
/// @param revision revision of the YANG module
/// @return a text explaining what the problem is and how to fix it
string missingModuleText(const string& name, const string& revision) {
    stringstream tmp;
    tmp << "ERROR: YANG module " << name << " is not installed." << endl
        << "The environment is not suitable for running unit tests." << endl
        << "Please install the module " << name << ":" << endl
        << "$ sysrepoctl -i ./src/share/yang/modules/" << name << "@" << revision << ".yang" << endl
        << endl;
    return (tmp.str());
}

/// @brief Returns nicely formed error message if module does not have
/// the expected revision.
///
/// @param name name of the YANG module to complain about
/// @param expected expected revision of the YANG module
/// @param got got (bad) revision of the YANG module
string badRevisionModuleText(const string& name, const string& expected,
                             const string& got) {
    stringstream tmp;
    tmp << endl
        << "ERROR: YANG module " << name << " is not installed with the right "
        << "revision: got " << got << ", but expected " << expected << "." << endl
        << "Please remove the module " << name << " and reinstall it: " << endl
        << "$ sysrepoctl -u " << name << endl
        << "$ sysrepoctl -i ./src/share/yang/modules/" << name << "@" << expected << ".yang" << endl
        << endl;
    return (tmp.str());
}

/// @brief Checks sysrepo setup:
///  - connection establishment
///  - session establishment
///  - test module
///  - type modules
///  - IETF module
///  - Kea modules.
///  - daemon required
int main() {
    Session session(sysrepo::Connection{}.sessionStart());

    try {
        session.switchDatastore(sysrepo::Datastore::Candidate);
    } catch (const libyang::ErrorWithCode& ex) {
        cerr << "ERROR: Can't establish a sysrepo session: "
             << ex.what() << endl;
        return (2);
    }

    vector<Module> modules;
    try {
        Context context(session.getContext());
        modules = context.modules();
    } catch (const libyang::ErrorWithCode& ex) {
        cerr << "ERROR: Can't retrieve available modules: " << ex.what() << endl;
        return (3);
    }

    std::unordered_map<std::string, std::string> installed_modules;
    for (Module const& module : modules) {
        string const name(module.name());
        if (!module.revision()) {
            cerr << "ERROR: module " << name << " has no revision" << endl;
            return (5);
        }
        string const revision(*module.revision());
        installed_modules.emplace(name, revision);
    }

    for (auto const& kv : YANG_REVISIONS) {
        std::string const& name(kv.first);
        std::string const& expected_revision(kv.second);
        if (!installed_modules.count(name)) {
            cerr << missingModuleText(name, expected_revision);
            return (6);
        }
        string const& revision(installed_modules.at(name));
        if (expected_revision != revision) {
            cerr << badRevisionModuleText(name, expected_revision, revision);
            return (7);
        }
    }

    return 0;
}
