
#include "electron/browser/api/ApiWebContents.h"

#include "electron/browser/api/WindowInterface.h"
#include "electron/browser/api/WindowList.h"
#include "electron/browser/api/ApiSession.h"
#include "electron/browser/api/ApiWebFrameMain.h"
#include "electron/browser/api/PostMessageUtil.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/IdLiveDetect.h"
#include "electron/common/NodeBinding.h"
#include "electron/common/api/EventEmitterCaller.h"
#include "electron/common/StringUtil.h"
#include "electron/common/WorldIDs.h"
#include "electron/common/mbexport.h"
#include "electron/common/PlatformUtil.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/EventEmitterCaller.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "gin/handle.h"
#include "content/common/ThreadCall.h"
#include "mojo/public/cpp/bindings/message.h"
#include "mojo/public/cpp/bindings/connector.h"
#include "mojo/public/cpp/system/message_pipe.h"
#include "third_party/blink/renderer/platform/bindings/v8_per_context_data.h"
#include "third_party/blink/renderer/platform/wtf/wtf.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libuv/include/uv.h"
#include "third_party/blink/public/web/blink.h"
#include "base/values.h"
#include <shlwapi.h>

void MB_CALL_TYPE mbGetWorldScriptContextByWebFrame(mbWebView webviewHandle, mbWebFrameHandle frameId, int worldID, v8ContextPtr contextOut);
void MB_CALL_TYPE mbDownloadUrl(mbWebView webviewHandle, mbWebFrameHandle frameId, const std::string& url);

namespace content {
void printCallstack();
}

namespace atom {

void WebContents::init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, WebContents::newFunction);

    prototype->SetClassName(v8::String::NewFromUtf8(isolate, "WebContents").ToLocalChecked());
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("getId", &WebContents::getIdApi);
    builder.SetMethod("getProcessId", &WebContents::getProcessIdApi);
    builder.SetMethod("equal", &WebContents::equalApi);
    builder.SetMethod("_loadURL", &WebContents::_loadURLApi);
    builder.SetMethod("loadURL", &WebContents::_loadURLApi);
    builder.SetMethod("downloadURL", &WebContents::downloadURLApi);
    builder.SetMethod("_getURL", &WebContents::_getURLApi);
    builder.SetMethod("getTitle", &WebContents::getTitleApi);
    builder.SetMethod("isLoading", &WebContents::isLoadingApi);
    builder.SetMethod("isLoadingMainFrame", &WebContents::isLoadingMainFrameApi);
    builder.SetMethod("isWaitingForResponse", &WebContents::isWaitingForResponseApi);
    builder.SetMethod("stop", &WebContents::stopApi);
    builder.SetMethod("goBack", &WebContents::goBackApi);
    builder.SetMethod("goForward", &WebContents::goForwardApi);
    builder.SetMethod("goToOffset", &WebContents::goToOffsetApi);
    builder.SetMethod("goToIndex", &WebContents::goToIndexApi);
    builder.SetMethod("isCrashed", &WebContents::isCrashedApi);
    builder.SetMethod("setUserAgent", &WebContents::setUserAgentApi);
    builder.SetMethod("getUserAgent", &WebContents::getUserAgentApi);
    builder.SetMethod("savePage", &WebContents::savePageApi);
    builder.SetMethod("openDevTools", &WebContents::openDevToolsApi);
    builder.SetMethod("closeDevTools", &WebContents::closeDevToolsApi);
    builder.SetMethod("isDevToolsOpened", &WebContents::isDevToolsOpenedApi);
    builder.SetMethod("isDevToolsFocused", &WebContents::isDevToolsFocusedApi);
    builder.SetMethod("insertCSS", &WebContents::insertCSSApi);
    builder.SetMethod("enableDeviceEmulation", &WebContents::enableDeviceEmulationApi);
    builder.SetMethod("disableDeviceEmulation", &WebContents::disableDeviceEmulationApi);
    builder.SetMethod("toggleDevTools", &WebContents::toggleDevToolsApi);
    builder.SetMethod("inspectElement", &WebContents::inspectElementApi);
    builder.SetMethod("setAudioMuted", &WebContents::setAudioMutedApi);
    builder.SetMethod("isAudioMuted", &WebContents::isAudioMutedApi);
    builder.SetMethod("undo", &WebContents::undoApi);
    builder.SetMethod("redo", &WebContents::redoApi);
    builder.SetMethod("cut", &WebContents::cutApi);
    builder.SetMethod("copy", &WebContents::copyApi);
    builder.SetMethod("paste", &WebContents::pasteApi);
    builder.SetMethod("pasteAndMatchStyle", &WebContents::pasteAndMatchStyleApi);
    builder.SetMethod("delete", &WebContents::_deleteApi);
    builder.SetMethod("selectAll", &WebContents::selectAllApi);
    builder.SetMethod("unselect", &WebContents::unselectApi);
    builder.SetMethod("replace", &WebContents::replaceApi);
    builder.SetMethod("replaceMisspelling", &WebContents::replaceMisspellingApi);
    builder.SetMethod("findInPage", &WebContents::findInPageApi);
    builder.SetMethod("stopFindInPage", &WebContents::stopFindInPageApi);
    builder.SetMethod("focus", &WebContents::focusApi);
    builder.SetMethod("isFocused", &WebContents::isFocusedApi);
    builder.SetMethod("tabTraverse", &WebContents::tabTraverseApi);
    builder.SetMethod("_send", &WebContents::_sendApi);
    builder.SetMethod("_postMessage", &WebContents::_postMessageApi);
    builder.SetMethod("_testPostMessage", &WebContents::_testPostMessageApi);
    builder.SetMethod("sendInputEvent", &WebContents::sendInputEventApi);
    builder.SetMethod("beginFrameSubscription", &WebContents::beginFrameSubscriptionApi);
    builder.SetMethod("endFrameSubscription", &WebContents::endFrameSubscriptionApi);
    builder.SetMethod("startDrag", &WebContents::startDragApi);
    builder.SetMethod("setSize", &WebContents::setSizeApi);
    builder.SetMethod("isGuest", &WebContents::isGuestApi);
    builder.SetMethod("isOffscreen", &WebContents::isOffscreenApi);
    builder.SetMethod("startPainting", &WebContents::startPaintingApi);
    builder.SetMethod("stopPainting", &WebContents::stopPaintingApi);
    builder.SetMethod("isPainting", &WebContents::isPaintingApi);
    builder.SetMethod("setFrameRate", &WebContents::setFrameRateApi);
    builder.SetMethod("getFrameRate", &WebContents::getFrameRateApi);
    builder.SetMethod("invalidate", &WebContents::invalidateApi);
    builder.SetMethod("getType", &WebContents::getTypeApi);
    builder.SetMethod("getWebPreferences", &WebContents::getWebPreferencesApi);
    builder.SetMethod("getOwnerBrowserWindow", &WebContents::getOwnerBrowserWindowApi);
    builder.SetMethod("hasServiceWorker", &WebContents::hasServiceWorkerApi);
    builder.SetMethod("unregisterServiceWorker", &WebContents::unregisterServiceWorkerApi);
    builder.SetMethod("inspectServiceWorker", &WebContents::inspectServiceWorkerApi);
    builder.SetMethod("print", &WebContents::printApi);
    builder.SetMethod("_printToPDF", &WebContents::_printToPDFApi);
    builder.SetMethod("addWorkSpace", &WebContents::addWorkSpaceApi);
    builder.SetMethod("reNullWorkSpace", &WebContents::reNullWorkSpaceApi);
    builder.SetMethod("showDefinitionForSelection", &WebContents::showDefinitionForSelectionApi);
    builder.SetMethod("copyImageAt", &WebContents::copyImageAtApi);
    builder.SetMethod("capturePage", &WebContents::capturePageApi);
    builder.SetMethod("setEmbedder", &WebContents::setEmbedderApi);
    builder.SetMethod("isDestroyed", &WebContents::isDestroyedApi);
    builder.SetMethod("reloadIgnoringCache", &WebContents::reloadIgnoringCacheApi);
    builder.SetMethod("reload", &WebContents::reloadIgnoringCacheApi);
    builder.SetProperty("id", &WebContents::getIdApi);
    builder.SetProperty("session", &WebContents::getSessionApi);
    builder.SetProperty("zoomFactor", &WebContents::zoomFactorApi);
    builder.SetProperty("mainFrame", &WebContents::getMainFrameApi);
    builder.SetMethod("_getZoomLevel", &WebContents::getZoomLevelApi);
    builder.SetMethod("_setZoomLevel", &WebContents::setZoomLevelApi);
    builder.SetMethod("_canGoBack", &WebContents::canGoBackApi);
    builder.SetMethod("_canGoForward", &WebContents::canGoForwardApi);
    builder.SetMethod("printToPDF", &WebContents::printToPDFApi);
    builder.SetMethod("setWindowOpenHandler", &WebContents::setWindowOpenHandlerApi);

    /// <summary>
    //     v8::Local<v8::Function> prototypFunc2 = prototype->GetFunction(context).ToLocalChecked();
    //     v8::Local<v8::Value> argv[1];
    //     v8::MaybeLocal<v8::Object> obj = prototypFunc2->NewInstance(context, 0, argv);
    ///

    v8::Local<v8::Function> prototypFunc = prototype->GetFunction(context).ToLocalChecked();

    gin_helper::Dictionary webContentsClass(isolate, prototypFunc);
    webContentsClass.SetMethod("getFocusedWebContents", &WebContents::getFocusedWebContentsApi);
    webContentsClass.SetMethod("getAllWebContents", &WebContents::getAllWebContentsApi);
    webContentsClass.SetMethod("fromId", &WebContents::fromIdApi);

    s_constructor.Reset(isolate, prototypFunc);
    target->Set(context, v8::String::NewFromUtf8(isolate, "WebContents").ToLocalChecked(), prototypFunc);
}

