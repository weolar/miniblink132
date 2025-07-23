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
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/ic-callable-tq-csa.h"
#include "torque-generated/src/builtins/ic-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-misc-tq-csa.h"
#include "torque-generated/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(GetIteratorWithFeedback, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<TaggedIndex> parameter2 = UncheckedParameter<TaggedIndex>(Descriptor::kLoadSlot);
  USE(parameter2);
  TNode<TaggedIndex> parameter3 = UncheckedParameter<TaggedIndex>(Descriptor::kCallSlot);
  USE(parameter3);
  TNode<HeapObject> parameter4 = UncheckedParameter<HeapObject>(Descriptor::kMaybeFeedbackVector);
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Undefined> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Undefined_2(state_, TNode<HeapObject>{parameter4}, &label1);
    ca_.Goto(&block10);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block11);
    }
  }

  TNode<Symbol> tmp2;
  TNode<Object> tmp3;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp2 = CodeStubAssembler(state_).IteratorSymbolConstant();
    tmp3 = ca_.CallBuiltin<Object>(Builtin::kLoadIC, parameter0, parameter1, tmp2, parameter2, ca_.UncheckedCast<FeedbackVector>(parameter4));
    ca_.Goto(&block8, tmp3);
  }

  TNode<Symbol> tmp4;
  TNode<Object> tmp5;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp4 = CodeStubAssembler(state_).IteratorSymbolConstant();
    tmp5 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<Object>{tmp4});
    ca_.Goto(&block8, tmp5);
  }

  TNode<Object> phi_bb8_5;
  TNode<Smi> tmp6;
  TNode<Object> tmp7;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_5);
    tmp6 = CodeStubAssembler(state_).TaggedIndexToSmi(TNode<TaggedIndex>{parameter3});
    tmp7 = ca_.CallBuiltin<Object>(Builtin::kCallIteratorWithFeedback, parameter0, parameter1, phi_bb8_5, tmp6, parameter4);
    CodeStubAssembler(state_).Return(tmp7);
  }
}

TF_BUILTIN(GetIteratorBaseline, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter0);
  TNode<TaggedIndex> parameter1 = UncheckedParameter<TaggedIndex>(Descriptor::kLoadSlot);
  USE(parameter1);
  TNode<TaggedIndex> parameter2 = UncheckedParameter<TaggedIndex>(Descriptor::kCallSlot);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<FeedbackVector> tmp1;
  TNode<Symbol> tmp2;
  TNode<Object> tmp3;
  TNode<Smi> tmp4;
  TNode<Object> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadContextFromBaseline();
    tmp1 = CodeStubAssembler(state_).LoadFeedbackVectorFromBaseline();
    tmp2 = CodeStubAssembler(state_).IteratorSymbolConstant();
    tmp3 = ca_.CallBuiltin<Object>(Builtin::kLoadIC, tmp0, parameter0, tmp2, parameter1, tmp1);
    tmp4 = CodeStubAssembler(state_).TaggedIndexToSmi(TNode<TaggedIndex>{parameter2});
    tmp5 = ca_.CallBuiltin<Object>(Builtin::kCallIteratorWithFeedback, tmp0, parameter0, tmp3, tmp4, tmp1);
    CodeStubAssembler(state_).Return(tmp5);
  }
}

TF_BUILTIN(CreateAsyncFromSyncIteratorBaseline, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kSyncIterator);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadContextFromBaseline();
    tmp1 = CodeStubAssembler(state_).CreateAsyncFromSyncIterator(TNode<Context>{tmp0}, TNode<Object>{parameter0});
    CodeStubAssembler(state_).Return(tmp1);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=107&c=1
TorqueStructIteratorRecord GetIteratorRecordAfterCreateAsyncFromSyncIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_asyncIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<String> tmp1;
  TNode<Object> tmp2;
  TNode<JSReceiver> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).CreateAsyncFromSyncIterator(TNode<Context>{p_context}, TNode<Object>{p_asyncIterator.object});
    tmp1 = kNextString_0(state_);
    tmp2 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp0}, TNode<Object>{tmp1});
    tmp3 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructIteratorRecord{TNode<JSReceiver>{tmp3}, TNode<Object>{tmp2}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=119&c=1
TNode<Object> GetLazyReceiver_0(compiler::CodeAssemblerState* state_, TNode<Object> p_receiver) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{p_receiver};
}

