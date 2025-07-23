#include "src/ast/ast.h"
#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-call-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-object-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins-wasm-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/debug/debug-wasm-objects.h"
#include "src/heap/factory-inl.h"
#include "src/ic/binary-op-assembler.h"
#include "src/ic/handler-configuration-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/call-site-info.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/intl-objects.h"
#include "src/objects/js-atomics-synchronization.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-disposable-stack.h"
#include "src/objects/js-duration-format.h"
#include "src/objects/js-function.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-iterator-helpers.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-raw-json.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator-inl.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-segments.h"
#include "src/objects/js-shadow-realm.h"
#include "src/objects/js-shared-array.h"
#include "src/objects/js-struct.h"
#include "src/objects/js-temporal-objects.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/ordered-hash-table.h"
#include "src/objects/property-array.h"
#include "src/objects/property-descriptor-object.h"
#include "src/objects/source-text-module.h"
#include "src/objects/swiss-hash-table-helpers.h"
#include "src/objects/swiss-name-dictionary.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "src/objects/torque-defined-classes.h"
#include "src/objects/turbofan-types.h"
#include "src/objects/turboshaft-types.h"
#include "src/torque/runtime-support.h"
#include "src/wasm/value-type.h"
#include "src/wasm/wasm-linkage.h"
#include "src/wasm/wasm-module.h"
#include "src/codegen/code-stub-assembler-inl.h"
// Required Builtins:
#include "torque-generated/src/builtins/function-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/function-tq-csa.h"
#include "torque-generated/src/builtins/promise-any-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/descriptor-array-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/test/torque/test-torque-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(FunctionPrototypeHasInstance, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).OrdinaryHasInstance(TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<Object>{parameter2});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/function.tq?l=32&c=1
void CheckAccessor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<DescriptorArray> p_array, int32_t p_index, TNode<Name> p_name, compiler::CodeAssemblerLabel* label_Slow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceDescriptorArrayDescriptors_0(state_, TNode<DescriptorArray>{p_array}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_int32_0(state_, p_index);
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<PrimitiveHeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Object> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<MaybeObject> tmp17;
  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp7 = TimesSizeOf_DescriptorEntry_0(state_, TNode<IntPtrT>{tmp3});
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp7});
    std::tie(tmp9, tmp10) = NewReference_DescriptorEntry_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp8}).Flatten();
    tmp11 = CodeStubAssembler(state_).LoadReference<PrimitiveHeapObject>(CodeStubAssembler::Reference{tmp9, tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp12});
    tmp14 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp9, tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp16 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{tmp9, tmp16});
    tmp18 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp11}, TNode<MaybeObject>{p_name});
    tmp19 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp18});
    ca_.Branch(tmp19, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1);
  }

  TNode<AccessorInfo> tmp20;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    compiler::CodeAssemblerLabel label21(&ca_);
    tmp20 = Cast_AccessorInfo_1(state_, TNode<Context>{p_context}, TNode<MaybeObject>{tmp17}, &label21);
    ca_.Goto(&block15);
    if (label21.is_used()) {
      ca_.Bind(&label21);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block1);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Slow);
  }

    ca_.Bind(&block17);
}