WebContents* WebContents::create(v8::Isolate* isolate, gin_helper::Dictionary options, WindowInterface* owner)
{
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { gin_helper::ConvertToV8(isolate, options) };
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, s_constructor);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, argc, argv); // call into WebContents::WebContents
    if (obj.IsEmpty())
        return nullptr;

    v8::Local<v8::Object> objV8 = obj.ToLocalChecked();

    WebContents* self = (WebContents*)WrappableBase::GetNativePtr(objV8, &kWrapperInfo);
    self->m_liveSelf.Reset(isolate, objV8);
    self->m_owner = owner;
    return self;
}

// class TransmitToWebContents : public mojo::MessageReceiver {
// public:
//     TransmitToWebContents(WebContents* parent, bool isMainThread, MojoHandle port)
//     {
//         m_parent = parent;
//         m_isMainThread = isMainThread;
//         m_port = port;
// 
//         m_connector = std::make_unique<mojo::Connector>(std::move(port), mojo::Connector::SINGLE_THREADED_SEND);
//         m_connector->PauseIncomingMethodCallProcessing();
//         m_connector->set_incoming_receiver(this);
//         //m_connectorOnMainUiThread->set_connection_error_handler(base::BindOnce(&ApiUtilityProcess::close, base::Unretained(this)));
//         m_connector->StartReceiving(base::SequencedTaskRunner::GetCurrentDefault());
//     }
// 
//     bool Accept(mojo::Message* message) override
//     {
// 
//     }
// 
// private:
//     WebContents* m_parent;
//     bool m_isMainThread; // 是在主线程创建还是在网页线程
//     MojoHandle m_port;
// 
//     std::unique_ptr<mojo::Connector> m_connector;
// };

WebContents::WebContents(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, const gin_helper::Dictionary& options)
{
    m_nodeBindings = new NodeBindings(false);
    m_isLoading = false;
    m_id = IdLiveDetect::get()->constructed(this);
    m_view = NULL_WEBVIEW;
    m_canGoBack = FALSE;
    m_canGoForward = FALSE;
    int id = m_id;

    options.GetBydefaultVal("preload", "", &m_preloadScriptPath);
    gin_helper::Wrappable<WebContents>::InitWith(isolate, wrapper);

    options.GetBydefaultVal("session", "", &m_sessionName);
    if (m_sessionName.empty()) {
        options.GetBydefaultVal("partition", "", &m_sessionName); //
    }
    if (!m_sessionName.empty()) {
        const char* persistPrefix = "persist:";
        size_t persistPrefixLen = strlen(persistPrefix);

        if (m_sessionName.substr(0, persistPrefixLen) == persistPrefix)
            m_sessionName = m_sessionName.substr(persistPrefixLen, std::string::npos);
    } else {
        m_sessionName = ApiSession::kDefaultSessionName;
    }

    WebContents* self = this;
    m_view = mbCreateWebView();
    mbSetUserKeyValue(m_view, "WebContents", self);
    mbSetAutoDrawToHwnd(m_view, FALSE);
    mbOnDidCreateScriptContext(m_view, &WebContents::staticDidCreateScriptContextCallback, this);
    mbOnWillReleaseScriptContext(m_view, &WebContents::staticOnWillReleaseScriptContextCallback, this);
    mbOnDownloadInBlinkThread(m_view, &WebContents::staticOnDownloadCallback, this);
    mbOnDocumentReadyInBlinkThread(m_view, &WebContents::onDocumentReadyInBlinkThread, this);
    mbOnNavigation(m_view, &WebContents::onNavigationCallback, this);
    mbOnTitleChanged(m_view, &WebContents::onTitleChanged, this);
    mbOnLoadingFinish(m_view, &WebContents::onLoadingFinishCallback, this);
    mbOnCreateView(m_view, &WebContents::onCreateViewCallback, this);
    mbOnURLChanged(m_view, &WebContents::onURLChanged, this);

    setUserAgentApi("UserAgent Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like XNT) Chrome/79.0.3945.130 Safari/537.36");

    ApiSession* session = SessionMgr::get()->findOrCreateSession(isolate, m_sessionName, true);

    std::string cookiejar = session->getPath();
    cookiejar += "\\cookie.dat";
    mbSetCookieJarFullPath(m_view, StringUtil::UTF8ToUTF16(cookiejar).c_str());
    mbSetLocalStorageFullPath(m_view, StringUtil::UTF8ToUTF16(session->getPath()).c_str());

//     m_portPipe = std::make_unique<mojo::MessagePipe>();
//     MojoHandle port0 = m_portPipe->handle0.get().value();
//     m_connectorOnMainUiThread = std::make_unique<TransmitToWebContents>(this, true, port0);
}

WebContents::~WebContents()
{
    // 在ui线程的js环境中可能因为gc机制被触发析构
    for (auto it : m_observers) {
        (it)->onWebContentsDeleted(this);
    }

    m_owner->close();
    delete m_nodeBindings;

    mbSetUserKeyValue(m_view, "WebContents", nullptr);
    IdLiveDetect::get()->deconstructed(m_id);
}

