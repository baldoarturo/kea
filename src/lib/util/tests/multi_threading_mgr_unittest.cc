// Copyright (C) 2019-2020 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <exceptions/exceptions.h>
#include <util/multi_threading_mgr.h>

#include <gtest/gtest.h>

using namespace isc::util;
using namespace isc;

/// @brief Verifies that the default mode is false (MT disabled).
TEST(MultiThreadingMgrTest, defaultMode) {
    // MT should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().getMode());
}

/// @brief Verifies that the default configuration lock flag is false.
TEST(MultiThreadingMgrTest, defaultConfigurationLock) {
    // configuration lock flag should be unset
    EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
}

/// @brief Verifies that the mode setter works.
TEST(MultiThreadingMgrTest, setMode) {
    // enable MT
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setMode(true));
    // MT should be enabled
    EXPECT_TRUE(MultiThreadingMgr::instance().getMode());
    // disable MT
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setMode(false));
    // MT should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().getMode());
}

/// @brief Verifies that the configuration lock setter works.
TEST(MultiThreadingMgrTest, setConfigLock) {
    // enable configuration lock
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setConfigLock(true));
    // configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // disable configuration lock
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setConfigLock(false));
    // configuration lock flag should be unset
    EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
}

/// @brief Verifies that accessing the thread pool works.
TEST(MultiThreadingMgrTest, threadPool) {
    // get the thread pool
    EXPECT_NO_THROW(MultiThreadingMgr::instance().getThreadPool());
}

/// @brief Verifies that the thread pool size setter works.
TEST(MultiThreadingMgrTest, threadPoolSize) {
    // default thread count is 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
    // set thread count to 16
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setThreadPoolSize(16));
    // thread count should be 16
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 16);
    // set thread count to 0
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setThreadPoolSize(0));
    // thread count should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
}

/// @brief Verifies that the packet queue size setter works.
TEST(MultiThreadingMgrTest, packetQueueSize) {
    // default queue size is 0
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
    // thread pool queue size is 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPool().getMaxQueueSize(), 0);
    // set queue size to 16
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setPacketQueueSize(16));
    // queue size should be 16
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 16);
    // thread pool queue size should be 16
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPool().getMaxQueueSize(), 16);
    // set queue size to 0
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setPacketQueueSize(0));
    // queue size should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
    // thread queue size should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPool().getMaxQueueSize(), 0);
}

/// @brief Verifies that detecting thread count works.
TEST(MultiThreadingMgrTest, detectThreadCount) {
    // detecting thread count should work
    EXPECT_NE(MultiThreadingMgr::detectThreadCount(), 0);
}

/// @brief Verifies that apply settings works.
TEST(MultiThreadingMgrTest, applyConfig) {
    // get the thread pool
    auto& thread_pool = MultiThreadingMgr::instance().getThreadPool();
    // MT should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().getMode());
    // default thread count is 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
    // thread pool should be stopped
    EXPECT_EQ(thread_pool.size(), 0);
    // enable MT with 16 threads and queue size 256
    EXPECT_NO_THROW(MultiThreadingMgr::instance().apply(true, 16, 256));
    // MT should be enabled
    EXPECT_TRUE(MultiThreadingMgr::instance().getMode());
    // thread count should be 16
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 16);
    // queue size should be 256
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
    // thread pool should be started
    EXPECT_EQ(thread_pool.size(), 16);
    // disable MT
    EXPECT_NO_THROW(MultiThreadingMgr::instance().apply(false, 16, 256));
    // MT should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().getMode());
    // thread count should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
    // queue size should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
    // thread pool should be stopped
    EXPECT_EQ(thread_pool.size(), 0);
    // enable MT with auto scaling
    EXPECT_NO_THROW(MultiThreadingMgr::instance().apply(true, 0, 0));
    // MT should be enabled
    EXPECT_TRUE(MultiThreadingMgr::instance().getMode());
    // thread count should be detected automatically
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), MultiThreadingMgr::detectThreadCount());
    // thread pool should be started
    EXPECT_EQ(thread_pool.size(), MultiThreadingMgr::detectThreadCount());
    // disable MT
    EXPECT_NO_THROW(MultiThreadingMgr::instance().apply(false, 0, 0));
    // MT should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().getMode());
    // thread count should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
    // thread pool should be stopped
    EXPECT_EQ(thread_pool.size(), 0);
}

