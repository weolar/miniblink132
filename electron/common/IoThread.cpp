
#include "electron/common/IoThread.h"

#include "base/threading/thread.h"

namespace atom {

IoThread* IoThread::s_inst = nullptr;

IoThread* IoThread::get()
{
    if (!s_inst)
        s_inst = new IoThread();
    return s_inst;
}

IoThread::IoThread()
{
    m_thread = new base::Thread("ElectronIoThread");

    base::Thread::Options opt;
    opt.message_pump_type = base::MessagePumpType::IO;
    CHECK(m_thread->StartWithOptions(std::move(opt)));
}

IoThread::~IoThread()
{
    delete m_thread;
}

scoped_refptr<base::SingleThreadTaskRunner> IoThread::taskRunner() const
{
    return m_thread->task_runner();
}

} // atom