void WebContents::destroyed()
{
    mate::EventEmitter<WebContents>::emit("destroyed");
}

void WebContents::addObserver(WebContentsObserver* observer)
{
    m_observers.insert(observer);
}

void WebContents::removeObserver(WebContentsObserver* observer)
{
    auto it = m_observers.find(observer);
    m_observers.erase(it);
}

void WebContents::newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    v8::Isolate* isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    if (args.IsConstructCall()) {
        if (args.Length() > 1)
            return;

        gin_helper::Dictionary options(args.GetIsolate(), args[0]->ToObject(context).ToLocalChecked());
        WebContents* webContents = new WebContents(isolate, args.This(), options);

        args.GetReturnValue().Set(args.This());
    } else {
        const int argc = 2;
        v8::Local<v8::Value> argv[argc] = { args[0], args[1] };
        v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, s_constructor);
        args.GetReturnValue().Set(cons->NewInstance(context, argc, argv).ToLocalChecked());
    }
}

// from BrowserWindow::newWindow         -> BrowserWindow::newWindowTaskInUiThread
// or   BrowserWindow::setBrowserViewApi -> BrowserView::newViewTaskInUiThread
// void WebContents::onNewWindowInUiThread(int x, int y, int width, int height, const CreateWindowParam* createWindowParam)
// {
//     mbWebView webView = getMbView();
//     if (createWindowParam->transparent)
//         mbSetTransparent(webView, true);
//     //mbSetDebugConfig(NULL_WEBVIEW, "paintCallbackInOtherThread", nullptr);
//     mbResize(webView, width, height);
//
//     char* output = (char*)malloc(0x300);
//     sprintf_s(output, 0x299, "preload,WebContents::onNewWindowInUiThread: %p, %s\n", this, m_preloadScriptPath.c_str());
//     OutputDebugStringA(output);
//     free(output);
// }

void WebContents::staticDidCreateScriptContextCallback(mbWebView webView, void* param, mbWebFrameHandle frame, void* context, int extensionGroup, int worldId)
{
    WebContents* self = (WebContents*)param;
    self->onDidCreateScriptContext(webView, frame, (v8::Local<v8::Context>*)context, extensionGroup, worldId);
}

static void disableNodejsOfWindow(mbWebView webView, mbWebFrameHandle frame)
{
    mbRunJs(webView, frame, "window.require = null;", false, nullptr, nullptr, nullptr);
}

void WebContents::onDidCreateScriptContext(mbWebView webView, mbWebFrameHandle frame, v8::Local<v8::Context>* context, int extensionGroup, int worldId)
{
    v8::MicrotasksScope microtasksScope((*context), v8::MicrotasksScope::Type::kRunMicrotasks);
    if (!m_preloadScriptPath.empty()) {
        char* output = (char*)malloc(0x300);
        sprintf_s(output, 0x299, "preload,WebContents::onDidCreateScriptContext: %p, %s\n", this, m_preloadScriptPath.c_str());
        OutputDebugStringA(output);
        free(output);
    }

    content::ThreadCall::callUiThreadAsync(FROM_HERE, [webView] {
        std::string temp = "preload,onDidCreateScriptContext, url:";
        temp += mbGetUrl(webView);
        temp += "\n";
        OutputDebugStringA(temp.c_str());
    });

    bindMbConsoleLog(*context);

    const utf8* script = "window.Notification = function(){};";
    mbRunJs(webView, frame, script, false, nullptr, nullptr, nullptr);

    bool isMainWorld = WorldIDs::MAIN_WORLD_ID == worldId;
    bool shouldLoadNodejs = false;
    bool shouldPreLoad = false;
    bool shouldDisableNodejsOfWindow = false;

    if (m_createWindowParam->m_isContextIsolation) {
        // 有预加载，只有隔离世界有nodejs。主世界没nodejs
        if (!isMainWorld) {
            shouldLoadNodejs = true;
        } else if (mbIsMainFrame(webView, frame) && !m_preloadScriptPath.empty()) {
            char output[100] = { 0 };
            sprintf_s(output, 99, "onDidCreateScriptContext 1: %p, %d\n", frame, worldId);
            OutputDebugStringA(output);

            mbRunJs(webView, frame, "void 0", false, nullptr, nullptr, (void*)WorldIDs::ISOLATED_WORLD_ID); // 这句话会导致重入本函数
        }
    } else if (m_createWindowParam->m_isNodeIntegration && !m_createWindowParam->m_isContextIsolation) {
        // 有预加载，预加载里有nodejs，而且预加载没隔离。主世界有nodejs
        if (!isMainWorld)
            DebugBreak();
        shouldLoadNodejs = true;
    } else if (!m_createWindowParam->m_isNodeIntegration && !m_createWindowParam->m_isContextIsolation) {
        shouldLoadNodejs = true; // 有预加载，预加载里有nodejs，而且预加载没隔离。主世界没nodejs
        shouldDisableNodejsOfWindow = true; // 想办法禁用主世界的nodejs
    }

    if (!m_createWindowParam->m_isNodeIntegrationInSubframes && !mbIsMainFrame(webView, frame))
        shouldLoadNodejs = false;

    /////
    if (isMainWorld) {
        //shouldLoadNodejs = true; // 老版本electron是强行兼容，新版本不兼容算了
        shouldDisableNodejsOfWindow = false;
    }
    /////

    if (shouldLoadNodejs) {
        //blink::V8PerContextData* perCtx = blink::V8PerContextData::From(*context);
        //NodeBindingsData* nodeBinding = (NodeBindingsData*)perCtx->GetData("NodeBindings");
        //nodeBinding = blink::MakeGarbageCollected<NodeBindingsData>(false);

        v8::Isolate* isolate = (*context)->GetIsolate();
        BlinkMicrotaskSuppressionHandle handle = nodeBlinkMicrotaskSuppressionEnter(isolate);
        uv_loop_t* uvloop = content::ThreadCall::getBlinkLoop();
        m_nodeBindings->setUvLoop(uvloop);
        m_nodeBindings->m_processObjInfo.isContextIsolated = m_createWindowParam->m_isContextIsolation;

        node::Environment* env = m_nodeBindings->createEnvironment(*context);
        nodeEnvironmentAddCustomArgs(env, m_createWindowParam->m_customArgs);
        m_nodeBindings->loadEnvironment(env);

        m_environments.insert(env);

        content::ThreadCall::runBlinkThreadNode(uvloop, isolate);
        nodeBlinkMicrotaskSuppressionLeave(handle);

        //perCtx->AddData("NodeBindings", nodeBinding);

        if (m_nodeBindings->getUvEnv() == nullptr && WorldIDs::MAIN_WORLD_ID == worldId) { // 给主world main frame设置uv env
            // Make uv loop being wrapped by window context.
            m_nodeBindings->setUvEnv(env);

            // Give the node loop a run to make sure everything is ready.
            //m_nodeBindings->StartPolling();
        }

        if (!m_preloadScriptPath.empty() && mbIsMainFrame(webView, frame) && WorldIDs::ISOLATED_WORLD_ID == worldId) {
            std::string preloadScriptPath = m_preloadScriptPath;
            for (size_t i = 0; i < preloadScriptPath.size(); ++i) {
                if ('\\' == preloadScriptPath[i])
                    preloadScriptPath[i] = '/';
            }

            std::string contents = "try {window.require('";
            contents += preloadScriptPath;
            contents += "');} catch(e) { mbConsoleLog('window.require fail:' + e); }";

            char output[100] = { 0 };
            sprintf_s(output, 99, "onDidCreateScriptContext preload begin: %p, %d\n", frame, worldId);
            OutputDebugStringA(output);

            mbRunJs(webView, frame, contents.c_str(), false, nullptr, nullptr, (void*)worldId);

            sprintf_s(output, 99, "onDidCreateScriptContext preload end: %p, %d\n", frame, worldId);
            OutputDebugStringA(output);
        }
    }
    if (shouldDisableNodejsOfWindow)
        disableNodejsOfWindow(webView, frame);

    if (WorldIDs::MAIN_WORLD_ID == worldId) {
        // test:
        //         const char* testjs =
        //             "const windowProxy = new Proxy(window, {"
        //             "  deleteProperty(target, property) {"
        //             "    mbConsoleLog(`The property ${property} of window is being deleted.`);"
        //             "    return delete target[property];"
        //             "  }"
        //             "});";
        //         mbRunJs(webView, frame, testjs, false, nullptr, nullptr, (void*)(WorldIDs::MAIN_WORLD_ID));
        // mbRunJs(webView, frame, "mbConsoleLog('window.clientAPI~~~' + window.clientAPI)", false, nullptr, nullptr, (void*)(WorldIDs::MAIN_WORLD_ID));
    }
}

