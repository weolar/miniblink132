#ifndef common_ThreadCall_h
#define common_ThreadCall_h

#include "mbvip/core/mb.h"
#include "base/location.h"
#include "base/memory/scoped_refptr.h"
#include "base/task/single_thread_task_runner.h"
#include "base/threading/platform_thread.h"
#include <functional>

#define MB_FROM_HERE FROM_HERE

typedef struct uv_loop_s uv_loop_t;

namespace v8 {
class Platform;
class Isolate;
}

namespace content {

using TraceLocation = ::base::Location;
struct TaskAsyncData;
class MbWebView;

class ThreadCall {
public:
    static void init(const mbSettings* settings);
    static void initializeWebKit();
    static void initTaskQueue();
    static bool isInitUiThread();
    static void exitUiThreadMessageLoop();

    static void callBlinkThreadAsyncWithValid(const TraceLocation& caller, mbWebView webView, std::function<void(MbWebView* webview)>&& closure);
    static void callBlinkThreadAsyncWithValidDelayed(const TraceLocation& caller, mbWebView webView, size_t millisecond, std::function<void(MbWebView* webview)>&& closure);
    static void callBlinkThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callBlinkThreadDelayed(const TraceLocation& caller, std::function<void(void)>&& closure, size_t millisecond);
    static void callBlinkThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callUiThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callUiThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callUiThreadDelayed(const TraceLocation& caller, std::function<void(void)>&& closure, size_t millisecond);
    static void callMediaThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);

    static void runUiThreadMessageLoop(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate);
    static void runBlinkThreadNode(uv_loop_t* loop, v8::Isolate* isolate);

    template <typename Ty> static void delayDestroySelf(Ty* self, scoped_refptr<base::SingleThreadTaskRunner> runner, int microseconds)
    {
        if (0 == microseconds)
            runner->PostTask(FROM_HERE, base::BindOnce([](Ty* self) { delete self; }, base::Unretained(self)));
        else 
            runner->PostDelayedTask(FROM_HERE, base::BindOnce([](Ty* self) { delete self; }, base::Unretained(self)), base::Microseconds(microseconds));
    }

    static void setThreadIdle(mbThreadCallback callback, void* param1, void* param2);
    static void setBlinkThreadInited(mbThreadCallback callback, void* param1, void* param2);

    static void postNodeCoreThreadTask(const TraceLocation& caller, std::function<void(void)>&& closure);

    static void shutdown();

    static void exitUiMessageLoop();
    static void exitBlinkMessageLoop();
    //static void blinkMessageLoop(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate);
    static void uiMessageLoop();

//     static DWORD getUiThreadId() { return m_uiThreadId; }
//     static DWORD getBlinkThreadId() { return m_blinkThreadId; }
// 
//     static uv_loop_t* getBlinkLoop() { return m_blinkLoop; }

    static bool isBlinkThread();
    static bool isUiThread();

    static void wake();
    static bool runNoWait(DWORD threadId);
    static bool runUntilIdle(DWORD threadId);

    static void setThreadName(const char* szThreadName);

    static uv_loop_t* getBlinkLoop() { return m_blinkUvLoop; }

private:
    static void callThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure, scoped_refptr<base::SingleThreadTaskRunner> runner);
    static bool waitForCallThreadAsync(TaskAsyncData* asyncData);

    static void onThreadIdle(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate);

    ThreadCall();
    static ThreadCall* m_inst;
    scoped_refptr<base::SingleThreadTaskRunner> m_uiThreadTask;

    static uv_loop_t* m_uiUvLoop;
    static v8::Platform* m_UiV8Platform;

    static uv_loop_t* m_blinkUvLoop;

    base::PlatformThreadId m_uiThreadId = 0;
};

}

#endif
