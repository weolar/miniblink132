#ifndef atom_NodeThread_h
#define atom_NodeThread_h

#define NODE_ARCH "ia32"
#define NODE_PLATFORM "win32"
#define NODE_WANT_INTERNALS 1
#define HAVE_OPENSSL 1
#define HAVE_ETW 1
#define HAVE_PERFCTR 1
#define V8_INSPECTOR_USE_STL 1
//#define NODE_USE_V8_PLATFORM 0
//#define USING_V8_SHARED 0
#define CARES_BUILDING_LIBRARY 0

#include "third_party/libnode/src/node.h"
#include "third_party/libuv/include/uv.h"
#include "base/synchronization/lock.h"
#include <set>

namespace node {
class Environment;
}

namespace gin {
class IsolateHolder;
}

namespace atom {

struct NodeNative {
    const char* name;
    const char* source;
    size_t sourceLen;
};

typedef struct _NodeArgc NodeArgc;
typedef void (*NodeInitCallBack)(NodeArgc*);
class NodeBindings;

struct NodeEnv {
    v8::Platform* v8platform = nullptr;
    uv_loop_t* uvLoop = nullptr;
    node::Environment* env = nullptr;
    gin::IsolateHolder* isolateHolder = nullptr;
};

typedef struct _NodeArgc {
    //     char** argv;
    //     int argc;

    NodeEnv uiThreadNodeEnv;

    uv_async_t async;
    uv_thread_t thread = nullptr;
    bool initType = false;
    HANDLE initEvent;
    //     NodeInitCallBack preInitcall;
    //     NodeInitCallBack initcall;
    NodeBindings* m_nodeBinding = nullptr;
    v8::Isolate* m_isolate = nullptr;
    node::MultiIsolatePlatform* m_nodeMultiIsolatePlatform = nullptr;

    base::Lock m_registerIsolatesLock;
    std::set<v8::Isolate*> m_registerIsolates;
} NodeArgc;

extern NodeArgc* g_nodeArgc; // 所有线程都可访问

NodeArgc* runNodeThread();
node::Environment* nodeGetEnvironment(NodeArgc*);

} // atom

#endif // atom_NodeThread_h