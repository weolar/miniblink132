
#ifndef content_renderer_WebWorkerFetchContextImpl_h
#define content_renderer_WebWorkerFetchContextImpl_h

#include "third_party/blink/public/platform/web_worker_fetch_context.h"

namespace mbnet {
class LoaderFactoryImpl;
}

namespace content {

class WebWorkerFetchContextImpl : public blink::WebWorkerFetchContext {
public:
    WebWorkerFetchContextImpl(const blink::WebSecurityOrigin& orig, int64_t mbwebviewId);
    ~WebWorkerFetchContextImpl() override;

    void SetTerminateSyncLoadEvent(base::WaitableEvent*) override;

    void InitializeOnWorkerThread(blink::AcceptLanguagesWatcher*) override;

    blink::URLLoaderFactory* GetURLLoaderFactory() override;

    std::unique_ptr<blink::URLLoaderFactory> WrapURLLoaderFactory(
        blink::CrossVariantMojoRemote<network::mojom::URLLoaderFactoryInterfaceBase> url_loader_factory) override;

    std::optional<blink::WebURL> WillSendRequest(const blink::WebURL& url) override;

    void FinalizeRequest(blink::WebURLRequest& req) override;

    blink::WebVector<std::unique_ptr<blink::URLLoaderThrottle>> CreateThrottles(const network::ResourceRequest& request) override;

    net::SiteForCookies SiteForCookies(void) const override;

    absl::optional<blink::WebSecurityOrigin> TopFrameOrigin(void) const override;

    blink::WebString GetAcceptLanguages(void) const override;

    void SetIsOfflineMode(bool) override;

    blink::mojom::ControllerServiceWorkerMode GetControllerServiceWorkerMode(void) const override;

private:
    std::unique_ptr<mbnet::LoaderFactoryImpl> m_loaderFactoryImpl;
    blink::WebSecurityOrigin m_orig;
    int64_t m_mbwebviewId = 0;
};

}

#endif // content_renderer_WebWorkerFetchContextImpl_h
