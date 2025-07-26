
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "mbvip/core/mb.h"

#include "mbvip/download/SimpleDownload.h"
#include "mbvip/core/MbJsValue.h"
#include "mbvip/core/MbInternalApi.h"
#include "content/browser/MbWebview.h"
#include "content/browser/SharedTimerWin.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/ThreadCall.h"
#include "content/common/mbchar.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/renderer/RendererBlinkPlatformImpl.h"
#include "mbnet/WebURLLoaderInternal.h"
#include "mbnet/cookies/WebCookieJarCurlImpl.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/public/web/web_view.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/renderer/platform/wtf/allocator/partitions.h"
#include "services/network/public/cpp/resource_request.h"
#include "base/command_line.h"
#include "base/run_loop.h"
#include "base/task/single_thread_task_executor.h"
#include "base/at_exit.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#if defined(OS_WIN)
#include "base/win/scoped_com_initializer.h"
#else
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <sys/types.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms-compat.h>
#endif // OS_WIN
#include "v8.h"
#include "third_party/skia/include/core/SkTraceMemoryDump.h"
#include "third_party/skia/include/core/SkGraphics.h"

#if OS_LINUX
extern base::RunLoop* g_mainThreadRunLoop;
#endif

namespace blink {
LocalFrame* FromFrameTokenHash(const size_t& frame_token_hash);
}

namespace content {
intptr_t getFrameIdByWebLocalFrame(blink::WebLocalFrame* frame);
}

DWORD g_uiThreadId = 0;

static bool checkThreadCallIsValidImpl(const char* funcName, bool isBlinkThread)
{
    return true;
    //     std::u16string textMsg;
    //     if (!g_mbIsInit) {
    //         textMsg = u16("禁止未初始化调用此接口：");
    //         textMsg += common::utf8ToUtf16(funcName);
    //         ::MessageBoxW(nullptr, textMsg.c_str(), u16("警告"), MB_OK);
    //         ::TerminateProcess((HANDLE)-1, 5);
    //         return false;
    //     }
    //
    //     if (isBlinkThread) {
    //         if (content::ThreadCall::isBlinkThread())
    //             return true;
    //     } else {
    //         if (content::ThreadCall::isUiThread())
    //             return true;
    //     }
    //
    // #if defined(OS_WIN)
    //     textMsg = u16("禁止跨线程调用此接口：");
    //     textMsg += common::utf8ToUtf16(funcName);
    //     textMsg += u16("，");
    //
    //     WCHAR* temp = (WCHAR*)malloc(0x200);
    //     wsprintf(temp, u16("当前线程:%d，主线程：%d"), ::GetCurrentThreadId(), common::ThreadCall::getUiThreadId());
    //     textMsg += temp;
    //     free(temp);
    //
    //     ::MessageBoxW(nullptr, textMsg.c_str(), u16("警告"), MB_OK);
    // #else
    //     printf("function: %s, current thread:%u, main thread:%u", funcName, ::GetCurrentThreadId(), common::ThreadCall::getUiThreadId());
    // #endif
    //     ::TerminateProcess((HANDLE)-1, 5);
    //     return false;
}

bool checkThreadCallIsValid(const char* funcName)
{
    return checkThreadCallIsValidImpl(funcName, false);
}

mbSettings* MB_CALL_TYPE mbCreateInitSettings()
{
    mbSettings* settings = new mbSettings();
    memset(settings, 0, sizeof(mbSettings));
    settings->version = kMbVersion;
    return settings;
}

void MB_CALL_TYPE mbSetInitSettings(mbSettings* settings, const char* name, const char* value)
{
    if (0 == strcmp(name, "DisableCC"))
        settings->mask = MB_ENABLE_DISABLE_CC;
}

mbWebView MB_CALL_TYPE mbCreateWebView()
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* result = new content::MbWebView(false);

    // 之所以要嵌套一层，是为了让isTransparent获取到外部接下来可能设置mbSetTransparent的值
    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [result] {
        content::ThreadCall::callBlinkThreadAsync(
            MB_FROM_HERE, [result] { result->createWebWindowOrViewInBlinkThread(nullptr, nullptr, false, result->isTransparent()); });
    });

    return (int)result->getId();
}

static bool s_gtkActivate = false;

static void createWebWindowInUiThread(mbWindowType type, HWND parent, int x, int y, int width, int height, content::MbWebView* newWebview)
{
    newWebview->createWebWindowInUiThread(type, parent, x, y, width, height);

    content::ThreadCall::callBlinkThreadAsync(
        MB_FROM_HERE, [newWebview, type] { newWebview->createWebWindowOrViewInBlinkThread(nullptr, nullptr, true, type == MB_WINDOW_TYPE_TRANSPARENT); });
}

static void createCustemWindowInUiThread(HWND parent, DWORD style, DWORD styleEx, int x, int y, int width, int height, content::MbWebView* newWebview)
{
    newWebview->createWebWindowImplInUiThread(parent, style, styleEx, x, y, width, height);

    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE,
        [newWebview, styleEx] { newWebview->createWebWindowOrViewInBlinkThread(nullptr, nullptr, true, WS_EX_LAYERED == (WS_EX_LAYERED & styleEx)); });
}

mbWebView MB_CALL_TYPE mbCreateWebWindow(mbWindowType type, HWND parent, int x, int y, int width, int height)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* result = new content::MbWebView(false);

#ifndef OS_WIN
    if (type == MB_WINDOW_TYPE_TRANSPARENT)
        type = MB_WINDOW_TYPE_POPUP; // linux下没有透明窗口
#endif // OS_WIN

    if (!s_gtkActivate) {
        content::ThreadCall::callUiThreadAsync(
            MB_FROM_HERE, [type, parent, x, y, width, height, result] { createWebWindowInUiThread(type, parent, x, y, width, height, result); });
    } else
        createWebWindowInUiThread(type, parent, x, y, width, height, result);

    return (int)result->getId();
}

// 兼容mbcef版本
mbWebView MB_CALL_TYPE mbCreateWebWindowEx(mbWindowType type, HWND parent, int x, int y, int width, int height, const mbViewSettings* settings)
{
    mbWebView webview = mbCreateWebWindow(type, parent, x, y, width, height);
    if (settings)
        mbSetViewSettings(webview, settings);
    return webview;
}

mbWebView MB_CALL_TYPE mbCreateWebCustomWindow(HWND parent, DWORD style, DWORD styleEx, int x, int y, int width, int height)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* result = new content::MbWebView(false);

    if (!s_gtkActivate) {
        content::ThreadCall::callUiThreadAsync(MB_FROM_HERE,
            [parent, style, styleEx, x, y, width, height, result] { createCustemWindowInUiThread(parent, style, styleEx, x, y, width, height, result); });
    } else
        createCustemWindowInUiThread(parent, style, styleEx, x, y, width, height, result);

    return (int)result->getId();
}

mbWebView MB_CALL_TYPE mbCreateWebViewBindGtkWindow(void* rootWindow, void* drawingArea, const char* type, DWORD style, DWORD styleEx, int width, int height)
{
#if !defined(WIN32)
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* result = new content::MbWebView(false);

    std::string typeStr(type);
    result->bindGtkWindow(rootWindow, drawingArea, typeStr == "glArea", style, styleEx, width, height);
    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [result] { result->createWebWindowOrViewInBlinkThread(nullptr, nullptr, true, false); });

    return (int)result->getId();
#else
    return NULL_WEBVIEW;
#endif
}

void MB_CALL_TYPE mbSetHandle(mbWebView webviewHandle, HWND wnd)
{
    checkThreadCallIsValid(__FUNCTION__);

    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [wnd](content::MbWebView* webview) {
        webview->setHostWnd(wnd); // 必须在这设置，不能放闭包外。那样会导致提前设置的mbSetDragDropEnable无效，从而导致RegisterDragDrop被设置
    });
}

