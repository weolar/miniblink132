/*
 * Copyright (C) 2006 Apple Inc.  All rights reserved.
 * Copyright (C) 2006 Michael Emmel mike.emmel@gmail.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef mbnet_WebURLLoaderManager_h
#define mbnet_WebURLLoaderManager_h

#define HTTP_ONLY

#include "mbnet/CancelledReason.h"
#include "mbnet/ProxyType.h"

#include "third_party/libcurl/include/curl/curl.h"
#include "base/containers/flat_map.h"
#include "base/synchronization/lock.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"
#include "base/task/single_thread_task_runner.h"
#include <map>
#include <windows.h>

namespace base {
class Thread;
class WaitableEvent;
}

namespace blink {
class WebURLRequest;
class WebURLResponse;
struct WebURLError;
class WebURLLoaderClient;
class WebURLLoader;
}

namespace mbnet {

class JobHead;
class WebURLLoaderInternal;
class WebURLLoaderManager;
class WebCookieJarImpl;
struct BlobTempFileInfo;
struct InitializeHandleInfo;
struct MainTaskArgs;
class WebURLLoaderManagerMainTask;
struct SyncJob;

class AutoLockJob {
public:
    AutoLockJob(WebURLLoaderManager* manager, int jobId);
    WebURLLoaderInternal* lock();
    JobHead* lockJobHead();
    ~AutoLockJob();

    void setNotDerefForDelete();

private:
    WebURLLoaderManager* m_manager;
    int m_jobId;
    bool m_isNotDerefForDelete;
};

class WebURLLoaderManager {
public:
    class IoTask;
    class MainTask;
    static WebURLLoaderManager* sharedInstance();
    static void setCookieJarFullPath(const char* path);
    int addAsynchronousJob(WebURLLoaderInternal* job);
    void cancel(int jobId);
    void cancelAll();
    void cancelAllJobsOfWebview(int webviewId);

    JobHead* checkJob(int jobId);
    void removeLiveJobs(int jobId);
    int addLiveJobs(JobHead* job);

    CURLSH* getCurlShareHandle() const;

    //const char* getCookieJarFileName() const;

    void dispatchSynchronousJob(WebURLLoaderInternal* job, base::WaitableEvent* terminateSyncLoadEvent);

    void setProxyInfo(const WTF::String& host, unsigned long port, ProxyType type, const WTF::String& username, const WTF::String& password);

    void shutdown();
    bool isShutdown() const
    {
        return m_isShutdown;
    }

    void didReceiveDataOrDownload(WebURLLoaderInternal* job, const char* data, int dataLength, int encodedDataLength);
    void handlReceiveData(WebURLLoaderInternal* job, const char* data, int dataLength, int encodedDataLength);

    void handleDidFinishLoading(WebURLLoaderInternal* job, int64_t finishTime, int64_t totalEncodedDataLength);
    void handleDidFail(WebURLLoaderInternal* job, const blink::WebURLError& error);
    void handleDidReceiveResponse(WebURLLoaderInternal* job);
    void handleDidSentData(WebURLLoaderInternal* job, unsigned long long bytesSent, unsigned long long totalBytesToBeSent);

    void continueJob(WebURLLoaderInternal* job);
    void cancelWithHookRedirect(WebURLLoaderInternal* job);

    String handleHeaderForBlobOnMainThread(WebURLLoaderInternal* job, size_t totalSize);

    enum IoThreadType {
        kIoThreadTypeRes, // 图片等资源类型
        kIoThreadTypeSync, // 同步资源
        kIoThreadTypeOther,
    };

    base::Thread* getIoThread(IoThreadType type);
    scoped_refptr<base::SingleThreadTaskRunner> getMainRunner() const
    {
        return m_mainThreadRunner;
    }

private:
    base::Thread* getSyncIoThread();

public:
    WebCookieJarImpl* getShareCookieJar() const;

    bool doCancel(JobHead* jobHeead, CancelledReason cancelledReason);

private:
    WebURLLoaderManager(const char* cookieJarFullPath);
    ~WebURLLoaderManager();

    void initializeMultiHandleOnIoThread(int* waitCount);

    void setupPOST(WebURLLoaderInternal*, struct curl_slist**);
    void setupPUT(WebURLLoaderInternal*, struct curl_slist**);

    bool downloadOnIoThread();
    void removeFromCurlOnIoThread(int jobId);

    void applyAuthenticationToRequest(WebURLLoaderInternal* job);

    int initializeHandleOnMainThread(WebURLLoaderInternal* job);
    void initializeHandleOnIoThread(int jobId, InitializeHandleInfo* info);
    InitializeHandleInfo* preInitializeHandleOnMainThread(WebURLLoaderInternal* job);
    void startOnIoThread(int jobId);
    void timeoutOnMainThread(int jobId);

    void dispatchSynchronousJobOnIoThread(WebURLLoaderInternal* job, InitializeHandleInfo* info, SyncJob* syncJob);

    void initCookieSession(const char* cookiePath);

    CURLM* getCurrentThreadCurlMultiHandle() const;

    std::vector<base::Thread*> getIoThreads();

    static WebURLLoaderManager* m_sharedInstance;

    Vector<WebURLLoaderInternal*> m_resourceHandleList;
    //CURLM* m_curlMultiHandle;
    //CURLSH* m_curlShareHandle;
    //char* m_cookieJarFileName;
    std::map<DWORD, CURLM*> m_curlMultiHandles;
    WebCookieJarImpl* m_shareCookieJar;

    char m_curlErrorBuffer[CURL_ERROR_SIZE];
    const std::string m_certificatePath;
    int m_runningJobs;
    std::vector<base::Thread*> m_threads;
    base::Thread* m_syncIoThread;
    std::string m_proxy;
    ProxyType m_proxyType;
    bool m_isShutdown;

    friend class WebURLLoaderInternal;
    WTF::RecursiveMutex m_liveJobsMutex;
    //base::flat_map<int, JobHead*> m_liveJobs;
    std::map<int, JobHead*> m_liveJobs;
    int m_newestJobId;

    friend class WebURLLoaderManagerMainTask;
    base::Lock m_mainTasksMutex;
    WebURLLoaderManagerMainTask* m_mainTasksBegin;
    WebURLLoaderManagerMainTask* m_mainTasksEnd;

    scoped_refptr<base::SingleThreadTaskRunner> m_mainThreadRunner;

public:
    //WTF::Mutex m_shutdownMutex;
    class ShutdownRWLock {
    public:
        ShutdownRWLock()
        {
            m_readCount = 0;
            m_writeCount = 0;
        }

        bool read()
        {
            base::AutoLock locker(m_lock);
            if (m_writeCount > 0)
                return false;

            ++m_readCount;
            return true;
        }

        void releaseRead()
        {
            base::AutoLock locker(m_lock);
            --m_readCount;
        }

        void waitForWrite()
        {
            m_lock.Acquire();
            ++m_writeCount;
            m_lock.Release();

            while (true) {
                m_lock.Acquire();
                if (m_readCount > 0) {
                    m_lock.Release();
                    ::Sleep(10);
                } else {
                    m_lock.Release();
                    break;
                }
            }
        }

    private:
        int m_readCount;
        int m_writeCount;
        base::Lock m_lock;
    };

    class ShutdownReadLocker {
    public:
        ShutdownReadLocker(ShutdownRWLock* lock)
        {
            m_lock = lock;
        }

        bool lock()
        {
            bool b = m_lock->read();
            if (!b)
                m_lock = nullptr;
            return b;
        }

        ~ShutdownReadLocker()
        {
            if (m_lock)
                m_lock->releaseRead();
        }

    private:
        ShutdownRWLock* m_lock;
    };

    ShutdownRWLock m_shutdownLock;

    std::vector<base::Thread*> m_ioThreads;
};

}

#endif // net_WebURLLoaderManager_h
