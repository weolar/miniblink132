// Copyright (C) 2008 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#ifndef CONTENT_RENDERER_NPAPI_PLUGIN_QUIRK_SET_H_
#define CONTENT_RENDERER_NPAPI_PLUGIN_QUIRK_SET_H_

#include "mbvip/core/mb.h"

namespace content {

enum PluginQuirk {
    PluginQuirkWantsMozillaUserAgent = 1 << 0,
    PluginQuirkDeferFirstSetWindowCall = 1 << 1,
    PluginQuirkThrottleInvalidate = 1 << 2,
    PluginQuirkRemoveWindowlessVideoParam = 1 << 3,
    PluginQuirkThrottleWMUserPlusOneMessages = 1 << 4,
    PluginQuirkDontUnloadPlugin = 1 << 5,
    PluginQuirkDontCallWndProcForSameMessageRecursively = 1 << 6,
    PluginQuirkHasModalMessageLoop = 1 << 7,
    PluginQuirkFlashURLNotifyBug = 1 << 8,
    PluginQuirkDontClipToZeroRectWhenScrolling = 1 << 9,
    PluginQuirkDontSetNullWindowHandleOnDestroy = 1 << 10,
    PluginQuirkDontAllowMultipleInstances = 1 << 11,
    PluginQuirkRequiresGtkToolKit = 1 << 12,
    PluginQuirkRequiresDefaultScreenDepth = 1 << 13,
    PluginQuirkDontCallSetWindowMoreThanOnce = 1 << 14,
    PluginQuirkIgnoreRightClickInWindowlessMode = 1 << 15,
    PluginQuirkWantsChromeUserAgent = 1 << 16,
    PluginQuirkEmulateIme = 1 << 17
};

class PluginQuirkSet {
public:
    PluginQuirkSet()
        : m_quirks(0)
    {
    }
    void add(PluginQuirk quirk)
    {
        m_quirks |= quirk;
    }
    bool contains(PluginQuirk quirk) const
    {
        return (m_quirks & quirk) != 0;
    }

private:
    unsigned m_quirks;
};

bool isNpapiPluginsEnabled();
void setNpapiPluginsEnabled(bool enabled);

void setNpapiPluginListCallback(mbGetPluginListCallback callback, void* param);
mbGetPluginListCallback getNpapiPluginListCallback();
void* getNpapiPluginListCallbackParam();
void getNpapiPluginListCallbackWithParam(mbGetPluginListCallback* outCallback, void** outParam);

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_PLUGIN_QUIRK_SET_H_
