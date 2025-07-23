
#include "third_party/blink/public/mojom/quota/quota_manager_host.mojom-blink.h"
#include "third_party/blink/public/mojom/quota/quota_types.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/quota/quota_types.mojom-blink.h"

namespace content {

class QuotaManagerHostImpl : public blink::mojom::blink::QuotaManagerHost {
public:
    // QuotaManagerHost:

    // W:\mycode\mb108\third_party\blink\renderer\modules\quota\deprecated_storage_quota.cc
    //using QueryStorageUsageAndQuotaCallback = base::OnceCallback<void(::blink::mojom::blink::QuotaStatusCode, int64_t, int64_t, ::blink::mojom::blink::UsageBreakdownPtr)>;
    void QueryStorageUsageAndQuota(blink::mojom::blink::QuotaManagerHost::QueryStorageUsageAndQuotaCallback callback) override
    {
        std::move(callback).Run(::blink::mojom::QuotaStatusCode::kOk, 0x100000, 0x100000, nullptr);
    }
};

}
