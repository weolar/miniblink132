
#if 1 // ENABLE_NODEJS

//#define USING_UV_SHARED 1

#if defined(BUILDING_UV_SHARED) && defined(USING_UV_SHARED)
#error "Define either BUILDING_UV_SHARED or USING_UV_SHARED, not both."
#endif

#include "electron/nodeblink.h"
#include "electron/common/TracingControllerImpl.h"
#include "electron/common/NodeThread.h"
#include "electron/resource.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/env.h"
#include "third_party/libnode/src/env-inl.h"
#include "third_party/libnode/src/node_buffer.h"
#include "third_party/libnode/src/node_builtins.h"
#include "third_party/libnode/src/node_platform.h"
#include "third_party/libuv/include/uv.h"
#include "gin/public/isolate_holder.h"
#include "v8/include/libplatform/libplatform.h"
#if V8_MAJOR_VERSION >= 7
//#include "v8_7_5/src/libplatform/default_platform_wrap.h"
#include "v8/src/libplatform/default-platform-wrap.h"
#endif

#include <string.h>
#include <Windows.h>
#include <process.h>
#include <shellapi.h>

#pragma comment(lib, "openssl.lib")
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "Userenv.lib")
#pragma comment(lib, "Psapi.lib")

namespace node {

// static void childSignalCallback(uv_async_t* signal) {
//
// }
//
// static void workerRun(NodeArgc* nodeArgc) {
//     int err = uv_loop_init(nodeArgc->childLoop);
//     if (err != 0)
//         goto loop_init_failed;
//
//     // Interruption signal handler
//     err = uv_async_init(nodeArgc->childLoop, &nodeArgc->async, childSignalCallback);
//     if (err != 0)
//         goto async_init_failed;
//
//     //uv_unref(reinterpret_cast<uv_handle_t*>(&nodeArgc->async)); //zero 不屏蔽此句导致loop循环退出
//     nodeArgc->initType = true;
//     ::SetEvent(nodeArgc->initEvent);
//
//     {
//         if (nodeArgc->preInitcall)
//             nodeArgc->preInitcall(nodeArgc);
//
//         v8::Isolate::CreateParams params;
//         node::ArrayBufferAllocator array_buffer_allocator;
//         params.array_buffer_allocator = &array_buffer_allocator;
//         v8::Isolate *isolate = v8::Isolate::New(params);
//         v8::Isolate::Scope isolate_scope(isolate);
//         {
//             v8::HandleScope handle_scope(isolate);
//             v8::Local<v8::Context> context = v8::Context::New(isolate);
//
//             v8::Context::Scope context_scope(context);
//             nodeArgc->childEnv = node::CreateEnvironment(isolate, nodeArgc->childLoop, context, nodeArgc->argc, nodeArgc->argv, nodeArgc->argc, nodeArgc->argv);
//
//             // Expose API
//             LoadEnvironment(nodeArgc->childEnv);
//
//             if (nodeArgc->initcall)
//                 nodeArgc->initcall(nodeArgc);
//             CHECK_EQ(nodeArgc->childLoop, nodeArgc->childEnv->event_loop());
//             //uv_run(nodeArgc->childLoop, UV_RUN_DEFAULT); // 由nodeArgc->initcall里负责消息循环
//         }
//         // Clean-up all running handles
//         nodeArgc->childEnv->CleanupHandles();
//
//         nodeArgc->childEnv->Dispose();
//         nodeArgc->childEnv = nullptr;
//
//         isolate->Dispose();
//
//         delete nodeArgc->v8platform;
//         nodeArgc->v8platform = nullptr;
//     }
//     return;
//
// async_init_failed:
//     err = uv_loop_close(nodeArgc->childLoop);
//     CHECK_EQ(err, 0);
// loop_init_failed:
//     free(nodeArgc);
//     nodeArgc->initType = false;
//     ::SetEvent(nodeArgc->initEvent);
// }
//
// extern "C" NODE_EXTERN NodeArgc* nodeRunThread(int argc, const wchar_t *wargv[], NodeInitCallBack initcall, NodeInitCallBack preInitcall, void *data) {
//     NodeArgc* nodeArgc = (NodeArgc *)malloc(sizeof(NodeArgc));
//     memset(nodeArgc, 0, sizeof(NodeArgc));
//     nodeArgc->initcall = initcall;
//     nodeArgc->preInitcall = preInitcall;
//     nodeArgc->data = data;
//     nodeArgc->childLoop = (uv_loop_t *)malloc(sizeof(uv_loop_t));
//     nodeArgc->argv = new char*[argc + 1];
//     for (int i = 0; i < argc; i++) {
//         // Compute the size of the required buffer
//         DWORD size = WideCharToMultiByte(CP_UTF8, 0, wargv[i], -1, nullptr, 0, nullptr, nullptr);
//         if (size == 0)
//             ::DebugBreak();
//
//         // Do the actual conversion
//         nodeArgc->argv[i] = new char[size];
//         DWORD result = WideCharToMultiByte(CP_UTF8, 0, wargv[i], -1, nodeArgc->argv[i], size, nullptr, nullptr);
//         if (result == 0)
//             ::DebugBreak();
//     }
//     nodeArgc->argv[argc] = nullptr;
//     nodeArgc->argc = argc;
//
//     nodeArgc->v8platform = v8::platform::CreateDefaultPlatform(4);
//     gin::V8Initializer::SetV8Platform(nodeArgc->v8platform);
//
//     nodeArgc->initEvent = ::CreateEvent(NULL, FALSE, FALSE, NULL); // 创建一个对象,用来等待node环境基础环境创建成功
//     int err = uv_thread_create(&nodeArgc->thread, reinterpret_cast<uv_thread_cb>(workerRun), nodeArgc);
//     if (err != 0)
//         goto thread_create_failed;
//     ::WaitForSingleObject(nodeArgc->initEvent, INFINITE);
//     CloseHandle(nodeArgc->initEvent);
//     nodeArgc->initEvent = NULL;
//     if (!nodeArgc->initType)
//         goto thread_init_failed;
//     return nodeArgc;
//
// thread_init_failed:
//
// thread_create_failed:
//     free(nodeArgc);
//     return nullptr;
// }
//
// extern "C" NODE_EXTERN Environment* nodeGetEnvironment(NodeArgc* nodeArgc) {
//     if (nodeArgc)
//         return nodeArgc->childEnv;
//     return nullptr;
// }

} // node

