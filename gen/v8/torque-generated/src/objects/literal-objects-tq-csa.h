#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_LITERAL_OBJECTS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_LITERAL_OBJECTS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
TNode<ObjectBoilerplateDescription> Cast_ObjectBoilerplateDescription_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=1
TNode<ArrayBoilerplateDescription> Cast_ArrayBoilerplateDescription_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=18&c=1
TNode<RegExpBoilerplateDescription> Cast_RegExpBoilerplateDescription_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=25&c=1
TNode<ClassBoilerplate> Cast_ClassBoilerplate_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=7&c=9
TNode<Smi> LoadObjectBoilerplateDescriptionLength_0(compiler::CodeAssemblerState* state_, TNode<ObjectBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=8&c=3
TNode<Smi> LoadObjectBoilerplateDescriptionBackingStoreSize_0(compiler::CodeAssemblerState* state_, TNode<ObjectBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=8&c=3
void StoreObjectBoilerplateDescriptionBackingStoreSize_0(compiler::CodeAssemblerState* state_, TNode<ObjectBoilerplateDescription> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=9&c=3
TNode<Smi> LoadObjectBoilerplateDescriptionFlags_0(compiler::CodeAssemblerState* state_, TNode<ObjectBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=9&c=3
void StoreObjectBoilerplateDescriptionFlags_0(compiler::CodeAssemblerState* state_, TNode<ObjectBoilerplateDescription> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=3
TorqueStructSlice_Object_MutableReference_Object_0 FieldSliceObjectBoilerplateDescriptionRawEntries_0(
    compiler::CodeAssemblerState* state_, TNode<ObjectBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=3
TNode<Object> LoadObjectBoilerplateDescriptionRawEntries_0(compiler::CodeAssemblerState* state_, TNode<ObjectBoilerplateDescription> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=3
void StoreObjectBoilerplateDescriptionRawEntries_0(
    compiler::CodeAssemblerState* state_, TNode<ObjectBoilerplateDescription> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=14&c=3
TNode<Smi> LoadArrayBoilerplateDescriptionFlags_0(compiler::CodeAssemblerState* state_, TNode<ArrayBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=14&c=3
void StoreArrayBoilerplateDescriptionFlags_0(compiler::CodeAssemblerState* state_, TNode<ArrayBoilerplateDescription> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
TNode<FixedArrayBase> LoadArrayBoilerplateDescriptionConstantElements_0(compiler::CodeAssemblerState* state_, TNode<ArrayBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
void StoreArrayBoilerplateDescriptionConstantElements_0(
    compiler::CodeAssemblerState* state_, TNode<ArrayBoilerplateDescription> p_o, TNode<FixedArrayBase> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=20&c=3
TNode<TrustedPointerT> LoadRegExpBoilerplateDescriptionData_0(compiler::CodeAssemblerState* state_, TNode<RegExpBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=20&c=3
void StoreRegExpBoilerplateDescriptionData_0(compiler::CodeAssemblerState* state_, TNode<RegExpBoilerplateDescription> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=21&c=3
TNode<String> LoadRegExpBoilerplateDescriptionSource_0(compiler::CodeAssemblerState* state_, TNode<RegExpBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=21&c=3
void StoreRegExpBoilerplateDescriptionSource_0(compiler::CodeAssemblerState* state_, TNode<RegExpBoilerplateDescription> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=22&c=3
TNode<Smi> LoadRegExpBoilerplateDescriptionFlags_0(compiler::CodeAssemblerState* state_, TNode<RegExpBoilerplateDescription> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=22&c=3
void StoreRegExpBoilerplateDescriptionFlags_0(compiler::CodeAssemblerState* state_, TNode<RegExpBoilerplateDescription> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=27&c=3
TNode<Smi> LoadClassBoilerplateArgumentsCount_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=27&c=3
void StoreClassBoilerplateArgumentsCount_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=28&c=3
TNode<Object> LoadClassBoilerplateStaticPropertiesTemplate_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=28&c=3
void StoreClassBoilerplateStaticPropertiesTemplate_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=29&c=3
TNode<Object> LoadClassBoilerplateStaticElementsTemplate_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=29&c=3
void StoreClassBoilerplateStaticElementsTemplate_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=30&c=3
TNode<FixedArray> LoadClassBoilerplateStaticComputedProperties_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=30&c=3
void StoreClassBoilerplateStaticComputedProperties_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=31&c=3
TNode<Object> LoadClassBoilerplateInstancePropertiesTemplate_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=31&c=3
void StoreClassBoilerplateInstancePropertiesTemplate_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=32&c=3
TNode<Object> LoadClassBoilerplateInstanceElementsTemplate_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=32&c=3
void StoreClassBoilerplateInstanceElementsTemplate_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=33&c=3
TNode<FixedArray> LoadClassBoilerplateInstanceComputedProperties_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=33&c=3
void StoreClassBoilerplateInstanceComputedProperties_0(compiler::CodeAssemblerState* state_, TNode<ClassBoilerplate> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
TNode<ObjectBoilerplateDescription> DownCastForTorqueClass_ObjectBoilerplateDescription_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=1
TNode<ArrayBoilerplateDescription> DownCastForTorqueClass_ArrayBoilerplateDescription_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=18&c=1
TNode<RegExpBoilerplateDescription> DownCastForTorqueClass_RegExpBoilerplateDescription_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=25&c=1
TNode<ClassBoilerplate> DownCastForTorqueClass_ClassBoilerplate_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_LITERAL_OBJECTS_TQ_CSA_H_
