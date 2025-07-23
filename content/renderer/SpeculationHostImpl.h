
#ifndef content_renderer_SpeculationHostImpl_h
#define content_renderer_SpeculationHostImpl_h

#include "gen/third_party/blink/public/mojom/speculation_rules/speculation_rules.mojom-blink.h"

namespace content {

class SpeculationHostImpl : public ::blink::mojom::blink::SpeculationHost {
public:
    SpeculationHostImpl() { }
    ~SpeculationHostImpl()
    {

    }

    void UpdateSpeculationCandidates(WTF::Vector<::blink::mojom::blink::SpeculationCandidatePtr> candidates) override
    {

    }

    void OnLCPPredicted() override
    {

    }

    void InitiatePreview(const ::blink::KURL& url) override
    {

    }
};

}

#endif // content_renderer_SpeculationHostImpl_h