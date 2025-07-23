#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STRING_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STRING_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=7&c=1
TNode<String> Cast_String_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=50&c=1
TNode<Uint32T> FromConstexpr_StringRepresentationTag_constexpr_kSeqStringTag_0(compiler::CodeAssemblerState* state_, StringRepresentationTag p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=50&c=1
TNode<Uint32T> FromConstexpr_StringRepresentationTag_constexpr_kConsStringTag_0(compiler::CodeAssemblerState* state_, StringRepresentationTag p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=50&c=1
TNode<Uint32T> FromConstexpr_StringRepresentationTag_constexpr_kExternalStringTag_0(compiler::CodeAssemblerState* state_, StringRepresentationTag p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=50&c=1
TNode<Uint32T> FromConstexpr_StringRepresentationTag_constexpr_kSlicedStringTag_0(compiler::CodeAssemblerState* state_, StringRepresentationTag p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=50&c=1
TNode<Uint32T> FromConstexpr_StringRepresentationTag_constexpr_kThinStringTag_0(compiler::CodeAssemblerState* state_, StringRepresentationTag p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=189&c=1
TNode<SeqOneByteString> AllocateNonEmptySeqOneByteString_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=192&c=1
TNode<SeqTwoByteString> AllocateNonEmptySeqTwoByteString_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=208&c=1
TNode<String> AllocateSeqOneByteString_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=214&c=1
TNode<String> AllocateSeqTwoByteString_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=261&c=1
TNode<String> Flatten_0(compiler::CodeAssemblerState* state_, TNode<String> p_string);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=275&c=1
TNode<String> Flatten_1(compiler::CodeAssemblerState* state_, TNode<ConsString> p_cons);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=346&c=1
void StaticAssertStringLengthFitsSmi_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=363&c=1
TNode<IntPtrT> AbstractStringIndexOf_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_subject, TNode<IntPtrT> p_subjectLen, TNode<RawPtrT> p_search,
    TNode<IntPtrT> p_searchLen, TNode<IntPtrT> p_fromIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=369&c=1
TNode<IntPtrT> AbstractStringIndexOf_1(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_subject, TNode<IntPtrT> p_subjectLen, TNode<RawPtrT> p_search,
    TNode<IntPtrT> p_searchLen, TNode<IntPtrT> p_fromIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=378&c=1
TNode<IntPtrT> AbstractStringIndexOf_2(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_subject, TNode<IntPtrT> p_subjectLen, TNode<RawPtrT> p_search,
    TNode<IntPtrT> p_searchLen, TNode<IntPtrT> p_fromIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=384&c=1
TNode<IntPtrT> AbstractStringIndexOf_3(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_subject, TNode<IntPtrT> p_subjectLen, TNode<RawPtrT> p_search,
    TNode<IntPtrT> p_searchLen, TNode<IntPtrT> p_fromIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=405&c=1
TNode<Smi> AbstractStringIndexOf_4(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<String> p_string, TNode<String> p_searchString, TNode<Smi> p_fromIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=47&c=9
TNode<Int32T> LoadStringLength_0(compiler::CodeAssemblerState* state_, TNode<String> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=11&c=3
TNode<Uint16T> Method_String_StringInstanceType_0(compiler::CodeAssemblerState* state_, TNode<String> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=16&c=3
TNode<BoolT> Method_String_IsNotInternalized_0(compiler::CodeAssemblerState* state_, TNode<String> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=21&c=3
TNode<BoolT> Method_String_IsOneByteRepresentationUnderneath_0(compiler::CodeAssemblerState* state_, TNode<String> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=78&c=3
TNode<String> LoadConsStringFirst_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=78&c=3
void StoreConsStringFirst_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=79&c=3
TNode<String> LoadConsStringSecond_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=79&c=3
void StoreConsStringSecond_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=70&c=3
TNode<BoolT> Method_ConsString_IsFlat_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=74&c=3
TNode<BoolT> Method_ConsString_IsOneByteRepresentation_0(compiler::CodeAssemblerState* state_, TNode<ConsString> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=86&c=3
TNode<ExternalPointerT> LoadExternalStringResource_0(compiler::CodeAssemblerState* state_, TNode<ExternalString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=86&c=3
void StoreExternalStringResource_0(compiler::CodeAssemblerState* state_, TNode<ExternalString> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=88&c=3
TNode<ExternalPointerT> LoadExternalStringResourceData_0(compiler::CodeAssemblerState* state_, TNode<ExternalString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=88&c=3
void StoreExternalStringResourceData_0(compiler::CodeAssemblerState* state_, TNode<ExternalString> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=108&c=3
TNode<RawPtrT> Method_ExternalOneByteString_GetChars_0(compiler::CodeAssemblerState* state_, TNode<ExternalOneByteString> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=120&c=3
TNode<RawPtrT> Method_ExternalTwoByteString_GetChars_0(compiler::CodeAssemblerState* state_, TNode<ExternalTwoByteString> p_this);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=141&c=9
TorqueStructSlice_char8_ConstReference_char8_0 FieldSliceSeqOneByteStringChars_0(compiler::CodeAssemblerState* state_, TNode<SeqOneByteString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=141&c=9
TNode<Uint8T> LoadSeqOneByteStringChars_0(compiler::CodeAssemblerState* state_, TNode<SeqOneByteString> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=147&c=9
TorqueStructSlice_char16_ConstReference_char16_0 FieldSliceSeqTwoByteStringChars_0(compiler::CodeAssemblerState* state_, TNode<SeqTwoByteString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=147&c=9
TNode<Uint16T> LoadSeqTwoByteStringChars_0(compiler::CodeAssemblerState* state_, TNode<SeqTwoByteString> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=153&c=3
TNode<String> LoadSlicedStringParent_0(compiler::CodeAssemblerState* state_, TNode<SlicedString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=153&c=3
void StoreSlicedStringParent_0(compiler::CodeAssemblerState* state_, TNode<SlicedString> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=154&c=3
TNode<Smi> LoadSlicedStringOffset_0(compiler::CodeAssemblerState* state_, TNode<SlicedString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=154&c=3
void StoreSlicedStringOffset_0(compiler::CodeAssemblerState* state_, TNode<SlicedString> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=160&c=3
TNode<String> LoadThinStringActual_0(compiler::CodeAssemblerState* state_, TNode<ThinString> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=160&c=3
void StoreThinStringActual_0(compiler::CodeAssemblerState* state_, TNode<ThinString> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=289&c=22
TorqueStructSlice_char8_ConstReference_char8_0 Subslice_char8_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char8_ConstReference_char8_0 p_slice,
    TNode<IntPtrT> p_start, TNode<IntPtrT> p_length, compiler::CodeAssemblerLabel* label_OutOfBounds);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=292&c=22
TorqueStructSlice_char16_ConstReference_char16_0 Subslice_char16_0(compiler::CodeAssemblerState* state_,
    TorqueStructSlice_char16_ConstReference_char16_0 p_slice, TNode<IntPtrT> p_start, TNode<IntPtrT> p_length, compiler::CodeAssemblerLabel* label_OutOfBounds);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=305&c=22
TorqueStructSlice_char8_ConstReference_char8_0 NewOffHeapConstSlice_char8_0(
    compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_startPointer, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=310&c=22
TorqueStructSlice_char16_ConstReference_char16_0 NewOffHeapConstSlice_char16_0(
    compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_startPointer, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=7&c=1
TNode<String> DownCastForTorqueClass_String_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=190&c=10
TNode<SeqOneByteString> AllocateNonEmptySeqOneByteString_UninitializedIterator_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructUninitializedIterator_0 p_content);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=193&c=10
TNode<SeqTwoByteString> AllocateNonEmptySeqTwoByteString_UninitializedIterator_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructUninitializedIterator_0 p_content);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=211&c=10
TNode<String> AllocateSeqOneByteString_UninitializedIterator_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructUninitializedIterator_0 p_content);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=217&c=10
TNode<String> AllocateSeqTwoByteString_UninitializedIterator_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructUninitializedIterator_0 p_content);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=249&c=23
TNode<SeqTwoByteString> UnsafeCast_SeqTwoByteString_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=267&c=15
TNode<BoolT> Is_ConsString_String_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<String> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=422&c=10
TNode<Smi> TwoStringsToSlices_Smi_AbstractStringIndexOfFunctor_0(
    compiler::CodeAssemblerState* state_, TNode<String> p_s1, TNode<String> p_s2, TorqueStructAbstractStringIndexOfFunctor_0 p_f);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=13&c=9
TNode<Uint16T> Convert_uint16_InstanceType_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=141&c=9
TorqueStructSlice_char8_ConstReference_char8_0 NewConstSlice_char8_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=331&c=14
TNode<BoolT> Call_char8_char8_0(compiler::CodeAssemblerState* state_, TorqueStructIsSubstringAtFunctor_0 p_self,
    TorqueStructSlice_char8_ConstReference_char8_0 p_string, TorqueStructSlice_char8_ConstReference_char8_0 p_searchStr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=333&c=14
TNode<BoolT> Call_char8_char16_0(compiler::CodeAssemblerState* state_, TorqueStructIsSubstringAtFunctor_0 p_self,
    TorqueStructSlice_char8_ConstReference_char8_0 p_string, TorqueStructSlice_char16_ConstReference_char16_0 p_searchStr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=339&c=14
TNode<BoolT> Call_char16_char8_0(compiler::CodeAssemblerState* state_, TorqueStructIsSubstringAtFunctor_0 p_self,
    TorqueStructSlice_char16_ConstReference_char16_0 p_string, TorqueStructSlice_char8_ConstReference_char8_0 p_searchStr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=341&c=14
TNode<BoolT> Call_char16_char16_0(compiler::CodeAssemblerState* state_, TorqueStructIsSubstringAtFunctor_0 p_self,
    TorqueStructSlice_char16_ConstReference_char16_0 p_string, TorqueStructSlice_char16_ConstReference_char16_0 p_searchStr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=331&c=14
TNode<Smi> Call_char8_char8_1(compiler::CodeAssemblerState* state_, TorqueStructAbstractStringIndexOfFunctor_0 p_self,
    TorqueStructSlice_char8_ConstReference_char8_0 p_string, TorqueStructSlice_char8_ConstReference_char8_0 p_searchStr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=333&c=14
TNode<Smi> Call_char8_char16_1(compiler::CodeAssemblerState* state_, TorqueStructAbstractStringIndexOfFunctor_0 p_self,
    TorqueStructSlice_char8_ConstReference_char8_0 p_string, TorqueStructSlice_char16_ConstReference_char16_0 p_searchStr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=339&c=14
TNode<Smi> Call_char16_char8_1(compiler::CodeAssemblerState* state_, TorqueStructAbstractStringIndexOfFunctor_0 p_self,
    TorqueStructSlice_char16_ConstReference_char16_0 p_string, TorqueStructSlice_char8_ConstReference_char8_0 p_searchStr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=341&c=14
TNode<Smi> Call_char16_char16_1(compiler::CodeAssemblerState* state_, TorqueStructAbstractStringIndexOfFunctor_0 p_self,
    TorqueStructSlice_char16_ConstReference_char16_0 p_string, TorqueStructSlice_char16_ConstReference_char16_0 p_searchStr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=205&c=10
TNode<SeqTwoByteString> AllocateNonEmptySeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructSliceIterator_char16_ConstReference_char16_0 p_content);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=170&c=10
void InitializeFieldsFromIterator_char8_TwoByteToOneByteIterator_0(
    compiler::CodeAssemblerState* state_, TorqueStructSlice_char8_MutableReference_char8_0 p_target, TorqueStructTwoByteToOneByteIterator_0 p_originIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=170&c=10
void InitializeFieldsFromIterator_char8_SliceIterator_char8_ConstReference_char8_0(compiler::CodeAssemblerState* state_,
    TorqueStructSlice_char8_MutableReference_char8_0 p_target, TorqueStructSliceIterator_char8_ConstReference_char8_0 p_originIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=181&c=10
void InitializeFieldsFromIterator_char16_SliceIterator_char16_ConstReference_char16_0(compiler::CodeAssemblerState* state_,
    TorqueStructSlice_char16_MutableReference_char16_0 p_target, TorqueStructSliceIterator_char16_ConstReference_char16_0 p_originIterator);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STRING_TQ_CSA_H_
