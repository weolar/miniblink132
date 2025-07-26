
#ifndef MbInternalApi_h
#define MbInternalApi_h

#include "mbvip/core/mb.h"

// 不知道为啥，如果在mb内部直接调用mbXXX api，在某些linux下会报错，导出表被改了
void mbDestroyWebViewImpl(mbWebView webviewHandle);
void mbShowWindowImpl(mbWebView webviewHandle, BOOL b);
BOOL mbFireMouseEventImpl(mbWebView webviewHandle, unsigned int message, int x, int y, unsigned int flags);
BOOL mbFireKeyPressEventImpl(mbWebView webviewHandle, unsigned int charCode, unsigned int flags, BOOL isSystemKey);
BOOL mbFireKeyUpEventImpl(mbWebView webviewHandle, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey);
BOOL mbFireKeyDownEventImpl(mbWebView webviewHandle, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey);
BOOL mbFireMouseWheelEventImpl(mbWebView webviewHandle, int x, int y, int wheelDelta, unsigned int flags);
BOOL mbFireWindowsMessageImpl(mbWebView webviewHandle, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result);

using FN_OutputDebugString = void(__cdecl*)(const char* str);
extern FN_OutputDebugString g_outputDebugString;
extern bool g_isDownloadVersion2;

#endif // MbInternalApi_h