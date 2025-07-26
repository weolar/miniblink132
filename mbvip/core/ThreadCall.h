#ifndef common_ThreadCall_h
#define common_ThreadCall_h

#include "mbvip/core/mb.h"
#include "base/location.h"
#include <functional>

#define MB_FROM_HERE FROM_HERE

namespace common {

using TraceLocation = ::base::Location;

class ThreadCall {
public:
    static void init(const mbSettings* settings);
    static void initTaskQueue();

    static void callBlinkThreadAsyncWithValid(const TraceLocation& caller, mbWebView webView, std::function<void(mb::MbWebView* webview)>&& closure);
    static void callBlinkThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callBlinkThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callUiThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callUiThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callMediaThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);

    static void setThreadIdle(mbThreadCallback callback, void* param1, void* param2);
    static void setBlinkThreadInited(mbThreadCallback callback, void* param1, void* param2);

    static void postNodeCoreThreadTask(const TraceLocation& caller, std::function<void(void)>&& closure);

    static void shutdown();

    static void exitUiMessageLoop();
    static void exitBlinkMessageLoop();
    static void blinkMessageLoop(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate);
    static void uiMessageLoop();

    static DWORD getUiThreadId()
    {
        return m_uiThreadId;
    }
    static DWORD getBlinkThreadId()
    {
        return m_blinkThreadId;
    }

    static uv_loop_t* getBlinkLoop()
    {
        return m_blinkLoop;
    }

    static bool isBlinkThread();
    static bool isUiThread();

    static void wake();
    static bool runNoWait(DWORD threadId);
    static bool runUntilIdle(DWORD threadId);

    static void setThreadName(const char* szThreadName);
};

}

#endif
