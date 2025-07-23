#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_REVERSE_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_REVERSE_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=9&c=1
TNode<Object> LoadElement_FixedArray_Object_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=15&c=1
TorqueStructfloat64_or_hole_0 LoadElement_FixedDoubleArray_float64_or_hole_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=26&c=1
void StoreElement_FixedArray_Object_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, TNode<Object> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=33&c=1
void StoreElement_FixedDoubleArray_float64_or_hole_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements,
    TNode<Smi> p_index, TorqueStructfloat64_or_hole_0 p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=58&c=1
TNode<Object> GenericArrayReverse_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=130&c=1
void TryFastPackedArrayReverse_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, compiler::CodeAssemblerLabel* label_Slow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=132&c=30
TNode<JSArray> Cast_FastJSArray_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=138&c=5
void FastArrayReverse_FixedArray_Object_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-reverse.tq?l=140&c=5
void FastArrayReverse_FixedDoubleArray_float64_or_hole_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_length);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_REVERSE_TQ_CSA_H_
