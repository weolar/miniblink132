#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TURBOSHAFT_TYPES_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TURBOSHAFT_TYPES_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=17&c=1
TNode<TurboshaftType> Cast_TurboshaftType_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=20&c=1
TNode<TurboshaftWord32Type> Cast_TurboshaftWord32Type_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=25&c=1
TNode<TurboshaftWord32RangeType> Cast_TurboshaftWord32RangeType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=33&c=1
TNode<TurboshaftWord32SetType> Cast_TurboshaftWord32SetType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=41&c=1
TNode<TurboshaftWord64Type> Cast_TurboshaftWord64Type_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=46&c=1
TNode<TurboshaftWord64RangeType> Cast_TurboshaftWord64RangeType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=56&c=1
TNode<TurboshaftWord64SetType> Cast_TurboshaftWord64SetType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=65&c=1
TNode<TurboshaftFloat64Type> Cast_TurboshaftFloat64Type_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=72&c=1
TNode<TurboshaftFloat64RangeType> Cast_TurboshaftFloat64RangeType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=81&c=1
TNode<TurboshaftFloat64SetType> Cast_TurboshaftFloat64SetType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=89&c=1
TNode<BoolT> TestTurboshaftWord32Type_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_value, TNode<TurboshaftWord32Type> p_expected);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=110&c=1
TNode<Int32T> CompareUint64HighLow_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_lhsHigh, TNode<Uint32T> p_lhsLow, TNode<Uint32T> p_rhsHigh, TNode<Uint32T> p_rhsLow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=120&c=1
TNode<BoolT> TestTurboshaftWord64Type_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_valueHigh, TNode<Uint32T> p_valueLow, TNode<TurboshaftWord64Type> p_expected);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=153&c=1
TNode<BoolT> TestTurboshaftFloat64Type_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_value, TNode<TurboshaftFloat64Type> p_expected);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=29&c=3
TNode<Uint32T> LoadTurboshaftWord32RangeTypeFrom_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord32RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=29&c=3
void StoreTurboshaftWord32RangeTypeFrom_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord32RangeType> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=30&c=3
TNode<Uint32T> LoadTurboshaftWord32RangeTypeTo_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord32RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=30&c=3
void StoreTurboshaftWord32RangeTypeTo_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord32RangeType> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=37&c=9
TNode<Uint32T> LoadTurboshaftWord32SetTypeSetSize_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord32SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
TorqueStructSlice_uint32_MutableReference_uint32_0 FieldSliceTurboshaftWord32SetTypeElements_0(
    compiler::CodeAssemblerState* state_, TNode<TurboshaftWord32SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
TNode<Uint32T> LoadTurboshaftWord32SetTypeElements_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord32SetType> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
void StoreTurboshaftWord32SetTypeElements_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord32SetType> p_o, TNode<IntPtrT> p_i, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=50&c=3
TNode<Uint32T> LoadTurboshaftWord64RangeTypeFromHigh_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=50&c=3
void StoreTurboshaftWord64RangeTypeFromHigh_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64RangeType> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=51&c=3
TNode<Uint32T> LoadTurboshaftWord64RangeTypeFromLow_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=51&c=3
void StoreTurboshaftWord64RangeTypeFromLow_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64RangeType> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=52&c=3
TNode<Uint32T> LoadTurboshaftWord64RangeTypeToHigh_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=52&c=3
void StoreTurboshaftWord64RangeTypeToHigh_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64RangeType> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=53&c=3
TNode<Uint32T> LoadTurboshaftWord64RangeTypeToLow_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=53&c=3
void StoreTurboshaftWord64RangeTypeToLow_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64RangeType> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=60&c=9
TNode<Uint32T> LoadTurboshaftWord64SetTypeSetSize_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
TorqueStructSlice_uint32_MutableReference_uint32_0 FieldSliceTurboshaftWord64SetTypeElementsHigh_0(
    compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
TNode<Uint32T> LoadTurboshaftWord64SetTypeElementsHigh_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64SetType> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
void StoreTurboshaftWord64SetTypeElementsHigh_0(
    compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64SetType> p_o, TNode<IntPtrT> p_i, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
TorqueStructSlice_uint32_MutableReference_uint32_0 FieldSliceTurboshaftWord64SetTypeElementsLow_0(
    compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
TNode<Uint32T> LoadTurboshaftWord64SetTypeElementsLow_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64SetType> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
void StoreTurboshaftWord64SetTypeElementsLow_0(
    compiler::CodeAssemblerState* state_, TNode<TurboshaftWord64SetType> p_o, TNode<IntPtrT> p_i, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=69&c=3
TNode<Uint32T> LoadTurboshaftFloat64TypeSpecialValues_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64Type> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=69&c=3
void StoreTurboshaftFloat64TypeSpecialValues_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64Type> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=76&c=3
TNode<Uint32T> LoadTurboshaftFloat64RangeTypePadding_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=76&c=3
void StoreTurboshaftFloat64RangeTypePadding_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64RangeType> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=77&c=3
TNode<Float64T> LoadTurboshaftFloat64RangeTypeMin_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=77&c=3
void StoreTurboshaftFloat64RangeTypeMin_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64RangeType> p_o, TNode<Float64T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=78&c=3
TNode<Float64T> LoadTurboshaftFloat64RangeTypeMax_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64RangeType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=78&c=3
void StoreTurboshaftFloat64RangeTypeMax_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64RangeType> p_o, TNode<Float64T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=85&c=9
TNode<Uint32T> LoadTurboshaftFloat64SetTypeSetSize_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
TorqueStructSlice_float64_MutableReference_float64_0 FieldSliceTurboshaftFloat64SetTypeElements_0(
    compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
TNode<Float64T> LoadTurboshaftFloat64SetTypeElements_0(compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64SetType> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
void StoreTurboshaftFloat64SetTypeElements_0(
    compiler::CodeAssemblerState* state_, TNode<TurboshaftFloat64SetType> p_o, TNode<IntPtrT> p_i, TNode<Float64T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=17&c=1
TNode<TurboshaftType> DownCastForTorqueClass_TurboshaftType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=20&c=1
TNode<TurboshaftWord32Type> DownCastForTorqueClass_TurboshaftWord32Type_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=25&c=1
TNode<TurboshaftWord32RangeType> DownCastForTorqueClass_TurboshaftWord32RangeType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=33&c=1
TNode<TurboshaftWord32SetType> DownCastForTorqueClass_TurboshaftWord32SetType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=41&c=1
TNode<TurboshaftWord64Type> DownCastForTorqueClass_TurboshaftWord64Type_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=46&c=1
TNode<TurboshaftWord64RangeType> DownCastForTorqueClass_TurboshaftWord64RangeType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=56&c=1
TNode<TurboshaftWord64SetType> DownCastForTorqueClass_TurboshaftWord64SetType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=65&c=1
TNode<TurboshaftFloat64Type> DownCastForTorqueClass_TurboshaftFloat64Type_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=72&c=1
TNode<TurboshaftFloat64RangeType> DownCastForTorqueClass_TurboshaftFloat64RangeType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=81&c=1
TNode<TurboshaftFloat64SetType> DownCastForTorqueClass_TurboshaftFloat64SetType_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
TorqueStructSlice_uint32_MutableReference_uint32_0 NewMutableSlice_uint32_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
TorqueStructSlice_float64_MutableReference_float64_0 NewMutableSlice_float64_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TURBOSHAFT_TYPES_TQ_CSA_H_
