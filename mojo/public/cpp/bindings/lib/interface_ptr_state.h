// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_CPP_BINDINGS_LIB_INTERFACE_PTR_STATE_H_
#define MOJO_PUBLIC_CPP_BINDINGS_LIB_INTERFACE_PTR_STATE_H_

#include <stdint.h>

#include <algorithm> // For |std::swap()|.
#include <memory>
#include <string>
#include <utility>

//#include "base/bind.h"
#include "base/callback.h"
#include "base/check.h"
#include "base/component_export.h"
#include "base/dcheck_is_on.h"
#include "base/memory/scoped_refptr.h"
#include "base/task/sequenced_task_runner.h"
#include "base/time/time.h"
#include "mojo/public/cpp/bindings/async_flusher.h"
#include "mojo/public/cpp/bindings/connection_error_callback.h"
#include "mojo/public/cpp/bindings/interface_endpoint_client.h"
#include "mojo/public/cpp/bindings/lib/multiplex_router.h"
#include "mojo/public/cpp/bindings/lib/pending_remote_state.h"
#include "mojo/public/cpp/bindings/lib/sync_method_traits.h"
#include "mojo/public/cpp/bindings/pending_flush.h"
#include "mojo/public/cpp/bindings/thread_safe_proxy.h"
#include "mojo/public/cpp/system/message_pipe.h"

namespace base {
class Location;
}

namespace mojo {

class AssociatedGroup;
class MessageReceiver;

namespace internal {

class /*COMPONENT_EXPORT(MOJO_CPP_BINDINGS)*/ RemoteImplBase {
public:
    RemoteImplBase();

    RemoteImplBase(RemoteImplBase&& other);

    RemoteImplBase(const RemoteImplBase&) = delete;
    RemoteImplBase& operator=(const RemoteImplBase&) = delete;
    ~RemoteImplBase();

    uint32_t version() const;
    bool is_bound() const;

    void CloseWithReason(uint32_t custom_reason, const std::string& description);

    //scoped_refptr<RawPtrMessagePipe> GetRawPtrMessagePipe();

    MessagePipeHandle handle() const;
    bool encountered_error() const;

    static void OnReceiverImplBaseClose(int64_t id, MojoHandle handle, base::OnceClosure reset_handler);

    int64_t GetId() const
    {
        return id_;
    }

//     bool HasAssociatedInterfaces() const;
//
//     // Returns true if bound and awaiting a response to a message.
//     bool has_pending_callbacks() const;
//
//     scoped_refptr<ThreadSafeProxy> CreateThreadSafeProxy(scoped_refptr<ThreadSafeProxy::Target> target);
//
#if DCHECK_IS_ON()
    void SetNextCallLocation(const base::Location& location);
#endif

    scoped_refptr<base::SequencedTaskRunner> GetReceiverTaskRunner();

    scoped_refptr<base::SequencedTaskRunner> runner()
    {
        return runner_;
    }

    void* TryGetInstance();

protected:
    void OnDisconnectError(MojoHandle handle, base::OnceClosure reset_handler);
    //     InterfaceEndpointClient* endpoint_client() const;
    //     MultiplexRouter* router() const;

    void QueryVersion(base::OnceCallback<void(uint32_t)> callback);
    void RequireVersion(uint32_t version);
    void PauseReceiverUntilFlushCompletes(PendingFlush flush);
    void FlushAsync(AsyncFlusher flusher);
    void Swap(RemoteImplBase* other);
    void Bind(PendingRemoteState* remote_state, scoped_refptr<base::SequencedTaskRunner> task_runner);
    PendingRemoteState Unbind();

    void set_connection_error_handler_is_sync(); // weolar

    ScopedMessagePipeHandle PassMessagePipe();
    //     ScopedMessagePipeHandle PassMessagePipe()
    //     {
    //         endpoint_client_.reset();
    //         return router_ ? router_->PassMessagePipe() : std::move(handle_);
    //     }
    //
    //     bool InitializeEndpointClient(bool passes_associated_kinds, bool has_sync_methods, bool has_uninterruptable_methods, std::unique_ptr<MessageReceiver> payload_validator,
    //         const char* interface_name, MessageToMethodInfoCallback method_info_callback, MessageToMethodNameCallback method_name_callback);

    //scoped_refptr<RawPtrMessagePipe> PassRawPtrMessagePipe();

    void* GetInstance();
    //     void** GetInstanceAddrImpl();
    //     void SetRawPtrMessagePipe(scoped_refptr<RawPtrMessagePipe> pipe);

    //void set_reset_handler(base::OnceClosure handler);

private:
    void OnQueryVersion(base::OnceCallback<void(uint32_t)> callback, uint32_t version);

    //     scoped_refptr<MultiplexRouter> router_;
    //
    //     std::unique_ptr<InterfaceEndpointClient> endpoint_client_;
    //
    //     // |router_| (as well as other members above) is not initialized until
    //     // read/write with the message pipe handle is needed. |handle_| is valid
    //     // between the Bind() call and the initialization of |router_|.
    ScopedMessagePipeHandle handle_;
    scoped_refptr<base::SequencedTaskRunner> runner_; // 这个好像没用到

    void* cache_interface_ptr_ = nullptr; // 缓存从handle_里获取的真实interface的指针

    uint32_t version_ = 0;

protected:
    int64_t id_ = 0;
    //base::OnceClosure reset_handler_;
    base::OnceClosure error_handler_;
    ConnectionErrorWithReasonCallback connection_error_handler_;
    bool error_handler_is_sync_ = false;