extern "C" NODE_EXTERN void* nodeCreateDefaultPlatform()
{
#if V8_MAJOR_VERSION >= 7
    gin::DefaultPlatformWrap* defaultPlatform = new gin::DefaultPlatformWrap();
    v8::Platform* v8platform = defaultPlatform->GetPlatform();
#else
    v8::Platform* v8platform = v8::platform::CreateDefaultPlatform(1);
#endif
    //gin::V8Initializer::SetV8Platform(v8platform);
    return v8platform;
}

static void waitForEnvironmentHandleWrapQueue(node::Environment* env)
{
    while (true) {
        uv_run(env->event_loop(), UV_RUN_NOWAIT);

        int emptyCount = 0;
        int allCount = 0;
        node::Environment::HandleWrapQueue::Iterator it = env->handle_wrap_queue()->begin();
        for (; it != env->handle_wrap_queue()->end(); ++it, ++allCount) {
            node::HandleWrap* wrap = (*it);
            v8::Local<v8::Object> obj = wrap->object();
            bool b = obj.IsEmpty();
            if (b)
                ++emptyCount;
        }
        if (emptyCount == allCount)
            break;
    }
    if (!env->handle_wrap_queue()->IsEmpty())
        DebugBreak();
}

static void handleCloseCb(uv_handle_t* handle)
{
    int* closingHandleCount = (int*)handle->data;
    ++(*closingHandleCount);
}

static void closeWalkCB(uv_handle_t* handle, void* arg)
{
    int* closeHandleCount = (int*)arg;

    if (!uv_is_closing(handle)) {
        ++(*closeHandleCount);
        handle->data = closeHandleCount + 1;
        uv_close(handle, handleCloseCb);
    }
}

