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
#include "torque-generated/src/objects/property-descriptor-object-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/property-descriptor-object-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
TNode<PropertyDescriptorObject> Cast_PropertyDescriptorObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<PropertyDescriptorObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_PropertyDescriptorObject_0(state_, TNode<HeapObject>{p_obj}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_CastError);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<PropertyDescriptorObject>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=53&c=1
TNode<BoolT> IsCompatiblePropertyDescriptor_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p__extensible, TNode<PropertyDescriptorObject> p_newDesc, TNode<PropertyDescriptorObject> p_current) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Method_PropertyDescriptorObject_IsEmptyOrEquivalentTo_0(state_, TNode<PropertyDescriptorObject>{p_newDesc}, TNode<PropertyDescriptorObject>{p_current});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp1);
  }

  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  TNode<BoolT> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_current, tmp2});
    tmp4 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 3, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp3))));
    tmp5 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp4});
    ca_.Branch(tmp5, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<Smi> tmp7;
  TNode<BoolT> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_newDesc, tmp6});
    tmp8 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 4, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp7))));
    ca_.Branch(tmp8, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp9;
  TNode<Smi> tmp10;
  TNode<BoolT> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp10 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_newDesc, tmp9});
    tmp11 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 3, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp10))));
    ca_.Goto(&block10, tmp11);
  }

  TNode<BoolT> tmp12;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block10, tmp12);
  }

  TNode<BoolT> phi_bb10_4;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_4);
    ca_.Branch(phi_bb10_4, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp13);
  }

  TNode<IntPtrT> tmp14;
  TNode<Smi> tmp15;
  TNode<BoolT> tmp16;
  TNode<BoolT> tmp17;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp15 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_current, tmp14});
    tmp16 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 2, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp15))));
    tmp17 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp16});
    ca_.Branch(tmp17, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp18;
  TNode<Smi> tmp19;
  TNode<BoolT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Smi> tmp22;
  TNode<BoolT> tmp23;
  TNode<BoolT> tmp24;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp19 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_newDesc, tmp18});
    tmp20 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 1, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp19))));
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp22 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_current, tmp21});
    tmp23 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 1, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp22))));
    tmp24 = CodeStubAssembler(state_).Word32NotEqual(TNode<BoolT>{tmp20}, TNode<BoolT>{tmp23});
    ca_.Goto(&block15, tmp24);
  }

  TNode<BoolT> tmp25;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block15, tmp25);
  }

  TNode<BoolT> phi_bb15_4;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_4);
    ca_.Branch(phi_bb15_4, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp26;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp26);
  }

  TNode<BoolT> tmp27;
  TNode<BoolT> tmp28;
  TNode<BoolT> tmp29;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp27 = Method_PropertyDescriptorObject_IsAccessorDescriptor_0(state_, TNode<PropertyDescriptorObject>{p_newDesc});
    tmp28 = Method_PropertyDescriptorObject_IsGenericDescriptor_0(state_, TNode<PropertyDescriptorObject>{p_newDesc});
    tmp29 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp28});
    ca_.Branch(tmp29, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp30;
  TNode<BoolT> tmp31;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp30 = Method_PropertyDescriptorObject_IsAccessorDescriptor_0(state_, TNode<PropertyDescriptorObject>{p_current});
    tmp31 = CodeStubAssembler(state_).Word32NotEqual(TNode<BoolT>{tmp27}, TNode<BoolT>{tmp30});
    ca_.Goto(&block20, tmp31);
  }

  TNode<BoolT> tmp32;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp32 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block20, tmp32);
  }

  TNode<BoolT> phi_bb20_5;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_5);
    ca_.Branch(phi_bb20_5, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp33;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp33 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp33);
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Branch(tmp27, &block21, std::vector<compiler::Node*>{}, &block22, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp34;
  TNode<Smi> tmp35;
  TNode<BoolT> tmp36;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp35 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_newDesc, tmp34});
    tmp36 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 8, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp35))));
    ca_.Branch(tmp36, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp37;
  TNode<Object> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<Object> tmp40;
  TNode<BoolT> tmp41;
  TNode<BoolT> tmp42;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp38 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_newDesc, tmp37});
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp40 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_current, tmp39});
    tmp41 = SameValue_0(state_, TNode<Object>{tmp38}, TNode<Object>{tmp40});
    tmp42 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp41});
    ca_.Goto(&block28, tmp42);
  }

  TNode<BoolT> tmp43;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp43 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block28, tmp43);
  }

  TNode<BoolT> phi_bb28_5;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_5);
    ca_.Branch(phi_bb28_5, &block24, std::vector<compiler::Node*>{}, &block25, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp44;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp44 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp44);
  }

  TNode<IntPtrT> tmp45;
  TNode<Smi> tmp46;
  TNode<BoolT> tmp47;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp46 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_newDesc, tmp45});
    tmp47 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 9, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp46))));
    ca_.Branch(tmp47, &block31, std::vector<compiler::Node*>{}, &block32, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp48;
  TNode<Object> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<Object> tmp51;
  TNode<BoolT> tmp52;
  TNode<BoolT> tmp53;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp49 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_newDesc, tmp48});
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp51 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_current, tmp50});
    tmp52 = SameValue_0(state_, TNode<Object>{tmp49}, TNode<Object>{tmp51});
    tmp53 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp52});
    ca_.Goto(&block33, tmp53);
  }

  TNode<BoolT> tmp54;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp54 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block33, tmp54);
  }

  TNode<BoolT> phi_bb33_5;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_5);
    ca_.Branch(phi_bb33_5, &block29, std::vector<compiler::Node*>{}, &block30, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp55;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp55);
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.Goto(&block23);
  }

  TNode<IntPtrT> tmp56;
  TNode<Smi> tmp57;
  TNode<BoolT> tmp58;
  TNode<BoolT> tmp59;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp57 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_current, tmp56});
    tmp58 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 5, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp57))));
    tmp59 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp58});
    ca_.Branch(tmp59, &block34, std::vector<compiler::Node*>{}, &block35, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp60;
  TNode<Smi> tmp61;
  TNode<BoolT> tmp62;
  if (block34.is_used()) {
    ca_.Bind(&block34);
    tmp60 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp61 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_newDesc, tmp60});
    tmp62 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 5, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp61))));
    ca_.Branch(tmp62, &block36, std::vector<compiler::Node*>{}, &block37, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp63;
  if (block36.is_used()) {
    ca_.Bind(&block36);
    tmp63 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp63);
  }

  TNode<IntPtrT> tmp64;
  TNode<Smi> tmp65;
  TNode<BoolT> tmp66;
  if (block37.is_used()) {
    ca_.Bind(&block37);
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp65 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_newDesc, tmp64});
    tmp66 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 7, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp65))));
    ca_.Branch(tmp66, &block40, std::vector<compiler::Node*>{}, &block41, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp67;
  TNode<Object> tmp68;
  TNode<IntPtrT> tmp69;
  TNode<Object> tmp70;
  TNode<BoolT> tmp71;
  TNode<BoolT> tmp72;
  if (block40.is_used()) {
    ca_.Bind(&block40);
    tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp68 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_newDesc, tmp67});
    tmp69 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp70 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_current, tmp69});
    tmp71 = SameValue_0(state_, TNode<Object>{tmp68}, TNode<Object>{tmp70});
    tmp72 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp71});
    ca_.Goto(&block42, tmp72);
  }

  TNode<BoolT> tmp73;
  if (block41.is_used()) {
    ca_.Bind(&block41);
    tmp73 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block42, tmp73);
  }

  TNode<BoolT> phi_bb42_5;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_5);
    ca_.Branch(phi_bb42_5, &block38, std::vector<compiler::Node*>{}, &block39, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp74;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    tmp74 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp74);
  }

  if (block39.is_used()) {
    ca_.Bind(&block39);
    ca_.Goto(&block35);
  }

  if (block35.is_used()) {
    ca_.Bind(&block35);
    ca_.Goto(&block23);
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.Goto(&block5);
  }

  TNode<BoolT> tmp75;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp75 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp75);
  }

  TNode<BoolT> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block43, phi_bb1_3);
  }

  TNode<BoolT> phi_bb43_3;
    ca_.Bind(&block43, &phi_bb43_3);
  return TNode<BoolT>{phi_bb43_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=99&c=1
TNode<BoolT> IsCompatiblePropertyDescriptor_1(compiler::CodeAssemblerState* state_, TNode<BoolT> p_extensible, TNode<HeapObject> p_newDesc, TNode<PropertyDescriptorObject> p_current) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Undefined> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Undefined_2(state_, TNode<HeapObject>{p_newDesc}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = IsCompatiblePropertyDescriptor_0(state_, TNode<BoolT>{p_extensible}, TNode<PropertyDescriptorObject>{ca_.UncheckedCast<PropertyDescriptorObject>(p_newDesc)}, TNode<PropertyDescriptorObject>{p_current});
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=114&c=1
TNode<BoolT> IsCompatiblePropertyDescriptor_2(compiler::CodeAssemblerState* state_, TNode<BoolT> p_extensible, TNode<HeapObject> p_newDesc, TNode<HeapObject> p_current) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Undefined> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Undefined_2(state_, TNode<HeapObject>{p_current}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = IsCompatiblePropertyDescriptor_1(state_, TNode<BoolT>{p_extensible}, TNode<HeapObject>{p_newDesc}, TNode<PropertyDescriptorObject>{ca_.UncheckedCast<PropertyDescriptorObject>(p_current)});
    ca_.Goto(&block1, tmp2);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1, p_extensible);
  }

  TNode<BoolT> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=131&c=1
void CompletePropertyDescriptor_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_desc) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Method_PropertyDescriptorObject_IsAccessorDescriptor_0(state_, TNode<PropertyDescriptorObject>{p_desc});
    tmp1 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp2});
    tmp4 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 7, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp3))));
    tmp5 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp4});
    ca_.Branch(tmp5, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<Smi> tmp7;
  TNode<BoolT> tmp8;
  TNode<Smi> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Undefined> tmp11;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp6});
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp9 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 7, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp7)), ca_.UncheckedCast<Uint32T>(tmp8))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp6}, tmp9);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_desc, tmp10}, tmp11);
    ca_.Goto(&block6);
  }

  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  TNode<BoolT> tmp14;
  TNode<BoolT> tmp15;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp12});
    tmp14 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 6, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp13))));
    tmp15 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp14});
    ca_.Branch(tmp15, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp16;
  TNode<Smi> tmp17;
  TNode<BoolT> tmp18;
  TNode<Smi> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<Smi> tmp21;
  TNode<BoolT> tmp22;
  TNode<Smi> tmp23;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp17 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp16});
    tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp19 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 6, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp17)), ca_.UncheckedCast<Uint32T>(tmp18))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp16}, tmp19);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp20});
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp23 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 5, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp21)), ca_.UncheckedCast<Uint32T>(tmp22))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp20}, tmp23);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp24;
  TNode<Smi> tmp25;
  TNode<BoolT> tmp26;
  TNode<BoolT> tmp27;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp25 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp24});
    tmp26 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 8, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp25))));
    tmp27 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp26});
    ca_.Branch(tmp27, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp28;
  TNode<Smi> tmp29;
  TNode<BoolT> tmp30;
  TNode<Smi> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<Undefined> tmp33;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp29 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp28});
    tmp30 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp31 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 8, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp29)), ca_.UncheckedCast<Uint32T>(tmp30))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp28}, tmp31);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp33 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_desc, tmp32}, tmp33);
    ca_.Goto(&block10);
  }

  TNode<IntPtrT> tmp34;
  TNode<Smi> tmp35;
  TNode<BoolT> tmp36;
  TNode<BoolT> tmp37;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp35 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp34});
    tmp36 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 9, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp35))));
    tmp37 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp36});
    ca_.Branch(tmp37, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp38;
  TNode<Smi> tmp39;
  TNode<BoolT> tmp40;
  TNode<Smi> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<Undefined> tmp43;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp39 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp38});
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp41 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 9, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp39)), ca_.UncheckedCast<Uint32T>(tmp40))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp38}, tmp41);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp43 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_desc, tmp42}, tmp43);
    ca_.Goto(&block12);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp44;
  TNode<Smi> tmp45;
  TNode<BoolT> tmp46;
  TNode<BoolT> tmp47;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp44 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp45 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp44});
    tmp46 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 2, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp45))));
    tmp47 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp46});
    ca_.Branch(tmp47, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp48;
  TNode<Smi> tmp49;
  TNode<BoolT> tmp50;
  TNode<Smi> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<Smi> tmp53;
  TNode<BoolT> tmp54;
  TNode<Smi> tmp55;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp49 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp48});
    tmp50 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp51 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 2, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp49)), ca_.UncheckedCast<Uint32T>(tmp50))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp48}, tmp51);
    tmp52 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp53 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp52});
    tmp54 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp55 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 1, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp53)), ca_.UncheckedCast<Uint32T>(tmp54))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp52}, tmp55);
    ca_.Goto(&block14);
  }

  TNode<IntPtrT> tmp56;
  TNode<Smi> tmp57;
  TNode<BoolT> tmp58;
  TNode<BoolT> tmp59;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp57 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp56});
    tmp58 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 4, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp57))));
    tmp59 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp58});
    ca_.Branch(tmp59, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp60;
  TNode<Smi> tmp61;
  TNode<BoolT> tmp62;
  TNode<Smi> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<Smi> tmp65;
  TNode<BoolT> tmp66;
  TNode<Smi> tmp67;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp60 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp61 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp60});
    tmp62 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp63 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 4, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp61)), ca_.UncheckedCast<Uint32T>(tmp62))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp60}, tmp63);
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp65 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp64});
    tmp66 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp67 = ca_.UncheckedCast<Smi>(ca_.BitcastWordToTaggedSigned(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<bool, 3, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp65)), ca_.UncheckedCast<Uint32T>(tmp66))));
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_desc, tmp64}, tmp67);
    ca_.Goto(&block16);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block17);
  }

    ca_.Bind(&block17);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
