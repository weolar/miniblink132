#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TORQUE_INTERNAL_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TORQUE_INTERNAL_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=257&c=1
TNode<IntPtrT> AddIndexedFieldSizeToObjectSize_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_baseSize, TNode<IntPtrT> p_arrayLength, int32_t p_fieldSize);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=266&c=1
TNode<IntPtrT> AlignTagged_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_x);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=271&c=1
TNode<BoolT> IsTaggedAligned_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_x);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=275&c=1
TNode<BoolT> ValidAllocationSize_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_sizeInBytes, TNode<Map> p_map);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=289&c=1
TNode<HeapObject> AllocateFromNew_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_sizeInBytes, TNode<Map> p_map, TNode<BoolT> p_pretenured, TNode<BoolT> p_clearPadding);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=318&c=1
void InitializeFieldsFromIterator_char8_UninitializedIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char8_MutableReference_char8_0 p__target, TorqueStructUninitializedIterator_0 p__originIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=321&c=1
void InitializeFieldsFromIterator_char16_UninitializedIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char16_MutableReference_char16_0 p__target, TorqueStructUninitializedIterator_0 p__originIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=328&c=1
TorqueStructfloat64_or_hole_0 LoadFloat64OrHole_0(compiler::CodeAssemblerState* state_, TorqueStructReference_float64_or_hole_0 p_r);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=335&c=1
void StoreFloat64OrHole_0(compiler::CodeAssemblerState* state_, TorqueStructReference_float64_or_hole_0 p_r, TorqueStructfloat64_or_hole_0 p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=386&c=1
TNode<HeapObject> GetAndResetPendingMessage_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_Object_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_Object_0 NewReference_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_float64_or_hole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_float64_or_hole_0 NewReference_float64_or_hole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_Smi_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_Smi_OR_TheHole_0 NewReference_Smi_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=125&c=23
TNode<IntPtrT> Convert_intptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_DescriptorEntry_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_DescriptorEntry_0 NewReference_DescriptorEntry_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_CoverageInfoSlot_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_CoverageInfoSlot_0 NewReference_CoverageInfoSlot_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_char8_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_char8_0 NewReference_char8_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_MaybeObject_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_MaybeObject_0 NewReference_MaybeObject_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=303&c=6
TorqueStructReference_Zero_0 NewReference_Zero_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=332&c=13
TorqueStructReference_float64_0 NewReference_float64_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_String_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_String_0 NewReference_String_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_NameToIndexHashTable_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_NameToIndexHashTable_0 NewReference_NameToIndexHashTable_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_uint32_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_uint32_0 NewReference_uint32_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_float64_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=238&c=22
TorqueStructReference_char16_0 NewReference_char16_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_int32_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_int32_0 NewReference_int32_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_char16_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_uint8_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_uint8_0 NewReference_uint8_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_Context_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_Context_0 NewReference_Context_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_Smi_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_Smi_0 NewReference_Smi_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_SmiTagged_VariableProperties_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_SmiTagged_VariableProperties_0 NewReference_SmiTagged_VariableProperties_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_Undefined_OR_String_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_Undefined_OR_String_0 NewReference_Undefined_OR_String_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_TheHole_OR_ScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_TheHole_OR_ScopeInfo_0 NewReference_TheHole_OR_ScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_SourceTextModuleInfo_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_SourceTextModuleInfo_0 NewReference_SourceTextModuleInfo_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_FeedbackCell_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_FeedbackCell_0 NewReference_FeedbackCell_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_Smi_OR_TrustedObject_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_Smi_OR_TrustedObject_0 NewReference_Smi_OR_TrustedObject_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0 NewReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_FunctionVariableInfo_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_FunctionVariableInfo_0 NewReference_FunctionVariableInfo_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_ModuleVariable_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_ModuleVariable_0 NewReference_ModuleVariable_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_HashMapEntry_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_HashMapEntry_0 NewReference_HashMapEntry_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_NameDictionaryEntry_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_NameDictionaryEntry_0 NewReference_NameDictionaryEntry_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
TNode<IntPtrT> TimesSizeOf_InternalClassStructElement_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
TorqueStructReference_InternalClassStructElement_0 NewReference_InternalClassStructElement_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=213&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_char8_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=213&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_char16_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_RawPtr_int32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=213&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_int32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=16&c=10
TorqueStructSlice_int32_ConstReference_int32_0 NewConstSlice_int32_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_JSReceiver_0 NewReference_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_JSAny_0 NewReference_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_JSPromise_0 NewReference_JSPromise_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Number_0 NewReference_Number_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Boolean_0 NewReference_Boolean_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_PromiseCapability_0 NewReference_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=90&c=3
TNode<PromiseCapability> UnsafeCast_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_FixedArray_0 NewReference_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Callable_0 NewReference_Callable_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Constructor_0 NewReference_Constructor_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Null_OR_JSProxy_0 NewReference_Null_OR_JSProxy_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=90&c=3
TNode<HeapObject> UnsafeCast_Null_OR_JSProxy_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Map_0 NewReference_Map_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_HeapObject_0 NewReference_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_WasmCodePointer_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_bool_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_int64_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_float64_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_float32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=84&c=29
TNode<RawPtrT> Convert_WasmCodePointer_RawPtr_uintptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_ScopeInfo_0 NewReference_ScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=90&c=3
TNode<ScopeInfo> UnsafeCast_ScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Undefined_OR_JSFunction_0 NewReference_Undefined_OR_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=90&c=3
TNode<HeapObject> UnsafeCast_Undefined_OR_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_JSFunction_0 NewReference_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=90&c=3
TNode<JSFunction> UnsafeCast_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_JSObject_0 NewReference_JSObject_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Undefined_OR_FixedArray_0 NewReference_Undefined_OR_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=90&c=3
TNode<HeapObject> UnsafeCast_Undefined_OR_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_RegExpMatchInfo_0 NewReference_RegExpMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_FixedDoubleArray_0 NewReference_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=89&c=15
TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0 NewReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=90&c=3
TNode<HeapObject> UnsafeCast_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TORQUE_INTERNAL_TQ_CSA_H_