static void waitForAllHandleWrapQueue(node::Environment* env)
{
    int closeHandleCount[2] = { 0, 0 };
    uv_walk(env->event_loop(), closeWalkCB, &closeHandleCount);

    while (closeHandleCount[0] != closeHandleCount[1])
        uv_run(env->event_loop(), UV_RUN_NOWAIT);
}

extern "C" NODE_EXTERN void nodeDeleteNodeEnvironment(node::Environment* env)
{
    //env->CleanupHandles();
    //waitForEnvironmentHandleWrapQueue(env);

    //waitForAllHandleWrapQueue(env);
    //env->Dispose();
    //delete env;
    node::FreeEnvironment(env);
}

extern "C" NODE_EXTERN BlinkMicrotaskSuppressionHandle nodeBlinkMicrotaskSuppressionEnter(v8::Isolate* isolate)
{
    //return new blink::V8RecursionScope::MicrotaskSuppression(isolate);
    return nullptr;
}

extern "C" NODE_EXTERN void nodeBlinkMicrotaskSuppressionLeave(BlinkMicrotaskSuppressionHandle handle)
{
    //blink::V8RecursionScope::MicrotaskSuppression* suppression = (blink::V8RecursionScope::MicrotaskSuppression*)handle;
    //delete suppression;
}

struct MemoryHead {
    size_t magicNum;
    size_t size;
};

static const size_t magicNum0 = 0x99223321;
static const size_t magicNum1 = 0x89223321;

extern "C" NODE_EXTERN void* nodeBlinkAllocateUninitialized(size_t length)
{
    return node::Malloc<char>(length);
    //     MemoryHead* head = (MemoryHead*)malloc(length + sizeof(MemoryHead));
    //     head->magicNum = magicNum0;
    //     head->size = length;
    //     return head + 1;
}

extern "C" NODE_EXTERN void nodeBlinkFree(void* data, size_t length)
{
    node::Realloc<char>((char*)data, 0);
    //     MemoryHead* head = (MemoryHead*)data;
    //     --head;
    //     if (head->magicNum != magicNum0 || head->size != length)
    //         DebugBreak();
    //     head->magicNum = magicNum1;
    //     free(head);
}

extern "C" void node_module_init_register();

extern "C" NODE_EXTERN void nodeModuleInitRegister()
{
    //node_module_init_register();
}

//////////////////////////////////////////////////////////////////////////
void testReadFile(const wchar_t* path, std::vector<char>* buffer);

static uv_loop_t* s_uvLoop = nullptr;
static v8::Platform* s_v8platform = nullptr;

bool isNodejsEnable()
{
    return !!s_uvLoop;
}

void enableNodejs()
{
    if (s_uvLoop)
        return;

    nodeModuleInitRegister();

    s_uvLoop = (uv_loop_t*)malloc(sizeof(uv_loop_t));
    uv_loop_init(s_uvLoop);

    s_v8platform = (v8::Platform*)nodeCreateDefaultPlatform();
}

static void bindFuncToProcessObj(v8::Isolate* isolate, v8::Local<v8::Context> context, node::Environment* env, const char* name, v8::FunctionCallback callback)
{
    v8::Local<v8::Function> func = v8::FunctionTemplate::New(isolate, callback)->GetFunction(context).ToLocalChecked();
    const v8::NewStringType type = v8::NewStringType::kInternalized;
    v8::Local<v8::String> nameString = v8::String::NewFromUtf8(isolate, name, type).ToLocalChecked();
    env->process_object()->Set(context, nameString, func);
    func->SetName(nameString);
}

static void getPreloadScript(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    //     std::vector<char> buffer;
    //     testReadFile(L"G:\\mycode\\mb\\node\\lib\\renderinit.js", &buffer);
    //     buffer.push_back('\0');

    const char* data = (const char*)node::render_init_native;
    size_t size = sizeof(node::render_init_native);

    v8::Isolate* isolate = info.GetIsolate();
    const v8::NewStringType type = v8::NewStringType::kInternalized;
    v8::Local<v8::String> nameString = v8::String::NewFromUtf8(isolate, data, type, size).ToLocalChecked();
    info.GetReturnValue().Set(nameString);
}