void WebContents::staticOnWillReleaseScriptContextCallback(mbWebView webView, void* param, mbWebFrameHandle frame, void* context, int worldId)
{
    WebContents* self = (WebContents*)param;
    self->onWillReleaseScriptContextCallback(webView, frame, (v8::Local<v8::Context>*)context, worldId);
}

void WebContents::onWillReleaseScriptContextCallback(mbWebView webView, mbWebFrameHandle frame, v8::Local<v8::Context>* context, int worldId)
{
    node::Environment* env = nodeEnvironmentGetByV8Context(*context);
    if (env /*&& node::IsLiveObj((intptr_t)env)*/ && m_environments.erase(env) != 0) {
        char* output = (char*)malloc(400);
        sprintf_s(output, 399, "WebContents::onWillReleaseScriptContextCallback: %p\n", env);
        OutputDebugStringA(output);
        free(output);

        mate::emitEvent((*context)->GetIsolate(), nodeGetEnvironmentProcessObject(env), "exit");

        // The main frame may be replaced.
        if (env == m_nodeBindings->getUvEnv())
            m_nodeBindings->setUvEnv(nullptr);

        // Destroying the node environment will also run the uv loop,
        // Node.js expects `kExplicit` microtasks policy and will run microtasks
        // checkpoints after every call into JavaScript. Since we use a different
        // policy in the renderer - switch to `kExplicit` and then drop back to the
        // previous policy value.
        v8::Isolate* isolate = (*context)->GetIsolate();
        auto old_policy = isolate->GetMicrotasksPolicy();
        DCHECK_EQ(v8::MicrotasksScope::GetCurrentDepth(isolate), 0);
        isolate->SetMicrotasksPolicy(v8::MicrotasksPolicy::kExplicit);

        node::FreeEnvironment(env);
        //         if (m_nodeBindings->getUvEnv() == nullptr) {
        //             node::FreeIsolateData(m_nodeBindings->getIsolateData());
        //             m_nodeBindings->setIsolateData(nullptr);
        //         }
        isolate->SetMicrotasksPolicy(old_policy);

        // ElectronBindings is tracking node environments.
        //electron_bindings_->EnvironmentDestroyed(env);
    }
}

mbDownloadOpt WebContents::staticOnDownloadCallback(mbWebView webView, void* param, size_t expectedContentLength, const char* url, const char* mime,
    const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind)
{
    WebContents* self = (WebContents*)param;
    ApiSession* ses = SessionMgr::get()->findOrCreateSession(v8::Isolate::GetCurrent(), self->m_sessionName, false);
    return ses->onDownloadCallback(self, webView, expectedContentLength, url, mime, disposition, job, dataBind);
}

int testEventEmitter = 0;

// channel是"ipc-message"字符串，和用户发送的channel不是一回事
void WebContents::rendererPostMessageToMain(const std::string& channel, const base::Value::List& listParams)
{
    int id = m_id;
    WebContents* self = this;
    base::Value::List* listParamsCopy = new base::Value::List(listParams.Clone());
    std::string* channelCopy = new std::string(channel);
    if (channel != "ipc-message" && channel != "ipc-render-invoke")
        DebugBreak();

//     if (listParams.size() == 2) {
//         const base::Value& a0 = listParams[0];
//         const base::Value& a1 = listParams[1];
//         if (a0.type() == base::Value::Type::STRING && a1.type() == base::Value::Type::NONE) {
//             const std::string* str = a0.GetIfString();
//             if (*str == "vscode:message") {
//                 testEventEmitter = 1;
//                 content::printCallstack();
//             }
//         }
//     }

    content::ThreadCall::callUiThreadAsync(FROM_HERE, [self, id, channelCopy, listParamsCopy] {
        if (IdLiveDetect::get()->isLive(id)) {
            //self->mate::EventEmitter<WebContents>::emit(channelCopy->c_str(), *listParamsCopy);

            v8::Isolate* isolate = self->isolate();
            v8::HandleScope handleScope(isolate);
            v8::Local<v8::Object> event = mate::internal::createJSEvent(isolate, self->getWrapper());

            mbWebView webView = self->getMbView();
            intptr_t mainFrame = (intptr_t)mbWebFrameGetMainFrame(webView);

            ApiWebFrameMain* webframe = ApiWebFrameMain::createOrGet(mainFrame);
            v8::Local<v8::Object> webframeV8 = webframe->GetWrapper(isolate);
            v8::Local<v8::Context> context = webframeV8->GetCreationContextChecked();
            v8::Context::Scope contextScope(context);

            event->Set(context, gin_helper::StringToV8(isolate, "senderFrame"), webframeV8);

            v8::Local<v8::Object> webContentsV8 = self->GetWrapper(isolate);
            event->Set(context, gin_helper::StringToV8(isolate, "sender"), webContentsV8);

            self->mate::EventEmitter<WebContents>::emitCustomEvent(channelCopy->c_str(), event, *listParamsCopy);

//             if (testEventEmitter) {
//                 base::Value::List::const_iterator it = listParamsCopy->begin();
//                 for (; it != listParamsCopy->end(); ++it) {
//                     const base::Value& item = *it;
//                     base::Value::Type type = item.type();
//                     if (type == base::Value::Type::STRING) {
//                         const std::string* str = item.GetIfString();
//                         OutputDebugStringA("");
//                     }
//                     OutputDebugStringA("");
//                 }
//             }
        }
        delete listParamsCopy;
        delete channelCopy;
    });
}

void WebContents::rendererSendMessageToMain(const std::string& channel, const base::Value::List& listParams, std::string* jsonRet)
{
    WebContents* self = this;
    const base::Value::List* listParamsPtr = &listParams;

    if (channel != "ipc-message-sync")
        DebugBreak();

    content::ThreadCall::callUiThreadSync(FROM_HERE, [self, listParamsPtr, jsonRet] {
        self->mate::EventEmitter<WebContents>::emitWithSender(
            "ipc-message-sync", [jsonRet](const std::string& json) { jsonRet->assign(json.c_str(), json.size()); }, *listParamsPtr);
    });
}