TF_BUILTIN(CallIteratorWithFeedback, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kIteratorMethod);
  USE(parameter2);
  TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kCallSlot);
  USE(parameter3);
  TNode<HeapObject> parameter4 = UncheckedParameter<HeapObject>(Descriptor::kFeedback);
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<UintPtrT> tmp1;
  std::function<TNode<Object>()> tmp2;
  TNode<JSReceiver> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{parameter3});
    tmp1 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp0});
    tmp2 = [=] () { return GetLazyReceiver_0(state_, TNode<Object>{parameter1}); };
    CollectCallFeedback_1(state_, TNode<Object>{parameter2}, std::function<TNode<Object>()>{tmp2}, TNode<Context>{parameter0}, TNode<HeapObject>{parameter4}, TNode<UintPtrT>{tmp1});
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label4);
    ca_.Goto(&block3);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowIteratorError, parameter0, parameter1);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp5 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp3}, TNode<Object>{parameter1});
    CodeStubAssembler(state_).ThrowIfNotJSReceiver(TNode<Context>{parameter0}, TNode<Object>{tmp5}, MessageTemplate::kSymbolIteratorInvalid, "");
    CodeStubAssembler(state_).Return(tmp5);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=141&c=1
void IteratorCloseOnException_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_iterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<String> tmp0;
  TNode<Object> tmp1;
      TNode<Object> tmp3;
  TNode<Undefined> tmp4;
  TNode<BoolT> tmp5;
      TNode<Object> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kReturnString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch2__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch2__label);
    tmp1 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_iterator.object}, TNode<Object>{tmp0});
    }
    if (catch2__label.is_used()) {
      compiler::CodeAssemblerLabel catch2_skip(&ca_);
      ca_.Goto(&catch2_skip);
      ca_.Bind(&catch2__label, &tmp3);
      ca_.Goto(&block4);
      ca_.Bind(&catch2_skip);
    }
    tmp4 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch6__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch6__label);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp1}, TNode<HeapObject>{tmp4});
    }
    if (catch6__label.is_used()) {
      compiler::CodeAssemblerLabel catch6_skip(&ca_);
      ca_.Goto(&catch6_skip);
      ca_.Bind(&catch6__label, &tmp7);
      ca_.Goto(&block7);
      ca_.Bind(&catch6_skip);
    }
    ca_.Branch(tmp5, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block3, tmp3, tmp8);
  }

  TNode<HeapObject> tmp9;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp9 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block3, tmp7, tmp9);
  }

  TNode<BoolT> tmp10;
      TNode<Object> tmp12;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    compiler::CodeAssemblerExceptionHandlerLabel catch11__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch11__label);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch11__label.is_used()) {
      compiler::CodeAssemblerLabel catch11_skip(&ca_);
      ca_.Goto(&catch11_skip);
      ca_.Bind(&catch11__label, &tmp12);
      ca_.Goto(&block11);
      ca_.Bind(&catch11_skip);
    }
    ca_.Goto(&block10, tmp10);
  }

  TNode<HeapObject> tmp13;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp13 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block3, tmp12, tmp13);
  }

  TNode<Null> tmp14;
  TNode<BoolT> tmp15;
      TNode<Object> tmp17;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp14 = Null_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    tmp15 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp1}, TNode<HeapObject>{tmp14});
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block12);
      ca_.Bind(&catch16_skip);
    }
    ca_.Goto(&block10, tmp15);
  }

  TNode<HeapObject> tmp18;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp18 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block3, tmp17, tmp18);
  }

  TNode<BoolT> phi_bb10_5;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    ca_.Branch(phi_bb10_5, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1);
  }

  TNode<Object> tmp19;
      TNode<Object> tmp21;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerExceptionHandlerLabel catch20__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch20__label);
    tmp19 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp1}, TNode<Object>{p_iterator.object});
    }
    if (catch20__label.is_used()) {
      compiler::CodeAssemblerLabel catch20_skip(&ca_);
      ca_.Goto(&catch20_skip);
      ca_.Bind(&catch20__label, &tmp21);
      ca_.Goto(&block13);
      ca_.Bind(&catch20_skip);
    }
    ca_.Goto(&block2);
  }

  TNode<HeapObject> tmp22;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp22 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block3, tmp21, tmp22);
  }

  TNode<Object> phi_bb3_3;
  TNode<HeapObject> phi_bb3_4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_3, &phi_bb3_4);
    ca_.Goto(&block2);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=163&c=1
