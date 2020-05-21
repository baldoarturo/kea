// Copyright (C) 2019-2020 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <config.h>

#include <util/multi_threading_mgr.h>

namespace isc {
namespace util {

MultiThreadingMgr::MultiThreadingMgr()
    : enabled_(false), thread_pool_size_(0), config_locked_(false) {
}

MultiThreadingMgr::~MultiThreadingMgr() {
}

MultiThreadingMgr&
MultiThreadingMgr::instance() {
    static MultiThreadingMgr manager;
    return (manager);
}

bool
MultiThreadingMgr::getMode() const {
    return (enabled_);
}

void
MultiThreadingMgr::setMode(bool enabled) {
    enabled_ = enabled;
}

void
MultiThreadingMgr::enterCriticalSection() {
    stopPktProcessing();
}

void
MultiThreadingMgr::exitCriticalSection() {
    startPktProcessing();
}

bool
MultiThreadingMgr::isInCriticalSection() const {
    return (MultiThreadingCriticalSectionBase::getCriticalSectionCount() != 0);
}

ThreadPool<std::function<void()>>&
MultiThreadingMgr::getThreadPool() {
    return thread_pool_;
}

uint32_t
MultiThreadingMgr::getThreadPoolSize() const {
    return (thread_pool_size_);
}

void
MultiThreadingMgr::setThreadPoolSize(uint32_t size) {
    thread_pool_size_ = size;
}

uint32_t
MultiThreadingMgr::getPacketQueueSize() {
    return (thread_pool_.getMaxQueueSize());
}

void
MultiThreadingMgr::setPacketQueueSize(uint32_t size) {
    thread_pool_.setMaxQueueSize(size);
}

uint32_t
MultiThreadingMgr::detectThreadCount() {
    return (std::thread::hardware_concurrency());
}

void
MultiThreadingMgr::apply(bool enabled, uint32_t thread_count, uint32_t queue_size) {
    // check the enabled flag
    if (enabled) {
        // check for auto scaling (enabled flag true but thread_count 0)
        if (!thread_count) {
            // might also return 0
            thread_count = MultiThreadingMgr::detectThreadCount();
        }
    } else {
        thread_count = 0;
        queue_size = 0;
    }
    // check enabled flag and explicit number of threads or system supports
    // hardware concurrency
    if (thread_count) {
        if (thread_pool_.size()) {
            thread_pool_.stop();
        }
        setThreadPoolSize(thread_count);
        setPacketQueueSize(queue_size);
        setMode(true);
        if (!isInCriticalSection()) {
            thread_pool_.start(thread_count);
        }
    } else {
        thread_pool_.reset();
        setMode(false);
        setThreadPoolSize(thread_count);
        setPacketQueueSize(queue_size);
    }
}

bool
MultiThreadingMgr::getConfigLock() const {
    return (config_locked_);
}

void
MultiThreadingMgr::setConfigLock(bool enabled) {
    config_locked_ = enabled;
}

void
MultiThreadingMgr::stopPktProcessing() {
    if (getMode() && getThreadPoolSize() && !isInCriticalSection()) {
        thread_pool_.stop();
    }
}

void
MultiThreadingMgr::startPktProcessing() {
    if (getMode() && getThreadPoolSize() && !isInCriticalSection()) {
        thread_pool_.start(getThreadPoolSize());
    }
}

template<>
void
CriticalSectionBase<MultiThreadingCriticalSectionBase>::lock() {
    MultiThreadingMgr::instance().enterCriticalSection();
}

template<>
void
CriticalSectionBase<MultiThreadingCriticalSectionBase>::unlock() {
    MultiThreadingMgr::instance().exitCriticalSection();
}

template<>
void
CriticalSectionBase<ConfigurationCriticalSectionBase>::lock() {
    if (!ConfigurationCriticalSectionBase::getCriticalSectionCount()) {
        MultiThreadingMgr::instance().setConfigLock(true);
    }
}

template<>
void
CriticalSectionBase<ConfigurationCriticalSectionBase>::unlock() {
    if (!ConfigurationCriticalSectionBase::getCriticalSectionCount()) {
        MultiThreadingMgr::instance().setConfigLock(false);
    }
}

}  // namespace util
}  // namespace isc