static bool getIPCObject(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object>* ipc)
{
    v8::Local<v8::String> key = gin_helper::StringToV8(isolate, "ipc");
    v8::Local<v8::Private> privateKey = v8::Private::ForApi(isolate, key);
    v8::Local<v8::Object> globalObject = context->Global();
    v8::Local<v8::Value> value;
    if (!globalObject->GetPrivate(context, privateKey).ToLocal(&value))
        return false;
    if (value.IsEmpty() || !value->IsObject())
        return false;
    *ipc = value->ToObject(context).ToLocalChecked();
    return true;
}

static std::vector<v8::Local<v8::Value>> listValueToVector(v8::Isolate* isolate, const base::Value::List& list)
{
    v8::Local<v8::Value> array = gin_helper::ConvertToV8(isolate, list);
    std::vector<v8::Local<v8::Value>> result;
    gin_helper::ConvertFromV8(isolate, array, &result);
    return result;
}

static void emitIPCEventToRendererImpl(
    WebContents* webContents, mbWebView view, mbWebFrameHandle frame, int worldID, const std::string& channel, const base::Value::List& args)
{
    CHECK(WTF::IsMainThread());
    if (!frame /*|| wkeIsWebRemoteFrame(view, frame)*/)
        return;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope handleScope(isolate);
    v8::TryCatch tryCatch(isolate);
    v8::Local<v8::Context> context;
    mbGetWorldScriptContextByWebFrame(view, frame, worldID, &context);
    if (context.IsEmpty())
        return;
    v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::kRunMicrotasks);
    v8::Context::Scope contextScope(context);

    tryCatch.SetVerbose(true);
    tryCatch.Reset();

    // Only emit IPC event for context with node integration.
    node::Environment* env = nodeEnvironmentGetByV8Context(context);
    if (!env)
        return;

    v8::Local<v8::Object> ipc;
    if (getIPCObject(isolate, context, &ipc)) {
        std::vector<v8::Local<v8::Value>> argsVector = listValueToVector(isolate, args);
        gin_helper::Dictionary evt = gin_helper::Dictionary::CreateEmpty(isolate);
#if 1 // 2.x版本electron的sender改成webContents(此处存疑，应该不是的)
        evt.Set("sender", ipc); // Insert the Event object, event.sender is ipc.
#else
        evt.Set("sender", webContents->GetWrapper(isolate));
#endif
        argsVector.insert(argsVector.begin(), evt.GetHandle());
        mate::emitEvent(isolate, ipc, channel, argsVector);
    }
}

static void emitIPCEventToRenderer(WebContents* webContents, mbWebView view, mbWebFrameHandle frame, const std::string& channel, const base::Value::List& args)
{
    emitIPCEventToRendererImpl(webContents, view, frame, WorldIDs::MAIN_WORLD_ID, channel, args);
    emitIPCEventToRendererImpl(webContents, view, frame, WorldIDs::ISOLATED_WORLD_ID, channel, args);
}

void WebContents::rendererSendMessageToRenderer(mbWebView view, mbWebFrameHandle frame, const std::string& channel, const base::Value::List& args)
{
    emitIPCEventToRenderer(nullptr, view, frame, channel, args);
}

void WebContents::anyPostMessageToRenderer(const std::string& channel, const base::Value::List& listParams)
{
    int id = m_id;
    WebContents* self = this;
    std::string* channelWrap = new std::string(channel);
    base::Value::List* listParamsWrap = new base::Value::List(listParams.Clone());

    content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [self, id, channelWrap, listParamsWrap] {
        if (IdLiveDetect::get()->isLive(id)) {
            emitIPCEventToRenderer(self, self->m_view, mbWebFrameGetMainFrame(self->m_view), *channelWrap, *listParamsWrap);
        }

//         if (listParamsWrap->size() == 1) {
//             const base::Value& a0 = (*listParamsWrap)[0];
//             base::Value::Type xx = a0.type();
//             if (a0.type() == base::Value::Type::STRING) {
//                 const std::string* str = a0.GetIfString();
//                 if (*str == "vscode:message") {
//                     testEventEmitter = 1;
//                     content::printCallstack();
//                 }
//             }
//         }

        delete channelWrap;
        delete listParamsWrap;
    });
}

void WebContents::getFocusedWebContentsApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::Value> result = WindowInterface::getFocusedContents(info.GetIsolate());
    info.GetReturnValue().Set(result);
}

void WebContents::getAllWebContentsApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
    WindowList* lists = WindowList::getInstance();

    v8::Local<v8::Array> results = v8::Array::New(info.GetIsolate(), lists->size());
    int count = 0;
    for (WindowList::iterator it = lists->begin(); it != lists->end(); ++it, ++count) {
        WebContents* content = (*it)->getWebContents();

        v8::Local<v8::Value> result = content->GetWrapper(info.GetIsolate());
        results->Set(context, count, result);
    }
    info.GetReturnValue().Set(results);
}

WebContents* WebContents::fromId(int id)
{
    WindowList* lists = WindowList::getInstance();

    WebContents* findedContent = nullptr;
    for (WindowList::iterator it = lists->begin(); it != lists->end(); ++it) {
        WebContents* content = (*it)->getWebContents();
        if ((int32_t)content->m_id != id)
            continue;
        findedContent = content;
        break;
    }
    return findedContent;
}

void WebContents::fromIdApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (1 != info.Length())
        return;
    v8::Local<v8::Value> arg0 = info[0];
    if (!arg0->IsInt32())
        return;

    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
    int32_t id = arg0->Int32Value(context).ToChecked();
    WebContents* self = WebContents::fromId(id);
    v8::Isolate* isolate = info.GetIsolate();
    if (!self) {
        info.GetReturnValue().Set(v8::Null(isolate));
        return;
    }
    v8::Local<v8::Value> result = v8::Local<v8::Value>::New(isolate, self->GetWrapper(isolate));
    info.GetReturnValue().Set(result);
}

int WebContents::getIdApi() const
{
    return (int)m_id;
}

void WebContents::getSessionApi(const v8::FunctionCallbackInfo<v8::Value>& info) const
{
    v8::Isolate* isolate = info.GetIsolate();
    ApiSession* ses = SessionMgr::get()->findOrCreateSession(isolate, m_sessionName, false);
    info.GetReturnValue().Set(ses->GetWrapper(isolate));
}

void WebContents::zoomFactorApi(const v8::FunctionCallbackInfo<v8::Value>& info) const
{
    mbWebView webView = getMbView();
    float ret = mbGetZoomFactor(webView);
    info.GetReturnValue().Set(ret);
}

void WebContents::getMainFrameApi(const v8::FunctionCallbackInfo<v8::Value>& info) const
{
    mbWebView webView = getMbView();
    intptr_t mainFrame = (intptr_t)mbWebFrameGetMainFrame(webView);

    ApiWebFrameMain* webframe = ApiWebFrameMain::createOrGet(mainFrame);
    v8::Local<v8::Object> wrapper = webframe->GetWrapper(isolate());
    if (wrapper.IsEmpty())
        return;
    info.GetReturnValue().Set(wrapper);
}

bool WebContents::canGoBackApi() const
{
    return m_canGoBack;
}

bool WebContents::canGoForwardApi() const
{
    return m_canGoForward;
}

