// Copyright (C) 2022 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>
#include <database/db_exceptions.h>
#include <database/server.h>
#include <dhcpsrv/cfgmgr.h>
#include <dhcpsrv/config_backend_dhcp6_mgr.h>
#include <dhcpsrv/testutils/generic_cb_dhcp6_unittest.h>
#include <dhcpsrv/testutils/generic_cb_recovery_unittest.h>
#include <dhcpsrv/testutils/pgsql_generic_backend_unittest.h>
#include <dhcpsrv/testutils/test_utils.h>
#include <pgsql_cb_dhcp6.h>
#include <pgsql/testutils/pgsql_schema.h>
#include <testutils/multi_threading_utils.h>
#include <testutils/gtest_utils.h>

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <gtest/gtest.h>
#include <map>
#include <sstream>

using namespace isc;
using namespace isc::util;
using namespace isc::asiolink;
using namespace isc::db;
using namespace isc::db::test;
using namespace isc::data;
using namespace isc::dhcp;
using namespace isc::dhcp::test;
using namespace isc::process;
using namespace isc::test;
namespace ph = std::placeholders;

namespace {

/// @brief Test implementation of the PostgreSQL configuration backend.
///
/// It exposes protected members of the @c PgSqlConfigBackendDHCPv6.
class TestPgSqlConfigBackendDHCPv6 : public PgSqlConfigBackendDHCPv6 {
public:

    /// @brief Constructor.
    ///
    /// @param parameters A data structure relating keywords and values
    /// concerned with the database.
    explicit TestPgSqlConfigBackendDHCPv6(const DatabaseConnection::ParameterMap& parameters)
        : PgSqlConfigBackendDHCPv6(parameters) {
    }

    using PgSqlConfigBackendDHCPv6::base_impl_;
};

/// @brief Test fixture class for @c PgSqlConfigBackendDHCPv6.
class PgSqlConfigBackendDHCPv6Test : public GenericConfigBackendDHCPv6Test {
public:
    /// @brief Constructor.
    PgSqlConfigBackendDHCPv6Test() {}

    /// @brief Destructor.
    virtual ~PgSqlConfigBackendDHCPv6Test() {}

    /// @brief Creates the PostgreSQL back end schema
    virtual void createSchema() {
        createPgSQLSchema();
    }

    /// @brief Destroys the PostgreSQL back end schema
    virtual void destroySchema() {
        destroyPgSQLSchema();
    }

    /// @brief Returns a valid PostgreSQL back end specific connection
    /// string
    std::string validConnectionString() {
        return (validPgSQLConnectionString());
    }

    /// @brief Instantiates an instance of a PostgreSQL DHCPv6 configuration
    /// back end.
    ///
    /// @params Connection parameters describing the back end to create.
    ///
    /// @return Pointer to the newly created back end instance.
    ConfigBackendDHCPv6Ptr backendFactory(db::DatabaseConnection::ParameterMap&
                                          params) {

        return (ConfigBackendDHCPv6Ptr(new TestPgSqlConfigBackendDHCPv6(params)));
    }

    /// @brief Counts rows in a selected table in PostgreSQL database.
    ///
    /// This method can be used to verify that some configuration elements were
    /// deleted from a selected table as a result of cascade delete or a trigger.
    /// For example, deleting a subnet should trigger deletion of its address
    /// pools and options. By counting the rows on each table we can determine
    /// whether the deletion took place on all tables for which it was expected.
    ///
    /// @param table Table name.
    /// @return Number of rows in the specified table.
    size_t countRows(const std::string& table) const {
        auto p = boost::dynamic_pointer_cast<TestPgSqlConfigBackendDHCPv6>(cbptr_);
        if (!p) {
            ADD_FAILURE() << "cbptr_ does not cast to TestPgSqlConfigBackendDHCPv6";
            return (0);
        }

        // Reuse the existing connection of the backend.
        auto impl = boost::dynamic_pointer_cast<PgSqlConfigBackendImpl>(p->base_impl_);
        auto& conn = impl->conn_;

        return (PgSqlGenericBackendTest::countRows(conn, table));
    }
};

TEST_F(PgSqlConfigBackendDHCPv6Test, getType) {
    getTypeTest("postgresql");
}

TEST_F(PgSqlConfigBackendDHCPv6Test, getHost) {
    getHostTest();
}

TEST_F(PgSqlConfigBackendDHCPv6Test, getPort) {
    getPortTest();
}

/// @brief Test fixture for verifying database connection loss-recovery
/// behavior.
class PgSqlConfigBackendDHCPv6DbLostCallbackTest : public GenericConfigBackendDbLostCallbackTest {
public:
    /// @brief Constructor
    PgSqlConfigBackendDHCPv6DbLostCallbackTest() {};

