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
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-function-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=103&c=1
TNode<Int32T> LoadOrderedHashTableMetadata_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_table, int32_t p_fieldIndex) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{p_table}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_int32_0(state_, p_fieldIndex);
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  TNode<Smi> tmp12;
  TNode<Int32T> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp7});
    std::tie(tmp9, tmp10) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp8}).Flatten();
    tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp9, tmp10});
    tmp12 = TORQUE_CAST(TNode<Object>{tmp11});
    tmp13 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp12});
    ca_.Goto(&block20);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block20);
  return TNode<Int32T>{tmp13};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=115&c=1
TorqueStructUnmodifiedOrderedHashSetIterator_0 NewUnmodifiedOrderedHashSetIterator_0(compiler::CodeAssemblerState* state_, TNode<OrderedHashSet> p_table) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Int32T> tmp3;
  TNode<Undefined> tmp4;
  TNode<IntPtrT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray>{p_table}, OrderedHashSet::NumberOfBucketsIndex());
    tmp1 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray>{p_table}, OrderedHashSet::NumberOfElementsIndex());
    tmp2 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray>{p_table}, OrderedHashSet::NumberOfDeletedElementsIndex());
    tmp3 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp2});
    tmp4 = Undefined_0(state_);
    tmp5 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructUnmodifiedOrderedHashSetIterator_0{TNode<OrderedHashSet>{p_table}, TNode<Int32T>{tmp0}, TNode<Int32T>{tmp3}, TorqueStructKeyIndexPair{TNode<Object>{tmp4}, TNode<IntPtrT>{tmp5}}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=135&c=1
TorqueStructOrderedHashSetIterator_0 NewOrderedHashSetIterator_0(compiler::CodeAssemblerState* state_, TNode<OrderedHashSet> p_table) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Undefined> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Undefined_0(state_);
    tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructOrderedHashSetIterator_0{TNode<OrderedHashSet>{p_table}, TorqueStructKeyIndexPair{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=200&c=1
TorqueStructUnmodifiedOrderedHashMapIterator_0 NewUnmodifiedOrderedHashMapIterator_0(compiler::CodeAssemblerState* state_, TNode<OrderedHashMap> p_table) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Int32T> tmp3;
  TNode<Undefined> tmp4;
  TNode<Undefined> tmp5;
  TNode<IntPtrT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray>{p_table}, OrderedHashMap::NumberOfBucketsIndex());
    tmp1 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray>{p_table}, OrderedHashMap::NumberOfElementsIndex());
    tmp2 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray>{p_table}, OrderedHashMap::NumberOfDeletedElementsIndex());
    tmp3 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp2});
    tmp4 = Undefined_0(state_);
    tmp5 = Undefined_0(state_);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructUnmodifiedOrderedHashMapIterator_0{TNode<OrderedHashMap>{p_table}, TNode<Int32T>{tmp0}, TNode<Int32T>{tmp3}, TorqueStructKeyValueIndexTuple{TNode<Object>{tmp4}, TNode<Object>{tmp5}, TNode<IntPtrT>{tmp6}}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=220&c=1
TorqueStructKeyValuePair LoadKeyValuePairNoSideEffects_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_MayHaveSideEffects) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_FastJSArray_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(label_MayHaveSideEffects);
  }

  TNode<Smi> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<FixedArrayBase> tmp4;
  TNode<FixedArray> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp0});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp0, tmp3});
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp4}, &label6);
    ca_.Goto(&block9);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block10);
    }
  }

  TNode<FixedDoubleArray> tmp7;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    compiler::CodeAssemblerLabel label8(&ca_);
    tmp7 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<FixedArrayBase>(tmp4)}, &label8);
    ca_.Goto(&block21);
    if (label8.is_used()) {
      ca_.Bind(&label8);
      ca_.Goto(&block22);
    }
  }

  TNode<Smi> tmp9;
  TNode<BoolT> tmp10;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp9 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp10 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp2}, TNode<Smi>{tmp9});
    ca_.Branch(tmp10, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp11;
  TNode<Object> tmp12;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp11 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp12 = LoadElementOrUndefined_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp5}, TNode<Smi>{tmp11});
    ca_.Goto(&block13, tmp12);
  }

  TNode<Undefined> tmp13;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp13 = Undefined_0(state_);
    ca_.Goto(&block13, tmp13);
  }

  TNode<Object> phi_bb13_7;
  TNode<Smi> tmp14;
  TNode<BoolT> tmp15;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_7);
    tmp14 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp15 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp2}, TNode<Smi>{tmp14});
    ca_.Branch(tmp15, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp16;
  TNode<Object> tmp17;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp16 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp17 = LoadElementOrUndefined_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp5}, TNode<Smi>{tmp16});
    ca_.Goto(&block17, tmp17);
  }

  TNode<Undefined> tmp18;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp18 = Undefined_0(state_);
    ca_.Goto(&block17, tmp18);
  }

  TNode<Object> phi_bb17_8;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_8);
    ca_.Goto(&block2, phi_bb13_7, phi_bb17_8);
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> tmp19;
  TNode<BoolT> tmp20;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp19 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp20 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp2}, TNode<Smi>{tmp19});
    ca_.Branch(tmp20, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp21;
  TNode<Object> tmp22;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp21 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp22 = LoadElementOrUndefined_1(state_, TNode<FixedDoubleArray>{tmp7}, TNode<Smi>{tmp21});
    ca_.Goto(&block25, tmp22);
  }

  TNode<Undefined> tmp23;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp23 = Undefined_0(state_);
    ca_.Goto(&block25, tmp23);
  }

  TNode<Object> phi_bb25_7;
  TNode<Smi> tmp24;
  TNode<BoolT> tmp25;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_7);
    tmp24 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp25 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp2}, TNode<Smi>{tmp24});
    ca_.Branch(tmp25, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp26;
  TNode<Object> tmp27;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp26 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp27 = LoadElementOrUndefined_1(state_, TNode<FixedDoubleArray>{tmp7}, TNode<Smi>{tmp26});
    ca_.Goto(&block29, tmp27);
  }

  TNode<Undefined> tmp28;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp28 = Undefined_0(state_);
    ca_.Goto(&block29, tmp28);
  }

  TNode<Object> phi_bb29_8;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_8);
    ca_.Goto(&block2, phi_bb25_7, phi_bb29_8);
  }

  TNode<Object> phi_bb2_2;
  TNode<Object> phi_bb2_3;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_2, &phi_bb2_3);
    ca_.Goto(&block31);
  }

    ca_.Bind(&block31);
  return TorqueStructKeyValuePair{TNode<Object>{phi_bb2_2}, TNode<Object>{phi_bb2_3}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=254&c=1
TorqueStructKeyValuePair LoadKeyValuePair_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label2(&ca_);
    std::tie(tmp0, tmp1) = LoadKeyValuePairNoSideEffects_0(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label2).Flatten();
    ca_.Goto(&block4);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block5);
    }
  }

  TNode<JSReceiver> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label4);
    ca_.Goto(&block8);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block9);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1, tmp0, tmp1);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kIteratorValueNotAnObject, TNode<Object>{p_o});
  }

  TNode<Smi> tmp5;
  TNode<Object> tmp6;
  TNode<Smi> tmp7;
  TNode<Object> tmp8;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp5 = Convert_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp3}, TNode<Object>{tmp5});
    tmp7 = Convert_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp8 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp3}, TNode<Object>{tmp7});
    ca_.Goto(&block1, tmp6, tmp8);
  }

  TNode<Object> phi_bb1_2;
  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2, &phi_bb1_3);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TorqueStructKeyValuePair{TNode<Object>{phi_bb1_2}, TNode<Object>{phi_bb1_3}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=270&c=1
TorqueStructSetRecord GetSetRecord_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_obj, const char* p_methodName) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_obj}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kArgumentIsNonObject, p_methodName);
  }

  TNode<String> tmp2;
  TNode<Object> tmp3;
  TNode<Number> tmp4;
  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = kSizeString_0(state_);
    tmp3 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp0}, TNode<Object>{tmp2});
    tmp4 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{p_context}, TNode<Object>{tmp3});
    tmp5 = NumberIsNaN_0(state_, TNode<Number>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kSizeIsNaN);
  }

  TNode<Number> tmp6;
  TNode<Number> tmp7;
  TNode<BoolT> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp6 = ToInteger_Inline_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp4});
    tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = NumberIsLessThan_0(state_, TNode<Number>{tmp6}, TNode<Number>{tmp7});
    ca_.Branch(tmp8, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kInvalidSizeValue, TNode<Object>{tmp6});
  }

  TNode<String> tmp9;
  TNode<Object> tmp10;
  TNode<JSReceiver> tmp11;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp9 = kHasString_0(state_);
    tmp10 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp0}, TNode<Object>{tmp9});
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp10}, &label12);
    ca_.Goto(&block12);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block13);
    }
  }

  TNode<String> tmp13;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp13 = kHasString_0(state_);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, p_context, tmp13);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<String> tmp14;
  TNode<Object> tmp15;
  TNode<JSReceiver> tmp16;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp14 = kKeysString_0(state_);
    tmp15 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp0}, TNode<Object>{tmp14});
    compiler::CodeAssemblerLabel label17(&ca_);
    tmp16 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp15}, &label17);
    ca_.Goto(&block16);
    if (label17.is_used()) {
      ca_.Bind(&label17);
      ca_.Goto(&block17);
    }
  }

  TNode<String> tmp18;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp18 = kKeysString_0(state_);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, p_context, tmp18);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block18);
  }

    ca_.Bind(&block18);
  return TorqueStructSetRecord{TNode<JSReceiver>{tmp0}, TNode<Number>{tmp6}, TNode<Object>{tmp11}, TNode<Object>{tmp16}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=316&c=1
TorqueStructIteratorRecord GetKeysIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_set, TNode<JSReceiver> p_keys) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<JSReceiver> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{p_keys}, TNode<Object>{p_set});
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp0}, &label2);
    ca_.Goto(&block4);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kKeysMethodInvalid);
  }

  TNode<String> tmp3;
  TNode<Object> tmp4;
  TNode<JSReceiver> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = kNextString_0(state_);
    tmp4 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp0}, TNode<Object>{tmp3});
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp4}, &label6);
    ca_.Goto(&block8);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block9);
    }
  }

  TNode<String> tmp7;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp7 = kNextString_0(state_);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, p_context, tmp7);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp4}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=338&c=1
