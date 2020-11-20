// Copyright (C) 2017-2020 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>
#include <agent/ca_cfg_mgr.h>
#include <agent/ca_command_mgr.h>
#include <agent/ca_controller.h>
#include <agent/ca_process.h>
#include <asiolink/asio_wrapper.h>
#include <asiolink/interval_timer.h>
#include <asiolink/io_service.h>
#include <asiolink/testutils/test_server_unix_socket.h>
#include <cc/command_interpreter.h>
#include <cc/data.h>
#include <hooks/hooks_manager.h>
#include <hooks/callout_handle.h>
#include <hooks/library_handle.h>
#include <process/testutils/d_test_stubs.h>
#include <testutils/sandbox.h>
#include <boost/pointer_cast.hpp>
#include <gtest/gtest.h>
#include <cstdlib>
#include <functional>
#include <thread>
#include <vector>

using namespace isc::agent;
using namespace isc::asiolink;
using namespace isc::data;
using namespace isc::hooks;
using namespace isc::process;

namespace {

/// @brief Test timeout in ms.
const long TEST_TIMEOUT = 10000;

/// @brief Test fixture class for @ref CtrlAgentCommandMgr.
///
/// @todo Add tests for various commands, including the cases when the
/// commands are forwarded to other servers via unix sockets.
/// Meanwhile, this is just a placeholder for the tests.
class CtrlAgentCommandMgrTest : public DControllerTest {
public:
    isc::test::Sandbox sandbox;

    /// @brief Constructor.
    ///
    /// Deregisters all commands except 'list-commands'.
    CtrlAgentCommandMgrTest()
        : DControllerTest(CtrlAgentController::instance),
          mgr_(CtrlAgentCommandMgr::instance()) {
        mgr_.deregisterAll();
        removeUnixSocketFile();
        initProcess();
        resetExtensionIndicators();
    }

    /// @brief Destructor.
    ///
    /// Deregisters all commands except 'list-commands'.
    virtual ~CtrlAgentCommandMgrTest() {
        mgr_.deregisterAll();
        removeUnixSocketFile();
        resetExtensionIndicators();
    }

    /// @brief Verifies received answer
    ///
    /// @todo Add better checks for failure cases and for
    /// verification of the response parameters.
    ///
    /// @param answer answer to be verified
    /// @param expected_code0 code expected to be returned in first result within
    /// the answer.
    /// @param expected_code1 code expected to be returned in second result within
    /// the answer.
    /// @param expected_code2 code expected to be returned in third result within
    /// the answer.
    void checkAnswer(const ConstElementPtr& answer, const int expected_code0 = 0,
                     const int expected_code1 = -1, const int expected_code2 = -1) {
        std::vector<int> expected_codes;
        if (expected_code0 >= 0) {
            expected_codes.push_back(expected_code0);
        }

        if (expected_code1 >= 0) {
            expected_codes.push_back(expected_code1);
        }

        if (expected_code2 >= 0) {
            expected_codes.push_back(expected_code2);
        }

        int status_code;
        // There may be multiple answers returned within a list.
        std::vector<ElementPtr> answer_list = answer->listValue();

        ASSERT_EQ(expected_codes.size(), answer_list.size());
        // Check all answers.
        for (auto ans = answer_list.cbegin(); ans != answer_list.cend();
             ++ans) {
            ConstElementPtr text;
            ASSERT_NO_THROW(text = isc::config::parseAnswer(status_code, *ans));
            EXPECT_EQ(expected_codes[std::distance(answer_list.cbegin(), ans)],
                      status_code)
                << "answer contains text: " << text->stringValue();
        }
    }

    /// @brief Returns socket file path.
    ///
    /// If the KEA_SOCKET_TEST_DIR environment variable is specified, the
    /// socket file is created in the location pointed to by this variable.
    /// Otherwise, it is created in the build directory.
    std::string unixSocketFilePath() {
        std::string socket_path;
        const char* env = getenv("KEA_SOCKET_TEST_DIR");
        if (env) {
            socket_path = std::string(env) + "/test-socket";
        } else {
            socket_path = sandbox.join("test-socket");
        }
        return (socket_path);
    }

