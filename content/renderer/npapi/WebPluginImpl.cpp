// Copyright (C) 2006-2010 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#include "content/renderer/npapi/WebPluginImpl.h"

#include <algorithm>
#include <cstring>
#include <map>

#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "base/functional/bind.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "base/task/single_thread_task_runner.h"
#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "content/renderer/npapi/PluginDatabase.h"
#include "content/renderer/npapi/PluginMainThreadScheduler.h"
#include "content/renderer/npapi/PluginMessageThrottlerWin.h"
#include "content/renderer/npapi/WebPluginImeWin.h"
#include "content/renderer/npapi/npruntime_priv.h"
#include "mbnet/cookies/WebCookieJarCurlImpl.h"
#include "services/network/public/cpp/resource_request_body.h"
#include "third_party/blink/public/mojom/loader/resource_load_info.mojom-shared.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/public/platform/web_security_origin.h"
#include "third_party/blink/public/platform/web_url_request.h"
#include "third_party/blink/public/web/web_document.h"
#include "third_party/blink/public/web/web_element.h"
#include "third_party/blink/public/web/web_plugin_container.h"
#include "url/gurl.h"

namespace content {

WebPluginImpl* WebPluginImpl::s_currentPluginView = nullptr;

namespace {

int g_callingPluginCount = 0;

constexpr char kMozillaUserAgent[] =
    "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1) Gecko/20061010 Firefox/2.0";
constexpr char kChromeUserAgent[] =
    "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/534.34 (KHTML, like Gecko) Chrome/19.0.1055.1 Safari/534.34";

std::map<NPP, WebPluginImpl*>& instanceMap()
{
    static auto* s_map = new std::map<NPP, WebPluginImpl*>();
    return *s_map;
}

std::map<blink::WebLocalFrame*, std::set<WebPluginImpl*>>& manualPluginsByFrame()
{
    static auto* s_map = new std::map<blink::WebLocalFrame*, std::set<WebPluginImpl*>>();
    return *s_map;
}

char* dupUtf8String(const std::string& str)
{
    char* out = static_cast<char*>(malloc(str.size() + 1));
    memcpy(out, str.data(), str.size());
    out[str.size()] = '\0';
    return out;
}

void deferredDestroyPluginInstance(scoped_refptr<PluginPackage> plugin, bool shouldUnload, NPP instance)
{
    NPP_DestroyProcPtr destroyFunc = plugin ? plugin->pluginFuncs()->destroy : nullptr;
    if (destroyFunc && instance) {
        NPSavedData* savedData = nullptr;
        destroyFunc(instance, &savedData);
        if (savedData) {
            if (savedData->buf)
                NPN_MemFree(savedData->buf);
            NPN_MemFree(savedData);
        }
        instance->pdata = nullptr;
    }
    delete instance;
    if (shouldUnload && plugin)
        plugin->unload();
}

} // namespace

WebPluginImpl::WebPluginImpl(blink::WebLocalFrame* parentFrame, const blink::WebPluginParams& params,
    int64_t mbwebviewId, HWND parentWidget, POINT widgetOffset)
    : m_webFrame(parentFrame)
    , m_mbwebviewId(mbwebviewId)
    , m_url(params.url)
    , m_mimeType(params.mime_type.Utf8())
    , m_mode(params.load_manually ? NP_FULL : NP_EMBED)
    , m_loadManually(params.load_manually)
    , m_parentWidget(parentWidget)
    , m_widgetOffset(widgetOffset.x, widgetOffset.y)
{
    if (!m_webFrame)
        return;

    memset(&m_npWindow, 0, sizeof(m_npWindow));
    findVirtualPluginByMime();

    if (!m_plugin)
        m_plugin = PluginDatabase::installedPlugins()->findPlugin(m_url, m_mimeType);
    if (!m_plugin && PluginDatabase::installedPlugins()->refresh())
        m_plugin = PluginDatabase::installedPlugins()->findPlugin(m_url, m_mimeType);

    // Always capture initial HTML attributes so late plugin resolution in Initialize()
    // (e.g. <object> with <param name="movie"> and no data attribute) preserves all attributes.
    setParameters(params.attribute_names, params.attribute_values);

    if (!m_plugin) {
        m_status = PluginStatusCanNotFindPlugin;
        return;
    }

    ensureInstanceAllocated();
}

void WebPluginImpl::ensureInstanceAllocated()
{
    if (m_instance || !m_plugin)
        return;
    m_instance = new NPP_t();
    m_instance->ndata = this;
    m_instance->pdata = nullptr;
    instanceMap()[m_instance] = this;
}

WebPluginImpl::~WebPluginImpl()
{
    unregisterManualPlugin();
    if (m_instance) {
        instanceMap().erase(m_instance);
        delete m_instance;
        m_instance = nullptr;
    }
    freeStringArray(m_paramNames, m_paramCount);
    freeStringArray(m_paramValues, m_paramCount);
}

void WebPluginImpl::registerManualPlugin()
{
    if (m_loadManually && m_webFrame)
        manualPluginsByFrame()[m_webFrame].insert(this);
}

void WebPluginImpl::unregisterManualPlugin()
{
    if (!m_webFrame)
        return;
    auto& byFrame = manualPluginsByFrame();
    auto it = byFrame.find(m_webFrame);
    if (it != byFrame.end()) {
        it->second.erase(this);
        if (it->second.empty())
            byFrame.erase(it);
    }
}

void WebPluginImpl::notifyManualLoadFinishedForFrame(blink::WebLocalFrame* frame)
{
    if (!frame)
        return;
    auto& byFrame = manualPluginsByFrame();
    auto it = byFrame.find(frame);
    if (it == byFrame.end() || it->second.empty())
        return;

    std::vector<scoped_refptr<WebPluginImpl>> plugins;
    plugins.reserve(it->second.size());
    for (WebPluginImpl* plugin : it->second)
        plugins.emplace_back(plugin);

    for (const auto& plugin : plugins)
        plugin->DidFinishLoading();
}

bool WebPluginImpl::Initialize(blink::WebPluginContainer* container)
{
    m_pluginContainer = container;
    if (m_pluginContainer) {
        m_pluginContainer->SetWantsWheelEvents(true);

        // Chromium 132 removed <param> child element collection from HTMLObjectElement::ParametersForPlugin.
        // Recover <param name="..." value="..."> children (flashvars, movie/src, allowScriptAccess, wmode, base, etc.) here.
        blink::WebElement element = m_pluginContainer->GetElement();
        if (!element.IsNull()) {
            std::vector<blink::WebString> mergedNames;
            std::vector<blink::WebString> mergedValues;
            for (int i = 0; i < m_paramCount; ++i) {
                mergedNames.push_back(blink::WebString::FromUTF8(m_paramNames[i]));
                mergedValues.push_back(blink::WebString::FromUTF8(m_paramValues[i]));
            }

            std::string codebaseParam;
            std::string urlFromParam;
            bool foundChildParam = false;

            for (blink::WebNode child = element.FirstChild(); !child.IsNull(); child = child.NextSibling()) {
                if (!child.IsElementNode())
                    continue;
                blink::WebElement paramElem = child.To<blink::WebElement>();
                if (!paramElem.HasHTMLTagName("param"))
                    continue;

                blink::WebString rawName = paramElem.GetAttribute("name");
                if (rawName.IsEmpty())
                    continue;
                blink::WebString rawVal = paramElem.GetAttribute("value");
                std::string nameUtf8 = rawName.Utf8();
                std::string valUtf8 = rawVal.Utf8();
                foundChildParam = true;

                if (base::EqualsCaseInsensitiveASCII(nameUtf8, "codebase") && !valUtf8.empty()) {
                    codebaseParam = valUtf8;
                } else if (urlFromParam.empty()
                    && (base::EqualsCaseInsensitiveASCII(nameUtf8, "movie")
                        || base::EqualsCaseInsensitiveASCII(nameUtf8, "src")
                        || base::EqualsCaseInsensitiveASCII(nameUtf8, "data")
                        || base::EqualsCaseInsensitiveASCII(nameUtf8, "code"))
                    && !valUtf8.empty()) {
                    urlFromParam = valUtf8;
                }

                if (base::EqualsCaseInsensitiveASCII(nameUtf8, "wmode")) {
                    if (!base::EqualsCaseInsensitiveASCII(valUtf8, "opaque")
                        && !base::EqualsCaseInsensitiveASCII(valUtf8, "transparent")) {
                        rawVal = blink::WebString::FromASCII("opaque");
                    }
                    bool updatedWmode = false;
                    for (size_t idx = 0; idx < mergedNames.size(); ++idx) {
                        if (base::EqualsCaseInsensitiveASCII(mergedNames[idx].Utf8(), "wmode")) {
                            mergedValues[idx] = rawVal;
                            updatedWmode = true;
                            break;
                        }
                    }
                    if (!updatedWmode) {
                        mergedNames.push_back(rawName);
                        mergedValues.push_back(rawVal);
                    }
                    continue;
                }

                bool exists = false;
                for (size_t idx = 0; idx < mergedNames.size(); ++idx) {
                    if (base::EqualsCaseInsensitiveASCII(mergedNames[idx].Utf8(), nameUtf8)) {
                        mergedValues[idx] = rawVal;
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    mergedNames.push_back(rawName);
                    mergedValues.push_back(rawVal);
                }
            }

            if (foundChildParam) {
                if (!urlFromParam.empty()) {
                    bool hasSrc = false;
                    for (const auto& existingName : mergedNames) {
                        if (base::EqualsCaseInsensitiveASCII(existingName.Utf8(), "src")) {
                            hasSrc = true;
                            break;
                        }
                    }
                    if (!hasSrc) {
                        mergedNames.push_back(blink::WebString::FromASCII("src"));
                        mergedValues.push_back(blink::WebString::FromUTF8(urlFromParam));
                    }
                }
                freeStringArray(m_paramNames, m_paramCount);
                freeStringArray(m_paramValues, m_paramCount);
                m_paramNames = nullptr;
                m_paramValues = nullptr;
                m_paramCount = 0;
                setParameters(blink::WebVector<blink::WebString>(mergedNames), blink::WebVector<blink::WebString>(mergedValues));
            }

            if (m_url.IsEmpty() && !urlFromParam.empty() && m_webFrame) {
                blink::KURL baseKurl = m_webFrame->GetDocument().BaseURL();
                if (!codebaseParam.empty()) {
                    blink::KURL candidateBase(baseKurl, WTF::String::FromUTF8(codebaseParam));
                    if (candidateBase.IsValid())
                        baseKurl = candidateBase;
                }
                m_url = blink::KURL(baseKurl, WTF::String::FromUTF8(urlFromParam));
            }

            if (!m_plugin && m_webFrame) {
                m_plugin = PluginDatabase::installedPlugins()->findPlugin(m_url, m_mimeType);
                if (!m_plugin && PluginDatabase::installedPlugins()->refresh())
                    m_plugin = PluginDatabase::installedPlugins()->findPlugin(m_url, m_mimeType);
                if (m_plugin) {
                    ensureInstanceAllocated();
                    m_status = PluginStatusLoadedSuccessfully;
                }
            }
        }
    }
    init();
    if (m_status != PluginStatusLoadedSuccessfully || !m_isStarted) {
        // Detach from WebPluginContainerImpl before self-destroying so Oilpan GC
        // won't invoke Destroy() a second time on a freed WebPluginImpl, and allow
        // Blink to render <object> fallback content (e.g. nested <embed>).
        if (m_pluginContainer)
            m_pluginContainer->SetPlugin(nullptr);
        Destroy();
        return false;
    }
    return true;
}

void WebPluginImpl::Destroy()
{
    if (m_isDestroyed)
        return;
    m_isDestroyed = true;

    unregisterManualPlugin();
    m_requestTimer.Stop();
    m_invalidateTimer.Stop();
    m_popPopupsStateTimer.Stop();
    m_visibilityTimer.Stop();

    stop();
    if (m_hasLoadedPlugin && m_plugin) {
        m_plugin->unload();
        m_hasLoadedPlugin = false;
    }
    platformDestroy();

    if (m_windowNPObject) {
        _NPN_UnregisterObject(m_windowNPObject);
        _NPN_ReleaseObject(m_windowNPObject);
        m_windowNPObject = nullptr;
    }
    if (m_pluginElementNPObject) {
        _NPN_UnregisterObject(m_pluginElementNPObject);
        _NPN_ReleaseObject(m_pluginElementNPObject);
        m_pluginElementNPObject = nullptr;
    }

    m_pluginContainer = nullptr;
    m_webFrame = nullptr;
    Release();
}

void WebPluginImpl::init()
{
    if (m_haveInitialized)
        return;
    m_haveInitialized = true;

    if (!m_plugin && PluginDatabase::installedPlugins()->refresh())
        m_plugin = PluginDatabase::installedPlugins()->findPlugin(m_url, m_mimeType);

    if (m_plugin)
        ensureInstanceAllocated();

    if (!m_plugin || !m_instance || !m_plugin->load()) {
        m_plugin = nullptr;
        m_status = PluginStatusCanNotLoadPlugin;
        return;
    }
    m_hasLoadedPlugin = true;

    if (!start()) {
        if (m_hasLoadedPlugin && m_plugin) {
            m_plugin->unload();
            m_hasLoadedPlugin = false;
        }
        m_status = PluginStatusCanNotLoadPlugin;
        return;
    }
    m_status = PluginStatusLoadedSuccessfully;
}

bool WebPluginImpl::start()
{
    if (m_isStarted || !m_plugin || !m_instance || !m_plugin->pluginFuncs()->newp)
        return false;

    PluginMainThreadScheduler::scheduler().registerPlugin(m_instance);

    if (m_plugin->quirks().contains(PluginQuirkEmulateIme))
        WebPluginIMEWin::hookGetProcAddress(m_plugin->module());

    NPError npErr = NPERR_GENERIC_ERROR;
    {
        ScopedCurrentPluginView currentGuard(this);
        setCallingPlugin(true);
        npErr = m_plugin->pluginFuncs()->newp(
            const_cast<NPMIMEType>(m_mimeType.c_str()), m_instance, m_mode, m_paramCount, m_paramNames, m_paramValues, nullptr);
        setCallingPlugin(false);
    }

    if (npErr != NPERR_NO_ERROR) {
        m_status = PluginStatusCanNotLoadPlugin;
        PluginMainThreadScheduler::scheduler().unregisterPlugin(m_instance);
        return false;
    }

    m_isStarted = true;

    if (!m_url.IsEmpty() && !m_loadManually && m_webFrame) {
        auto req = std::make_unique<network::ResourceRequest>();
        req->method = "GET";
        req->url = GURL(m_url.GetString().Utf8());
        req->resource_type = static_cast<int>(blink::mojom::ResourceType::kObject);
        req->headers.SetHeader("User-Agent", blink::Platform::Current()->UserAgent().Utf8());
        blink::KURL docUrl = m_webFrame->GetDocument().Url();
        if (docUrl.ProtocolIsInHTTPFamily())
            req->headers.SetHeader("Referer", docUrl.GetString().Utf8());
        loadRequest(std::move(req), nullptr, false, nullptr);
    }

    m_status = PluginStatusLoadedSuccessfully;
    if (!platformStart()) {
        m_status = PluginStatusCanNotLoadPlugin;
        stop();
        return false;
    }
    return true;
}

void WebPluginImpl::stop()
{
    if (!m_isStarted)
        return;

    auto streamsCopy = m_streams;
    for (const auto& stream : streamsCopy) {
        stream->stop();
        disconnectStream(stream.get());
    }
    if (m_manualStream) {
        m_manualStream->stop();
        m_manualStream.reset();
    }

    m_isStarted = false;
    m_messageThrottler.reset();

#if defined(_WIN32)
    if (m_isWindowed && m_widget) {
        WNDPROC currentWndProc = reinterpret_cast<WNDPROC>(::GetWindowLongPtrW(m_widget, GWLP_WNDPROC));
        if (currentWndProc == PluginViewWndProc && m_pluginWndProc)
            ::SetWindowLongPtrW(m_widget, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(m_pluginWndProc));
    }
    m_pluginWndProc = nullptr;
#endif

    m_npWindow.window = nullptr;
    if (m_plugin && m_plugin->pluginFuncs()->setwindow && !m_plugin->quirks().contains(PluginQuirkDontSetNullWindowHandleOnDestroy)) {
        ScopedCurrentPluginView currentGuard(this);
        setCallingPlugin(true);
        m_plugin->pluginFuncs()->setwindow(m_instance, &m_npWindow);
        setCallingPlugin(false);
    }

    PluginMainThreadScheduler::scheduler().unregisterPlugin(m_instance);

    // Defer NPP_Destroy to the next task turn so tearing down from inside _NPN_Evaluate never crashes.
    // Keep m_plugin alive until NPP_Destroy finishes, then pair unload() with load().
    NPP instanceToDestroy = m_instance;
    m_instance = nullptr;
    if (instanceToDestroy) {
        instanceMap().erase(instanceToDestroy);
        instanceToDestroy->ndata = nullptr;
        scoped_refptr<PluginPackage> pkg = m_plugin;
        bool shouldUnload = m_hasLoadedPlugin;
        m_hasLoadedPlugin = false;
        base::SingleThreadTaskRunner::GetCurrentDefault()->PostTask(
            FROM_HERE, base::BindOnce(&deferredDestroyPluginInstance, std::move(pkg), shouldUnload, instanceToDestroy));
    }
}

void WebPluginImpl::findVirtualPluginByMime()
{
    if (m_plugin)
        return;
    for (int i = 0;; ++i) {
        std::string virtualMime = "application/virtual-plugin-" + std::to_string(i);
        scoped_refptr<PluginPackage> candidate = PluginDatabase::installedPlugins()->findPlugin(m_url, virtualMime);
        if (!candidate)
            break;
        if (!candidate->load())
            continue;
        bool matched = candidate->pluginFuncs()->newp
            && candidate->pluginFuncs()->newp(const_cast<NPMIMEType>(m_mimeType.c_str()), nullptr, 0, 0, nullptr, nullptr, nullptr) == NPERR_NO_ERROR;
        candidate->unload();
        if (matched) {
            m_plugin = std::move(candidate);
            break;
        }
    }
}

void WebPluginImpl::setParameters(const blink::WebVector<blink::WebString>& paramNames, const blink::WebVector<blink::WebString>& paramValues)
{
    size_t size = std::min(paramNames.size(), paramValues.size());
    m_paramNames = static_cast<char**>(malloc(sizeof(char*) * (size > 0 ? size : 1)));
    m_paramValues = static_cast<char**>(malloc(sizeof(char*) * (size > 0 ? size : 1)));

    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        std::string nameUtf8 = paramNames[i].Utf8();
        std::string valUtf8 = paramValues[i].Utf8();
        if (m_plugin && m_plugin->quirks().contains(PluginQuirkRemoveWindowlessVideoParam)
            && base::EqualsCaseInsensitiveASCII(nameUtf8, "windowlessvideo")) {
            continue;
        }
        if (base::EqualsCaseInsensitiveASCII(nameUtf8, "pluginspage"))
            m_pluginsPage = paramValues[i];
        if (base::EqualsCaseInsensitiveASCII(nameUtf8, "wmode")) {
            if (base::EqualsCaseInsensitiveASCII(valUtf8, "transparent")) {
                m_isWindowed = false;
                m_isTransparent = true;
            } else if (base::EqualsCaseInsensitiveASCII(valUtf8, "opaque")) {
                m_isWindowed = false;
                m_isTransparent = false;
            }
        }
        m_paramNames[count] = dupUtf8String(nameUtf8);
        m_paramValues[count] = dupUtf8String(valUtf8);
        ++count;
    }
    m_paramCount = count;
}

void WebPluginImpl::freeStringArray(char** stringArray, int length)
{
    if (!stringArray)
        return;
    for (int i = 0; i < length; ++i)
        free(stringArray[i]);
    free(stringArray);
}

void WebPluginImpl::setCurrentPluginView(WebPluginImpl* view)
{
    s_currentPluginView = view;
}

WebPluginImpl* WebPluginImpl::currentPluginView()
{
    return s_currentPluginView;
}

WebPluginImpl* WebPluginImpl::fromInstance(NPP instance)
{
    if (!instance)
        return nullptr;
    auto& map = instanceMap();
    auto it = map.find(instance);
    return (it == map.end()) ? nullptr : it->second;
}

bool WebPluginImpl::isAlive(NPP instance)
{
    return instance && instanceMap().find(instance) != instanceMap().end();
}

void WebPluginImpl::setCallingPlugin(bool calling) const
{
    if (!m_plugin || !m_plugin->quirks().contains(PluginQuirkHasModalMessageLoop))
        return;
    g_callingPluginCount += calling ? 1 : -1;
}

NPObject* WebPluginImpl::windowScriptNPObject()
{
    if (m_windowNPObject)
        return m_windowNPObject;
    if (!m_webFrame)
        return nullptr;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    if (!isolate)
        return nullptr;
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context = m_webFrame->MainWorldScriptContext();
    if (context.IsEmpty())
        return nullptr;

    m_windowNPObject = npCreateV8ScriptObject(isolate, context, m_instance, context->Global(), m_webFrame, m_mbwebviewId);
    if (m_windowNPObject)
        _NPN_RegisterObject(m_windowNPObject, nullptr);
    return m_windowNPObject;
}

NPObject* WebPluginImpl::pluginElementNPObject()
{
    if (m_pluginElementNPObject)
        return m_pluginElementNPObject;
    if (!m_pluginContainer || !m_webFrame)
        return nullptr;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    if (!isolate)
        return nullptr;
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context = m_webFrame->MainWorldScriptContext();
    if (context.IsEmpty())
        return nullptr;

    v8::Local<v8::Object> elemObj = m_pluginContainer->V8ObjectForElement();
    if (elemObj.IsEmpty())
        return nullptr;

    m_pluginElementNPObject = npCreateV8ScriptObject(isolate, context, m_instance, elemObj, m_webFrame, m_mbwebviewId);
    if (m_pluginElementNPObject)
        _NPN_RegisterObject(m_pluginElementNPObject, windowScriptNPObject());
    return m_pluginElementNPObject;
}

NPObject* WebPluginImpl::npObject()
{
    if (!m_isStarted || !m_plugin || !m_plugin->pluginFuncs()->getvalue || !m_instance)
        return nullptr;

    scoped_refptr<WebPluginImpl> protect(this);
    NPObject* object = nullptr;
    NPError npErr = NPERR_GENERIC_ERROR;
    {
        ScopedCurrentPluginView currentGuard(this);
        setCallingPlugin(true);
        npErr = m_plugin->pluginFuncs()->getvalue(m_instance, NPPVpluginScriptableNPObject, &object);
        setCallingPlugin(false);
    }
    return (npErr == NPERR_NO_ERROR) ? object : nullptr;
}

v8::Local<v8::Object> WebPluginImpl::V8ScriptableObject(v8::Isolate* isolate)
{
    if (!m_webFrame || !isolate)
        return v8::Local<v8::Object>();

    NPObject* scriptObj = npObject();
    if (!scriptObj)
        return v8::Local<v8::Object>();

    v8::EscapableHandleScope handleScope(isolate);
    v8::Local<v8::Context> context = m_webFrame->MainWorldScriptContext();
    if (context.IsEmpty()) {
        _NPN_ReleaseObject(scriptObj);
        return v8::Local<v8::Object>();
    }

    v8::Context::Scope contextScope(context);
    v8::Local<v8::Object> wrapped = createV8ObjectForNPObject(isolate, context, scriptObj, windowScriptNPObject());
    // NPPVpluginScriptableNPObject returns a retained reference; createV8ObjectForNPObject also retains it.
    _NPN_ReleaseObject(scriptObj);
    return handleScope.Escape(wrapped);
}

const char* WebPluginImpl::userAgent()
{
    if (m_plugin && m_plugin->quirks().contains(PluginQuirkWantsMozillaUserAgent))
        return kMozillaUserAgent;
    if (m_plugin && m_plugin->quirks().contains(PluginQuirkWantsChromeUserAgent))
        return kChromeUserAgent;
    if (m_userAgent.empty())
        m_userAgent = blink::Platform::Current()->UserAgent().Utf8();
    return m_userAgent.c_str();
}

const char* WebPluginImpl::userAgentStatic()
{
    return kMozillaUserAgent;
}

void WebPluginImpl::status(const char*) { }

NPError WebPluginImpl::setValue(NPPVariable variable, void* value)
{
    switch (variable) {
    case NPPVpluginWindowBool:
        m_isWindowed = (value != nullptr);
        return NPERR_NO_ERROR;
    case NPPVpluginTransparentBool:
        m_isTransparent = (value != nullptr);
        return NPERR_NO_ERROR;
    default:
        return NPERR_GENERIC_ERROR;
    }
}

NPError WebPluginImpl::getValueStatic(NPNVariable variable, void* value)
{
    NPError result = NPERR_GENERIC_ERROR;
    if (platformGetValueStatic(variable, value, &result))
        return result;
    return NPERR_GENERIC_ERROR;
}

NPError WebPluginImpl::getValue(NPNVariable variable, void* value)
{
    if (!value)
        return NPERR_INVALID_PARAM;

    NPError result = NPERR_GENERIC_ERROR;
    if (platformGetValue(variable, value, &result) || platformGetValueStatic(variable, value, &result))
        return result;

    switch (variable) {
    case NPNVjavascriptEnabledBool:
        *static_cast<NPBool*>(value) = TRUE;
        return NPERR_NO_ERROR;
    case NPNVisOfflineBool:
        *static_cast<NPBool*>(value) = FALSE;
        return NPERR_NO_ERROR;
    case NPNVWindowNPObject: {
        NPObject* winObj = windowScriptNPObject();
        if (winObj)
            _NPN_RetainObject(winObj);
        *static_cast<void**>(value) = winObj;
        return NPERR_NO_ERROR;
    }
    case NPNVPluginElementNPObject: {
        NPObject* elemObj = pluginElementNPObject();
        if (elemObj)
            _NPN_RetainObject(elemObj);
        *static_cast<void**>(value) = elemObj;
        return NPERR_NO_ERROR;
    }
    case NPNVprivateModeBool:
        *static_cast<NPBool*>(value) = FALSE;
        return NPERR_NO_ERROR;
    case NPNVdocumentOrigin: {
        if (!m_webFrame)
            return NPERR_GENERIC_ERROR;
        std::string origin = m_webFrame->GetSecurityOrigin().ToString().Utf8();
        char* originCopy = static_cast<char*>(NPN_MemAlloc(static_cast<uint32_t>(origin.size() + 1)));
        if (!originCopy)
            return NPERR_OUT_OF_MEMORY_ERROR;
        memcpy(originCopy, origin.data(), origin.size() + 1);
        *static_cast<char**>(value) = originCopy;
        return NPERR_NO_ERROR;
    }
    default:
        return NPERR_GENERIC_ERROR;
    }
}

NPError WebPluginImpl::getValueForURL(NPNURLVariable variable, const char* url, char** value, uint32_t* len)
{
    if (!m_webFrame || !url || !value)
        return NPERR_INVALID_PARAM;

    if (variable == NPNURLVCookie) {
        blink::KURL u(m_webFrame->GetDocument().BaseURL(), WTF::String::FromUTF8(url));
        if (!u.IsValid())
            return NPERR_INVALID_URL;
        auto* webview = static_cast<MbWebView*>(common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId));
        if (!webview || !webview->getWebCookieJarImpl())
            return NPERR_GENERIC_ERROR;

        // Do not expose HttpOnly cookies to NPAPI plugins.
        std::string cookieStr = webview->getWebCookieJarImpl()->getCookiesForSession(u, false);
        uint32_t size = static_cast<uint32_t>(cookieStr.size());
        *value = static_cast<char*>(NPN_MemAlloc(size + 1));
        if (!*value)
            return NPERR_OUT_OF_MEMORY_ERROR;
        memcpy(*value, cookieStr.data(), size + 1);
        if (len)
            *len = size;
        return NPERR_NO_ERROR;
    }
    return NPERR_GENERIC_ERROR;
}

