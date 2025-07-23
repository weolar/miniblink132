
#include "content/browser/SharedTimerWin.h"
// #include "content/web_impl_win/WebThreadImpl.h"
// #include "content/browser/CheckReEnter.h"
#include "base/run_loop.h"
#if ENABLE_NODEJS
#include "node/nodeblink.h"
#endif

#include <windows.h>
#include <mmsystem.h>

extern "C" long MB_InterlockedExchange(long volatile* _Target, long _Value);
extern "C" long MB_InterlockedIncrement(long volatile* _Target);
void nodeRunNoWait();

extern base::RunLoop* g_mainThreadRunLoop;

// These aren't in winuser.h with the MSVS 2003 Platform SDK,
// so use default values in that case.
#ifndef USER_TIMER_MINIMUM
#define USER_TIMER_MINIMUM 0x0000000A
#endif

#ifndef USER_TIMER_MAXIMUM
#define USER_TIMER_MAXIMUM 0x7FFFFFFF
#endif

#ifndef QS_RAWINPUT
#define QS_RAWINPUT 0x0400
#endif

typedef HANDLE(WINAPI* PfnCreateTimerQueue)();
typedef BOOL(WINAPI* PfnDeleteTimerQueueTimer)(HANDLE TimerQueue, HANDLE Timer, HANDLE CompletionEvent);
typedef BOOL(WINAPI* PfnCreateTimerQueueTimer)(
    HANDLE* phNewTimer, HANDLE TimerQueue, void* Callback, PVOID Parameter, DWORD DueTime, DWORD Period, ULONG Flags);

PfnCreateTimerQueue pCreateTimerQueue = nullptr;
PfnDeleteTimerQueueTimer pDeleteTimerQueueTimer = nullptr;
PfnCreateTimerQueueTimer pCreateTimerQueueTimer = nullptr;

#ifndef NO_USE_ORIG_CHROME

namespace base {
extern DWORD s_disableDispatchMessageReentry;
}

#endif

namespace content {

typedef void(WINAPI* PfnUiThreadHeartbeatCallback)();
PfnUiThreadHeartbeatCallback g_uiThreadHeartbeatCallback = nullptr;

const LPCWSTR kTimerWindowClassName = L"MiniBlinkTimerWindowClass";

static UINT s_timerID;
static void sharedTimerFiredFunction();

static HANDLE s_timer;
static HWND s_timerWindowHandle = 0;

static UINT s_timerFiredMessage = 0;
static HANDLE s_timerQueue;
static HANDLE s_timerThreadHandle = nullptr;
static bool s_highResTimerActive;
static bool s_processingCustomTimerMessage = false;
static long s_pendingTimers = 0;
static double s_lastIntervalInMS = 0;

static long s_pendingSharedTimers = 0;

const int kTimerResolution = 1; // To improve s_timer resolution, we call timeBeginPeriod/timeEndPeriod with this value to increase s_timer resolution to 1ms.
const int kHighResolutionThresholdMsec
    = 16; // Only activate high-res s_timer for sub-16ms timers (Windows can fire timers at 16ms intervals without changing the system resolution).
const int kStopHighResTimerInMsec
    = 300; // Stop high-res s_timer after 0.3 seconds to lessen power consumption (we don't use a smaller time since oscillating between high and low resolution breaks s_timer accuracy on XP).

enum {
    sharedTimerID = 1000,
    endHighResTimerID = 1001,
    lowResTimerID = 1002,
};
DWORD s_timerWindowWndProcThreadId = 0;

static void initializeOffScreenTimerWindow();
const bool kShouldUseHighResolutionTimers = true;
const bool kShouldUseHighResolutionThreadTimers = true;

static LRESULT CALLBACK timerWindowWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (s_timerWindowWndProcThreadId != ::GetCurrentThreadId()) // win10好像有bug，会意外的在别的线程本函数被调用
        return 0;

    LRESULT result = 0;
    if (message == WM_TIMER) {
        if (wParam == sharedTimerID) {
            MB_InterlockedExchange((long*)&s_pendingSharedTimers, 0);

            if (kShouldUseHighResolutionTimers)
                ::KillTimer(s_timerWindowHandle, sharedTimerID);
            sharedTimerFiredFunction();
        } else if (wParam == endHighResTimerID) {
            if (kShouldUseHighResolutionTimers)
                ::KillTimer(s_timerWindowHandle, endHighResTimerID);
            s_highResTimerActive = false;
            timeEndPeriod(kTimerResolution);
        } else if (wParam == lowResTimerID) {
            sharedTimerFiredFunction();
        }
    } else if (message == s_timerFiredMessage || WM_NULL == message) {
        MB_InterlockedExchange((long*)&s_pendingTimers, 0);
        s_processingCustomTimerMessage = true;
        sharedTimerFiredFunction();
        s_processingCustomTimerMessage = false;
    } else
        result = ::DefWindowProcW(hWnd, message, wParam, lParam);

    return result;
}

