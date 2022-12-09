// Copyright (C) 2019-2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// This file is dedicated to testing vendor options in DHCPv6. There
// are several related options:
//
// client-class (15) - this specifies (as a plain string) what kind of
//                     device this is
// vendor-class (16) - contains an enterprise-id followed by zero or
//                     more of vendor-class data.
// vendor-option (17) - contains an enterprise-id followed by zero or
//                     more vendor suboptions

#include <config.h>

#include <asiolink/io_address.h>
#include <dhcp/dhcp6.h>
#include <dhcp/option_vendor.h>
#include <dhcp/option_vendor_class.h>
#include <dhcp6/tests/dhcp6_test_utils.h>
#include <dhcp6/tests/dhcp6_client.h>
#include <dhcp6/json_config_parser.h>
#include <dhcp/tests/pkt_captures.h>
#include <dhcp/docsis3_option_defs.h>
#include <dhcp/tests/iface_mgr_test_config.h>
#include <dhcp/option_string.h>
#include <cc/command_interpreter.h>

#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace isc;
using namespace isc::config;
using namespace isc::dhcp;
using namespace isc::dhcp::test;
using namespace isc::asiolink;

namespace {

/// @brief Class dedicated to testing vendor options in DHCPv6
class VendorOptsTest : public Dhcpv6SrvTest {
public:
    /// @brief Called before each test
    void SetUp() override {
        iface_mgr_test_config_.reset(new IfaceMgrTestConfig(true));
        IfaceMgr::instance().openSockets6();
    }

    /// @brief Called after each test
    void TearDown() override {
        iface_mgr_test_config_.reset();
        IfaceMgr::instance().closeSockets();
    }

    void testVendorOptionsORO(uint32_t vendor_id) {
        // Create a config with a custom option for Cable Labs.
        string config = R"(
            {
            "interfaces-config": {
                "interfaces": [ "*" ]
            },
            "option-data": [
                {
                    "data": "normal_erouter_v6.cm",
                    "name": "config-file",
                    "space": "vendor-4491"
                }
            ],
            "option-def": [
                {
                    "code": 33,
                    "name": "config-file",
                    "space": "vendor-4491",
                    "type": "string"
                }
            ],
            "preferred-lifetime": 3000,
            "rebind-timer": 2000,
            "renew-timer": 1000,
            "subnet6": [
                {
                    "interface": "eth0",
                    "interface-id": "",
                    "pools": [
                        {
                            "pool": "2001:db8:1::/64"
                        }
                    ],
                    "preferred-lifetime": 3000,
                    "rebind-timer": 1000,
                    "renew-timer": 1000,
                    "subnet": "2001:db8:1::/48",
                    "valid-lifetime": 4000
                }
            ],
            "valid-lifetime": 4000
            }
        )";

        // Configure a mocked server.
        ASSERT_NO_THROW(configure(config));

        // Create a SOLICIT.
        Pkt6Ptr sol = Pkt6Ptr(new Pkt6(DHCPV6_SOLICIT, 1234));
        sol->setRemoteAddr(IOAddress("fe80::abcd"));
        sol->setIface("eth0");
        sol->setIndex(ETH0_INDEX);
        sol->addOption(generateIA(D6O_IA_NA, 234, 1500, 3000));
        OptionPtr clientid = generateClientId();
        sol->addOption(clientid);

        // Pass it to the server and get an advertise.
        AllocEngine::ClientContext6 ctx;
        bool drop = !srv_.earlyGHRLookup(sol, ctx);
        ASSERT_FALSE(drop);
        srv_.initContext(sol, ctx, drop);
        ASSERT_FALSE(drop);
        Pkt6Ptr adv = srv_.processSolicit(ctx);

        // Check if we get a response at all.
        ASSERT_TRUE(adv);

        // We did not include any vendor opts in SOLICIT, so there should be none
        // in ADVERTISE.
        ASSERT_FALSE(adv->getOption(D6O_VENDOR_OPTS));

        // Let's add a vendor-option (vendor-id=4491) with a single sub-option.
        // That suboption has code 1 and is a docsis ORO option.
        boost::shared_ptr<OptionUint16Array> vendor_oro(new OptionUint16Array(Option::V6,
                                                                              DOCSIS3_V6_ORO));
        vendor_oro->addValue(DOCSIS3_V6_CONFIG_FILE); // Request option 33
        OptionVendorPtr vendor(new OptionVendor(Option::V6, { vendor_id }));
        vendor->addOption(vendor_id, vendor_oro);
        sol->addOption(vendor);

        // Need to process SOLICIT again after requesting new option.
        AllocEngine::ClientContext6 ctx2;
        drop = !srv_.earlyGHRLookup(sol, ctx2);
        ASSERT_FALSE(drop);
        srv_.initContext(sol, ctx2, drop);
        ASSERT_FALSE(drop);
        adv = srv_.processSolicit(ctx2);
        ASSERT_TRUE(adv);

