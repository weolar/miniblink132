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
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=23&c=1
TNode<IntPtrT> RegExpReplaceCallableNoExplicitCaptures_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_matchesElements, TNode<IntPtrT> p_matchesCapacity, TNode<String> p_string, TNode<JSReceiver> p_replaceFn) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block4, tmp0, tmp1);
  }

  TNode<Smi> phi_bb4_5;
  TNode<IntPtrT> phi_bb4_6;
  TNode<BoolT> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5, &phi_bb4_6);
    tmp2 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb4_6}, TNode<IntPtrT>{p_matchesCapacity});
    ca_.Branch(tmp2, &block2, std::vector<compiler::Node*>{phi_bb4_5, phi_bb4_6}, &block3, std::vector<compiler::Node*>{phi_bb4_5, phi_bb4_6});
  }

  TNode<Smi> phi_bb2_5;
  TNode<IntPtrT> phi_bb2_6;
  TNode<Object> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<UintPtrT> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5, &phi_bb2_6);
    std::tie(tmp3, tmp4, tmp5) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{p_matchesElements}).Flatten();
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb2_6});
    tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    tmp8 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp6}, TNode<UintPtrT>{tmp7});
    ca_.Branch(tmp8, &block10, std::vector<compiler::Node*>{phi_bb2_5, phi_bb2_6, phi_bb2_6, phi_bb2_6, phi_bb2_6, phi_bb2_6}, &block11, std::vector<compiler::Node*>{phi_bb2_5, phi_bb2_6, phi_bb2_6, phi_bb2_6, phi_bb2_6, phi_bb2_6});
  }

  TNode<Smi> phi_bb10_5;
  TNode<IntPtrT> phi_bb10_6;
  TNode<IntPtrT> phi_bb10_11;
  TNode<IntPtrT> phi_bb10_12;
  TNode<IntPtrT> phi_bb10_16;
  TNode<IntPtrT> phi_bb10_17;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Object> tmp13;
  TNode<Smi> tmp14;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5, &phi_bb10_6, &phi_bb10_11, &phi_bb10_12, &phi_bb10_16, &phi_bb10_17);
    tmp9 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb10_17});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_Object_0(state_, TNode<Object>{tmp3}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp13 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp11, tmp12});
    compiler::CodeAssemblerLabel label15(&ca_);
    tmp14 = Cast_Smi_0(state_, TNode<Object>{tmp13}, &label15);
    ca_.Goto(&block16, phi_bb10_5, phi_bb10_6);
    if (label15.is_used()) {
      ca_.Bind(&label15);
      ca_.Goto(&block17, phi_bb10_5, phi_bb10_6);
    }
  }

  TNode<Smi> phi_bb11_5;
  TNode<IntPtrT> phi_bb11_6;
  TNode<IntPtrT> phi_bb11_11;
  TNode<IntPtrT> phi_bb11_12;
  TNode<IntPtrT> phi_bb11_16;
  TNode<IntPtrT> phi_bb11_17;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_5, &phi_bb11_6, &phi_bb11_11, &phi_bb11_12, &phi_bb11_16, &phi_bb11_17);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb17_5;
  TNode<IntPtrT> phi_bb17_6;
  TNode<String> tmp16;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_5, &phi_bb17_6);
    compiler::CodeAssemblerLabel label17(&ca_);
    tmp16 = Cast_String_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp13)}, &label17);
    ca_.Goto(&block31, phi_bb17_5, phi_bb17_6);
    if (label17.is_used()) {
      ca_.Bind(&label17);
      ca_.Goto(&block32, phi_bb17_5, phi_bb17_6);
    }
  }

  TNode<Smi> phi_bb16_5;
  TNode<IntPtrT> phi_bb16_6;
  TNode<Smi> tmp18;
  TNode<BoolT> tmp19;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_5, &phi_bb16_6);
    tmp18 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp19 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp14}, TNode<Smi>{tmp18});
    ca_.Branch(tmp19, &block18, std::vector<compiler::Node*>{phi_bb16_5, phi_bb16_6}, &block19, std::vector<compiler::Node*>{phi_bb16_5, phi_bb16_6});
  }

  TNode<Smi> phi_bb18_5;
  TNode<IntPtrT> phi_bb18_6;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Smi> tmp26;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_5, &phi_bb18_6);
    tmp20 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp14});
    tmp21 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xbull));
    tmp22 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp21});
    tmp23 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x7ffull));
    tmp24 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp23});
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp24});
    tmp26 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp25});
    ca_.Goto(&block20, tmp26, phi_bb18_6);
  }

  TNode<Smi> phi_bb19_5;
  TNode<IntPtrT> phi_bb19_6;
  TNode<Object> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<UintPtrT> tmp33;
  TNode<BoolT> tmp34;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_5, &phi_bb19_6);
    std::tie(tmp27, tmp28, tmp29) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{p_matchesElements}).Flatten();
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp31 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_6}, TNode<IntPtrT>{tmp30});
    tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp31});
    tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp29});
    tmp34 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp33});
    ca_.Branch(tmp34, &block25, std::vector<compiler::Node*>{phi_bb19_5}, &block26, std::vector<compiler::Node*>{phi_bb19_5});
  }

  TNode<Smi> phi_bb25_5;
  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<Object> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<Object> tmp39;
  TNode<Smi> tmp40;
  TNode<Smi> tmp41;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_5);
    tmp35 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp31});
    tmp36 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp35});
    std::tie(tmp37, tmp38) = NewReference_Object_0(state_, TNode<Object>{tmp27}, TNode<IntPtrT>{tmp36}).Flatten();
    tmp39 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp37, tmp38});
    tmp40 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp39});
    tmp41 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp40}, TNode<Smi>{tmp14});
    ca_.Goto(&block20, tmp41, tmp31);
  }

  TNode<Smi> phi_bb26_5;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_5);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb20_5;
  TNode<IntPtrT> phi_bb20_6;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_5, &phi_bb20_6);
    ca_.Goto(&block14, phi_bb20_5, phi_bb20_6);
  }

  TNode<Smi> phi_bb32_5;
  TNode<IntPtrT> phi_bb32_6;
  TNode<Hole> tmp42;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_5, &phi_bb32_6);
    compiler::CodeAssemblerLabel label43(&ca_);
    tmp42 = Cast_TheHole_1(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp13)}, &label43);
    ca_.Goto(&block43, phi_bb32_5, phi_bb32_6);
    if (label43.is_used()) {
      ca_.Bind(&label43);
      ca_.Goto(&block44, phi_bb32_5, phi_bb32_6);
    }
  }

  TNode<Smi> phi_bb31_5;
  TNode<IntPtrT> phi_bb31_6;
  TNode<Undefined> tmp44;
  TNode<Object> tmp45;
  TNode<String> tmp46;
  TNode<Object> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<UintPtrT> tmp50;
  TNode<UintPtrT> tmp51;
  TNode<BoolT> tmp52;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_5, &phi_bb31_6);
    tmp44 = Undefined_0(state_);
    tmp45 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{p_replaceFn}, TNode<Object>{tmp44}, TNode<Object>{tmp16}, TNode<Object>{phi_bb31_5}, TNode<Object>{p_string});
    tmp46 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{p_context}, TNode<Object>{tmp45});
    std::tie(tmp47, tmp48, tmp49) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{p_matchesElements}).Flatten();
    tmp50 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb31_6});
    tmp51 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp49});
    tmp52 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp50}, TNode<UintPtrT>{tmp51});
    ca_.Branch(tmp52, &block37, std::vector<compiler::Node*>{phi_bb31_5, phi_bb31_6, phi_bb31_6, phi_bb31_6, phi_bb31_6, phi_bb31_6}, &block38, std::vector<compiler::Node*>{phi_bb31_5, phi_bb31_6, phi_bb31_6, phi_bb31_6, phi_bb31_6, phi_bb31_6});
  }

  TNode<Smi> phi_bb37_5;
  TNode<IntPtrT> phi_bb37_6;
  TNode<IntPtrT> phi_bb37_15;
  TNode<IntPtrT> phi_bb37_16;
  TNode<IntPtrT> phi_bb37_20;
  TNode<IntPtrT> phi_bb37_21;
  TNode<IntPtrT> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<Object> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<Smi> tmp57;
  TNode<Smi> tmp58;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_5, &phi_bb37_6, &phi_bb37_15, &phi_bb37_16, &phi_bb37_20, &phi_bb37_21);
    tmp53 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb37_21});
    tmp54 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp48}, TNode<IntPtrT>{tmp53});
    std::tie(tmp55, tmp56) = NewReference_Object_0(state_, TNode<Object>{tmp47}, TNode<IntPtrT>{tmp54}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp55, tmp56}, tmp46);
    tmp57 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp16});
    tmp58 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb37_5}, TNode<Smi>{tmp57});
    ca_.Goto(&block14, tmp58, phi_bb37_6);
  }

  TNode<Smi> phi_bb38_5;
  TNode<IntPtrT> phi_bb38_6;
  TNode<IntPtrT> phi_bb38_15;
  TNode<IntPtrT> phi_bb38_16;
  TNode<IntPtrT> phi_bb38_20;
  TNode<IntPtrT> phi_bb38_21;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_5, &phi_bb38_6, &phi_bb38_15, &phi_bb38_16, &phi_bb38_20, &phi_bb38_21);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb44_5;
  TNode<IntPtrT> phi_bb44_6;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_5, &phi_bb44_6);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb43_5;
  TNode<IntPtrT> phi_bb43_6;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_5, &phi_bb43_6);
    ca_.Goto(&block1, phi_bb43_6);
  }

  TNode<Smi> phi_bb14_5;
  TNode<IntPtrT> phi_bb14_6;
  TNode<IntPtrT> tmp59;
  TNode<IntPtrT> tmp60;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_5, &phi_bb14_6);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp60 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb14_6}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block4, phi_bb14_5, tmp60);
  }

  TNode<Smi> phi_bb3_5;
  TNode<IntPtrT> phi_bb3_6;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5, &phi_bb3_6);
    ca_.Goto(&block1, p_matchesCapacity);
  }

  TNode<IntPtrT> phi_bb1_5;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5);
    ca_.Goto(&block45, phi_bb1_5);
  }

  TNode<IntPtrT> phi_bb45_5;
    ca_.Bind(&block45, &phi_bb45_5);
  return TNode<IntPtrT>{phi_bb45_5};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=71&c=1
