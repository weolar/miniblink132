
#ifndef content_renderer_BlinkInterfaceRegistryImpl_h
#define content_renderer_BlinkInterfaceRegistryImpl_h

#include "third_party/blink/public/mojom/reporting/reporting.mojom-blink.h"
#include "third_party/blink/public/platform/interface_registry.h"

namespace content {

class WebLocalFrameClientImpl;

class BlinkInterfaceRegistryImpl : public blink::InterfaceRegistry {
public:
    BlinkInterfaceRegistryImpl(WebLocalFrameClientImpl* frameClient);
    ~BlinkInterfaceRegistryImpl();

    // blink::InterfaceRegistry override.
    void AddInterface(const char* name, const blink::InterfaceFactory& factory, scoped_refptr<base::SingleThreadTaskRunner> task_runner) override;

    void AddAssociatedInterface(const char* name, const blink::AssociatedInterfaceFactory& factory) override;

private:
    WebLocalFrameClientImpl* m_frameClient;
    //     const base::WeakPtr<service_manager::BinderRegistry> interface_registry_;
    //     const base::WeakPtr<blink::AssociatedInterfaceRegistry> associated_interface_registry_;
    //
    //     DISALLOW_COPY_AND_ASSIGN(BlinkInterfaceRegistryImpl);
};

}

#endif // content_renderer_BlinkInterfaceRegistryImpl_h