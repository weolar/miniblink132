
#ifndef gin_default_platform_wrap_h
#define gin_default_platform_wrap_h

#include "v8-platform.h"

namespace v8 {
class PageAllocator;

namespace platform {
class DefaultPlatform;
}
}

namespace gin {

class DefaultPlatformWrap {
public:
    DefaultPlatformWrap();
    std::shared_ptr<v8::TaskRunner> GetForegroundTaskRunner(v8::Isolate* isolate);
    void CallOnWorkerThread(std::unique_ptr<v8::Task> task);
    int NumberOfWorkerThreads();
    void CallDelayedOnWorkerThread(std::unique_ptr<v8::Task> task, double delay_in_seconds);
    double CurrentClockTimeMillis();
    v8::PageAllocator* GetPageAllocator();
    std::unique_ptr<v8::JobHandle> CreateJob(v8::TaskPriority priority, std::unique_ptr<v8::JobTask> job_task);

    v8::Platform* GetPlatform() const
    {
        return (v8::Platform*)m_defaultPlatform;
    }
private:
    v8::platform::DefaultPlatform* m_defaultPlatform;
};

}

#endif
