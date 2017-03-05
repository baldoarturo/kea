// Copyright (C) 2017 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <cc/command_interpreter.h>
#include <cc/data.h>
#include <cc/simple_parser.h>
#include <cc/cfg_to_element.h>
#include <dhcp/tests/iface_mgr_test_config.h>
#include <dhcpsrv/cfgmgr.h>
#include <dhcp4/tests/dhcp4_test_utils.h>
#include <dhcp4/tests/get_config_unittest.h>
#include <dhcp4/dhcp4_srv.h>
#include <dhcp4/json_config_parser.h>
#include <dhcp4/simple_parser4.h>

#include <boost/algorithm/string.hpp>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace isc::config;
using namespace isc::data;
using namespace isc::dhcp;
using namespace isc::dhcp::test;

namespace {

/// @name How to fill configurations
///
/// Copy get_config_unittest.cc.skel into get_config_unittest.cc
///
/// For the extracted configurations define the EXTRACT_CONFIG and
/// recompile this file. Run dhcp4_unittests on Dhcp4ParserTest
/// redirecting the standard error to a temporary file, e.g. by
/// @code
///    ./dhcp4_unittests --gtest_filter="Dhcp4Parser*" > /dev/null 2> x
/// @endcode
///
/// Update EXTRACTED_CONFIGS with the file content
///
/// When configurations have been extracted the corresponding unparsed
/// configurations must be generated. To do that define GENERATE_ACTION
/// and recompile this file. Run dhcp4_unittests on Dhcp4GetConfigTest
/// redirecting the standard error to a temporary file, e.g. by
/// @code
///    ./dhcp4_unittests --gtest_filter="Dhcp4GetConfig*" > /dev/null 2> u
/// @endcode
///
/// Update UNPARSED_CONFIGS with the file content, recompile this file
/// without EXTRACT_CONFIG and GENERATE_ACTION.
///
/// @note Check for failures at each step!
/// @note The tests of this file do not check if configs returned
/// by @ref isc::dhcp::CfgToElement::ToElement() are complete.
/// This has to be done manually.
///
///@{
/// @brief extracted configurations
const char* EXTRACTED_CONFIGS[] = {
    // "to be replaced"
};

/// @brief unparsed configurations
const char* UNPARSED_CONFIGS[] = {
    // "to be replaced"
};

/// @brief the number of configurations
const size_t max_config_counter = sizeof(EXTRACTED_CONFIGS) / sizeof(char*);
///@}

/// @brief the extraction counter
///
/// < 0 means do not extract, >= 0 means extract on extractConfig() calls
/// and increment
#ifdef EXTRACT_CONFIG
int extract_count = 0;
#else
int extract_count = -1;
#endif

/// @brief the generate action
/// false means do nothing, true means unparse extracted configurations
#ifdef GENERATE_ACTION
const bool generate_action = true;
#else
const bool generate_action = false;
static_assert(max_config_counter == sizeof(UNPARSED_CONFIGS) / sizeof(char*),
              "unparsed configurations must be generated");
#endif

/// @brief format and output a configuration
void
outputFormatted(const std::string& config) {
    // pretty print it
    ConstElementPtr json = parseJSON(config);
    std::string prettier = prettyPrint(json, 4, 4);
    // get it as a line array
    std::list<std::string> lines;
    boost::split(lines, prettier, boost::is_any_of("\n"));
    // add escapes using again JSON
    std::list<std::string> escapes;
    while (!lines.empty()) {
        const std::string& line = lines.front();
        ConstElementPtr escaping = Element::create(line + "\n");
        escapes.push_back(escaping->str());
        lines.pop_front();
    }
    // output them on std::cerr
    while (!escapes.empty()) {
        std::cerr << "\n" << escapes.front();
        escapes.pop_front();
    }
}

};

namespace isc {
namespace dhcp {
namespace test {

/// @ref isc::dhcp::test::extractConfig in the header
void
extractConfig(const std::string& config) {
    // skip when disable
    if (extract_count < 0) {
        return;
    }
    // mark beginning
    if (extract_count == 0) {
        // header (note there is no trailer)
        std::cerr << "/// put this after const char* EXTRACTED_CONFIGS[] = {\n";
    } else {
        // end of previous configuration
        std::cerr << ",\n";
    }
    std::cerr << "    // CONFIGURATION " << extract_count;
    try {
        outputFormatted(config);
    } catch (...) {
        // mark error
        std::cerr << "\n//// got an error\n";
    }
    ++extract_count;
}

};
};
};

namespace {

/// Test fixture class (code from Dhcp4ParserTest)
class Dhcp4GetConfigTest : public ::testing::TestWithParam<size_t> {
public:
    Dhcp4GetConfigTest()
    : rcode_(-1) {
        // Open port 0 means to not do anything at all. We don't want to
        // deal with sockets here, just check if configuration handling
        // is sane.
        srv_.reset(new Dhcpv4Srv(0));
        // Create fresh context.
        resetConfiguration();
    }

    ~Dhcp4GetConfigTest() {
        resetConfiguration();
    };

