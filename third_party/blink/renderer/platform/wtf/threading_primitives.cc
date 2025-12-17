// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"

#include "base/check.h"
#include "base/threading/platform_thread.h"
#include <windows.h>

namespace WTF {

#if 0
void RecursiveMutex::lock()
{
    auto thread_id = base::PlatformThread::CurrentId();
    // Even though the thread checker doesn't complain, we are not guaranteed to
    // hold the lock here. However, reading |owner_| is fine because it is only
    // ever set to |CurrentId()| when the current thread owns the lock. It is
    // reset to another value before releasing the lock.
    //
    // So the observed values can be:
    // 1. Us: we hold the lock
    // 2. Stale kInvalidThreadId, or some other ID: not a problem, cannot be the
    //    current thread ID (as it would be set by the current thread, and thus
    //    not stale, back to case (1))
    // 3. Partial value: not possible, std::atomic<> protects from load shearing.
    if (owner_.load(std::memory_order_relaxed) != thread_id) {
        lock_.Acquire();
        DCHECK_EQ(lock_depth_, 0u);
    }
    lock_.AssertAcquired();
    UpdateStateAfterLockAcquired(thread_id);
}

void RecursiveMutex::unlock()
{
    AssertAcquired();
    CHECK_GT(lock_depth_, 0u); // No underflow.
    lock_depth_--;
    if (lock_depth_ == 0) {
        owner_.store(base::kInvalidThreadId, std::memory_order_relaxed);
        lock_.Release();
    }
}

bool RecursiveMutex::TryLock()
{
    auto thread_id = base::PlatformThread::CurrentId();
    // See comment above about reading |owner_|.
    if ((owner_.load(std::memory_order_relaxed) == thread_id) || lock_.Try()) {
        UpdateStateAfterLockAcquired(thread_id);
        return true;
    }

    return false;
}

void RecursiveMutex::UpdateStateAfterLockAcquired(base::PlatformThreadId thread_id)
{
    lock_depth_++; // uint64_t, no overflow.
    owner_.store(thread_id, std::memory_order_relaxed);
}

#else

MutexBase::MutexBase(bool recursive)
{
    m_mutex.m_recursionCount = 0;
    m_mutex.m_internalMutex = new CRITICAL_SECTION();
    InitializeCriticalSection((CRITICAL_SECTION*)(m_mutex.m_internalMutex));
}

MutexBase::~MutexBase()
{
    DeleteCriticalSection((CRITICAL_SECTION*)m_mutex.m_internalMutex);
    delete ((CRITICAL_SECTION*)m_mutex.m_internalMutex);
}

void MutexBase::lock()
{
    EnterCriticalSection((CRITICAL_SECTION*)(m_mutex.m_internalMutex));
    ++m_mutex.m_recursionCount;
}

void MutexBase::unlock()
{
    DCHECK(m_mutex.m_recursionCount);
    --m_mutex.m_recursionCount;
    LeaveCriticalSection((CRITICAL_SECTION*)(m_mutex.m_internalMutex));
}

bool Mutex::tryLock()
{
    // This method is modeled after the behavior of pthread_mutex_trylock,
    // which will return an error if the lock is already owned by the
    // current thread.  Since the primitive Win32 'TryEnterCriticalSection'
    // treats this as a successful case, it changes the behavior of several
    // tests in WebKit that check to see if the current thread already
    // owned this mutex (see e.g., IconDatabase::getOrCreateIconRecord)
    DWORD result = TryEnterCriticalSection((CRITICAL_SECTION*)(m_mutex.m_internalMutex));

    if (result != 0) { // We got the lock
        // If this thread already had the lock, we must unlock and return
        // false since this is a non-recursive mutex. This is to mimic the
        // behavior of POSIX's pthread_mutex_trylock. We don't do this
        // check in the lock method (presumably due to performance?). This
        // means lock() will succeed even if the current thread has already
        // entered the critical section.
        if (m_mutex.m_recursionCount > 0) {
            LeaveCriticalSection((CRITICAL_SECTION*)(m_mutex.m_internalMutex));
            return false;
        }
        ++m_mutex.m_recursionCount;
        return true;
    }

    return false;
}

bool RecursiveMutex::tryLock()
{
    // CRITICAL_SECTION is recursive/reentrant so TryEnterCriticalSection will
    // succeed if the current thread is already in the critical section.
    DWORD result = TryEnterCriticalSection((CRITICAL_SECTION*)(m_mutex.m_internalMutex));
    if (result == 0) { // We didn't get the lock.
        return false;
    }
    ++m_mutex.m_recursionCount;
    return true;
}

#endif

} // namespace WTF
