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
#include "torque-generated/src/builtins/set-symmetric-difference-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/function-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/object-groupby-tq-csa.h"
#include "torque-generated/src/builtins/set-difference-tq-csa.h"
#include "torque-generated/src/builtins/set-symmetric-difference-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(SetPrototypeSymmetricDifference, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kOther);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, IntPtrT, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, Object, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, Object, IntPtrT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, Object, IntPtrT, IntPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, Object, IntPtrT, IntPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, Object, Object, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi, JSReceiver> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi, JSReceiver> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi, JSReceiver> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi, JSReceiver> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, OrderedHashSet> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi, OrderedHashSet> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi, JSReceiver> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSSet> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_JSSet_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label2);
    ca_.Goto(&block3);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block4);
    }
  }

  TNode<Object> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_Object_constexpr_string_0(state_, "Set.prototype.symmetricDifference");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp3}, TNode<Object>{parameter1});
  }

  TNode<JSReceiver> tmp4;
  TNode<Number> tmp5;
  TNode<Object> tmp6;
  TNode<Object> tmp7;
  TNode<JSReceiver> tmp8;
  TNode<JSReceiver> tmp9;
  TNode<Object> tmp10;
  TNode<JSSet> tmp11;
  TNode<OrderedHashSet> tmp12;
  TNode<FixedArrayBase> tmp13;
  TNode<OrderedHashSet> tmp14;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    std::tie(tmp4, tmp5, tmp6, tmp7) = GetSetRecord_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, "Set.prototype.symmetricDifference").Flatten();
    tmp8 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp7});
    std::tie(tmp9, tmp10) = GetKeysIterator_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp4}, TNode<JSReceiver>{tmp8}).Flatten();
    std::tie(tmp11, tmp12) = NewStableBackingTableWitness_0(state_, TNode<JSSet>{tmp1}).Flatten();
    tmp13 = CodeStubAssembler(state_).CloneFixedArray(TNode<FixedArrayBase>{tmp12}, CodeStubAssembler::ExtractFixedArrayFlag::kFixedArrays);
    compiler::CodeAssemblerLabel label15(&ca_);
    tmp14 = Cast_OrderedHashSet_0(state_, TNode<HeapObject>{tmp13}, &label15);
    ca_.Goto(&block8);
    if (label15.is_used()) {
      ca_.Bind(&label15);
      ca_.Goto(&block9);
    }
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<UintPtrT> tmp20;
  TNode<UintPtrT> tmp21;
  TNode<BoolT> tmp22;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    std::tie(tmp16, tmp17, tmp18) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp14}).Flatten();
    tmp19 = FromConstexpr_intptr_constexpr_int32_0(state_, OrderedHashSet::NumberOfElementsIndex());
    tmp20 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp18});
    tmp22 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp20}, TNode<UintPtrT>{tmp21});
    ca_.Branch(tmp22, &block14, std::vector<compiler::Node*>{}, &block15, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<Object> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Object> tmp27;
  TNode<Smi> tmp28;
  TNode<JSSet> tmp29;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp23 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp19});
    tmp24 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp23});
    std::tie(tmp25, tmp26) = NewReference_Object_0(state_, TNode<Object>{tmp16}, TNode<IntPtrT>{tmp24}).Flatten();
    tmp27 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp25, tmp26});
    tmp28 = UnsafeCast_Smi_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp27});
    compiler::CodeAssemblerLabel label30(&ca_);
    tmp29 = Cast_JSSetWithNoCustomIteration_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label30);
    ca_.Goto(&block24);
    if (label30.is_used()) {
      ca_.Bind(&label30);
      ca_.Goto(&block25);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSMap> tmp31;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    compiler::CodeAssemblerLabel label32(&ca_);
    tmp31 = Cast_JSMapWithNoCustomIteration_1(state_, TNode<Context>{parameter0}, TNode<Object>{ca_.UncheckedCast<Object>(parameter2)}, &label32);
    ca_.Goto(&block37);
    if (label32.is_used()) {
      ca_.Bind(&label32);
      ca_.Goto(&block38);
    }
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    compiler::CodeAssemblerLabel label33(&ca_);
    CheckSetRecordHasJSSetMethods_0(state_, TorqueStructSetRecord{TNode<JSReceiver>{tmp4}, TNode<Number>{tmp5}, TNode<Object>{tmp6}, TNode<Object>{tmp7}}, &label33);
    ca_.Goto(&block26);
    if (label33.is_used()) {
      ca_.Bind(&label33);
      ca_.Goto(&block27);
    }
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.Goto(&block21);
  }

  TNode<JSSet> tmp34;
  TNode<OrderedHashSet> tmp35;
  TNode<OrderedHashSet> tmp36;
  TNode<Int32T> tmp37;
  TNode<Int32T> tmp38;
  TNode<Object> tmp39;
  TNode<IntPtrT> tmp40;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    std::tie(tmp34, tmp35) = NewStableBackingTableWitness_0(state_, TNode<JSSet>{tmp29}).Flatten();
    std::tie(tmp36, tmp37, tmp38, tmp39, tmp40) = NewUnmodifiedOrderedHashSetIterator_0(state_, TNode<OrderedHashSet>{tmp35}).Flatten();
    ca_.Goto(&block31, tmp14, tmp28, tmp39, tmp40);
  }

  TNode<OrderedHashSet> phi_bb31_14;
  TNode<Smi> phi_bb31_15;
  TNode<Object> phi_bb31_23;
  TNode<IntPtrT> phi_bb31_24;
  TNode<BoolT> tmp41;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_14, &phi_bb31_15, &phi_bb31_23, &phi_bb31_24);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp41, &block29, std::vector<compiler::Node*>{phi_bb31_14, phi_bb31_15, phi_bb31_23, phi_bb31_24}, &block30, std::vector<compiler::Node*>{phi_bb31_14, phi_bb31_15, phi_bb31_23, phi_bb31_24});
  }

  TNode<OrderedHashSet> phi_bb29_14;
  TNode<Smi> phi_bb29_15;
  TNode<Object> phi_bb29_23;
  TNode<IntPtrT> phi_bb29_24;
  TNode<Object> tmp42;
  TNode<IntPtrT> tmp43;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_14, &phi_bb29_15, &phi_bb29_23, &phi_bb29_24);
    compiler::CodeAssemblerLabel label44(&ca_);
    std::tie(tmp42, tmp43) = CollectionsBuiltinsAssembler(state_).NextKeyIndexPairUnmodifiedTable(TNode<OrderedHashSet>{tmp36}, TNode<Int32T>{tmp37}, TNode<Int32T>{tmp38}, TNode<IntPtrT>{phi_bb29_24}, &label44).Flatten();
    ca_.Goto(&block33, phi_bb29_14, phi_bb29_15, phi_bb29_23, phi_bb29_24, phi_bb29_24);
    if (label44.is_used()) {
      ca_.Bind(&label44);
      ca_.Goto(&block34, phi_bb29_14, phi_bb29_15, phi_bb29_23, phi_bb29_24, phi_bb29_24);
    }
  }

  TNode<OrderedHashSet> phi_bb34_14;
  TNode<Smi> phi_bb34_15;
  TNode<Object> phi_bb34_23;
  TNode<IntPtrT> phi_bb34_24;
  TNode<IntPtrT> phi_bb34_28;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_14, &phi_bb34_15, &phi_bb34_23, &phi_bb34_24, &phi_bb34_28);
    ca_.Goto(&block19, tmp12, phi_bb34_14, phi_bb34_15);
  }

  TNode<OrderedHashSet> phi_bb33_14;
  TNode<Smi> phi_bb33_15;
  TNode<Object> phi_bb33_23;
  TNode<IntPtrT> phi_bb33_24;
  TNode<IntPtrT> phi_bb33_28;
  TNode<OrderedHashSet> tmp45;
  TNode<Smi> tmp46;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_14, &phi_bb33_15, &phi_bb33_23, &phi_bb33_24, &phi_bb33_28);
    std::tie(tmp45, tmp46) = FastSymmetricDifference_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp42}, TorqueStructStableJSSetBackingTableWitness_0{TNode<JSSet>{tmp11}, TNode<OrderedHashSet>{tmp12}}, TorqueStructOrderedHashSetAndNumberOfElements_0{TNode<OrderedHashSet>{phi_bb33_14}, TNode<Smi>{phi_bb33_15}}, "Set.prototype.symmetricDifference").Flatten();
    ca_.Goto(&block31, tmp45, tmp46, tmp42, tmp43);
  }

  TNode<OrderedHashSet> phi_bb30_14;
  TNode<Smi> phi_bb30_15;
  TNode<Object> phi_bb30_23;
  TNode<IntPtrT> phi_bb30_24;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_14, &phi_bb30_15, &phi_bb30_23, &phi_bb30_24);
    ca_.Goto(&block22, phi_bb30_14, phi_bb30_15);
  }

  if (block38.is_used()) {
    ca_.Bind(&block38);
    ca_.Goto(&block21);
  }

  if (block37.is_used()) {
    ca_.Bind(&block37);
    compiler::CodeAssemblerLabel label47(&ca_);
    CheckSetRecordHasJSMapMethods_0(state_, TorqueStructSetRecord{TNode<JSReceiver>{tmp4}, TNode<Number>{tmp5}, TNode<Object>{tmp6}, TNode<Object>{tmp7}}, &label47);
    ca_.Goto(&block39);
    if (label47.is_used()) {
      ca_.Bind(&label47);
      ca_.Goto(&block40);
    }
  }

  if (block40.is_used()) {
    ca_.Bind(&block40);
    ca_.Goto(&block21);
  }

  TNode<JSMap> tmp48;
  TNode<OrderedHashMap> tmp49;
  TNode<OrderedHashMap> tmp50;
  TNode<Int32T> tmp51;
  TNode<Int32T> tmp52;
  TNode<Object> tmp53;
  TNode<Object> tmp54;
  TNode<IntPtrT> tmp55;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    std::tie(tmp48, tmp49) = NewStableBackingTableWitness_1(state_, TNode<JSMap>{tmp31}).Flatten();
    std::tie(tmp50, tmp51, tmp52, tmp53, tmp54, tmp55) = NewUnmodifiedOrderedHashMapIterator_0(state_, TNode<OrderedHashMap>{tmp49}).Flatten();
    ca_.Goto(&block44, tmp14, tmp28, tmp53, tmp54, tmp55);
  }

  TNode<OrderedHashSet> phi_bb44_14;
  TNode<Smi> phi_bb44_15;
  TNode<Object> phi_bb44_23;
  TNode<Object> phi_bb44_24;
  TNode<IntPtrT> phi_bb44_25;
  TNode<BoolT> tmp56;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_14, &phi_bb44_15, &phi_bb44_23, &phi_bb44_24, &phi_bb44_25);
    tmp56 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp56, &block42, std::vector<compiler::Node*>{phi_bb44_14, phi_bb44_15, phi_bb44_23, phi_bb44_24, phi_bb44_25}, &block43, std::vector<compiler::Node*>{phi_bb44_14, phi_bb44_15, phi_bb44_23, phi_bb44_24, phi_bb44_25});
  }

  TNode<OrderedHashSet> phi_bb42_14;
  TNode<Smi> phi_bb42_15;
  TNode<Object> phi_bb42_23;
  TNode<Object> phi_bb42_24;
  TNode<IntPtrT> phi_bb42_25;
  TNode<Object> tmp57;
  TNode<Object> tmp58;
  TNode<IntPtrT> tmp59;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_14, &phi_bb42_15, &phi_bb42_23, &phi_bb42_24, &phi_bb42_25);
    compiler::CodeAssemblerLabel label60(&ca_);
    std::tie(tmp57, tmp58, tmp59) = CollectionsBuiltinsAssembler(state_).NextKeyValueIndexTupleUnmodifiedTable(TNode<OrderedHashMap>{tmp50}, TNode<Int32T>{tmp51}, TNode<Int32T>{tmp52}, TNode<IntPtrT>{phi_bb42_25}, &label60).Flatten();
    ca_.Goto(&block46, phi_bb42_14, phi_bb42_15, phi_bb42_23, phi_bb42_24, phi_bb42_25, phi_bb42_25);
    if (label60.is_used()) {
      ca_.Bind(&label60);
      ca_.Goto(&block47, phi_bb42_14, phi_bb42_15, phi_bb42_23, phi_bb42_24, phi_bb42_25, phi_bb42_25);
    }
  }

  TNode<OrderedHashSet> phi_bb47_14;
  TNode<Smi> phi_bb47_15;
  TNode<Object> phi_bb47_23;
  TNode<Object> phi_bb47_24;
  TNode<IntPtrT> phi_bb47_25;
  TNode<IntPtrT> phi_bb47_29;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_14, &phi_bb47_15, &phi_bb47_23, &phi_bb47_24, &phi_bb47_25, &phi_bb47_29);
    ca_.Goto(&block19, tmp12, phi_bb47_14, phi_bb47_15);
  }

  TNode<OrderedHashSet> phi_bb46_14;
  TNode<Smi> phi_bb46_15;
  TNode<Object> phi_bb46_23;
  TNode<Object> phi_bb46_24;
  TNode<IntPtrT> phi_bb46_25;
  TNode<IntPtrT> phi_bb46_29;
  TNode<OrderedHashSet> tmp61;
  TNode<Smi> tmp62;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_14, &phi_bb46_15, &phi_bb46_23, &phi_bb46_24, &phi_bb46_25, &phi_bb46_29);
    std::tie(tmp61, tmp62) = FastSymmetricDifference_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp57}, TorqueStructStableJSSetBackingTableWitness_0{TNode<JSSet>{tmp11}, TNode<OrderedHashSet>{tmp12}}, TorqueStructOrderedHashSetAndNumberOfElements_0{TNode<OrderedHashSet>{phi_bb46_14}, TNode<Smi>{phi_bb46_15}}, "Set.prototype.symmetricDifference").Flatten();
    ca_.Goto(&block44, tmp61, tmp62, tmp57, tmp58, tmp59);
  }

  TNode<OrderedHashSet> phi_bb43_14;
  TNode<Smi> phi_bb43_15;
  TNode<Object> phi_bb43_23;
  TNode<Object> phi_bb43_24;
  TNode<IntPtrT> phi_bb43_25;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_14, &phi_bb43_15, &phi_bb43_23, &phi_bb43_24, &phi_bb43_25);
    ca_.Goto(&block22, phi_bb43_14, phi_bb43_15);
  }

  TNode<OrderedHashSet> phi_bb22_14;
  TNode<Smi> phi_bb22_15;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_14, &phi_bb22_15);
    ca_.Goto(&block20, tmp12, phi_bb22_14, phi_bb22_15);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.Goto(&block50, tmp12, tmp14, tmp28, ca_.Uninitialized<JSReceiver>());
  }

  TNode<OrderedHashSet> phi_bb50_12;
  TNode<OrderedHashSet> phi_bb50_14;
  TNode<Smi> phi_bb50_15;
  TNode<JSReceiver> phi_bb50_16;
  TNode<BoolT> tmp63;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_12, &phi_bb50_14, &phi_bb50_15, &phi_bb50_16);
    tmp63 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp63, &block48, std::vector<compiler::Node*>{phi_bb50_12, phi_bb50_14, phi_bb50_15, phi_bb50_16}, &block49, std::vector<compiler::Node*>{phi_bb50_12, phi_bb50_14, phi_bb50_15, phi_bb50_16});
  }

  TNode<OrderedHashSet> phi_bb48_12;
  TNode<OrderedHashSet> phi_bb48_14;
  TNode<Smi> phi_bb48_15;
  TNode<JSReceiver> phi_bb48_16;
  TNode<JSReceiver> tmp64;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_12, &phi_bb48_14, &phi_bb48_15, &phi_bb48_16);
    compiler::CodeAssemblerLabel label65(&ca_);
    tmp64 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp9}, TNode<Object>{tmp10}}, TNode<Map>{tmp0}, &label65);
    ca_.Goto(&block51, phi_bb48_12, phi_bb48_14, phi_bb48_15, phi_bb48_16);
    if (label65.is_used()) {
      ca_.Bind(&label65);
      ca_.Goto(&block52, phi_bb48_12, phi_bb48_14, phi_bb48_15, phi_bb48_16);
    }
  }

  TNode<OrderedHashSet> phi_bb52_12;
  TNode<OrderedHashSet> phi_bb52_14;
  TNode<Smi> phi_bb52_15;
  TNode<JSReceiver> phi_bb52_16;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_12, &phi_bb52_14, &phi_bb52_15, &phi_bb52_16);
    ca_.Goto(&block19, phi_bb52_12, phi_bb52_14, phi_bb52_15);
  }

  TNode<OrderedHashSet> phi_bb51_12;
  TNode<OrderedHashSet> phi_bb51_14;
  TNode<Smi> phi_bb51_15;
  TNode<JSReceiver> phi_bb51_16;
  TNode<Object> tmp66;
  TNode<Object> tmp67;
  TNode<BoolT> tmp68;
  TNode<IntPtrT> tmp69;
  TNode<Object> tmp70;
  TNode<HeapObject> tmp71;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_12, &phi_bb51_14, &phi_bb51_15, &phi_bb51_16);
    tmp66 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp64}, TNode<Map>{tmp0});
    tmp67 = CollectionsBuiltinsAssembler(state_).NormalizeNumberKey(TNode<Object>{tmp66});
    tmp68 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context>{parameter0}, TNode<OrderedHashSet>{phi_bb51_14}, TNode<Object>{tmp67});
    tmp69 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp70 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp11, tmp69});
    compiler::CodeAssemblerLabel label72(&ca_);
    tmp71 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp70}, &label72);
    ca_.Goto(&block57, phi_bb51_12, phi_bb51_14, phi_bb51_15);
    if (label72.is_used()) {
      ca_.Bind(&label72);
      ca_.Goto(&block58, phi_bb51_12, phi_bb51_14, phi_bb51_15);
    }
  }

  TNode<OrderedHashSet> phi_bb58_12;
  TNode<OrderedHashSet> phi_bb58_14;
  TNode<Smi> phi_bb58_15;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_12, &phi_bb58_14, &phi_bb58_15);
    ca_.Goto(&block55, phi_bb58_12, phi_bb58_14, phi_bb58_15);
  }

  TNode<OrderedHashSet> phi_bb57_12;
  TNode<OrderedHashSet> phi_bb57_14;
  TNode<Smi> phi_bb57_15;
  TNode<OrderedHashSet> tmp73;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_12, &phi_bb57_14, &phi_bb57_15);
    compiler::CodeAssemblerLabel label74(&ca_);
    tmp73 = Cast_OrderedHashSet_0(state_, TNode<HeapObject>{tmp71}, &label74);
    ca_.Goto(&block60, phi_bb57_12, phi_bb57_14, phi_bb57_15);
    if (label74.is_used()) {
      ca_.Bind(&label74);
      ca_.Goto(&block61, phi_bb57_12, phi_bb57_14, phi_bb57_15);
    }
  }

  TNode<OrderedHashSet> phi_bb61_12;
  TNode<OrderedHashSet> phi_bb61_14;
  TNode<Smi> phi_bb61_15;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_12, &phi_bb61_14, &phi_bb61_15);
    ca_.Goto(&block55, phi_bb61_12, phi_bb61_14, phi_bb61_15);
  }

  TNode<OrderedHashSet> phi_bb60_12;
  TNode<OrderedHashSet> phi_bb60_14;
  TNode<Smi> phi_bb60_15;
  TNode<OrderedHashSet> tmp75;
  TNode<BoolT> tmp76;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_12, &phi_bb60_14, &phi_bb60_15);
    tmp75 = (TNode<OrderedHashSet>{tmp73});
    tmp76 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context>{parameter0}, TNode<OrderedHashSet>{tmp75}, TNode<Object>{tmp67});
    ca_.Branch(tmp76, &block62, std::vector<compiler::Node*>{phi_bb60_14, phi_bb60_15}, &block63, std::vector<compiler::Node*>{phi_bb60_14, phi_bb60_15});
  }

  TNode<OrderedHashSet> phi_bb55_12;
  TNode<OrderedHashSet> phi_bb55_14;
  TNode<Smi> phi_bb55_15;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_12, &phi_bb55_14, &phi_bb55_15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<OrderedHashSet> phi_bb62_14;
  TNode<Smi> phi_bb62_15;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_14, &phi_bb62_15);
    ca_.Branch(tmp68, &block66, std::vector<compiler::Node*>{phi_bb62_14, phi_bb62_15}, &block67, std::vector<compiler::Node*>{phi_bb62_14, phi_bb62_15});
  }

  TNode<OrderedHashSet> phi_bb66_14;
  TNode<Smi> phi_bb66_15;
  TNode<Smi> tmp77;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_14, &phi_bb66_15);
    compiler::CodeAssemblerLabel label78(&ca_);
    tmp77 = CollectionsBuiltinsAssembler(state_).DeleteFromSetTable(TNode<Context>{parameter0}, TNode<OrderedHashSet>{phi_bb66_14}, TNode<Object>{tmp67}, &label78);
    ca_.Goto(&block70, phi_bb66_14, phi_bb66_15, phi_bb66_14);
    if (label78.is_used()) {
      ca_.Bind(&label78);
      ca_.Goto(&block71, phi_bb66_14, phi_bb66_15, phi_bb66_14);
    }
  }

  TNode<OrderedHashSet> phi_bb71_14;
  TNode<Smi> phi_bb71_15;
  TNode<OrderedHashSet> phi_bb71_19;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_14, &phi_bb71_15, &phi_bb71_19);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<OrderedHashSet> phi_bb70_14;
  TNode<Smi> phi_bb70_15;
  TNode<OrderedHashSet> phi_bb70_19;
  if (block70.is_used()) {
    ca_.Bind(&block70, &phi_bb70_14, &phi_bb70_15, &phi_bb70_19);
    ca_.Goto(&block67, phi_bb70_14, tmp77);
  }

  TNode<OrderedHashSet> phi_bb67_14;
  TNode<Smi> phi_bb67_15;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_14, &phi_bb67_15);
    ca_.Goto(&block65, phi_bb67_14, phi_bb67_15);
  }

  TNode<OrderedHashSet> phi_bb63_14;
  TNode<Smi> phi_bb63_15;
  TNode<BoolT> tmp79;
  if (block63.is_used()) {
    ca_.Bind(&block63, &phi_bb63_14, &phi_bb63_15);
    tmp79 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp68});
    ca_.Branch(tmp79, &block72, std::vector<compiler::Node*>{phi_bb63_14, phi_bb63_15}, &block73, std::vector<compiler::Node*>{phi_bb63_14, phi_bb63_15});
  }

  TNode<OrderedHashSet> phi_bb72_14;
  TNode<Smi> phi_bb72_15;
  TNode<String> tmp80;
  TNode<OrderedHashSet> tmp81;
  TNode<Smi> tmp82;
  TNode<Smi> tmp83;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_14, &phi_bb72_15);
    tmp80 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.symmetricDifference");
    tmp81 = CollectionsBuiltinsAssembler(state_).AddToSetTable(TNode<Context>{parameter0}, TNode<OrderedHashSet>{phi_bb72_14}, TNode<Object>{tmp67}, TNode<String>{tmp80});
    tmp82 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp83 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb72_15}, TNode<Smi>{tmp82});
    ca_.Goto(&block73, tmp81, tmp83);
  }

  TNode<OrderedHashSet> phi_bb73_14;
  TNode<Smi> phi_bb73_15;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_14, &phi_bb73_15);
    ca_.Goto(&block65, phi_bb73_14, phi_bb73_15);
  }

  TNode<OrderedHashSet> phi_bb65_14;
  TNode<Smi> phi_bb65_15;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_14, &phi_bb65_15);
    ca_.Goto(&block50, tmp75, phi_bb65_14, phi_bb65_15, tmp64);
  }

  TNode<OrderedHashSet> phi_bb49_12;
  TNode<OrderedHashSet> phi_bb49_14;
  TNode<Smi> phi_bb49_15;
  TNode<JSReceiver> phi_bb49_16;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_12, &phi_bb49_14, &phi_bb49_15, &phi_bb49_16);
    ca_.Goto(&block20, phi_bb49_12, phi_bb49_14, phi_bb49_15);
  }

  TNode<OrderedHashSet> phi_bb20_12;
  TNode<OrderedHashSet> phi_bb20_14;
  TNode<Smi> phi_bb20_15;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_12, &phi_bb20_14, &phi_bb20_15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<OrderedHashSet> phi_bb19_12;
  TNode<OrderedHashSet> phi_bb19_14;
  TNode<Smi> phi_bb19_15;
  TNode<OrderedHashSet> tmp84;
  TNode<IntPtrT> tmp85;
  TNode<Object> tmp86;
  TNode<IntPtrT> tmp87;
  TNode<Map> tmp88;
  TNode<FixedArray> tmp89;
  TNode<FixedArray> tmp90;
  TNode<BoolT> tmp91;
  TNode<BoolT> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<HeapObject> tmp94;
  TNode<IntPtrT> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<IntPtrT> tmp98;
  TNode<JSSet> tmp99;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_12, &phi_bb19_14, &phi_bb19_15);
    tmp84 = ShrinkOrderedHashSetIfNeeded_0(state_, TNode<Context>{parameter0}, TNode<Smi>{phi_bb19_15}, TNode<OrderedHashSet>{phi_bb19_14});
    tmp85 = JS_SET_MAP_INDEX_0(state_);
    std::tie(tmp86, tmp87) = NativeContextSlot_NativeContext_Map_0(state_, TNode<NativeContext>{parameter0}, TNode<IntPtrT>{tmp85}).Flatten();
    tmp88 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp86, tmp87});
    tmp89 = kEmptyFixedArray_0(state_);
    tmp90 = kEmptyFixedArray_0(state_);
    tmp91 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp92 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp93 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp94 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp93}, TNode<Map>{tmp88}, TNode<BoolT>{tmp91}, TNode<BoolT>{tmp92});
    tmp95 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp94, tmp95}, tmp88);
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp94, tmp96}, tmp89);
    tmp97 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp94, tmp97}, tmp90);
    tmp98 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp94, tmp98}, tmp84);
    tmp99 = TORQUE_CAST(TNode<HeapObject>{tmp94});
    CodeStubAssembler(state_).Return(tmp99);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-symmetric-difference.tq?l=135&c=1