void IteratorClose_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_iterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<String> tmp0;
  TNode<Object> tmp1;
  TNode<Undefined> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kReturnString_0(state_);
    tmp1 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_iterator.object}, TNode<Object>{tmp0});
    tmp2 = Undefined_0(state_);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp4);
  }

  TNode<Null> tmp5;
  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = Null_0(state_);
    tmp6 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp1}, TNode<HeapObject>{tmp5});
    ca_.Goto(&block6, tmp6);
  }

  TNode<BoolT> phi_bb6_5;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    ca_.Branch(phi_bb6_5, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block1);
  }

  TNode<Object> tmp7;
  TNode<JSReceiver> tmp8;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp7 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp1}, TNode<Object>{p_iterator.object});
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp7}, &label9);
    ca_.Goto(&block9);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledOnNonObject, "return");
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block11);
  }

    ca_.Bind(&block11);
}

TF_BUILTIN(IteratorConstructor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kJSNewTarget);
USE(parameter2);
  TNode<JSFunction> parameter3 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Undefined> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Undefined_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter2}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kConstructorNotFunction, "Iterator");
  }

  TNode<BoolT> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter2}, TNode<HeapObject>{parameter3});
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kConstructAbstractClass, "Iterator");
  }

  TNode<JSReceiver> tmp3;
  TNode<Map> tmp4;
  TNode<JSObject> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp4 = GetDerivedMap_0(state_, TNode<Context>{parameter0}, TNode<JSFunction>{parameter3}, TNode<JSReceiver>{tmp3});
    tmp5 = AllocateFastOrSlowJSObjectFromMap_0(state_, TNode<Context>{parameter0}, TNode<Map>{tmp4});
    CodeStubAssembler(state_).Return(tmp5);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=208&c=1
TNode<Object> SetterThatIgnoresPrototypeProperties_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<JSObject> p_home, TNode<Object> p_key, TNode<Object> p_value, const char* p_methodName) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledOnNonObject, p_methodName);
  }

  TNode<BoolT> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp0}, TNode<HeapObject>{p_home});
    ca_.Branch(tmp2, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<String> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp3 = CodeStubAssembler(state_).objectStringConstant();
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kStrictReadOnlyProperty, TNode<Object>{p_key}, TNode<Object>{tmp3}, TNode<Object>{p_home});
  }

  TNode<Boolean> tmp4;
  TNode<False> tmp5;
  TNode<BoolT> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kObjectHasOwnProperty, p_context, tmp0, p_key)); 
    tmp5 = False_0(state_);
    tmp6 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp4}, TNode<HeapObject>{tmp5});
    ca_.Branch(tmp6, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).CallRuntime(Runtime::kCreateDataProperty, p_context, tmp0, p_key, p_value);
    ca_.Goto(&block10);
  }

  TNode<Object> tmp7;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp7 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, p_context, tmp0, p_key, p_value);
    ca_.Goto(&block10);
  }

  TNode<Undefined> tmp8;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp8 = Undefined_0(state_);
    ca_.Goto(&block11);
  }

    ca_.Bind(&block11);
  return TNode<Object>{tmp8};
}

TF_BUILTIN(IteratorPrototypeGetToStringTag, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<String> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).IteratorStringConstant();
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(IteratorPrototypeSetToStringTag, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSObject> tmp0;
  TNode<Symbol> tmp1;
  TNode<Object> tmp2;
  TNode<Undefined> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorPrototype_0(state_, TNode<Context>{parameter0});
    tmp1 = CodeStubAssembler(state_).ToStringTagSymbolConstant();
    tmp2 = SetterThatIgnoresPrototypeProperties_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<JSObject>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{parameter2}, "set Iterator.prototype[Symbol.toStringTag]");
    tmp3 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(IteratorPrototypeGetConstructor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSFunction> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorFunction_0(state_, TNode<Context>{parameter0});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(IteratorPrototypeSetConstructor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSObject> tmp0;
  TNode<String> tmp1;
  TNode<Object> tmp2;
  TNode<Undefined> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorPrototype_0(state_, TNode<Context>{parameter0});
    tmp1 = CodeStubAssembler(state_).ConstructorStringConstant();
    tmp2 = SetterThatIgnoresPrototypeProperties_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<JSObject>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{parameter2}, "set Iterator.prototype.constructor");
    tmp3 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(IteratorPrototypeDispose, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<String> tmp0;
  TNode<JSReceiver> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kReturnString_0(state_);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = GetMethod_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<String>{tmp0}, &label2);
    ca_.Goto(&block3);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<Object> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp1}, TNode<Object>{parameter1});
    ca_.Goto(&block1);
  }

  TNode<Undefined> tmp4;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp4 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=317&c=1
intptr_t kAsyncIteratorPrototypeAsyncDisposeResolveContextLength_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  return Context::Field::MIN_CONTEXT_SLOTS;}

