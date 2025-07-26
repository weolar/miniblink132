
#include "mbnet/LoaderFactoryImpl.h"

#include "content/renderer/PolicyContainerHostImpl.h"
#include "content/common/CreateAndBindTempl.h"

#include "mojo/public/cpp/bindings/associated_receiver.h"
#include "third_party/blink/public/web/web_navigation_params.h"
#include "third_party/blink/public/web/web_navigation_control.h"
#include "third_party/blink/public/platform/weak_wrapper_resource_load_info_notifier.h"
#include "third_party/blink/public/platform/resource_load_info_notifier_wrapper.h"
#include "third_party/blink/public/common/tokens/tokens.h"
#include "third_party/blink/public/common/loader/url_loader_throttle.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/navigation_body_loader.h"
#include "gen/third_party/blink/public/mojom/frame/frame.mojom-blink.h"
#include "gen/services/network/public/mojom/url_response_head.mojom.h"
#include "gen/services/network/public/mojom/encoded_body_length.mojom.h"
#include "mbnet/WebURLLoaderImplCurl.h"
#include <windows.h>

namespace mbnet {

void pushBackToBuffer(std::vector<char>* buf, const char* data, size_t len);

LoaderFactoryImpl::LoaderFactoryImpl(int64_t mbwebviewId)
{
    m_mbwebviewId = mbwebviewId;
}

std::unique_ptr<blink::URLLoader> LoaderFactoryImpl::CreateURLLoader(
    const network::ResourceRequest& request,
    scoped_refptr<base::SingleThreadTaskRunner> freezableTaskRunnerHandle, scoped_refptr<base::SingleThreadTaskRunner> unfreezableTaskRunnerHandle,
    mojo::PendingRemote<blink::mojom::blink::KeepAliveHandle> keepAliveHandle, blink::BackForwardCacheLoaderHelper* backForwardCacheLoaderHelper,
    WTF::Vector<std::unique_ptr<blink::URLLoaderThrottle>> throttles
)
{
    return std::make_unique<WebURLLoaderImplCurl>(std::move(freezableTaskRunnerHandle), std::move(unfreezableTaskRunnerHandle), m_terminateSyncLoadEvent, m_mbwebviewId);
}

BodyLoaderClient::BodyLoaderClient(
    bool isDownload,
    std::unique_ptr<blink::WebNavigationInfo> info,
    const blink::LocalFrameToken& navigationControlToken,
    const blink::FrameToken& token)
{
    m_isDownload = isDownload;
    m_info.reset(info.release());
    m_navigationControlId = navigationControlToken;
    m_urlLoaderImpl = nullptr;
    m_frameToken = token;

    CHECK(WTF::IsMainThread());

    char output[100] = { 0 };
    sprintf(output, "BodyLoaderClient: %p, %p\n", this, m_urlLoaderImpl.get());
    OutputDebugStringA(output);
}

BodyLoaderClient::~BodyLoaderClient()
{
    char output[100] = { 0 };
    sprintf(output, "~BodyLoaderClient: %p, %p\n", this, m_urlLoaderImpl.get());
    OutputDebugStringA(output);

    m_response.reset();

    if (m_urlLoaderImpl.get())
        m_urlLoaderImpl->m_canDestroy = true;
    m_urlLoaderImpl.reset();
}

bool BodyLoaderClient::WillFollowRedirect(
    const blink::WebURL& newUrl, const net::SiteForCookies& newSiteForCookies, const blink::WebString& newReferrer,
    network::mojom::ReferrerPolicy newReferrerPolicy, const blink::WebString& newMethod, const blink::WebURLResponse& passedRedirectResponse,
    bool& reportRaw_headers, std::vector<std::string>* removedHeaders, net::HttpRequestHeaders& modified_headers, bool insecureSchemeWasUpgraded
    )
{
    m_info->url_request.SetUrl(newUrl);
//     m_info->url_request.SetHttpMethod(newMethod);
//     m_info->url_request.SetReferrerString(newReferrer);
//     m_info->url_request.SetReferrerPolicy(newReferrerPolicy);

    blink::WebNavigationControl* navigationControl = (blink::WebNavigationControl*)blink::WebLocalFrame::FromFrameToken(m_navigationControlId);
    if (navigationControl)
        navigationControl->WillStartNavigation(*(m_info.get()));

    return true;
}

void BodyLoaderClient::DidReceiveResponse(const blink::WebURLResponse& response, 
    absl::variant<mojo::ScopedDataPipeConsumerHandle, SegmentedBuffer> responseBodyConsumerVar, std::optional<mojo_base::BigBuffer> cached_metadata)
{
    CHECK(!m_response.get());
    m_response.reset(new blink::WebURLResponse(response));

    mojo::ScopedDataPipeConsumerHandle* responseBodyConsumer = absl::get_if<mojo::ScopedDataPipeConsumerHandle>(&responseBodyConsumerVar);
    CHECK(responseBodyConsumer);
    DidStartLoadingResponseBody(std::move(*responseBodyConsumer));
}

void BodyLoaderClient::DidStartLoadingResponseBody(mojo::ScopedDataPipeConsumerHandle responseBodyConsumer)
{
    if (m_info->frame_load_type == blink::WebFrameLoadType::kBackForward)
        return;
    blink::WebFrame* frame = blink::WebFrame::FromFrameToken(m_frameToken);
    if (!frame)
        return;

    blink::KURL url = m_info->url_request.Url();
    std::unique_ptr<blink::WebNavigationParams> navigationParams = std::make_unique<blink::WebNavigationParams>();
    navigationParams->url = url;
    navigationParams->referrer = m_info->url_request.ReferrerString();

    mojo::PendingAssociatedRemote<blink::mojom::blink::PolicyContainerHost> policyContainerRemote;
    mojo::PendingAssociatedReceiver<blink::mojom::blink::PolicyContainerHost> policyContainerReceiver
        = policyContainerRemote.InitWithNewEndpointAndPassReceiver();

    content::createAndBindInterface<::blink::mojom::blink::PolicyContainerHost, content::PolicyContainerHostImpl>(policyContainerReceiver.PassPipe());

    navigationParams->policy_container = std::make_unique<blink::WebPolicyContainer>(
        blink::WebPolicyContainerPolicies(), blink::ToCrossVariantAssociatedMojoType(std::move(policyContainerRemote)));

    if (m_response->MimeType().IsNull() || m_response->MimeType().IsEmpty())
        m_response->SetMimeType(blink::WebString::FromASCII("text/html")); // 有的网站，比如https://mofang.163.com/下面的，没这个字段

    ::network::mojom::URLResponseHeadPtr urlResponseHead = ::network::mojom::URLResponseHead::New();
    //urlResponseHead->headers;
    urlResponseHead->mime_type = m_response->MimeType().Ascii();
    urlResponseHead->charset = m_response->HttpHeaderField(blink::WebString::FromASCII("charset")).Ascii();
    urlResponseHead->content_length = m_response->ExpectedContentLength();
    urlResponseHead->encoded_data_length = m_response->ExpectedContentLength();
    urlResponseHead->encoded_body_length = network::mojom::EncodedBodyLength::New(m_response->ExpectedContentLength());

    CHECK(!m_urlLoaderImpl);
    m_urlLoaderImpl.reset(new URLLoaderImpl(this)); // TODO: 内存泄露

    ::network::mojom::URLLoaderClientEndpointsPtr urlLoaderClientEndpoints = ::network::mojom::URLLoaderClientEndpoints::New(
        m_urlLoaderImpl->m_urlLoader.BindNewPipeAndPassRemote(), m_urlLoaderImpl->m_urlLoaderClient.BindNewPipeAndPassReceiver());

    blink::WeakWrapperResourceLoadInfoNotifier* resourceLoadInfoNotifier = new blink::WeakWrapperResourceLoadInfoNotifier(ResourceLoadInfoNotifierImpl::get());

    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrap
        = std::make_unique<blink::ResourceLoadInfoNotifierWrapper>(resourceLoadInfoNotifier->AsWeakPtr());

    resourceLoadInfoNotifierWrap->NotifyResourceLoadInitiated((int64_t)resourceLoadInfoNotifierWrap.get() /*request_id*/, (GURL)(url), "GET",
        GURL() /*referrer*/, network::mojom::RequestDestination::kDocument, net::RequestPriority::DEFAULT_PRIORITY, false);

    navigationParams->body_loader = std::make_unique<blink::NavigationBodyLoader>(url, std::move(urlResponseHead), std::move(responseBodyConsumer),
        std::move(urlLoaderClientEndpoints), base::SingleThreadTaskRunner::GetCurrentDefault(), std::move(resourceLoadInfoNotifierWrap));

    navigationParams->frame_load_type = m_info->frame_load_type;
    navigationParams->response.SetCurrentRequestUrl(url);
    navigationParams->response.SetMimeType(m_response->MimeType());

    blink::WebNavigationControl* navigationControl = (blink::WebNavigationControl*)blink::WebLocalFrame::FromFrameToken(m_navigationControlId);
    if (navigationControl && !m_isDownload)
        navigationControl->CommitNavigation(std::move(navigationParams), nullptr);
}

// 本函数一般从handleDataURL传来。测试案例：
// var iframe = document.createElement('iframe');
// iframe.src = "data:text/html;charset=utf-8,<!DOCTYPE html><script>parent.postMessage(document.contentType,'*')<\/script>";
void BodyLoaderClient::DidReceiveDataForTesting(base::span<const char> data)
{
    pushBackToBuffer(&m_buf, data.data(), data.size());
}

void BodyLoaderClient::DidFinishLoading(
    base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length, int64_t total_decoded_body_length
    )
{
    if (m_isDownload) {
        delete this;
        return;
    }

    blink::WebNavigationControl* navigationControl = (blink::WebNavigationControl*)blink::WebLocalFrame::FromFrameToken(m_navigationControlId);

    if (navigationControl && !m_buf.empty()) {
        base::span<const char> html(m_buf.data(), m_buf.size());
        std::unique_ptr<blink::WebNavigationParams> navigationParams = blink::WebNavigationParams::CreateWithHTMLStringForTesting(html, blink::WebURL());
        navigationControl->CommitNavigation(std::move(navigationParams), nullptr /* extra_data */);
        m_buf.clear();
        return;
    }

    char output[200] = { 0 };
    sprintf(output, "BodyLoaderClient::DidFinishLoading: %p, %p, %p\n", this, navigationControl, m_urlLoaderImpl.get());
    OutputDebugStringA(output);

    if (navigationControl && m_urlLoaderImpl.get()) {
        ::network::URLLoaderCompletionStatus status(0);
        if (m_urlLoaderImpl->m_urlLoaderClient.get())
            m_urlLoaderImpl->m_urlLoaderClient->OnComplete(status);
        m_urlLoaderImpl->m_canDestroy = true;
        m_urlLoaderImpl.reset();
    }

    delete this;
}

void BodyLoaderClient::DidFail(
    const blink::WebURLError& error,
    base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length,
    int64_t total_decoded_body_length
    )
{
    if (m_isDownload) {
        delete this;
        return;
    }
    blink::WebNavigationControl* navigationControl = (blink::WebNavigationControl*)blink::WebLocalFrame::FromFrameToken(m_navigationControlId);

    char output[200] = { 0 };
    sprintf(output, "BodyLoaderClient::DidFail: %p, %p, %p\n", this, navigationControl, m_urlLoaderImpl.get());
    OutputDebugStringA(output);

    if (navigationControl && m_urlLoaderImpl.get()) {
        ::network::URLLoaderCompletionStatus status(error.reason());
        if (m_urlLoaderImpl->m_urlLoaderClient.get())
            m_urlLoaderImpl->m_urlLoaderClient->OnComplete(status);
        m_urlLoaderImpl->m_canDestroy = true;
        m_urlLoaderImpl.reset();
    }
    delete this;
}

ResourceLoadInfoNotifierImpl* ResourceLoadInfoNotifierImpl::get()
{
    static ResourceLoadInfoNotifierImpl* s_inst = nullptr;
    if (!s_inst)
        s_inst = new ResourceLoadInfoNotifierImpl();
    return s_inst;
}

URLLoaderImpl::URLLoaderImpl(BodyLoaderClient* parent)
{
    URLLoaderImpl* ptr = this;
    m_urlLoader.set_disconnect_handler(base::BindOnce(
        [](URLLoaderImpl* ptr) {
            if (ptr->m_parent)
                ptr->m_parent->m_urlLoaderImpl.reset();
        },
        base::Unretained(ptr)));

    m_parent = parent;

    char output[100] = { 0 };
    sprintf(output, "URLLoaderImpl: %p\n", this);
    OutputDebugStringA(output);
}

URLLoaderImpl::~URLLoaderImpl()
{
    //delete m_resourceLoadInfoNotifierImpl;

    //if (!m_canDestroy)
    //    DebugBreak();

    char output[100] = { 0 };
    sprintf(output, "~URLLoaderImpl: %p\n", this);
    OutputDebugStringA(output);
}

}