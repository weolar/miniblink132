// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef mbnet_WebURLLoaderImplCurl_h
#define mbnet_WebURLLoaderImplCurl_h

#include "mbnet/WebURLRequestExtraDataWrap.h"
#include "third_party/blink/renderer/platform/loader/fetch/loader_freeze_mode.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader.h"
#include "third_party/blink/renderer/platform/weborigin/security_origin.h"
#include "third_party/blink/renderer/platform/wtf/shared_buffer.h"
#include "third_party/blink/public/platform/resource_load_info_notifier_wrapper.h"
#include "services/network/public/cpp/resource_request.h"
#include <stdint.h>

namespace base {
class WaitableEvent;
}

namespace blink {
class WebURLRequest;
class WebURLLoaderClient;
}

namespace mbnet {

class WebURLLoaderInternal;
class BlobResourceLoader;

//using ResTaskRunnerHandle = blink::scheduler::WebResourceLoadingTaskRunnerHandle;

class WebURLLoaderImplCurl : public blink::URLLoader {
public:
    WebURLLoaderImplCurl(
        scoped_refptr<base::SingleThreadTaskRunner> freezableTaskRunnerHandle, 
        scoped_refptr<base::SingleThreadTaskRunner> unfreezableTaskRunnerHandle,
        base::WaitableEvent* terminateSyncLoadEvent,
        int64_t mbwebviewId);
    ~WebURLLoaderImplCurl() /*override*/;

    // --URLLoader methods:
    void LoadSynchronously(std::unique_ptr<network::ResourceRequest> request,
        scoped_refptr<const blink::SecurityOrigin> topFrameOrigin,
        bool downloadToBlob,
        bool noMimeSniffing,
        base::TimeDelta timeoutInterval,
        blink::URLLoaderClient* client,
        blink::WebURLResponse& response,
        std::optional<blink::WebURLError>& error,
        scoped_refptr<WTF::SharedBuffer>& data,
        int64_t& encoded_data_length,
        uint64_t& encodedBodyLength,
        scoped_refptr<blink::BlobDataHandle>& downloadedBlob,
        std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper) override;

    void LoadAsynchronously(std::unique_ptr<network::ResourceRequest> request, 
        scoped_refptr<const blink::SecurityOrigin> topFrameOrigin,
        bool noMimeSniffing, 
        std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper, 
        blink::CodeCacheHost* code_cache_host,
        blink::URLLoaderClient* client) override;

    void Freeze(blink::LoaderFreezeMode mode) override;
    void DidChangePriority(blink::WebURLRequest::Priority, int intra_priority_value) override;
    scoped_refptr<base::SingleThreadTaskRunner> GetTaskRunnerForBodyLoader() override;
    //--

    void setNotAutoDestroy()
    {
        m_isAutoDestroy = false;
    }

    void LoadAsynchronouslyEx(
        std::unique_ptr<network::ResourceRequest> request,
        scoped_refptr<const blink::SecurityOrigin> topFrameOrigin,
        bool noMimeSniffing,
        std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper,
        blink::CodeCacheHost* codeCacheHost,
        scoped_refptr<mbnet::WebURLRequestExtraDataWrap> extraData,
        blink::URLLoaderClient* client);

private:
    void init();

    //mojo::ScopedDataPipeConsumerHandle m_responseBodyConsumerDataPipe;

    bool m_isAutoDestroy = true; // 一般都是自动销毁，不过main frame的例外

    bool* m_hadDestroied = nullptr;
    int m_jobId = 0;

    mbnet::BlobResourceLoader* m_blobLoader = nullptr;

    //blink::KURL m_url;
    blink::WebURLLoaderClient* m_client = nullptr;
    blink::LoaderFreezeMode m_mode = blink::LoaderFreezeMode::kNone;

    scoped_refptr<base::SingleThreadTaskRunner> m_freezableTaskRunner;
    scoped_refptr<base::SingleThreadTaskRunner> m_unfreezableTaskRunner;

    base::WaitableEvent* m_terminateSyncLoadEvent = nullptr;
    int64_t m_mbwebviewId = 0;

    base::WeakPtrFactory<WebURLLoaderImplCurl> m_weakPtr { this };
};

} // namespace content

#endif // WebURLLoaderImplCurl_h
