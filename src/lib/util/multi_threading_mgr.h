// Copyright (C) 2019-2021 Internet Systems Consortium, Inc. ("ISC")
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MULTI_THREADING_MGR_H
#define MULTI_THREADING_MGR_H

#include <util/thread_pool.h>
#include <functional>
#include <list>

#include <boost/noncopyable.hpp>

#include <stdint.h>

namespace isc {
namespace util {


/// @brief Embodies a named pair of CriticalSection callbacks.
///
/// This class associates a pair of callbacks, one to be invoked
/// upon CriticalSection entry and the other invoked upon
/// CriticalSection exit, with name.  The name allows the pair
/// to be uniquely identified such that they can be added and
/// removed as needed.
struct CSCallbackPair {
    /// @brief Defines a callback as a simple void() functor.
    typedef std::function<void()> Callback;

    /// @brief Constructor
    ///
    /// @param name Name by which the callbacks can be found.
    /// @param entry_cb Callback to invoke upon CriticalSection entry.
    /// @param entry_cb Callback to invoke upon CriticalSection exit.
    CSCallbackPair(const std::string& name, const Callback& entry_cb,
                   const Callback& exit_cb)
        : name_(name), entry_cb_(entry_cb), exit_cb_(exit_cb) {}

    /// @brief Name by which the callback can be found.
    std::string name_;

    /// @brief Entry point callback associated with name.
    Callback entry_cb_;

    /// @brief Exit point callback associated with name.
    Callback exit_cb_;
};

/// @brief Maintains list of unique CSCallbackPairs.
///
/// The list emphasizes iteration order and speed over
/// retrieval by name. When iterating over the list of
/// callback pairs, they are returned in the order they were
/// added, not by name.
class CSCallbackPairList {
public:
    /// @brief Constructor.
    CSCallbackPairList() {}

    /// @brief Adds a callback pair to the list.
    ///
    /// @param name Name of the callback to add.
    /// @param entry_cb Callback to add.
    /// @param exit_cb Callback to add.
    ///
    /// @throw BadValue if the name is already in the list,
    /// the name is blank, or either callback is empty.
    void addCallbackPair(const std::string& name,
                         const CSCallbackPair::Callback& entry_cb,
                         const CSCallbackPair::Callback& exit_cb);

    /// @brief Removes a callback pair from the list.
    ///
    /// @param name Name of the callback to remove.
    /// If no such callback exists, it simply returns.
    void removeCallbackPair(const std::string& name);

    /// @brief Removes all callbacks from the list.
    void removeAll();

    /// @brief Fetches the list of callback pairs.
    const std::list<CSCallbackPair>& getCallbackPairs();

private:
    /// @brief The list of callback pairs.
    std::list<CSCallbackPair> cb_pairs_;
};

/// @brief Multi Threading Manager.
///
/// This singleton class holds the multi-threading mode.
///
/// The standard way to use it is:
/// @code
/// if (MultiThreadingMgr::instance().getMode()) {
///     multi-threaded code
/// } else {
///     single-threaded code
/// }
/// @endcode
///
/// For instance for a class protected by its mutex:
/// @code
/// namespace locked {
///     void foo() { ... }
/// } // end of locked namespace
///
/// void foo() {
///     if (MultiThreadingMgr::instance().getMode()) {
///         lock_guard<mutex> lock(mutex_);
///         locked::foo();
///     } else {
///         locked::foo();
///     }
/// }
/// @endcode
class MultiThreadingMgr : public boost::noncopyable {
public:

    /// @brief Returns a single instance of Multi Threading Manager.
    ///
    /// MultiThreadingMgr is a singleton and this method is the only way
    /// of accessing it.
    ///
    /// @return the single instance.
    static MultiThreadingMgr& instance();

    /// @brief Get the multi-threading mode.
    ///
    /// @return The current multi-threading mode: true if multi-threading is
    /// enabled, false otherwise.
    bool getMode() const;

    /// @brief Set the multi-threading mode.
    ///
    /// @param enabled The new mode.
    void setMode(bool enabled);

    /// @brief Enter critical section.
    ///
    /// When entering @ref MultiThreadingCriticalSection, increment internal
    /// counter so that any configuration change that might start the packet
    /// thread pool is delayed until exiting the respective section.
    /// If the internal counter is 0, then stop the thread pool.
    void enterCriticalSection();

    /// @brief Exit critical section.
    ///
    /// When exiting @ref MultiThreadingCriticalSection, decrement internal
    /// counter so that the dhcp thread pool can be started according to the
    /// new configuration.
    /// If the internal counter is 0, then start the thread pool.
    void exitCriticalSection();

    /// @brief Is in critical section flag.
    ///
    /// @return The critical section flag.
    bool isInCriticalSection();

    /// @brief Get the dhcp thread pool.
    ///
    /// @return The dhcp thread pool.
    ThreadPool<std::function<void()>>& getThreadPool();

    /// @brief Get the configured dhcp thread pool size.
    ///
    /// @return The dhcp thread pool size.
    uint32_t getThreadPoolSize() const;