void nodeWillReleaseScriptContext(NodeBindingInMbCore* nodebinding)
{
    node::FreeEnvironment((node::Environment*)nodebinding->env);
    delete nodebinding;
}

node::Environment* nodeCreateEnvironment(void* isolateData, void* ctx, const void* args, const void* execArgs, int flags)
{
    v8::Local<v8::Context>* context = (v8::Local<v8::Context>*)ctx;
    const std::vector<std::string>* argsPtr = (const std::vector<std::string>*)args;
    const std::vector<std::string>* execArgsPtr = (const std::vector<std::string>*)execArgs;

    return node::CreateEnvironment((node::IsolateData*)(isolateData), *context, *argsPtr, *execArgsPtr, (node::EnvironmentFlags::Flags)(flags));
}

v8::Local<v8::Object> nodeGetEnvironmentProcessObject(node::Environment* env)
{
    return env->process_object();
}

node::Environment* nodeEnvironmentGetCurrent(v8::Isolate* isoloate)
{
    return node::Environment::GetCurrent(isoloate);
}

v8::Isolate* nodeEnvironmentGetV8Isolate(node::Environment* env)
{
    return env->isolate();
}

v8::Local<v8::Context> nodeEnvironmentGetV8Context(node::Environment* env)
{
    return env->context();
}

node::Environment* nodeEnvironmentGetByV8Context(v8::Local<v8::Context> context)
{
    return node::Environment::GetCurrent(context);
}

void nodeEnvironmentSetIsblinkCore(node::Environment* env)
{
    env->set_is_blink_core();
}

void nodeEnvironmentAddCustomArgs(node::Environment* env, const std::vector<std::string>& argv)
{
    if (!argv.empty())
        env->AddCustomArgs(argv);
}

// look: ElectronBrowserMainParts::PostEarlyInitialization
void nodeEnvironmentElectronPostEarlyInitialization(node::Environment* env)
{
    // We do not want to crash the main process on unhandled rejections.
    env->options()->unhandled_rejections = "warn";
    //env->options()->trace_uncaught = true;
    //env->options()->trace_warnings = true;
}

void nodeAddElectronRequire(node::Environment* env)
{
    node::builtins::BuiltinLoader* loader = env->builtin_loader();
    node::StaticExternalOneByteResource resource((const uint8_t*)" ", 2, nullptr);
    //loader->Add("electron", node::UnionBytes(&resource));
}

