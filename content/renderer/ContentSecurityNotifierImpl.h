
#ifndef content_renderer_ContentSecurityNotifierImpl_h
#define content_renderer_ContentSecurityNotifierImpl_h

#include "third_party/blink/public/mojom/loader/content_security_notifier.mojom-blink.h"

namespace content {

class ContentSecurityNotifierImpl : public blink::mojom::blink::ContentSecurityNotifier {
public:
    ContentSecurityNotifierImpl(int64_t webviewId)
    {
    }

    ~ContentSecurityNotifierImpl()
    {
    }

    void NotifyContentWithCertificateErrorsRan() override
    {
        //OutputDebugStringA("ContentSecurityNotifierImpl::NotifyContentWithCertificateErrorsRan\n");
    }

    void NotifyContentWithCertificateErrorsDisplayed() override
    {
        //OutputDebugStringA("ContentSecurityNotifierImpl::NotifyContentWithCertificateErrorsDisplayed\n");
    }

    void NotifyInsecureContentRan(const ::blink::KURL& origin, const ::blink::KURL& insecure_url) override
    {
        //OutputDebugStringA("ContentSecurityNotifierImpl::NotifyInsecureContentRan\n");
    }
};

}

#endif // content_renderer_ContentSecurityNotifierImpl_h