        // Check if there is (or not) a vendor option in the response.
        OptionPtr tmp = adv->getOption(D6O_VENDOR_OPTS);
        if (vendor_id != VENDOR_ID_CABLE_LABS) {
            EXPECT_FALSE(tmp);
            return;
        }
        ASSERT_TRUE(tmp);

        // The response should be an OptionVendor.
        boost::shared_ptr<OptionVendor> vendor_resp =
            boost::dynamic_pointer_cast<OptionVendor>(tmp);
        ASSERT_TRUE(vendor_resp);

        // Option 33 should be present.
        OptionPtr docsis33 = vendor_resp->getOption(vendor_id, DOCSIS3_V6_CONFIG_FILE);
        ASSERT_TRUE(docsis33);

        // Check that the provided content match the one in configuration.
        OptionStringPtr config_file = boost::dynamic_pointer_cast<OptionString>(docsis33);
        ASSERT_TRUE(config_file);
        EXPECT_EQ("normal_erouter_v6.cm", config_file->getValue());
    }

    /// @brief Test what options a client can use to request vendor options.
    void testRequestingOfVendorOptions(vector<int8_t> const& client_options) {
        Dhcp6Client client;

        EXPECT_NO_THROW(configure(config_, *client.getServer()));

        bool should_yield_response(false);
        for (int8_t const i : client_options) {
            OptionPtr vendor_option;

            if (i == D6O_USER_CLASS) {
                // An option that should not trigger a response containing
                // vendor options.
                vendor_option = boost::make_shared<OptionString>(Option::V6,
                                                                 D6O_USER_CLASS,
                                                                 "hello");
            } else if (i == D6O_VENDOR_CLASS) {
                vendor_option =
                    boost::make_shared<OptionVendorClass>(Option::V6,
                                                          vendor_id_);
                should_yield_response = true;
            } else if (i == D6O_VENDOR_OPTS) {
                vendor_option.reset(new OptionVendor(Option::V6, { vendor_id_ }));
                should_yield_response = true;
            } else {
                continue;
            }
            client.addExtraOption(vendor_option);
        }

        // Let's check whether the server is able to process this packet
        // and include the appropriate options.
        EXPECT_NO_THROW(client.doSolicit());
        ASSERT_TRUE(client.getContext().response_);

        // Check that there is a response if an option was properly requested.
        // Otherwise check that a response has not been provided and stop here.
        OptionPtr response(
            client.getContext().response_->getOption(D6O_VENDOR_OPTS));
        if (should_yield_response) {
            ASSERT_TRUE(response);
        } else {
            ASSERT_FALSE(response);
            return;
        }

        // Check that it includes vendor opts with the right vendor ID.
        OptionVendorPtr response_vendor_options(
            boost::dynamic_pointer_cast<OptionVendor>(response));
        ASSERT_TRUE(response_vendor_options);
        EXPECT_EQ(vendor_id_, response_vendor_options->getVendorIds()[0]);

        // Check that it contains requested option with the appropriate content.
        OptionPtr suboption(
            response_vendor_options->getOption(vendor_id_, option_));
        ASSERT_TRUE(suboption);
        vector<uint8_t> binary_suboption = suboption->toBinary(false);
        string text(binary_suboption.begin(), binary_suboption.end());
        EXPECT_EQ("2001:db8::1234:5678", text);
    }

private:
    /// @brief Configured option data
    string data_ = "2001:db8::1234:5678";

    /// @brief Configured option code
    int32_t option_ = 32;

    /// @brief Configured and requested vendor ID
    uint32_t vendor_id_ = 32768;

    /// @brief Server configuration
    string config_ = R"(
    {
      "option-data": [
        {
          "always-send": true,
          "code": )" + to_string(option_) + R"(,
          "data": ")" + data_ + R"(",
          "name": "tftp-address",
          "space": "vendor-)" + to_string(vendor_id_) + R"("
        }
      ],
      "option-def": [
        {
          "code": )" + to_string(option_) + R"(,
          "name": "tftp-address",
          "space": "vendor-)" + to_string(vendor_id_) + R"(",
          "type": "string"
        }
      ],
      "subnet6": [
        {
          "interface": "eth0",
          "pools": [
            {
              "pool": "2001:db8::/64"
            }
          ],
          "subnet": "2001:db8::/64"
        }
      ]
    }
    )";

    std::unique_ptr<IfaceMgrTestConfig> iface_mgr_test_config_;
};

TEST_F(VendorOptsTest, dontRequestVendorID) {
    testRequestingOfVendorOptions({});
}

