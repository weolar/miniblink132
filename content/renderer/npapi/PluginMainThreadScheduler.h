// Copyright (C) 2008 Apple Inc. All Rights Reserved.
// Ported and adapted for miniblink132.

#ifndef CONTENT_RENDERER_NPAPI_PLUGIN_MAIN_THREAD_SCHEDULER_H_
#define CONTENT_RENDERER_NPAPI_PLUGIN_MAIN_THREAD_SCHEDULER_H_

#include <deque>
#include <map>

#include "base/synchronization/lock.h"
#include "third_party/npapi/bindings/npapi.h"

namespace content {

class PluginMainThreadScheduler {
public:
    typedef void MainThreadFunction(void*);

    static PluginMainThreadScheduler& scheduler();

    void scheduleCall(NPP npp, MainThreadFunction* function, void* userData);
    void registerPlugin(NPP npp);
    void unregisterPlugin(NPP npp);
    void dispatchCalls();

private:
    PluginMainThreadScheduler();
    ~PluginMainThreadScheduler() = default;

    class Call {
    public:
        Call(MainThreadFunction* function, void* userData)
            : m_function(function)
            , m_userData(userData)
        {
        }

        void performCall() const
        {
            m_function(m_userData);
        }

    private:
        MainThreadFunction* m_function;
        void* m_userData;
    };

    void dispatchCallsForPlugin(NPP npp, const std::deque<Call>& calls);

    using CallQueueMap = std::map<NPP, std::deque<Call>>;
    CallQueueMap m_callQueueMap;
    bool m_callPending;
    base::Lock m_queueMutex;
};

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_PLUGIN_MAIN_THREAD_SCHEDULER_H_
