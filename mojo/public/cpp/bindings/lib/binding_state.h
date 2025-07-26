// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_CPP_BINDINGS_LIB_BINDING_STATE_H_
#define MOJO_PUBLIC_CPP_BINDINGS_LIB_BINDING_STATE_H_

#include <stdint.h>

#include <memory>
#include <utility>

#include "base/bind.h"
#include "base/callback.h"
#include "base/check.h"
#include "base/component_export.h"
#include "base/sequence_checker.h"
#include "base/containers/span.h"
#include "base/memory/ptr_util.h"
#include "base/memory/ref_counted.h"
#include "base/strings/string_piece.h"
#include "base/task/sequenced_task_runner.h"
#include "mojo/public/cpp/bindings/async_flusher.h"
#include "mojo/public/cpp/bindings/connection_error_callback.h"
#include "mojo/public/cpp/bindings/connection_group.h"
#include "mojo/public/cpp/bindings/interface_endpoint_client.h"
#include "mojo/public/cpp/bindings/interface_id.h"
#include "mojo/public/cpp/bindings/lib/multiplex_router.h"
#include "mojo/public/cpp/bindings/lib/pending_receiver_state.h"
#include "mojo/public/cpp/bindings/lib/sync_method_traits.h"
#include "mojo/public/cpp/bindings/message_header_validator.h"
#include "mojo/public/cpp/bindings/pending_flush.h"
#include "mojo/public/cpp/bindings/pending_receiver.h"
#include "mojo/public/cpp/bindings/scoped_interface_endpoint_handle.h"

namespace mojo {

namespace internal {

class /*COMPONENT_EXPORT(MOJO_CPP_BINDINGS)*/ ReceiverImplBase {
public:
    ReceiverImplBase();
    ~ReceiverImplBase();

    void SetFilter(std::unique_ptr<MessageFilter> filter);

    bool HasAssociatedInterfaces() const;

    void PauseIncomingMethodCallProcessing();
    void ResumeIncomingMethodCallProcessing();

    bool WaitForIncomingMethodCall();

    void PauseRemoteCallbacksUntilFlushCompletes(PendingFlush flush);
    void FlushAsync(AsyncFlusher flusher);

    void Close();
    void CloseWithReason(uint32_t custom_reason, base::StringPiece description);
    static void OnRemoteImplBaseClose(int64_t id, MojoHandle handle, base::OnceClosure cb);

    void RaiseError();

    //void set_reset_handler(base::OnceClosure handler);

    void set_connection_error_handler(base::OnceClosure error_handler);
    void set_connection_error_with_reason_handler(ConnectionErrorWithReasonCallback error_handler);

    void set_connection_error_handler_is_sync(); // weolar

    bool is_bound() const;

    MessagePipeHandle handle() const;

    ReportBadMessageCallback GetBadMessageCallback();
    void FlushForTesting();
    void EnableBatchDispatch();
    void EnableTestingMode();
    scoped_refptr<internal::MultiplexRouter> RouterForTesting();

    int64_t GetId() const
    {
        return id_;
    }

protected:
    void BindInternal(PendingReceiverState* receiver_state, scoped_refptr<base::SequencedTaskRunner> runner, const char* interface_name,
        std::unique_ptr<MessageReceiver> request_validator, bool passes_associated_kinds, base::span<const uint32_t> sync_method_ordinals,
        MessageReceiverWithResponderStatus* stub, uint32_t interface_version, MessageToMethodInfoCallback method_info_callback,
        MessageToMethodNameCallback method_name_callback);

    void BindInternal2(
        PendingReceiverState* receiver_state, scoped_refptr<base::SequencedTaskRunner> runner, const char* interface_name, uint32_t interface_version);

    //     scoped_refptr<internal::MultiplexRouter> router_;
    //     std::unique_ptr<InterfaceEndpointClient> endpoint_client_;

    void OnDisconnectError(MojoHandle handle, base::OnceClosure cb);

    base::OnceClosure error_handler_;
    bool error_handler_is_sync_ = false;
    //base::OnceClosure reset_handler_;
    ConnectionErrorWithReasonCallback error_with_reason_handler_;
    scoped_refptr<base::SequencedTaskRunner> runner_;
    bool encountered_error_ = false;

    ScopedMessagePipeHandle handle_;
    void* impl_ = nullptr;
    void* last_impl_ = nullptr;
    int64_t id_ = 0;

    // We use SequenceCheckerImpl directly, to assert some sequence checks even in
    // release builds. See https://crbug.com/1325096.
    SEQUENCE_CHECKER(sequence_checker_);

    //base::WeakPtrFactory<ReceiverImplBase> weak_ptr_factory_ { this };
};

template <typename Interface, typename ImplRefTraits> class ReceiverImpl : public ReceiverImplBase {
public:
    using ImplPointerType = typename ImplRefTraits::PointerType; // ImplPointerType=device::mojom::blink::TimeZoneMonitorClient = blink::TimeZoneController

    explicit ReceiverImpl(ImplPointerType impl)
    {
        // stub_.set_sink(std::move(impl));
        impl_ = (void*)ImplRefTraits::GetRawPointer(&impl);
    }

    ReceiverImpl(const ReceiverImpl&) = delete;
    ReceiverImpl& operator=(const ReceiverImpl&) = delete;

    ~ReceiverImpl()
    {
        Close();
    }

    void Bind(PendingReceiverState* receiver_state, scoped_refptr<base::SequencedTaskRunner> runner)
    {
        //         ReceiverImplBase::BindInternal(
        //             std::move(receiver_state), runner, Interface::Name_,
        //             Interface::PassesAssociatedKinds_,
        //             SyncMethodTraits<Interface>::GetOrdinals(), &stub_, Interface::Version_,
        //             Interface::MessageToMethodInfo_, Interface::MessageToMethodName_);

        ReceiverImplBase::BindInternal2(std::move(receiver_state), runner, Interface::Name_, Interface::Version_);
    }

    PendingReceiver<Interface> Unbind()
    {
        //weak_ptr_factory_.InvalidateWeakPtrs();
        //endpoint_client_.reset();
        //PendingReceiver<Interface> request(router_->PassMessagePipe());
        //PendingReceiver<Interface> request((Interface**)(&impl_));

        //ScopedMessagePipeHandle message_pipe(handle_.release());
        PendingReceiver<Interface> request(std::move(handle_));
        handle_.reset();

        //router_ = nullptr;
        impl_ = nullptr;
        return request;
    }

    Interface* impl()
    {
        // return ImplRefTraits::GetRawPointer(&stub_.sink());
        return (Interface*)impl_;
    }

    ImplPointerType SwapImplForTesting(ImplPointerType new_impl)
    {
        *(int*)1 = 1;
        // return std::exchange(stub_.sink(), std::move(new_impl));
        return nullptr;
    }

private:
    // typename Interface::template Stub_<ImplRefTraits> stub_;
};

} // namespace internal
} // namespace mojo

#endif // MOJO_PUBLIC_CPP_BINDINGS_LIB_BINDING_STATE_H_