TNode<Smi> LoadPropertyDescriptorObjectFlags_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
void StorePropertyDescriptorObjectFlags_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
TNode<Object> LoadPropertyDescriptorObjectValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
void StorePropertyDescriptorObjectValue_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
TNode<Object> LoadPropertyDescriptorObjectGet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
void StorePropertyDescriptorObjectGet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
TNode<Object> LoadPropertyDescriptorObjectSet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
void StorePropertyDescriptorObjectSet_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=20&c=3
TNode<BoolT> Method_PropertyDescriptorObject_IsDataDescriptor_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp0});
    tmp2 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 7, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp1))));
    ca_.Branch(tmp2, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp3);
  }

  TNode<IntPtrT> tmp4;
  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp4});
    tmp6 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 6, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp5))));
    ca_.Goto(&block4, tmp6);
  }

  TNode<BoolT> phi_bb4_2;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_2);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<BoolT>{phi_bb4_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=24&c=3
TNode<BoolT> Method_PropertyDescriptorObject_IsAccessorDescriptor_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp0});
    tmp2 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 8, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp1))));
    ca_.Branch(tmp2, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp3);
  }

  TNode<IntPtrT> tmp4;
  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp4});
    tmp6 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 9, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp5))));
    ca_.Goto(&block4, tmp6);
  }

  TNode<BoolT> phi_bb4_2;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_2);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<BoolT>{phi_bb4_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=28&c=3
TNode<BoolT> Method_PropertyDescriptorObject_IsGenericDescriptor_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Method_PropertyDescriptorObject_IsDataDescriptor_0(state_, TNode<PropertyDescriptorObject>{p_this});
    ca_.Branch(tmp0, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp1);
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = Method_PropertyDescriptorObject_IsAccessorDescriptor_0(state_, TNode<PropertyDescriptorObject>{p_this});
    ca_.Goto(&block6, tmp2);
  }

  TNode<BoolT> phi_bb6_2;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_2);
    ca_.Branch(phi_bb6_2, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp4);
  }

  TNode<BoolT> phi_bb1_1;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_1);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
  return TNode<BoolT>{phi_bb1_1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=35&c=3
TNode<BoolT> Method_PropertyDescriptorObject_IsEmptyOrEquivalentTo_0(compiler::CodeAssemblerState* state_, TNode<PropertyDescriptorObject> p_this, TNode<PropertyDescriptorObject> p_current) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  TNode<BoolT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp0});
    tmp2 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 2, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp1))));
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp4);
  }

  TNode<IntPtrT> tmp5;
  TNode<Smi> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<BoolT> tmp10;
  TNode<BoolT> tmp11;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp5});
    tmp7 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 1, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp6))));
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_current, tmp8});
    tmp10 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 1, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp9))));
    tmp11 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp7}, TNode<BoolT>{tmp10});
    ca_.Goto(&block4, tmp11);
  }

  TNode<BoolT> phi_bb4_3;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3);
    ca_.Branch(phi_bb4_3, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  TNode<BoolT> tmp14;
  TNode<BoolT> tmp15;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp12});
    tmp14 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 4, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp13))));
    tmp15 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp14});
    ca_.Branch(tmp15, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp16;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp16 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block10, tmp16);
  }

  TNode<IntPtrT> tmp17;
  TNode<Smi> tmp18;
  TNode<BoolT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<Smi> tmp21;
  TNode<BoolT> tmp22;
  TNode<BoolT> tmp23;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp18 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp17});
    tmp19 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 3, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp18))));
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_current, tmp20});
    tmp22 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 3, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp21))));
    tmp23 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp19}, TNode<BoolT>{tmp22});
    ca_.Goto(&block10, tmp23);
  }

  TNode<BoolT> phi_bb10_4;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_4);
    ca_.Goto(&block7, phi_bb10_4);
  }

  TNode<BoolT> tmp24;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block7, tmp24);
  }

  TNode<BoolT> phi_bb7_3;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_3);
    ca_.Branch(phi_bb7_3, &block11, std::vector<compiler::Node*>{phi_bb7_3}, &block12, std::vector<compiler::Node*>{phi_bb7_3});
  }

  TNode<BoolT> phi_bb11_2;
  TNode<IntPtrT> tmp25;
  TNode<Smi> tmp26;
  TNode<BoolT> tmp27;
  TNode<BoolT> tmp28;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_2);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp26 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp25});
    tmp27 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 7, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp26))));
    tmp28 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp27});
    ca_.Branch(tmp28, &block14, std::vector<compiler::Node*>{phi_bb11_2}, &block15, std::vector<compiler::Node*>{phi_bb11_2});
  }

  TNode<BoolT> phi_bb14_2;
  TNode<BoolT> tmp29;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_2);
    tmp29 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block16, phi_bb14_2, tmp29);
  }

  TNode<BoolT> phi_bb15_2;
  TNode<IntPtrT> tmp30;
  TNode<Object> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<Object> tmp33;
  TNode<BoolT> tmp34;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_2);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp31 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_this, tmp30});
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp33 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_current, tmp32});
    tmp34 = SameValue_0(state_, TNode<Object>{tmp31}, TNode<Object>{tmp33});
    ca_.Goto(&block16, phi_bb15_2, tmp34);
  }

  TNode<BoolT> phi_bb16_2;
  TNode<BoolT> phi_bb16_4;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_2, &phi_bb16_4);
    ca_.Goto(&block13, phi_bb16_2, phi_bb16_4);
  }

  TNode<BoolT> phi_bb12_2;
  TNode<BoolT> tmp35;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_2);
    tmp35 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block13, phi_bb12_2, tmp35);
  }

  TNode<BoolT> phi_bb13_2;
  TNode<BoolT> phi_bb13_3;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_3);
    ca_.Branch(phi_bb13_3, &block17, std::vector<compiler::Node*>{phi_bb13_3}, &block18, std::vector<compiler::Node*>{phi_bb13_3});
  }

  TNode<BoolT> phi_bb17_2;
  TNode<IntPtrT> tmp36;
  TNode<Smi> tmp37;
  TNode<BoolT> tmp38;
  TNode<BoolT> tmp39;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_2);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp37 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp36});
    tmp38 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 6, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp37))));
    tmp39 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp38});
    ca_.Branch(tmp39, &block20, std::vector<compiler::Node*>{phi_bb17_2}, &block21, std::vector<compiler::Node*>{phi_bb17_2});
  }

  TNode<BoolT> phi_bb20_2;
  TNode<BoolT> tmp40;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_2);
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block22, phi_bb20_2, tmp40);
  }

  TNode<BoolT> phi_bb21_2;
  TNode<IntPtrT> tmp41;
  TNode<Smi> tmp42;
  TNode<BoolT> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<Smi> tmp45;
  TNode<BoolT> tmp46;
  TNode<BoolT> tmp47;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_2);
    tmp41 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp42 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp41});
    tmp43 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 5, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp42))));
    tmp44 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp45 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_current, tmp44});
    tmp46 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 5, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp45))));
    tmp47 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp43}, TNode<BoolT>{tmp46});
    ca_.Goto(&block22, phi_bb21_2, tmp47);
  }

  TNode<BoolT> phi_bb22_2;
  TNode<BoolT> phi_bb22_4;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_2, &phi_bb22_4);
    ca_.Goto(&block19, phi_bb22_2, phi_bb22_4);
  }

  TNode<BoolT> phi_bb18_2;
  TNode<BoolT> tmp48;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_2);
    tmp48 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block19, phi_bb18_2, tmp48);
  }

  TNode<BoolT> phi_bb19_2;
  TNode<BoolT> phi_bb19_3;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_2, &phi_bb19_3);
    ca_.Branch(phi_bb19_3, &block23, std::vector<compiler::Node*>{phi_bb19_3}, &block24, std::vector<compiler::Node*>{phi_bb19_3});
  }

  TNode<BoolT> phi_bb23_2;
  TNode<IntPtrT> tmp49;
  TNode<Smi> tmp50;
  TNode<BoolT> tmp51;
  TNode<BoolT> tmp52;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_2);
    tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp50 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp49});
    tmp51 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 8, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp50))));
    tmp52 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp51});
    ca_.Branch(tmp52, &block26, std::vector<compiler::Node*>{phi_bb23_2}, &block27, std::vector<compiler::Node*>{phi_bb23_2});
  }

  TNode<BoolT> phi_bb26_2;
  TNode<BoolT> tmp53;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_2);
    tmp53 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block28, phi_bb26_2, tmp53);
  }

  TNode<BoolT> phi_bb27_2;
  TNode<IntPtrT> tmp54;
  TNode<Object> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<Object> tmp57;
  TNode<BoolT> tmp58;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_2);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp55 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_this, tmp54});
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp57 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_current, tmp56});
    tmp58 = SameValue_0(state_, TNode<Object>{tmp55}, TNode<Object>{tmp57});
    ca_.Goto(&block28, phi_bb27_2, tmp58);
  }

  TNode<BoolT> phi_bb28_2;
  TNode<BoolT> phi_bb28_4;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_2, &phi_bb28_4);
    ca_.Goto(&block25, phi_bb28_2, phi_bb28_4);
  }

  TNode<BoolT> phi_bb24_2;
  TNode<BoolT> tmp59;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_2);
    tmp59 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block25, phi_bb24_2, tmp59);
  }

  TNode<BoolT> phi_bb25_2;
  TNode<BoolT> phi_bb25_3;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_2, &phi_bb25_3);
    ca_.Branch(phi_bb25_3, &block29, std::vector<compiler::Node*>{phi_bb25_3}, &block30, std::vector<compiler::Node*>{phi_bb25_3});
  }

  TNode<BoolT> phi_bb29_2;
  TNode<IntPtrT> tmp60;
  TNode<Smi> tmp61;
  TNode<BoolT> tmp62;
  TNode<BoolT> tmp63;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_2);
    tmp60 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp61 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp60});
    tmp62 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 9, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(ca_.BitcastTaggedToWordForTagAndSmiBits(tmp61))));
    tmp63 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp62});
    ca_.Branch(tmp63, &block32, std::vector<compiler::Node*>{phi_bb29_2}, &block33, std::vector<compiler::Node*>{phi_bb29_2});
  }

  TNode<BoolT> phi_bb32_2;
  TNode<BoolT> tmp64;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_2);
    tmp64 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block34, phi_bb32_2, tmp64);
  }

  TNode<BoolT> phi_bb33_2;
  TNode<IntPtrT> tmp65;
  TNode<Object> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<Object> tmp68;
  TNode<BoolT> tmp69;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_2);
    tmp65 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp66 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_this, tmp65});
    tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp68 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_current, tmp67});
    tmp69 = SameValue_0(state_, TNode<Object>{tmp66}, TNode<Object>{tmp68});
    ca_.Goto(&block34, phi_bb33_2, tmp69);
  }

  TNode<BoolT> phi_bb34_2;
  TNode<BoolT> phi_bb34_4;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_2, &phi_bb34_4);
    ca_.Goto(&block31, phi_bb34_2, phi_bb34_4);
  }

  TNode<BoolT> phi_bb30_2;
  TNode<BoolT> tmp70;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_2);
    tmp70 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block31, phi_bb30_2, tmp70);
  }

  TNode<BoolT> phi_bb31_2;
  TNode<BoolT> phi_bb31_3;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_2, &phi_bb31_3);
    ca_.Goto(&block35, phi_bb31_3);
  }

  TNode<BoolT> phi_bb35_2;
    ca_.Bind(&block35, &phi_bb35_2);
  return TNode<BoolT>{phi_bb35_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
TNode<PropertyDescriptorObject> DownCastForTorqueClass_PropertyDescriptorObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Map> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(163), static_cast<InstanceType>(163))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<PropertyDescriptorObject>())) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<PropertyDescriptorObject>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block1);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block8);
  }

  TNode<IntPtrT> tmp4;
  TNode<Uint16T> tmp5;
  TNode<Uint32T> tmp6;
  TNode<BoolT> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(163));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block5);
  }

  TNode<Int32T> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint16T> tmp10;
  TNode<Uint16T> tmp11;
  TNode<Int32T> tmp12;
  TNode<Uint16T> tmp13;
  TNode<Uint16T> tmp14;
  TNode<Int32T> tmp15;
  TNode<Int32T> tmp16;
  TNode<Uint32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<BoolT> tmp19;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(163), static_cast<InstanceType>(163))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(163));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<PropertyDescriptorObject> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<PropertyDescriptorObject>{tmp20};
}

} // namespace internal
} // namespace v8
