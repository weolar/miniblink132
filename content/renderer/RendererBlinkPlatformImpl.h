// Copyright 2012 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_RENDERER_RENDERER_BLINK_PLATFORM_IMPL_H_
#define CONTENT_RENDERER_RENDERER_BLINK_PLATFORM_IMPL_H_

#include <stddef.h>
#include <stdint.h>

#include <memory>
#include <string>

#include "base/containers/id_map.h"
#include "base/synchronization/lock.h"
#include "base/synchronization/waitable_event.h"
#include "base/task/sequenced_task_runner.h"
#include "base/task/single_thread_task_runner.h"
#include "base/thread_annotations.h"
#include "base/threading/thread.h"
#include "base/threading/thread_checker.h"
#include "base/time/time.h"
#include "build/build_config.h"
// #include "content/child/blink_platform_impl.h"
// #include "content/common/content_export.h"
#include "mojo/public/cpp/bindings/pending_remote.h"
#include "mojo/public/cpp/bindings/shared_remote.h"

#include "third_party/blink/public/platform/platform.h"

namespace blink {
namespace scheduler {
class WebThreadScheduler;
}
class WebGraphicsContext3DProvider;
class WebSecurityOrigin;
enum class ProtocolHandlerSecurityLevel;
struct WebContentSecurityPolicyHeader;
} // namespace blink

namespace gpu {
struct GPUInfo;
}

namespace media {
class GpuVideoAcceleratorFactories;
}

namespace viz {
class RasterContextProvider;
}

namespace webcrypto {
class WebCryptoImpl;
}

namespace content {

class RendererBlinkPlatformImpl : public blink::Platform {
public:
    RendererBlinkPlatformImpl();
//     std::unique_ptr<blink::WebURLLoaderFactory> WrapURLLoaderFactory(
//         blink::CrossVariantMojoRemote<network::mojom::URLLoaderFactoryInterfaceBase> url_loader_factory) override;
    blink::ThreadSafeBrowserInterfaceBrokerProxy* GetBrowserInterfaceBroker() override;
    blink::WebString DefaultLocale() override;
    std::unique_ptr<blink::URLLoaderThrottleProvider> CreateURLLoaderThrottleProviderForWorker(blink::URLLoaderThrottleProviderType provider_type) override;

    blink::WebData GetDataResource(int resource_id, ui::ResourceScaleFactor scale_factor = ui::kScaleFactorNone) override;
    std::string GetDataResourceString(int resource_id) override;
    blink::WebString QueryLocalizedString(int resource_id) override;
    blink::WebString QueryLocalizedString(int resource_id, const blink::WebString& parameter) override;
    blink::WebString QueryLocalizedString(int resource_id, const blink::WebString& parameter1, const blink::WebString& parameter2) override;

    blink::WebString UserAgent() override;
    blink::UserAgentMetadata UserAgentMetadata() override;

    bool IsTakingV8ContextSnapshot() override;

    void setUserAgent(const std::string& ua);
    // WebWorker ----------------------------------------------------------

    blink::WebCrypto* Crypto() override;

    std::unique_ptr<blink::WebDedicatedWorkerHostFactoryClient> CreateDedicatedWorkerHostFactoryClient(
        blink::WebDedicatedWorker*, const blink::BrowserInterfaceBrokerProxy&) override;
    void DidStartWorkerThread() override;
    void WillStopWorkerThread() override;
    void WorkerContextCreated(const v8::Local<v8::Context>& worker) override;
    bool AllowScriptExtensionForServiceWorker(const blink::WebSecurityOrigin& script_origin) override;
    blink::ProtocolHandlerSecurityLevel GetProtocolHandlerSecurityLevel(const blink::WebSecurityOrigin& origin) override;
    bool OriginCanAccessServiceWorkers(const GURL& url) override;
    std::tuple<blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase>,
        blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase>>
    CloneServiceWorkerContainerHost(
        blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase> service_worker_container_host) override;

    void CreateServiceWorkerSubresourceLoaderFactory(
        blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase> service_worker_container_host, const blink::WebString& client_id,
        std::unique_ptr<network::PendingSharedURLLoaderFactory> fallback_factory, mojo::PendingReceiver<network::mojom::URLLoaderFactory> receiver,
        scoped_refptr<base::SequencedTaskRunner> task_runner) override;

    std::unique_ptr<blink::WebV8ValueConverter> CreateWebV8ValueConverter() override;

    webcrypto::WebCryptoImpl* m_webCryptoImpl = nullptr;
};

}

#endif