NPError WebPluginImpl::setValueForURL(NPNURLVariable variable, const char* url, const char* value, uint32_t len)
{
    if (!m_webFrame || !url || !value)
        return NPERR_INVALID_PARAM;

    if (variable == NPNURLVCookie) {
        blink::KURL u(m_webFrame->GetDocument().BaseURL(), WTF::String::FromUTF8(url));
        if (!u.IsValid())
            return NPERR_INVALID_URL;
        auto* webview = static_cast<MbWebView*>(common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId));
        if (webview && webview->getWebCookieJarImpl())
            webview->getWebCookieJarImpl()->setCookiesFromDOM(m_webFrame->GetDocument().BaseURL(), u, std::string(value, len));
        return NPERR_NO_ERROR;
    }
    return NPERR_GENERIC_ERROR;
}

NPError WebPluginImpl::getAuthenticationInfo(
    const char*, const char*, int32_t, const char*, const char*, char**, uint32_t*, char**, uint32_t*)
{
    return NPERR_GENERIC_ERROR;
}

void WebPluginImpl::pushPopupsEnabledState(bool state)
{
    m_popupStateStack.push_back(state);
}

void WebPluginImpl::popPopupsEnabledState()
{
    if (!m_popupStateStack.empty())
        m_popupStateStack.pop_back();
}

void WebPluginImpl::popPopupsStateTimerFired()
{
    popPopupsEnabledState();
}

bool WebPluginImpl::arePopupsAllowed() const
{
    return !m_popupStateStack.empty() && m_popupStateStack.back();
}

} // namespace content
