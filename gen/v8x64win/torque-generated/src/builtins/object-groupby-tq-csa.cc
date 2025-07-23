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
#include "torque-generated/src/builtins/object-groupby-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/object-groupby-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object-groupby.tq?l=15&c=1
TNode<Object> CoerceGroupKey_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_key, TNode<Boolean> p_coerceToProperty) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<True> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = True_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{p_coerceToProperty}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Name> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = ca_.CallBuiltin<Name>(Builtin::kToName, p_context, p_key);
    ca_.Goto(&block1, tmp2);
  }

  TNode<Object> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = CollectionsBuiltinsAssembler(state_).NormalizeNumberKey(TNode<Object>{p_key});
    ca_.Goto(&block1, tmp3);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<Object>{phi_bb1_3};
}

TF_BUILTIN(GroupByGeneric, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kItems);
  USE(parameter1);
  TNode<OrderedHashMap> parameter2 = UncheckedParameter<OrderedHashMap>(Descriptor::kInitialGroups);
  USE(parameter2);
  TNode<JSReceiver> parameter3 = UncheckedParameter<JSReceiver>(Descriptor::kCallbackfn);
  USE(parameter3);
  TNode<Boolean> parameter4 = UncheckedParameter<Boolean>(Descriptor::kCoerceToProperty);
  USE(parameter4);
  TNode<String> parameter5 = UncheckedParameter<String>(Descriptor::kMethodName);
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Number, Number> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Number> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Number, Object, Object, HeapObject> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSReceiver> tmp1;
  TNode<Object> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    std::tie(tmp1, tmp2) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{parameter0}, TNode<Object>{parameter1}).Flatten();
    tmp3 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block3, parameter2, tmp3);
  }

  TNode<OrderedHashMap> phi_bb3_6;
  TNode<Number> phi_bb3_10;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_6, &phi_bb3_10);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp4, &block1, std::vector<compiler::Node*>{phi_bb3_6, phi_bb3_10}, &block2, std::vector<compiler::Node*>{phi_bb3_6, phi_bb3_10});
  }

  TNode<OrderedHashMap> phi_bb1_6;
  TNode<Number> phi_bb1_10;
  TNode<JSReceiver> tmp5;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_6, &phi_bb1_10);
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, TNode<Map>{tmp0}, &label6);
    ca_.Goto(&block10, phi_bb1_6, phi_bb1_10);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block11, phi_bb1_6, phi_bb1_10);
    }
  }

  TNode<OrderedHashMap> phi_bb11_6;
  TNode<Number> phi_bb11_10;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_6, &phi_bb11_10);
    CodeStubAssembler(state_).Return(phi_bb11_6);
  }

  TNode<OrderedHashMap> phi_bb10_6;
  TNode<Number> phi_bb10_10;
  TNode<Object> tmp7;
  TNode<Undefined> tmp8;
  TNode<Object> tmp9;
      TNode<Object> tmp11;
  TNode<Object> tmp12;
      TNode<Object> tmp14;
  TNode<OrderedHashMap> tmp15;
  TNode<Number> tmp16;
  TNode<Number> tmp17;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_6, &phi_bb10_10);
    tmp7 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp5}, TNode<Map>{tmp0});
    tmp8 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch10__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch10__label);
    tmp9 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{parameter3}, TNode<Object>{tmp8}, TNode<Object>{tmp7}, TNode<Object>{phi_bb10_10});
    }
    if (catch10__label.is_used()) {
      compiler::CodeAssemblerLabel catch10_skip(&ca_);
      ca_.Goto(&catch10_skip);
      ca_.Bind(&catch10__label, &tmp11);
      ca_.Goto(&block14, phi_bb10_6, phi_bb10_10, phi_bb10_10);
      ca_.Bind(&catch10_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch13__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch13__label);
    tmp12 = CoerceGroupKey_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp9}, TNode<Boolean>{parameter4});
    }
    if (catch13__label.is_used()) {
      compiler::CodeAssemblerLabel catch13_skip(&ca_);
      ca_.Goto(&catch13_skip);
      ca_.Bind(&catch13__label, &tmp14);
      ca_.Goto(&block15, phi_bb10_6, phi_bb10_10);
      ca_.Bind(&catch13_skip);
    }
    tmp15 = CollectionsBuiltinsAssembler(state_).AddValueToKeyedGroup(TNode<OrderedHashMap>{phi_bb10_6}, TNode<Object>{tmp12}, TNode<Object>{tmp7}, TNode<String>{parameter5});
    tmp16 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp17 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb10_10}, TNode<Number>{tmp16});
    ca_.Goto(&block3, tmp15, tmp17);
  }

  TNode<OrderedHashMap> phi_bb14_6;
  TNode<Number> phi_bb14_10;
  TNode<Number> phi_bb14_18;
  TNode<HeapObject> tmp18;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_6, &phi_bb14_10, &phi_bb14_18);
    tmp18 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block13, phi_bb14_6, phi_bb14_10, ca_.Uninitialized<Object>(), tmp11, tmp18);
  }

  TNode<OrderedHashMap> phi_bb15_6;
  TNode<Number> phi_bb15_10;
  TNode<HeapObject> tmp19;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_6, &phi_bb15_10);
    tmp19 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block13, phi_bb15_6, phi_bb15_10, tmp9, tmp14, tmp19);
  }

  TNode<OrderedHashMap> phi_bb13_6;
  TNode<Number> phi_bb13_10;
  TNode<Object> phi_bb13_13;
  TNode<Object> phi_bb13_14;
  TNode<HeapObject> phi_bb13_15;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_6, &phi_bb13_10, &phi_bb13_13, &phi_bb13_14, &phi_bb13_15);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb13_14, phi_bb13_15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<OrderedHashMap> phi_bb2_6;
  TNode<Number> phi_bb2_10;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_6, &phi_bb2_10);
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object-groupby.tq?l=94&c=1
TNode<OrderedHashMap> GroupByImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_items, TNode<Object> p_callback, TNode<Boolean> p_coerceToProperty, const char* p_methodName) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi, Smi, Smi> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi, Smi, Smi, Smi> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi, Smi, Smi, Smi> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi, Smi, Smi> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi, Smi, Smi, Smi> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi, Smi, Smi, Smi> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi, Smi, Smi, Object> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, Smi, Object> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap, JSArray, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<OrderedHashMap> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<JSReceiver> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = RequireObjectCoercible_0(state_, TNode<Context>{p_context}, TNode<Object>{p_items}, p_methodName);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{p_callback}, &label2);
    ca_.Goto(&block4);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledNonCallable, TNode<Object>{p_callback});
  }

  TNode<OrderedHashMap> tmp3;
  TNode<JSArray> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = CodeStubAssembler(state_).AllocateOrderedHashMap();
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_FastJSArrayForReadWithNoCustomIteration_1(state_, TNode<Context>{p_context}, TNode<Object>{p_items}, &label5);
    ca_.Goto(&block10);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block11);
    }
  }

  TNode<String> tmp6;
  TNode<OrderedHashMap> tmp7;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp6 = FromConstexpr_String_constexpr_string_0(state_, p_methodName);
    tmp7 = ca_.CallBuiltin<OrderedHashMap>(Builtin::kGroupByGeneric, p_context, p_items, tmp3, tmp1, p_coerceToProperty, tmp6);
    ca_.Goto(&block1, tmp7);
  }

  TNode<JSArray> tmp8;
  TNode<JSArray> tmp9;
  TNode<Map> tmp10;
  TNode<BoolT> tmp11;
  TNode<Smi> tmp12;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    std::tie(tmp8, tmp9, tmp10, tmp11) = NewFastJSArrayForReadWitness_0(state_, TNode<JSArray>{tmp4}).Flatten();
    tmp12 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block16, tmp3, tmp9, tmp12);
  }

  TNode<OrderedHashMap> phi_bb16_5;
  TNode<JSArray> phi_bb16_9;
  TNode<Smi> phi_bb16_13;
  TNode<IntPtrT> tmp13;
  TNode<Number> tmp14;
  TNode<BoolT> tmp15;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_5, &phi_bb16_9, &phi_bb16_13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp14 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp8, tmp13});
    tmp15 = NumberIsLessThan_0(state_, TNode<Number>{phi_bb16_13}, TNode<Number>{tmp14});
    ca_.Branch(tmp15, &block14, std::vector<compiler::Node*>{phi_bb16_5, phi_bb16_9, phi_bb16_13}, &block15, std::vector<compiler::Node*>{phi_bb16_5, phi_bb16_9, phi_bb16_13});
  }

  TNode<OrderedHashMap> phi_bb14_5;
  TNode<JSArray> phi_bb14_9;
  TNode<Smi> phi_bb14_13;
  TNode<IntPtrT> tmp16;
  TNode<Map> tmp17;
  TNode<BoolT> tmp18;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_5, &phi_bb14_9, &phi_bb14_13);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp17 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp8, tmp16});
    tmp18 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp17}, TNode<HeapObject>{tmp10});
    ca_.Branch(tmp18, &block20, std::vector<compiler::Node*>{phi_bb14_5, phi_bb14_9, phi_bb14_13}, &block21, std::vector<compiler::Node*>{phi_bb14_5, phi_bb14_9, phi_bb14_13});
  }

  TNode<OrderedHashMap> phi_bb20_5;
  TNode<JSArray> phi_bb20_9;
  TNode<Smi> phi_bb20_13;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_5, &phi_bb20_9, &phi_bb20_13);
    ca_.Goto(&block18, phi_bb20_5, phi_bb20_9, phi_bb20_13);
  }

  TNode<OrderedHashMap> phi_bb21_5;
  TNode<JSArray> phi_bb21_9;
  TNode<Smi> phi_bb21_13;
  TNode<BoolT> tmp19;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_5, &phi_bb21_9, &phi_bb21_13);
    tmp19 = CodeStubAssembler(state_).IsNoElementsProtectorCellInvalid();
    ca_.Branch(tmp19, &block22, std::vector<compiler::Node*>{phi_bb21_5, phi_bb21_9, phi_bb21_13}, &block23, std::vector<compiler::Node*>{phi_bb21_5, phi_bb21_9, phi_bb21_13});
  }

  TNode<OrderedHashMap> phi_bb22_5;
  TNode<JSArray> phi_bb22_9;
  TNode<Smi> phi_bb22_13;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_5, &phi_bb22_9, &phi_bb22_13);
    ca_.Goto(&block18, phi_bb22_5, phi_bb22_9, phi_bb22_13);
  }

  TNode<OrderedHashMap> phi_bb23_5;
  TNode<JSArray> phi_bb23_9;
  TNode<Smi> phi_bb23_13;
  TNode<JSArray> tmp20;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_5, &phi_bb23_9, &phi_bb23_13);
    tmp20 = (TNode<JSArray>{tmp8});
    ca_.Branch(tmp11, &block27, std::vector<compiler::Node*>{phi_bb23_5, phi_bb23_13, phi_bb23_13, phi_bb23_13}, &block28, std::vector<compiler::Node*>{phi_bb23_5, phi_bb23_13, phi_bb23_13, phi_bb23_13});
  }

  TNode<OrderedHashMap> phi_bb18_5;
  TNode<JSArray> phi_bb18_9;
  TNode<Smi> phi_bb18_13;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_5, &phi_bb18_9, &phi_bb18_13);
    ca_.Goto(&block36, phi_bb18_5, phi_bb18_9, phi_bb18_13);
  }

  TNode<OrderedHashMap> phi_bb27_5;
  TNode<Smi> phi_bb27_13;
  TNode<Smi> phi_bb27_15;
  TNode<Smi> phi_bb27_18;
  TNode<Object> tmp21;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_5, &phi_bb27_13, &phi_bb27_15, &phi_bb27_18);
    compiler::CodeAssemblerLabel label22(&ca_);
    tmp21 = LoadElementNoHole_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{tmp20}, TNode<Smi>{phi_bb27_18}, &label22);
    ca_.Goto(&block30, phi_bb27_5, phi_bb27_13, phi_bb27_15, phi_bb27_18, phi_bb27_18);
    if (label22.is_used()) {
      ca_.Bind(&label22);
      ca_.Goto(&block31, phi_bb27_5, phi_bb27_13, phi_bb27_15, phi_bb27_18, phi_bb27_18);
    }
  }

  TNode<OrderedHashMap> phi_bb31_5;
  TNode<Smi> phi_bb31_13;
  TNode<Smi> phi_bb31_15;
  TNode<Smi> phi_bb31_18;
  TNode<Smi> phi_bb31_20;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_5, &phi_bb31_13, &phi_bb31_15, &phi_bb31_18, &phi_bb31_20);
    ca_.Goto(&block25, phi_bb31_5, phi_bb31_13);
  }

  TNode<OrderedHashMap> phi_bb30_5;
  TNode<Smi> phi_bb30_13;
  TNode<Smi> phi_bb30_15;
  TNode<Smi> phi_bb30_18;
  TNode<Smi> phi_bb30_20;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_5, &phi_bb30_13, &phi_bb30_15, &phi_bb30_18, &phi_bb30_20);
    ca_.Goto(&block26, phi_bb30_5, phi_bb30_13, phi_bb30_15, phi_bb30_18, tmp21);
  }

  TNode<OrderedHashMap> phi_bb28_5;
  TNode<Smi> phi_bb28_13;
  TNode<Smi> phi_bb28_15;
  TNode<Smi> phi_bb28_18;
  TNode<Object> tmp23;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_5, &phi_bb28_13, &phi_bb28_15, &phi_bb28_18);
    compiler::CodeAssemblerLabel label24(&ca_);
    tmp23 = LoadElementNoHole_FixedArray_0(state_, TNode<Context>{p_context}, TNode<JSArray>{tmp20}, TNode<Smi>{phi_bb28_18}, &label24);
    ca_.Goto(&block32, phi_bb28_5, phi_bb28_13, phi_bb28_15, phi_bb28_18, phi_bb28_18);
    if (label24.is_used()) {
      ca_.Bind(&label24);
      ca_.Goto(&block33, phi_bb28_5, phi_bb28_13, phi_bb28_15, phi_bb28_18, phi_bb28_18);
    }
  }

  TNode<OrderedHashMap> phi_bb33_5;
  TNode<Smi> phi_bb33_13;
  TNode<Smi> phi_bb33_15;
  TNode<Smi> phi_bb33_18;
  TNode<Smi> phi_bb33_20;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_5, &phi_bb33_13, &phi_bb33_15, &phi_bb33_18, &phi_bb33_20);
    ca_.Goto(&block25, phi_bb33_5, phi_bb33_13);
  }

  TNode<OrderedHashMap> phi_bb32_5;
  TNode<Smi> phi_bb32_13;
  TNode<Smi> phi_bb32_15;
  TNode<Smi> phi_bb32_18;
  TNode<Smi> phi_bb32_20;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_5, &phi_bb32_13, &phi_bb32_15, &phi_bb32_18, &phi_bb32_20);
    ca_.Goto(&block26, phi_bb32_5, phi_bb32_13, phi_bb32_15, phi_bb32_18, tmp23);
  }

  TNode<OrderedHashMap> phi_bb26_5;
  TNode<Smi> phi_bb26_13;
  TNode<Smi> phi_bb26_15;
  TNode<Smi> phi_bb26_18;
  TNode<Object> phi_bb26_19;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_5, &phi_bb26_13, &phi_bb26_15, &phi_bb26_18, &phi_bb26_19);
    ca_.Goto(&block24, phi_bb26_5, phi_bb26_13, phi_bb26_19);
  }

  TNode<OrderedHashMap> phi_bb25_5;
  TNode<Smi> phi_bb25_13;
  TNode<Undefined> tmp25;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_5, &phi_bb25_13);
    tmp25 = Undefined_0(state_);
    ca_.Goto(&block24, phi_bb25_5, phi_bb25_13, tmp25);
  }

  TNode<OrderedHashMap> phi_bb24_5;
  TNode<Smi> phi_bb24_13;
  TNode<Object> phi_bb24_14;
  TNode<Undefined> tmp26;
  TNode<Object> tmp27;
  TNode<Object> tmp28;
  TNode<String> tmp29;
  TNode<OrderedHashMap> tmp30;
  TNode<Smi> tmp31;
  TNode<Smi> tmp32;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_5, &phi_bb24_13, &phi_bb24_14);
    tmp26 = Undefined_0(state_);
    tmp27 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp1}, TNode<Object>{tmp26}, TNode<Object>{phi_bb24_14}, TNode<Object>{phi_bb24_13});
    tmp28 = CoerceGroupKey_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp27}, TNode<Boolean>{p_coerceToProperty});
    tmp29 = FromConstexpr_String_constexpr_string_0(state_, p_methodName);
    tmp30 = CollectionsBuiltinsAssembler(state_).AddValueToKeyedGroup(TNode<OrderedHashMap>{phi_bb24_5}, TNode<Object>{tmp28}, TNode<Object>{phi_bb24_14}, TNode<String>{tmp29});
    tmp31 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp32 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb24_13}, TNode<Smi>{tmp31});
    ca_.Goto(&block16, tmp30, tmp20, tmp32);
  }

  TNode<OrderedHashMap> phi_bb15_5;
  TNode<JSArray> phi_bb15_9;
  TNode<Smi> phi_bb15_13;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_5, &phi_bb15_9, &phi_bb15_13);
    ca_.Goto(&block12, phi_bb15_5, phi_bb15_9, phi_bb15_13);
  }

  TNode<OrderedHashMap> phi_bb36_5;
  TNode<JSArray> phi_bb36_9;
  TNode<Smi> phi_bb36_13;
  TNode<IntPtrT> tmp33;
  TNode<Number> tmp34;
  TNode<BoolT> tmp35;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_5, &phi_bb36_9, &phi_bb36_13);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp34 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp8, tmp33});
    tmp35 = NumberIsLessThan_0(state_, TNode<Number>{phi_bb36_13}, TNode<Number>{tmp34});
    ca_.Branch(tmp35, &block34, std::vector<compiler::Node*>{phi_bb36_5, phi_bb36_9, phi_bb36_13}, &block35, std::vector<compiler::Node*>{phi_bb36_5, phi_bb36_9, phi_bb36_13});
  }

  TNode<OrderedHashMap> phi_bb34_5;
  TNode<JSArray> phi_bb34_9;
  TNode<Smi> phi_bb34_13;
  TNode<Object> tmp36;
  TNode<Undefined> tmp37;
  TNode<Object> tmp38;
  TNode<Object> tmp39;
  TNode<String> tmp40;
  TNode<OrderedHashMap> tmp41;
  TNode<Smi> tmp42;
  TNode<Smi> tmp43;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_5, &phi_bb34_9, &phi_bb34_13);
    tmp36 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp8}, TNode<Object>{phi_bb34_13});
    tmp37 = Undefined_0(state_);
    tmp38 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp1}, TNode<Object>{tmp37}, TNode<Object>{tmp36}, TNode<Object>{phi_bb34_13});
    tmp39 = CoerceGroupKey_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp38}, TNode<Boolean>{p_coerceToProperty});
    tmp40 = FromConstexpr_String_constexpr_string_0(state_, p_methodName);
    tmp41 = CollectionsBuiltinsAssembler(state_).AddValueToKeyedGroup(TNode<OrderedHashMap>{phi_bb34_5}, TNode<Object>{tmp39}, TNode<Object>{tmp36}, TNode<String>{tmp40});
    tmp42 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp43 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb34_13}, TNode<Smi>{tmp42});
    ca_.Goto(&block36, tmp41, phi_bb34_9, tmp43);
  }

  TNode<OrderedHashMap> phi_bb35_5;
  TNode<JSArray> phi_bb35_9;
  TNode<Smi> phi_bb35_13;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_5, &phi_bb35_9, &phi_bb35_13);
    ca_.Goto(&block12, phi_bb35_5, phi_bb35_9, phi_bb35_13);
  }

  TNode<OrderedHashMap> phi_bb12_5;
  TNode<JSArray> phi_bb12_9;
  TNode<Smi> phi_bb12_13;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_5, &phi_bb12_9, &phi_bb12_13);
    ca_.Goto(&block1, phi_bb12_5);
  }

  TNode<OrderedHashMap> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.Goto(&block37, phi_bb1_4);
  }

  TNode<OrderedHashMap> phi_bb37_4;
    ca_.Bind(&block37, &phi_bb37_4);
  return TNode<OrderedHashMap>{phi_bb37_4};
}