    /// @brief Removes unix socket descriptor.
    void removeUnixSocketFile() {
        static_cast<void>(remove(unixSocketFilePath().c_str()));
    }

    /// @brief Returns pointer to CtrlAgentProcess instance.
    CtrlAgentProcessPtr getCtrlAgentProcess() {
        return (boost::dynamic_pointer_cast<CtrlAgentProcess>(getProcess()));
    }

    /// @brief Returns pointer to CtrlAgentCfgMgr instance for a process.
    CtrlAgentCfgMgrPtr getCtrlAgentCfgMgr() {
        CtrlAgentCfgMgrPtr p;
        if (getCtrlAgentProcess()) {
            p = getCtrlAgentProcess()->getCtrlAgentCfgMgr();
        }
        return (p);
    }

    /// @brief Returns a pointer to the configuration context.
    CtrlAgentCfgContextPtr getCtrlAgentCfgContext() {
        CtrlAgentCfgContextPtr p;
        if (getCtrlAgentCfgMgr()) {
            p = getCtrlAgentCfgMgr()->getCtrlAgentCfgContext();
        }
        return (p);
    }

    /// @brief Adds configuration of the control socket.
    ///
    /// @param service Service for which socket configuration is to be added.
    void
    configureControlSocket(const std::string& service) {
        CtrlAgentCfgContextPtr ctx = getCtrlAgentCfgContext();
        ASSERT_TRUE(ctx);

        ElementPtr control_socket = Element::createMap();
        control_socket->set("socket-name",
                            Element::create(unixSocketFilePath()));
        ctx->setControlSocketInfo(control_socket, service);
    }

    /// @brief Create and bind server side socket.
    ///
    /// @param response Stub response to be sent from the server socket to the
    /// client.
    /// @param use_thread Indicates if the IO service will be ran in thread.
    void bindServerSocket(const std::string& response,
                          const bool use_thread = false) {
        server_socket_.reset(new test::TestServerUnixSocket(*getIOService(),
                                                            unixSocketFilePath(),
                                                            response));
        server_socket_->startTimer(TEST_TIMEOUT);
        server_socket_->bindServerSocket(use_thread);
    }

    /// @brief Creates command with no arguments.
    ///
    /// @param command_name Command name.
    /// @param service Service value to be added to the command. This value is
    /// specified as a list of comma separated values, e.g. "dhcp4, dhcp6".
    ///
    /// @return Pointer to the instance of the created command.
    ConstElementPtr createCommand(const std::string& command_name,
                                  const std::string& service) {
        ElementPtr command = Element::createMap();
        command->set("command", Element::create(command_name));

        // Only add the 'service' parameter if non-empty.
        if (!service.empty()) {
            std::string s = boost::replace_all_copy(service, ",", "\",\"");
            s = std::string("[ \"") + s + std::string("\" ]");
            command->set("service", Element::fromJSON(s));
        }

        command->set("arguments", Element::createMap());

        return (command);
    }

