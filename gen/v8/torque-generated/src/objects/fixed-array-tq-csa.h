#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FIXED_ARRAY_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FIXED_ARRAY_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=5&c=1
TNode<FixedArrayBase> Cast_FixedArrayBase_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=11&c=1
TNode<FixedArray> Cast_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=19&c=1
TNode<TrustedFixedArray> Cast_TrustedFixedArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=25&c=1
TNode<ProtectedFixedArray> Cast_ProtectedFixedArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=31&c=1
TNode<FixedDoubleArray> Cast_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=36&c=1
TNode<WeakFixedArray> Cast_WeakFixedArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=42&c=1
TNode<TrustedWeakFixedArray> Cast_TrustedWeakFixedArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=48&c=1
TNode<ByteArray> Cast_ByteArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=53&c=1
TNode<TrustedByteArray> Cast_TrustedByteArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=61&c=1
TNode<ArrayList> Cast_ArrayList_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=68&c=1
TNode<WeakArrayList> Cast_WeakArrayList_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=116&c=1
void StoreFixedDoubleArrayDirect_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_a, TNode<Smi> p_i, TNode<Number> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=120&c=1
void StoreFixedArrayDirect_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_a, TNode<Smi> p_i, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=155&c=1
TNode<FixedArray> ExtractFixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_source, TNode<IntPtrT> p_first, TNode<IntPtrT> p_count,
    TNode<IntPtrT> p_capacity, TNode<Hole> p_initialElement);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=165&c=1
TNode<FixedArrayBase> ExtractFixedDoubleArray_0(
    compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_source, TNode<IntPtrT> p_first, TNode<IntPtrT> p_count, TNode<IntPtrT> p_capacity);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=8&c=9