/// @brief Verifies that the multi threading critical section works.
TEST(MultiThreadingMgrTest, multiThreadingCriticalSection) {
    // get the thread pool
    auto& thread_pool = MultiThreadingMgr::instance().getThreadPool();
    // thread pool should be stopped
    EXPECT_EQ(thread_pool.size(), 0);
    // critical section should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().isInCriticalSection());
    // critical section count should be 0
    EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 0);
    // the configuration lock flag should be unset
    EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // lock configuration
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setConfigLock(true));
    // apply multi-threading configuration with 16 threads and queue size 256
    MultiThreadingMgr::instance().apply(true, 16, 256);
    // thread count should match
    EXPECT_EQ(thread_pool.size(), 16);
    // thread count should be 16
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 16);
    // queue size should be 256
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
    // critical section should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().isInCriticalSection());
    // critical section count should be 0
    EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 0);
    // the configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // use scope to test constructor and destructor
    {
        MultiThreadingCriticalSection cs;
        // critical section should be enabled
        EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
        // critical section count should be 1
        EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 1);
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 16
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 16);
        // queue size should be 256
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
        // use scope to test constructor and destructor
        {
            MultiThreadingCriticalSection inner_cs;
            // critical section should be enabled
            EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
            // critical section count should be 2
            EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 2);
            // the configuration lock flag should be unset
            EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
            // critical section count should be 2
            EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 2);
            // thread pool should be stopped
            EXPECT_EQ(thread_pool.size(), 0);
            // thread count should be 16
            EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 16);
            // queue size should be 256
            EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
        }
        // critical section should be enabled
        EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
        // critical section count should be 1
        EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 1);
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 16
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 16);
        // queue size should be 256
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
    }
    // critical section should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().isInCriticalSection());
    // critical section count should be 0
    EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 0);
    // the configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // thread count should match
    EXPECT_EQ(thread_pool.size(), 16);
    // thread count should be 16
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 16);
    // queue size should be 256
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
    // use scope to test constructor and destructor
    {
        MultiThreadingCriticalSection cs;
        // critical section should be enabled
        EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
        // critical section count should be 1
        EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 1);
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 16
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 16);
        // queue size should be 256
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
        // apply multi-threading configuration with 64 threads and queue size 4
        MultiThreadingMgr::instance().apply(true, 64, 4);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 64
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 64);
        // queue size should be 4
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 4);
    }
    // critical section should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().isInCriticalSection());
    // critical section count should be 0
    EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 0);
    // the configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // thread count should match
    EXPECT_EQ(thread_pool.size(), 64);
    // thread count should be 64
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 64);
    // queue size should be 4
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 4);
    // use scope to test constructor and destructor
    {
        MultiThreadingCriticalSection cs;
        // critical section should be enabled
        EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
        // critical section count should be 1
        EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 1);
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 64
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 64);
        // queue size should be 4
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 4);
        // apply multi-threading configuration with 0 threads
        MultiThreadingMgr::instance().apply(false, 64, 256);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 0
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
        // queue size should be 0
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
    }
    // critical section should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().isInCriticalSection());
    // critical section count should be 0
    EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 0);
    // the configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // thread count should match
    EXPECT_EQ(thread_pool.size(), 0);
    // thread count should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
    // queue size should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
    // use scope to test constructor and destructor
    {
        MultiThreadingCriticalSection cs;
        // critical section should be enabled
        EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
        // critical section count should be 1
        EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 1);
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 0
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
        // queue size should be 0
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
        // use scope to test constructor and destructor
        {
            MultiThreadingCriticalSection inner_cs;
            // critical section should be enabled
            EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
            // critical section count should be 2
            EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 2);
            // the configuration lock flag should be unset
            EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
            // critical section count should be 2
            EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 2);
            // thread pool should be stopped
            EXPECT_EQ(thread_pool.size(), 0);
            // thread count should be 0
            EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
            // queue size should be 0
            EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
        }
        // critical section should be enabled
        EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
        // critical section count should be 1
        EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 1);
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 0
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
        // queue size should be 0
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
    }
    // critical section should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().isInCriticalSection());
    // critical section count should be 0
    EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 0);
    // the configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // thread count should match
    EXPECT_EQ(thread_pool.size(), 0);
    // thread count should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 0);
    // queue size should be 0
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 0);
    // use scope to test constructor and destructor
    {
        MultiThreadingCriticalSection cs;
        // critical section should be enabled
        EXPECT_TRUE(MultiThreadingMgr::instance().isInCriticalSection());
        // critical section count should be 1
        EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 1);
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // apply multi-threading configuration with 64 threads
        MultiThreadingMgr::instance().apply(true, 64, 256);
        // thread pool should be stopped
        EXPECT_EQ(thread_pool.size(), 0);
        // thread count should be 64
        EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 64);
        // queue size should be 256
        EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
    }
    // critical section should be disabled
    EXPECT_FALSE(MultiThreadingMgr::instance().isInCriticalSection());
    // critical section count should be 0
    EXPECT_EQ(MultiThreadingCriticalSectionBase::getCriticalSectionCount(), 0);
    // the configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // thread count should match
    EXPECT_EQ(thread_pool.size(), 64);
    // thread count should be 64
    EXPECT_EQ(MultiThreadingMgr::instance().getThreadPoolSize(), 64);
    // queue size should be 256
    EXPECT_EQ(MultiThreadingMgr::instance().getPacketQueueSize(), 256);
    // apply multi-threading configuration with 0 threads
    MultiThreadingMgr::instance().apply(false, 0, 0);
    // unlock configuration
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setConfigLock(false));
}

