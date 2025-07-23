
#ifndef electron_common_IoThread_h
#define electron_common_IoThread_h

#include "base/task/single_thread_task_runner.h"

namespace base {
class Thread;
}

namespace atom {

class IoThread {
public:
    static IoThread* get();

    scoped_refptr<base::SingleThreadTaskRunner> taskRunner() const;

private:
    IoThread();
    ~IoThread();

    base::Thread* m_thread = nullptr;
    static IoThread* s_inst;
};

}

#endif