TF_BUILTIN(AsyncIteratorPrototypeAsyncDisposeResolveClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Undefined> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(AsyncIteratorPrototypeAsyncDispose, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSPromise> tmp0;
  TNode<String> tmp1;
  TNode<JSReceiver> tmp2;
      TNode<Object> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = NewJSPromise_1(state_, TNode<Context>{parameter0});
    tmp1 = kReturnString_0(state_);
    compiler::CodeAssemblerLabel label3(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch4__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch4__label);
    tmp2 = GetMethod_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<String>{tmp1}, &label3);
    }
    if (catch4__label.is_used()) {
      compiler::CodeAssemblerLabel catch4_skip(&ca_);
      ca_.Goto(&catch4_skip);
      ca_.Bind(&catch4__label, &tmp5);
      ca_.Goto(&block7);
      ca_.Bind(&catch4_skip);
    }
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  TNode<HeapObject> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp6 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp5, tmp6);
  }

  TNode<Undefined> tmp7;
  TNode<Object> tmp8;
      TNode<Object> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch9__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch9__label);
    tmp8 = ca_.CallBuiltin<Object>(Builtin::kResolvePromise, parameter0, tmp0, tmp7);
    }
    if (catch9__label.is_used()) {
      compiler::CodeAssemblerLabel catch9_skip(&ca_);
      ca_.Goto(&catch9_skip);
      ca_.Bind(&catch9__label, &tmp10);
      ca_.Goto(&block18);
      ca_.Bind(&catch9_skip);
    }
    ca_.Goto(&block3);
  }

  TNode<Undefined> tmp11;
  TNode<Object> tmp12;
      TNode<Object> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<Object> tmp16;
  TNode<IntPtrT> tmp17;
      TNode<Object> tmp19;
  TNode<JSFunction> tmp20;
  TNode<JSReceiver> tmp21;
      TNode<Object> tmp23;
  TNode<Object> tmp24;
      TNode<Object> tmp26;
  TNode<NativeContext> tmp27;
  TNode<IntPtrT> tmp28;
      TNode<Object> tmp30;
  TNode<Context> tmp31;
      TNode<Object> tmp33;
  TNode<Context> tmp34;
  TNode<NativeContext> tmp35;
  TNode<JSFunction> tmp36;
      TNode<Object> tmp38;
  TNode<JSPromise> tmp39;
      TNode<Object> tmp41;
  TNode<Undefined> tmp42;
      TNode<Object> tmp44;
      TNode<Object> tmp46;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp11 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch13__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch13__label);
    tmp12 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp2}, TNode<Object>{parameter1}, TNode<Object>{tmp11});
    }
    if (catch13__label.is_used()) {
      compiler::CodeAssemblerLabel catch13_skip(&ca_);
      ca_.Goto(&catch13_skip);
      ca_.Bind(&catch13__label, &tmp14);
      ca_.Goto(&block8);
      ca_.Bind(&catch13_skip);
    }
    tmp15 = PROMISE_FUNCTION_INDEX_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch18__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch18__label);
    std::tie(tmp16, tmp17) = NativeContextSlot_Context_JSFunction_0(state_, TNode<Context>{parameter0}, TNode<IntPtrT>{tmp15}).Flatten();
    }
    if (catch18__label.is_used()) {
      compiler::CodeAssemblerLabel catch18_skip(&ca_);
      ca_.Goto(&catch18_skip);
      ca_.Bind(&catch18__label, &tmp19);
      ca_.Goto(&block9);
      ca_.Bind(&catch18_skip);
    }
    tmp20 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference{tmp16, tmp17});
    compiler::CodeAssemblerExceptionHandlerLabel catch22__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch22__label);
    tmp21 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context>{parameter0}, TNode<Object>{tmp0}, TNode<JSReceiver>{tmp20});
    }
    if (catch22__label.is_used()) {
      compiler::CodeAssemblerLabel catch22_skip(&ca_);
      ca_.Goto(&catch22_skip);
      ca_.Bind(&catch22__label, &tmp23);
      ca_.Goto(&block10);
      ca_.Bind(&catch22_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch25__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch25__label);
    tmp24 = ca_.CallBuiltin<Object>(Builtin::kPromiseResolve, parameter0, tmp21, tmp12);
    }
    if (catch25__label.is_used()) {
      compiler::CodeAssemblerLabel catch25_skip(&ca_);
      ca_.Goto(&catch25_skip);
      ca_.Bind(&catch25__label, &tmp26);
      ca_.Goto(&block11);
      ca_.Bind(&catch25_skip);
    }
    tmp27 = TORQUE_CAST(TNode<Context>{parameter0});
    compiler::CodeAssemblerExceptionHandlerLabel catch29__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch29__label);
    tmp28 = FromConstexpr_intptr_constexpr_intptr_0(state_, kAsyncIteratorPrototypeAsyncDisposeResolveContextLength_0(state_));
    }
    if (catch29__label.is_used()) {
      compiler::CodeAssemblerLabel catch29_skip(&ca_);
      ca_.Goto(&catch29_skip);
      ca_.Bind(&catch29__label, &tmp30);
      ca_.Goto(&block12);
      ca_.Bind(&catch29_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch32__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch32__label);
    tmp31 = AllocateSyntheticFunctionContext_1(state_, TNode<NativeContext>{tmp27}, TNode<IntPtrT>{tmp28});
    }
    if (catch32__label.is_used()) {
      compiler::CodeAssemblerLabel catch32_skip(&ca_);
      ca_.Goto(&catch32_skip);
      ca_.Bind(&catch32__label, &tmp33);
      ca_.Goto(&block13);
      ca_.Bind(&catch32_skip);
    }
    tmp34 = (TNode<Context>{tmp31});
    tmp35 = TORQUE_CAST(TNode<Context>{parameter0});
    compiler::CodeAssemblerExceptionHandlerLabel catch37__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch37__label);
    tmp36 = CodeStubAssembler(state_).AllocateRootFunctionWithContext(RootIndex::kAsyncIteratorPrototypeAsyncDisposeResolveClosureSharedFun, TNode<Context>{tmp34}, TNode<NativeContext>{tmp35});
    }
    if (catch37__label.is_used()) {
      compiler::CodeAssemblerLabel catch37_skip(&ca_);
      ca_.Goto(&catch37_skip);
      ca_.Bind(&catch37__label, &tmp38);
      ca_.Goto(&block14);
      ca_.Bind(&catch37_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch40__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch40__label);
    tmp39 = UnsafeCast_JSPromise_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp24});
    }
    if (catch40__label.is_used()) {
      compiler::CodeAssemblerLabel catch40_skip(&ca_);
      ca_.Goto(&catch40_skip);
      ca_.Bind(&catch40__label, &tmp41);
      ca_.Goto(&block15);
      ca_.Bind(&catch40_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch43__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch43__label);
    tmp42 = CodeStubAssembler(state_).UndefinedConstant();
    }
    if (catch43__label.is_used()) {
      compiler::CodeAssemblerLabel catch43_skip(&ca_);
      ca_.Goto(&catch43_skip);
      ca_.Bind(&catch43__label, &tmp44);
      ca_.Goto(&block16);
      ca_.Bind(&catch43_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch45__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch45__label);
    PerformPromiseThenImpl_0(state_, TNode<Context>{parameter0}, TNode<JSPromise>{tmp39}, TNode<HeapObject>{tmp36}, TNode<HeapObject>{tmp42}, TNode<HeapObject>{tmp0});
    }
    if (catch45__label.is_used()) {
      compiler::CodeAssemblerLabel catch45_skip(&ca_);
      ca_.Goto(&catch45_skip);
      ca_.Bind(&catch45__label, &tmp46);
      ca_.Goto(&block17);
      ca_.Bind(&catch45_skip);
    }
    ca_.Goto(&block3);
  }

  TNode<HeapObject> tmp47;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp47 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp14, tmp47);
  }

  TNode<HeapObject> tmp48;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp48 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp19, tmp48);
  }

  TNode<HeapObject> tmp49;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp49 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp23, tmp49);
  }

  TNode<HeapObject> tmp50;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp50 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp26, tmp50);
  }

  TNode<HeapObject> tmp51;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp51 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp30, tmp51);
  }

  TNode<HeapObject> tmp52;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp52 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp33, tmp52);
  }

  TNode<HeapObject> tmp53;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp53 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp38, tmp53);
  }

  TNode<HeapObject> tmp54;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp54 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp41, tmp54);
  }

  TNode<HeapObject> tmp55;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp55 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp44, tmp55);
  }

  TNode<HeapObject> tmp56;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp56 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp46, tmp56);
  }

  TNode<HeapObject> tmp57;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp57 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp10, tmp57);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).Return(tmp0);
  }

  TNode<Object> phi_bb2_3;
  TNode<HeapObject> phi_bb2_4;
  TNode<False> tmp58;
  TNode<Object> tmp59;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_3, &phi_bb2_4);
    tmp58 = False_0(state_);
    tmp59 = ca_.CallBuiltin<Object>(Builtin::kRejectPromise, parameter0, tmp0, phi_bb2_3, tmp58);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=366&c=11
TNode<JSPromise> UnsafeCast_JSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSPromise> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<JSPromise>{tmp0};
}

} // namespace internal
} // namespace v8