    /// @brief Destructor
    virtual ~PgSqlConfigBackendDHCPv6DbLostCallbackTest() {};

    /// @brief Creates the PostgreSQL CB schema.
    virtual void createSchema() {
        createPgSQLSchema();
    }

    /// @brief Destroys the PostgreSQL CB schema.
    virtual void destroySchema() {
        destroyPgSQLSchema();
    }

    /// @brief Method which returns a valid back end specific connection
    /// string
    virtual std::string validConnectionString() {
        return (validPgSQLConnectionString());
    }

    /// @brief Method which returns an invalid back end specific connection
    /// string.
    virtual std::string invalidConnectionString() {
        return (connectionString(PGSQL_VALID_TYPE, INVALID_NAME, VALID_HOST,
                                 VALID_USER, VALID_PASSWORD));
    }

    /// @brief Registers PostgreSQL as a CB backend type.
    virtual void registerBackendType() {
        isc::dhcp::PgSqlConfigBackendDHCPv6::registerBackendType();
    }

    /// @brief Unregisters PostgreSQL as a CB backend type.
    virtual void unregisterBackendType() {
        isc::dhcp::PgSqlConfigBackendDHCPv6::unregisterBackendType();
    }

    /// @brief Sets the IOService instance in the CB implementation object.
    ///
    /// @param io_service pointer to the IOService instance to use. It may be
    /// an empty pointer.
    virtual void setConfigBackendImplIOService(isc::asiolink::IOServicePtr io_service) {
        isc::dhcp::PgSqlConfigBackendImpl::setIOService(io_service);
    }

    /// @brief  Attempts to add a backend instance to the CB manager.
    ///
    /// @param access Connection access string containing the database
    /// connetion parameters.
    virtual void addBackend(const std::string& access) {
        ConfigBackendDHCPv6Mgr::instance().addBackend(access);
    }

    /// @brief Fetches a collection of all the servers currently in
    /// the CB database.  This function is used to check the operability
    /// of the CB backend.
    ServerCollection getAllServers() {
        return (ConfigBackendDHCPv6Mgr::instance().getPool()->getAllServers6(BackendSelector()));
    }
};

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testNoCallbackOnOpenFailure) {
    MultiThreadingTest mt(false);
    testNoCallbackOnOpenFailure();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testNoCallbackOnOpenFailureMultiThreading) {
    MultiThreadingTest mt(true);
    testNoCallbackOnOpenFailure();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testDbLostAndRecoveredCallback) {
    MultiThreadingTest mt(false);
    testDbLostAndRecoveredCallback();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testDbLostAndRecoveredCallbackMultiThreading) {
    MultiThreadingTest mt(true);
    testDbLostAndRecoveredCallback();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testDbLostAndFailedCallback) {
    MultiThreadingTest mt(false);
    testDbLostAndFailedCallback();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testDbLostAndFailedCallbackMultiThreading) {
    MultiThreadingTest mt(true);
    testDbLostAndFailedCallback();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testDbLostAndRecoveredAfterTimeoutCallback) {
    MultiThreadingTest mt(false);
    testDbLostAndRecoveredAfterTimeoutCallback();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testDbLostAndRecoveredAfterTimeoutCallbackMultiThreading) {
    MultiThreadingTest mt(true);
    testDbLostAndRecoveredAfterTimeoutCallback();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testDbLostAndFailedAfterTimeoutCallback) {
    MultiThreadingTest mt(false);
    testDbLostAndFailedAfterTimeoutCallback();
}

TEST_F(PgSqlConfigBackendDHCPv6DbLostCallbackTest, testDbLostAndFailedAfterTimeoutCallbackMultiThreading) {
    MultiThreadingTest mt(true);
    testDbLostAndFailedAfterTimeoutCallback();
}

}