TF_BUILTIN(FastFunctionPrototypeBind, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kJSNewTarget);
USE(parameter2);
  TNode<JSFunction> parameter3 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Map> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSFunctionOrBoundFunctionOrWrappedFunction> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSFunction_OR_JSWrappedFunction_OR_JSBoundFunction_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_intptr_constexpr_intptr_0(state_, Code::kMaxArguments);
    tmp3 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{torque_arguments.actual_count}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp3, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp4;
  TNode<Map> tmp5;
  TNode<BoolT> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).Comment("Disallow binding of slow-mode functions");
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp4});
    tmp6 = ConstructorBuiltinsAssembler(state_).IsDictionaryMap(TNode<Map>{tmp5});
    ca_.Branch(tmp6, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp7;
  TNode<Map> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint32T> tmp10;
  TNode<Int32T> tmp11;
  TNode<Int32T> tmp12;
  TNode<BoolT> tmp13;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp8 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{tmp8, tmp9});
    tmp11 = ca_.UncheckedCast<Int32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<int32_t, 10, 10, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp10)));
    tmp12 = FromConstexpr_int32_constexpr_int31_0(state_, JSFunction::kMinDescriptorsForFastBindAndWrap);
    tmp13 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{tmp11}, TNode<Int32T>{tmp12});
    ca_.Branch(tmp13, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp14;
  TNode<Map> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<DescriptorArray> tmp17;
  TNode<String> tmp18;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp15 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp14});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp17 = CodeStubAssembler(state_).LoadReference<DescriptorArray>(CodeStubAssembler::Reference{tmp15, tmp16});
    tmp18 = CodeStubAssembler(state_).LengthStringConstant();
    compiler::CodeAssemblerLabel label19(&ca_);
    CheckAccessor_0(state_, TNode<Context>{parameter0}, TNode<DescriptorArray>{tmp17}, JSFunctionOrBoundFunctionOrWrappedFunction::kLengthDescriptorIndex, TNode<Name>{tmp18}, &label19);
    ca_.Goto(&block13);
    if (label19.is_used()) {
      ca_.Bind(&label19);
      ca_.Goto(&block14);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block2);
  }

  TNode<String> tmp20;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp20 = CodeStubAssembler(state_).NameStringConstant();
    compiler::CodeAssemblerLabel label21(&ca_);
    CheckAccessor_0(state_, TNode<Context>{parameter0}, TNode<DescriptorArray>{tmp17}, JSFunctionOrBoundFunctionOrWrappedFunction::kNameDescriptorIndex, TNode<Name>{tmp20}, &label21);
    ca_.Goto(&block15);
    if (label21.is_used()) {
      ca_.Bind(&label21);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block2);
  }

  TNode<BoolT> tmp22;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp22 = CodeStubAssembler(state_).IsConstructor(TNode<HeapObject>{tmp0});
    ca_.Branch(tmp22, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp23;
  TNode<Object> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Map> tmp26;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp23 = BOUND_FUNCTION_WITH_CONSTRUCTOR_MAP_INDEX_0(state_);
    std::tie(tmp24, tmp25) = NativeContextSlot_NativeContext_Map_0(state_, TNode<NativeContext>{parameter0}, TNode<IntPtrT>{tmp23}).Flatten();
    tmp26 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp24, tmp25});
    ca_.Goto(&block19, tmp26);
  }

  TNode<IntPtrT> tmp27;
  TNode<Object> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<Map> tmp30;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp27 = BOUND_FUNCTION_WITHOUT_CONSTRUCTOR_MAP_INDEX_0(state_);
    std::tie(tmp28, tmp29) = NativeContextSlot_NativeContext_Map_0(state_, TNode<NativeContext>{parameter0}, TNode<IntPtrT>{tmp27}).Flatten();
    tmp30 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp28, tmp29});
    ca_.Goto(&block19, tmp30);
  }

  TNode<Map> phi_bb19_12;
  TNode<IntPtrT> tmp31;
  TNode<Map> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<HeapObject> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<HeapObject> tmp36;
  TNode<BoolT> tmp37;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_12);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp32 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp31});
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp34 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp32, tmp33});
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp36 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{phi_bb19_12, tmp35});
    tmp37 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp34}, TNode<HeapObject>{tmp36});
    ca_.Branch(tmp37, &block21, std::vector<compiler::Node*>{}, &block22, std::vector<compiler::Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp38;
  TNode<BoolT> tmp39;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp38 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp39 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp38});
    ca_.Branch(tmp39, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  TNode<FixedArray> tmp40;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp40 = kEmptyFixedArray_0(state_);
    ca_.Goto(&block25, tmp40);
  }

  TNode<IntPtrT> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<FixedArray> tmp44;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp41 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp42 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp41});
    tmp43 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp44 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{tmp42}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp43}});
    ca_.Goto(&block25, tmp44);
  }

  TNode<FixedArray> phi_bb25_13;
  TNode<IntPtrT> tmp45;
  TNode<Object> tmp46;
  TNode<FixedArray> tmp47;
  TNode<FixedArray> tmp48;
  TNode<BoolT> tmp49;
  TNode<BoolT> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<HeapObject> tmp52;
  TNode<IntPtrT> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<JSBoundFunction> tmp59;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_13);
    tmp45 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp46 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp45});
    tmp47 = kEmptyFixedArray_0(state_);
    tmp48 = kEmptyFixedArray_0(state_);
    tmp49 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp50 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp51 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp52 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp51}, TNode<Map>{phi_bb19_12}, TNode<BoolT>{tmp49}, TNode<BoolT>{tmp50});
    tmp53 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp52, tmp53}, phi_bb19_12);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp52, tmp54}, tmp47);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp52, tmp55}, tmp48);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp52, tmp56}, tmp0);
    tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp52, tmp57}, tmp46);
    tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference{tmp52, tmp58}, phi_bb25_13);
    tmp59 = TORQUE_CAST(TNode<HeapObject>{tmp52});
    arguments.PopAndReturn(tmp59);
  }

  TNode<JSFunction> tmp60;
  TNode<Int32T> tmp61;
  TNode<JSDispatchHandleT> tmp62;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp60 = LoadTargetFromFrame_0(state_);
    tmp61 = Convert_int32_intptr_0(state_, TNode<IntPtrT>{torque_arguments.actual_count});
    tmp62 = kInvalidDispatchHandle_0(state_);
   CodeStubAssembler(state_).TailCallJSBuiltin(Builtin::kFunctionPrototypeBind, parameter0, tmp60, parameter2, tmp61, tmp62);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/function.tq?l=40&c=3
