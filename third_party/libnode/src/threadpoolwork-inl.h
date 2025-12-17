// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SRC_THREADPOOLWORK_INL_H_
#define SRC_THREADPOOLWORK_INL_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "node_internals.h"
#include "tracing/trace_event.h"
#include "util-inl.h"

namespace node {

void ThreadPoolWork::ScheduleWork()
{
    env_->IncreaseWaitingRequestCounter();
    TRACE_EVENT_NESTABLE_ASYNC_BEGIN0(TRACING_CATEGORY_NODE2(threadpoolwork, async), type_, this);
    int status = uv_queue_work(
        env_->event_loop(), &work_req_,
        [](uv_work_t* req) {
            ThreadPoolWork* self = ContainerOf(&ThreadPoolWork::work_req_, req);
            TRACE_EVENT_BEGIN0(TRACING_CATEGORY_NODE2(threadpoolwork, sync), self->type_);
            self->DoThreadPoolWork();
            TRACE_EVENT_END0(TRACING_CATEGORY_NODE2(threadpoolwork, sync), self->type_);
        },
        [](uv_work_t* req, int status) {
            ThreadPoolWork* self = ContainerOf(&ThreadPoolWork::work_req_, req);
            self->env_->DecreaseWaitingRequestCounter();

            //////////////////////////////////////////////////////////////////////////
            Environment* env_need_exit_context = nullptr;
            v8::Isolate* isolate = self->env_->isolate();
            v8::HandleScope handle_scope(isolate);
            v8::Local<v8::Context> current_context = isolate->GetCurrentContext();
            if (self->env_->context() != current_context && current_context.IsEmpty()) {
                node::Environment* env2 = node::Environment::GetCurrent(isolate);
                if (env2 != self->env_) {
                    self->env_->context()->Enter();
                    env_need_exit_context = self->env_;
                }
            }
            //////////////////////////////////////////////////////////////////////////

            TRACE_EVENT_NESTABLE_ASYNC_END1(TRACING_CATEGORY_NODE2(threadpoolwork, async), self->type_, self, "result", status);
            self->AfterThreadPoolWork(status);
            if (env_need_exit_context)
                env_need_exit_context->context();
        });
    CHECK_EQ(status, 0);
}

int ThreadPoolWork::CancelWork()
{
    return uv_cancel(reinterpret_cast<uv_req_t*>(&work_req_));
}

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_THREADPOOLWORK_INL_H_
