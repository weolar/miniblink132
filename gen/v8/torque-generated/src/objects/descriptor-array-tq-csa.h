#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DESCRIPTOR_ARRAY_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DESCRIPTOR_ARRAY_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=5&c=1
TNode<EnumCache> Cast_EnumCache_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=18&c=1
TNode<DescriptorArray> Cast_DescriptorArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=31&c=1
TNode<StrongDescriptorArray> Cast_StrongDescriptorArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
TNode<FixedArray> LoadEnumCacheKeys_0(compiler::CodeAssemblerState* state_, TNode<EnumCache> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
void StoreEnumCacheKeys_0(compiler::CodeAssemblerState* state_, TNode<EnumCache> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
TNode<FixedArray> LoadEnumCacheIndices_0(compiler::CodeAssemblerState* state_, TNode<EnumCache> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
void StoreEnumCacheIndices_0(compiler::CodeAssemblerState* state_, TNode<EnumCache> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=21&c=9
TNode<Uint16T> LoadDescriptorArrayNumberOfAllDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=22&c=3
TNode<Uint16T> LoadDescriptorArrayNumberOfDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=22&c=3
void StoreDescriptorArrayNumberOfDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o, TNode<Uint16T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=25&c=3
TNode<Uint32T> LoadDescriptorArrayRawGcState_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=25&c=3
void StoreDescriptorArrayRawGcState_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
TNode<EnumCache> LoadDescriptorArrayEnumCache_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
void StoreDescriptorArrayEnumCache_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o, TNode<EnumCache> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
TorqueStructSlice_DescriptorEntry_MutableReference_DescriptorEntry_0 FieldSliceDescriptorArrayDescriptors_0(
    compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=5&c=1
TNode<EnumCache> DownCastForTorqueClass_EnumCache_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=18&c=1
TNode<DescriptorArray> DownCastForTorqueClass_DescriptorArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=31&c=1
TNode<StrongDescriptorArray> DownCastForTorqueClass_StrongDescriptorArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
TorqueStructSlice_DescriptorEntry_MutableReference_DescriptorEntry_0 NewMutableSlice_DescriptorEntry_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DESCRIPTOR_ARRAY_TQ_CSA_H_