TEST_F(VendorOptsTest, negativeTestRequestVendorIDWithOption15) {
    testRequestingOfVendorOptions({D6O_USER_CLASS});
}

TEST_F(VendorOptsTest, requestVendorIDWithOption16) {
    testRequestingOfVendorOptions({D6O_VENDOR_CLASS});
}

TEST_F(VendorOptsTest, requestVendorIDWithOption17) {
    testRequestingOfVendorOptions({D6O_VENDOR_OPTS});
}

TEST_F(VendorOptsTest, requestVendorIDWithOptions16And17) {
    testRequestingOfVendorOptions({D6O_VENDOR_CLASS, D6O_VENDOR_OPTS});
}

TEST_F(VendorOptsTest, requestVendorIDWithOptions17And16) {
    testRequestingOfVendorOptions({D6O_VENDOR_OPTS, D6O_VENDOR_CLASS});
}

// Checks if server is able to handle a relayed traffic from DOCSIS3.0 modems
TEST_F(VendorOptsTest, docsisVendorOptionsParse) {

    // Let's get a traffic capture from DOCSIS3.0 modem
    Pkt6Ptr sol = PktCaptures::captureDocsisRelayedSolicit();
    EXPECT_NO_THROW(sol->unpack());

    // Check if the packet contain
    OptionPtr opt = sol->getOption(D6O_VENDOR_OPTS);
    ASSERT_TRUE(opt);

    boost::shared_ptr<OptionVendor> vendor = boost::dynamic_pointer_cast<OptionVendor>(opt);
    ASSERT_TRUE(vendor);

    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, DOCSIS3_V6_ORO));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 36));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 35));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, DOCSIS3_V6_DEVICE_TYPE));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 3));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 4));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 5));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 6));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 7));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 8));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 9));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, DOCSIS3_V6_VENDOR_NAME));
    EXPECT_TRUE(vendor->getOption(VENDOR_ID_CABLE_LABS, 15));

    EXPECT_FALSE(vendor->getOption(VENDOR_ID_CABLE_LABS, 20));
    EXPECT_FALSE(vendor->getOption(VENDOR_ID_CABLE_LABS, 11));
    EXPECT_FALSE(vendor->getOption(VENDOR_ID_CABLE_LABS, 17));
}

// Checks if server is able to parse incoming docsis option and extract suboption 1 (docsis ORO)
TEST_F(VendorOptsTest, docsisVendorORO) {

    NakedDhcpv6Srv srv(0);

    // Let's get a traffic capture from DOCSIS3.0 modem
    Pkt6Ptr sol = PktCaptures::captureDocsisRelayedSolicit();
    ASSERT_NO_THROW(sol->unpack());

    // Check if the packet contains vendor options option
    OptionPtr opt = sol->getOption(D6O_VENDOR_OPTS);
    ASSERT_TRUE(opt);

    boost::shared_ptr<OptionVendor> vendor = boost::dynamic_pointer_cast<OptionVendor>(opt);
    ASSERT_TRUE(vendor);

    opt = vendor->getOption(VENDOR_ID_CABLE_LABS, DOCSIS3_V6_ORO);
    ASSERT_TRUE(opt);

    OptionUint16ArrayPtr oro = boost::dynamic_pointer_cast<OptionUint16Array>(opt);
    EXPECT_TRUE(oro);
}

// This test checks if Option Request Option (ORO) in docsis (vendor-id=4491)
// vendor options is parsed correctly and the requested options are actually assigned.
TEST_F(VendorOptsTest, vendorOptionsORO) {
    testVendorOptionsORO(VENDOR_ID_CABLE_LABS);
}

// Same as vendorOptionsORO except a different vendor ID than Cable Labs is
// provided and vendor options are expected to not be present in the response.
TEST_F(VendorOptsTest, vendorOptionsORODifferentVendorID) {
    testVendorOptionsORO(32768);
}

