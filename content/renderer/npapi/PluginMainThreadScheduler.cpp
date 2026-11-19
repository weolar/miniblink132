// Copyright (C) 2008 Apple Inc. All Rights Reserved.
// Ported and adapted for miniblink132.

#include "content/renderer/npapi/PluginMainThreadScheduler.h"

#include "content/common/ThreadCall.h"

namespace content {

PluginMainThreadScheduler& PluginMainThreadScheduler::scheduler()
{
    static PluginMainThreadScheduler* s_scheduler = new PluginMainThreadScheduler();
    return *s_scheduler;
}

PluginMainThreadScheduler::PluginMainThreadScheduler()
    : m_callPending(false)
{
}

void PluginMainThreadScheduler::scheduleCall(NPP npp, MainThreadFunction* function, void* userData)
{
    base::AutoLock lock(m_queueMutex);

    auto it = m_callQueueMap.find(npp);
    if (it == m_callQueueMap.end())
        return;

    it->second.emplace_back(function, userData);

    if (!m_callPending) {
        m_callPending = true;
        ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [this]() { this->dispatchCalls(); });
    }
}

void PluginMainThreadScheduler::registerPlugin(NPP npp)
{
    base::AutoLock lock(m_queueMutex);
    m_callQueueMap[npp] = std::deque<Call>();
}

void PluginMainThreadScheduler::unregisterPlugin(NPP npp)
{
    base::AutoLock lock(m_queueMutex);
    m_callQueueMap.erase(npp);
}

void PluginMainThreadScheduler::dispatchCallsForPlugin(NPP npp, const std::deque<Call>& calls)
{
    for (const auto& call : calls) {
        {
            base::AutoLock lock(m_queueMutex);
            if (m_callQueueMap.find(npp) == m_callQueueMap.end())
                return;
        }
        call.performCall();
    }
}

void PluginMainThreadScheduler::dispatchCalls()
{
    CallQueueMap copy;
    {
        base::AutoLock lock(m_queueMutex);
        copy = m_callQueueMap;
        for (auto& kv : m_callQueueMap)
            kv.second.clear();
        m_callPending = false;
    }

    for (const auto& entry : copy)
        dispatchCallsForPlugin(entry.first, entry.second);
}

} // namespace content
