
#ifndef content_browser_BackForwardCacheControllerHostImpl_h
#define content_browser_BackForwardCacheControllerHostImpl_h

#include "third_party/blink/public/mojom/frame/back_forward_cache_controller.mojom-blink.h"
#include "content/common/common.h"

namespace content {

class BackForwardCacheControllerHostImpl : public ::blink::mojom::blink::BackForwardCacheControllerHost {
    virtual void EvictFromBackForwardCache(::blink::mojom::blink::RendererEvictionReason reason, ::blink::mojom::blink::ScriptSourceLocationPtr source) override
    {
        //printFuncName(__FUNCTION__, true, false);
    }

    virtual void DidChangeBackForwardCacheDisablingFeatures(WTF::Vector<::blink::mojom::blink::BlockingDetailsPtr> details) override
    {
        //printFuncName(__FUNCTION__, true, false);
    }
};

}

#endif