TNode<IntPtrT> RegExpReplaceCallableWithExplicitCaptures_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_matchesElements, TNode<IntPtrT> p_matchesCapacity, TNode<JSReceiver> p_replaceFn) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block4, tmp0);
  }

  TNode<IntPtrT> phi_bb4_4;
  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_4);
    tmp1 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb4_4}, TNode<IntPtrT>{p_matchesCapacity});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{phi_bb4_4}, &block3, std::vector<compiler::Node*>{phi_bb4_4});
  }

  TNode<IntPtrT> phi_bb2_4;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_4);
    std::tie(tmp2, tmp3, tmp4) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{p_matchesElements}).Flatten();
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb2_4});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block12, std::vector<compiler::Node*>{phi_bb2_4, phi_bb2_4, phi_bb2_4, phi_bb2_4, phi_bb2_4}, &block13, std::vector<compiler::Node*>{phi_bb2_4, phi_bb2_4, phi_bb2_4, phi_bb2_4, phi_bb2_4});
  }

  TNode<IntPtrT> phi_bb12_4;
  TNode<IntPtrT> phi_bb12_9;
  TNode<IntPtrT> phi_bb12_10;
  TNode<IntPtrT> phi_bb12_14;
  TNode<IntPtrT> phi_bb12_15;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Object> tmp12;
  TNode<Hole> tmp13;
  TNode<BoolT> tmp14;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_4, &phi_bb12_9, &phi_bb12_10, &phi_bb12_14, &phi_bb12_15);
    tmp8 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb12_15});
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp8});
    std::tie(tmp10, tmp11) = NewReference_Object_0(state_, TNode<Object>{tmp2}, TNode<IntPtrT>{tmp9}).Flatten();
    tmp12 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp10, tmp11});
    tmp13 = TheHole_0(state_);
    tmp14 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp12}, TNode<HeapObject>{tmp13});
    ca_.Branch(tmp14, &block6, std::vector<compiler::Node*>{phi_bb12_4}, &block7, std::vector<compiler::Node*>{phi_bb12_4});
  }

  TNode<IntPtrT> phi_bb13_4;
  TNode<IntPtrT> phi_bb13_9;
  TNode<IntPtrT> phi_bb13_10;
  TNode<IntPtrT> phi_bb13_14;
  TNode<IntPtrT> phi_bb13_15;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_4, &phi_bb13_9, &phi_bb13_10, &phi_bb13_14, &phi_bb13_15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb6_4;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_4);
    ca_.Goto(&block1, phi_bb6_4);
  }

  TNode<IntPtrT> phi_bb7_4;
  TNode<Object> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<UintPtrT> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<BoolT> tmp20;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_4);
    std::tie(tmp15, tmp16, tmp17) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{p_matchesElements}).Flatten();
    tmp18 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb7_4});
    tmp19 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp17});
    tmp20 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp19});
    ca_.Branch(tmp20, &block22, std::vector<compiler::Node*>{phi_bb7_4, phi_bb7_4, phi_bb7_4, phi_bb7_4, phi_bb7_4}, &block23, std::vector<compiler::Node*>{phi_bb7_4, phi_bb7_4, phi_bb7_4, phi_bb7_4, phi_bb7_4});
  }

  TNode<IntPtrT> phi_bb22_4;
  TNode<IntPtrT> phi_bb22_9;
  TNode<IntPtrT> phi_bb22_10;
  TNode<IntPtrT> phi_bb22_14;
  TNode<IntPtrT> phi_bb22_15;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<Object> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<Object> tmp25;
  TNode<JSArray> tmp26;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_4, &phi_bb22_9, &phi_bb22_10, &phi_bb22_14, &phi_bb22_15);
    tmp21 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb22_15});
    tmp22 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp21});
    std::tie(tmp23, tmp24) = NewReference_Object_0(state_, TNode<Object>{tmp15}, TNode<IntPtrT>{tmp22}).Flatten();
    tmp25 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp23, tmp24});
    compiler::CodeAssemblerLabel label27(&ca_);
    tmp26 = Cast_JSArray_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp25}, &label27);
    ca_.Goto(&block26, phi_bb22_4);
    if (label27.is_used()) {
      ca_.Bind(&label27);
      ca_.Goto(&block27, phi_bb22_4);
    }
  }

  TNode<IntPtrT> phi_bb23_4;
  TNode<IntPtrT> phi_bb23_9;
  TNode<IntPtrT> phi_bb23_10;
  TNode<IntPtrT> phi_bb23_14;
  TNode<IntPtrT> phi_bb23_15;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_4, &phi_bb23_9, &phi_bb23_10, &phi_bb23_14, &phi_bb23_15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb27_4;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_4);
    ca_.Goto(&block5, phi_bb27_4);
  }

  TNode<IntPtrT> phi_bb26_4;
  TNode<JSReceiver> tmp28;
  TNode<Undefined> tmp29;
  TNode<Undefined> tmp30;
  TNode<Object> tmp31;
  TNode<Object> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<UintPtrT> tmp35;
  TNode<UintPtrT> tmp36;
  TNode<BoolT> tmp37;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_4);
    tmp28 = GetReflectApply_0(state_, TNode<Context>{p_context});
    tmp29 = Undefined_0(state_);
    tmp30 = Undefined_0(state_);
    tmp31 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp28}, TNode<Object>{tmp29}, TNode<Object>{p_replaceFn}, TNode<Object>{tmp30}, TNode<Object>{tmp26});
    std::tie(tmp32, tmp33, tmp34) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{p_matchesElements}).Flatten();
    tmp35 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb26_4});
    tmp36 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp34});
    tmp37 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp35}, TNode<UintPtrT>{tmp36});
    ca_.Branch(tmp37, &block32, std::vector<compiler::Node*>{phi_bb26_4, phi_bb26_4, phi_bb26_4, phi_bb26_4, phi_bb26_4}, &block33, std::vector<compiler::Node*>{phi_bb26_4, phi_bb26_4, phi_bb26_4, phi_bb26_4, phi_bb26_4});
  }

  TNode<IntPtrT> phi_bb32_4;
  TNode<IntPtrT> phi_bb32_11;
  TNode<IntPtrT> phi_bb32_12;
  TNode<IntPtrT> phi_bb32_16;
  TNode<IntPtrT> phi_bb32_17;
  TNode<IntPtrT> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<Object> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<String> tmp42;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_4, &phi_bb32_11, &phi_bb32_12, &phi_bb32_16, &phi_bb32_17);
    tmp38 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb32_17});
    tmp39 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp38});
    std::tie(tmp40, tmp41) = NewReference_Object_0(state_, TNode<Object>{tmp32}, TNode<IntPtrT>{tmp39}).Flatten();
    tmp42 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{p_context}, TNode<Object>{tmp31});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp40, tmp41}, tmp42);
    ca_.Goto(&block5, phi_bb32_4);
  }

  TNode<IntPtrT> phi_bb33_4;
  TNode<IntPtrT> phi_bb33_11;
  TNode<IntPtrT> phi_bb33_12;
  TNode<IntPtrT> phi_bb33_16;
  TNode<IntPtrT> phi_bb33_17;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_4, &phi_bb33_11, &phi_bb33_12, &phi_bb33_16, &phi_bb33_17);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb5_4;
  TNode<IntPtrT> tmp43;
  TNode<IntPtrT> tmp44;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_4);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp44 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb5_4}, TNode<IntPtrT>{tmp43});
    ca_.Goto(&block4, tmp44);
  }

  TNode<IntPtrT> phi_bb3_4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_4);
    ca_.Goto(&block1, p_matchesCapacity);
  }

  TNode<IntPtrT> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.Goto(&block36, phi_bb1_4);
  }

  TNode<IntPtrT> phi_bb36_4;
    ca_.Bind(&block36, &phi_bb36_4);
  return TNode<IntPtrT>{phi_bb36_4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=94&c=1
TNode<String> RegExpReplaceFastGlobalCallable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<JSReceiver> p_replaceFn) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<RegExpMatchInfo> tmp1;
  TNode<HeapObject> tmp2;
  TNode<Smi> tmp3;
  TNode<Null> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{p_regexp}, TNode<Smi>{tmp0});
    tmp1 = GetRegExpLastMatchInfo_0(state_, TNode<Context>{p_context});
    tmp2 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpExecMultiple, p_context, p_regexp, p_string, tmp1)); 
    tmp3 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{p_regexp}, TNode<Smi>{tmp3});
    tmp4 = Null_0(state_);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp2}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block1, p_string);
  }

  TNode<FixedArray> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Smi> tmp8;
  TNode<Smi> tmp9;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp6 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp2});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp6, tmp7});
    compiler::CodeAssemblerLabel label10(&ca_);
    tmp9 = Cast_Smi_0(state_, TNode<Object>{tmp8}, &label10);
    ca_.Goto(&block6);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block7);
    }
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp11;
  TNode<RegExpMatchInfo> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Smi> tmp14;
  TNode<Smi> tmp15;
  TNode<BoolT> tmp16;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp11 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp9});
    tmp12 = GetRegExpLastMatchInfo_0(state_, TNode<Context>{p_context});
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp14 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp13});
    tmp15 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp16 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp14}, TNode<Smi>{tmp15});
    ca_.Branch(tmp16, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp17;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp17 = RegExpReplaceCallableNoExplicitCaptures_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp6}, TNode<IntPtrT>{tmp11}, TNode<String>{p_string}, TNode<JSReceiver>{p_replaceFn});
    ca_.Goto(&block10, tmp17);
  }

  TNode<IntPtrT> tmp18;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp18 = RegExpReplaceCallableWithExplicitCaptures_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp6}, TNode<IntPtrT>{tmp11}, TNode<JSReceiver>{p_replaceFn});
    ca_.Goto(&block10, tmp18);
  }

  TNode<IntPtrT> phi_bb10_9;
  TNode<Smi> tmp19;
  TNode<String> tmp20;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_9);
    tmp19 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{phi_bb10_9});
    tmp20 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringBuilderConcat, p_context, tmp6, tmp19, p_string)); 
    ca_.Goto(&block1, tmp20);
  }

  TNode<String> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.Goto(&block11, phi_bb1_4);
  }

  TNode<String> phi_bb11_4;
    ca_.Bind(&block11, &phi_bb11_4);
  return TNode<String>{phi_bb11_4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=132&c=1
TNode<String> RegExpReplaceFastString_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<String> p_replaceString) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, Smi, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, Smi, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, Smi, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, Smi, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String, Smi, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<String> tmp0;
  TNode<Smi> tmp1;
  TNode<BoolT> tmp2;
  TNode<Smi> tmp3;
  TNode<JSRegExp> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kEmptyString_0(state_);
    tmp1 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp3 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{p_replaceString});
    tmp4 = UnsafeCast_FastJSRegExp_0(state_, TNode<Context>{p_context}, TNode<Object>{p_regexp});
    tmp5 = RegExpBuiltinsAssembler(state_).FastFlagGetterGlobal(TNode<JSRegExp>{tmp4});
    ca_.Branch(tmp5, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{tmp2});
  }

  TNode<BoolT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp6 = RegExpBuiltinsAssembler(state_).FastFlagGetterUnicode(TNode<JSRegExp>{tmp4});
    ca_.Branch(tmp6, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp7);
  }

  TNode<BoolT> tmp8;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp8 = RegExpBuiltinsAssembler(state_).FastFlagGetterUnicodeSets(TNode<JSRegExp>{tmp4});
    ca_.Goto(&block6, tmp8);
  }

  TNode<BoolT> phi_bb6_11;
  TNode<Smi> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_11);
    tmp9 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp4}, TNode<Smi>{tmp9});
    ca_.Goto(&block3, phi_bb6_11);
  }

  TNode<BoolT> phi_bb3_6;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_6);
    ca_.Goto(&block9, tmp0, tmp1, phi_bb3_6);
  }

  TNode<String> phi_bb9_4;
  TNode<Smi> phi_bb9_5;
  TNode<BoolT> phi_bb9_6;
  TNode<BoolT> tmp10;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_4, &phi_bb9_5, &phi_bb9_6);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp10, &block7, std::vector<compiler::Node*>{phi_bb9_4, phi_bb9_5, phi_bb9_6}, &block8, std::vector<compiler::Node*>{phi_bb9_4, phi_bb9_5, phi_bb9_6});
  }

  TNode<String> phi_bb7_4;
  TNode<Smi> phi_bb7_5;
  TNode<BoolT> phi_bb7_6;
  TNode<RegExpMatchInfo> tmp11;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_4, &phi_bb7_5, &phi_bb7_6);
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = RegExpPrototypeExecBodyWithoutResultFast_0(state_, TNode<Context>{p_context}, TNode<JSRegExp>{p_regexp}, TNode<String>{p_string}, &label12);
    ca_.Goto(&block12, phi_bb7_4, phi_bb7_5, phi_bb7_6);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block13, phi_bb7_4, phi_bb7_5, phi_bb7_6);
    }
  }

  TNode<String> phi_bb13_4;
  TNode<Smi> phi_bb13_5;
  TNode<BoolT> phi_bb13_6;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_4, &phi_bb13_5, &phi_bb13_6);
    ca_.Goto(&block8, phi_bb13_4, phi_bb13_5, phi_bb13_6);
  }

  TNode<String> phi_bb12_4;
  TNode<Smi> phi_bb12_5;
  TNode<BoolT> phi_bb12_6;
  TNode<Smi> tmp13;
  TNode<Smi> tmp14;
  TNode<String> tmp15;
  TNode<String> tmp16;
  TNode<Smi> tmp17;
  TNode<BoolT> tmp18;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_4, &phi_bb12_5, &phi_bb12_6);
    tmp13 = Method_RegExpMatchInfo_GetStartOfCapture_0(state_, TNode<RegExpMatchInfo>{tmp11}, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull))));
    tmp14 = Method_RegExpMatchInfo_GetEndOfCapture_0(state_, TNode<RegExpMatchInfo>{tmp11}, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull))));
    tmp15 = ca_.CallBuiltin<String>(Builtin::kSubString, p_context, p_string, phi_bb12_5, tmp13);
    tmp16 = StringAdd_0(state_, TNode<Context>{p_context}, TNode<String>{phi_bb12_4}, TNode<String>{tmp15});
    tmp17 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp18 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp17});
    ca_.Branch(tmp18, &block14, std::vector<compiler::Node*>{phi_bb12_6}, &block15, std::vector<compiler::Node*>{tmp16, phi_bb12_6});
  }

  TNode<BoolT> phi_bb14_6;
  TNode<String> tmp19;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_6);
    tmp19 = StringAdd_0(state_, TNode<Context>{p_context}, TNode<String>{tmp16}, TNode<String>{p_replaceString});
    ca_.Goto(&block15, tmp19, phi_bb14_6);
  }

  TNode<String> phi_bb15_4;
  TNode<BoolT> phi_bb15_6;
  TNode<BoolT> tmp20;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_4, &phi_bb15_6);
    tmp20 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp5});
    ca_.Branch(tmp20, &block16, std::vector<compiler::Node*>{phi_bb15_6}, &block17, std::vector<compiler::Node*>{phi_bb15_6});
  }

  TNode<BoolT> phi_bb16_6;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_6);
    ca_.Goto(&block8, phi_bb15_4, tmp14, phi_bb16_6);
  }

  TNode<BoolT> phi_bb17_6;
  TNode<BoolT> tmp21;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_6);
    tmp21 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp14}, TNode<Smi>{tmp13});
    ca_.Branch(tmp21, &block18, std::vector<compiler::Node*>{phi_bb17_6}, &block19, std::vector<compiler::Node*>{phi_bb17_6});
  }

  TNode<BoolT> phi_bb18_6;
  TNode<JSRegExp> tmp22;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_6);
    compiler::CodeAssemblerLabel label23(&ca_);
    tmp22 = Cast_FastJSRegExp_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_regexp}, &label23);
    ca_.Goto(&block22, phi_bb18_6);
    if (label23.is_used()) {
      ca_.Bind(&label23);
      ca_.Goto(&block23, phi_bb18_6);
    }
  }

  TNode<BoolT> phi_bb23_6;
  TNode<Object> tmp24;
  TNode<Number> tmp25;
  TNode<Smi> tmp26;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_6);
    tmp24 = RegExpBuiltinsAssembler(state_).SlowLoadLastIndex(TNode<Context>{p_context}, TNode<Object>{p_regexp});
    tmp25 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{p_context}, TNode<Object>{tmp24});
    tmp26 = RegExpBuiltinsAssembler(state_).AdvanceStringIndexSlow(TNode<String>{p_string}, TNode<Number>{tmp25}, TNode<BoolT>{phi_bb23_6});
    RegExpBuiltinsAssembler(state_).SlowStoreLastIndex(TNode<Context>{p_context}, TNode<Object>{p_regexp}, TNode<Object>{tmp26});
    ca_.Goto(&block20, phi_bb23_6);
  }

  TNode<BoolT> phi_bb22_6;
  TNode<Smi> tmp27;
  TNode<Smi> tmp28;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_6);
    tmp27 = RegExpBuiltinsAssembler(state_).FastLoadLastIndex(TNode<JSRegExp>{tmp22});
    tmp28 = RegExpBuiltinsAssembler(state_).AdvanceStringIndexFast(TNode<String>{p_string}, TNode<Smi>{tmp27}, TNode<BoolT>{phi_bb22_6});
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp22}, TNode<Smi>{tmp28});
    ca_.Goto(&block20, phi_bb22_6);
  }

  TNode<BoolT> phi_bb20_6;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_6);
    ca_.Goto(&block19, phi_bb20_6);
  }

  TNode<BoolT> phi_bb19_6;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_6);
    ca_.Goto(&block9, phi_bb15_4, tmp14, phi_bb19_6);
  }

  TNode<String> phi_bb8_4;
  TNode<Smi> phi_bb8_5;
  TNode<BoolT> phi_bb8_6;
  TNode<Smi> tmp29;
  TNode<String> tmp30;
  TNode<String> tmp31;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_4, &phi_bb8_5, &phi_bb8_6);
    tmp29 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{p_string});
    tmp30 = ca_.CallBuiltin<String>(Builtin::kSubString, p_context, p_string, phi_bb8_5, tmp29);
    tmp31 = StringAdd_0(state_, TNode<Context>{p_context}, TNode<String>{phi_bb8_4}, TNode<String>{tmp30});
    ca_.Goto(&block24);
  }

    ca_.Bind(&block24);
  return TNode<String>{tmp31};
}

