
#include "electron/common/NodeThread.h"

#include "electron/common/NodeBinding.h"
#include "content/common/ThreadCall.h"
#include "electron/common/TracingControllerImpl.h"
#include "electron/nodeblink.h"
#include "third_party/libnode/src/node_platform.h"
#include "v8/include/libplatform/libplatform.h"
//#include "third_party/zlib/unzip.h"
#include "electron/common/AtomVersion.h"
#include "gin/v8_initializer.h"
#include "gin/public/isolate_holder.h"
#include "base/command_line.h"
#include "base/task/sequenced_task_runner.h"
#include "base/task/thread_pool/initialization_util.h"
#include "base/threading/platform_thread.h"

#include <string.h>
#include <Windows.h>
#include <process.h>
#include <objbase.h>

namespace node {
extern bool g_is_in_electron;
}

namespace atom {

base::PlatformThreadId g_mainThreadId;

bool isMainThread()
{
    return g_mainThreadId == base::PlatformThread::CurrentId();
}

static void childSignalCallback(uv_async_t* signal)
{
}

// class ElectronFsHooks : public node::Environment::FileSystemHooks {
//     virtual bool internalModuleStat(const char* path, int* rc) override
//     {
//         *rc = 1;
//         return false;
//     }
//
//     void open()
//     {
//     }
// };

class ArrayBufferAllocator : public v8::ArrayBuffer::Allocator {
public:
    ArrayBufferAllocator()
    {
    }

    virtual void* Allocate(size_t size)
    {
        void* p = AllocateUninitialized(size);
        memset(p, 0, size);
        return p;
    }

    virtual void* AllocateUninitialized(size_t size)
    {
        if (!content::ThreadCall::isUiThread())
            DebugBreak();
        return nodeBlinkAllocateUninitialized(size);
    }