/// @brief Verifies that the configuration critical section works.
TEST(MultiThreadingMgrTest, configurationCriticalSection) {
    // the configuration lock flag should be unset
    EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // lock configuration
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setConfigLock(true));
    // the configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // use scope to test constructor and destructor
    {
        ConfigurationCriticalSection cs;
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
        // use scope to test constructor and destructor
        {
            ConfigurationCriticalSection inner_cs;
            // the configuration lock flag should be unset
            EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
            // critical section count should be 2
            EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 2);
        }
        // the configuration lock flag should be unset
        EXPECT_FALSE(MultiThreadingMgr::instance().getConfigLock());
        // critical section count should be 1
        EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 1);
    }
    // the configuration lock flag should be set
    EXPECT_TRUE(MultiThreadingMgr::instance().getConfigLock());
    // critical section count should be 0
    EXPECT_EQ(ConfigurationCriticalSectionBase::getCriticalSectionCount(), 0);
    // unlock configuration
    EXPECT_NO_THROW(MultiThreadingMgr::instance().setConfigLock(false));
}

/// @brief Verifies that the configuration lock checker works.
TEST(MultiThreadingMgrTest, configurationLockChecker) {
    // store a lambda
    std::function<void()> configuration_function = []() { ReadOnlyConfigProbe ck; };
    // calling function with configuration lock unset should not throw
    EXPECT_NO_THROW(configuration_function());
    // lock configuration
    MultiThreadingMgr::instance().setConfigLock(true);
    // calling function with configuration lock set should throw
    EXPECT_THROW(configuration_function(), isc::InvalidOperation);
    // unlock configuration
    MultiThreadingMgr::instance().setConfigLock(false);
    // calling function with configuration lock unset should not throw
    EXPECT_NO_THROW(configuration_function());
}
