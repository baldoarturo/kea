// Copyright (C) 2018-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <mysql/mysql_connection.h>
#include <mysql/testutils/mysql_schema.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <gtest/gtest.h>
#include <array>

using namespace isc::db;
using namespace isc::db::test;

namespace {

/// @brief RAII wrapper over MYSQL_RES obtained from MySQL library functions like
/// mysql_use_result().
struct MySqlResult {

    /// @brief Constructor
    MySqlResult(MYSQL_RES* result) : result_(result) {
    }

    /// @brief Destructor
    ~MySqlResult() {
        try {
            mysql_free_result(result_);
        } catch (...) {
        }
    }

    MYSQL_RES* const result_;
};

/// @brief Test fixture class for @c MySqlConnection class.
class MySqlConnectionTest : public ::testing::Test {
public:

    /// @brief Indexes of prepared statements used within the tests.
    enum StatementIndex {
        GET_BY_INT_VALUE,
        DELETE_BY_INT_VALUE,
        INSERT_VALUE,
        NUM_STATEMENTS
    };

    /// @brief Array of tagged MySQL statements.
    typedef std::array<TaggedStatement, NUM_STATEMENTS> TaggedStatementArray;

    /// @brief Prepared MySQL statements used in the tests.
    TaggedStatementArray tagged_statements = {{
            { GET_BY_INT_VALUE,
              "SELECT tinyint_value, int_value, bigint_value, string_value,"
              " blob_value, timestamp_value"
              " FROM mysql_connection_test WHERE int_value = ?" },

            { DELETE_BY_INT_VALUE,
              "DELETE FROM mysql_connection_test WHERE int_value = ?" },

            { INSERT_VALUE,
              "INSERT INTO mysql_connection_test (tinyint_value, int_value,"
              "bigint_value, string_value, blob_value, timestamp_value)"
              " VALUES (?, ?, ?, ?, ?, ?)" }
    }};

    /// @brief Constructor.
    ///
    /// Re-creates database schema, opens new database connection and creates
    /// prepared statements used in tests. Created schema contains a test
    /// table @c mysql_connection_test which includes 6 columns of various
    /// types.
    MySqlConnectionTest(bool const primary_key = false)
        : conn_(DatabaseConnection::parse(validMySQLConnectionString())) {

        try {
            // Open new connection.
            conn_.openDatabase();

            // Create mysql_connection_test table.
            createTestTable(primary_key);

            // In Percona XtraDB cluster, you can't do much on tables with
            // primary keys. So far the connection and the table creation have
            // been tested. Continue only if:
            // * we are in primary key mode
            // * a MySQL database other than Percona is running
            // * Percona's pxc_strict_mode is set to "DISABLED" or "PERMISSIVE"
            // The last two checks are done with inverse logic against the two
            // modes that restrict this: "ENFORCING" and "MASTER". This check is
            // to be paired inside the tests without a primary key to disable
            // those tests.
            if (!primary_key &&
                (showPxcStrictMode() == "ENFORCING" || showPxcStrictMode() == "MASTER")) {
                return;
            }

            // Created prepared statements for basic queries to test table.
            conn_.prepareStatements(tagged_statements.begin(),
                                    tagged_statements.end());
        } catch (...) {
            std::cerr << "*** ERROR: unable to open database. The test\n"
                         "*** environment is broken and must be fixed before\n"
                         "*** the MySQL tests will run correctly.\n"
                         "*** The reason for the problem is described in the\n"
                         "*** accompanying exception output.\n";
            throw;
        }
    }

    /// @brief Destructor
    ///
    /// Removes test table from the database.
    virtual ~MySqlConnectionTest() {
        try {
            conn_.rollback();
            dropTestTable();
        } catch (...) {
        }
    }

    /// @brief Creates test table @c mysql_connection_test.
    ///
    /// The new table contains 6 columns of various data types. All of
    /// the columns accept null values.
    void createTestTable(bool const primary_key = false) {
        /// @todo TIMESTAMP value lacks sub second precision because
        /// it is supported since MySQL 5.6.4, which is still not a
        /// default version on some OSes. When the subsecond precision
        /// is available on all OSes that Kea supports, the timestamp
        /// column should be turned to TIMESTAMP(6). Until then, it
        /// must remain TIMESTAMP.
        runQuery("CREATE TABLE IF NOT EXISTS mysql_connection_test ("
                 "tinyint_value TINYINT " +
                 std::string(primary_key ? "PRIMARY KEY NOT NULL," : "NULL,") +
                 "int_value INT NULL,"
                 "bigint_value BIGINT NULL,"
                 "string_value TEXT NULL,"
                 "blob_value BLOB NULL,"
                 "timestamp_value TIMESTAMP NULL"
                 ")");
    }