    /// @brief Test forwarding the command.
    ///
    /// @param server_type Server for which the client socket should be
    /// configured.
    /// @param service Service to be included in the command.
    /// @param expected_result0 Expected first result in response from the server.
    /// @param expected_result1 Expected second result in response from the server.
    /// @param expected_result2 Expected third result in response from the server.
    /// server socket after which the IO service should be stopped.
    /// @param expected_responses Number of responses after which the test finishes.
    /// @param server_response Stub response to be sent by the server.
    void testForward(const std::string& configured_service,
                     const std::string& service,
                     const int expected_result0,
                     const int expected_result1 = -1,
                     const int expected_result2 = -1,
                     const size_t expected_responses = 1,
                     const std::string& server_response = "{ \"result\": 0 }") {
        // Configure client side socket.
        configureControlSocket(configured_service);
        // Create server side socket.
        bindServerSocket(server_response, true);

        // The client side communication is synchronous. To be able to respond
        // to this we need to run the server side socket at the same time as the
        // client. Running IO service in a thread guarantees that the server
        //responds as soon as it receives the control command.
        std::thread th(std::bind(&IOService::run, getIOService().get()));


        // Wait for the IO service in thread to actually run.
        server_socket_->waitForRunning();

        ConstElementPtr command = createCommand("foo", service);
        ConstElementPtr answer = mgr_.handleCommand("foo", ConstElementPtr(),
                                                    command);

        // Stop IO service immediatelly and let the thread die.
        getIOService()->stop();

        // Wait for the thread to finish.
        th.join();

        // Cancel all asynchronous operations on the server.
        server_socket_->stopServer();

        // We have some cancelled operations for which we need to invoke the
        // handlers with the operation_aborted error code.
        getIOService()->get_io_service().reset();
        getIOService()->poll();

        EXPECT_EQ(expected_responses, server_socket_->getResponseNum());
        checkAnswer(answer, expected_result0, expected_result1, expected_result2);
    }

    /// @brief Resets indicators related to handler and callout invocation.
    ///
    /// It also removes any registered callouts.
    static void resetExtensionIndicators() {
        handler_name_ = "";
        handler_log_ = "";
        callout_name_ = "";
        processed_log_ = "";

        // Iterate over existing hook points and for each of them remove
        // callouts registered.
        for (auto const& h : ServerHooks::getServerHooksPtr()->getHookNames()) {
            HooksManager::preCalloutsLibraryHandle().deregisterAllCallouts(h);
        }
    }

    /// @brief A simple command handler that always returns an error.
    ///
    /// @param name Command name
    /// @param params Command parameters
    static ConstElementPtr my_handler(const std::string& name,
                                      const ConstElementPtr& params) {
        handler_name_ = name;
        std::ostringstream os;
        os << name << ":" << params->str();
        handler_log_ = os.str();

        ElementPtr answer = Element::createMap();
        answer->set("result", Element::create(123));
        std::string text = "test error message";
        answer->set("text", Element::create(text));

        return (answer);
    }

    /// @brief Test callback which stores callout name and passed arguments and
    /// which handles the command.
    ///
    /// @param callout_handle Handle passed by the hooks framework.
    /// @return Always 0.
    static int
    command_processed_callout(CalloutHandle& callout_handle) {
        callout_name_ = "command_processed_handler";

        std::string name;
        callout_handle.getArgument("name", name);

        ConstElementPtr arguments;
        callout_handle.getArgument("arguments", arguments);

        ConstElementPtr response;
        callout_handle.getArgument("response", response);
        std::ostringstream os;
        os << name << ":" << arguments->str() << ":" << response->str();
        processed_log_ = os.str();

        ElementPtr answer = Element::createMap();
        answer->set("result", Element::create(777));
        std::string text = "replaced response text";
        answer->set("text", Element::create(text));

        // Can't use directly answer because it does not have the right type.
        response = answer;
        callout_handle.setArgument("response", response);

        return (0);
    }

    /// @brief a convenience reference to control agent command manager
    CtrlAgentCommandMgr& mgr_;

    /// @brief Pointer to the test server unix socket.
    test::TestServerUnixSocketPtr server_socket_;

    /// @brief Holds invoked handler name.
    static std::string handler_name_;

    /// @brief Holds the arguments passed to the handler.
    static std::string handler_log_;

    /// @brief Holds invoked callout name.
    static std::string callout_name_;

