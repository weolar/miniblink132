#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_JOIN_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_JOIN_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=101&c=1
TNode<BoolT> CannotUseSameArrayAccessor_JSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<BuiltinPtr> p_loadFn, TNode<JSReceiver> p_receiver, TNode<Map> p_originalMap, TNode<Number> p_originalLen);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=113&c=1
TNode<BoolT> CannotUseSameArrayAccessor_JSTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<BuiltinPtr> p__loadFn, TNode<JSReceiver> p_receiver, TNode<Map> p__initialMap, TNode<Number> p__initialLen);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=135&c=1
TNode<IntPtrT> AddStringLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_lenA, TNode<IntPtrT> p_lenB);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=269&c=1
TorqueStructBuffer_0 NewBuffer_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_len, TNode<String> p_sep);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=283&c=1
TNode<String> BufferJoin_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructBuffer_0 p_buffer, TNode<String> p_sep);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=388&c=1
TNode<Object> ArrayJoin_JSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_useToLocaleString, TNode<JSReceiver> p_receiver, TNode<String> p_sep, TNode<Number> p_lenNumber, TNode<Object> p_locales, TNode<Object> p_options);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=435&c=1
TNode<Object> ArrayJoin_JSTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_useToLocaleString, TNode<JSReceiver> p_receiver, TNode<String> p_sep, TNode<Number> p_lenNumber, TNode<Object> p_locales, TNode<Object> p_options);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=511&c=1
TNode<FixedArray> LoadJoinStack_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, compiler::CodeAssemblerLabel* label_IfUninitialized);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=523&c=1
void SetJoinStack_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_stack);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=556&c=1
TNode<BoolT> JoinStackPushInline_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=601&c=1
void JoinStackPopInline_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=25&c=26
TNode<JSArray> UnsafeCast_JSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=26&c=34
TNode<NumberDictionary> UnsafeCast_NumberDictionary_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=40&c=34
TNode<FixedArray> UnsafeCast_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=42&c=46
TNode<Object> UnsafeCast_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=49&c=7
TNode<FixedDoubleArray> UnsafeCast_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=116&c=36
TNode<JSTypedArray> UnsafeCast_JSTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=294&c=7
TNode<String> Cast_String_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=431&c=10
TNode<String> ArrayJoinImpl_JSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_sep, TNode<Number> p_lengthNumber, bool p_useToLocaleString, TNode<Object> p_locales, TNode<Object> p_options, TNode<BuiltinPtr> p_initialLoadFn);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=500&c=10
TNode<String> ArrayJoinImpl_JSTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_sep, TNode<Number> p_lengthNumber, bool p_useToLocaleString, TNode<Object> p_locales, TNode<Object> p_options, TNode<BuiltinPtr> p_initialLoadFn);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=513&c=16
TorqueStructReference_Undefined_OR_FixedArray_0 NativeContextSlot_Context_Undefined_OR_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=549&c=7
TNode<FixedArray> StoreAndGrowFixedArray_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_fixedArray, TNode<IntPtrT> p_index, TNode<JSReceiver> p_element);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=660&c=10
TNode<Object> CycleProtectedArrayJoin_JSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_useToLocaleString, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Object> p_sepObj, TNode<Object> p_locales, TNode<Object> p_options);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=716&c=10
TNode<Object> CycleProtectedArrayJoin_JSTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_useToLocaleString, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Object> p_sepObj, TNode<Object> p_locales, TNode<Object> p_options);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=209&c=27
TNode<FixedArray> StoreAndGrowFixedArray_Smi_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_fixedArray, TNode<IntPtrT> p_index, TNode<Smi> p_element);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-join.tq?l=187&c=11
TNode<FixedArray> StoreAndGrowFixedArray_String_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_fixedArray, TNode<IntPtrT> p_index, TNode<String> p_element);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_JOIN_TQ_CSA_H_