void* MB_CALL_TYPE mbGetPlatformWindowHandle(mbWebView webviewHandle)
{
    void* handle = (void*)mbGetHostHWND(webviewHandle);
#ifdef OS_LINUX
    return HwndToGtkWindow(handle);
#else
    return handle;
#endif // OS_LINUX
}

HWND MB_CALL_TYPE mbGetHostHWND(mbWebView webviewHandle)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return NULL;
    return webview->getHostWnd();
}

void MB_CALL_TYPE mbSetCspCheckEnable(mbWebView webView, BOOL b)
{
}

void gtkMessageBox(const char* txt)
{
#if !defined(OS_WIN)
    GtkDialogFlags flags = (GtkDialogFlags)(GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT);
    GtkWidget* dialog = gtk_message_dialog_new(NULL, flags, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "txt");

    char output[100] = { 0 };
    sprintf(output, "gtkMessageBox: %p\n", dialog);
    OutputDebugStringA(output);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
#endif
}

#if !defined(OS_WIN)
static void onGtkActivate(GtkApplication* app, gpointer user_data)
{
    s_gtkActivate = true;
}
#endif

FN_OutputDebugString g_outputDebugString = nullptr;
void __cdecl defaultOutputDebugString(const char* str)
{
    OutputDebugStringA(str);
}

void MB_CALL_TYPE mbInit(const mbSettings* settings)
{
    if (content::ThreadCall::isInitUiThread())
        return;

    g_outputDebugString = defaultOutputDebugString;

    base::AtExitManager* atExitManager = new base::AtExitManager();
#if defined(OS_WIN)
    base::win::ScopedCOMInitializer* comInitializer = new base::win::ScopedCOMInitializer();
    s_gtkActivate = true;
#else
    gtk_init(nullptr, nullptr);

    GtkApplication* app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(onGtkActivate), NULL);

    printf("mbInit: %x\n", ::GetCurrentThreadId());
#endif
    base::CommandLine::Init(0, nullptr);
    content::RenderThreadImpl::get()->initializeWebKit();

#if defined(OS_WIN)
    content::setSharedTimerFireInterval(16);
#endif
}

void MB_CALL_TYPE mbUninit()
{
#if defined(OS_WIN)
    _CrtDumpMemoryLeaks();
#endif
}

void MB_CALL_TYPE mbOnDidCreateScriptContext(mbWebView webviewHandle, mbDidCreateScriptContextCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setDidCreateScriptContextCallback(callback, param);
}

void MB_CALL_TYPE mbOnWillReleaseScriptContext(mbWebView webviewHandle, mbWillReleaseScriptContextCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setWillReleaseScriptContextCallback(callback, param);
}

void MB_CALL_TYPE mbOnNavigation(mbWebView webviewHandle, mbNavigationCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setNavigationCallback(callback, param);
}

void MB_CALL_TYPE mbSetZoomFactor(mbWebView webviewHandle, float factor)
{
    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, factor] {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (webview)
            webview->setZoomFactor(factor);
    });
}

float MB_CALL_TYPE mbGetZoomFactor(mbWebView webviewHandle)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return 1.0f;
    return webview->getZoomFactor();
}

mbJsExecState MB_CALL_TYPE mbGetGlobalExecByFrame(mbWebView webviewHandle, mbWebFrameHandle frameId)
{
    //     content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    //     if (!webview)
    //         return nullptr;

    //     wkeWebView wkeWebview = webview->getWkeWebView();
    //     return wkeGetGlobalExecByFrame(wkeWebview, (wkeWebFrameHandle)frameId);
    //OutputDebugStringA("mbGetGlobalExecByFrame not impl\n");
    return nullptr;
}

int MB_CALL_TYPE mbGetCursorInfoType(mbWebView webviewHandle)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return 0;
    return webview->getCursorInfoType();
}

int MB_CALL_TYPE mbGetContentWidth(mbWebView webviewHandle)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return 1;
    //     return wkeGetContentWidth(webview->getWkeWebView());

    SIZE size = webview->getClientSizeLocked();
    return size.cx;
}

int MB_CALL_TYPE mbGetContentHeight(mbWebView webviewHandle)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return 1;
    // return wkeGetContentHeight(webview->getWkeWebView());

    SIZE size = webview->getClientSizeLocked();
    return size.cy;
}

void MB_CALL_TYPE mbGetCaretRect(mbWebView webviewHandle, mbRect* r)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;
    gfx::Point pt = webview->getCaretPos();
    r->x = pt.x();
    r->y = pt.y();
    r->w = 3;
    r->h = 10;
}

void MB_CALL_TYPE mbEditorUnSelect(mbWebView webviewHandle)
{
    //     checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](mb::MbWebView* webview) {
    //         wkeEditorUnSelect(webview->getWkeWebView());
    //         });
}

void MB_CALL_TYPE mbEditorCopy(mbWebView webviewHandle)
{
    //     checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](mb::MbWebView* webview) {
    //         wkeCopy(webview->getWkeWebView());
    //         });
}

void MB_CALL_TYPE mbEditorCut(mbWebView webviewHandle)
{
    //     checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](mb::MbWebView* webview) {
    //         wkeCut(webview->getWkeWebView());
    //         });
}

void MB_CALL_TYPE mbEditorPaste(mbWebView webviewHandle)
{
    //     checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](mb::MbWebView* webview) {
    //         wkePaste(webview->getWkeWebView());
    //         });
}

void MB_CALL_TYPE mbEditorDelete(mbWebView webviewHandle)
{
    //     checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](mb::MbWebView* webview) {
    //         wkeEditorDelete(webview->getWkeWebView());
    //         });
}

void MB_CALL_TYPE mbEditorRedo(mbWebView webviewHandle)
{
    //     checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](mb::MbWebView* webview) {
    //         wkeEditorRedo(webview->getWkeWebView());
    //         });
}

void MB_CALL_TYPE mbEditorUndo(mbWebView webviewHandle)
{
    //     checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](mb::MbWebView* webview) {
    //         wkeEditorUndo(webview->getWkeWebView());
    //         });
}

void MB_CALL_TYPE mbRunMessageLoop()
{
    content::ThreadCall::runUiThreadMessageLoop(nullptr, nullptr, nullptr);
}

void MB_CALL_TYPE mbExitMessageLoop()
{
    content::ThreadCall::exitUiThreadMessageLoop();
}

void MB_CALL_TYPE mbMoveToCenter(mbWebView webviewHandle)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;

    int width = 0;
    int height = 0;

    HWND hWnd = webview->getHostWnd();

    RECT rect = { 0 };
    ::GetWindowRect(hWnd, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;

    int parentWidth = 0;
    int parentHeight = 0;
    if (WS_CHILD == ::GetWindowLongW(hWnd, GWL_STYLE)) {
        HWND parent = ::GetParent(hWnd);
        RECT rect = { 0 };
        ::GetClientRect(parent, &rect);
        parentWidth = rect.right - rect.left;
        parentHeight = rect.bottom - rect.top;
    } else {
        parentWidth = ::GetSystemMetrics(SM_CXSCREEN);
        parentHeight = ::GetSystemMetrics(SM_CYSCREEN);
    }

    int x = (parentWidth - width) / 2;
    int y = (parentHeight - height) / 2;

    ::MoveWindow(hWnd, x, y, width, height, FALSE);
}

void mbShowWindowImpl(mbWebView webviewHandle, int nCmdShow)
{
    if (nCmdShow == -1)
        nCmdShow = SW_SHOW;
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;

    if (content::ThreadCall::isUiThread() && webview->getHostWnd()) {
        webview->setShow(nCmdShow /*, true*/);
        return;
    }

    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, nCmdShow]() {
        content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [webviewHandle, nCmdShow] {
            content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
            if (!webview)
                return;
            webview->setShow(nCmdShow /*, true*/);
        });
    });
}

void MB_CALL_TYPE mbShowWindow(mbWebView webviewHandle, int nCmdShow)
{
    mbShowWindowImpl(webviewHandle, nCmdShow);
}