void WebContents::printToPDFApi()
{
    OutputDebugStringA("WebContents::printToPDFApi not impl\n");
}

void WebContents::setWindowOpenHandlerApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    OutputDebugStringA("WebContents::setWindowOpenHandlerApi not impl\n");

    if (1 != info.Length())
        return;
    v8::Local<v8::Value> arg0 = info[0];
    if (!arg0->IsFunction())
        return;
    v8::Local<v8::Function> fn = arg0.As<v8::Function>();
    m_windowOpenHandlerCb.Reset(info.GetIsolate(), fn);
}

void WebContents::downloadURLApi(const std::string& url)
{
    mbWebView webView = getMbView();
    intptr_t mainFrame = (intptr_t)mbWebFrameGetMainFrame(webView);
    mbDownloadUrl(webView, (mbWebFrameHandle) mainFrame, url);
}

void WebContents::setZoomLevelApi(float level)
{
    mbWebView webView = getMbView();
    mbSetZoomFactor(webView, level);
}

float WebContents::getZoomLevelApi() const
{
    mbWebView webView = getMbView();
    float ret = mbGetZoomFactor(webView);
    return ret;
}

int WebContents::getProcessIdApi() const
{
    return (int)::GetCurrentProcessId();
}

bool WebContents::equalApi() const
{
    return false;
}

static std::string* trimUrl(const std::string& url)
{
    std::string* str = new std::string(url);

    // file:\c:\ 处理这种字符串
    if (str->size() > 9 && str->substr(0, 6) == "file:\\" && str->at(7) == ':') {
        std::string* strTemp = new std::string(str->substr(6));
        strTemp->insert(0, "file:///");
        delete str;
        str = strTemp;
    }

    if (str->size() > 9 && str->substr(0, 7) == "file://") {
        if (str->at(7) != '/')
            str->insert(7, 1, '/');

        for (size_t i = 0; i < str->size(); ++i) { // 如果是中文路径，则把问号前面的内容解码
            char c = str->at(i);
            if ('?' != c)
                continue;

            std::string urldecodeHead = StringUtil::urlDecode(str->c_str(), i + 1);
            urldecodeHead += str->substr(i, str->size() - i);
            *str = urldecodeHead;
            break;
        }
    }

    char invalideHead[] = "http:\\";
    int invalideHeadLength = sizeof(invalideHead) - 1;
    if (((int)str->size() > invalideHeadLength) && str->substr(0, invalideHeadLength) == invalideHead) {
        for (size_t i = 0; i < str->size(); ++i) { // 反斜杠替换成斜杠
            char c = str->at(i);
            if ('\\' != c)
                continue;
            str->at(i) = '/';
        }
        char c = str->at(invalideHeadLength);
        if (c != '/')
            str->insert(str->begin() + invalideHeadLength, 1, '/');
    }

    return str;
}

void WebContents::_loadURLApi(const std::string& url)
{
    std::string* str = trimUrl(url);
    m_isLoading = true;

    mbLoadURL(m_view, str->c_str());

    delete str;
    m_isLoading = false;
}

std::string WebContents::_getURLApi()
{
    return m_url;
}

std::string WebContents::getTitleApi()
{
    return m_title;
}

void WebContents::onTitleChanged(mbWebView webView, void* param, const utf8* title)
{
    WebContents* self = (WebContents*)param;
    if (self->mate::EventEmitter<WebContents>::emit("page-title-updated"))
        return;

    self->m_title = title;
    std::wstring titleW = StringUtil::UTF8ToUTF16(title);
    HWND hwnd = mbGetHostHWND(self->m_view);
    ::SetWindowText(hwnd, titleW.c_str());
}

void WebContents::onURLChanged(mbWebView webView, void* param, const utf8* url, BOOL canGoBack, BOOL canGoForward)
{
    WebContents* self = (WebContents*)param;
    self->m_url = url;
    self->m_canGoBack = canGoBack;
    self->m_canGoForward = canGoForward;
}

static void MB_CALL_TYPE onNetGetFaviconCallback(mbWebView webView, void* param, const utf8* url, mbMemBuf* buf)
{
    if (!url)
        return;
    WebContents* self = (WebContents*)param;

    base::Value::List params;
    base::Value::List urls;
    urls.Append(std::string(url));
    params.Append(std::move(urls));

    self->mate::EventEmitter<WebContents>::emit("page-favicon-updated", params);
}

void WebContents::onLoadingFinishCallback(
    mbWebView webView, void* param, mbWebFrameHandle frameId, const utf8* url, mbLoadingResult result, const utf8* failedReason)
{
    WebContents* self = (WebContents*)param;
    int id = self->m_id;
    //     WindowState state = self->m_state;
    //     bool isDestroyApiBeCalled = self->m_isDestroyApiBeCalled;
    BOOL isMainFrame = mbIsMainFrame(webView, frameId);
    std::string* failedReasonString = new std::string((failedReason));
    std::string* urlString = new std::string((url));

    //mbOnNetGetFavicon(webView, onNetGetFaviconCallback, self);

    content::ThreadCall::callUiThreadAsync(FROM_HERE, [id, self, result, /*state, isDestroyApiBeCalled,*/ failedReasonString, urlString, isMainFrame] {
        if (!IdLiveDetect::get()->isLive(id) /*|| WindowDestroying == state || WindowDestroyed == state || isDestroyApiBeCalled*/) {
            delete failedReasonString;
            delete urlString;
            return;
        }

        if (result == MB_LOADING_SUCCEEDED) {
            self->mate::EventEmitter<WebContents>::emit("did-frame-finish-load", isMainFrame);
            if (isMainFrame)
                self->mate::EventEmitter<WebContents>::emit("did-finish-load");
        } else {
            self->mate::EventEmitter<WebContents>::emit("did-fail-provisional-load", 0, *failedReasonString, *urlString, isMainFrame);

            if (result == MB_LOADING_FAILED)
                self->mate::EventEmitter<WebContents>::emit("did-fail-load", 0, *failedReasonString, *urlString, isMainFrame);
        }
        delete failedReasonString;
        delete urlString;
    });
}

struct WindowOpenHandlerResult {
    bool isDeny = false;
    v8::Local<v8::Object> overrideBrowserWindowOptions;

    //     bool hasFrame = true;
    //     bool isFullscreenable = false;
    //     std::string preload;
    //     std::string backgroundColor;
};

std::unique_ptr<WindowOpenHandlerResult> WebContents::onWindowOpenHandler(v8::Local<v8::Context> context, const std::string& url)
{
    if (m_windowOpenHandlerCb.IsEmpty())
        return nullptr;

    v8::Local<v8::Function> cb = m_windowOpenHandlerCb.Get(isolate());
    v8::Local<v8::Value> undefined = v8::Undefined(isolate());

    v8::Local<v8::Object> object = v8::Object::New(isolate());
    gin_helper::Dictionary objDict(isolate(), object);
    objDict.Set("url", url);
    v8::Local<v8::Value> argv[1] = { object.As<v8::Value>() };

    v8::MaybeLocal<v8::Value> ret = cb->Call(context, undefined, 1, argv);
    if (ret.IsEmpty())
        return nullptr;

    v8::Local<v8::Value> result = ret.ToLocalChecked();
    if (!result->IsObject())
        return nullptr;
    gin_helper::Dictionary resultDict(isolate(), result.As<v8::Object>());
    std::string action;

    std::unique_ptr<WindowOpenHandlerResult> handlerResult = std::make_unique<WindowOpenHandlerResult>();
    if (resultDict.Get("action", &action)) {
        if ("deny" == action)
            handlerResult->isDeny = true;
    }

    v8::Local<v8::Object> overrideBrowserWindowOptions;
    if (resultDict.Get("overrideBrowserWindowOptions", &overrideBrowserWindowOptions)) {
        handlerResult->overrideBrowserWindowOptions = overrideBrowserWindowOptions;
    }

    return std::move(handlerResult);
}

