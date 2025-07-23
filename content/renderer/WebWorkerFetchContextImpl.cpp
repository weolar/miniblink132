
#include "content/renderer/WebWorkerFetchContextImpl.h"

#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_factory.h"
#include "net/cookies/site_for_cookies.h"
#include "mbnet/LoaderFactoryImpl.h"
#include "mbnet/WebURLRequestExtraDataWrap.h"
#include <windows.h>

namespace blink {
class WebLocalFrame;
}

namespace content {

WebWorkerFetchContextImpl::WebWorkerFetchContextImpl(const blink::WebSecurityOrigin& orig, int64_t mbwebviewId)
{
    m_orig = blink::WebSecurityOrigin::CreateFromString(orig.ToString());
    m_mbwebviewId = mbwebviewId;
    m_loaderFactoryImpl.reset(new mbnet::LoaderFactoryImpl(mbwebviewId));
}

WebWorkerFetchContextImpl::~WebWorkerFetchContextImpl()
{
    m_loaderFactoryImpl.reset();
}

void WebWorkerFetchContextImpl::SetTerminateSyncLoadEvent(base::WaitableEvent* evt)
{
    m_loaderFactoryImpl->SetTerminateSyncLoadEvent(evt);
}

void WebWorkerFetchContextImpl::InitializeOnWorkerThread(blink::AcceptLanguagesWatcher*)
{
    OutputDebugStringA("WebWorkerFetchContextImpl::InitializeOnWorkerThread Not impl\n");
}

blink::URLLoaderFactory* WebWorkerFetchContextImpl::GetURLLoaderFactory()
{
    return m_loaderFactoryImpl.get();
}

std::unique_ptr<blink::URLLoaderFactory> WebWorkerFetchContextImpl::WrapURLLoaderFactory(
    blink::CrossVariantMojoRemote<network::mojom::URLLoaderFactoryInterfaceBase> url_loader_factory)
{
    std::unique_ptr<blink::URLLoaderFactory> loaderFactoryImpl;
    loaderFactoryImpl.reset(new mbnet::LoaderFactoryImpl(m_mbwebviewId));
    return std::move(loaderFactoryImpl);
}

void setRequestHead(blink::WebLocalFrame* webFrame, blink::WebURLRequest& request);

std::optional<blink::WebURL> WebWorkerFetchContextImpl::WillSendRequest(const blink::WebURL& url)
{
    return std::nullopt;
}

void WebWorkerFetchContextImpl::FinalizeRequest(blink::WebURLRequest& request)
{
    scoped_refptr<mbnet::WebURLRequestExtraDataWrap> extraData = base::MakeRefCounted<mbnet::WebURLRequestExtraDataWrap>();
    extraData->mbwebviewId = m_mbwebviewId;

    blink::WebURLRequest* req = (blink::WebURLRequest*)(&request);
    req->SetURLRequestExtraData(extraData);

    setRequestHead(nullptr, *req);
}

blink::WebVector<std::unique_ptr<blink::URLLoaderThrottle>> WebWorkerFetchContextImpl::CreateThrottles(const network::ResourceRequest& request)
{
    return blink::WebVector<std::unique_ptr<blink::URLLoaderThrottle>>();
}

net::SiteForCookies WebWorkerFetchContextImpl::SiteForCookies(void) const
{
    return net::SiteForCookies();
}

absl::optional<blink::WebSecurityOrigin> WebWorkerFetchContextImpl::TopFrameOrigin(void) const
{
    return m_orig;
}

blink::WebString WebWorkerFetchContextImpl::GetAcceptLanguages(void) const
{
    return blink::WebString::FromASCII("zh-CN");
}

void WebWorkerFetchContextImpl::SetIsOfflineMode(bool)
{
    DebugBreak();
    return;
}

blink::mojom::ControllerServiceWorkerMode WebWorkerFetchContextImpl::GetControllerServiceWorkerMode(void) const
{
    return blink::mojom::ControllerServiceWorkerMode::kNoController;
}

}