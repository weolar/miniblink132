
#include "mbvip/core/mb.h"
#include "RootWindow.h"
#include <windows.h>
#include <string>
#include <vector>

#define CLS_WINDOW L"mbTestWindow"

#if 1

void MB_CALL_TYPE handlePaintUpdatedCallback(mbWebView webView, void* param, const HDC hdc, int x, int y, int cx, int cy)
{
    HWND hWnd = (HWND)param;
    BOOL callOk = FALSE;
    if (WS_EX_LAYERED == (WS_EX_LAYERED & GetWindowLong(hWnd, GWL_EXSTYLE))) {
        RECT rectDest;
        ::GetWindowRect(hWnd, &rectDest);

        SIZE sizeDest = { rectDest.right - rectDest.left, rectDest.bottom - rectDest.top };
        POINT pointDest = { 0, 0 }; // { rectDest.left, rectDest.top };
        POINT pointSource = { 0, 0 };

        BITMAP bmp = { 0 };
        HBITMAP hBmp = (HBITMAP)::GetCurrentObject(hdc, OBJ_BITMAP);
        ::GetObject(hBmp, sizeof(BITMAP), (LPSTR)&bmp);

        sizeDest.cx = bmp.bmWidth;
        sizeDest.cy = bmp.bmHeight;

        HDC hdcScreen = GetDC(hWnd);

        BLENDFUNCTION blend = { 0 };
        blend.BlendOp = AC_SRC_OVER;
        blend.SourceConstantAlpha = 255;
        blend.AlphaFormat = AC_SRC_ALPHA;
        callOk = ::UpdateLayeredWindow(hWnd, hdcScreen, nullptr, &sizeDest, hdc, &pointSource, RGB(0xFF, 0xFF, 0xFF), &blend, ULW_ALPHA);
        if (!callOk) {
            HDC hdcMemory = ::CreateCompatibleDC(hdcScreen);
            HBITMAP hbmpMemory = ::CreateCompatibleBitmap(hdcScreen, sizeDest.cx, sizeDest.cy);
            HBITMAP hbmpOld = (HBITMAP)::SelectObject(hdcMemory, hbmpMemory);

            ::BitBlt(hdcMemory, 0, 0, sizeDest.cx, sizeDest.cy, hdc, 0, 0, SRCCOPY | CAPTUREBLT);

            ::BitBlt(hdc, 0, 0, sizeDest.cx, sizeDest.cy, hdcMemory, 0, 0, SRCCOPY | CAPTUREBLT); //!

            callOk = ::UpdateLayeredWindow(hWnd, hdcScreen, nullptr, &sizeDest, hdcMemory, &pointSource, RGB(0xFF, 0xFF, 0xFF), &blend, ULW_ALPHA);

            ::SelectObject(hdcMemory, (HGDIOBJ)hbmpOld);
            ::DeleteObject((HGDIOBJ)hbmpMemory);
            ::DeleteDC(hdcMemory);
        }

        ::ReleaseDC(hWnd, hdcScreen);
    } else {
        RECT rc = { x, y, x + cx, y + cy };
        ::InvalidateRect(hWnd, &rc, FALSE);
    }
}

LRESULT CALLBACK simpleMbWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    mbWebView webview = (mbWebView)::GetProp(hWnd, L"mb");
    //mbWebView webview = (mbWebView)(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    if (webview == NULL_WEBVIEW)
        return ::DefWindowProc(hWnd, message, wParam, lParam);

    switch (message) {
    case WM_SIZE: {
        RECT rect;
        ::GetClientRect(hWnd, &rect);

        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;

        mbResize(webview, width, height);
        mbWake(webview);
    } break;

    case WM_PAINT:

        PAINTSTRUCT ps = { 0 };
        HDC hdc = ::BeginPaint(hWnd, &ps);
        ::EndPaint(hWnd, &ps);
        break;
    }
    return ::DefWindowProc(hWnd, message, wParam, lParam);
}

void createSimpleMb()
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = simpleMbWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = ::GetModuleHandle(NULL);
    wcex.hIcon = nullptr; // LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WKEXE));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = NULL;
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = CLS_WINDOW;
    wcex.hIconSm = NULL;

    RegisterClassEx(&wcex);

    mbWebView view = mbCreateWebView();
    HWND hWnd = ::CreateWindowEx(/*WS_EX_APPWINDOW*/ 0, CLS_WINDOW, NULL, WS_OVERLAPPEDWINDOW, 0, 0, 840, 680, NULL, NULL, ::GetModuleHandle(NULL), NULL);
    ::SetProp(hWnd, L"mb", (HANDLE)view);
    //::mbSetTransparent(view, true);
    ::mbSetHandle(view, hWnd);
    ::mbOnPaintUpdated(view, handlePaintUpdatedCallback, hWnd);
    //::mbOnPaintBitUpdated(view, onPaintBitUpdatedCallback, nullptr);

    //     ::mbOnDocumentReady(view, handleDocumentReady, (void*)view);
    //     ::mbOnLoadingFinish(view, handleLoadingFinish, (void*)view);
    //     ::mbOnCreateView(view, handleCreateView, (void*)view);
    //     ::mbSetNavigationToNewWindowEnable(view, true);
    //     ::mbSetCspCheckEnable(view, false);

    //hWnd = mbGetHostHWND(view);
    RECT rc = { 0 };
    ::GetClientRect(hWnd, &rc);
    ::mbResize(view, rc.right, rc.bottom);

    //mbMoveToCenter(view);
    mbShowWindow(view, TRUE);
    ::ShowWindow(hWnd, SW_SHOW);
    //mbSetHeadlessEnabled(view, TRUE);
    ::UpdateWindow(hWnd);

    //::mbLoadHTML(view, "<html><head><style></style><script type=\"text/javascript\">var test = 'test';</script></head><body></body></html>");
    //https://www.baidu.com/s?wd=123

    //char* randUrl = (char*)malloc(0x100);
    //sprintf_s(randUrl, 0x99, "https://www.baidu.com/s?wd=%d", ::GetTickCount());

    ::mbLoadURL(view, "qq.com");
    //::mbLoadURL(view, "file:///G:/mycode/mbvip/out/x86/Release/1234.htm");
    //     //::mbLoadURL(view, "file:///C:/Users/weo/AppData/Local/AllMobilize/parent.htm");
    //     //::mbLoadURL(view, "file:///E:/mycode/mtmb/Debug/guiji.htm");
    //     //::mbLoadURL(view, "https://passport.csdn.net/account/login");//http://www.17sucai.com/pins/demo-show?id=23150
    //
    //     mbOnJsQuery(view, onJsQuery, (void*)1);

    //free(randUrl);
}

#endif