TF_BUILTIN(ObjectGroupBy, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kItems);
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kCallback);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<True> tmp0;
  TNode<OrderedHashMap> tmp1;
  TNode<OrderedHashMap> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<Object> tmp5;
  TNode<Object> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<NameDictionary> tmp9;
  TNode<Map> tmp10;
  TNode<JSObject> tmp11;
  TNode<Map> tmp12;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = True_0(state_);
    tmp1 = GroupByImpl_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, TNode<Object>{parameter3}, TNode<Boolean>{tmp0}, "Object.groupBy");
    std::tie(tmp2, tmp3, tmp4, tmp5, tmp6, tmp7) = NewUnmodifiedOrderedHashMapIterator_0(state_, TNode<OrderedHashMap>{tmp1}).Flatten();
    tmp8 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp4});
    tmp9 = CodeStubAssembler(state_).AllocateNameDictionary(TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).LoadSlowObjectWithNullPrototypeMap(TNode<NativeContext>{parameter0});
    tmp11 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp10}, TNode<HeapObject>{tmp9});
    tmp12 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{parameter0});
    ca_.Goto(&block5, tmp5, tmp6, tmp7);
  }

  TNode<Object> phi_bb5_8;
  TNode<Object> phi_bb5_9;
  TNode<IntPtrT> phi_bb5_10;
  TNode<BoolT> tmp13;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_8, &phi_bb5_9, &phi_bb5_10);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp13, &block3, std::vector<compiler::Node*>{phi_bb5_8, phi_bb5_9, phi_bb5_10}, &block4, std::vector<compiler::Node*>{phi_bb5_8, phi_bb5_9, phi_bb5_10});
  }

  TNode<Object> phi_bb3_8;
  TNode<Object> phi_bb3_9;
  TNode<IntPtrT> phi_bb3_10;
  TNode<Object> tmp14;
  TNode<Object> tmp15;
  TNode<IntPtrT> tmp16;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_8, &phi_bb3_9, &phi_bb3_10);
    compiler::CodeAssemblerLabel label17(&ca_);
    std::tie(tmp14, tmp15, tmp16) = CollectionsBuiltinsAssembler(state_).NextKeyValueIndexTupleUnmodifiedTable(TNode<OrderedHashMap>{tmp2}, TNode<Int32T>{tmp3}, TNode<Int32T>{tmp4}, TNode<IntPtrT>{phi_bb3_10}, &label17).Flatten();
    ca_.Goto(&block7, phi_bb3_8, phi_bb3_9, phi_bb3_10, phi_bb3_10);
    if (label17.is_used()) {
      ca_.Bind(&label17);
      ca_.Goto(&block8, phi_bb3_8, phi_bb3_9, phi_bb3_10, phi_bb3_10);
    }
  }

  TNode<Object> phi_bb8_8;
  TNode<Object> phi_bb8_9;
  TNode<IntPtrT> phi_bb8_10;
  TNode<IntPtrT> phi_bb8_18;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_8, &phi_bb8_9, &phi_bb8_10, &phi_bb8_18);
    ca_.Goto(&block1, phi_bb8_8, phi_bb8_9, phi_bb8_10);
  }

  TNode<Object> phi_bb7_8;
  TNode<Object> phi_bb7_9;
  TNode<IntPtrT> phi_bb7_10;
  TNode<IntPtrT> phi_bb7_18;
  TNode<ArrayList> tmp18;
  TNode<FixedArray> tmp19;
  TNode<JSArray> tmp20;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_8, &phi_bb7_9, &phi_bb7_10, &phi_bb7_18);
    tmp18 = UnsafeCast_ArrayList_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp15});
    tmp19 = CodeStubAssembler(state_).ArrayListElements(TNode<ArrayList>{tmp18});
    tmp20 = NewJSArray_0(state_, TNode<Context>{parameter0}, TNode<Map>{tmp12}, TNode<FixedArrayBase>{tmp19});
    CodeStubAssembler(state_).CallRuntime(Runtime::kCreateDataProperty, parameter0, tmp11, tmp14, tmp20);
    ca_.Goto(&block5, tmp14, tmp15, tmp16);
  }

  TNode<Object> phi_bb4_8;
  TNode<Object> phi_bb4_9;
  TNode<IntPtrT> phi_bb4_10;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_8, &phi_bb4_9, &phi_bb4_10);
    ca_.Goto(&block1, phi_bb4_8, phi_bb4_9, phi_bb4_10);
  }

  TNode<Object> phi_bb1_8;
  TNode<Object> phi_bb1_9;
  TNode<IntPtrT> phi_bb1_10;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_8, &phi_bb1_9, &phi_bb1_10);
    CodeStubAssembler(state_).Return(tmp11);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object-groupby.tq?l=109&c=7
TNode<JSArray> Cast_FastJSArrayForReadWithNoCustomIteration_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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

  TNode<JSArray> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_FastJSArrayForReadWithNoCustomIteration_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{tmp0}, &label3);
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
  return TNode<JSArray>{tmp2};
}

} // namespace internal
} // namespace v8
