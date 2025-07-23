
#ifndef content_renderer_PolicyContainerHostImpl_h
#define content_renderer_PolicyContainerHostImpl_h

#include "gen/third_party/blink/public/mojom/frame/policy_container.mojom-blink.h"

namespace content {

class PolicyContainerHostImpl : public blink::mojom::blink::PolicyContainerHost {
public:
    PolicyContainerHostImpl()
    {
    }
    ~PolicyContainerHostImpl()
    {
    }

    void SetReferrerPolicy(::network::mojom::blink::ReferrerPolicy referrer_policy) override
    {
        //OutputDebugStringA("PolicyContainerHostImpl::SetReferrerPolicy not impl\n");
    }

    void AddContentSecurityPolicies(WTF::Vector<::network::mojom::blink::ContentSecurityPolicyPtr> content_security_policies) override
    {
        //OutputDebugStringA("PolicyContainerHostImpl::AddContentSecurityPolicies not impl\n");
    }

//     void IssueKeepAliveHandle(::mojo::PendingReceiver<blink::mojom::blink::PolicyContainerHostKeepAliveHandle> receiver) override
//     {
//         //OutputDebugStringA("PolicyContainerHostImpl::IssueKeepAliveHandle not impl\n");
//     }
};

}

#endif // content_renderer_PolicyContainerHostImpl_h