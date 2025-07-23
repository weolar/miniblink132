
//#include "third_party/libuv/include/uv.h"
#include "v8/include/v8.h"

typedef struct uv_loop_s uv_loop_t;
typedef enum { UV_RUN_DEFAULT = 0, UV_RUN_ONCE, UV_RUN_NOWAIT } uv_run_mode;

bool g_isElectronMode = false;

extern "C" int uv_run(uv_loop_t*, uv_run_mode mode)
{
    return 0;
}

extern "C" int uv_loop_init(uv_loop_t* loop)
{
    return 0;
}

std::shared_ptr<v8::TaskRunner> nodePlatformGetForegroundTaskRunner(v8::Isolate* isolate)
{
    return nullptr;
}

bool nodePlatformIdleTasksEnabled(v8::Isolate* isolate)
{
    return true;
}