    /// @brief Drops test table.
    void dropTestTable() {
        runQuery("DROP TABLE IF EXISTS mysql_connection_test");
    }

    /// @brief Runs MySQL query on the opened connection.
    ///
    /// @param sql Query in the textual form.
    void runQuery(const std::string& sql) {
        MYSQL_STMT *stmt = mysql_stmt_init(conn_.mysql_);
        if (stmt == NULL) {
            isc_throw(DbOperationError, "unable to allocate MySQL prepared "
                  "statement structure, reason: " << mysql_error(conn_.mysql_));
        }

        int status = mysql_stmt_prepare(stmt, sql.c_str(), sql.length());
        if (status != 0) {
            isc_throw(DbOperationError, "unable to prepare MySQL statement <"
                      << sql << ">, reason: " << mysql_errno(conn_.mysql_));
        }

        // Execute the prepared statement.
        if (MysqlExecuteStatement(stmt) != 0) {
            isc_throw(DbOperationError, "cannot execute MySQL query <"
                  << sql << ">, reason: " << mysql_errno(conn_.mysql_));
        }

        // Discard the statement and its resources
        mysql_stmt_close(stmt);
    }


    /// @brief Tests inserting and retrieving data from the database.
    ///
    /// In this test data carried in the bindings is inserted into the database.
    /// Then this data is retrieved from the database and compared with the
    /// orginal.
    ///
    /// @param in_bindings Collection of bindings encapsulating the data to
    /// be inserted into the database and then retrieved.
    void testInsertSelect(const MySqlBindingCollection& in_bindings) {
        // Expecting 6 bindings because we have 6 columns in our table.
        ASSERT_EQ(6, in_bindings.size());
        // We are going to select by int_value so this value must not be null.
        ASSERT_FALSE(in_bindings[1]->amNull());

        // Store data in the database.
        ASSERT_NO_THROW(conn_.insertQuery(MySqlConnectionTest::INSERT_VALUE,
                                          in_bindings));

        // Create input binding for select query.
        MySqlBindingCollection bindings =
            { MySqlBinding::createInteger<uint32_t>(in_bindings[1]->getInteger<uint32_t>()) };

        // Also, create output (placeholder) bindings for receiving data.
        MySqlBindingCollection out_bindings = {
            MySqlBinding::createInteger<uint8_t>(),
            MySqlBinding::createInteger<uint32_t>(),
            MySqlBinding::createInteger<int64_t>(),
            MySqlBinding::createString(512),
            MySqlBinding::createBlob(512),
            MySqlBinding::createTimestamp()
        };

        // Execute select statement. We expect one row to be returned. For this
        // returned row the lambda provided as 4th argument should be executed.
        ASSERT_NO_THROW(conn_.selectQuery(MySqlConnectionTest::GET_BY_INT_VALUE,
                                          bindings, out_bindings,
                                          [&](MySqlBindingCollection& out_bindings) {

            // Compare received data with input data assuming they are both non-null.

            if (!out_bindings[0]->amNull() && !in_bindings[0]->amNull()) {
                EXPECT_EQ(static_cast<int>(in_bindings[0]->getInteger<uint8_t>()),
                          static_cast<int>(out_bindings[0]->getInteger<uint8_t>()));
            }

            if (!out_bindings[1]->amNull() && !in_bindings[1]->amNull()) {
                EXPECT_EQ(in_bindings[1]->getInteger<uint32_t>(),
                          out_bindings[1]->getInteger<uint32_t>());
            }

            if (!out_bindings[2]->amNull() && !in_bindings[2]->amNull()) {
                EXPECT_EQ(in_bindings[2]->getInteger<int64_t>(),
                          out_bindings[2]->getInteger<int64_t>());
            }

            if (!out_bindings[3]->amNull() && !in_bindings[3]->amNull()) {
                EXPECT_EQ(in_bindings[3]->getString(),
                          out_bindings[3]->getString());
            }

            if (!out_bindings[4]->amNull() && !in_bindings[4]->amNull()) {
                EXPECT_EQ(in_bindings[4]->getBlob(),
                          out_bindings[4]->getBlob());
            }

            if (!out_bindings[5]->amNull() && !in_bindings[5]->amNull()) {
                EXPECT_TRUE(in_bindings[5]->getTimestamp() ==
                            out_bindings[5]->getTimestamp());
            }
        }));

        // Make sure that null values were returned for columns for which null
        // was set.
        ASSERT_EQ(in_bindings.size(), out_bindings.size());
        for (auto i = 0; i < in_bindings.size(); ++i) {
            EXPECT_EQ(in_bindings[i]->amNull(), out_bindings[i]->amNull())
                << "null value test failed for binding #" << i;
        }
    }