// This test checks if Option Request Option (ORO) in docsis (vendor-id=4491)
// vendor options is parsed correctly and the persistent options are actually assigned.
TEST_F(VendorOptsTest, vendorPersistentOptions) {
    string config = "{ \"interfaces-config\": {"
        "  \"interfaces\": [ \"*\" ]"
        "},"
        "\"preferred-lifetime\": 3000,"
        "\"rebind-timer\": 2000, "
        "\"renew-timer\": 1000, "
        "    \"option-def\": [ {"
        "        \"name\": \"config-file\","
        "        \"code\": 33,"
        "        \"type\": \"string\","
        "        \"space\": \"vendor-4491\""
        "     } ],"
        "    \"option-data\": [ {"
        "          \"name\": \"config-file\","
        "          \"space\": \"vendor-4491\","
        "          \"data\": \"normal_erouter_v6.cm\","
        "          \"always-send\": true"
        "        }],"
        "\"subnet6\": [ { "
        "    \"pools\": [ { \"pool\": \"2001:db8:1::/64\" } ],"
        "    \"subnet\": \"2001:db8:1::/48\", "
        "    \"renew-timer\": 1000, "
        "    \"rebind-timer\": 1000, "
        "    \"preferred-lifetime\": 3000,"
        "    \"valid-lifetime\": 4000,"
        "    \"interface-id\": \"\","
        "    \"interface\": \"eth0\""
        " } ],"
        "\"valid-lifetime\": 4000 }";

    ASSERT_NO_THROW(configure(config));

    Pkt6Ptr sol = Pkt6Ptr(new Pkt6(DHCPV6_SOLICIT, 1234));
    sol->setRemoteAddr(IOAddress("fe80::abcd"));
    sol->setIface("eth0");
    sol->setIndex(ETH0_INDEX);
    sol->addOption(generateIA(D6O_IA_NA, 234, 1500, 3000));
    OptionPtr clientid = generateClientId();
    sol->addOption(clientid);

    // Let's add a vendor-option (vendor-id=4491).
    OptionPtr vendor(new OptionVendor(Option::V6, { VENDOR_ID_CABLE_LABS }));
    sol->addOption(vendor);

    // Pass it to the server and get an advertise
    AllocEngine::ClientContext6 ctx;
    bool drop = !srv_.earlyGHRLookup(sol, ctx);
    ASSERT_FALSE(drop);
    srv_.initContext(sol, ctx, drop);
    ASSERT_FALSE(drop);
    Pkt6Ptr adv = srv_.processSolicit(ctx);

    // check if we get response at all
    ASSERT_TRUE(adv);

    // Check if there is vendor option response
    OptionPtr tmp = adv->getOption(D6O_VENDOR_OPTS);
    ASSERT_TRUE(tmp);

    // The response should be OptionVendor object
    boost::shared_ptr<OptionVendor> vendor_resp =
        boost::dynamic_pointer_cast<OptionVendor>(tmp);
    ASSERT_TRUE(vendor_resp);

    OptionPtr docsis33 = vendor_resp->getOption(VENDOR_ID_CABLE_LABS, 33);
    ASSERT_TRUE(docsis33);

    OptionStringPtr config_file = boost::dynamic_pointer_cast<OptionString>(docsis33);
    ASSERT_TRUE(config_file);
    EXPECT_EQ("normal_erouter_v6.cm", config_file->getValue());

    // Let's add a vendor-option (vendor-id=4491) with a single sub-option.
    // That suboption has code 1 and is a docsis ORO option.
    sol->delOption(D6O_VENDOR_OPTS);
    boost::shared_ptr<OptionUint16Array> vendor_oro(new OptionUint16Array(Option::V6,
                                                                          DOCSIS3_V6_ORO));
    vendor_oro->addValue(DOCSIS3_V6_CONFIG_FILE); // Request option 33
    OptionVendorPtr vendor2(new OptionVendor(Option::V6, { VENDOR_ID_CABLE_LABS }));
    vendor2->addOption(VENDOR_ID_CABLE_LABS, vendor_oro);
    sol->addOption(vendor2);

    // Need to process SOLICIT again after requesting new option.
    AllocEngine::ClientContext6 ctx2;
    drop = !srv_.earlyGHRLookup(sol, ctx2);
    ASSERT_FALSE(drop);
    srv_.initContext(sol, ctx2, drop);
    ASSERT_FALSE(drop);
    adv = srv_.processSolicit(ctx2);
    ASSERT_TRUE(adv);

    // Check if there is vendor option response
    tmp = adv->getOption(D6O_VENDOR_OPTS);
    ASSERT_TRUE(tmp);

    // The response should be OptionVendor object
    vendor_resp = boost::dynamic_pointer_cast<OptionVendor>(tmp);
    ASSERT_TRUE(vendor_resp);

    // There should be only one suboption despite config-file is both
    // requested and has the always-send flag.
    const OptionCollection& opts = vendor_resp->getOptions(VENDOR_ID_CABLE_LABS);
    ASSERT_EQ(1, opts.size());
}

