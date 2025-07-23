
#include "third_party/blink/public/mojom/plugins/plugin_registry.mojom-blink.h"

bool blink::mojom::blink::PluginRegistry::GetPlugins(bool refresh, WTF::Vector<::blink::mojom::blink::PluginInfoPtr>*)
{
    *(int*)1 = 1;
    return true;
}

namespace content {

class PluginRegistryImpl : public ::blink::mojom::blink::PluginRegistry {
public:
    bool GetPlugins(bool refresh, WTF::Vector<::blink::mojom::blink::PluginInfoPtr>* out_plugins) override
    {
        return true;
    }

    //using GetPluginsCallback = base::OnceCallback<void(WTF::Vector<PluginInfoPtr>)>;
    void GetPlugins(bool refresh, ::blink::mojom::blink::PluginRegistry::GetPluginsCallback callback) override
    {
        WTF::Vector<::blink::mojom::blink::PluginInfoPtr> pluginInfo;
        std::move(callback).Run(std::move(pluginInfo));
    }
};

}