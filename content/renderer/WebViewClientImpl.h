
#ifndef content_renderer_WebViewClientImpl_h
#define content_renderer_WebViewClientImpl_h

#include "third_party/blink/public/web/web_view_client.h"

namespace content {

class MbWebView;

class WebViewClientImpl : public blink::WebViewClient {
public:
    WebViewClientImpl(MbWebView* mbwebview)
    {
        m_mbwebview = mbwebview;
    }

    ~WebViewClientImpl() override
    {
    }

    MbWebView* getMbwebview() const
    {
        return m_mbwebview;
    }

    void InvalidateContainer() override
    {
    }

    void DidAutoResize(const gfx::Size& new_size) override
    {
    }

    void DidFocus() override
    {
    }

    void OnDestruct() override
    {
    }

private:
    MbWebView* m_mbwebview;
};

}

#endif // content_renderer_WebViewClientImpl_h