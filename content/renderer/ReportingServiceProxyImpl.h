
#ifndef content_renderer_ReportingServiceProxyImpl_h
#define content_renderer_ReportingServiceProxyImpl_h

#include "third_party/blink/public/mojom/reporting/reporting.mojom-blink.h"

namespace content {

class ReportingServiceProxyImpl : public ::blink::mojom::blink::ReportingServiceProxy {
public:
    ReportingServiceProxyImpl(int64_t webviewId)
    {
    }
    void QueueInterventionReport(const ::blink::KURL& url, const WTF::String& id, const WTF::String& message, const WTF::String& source_file,
        int32_t line_number, int32_t column_number) override
    {
        //OutputDebugStringA("ReportingServiceProxyImpl::QueueInterventionReport not impl\n");
    }

    void QueueDeprecationReport(const ::blink::KURL& url, const WTF::String& id, absl::optional<::base::Time> anticipatedRemoval, const WTF::String& message,
        const WTF::String& source_file, int32_t line_number, int32_t column_number) override
    {
        //OutputDebugStringA("ReportingServiceProxyImpl::QueueInterventionReport not impl\n");
    }

    void QueueCspViolationReport(const ::blink::KURL& url, const WTF::String& group, const WTF::String& document_url, const WTF::String& referrer,
        const WTF::String& blocked_url, const WTF::String& effective_directive, const WTF::String& original_policy, const WTF::String& source_file,
        const WTF::String& script_sample, const WTF::String& disposition, uint16_t status_code, int32_t line_number, int32_t column_number) override
    {
        //OutputDebugStringA("ReportingServiceProxyImpl::QueueCspViolationReport not impl\n");
    }

    void QueuePermissionsPolicyViolationReport(const ::blink::KURL& url, const WTF::String& endpoint, const WTF::String& policy_id,
        const WTF::String& disposition, const WTF::String& message, const WTF::String& source_file, int32_t line_number, int32_t column_number) override
    {
        //OutputDebugStringA("ReportingServiceProxyImpl::QueuePermissionsPolicyViolationReport not impl\n");
    }

    void QueueDocumentPolicyViolationReport(const ::blink::KURL& url, const WTF::String& group, const WTF::String& policy_id, const WTF::String& disposition,
        const WTF::String& message, const WTF::String& source_file, int32_t line_number, int32_t column_number) override
    {
        //OutputDebugStringA("ReportingServiceProxyImpl::QueueDocumentPolicyViolationReport not impl\n");
    }
};

}

#endif // content_renderer_ReportingServiceProxyImpl_h