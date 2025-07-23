
#ifndef content_renderer_NoStatePrefetchProcessorImpl_h
#define content_renderer_NoStatePrefetchProcessorImpl_h

#include "gen/third_party/blink/public/mojom/prerender/prerender.mojom-blink.h"

namespace content {

class NoStatePrefetchProcessorImpl : public blink::mojom::blink::NoStatePrefetchProcessor {
public:
    NoStatePrefetchProcessorImpl()
    {
    }
    ~NoStatePrefetchProcessorImpl()
    {
    }

    void Start(::blink::mojom::blink::PrerenderAttributesPtr prerender_attribute) override
    {
    }

    void Cancel() override
    {
    }
};

}

#endif // content_renderer_PolicyContainerHostImpl_h