    /// @brief Set the configured dhcp thread pool size.
    ///
    /// @param size The dhcp thread pool size.
    void setThreadPoolSize(uint32_t size);

    /// @brief Get the configured dhcp packet queue size.
    ///
    /// @return The dhcp packet queue size.
    uint32_t getPacketQueueSize();

    /// @brief Set the configured dhcp packet queue size.
    ///
    /// @param size The dhcp packet queue size.
    void setPacketQueueSize(uint32_t size);

    /// @brief The system current detected hardware concurrency thread count.
    ///
    /// This function will return 0 if the value can not be determined.
    ///
    /// @return The thread count.
    static uint32_t detectThreadCount();

    /// @brief Apply the multi-threading related settings.
    ///
    /// @param enabled The enabled flag: true if multi-threading is enabled,
    /// false otherwise.
    /// @param thread_count The desired number of threads: non 0 if explicitly
    /// configured, 0 if auto scaling is desired
    /// @param queue_size The desired thread queue size: non 0 if explicitly
    /// configured, 0 for unlimited size
    void apply(bool enabled, uint32_t thread_count, uint32_t queue_size);

    /// @brief Adds a pair of callbacks to the list of CriticalSection callbacks.
    ///
    /// @note Callbacks must be exception-safe, handling any errors themselves.
    ///
    /// @param name Name of the set of callbacks. This value is used by the
    /// callback owner to add and remove them. Duplicates are not allowed.
    /// @param entry_cb Callback to invoke upon CriticalSection entry. Cannot be
    /// empty.
    /// @param exit_cb Callback to invoke upon CriticalSection exit. Cannot be
    /// empty.
    void addCriticalSectionCallbacks(const std::string& name,
                                     const CSCallbackPair::Callback& entry_cb,
                                     const CSCallbackPair::Callback& exit_cb);

    /// @brief Removes the set of callbacks associated with a given name
    /// from the list of CriticalSection callbacks.
    ///
    /// If the name is not found in the list, it simply returns, otherwise
    /// both callbacks registered under the name are removed.
    ///
    /// @param name Name of the set of callbacks to remove.
    void removeCriticalSectionCallbacks(const std::string& name);

    /// @brief Removes all callbacks in the list of CriticalSection callbacks.
    void removeAllCriticalSectionCallbacks();

protected:

    /// @brief Constructor.
    MultiThreadingMgr();

    /// @brief Destructor.
    virtual ~MultiThreadingMgr() = default;

private:

    /// @brief Class method stops non-critical processing.
    ///
    /// Stops the DHCP thread pool if it's running and invokes
    /// all CriticalSection entry callbacks.  Has no effect
    /// in single-threaded mode.
    ///
    /// @note This function swallows exceptions thrown by exit
    /// callbacks without logging to avoid breaking the CS
    /// chain.
    void stopProcessing();

    /// @brief Class method (re)starts non-critical processing.
    ///
    /// Starts the DHCP thread pool according to current configuration,
    /// and invokes all CriticalSection exit callbacks. Has no effect
    /// in single-threaded mode.
    ///
    /// @note This function swallows exceptions thrown by entry
    /// callbacks without logging to avoid breaking the CS
    /// chain.
    void startProcessing();

    /// @brief The current multi-threading mode.
    ///
    /// The multi-threading flag: true if multi-threading is enabled, false
    /// otherwise
    bool enabled_;

    /// @brief The critical section count.
    ///
    /// In case the configuration is applied within a
    /// @ref MultiThreadingCriticalSection, the thread pool should not be
    /// started until leaving the respective section.
    /// This handles multiple interleaved sections.
    uint32_t critical_section_count_;

    /// @brief The configured size of the dhcp thread pool.
    uint32_t thread_pool_size_;

    /// @brief Packet processing thread pool.
    ThreadPool<std::function<void()>> thread_pool_;

    /// @brief List of CriticalSection entry and exit callback pairs.
    CSCallbackPairList cs_callbacks_;
};

/// @note: everything here MUST be used ONLY from the main thread.
/// When called from a thread of the pool it can deadlock.

/// @brief RAII class creating a critical section.
///
/// @note: the multi-threading mode MUST NOT be changed in the RAII
/// @c MultiThreadingCriticalSection body.
/// @note: starting and stopping the dhcp thread pool should be handled
/// in the main thread, if done on one of the processing threads will cause a
/// deadlock.
/// This is mainly useful in hook commands which handle configuration
/// changes.
class MultiThreadingCriticalSection : public boost::noncopyable {
public:

    /// @brief Constructor.
    ///
    /// Entering the critical section. The dhcp thread pool instance will be
    /// stopped so that all configuration changes can be safely applied.
    MultiThreadingCriticalSection();

    /// @brief Destructor.
    ///
    /// Leaving the critical section. The dhcp thread pool instance will be
    /// started according to the new configuration.
    virtual ~MultiThreadingCriticalSection();
};

}  // namespace util
}  // namespace isc

#endif // MULTI_THREADING_MGR_H