mbWebView WebContents::onCreateViewCallback(
    mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures)
{
    WebContents* self = (WebContents*)param;
    std::string* urlString = new std::string((url));
    v8::Isolate* isolate = self->isolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    bool allow = true;
    WebContents* newWebcontents = nullptr;
    v8::HandleScope handleScope(isolate);
    v8::TryCatch block(isolate);

    std::unique_ptr<WindowOpenHandlerResult> handlerResult = self->onWindowOpenHandler(context, std::string(url));
    if (handlerResult && handlerResult->isDeny)
        return NULL_WEBVIEW;

    v8::Local<v8::Object> newGuestWindow;

    v8::Local<v8::Object> event = mate::internal::createJSEvent(isolate, self->getWrapper());
    mate::emitEvent(isolate, self->getWrapper(), "new-window", event, *urlString, "", "new-window");
    allow = !event->Get(context, gin_helper::StringToV8(isolate, "defaultPrevented")).ToLocalChecked()->BooleanValue(isolate);

    if (!allow) { // 如果调用了preventDefault，则从newGuest字段找到newGuestWindow
        newGuestWindow = event->Get(context, gin_helper::StringToV8(isolate, "newGuest")).ToLocalChecked().As<v8::Object>();
    } else { // 如果使用默认创建的BrowserWindow
        v8::Local<v8::Object> evt = mate::internal::createJSEvent(isolate, self->getWrapper());
        if (handlerResult && !handlerResult->overrideBrowserWindowOptions.IsEmpty()) {
            std::vector<v8::Local<v8::Value>> args;
            args.push_back(evt);
            args.push_back(handlerResult->overrideBrowserWindowOptions);
            mate::emitEvent(isolate, self->getWrapper(), "-new-window", args);
        } else {
            mate::emitEvent(isolate, self->getWrapper(), "-new-window", evt, *urlString, "", "new-window");
        }
        newGuestWindow = evt->Get(context, gin_helper::StringToV8(isolate, "newGuest")).ToLocalChecked().As<v8::Object>();
    }

    newWebcontents = WindowInterface::onCreateNewWebview(newGuestWindow);
    // 如果拿不到newWebcontents，说明可能调用了defaultPrevented，并且没走electron.webContents.prototype.onCreateNewWebview
    return newWebcontents ? newWebcontents->getMbView() : NULL_WEBVIEW;
}

bool WebContents::isLoadingApi()
{
    bool isLoading = false;
    return isLoading;
}

bool WebContents::isLoadingMainFrameApi()
{
    //todo
    return false;
}

bool WebContents::isWaitingForResponseApi()
{
    //todo
    return false;
}

void WebContents::stopApi()
{
    mbStopLoading(m_view);
}

void WebContents::goBackApi()
{
    mbGoBack(m_view);
}

void WebContents::goForwardApi()
{
    mbGoForward(m_view);
}

void WebContents::goToOffsetApi(int offset)
{
    mbGoToOffset(m_view, offset);
}

void WebContents::goToIndexApi(int index)
{
    mbGoToIndex(m_view, index);
}

bool WebContents::isCrashedApi()
{
    return false;
}

void WebContents::setUserAgentApi(const std::string userAgent)
{
    m_ua = userAgent;
    mbSetUserAgent(m_view, userAgent.c_str());
}

std::string WebContents::getUserAgentApi()
{
    return m_ua;
}

void WebContents::savePageApi()
{
    //todo
}

void WebContents::openDevToolsApi()
{
    std::vector<WCHAR> fullpath;
    fullpath.resize(MAX_PATH + 1);
    memset(fullpath.data(), 0, sizeof(wchar_t) * (MAX_PATH + 1));
    ::GetModuleFileNameW(NULL, fullpath.data(), MAX_PATH);
    ::PathRemoveFileSpecW(fullpath.data());

    std::vector<WCHAR> name = fullpath;
    ::PathAppendW(name.data(), L"\\front_end\\inspector.html");

    std::string nameA;
    if (::PathFileExistsW(name.data())) {
        nameA = StringUtil::UTF16ToUTF8(name.data());
        mbSetDebugConfig(m_view, "showDevTools", nameA.c_str());
        return;
    }

    name = fullpath;
    ::PathAppendW(name.data(), L"\\resources\\devtools\\inspector.html");
    nameA = StringUtil::UTF16ToUTF8(name.data());
    mbSetDebugConfig(m_view, "showDevTools", nameA.c_str());

    //mbSetDebugConfig(m_view, "showDevTools", "G:/mycode/mb/third_party/WebKit/Source/devtools/front_end/inspector.html");
}

void WebContents::closeDevToolsApi()
{
    //todo
}

bool WebContents::isDevToolsOpenedApi()
{
    return false;
}

bool WebContents::isDevToolsFocusedApi()
{
    //todo
    return true;
}

void WebContents::insertCSSApi(const std::string& cssText)
{
    mbInsertCSSByFrame(m_view, mbWebFrameGetMainFrame(m_view), cssText.c_str());
}

void WebContents::enableDeviceEmulationApi()
{
    //todo
}

void WebContents::disableDeviceEmulationApi()
{
    //todo
}

void WebContents::toggleDevToolsApi()
{
    //todo
}

void WebContents::inspectElementApi()
{
    //todo
}

void WebContents::setAudioMutedApi()
{
    /*Isolate* isolate = args.GetIsolate();

    WebContents* webContents = ObjectWrap::Unwrap<WebContents>(args.Holder());

    ThreadCall::callBlinkThreadSync([webContents] {
        mbSetMediaVolume(webContents->m_view, 0.0);
    });*/
}

void WebContents::isAudioMutedApi()
{
}

void WebContents::undoApi()
{
    mbEditorUndo(m_view);
}

void WebContents::redoApi()
{
    mbEditorRedo(m_view);
}

void WebContents::cutApi()
{
    mbEditorCut(m_view);
}

void WebContents::copyApi()
{
    mbEditorCopy(m_view);
}

void WebContents::pasteApi()
{
    mbEditorPaste(m_view);
}

void WebContents::pasteAndMatchStyleApi()
{
    //todo
}

void WebContents::_deleteApi()
{
    mbEditorDelete(m_view);
}

void WebContents::selectAllApi()
{
    mbEditorSelectAll(m_view);
}

void WebContents::unselectApi()
{
    mbEditorUnSelect(m_view);
}

void WebContents::replaceApi()
{
    //todo
}

void WebContents::replaceMisspellingApi()
{
    //todo
}

void WebContents::findInPageApi()
{
    //todo
}

void WebContents::stopFindInPageApi()
{
    //todo
}

void WebContents::focusApi()
{
    mbSetFocus(m_view);
}

bool WebContents::isFocusedApi()
{
    return mbGetHostHWND(m_view) == GetFocus();
}

void WebContents::tabTraverseApi()
{
    //todo
}

