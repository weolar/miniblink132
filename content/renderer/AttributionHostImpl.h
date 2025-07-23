
#ifndef content_renderer_AttributionHostImpl_h
#define content_renderer_AttributionHostImpl_h

#include "gen/components/attribution_reporting/data_host.mojom-blink.h"
#include "gen/components/attribution_reporting/registration_header_error.mojom-blink.h"
#include "gen/third_party/blink/public/mojom/conversions/conversions.mojom-blink.h"
#include "content/renderer/DataHostImpl.h"
#include "content/common/CreateAndBindTempl.h"

namespace content {

class AttributionHostImpl : public ::blink::mojom::blink::AttributionHost {
    void RegisterDataHost(
        ::mojo::PendingReceiver<::attribution_reporting::mojom::blink::DataHost> data_host,
        ::attribution_reporting::mojom::blink::RegistrationEligibility registration_eligibility,
        bool is_for_background_requests) override
    {
        createAndBindInterface<::attribution_reporting::mojom::blink::DataHost, DataHostImpl>(data_host.PassPipe());
    }

    void RegisterNavigationDataHost(
        ::mojo::PendingReceiver<::attribution_reporting::mojom::blink::DataHost> data_host, const ::blink::AttributionSrcToken& attribution_src_token) override
    {
        createAndBindInterface<::attribution_reporting::mojom::blink::DataHost, DataHostImpl>(data_host.PassPipe());
    }

    void NotifyNavigationWithBackgroundRegistrationsWillStart(
        const ::blink::AttributionSrcToken& attribution_src_token,
        uint32_t expected_registrations) override
    {

    }
};

}

#endif // content_renderer_AttributionHostImpl_h
