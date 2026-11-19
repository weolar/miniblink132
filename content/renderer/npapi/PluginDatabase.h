// Copyright (C) 2006, 2007 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#ifndef CONTENT_RENDERER_NPAPI_PLUGIN_DATABASE_H_
#define CONTENT_RENDERER_NPAPI_PLUGIN_DATABASE_H_

#include <map>
#include <set>
#include <string>
#include <vector>

#include "base/memory/scoped_refptr.h"
#include "content/renderer/npapi/PluginPackage.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace content {

class PluginDatabase {
public:
    PluginDatabase() = default;
    PluginDatabase(const PluginDatabase&) = delete;
    PluginDatabase& operator=(const PluginDatabase&) = delete;

    static PluginDatabase* installedPlugins(bool populate = true);

    bool refresh();
    void clear();
    std::vector<PluginPackage*> plugins() const;
    bool isMIMETypeRegistered(const std::string& mimeType);
    void addExtraPluginDirectory(const WTF::String& directory);

    static bool isPreferredPluginDirectory(const WTF::String& directory);
    static std::vector<WTF::String> defaultPluginDirectories();

    PluginPackage* findPlugin(const blink::KURL& url, std::string& mimeType);
    PluginPackage* pluginForMIMEType(const std::string& mimeType);
    void setPreferredPluginForMIMEType(const std::string& mimeType, PluginPackage* plugin);

    void setPluginDirectories(const std::vector<WTF::String>& directories)
    {
        clear();
        m_pluginDirectories = directories;
    }

    std::string MIMETypeForExtension(const std::string& extension) const;
    bool addVirtualPlugin(scoped_refptr<PluginPackage> package) { return add(std::move(package)); }

private:
    void getPluginPathsInDirectories(std::map<std::string, std::string>& pathsByLowerKey) const;
    void getDeletedPlugins(std::vector<PluginPackage*>& plugins) const;
    bool fileExistsAndIsNotDisabled(const std::string& filePath) const;

    bool add(scoped_refptr<PluginPackage> package);
    void remove(PluginPackage* package);

    std::set<std::string> m_disabledPluginFiles;
    std::vector<WTF::String> m_pluginDirectories;
    std::set<std::string> m_registeredMIMETypes;
    std::vector<scoped_refptr<PluginPackage>> m_plugins;
    std::map<std::string, scoped_refptr<PluginPackage>> m_pluginsByPath;
    std::map<std::string, time_t> m_pluginPathsWithTimes;
    std::map<std::string, scoped_refptr<PluginPackage>> m_preferredPlugins;
};

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_PLUGIN_DATABASE_H_