BOOL mbGetWindowRectImpl(mbWebView webviewHandle, mbRect* rc)
{
    HWND hwnd = mbGetHostHWND(webviewHandle);
    if (!hwnd)
        return FALSE;
    RECT windowRect;
    if (!::GetWindowRect(hwnd, &windowRect))
        return FALSE;

    rc->x = windowRect.top;
    rc->y = windowRect.left;
    rc->w = windowRect.bottom - windowRect.top;
    rc->h = windowRect.right - windowRect.left;
    return TRUE;
}

BOOL MB_CALL_TYPE mbGetWindowRect(mbWebView webviewHandle, mbRect* rc)
{
    if (content::ThreadCall::isUiThread())
        return mbGetWindowRectImpl(webviewHandle, rc);

    BOOL ret = FALSE;
    content::ThreadCall::callUiThreadSync(MB_FROM_HERE, [webviewHandle, rc, &ret] { ret = mbGetWindowRectImpl(webviewHandle, rc); });
    return ret;
}

void MB_CALL_TYPE mbLoadURL(mbWebView webviewHandle, const utf8* url)
{
    std::string* urlString = new std::string(url);

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;
    webview->resetState();

    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, urlString] {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (webview)
            webview->loadUrl(urlString->c_str());
        delete urlString;
    });

    //////////////////////////////////////////////////////////////////////////
    //mbOnLoadUrlBegin(webview, handleLoadUrlBegin, nullptr);
    //////////////////////////////////////////////////////////////////////////
}

void mbLoadHtmlWithBaseUrlImpl(mbWebView webviewHandle, const std::string* htmlString, const std::string* baseUrlString, int count)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview) {
        delete htmlString;
        delete baseUrlString;
        return;
    }
    webview->resetState();

    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, htmlString, baseUrlString, count] {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        bool needFree = true;

        if (count > 50)
            Sleep(100);

        if (webview && !webview->loadHTMLString(*htmlString, *baseUrlString) && count < 500) {
            mbLoadHtmlWithBaseUrlImpl(webviewHandle, htmlString, baseUrlString, count + 1);
            needFree = false;
        }
        if (needFree) {
            delete htmlString;
            delete baseUrlString;
        }
    });
}

void MB_CALL_TYPE mbLoadHtmlWithBaseUrl(mbWebView webviewHandle, const utf8* html, const utf8* baseUrl)
{
    std::string* htmlString = new std::string(html);
    std::string* baseUrlString = new std::string(baseUrl);
    mbLoadHtmlWithBaseUrlImpl(webviewHandle, htmlString, baseUrlString, 0);
}

void MB_CALL_TYPE mbSetAutoDrawToHwnd(mbWebView webviewHandle, BOOL b)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->setAutoDrawToHwnd(!!b);
}

void MB_CALL_TYPE mbOnPaintUpdated(mbWebView webviewHandle, mbPaintUpdatedCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;
    webview->setPaintUpdatedCallback(callback, param);
}

BOOL mbFireKeyUpEventImpl(mbWebView webviewHandle, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle,
        [virtualKeyCode, flags, isSystemKey](content::MbWebView* webview) { webview->onKeyUp(virtualKeyCode, flags, isSystemKey); });

    return true;
}

BOOL MB_CALL_TYPE mbFireKeyUpEvent(mbWebView webviewHandle, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey)
{
    return mbFireKeyUpEventImpl(webviewHandle, virtualKeyCode, flags, isSystemKey);
}

BOOL mbFireKeyDownEventImpl(mbWebView webviewHandle, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [virtualKeyCode, flags, isSystemKey](content::MbWebView* webview) {
        webview->onKeyDown(virtualKeyCode, flags, isSystemKey);
        //         if (113 == virtualKeyCode) {
        //             wkeSetDebugConfig(webview->getWkeWebView(), "showDevTools", "E:/mycode/miniblink49/trunk/third_party/WebKit/Source/devtools/front_end/inspector.html");
        //         }

        //         char* output = (char*)malloc(0x100);
        //         sprintf(output, "mbFireKeyDownEvent: %d\n", virtualKeyCode);
        //         OutputDebugStringA(output);
        //         free(output);
    });

    return true;
}

BOOL MB_CALL_TYPE mbFireKeyDownEvent(mbWebView webviewHandle, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey)
{
    return mbFireKeyDownEventImpl(webviewHandle, virtualKeyCode, flags, isSystemKey);
}

BOOL mbFireKeyPressEventImpl(mbWebView webviewHandle, unsigned int charCode, unsigned int flags, BOOL isSystemKey)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::ThreadCall::callBlinkThreadAsyncWithValid(
        MB_FROM_HERE, webviewHandle, [charCode, flags, isSystemKey](content::MbWebView* webview) { webview->onKeyPress(charCode, flags, isSystemKey); });

    return true;
}

BOOL MB_CALL_TYPE mbFireKeyPressEvent(mbWebView webviewHandle, unsigned int charCode, unsigned int flags, BOOL isSystemKey)
{
    return mbFireKeyPressEventImpl(webviewHandle, charCode, flags, isSystemKey);
}

BOOL mbFireWindowsMessageImpl(mbWebView webviewHandle, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result)
{
    checkThreadCallIsValid(__FUNCTION__);

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return TRUE;

    if (WM_SETCURSOR == message) {
        if (webview->setCursorInfoTypeByCache()) {
            if (result)
                *result = 1;
            return TRUE;
        }
    } else if (WM_IME_STARTCOMPOSITION == message) {
        webview->onImeComposition(content::MbWebView::kImeCompositioTypeStart, (WCHAR)(0));

        content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [webviewHandle, hWnd](content::MbWebView* webview) {
            gfx::Point caret = webview->getCaretPos();

            POINT offset = webview->getOffset();
            int x = caret.x() + offset.x;
            int y = caret.y() + offset.y;

            content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [hWnd, webviewHandle, x, y] {
                content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
                if (!webview)
                    return;

                COMPOSITIONFORM compositionForm;
                compositionForm.dwStyle = CFS_POINT | CFS_FORCE_POSITION;
                compositionForm.ptCurrentPos.x = x;
                compositionForm.ptCurrentPos.y = y;

                HIMC hIMC = ::ImmGetContext(hWnd);
                ::ImmSetCompositionWindow(hIMC, &compositionForm);
                ::ImmReleaseContext(hWnd, hIMC);
            });
        });
        return false;
    } else if (WM_IME_COMPOSITION == message) {
        WCHAR c = (WCHAR)wParam;
        webview->onImeComposition(content::MbWebView::kImeCompositioTypeCom, c);

        if (lParam & GCS_RESULTSTR) {
            std::vector<WCHAR> buffer;
            HIMC hIMC = ::ImmGetContext(hWnd);
            int stringSize = ImmGetCompositionStringW(hIMC, GCS_COMPSTR, NULL, 0);
            buffer.resize(stringSize + 2);
            memset(&buffer[0], 0, buffer.size());
            ImmGetCompositionStringW(hIMC, GCS_COMPSTR, &buffer[0], buffer.size() - 2);
            ImmReleaseContext(hWnd, hIMC);
        }
    } else if (WM_IME_ENDCOMPOSITION == message) {
        webview->onImeComposition(content::MbWebView::kImeCompositioTypeEnd, (WCHAR)(0));
    } else if (WM_IME_CHAR == message) {
        WCHAR c = (WCHAR)wParam;
        webview->onImeComposition(content::MbWebView::kImeCompositioTypeChar, c);
    } else {
        //         content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [hWnd, message, wParam, lParam](content::MbWebView* webview) {
        //             LRESULT result = 0;
        //             mbFireWindowsMessage(webview->getId(), hWnd, message, wParam, lParam, &result);
        //         });
    }
    return false;
}

BOOL MB_CALL_TYPE mbFireWindowsMessage(mbWebView webviewHandle, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result)
{
    return mbFireWindowsMessageImpl(webviewHandle, hWnd, message, wParam, lParam, result);
}

