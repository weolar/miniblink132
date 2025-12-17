
#pragma clang optimize off
#include "mbvip/core/mb.h"
#include "RootWindow.h"
#include <windows.h>
#include <string>
#include <vector>
#include <map>

HWND g_hRootWnd = nullptr;
const LPCWSTR kClassName = L"WebBrowserContainer";
SIZE g_wndSize = { 900, 600 };

void readFileToBuf(const char* path, std::vector<char>* buffer)
{
    const char kHead[] = "file:///";
    std::string url = path;
    if (0 == url.find(kHead))
        url = url.substr(sizeof(kHead) - 1);

    buffer->clear();
    HANDLE hFile = CreateFileA(url.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
        return;

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (0 == bufferSize)
        return;

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
}

LRESULT CALLBACK ieWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //     if (WM_MOUSEMOVE != message && WM_TIMER != message && WM_NCHITTEST != message && WM_SETCURSOR != message) {
    //         char* output = (char*)malloc(0x100);
    //         sprintf_s(output, 0x99, "WndProc: %x\n", message);
    //         OutputDebugStringA(output);
    //         free(output);
    //     }

    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_INITMENUPOPUP:
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void readFile(const wchar_t* path, std::vector<char>* buffer)
{
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        //         std::vector<WCHAR> filenameBuffer;
        //         filenameBuffer.resize(MAX_PATH + 3);
        //         ::GetModuleFileNameW(NULL, filenameBuffer.data(), MAX_PATH);
        //         ::PathRemoveFileSpecW(filenameBuffer.data());
        //
        //         ::PathAppendW(filenameBuffer.data(), L"mtmb.exp");
        //         if (::PathFileExistsW(filenameBuffer.data())) {
        // #ifdef _DEBUG
        //             DebugBreak();
        // #endif
        //         }
        DebugBreak();
        return;
    }

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (0 == bufferSize)
        return;

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    b = b;
}

static bool hookUrl(void* job, const char* url, const char* hookedUrl, const wchar_t* localFile, const char* mime, const char* contentType)
{
    if (0 == strstr(url, hookedUrl))
        return false;

    std::vector<char> buffer;
    readFile(localFile, &buffer);
    if (0 == buffer.size())
        return false;

    mbNetSetData(job, &buffer[0], buffer.size());
    mbNetSetMIMEType(job, mime);
    mbNetSetHTTPHeaderFieldUtf8(job, "Content-Type", contentType, TRUE);

    OutputDebugStringA("hookUrl:");
    OutputDebugStringA(url);
    OutputDebugStringA("\n");

    return true;
}

static BOOL MB_CALL_TYPE handleLoadUrlBegin(mbWebView webView, void* param, const char* url, void* job)
{
    //     std::string urlStrDebug("handleLoadUrlBegin:");
    //     urlStrDebug += url;
    //     urlStrDebug += "\n";
    //     OutputDebugStringA(urlStrDebug.c_str());

    //     if (hookUrl(job, url, "3.46df1747.chunk.js", L"G:\\test\\web_test\\51iwifi\\3.46df1747.chunk.js", "text/javascript", "application/javascript"))
    //         return true;

    //     if (hookUrl(job, url, "appchannel.html5.qq.com/package?app=qqbrowser", L"G:\\test\\web_test\\51iwifi\\gtm_id=GTM-WXXJ8PZ.js", "text/javascript", "application/javascript"))
    //         return true;

    std::string urlStr = url;
    if (urlStr.find("F70899E7EDB491741E8AB94E06451372") != std::string::npos)
        OutputDebugStringA("");

    //     if (strstr(url, "daxiansheng/images/header.png")) {
    //         //mbNetSetData(job, " ", 1);
    //         OutputDebugStringA("trackMi.tml!!!!!!!!!!!!!!!!!!\n");
    //         return false;
    //     }

    //     std::vector<char> buffer;
    //     readFile(L"E:\\test_code\\bemo\\res\\1.asar", &buffer);
    //
    //     static void* s_packetMgr = nullptr;
    //     if (!s_packetMgr)
    //         s_packetMgr = wkeCreateResPacketMgr(buffer.data(), buffer.size());
    //
    //     wkeOnUrlBeginResPacketMgr(s_packetMgr, url, job);

    //     if (hookUrl(job, url, "wangeditor@3.1.1/release/wangEditor.min.js", L"G:\\test\\web_test\\wangeditor\\wangeditor.js", "text/javascript"))
    //         return true;

    //      if (0 != strstr(url, "ecpm.tanx.com/ex?i=mm_"))
    //      {
    //          mbNetHookRequest(job);
    //      }

    //     if (0 != strstr(url, "video.webm")) {
    //         mbNetChangeRequestUrl(job, "file:///G:/test/web_test/icoc/index-4.mp4");
    //     }

    return false;
}

void testMain();
void createSimpleMb();

unsigned int RSHash(const char* str, unsigned int len)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < len; str++, i++) {
        hash = hash * a + (*str);
        a = a * b;
    }

    return hash;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
