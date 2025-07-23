#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_ANY_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_ANY_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=9&c=1
TNode<IntPtrT> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementRemainingSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=9&c=1
TNode<IntPtrT> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementCapabilitySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=9&c=1
TNode<IntPtrT> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementErrorsSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=9&c=1
TNode<IntPtrT> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementLength_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=9&c=1
TNode<IntPtrT> kPromiseAnyRejectElementRemainingSlot_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=9&c=1
TNode<IntPtrT> kPromiseAnyRejectElementCapabilitySlot_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=9&c=1
TNode<IntPtrT> kPromiseAnyRejectElementErrorsSlot_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=32&c=1
TNode<Context> CreatePromiseAnyRejectElementContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseCapability> p_capability, TNode<NativeContext> p_nativeContext);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=59&c=1
TNode<JSFunction> CreatePromiseAnyRejectElementFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_rejectElementContext, TNode<Smi> p_index, TNode<NativeContext> p_nativeContext);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=173&c=1
TNode<Object> PerformPromiseAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TorqueStructIteratorRecord p_iteratorRecord, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_resultCapability, TNode<Object> p_promiseResolveFunction, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=396&c=1
TNode<JSObject> ConstructAggregateError_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_errors);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=39&c=3
void InitContextSlot_PromiseAnyRejectElementContext_PromiseAnyRejectElementContext_Smi_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, IntegerLiteral p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=44&c=3
void InitContextSlot_PromiseAnyRejectElementContext_PromiseAnyRejectElementContext_PromiseCapability_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<PromiseCapability> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=49&c=3
void InitContextSlot_PromiseAnyRejectElementContext_PromiseAnyRejectElementContext_FixedArray_EmptyFixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<FixedArray> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=109&c=31
TorqueStructReference_FixedArray_0 ContextSlot_PromiseAnyRejectElementContext_PromiseAnyRejectElementContext_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=117&c=33
TorqueStructReference_Smi_0 ContextSlot_PromiseAnyRejectElementContext_PromiseAnyRejectElementContext_Smi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=162&c=25
TorqueStructReference_PromiseCapability_0 ContextSlot_PromiseAnyRejectElementContext_PromiseAnyRejectElementContext_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=194&c=36
TorqueStructReference_Map_0 NativeContextSlot_Map_1(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=291&c=30
TNode<BoolT> Is_JSPromise_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-any.tq?l=351&c=10
TNode<BoolT> Is_Constructor_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_ANY_TQ_CSA_H_
