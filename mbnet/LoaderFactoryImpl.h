
#ifndef mbnet_LoaderFactoryImpl_h
#define mbnet_LoaderFactoryImpl_h

#include "mbnet/WebURLRequestExtraDataWrap.h"
#include "third_party/blink/public/web/web_associated_url_loader_client.h"
#include "third_party/blink/public/web/web_navigation_params.h"
#include "third_party/blink/public/mojom/loader/resource_load_info_notifier.mojom.h"
#include "third_party/blink/public/mojom/loader/resource_load_info.mojom-forward.h"
#include "third_party/blink/public/mojom/loader/resource_load_info.mojom.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_client.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_factory.h"
#include "services/network/public/mojom/url_loader.mojom.h"
#include "services/network/public/mojom/url_response_head.mojom.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "third_party/blink/renderer/core/mojo/mojo_handle.h"

namespace base {
class WaitableEvent;
}

namespace blink {
class WebURLResponse;
class WebNavigationControl;
}

namespace mbnet {

//using ResTaskRunnerHandle = blink::scheduler::WebResourceLoadingTaskRunnerHandle;

class ResourceLoadInfoNotifierImpl : public blink::mojom::ResourceLoadInfoNotifier {
public:
    void NotifyResourceRedirectReceived(const ::net::RedirectInfo& redirect_info, ::network::mojom::URLResponseHeadPtr redirect_response) override
    {
        //OutputDebugStringA("ResourceLoadInfoNotifierImpl::NotifyResourceRedirectReceived not impl\n");
    }

    // int64_t request_id, const ::url::SchemeHostPort& final_response_url,
    //::network::mojom::URLResponseHeadPtr head, ::network::mojom::RequestDestination request_destination, bool is_ad_resource
    void NotifyResourceResponseReceived(int64_t request_id, const ::url::SchemeHostPort& final_response_url, ::network::mojom::URLResponseHeadPtr head,
        ::network::mojom::RequestDestination request_destination, bool is_ad_resource) override
    {
        //OutputDebugStringA("ResourceLoadInfoNotifierImpl::NotifyResourceResponseReceived not impl\n");
    }

    void NotifyResourceTransferSizeUpdated(int64_t request_id, int32_t transfer_size_diff) override
    {
        //OutputDebugStringA("ResourceLoadInfoNotifierImpl::NotifyResourceTransferSizeUpdated not impl\n");
    }

    void NotifyResourceLoadCompleted(::blink::mojom::ResourceLoadInfoPtr resource_load_info, const ::network::URLLoaderCompletionStatus& status) override
    {
        //OutputDebugStringA("ResourceLoadInfoNotifierImpl::NotifyResourceLoadCompleted not impl\n");
    }

    void NotifyResourceLoadCanceled(int64_t request_id) override
    {
        //OutputDebugStringA("ResourceLoadInfoNotifierImpl::NotifyResourceLoadCanceled not impl\n");
    }

    void Clone(::mojo::PendingReceiver<ResourceLoadInfoNotifier> pending_resource_load_info_notifier) override
    {
        //OutputDebugStringA("ResourceLoadInfoNotifierImpl::Clone not impl\n");
    }

    static ResourceLoadInfoNotifierImpl* get();

private:
};

class BodyLoaderClient;

class URLLoaderImpl : public ::network::mojom::URLLoader {
public:
    URLLoaderImpl(BodyLoaderClient* parent);
    ~URLLoaderImpl() override;

    void FollowRedirect(const std::vector<std::string>& removed_headers, const ::net::HttpRequestHeaders& modified_headers,
        const ::net::HttpRequestHeaders& modified_cors_exempt_headers, const absl::optional<::GURL>& new_url) override
    {
        //OutputDebugStringA("URLLoaderImpl::FollowRedirect not impl\n");
    }

    void SetPriority(::net::RequestPriority priority, int32_t intra_priority_value) override
    {
        //OutputDebugStringA("URLLoaderImpl::SetPriority not impl\n");
    }

    void PauseReadingBodyFromNet() override
    {
        //OutputDebugStringA("URLLoaderImpl::PauseReadingBodyFromNet not impl\n");
    }

    void ResumeReadingBodyFromNet() override
    {
        //OutputDebugStringA("URLLoaderImpl::ResumeReadingBodyFromNet not impl\n");
    }

