#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_CELL_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_CELL_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=6&c=1
TNode<PropertyCell> Cast_PropertyCell_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=14&c=1
TNode<ContextSidePropertyCell> Cast_ContextSidePropertyCell_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=19&c=1
TNode<IntPtrT> kContextSidePropertyOther_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=20&c=1
TNode<IntPtrT> kContextSidePropertyConst_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=21&c=1
TNode<IntPtrT> kContextSidePropertySmi_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=22&c=1
TNode<IntPtrT> kContextSidePropertyHeapNumber_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
TNode<Name> LoadPropertyCellName_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
void StorePropertyCellName_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o, TNode<Name> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=8&c=3
TNode<Smi> LoadPropertyCellPropertyDetailsRaw_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=8&c=3
void StorePropertyCellPropertyDetailsRaw_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
TNode<Object> LoadPropertyCellValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
void StorePropertyCellValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
TNode<WeakArrayList> LoadPropertyCellDependentCode_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
void StorePropertyCellDependentCode_0(compiler::CodeAssemblerState* state_, TNode<PropertyCell> p_o, TNode<WeakArrayList> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=15&c=3
TNode<Smi> LoadContextSidePropertyCellPropertyDetailsRaw_0(compiler::CodeAssemblerState* state_, TNode<ContextSidePropertyCell> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=15&c=3
void StoreContextSidePropertyCellPropertyDetailsRaw_0(compiler::CodeAssemblerState* state_, TNode<ContextSidePropertyCell> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
TNode<WeakArrayList> LoadContextSidePropertyCellDependentCode_0(compiler::CodeAssemblerState* state_, TNode<ContextSidePropertyCell> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
void StoreContextSidePropertyCellDependentCode_0(compiler::CodeAssemblerState* state_, TNode<ContextSidePropertyCell> p_o, TNode<WeakArrayList> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=6&c=1
TNode<PropertyCell> DownCastForTorqueClass_PropertyCell_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=14&c=1
TNode<ContextSidePropertyCell> DownCastForTorqueClass_ContextSidePropertyCell_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_CELL_TQ_CSA_H_