// Test checks whether it is possible to use option definitions defined in
// src/lib/dhcp/docsis3_option_defs.h.
TEST_F(VendorOptsTest, vendorOptionsDocsisDefinitions) {
    ConstElementPtr x;
    string config_prefix = "{ \"interfaces-config\": {"
        "  \"interfaces\": [ ]"
        "},"
        "\"preferred-lifetime\": 3000,"
        "\"rebind-timer\": 2000, "
        "\"renew-timer\": 1000, "
        "    \"option-data\": [ {"
        "          \"name\": \"config-file\","
        "          \"space\": \"vendor-4491\","
        "          \"code\": ";
    string config_postfix = ","
        "          \"data\": \"normal_erouter_v6.cm\","
        "          \"csv-format\": true"
        "        }],"
        "\"subnet6\": [ { "
        "    \"pools\": [ { \"pool\": \"2001:db8:1::/64\" } ],"
        "    \"subnet\": \"2001:db8:1::/48\", "
        "    \"renew-timer\": 1000, "
        "    \"rebind-timer\": 1000, "
        "    \"preferred-lifetime\": 3000,"
        "    \"valid-lifetime\": 4000,"
        "    \"interface-id\": \"\","
        "    \"interface\": \"\""
        " } ],"
        "\"valid-lifetime\": 4000 }";

    // There is docsis3 (vendor-id=4491) vendor option 33, which is a
    // config-file. Its format is a single string.
    string config_valid = config_prefix + "33" + config_postfix;

    // There is no option 99 defined in vendor-id=4491. As there is no
    // definition, the config should fail.
    string config_bogus = config_prefix + "99" + config_postfix;

    ConstElementPtr json_bogus;
    ASSERT_NO_THROW(json_bogus = parseDHCP6(config_bogus));
    ConstElementPtr json_valid;
    ASSERT_NO_THROW(json_valid = parseDHCP6(config_valid));

    NakedDhcpv6Srv srv(0);

    // This should fail (missing option definition)
    EXPECT_NO_THROW(x = configureDhcp6Server(srv, json_bogus));
    ASSERT_TRUE(x);
    comment_ = isc::config::parseAnswer(rcode_, x);
    ASSERT_EQ(1, rcode_);

    // This should work (option definition present)
    EXPECT_NO_THROW(x = configureDhcp6Server(srv, json_valid));
    ASSERT_TRUE(x);
    comment_ = isc::config::parseAnswer(rcode_, x);
    ASSERT_EQ(0, rcode_);
}

// This test checks that the server will handle a Solicit with the Vendor Class
// having a length of 4 (enterprise-id only).
TEST_F(VendorOptsTest, cableLabsShortVendorClass) {
    NakedDhcpv6Srv srv(0);

    // Create a simple Solicit with the 4-byte long vendor class option.
    Pkt6Ptr sol = PktCaptures::captureCableLabsShortVendorClass();

    // Simulate that we have received that traffic
    srv.fakeReceive(sol);

    // Server will now process to run its normal loop, but instead of calling
    // IfaceMgr::receive6(), it will read all packets from the list set by
    // fakeReceive()
    srv.run();

    // Get Advertise...
    ASSERT_FALSE(srv.fake_sent_.empty());
    Pkt6Ptr adv = srv.fake_sent_.front();
    ASSERT_TRUE(adv);

    // This is sent back to client, so port is 546
    EXPECT_EQ(DHCP6_CLIENT_PORT, adv->getRemotePort());
}

// Checks that it's possible to have a vendor opts (17) option in the response
// only. Once specific client (Genexis) sends only vendor-class info and
// expects the server to include vendor opts in the response.
TEST_F(VendorOptsTest, vendorOpsInResponseOnly) {
    Dhcp6Client client;

    // The config defines custom vendor (17) suboption 2 that conveys
    // a TFTP URL.  The client doesn't send vendor class (16) or
    // vendor opts (17) option, so normal vendor option processing is
    // impossible. However, since there's a class defined that matches
    // client's packets and that class inserts a vendor opts in the
    // response, Kea should be able to figure out the vendor-id and
    // then also insert the suboption 2 with the TFTP URL.
    string config =
        "{"
        "    \"interfaces-config\": {"
        "        \"interfaces\": [ ]"
        "    },"
        "    \"option-def\": ["
        "        {"
        "            \"name\": \"tftp\","
        "            \"code\": 2,"
        "            \"space\": \"vendor-25167\","
        "            \"type\": \"string\""
        "        }"
        "    ],"
        "    \"client-classes\": ["
        "    {"
        "        \"name\": \"cpe_genexis\","
        "        \"test\": \"substring(option[15].hex,0,7) == 'HMC1000'\","
        "        \"option-data\": ["
        "        {"
        "            \"name\": \"vendor-opts\","
        "            \"data\": \"25167\""
        "        },"
        "        {"
        "            \"name\": \"tftp\","
        "            \"space\": \"vendor-25167\","
        "            \"data\": \"tftp://192.0.2.1/genexis/HMC1000.v1.3.0-R.img\","
        "            \"always-send\": true"
        "        } ]"
        "    } ],"
        "\"subnet6\": [ { "
        "    \"pools\": [ { \"pool\": \"2001:db8::/64\" } ],"
        "    \"subnet\": \"2001:db8::/64\", "
        "    \"interface\": \"eth0\" "
        " } ]"
        "}";

    EXPECT_NO_THROW(configure(config, *client.getServer()));

    // A vendor-class identifier (this matches what Genexis hardware sends)
    OptionPtr vopt(new OptionString(Option::V6, D6O_USER_CLASS,
                                    "HMC1000.v1.3.0-R,Element-P1090,genexis.eu"));
    client.addExtraOption(vopt);
    client.requestOption(D6O_VENDOR_OPTS);

    // Let's check whether the server is not able to process this packet
    // and include vivso with appropriate sub-options
    EXPECT_NO_THROW(client.doSolicit());
    ASSERT_TRUE(client.getContext().response_);

    // Check whether there's a response.
    OptionPtr rsp = client.getContext().response_->getOption(D6O_VENDOR_OPTS);
    ASSERT_TRUE(rsp);

    // Check that it includes vendor opts with vendor-id = 25167
    OptionVendorPtr rsp_vopts = boost::dynamic_pointer_cast<OptionVendor>(rsp);
    ASSERT_TRUE(rsp_vopts);
    EXPECT_EQ(25167, rsp_vopts->getVendorIds()[0]);

    // Now check that it contains suboption 2 with appropriate content.
    OptionPtr subopt2 = rsp_vopts->getOption(25167, 2);
    ASSERT_TRUE(subopt2);
    vector<uint8_t> subopt2bin = subopt2->toBinary(false);
    string txt(subopt2bin.begin(), subopt2bin.end());
    EXPECT_EQ("tftp://192.0.2.1/genexis/HMC1000.v1.3.0-R.img", txt);
}