BOOL mbFireMouseEventImpl(mbWebView webviewHandle, unsigned int message, int x, int y, unsigned int flags)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (webview)
        webview->onMouseMessage(message, x, y, flags);

    return TRUE;
}

BOOL MB_CALL_TYPE mbFireContextMenuEvent(mbWebView webView, int x, int y, unsigned int flags)
{
    return false;
}

BOOL MB_CALL_TYPE mbFireMouseEvent(mbWebView webviewHandle, unsigned int message, int x, int y, unsigned int flags)
{
    return mbFireMouseEventImpl(webviewHandle, message, x, y, flags);
}

BOOL mbFireMouseWheelEventImpl(mbWebView webviewHandle, int x, int y, int wheelDelta, unsigned int flags)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return FALSE;
    //     if (!webview->getWkeWebView())
    //         return true;
    //     if (!wkeFireMouseWheelEventOnUiThread(webview->getWkeWebView(), x, y, delta, flags))
    //         return true;

    WPARAM wParam = 0;

    HWND hWnd = webview->getHostWnd();

    POINT screenPoint = { x, y };
    ::ClientToScreen(hWnd, &screenPoint);
    LPARAM lParam = MAKELPARAM(screenPoint.x, screenPoint.y);
    if (flags & MB_CONTROL)
        wParam |= MK_CONTROL;
    if (flags & MB_SHIFT)
        wParam |= MK_SHIFT;

    if (flags & MB_LBUTTON)
        wParam |= MK_LBUTTON;
    if (flags & MB_MBUTTON)
        wParam |= MK_MBUTTON;
    if (flags & MB_RBUTTON)
        wParam |= MK_RBUTTON;

    wParam = MAKEWPARAM(wParam, wheelDelta);

    webview->fireWheelEventOnUiThread(wParam, lParam);

    //     content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [lParam, wParam](content::MbWebView* webview) {
    //         //wkeFireMouseWheelEvent(webview->getWkeWebView(), x, y, delta, flags);
    //         webview->fireWheelEventOnUiThread(wParam, wParam);
    //     });

    return TRUE;
}

BOOL MB_CALL_TYPE mbFireMouseWheelEvent(mbWebView webviewHandle, int x, int y, int wheelDelta, unsigned int flags)
{
    return mbFireMouseWheelEventImpl(webviewHandle, x, y, wheelDelta, flags);
}

void MB_CALL_TYPE mbSetNavigationToNewWindowEnable(mbWebView webviewHandle, BOOL b)
{
    //checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [b](content::MbWebView* webview) {
    //         wkeSetNavigationToNewWindowEnable(webview->getWkeWebView(), !!b);
    //     });
}

namespace mbnet {
void onNetSetData(mbNetJob jobPtr, void* buf, int len);
void onNetSetMIMEType(mbNetJob jobPtr, const char* type);
void onNetSetHTTPHeaderFieldCommon(mbNetJob jobPtr, const utf8* key, const utf8* value, BOOL response);
void changeRequestUrl(mbNetJob jobPtr, const char* url);
}

void MB_CALL_TYPE mbNetSetHTTPHeaderFieldUtf8(mbNetJob jobPtr, const utf8* key, const utf8* value, BOOL response)
{
    mbnet::onNetSetHTTPHeaderFieldCommon(jobPtr, key, value, response);
//     if (content::ThreadCall::isBlinkThread()) {
//         mbnet::onNetSetHTTPHeaderField(jobPtr, key, value, response);
//     } else {
//         DebugBreak();
//         std::string* keyCopy = new std::string(key);
//         std::string* valueCopy = new std::string(value);
//         content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [jobPtr, keyCopy, valueCopy, response] {
//             mbnet::onNetSetHTTPHeaderField(jobPtr, keyCopy->c_str(), valueCopy->c_str(), response);
//             delete keyCopy;
//             delete valueCopy;
//         });
//     }
}

void MB_CALL_TYPE mbNetSetMIMEType(mbNetJob jobPtr, const char* type)
{
    if (content::ThreadCall::isBlinkThread()) {
        mbnet::onNetSetMIMEType(jobPtr, type);
    } else {
        std::string* typeCopy = new std::string(type);
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [jobPtr, typeCopy] {
            mbnet::onNetSetMIMEType(jobPtr, typeCopy->c_str());
            delete typeCopy;
        });
    }
}

void MB_CALL_TYPE mbNetSetData(mbNetJob jobPtr, void* buf, int len)
{
    //checkThreadCallIsValid(__FUNCTION__);
    if (content::ThreadCall::isBlinkThread()) {
        mbnet::onNetSetData(jobPtr, buf, len);
    } else {
        std::vector<char>* bufferCopy = new std::vector<char>();
        bufferCopy->resize(len);
        memcpy(&bufferCopy->at(0), buf, len);
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [jobPtr, bufferCopy] {
            mbnet::onNetSetData(jobPtr, &bufferCopy->at(0), (int)bufferCopy->size());
            delete bufferCopy;
        });
    }
}

void MB_CALL_TYPE mbNetChangeRequestUrl(mbNetJob jobPtr, const char* url)
{
    if (content::ThreadCall::isBlinkThread())
        mbnet::changeRequestUrl(jobPtr, url);
    else {
        std::string* urlCopy = new std::string(url);
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [jobPtr, urlCopy] {
            mbnet::changeRequestUrl(jobPtr, urlCopy->c_str());
            delete urlCopy;
        });
    }
}

void MB_CALL_TYPE mbOnLoadUrlBegin(mbWebView webviewHandle, mbLoadUrlBeginCallback callback, void* callbackParam)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setLoadUrlBeginCallback(callback, callbackParam);
}

void MB_CALL_TYPE mbNetHookRequest(mbNetJob jobPtr)
{
    checkThreadCallIsValid(__FUNCTION__);
    mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
    job->m_isWkeNetSetDataBeSetted = false;
    if (job->m_asynWkeNetSetData)
        delete (job->m_asynWkeNetSetData);
    job->m_asynWkeNetSetData = nullptr;
    job->m_isHoldJobToAsynCommit = false;
    job->m_isHookRequest = true;
}

void MB_CALL_TYPE mbOnURLChanged(mbWebView webviewHandle, mbURLChangedCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setURLChangedCallback(callback, param);
}

void MB_CALL_TYPE mbOnTitleChanged(mbWebView webviewHandle, mbTitleChangedCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setTitleChangedCallback(callback, param);
}

void MB_CALL_TYPE mbOnCreateView(mbWebView webviewHandle, mbCreateViewCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setCreateViewCallback(callback, param);
}

BOOL MB_CALL_TYPE mbOnClose(mbWebView webviewHandle, mbCloseCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return FALSE;
    webview->getClosure().setCloseCallback(callback, param);

    return TRUE;
}

void MB_CALL_TYPE mbOnDownloadInBlinkThread(mbWebView webviewHandle, mbDownloadInBlinkThreadCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setDownloadInBlinkThreadCallback(callback, param);
}

void MB_CALL_TYPE mbReload(mbWebView webviewHandle)
{
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* webview) { webview->reload(FALSE); });
}

void MB_CALL_TYPE mbGoBack(mbWebView webviewHandle)
{
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* webview) { webview->navigateBackForwardSoon(-1); });
}

void MB_CALL_TYPE mbGoForward(mbWebView webviewHandle)
{
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* webview) { webview->navigateBackForwardSoon(1); });
}

BOOL MB_CALL_TYPE mbCanGoBackOrForward(mbWebView webviewHandle, BOOL isGoBack)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return FALSE;

    if (isGoBack)
        return webview->historyBackListCount() > 0;
    return webview->historyForwardListCount() > 0;
}

