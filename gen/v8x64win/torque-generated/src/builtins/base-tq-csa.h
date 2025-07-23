#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_BASE_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_BASE_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=79&c=1
TNode<HeapObject> MaybeObjectToStrong_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_maybeObject, compiler::CodeAssemblerLabel* label_IfCleared);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=188&c=1
TorqueStructfloat64_or_hole_0 kDoubleHole_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=230&c=1
TNode<OrderedHashMap> Cast_OrderedHashMap_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=231&c=1
TNode<OrderedHashSet> Cast_OrderedHashSet_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=232&c=1
TNode<OrderedNameDictionary> Cast_OrderedNameDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=233&c=1
TNode<NameToIndexHashTable> Cast_NameToIndexHashTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=234&c=1
TNode<RegisteredSymbolTable> Cast_RegisteredSymbolTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=235&c=1
TNode<NameDictionary> Cast_NameDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=236&c=1
TNode<GlobalDictionary> Cast_GlobalDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=237&c=1
TNode<SimpleNumberDictionary> Cast_SimpleNumberDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=238&c=1
TNode<EphemeronHashTable> Cast_EphemeronHashTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=241&c=1
TNode<NumberDictionary> Cast_NumberDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=255&c=1
TNode<InstructionStream> Cast_InstructionStream_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=261&c=1
TNode<TransitionArray> Cast_TransitionArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=296&c=1
TNode<Int32T> FromConstexpr_CallFeedbackContent_constexpr_kTarget_0(compiler::CodeAssemblerState* state_, CallFeedbackContent p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=296&c=1
TNode<Int32T> FromConstexpr_CallFeedbackContent_constexpr_kReceiver_0(compiler::CodeAssemblerState* state_, CallFeedbackContent p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=301&c=1
TNode<Int32T> FromConstexpr_PromiseState_constexpr_kPending_0(compiler::CodeAssemblerState* state_, Promise::PromiseState p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=301&c=1
TNode<Int32T> FromConstexpr_PromiseState_constexpr_kFulfilled_0(compiler::CodeAssemblerState* state_, Promise::PromiseState p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=301&c=1
TNode<Int32T> FromConstexpr_PromiseState_constexpr_kRejected_0(compiler::CodeAssemblerState* state_, Promise::PromiseState p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_NO_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_PACKED_SMI_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_HOLEY_SMI_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_PACKED_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_HOLEY_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_PACKED_DOUBLE_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_HOLEY_DOUBLE_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_LAST_ANY_NONEXTENSIBLE_ELEMENTS_KIND_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_DICTIONARY_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_UINT8_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_INT8_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_UINT16_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_INT16_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_UINT32_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_INT32_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_FLOAT16_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_FLOAT32_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_FLOAT64_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_UINT8_CLAMPED_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_BIGUINT64_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_BIGINT64_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_UINT8_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_INT8_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_UINT16_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_INT16_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_UINT32_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_INT32_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_FLOAT16_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_FLOAT32_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_FLOAT64_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_UINT8_CLAMPED_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_BIGUINT64_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=317&c=1
TNode<Int32T> FromConstexpr_ElementsKind_constexpr_RAB_GSAB_BIGINT64_ELEMENTS_0(compiler::CodeAssemblerState* state_, ElementsKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=359&c=1
ElementsKind kFirstFixedTypedArrayElementsKind_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=361&c=1
ElementsKind kFirstRabGsabFixedTypedArrayElementsKind_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=364&c=1
TNode<Int32T> FromConstexpr_AllocationFlag_constexpr_kNone_0(compiler::CodeAssemblerState* state_, CodeStubAssembler::AllocationFlag p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=364&c=1
TNode<Int32T> FromConstexpr_AllocationFlag_constexpr_kDoubleAlignment_0(compiler::CodeAssemblerState* state_, CodeStubAssembler::AllocationFlag p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=364&c=1
TNode<Int32T> FromConstexpr_AllocationFlag_constexpr_kPretenured_0(compiler::CodeAssemblerState* state_, CodeStubAssembler::AllocationFlag p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=391&c=1
TNode<IntPtrT> kBigIntDigitBits_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=496&c=1
TNode<Int32T> FromConstexpr_PropertyAttributes_constexpr_NONE_0(compiler::CodeAssemblerState* state_, PropertyAttributes p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=496&c=1
TNode<Int32T> FromConstexpr_PropertyAttributes_constexpr_READ_ONLY_0(compiler::CodeAssemblerState* state_, PropertyAttributes p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=496&c=1
TNode<Int32T> FromConstexpr_PropertyAttributes_constexpr_DONT_ENUM_0(compiler::CodeAssemblerState* state_, PropertyAttributes p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=496&c=1
TNode<Int32T> FromConstexpr_PropertyAttributes_constexpr_DONT_DELETE_0(compiler::CodeAssemblerState* state_, PropertyAttributes p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=496&c=1
TNode<Int32T> FromConstexpr_PropertyAttributes_constexpr_ALL_ATTRIBUTES_MASK_0(compiler::CodeAssemblerState* state_, PropertyAttributes p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=496&c=1
TNode<Int32T> FromConstexpr_PropertyAttributes_constexpr_FROZEN_0(compiler::CodeAssemblerState* state_, PropertyAttributes p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=518&c=1
TNode<UintPtrT> kSmiMax_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=603&c=1
TNode<Hole> TheHole_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=604&c=1
TNode<Hole> PromiseHole_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=605&c=1
TNode<Null> Null_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=606&c=1
TNode<Undefined> Undefined_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=607&c=1
TNode<True> True_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=608&c=1
TNode<False> False_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=609&c=1
TNode<String> kEmptyString_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=610&c=1
TNode<String> kLengthString_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=611&c=1
TNode<String> kMessageString_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=612&c=1
TNode<String> kNextString_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=613&c=1
TNode<String> kReturnString_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=614&c=1
TNode<String> kSizeString_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=615&c=1
TNode<String> kHasString_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=616&c=1
TNode<String> kKeysString_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=618&c=1
TNode<HeapNumber> kNaN_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=619&c=1
TNode<Smi> kZero_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=620&c=1
TNode<TaggedIndex> kZeroBitPattern_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=626&c=1
TNode<BoolT> FromConstexpr_LanguageMode_constexpr_kStrict_0(compiler::CodeAssemblerState* state_, LanguageMode p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=626&c=1
TNode<BoolT> FromConstexpr_LanguageMode_constexpr_kSloppy_0(compiler::CodeAssemblerState* state_, LanguageMode p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=634&c=1
TNode<JSDispatchHandleT> kInvalidDispatchHandle_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=644&c=1
TNode<HeapObject> Cast_Filler_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=664&c=1
TNode<JSSpecialObject> Cast_JSSpecialApiObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=667&c=1
TNode<JSObject> Cast_JSContextExtensionObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=669&c=1
TNode<JSObject> Cast_JSError_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=690&c=1
TNode<Number> ToIntegerImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_input);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=722&c=1
TNode<Number> ToInteger_Inline_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_input);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=737&c=1
TNode<Int32T> FromConstexpr_BigIntHandling_constexpr_kConvertToNumber_0(compiler::CodeAssemblerState* state_, CodeStubAssembler::BigIntHandling p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=737&c=1
TNode<Int32T> FromConstexpr_BigIntHandling_constexpr_kThrow_0(compiler::CodeAssemblerState* state_, CodeStubAssembler::BigIntHandling p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=861&c=1
TNode<Object> ToPrimitiveDefault_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=901&c=1
TNode<Boolean> Equal_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_left, TNode<Object> p_right);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=937&c=1
TNode<BoolT> ElementsKindNotEqual_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_k1, TNode<Int32T> p_k2);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=995&c=1
TNode<BoolT> IsNumberEqual_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=998&c=1
TNode<BoolT> IsNumberNotEqual_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1003&c=1
TNode<BoolT> NumberIsLessThan_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1008&c=1
TNode<BoolT> NumberIsLessThanOrEqual_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1012&c=1
TNode<BoolT> NumberIsGreaterThan_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1015&c=1
TNode<BoolT> NumberIsGreaterThanOrEqual_0(compiler::CodeAssemblerState* state_, TNode<Number> p_a, TNode<Number> p_b);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1021&c=1
TNode<BoolT> Float64IsNaN_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_n);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1199&c=1
TNode<Number> Min_0(compiler::CodeAssemblerState* state_, TNode<Number> p_x, TNode<Number> p_y);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1202&c=1
TNode<Number> Max_0(compiler::CodeAssemblerState* state_, TNode<Number> p_x, TNode<Number> p_y);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1240&c=1
TNode<UintPtrT> LoadJSArrayLengthAsUintPtr_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_array);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1246&c=1
TNode<UintPtrT> LoadStringLengthAsUintPtr_0(compiler::CodeAssemblerState* state_, TNode<String> p_s);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1254&c=1
TNode<String> StringAdd_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<String> p_a, TNode<String> p_b);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1259&c=1
TNode<BoolT> PromiseStateEquals_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_s1, TNode<Int32T> p_s2);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1347&c=1
TNode<Int32T> Int32Constant_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1360&c=1
TNode<Smi> SmiConstant_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_il);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1367&c=1
TNode<IntPtrT> IntPtrConstant_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_il);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1393&c=1
TNode<Map> kFixedArrayMap_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1394&c=1
TNode<Map> kFixedDoubleArrayMap_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1395&c=1
TNode<Map> kCOWMap_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1396&c=1
TNode<ByteArray> kEmptyByteArray_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1397&c=1
TNode<FixedArray> kEmptyFixedArray_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1398&c=1
TNode<Map> kPromiseCapabilityMap_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1400&c=1
TNode<Map> kSeqOneByteStringMap_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1402&c=1
TNode<Map> kSeqTwoByteStringMap_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1434&c=1
void StoreFastJSArrayLength_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_array, TNode<Smi> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1454&c=1
TNode<Int32T> FastHoleyElementsKind_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_kind);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1464&c=1
TNode<Int32T> AllowDoubleElements_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_kind);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1473&c=1
TNode<Int32T> AllowNonNumberElements_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_kind);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1486&c=1
TNode<JSFunction> GetObjectFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1489&c=1
TNode<JSFunction> GetArrayFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1492&c=1
TNode<JSReceiver> GetArrayBufferFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1495&c=1
TNode<JSFunction> GetArrayBufferNoInitFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1498&c=1
TNode<JSFunction> GetIteratorFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1501&c=1
TNode<JSFunction> GetStringFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1504&c=1
TNode<Map> GetFastPackedElementsJSArrayMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1507&c=1
TNode<Map> GetFastPackedSmiElementsJSArrayMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1511&c=1
TNode<Map> GetProxyRevocableResultMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1514&c=1
TNode<Map> GetIteratorResultMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1517&c=1
TNode<Map> GetInitialStringIteratorMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1520&c=1
TNode<JSReceiver> GetReflectApply_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1523&c=1
TNode<RegExpMatchInfo> GetRegExpLastMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1526&c=1
TNode<Map> GetStrictArgumentsMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1529&c=1
TNode<Map> GetSloppyArgumentsMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1532&c=1
TNode<Map> GetFastAliasedArgumentsMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1535&c=1
TNode<Map> GetWeakCellMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1538&c=1
TNode<JSFunction> GetPrototypeApplyFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1541&c=1
TNode<JSObject> GetIteratorPrototype_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1567&c=1
TNode<BoolT> NumberIsNaN_0(compiler::CodeAssemblerState* state_, TNode<Number> p_number);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1580&c=1
TNode<BoolT> IsForceSlowPath_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1590&c=1
TNode<BoolT> ToBoolean_0(compiler::CodeAssemblerState* state_, TNode<Object> p_obj);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1594&c=1
TNode<Object> RequireObjectCoercible_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, const char* p_name);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1606&c=1
TNode<BoolT> SameValue_0(compiler::CodeAssemblerState* state_, TNode<Object> p_a, TNode<Object> p_b);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1613&c=1
void CheckIntegerIndexAdditionOverflow_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_index1, TNode<UintPtrT> p_index2, TNode<UintPtrT> p_limit, compiler::CodeAssemblerLabel* label_IfOverflow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1637&c=1
int31_t kModeValueIsSafeIntegerUintPtr_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1640&c=1
int31_t kModeValueIsSafeInteger_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1642&c=1
int31_t kModeValueIsAnyNumber_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1644&c=1
TNode<UintPtrT> TryNumberToUintPtr_0(compiler::CodeAssemblerState* state_, TNode<Number> p_valueNumber, int31_t p_kMode, compiler::CodeAssemblerLabel* label_IfLessThanZero, compiler::CodeAssemblerLabel* label_IfUIntPtrOverflow, compiler::CodeAssemblerLabel* label_IfSafeIntegerOverflow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1692&c=1
TNode<UintPtrT> ChangeUintPtrNumberToUintPtr_0(compiler::CodeAssemblerState* state_, TNode<Number> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1702&c=1
TNode<UintPtrT> ChangeSafeIntegerNumberToUintPtr_0(compiler::CodeAssemblerState* state_, TNode<Number> p_value, compiler::CodeAssemblerLabel* label_IfUIntPtrOverflow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1713&c=1
TNode<UintPtrT> ToUintPtr_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_IfLessThanZero, compiler::CodeAssemblerLabel* label_IfUIntPtrOverflow, compiler::CodeAssemblerLabel* label_IfSafeIntegerOverflow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1726&c=1
TNode<UintPtrT> ToIndex_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_IfRangeError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1737&c=1
TNode<Number> GetLengthProperty_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1759&c=1
TNode<JSReceiver> GetMethod_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, TNode<Name> p_name, compiler::CodeAssemblerLabel* label_IfNullOrUndefined, compiler::CodeAssemblerLabel* label_IfMethodNotCallable, compiler::TypedCodeAssemblerVariable<Object>* label_IfMethodNotCallable_parameter_0);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1774&c=1
TNode<JSReceiver> GetMethod_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, TNode<String> p_name, compiler::CodeAssemblerLabel* label_IfNullOrUndefined);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1787&c=1
TNode<JSReceiver> GetMethod_2(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, const char* p_name, compiler::CodeAssemblerLabel* label_IfNullOrUndefined);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1793&c=1
TNode<JSReceiver> GetMethod_3(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, TNode<Symbol> p_symbol, compiler::CodeAssemblerLabel* label_IfNullOrUndefined);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1806&c=1
TNode<JSReceiver> GetInterestingMethod_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<String> p_name, compiler::CodeAssemblerLabel* label_IfNullOrUndefined);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1825&c=1
TNode<UintPtrT> ConvertAndClampRelativeIndex_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_index, TNode<UintPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1834&c=1
TNode<UintPtrT> ConvertAndClampRelativeIndex_2(compiler::CodeAssemblerState* state_, TNode<Number> p_indexNumber, TNode<UintPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1848&c=1
TNode<UintPtrT> ConvertRelativeIndex_1(compiler::CodeAssemblerState* state_, TNode<Number> p_indexNumber, TNode<UintPtrT> p_length, compiler::CodeAssemblerLabel* label_OutOfBoundsLow, compiler::CodeAssemblerLabel* label_OutOfBoundsHigh);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1893&c=1
TNode<UintPtrT> ClampToIndexRange_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_index, TNode<UintPtrT> p_limit);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1902&c=1
TNode<UintPtrT> ClampToIndexRange_1(compiler::CodeAssemblerState* state_, TNode<Number> p_indexNumber, TNode<UintPtrT> p_limit);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1939&c=1
TNode<BoolT> IsFastJSArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1947&c=1
void BranchIfFastJSArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, TNode<Context> p_context, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1957&c=1
void BranchIfFastJSArrayForRead_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, TNode<Context> p_context, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1970&c=1
TNode<BoolT> IsFastJSArrayWithNoCustomIteration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1975&c=1
TNode<BoolT> IsFastJSArrayForReadWithNoCustomIteration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2049&c=1
void VerifiedUnreachable_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2054&c=1
TNode<BoolT> Float64IsSomeInfinity_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2061&c=1
TNode<BoolT> IsIntegerOrSomeInfinity_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2078&c=1
TNode<BoolT> NumberIsSomeInfinity_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2089&c=1
TNode<Object> ReplaceTheHoleWithUndefined_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2124&c=1
TNode<Uint32T> FromConstexpr_HashFieldType_constexpr_kHash_0(compiler::CodeAssemblerState* state_, Name::HashFieldType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2124&c=1
TNode<Uint32T> FromConstexpr_HashFieldType_constexpr_kIntegerIndex_0(compiler::CodeAssemblerState* state_, Name::HashFieldType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2124&c=1
TNode<Uint32T> FromConstexpr_HashFieldType_constexpr_kForwardingIndex_0(compiler::CodeAssemblerState* state_, Name::HashFieldType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2124&c=1
TNode<Uint32T> FromConstexpr_HashFieldType_constexpr_kEmpty_0(compiler::CodeAssemblerState* state_, Name::HashFieldType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2131&c=1
TNode<BoolT> HashFieldTypeEquals_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_s1, TNode<Uint32T> p_s2);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=83&c=10
TNode<HeapObject> WeakToStrong_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_x, compiler::CodeAssemblerLabel* label_ClearedWeakPointer);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=230&c=1
TNode<OrderedHashMap> DownCastForTorqueClass_OrderedHashMap_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=231&c=1
TNode<OrderedHashSet> DownCastForTorqueClass_OrderedHashSet_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=232&c=1
TNode<OrderedNameDictionary> DownCastForTorqueClass_OrderedNameDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=233&c=1
TNode<NameToIndexHashTable> DownCastForTorqueClass_NameToIndexHashTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=234&c=1
TNode<RegisteredSymbolTable> DownCastForTorqueClass_RegisteredSymbolTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=235&c=1
TNode<NameDictionary> DownCastForTorqueClass_NameDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=236&c=1
TNode<GlobalDictionary> DownCastForTorqueClass_GlobalDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=237&c=1
TNode<SimpleNumberDictionary> DownCastForTorqueClass_SimpleNumberDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=238&c=1
TNode<EphemeronHashTable> DownCastForTorqueClass_EphemeronHashTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=241&c=1
TNode<NumberDictionary> DownCastForTorqueClass_NumberDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=255&c=1
TNode<InstructionStream> DownCastForTorqueClass_InstructionStream_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=261&c=1
TNode<TransitionArray> DownCastForTorqueClass_TransitionArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=621&c=47
TNode<IntPtrT> Convert_intptr_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=621&c=5
TNode<MaybeObject> Convert_Tagged_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=644&c=1
TNode<HeapObject> DownCastForTorqueClass_Filler_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=664&c=1
TNode<JSSpecialObject> DownCastForTorqueClass_JSSpecialApiObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=667&c=1
TNode<JSObject> DownCastForTorqueClass_JSContextExtensionObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=669&c=1
TNode<JSObject> DownCastForTorqueClass_JSError_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1487&c=11
TorqueStructReference_JSFunction_0 NativeContextSlot_Context_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1493&c=11
TorqueStructReference_Constructor_0 NativeContextSlot_Context_Constructor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1505&c=11
TorqueStructReference_Map_0 NativeContextSlot_Context_Map_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1521&c=11
TorqueStructReference_Callable_0 NativeContextSlot_Context_Callable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1524&c=11
TorqueStructReference_RegExpMatchInfo_0 NativeContextSlot_Context_RegExpMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1542&c=11
TorqueStructReference_JSObject_0 NativeContextSlot_Context_JSObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1944&c=10
TNode<BoolT> Is_FastJSArray_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1963&c=7
TNode<BoolT> Is_FastJSArrayForRead_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1972&c=10
TNode<BoolT> Is_FastJSArrayWithNoCustomIteration_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1978&c=10
TNode<BoolT> Is_FastJSArrayForReadWithNoCustomIteration_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=2058&c=20
TNode<Float64T> Convert_float64_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=1301&c=46
TNode<Smi> Convert_Smi_SmiTagged_ArrayFromAsyncLabels_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_i);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_BASE_TQ_CSA_H_
