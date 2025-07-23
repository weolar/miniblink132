
#define _CRT_SECURE_NO_WARNINGS
//
// 部分api文档地址：https://miniblink.net/views/doc/api-doc-vip.html
// 目前已导出的api:
// mbInit
// mbUninit
// mbCreateInitSettings
// mbSetInitSettings
// mbCreateWebWindow
// mbOnLoadUrlBegin
// mbOnTitleChanged
// mbOnURLChanged
// mbOnCreateView
// mbOnConsole
// mbLoadURL
// mbShowWindow
// mbRunMessageLoop
// mbExitMessageLoop
// mbPostToUiThread
// mbGetString
// mbGetStringLen
// mbDeleteString
// mbCreateString
// mbNetSetData
// mbNetSetMIMEType
// mbNetSetHTTPHeaderFieldUtf8
// mbIsMainFrame
// mbReload
// mbGoForward
// mbGoBack
// mbResize
// mbGetSize
// mbWake
// mbDestroyWebView
// mbNetCancelRequest
// mbPopupDialogAndDownload
// mbOnDownloadInBlinkThread
// mbOnPrinting
// mbSetNavigationToNewWindowEnable
// mbOnClose
// mbQueryState
// mbNetChangeRequestUrl
// mbRunJs
// mbWebFrameGetMainFrame
// mbResponseQuery
// mbOnJsQuery
// mbCreateWebView
// mbOnPaintUpdated
// mbGetHostHWND
// mbMoveToCenter
// mbSetHandle
// mbSetFocus
// mbKillFocus
// mbSetDebugConfig
// mbJsToBoolean
// mbJsToDouble
// mbJsToString
// mbGetLockedViewDC
// mbUnlockViewDC
// mbOnLoadingFinish
// mbOnLoadUrlEnd
// mbOnDocumentReady
// mbOnDownload
// mbOnAlertBox
// mbOnConfirmBox
// mbOnPromptBox
// mbOnImageBufferToDataURL
// mbOnNavigation
// mbOnDidCreateScriptContext
// mbSetCspCheckEnable
// mbSetCookieEnabled
// mbFireKeyDownEvent
// mbFireKeyPressEvent
// mbFireKeyUpEvent
// mbFireMouseWheelEvent
// mbFireWindowsMessage
// mbFireMouseEvent
// mbSetResourceGc
// mbSetUserKeyValue
// mbGetUserKeyValue
// mbGetSource
// mbGetSize

#if 1 // !defined(_WIN32)

#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <signal.h>
#include <string.h>
#include <string>

#if defined(_WIN32)
#include <windows.h>
#else
#include <pthread.h>
#include <stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dlfcn.h>
#include <dirent.h>
#include <sys/types.h>
#endif
#include "../../mbvip/core/mb.h"

const char* kHtmlTestStr = "<!DOCTYPE html>\n"
                           "<html lang=\"en\">\n"
                           "<head>\n"
                           "    <meta charset=\"UTF-8\">\n"
                           "    <meta name=\"viewport\" content=\"width=device-width, initial-scale = 1.0\">\n"
                           "    <title>test</title>\n"
                           "    <style>\n"
                           "        .red-rectangle {\n"
                           "            width: 200px;\n"
                           "            height: 50px;\n"
                           "            background-color: red;\n"
                           "            -webkit-app-region: drag;\n"
                           "        }\n"
                           "    </style>\n"
                           "</head>\n"
                           "<body>\n"
                           "    <div class=\"red-rectangle\"></div>\n"
                           "</body>\n"
                           "</html>\n";

const char* kHtmlTestStr2 = "<html><head></head>"
                            "<body style='font-size:16px;'>"
                            "input url: &nbsp<input id=myurl style='width:400px;' onkeydown=if(event.keyCode==13)GoURL(); "
                            "value='https://www.baidu.com/'><button onclick=GoURL();>GO</button><hr />"
                            "<a href='http://qq.com/'>QQ</a><br />"
                            "<a href='http://download.csdn.net/'>CSDN</a><br />"
                            "<a href='http://chat.workerman.net/'>Websocket test</a><br />"
                            "<a href='http://www.workerman.net/demos/browserquest/'>Websocket demos</a><br />"
                            "<a href='http://www.163.com/'>163</a><br />"
                            //L"<span onclick=JsCall('')>JsCall</span>"
                            "</body>"
                            "<script>function GoURL(){document.location=document.getElementById('myurl').value;}</script>"
                            "</html>";

extern "C" unsigned long _stack_chk_guard;

mbWebView MB_CALL_TYPE handleCreateView(
    mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures)
{
    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 110, 60, 600, 700);
    ::mbOnCreateView(mbView, handleCreateView, nullptr);
    ::mbSetNavigationToNewWindowEnable(mbView, true);
    ::mbSetCspCheckEnable(mbView, true);

    ::mbShowWindow(mbView, TRUE);
    return mbView;
}