void MB_CALL_TYPE mbSetUserAgent(mbWebView webviewHandle, const utf8* userAgent)
{
    checkThreadCallIsValid(__FUNCTION__);
    if (!userAgent)
        return;

    std::string* userAgentString = new std::string(userAgent);

    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, userAgentString] {
        content::RendererBlinkPlatformImpl* platform = (content::RendererBlinkPlatformImpl*)blink::Platform::Current();
        platform->setUserAgent(*userAgentString);
        delete userAgentString;
    });
}

BOOL MB_CALL_TYPE mbIsMainFrame(mbWebView webviewHandle, mbWebFrameHandle frameId)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return FALSE;

    if (frameId == (mbWebFrameHandle)-2)
        return TRUE;
    //     return webview->getMainFrameId() == frameId;

    blink::LocalFrame* blinkFrame = blink::FromFrameTokenHash((size_t)(frameId));
    if (!blinkFrame)
        return FALSE;
    blink::WebLocalFrameImpl* mainFrame = blink::WebLocalFrameImpl::FromFrame(blinkFrame);
    if (!mainFrame)
        return FALSE;
    return mainFrame->View()->MainFrame() == mainFrame;
}

void MB_CALL_TYPE mbResize(mbWebView webviewHandle, int w, int h)
{
    content::ThreadCall::callBlinkThreadAsyncWithValid(
        MB_FROM_HERE, webviewHandle, [w, h](content::MbWebView* webview) { webview->onResize(w, h, webview->isWebWindowMode()); });
}

void MB_CALL_TYPE mbWake(mbWebView webviewHandle)
{
    content::ThreadCall::wake();
}

void mbDestroyWebViewImpl(mbWebView webviewHandle)
{
    OutputDebugStringA("mbDestroyWebViewImpl-1-------------\n");
    checkThreadCallIsValid(__FUNCTION__);

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;

    webview->preDestroyOnUiThread();
    webview->getClosure().m_ClosingCallback = nullptr;

    //     if (webview->m_destroyCallback)
    //         webview->m_destroyCallback(webviewHandle, webview->m_destroyCallbackParam, nullptr);

    ::PostMessageW(webview->getHostWnd(), WM_CLOSE, 0, 0);

    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webview] { webview->preDestroyOnBlinkThread(); });
    OutputDebugStringA("mbDestroyWebViewImpl-2-------------\n");
}

void MB_CALL_TYPE mbDestroyWebView(mbWebView webviewHandle)
{
    mbDestroyWebViewImpl(webviewHandle);
}

static mbDownloadOpt mbSimpleDownload(mbWebView mbWebview, const WCHAR* path, const mbDialogOptions* dialogOpt, const mbDownloadOptions* downloadOptions,
    size_t expectedContentLength, const char* url, const char* mime, const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind,
    mbDownloadBind* callbackBind)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(mbWebview);
    if (!webview)
        return kMbDownloadOptCancel;

    webview->setIsMouseKeyMessageEnable(false);
    download::SimpleDownload* downloader = download::SimpleDownload::create(
        mbWebview, path, dialogOpt, downloadOptions, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);
    if (downloader)
        return kMbDownloadOptCacheData;

    webview->setIsMouseKeyMessageEnable(true);
    return kMbDownloadOptCancel;
}

mbDownloadOpt MB_CALL_TYPE mbPopupDialogAndDownload(mbWebView webviewHandle, const mbDialogOptions* dialogOpt, size_t expectedContentLength, const char* url,
    const char* mime, const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind, mbDownloadBind* callbackBind)
{
    // #if ENABLE_IN_MB_MAIN
    //     return DownloadMgr::simpleDownload(webviewHandle, nullptr, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);
    // #endif
#if 1 // ENABLE_IN_MB_MAIN
    return mbSimpleDownload(webviewHandle, nullptr, dialogOpt, nullptr, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);
#endif
    return kMbDownloadOptCancel;
}

mbDownloadOpt MB_CALL_TYPE mbDownloadByPath(mbWebView webviewHandle, const mbDownloadOptions* downloadOptions, const WCHAR* path, size_t expectedContentLength,
    const char* url, const char* mime, const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind, mbDownloadBind* callbackBind)
{
    return mbSimpleDownload(webviewHandle, path, nullptr, downloadOptions, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);
}

mbDownloadOpt MB_CALL_TYPE mbDownloadByUtf8Path(mbWebView webviewHandle, const mbDownloadOptions* downloadOptions, const char* path,
    size_t expectedContentLength, const char* url, const char* mime, const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind,
    mbDownloadBind* callbackBind)
{
    if (!path)
        return kMbDownloadOptCancel;
    std::u16string pathW = base::UTF8ToUTF16(path);
    return mbSimpleDownload(
        webviewHandle, (const WCHAR*)pathW.c_str(), nullptr, downloadOptions, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);
}

void MB_CALL_TYPE mbNetCancelRequest(mbNetJob jobPtr)
{
    mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
    if (content::ThreadCall::isBlinkThread()) {
        job->m_isWkeCanceled = true;
    } else {
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [job] { job->m_isWkeCanceled = true; });
    }
}

void MB_CALL_TYPE mbOnLoadUrlEnd(mbWebView webviewHandle, mbLoadUrlEndCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setLoadUrlEndCallback(callback, param);
}

void MB_CALL_TYPE mbOnImageBufferToDataURL(mbWebView webviewHandle, mbImageBufferToDataURLCallback callback, void* param)
{
}

void MB_CALL_TYPE mbOnDocumentReady(mbWebView webviewHandle, mbDocumentReadyCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setDocumentReadyCallback(callback, param);
}

void MB_CALL_TYPE mbOnDocumentReadyInBlinkThread(mbWebView webviewHandle, mbDocumentReadyCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setDocumentReadyInBlinkCallback(callback, param);
}

void MB_CALL_TYPE mbOnDownload(mbWebView webviewHandle, mbDownloadCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setDownloadCallback(callback, param);
}

void MB_CALL_TYPE mbOnLoadingFinish(mbWebView webviewHandle, mbLoadingFinishCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setLoadingFinishCallback(callback, param);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [webviewHandle](mb::MbWebView* webview) {
    //         wkeOnLoadingFinish(webview->getWkeWebView(), onLoadingFinish, (void*)webviewHandle);
    //     });
}

HDC MB_CALL_TYPE mbGetLockedViewDC(mbWebView webviewHandle)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return NULL;
    return webview->getViewDC();
}

void MB_CALL_TYPE mbUnlockViewDC(mbWebView webviewHandle)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;
    webview->unlockViewDC();
}

void MB_CALL_TYPE mbSetFocus(mbWebView webviewHandle)
{
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* webview) { webview->setFocus(); });
}

void MB_CALL_TYPE mbKillFocus(mbWebView webviewHandle)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* webview) { webview->killFocus(); });
}

class SkTraceMemoryDumpImpl : public SkTraceMemoryDump {
    void dumpNumericValue(const char* dumpName, const char* valueName, const char* units, uint64_t value) override
    {
        char* output = (char*)malloc(400);
        sprintf(output, "SkTraceMemoryDumpImpl: %s %s %d\n", valueName, units, (int)value);
        OutputDebugStringA(output);
        free(output);
    }

    void setMemoryBacking(const char* dumpName, const char* backingType, const char* backingObjectId) override
    {
    }

    void setDiscardableMemoryBacking(const char* dumpName, const SkDiscardableMemory& discardableMemoryObject) override
    {
    }

    SkTraceMemoryDump::LevelOfDetail getRequestedDetails() const override
    {
        return SkTraceMemoryDump::kLight_LevelOfDetail;
    }
};

void MB_CALL_TYPE mbSetResourceGc(mbWebView webView, int intervalSec)
{
    content::RenderThreadImpl::get()->garbageCollectionDelay(100);
}

std::vector<std::vector<char>*>* s_sharedStringBuffers = nullptr;