    //scoped_refptr<RawPtrMessagePipe> raw_ptr_message_pipe_;
};

template <typename Interface> class RemoteImpl : public RemoteImplBase {
public:
    // using Proxy = typename Interface::Proxy_;

    RemoteImpl() = default;

    RemoteImpl(const RemoteImpl&) = delete;
    RemoteImpl& operator=(const RemoteImpl&) = delete;

    ~RemoteImpl() = default;

#if 0
    //   Proxy* instance() {
    //     ConfigureProxyIfNecessary();
    //
    //     // This will be null if the object is not bound.
    //     return proxy_.get();
    //   }
#else
    //     RemoteImpl(Interface** inter)
    //         : interface_addr_(inter) {}

    Interface* instance()
    {
        return (Interface*)GetInstance();
    }
    //Interface** instance_addr() { return (Interface**)GetInstanceAddrImpl(); }
#endif

    void SetNextCallLocation(const base::Location& location)
    {
#if DCHECK_IS_ON()
        //     ConfigureProxyIfNecessary();
        RemoteImplBase::SetNextCallLocation(location);
#endif
    }

    void QueryVersion(base::OnceCallback<void(uint32_t)> callback)
    {
        //     ConfigureProxyIfNecessary();
        RemoteImplBase::QueryVersion(std::move(callback));
        //*(int*)1 = 1;
    }

    void RequireVersion(uint32_t version)
    {
        //     ConfigureProxyIfNecessary();
        RemoteImplBase::RequireVersion(version);
        //*(int*)1 = 1;
    }

    void PauseReceiverUntilFlushCompletes(PendingFlush flush)
    {
        //     ConfigureProxyIfNecessary();
        RemoteImplBase::PauseReceiverUntilFlushCompletes(std::move(flush));
    }

    void FlushAsync(AsyncFlusher flusher)
    {
        //     ConfigureProxyIfNecessary();
        RemoteImplBase::FlushAsync(std::move(flusher));
    }

    void FlushForTesting()
    {
        // ConfigureProxyIfNecessary();
        //endpoint_client()->FlushForTesting();
    }

    void FlushAsyncForTesting(base::OnceClosure callback)
    {
        //     ConfigureProxyIfNecessary();
        //endpoint_client()->FlushAsyncForTesting(std::move(callback));
    }

    void CloseWithReason(uint32_t custom_reason, const std::string& description)
    {
        // ConfigureProxyIfNecessary();
        //endpoint_client()->CloseWithReason(custom_reason, description);
        RemoteImplBase::CloseWithReason(custom_reason, description);
    }

    void Swap(RemoteImpl* other)
    {
        //     using std::swap;
        //     swap(other->proxy_, proxy_);
        RemoteImplBase::Swap(other);
    }

    void Bind(PendingRemoteState* remote_state, scoped_refptr<base::SequencedTaskRunner> runner)
    {
        //     DCHECK(!proxy_);
        RemoteImplBase::Bind(remote_state, std::move(runner));
    }

    // After this method is called, the object is in an invalid state and
    // shouldn't be reused.
    PendingRemoteState Unbind()
    {
        // proxy_.reset();
        return RemoteImplBase::Unbind();
    }

    void set_connection_error_handler(base::OnceClosure error_handler)
    {
        //         ConfigureProxyIfNecessary();
        //         DCHECK(endpoint_client());
        //         endpoint_client()->set_connection_error_handler(std::move(error_handler));
        error_handler_ = std::move(error_handler);
    }

    void set_connection_error_with_reason_handler(ConnectionErrorWithReasonCallback error_handler)
    {
        connection_error_handler_ = std::move(error_handler);
        //         ConfigureProxyIfNecessary();
        //         DCHECK(endpoint_client());
        //         endpoint_client()->set_connection_error_with_reason_handler(std::move(error_handler));
    }

    void set_idle_handler(base::TimeDelta timeout, base::RepeatingClosure handler)
    {
        //         ConfigureProxyIfNecessary();
        //         DCHECK(endpoint_client());
        //         endpoint_client()->SetIdleHandler(timeout, std::move(handler));
    }

    //     unsigned int GetNumUnackedMessagesForTesting() const
    //     {
    //         return endpoint_client()->GetNumUnackedMessagesForTesting();
    //     }
    //
    AssociatedGroup* associated_group()
    {
        // ConfigureProxyIfNecessary();
        //return endpoint_client()->associated_group();
        return nullptr;
    }

    void EnableTestingMode()
    {
        // ConfigureProxyIfNecessary();
        // router()->EnableTestingMode();
    }

    void RaiseError()
    {
        // ConfigureProxyIfNecessary();
        // endpoint_client()->RaiseError();
    }

    //InterfaceEndpointClient* endpoint_client_for_test() { return endpoint_client(); }

private:
    //   void ConfigureProxyIfNecessary() {
    //     // The proxy has been configured.
    //     if (proxy_) {
    //       DCHECK(router());
    //       DCHECK(endpoint_client());
    //       return;
    //     }
    //
    //     if (InitializeEndpointClient(
    //             Interface::PassesAssociatedKinds_,
    //             !SyncMethodTraits<Interface>::GetOrdinals().empty(),
    //             Interface::HasUninterruptableMethods_,
    //             std::make_unique<typename Interface::ResponseValidator_>(),
    //             Interface::Name_, Interface::MessageToMethodInfo_,
    //             Interface::MessageToMethodName_)) {
    //       proxy_ = std::make_unique<Proxy>(endpoint_client());
    //     }
    //   }
    // std::unique_ptr<Proxy> proxy_;
};

} // namespace internal
} // namespace mojo

#endif // MOJO_PUBLIC_CPP_BINDINGS_LIB_INTERFACE_PTR_STATE_H_
