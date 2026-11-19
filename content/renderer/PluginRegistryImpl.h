#ifndef content_renderer_PluginRegistryImpl_h
#define content_renderer_PluginRegistryImpl_h

#include "base/files/file_path.h"
#include "content/renderer/npapi/PluginDatabase.h"
#include "content/renderer/npapi/PluginQuirkSet.h"
#include "third_party/blink/public/mojom/plugins/plugin_registry.mojom-blink.h"

inline bool blink::mojom::blink::PluginRegistry::GetPlugins(bool refresh, WTF::Vector<::blink::mojom::blink::PluginInfoPtr>* out_plugins)
{
    if (out_plugins)
        out_plugins->clear();
    return false;
}

namespace content {

class PluginRegistryImpl : public ::blink::mojom::blink::PluginRegistry {
public:
    bool GetPlugins(bool refresh, WTF::Vector<::blink::mojom::blink::PluginInfoPtr>* out_plugins) override
    {
        fillPluginInfoList(refresh, out_plugins);
        return true;
    }

    void GetPlugins(bool refresh, ::blink::mojom::blink::PluginRegistry::GetPluginsCallback callback) override
    {
        WTF::Vector<::blink::mojom::blink::PluginInfoPtr> pluginInfo;
        fillPluginInfoList(refresh, &pluginInfo);
        std::move(callback).Run(std::move(pluginInfo));
    }

private:
    static void fillPluginInfoList(bool refresh, WTF::Vector<::blink::mojom::blink::PluginInfoPtr>* out_plugins)
    {
        if (!out_plugins)
            return;
        out_plugins->clear();

        if (!isNpapiPluginsEnabled())
            return;

        mbGetPluginListCallback customCb = nullptr;
        void* customParam = nullptr;
        getNpapiPluginListCallbackWithParam(&customCb, &customParam);
        if (customCb) {
            if (customCb(refresh ? TRUE : FALSE, out_plugins, customParam))
                return;
            out_plugins->clear();
        }

        PluginDatabase* db = PluginDatabase::installedPlugins(true);
        if (!db)
            return;
        if (refresh)
            db->refresh();

        const std::vector<PluginPackage*>& pkgs = db->plugins();
        for (PluginPackage* pkg : pkgs) {
            if (!pkg || !pkg->isEnabled())
                continue;

            auto info = ::blink::mojom::blink::PluginInfo::New();
            info->name = pkg->name();
            info->description = pkg->description();
            std::string pathUtf8 = pkg->path().Utf8();
            info->filename = base::FilePath::FromUTF8Unsafe(pathUtf8);
            info->background_color = 0xFFFFFFFF;
            info->may_use_external_handler = false;

            const MIMEToDescriptionsMap& mimeDescs = pkg->mimeToDescriptions();
            const MIMEToExtensionsMap& mimeExts = pkg->mimeToExtensions();
            for (const auto& pair : mimeDescs) {
                auto mime = ::blink::mojom::blink::PluginMimeType::New();
                mime->mime_type = WTF::String::FromUTF8(pair.first);
                mime->description = pair.second;
                auto extIt = mimeExts.find(pair.first);
                if (extIt != mimeExts.end()) {
                    for (const std::string& ext : extIt->second)
                        mime->file_extensions.push_back(WTF::String::FromUTF8(ext));
                }
                info->mime_types.push_back(std::move(mime));
            }
            out_plugins->push_back(std::move(info));
        }
    }
};

} // namespace content

#endif // content_renderer_PluginRegistryImpl_h