    /// @brief Run a raw, unprepared statement and return the result.
    ///
    /// This is useful when running statements that can't be parameterized with a
    /// question mark in place of a bound variable e.g. "SHOW GLOBAL VARIABLES"
    /// and thus cannot be prepared beforehand. All the results are string, the
    /// output should be the same as that which one would see in a mysql command
    /// line client.
    ///
    /// @param statement the statement in string form
    /// @throw DbOperationError if the statement could not be run
    /// @return the list of rows, each row consisting of a list of values for
    ///     each column
    std::vector<std::vector<std::string>>
    rawStatement(std::string const& statement) const {
        // Execute a SQL statement.
        if (mysql_query(conn_.mysql_, statement.c_str())) {
            isc_throw(DbOperationError,
                      statement << ": " << mysql_error(conn_.mysql_));
        }

        // Get a result set.
        MySqlResult result(mysql_use_result(conn_.mysql_));

        // Fetch a result set.
        std::vector<std::vector<std::string>> output;
        size_t r(0);
        MYSQL_ROW row;
        size_t const column_count(mysql_num_fields(result.result_));
        while ((row = mysql_fetch_row(result.result_)) != NULL) {
            output.push_back(std::vector<std::string>());
            for (size_t i = 0; i < column_count; ++i) {
                output[r].push_back(row[i]);
            }
            ++r;
        }

        return output;
    }

    /// @brief Get pxc_strict_mode global variable from the database.
    /// For Percona, they can be: DISABLED, PERMISSIVE, ENFORCING, MASTER.
    std::string showPxcStrictMode() {
        // Store in a static variable so this only runs once per gtest binary
        // invocation.
        static std::string const pxc_strict_mode([&]() -> std::string {
            // Execute select statement. We expect one row to be returned. For
            // this returned row the lambda provided as 4th argument should be
            // executed.
            std::vector<std::vector<std::string>> const result(
                rawStatement("SHOW GLOBAL VARIABLES LIKE 'pxc_strict_mode'"));
            if (result.size() < 1 || result[0].size() < 2) {
                // Not Percona
                return "";
            }

            return result[0][1];
        }());
        return pxc_strict_mode;
    }

    /// ***          Test definitions start here. Tests are invoked          ***
    /// ***     multiple times further below in different test fixtures.     ***

    /// @brief Test that non-null values of various types can be inserted and
    /// retrieved from the dataabse.
    void select() {
        std::string blob = "myblob";
        MySqlBindingCollection in_bindings = {
            MySqlBinding::createInteger<uint8_t>(123),
            MySqlBinding::createInteger<uint32_t>(1024),
            MySqlBinding::createInteger<int64_t>(-4096),
            MySqlBinding::createString("shellfish"),
            MySqlBinding::createBlob(blob.begin(), blob.end()),
            /// @todo Change it to microsec_clock once we transition to
            /// subsecond precision.
            MySqlBinding::createTimestamp(
                boost::posix_time::second_clock::local_time()),
        };

        testInsertSelect(in_bindings);
    }

    /// @brief Test that null value can be inserted to a column having numeric
    /// type and retrieved.
    void selectNullInteger() {
        std::string blob = "myblob";
        MySqlBindingCollection in_bindings = {
            MySqlBinding::createInteger<uint8_t>(123),
            MySqlBinding::createInteger<uint32_t>(1024),
            MySqlBinding::createNull(),
            MySqlBinding::createString("shellfish"),
            MySqlBinding::createBlob(blob.begin(), blob.end()),
            /// @todo Change it to microsec_clock once we transition to
            /// subsecond precision.
            MySqlBinding::createTimestamp(
                boost::posix_time::second_clock::local_time()),
        };

        testInsertSelect(in_bindings);
    }

