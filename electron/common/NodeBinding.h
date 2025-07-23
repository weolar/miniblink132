#ifndef atom_NodeBinding_h
#define atom_NodeBinding_h

// #include "base/check.h"
// #include "base/check_op.h"
#include "v8.h"
#include <list>
#include <windows.h>

namespace node {
class Environment;
class IsolateData;
class MultiIsolatePlatform;
}

namespace gin {
class Dictionary;
}

typedef struct uv_loop_s uv_loop_t;
typedef struct uv_async_s uv_async_t;

namespace atom {

class TracingControllerImpl;

void bindMbConsoleLog(v8::Local<v8::Context> context);

class NodeBindings {
public:
    NodeBindings(bool isBrowser);
    ~NodeBindings();

    void setUvLoop(uv_loop_t* uvLoop)
    {
        m_uvLoop = uvLoop;
    }

    static void initNodeEnv();

    // https://electron.js.cn/docs/latest/api/process#processcontextisolated-readonly
    struct ProcessObjInfo {
        bool isBrowserProcess = false;
        bool isContextIsolated = false;
    };
    ProcessObjInfo m_processObjInfo;

    void bindFunction(v8::Isolate* isolate, v8::Local<v8::Object> object);

    node::Environment* createEnvironment(v8::Local<v8::Context> context);
    void loadEnvironment(node::Environment* evn);
    void activateUVLoop(v8::Isolate* isoloate);

    node::IsolateData* getIsolateData() const
    {
        return m_isolateData;
    }
    void setIsolateData(node::IsolateData* data)
    {
        m_isolateData = data;
    }

    // Gets/sets the environment to wrap uv loop.
    void setUvEnv(node::Environment* env)
    {
        m_uvEnv = env;
    }
    node::Environment* getUvEnv() const
    {
        return m_uvEnv;
    }

private:
    static void onCallNextTick(uv_async_t* handle);
    bool m_isBrowser;
    uv_loop_t* m_uvLoop = nullptr;
    node::Environment* m_uvEnv = nullptr;
    uv_async_t* m_callNextTickAsync = nullptr;
    std::list<node::Environment*> m_pendingNextTicks;

    // Isolate data used in creating the environment
    node::IsolateData* m_isolateData = nullptr;
};

} // atom

#endif // atom_NodeBinding_h