// Checks if it's possible to have 2 vendor-class options and 2 vendor-opts
// options with different vendor IDs.
TEST_F(VendorOptsTest, twoVendors) {
    Dhcp6Client client;

    // The config defines 2 vendors with for each a vendor-class option,
    // a vendor-opts option and a custom vendor suboption, all having
    // the always send flag set to true.
    // The encoding for the option-class option is a bit hairy: first is
    // the vendor id (uint32) and the remaining is a binary which stands
    // for tuples so length (uint16) x value.
    string config =
        "{"
        "    \"interfaces-config\": {"
        "        \"interfaces\": [ ]"
        "    },"
        "    \"option-def\": ["
        "        {"
        "            \"name\": \"foo\","
        "            \"code\": 123,"
        "            \"space\": \"vendor-1234\","
        "            \"type\": \"string\""
        "        },"
        "        {"
        "            \"name\": \"bar\","
        "            \"code\": 456,"
        "            \"space\": \"vendor-5678\","
        "            \"type\": \"string\""
        "        }"
        "    ],"
        "    \"option-data\": ["
        "        {"
        "            \"name\": \"vendor-class\","
        "            \"always-send\": true,"
        "            \"data\": \"1234, 0003666f6f\""
        "        },"
        "        {"
        "            \"name\": \"vendor-class\","
        "            \"always-send\": true,"
        "            \"data\": \"5678, 0003626172\""
        "        },"
        "        {"
        "            \"name\": \"vendor-opts\","
        "            \"always-send\": true,"
        "            \"data\": \"1234\""
        "        },"
        "        {"
        "            \"name\": \"vendor-opts\","
        "            \"always-send\": true,"
        "            \"data\": \"5678\""
        "        },"
        "        {"
        "            \"name\": \"foo\","
        "            \"always-send\": true,"
        "            \"space\": \"vendor-1234\","
        "            \"data\": \"foo\""
        "        },"
        "        {"
        "            \"name\": \"bar\","
        "            \"always-send\": true,"
        "            \"space\": \"vendor-5678\","
        "            \"data\": \"bar\""
        "        }"
        "    ],"
        "\"subnet6\": [ { "
        "    \"pools\": [ { \"pool\": \"2001:db8::/64\" } ],"
        "    \"subnet\": \"2001:db8::/64\", "
        "    \"interface\": \"eth0\" "
        " } ]"
        "}";

    EXPECT_NO_THROW(configure(config, *client.getServer()));

    // Let's check whether the server is not able to process this packet.
    EXPECT_NO_THROW(client.doSolicit());
    ASSERT_TRUE(client.getContext().response_);

    // Check whether there are vendor-class options.
    const OptionCollection& classes =
        client.getContext().response_->getOptions(D6O_VENDOR_CLASS);
    ASSERT_EQ(2, classes.size());
    OptionVendorClassPtr opt_class1234;
    OptionVendorClassPtr opt_class5678;
    for (auto opt : classes) {
        ASSERT_EQ(D6O_VENDOR_CLASS, opt.first);
        OptionVendorClassPtr opt_class =
            boost::dynamic_pointer_cast<OptionVendorClass>(opt.second);
        ASSERT_TRUE(opt_class);
        uint32_t vendor_id = opt_class->getVendorId();
        if (vendor_id == 1234) {
            ASSERT_FALSE(opt_class1234);
            opt_class1234 = opt_class;
            continue;
        }
        ASSERT_EQ(5678, vendor_id);
        ASSERT_FALSE(opt_class5678);
        opt_class5678 = opt_class;
    }

    // Verify first vendor-class option.
    ASSERT_TRUE(opt_class1234);
    ASSERT_EQ(1, opt_class1234->getTuplesNum());
    EXPECT_EQ("foo", opt_class1234->getTuple(0).getText());

    // Verify second vendor-class option.
    ASSERT_TRUE(opt_class5678);
    ASSERT_EQ(1, opt_class5678->getTuplesNum());
    EXPECT_EQ("bar", opt_class5678->getTuple(0).getText());

    // Check whether there are vendor-opts options.
    const OptionCollection& options =
        client.getContext().response_->getOptions(D6O_VENDOR_OPTS);
    ASSERT_EQ(2, options.size());
    OptionVendorPtr opt_opts1234;
    OptionVendorPtr opt_opts5678;
    for (auto opt : options) {
        ASSERT_EQ(D6O_VENDOR_OPTS, opt.first);
        OptionVendorPtr opt_opts =
            boost::dynamic_pointer_cast<OptionVendor>(opt.second);
        ASSERT_TRUE(opt_opts);
        uint32_t vendor_id = opt_opts->getVendorIds()[0];
        if (vendor_id == 1234) {
            ASSERT_FALSE(opt_opts1234);
            opt_opts1234 = opt_opts;
            continue;
        }
        ASSERT_EQ(5678, vendor_id);
        ASSERT_FALSE(opt_opts5678);
        opt_opts5678 = opt_opts;
    }

    // Verify first vendor-opts option.
    ASSERT_TRUE(opt_opts1234);
    OptionCollection subs1234 = opt_opts1234->getOptions(1234);
    ASSERT_EQ(1, subs1234.size());
    OptionPtr sub1234 = subs1234.begin()->second;
    ASSERT_TRUE(sub1234);
    EXPECT_EQ(123, sub1234->getType());
    OptionStringPtr opt_foo =
        boost::dynamic_pointer_cast<OptionString>(sub1234);
    ASSERT_TRUE(opt_foo);
    EXPECT_EQ("foo", opt_foo->getValue());

    // Verify second vendor-opts option.
    ASSERT_TRUE(opt_opts5678);
    OptionCollection subs5678 = opt_opts5678->getOptions(5678);
    ASSERT_EQ(1, subs5678.size());
    OptionPtr sub5678 = subs5678.begin()->second;
    ASSERT_TRUE(sub5678);
    EXPECT_EQ(456, sub5678->getType());
    OptionStringPtr opt_bar =
        boost::dynamic_pointer_cast<OptionString>(sub5678);
    ASSERT_TRUE(opt_bar);
    EXPECT_EQ("bar", opt_bar->getValue());
}