static const char* createTempCharString(const char* str, size_t length)
{
    if (!str || 0 == length)
        return "";
    std::vector<char>* stringBuffer = new std::vector<char>(length);
    memcpy(&stringBuffer->at(0), str, length * sizeof(char));
    stringBuffer->push_back('\0');

    if (!s_sharedStringBuffers)
        s_sharedStringBuffers = new std::vector<std::vector<char>*>();
    s_sharedStringBuffers->push_back(stringBuffer);
    return &stringBuffer->at(0);
}

void MB_CALL_TYPE mbSetWindowTitle(mbWebView webviewHandle, const utf8* title)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->setWindowTitle(title);
}

const utf8* MB_CALL_TYPE mbGetTitle(mbWebView webviewHandle)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return "";
    const std::string& title = webview->getWindowTitle();

    return createTempCharString(title.c_str(), title.length());
}

const utf8* MB_CALL_TYPE mbGetUrl(mbWebView webviewHandle)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return "";
    const std::string& url = webview->getUrl();

    return createTempCharString(url.c_str(), url.length());
}

void MB_CALL_TYPE mbSetTransparent(mbWebView webviewHandle, BOOL transparent)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->setIsTransparent(transparent);
}

void MB_CALL_TYPE mbSetEditable(mbWebView webviewHandle, bool editable)
{
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [editable](mb::MbWebView* webview) {
    //         wkeSetEditable(webview->getWkeWebView(), editable);
    //     });
    OutputDebugStringA("mbSetTransparent not impl\n");
}

mbJsValue MB_CALL_TYPE mbRunJsSync(mbWebView webviewHandle, mbWebFrameHandle frameId, const utf8* script, BOOL isInClosure)
{
    OutputDebugStringA("mbSetTransparent not impl\n");
    return 0;
}

BOOL MB_CALL_TYPE mbRegisterEmbedderCustomElement(mbWebView webviewHandle, mbWebFrameHandle frameId, const char* name, void* options, void* outResult)
{
    OutputDebugStringA("mbRegisterEmbedderCustomElement not impl\n");
    //     mb::MbWebView* webview = (mb::MbWebView*)common::LiveIdDetect::get()->getPtr(webviewHandle);
    //     if (!webview)
    //         return FALSE;
    //     return wkeRegisterEmbedderCustomElement(webview->getWkeWebView(), (mbWebFrameHandle)frameId, name, options, outResult);
    return FALSE;
}

void MB_CALL_TYPE mbGoToOffset(mbWebView webviewHandle, int offset)
{
    content::ThreadCall::callBlinkThreadAsyncWithValid(
        MB_FROM_HERE, webviewHandle, [offset](content::MbWebView* webview) { webview->navigateBackForwardSoon(offset); });
}

void MB_CALL_TYPE mbGoToIndex(mbWebView webviewHandle, int index)
{
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [index](content::MbWebView* webview) { webview->navigateToIndex(index); });
}

void MB_CALL_TYPE mbInsertCSSByFrame(mbWebView webviewHandle, mbWebFrameHandle frameId, const utf8* cssText)
{
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [frameId, cssText](mb::MbWebView* webview) {
    //         wkeInsertCSSByFrame(webview->getWkeWebView(), (wkeWebFrameHandle)frameId, cssText);
    //     });
    OutputDebugStringA("mbInsertCSSByFrame not impl\n");
}

BOOL MB_CALL_TYPE mbIsLoading(mbWebView webView)
{
    OutputDebugStringA("mbIsLoading not impl\n");
    //     WKE_CHECK_WEBVIEW_AND_THREAD_IS_VALID(webView, false);
    //     return webView->isLoading();
    DebugBreak();
    return FALSE;
}

void MB_CALL_TYPE mbStopLoading(mbWebView webView)
{
    OutputDebugStringA("mbStopLoading not impl\n");
    //     WKE_CHECK_WEBVIEW_AND_THREAD_IS_VALID(webView, (void)0);
    //     webView->stopLoading();
    //DebugBreak();
}

void MB_CALL_TYPE mbNetSetHTTPHeaderField(mbNetJob jobPtr, const WCHAR* key, const WCHAR* value, BOOL response)
{
    std::string keyUtf8 = base::UTF16ToUTF8(std::u16string_view((const char16_t*)key));
    std::string valueUtf8 = base::UTF16ToUTF8(std::u16string_view((const char16_t*)value));
    mbNetSetHTTPHeaderFieldUtf8(jobPtr, keyUtf8.c_str(), valueUtf8.c_str(), response);
}

void MB_CALL_TYPE mbEditorSelectAll(mbWebView webviewHandle)
{
    OutputDebugStringA("mbEditorSelectAll not impl\n");
    DebugBreak();
    //     checkThreadCallIsValid(__FUNCTION__);
    //     common::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](mb::MbWebView* webview) {
    //         wkeSelectAll(webview->getWkeWebView());
    //         });
}

void* MB_CALL_TYPE mbJsToV8Value(mbJsExecState es, mbJsValue v)
{
    mb::MbJsValue* mbVal = (mb::MbJsValue*)v;
    if (mbVal->getType() != kMbJsTypeV8Value)
        return nullptr;
    //return jsToV8Value((jsExecState)es, mbVal->getJsVal());
    DebugBreak();
    return nullptr;
}

const char* MB_CALL_TYPE mbNetGetReferrer(mbNetJob jobPtr)
{
    //return wkeNetGetReferrer((wkeNetJob)jobPtr);
    return "";
}

void gtkSimpleWin()
{
#if !defined(OS_WIN)
    GtkWidget* window;
    GtkWidget* label;
    GtkWidget* grid;

    // 创建一个新窗口，并设置其标题和默认大小
    //window = gtk_application_window_new(app);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple GTK3 Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // 创建一个网格容器
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // 创建一个标签，并设置要显示的文字
    label = gtk_label_new("Hello, this is a simple GTK3 window!");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    // 显示所有的部件
    gtk_widget_show_all(window);
#endif
}

#if OS_LINUX
static gboolean onTimerHeartbeat(gpointer arg)
{
    g_mainThreadRunLoop->RunUntilIdle();
    return TRUE;
}
#endif

bool g_isDownloadVersion2 = false;
extern "C" bool g_disableCookieFlushToFile = false;

void MB_CALL_TYPE mbSetDebugConfig(mbWebView webviewHandle, const char* debugString, const char* param)
{
    std::string dbgStr(debugString);
    if (dbgStr == "showDomNode") {
        content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* webview) { webview->debugShowDomNode(); });
    } else if (dbgStr == "ncHittestPaddingWidth") {
#ifndef _WIN32
        int ncHittestPadding = 0;
        printf("ncHittestPadding\n");
        if (base::StringToInt(base::StringPiece(param), &ncHittestPadding)) {
            printf("ncHittestPadding: %d\n", ncHittestPadding);
            content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
            if (webview)
                webview->setNcHittestPadding(ncHittestPadding);
        }
#endif
    } else if (dbgStr == "setDebugString") {
        g_outputDebugString = (FN_OutputDebugString)param;
    } else if (dbgStr == "setDownloadVersion2") {
        g_isDownloadVersion2 = true;
    } else if (dbgStr == "disableCookieFlushToFile") {
//         content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* webview) {
//             mbnet::WebCookieJarImpl* cookieJar = webview->getWebCookieJarImpl();
//             if (cookieJar) {
//                 CURLSH* curlSh = cookieJar->getCurlShareHandle();
// 
//                 CURL* handle = curl_easy_init();
//                 curl_easy_setopt(handle, CURLOPT_SHARE, curlSh);
//                 curl_easy_setopt(handle, CURLOPT_COOKIEJAR, "-");
//                 curl_easy_cleanup(handle);
//             }
//         });
        g_disableCookieFlushToFile = true;
    } else if (dbgStr == "gtkMessageBox") {
        gtkMessageBox(param);
    } else if (dbgStr == "gtkSimpleWin") {
        gtkSimpleWin();
    } else if (dbgStr == "setTimerHeartbeat") {
#if OS_LINUX
        g_timeout_add(16, onTimerHeartbeat, NULL);
#endif
    } else if (dbgStr == "showTotalSizeOfCommittedPages") {
        content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* webview) {
            size_t size = WTF::Partitions::TotalSizeOfCommittedPages();

            v8::HeapStatistics v8HeapStats;
            v8::Isolate::GetCurrent()->GetHeapStatistics(&v8HeapStats);
            size_t totalMemory = v8HeapStats.total_heap_size();
            size_t totalMemoryExec = v8HeapStats.total_heap_size_executable();
            size_t totalPhysicalSize = v8HeapStats.total_physical_size();

            SkTraceMemoryDumpImpl dump;
            SkGraphics::DumpMemoryStatistics(&dump);

            char output[100] = { 0 };
            sprintf(output, "TotalSizeOfCommittedPages: %d %d\n", (int)size, (int)totalMemory);
            OutputDebugStringA(output);
        });
    }
}