static BOOL MB_CALL_TYPE handleLoadUrlBegin(mbWebView webView, void* param, const char* url, void* job)
{
    printf("handleLoadUrlBegin: %s\n", url);

    //     std::string urlStr("handleLoadUrlBegin:");
    //     urlStr += url;
    //     urlStr += "\n";
    //     printf(urlStr.c_str());
    //
    //     if (hookUrl(job, url, "universal-report.min.js", L"G:\\test\\web_test\\51iwifi\\universal-report.min.js", "text/html"))
    //         return true;
    //
    //     if (hookUrl(job, url, "_app-f54e3843f15fa10c7198.js", L"D:\\test\\web\\cc_163\\_app-f54e3843f15fa10c7198.js", "text/javascript"))
    //         return true;
    //
    //     if (hookUrl(job, url, "act/webcc/link-pk-game/v1.9.1/index.js", L"D:\\test\\web\\cc_163\\webcc_191_index.js", "text/javascript"))
    //         return true;
    //
    //     if (hookUrl(job, url, "act/webcc/performance-reporter/v1.2.0/index.js", L"D:\\test\\web\\cc_163\\performance-reporter.js", "text/javascript"))
    //         return true;
    //
    //     if (0 != strstr(url, "mini_original.js?v")) {
    //         mbNetChangeRequestUrl(job, "http://192.168.83.1:8080/mini_original.js");
    //     }
    return TRUE;
}

void MB_CALL_TYPE onJsQueryTest(mbWebView webView, void* param, mbJsExecState es, int64_t queryId, int customMsg, const utf8* request)
{
    printf("onJsQueryCallback");
    mbResponseQuery(webView, queryId, customMsg, "I am response");
}

#if defined(_WIN32)
int WINAPI wWinMain55(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char** argv)
#endif
{
#if defined(_WIN32)
#if defined(_M_X64) || defined(__x86_64__)
#ifdef _DEBUG
    mbSetMbMainDllPath(L"mb132_x64_d.dll");
#else
    mbSetMbMainDllPath(L"mb132_x64.dll");
#endif
#else
#ifdef _DEBUG
    mbSetMbMainDllPath(L"mb132_x32_d.dll");
#else
    mbSetMbMainDllPath(L"mb132_x32.dll");
#endif
#endif
#endif
    mbInit(nullptr);
    mbEnableHighDPISupport();

    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_TRANSPARENT /*MB_WINDOW_TYPE_TRANSPARENT*/, NULL, 100, 50, 600, 700); // 创建一个普通窗口
    //mbWebView mbView = ::mbCreateWebCustomWindow(NULL, WS_POPUP, 0, 100, 50, 600, 700); // 创建了一个无标题栏无边框的窗口

    ::mbSetWindowTitle(mbView, "miniblink108");
    ::mbOnLoadUrlBegin(mbView, handleLoadUrlBegin, nullptr);
    ::mbOnCreateView(mbView, handleCreateView, nullptr);
    ::mbOnJsQuery(mbView, onJsQueryTest, nullptr);
    ::mbSetDebugConfig(mbView, "ncHittestPaddingWidth", "2"); // 设置边框边缘多长为可拉伸
    ::mbSetContextMenuEnabled(mbView, FALSE);

    mbProxy proxy;
    memset(&proxy, 0, sizeof(proxy));
    proxy.type = MB_PROXY_HTTP;
    strcpy(proxy.hostname, "127.0.0.1");
    //     strcpy(proxy.username, "ipProxy");
    //     strcpy(proxy.password, "BarZEkqTnZ");
    proxy.port = 10909;
    ::mbSetProxy(mbView, &proxy);

    const char* url =
        "file:///G:/test/exe_test/ConsoleApplication1/test_nodejs.html";
        //"file:///G:/test/web_test/AIDA64_RemoteSensor/index.html";
        //"view-source:https://www.baidu.com"
        //"http://192.168.0.107:8091/linux_mb/index.html";
        //"https://my-ip.cc/zh-hans/"
        //"baidu.com"
        //"file:///G:/test/exe_test/mbTest/skin/index.html";
        //"file:///G:/test/exe_test/mbTest/skin/2.htm";
        //"https://google.com";
        //"https://microsoft.github.io/monaco-editor/playground.html?source=v0.52.0#example-creating-the-editor-hello-world"
        ;

    ::mbLoadURL(mbView, url); // 通过url加载网页
    //::mbLoadHtmlWithBaseUrl(mbView, kHtmlTestStr2, "file:///test.html"); // 通过字符串加载html

    ::mbShowWindow(mbView, TRUE);

#if !defined(_WIN32)
    void* gtkWin = mbGetPlatformWindowHandle(mbView); // 获取gtk的GtkWidget*，但不一定能成功，需要等待窗口创建完毕才行
    printf("gtkWin::::::: %p\n", gtkWin);
#endif
    ::mbRunMessageLoop(); // 需要退出可调用mbExitMessageLoop

    return 0;
}

#endif