    /// @brief Test that null value can be inserted to a column having string
    /// type and retrieved.
    void selectNullString() {
        std::string blob = "myblob";

        MySqlBindingCollection in_bindings = {
            MySqlBinding::createInteger<uint8_t>(123),
            MySqlBinding::createInteger<uint32_t>(1024),
            MySqlBinding::createInteger<int64_t>(-4096),
            MySqlBinding::createNull(),
            MySqlBinding::createBlob(blob.begin(), blob.end()),
            /// @todo Change it to microsec_clock once we transition to
            /// subsecond precision.
            MySqlBinding::createTimestamp(
                boost::posix_time::second_clock::local_time()),
        };

        testInsertSelect(in_bindings);
    }

    /// @brief Test that null value can be inserted to a column having blob type
    /// and retrieved.
    void selectNullBlob() {
        MySqlBindingCollection in_bindings = {
            MySqlBinding::createInteger<uint8_t>(123),
            MySqlBinding::createInteger<uint32_t>(1024),
            MySqlBinding::createInteger<int64_t>(-4096),
            MySqlBinding::createString("shellfish"),
            MySqlBinding::createNull(),
            /// @todo Change it to microsec_clock once we transition to
            /// subsecond precision.
            MySqlBinding::createTimestamp(
                boost::posix_time::second_clock::local_time()),
        };

        testInsertSelect(in_bindings);
    }

    /// @brief Test that null value can be inserted to a column having timestamp
    /// type and retrieved.
    void selectNullTimestamp() {
        std::string blob = "myblob";
        MySqlBindingCollection in_bindings = {
            MySqlBinding::createInteger<uint8_t>(123),
            MySqlBinding::createInteger<uint32_t>(1024),
            MySqlBinding::createInteger<int64_t>(-4096),
            MySqlBinding::createString("shellfish"),
            MySqlBinding::createBlob(blob.begin(), blob.end()),
            MySqlBinding::createNull(),
        };

        testInsertSelect(in_bindings);
    }

    /// @brief Test that empty string and empty blob can be inserted to a
    /// database.
    void selectEmptyStringBlob() {
        std::string blob = "";
        MySqlBindingCollection in_bindings = {
            MySqlBinding::createInteger<uint8_t>(123),
            MySqlBinding::createInteger<uint32_t>(1024),
            MySqlBinding::createInteger<int64_t>(-4096),
            MySqlBinding::createString(""),
            MySqlBinding::createBlob(blob.begin(), blob.end()),
            /// @todo Change it to microsec_clock once we transition to
            /// subsecond precision.
            MySqlBinding::createTimestamp(
                boost::posix_time::second_clock::local_time()),
        };

        testInsertSelect(in_bindings);
    }

    /// @brief Test that a row can be deleted from the database.
    void deleteByValue() {
        // Insert a row with numeric values.
        MySqlBindingCollection in_bindings = {
            MySqlBinding::createInteger<uint8_t>(123),
            MySqlBinding::createInteger<uint32_t>(1024),
            MySqlBinding::createInteger<int64_t>(-4096),
            MySqlBinding::createNull(),
            MySqlBinding::createNull(),
            MySqlBinding::createNull(),
        };

        ASSERT_NO_THROW(
            conn_.insertQuery(MySqlConnectionTest::INSERT_VALUE, in_bindings));

        // This variable will be checked to see if the row has been deleted
        // from the database.
        bool deleted = false;

        // Execute delete query but use int_value of non existing row.
        // The row should not be deleted.
        in_bindings = {MySqlBinding::createInteger<uint32_t>(1)};
        ASSERT_NO_THROW(
            deleted = conn_.updateDeleteQuery(
                MySqlConnectionTest::DELETE_BY_INT_VALUE, in_bindings));
        ASSERT_FALSE(deleted);

        // This time use the correct value.
        in_bindings = {MySqlBinding::createInteger<uint32_t>(1024)};
        ASSERT_NO_THROW(
            deleted = conn_.updateDeleteQuery(
                MySqlConnectionTest::DELETE_BY_INT_VALUE, in_bindings));
        // The row should have been deleted.
        ASSERT_TRUE(deleted);

        // Let's confirm that it has been deleted by issuing a select query.
        MySqlBindingCollection out_bindings = {
            MySqlBinding::createInteger<uint8_t>(),
            MySqlBinding::createInteger<uint32_t>(),
            MySqlBinding::createInteger<int64_t>(),
            MySqlBinding::createString(512),
            MySqlBinding::createBlob(512),
            MySqlBinding::createTimestamp(),
        };

        ASSERT_NO_THROW(conn_.selectQuery(MySqlConnectionTest::GET_BY_INT_VALUE,
                                          in_bindings, out_bindings,
                                          [&deleted](MySqlBindingCollection&) {
                                              // This will be executed if the
                                              // row is returned as a result of
                                              // select query. We expect that
                                              // this is not executed.
                                              deleted = false;
                                          }));
        // Make sure that select query returned nothing.
        EXPECT_TRUE(deleted);
    }