void MB_CALL_TYPE mbSetCookieEnabled(mbWebView webView, BOOL enable)
{
}

double MB_CALL_TYPE mbJsToDouble(mbJsExecState es, mbJsValue v)
{
    mb::MbJsValue* jsV = (mb::MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return 0;

    double result = 0;
    if (kMbJsTypeNumber == jsV->getType())
        result = jsV->getDoubleVal();
    common::LiveIdDetect::get()->unlock(v, jsV);

    return result;
}

BOOL MB_CALL_TYPE mbJsToBoolean(mbJsExecState es, mbJsValue v)
{
    mb::MbJsValue* jsV = (mb::MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return false;

    BOOL result = FALSE;
    if (kMbJsTypeBool == jsV->getType())
        result = jsV->getBoolVal();
    common::LiveIdDetect::get()->unlock(v, jsV);

    return result;
}

const utf8* MB_CALL_TYPE mbJsToString(mbJsExecState es, mbJsValue v)
{
    mb::MbJsValue* jsV = (mb::MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return "";

    std::string result;
    if (kMbJsTypeString == jsV->getType())
        result = jsV->getStrVal();
    common::LiveIdDetect::get()->unlock(v, jsV);

    if (0 == result.size())
        return "";

    return createTempCharString(result.c_str(), result.size());
}

mbWebFrameHandle MB_CALL_TYPE mbJsToWebFrameHandle(mbJsExecState es, mbJsValue v)
{
    mb::MbJsValue* jsV = (mb::MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return nullptr;

    if (kMbJsTypeFrame == jsV->getType()) {
        mbWebFrameHandle ret = jsV->getWebFrameHandle();
        common::LiveIdDetect::get()->unlock(v, jsV);
        return ret;
    }

    common::LiveIdDetect::get()->unlock(v, jsV);
    return nullptr;
}

mbWebFrameHandle MB_CALL_TYPE mbGetParentWebFrameHandle(mbWebView webView, mbWebFrameHandle frame)
{
    if (content::ThreadCall::isBlinkThread())
        return nullptr;

    blink::LocalFrame* blinkFrame = blink::FromFrameTokenHash((size_t)(frame));
    if (!blinkFrame)
        return nullptr;
    blink::WebLocalFrameImpl* mainFrame = blink::WebLocalFrameImpl::FromFrame(blinkFrame);
    blink::WebFrame* parent = mainFrame->Parent();
    if (!parent)
        return nullptr;

    return (mbWebFrameHandle)content::getFrameIdByWebLocalFrame(parent->ToWebLocalFrame());
}

template <class T> static void freeShareds(std::vector<T*>* s_shared)
{
    if (!s_shared)
        return;

    for (size_t i = 0; i < s_shared->size(); ++i) {
        delete s_shared->at(i);
    }
    s_shared->clear();
}

namespace content {

void freeTempCharStrings()
{
    freeShareds(s_sharedStringBuffers);
}

}

std::vector<mbJsValue>* s_jsValues;

mbJsType MB_CALL_TYPE mbGetJsValueType(mbJsExecState es, mbJsValue v)
{
    mb::MbJsValue* jsV = (mb::MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return kMbJsTypeUndefined;

    mbJsType type = jsV->getType();
    common::LiveIdDetect::get()->unlock(v, jsV);
    return type;
}

void MB_CALL_TYPE mbJsValueAddRef(mbJsExecState es, mbJsValue v)
{
    mb::MbJsValue* jsV = (mb::MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return;

    jsV->ref();
    common::LiveIdDetect::get()->unlock(v, jsV);
}

void MB_CALL_TYPE mbJsValueDeref(mbJsExecState es, mbJsValue v)
{
    mb::MbJsValue* jsV = (mb::MbJsValue*)common::LiveIdDetect::get()->getPtrLocked(v);
    if (!jsV)
        return;

    jsV->deref();
    common::LiveIdDetect::get()->unlock(v, jsV);
}

namespace content {
void runJsOnBlinkThread(
    mbWebView webviewHandle, mbWebFrameHandle frameId, int worldId, std::string* scriptString, BOOL isInClosure, mbRunJsCallback callback, void* param);
}

mbWebFrameHandle MB_CALL_TYPE mbWebFrameGetMainFrame(mbWebView webviewHandle)
{
    //LocalFrameToken::Hasher()(frame_token);
    //return (mbWebFrameHandle)-2;

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return nullptr;
    blink::WebLocalFrame* frame = (blink::WebLocalFrame*)webview->getMainFrame();
    return (mbWebFrameHandle)(content::getFrameIdByWebLocalFrame(frame));
}

void MB_CALL_TYPE mbRunJs(
    mbWebView webviewHandle, mbWebFrameHandle frameId, const utf8* script, BOOL isInClosure, mbRunJsCallback callback, void* param, void* unuse)
{
    std::string* scriptString = new std::string(script);
    if (content::ThreadCall::isBlinkThread()) {
        content::runJsOnBlinkThread(webviewHandle, frameId, (int)unuse, scriptString, isInClosure, callback, param);
    } else {
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, frameId, unuse, scriptString, isInClosure, callback, param] {
            content::runJsOnBlinkThread(webviewHandle, frameId, (int)unuse, scriptString, isInClosure, callback, param);
        });
    }
}

void MB_CALL_TYPE mbOnJsQuery(mbWebView webviewHandle, mbJsQueryCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;

    std::function<void(mbJsExecState es, int64_t queryId, int customMsg, const utf8* request)>* closure = nullptr;
    closure = new std::function<void(mbJsExecState es, int64_t queryId, int customMsg, const utf8* request)>(
        /*std::move*/ (MB_FROM_HERE, [webviewHandle, callback, param](mbJsExecState es, int64_t queryId, int customMsg, const utf8* request) {
            return callback(webviewHandle, param, es, queryId, customMsg, request);
        }));
    webview->getClosure().setJsQueryClosure(closure);
}

void MB_CALL_TYPE mbOnJsQueryEx(mbWebView webviewHandle, mbJsQueryExCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;

    std::function<void(mbJsExecState es, const mbJsValue* val, int count)>* closure = nullptr;
    closure = new std::function<void(mbJsExecState es, const mbJsValue* val, int count)>(
        /*std::move*/ (MB_FROM_HERE,
            [webviewHandle, callback, param](mbJsExecState es, const mbJsValue* val, int count) { return callback(webviewHandle, param, es, val, count); }));
    webview->getClosure().setJsQuery2Closure(closure);
}

void MB_CALL_TYPE mbResponseQuery(mbWebView webviewHandle, int64_t queryId, int customMsg, const utf8* response)
{
    std::string* requestString = new std::string(response ? response : "");
    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, queryId, customMsg, requestString] {
        std::pair<mbWebFrameHandle, int>* idInfo = (std::pair<mbWebFrameHandle, int>*)queryId;
        printf("mbResponseQuery 1111\n");
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        do {
            if (!webview)
                break;
            blink::LocalFrame* blinkFrame = blink::FromFrameTokenHash((size_t)(idInfo->first));
            if (!blinkFrame)
                break;

            v8::Isolate* isolate = v8::Isolate::GetCurrent();
            v8::HandleScope handleScope(isolate);
            blink::WebLocalFrame* mainFrame = blink::WebLocalFrameImpl::FromFrame(blinkFrame);
            v8::Local<v8::Context> context = mainFrame->MainWorldScriptContext();
            v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::kDoNotRunMicrotasks);

            context->Enter();

            v8::Local<v8::Object> global = context->Global();
            v8::Local<v8::Value> windowVal
                = global->Get(context, v8::String::NewFromUtf8(isolate, "window", v8::NewStringType::kNormal, -1).ToLocalChecked()).ToLocalChecked();

            v8::Local<v8::Object> windowObj = windowVal->ToObject(context).ToLocalChecked();

            v8::Local<v8::String> onMbQueryStr = v8::String::NewFromUtf8(isolate, "__onMbQuery__", v8::NewStringType::kNormal, -1).ToLocalChecked();
            v8::Local<v8::Value> onMbQueryValue = windowObj->Get(context, onMbQueryStr).ToLocalChecked();
            v8::Function* onMbQueryFunc = v8::Function::Cast(*onMbQueryValue);

            v8::Local<v8::Integer> arg0 = v8::Integer::New(isolate, idInfo->second);
            v8::Local<v8::Integer> arg1 = v8::Integer::New(isolate, customMsg);
            v8::Local<v8::String> arg2
                = v8::String::NewFromUtf8(isolate, requestString->c_str(), v8::NewStringType::kNormal, requestString->size()).ToLocalChecked();
            v8::Local<v8::Value> argv[3] = { arg0, arg1, arg2 };

            onMbQueryFunc->Call(context, v8::Undefined(isolate), 3, argv);
            context->Exit();
        } while (false);

        delete idInfo;
        delete requestString;
    });
}

void MB_CALL_TYPE mbOnConsole(mbWebView webviewHandle, mbConsoleCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setConsoleCallback(callback, param);
}

void MB_CALL_TYPE mbPostToUiThread(mbOnCallUiThread callback, void* param)
{
    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [callback, param]() { callback(NULL_WEBVIEW, param); });
}

