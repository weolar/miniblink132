
#ifndef content_browser_DomStorageProviderImpl_h
#define content_browser_DomStorageProviderImpl_h

#include "third_party/blink/public/mojom/dom_storage/dom_storage.mojom-blink.h"

namespace content {

class DomStorageProviderImpl : public ::blink::mojom::blink::DomStorageProvider {
public:
    DomStorageProviderImpl();

    void BindDomStorage(
        ::mojo::PendingReceiver<::blink::mojom::blink::DomStorage> receiver, ::mojo::PendingRemote<::blink::mojom::blink::DomStorageClient> client) override;
};

}

#endif // content_browser_DomStorageProviderImpl_h