// 给mb自己用的，不导出dll。可以让mb的js环境带上nodejs的api
// NodeBindingInMbCore* nodeBindNodejsOnDidCreateScriptContext(void* webView, void* frameId, void* ctx)
// {
//     v8::Local<v8::Context>* context = (v8::Local<v8::Context>*)ctx;
//
//     BlinkMicrotaskSuppressionHandle handle = nodeBlinkMicrotaskSuppressionEnter((*context)->GetIsolate());
//     NodeBindingInMbCore* binding = new NodeBindingInMbCore();
//
//     int argc = 0;
//     int argsArrayNum = 0;
//     char16_t** argvW = (char16_t**)::CommandLineToArgvW(::GetCommandLineW(), &argc);
//     char** argsArray = (char**)malloc((argc + 1) * sizeof(char**));
//     memset(argsArray, 0, argc * sizeof(char**));
//
//     for (int i = 0; i < argc; ++i) {
//         std::u16string arg = argvW[i];
//         if (arg.length() > 0 && arg[0] >= L'a' && arg[0] <= L'z')
//             arg[0] += L'A' - L'a';
//
//         std::string argUtf8 /*= base::UTF16ToUTF8(arg)*/;
//         if (std::string::npos != argUtf8.find("use_res_url")) // 测试demo会有这个命令行。
//             continue;
//
//         argsArray[argsArrayNum] = strdup(argUtf8.c_str());
//         ++argsArrayNum;
//     }
// //     argsArray[argsArrayNum] = strdup("G:\\mycode\\mb\\node\\lib\\renderinit.js");
// //     ++argsArrayNum;
//
//     v8::Isolate* isolate = (*context)->GetIsolate();
//
//     //CreateEnvironment(IsolateData * isolate_data, v8::Local<v8::Context> context, const std::vector<std::string>&args,
//     //    const std::vector<std::string>&exec_args, EnvironmentFlags::Flags flags = EnvironmentFlags::kDefaultFlags,
//     //    ThreadId thread_id = {} /* allocates a thread id automatically */, std::unique_ptr<InspectorParentHandle> inspector_parent_handle = {});
//
//     binding->tracingControllerImpl = new atom::TracingControllerImpl();
//
//     node::MultiIsolatePlatform* multiIsolatePlatform = node::CreatePlatform(base::RecommendedMaxNumberOfThreadsInThreadGroup(3, 8, 0.1, 0),
//         (v8::TracingController*)binding->tracingControllerImpl);
//     multiIsolatePlatform->RegisterIsolate(isolate, s_uvLoop);
//     binding->multiIsolatePlatform = multiIsolatePlatform;
//
//     binding->isolateData = node::CreateIsolateData(isolate, s_uvLoop, (node::MultiIsolatePlatform*)binding->multiIsolatePlatform);
//
//     uint64_t flags =
//         //node::EnvironmentFlags::kDefaultFlags |
//         node::EnvironmentFlags::kOwnsProcessState |
//         node::EnvironmentFlags::kHideConsoleWindows |
//         node::EnvironmentFlags::kNoGlobalSearchPaths;
//     std::vector<std::string> args;
//     std::vector<std::string> execArgs;
//     binding->env = node::CreateEnvironment((node::IsolateData*)(binding->isolateData), *context, args, execArgs,
//         static_cast<node::EnvironmentFlags::Flags>(flags));
//
//     node::Environment* env = (node::Environment*)binding->env;
//
//     bindFuncToProcessObj(isolate, context, env, "_isInElectronEnv", isInElectronEnv);
//     bindFuncToProcessObj(isolate, context, env, "_getPreloadScript", getPreloadScript);
//
//     node::LoadEnvironment(env, node::StartExecutionCallback{});
//
//     nodeBlinkMicrotaskSuppressionLeave(handle);
//
// //     std::vector<char> buffer;
// //     readFile(L"G:\\mycode\\mb\\node\\lib\\renderinit.js", &buffer);
// //     buffer.push_back('\0');
// //     wkeRunJsByFrame((wkeWebView)webView, (wkeWebFrameHandle)frameId, buffer.data(), false);
//
//     for (int i = 0; i < argsArrayNum; ++i) {
//         if (argsArray[i])
//             free(argsArray[i]);
//     }
//     free(argsArray);
//
//     return binding;
// }

void nodeRunNoWait()
{
    if (!s_uvLoop)
        return;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    BlinkMicrotaskSuppressionHandle handle = nodeBlinkMicrotaskSuppressionEnter(isolate);
    bool more = (0 != uv_run(s_uvLoop, UV_RUN_NOWAIT));
    nodeBlinkMicrotaskSuppressionLeave(handle);

    if (s_v8platform && isolate)
        v8::platform::PumpMessageLoop(s_v8platform, isolate);
}

char* nodeBufferGetData(void* buf, size_t* len)
{
    v8::Local<v8::Value>* val = (v8::Local<v8::Value>*)buf;
    char* data = node::Buffer::Data(*val);
    *len = node::Buffer::Length(*val);
    return data;
}

std::shared_ptr<v8::TaskRunner> nodePlatformGetForegroundTaskRunner(v8::Isolate* isolate)
{
    return atom::g_nodeArgc->m_nodeMultiIsolatePlatform->GetForegroundTaskRunner(isolate);
}

bool nodePlatformIdleTasksEnabled(v8::Isolate* isolate)
{
    return atom::g_nodeArgc->m_nodeMultiIsolatePlatform->IdleTasksEnabled(isolate);
}

#endif // ENABLE_NODEJS