void MB_CALL_TYPE mbPostToUiThreadDelay(mbOnCallUiThread callback, void* param, size_t millisecond)
{
    content::ThreadCall::callUiThreadDelayed(
        MB_FROM_HERE, [callback, param]() { callback(NULL_WEBVIEW, param); }, millisecond);
}

BOOL MB_CALL_TYPE mbOnPrinting(mbWebView webviewHandle, mbPrintingCallback callback, void* param)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return FALSE;
    //webview->m_printingCallback = callback;
    //webview->m_printingCallbackParam = param;
    return TRUE;
}

void MB_CALL_TYPE mbGetSize(mbWebView webviewHandle, mbRect* rc)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;

    rc->x = 0;
    rc->y = 0;
    rc->w = 0;
    rc->h = 0;

    SIZE size = webview->getClientSizeLocked();
    rc->w = size.cx;
    rc->h = size.cy;
}

void MB_CALL_TYPE mbSetUserKeyValue(mbWebView webviewHandle, const char* key, void* value)
{
    //checkThreadCallIsValid(__FUNCTION__);
    if (!key)
        return;

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;
    webview->setUserKeyValue(key, value);
}

void* MB_CALL_TYPE mbGetUserKeyValue(mbWebView webviewHandle, const char* key)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return nullptr;
    return webview->getUserKeyValue(key);
}

void MB_CALL_TYPE mbOnAlertBox(mbWebView webviewHandle, mbAlertBoxCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setAlertBoxCallback(callback, param);
}

void MB_CALL_TYPE mbOnConfirmBox(mbWebView webviewHandle, mbConfirmBoxCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setConfirmBoxCallback(callback, param);
}

void MB_CALL_TYPE mbOnPromptBox(mbWebView webviewHandle, mbPromptBoxCallback callback, void* param)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
    if (!webview)
        return;
    webview->getClosure().setPromptBoxCallback(callback, param);
}

int MB_CALL_TYPE mbQueryState(mbWebView webviewHandle, const char* type)
{
    std::string typeStr(type);
    if ("dispatchWillCommitProvisionalLoad" == typeStr) {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (!webview)
            return -1;
        return webview->hasDispatchWillCommitProvisionalLoad();
    }

    return -1;
}

void getSourceOrMHTML(mbWebView webviewHandle, mbGetSourceCallback calback, void* param, bool isSource);

void MB_CALL_TYPE mbGetSource(mbWebView webviewHandle, mbGetSourceCallback calback, void* param)
{
    getSourceOrMHTML(webviewHandle, calback, param, true);
}

mbStringPtr getSourceOrMhtmlSync(mbWebView webviewHandle, bool isSource);

mbStringPtr MB_CALL_TYPE mbGetSourceSync(mbWebView webviewHandle)
{
    return getSourceOrMhtmlSync(webviewHandle, true);
}

void MB_CALL_TYPE mbCallBlinkThreadAsync(mbThreadCallback callback, void* param1, void* param2)
{
    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [callback, param1, param2] { callback(param1, param2); });
}

void mbSetProxy(mbWebView webviewHandle, const mbProxy* proxy)
{
    checkThreadCallIsValid(__FUNCTION__);

    mbProxy* proxyCopy = new mbProxy();
    memcpy(proxyCopy, proxy, sizeof(mbProxy));

    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, proxyCopy] {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (webview)
            webview->setProxy(proxyCopy);
    });
}

void setFullPath(mbWebView webviewHandle, const WCHAR* path, bool isCookiePath);

// 这两api如果在blink线程被调用，必须立刻执行。否则会产生老cookie\storage路径文件
void MB_CALL_TYPE mbSetLocalStorageFullPath(mbWebView webviewHandle, const WCHAR* path)
{
    setFullPath(webviewHandle, path, false);
}

void MB_CALL_TYPE mbSetCookieJarFullPath(mbWebView webviewHandle, const WCHAR* path)
{
    setFullPath(webviewHandle, path, true);
}

void MB_CALL_TYPE mbSetContextMenuEnabled(mbWebView webviewHandle, BOOL b)
{
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [b](content::MbWebView* webview) { webview->setContextMenuEnable(!!b); });
}

namespace content {
extern uint32_t g_contextMenuItemMask;
}

void MB_CALL_TYPE mbSetContextMenuItemShow(mbWebView webviewHandle, mbMenuItemId item, BOOL isShow)
{
    if (isShow)
        content::g_contextMenuItemMask |= item;
    else
        content::g_contextMenuItemMask &= (~item);
}

void MB_CALL_TYPE mbSetCookieJarPath(mbWebView webviewHandle, const WCHAR* path)
{
    if (!path)
        return;

    std::u16string pathString((const char16_t*)path);
    if (0 == pathString.size())
        return;

    if (mbu16('\\') != pathString[pathString.size() - 1])
        pathString += (char16_t)mbu16('\\');
    pathString += (const char16_t*)mbu16("cookies.dat");

    mbSetCookieJarFullPath(webviewHandle, (const WCHAR*)pathString.c_str());
}

void MB_CALL_TYPE mbSetViewSettings(mbWebView webviewHandle, const mbViewSettings* settings)
{
    checkThreadCallIsValid(__FUNCTION__);
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;

    //     mbViewSettings* settingsCopy = new mbViewSettings();
    //     memcpy(settingsCopy, settings, sizeof(mbViewSettings));

    webview->setBackgroundColor(settings->bgColor);
    //
    //     common::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewHandle, settingsCopy]() {
    //         content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    //         if (webview)
    //             wkeSetViewSettings(webview->getWkeWebView(), (const wkeViewSettings*)settingsCopy);
    //         delete settingsCopy;
    //     });
}

void* MB_CALL_TYPE mbGetProcAddr(const char* name)
{
    DebugBreak();
    return nullptr;
}