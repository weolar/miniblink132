// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_CPP_BINDINGS_LIB_PENDING_REMOTE_STATE_H_
#define MOJO_PUBLIC_CPP_BINDINGS_LIB_PENDING_REMOTE_STATE_H_

#include <stdint.h>

#include "base/component_export.h"
#include "mojo/public/cpp/bindings/connection_group.h"
#include "mojo/public/cpp/system/message_pipe.h"

namespace mojo {
namespace internal {

// Generic state owned by every templated InterfacePtrInfo or PendingRemote
// instance.
struct /*COMPONENT_EXPORT(MOJO_CPP_BINDINGS_BASE)*/ PendingRemoteState {
public:
    PendingRemoteState();
    PendingRemoteState(ScopedMessagePipeHandle pipe, uint32_t version);

    //     PendingRemoteState(scoped_refptr<RawPtrMessagePipe> pipe, uint32_t ver)
    //         : raw_ptr_pipe(pipe)
    //         , version(ver){}

    PendingRemoteState(const PendingRemoteState&) = delete;
    PendingRemoteState(PendingRemoteState&&) noexcept;
    ~PendingRemoteState();

    PendingRemoteState& operator=(const PendingRemoteState&) = delete;
    PendingRemoteState& operator=(PendingRemoteState&&) noexcept;

    void reset();

    ScopedMessagePipeHandle pipe;
    uint32_t version = 0;
    //scoped_refptr<RawPtrMessagePipe> raw_ptr_pipe; // Interface**
};

} // namespace internal
} // namespace mojo

#endif // MOJO_PUBLIC_CPP_BINDINGS_LIB_PENDING_REMOTE_STATE_H_
