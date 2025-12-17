// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/mojo/mojo_handle.h"

#include "base/numerics/safe_math.h"
#include "mojo/public/c/system/message_pipe.h"
#include "mojo/public/cpp/bindings/message.h"
#include "mojo/public/cpp/system/message_pipe.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_create_shared_buffer_result.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_discard_data_options.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_duplicate_buffer_handle_options.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_map_buffer_result.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_read_data_options.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_read_data_result.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_read_message_flags.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_read_message_result.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_write_data_options.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_write_data_result.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_union_arraybuffer_arraybufferview.h"
#include "third_party/blink/renderer/core/mojo/mojo_watcher.h"
#include "third_party/blink/renderer/core/mojo/test/mojo_interface_request_event.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_array_buffer.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_array_buffer_view.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_interface_request_event_init.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_interface_request_event.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_mojo_handle.h"
#include "third_party/blink/renderer/core/event_type_names.h"
#include "third_party/blink/renderer/core/mojo/mojo_handle.h"

const blink::WrapperTypeInfo blink::V8MojoInterfaceRequestEvent::wrapper_type_info_ {
    gin::kEmbedderBlink,
    nullptr,
    nullptr,
    "MojoInterfaceRequestEvent",
    nullptr,
    static_cast<v8::CppHeapPointerTag>(356),
    static_cast<v8::CppHeapPointerTag>(356),
    blink::WrapperTypeInfo::kWrapperTypeObjectPrototype,
    blink::WrapperTypeInfo::kObjectClassId,
    blink::WrapperTypeInfo::kNotInheritFromActiveScriptWrappable,
    blink::WrapperTypeInfo::kIdlInterface,
    false,
};

const blink::WrapperTypeInfo& blink::MojoInterfaceRequestEvent::wrapper_type_info_ =
blink::V8MojoInterfaceRequestEvent::wrapper_type_info_;

const blink::WrapperTypeInfo blink::V8MojoHandle::wrapper_type_info_{
    gin::kEmbedderBlink,
    nullptr/*blink::V8MojoHandle::InstallInterfaceTemplate*/,
    nullptr,
    "MojoHandle",
    nullptr,
    blink::V8MojoHandle::kThisTag,
    blink::V8MojoHandle::kMaxSubclassTag,
    blink::WrapperTypeInfo::kWrapperTypeObjectPrototype,
    blink::WrapperTypeInfo::kObjectClassId,
    blink::WrapperTypeInfo::kIdlInterface,
    false,
};

const blink::WrapperTypeInfo& blink::MojoHandle::wrapper_type_info_ = blink::V8MojoHandle::wrapper_type_info_;

blink::MojoInterfaceRequestEvent::MojoInterfaceRequestEvent(WTF::AtomicString const&, blink::MojoInterfaceRequestEventInit const*)
{
    *(int*)1 = 1;
}

blink::MojoHandle::MojoHandle(mojo::ScopedHandleBase<mojo::Handle>)
{
    *(int*)1 = 1;
}

blink::MojoCreateSharedBufferResult* blink::MojoHandle::duplicateBufferHandle(blink::MojoDuplicateBufferHandleOptions const*)
{
    *(int*)1 = 1;
    return nullptr;
}
blink::MojoMapBufferResult* blink::MojoHandle::mapBuffer(unsigned int, unsigned int)
{
    *(int*)1 = 1;
    return nullptr;
}
blink::MojoReadDataResult* blink::MojoHandle::discardData(unsigned int, blink::MojoDiscardDataOptions const*)
{
    *(int*)1 = 1;
    return nullptr;
}
blink::MojoReadDataResult* blink::MojoHandle::queryData(void) const
{
    *(int*)1 = 1;
    return nullptr;
}
blink::MojoReadDataResult* blink::MojoHandle::readData(blink::V8UnionArrayBufferOrArrayBufferView const*, blink::MojoReadDataOptions const*) const
{
    *(int*)1 = 1;
    return nullptr;
}
blink::MojoReadMessageResult* blink::MojoHandle::readMessage(blink::MojoReadMessageFlags const*)
{
    *(int*)1 = 1;
    return nullptr;
}
blink::MojoWatcher* blink::MojoHandle::watch(blink::ScriptState*, blink::MojoHandleSignals const*, blink::V8MojoWatchCallback*)
{
    *(int*)1 = 1;
    return nullptr;
}
blink::MojoWriteDataResult* blink::MojoHandle::writeData(blink::V8UnionArrayBufferOrArrayBufferView const*, blink::MojoWriteDataOptions const*)
{
    *(int*)1 = 1;
    return nullptr;
}

mojo::ScopedHandleBase<mojo::Handle> blink::MojoHandle::TakeHandle(void)
{
    *(int*)1 = 1;
    return mojo::ScopedHandleBase<mojo::Handle>();
}