void CheckSetRecordHasJSSetMethods_0(compiler::CodeAssemblerState* state_, TorqueStructSetRecord p_setRecord, compiler::CodeAssemblerLabel* label_HasUserProvidedMethods) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_setRecord.keys}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1);
  }

  TNode<JSFunction> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSFunction_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block6);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block7);
    }
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block1);
  }

  TNode<HeapObject> tmp4;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_setRecord.has}, &label5);
    ca_.Goto(&block9);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block1);
  }

  TNode<JSFunction> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_JSFunction_0(state_, TNode<HeapObject>{tmp4}, &label7);
    ca_.Goto(&block11);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp8;
  TNode<SharedFunctionInfo> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  TNode<Smi> tmp12;
  TNode<BoolT> tmp13;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp9 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{tmp2, tmp8});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp9, tmp10});
    tmp12 = CodeStubAssembler(state_).SmiConstant(Builtin::kSetPrototypeValues);
    tmp13 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp11}, TNode<MaybeObject>{tmp12});
    ca_.Branch(tmp13, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp14;
  TNode<SharedFunctionInfo> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Object> tmp17;
  TNode<Smi> tmp18;
  TNode<BoolT> tmp19;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp15 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{tmp6, tmp14});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp17 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp15, tmp16});
    tmp18 = CodeStubAssembler(state_).SmiConstant(Builtin::kSetPrototypeHas);
    tmp19 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp17}, TNode<MaybeObject>{tmp18});
    ca_.Goto(&block17, tmp19);
  }

  TNode<BoolT> tmp20;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp20 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block17, tmp20);
  }

  TNode<BoolT> phi_bb17_7;
  TNode<BoolT> tmp21;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_7);
    tmp21 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb17_7});
    ca_.Branch(tmp21, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block18);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_HasUserProvidedMethods);
  }

    ca_.Bind(&block18);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=352&c=1