    /// @brief Holds the generated command process log.
    static std::string processed_log_;
};

/// @brief Holds invoked handler name.
std::string CtrlAgentCommandMgrTest::handler_name_("");

/// @brief Holds the arguments passed to the handler.
std::string CtrlAgentCommandMgrTest::handler_log_("");

/// Holds invoked callout name.
std::string CtrlAgentCommandMgrTest::callout_name_("");

/// @brief Holds the generated command process log.
std::string CtrlAgentCommandMgrTest::processed_log_("");

/// Just a basic test checking that non-existent command is handled
/// properly.
TEST_F(CtrlAgentCommandMgrTest, bogus) {
    ConstElementPtr answer;
    EXPECT_NO_THROW(answer = mgr_.handleCommand("fish-and-chips-please",
                                                ConstElementPtr(),
                                                ConstElementPtr()));
    checkAnswer(answer, isc::config::CONTROL_RESULT_COMMAND_UNSUPPORTED);
};

/// Just a basic test checking that 'list-commands' is supported.
TEST_F(CtrlAgentCommandMgrTest, listCommands) {
    ConstElementPtr answer;
    EXPECT_NO_THROW(answer = mgr_.handleCommand("list-commands",
                                                ConstElementPtr(),
                                                ConstElementPtr()));
    checkAnswer(answer, isc::config::CONTROL_RESULT_SUCCESS);
};

/// Check that control command is successfully forwarded to the DHCPv4 server.
TEST_F(CtrlAgentCommandMgrTest, forwardToDHCPv4Server) {
    testForward("dhcp4", "dhcp4", isc::config::CONTROL_RESULT_SUCCESS);
}

/// Check that control command is successfully forwarded to the DHCPv6 server.
TEST_F(CtrlAgentCommandMgrTest, forwardToDHCPv6Server) {
    testForward("dhcp6", "dhcp6", isc::config::CONTROL_RESULT_SUCCESS);
}

/// Check that control command is successfully forwarded to the D2 server.
TEST_F(CtrlAgentCommandMgrTest, forwardToD2Server) {
    testForward("d2", "d2", isc::config::CONTROL_RESULT_SUCCESS);
}

/// Check that the same command is forwarded to multiple servers.
TEST_F(CtrlAgentCommandMgrTest, forwardToBothDHCPServers) {
    configureControlSocket("dhcp6");

    testForward("dhcp4", "dhcp4,dhcp6", isc::config::CONTROL_RESULT_SUCCESS,
                isc::config::CONTROL_RESULT_SUCCESS, -1, 2);
}

/// Check that the same command is forwarded to all servers.
TEST_F(CtrlAgentCommandMgrTest, forwardToAllServers) {
    configureControlSocket("dhcp6");
    configureControlSocket("d2");

    testForward("dhcp4", "dhcp4,dhcp6,d2", isc::config::CONTROL_RESULT_SUCCESS,
                isc::config::CONTROL_RESULT_SUCCESS,
                isc::config::CONTROL_RESULT_SUCCESS, 3);
}

/// Check that the command may forwarded to the second server even if
/// forwarding to a first server fails.
TEST_F(CtrlAgentCommandMgrTest, failForwardToServer) {
    testForward("dhcp6", "dhcp4,dhcp6",
                isc::config::CONTROL_RESULT_ERROR,
                isc::config::CONTROL_RESULT_SUCCESS);
}

/// Check that control command is not forwarded if the service is not specified.
TEST_F(CtrlAgentCommandMgrTest, noService) {
    testForward("dhcp6", "",
                isc::config::CONTROL_RESULT_COMMAND_UNSUPPORTED,
                -1, -1, 0);
}

/// Check that error is returned to the client when the server to which the
/// command was forwarded sent an invalid message.
TEST_F(CtrlAgentCommandMgrTest, invalidAnswer) {
    testForward("dhcp6", "dhcp6",
                isc::config::CONTROL_RESULT_ERROR, -1, -1, 1,
                "{ \"result\": }");
}

/// Check that connection is dropped if it takes too long. The test checks
/// client's behavior when partial JSON is returned. Client will be waiting
/// for the '}' and will timeout because it is never received.
/// @todo Currently this test is disabled because we don't have configurable
/// timeout value. It is hardcoded to 5 sec, which is too long for the
/// unit test to run.
TEST_F(CtrlAgentCommandMgrTest, DISABLED_connectionTimeout) {
    testForward("dhcp6", "dhcp6",
                isc::config::CONTROL_RESULT_ERROR, -1, -1, 1,
                "{ \"result\": 0");
}

/// Check that error is returned to the client if the forwarding socket is
/// not configured for the given service.
TEST_F(CtrlAgentCommandMgrTest, noClientSocket) {
    ConstElementPtr command = createCommand("foo", "dhcp4");
    ConstElementPtr answer = mgr_.handleCommand("foo", ConstElementPtr(),
                                                command);

    checkAnswer(answer, isc::config::CONTROL_RESULT_ERROR);
}

/// Check that error is returned to the client if the remote server to
/// which the control command is to be forwarded is not available.
TEST_F(CtrlAgentCommandMgrTest, noServerSocket) {
    configureControlSocket("dhcp6");

    ConstElementPtr command = createCommand("foo", "dhcp6");
    ConstElementPtr answer = mgr_.handleCommand("foo", ConstElementPtr(),
                                                command);

    checkAnswer(answer, isc::config::CONTROL_RESULT_ERROR);
}

// Check that list-commands command is forwarded when the service
// value is specified.
TEST_F(CtrlAgentCommandMgrTest, forwardListCommands) {
    // Configure client side socket.
    configureControlSocket("dhcp4");
    // Create server side socket.
    bindServerSocket("{ \"result\" : 3 }", true);

    // The client side communication is synchronous. To be able to respond
    // to this we need to run the server side socket at the same time.
    // Running IO service in a thread guarantees that the server responds
    // as soon as it receives the control command.
    std::thread th(std::bind(&IOService::run, getIOService().get()));

    // Wait for the IO service in thread to actually run.
    server_socket_->waitForRunning();

    ConstElementPtr command = createCommand("list-commands", "dhcp4");
    ConstElementPtr answer = mgr_.handleCommand("list-commands", ConstElementPtr(),
                                                command);

    // Stop IO service immediatelly and let the thread die.
    getIOService()->stop();

    // Wait for the thread to finish.
    th.join();

    // Cancel all asynchronous operations on the server.
    server_socket_->stopServer();

    // We have some cancelled operations for which we need to invoke the
    // handlers with the operation_aborted error code.
    getIOService()->get_io_service().reset();
    getIOService()->poll();

    // Answer of 3 is specific to the stub response we send when the
    // command is forwarded. So having this value returned means that
    // the command was forwarded as expected.
    checkAnswer(answer, 3);
}

// This test verifies that a registered handler and a callout for the
// command_processed hookpoint are invoked and can replace the command
// response content.
TEST_F(CtrlAgentCommandMgrTest, commandProcessedHook) {
    // Register callout so as we can check that it is called.
    HooksManager::preCalloutsLibraryHandle().registerCallout(
        "command_processed", command_processed_callout);

    // Install local handler.
    EXPECT_NO_THROW(mgr_.registerCommand("my-command", my_handler));

    // Now tell CtrlAgentCommandMgr to process a command.
    ElementPtr command = Element::createMap();
    command->set("command", Element::create(std::string("my-command")));
    ElementPtr params = Element::fromJSON("[ \"just\", \"some\", \"data\" ]");
    command->set("arguments", params);

    ConstElementPtr answer;
    ASSERT_NO_THROW(answer = mgr_.processCommand(command));

    // There should be an answer.
    ASSERT_TRUE(answer);

    // Make sure invoked the my_handler command handler.
    EXPECT_EQ("my-command", handler_name_);

    // Verify the handler was called with expected arguments.
    EXPECT_EQ("my-command:[ \"just\", \"some\", \"data\" ]",
              handler_log_);

    // Verify that we overrode response.
    EXPECT_EQ("{ \"result\": 777, \"text\": \"replaced response text\" }",
              answer->str());

    // Make sure invoked the command_processed callout.
    EXPECT_EQ("command_processed_handler", callout_name_);

    // Verify the callout could extract all the context arguments.
    std::string expected = "my-command:[ \"just\", \"some\", \"data\" ]:";
    expected += "[ { \"result\": 123, \"text\": \"test error message\" } ]";
    EXPECT_EQ(expected, processed_log_);
}

}
