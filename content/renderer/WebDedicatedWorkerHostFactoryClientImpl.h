
#ifndef content_renderer_WebDedicatedWorkerHostFactoryClientImpl_h
#define content_renderer_WebDedicatedWorkerHostFactoryClientImpl_h

#include "third_party/blink/public/platform/web_dedicated_worker_host_factory_client.h"
#include "gen/third_party/blink/public/mojom/browser_interface_broker.mojom.h"
#include "gen/third_party/blink/public/mojom/worker/dedicated_worker_host.mojom-blink.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "base/memory/weak_ptr.h"

namespace blink {
class WebDedicatedWorker;
}

namespace content {

class DedicatedWorkerHostImpl;
class DedicatedWorkerHostBrowserInterfaceBroker;

class WebDedicatedWorkerHostFactoryClientImpl : public blink::WebDedicatedWorkerHostFactoryClient {
public:
    WebDedicatedWorkerHostFactoryClientImpl(blink::WebDedicatedWorker* worker);
    ~WebDedicatedWorkerHostFactoryClientImpl() override;

    void CreateWorkerHostDeprecated(const blink::DedicatedWorkerToken& dedicated_worker_token, const blink::WebURL& script_url, 
        const blink::WebSecurityOrigin& origin, blink::WebDedicatedWorkerHostFactoryClient::CreateWorkerHostCallback callback) override;

    void CreateWorkerHost(const blink::DedicatedWorkerToken& dedicated_worker_token, const blink::WebURL& script_url,
        network::mojom::CredentialsMode credentials_mode, const blink::WebFetchClientSettingsObject& fetch_client_settings_object,
        blink::CrossVariantMojoRemote<blink::mojom::BlobURLTokenInterfaceBase> blob_url_token, net::StorageAccessApiStatus storage_access_api_status) override;

    scoped_refptr<blink::WebWorkerFetchContext> CloneWorkerFetchContext(blink::WebWorkerFetchContext*, scoped_refptr<base::SingleThreadTaskRunner>) override;

private:
    blink::WebDedicatedWorker* m_worker;
    DedicatedWorkerHostBrowserInterfaceBroker* m_browserInterfaceBrokerImpl = nullptr;
    //mojo::Receiver<::blink::mojom::BrowserInterfaceBroker> m_browserInterfaceBroker;
    //mojo::Receiver<::blink::mojom::blink::DedicatedWorkerHost> m_dedicatedWorkerHost;
    DedicatedWorkerHostImpl* m_dedicatedWorkerHost = nullptr;

    base::WeakPtrFactory<WebDedicatedWorkerHostFactoryClientImpl> m_weakFactory;
};

}

#endif // content_renderer_WebDedicatedWorkerHostFactoryClientImpl_h