TF_BUILTIN(RegExpReplace, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSRegExp> parameter1 = UncheckedParameter<JSRegExp>(Descriptor::kRegexp);
  USE(parameter1);
  TNode<String> parameter2 = UncheckedParameter<String>(Descriptor::kString);
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kReplaceValue);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<String> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter3}, &label1);
    ca_.Goto(&block7);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block8);
    }
  }

  TNode<String> tmp2;
  TNode<JSRegExp> tmp3;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp2 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter3});
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_FastJSRegExp_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{parameter1}, &label4);
    ca_.Goto(&block15);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block16);
    }
  }

  TNode<BoolT> tmp5;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp5 = RegExpBuiltinsAssembler(state_).FastFlagGetterGlobal(TNode<JSRegExp>{parameter1});
    ca_.Branch(tmp5, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<String> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp6 = RegExpReplaceFastGlobalCallable_0(state_, TNode<Context>{parameter0}, TNode<JSRegExp>{parameter1}, TNode<String>{parameter2}, TNode<JSReceiver>{tmp0});
    ca_.Goto(&block11, tmp6);
  }

  TNode<String> tmp7;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp7 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringReplaceNonGlobalRegExpWithFunction, parameter0, parameter2, parameter1, tmp0)); 
    ca_.Goto(&block11, tmp7);
  }

  TNode<String> phi_bb11_6;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_6);
    CodeStubAssembler(state_).Return(phi_bb11_6);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block14);
  }

  TNode<String> tmp8;
  TNode<Smi> tmp9;
  TNode<Smi> tmp10;
  TNode<Smi> tmp11;
  TNode<BoolT> tmp12;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp8 = CodeStubAssembler(state_).SingleCharacterStringConstant("$");
    tmp9 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp10 = ca_.CallBuiltin<Smi>(Builtin::kStringIndexOf, TNode<Object>(), tmp2, tmp8, tmp9);
    tmp11 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
    tmp12 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp11});
    ca_.Branch(tmp12, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block14);
  }

  TNode<String> tmp13;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp13 = RegExpReplaceFastString_0(state_, TNode<Context>{parameter0}, TNode<JSRegExp>{tmp3}, TNode<String>{parameter2}, TNode<String>{tmp2});
    CodeStubAssembler(state_).Return(tmp13);
  }

  TNode<String> tmp14;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp14 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpReplaceRT, parameter0, parameter1, parameter2, tmp2)); 
    CodeStubAssembler(state_).Return(tmp14);
  }
}

