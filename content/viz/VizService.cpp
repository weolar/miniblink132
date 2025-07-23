// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/viz/VizService.h"

#include <memory>
#include <utility>

#include "content/common/ThreadCall.h"
#include "components/viz/common/frame_sinks/begin_frame_source.h"
#include "components/viz/service/main/viz_compositor_thread_runner_impl.h"

#ifdef OS_WIN
inline BOOL GetCurrentProcessorNumberExXp(PPROCESSOR_NUMBER ProcNumber)
{
    typedef BOOL(WINAPI * PFN_GetCurrentProcessorNumberEx)(PPROCESSOR_NUMBER ProcNumber);
    static PFN_GetCurrentProcessorNumberEx s_GetCurrentProcessorNumberEx = (PFN_GetCurrentProcessorNumberEx)-1;

    if ((PFN_GetCurrentProcessorNumberEx)-1 == s_GetCurrentProcessorNumberEx) {
        HMODULE handle = GetModuleHandle(L"kernel32.dll");
        s_GetCurrentProcessorNumberEx = (PFN_GetCurrentProcessorNumberEx)(GetProcAddress(handle, "GetCurrentProcessorNumberEx"));
    }
    if (s_GetCurrentProcessorNumberEx)
        return s_GetCurrentProcessorNumberEx(ProcNumber);
    return FALSE;
}
#endif

namespace content {

void bindCurrentThreadToCurrentCPU()
{
#ifdef OS_WIN
    // Get the processor number on which the current thread is running.
    PROCESSOR_NUMBER procNumber;
    GetCurrentProcessorNumberExXp(&procNumber);

    // Calculate the CPU affinity mask for the logical processor.
    DWORD_PTR cpuMask = (static_cast<DWORD_PTR>(1) << procNumber.Number);

    // Bind the current thread to the CPU.
    HANDLE thread = GetCurrentThread();
    SetThreadAffinityMask(thread, cpuMask);
#endif
}

VizService::VizService(mojo::PendingReceiver<viz::mojom::FrameSinkManager> receiver, mojo::PendingRemote<viz::mojom::FrameSinkManagerClient> client)
{
    viz::mojom::FrameSinkManagerParamsPtr params = viz::mojom::FrameSinkManagerParams::New();
    params->restart_id = viz::BeginFrameSource::kNotRestartableId;
    params->use_activation_deadline = false;
    params->activation_deadline_in_frames = 0u;
    params->frame_sink_manager = std::move(receiver);
    params->frame_sink_manager_client = std::move(client);
    m_runner = std::make_unique<viz::VizCompositorThreadRunnerImpl>();
    m_runner->CreateFrameSinkManager(std::move(params), /*gpu_service=*/nullptr);

    m_runner->task_runner()->PostTask(FROM_HERE, base::BindOnce([]() { bindCurrentThreadToCurrentCPU(); }));
}

VizService::~VizService()
{
}

// 本函数运行在blink线程
void VizService::destroy(std::function<void(void)>&& callback)
{
    CHECK(!m_runner->task_runner()->BelongsToCurrentThread()); // 不能是viz com线程，因为m_runner里面会关闭这个线程
    //delete this;

    base::SingleThreadTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE,
        base::BindOnce(
            [](VizService* self, std::function<void(void)>&& callback) {
                OutputDebugStringA("VizService::destroy\n");

                self->m_runner.reset();
                callback();
                ThreadCall::delayDestroySelf(self, base::SingleThreadTaskRunner::GetCurrentDefault(), 2000);
            },
            base::Unretained(this), std::move(callback)));
}

scoped_refptr<base::SingleThreadTaskRunner> VizService::GetCompositorThreadRunner()
{
    return m_runner->task_runner();
}

} // namespace demo