#if 1 // def _DEBUG
    testMain();
    //return 0;
#endif

//     OutputDebugStringA("CoInitializeEx 1\n");
//     ::CoInitializeEx(nullptr, COINIT_DISABLE_OLE1DDE);
//     OutputDebugStringA("CoInitializeEx 2\n");

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
    mbInit(nullptr);
    mbEnableHighDPISupport();

    //     createSimpleMb();
    //     mbRunMessageLoop();
    //     return 0;

    RootWindow* rootWin = new RootWindow();
    rootWin->createRootWindow();

    mbRunMessageLoop();
    return 0;
}

int WINAPI wWinMain2(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
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
    mbInit(nullptr);

    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_TRANSPARENT, NULL, 100, 50, 800, 700);

    ::mbOnLoadUrlBegin(mbView, handleLoadUrlBegin, nullptr);

    const char* url =
        "http://192.168.83.1:8091/index.html";
        "file:///G:/test/web_test/51iwifi/weibo.htm";
    "https://element.eleme.cn";
    "https://element.eleme.cn/#/zh-CN/component/layout";
    "https://www.66rjz.com/pcsoft/xtgj";
    "https://link.csdn.net/?target=https%3A%2F%2Fwww.66rjz.com%2Fpcsoft%2F144156.html"; // 跳转导致崩溃
    "file:///G:/test/exe_test/MiniblinkDemo/selectFile.html";
    "http://f10.legu168.com:81/gu/600000/0001.htm";
    "https://ant-design.antgroup.com/components/button-cn";
    "https://ant-design.antgroup.com/components/overview-cn";
    "http://admin.2018k.cn/#/login";
    "https://kandianshare.html5.qq.com/v2/news/"
    "8407287589294883138?cardmode=1&docId=8407287589294883138&from_app=qb&sGuid=d997c50c09c7f4e96c448e16795588cb&sQueryId=1702641489578&sUserId=&sUserType=&sh_"
    "sid=5__228b5fc73e7ddb6f__d997c50c09c7f4e96c448e16795588cb&target_app=kb";
    "file:///G:/test/web_test/51iwifi/kandian.htm";
    "file:///G:/test/web_test/51iwifi/1.htm";
    "http://192.168.10.46:8091/aardio.htm";
    "file:///G:/test/web_test/51iwifi/aardio.htm";
    "https://cn.bing.com/"
    "search?q=%E5%8F%A4%E5%8F%B2%E9%92%A9%E5%A5%87%E7%BC%98&qs=n&form=QBRE&sp=-1&lq=0&pq=%E5%8F%A4%E5%8F%B2%E9%92%A9%E5%A5%87%E7%BC%98&sc=1-5&sk=&cvid="
    "5815DE40E8AF40DC974636206871D0DD&ghsh=0&ghacc=0&ghpl=";
    "https://geek-docs.com/html/html-ask-answer/810_html_this_document_requires_trustedscripturl_assignment.html";

    "https://gitee.com/weolar_admin/mininodejs20/pulls/9/files";
    "file:///G:/test/web_test/51iwifi/insertbefore.html";
    "https://www.net-usb.com/cn/usb-over-wi-fi/wireless-usb-connection/";
    "https://source.chromium.org/search?q=SupportedPrefixesStruct&sq=";
    "https://finance.sina.com.cn/stock/usstock/c/2023-12-08/doc-imzxiprr0450628.shtml";
    "https://servo.org/blog/2023/10/26/css-filters-testing-tauri/";
    "https://www.aardio.com/";
    "view-source:https://www.baidu.com";
    //u8"view-source:/home/euweb/桌面/mini_electron/linux/main4.htm";
    "https://www.qidian.com/chapter/1038152211/768723838/";
    "https://www.qidian.com/";
    "https://www.baidu.com/";
    "file:///G:/test/sln_test/QueueByMiniBlink/dist/test_vite.htm";
    "file:///G:/test/web_test/51iwifi/1.htm";
    "file:///G:/test/web_test/58/svgimage.htm"; // 测试LoaderFactoryForFrame::LoaderFactoryForFrame里的svgimage产生的崩溃

    ::mbLoadURL(mbView, url);
    ::mbShowWindow(mbView, TRUE);

//     HWND hwnd = ::mbGetHostHWND(mbView);
// 
//     ::mbWebView mbView2 = mbCreateWebWindow(MB_WINDOW_TYPE_CONTROL, hwnd, 100, 50, 600, 700);
//     ::mbLoadURL(mbView2, "https://www.baidu.com/");
//     ::mbShowWindow(mbView2, TRUE);

    mbRunMessageLoop();
    return 0;
}

int WINAPI wWinMain4(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
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
    mbInit(NULL);
    mbEnableHighDPISupport();

    mbWebView web_view = mbCreateWebView();
    mbLoadURL(web_view, "https://baidu.com");
    mbRunMessageLoop();
    return 0;
}