TF_BUILTIN(RegExpPrototypeReplace, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<JSReceiver> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp0});
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp2});
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label5);
    ca_.Goto(&block3);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block4);
    }
  }

  TNode<Object> tmp6;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp6 = FromConstexpr_Object_constexpr_string_0(state_, "RegExp.prototype.@@replace");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp6}, TNode<Object>{parameter1});
  }

  TNode<String> tmp7;
  TNode<JSRegExp> tmp8;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp7 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{parameter0}, TNode<Object>{tmp1});
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_FastJSRegExp_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{tmp4}, &label9);
    ca_.Goto(&block7);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block8);
    }
  }

  TNode<Smi> tmp10;
  TNode<String> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp10 = CodeStubAssembler(state_).SmiConstant(v8::Isolate::kRegExpReplaceCalledOnSlowRegExp);
    CodeStubAssembler(state_).CallRuntime(Runtime::kIncrementUseCounter, parameter0, tmp10);
    tmp11 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpReplaceRT, parameter0, tmp4, tmp7, tmp3)); 
    arguments.PopAndReturn(tmp11);
  }

  TNode<String> tmp12;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp12 = ca_.CallBuiltin<String>(Builtin::kRegExpReplace, parameter0, tmp8, tmp7, tmp3);
    arguments.PopAndReturn(tmp12);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=193&c=10
TNode<BoolT> Is_FastJSRegExp_FastJSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSRegExp> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FastJSRegExp_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_o}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

} // namespace internal
} // namespace v8