TNode<AccessorInfo> Cast_AccessorInfo_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<MaybeObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<MaybeObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_WeakHeapObject_0(state_, TNode<MaybeObject>{p_o}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  TNode<AccessorInfo> tmp2;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_AccessorInfo_2(state_, TNode<Context>{p_context}, TNode<Object>{ca_.UncheckedCast<Object>(p_o)}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block1);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block9);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block9);
  return TNode<AccessorInfo>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/function.tq?l=79&c=14
TorqueStructReference_Map_0 NativeContextSlot_NativeContext_Map_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NativeContextSlot_Map_1(state_, TNode<NativeContext>{p_context}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Map_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/function.tq?l=92&c=13
TNode<FixedArray> NewFixedArray_ArgumentsIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructArgumentsIterator_0 p_it) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{p_length}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<FixedArray> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = kEmptyFixedArray_0(state_);
    ca_.Goto(&block1, tmp2);
  }

  TNode<IntPtrT> tmp3;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, FixedArray::kMaxLength);
    tmp4 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{p_length}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp5 = kNoContext_0(state_);
    CodeStubAssembler(state_).CallRuntime(Runtime::kFatalProcessOutOfMemoryInvalidArrayLength, tmp5);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Map> tmp6;
  TNode<Smi> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<BoolT> tmp11;
  TNode<BoolT> tmp12;
  TNode<HeapObject> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<FixedArray> tmp17;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = kFixedArrayMap_0(state_);
    tmp7 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{p_length});
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp8}, kTaggedSize);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp13 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp10}, TNode<Map>{tmp6}, TNode<BoolT>{tmp11}, TNode<BoolT>{tmp12});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp13, tmp14}, tmp6);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp13, tmp15}, tmp7);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_ArgumentsIterator_0(state_, TorqueStructSlice_Object_MutableReference_Object_0{TNode<Object>{tmp13}, TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp8}, TorqueStructUnsafe_0{}}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{p_it.arguments.frame}, TNode<RawPtrT>{p_it.arguments.base}, TNode<IntPtrT>{p_it.arguments.length}, TNode<IntPtrT>{p_it.arguments.actual_count}}, TNode<IntPtrT>{p_it.current}});
    tmp17 = TORQUE_CAST(TNode<HeapObject>{tmp13});
    ca_.Goto(&block1, tmp17);
  }

  TNode<FixedArray> phi_bb1_6;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_6);
    ca_.Goto(&block6, phi_bb1_6);
  }

  TNode<FixedArray> phi_bb6_6;
    ca_.Bind(&block6, &phi_bb6_6);
  return TNode<FixedArray>{phi_bb6_6};
}

} // namespace internal
} // namespace v8