static void sharedTimerFiredFunction()
{
#if 0 // ndef NO_USE_ORIG_CHROME
    if (base::s_disableDispatchMessageReentry == ::GetCurrentThreadId())
        return;
#endif
    //     if (0 != CheckReEnter::getEnterCount())
    //         return;
    //     CheckReEnter::incrementEnterCount();
    static int s_enterCount = 0;
    if (0 != s_enterCount)
        return;
    s_enterCount++;

#if ENABLE_NODEJS
    nodeRunNoWait();
#endif
    //     content::WebThreadImpl* threadImpl = nullptr;
    //     threadImpl = (content::WebThreadImpl*)(blink::Platform::current()->currentThread());
    //     threadImpl->fire();

    g_mainThreadRunLoop->RunUntilIdle();
    --s_enterCount;
    //CheckReEnter::decrementEnterCount();
}

static void WINAPI queueTimerProc(PVOID, BOOLEAN)
{
    if (s_pendingTimers > 100000) // 太大说明主线程卡死了
        return;
    if (MB_InterlockedIncrement((long*)&s_pendingTimers) == 1)
        ::PostMessageW(s_timerWindowHandle, /*s_timerFiredMessage*/ WM_NULL, s_timerFiredMessage, s_timerFiredMessage);
}

static DWORD WINAPI threadTimerProc(void* param)
{
    DWORD displayFrequency = 16;

#if defined(OS_WIN)
    HMONITOR monitor = ::MonitorFromWindow(NULL, MONITOR_DEFAULTTONEAREST);
    MONITORINFOEXW monitorInfo;
    monitorInfo.cbSize = sizeof(MONITORINFOEX);
    BOOL result = ::GetMonitorInfo(monitor, &monitorInfo);
    if (result) {
        DEVMODE displayInfo;
        displayInfo.dmSize = sizeof(DEVMODE);
        displayInfo.dmDriverExtra = 0;
        result = ::EnumDisplaySettings(monitorInfo.szDevice, ENUM_CURRENT_SETTINGS, &displayInfo);
        if (result && displayInfo.dmDisplayFrequency > 1)
            displayFrequency = (DWORD)(1000 / displayInfo.dmDisplayFrequency);
    }
#endif
    while (true) {
        queueTimerProc(nullptr, false);

        if (g_uiThreadHeartbeatCallback)
            g_uiThreadHeartbeatCallback();

        ::Sleep(displayFrequency);
    }
}

void setSharedTimerFireInterval(double interval)
{
    unsigned intervalInMS;
    interval *= 1000;
    if (interval > USER_TIMER_MAXIMUM)
        intervalInMS = USER_TIMER_MAXIMUM;
    else
        intervalInMS = static_cast<unsigned>(interval);

    if (s_lastIntervalInMS == intervalInMS)
        return;
    s_lastIntervalInMS = intervalInMS;
    bool isTimerSet = false;

    initializeOffScreenTimerWindow();

#if defined(OS_WIN)
    if (!s_timerThreadHandle) {
        DWORD threadIdentifier = 0;
        s_timerThreadHandle = ::CreateThread(0, 0, threadTimerProc, nullptr, 0, &threadIdentifier);
    }
#endif
}

void stopSharedTimer()
{
    if (s_timerQueue && s_timer) {
        ::pDeleteTimerQueueTimer(s_timerQueue, s_timer, 0);
        s_timer = 0;
    }

    if (s_timerID) {
        ::KillTimer(s_timerWindowHandle, s_timerID);
        s_timerID = 0;
    }

    ::DestroyWindow(s_timerWindowHandle);
    ::UnregisterClassW(kTimerWindowClassName, NULL);
}

static void initializeOffScreenTimerWindow()
{
#if defined(OS_WIN)
    if (s_timerWindowHandle)
        return;
    s_timerWindowWndProcThreadId = ::GetCurrentThreadId();

    HMODULE hMod = GetModuleHandleW(L"Kernel32.dll");
    pCreateTimerQueue = (PfnCreateTimerQueue)::GetProcAddress(hMod, "CreateTimerQueue");
    pDeleteTimerQueueTimer = (PfnDeleteTimerQueueTimer)::GetProcAddress(hMod, "DeleteTimerQueueTimer");
    pCreateTimerQueueTimer = (PfnCreateTimerQueueTimer)::GetProcAddress(hMod, "CreateTimerQueueTimer");

    WNDCLASSEXW wcex = { 0 };
    wcex.cbSize = sizeof(WNDCLASSEXW);
    wcex.lpfnWndProc = timerWindowWndProc;
    wcex.hInstance = ::GetModuleHandleW(NULL);
    wcex.lpszClassName = kTimerWindowClassName;
    ::RegisterClassExW(&wcex);

    s_timerWindowHandle = CreateWindowExW(0, // window ex-style
        kTimerWindowClassName, // window class name
        L"OffScreenTimer", // window caption
        WS_POPUP, // window style
        1, // initial x position
        1, // initial y position
        1, // initial x size
        1, // initial y size
        NULL, // parent window handle
        NULL, // window menu handle
        GetModuleHandleW(NULL), // program instance handle
        NULL); // creation parameters
    //::SetTimer(s_timerWindowHandle, (UINT_PTR)s_timerWindowHandle, 50, 0);

    s_timerFiredMessage = ::RegisterWindowMessageW(L"com.weolar.Miniblink.TimerFired");
    //::SetTimer(s_timerWindowHandle, lowResTimerID, 16, 0);
#endif
}

}