// Checks if it's possible to have 3 vendor-opts options with
// different vendor IDs selected using the 3 ways (vendor-opts in
// response, vendor-opts in query and vendor-class in query).
TEST_F(VendorOptsTest, threeVendors) {
    Dhcp6Client client;

    // The config defines 2 vendors with for each a vendor-opts option
    // and a custom vendor suboption, and a suboption for DOCSIS.
    string config =
        "{"
        "    \"interfaces-config\": {"
        "        \"interfaces\": [ ]"
        "    },"
        "    \"option-def\": ["
        "        {"
        "            \"name\": \"foo\","
        "            \"code\": 123,"
        "            \"space\": \"vendor-1234\","
        "            \"type\": \"string\""
        "        },"
        "        {"
        "            \"name\": \"bar\","
        "            \"code\": 456,"
        "            \"space\": \"vendor-5678\","
        "            \"type\": \"string\""
        "        },"
        "        {"
        "            \"name\": \"config-file\","
        "            \"code\": 33,"
        "            \"space\": \"vendor-4491\","
        "            \"type\": \"string\""
        "        }"
        "    ],"
        "    \"option-data\": ["
        "        {"
        "            \"name\": \"vendor-opts\","
        "            \"always-send\": true,"
        "            \"data\": \"1234\""
        "        },"
        "        {"
        "            \"name\": \"vendor-opts\","
        "            \"data\": \"5678\""
        "        },"
        "        {"
        "            \"name\": \"foo\","
        "            \"always-send\": true,"
        "            \"space\": \"vendor-1234\","
        "            \"data\": \"foo\""
        "        },"
        "        {"
        "            \"name\": \"bar\","
        "            \"always-send\": true,"
        "            \"space\": \"vendor-5678\","
        "            \"data\": \"bar\""
        "        },"
        "        {"
        "            \"name\": \"config-file\","
        "            \"space\": \"vendor-4491\","
        "            \"data\": \"normal_erouter_v6.cm\""
        "        }"
        "    ],"
        "\"subnet6\": [ { "
        "    \"pools\": [ { \"pool\": \"2001:db8::/64\" } ],"
        "    \"subnet\": \"2001:db8::/64\", "
        "    \"interface\": \"eth0\" "
        " } ]"
        "}";

    EXPECT_NO_THROW(configure(config, *client.getServer()));

    // Add a vendor-class for vendor id 5678.
    OptionVendorClassPtr cclass(new OptionVendorClass(Option::V6, 5678));
    OpaqueDataTuple tuple(OpaqueDataTuple::LENGTH_2_BYTES);
    tuple = "bar";
    cclass->addTuple(tuple);
    client.addExtraOption(cclass);

    // Add a DOCSIS vendor-opts with an ORO.
    OptionUint16ArrayPtr oro(new OptionUint16Array(Option::V6, DOCSIS3_V6_ORO));
    oro->addValue(DOCSIS3_V6_CONFIG_FILE); // Request option 33.
    OptionVendorPtr vendor(new OptionVendor(Option::V6, { VENDOR_ID_CABLE_LABS }));
    vendor->addOption(VENDOR_ID_CABLE_LABS, oro);
    client.addExtraOption(vendor);

    // Let's check whether the server is not able to process this packet.
    EXPECT_NO_THROW(client.doSolicit());
    ASSERT_TRUE(client.getContext().response_);

    // Check whether there are vendor-opts options.
    const OptionCollection& options =
        client.getContext().response_->getOptions(D6O_VENDOR_OPTS);
    ASSERT_EQ(3, options.size());
    OptionVendorPtr opt_opts1234;
    OptionVendorPtr opt_docsis;
    OptionVendorPtr opt_opts5678;
    for (auto opt : options) {
        ASSERT_EQ(D6O_VENDOR_OPTS, opt.first);
        OptionVendorPtr opt_opts =
            boost::dynamic_pointer_cast<OptionVendor>(opt.second);
        ASSERT_TRUE(opt_opts);
        uint32_t vendor_id = opt_opts->getVendorIds()[0];
        if (vendor_id == 1234) {
            ASSERT_FALSE(opt_opts1234);
            opt_opts1234 = opt_opts;
            continue;
        }
        if (vendor_id == VENDOR_ID_CABLE_LABS) {
            ASSERT_FALSE(opt_docsis);
            opt_docsis = opt_opts;
            continue;
        }
        ASSERT_EQ(5678, vendor_id);
        ASSERT_FALSE(opt_opts5678);
        opt_opts5678 = opt_opts;
    }

    // Verify first vendor-opts option.
    ASSERT_TRUE(opt_opts1234);
    OptionCollection subs1234 = opt_opts1234->getOptions(1234);
    ASSERT_EQ(1, subs1234.size());
    OptionPtr sub1234 = subs1234.begin()->second;
    ASSERT_TRUE(sub1234);
    EXPECT_EQ(123, sub1234->getType());
    OptionStringPtr opt_foo =
        boost::dynamic_pointer_cast<OptionString>(sub1234);
    ASSERT_TRUE(opt_foo);
    EXPECT_EQ("foo", opt_foo->getValue());

    // Verify DOCSIS vendor-opts option.
    ASSERT_TRUE(opt_docsis);
    OptionCollection subs_docsis = opt_docsis->getOptions(VENDOR_ID_CABLE_LABS);
    ASSERT_EQ(1, subs_docsis.size());
    OptionPtr cfile = subs_docsis.begin()->second;
    ASSERT_TRUE(cfile);
    EXPECT_EQ(33, cfile->getType());
    OptionStringPtr cfile_str = boost::dynamic_pointer_cast<OptionString>(cfile);
    ASSERT_TRUE(cfile_str);
    EXPECT_EQ("normal_erouter_v6.cm", cfile_str->getValue());

    // Verify last vendor-opts option.
    ASSERT_TRUE(opt_opts5678);
    OptionCollection subs5678 = opt_opts5678->getOptions(5678);
    ASSERT_EQ(1, subs5678.size());
    OptionPtr sub5678 = subs5678.begin()->second;
    ASSERT_TRUE(sub5678);
    EXPECT_EQ(456, sub5678->getType());
    OptionStringPtr opt_bar =
        boost::dynamic_pointer_cast<OptionString>(sub5678);
    ASSERT_TRUE(opt_bar);
    EXPECT_EQ("bar", opt_bar->getValue());
}

}
