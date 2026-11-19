// Copyright (C) 2006, 2007 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#ifndef CONTENT_RENDERER_NPAPI_PLUGIN_PACKAGE_H_
#define CONTENT_RENDERER_NPAPI_PLUGIN_PACKAGE_H_

#include <map>
#include <string>
#include <vector>

#include "base/memory/ref_counted.h"
#include "base/memory/scoped_refptr.h"
#include "base/timer/timer.h"
#include "content/renderer/npapi/PluginQuirkSet.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/npapi/bindings/npfunctions.h"
#include <windows.h>

namespace content {

using MIMEToDescriptionsMap = std::map<std::string, WTF::String>;
using MIMEToExtensionsMap = std::map<std::string, std::vector<std::string>>;
using PlatformModule = HMODULE;

struct PlatformModuleVersion {
    unsigned leastSig = 0;
    unsigned mostSig = 0;

    PlatformModuleVersion() = default;
    explicit PlatformModuleVersion(unsigned)
        : leastSig(0)
        , mostSig(0)
    {
    }
    PlatformModuleVersion(unsigned lsb, unsigned msb)
        : leastSig(lsb)
        , mostSig(msb)
    {
    }
};

class PluginPackage : public base::RefCounted<PluginPackage> {
public:
    static scoped_refptr<PluginPackage> createPackage(const WTF::String& path, time_t lastModified);
    static scoped_refptr<PluginPackage> createVirtualPackage(
        NP_InitializeFuncPtr npInitialize, NP_GetEntryPointsFuncPtr npGetEntryPoints, NPP_ShutdownProcPtr nppShutdown);

    const WTF::String& name() const { return m_name; }
    const WTF::String& description() const { return m_description; }
    const WTF::String& path() const { return m_path; }
    const WTF::String& fileName() const { return m_fileName; }
    const WTF::String& parentDirectory() const { return m_parentDirectory; }
    PlatformModule module() const { return m_module; }
    uint16_t NPVersion() const { return NPVERS_HAS_PRIVATE_MODE; }
    time_t lastModified() const { return m_lastModified; }

    const MIMEToDescriptionsMap& mimeToDescriptions() const { return m_mimeToDescriptions; }
    const MIMEToExtensionsMap& mimeToExtensions() const { return m_mimeToExtensions; }

    static bool equal(const PluginPackage& a, const PluginPackage& b);

    bool load();
    void unload();
    void unloadWithoutShutdown();

    bool isEnabled() const { return m_isEnabled; }
    void setEnabled(bool enabled) { m_isEnabled = enabled; }
    bool isVirtual() const { return m_isVirtual; }

    const NPPluginFuncs* pluginFuncs() const { return &m_pluginFuncs; }
    const NPNetscapeFuncs* browserFuncs() const { return &m_browserFuncs; }

    int compareFileVersion(const PlatformModuleVersion& compareVersion) const;
    int compare(const PluginPackage& compareTo) const;
    PluginQuirkSet quirks() const { return m_quirks; }
    const PlatformModuleVersion& version() const { return m_moduleVersion; }

private:
    friend class base::RefCounted<PluginPackage>;
    PluginPackage(const WTF::String& path, time_t lastModified);
    ~PluginPackage();

    bool doLoad();
    bool fetchInfo();
    bool isPluginBlacklisted() const;
    void determineQuirks(const std::string& mimeType);
    void initializeBrowserFuncs();
    void freeLibrarySoon();
    void freeLibraryTimerFired();

    bool m_isEnabled = true;
    bool m_isLoaded = false;
    int m_loadCount = 0;

    WTF::String m_description;
    WTF::String m_path;
    WTF::String m_fileName;
    WTF::String m_name;
    WTF::String m_parentDirectory;

    PlatformModuleVersion m_moduleVersion;
    MIMEToDescriptionsMap m_mimeToDescriptions;
    MIMEToExtensionsMap m_mimeToExtensions;

    PlatformModule m_module = nullptr;
    time_t m_lastModified = 0;

    bool m_isVirtual = false;
    NP_GetEntryPointsFuncPtr m_NP_GetEntryPoints = nullptr;
    NP_InitializeFuncPtr m_NP_Initialize = nullptr;
    NPP_ShutdownProcPtr m_NPP_Shutdown = nullptr;

    NPPluginFuncs m_pluginFuncs {};
    NPNetscapeFuncs m_browserFuncs {};

    base::OneShotTimer m_freeLibraryTimer;
    PluginQuirkSet m_quirks;
};

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_PLUGIN_PACKAGE_H_
