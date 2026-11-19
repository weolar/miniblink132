// Copyright (C) 2006, 2007 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#include "content/renderer/npapi/PluginMainThreadScheduler.h"
#include "content/renderer/npapi/WebPluginImpl.h"
#include "third_party/blink/renderer/core/page/plugin_data.h"
#include "third_party/npapi/bindings/npruntime.h"
#include <stdlib.h>

using namespace content;

// Sometimes plug-ins (specifically Flash) call instance-specific NPN_* functions
// with a NULL instance during NPP_New. Fall back to WebPluginImpl::currentPluginView().
static WebPluginImpl* pluginViewForInstance(NPP instance)
{
    if (instance) {
        if (WebPluginImpl::isAlive(instance) && instance->ndata)
            return static_cast<WebPluginImpl*>(instance->ndata);
        return nullptr;
    }
    return WebPluginImpl::currentPluginView();
}

void* NPN_MemAlloc(uint32_t size)
{
    return malloc(size);
}

void NPN_MemFree(void* ptr)
{
    free(ptr);
}

uint32_t NPN_MemFlush(uint32_t)
{
    return 0;
}

void NPN_ReloadPlugins(NPBool)
{
    blink::PluginData::RefreshBrowserSidePluginCache();
}

NPError NPN_RequestRead(NPStream*, NPByteRange*)
{
    return NPERR_STREAM_NOT_SEEKABLE;
}

NPError NPN_GetURLNotify(NPP instance, const char* url, const char* target, void* notifyData)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->getURLNotify(url, target, notifyData);
}

NPError NPN_GetURL(NPP instance, const char* url, const char* target)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->getURL(url, target);
}

NPError NPN_PostURLNotify(NPP instance, const char* url, const char* target, uint32_t len, const char* buf, NPBool file, void* notifyData)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->postURLNotify(url, target, len, buf, file, notifyData);
}

NPError NPN_PostURL(NPP instance, const char* url, const char* target, uint32_t len, const char* buf, NPBool file)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->postURL(url, target, len, buf, file);
}

NPError NPN_NewStream(NPP instance, NPMIMEType type, const char* target, NPStream** stream)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->newStream(type, target, stream);
}

int32_t NPN_Write(NPP instance, NPStream* stream, int32_t len, void* buffer)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->write(stream, len, buffer);
}

NPError NPN_DestroyStream(NPP instance, NPStream* stream, NPReason reason)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->destroyStream(stream, reason);
}

const char* NPN_UserAgent(NPP instance)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return WebPluginImpl::userAgentStatic();
    return view->userAgent();
}

void NPN_Status(NPP instance, const char* message)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (view)
        view->status(message);
}

void NPN_InvalidateRect(NPP instance, NPRect* invalidRect)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (view)
        view->invalidateRect(invalidRect);
}

void NPN_InvalidateRegion(NPP instance, NPRegion invalidRegion)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (view)
        view->invalidateRegion(invalidRegion);
}

void NPN_ForceRedraw(NPP instance)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (view)
        view->forceRedraw();
}

NPError NPN_GetValue(NPP instance, NPNVariable variable, void* value)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return WebPluginImpl::getValueStatic(variable, value);
    return view->getValue(variable, value);
}

NPError NPN_SetValue(NPP instance, NPPVariable variable, void* value)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->setValue(variable, value);
}

void* NPN_GetJavaEnv()
{
    return nullptr;
}

void* NPN_GetJavaPeer(NPP)
{
    return nullptr;
}

void NPN_PushPopupsEnabledState(NPP instance, NPBool enabled)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (view)
        view->pushPopupsEnabledState(enabled != 0);
}

void NPN_PopPopupsEnabledState(NPP instance)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (view)
        view->popPopupsEnabledState();
}

extern "C" typedef void PluginThreadAsyncCallFunction(void*);
void NPN_PluginThreadAsyncCall(NPP instance, PluginThreadAsyncCallFunction func, void* userData)
{
    PluginMainThreadScheduler::scheduler().scheduleCall(
        instance, reinterpret_cast<PluginMainThreadScheduler::MainThreadFunction*>(func), userData);
}

NPError NPN_GetValueForURL(NPP instance, NPNURLVariable variable, const char* url, char** value, uint32_t* len)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->getValueForURL(variable, url, value, len);
}

NPError NPN_SetValueForURL(NPP instance, NPNURLVariable variable, const char* url, const char* value, uint32_t len)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->setValueForURL(variable, url, value, len);
}

NPError NPN_GetAuthenticationInfo(NPP instance, const char* protocol, const char* host, int32_t port,
    const char* scheme, const char* realm, char** username, uint32_t* ulen, char** password, uint32_t* plen)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return view->getAuthenticationInfo(protocol, host, port, scheme, realm, username, ulen, password, plen);
}

NPError NPN_PopUpContextMenu(NPP instance, NPMenu*)
{
    WebPluginImpl* view = pluginViewForInstance(instance);
    if (!view)
        return NPERR_INVALID_INSTANCE_ERROR;
    return NPERR_NO_ERROR;
}