    virtual void Free(void* data, size_t size)
    {
        nodeBlinkFree(data, size);
    }
};

static uv_timer_t* s_gcTimer = new uv_timer_t();

static void gcTimerCallBack(uv_timer_t* handle)
{
    uv_timer_stop(s_gcTimer);
    uv_timer_start(s_gcTimer, gcTimerCallBack, 1000 * 20, 1);

    v8::Isolate* isolate = (v8::Isolate*)(handle->data);
    if (isolate)
        isolate->LowMemoryNotification();
}

static void runUiMessageLoop(NodeArgc* n)
{
    content::ThreadCall::runUiThreadMessageLoop(n->uiThreadNodeEnv.uvLoop, n->uiThreadNodeEnv.v8platform, n->m_isolate);
}

static void initUiThread(NodeArgc* n)
{
    base::PlatformThread::SetName("NodeCoreAndUi");
    v8::V8::SetFlagsFromString("--no-freeze-flags-after-init");
    uv_loop_t* loop = n->uiThreadNodeEnv.uvLoop;
    mbInit(nullptr);

    g_mainThreadId = base::PlatformThread::CurrentId();

    s_gcTimer = new uv_timer_t();
    uv_timer_init(loop, s_gcTimer);
    uv_timer_start(s_gcTimer, gcTimerCallBack, 1000 * 20, 1);
}

static v8::Isolate* initNodeEnvAndRunLoop(NodeArgc* nodeArgc)
{
    initUiThread(nodeArgc);
    //     ElectronFsHooks fsHooks;
    //     nodeArgc->childEnv->file_system_hooks(&fsHooks);
    NodeBindings::initNodeEnv();

    nodeArgc->uiThreadNodeEnv.isolateHolder
        = new gin::IsolateHolder(base::SingleThreadTaskRunner::GetCurrentDefault(), gin::IsolateHolder::IsolateType::kUtility);
    v8::Isolate* isolate = nodeArgc->uiThreadNodeEnv.isolateHolder->isolate();

    node::IsolateSettings isolateSettings;
    node::SetIsolateUpForNode(isolate, isolateSettings);

    v8::Isolate::Scope isolateScope(isolate);
    {
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> context = v8::Context::New(isolate);
        v8::Context::Scope contextScope(context);
        bindMbConsoleLog(context);

        nodeArgc->m_nodeMultiIsolatePlatform
            = node::CreatePlatform(base::RecommendedMaxNumberOfThreadsInThreadGroup(3, 8, 0.1, 0), new TracingControllerImpl());

        node::Environment* env = nodeArgc->m_nodeBinding->createEnvironment(context);
        nodeArgc->uiThreadNodeEnv.env = env;
        nodeAddElectronRequire(env);
        nodeArgc->m_nodeBinding->loadEnvironment(env);
        nodeArgc->m_nodeBinding->setUvEnv(env);
        //nodeArgc->m_nodeBinding->patchProcessObject(env);
        nodeArgc->m_isolate = isolate;
        s_gcTimer->data = isolate;
        runUiMessageLoop(nodeArgc);
    }

    return isolate;
}

static void uiThreadRun(NodeArgc* nodeArgc)
{
    //node::g_is_in_electron = true;
    int err = 0;
    nodeArgc->uiThreadNodeEnv.uvLoop = uv_default_loop();
    nodeArgc->m_nodeBinding->setUvLoop(nodeArgc->uiThreadNodeEnv.uvLoop);

    ::OleInitialize(nullptr);

    // Interruption signal handler
    err = uv_async_init(nodeArgc->uiThreadNodeEnv.uvLoop, &nodeArgc->async, childSignalCallback);
    if (err != 0) {
        err = uv_loop_close(nodeArgc->uiThreadNodeEnv.uvLoop);
        //CHECK_EQ(err, 0);
        free(nodeArgc);
        nodeArgc->initType = false;
        //::SetEvent(nodeArgc->initEvent);
        return;
    }
    //uv_unref(reinterpret_cast<uv_handle_t*>(&nodeArgc->async)); //zero 不屏蔽此句导致loop循环退出

    nodeArgc->initType = true;
    //::SetEvent(nodeArgc->initEvent);

    nodeArgc->uiThreadNodeEnv.v8platform = (v8::Platform*)nodeCreateDefaultPlatform();
    //ThreadCall::createBlinkThread(nodeArgc->v8platform);

    [[maybe_unused]] v8::Isolate* isolate = initNodeEnvAndRunLoop(nodeArgc);

    OutputDebugStringA("env->CleanupHandles not impl\n");
    //nodeArgc->uiThreadNodeEnv.env->CleanupHandles(); // Clean-up all running handles
    //delete nodeArgc->uiThreadNodeEnv.env;//nodeArgc->childEnv->Dispose();
    //nodeArgc->uiThreadNodeEnv.env = nullptr;
    //isolate->Dispose();
}

NodeArgc* g_nodeArgc = nullptr;

NodeArgc* runNodeThread()
{
    //MessageBoxA(0, "runNodeThread", 0, 0);
    //NodeArgc* nodeArgc = (NodeArgc*)malloc(sizeof(NodeArgc));
    NodeArgc* nodeArgc = new NodeArgc();
    g_nodeArgc = nodeArgc;
    // memset(nodeArgc, 0, sizeof(NodeArgc));
    // nodeArgc->childLoop = (uv_loop_t*)malloc(sizeof(uv_loop_t));

    nodeArgc->m_nodeBinding = new NodeBindings(true /*, nodeArgc->childLoop*/);

    uiThreadRun(nodeArgc);
    //     nodeArgc->initEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL); // 创建一个对象,用来等待node环境基础环境创建成功
    //     int err = uv_thread_create(&nodeArgc->thread, reinterpret_cast<uv_thread_cb>(workerRun), nodeArgc);
    //     if (err != 0)
    //         goto thread_create_failed;
    //     ::WaitForSingleObject(nodeArgc->initEvent, INFINITE);
    //     ::CloseHandle(nodeArgc->initEvent);
    //     nodeArgc->initEvent = NULL;
    //
    //     if (!nodeArgc->initType)
    //         goto thread_init_failed;
    //     return nodeArgc;
    //
    // thread_init_failed:
    //
    // thread_create_failed:
    free(nodeArgc);
    return nullptr;
}

node::Environment* nodeGetEnvironment(NodeArgc* nodeArgc)
{
    if (nodeArgc)
        return nodeArgc->uiThreadNodeEnv.env;
    return nullptr;
}

} // atom

// #include "node/src/debug-agent.h"
//
// namespace node {
// namespace debugger {
//
// Agent::~Agent(void)
// {
//     Stop();
//     uv_sem_destroy(&start_sem_);
//
//     while (AgentMessage* msg = messages_.PopFront())
//         delete msg;
// }
//
// void Agent::Stop()
// {
//     if (state_ != kRunning)
//         return;
//
//     DebugBreak();
//     state_ = kNone;
// }
//
// } // debugger
// } // node