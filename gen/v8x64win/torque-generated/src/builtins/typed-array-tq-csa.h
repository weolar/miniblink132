#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TYPED_ARRAY_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TYPED_ARRAY_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=97&c=1
TNode<Smi> kStoreSucceded_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=98&c=1
TNode<Smi> kStoreFailureArrayDetachedOrOutOfBounds_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=149&c=1
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_elementsKindParam);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=202&c=1
TNode<JSTypedArray> EnsureAttached_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_array, compiler::CodeAssemblerLabel* label_DetachedOrOutOfBounds);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=217&c=1
TorqueStructAttachedJSTypedArrayAndLength_0 EnsureAttachedAndReadLength_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_array, compiler::CodeAssemblerLabel* label_DetachedOrOutOfBounds);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=252&c=1
TorqueStructAttachedJSTypedArrayWitness_0 NewAttachedJSTypedArrayWitness_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_array);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=265&c=1
ElementsKind KindForArrayType_Uint8Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=268&c=1
ElementsKind KindForArrayType_Int8Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=271&c=1
ElementsKind KindForArrayType_Uint16Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=274&c=1
ElementsKind KindForArrayType_Int16Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=277&c=1
ElementsKind KindForArrayType_Uint32Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=280&c=1
ElementsKind KindForArrayType_Int32Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=283&c=1
ElementsKind KindForArrayType_Float16Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=286&c=1
ElementsKind KindForArrayType_Float32Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=289&c=1
ElementsKind KindForArrayType_Float64Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=292&c=1
ElementsKind KindForArrayType_Uint8ClampedElements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=295&c=1
ElementsKind KindForArrayType_BigUint64Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=298&c=1
ElementsKind KindForArrayType_BigInt64Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=160&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Int32Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=162&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Float16Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=164&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Float32Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=166&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Float64Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=168&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Uint8ClampedElements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=170&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_BigUint64Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=172&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_BigInt64Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=176&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Uint8Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=178&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Int8Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=180&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Uint16Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=182&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Int16Elements_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array.tq?l=184&c=14
TorqueStructTypedArrayAccessor_0 GetTypedArrayAccessor_Uint32Elements_0(compiler::CodeAssemblerState* state_);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TYPED_ARRAY_TQ_CSA_H_
