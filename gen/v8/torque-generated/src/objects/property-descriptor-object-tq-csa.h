#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_DESCRIPTOR_OBJECT_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_DESCRIPTOR_OBJECT_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
TNode<PropertyDescriptorObject> Cast_PropertyDescriptorObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=53&c=1
TNode<BoolT> IsCompatiblePropertyDescriptor_0(
    compiler::CodeAssemblerState* state_, TNode<BoolT> p__extensible, TNode<PropertyDescriptorObject> p_newDesc, TNode<PropertyDescriptorObject> p_current);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=99&c=1
TNode<BoolT> IsCompatiblePropertyDescriptor_1(
    compiler::CodeAssemblerState* state_, TNode<BoolT> p_extensible, TNode<HeapObject> p_newDesc, TNode<PropertyDescriptorObject> p_current);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=114&c=1
TNode<BoolT> IsCompatiblePropertyDescriptor_2(
    compiler::CodeAssemblerState* state_, TNode<BoolT> p_extensible, TNode<HeapObject> p_newDesc, TNode<HeapObject> p_current);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=131&c=1
void CompletePropertyDescriptor_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_desc);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
TNode<Smi> LoadPropertyDescriptorObjectFlags_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
void StorePropertyDescriptorObjectFlags_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
TNode<Object> LoadPropertyDescriptorObjectValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
void StorePropertyDescriptorObjectValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
TNode<Object> LoadPropertyDescriptorObjectGet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
void StorePropertyDescriptorObjectGet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
TNode<Object> LoadPropertyDescriptorObjectSet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
void StorePropertyDescriptorObjectSet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=20&c=3
TNode<BoolT> Method_PropertyDescriptorObject_IsDataDescriptor_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=24&c=3
TNode<BoolT> Method_PropertyDescriptorObject_IsAccessorDescriptor_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=28&c=3
TNode<BoolT> Method_PropertyDescriptorObject_IsGenericDescriptor_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=35&c=3
TNode<BoolT> Method_PropertyDescriptorObject_IsEmptyOrEquivalentTo_0(
    compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_this, TNode<PropertyDescriptorObject> p_current);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
TNode<PropertyDescriptorObject> DownCastForTorqueClass_PropertyDescriptorObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROPERTY_DESCRIPTOR_OBJECT_TQ_CSA_H_