TorqueStructOrderedHashSetAndNumberOfElements_0 FastSymmetricDifference_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_nextValue, TorqueStructStableJSSetBackingTableWitness_0 p_table, TorqueStructOrderedHashSetAndNumberOfElements_0 p_resultSetDataAndNumberOfElements, const char* p_methodName) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CollectionsBuiltinsAssembler(state_).NormalizeNumberKey(TNode<Object>{p_nextValue});
    tmp1 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context>{p_context}, TNode<OrderedHashSet>{p_resultSetDataAndNumberOfElements.setData}, TNode<Object>{tmp0});
    ca_.Branch(tmp1, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp2;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = CollectionsBuiltinsAssembler(state_).DeleteFromSetTable(TNode<Context>{p_context}, TNode<OrderedHashSet>{p_resultSetDataAndNumberOfElements.setData}, TNode<Object>{tmp0}, &label3);
    ca_.Goto(&block12);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block13);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block9, p_resultSetDataAndNumberOfElements.setData, tmp2);
  }

  TNode<String> tmp4;
  TNode<OrderedHashSet> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = FromConstexpr_String_constexpr_string_0(state_, p_methodName);
    tmp5 = CollectionsBuiltinsAssembler(state_).AddToSetTable(TNode<Context>{p_context}, TNode<OrderedHashSet>{p_resultSetDataAndNumberOfElements.setData}, TNode<Object>{tmp0}, TNode<String>{tmp4});
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{p_resultSetDataAndNumberOfElements.numberOfElements}, TNode<Smi>{tmp6});
    ca_.Goto(&block9, tmp5, tmp7);
  }

  TNode<OrderedHashSet> phi_bb9_7;
  TNode<Smi> phi_bb9_8;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_7, &phi_bb9_8);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
  return TorqueStructOrderedHashSetAndNumberOfElements_0{TNode<OrderedHashSet>{phi_bb9_7}, TNode<Smi>{phi_bb9_8}};
}

} // namespace internal
} // namespace v8