bool WebContents::_sendApi(bool isAllFrames, const std::string& channel, const base::Value::List& args)
{
    if (!isAllFrames) {
        anyPostMessageToRenderer(channel, args);
        return true;
    }
    WindowList::iterator winIt = WindowList::getInstance()->begin();
    for (; winIt != WindowList::getInstance()->end(); ++winIt) {
        WindowInterface* windowInterface = *winIt;
        WebContents* webContents = windowInterface->getWebContents();
        webContents->anyPostMessageToRenderer(channel, args);
    }
    return true;
}

static void emitMojoMessageToRendererImpl(
    WebContents* webContents, mbWebView view, mbWebFrameHandle frame, int worldID, const std::string& channel, mojo::Message& mojoMessage)
{
    CHECK(WTF::IsMainThread());
    if (!frame)
        return;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope handleScope(isolate);
    v8::TryCatch tryCatch(isolate);
    v8::Local<v8::Context> context;
    mbGetWorldScriptContextByWebFrame(view, frame, worldID, &context);
    if (context.IsEmpty())
        return;
    v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::kRunMicrotasks);
    v8::Context::Scope contextScope(context);

    tryCatch.SetVerbose(true);
    tryCatch.Reset();

    // Only emit IPC event for context with node integration.
    node::Environment* env = nodeEnvironmentGetByV8Context(context);
    if (!env)
        return;

    v8::Local<v8::Object> ipc;
    if (getIPCObject(isolate, context, &ipc)) {
        onChannelMessagingApiAcceptHelper(true, channel, ipc, &mojoMessage);
    }
}

void mbTestMessageChannelMain(const v8::FunctionCallbackInfo<v8::Value>& info)
{

}

void WebContents::_testPostMessageApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{

}

bool WebContents::_postMessageApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    int id = m_id;
    WebContents* self = this;
    mojo::Message* mojoMessage = new mojo::Message();
    std::string* channel = new std::string();
    if (!v8FunInfoToMojoMessage(info, mojoMessage, channel))
        return false;

    content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [self, id, mojoMessage, channel] {
        if (IdLiveDetect::get()->isLive(id)) {
            emitMojoMessageToRendererImpl(self, self->m_view, mbWebFrameGetMainFrame(self->m_view), WorldIDs::ISOLATED_WORLD_ID, *channel, *mojoMessage);
        }
        delete mojoMessage;
        delete channel;
    });
    return true;
}

void WebContents::sendInputEventApi()
{
    //todo
}

void WebContents::beginFrameSubscriptionApi()
{
    //todo
}

void WebContents::endFrameSubscriptionApi()
{
    //todo
}

void WebContents::startDragApi()
{
    //todo
}

void WebContents::setSizeApi()
{
    //todo
}

bool WebContents::isGuestApi()
{
    //todo
    return false;
}

bool WebContents::isOffscreenApi()
{
    //todo
    return false;
}

void WebContents::startPaintingApi()
{
    //todo
}

void WebContents::stopPaintingApi()
{
    //todo
}

bool WebContents::isPaintingApi()
{
    //todo
    return false;
}

void WebContents::setFrameRateApi(int frameRate)
{
    m_frameRate = frameRate;
}

int WebContents::getFrameRateApi()
{
    return m_frameRate;
}

void WebContents::invalidateApi()
{
    //todo
}

void WebContents::getTypeApi()
{
    //todo
}

void WebContents::getWebPreferencesApi()
{
    //todo
}

v8::Local<v8::Value> WebContents::getOwnerBrowserWindowApi()
{
    if (m_owner)
        return m_owner->getWrapper();

    return v8::Null(isolate());
}

bool WebContents::hasServiceWorkerApi()
{
    return false;
}

void WebContents::unregisterServiceWorkerApi()
{
    //todo
}

void WebContents::inspectServiceWorkerApi()
{
    //todo
}

void WebContents::printApi()
{
    //todo
}

void WebContents::_printToPDFApi()
{
    //todo
}

void WebContents::addWorkSpaceApi()
{
    //todo
}

void WebContents::reNullWorkSpaceApi()
{
    //todo
}

void WebContents::showDefinitionForSelectionApi()
{
    //todo
}

void WebContents::copyImageAtApi()
{
    //todo
}

void WebContents::capturePageApi()
{
    //todo
}

void WebContents::setEmbedderApi()
{
    //todo
}

bool WebContents::isDestroyedApi() const
{
    return false;
}

void WebContents::reloadIgnoringCacheApi()
{
    mbReload(m_view);
}

BOOL WebContents::onNavigationCallback(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url)
{
    WebContents* self = (WebContents*)param;
    std::string* urlString = new std::string(url);
    int id = self->m_id;
    bool allow = true;
    content::ThreadCall::callUiThreadSync(FROM_HERE, [id, self, urlString, &allow] {
        if (!IdLiveDetect::get()->isLive(id))
            return;

        if (!self->m_isLoading) {
            self->mate::EventEmitter<WebContents>::emit("did-stop-loading");

            allow = !(self->mate::EventEmitter<WebContents>::emit("will-navigate", *urlString));
        }
        self->m_isLoading = false;
        delete urlString;
    });
    return allow;
}

void WebContents::onDocumentReadyInBlinkThread(mbWebView webView, void* param, mbWebFrameHandle frameId)
{
    int width = mbGetContentWidth(webView);
    int height = mbGetContentHeight(webView);
    WebContents* self = (WebContents*)param;
    int id = self->m_id;

    bool needSetPos = false;
    if (self->m_createWindowParam->isUseContentSize && 0 != width && 0 != height)
        needSetPos = true;

    content::ThreadCall::callUiThreadAsync(FROM_HERE, [webView, self, id, needSetPos, width, height] {
        if (!IdLiveDetect::get()->isLive(id))
            return;

        HWND hWnd = mbGetHostHWND(webView);
        RECT rect = { 0 };
        ::GetWindowRect(hWnd, &rect);
        //         if (rect.left == kNotSetXYFlag || rect.top == kNotSetXYFlag)
        //             platform_util::moveToCenter(hWnd);

        if (needSetPos)
            ::SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, width, height, SWP_NOMOVE | SWP_NOREPOSITION);

        self->mate::EventEmitter<WebContents>::emit("did-navigate");
        self->mate::EventEmitter<WebContents>::emit("ready-to-show"); // 暂时在这发消息。以后再想办法
        self->mate::EventEmitter<WebContents>::emit("dom-ready");
        self->mate::EventEmitter<WebContents>::emit("did-stop-loading");

        for (std::set<WebContentsObserver*>::iterator it = self->m_observers.begin(); it != self->m_observers.end(); ++it) {
            WebContentsObserver* obs = *it;
            obs->onWebContentsReadyToShow(self);
        }
    });
}

void WebContents::nullFunction()
{
}

gin_helper::WrapperInfo WebContents::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };
v8::Persistent<v8::Function> WebContents::s_constructor;

static void initializeWebContentApi(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    WebContents::init(context->GetIsolate(), target, nullptr);
}

static const char WebContentsSricpt[] = "exports = {};";

static NodeNative nativeBrowserWebContentsNative { "WebContents", WebContentsSricpt, sizeof(WebContentsSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_web_contents, initializeWebContentApi, &nativeBrowserWebContentsNative)

} // atom

namespace gin_helper {

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const atom::WebContents& content)
{
    atom::WebContents* ctx = (atom::WebContents*)&content;
    return ctx->GetWrapper(isolate);
}

}