void CheckSetRecordHasJSMapMethods_0(compiler::CodeAssemblerState* state_, TorqueStructSetRecord p_setRecord, compiler::CodeAssemblerLabel* label_HasUserProvidedMethods) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_setRecord.keys}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1);
  }

  TNode<JSFunction> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSFunction_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block6);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block7);
    }
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block1);
  }

  TNode<HeapObject> tmp4;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_setRecord.has}, &label5);
    ca_.Goto(&block9);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block1);
  }

  TNode<JSFunction> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_JSFunction_0(state_, TNode<HeapObject>{tmp4}, &label7);
    ca_.Goto(&block11);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp8;
  TNode<SharedFunctionInfo> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  TNode<Smi> tmp12;
  TNode<BoolT> tmp13;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp9 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{tmp2, tmp8});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp9, tmp10});
    tmp12 = CodeStubAssembler(state_).SmiConstant(Builtin::kMapPrototypeKeys);
    tmp13 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp11}, TNode<MaybeObject>{tmp12});
    ca_.Branch(tmp13, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp14;
  TNode<SharedFunctionInfo> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Object> tmp17;
  TNode<Smi> tmp18;
  TNode<BoolT> tmp19;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp15 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{tmp6, tmp14});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp17 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp15, tmp16});
    tmp18 = CodeStubAssembler(state_).SmiConstant(Builtin::kMapPrototypeHas);
    tmp19 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp17}, TNode<MaybeObject>{tmp18});
    ca_.Goto(&block17, tmp19);
  }

  TNode<BoolT> tmp20;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp20 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block17, tmp20);
  }

  TNode<BoolT> phi_bb17_7;
  TNode<BoolT> tmp21;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_7);
    tmp21 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb17_7});
    ca_.Branch(tmp21, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block18);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_HasUserProvidedMethods);
  }

    ca_.Bind(&block18);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=366&c=1
