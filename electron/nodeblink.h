#ifndef _NODEBLINK_H_
#define _NODEBLINK_H_

#if 1 // ENABLE_NODEJS

#define NODE_ARCH "ia32"
#define NODE_PLATFORM "win32"
#define NODE_WANT_INTERNALS 1
#define HAVE_OPENSSL 1
#define HAVE_ETW 1
#define HAVE_PERFCTR 1
#define V8_INSPECTOR_USE_STL 1
//#define NODE_USE_V8_PLATFORM 1
//#define USING_V8_SHARED 0
//#define USING_UV_SHARED 0
//#define BUILDING_UV_SHARED 1
#define CARES_BUILDING_LIBRARY 0

// #include "node/src/node.h"
// #include "node/src/env.h"
// #include "node/src/env-inl.h"
// #include "node/uv/include/uv.h"
#include "v8.h"

#ifdef _WIN32
#ifndef BUILDING_NODE_EXTENSION
#define NODE_EXTERN __declspec(dllexport)
#else
#define NODE_EXTERN __declspec(dllimport)
#endif
#else
#define NODE_EXTERN /* nothing */
#endif

namespace node {
class Environment;
}

namespace v8 {
class Isolate;
}

struct NodeNative {
    const char* name;
    const char* source;
    size_t sourceLen;
};

// 原本这些函数是属于不同dll里，所以要导出成c接口。后来目的变了，变成为了隔离nodejs的头文件和chromium base的头文件冲突的目的
extern "C" NODE_EXTERN void* nodeCreateDefaultPlatform();
extern "C" NODE_EXTERN void nodeDeleteNodeEnvironment(node::Environment* env);

extern "C" NODE_EXTERN node::Environment* nodeCreateEnvironment(void* isolate_data, void* context, const void* args, const void* execArgs, int flags);

v8::Local<v8::Object> nodeGetEnvironmentProcessObject(node::Environment* env);
node::Environment* nodeEnvironmentGetCurrent(v8::Isolate* isoloate);
v8::Isolate* nodeEnvironmentGetV8Isolate(node::Environment* env);
v8::Local<v8::Context> nodeEnvironmentGetV8Context(node::Environment* env);
node::Environment* nodeEnvironmentGetByV8Context(v8::Local<v8::Context> context);
void nodeEnvironmentSetIsblinkCore(node::Environment* env);
void nodeEnvironmentAddCustomArgs(node::Environment* env, const std::vector<std::string>& argv);
void nodeAddElectronRequire(node::Environment* env);
void nodeEnvironmentElectronPostEarlyInitialization(node::Environment* env);
bool nodePlatformIdleTasksEnabled(v8::Isolate* isolate);

typedef void* BlinkMicrotaskSuppressionHandle;
extern "C" NODE_EXTERN BlinkMicrotaskSuppressionHandle nodeBlinkMicrotaskSuppressionEnter(v8::Isolate* isolate);
extern "C" NODE_EXTERN void nodeBlinkMicrotaskSuppressionLeave(BlinkMicrotaskSuppressionHandle handle);

extern "C" NODE_EXTERN void* nodeBlinkAllocateUninitialized(size_t length);
extern "C" NODE_EXTERN void nodeBlinkFree(void* data, size_t length);

extern "C" NODE_EXTERN void nodeModuleInitRegister();
extern "C" NODE_EXTERN char* nodeBufferGetData(void* buf, size_t* len);

// 这个类和electron\common\NodeBinding.cpp功能一样，只是以前因为不在同一个模块，所以分开写了。现在其实没必要
struct NodeBindingInMbCore {
    void* env; // node::Environment
    void* isolateData; // node::IsolateData
    void* multiIsolatePlatform; // node::MultiIsolatePlatform
    void* tracingControllerImpl = nullptr; // TracingControllerImpl
};
NodeBindingInMbCore* nodeBindNodejsOnDidCreateScriptContext(void* webView, void* frameId, void* ctx);
void nodeWillReleaseScriptContext(NodeBindingInMbCore* nodebinding);
bool isNodejsEnable();
std::shared_ptr<v8::TaskRunner> nodePlatformGetForegroundTaskRunner(v8::Isolate* isolate);

#endif // ENABLE_NODEJS
#endif //_NODEBLINK_H_