    bool m_canDestroy = false;
    BodyLoaderClient* m_parent = nullptr;

    ::mojo::Remote<::network::mojom::URLLoaderClient> m_urlLoaderClient;
    ::mojo::Receiver<::network::mojom::URLLoader> m_urlLoader { this };

    //ResourceLoadInfoNotifierImpl* m_resourceLoadInfoNotifierImpl = nullptr; /*new ResourceLoadInfoNotifierImpl()*/;
};

class LoaderFactoryImpl final : public blink::URLLoaderFactory {
public:
    LoaderFactoryImpl(int64_t mbwebviewId);

    // URLLoaderFactory implementation:
    std::unique_ptr<blink::URLLoader> CreateURLLoader(const network::ResourceRequest& request,
        scoped_refptr<base::SingleThreadTaskRunner> freezable_task_runner, scoped_refptr<base::SingleThreadTaskRunner> unfreezable_task_runner,
        mojo::PendingRemote<blink::mojom::blink::KeepAliveHandle> keep_alive_handle, blink::BackForwardCacheLoaderHelper* back_forward_cache_loader_helper,
        WTF::Vector<std::unique_ptr<blink::URLLoaderThrottle>> throttles) override;

    void SetTerminateSyncLoadEvent(base::WaitableEvent* evt)
    {
        m_terminateSyncLoadEvent = evt;
    }

private:
    base::WaitableEvent* m_terminateSyncLoadEvent = nullptr;
    int64_t m_mbwebviewId = 0;
};

class BodyLoaderClient : public blink::URLLoaderClient {
public:
    BodyLoaderClient(
        bool isDownload, 
        std::unique_ptr<blink::WebNavigationInfo> info, 
        const blink::LocalFrameToken& navigationControlToken,
        const blink::FrameToken& token
    ); // TODO: WebNavigationControl要考虑页面被销毁了
    ~BodyLoaderClient() override;

    bool WillFollowRedirect(
//         const blink::WebURL& new_url, const net::SiteForCookies& new_site_for_cookies, const blink::WebString& new_referrer,
//         network::mojom::ReferrerPolicy new_referrer_policy, const blink::WebString& new_method, const blink::WebURLResponse& passed_redirect_response,
//         bool& report_raw_headers, std::vector<std::string>* removed_headers, bool insecure_scheme_was_upgraded
        const blink::WebURL& new_url, const net::SiteForCookies& new_site_for_cookies, const blink::WebString& new_referrer,
        network::mojom::ReferrerPolicy new_referrer_policy, const blink::WebString& new_method, const blink::WebURLResponse& passed_redirect_response,
        bool& report_raw_headers, std::vector<std::string>* removed_headers, net::HttpRequestHeaders& modified_headers, bool insecure_scheme_was_upgraded
    ) override;

    void DidSendData(uint64_t bytes_sent, uint64_t total_bytes_to_be_sent) override
    {
    }

    void DidReceiveResponse(const blink::WebURLResponse&, 
        absl::variant<mojo::ScopedDataPipeConsumerHandle, SegmentedBuffer>, std::optional<mojo_base::BigBuffer> cached_metadata) override;
    void DidStartLoadingResponseBody(mojo::ScopedDataPipeConsumerHandle body) /*override*/;
    void DidReceiveDataForTesting(base::span<const char> data) override;

    void DidReceiveTransferSizeUpdate(int transfer_size_diff) override
    {
    }

    void DidReceiveCachedMetadata(mojo_base::BigBuffer data) /*override*/
    {
    }

    void DidFinishLoading(
        base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length, int64_t total_decoded_body_length
        ) override;

    void DidFail(const blink::WebURLError&, base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length,
        int64_t total_decoded_body_length
        ) override;

protected:
    blink::FrameToken m_frameToken;
    std::unique_ptr<blink::WebNavigationInfo> m_info;
    blink::LocalFrameToken m_navigationControlId;

    std::vector<char> m_buf;

    friend class URLLoaderImpl;
    std::unique_ptr<URLLoaderImpl> m_urlLoaderImpl;
    std::unique_ptr<blink::WebURLResponse> m_response;

    bool m_isDownload = false;
};

}

#endif