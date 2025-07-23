
#include "content/browser/LocalMainFrameHostImpl.h"

#include "content/browser/MbWebview.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/common/LiveIdDetect.h"

void mbDestroyWebViewImpl(mbWebView webviewHandle);

namespace content {

LocalMainFrameHostImpl::LocalMainFrameHostImpl(WebLocalFrameClientImpl* frameClient)
{
    m_frameClient = frameClient;
}

void LocalMainFrameHostImpl::DidFirstVisuallyNonEmptyPaint()
{
    if (m_frameClient)
        m_frameClient->onLoadingSucceeded();
}

void LocalMainFrameHostImpl::RequestClose()
{
    if (!m_frameClient)
        return;
    int64_t id = m_frameClient->getMbwebviewId();
    mbDestroyWebViewImpl(id);
}

void LocalMainFrameHostImpl::DraggableRegionsChanged(WTF::Vector<::blink::mojom::blink::DraggableRegionPtr> regions)
{
    if (!m_frameClient)
        return;
    int64_t id = m_frameClient->getMbwebviewId();
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(id);
    if (!webview)
        return;

    blink::WebVector<blink::WebDraggableRegion> regionsCopy;
    for (size_t i = 0; i < regions.size(); ++i) {
        const ::blink::mojom::blink::DraggableRegionPtr& r = regions[i];
        blink::WebDraggableRegion webR;
        webR.bounds = r->bounds;
        webR.draggable = r->draggable;
        regionsCopy.push_back(webR);
    }
    webview->draggableRegionsChanged(regionsCopy);
}

}