TNode<OrderedHashSet> ShrinkOrderedHashSetIfNeeded_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_numberOfElements, TNode<OrderedHashSet> p_resultSetData) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Int32T> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray>{p_resultSetData}, OrderedHashSet::NumberOfBucketsIndex());
    tmp1 = Convert_int32_Smi_0(state_, TNode<Smi>{p_numberOfElements});
    tmp2 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp3 = CodeStubAssembler(state_).Int32Div(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp2});
    tmp4 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp3});
    ca_.Branch(tmp4, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{p_resultSetData});
  }

  TNode<OrderedHashSet> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp5 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kOrderedHashSetShrink, p_context, p_resultSetData)); 
    ca_.Goto(&block7, tmp5);
  }

  TNode<OrderedHashSet> phi_bb7_3;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_3);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<OrderedHashSet>{phi_bb7_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=425&c=1
TorqueStructStableJSSetBackingTableWitness_0 NewStableBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<JSSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<HeapObject> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block3);
  }

  TNode<OrderedHashSet> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_OrderedHashSet_0(state_, TNode<HeapObject>{tmp2}, &label5);
    ca_.Goto(&block8);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block9);
    }
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block3);
  }

  TNode<OrderedHashSet> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp6 = (TNode<OrderedHashSet>{tmp4});
    ca_.Goto(&block10);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructStableJSSetBackingTableWitness_0{TNode<JSSet>{p_o}, TNode<OrderedHashSet>{tmp6}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=433&c=1
TorqueStructStableJSMapBackingTableWitness_0 NewStableBackingTableWitness_1(compiler::CodeAssemblerState* state_, TNode<JSMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<HeapObject> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block3);
  }

  TNode<OrderedHashMap> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_OrderedHashMap_0(state_, TNode<HeapObject>{tmp2}, &label5);
    ca_.Goto(&block8);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block9);
    }
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block3);
  }

  TNode<OrderedHashMap> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp6 = (TNode<OrderedHashMap>{tmp4});
    ca_.Goto(&block10);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructStableJSMapBackingTableWitness_0{TNode<JSMap>{p_o}, TNode<OrderedHashMap>{tmp6}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=429&c=15
TNode<OrderedHashSet> Cast_StableOrderedHashSet_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<OrderedHashSet> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_StableOrderedHashSet_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<OrderedHashSet>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=437&c=15
TNode<OrderedHashMap> Cast_StableOrderedHashMap_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<OrderedHashMap> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_StableOrderedHashMap_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<OrderedHashMap>{tmp2};
}

} // namespace internal
} // namespace v8