    /// @brief Parse and Execute configuration
    ///
    /// Parses a configuration and executes a configuration of the server.
    /// If the operation fails, the current test will register a failure.
    ///
    /// @param config Configuration to parse
    /// @param operation Operation being performed.  In the case of an error,
    ///        the error text will include the string "unable to <operation>.".
    ///
    /// @return true if the configuration succeeded, false if not.
    bool
    executeConfiguration(const std::string& config, const char* operation) {
        // clear config manager
        CfgMgr::instance().clear();

        // enable fake network interfaces
        IfaceMgrTestConfig test_config(true);

        // try JSON parser
        ConstElementPtr json;
        try {
            json = parseJSON(config);
        } catch (const std::exception& ex) {
            ADD_FAILURE() << "invalid JSON for " << operation
                          << " failed with " << ex.what()
                          << " on\n" << config << "\n";
            return (false);
        }

        // try DHCP4 parser
        try {
            json = parseDHCP4(config, true);
        } catch (...) {
            ADD_FAILURE() << "parsing failed for " << operation
                          << " on\n" << prettyPrint(json) << "\n";
            return (false);
        }

        // try DHCP4 configure
        ConstElementPtr status;
        try {
            status = configureDhcp4Server(*srv_, json);
        } catch (const std::exception& ex) {
            ADD_FAILURE() << "configure for " << operation
                          << " failed with " << ex.what()
                          << " on\n" << prettyPrint(json) << "\n";
            return (false);
        }

        // The status object must not be NULL
        if (!status) {
            ADD_FAILURE() << "configure for " << operation
                          << " returned null on\n"
                          << prettyPrint(json) << "\n";
            return (false);
        }

        // Returned value should be 0 (configuration success)
        comment_ = parseAnswer(rcode_, status);
        if (rcode_ != 0) {
            string reason = "";
            if (comment_) {
                reason = string(" (") + comment_->stringValue() + string(")");
            }
            ADD_FAILURE() << "configure for " << operation
                          << " returned error code "
                          << rcode_ << reason << " on\n"
                          << prettyPrint(json) << "\n";
            return (false);
        }
        return (true);
    }

    /// @brief Reset configuration database.
    ///
    /// This function resets configuration data base by
    /// removing all subnets and option-data. Reset must
    /// be performed after each test to make sure that
    /// contents of the database do not affect result of
    /// subsequent tests.
    void resetConfiguration() {
        string config = "{"
            "\"interfaces-config\": { \"interfaces\": [ \"*\" ] },"
            "\"valid-lifetime\": 4000, "
            "\"subnet4\": [ ], "
            "\"dhcp-ddns\": { \"enable-updates\" : false }, "
            "\"option-def\": [ ], "
            "\"option-data\": [ ] }";
        EXPECT_TRUE(executeConfiguration(config, "reset configuration"));
        CfgMgr::instance().clear();
        CfgMgr::instance().setFamily(AF_INET);
    }

    boost::scoped_ptr<Dhcpv4Srv> srv_;  ///< DHCP4 server under test
    int rcode_;                         ///< Return code from element parsing
    ConstElementPtr comment_;           ///< Reason for parse fail
};

/// Test a configuration
TEST_P(Dhcp4GetConfigTest, run) {
    // configurations have not been extracted yet
    if (max_config_counter == 0) {
        return;
    }

    // get the index of configurations to test
    size_t config_counter = GetParam();

    // emit unparsed header if wanted
    if ((config_counter == 0) && generate_action) {
        std::cerr << "///put this after const char* UNPARSED_CONFIGS[] = {\n";
    }

    // get the extracted configuration
    std::string config = EXTRACTED_CONFIGS[config_counter];
    std::ostringstream ss;
    ss << "extracted config #" << config_counter;

    // execute the extracted configuration
    ASSERT_TRUE(executeConfiguration(config, ss.str().c_str()));

    // unparse it
    ConstSrvConfigPtr extracted = CfgMgr::instance().getStagingCfg();
    ConstElementPtr unparsed;
    ASSERT_NO_THROW(unparsed = extracted->toElement());
    ConstElementPtr dhcp;
    ASSERT_NO_THROW(dhcp = unparsed->get("Dhcp4"));
    ASSERT_TRUE(dhcp);

    // dump if wanted else check
    std::string expected;
    if (generate_action) {
        if (config_counter > 0) {
            std::cerr << ",\n";
        }
        std::cerr << "    // CONFIGURATION " << config_counter;
        ASSERT_NO_THROW(expected = prettyPrint(dhcp));
        ASSERT_NO_THROW(outputFormatted(dhcp->str()));
    } else {
        expected = UNPARSED_CONFIGS[config_counter];
        ConstElementPtr json;
        ASSERT_NO_THROW(json = parseDHCP4(expected, true));
        EXPECT_TRUE(isEquivalent(dhcp, json));
        std::string current = prettyPrint(dhcp, 4, 4) + "\n";
        EXPECT_EQ(expected, current);
        if (expected != current) {
            expected = current;
        }
    }

    // execute the dhcp configuration
    ss.str("");
    ss << "unparsed config #" << config_counter;
    EXPECT_TRUE(executeConfiguration(expected, ss.str().c_str()));

    // is it a fixed point?
    ConstSrvConfigPtr extracted2 = CfgMgr::instance().getStagingCfg();
    ConstElementPtr unparsed2;
    ASSERT_NO_THROW(unparsed2 = extracted2->toElement());
    ASSERT_TRUE(unparsed2);
    EXPECT_TRUE(isEquivalent(unparsed, unparsed2));
}

/// Define the parametrized test loop
INSTANTIATE_TEST_CASE_P(Dhcp4GetConfigTest, Dhcp4GetConfigTest,
                        ::testing::Range(0UL, max_config_counter));

};
