
#include "gin/per_isolate_data.h"
#include "base/task/single_thread_task_runner.h"
#include "base/task/thread_pool/initialization_util.h"
#include "v8.h"

void nodeCreateGinPerIsolateData(v8::Isolate* isolate, v8::ArrayBuffer::Allocator* allocator, bool isUseLocker)
{
    if (gin::PerIsolateData::From(isolate))
        return;

    gin::IsolateHolder::AccessMode mode = gin::IsolateHolder::kSingleThread;
    if (isUseLocker)
        mode = gin::IsolateHolder::AccessMode::kUseLocker;

    new gin::PerIsolateData(isolate, allocator, mode, base::SingleThreadTaskRunner::GetCurrentDefault(),
        base::SingleThreadTaskRunner::GetCurrentDefault(), base::SingleThreadTaskRunner::GetCurrentDefault());
}