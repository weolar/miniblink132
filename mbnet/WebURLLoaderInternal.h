/*
 * Copyright (C) 2004, 2006 Apple Computer, Inc.  All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef WebURLLoaderInternal_h
#define WebURLLoaderInternal_h

#include "mbnet/WebURLLoaderImplCurl.h"

#include "mbnet/MultipartHandle.h"
#include "mbnet/SharedMemoryDataConsumerHandle.h"
#include "mbnet/CancelledReason.h"
#include "mbnet/PageNetExtraData.h"
#include "third_party/blink/public/platform/web_url_response.h"
#include "third_party/blink/public/platform/web_url_error.h"
#include "third_party/blink/public/web/web_associated_url_loader_client.h"
#include "third_party/blink/public/mojom/loader/request_context_frame_type.mojom-shared.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader.h"
#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"
#include "third_party/blink/renderer/platform/wtf/wtf.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "base/atomicops.h"
#include "third_party/libcurl/include/curl/curl.h"
#include "base/threading/thread.h"
#include <windows.h>
#include <memory>

//#define MINIBLINK_NO_MULTITHREAD_NET 0

// The allocations and releases in WebURLLoaderInternal are
// Cocoa-exception-free (either simple Foundation classes or
// WebCoreResourceLoaderImp which avoids doing work in dealloc).

namespace blink {
class URLLoaderClient;
}

namespace network {
struct ResourceRequest;
}

typedef struct _mbNetJobDataBind mbNetJobDataBind;

namespace mbnet {

class WebURLLoaderImplCurl;

class WebURLLoaderManagerMainTask;
class WebURLLoaderManager;
class FlattenHTTPBodyElementStream;
struct InitializeHandleInfo;

class JobHead {
public:
    enum Type {
        kLoaderInternal,
        kGetFaviconTask,
        kSetCookiesTask,
        kWkeCustomNetRequest,
    };
    virtual ~JobHead()
    {
    }
    virtual int getRefCount() const
    {
        return m_ref;
    }
    virtual void ref()
    {
        base::subtle::NoBarrier_AtomicIncrement(&m_ref, 1);
    }
    virtual void deref()
    {
        base::subtle::NoBarrier_AtomicIncrement(&m_ref, -1);
    }
    virtual Type getType()
    {
        return m_type;
    }
    virtual void cancel()
    {
    }
    int m_id;
    int m_ref;
    Type m_type;
};

class WebURLLoaderInternal : public JobHead {
public:
    WebURLLoaderInternal(base::Thread* ioThread, WebURLLoaderImplCurl* loader, std::unique_ptr<network::ResourceRequest> request,
        blink::URLLoaderClient* client, bool defersLoading, bool shouldContentSniff);
    virtual ~WebURLLoaderInternal() override;

    static void release(int jobId);

    blink::URLLoaderClient* client()
    {
        return m_client;
    }
    void resetClient()
    {
        m_client = nullptr;
    }

    void setResponseFired(bool responseFired)
    {
        m_responseFired = responseFired;
    }
    bool responseFired()
    {
        return m_responseFired;
    }

    WebURLLoaderImplCurl* loader()
    {
        return m_loader;
    }
    void setLoader(WebURLLoaderImplCurl* loader)
    {
        m_loader = loader;
    }

    network::ResourceRequest* firstRequest() const
    {
        //CHECK(WTF::IsMainThread());
        return m_firstRequest.get();
    }

    void decodeUrlRequest();

    void resetFirstRequest(std::unique_ptr<network::ResourceRequest>&& newRequest);

    bool isCancelled() const
    {
        return kNoCancelled != m_cancelledReason;
    }

public:
    blink::URLLoaderClient* m_client;
    bool m_isSynchronous;
    bool m_isCrossThread = false;

private:
    std::unique_ptr<network::ResourceRequest> m_firstRequest;

public:
    blink::WebURLResponse m_response;
    std::string m_url; // 设置给curl的地址。和request可能不同，主要是fragment
    std::string m_fragment;

    String m_lastHTTPMethod;

    int m_jobId = -1;

    // Suggested credentials for the current redirection step.
    std::string m_user;
    std::string m_pass;

    bool m_isRedirection;

    //Credential m_initialCredential;

    int m_status;

    size_t m_dataLength;

    bool m_defersLoading;
    bool m_shouldContentSniff;

    CURL* m_handle;

    std::string m_effectiveUrl; // curl收到网络包后返回的最后有效地址，如果有重定向redirect，则可能和上面的变量不同
    struct curl_slist* m_customHeaders;

    //std::unique_ptr<MultipartHandle> m_multipartHandle;
    FlattenHTTPBodyElementStream* m_formDataStream = nullptr;

    CancelledReason m_cancelledReason;

    enum FailureType { NoFailure, BlockedFailure, InvalidURLFailure };
    FailureType m_scheduledFailureType;

    bool m_responseFired;

    WebURLLoaderImplCurl* m_loader;
    WebURLLoaderManager* m_manager;

    MojoHandle m_dataPipeProducerHandle = 0; // 给DidStartLoadingResponseBody用的。现在的blink靠这个MojoHandle来接收数据

    blink::mojom::RequestContextFrameType m_frameType = blink::mojom::RequestContextFrameType::kNone;

    std::unique_ptr<String> m_downloadName;

    std::unique_ptr<WTF::RecursiveMutex> m_destroingMutex;
    enum State {
        kNormal,
        kDestroying,
        kDestroyed,
    };
    State m_state;

    base::Lock m_syncTasksLock;
    std::vector<WebURLLoaderManagerMainTask*> m_syncTasks;
    WebURLLoaderManagerMainTask* m_crossThreadTasksBegin = nullptr;

    //SharedMemoryDataConsumerHandle::Writer* m_bodyStreamWriter;

    String m_debugPath;

    bool m_isBlackList;
    bool m_isDataUrl;
    bool m_isProxy;
    bool m_isProxyConnect; // 是否使用代理的Connect请求
    bool m_isProxyHeadRequest;
    bool m_needParseMime; // 如果response为空的时候，是否需要在recv data的时候分析
    bool m_hadHandleDidSentData = false;

    int m_recvTotalSize = 0;

    InitializeHandleInfo* m_initializeHandleInfo;
    bool m_isHoldJobToAsynCommit;

    enum CacheForDownloadOpt {
        kCacheForDownloadUnknow,
        kCacheForDownloadNot,
        kCacheForDownloadYes,
    };

#if 1 // ENABLE_WKE == 1
    int m_isHookRequest; // 1表示wke接口设置的，2表示内部指定要缓存，3表示既是内部指定，又被缓存了
    Vector<char>* m_hookBufForEndHook = nullptr;
    Vector<char>* m_asynWkeNetSetData = nullptr;
    bool m_isWkeNetSetDataBeSetted;
    bool m_isWkeCanceled; // 是否调用过wkeNetCancelRequest
    bool m_isUrlBegining = false;

    mbNetJobDataBind* m_dataBind = nullptr;
    std::vector<char> m_dataCacheForDownload; // 下载时需要先缓存再给外部
#endif
    bool m_hasCallResponse; // 是否有head call被调用过。如果没有的话，且又有write call 提前调用了，就需要缓存数据给下载
    uint32_t m_sentDataBytes;
    uint32_t m_totalBytesToBeSent; // post的时候，记录发送进度用

    int64_t m_mbwebviewId = 0;

    scoped_refptr<base::SequencedTaskRunner> m_taskRunner;

    CacheForDownloadOpt m_cacheForDownloadOpt;

    scoped_refptr<PageNetExtraData> m_pageNetExtraData;

    base::Thread* m_ioThread = nullptr;
};

} // namespace mbnet

#endif // WebURLLoaderInternal_h