TNode<Smi> LoadFixedArrayBaseLength_0(compiler::CodeAssemblerState* state_, TNode<FixedArrayBase> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=14&c=3
TorqueStructSlice_Object_MutableReference_Object_0 FieldSliceFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=14&c=3
TNode<Object> LoadFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=14&c=3
void StoreFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=38&c=9
TNode<Smi> LoadWeakFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
TorqueStructSlice_MaybeObject_MutableReference_MaybeObject_0 FieldSliceWeakFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
TNode<MaybeObject> LoadWeakFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
void StoreWeakFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o, TNode<IntPtrT> p_i, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=70&c=9
TNode<Smi> LoadWeakArrayListCapacity_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=71&c=3
TNode<Smi> LoadWeakArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=71&c=3
void StoreWeakArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=72&c=36
TorqueStructSlice_MaybeObject_MutableReference_MaybeObject_0 FieldSliceWeakArrayListObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=72&c=36
TNode<MaybeObject> LoadWeakArrayListObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=72&c=36
void StoreWeakArrayListObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<IntPtrT> p_i, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=33&c=3
TorqueStructSlice_float64_or_hole_MutableReference_float64_or_hole_0 FieldSliceFixedDoubleArrayValues_0(
    compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=21&c=9
TNode<Smi> LoadTrustedFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<TrustedFixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=22&c=3
TorqueStructSlice_Object_MutableReference_Object_0 FieldSliceTrustedFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<TrustedFixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=22&c=3
TNode<Object> LoadTrustedFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<TrustedFixedArray> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=22&c=3
void StoreTrustedFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<TrustedFixedArray> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=27&c=9
TNode<Smi> LoadProtectedFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<ProtectedFixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=28&c=3
TorqueStructSlice_Smi_OR_TrustedObject_MutableReference_Smi_OR_TrustedObject_0 FieldSliceProtectedFixedArrayObjects_0(
    compiler::CodeAssemblerState* state_, TNode<ProtectedFixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=28&c=3
TNode<Object> LoadProtectedFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<ProtectedFixedArray> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=28&c=3
void StoreProtectedFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<ProtectedFixedArray> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=44&c=9
TNode<Smi> LoadTrustedWeakFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<TrustedWeakFixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=45&c=3
TorqueStructSlice_MaybeObject_MutableReference_MaybeObject_0 FieldSliceTrustedWeakFixedArrayObjects_0(
    compiler::CodeAssemblerState* state_, TNode<TrustedWeakFixedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=45&c=3
TNode<MaybeObject> LoadTrustedWeakFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<TrustedWeakFixedArray> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=45&c=3
void StoreTrustedWeakFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<TrustedWeakFixedArray> p_o, TNode<IntPtrT> p_i, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=50&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceByteArrayValues_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=50&c=3
TNode<Uint8T> LoadByteArrayValues_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=50&c=3
void StoreByteArrayValues_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=55&c=9
TNode<Smi> LoadTrustedByteArrayLength_0(compiler::CodeAssemblerState* state_, TNode<TrustedByteArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=56&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceTrustedByteArrayValues_0(compiler::CodeAssemblerState* state_, TNode<TrustedByteArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=56&c=3
TNode<Uint8T> LoadTrustedByteArrayValues_0(compiler::CodeAssemblerState* state_, TNode<TrustedByteArray> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=56&c=3
void StoreTrustedByteArrayValues_0(compiler::CodeAssemblerState* state_, TNode<TrustedByteArray> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=63&c=9
TNode<Smi> LoadArrayListCapacity_0(compiler::CodeAssemblerState* state_, TNode<ArrayList> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=64&c=3
TNode<Smi> LoadArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<ArrayList> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=64&c=3
void StoreArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<ArrayList> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=65&c=3
TorqueStructSlice_Object_MutableReference_Object_0 FieldSliceArrayListObjects_0(compiler::CodeAssemblerState* state_, TNode<ArrayList> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=65&c=3
TNode<Object> LoadArrayListObjects_0(compiler::CodeAssemblerState* state_, TNode<ArrayList> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=65&c=3
void StoreArrayListObjects_0(compiler::CodeAssemblerState* state_, TNode<ArrayList> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=5&c=1
TNode<FixedArrayBase> DownCastForTorqueClass_FixedArrayBase_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=11&c=1
TNode<FixedArray> DownCastForTorqueClass_FixedArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=19&c=1
TNode<TrustedFixedArray> DownCastForTorqueClass_TrustedFixedArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=25&c=1
TNode<ProtectedFixedArray> DownCastForTorqueClass_ProtectedFixedArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=31&c=1
TNode<FixedDoubleArray> DownCastForTorqueClass_FixedDoubleArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=36&c=1
TNode<WeakFixedArray> DownCastForTorqueClass_WeakFixedArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=42&c=1
TNode<TrustedWeakFixedArray> DownCastForTorqueClass_TrustedWeakFixedArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=48&c=1
TNode<ByteArray> DownCastForTorqueClass_ByteArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=53&c=1
TNode<TrustedByteArray> DownCastForTorqueClass_TrustedByteArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=61&c=1
TNode<ArrayList> DownCastForTorqueClass_ArrayList_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=68&c=1
TNode<WeakArrayList> DownCastForTorqueClass_WeakArrayList_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=163&c=11
TorqueStructConstantIterator_Hole_0 ConstantIterator_Hole_0(compiler::CodeAssemblerState* state_, TNode<Hole> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=161&c=7
TorqueStructIteratorSequence_Object_SliceIterator_Object_MutableReference_Object_ConstantIterator_Hole_0
IteratorSequence_Object_SliceIterator_Object_MutableReference_Object_ConstantIterator_Hole_0(
    compiler::CodeAssemblerState* state_, TorqueStructSliceIterator_Object_MutableReference_Object_0 p_first, TorqueStructConstantIterator_Hole_0 p_second);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=159&c=10
TNode<FixedArray> NewFixedArray_IteratorSequence_Object_SliceIterator_Object_MutableReference_Object_ConstantIterator_Hole_0(
    compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length,
    TorqueStructIteratorSequence_Object_SliceIterator_Object_MutableReference_Object_ConstantIterator_Hole_0 p_it);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=173&c=11
TorqueStructConstantIterator_float64_or_hole_0 ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructfloat64_or_hole_0 p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=171&c=7
TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_MutableReference_float64_or_hole_ConstantIterator_float64_or_hole_0
IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_MutableReference_float64_or_hole_ConstantIterator_float64_or_hole_0(
    compiler::CodeAssemblerState* state_, TorqueStructSliceIterator_float64_or_hole_MutableReference_float64_or_hole_0 p_first,
    TorqueStructConstantIterator_float64_or_hole_0 p_second);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=169&c=10
TNode<FixedArrayBase>
NewFixedDoubleArray_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_MutableReference_float64_or_hole_ConstantIterator_float64_or_hole_0(
    compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length,
    TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_MutableReference_float64_or_hole_ConstantIterator_float64_or_hole_0 p_it);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
TorqueStructSlice_MaybeObject_MutableReference_MaybeObject_0 NewMutableSlice_MaybeObject_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=33&c=3
TorqueStructSlice_float64_or_hole_MutableReference_float64_or_hole_0 NewMutableSlice_float64_or_hole_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=28&c=3
TorqueStructSlice_Smi_OR_TrustedObject_MutableReference_Smi_OR_TrustedObject_0 NewMutableSlice_Smi_OR_TrustedObject_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=186&c=10
void InitializeFieldsFromIterator_Object_ArgumentsIterator_0(
    compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_MutableReference_Object_0 p_target, TorqueStructArgumentsIterator_0 p_originIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=186&c=10
void InitializeFieldsFromIterator_Object_ParameterValueIterator_0(
    compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_MutableReference_Object_0 p_target, TorqueStructParameterValueIterator_0 p_originIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=186&c=10
void InitializeFieldsFromIterator_Object_IteratorSequence_Object_SliceIterator_Object_MutableReference_Object_ConstantIterator_Hole_0(
    compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_MutableReference_Object_0 p_target,
    TorqueStructIteratorSequence_Object_SliceIterator_Object_MutableReference_Object_ConstantIterator_Hole_0 p_originIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=196&c=10
void InitializeFieldsFromIterator_float64_or_hole_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_MutableReference_float64_or_hole_ConstantIterator_float64_or_hole_0(
    compiler::CodeAssemblerState* state_, TorqueStructSlice_float64_or_hole_MutableReference_float64_or_hole_0 p_target,
    TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_MutableReference_float64_or_hole_ConstantIterator_float64_or_hole_0
        p_originIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=186&c=10
void InitializeFieldsFromIterator_Object_ConstantIterator_TheHole_0(
    compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_MutableReference_Object_0 p_target, TorqueStructConstantIterator_TheHole_0 p_originIterator);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_FIXED_ARRAY_TQ_CSA_H_