    /// @brief Test MySQL connection.
    MySqlConnection conn_;
};

struct MySqlConnectionWithPrimaryKeyTest : MySqlConnectionTest {
    MySqlConnectionWithPrimaryKeyTest()
        : MySqlConnectionTest(/* primary_key = */ true) {
    }
};

TEST_F(MySqlConnectionTest, select) {
    if (showPxcStrictMode() == "ENFORCING" || showPxcStrictMode() == "MASTER") {
        return;
    }
    select();
}

TEST_F(MySqlConnectionTest, selectNullInteger) {
    if (showPxcStrictMode() == "ENFORCING" || showPxcStrictMode() == "MASTER") {
        return;
    }
    selectNullInteger();
}

TEST_F(MySqlConnectionTest, selectNullString) {
    if (showPxcStrictMode() == "ENFORCING" || showPxcStrictMode() == "MASTER") {
        return;
    }
    selectNullString();
}

TEST_F(MySqlConnectionTest, selectNullBlob) {
    if (showPxcStrictMode() == "ENFORCING" || showPxcStrictMode() == "MASTER") {
        return;
    }
    selectNullBlob();
}

TEST_F(MySqlConnectionTest, selectNullTimestamp) {
    if (showPxcStrictMode() == "ENFORCING" || showPxcStrictMode() == "MASTER") {
        return;
    }
    selectNullTimestamp();
}

TEST_F(MySqlConnectionTest, selectEmptyStringBlob) {
    if (showPxcStrictMode() == "ENFORCING" || showPxcStrictMode() == "MASTER") {
        return;
    }
    selectEmptyStringBlob();
}

TEST_F(MySqlConnectionTest, deleteByValue) {
    if (showPxcStrictMode() == "ENFORCING" || showPxcStrictMode() == "MASTER") {
        return;
    }
    deleteByValue();
}

TEST_F(MySqlConnectionWithPrimaryKeyTest, select) {
    select();
}

TEST_F(MySqlConnectionWithPrimaryKeyTest, selectNullInteger) {
    selectNullInteger();
}

TEST_F(MySqlConnectionWithPrimaryKeyTest, selectNullString) {
    selectNullString();
}

TEST_F(MySqlConnectionWithPrimaryKeyTest, selectNullBlob) {
    selectNullBlob();
}

TEST_F(MySqlConnectionWithPrimaryKeyTest, selectNullTimestamp) {
    selectNullTimestamp();
}

TEST_F(MySqlConnectionWithPrimaryKeyTest, selectEmptyStringBlob) {
    selectEmptyStringBlob();
}

TEST_F(MySqlConnectionWithPrimaryKeyTest, deleteByValue) {
    deleteByValue();
}

/// @brief Test fixture class for @c MySqlConnection class methods.
class MySqlSchemaTest : public ::testing::Test {
public:

    /// @brief Constructor.
    MySqlSchemaTest() {
        // Ensure we have the proper schema.
        createMySQLSchema();
    }

    /// @brief Destructor.
    virtual ~MySqlSchemaTest() {
        try {
            destroyMySQLSchema();
        } catch (...) {
        }
    }
};

/// @brief Check that getVersion() returns the expected version.
TEST_F(MySqlSchemaTest, checkVersion) {
    // Check version
    auto parameters = DatabaseConnection::parse(validMySQLConnectionString());
    std::pair<uint32_t, uint32_t> version;
    ASSERT_NO_THROW(version = MySqlConnection::getVersion(parameters));
    EXPECT_EQ(MYSQL_SCHEMA_VERSION_MAJOR, version.first);
    EXPECT_EQ(MYSQL_SCHEMA_VERSION_MINOR, version.second);
}

}  // namespace
