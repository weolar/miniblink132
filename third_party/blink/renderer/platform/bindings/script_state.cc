// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/platform/bindings/script_state.h"

#include "third_party/blink/renderer/platform/bindings/v8_binding.h"
#include "third_party/blink/renderer/platform/bindings/v8_per_context_data.h"
#include "third_party/blink/renderer/platform/instrumentation/instance_counters.h"
#include "third_party/blink/renderer/platform/instrumentation/resource_coordinator/renderer_resource_coordinator.h"

namespace blink {

ScriptState::CreateCallback ScriptState::s_create_callback_ = nullptr;

// static
void ScriptState::SetCreateCallback(CreateCallback create_callback)
{
    DCHECK(create_callback);
    DCHECK(!s_create_callback_);
    s_create_callback_ = create_callback;
}

// static
ScriptState* ScriptState::Create(v8::Local<v8::Context> context, DOMWrapperWorld* world, ExecutionContext* execution_context)
{
    return s_create_callback_(context, world, execution_context);
}

int kBlinkV8ContextFlagIndex = 19;
int kBlinkV8ContextFlagValue = 123456;

ScriptState::ScriptState(v8::Local<v8::Context> context, DOMWrapperWorld* world, ExecutionContext* execution_context)
    : isolate_(context->GetIsolate())
    , context_(isolate_, context)
    , world_(world)
    , per_context_data_(MakeGarbageCollected<V8PerContextData>(context))
{
    DCHECK(world_);
    context_.SetWeak(this, &OnV8ContextCollectedCallback);
    context->SetAlignedPointerInEmbedderData(kV8ContextPerContextDataIndex, this);
    RendererResourceCoordinator::Get()->OnScriptStateCreated(this, execution_context);

    //--
    CHECK(context->GetNumberOfEmbedderDataFields() < kBlinkV8ContextFlagIndex);
    context->SetEmbedderData(kBlinkV8ContextFlagIndex, v8::Integer::New(isolate_, kBlinkV8ContextFlagValue));
    //---
}

ScriptState::~ScriptState()
{
    DCHECK(!per_context_data_);
    DCHECK(context_.IsEmpty());
    InstanceCounters::DecrementCounter(InstanceCounters::kDetachedScriptStateCounter);
    RendererResourceCoordinator::Get()->OnScriptStateDestroyed(this);
}

ScriptState* ScriptState::From(v8::Isolate* isolate, v8::Local<v8::Context> context)
{
    DCHECK(!context.IsEmpty());
    ScriptState* script_state = static_cast<ScriptState*>(context->GetAlignedPointerFromEmbedderData(isolate, kV8ContextPerContextDataIndex));
    // ScriptState::From() must not be called for a context that does not have
    // valid embedder data in the embedder field.
    DCHECK(script_state);
    SECURITY_CHECK(script_state->context_ == context);
    return script_state;
}

ScriptState* ScriptState::MaybeFrom(v8::Isolate* isolate, v8::Local<v8::Context> context)
{
    DCHECK(!context.IsEmpty());
    if (context->GetNumberOfEmbedderDataFields() <= kV8ContextPerContextDataIndex) {
        return nullptr;
    }

    // ---- check for nodejs context
    if (context->GetNumberOfEmbedderDataFields() < kBlinkV8ContextFlagIndex)
        return nullptr;
    v8::Local<v8::Value> blink_v8context_flag_value = context->GetEmbedderData(kBlinkV8ContextFlagIndex);
    if (blink_v8context_flag_value.IsEmpty() || !blink_v8context_flag_value->IsInt32())
        return nullptr;
    int value = blink_v8context_flag_value.As<v8::Int32>()->Value();
    if (value != kBlinkV8ContextFlagValue)
        return nullptr;
    //----

    ScriptState* script_state = static_cast<ScriptState*>(context->GetAlignedPointerFromEmbedderData(isolate, kV8ContextPerContextDataIndex));
    SECURITY_CHECK(!script_state || script_state->context_ == context);
    return script_state;
}

void ScriptState::Trace(Visitor* visitor) const
{
    visitor->Trace(per_context_data_);
    visitor->Trace(world_);
}

void ScriptState::DetachGlobalObject()
{
    DCHECK(!context_.IsEmpty());
    GetContext()->DetachGlobal();
}

void ScriptState::DisposePerContextData()
{
    per_context_data_->Dispose();
    per_context_data_ = nullptr;
    InstanceCounters::IncrementCounter(InstanceCounters::kDetachedScriptStateCounter);
    RendererResourceCoordinator::Get()->OnScriptStateDetached(this);
}

void ScriptState::DissociateContext()
{
    DCHECK(!per_context_data_);

    // On a worker thread we tear down V8's isolate without running a GC.
    // Alternately we manually clear all references between V8 and Blink, and run
    // operations that should have been invoked by weak callbacks if a GC were
    // run.

    v8::HandleScope scope(GetIsolate());
    // Cut the reference from V8 context to ScriptState.
    GetContext()->SetAlignedPointerInEmbedderData(kV8ContextPerContextDataIndex, nullptr);
    reference_from_v8_context_.Clear();

    // Cut the reference from ScriptState to V8 context.
    context_.Clear();
}

void ScriptState::OnV8ContextCollectedCallback(const v8::WeakCallbackInfo<ScriptState>& data)
{
    data.GetParameter()->reference_from_v8_context_.Clear();
    data.GetParameter()->context_.Clear();
}

} // namespace blink
