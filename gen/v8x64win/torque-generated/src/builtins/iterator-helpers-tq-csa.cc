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
#include "torque-generated/src/builtins/iterator-helpers-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/iterator-from-tq-csa.h"
#include "torque-generated/src/builtins/iterator-helpers-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-iterator-helpers-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=14&c=1
TNode<Null> kIteratorHelperExhausted_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Null> tmp0;
    tmp0 = Null_0(state_);
  return TNode<Null>{tmp0};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=16&c=1
TNode<Undefined> kIteratorHelperExecuting_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Undefined> tmp0;
    tmp0 = Undefined_0(state_);
  return TNode<Undefined>{tmp0};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=18&c=1
TNode<BoolT> IsIteratorHelperExhausted_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<Null> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_helper, tmp0});
    tmp2 = kIteratorHelperExhausted_0(state_);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=22&c=1
void MarkIteratorHelperAsExhausted_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Null> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = kIteratorHelperExhausted_0(state_);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_helper, tmp0}, tmp1);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=26&c=1
TNode<BoolT> IsIteratorHelperExecuting_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<Undefined> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_helper, tmp0});
    tmp2 = kIteratorHelperExecuting_0(state_);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=32&c=1
void ThrowIfIteratorHelperExecuting_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSIteratorHelper> p_helper) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = IsIteratorHelperExecuting_0(state_, TNode<JSIteratorHelper>{p_helper});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kGeneratorRunning);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=39&c=1
TorqueStructIteratorRecord MarkIteratorHelperAsExecuting_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<JSReceiver> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_helper, tmp0});
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp1}, &label3);
    ca_.Goto(&block8);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block9);
    }
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp4;
  TNode<Undefined> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp5 = kIteratorHelperExecuting_0(state_);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_helper, tmp4}, tmp5);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp7 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_helper, tmp6});
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp7}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=48&c=1
void MarkIteratorHelperAsFinishedExecuting_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper, TorqueStructIteratorRecord p_underlying) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_helper, tmp0}, p_underlying.object);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=56&c=1
TorqueStructIteratorRecord GetIteratorDirect_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_obj) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<String> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kNextString_0(state_);
    tmp1 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_obj}, TNode<Object>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructIteratorRecord{TNode<JSReceiver>{p_obj}, TNode<Object>{tmp1}};
}

TF_BUILTIN(IteratorHelperPrototypeNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSIteratorHelper> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSIteratorHelper_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<Object> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_Object_constexpr_string_0(state_, "Iterator Helper.prototype.next");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp2}, TNode<Object>{parameter1});
  }

  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ThrowIfIteratorHelperExecuting_0(state_, TNode<Context>{parameter0}, TNode<JSIteratorHelper>{tmp0});
    tmp3 = IsIteratorHelperExhausted_0(state_, TNode<JSIteratorHelper>{tmp0});
    ca_.Branch(tmp3, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Undefined> tmp4;
  TNode<True> tmp5;
  TNode<JSObject> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp4 = Undefined_0(state_);
    tmp5 = True_0(state_);
    tmp6 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp4}, TNode<Boolean>{tmp5});
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<JSIteratorMapHelper> tmp7;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerLabel label8(&ca_);
    tmp7 = Cast_JSIteratorMapHelper_0(state_, TNode<HeapObject>{tmp0}, &label8);
    ca_.Goto(&block9);
    if (label8.is_used()) {
      ca_.Bind(&label8);
      ca_.Goto(&block10);
    }
  }

  TNode<JSIteratorFilterHelper> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    compiler::CodeAssemblerLabel label10(&ca_);
    tmp9 = Cast_JSIteratorFilterHelper_0(state_, TNode<HeapObject>{ca_.UncheckedCast<JSIteratorHelper>(tmp0)}, &label10);
    ca_.Goto(&block13);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block14);
    }
  }

  TNode<Object> tmp11;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp11 = ca_.CallBuiltin<Object>(Builtin::kIteratorMapHelperNext, parameter0, tmp7);
    CodeStubAssembler(state_).Return(tmp11);
  }

  TNode<JSIteratorTakeHelper> tmp12;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    compiler::CodeAssemblerLabel label13(&ca_);
    tmp12 = Cast_JSIteratorTakeHelper_0(state_, TNode<HeapObject>{ca_.UncheckedCast<JSIteratorHelper>(tmp0)}, &label13);
    ca_.Goto(&block17);
    if (label13.is_used()) {
      ca_.Bind(&label13);
      ca_.Goto(&block18);
    }
  }

  TNode<Object> tmp14;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp14 = ca_.CallBuiltin<Object>(Builtin::kIteratorFilterHelperNext, parameter0, tmp9);
    CodeStubAssembler(state_).Return(tmp14);
  }

  TNode<JSIteratorDropHelper> tmp15;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    compiler::CodeAssemblerLabel label16(&ca_);
    tmp15 = Cast_JSIteratorDropHelper_0(state_, TNode<HeapObject>{ca_.UncheckedCast<JSIteratorHelper>(tmp0)}, &label16);
    ca_.Goto(&block21);
    if (label16.is_used()) {
      ca_.Bind(&label16);
      ca_.Goto(&block22);
    }
  }

  TNode<Object> tmp17;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp17 = ca_.CallBuiltin<Object>(Builtin::kIteratorTakeHelperNext, parameter0, tmp12);
    CodeStubAssembler(state_).Return(tmp17);
  }

  TNode<JSIteratorFlatMapHelper> tmp18;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    compiler::CodeAssemblerLabel label19(&ca_);
    tmp18 = Cast_JSIteratorFlatMapHelper_0(state_, TNode<HeapObject>{ca_.UncheckedCast<JSIteratorHelper>(tmp0)}, &label19);
    ca_.Goto(&block25);
    if (label19.is_used()) {
      ca_.Bind(&label19);
      ca_.Goto(&block26);
    }
  }

  TNode<Object> tmp20;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp20 = ca_.CallBuiltin<Object>(Builtin::kIteratorDropHelperNext, parameter0, tmp15);
    CodeStubAssembler(state_).Return(tmp20);
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp21;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp21 = ca_.CallBuiltin<Object>(Builtin::kIteratorFlatMapHelperNext, parameter0, tmp18);
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TF_BUILTIN(IteratorHelperPrototypeReturn, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSIteratorFlatMapHelper> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSIteratorFlatMapHelper_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<JSIteratorHelper> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorHelper_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label3);
    ca_.Goto(&block21);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block22);
    }
  }

  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    ThrowIfIteratorHelperExecuting_0(state_, TNode<Context>{parameter0}, TNode<JSIteratorHelper>{tmp0});
    tmp4 = IsIteratorHelperExhausted_0(state_, TNode<JSIteratorHelper>{tmp0});
    ca_.Branch(tmp4, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Undefined> tmp5;
  TNode<True> tmp6;
  TNode<JSObject> tmp7;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = Undefined_0(state_);
    tmp6 = True_0(state_);
    tmp7 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp5}, TNode<Boolean>{tmp6});
    CodeStubAssembler(state_).Return(tmp7);
  }

  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<JSReceiver> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp0, tmp8});
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp9}, &label11);
    ca_.Goto(&block9);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp12;
  TNode<Object> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Boolean> tmp15;
  TNode<True> tmp16;
  TNode<BoolT> tmp17;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp13 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp12});
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{tmp0});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
    tmp15 = CodeStubAssembler(state_).LoadReference<Boolean>(CodeStubAssembler::Reference{tmp0, tmp14});
    tmp16 = True_0(state_);
    tmp17 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp15}, TNode<HeapObject>{tmp16});
    ca_.Branch(tmp17, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp18;
      TNode<Object> tmp20;
  TNode<JSReceiver> tmp21;
  TNode<IntPtrT> tmp22;
      TNode<Object> tmp24;
  TNode<IntPtrT> tmp25;
      TNode<Object> tmp27;
  TNode<Object> tmp28;
      TNode<Object> tmp30;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch19__label);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      ca_.Bind(&catch19__label, &tmp20);
      ca_.Goto(&block15);
      ca_.Bind(&catch19_skip);
    }
    tmp21 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp18});
    compiler::CodeAssemblerExceptionHandlerLabel catch23__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch23__label);
    tmp22 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    }
    if (catch23__label.is_used()) {
      compiler::CodeAssemblerLabel catch23_skip(&ca_);
      ca_.Goto(&catch23_skip);
      ca_.Bind(&catch23__label, &tmp24);
      ca_.Goto(&block16);
      ca_.Bind(&catch23_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp22});
    }
    if (catch26__label.is_used()) {
      compiler::CodeAssemblerLabel catch26_skip(&ca_);
      ca_.Goto(&catch26_skip);
      ca_.Bind(&catch26__label, &tmp27);
      ca_.Goto(&block17);
      ca_.Bind(&catch26_skip);
    }
    tmp28 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp25});
    compiler::CodeAssemblerExceptionHandlerLabel catch29__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch29__label);
    IteratorClose_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp21}, TNode<Object>{tmp28}});
    }
    if (catch29__label.is_used()) {
      compiler::CodeAssemblerLabel catch29_skip(&ca_);
      ca_.Goto(&catch29_skip);
      ca_.Bind(&catch29__label, &tmp30);
      ca_.Goto(&block18);
      ca_.Bind(&catch29_skip);
    }
    ca_.Goto(&block12);
  }

  TNode<HeapObject> tmp31;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp31 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block14, tmp20, tmp31);
  }

  TNode<HeapObject> tmp32;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp32 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block14, tmp24, tmp32);
  }

  TNode<HeapObject> tmp33;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp33 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block14, tmp27, tmp33);
  }

  TNode<HeapObject> tmp34;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp34 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block14, tmp30, tmp34);
  }

  TNode<Object> phi_bb14_7;
  TNode<HeapObject> phi_bb14_8;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_7, &phi_bb14_8);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp10}, TNode<Object>{tmp13}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb14_7, phi_bb14_8);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Undefined> tmp35;
  TNode<True> tmp36;
  TNode<JSObject> tmp37;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    IteratorClose_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp10}, TNode<Object>{tmp13}});
    tmp35 = Undefined_0(state_);
    tmp36 = True_0(state_);
    tmp37 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp35}, TNode<Boolean>{tmp36});
    CodeStubAssembler(state_).Return(tmp37);
  }

  TNode<Object> tmp38;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp38 = FromConstexpr_Object_constexpr_string_0(state_, "Iterator Helper.prototype.return");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp38}, TNode<Object>{parameter1});
  }

  TNode<BoolT> tmp39;
  TNode<BoolT> tmp40;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    ThrowIfIteratorHelperExecuting_0(state_, TNode<Context>{parameter0}, TNode<JSIteratorHelper>{tmp2});
    tmp39 = IsIteratorHelperExhausted_0(state_, TNode<JSIteratorHelper>{tmp2});
    tmp40 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp39});
    ca_.Branch(tmp40, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp41;
  TNode<HeapObject> tmp42;
  TNode<JSReceiver> tmp43;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp41 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp42 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp2, tmp41});
    compiler::CodeAssemblerLabel label44(&ca_);
    tmp43 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp42}, &label44);
    ca_.Goto(&block27);
    if (label44.is_used()) {
      ca_.Bind(&label44);
      ca_.Goto(&block28);
    }
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp45;
  TNode<Object> tmp46;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp46 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp2, tmp45});
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{tmp2});
    IteratorClose_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp43}, TNode<Object>{tmp46}});
    ca_.Goto(&block24);
  }

  TNode<Undefined> tmp47;
  TNode<True> tmp48;
  TNode<JSObject> tmp49;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp47 = Undefined_0(state_);
    tmp48 = True_0(state_);
    tmp49 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp47}, TNode<Boolean>{tmp48});
    CodeStubAssembler(state_).Return(tmp49);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=181&c=1
TNode<JSIteratorMapHelper> NewJSIteratorMapHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<JSReceiver> p_mapper) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Number> tmp17;
  TNode<JSIteratorMapHelper> tmp18;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_MAP_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp8}, TNode<Map>{tmp3}, TNode<BoolT>{tmp6}, TNode<BoolT>{tmp7});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp11}, tmp4);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp12}, tmp5);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp9, tmp13}, p_underlying.object);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp14}, p_underlying.next);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp9, tmp15}, p_mapper);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp17 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp16}, tmp17);
    tmp18 = TORQUE_CAST(TNode<HeapObject>{tmp9});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorMapHelper>{tmp18};
}

TF_BUILTIN(IteratorPrototypeMap, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kMapper);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.map");
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<Object> tmp4;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = FromConstexpr_JSAny_constexpr_string_0(state_, "Iterator.prototype.map");
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp4);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSReceiver> tmp5;
  TNode<Object> tmp6;
  TNode<JSIteratorMapHelper> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp5, tmp6) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp7 = NewJSIteratorMapHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}}, TNode<JSReceiver>{tmp2});
    CodeStubAssembler(state_).Return(tmp7);
  }
}

TF_BUILTIN(IteratorMapHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorMapHelper> parameter1 = UncheckedParameter<JSIteratorMapHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSReceiver> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Number> tmp4;
  TNode<JSReceiver> tmp5;
      TNode<Object> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    std::tie(tmp1, tmp2) = MarkIteratorHelperAsExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp4 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp3});
    compiler::CodeAssemblerLabel label6(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch7__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch7__label);
    tmp5 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, TNode<Map>{tmp0}, &label6);
    }
    if (catch7__label.is_used()) {
      compiler::CodeAssemblerLabel catch7_skip(&ca_);
      ca_.Goto(&catch7_skip);
      ca_.Bind(&catch7__label, &tmp8);
      ca_.Goto(&block7);
      ca_.Bind(&catch7_skip);
    }
    ca_.Goto(&block5);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block6);
    }
  }

  TNode<HeapObject> tmp9;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp9 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp8, tmp9);
  }

      TNode<Object> tmp11;
  TNode<Undefined> tmp12;
  TNode<True> tmp13;
  TNode<JSObject> tmp14;
      TNode<Object> tmp16;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerExceptionHandlerLabel catch10__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch10__label);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    }
    if (catch10__label.is_used()) {
      compiler::CodeAssemblerLabel catch10_skip(&ca_);
      ca_.Goto(&catch10_skip);
      ca_.Bind(&catch10__label, &tmp11);
      ca_.Goto(&block8);
      ca_.Bind(&catch10_skip);
    }
    tmp12 = Undefined_0(state_);
    tmp13 = True_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch15__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch15__label);
    tmp14 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp12}, TNode<Boolean>{tmp13});
    }
    if (catch15__label.is_used()) {
      compiler::CodeAssemblerLabel catch15_skip(&ca_);
      ca_.Goto(&catch15_skip);
      ca_.Bind(&catch15__label, &tmp16);
      ca_.Goto(&block9);
      ca_.Bind(&catch15_skip);
    }
    CodeStubAssembler(state_).Return(tmp14);
  }

  TNode<Object> tmp17;
      TNode<Object> tmp19;
  TNode<IntPtrT> tmp20;
      TNode<Object> tmp22;
  TNode<JSReceiver> tmp23;
  TNode<Undefined> tmp24;
  TNode<Object> tmp25;
      TNode<Object> tmp27;
  TNode<IntPtrT> tmp28;
      TNode<Object> tmp30;
  TNode<Number> tmp31;
      TNode<Object> tmp33;
  TNode<Number> tmp34;
      TNode<Object> tmp36;
      TNode<Object> tmp38;
  TNode<False> tmp39;
  TNode<JSObject> tmp40;
      TNode<Object> tmp42;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerExceptionHandlerLabel catch18__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch18__label);
    tmp17 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp5}, TNode<Map>{tmp0});
    }
    if (catch18__label.is_used()) {
      compiler::CodeAssemblerLabel catch18_skip(&ca_);
      ca_.Goto(&catch18_skip);
      ca_.Bind(&catch18__label, &tmp19);
      ca_.Goto(&block10);
      ca_.Bind(&catch18_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch21__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch21__label);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    }
    if (catch21__label.is_used()) {
      compiler::CodeAssemblerLabel catch21_skip(&ca_);
      ca_.Goto(&catch21_skip);
      ca_.Bind(&catch21__label, &tmp22);
      ca_.Goto(&block13);
      ca_.Bind(&catch21_skip);
    }
    tmp23 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp20});
    tmp24 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
    tmp25 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp23}, TNode<Object>{tmp24}, TNode<Object>{tmp17}, TNode<Object>{tmp4});
    }
    if (catch26__label.is_used()) {
      compiler::CodeAssemblerLabel catch26_skip(&ca_);
      ca_.Goto(&catch26_skip);
      ca_.Bind(&catch26__label, &tmp27);
      ca_.Goto(&block14);
      ca_.Bind(&catch26_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch29__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch29__label);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    }
    if (catch29__label.is_used()) {
      compiler::CodeAssemblerLabel catch29_skip(&ca_);
      ca_.Goto(&catch29_skip);
      ca_.Bind(&catch29__label, &tmp30);
      ca_.Goto(&block15);
      ca_.Bind(&catch29_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch32__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch32__label);
    tmp31 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch32__label.is_used()) {
      compiler::CodeAssemblerLabel catch32_skip(&ca_);
      ca_.Goto(&catch32_skip);
      ca_.Bind(&catch32__label, &tmp33);
      ca_.Goto(&block16);
      ca_.Bind(&catch32_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch35__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch35__label);
    tmp34 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp4}, TNode<Number>{tmp31});
    }
    if (catch35__label.is_used()) {
      compiler::CodeAssemblerLabel catch35_skip(&ca_);
      ca_.Goto(&catch35_skip);
      ca_.Bind(&catch35__label, &tmp36);
      ca_.Goto(&block17);
      ca_.Bind(&catch35_skip);
    }
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp28}, tmp34);
    compiler::CodeAssemblerExceptionHandlerLabel catch37__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch37__label);
    MarkIteratorHelperAsFinishedExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch37__label.is_used()) {
      compiler::CodeAssemblerLabel catch37_skip(&ca_);
      ca_.Goto(&catch37_skip);
      ca_.Bind(&catch37__label, &tmp38);
      ca_.Goto(&block18);
      ca_.Bind(&catch37_skip);
    }
    tmp39 = False_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch41__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch41__label);
    tmp40 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp25}, TNode<Boolean>{tmp39});
    }
    if (catch41__label.is_used()) {
      compiler::CodeAssemblerLabel catch41_skip(&ca_);
      ca_.Goto(&catch41_skip);
      ca_.Bind(&catch41__label, &tmp42);
      ca_.Goto(&block19);
      ca_.Bind(&catch41_skip);
    }
    CodeStubAssembler(state_).Return(tmp40);
  }

  TNode<HeapObject> tmp43;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp43 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp11, tmp43);
  }

  TNode<HeapObject> tmp44;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp44 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp16, tmp44);
  }

  TNode<HeapObject> tmp45;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp45 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp19, tmp45);
  }

  TNode<HeapObject> tmp46;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp46 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block12, tmp22, tmp46);
  }

  TNode<HeapObject> tmp47;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp47 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block12, tmp27, tmp47);
  }

  TNode<HeapObject> tmp48;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp48 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block12, tmp30, tmp48);
  }

  TNode<HeapObject> tmp49;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp49 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block12, tmp33, tmp49);
  }

  TNode<HeapObject> tmp50;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp50 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block12, tmp36, tmp50);
  }

  TNode<HeapObject> tmp51;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp51 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block12, tmp38, tmp51);
  }

  TNode<HeapObject> tmp52;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp52 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block12, tmp42, tmp52);
  }

  TNode<Object> phi_bb12_8;
  TNode<HeapObject> phi_bb12_9;
      TNode<Object> tmp54;
      TNode<Object> tmp56;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_8, &phi_bb12_9);
    compiler::CodeAssemblerExceptionHandlerLabel catch53__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch53__label);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch53__label.is_used()) {
      compiler::CodeAssemblerLabel catch53_skip(&ca_);
      ca_.Goto(&catch53_skip);
      ca_.Bind(&catch53__label, &tmp54);
      ca_.Goto(&block20);
      ca_.Bind(&catch53_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch55__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch55__label);
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb12_8, phi_bb12_9);
    CodeStubAssembler(state_).Unreachable();
    }
    if (catch55__label.is_used()) {
      compiler::CodeAssemblerLabel catch55_skip(&ca_);
      ca_.Bind(&catch55__label, &tmp56);
      ca_.Goto(&block21);
    }
  }

  TNode<HeapObject> tmp57;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp57 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp54, tmp57);
  }

  TNode<HeapObject> tmp58;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp58 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp56, tmp58);
  }

  TNode<Object> phi_bb2_6;
  TNode<HeapObject> phi_bb2_7;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_6, &phi_bb2_7);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb2_6, phi_bb2_7);
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=276&c=1
TNode<JSIteratorFilterHelper> NewJSIteratorFilterHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<JSReceiver> p_predicate) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Number> tmp17;
  TNode<JSIteratorFilterHelper> tmp18;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_FILTER_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp8}, TNode<Map>{tmp3}, TNode<BoolT>{tmp6}, TNode<BoolT>{tmp7});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp11}, tmp4);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp12}, tmp5);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp9, tmp13}, p_underlying.object);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp14}, p_underlying.next);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp9, tmp15}, p_predicate);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp17 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp16}, tmp17);
    tmp18 = TORQUE_CAST(TNode<HeapObject>{tmp9});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorFilterHelper>{tmp18};
}

TF_BUILTIN(IteratorPrototypeFilter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kPredicate);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.filter");
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<Object> tmp4;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = FromConstexpr_JSAny_constexpr_string_0(state_, "Iterator.prototype.filter");
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp4);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSReceiver> tmp5;
  TNode<Object> tmp6;
  TNode<JSIteratorFilterHelper> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp5, tmp6) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp7 = NewJSIteratorFilterHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}}, TNode<JSReceiver>{tmp2});
    CodeStubAssembler(state_).Return(tmp7);
  }
}

TF_BUILTIN(IteratorFilterHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorFilterHelper> parameter1 = UncheckedParameter<JSIteratorFilterHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSReceiver> tmp1;
  TNode<Object> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    std::tie(tmp1, tmp2) = MarkIteratorHelperAsExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}).Flatten();
    ca_.Goto(&block5);
  }

  TNode<BoolT> tmp3;
      TNode<Object> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerExceptionHandlerLabel catch4__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch4__label);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch4__label.is_used()) {
      compiler::CodeAssemblerLabel catch4_skip(&ca_);
      ca_.Goto(&catch4_skip);
      ca_.Bind(&catch4__label, &tmp5);
      ca_.Goto(&block6);
      ca_.Bind(&catch4_skip);
    }
    ca_.Branch(tmp3, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp6;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp5, tmp6);
  }

  TNode<IntPtrT> tmp7;
      TNode<Object> tmp9;
  TNode<Number> tmp10;
  TNode<JSReceiver> tmp11;
      TNode<Object> tmp14;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerExceptionHandlerLabel catch8__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch8__label);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    }
    if (catch8__label.is_used()) {
      compiler::CodeAssemblerLabel catch8_skip(&ca_);
      ca_.Goto(&catch8_skip);
      ca_.Bind(&catch8__label, &tmp9);
      ca_.Goto(&block7);
      ca_.Bind(&catch8_skip);
    }
    tmp10 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp7});
    compiler::CodeAssemblerLabel label12(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch13__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch13__label);
    tmp11 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, TNode<Map>{tmp0}, &label12);
    }
    if (catch13__label.is_used()) {
      compiler::CodeAssemblerLabel catch13_skip(&ca_);
      ca_.Goto(&catch13_skip);
      ca_.Bind(&catch13__label, &tmp14);
      ca_.Goto(&block12);
      ca_.Bind(&catch13_skip);
    }
    ca_.Goto(&block10);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block11);
    }
  }

  TNode<HeapObject> tmp15;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp15 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp9, tmp15);
  }

  TNode<HeapObject> tmp16;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp16 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp14, tmp16);
  }

      TNode<Object> tmp18;
  TNode<Undefined> tmp19;
  TNode<True> tmp20;
  TNode<JSObject> tmp21;
      TNode<Object> tmp23;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    compiler::CodeAssemblerExceptionHandlerLabel catch17__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch17__label);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    }
    if (catch17__label.is_used()) {
      compiler::CodeAssemblerLabel catch17_skip(&ca_);
      ca_.Goto(&catch17_skip);
      ca_.Bind(&catch17__label, &tmp18);
      ca_.Goto(&block13);
      ca_.Bind(&catch17_skip);
    }
    tmp19 = Undefined_0(state_);
    tmp20 = True_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch22__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch22__label);
    tmp21 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp19}, TNode<Boolean>{tmp20});
    }
    if (catch22__label.is_used()) {
      compiler::CodeAssemblerLabel catch22_skip(&ca_);
      ca_.Goto(&catch22_skip);
      ca_.Bind(&catch22__label, &tmp23);
      ca_.Goto(&block14);
      ca_.Bind(&catch22_skip);
    }
    CodeStubAssembler(state_).Return(tmp21);
  }

  TNode<Object> tmp24;
      TNode<Object> tmp26;
  TNode<IntPtrT> tmp27;
      TNode<Object> tmp29;
  TNode<JSReceiver> tmp30;
  TNode<Undefined> tmp31;
  TNode<Object> tmp32;
      TNode<Object> tmp34;
  TNode<IntPtrT> tmp35;
      TNode<Object> tmp37;
  TNode<Number> tmp38;
      TNode<Object> tmp40;
  TNode<Number> tmp41;
      TNode<Object> tmp43;
  TNode<BoolT> tmp44;
      TNode<Object> tmp46;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    compiler::CodeAssemblerExceptionHandlerLabel catch25__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch25__label);
    tmp24 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp11}, TNode<Map>{tmp0});
    }
    if (catch25__label.is_used()) {
      compiler::CodeAssemblerLabel catch25_skip(&ca_);
      ca_.Goto(&catch25_skip);
      ca_.Bind(&catch25__label, &tmp26);
      ca_.Goto(&block15);
      ca_.Bind(&catch25_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch28__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch28__label);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    }
    if (catch28__label.is_used()) {
      compiler::CodeAssemblerLabel catch28_skip(&ca_);
      ca_.Goto(&catch28_skip);
      ca_.Bind(&catch28__label, &tmp29);
      ca_.Goto(&block18);
      ca_.Bind(&catch28_skip);
    }
    tmp30 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp27});
    tmp31 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch33__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch33__label);
    tmp32 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp30}, TNode<Object>{tmp31}, TNode<Object>{tmp24}, TNode<Object>{tmp10});
    }
    if (catch33__label.is_used()) {
      compiler::CodeAssemblerLabel catch33_skip(&ca_);
      ca_.Goto(&catch33_skip);
      ca_.Bind(&catch33__label, &tmp34);
      ca_.Goto(&block19);
      ca_.Bind(&catch33_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch36__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch36__label);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    }
    if (catch36__label.is_used()) {
      compiler::CodeAssemblerLabel catch36_skip(&ca_);
      ca_.Goto(&catch36_skip);
      ca_.Bind(&catch36__label, &tmp37);
      ca_.Goto(&block20);
      ca_.Bind(&catch36_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch39__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch39__label);
    tmp38 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch39__label.is_used()) {
      compiler::CodeAssemblerLabel catch39_skip(&ca_);
      ca_.Goto(&catch39_skip);
      ca_.Bind(&catch39__label, &tmp40);
      ca_.Goto(&block21);
      ca_.Bind(&catch39_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch42__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch42__label);
    tmp41 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp10}, TNode<Number>{tmp38});
    }
    if (catch42__label.is_used()) {
      compiler::CodeAssemblerLabel catch42_skip(&ca_);
      ca_.Goto(&catch42_skip);
      ca_.Bind(&catch42__label, &tmp43);
      ca_.Goto(&block22);
      ca_.Bind(&catch42_skip);
    }
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp35}, tmp41);
    compiler::CodeAssemblerExceptionHandlerLabel catch45__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch45__label);
    tmp44 = ToBoolean_0(state_, TNode<Object>{tmp32});
    }
    if (catch45__label.is_used()) {
      compiler::CodeAssemblerLabel catch45_skip(&ca_);
      ca_.Goto(&catch45_skip);
      ca_.Bind(&catch45__label, &tmp46);
      ca_.Goto(&block25);
      ca_.Bind(&catch45_skip);
    }
    ca_.Branch(tmp44, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp47;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp47 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp18, tmp47);
  }

  TNode<HeapObject> tmp48;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp48 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp23, tmp48);
  }

  TNode<HeapObject> tmp49;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp49 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp26, tmp49);
  }

  TNode<HeapObject> tmp50;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp50 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, tmp29, tmp50);
  }

  TNode<HeapObject> tmp51;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp51 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, tmp34, tmp51);
  }

  TNode<HeapObject> tmp52;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp52 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, tmp37, tmp52);
  }

  TNode<HeapObject> tmp53;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp53 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, tmp40, tmp53);
  }

  TNode<HeapObject> tmp54;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp54 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, tmp43, tmp54);
  }

  TNode<HeapObject> tmp55;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp55 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, tmp46, tmp55);
  }

      TNode<Object> tmp57;
  TNode<False> tmp58;
  TNode<JSObject> tmp59;
      TNode<Object> tmp61;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    compiler::CodeAssemblerExceptionHandlerLabel catch56__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch56__label);
    MarkIteratorHelperAsFinishedExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch56__label.is_used()) {
      compiler::CodeAssemblerLabel catch56_skip(&ca_);
      ca_.Goto(&catch56_skip);
      ca_.Bind(&catch56__label, &tmp57);
      ca_.Goto(&block26);
      ca_.Bind(&catch56_skip);
    }
    tmp58 = False_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch60__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch60__label);
    tmp59 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp24}, TNode<Boolean>{tmp58});
    }
    if (catch60__label.is_used()) {
      compiler::CodeAssemblerLabel catch60_skip(&ca_);
      ca_.Goto(&catch60_skip);
      ca_.Bind(&catch60__label, &tmp61);
      ca_.Goto(&block27);
      ca_.Bind(&catch60_skip);
    }
    CodeStubAssembler(state_).Return(tmp59);
  }

  TNode<HeapObject> tmp62;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp62 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, tmp57, tmp62);
  }

  TNode<HeapObject> tmp63;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp63 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, tmp61, tmp63);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.Goto(&block5);
  }

  TNode<Object> phi_bb17_8;
  TNode<HeapObject> phi_bb17_9;
      TNode<Object> tmp65;
      TNode<Object> tmp67;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_8, &phi_bb17_9);
    compiler::CodeAssemblerExceptionHandlerLabel catch64__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch64__label);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch64__label.is_used()) {
      compiler::CodeAssemblerLabel catch64_skip(&ca_);
      ca_.Goto(&catch64_skip);
      ca_.Bind(&catch64__label, &tmp65);
      ca_.Goto(&block28);
      ca_.Bind(&catch64_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch66__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch66__label);
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb17_8, phi_bb17_9);
    CodeStubAssembler(state_).Unreachable();
    }
    if (catch66__label.is_used()) {
      compiler::CodeAssemblerLabel catch66_skip(&ca_);
      ca_.Bind(&catch66__label, &tmp67);
      ca_.Goto(&block29);
    }
  }

  TNode<HeapObject> tmp68;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp68 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp65, tmp68);
  }

  TNode<HeapObject> tmp69;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    tmp69 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp67, tmp69);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> phi_bb2_5;
  TNode<HeapObject> phi_bb2_6;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5, &phi_bb2_6);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb2_5, phi_bb2_6);
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=378&c=1
TNode<JSIteratorTakeHelper> NewJSIteratorTakeHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<Number> p_limit) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<JSIteratorTakeHelper> tmp16;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_TAKE_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp8}, TNode<Map>{tmp3}, TNode<BoolT>{tmp6}, TNode<BoolT>{tmp7});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp11}, tmp4);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp12}, tmp5);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp9, tmp13}, p_underlying.object);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp14}, p_underlying.next);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp15}, p_limit);
    tmp16 = TORQUE_CAST(TNode<HeapObject>{tmp9});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorTakeHelper>{tmp16};
}

TF_BUILTIN(IteratorPrototypeTake, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kLimit);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.take");
  }

  TNode<Number> tmp2;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp3 = NumberIsNaN_0(state_, TNode<Number>{tmp2});
    ca_.Branch(tmp3, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<Number> tmp4;
  TNode<Number> tmp5;
  TNode<BoolT> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp2});
    tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = NumberIsLessThan_0(state_, TNode<Number>{tmp4}, TNode<Number>{tmp5});
    ca_.Branch(tmp6, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2);
  }

  TNode<JSReceiver> tmp7;
  TNode<Object> tmp8;
  TNode<JSIteratorTakeHelper> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    std::tie(tmp7, tmp8) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp9 = NewJSIteratorTakeHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp7}, TNode<Object>{tmp8}}, TNode<Number>{tmp4});
    CodeStubAssembler(state_).Return(tmp9);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{parameter0}, MessageTemplate::kMustBePositive, TNode<Object>{parameter2});
  }
}

TF_BUILTIN(IteratorTakeHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorTakeHelper> parameter1 = UncheckedParameter<JSIteratorTakeHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSReceiver> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Number> tmp4;
  TNode<Number> tmp5;
      TNode<Object> tmp7;
  TNode<BoolT> tmp8;
      TNode<Object> tmp10;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    std::tie(tmp1, tmp2) = MarkIteratorHelperAsExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp4 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp3});
    compiler::CodeAssemblerExceptionHandlerLabel catch6__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch6__label);
    tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    }
    if (catch6__label.is_used()) {
      compiler::CodeAssemblerLabel catch6_skip(&ca_);
      ca_.Goto(&catch6_skip);
      ca_.Bind(&catch6__label, &tmp7);
      ca_.Goto(&block5);
      ca_.Bind(&catch6_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch9__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch9__label);
    tmp8 = IsNumberEqual_0(state_, TNode<Number>{tmp4}, TNode<Number>{tmp5});
    }
    if (catch9__label.is_used()) {
      compiler::CodeAssemblerLabel catch9_skip(&ca_);
      ca_.Goto(&catch9_skip);
      ca_.Bind(&catch9__label, &tmp10);
      ca_.Goto(&block6);
      ca_.Bind(&catch9_skip);
    }
    ca_.Branch(tmp8, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp11;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp11 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp7, tmp11);
  }

  TNode<HeapObject> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp12 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp10, tmp12);
  }

      TNode<Object> tmp14;
      TNode<Object> tmp16;
  TNode<Undefined> tmp17;
  TNode<True> tmp18;
  TNode<JSObject> tmp19;
      TNode<Object> tmp21;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerExceptionHandlerLabel catch13__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch13__label);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    }
    if (catch13__label.is_used()) {
      compiler::CodeAssemblerLabel catch13_skip(&ca_);
      ca_.Goto(&catch13_skip);
      ca_.Bind(&catch13__label, &tmp14);
      ca_.Goto(&block7);
      ca_.Bind(&catch13_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch15__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch15__label);
    IteratorClose_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch15__label.is_used()) {
      compiler::CodeAssemblerLabel catch15_skip(&ca_);
      ca_.Goto(&catch15_skip);
      ca_.Bind(&catch15__label, &tmp16);
      ca_.Goto(&block8);
      ca_.Bind(&catch15_skip);
    }
    tmp17 = Undefined_0(state_);
    tmp18 = True_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch20__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch20__label);
    tmp19 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp17}, TNode<Boolean>{tmp18});
    }
    if (catch20__label.is_used()) {
      compiler::CodeAssemblerLabel catch20_skip(&ca_);
      ca_.Goto(&catch20_skip);
      ca_.Bind(&catch20__label, &tmp21);
      ca_.Goto(&block9);
      ca_.Bind(&catch20_skip);
    }
    CodeStubAssembler(state_).Return(tmp19);
  }

  TNode<HeapObject> tmp22;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp22 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp14, tmp22);
  }

  TNode<HeapObject> tmp23;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp23 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp16, tmp23);
  }

  TNode<HeapObject> tmp24;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp24 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp21, tmp24);
  }

  TNode<BoolT> tmp25;
      TNode<Object> tmp27;
  TNode<BoolT> tmp28;
      TNode<Object> tmp30;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
    tmp25 = NumberIsSomeInfinity_0(state_, TNode<Number>{tmp4});
    }
    if (catch26__label.is_used()) {
      compiler::CodeAssemblerLabel catch26_skip(&ca_);
      ca_.Goto(&catch26_skip);
      ca_.Bind(&catch26__label, &tmp27);
      ca_.Goto(&block12);
      ca_.Bind(&catch26_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch29__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch29__label);
    tmp28 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp25});
    }
    if (catch29__label.is_used()) {
      compiler::CodeAssemblerLabel catch29_skip(&ca_);
      ca_.Goto(&catch29_skip);
      ca_.Bind(&catch29__label, &tmp30);
      ca_.Goto(&block13);
      ca_.Bind(&catch29_skip);
    }
    ca_.Branch(tmp28, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp31;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp31 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp27, tmp31);
  }

  TNode<HeapObject> tmp32;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp32 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp30, tmp32);
  }

  TNode<IntPtrT> tmp33;
      TNode<Object> tmp35;
  TNode<Number> tmp36;
      TNode<Object> tmp38;
  TNode<Number> tmp39;
      TNode<Object> tmp41;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    compiler::CodeAssemblerExceptionHandlerLabel catch34__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch34__label);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    }
    if (catch34__label.is_used()) {
      compiler::CodeAssemblerLabel catch34_skip(&ca_);
      ca_.Goto(&catch34_skip);
      ca_.Bind(&catch34__label, &tmp35);
      ca_.Goto(&block14);
      ca_.Bind(&catch34_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch37__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch37__label);
    tmp36 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch37__label.is_used()) {
      compiler::CodeAssemblerLabel catch37_skip(&ca_);
      ca_.Goto(&catch37_skip);
      ca_.Bind(&catch37__label, &tmp38);
      ca_.Goto(&block15);
      ca_.Bind(&catch37_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch40__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch40__label);
    tmp39 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp4}, TNode<Number>{tmp36});
    }
    if (catch40__label.is_used()) {
      compiler::CodeAssemblerLabel catch40_skip(&ca_);
      ca_.Goto(&catch40_skip);
      ca_.Bind(&catch40__label, &tmp41);
      ca_.Goto(&block16);
      ca_.Bind(&catch40_skip);
    }
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp33}, tmp39);
    ca_.Goto(&block11);
  }

  TNode<HeapObject> tmp42;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp42 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp35, tmp42);
  }

  TNode<HeapObject> tmp43;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp43 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp38, tmp43);
  }

  TNode<HeapObject> tmp44;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp44 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp41, tmp44);
  }

  TNode<JSReceiver> tmp45;
      TNode<Object> tmp48;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    compiler::CodeAssemblerLabel label46(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch47__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch47__label);
    tmp45 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, TNode<Map>{tmp0}, &label46);
    }
    if (catch47__label.is_used()) {
      compiler::CodeAssemblerLabel catch47_skip(&ca_);
      ca_.Goto(&catch47_skip);
      ca_.Bind(&catch47__label, &tmp48);
      ca_.Goto(&block21);
      ca_.Bind(&catch47_skip);
    }
    ca_.Goto(&block19);
    if (label46.is_used()) {
      ca_.Bind(&label46);
      ca_.Goto(&block20);
    }
  }

  TNode<HeapObject> tmp49;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp49 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp48, tmp49);
  }

      TNode<Object> tmp51;
  TNode<Undefined> tmp52;
  TNode<True> tmp53;
  TNode<JSObject> tmp54;
      TNode<Object> tmp56;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    compiler::CodeAssemblerExceptionHandlerLabel catch50__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch50__label);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    }
    if (catch50__label.is_used()) {
      compiler::CodeAssemblerLabel catch50_skip(&ca_);
      ca_.Goto(&catch50_skip);
      ca_.Bind(&catch50__label, &tmp51);
      ca_.Goto(&block22);
      ca_.Bind(&catch50_skip);
    }
    tmp52 = Undefined_0(state_);
    tmp53 = True_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch55__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch55__label);
    tmp54 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp52}, TNode<Boolean>{tmp53});
    }
    if (catch55__label.is_used()) {
      compiler::CodeAssemblerLabel catch55_skip(&ca_);
      ca_.Goto(&catch55_skip);
      ca_.Bind(&catch55__label, &tmp56);
      ca_.Goto(&block23);
      ca_.Bind(&catch55_skip);
    }
    CodeStubAssembler(state_).Return(tmp54);
  }

  TNode<Object> tmp57;
      TNode<Object> tmp59;
      TNode<Object> tmp61;
  TNode<False> tmp62;
  TNode<JSObject> tmp63;
      TNode<Object> tmp65;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    compiler::CodeAssemblerExceptionHandlerLabel catch58__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch58__label);
    tmp57 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp45}, TNode<Map>{tmp0});
    }
    if (catch58__label.is_used()) {
      compiler::CodeAssemblerLabel catch58_skip(&ca_);
      ca_.Goto(&catch58_skip);
      ca_.Bind(&catch58__label, &tmp59);
      ca_.Goto(&block24);
      ca_.Bind(&catch58_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch60__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch60__label);
    MarkIteratorHelperAsFinishedExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch60__label.is_used()) {
      compiler::CodeAssemblerLabel catch60_skip(&ca_);
      ca_.Goto(&catch60_skip);
      ca_.Bind(&catch60__label, &tmp61);
      ca_.Goto(&block25);
      ca_.Bind(&catch60_skip);
    }
    tmp62 = False_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch64__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch64__label);
    tmp63 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp57}, TNode<Boolean>{tmp62});
    }
    if (catch64__label.is_used()) {
      compiler::CodeAssemblerLabel catch64_skip(&ca_);
      ca_.Goto(&catch64_skip);
      ca_.Bind(&catch64__label, &tmp65);
      ca_.Goto(&block26);
      ca_.Bind(&catch64_skip);
    }
    CodeStubAssembler(state_).Return(tmp63);
  }

  TNode<HeapObject> tmp66;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp66 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp51, tmp66);
  }

  TNode<HeapObject> tmp67;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp67 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp56, tmp67);
  }

  TNode<HeapObject> tmp68;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp68 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp59, tmp68);
  }

  TNode<HeapObject> tmp69;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp69 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp61, tmp69);
  }

  TNode<HeapObject> tmp70;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp70 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp65, tmp70);
  }

  TNode<Object> phi_bb2_6;
  TNode<HeapObject> phi_bb2_7;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_6, &phi_bb2_7);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb2_6, phi_bb2_7);
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=482&c=1
TNode<JSIteratorDropHelper> NewJSIteratorDropHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<Number> p_limit) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<JSIteratorDropHelper> tmp16;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_DROP_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp8}, TNode<Map>{tmp3}, TNode<BoolT>{tmp6}, TNode<BoolT>{tmp7});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp11}, tmp4);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp12}, tmp5);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp9, tmp13}, p_underlying.object);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp14}, p_underlying.next);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp15}, p_limit);
    tmp16 = TORQUE_CAST(TNode<HeapObject>{tmp9});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorDropHelper>{tmp16};
}

TF_BUILTIN(IteratorPrototypeDrop, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kLimit);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.drop");
  }

  TNode<Number> tmp2;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp3 = NumberIsNaN_0(state_, TNode<Number>{tmp2});
    ca_.Branch(tmp3, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<Number> tmp4;
  TNode<Number> tmp5;
  TNode<BoolT> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp2});
    tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = NumberIsLessThan_0(state_, TNode<Number>{tmp4}, TNode<Number>{tmp5});
    ca_.Branch(tmp6, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2);
  }

  TNode<JSReceiver> tmp7;
  TNode<Object> tmp8;
  TNode<JSIteratorDropHelper> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    std::tie(tmp7, tmp8) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp9 = NewJSIteratorDropHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp7}, TNode<Object>{tmp8}}, TNode<Number>{tmp4});
    CodeStubAssembler(state_).Return(tmp9);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{parameter0}, MessageTemplate::kMustBePositive, TNode<Object>{parameter2});
  }
}

TF_BUILTIN(IteratorDropHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorDropHelper> parameter1 = UncheckedParameter<JSIteratorDropHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, JSReceiver, Object, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSReceiver> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Number> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    std::tie(tmp1, tmp2) = MarkIteratorHelperAsExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp4 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp3});
    ca_.Goto(&block7, tmp4);
  }

  TNode<Number> phi_bb7_5;
  TNode<Number> tmp5;
      TNode<Object> tmp7;
  TNode<BoolT> tmp8;
      TNode<Object> tmp10;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5);
    compiler::CodeAssemblerExceptionHandlerLabel catch6__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch6__label);
    tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    }
    if (catch6__label.is_used()) {
      compiler::CodeAssemblerLabel catch6_skip(&ca_);
      ca_.Goto(&catch6_skip);
      ca_.Bind(&catch6__label, &tmp7);
      ca_.Goto(&block8, phi_bb7_5, phi_bb7_5, phi_bb7_5);
      ca_.Bind(&catch6_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch9__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch9__label);
    tmp8 = NumberIsGreaterThan_0(state_, TNode<Number>{phi_bb7_5}, TNode<Number>{tmp5});
    }
    if (catch9__label.is_used()) {
      compiler::CodeAssemblerLabel catch9_skip(&ca_);
      ca_.Goto(&catch9_skip);
      ca_.Bind(&catch9__label, &tmp10);
      ca_.Goto(&block9, phi_bb7_5, phi_bb7_5);
      ca_.Bind(&catch9_skip);
    }
    ca_.Branch(tmp8, &block5, std::vector<compiler::Node*>{phi_bb7_5}, &block6, std::vector<compiler::Node*>{phi_bb7_5});
  }

  TNode<Number> phi_bb8_5;
  TNode<Number> phi_bb8_7;
  TNode<Number> phi_bb8_8;
  TNode<HeapObject> tmp11;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_5, &phi_bb8_7, &phi_bb8_8);
    tmp11 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb8_5, ca_.Uninitialized<JSReceiver>(), tmp7, tmp11);
  }

  TNode<Number> phi_bb9_5;
  TNode<Number> phi_bb9_7;
  TNode<HeapObject> tmp12;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5, &phi_bb9_7);
    tmp12 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb9_5, ca_.Uninitialized<JSReceiver>(), tmp10, tmp12);
  }

  TNode<Number> phi_bb5_5;
  TNode<BoolT> tmp13;
      TNode<Object> tmp15;
  TNode<BoolT> tmp16;
      TNode<Object> tmp18;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    compiler::CodeAssemblerExceptionHandlerLabel catch14__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch14__label);
    tmp13 = NumberIsSomeInfinity_0(state_, TNode<Number>{phi_bb5_5});
    }
    if (catch14__label.is_used()) {
      compiler::CodeAssemblerLabel catch14_skip(&ca_);
      ca_.Goto(&catch14_skip);
      ca_.Bind(&catch14__label, &tmp15);
      ca_.Goto(&block12, phi_bb5_5, phi_bb5_5);
      ca_.Bind(&catch14_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch17__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch17__label);
    tmp16 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp13});
    }
    if (catch17__label.is_used()) {
      compiler::CodeAssemblerLabel catch17_skip(&ca_);
      ca_.Goto(&catch17_skip);
      ca_.Bind(&catch17__label, &tmp18);
      ca_.Goto(&block13, phi_bb5_5);
      ca_.Bind(&catch17_skip);
    }
    ca_.Branch(tmp16, &block10, std::vector<compiler::Node*>{phi_bb5_5}, &block11, std::vector<compiler::Node*>{phi_bb5_5});
  }

  TNode<Number> phi_bb12_5;
  TNode<Number> phi_bb12_7;
  TNode<HeapObject> tmp19;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_5, &phi_bb12_7);
    tmp19 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb12_5, ca_.Uninitialized<JSReceiver>(), tmp15, tmp19);
  }

  TNode<Number> phi_bb13_5;
  TNode<HeapObject> tmp20;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_5);
    tmp20 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb13_5, ca_.Uninitialized<JSReceiver>(), tmp18, tmp20);
  }

  TNode<Number> phi_bb10_5;
  TNode<Number> tmp21;
      TNode<Object> tmp23;
  TNode<Number> tmp24;
      TNode<Object> tmp26;
  TNode<IntPtrT> tmp27;
      TNode<Object> tmp29;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    compiler::CodeAssemblerExceptionHandlerLabel catch22__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch22__label);
    tmp21 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch22__label.is_used()) {
      compiler::CodeAssemblerLabel catch22_skip(&ca_);
      ca_.Goto(&catch22_skip);
      ca_.Bind(&catch22__label, &tmp23);
      ca_.Goto(&block14, phi_bb10_5, phi_bb10_5, phi_bb10_5);
      ca_.Bind(&catch22_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch25__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch25__label);
    tmp24 = CodeStubAssembler(state_).NumberSub(TNode<Number>{phi_bb10_5}, TNode<Number>{tmp21});
    }
    if (catch25__label.is_used()) {
      compiler::CodeAssemblerLabel catch25_skip(&ca_);
      ca_.Goto(&catch25_skip);
      ca_.Bind(&catch25__label, &tmp26);
      ca_.Goto(&block15, phi_bb10_5, phi_bb10_5);
      ca_.Bind(&catch25_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch28__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch28__label);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    }
    if (catch28__label.is_used()) {
      compiler::CodeAssemblerLabel catch28_skip(&ca_);
      ca_.Goto(&catch28_skip);
      ca_.Bind(&catch28__label, &tmp29);
      ca_.Goto(&block16);
      ca_.Bind(&catch28_skip);
    }
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp27}, tmp24);
    ca_.Goto(&block11, tmp24);
  }

  TNode<Number> phi_bb14_5;
  TNode<Number> phi_bb14_7;
  TNode<Number> phi_bb14_8;
  TNode<HeapObject> tmp30;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_5, &phi_bb14_7, &phi_bb14_8);
    tmp30 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb14_5, ca_.Uninitialized<JSReceiver>(), tmp23, tmp30);
  }

  TNode<Number> phi_bb15_5;
  TNode<Number> phi_bb15_7;
  TNode<HeapObject> tmp31;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_5, &phi_bb15_7);
    tmp31 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb15_5, ca_.Uninitialized<JSReceiver>(), tmp26, tmp31);
  }

  TNode<HeapObject> tmp32;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp32 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp24, ca_.Uninitialized<JSReceiver>(), tmp29, tmp32);
  }

  TNode<Number> phi_bb11_5;
  TNode<JSReceiver> tmp33;
      TNode<Object> tmp36;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_5);
    compiler::CodeAssemblerLabel label34(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch35__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch35__label);
    tmp33 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, TNode<Map>{tmp0}, &label34);
    }
    if (catch35__label.is_used()) {
      compiler::CodeAssemblerLabel catch35_skip(&ca_);
      ca_.Goto(&catch35_skip);
      ca_.Bind(&catch35__label, &tmp36);
      ca_.Goto(&block19);
      ca_.Bind(&catch35_skip);
    }
    ca_.Goto(&block17);
    if (label34.is_used()) {
      ca_.Bind(&label34);
      ca_.Goto(&block18);
    }
  }

  TNode<HeapObject> tmp37;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp37 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb11_5, ca_.Uninitialized<JSReceiver>(), tmp36, tmp37);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block4, phi_bb11_5);
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block7, phi_bb11_5);
  }

  TNode<Number> phi_bb6_5;
  TNode<JSReceiver> tmp38;
      TNode<Object> tmp41;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    compiler::CodeAssemblerLabel label39(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch40__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch40__label);
    tmp38 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, TNode<Map>{tmp0}, &label39);
    }
    if (catch40__label.is_used()) {
      compiler::CodeAssemblerLabel catch40_skip(&ca_);
      ca_.Goto(&catch40_skip);
      ca_.Bind(&catch40__label, &tmp41);
      ca_.Goto(&block22, phi_bb6_5);
      ca_.Bind(&catch40_skip);
    }
    ca_.Goto(&block20, phi_bb6_5);
    if (label39.is_used()) {
      ca_.Bind(&label39);
      ca_.Goto(&block21, phi_bb6_5);
    }
  }

  TNode<Number> phi_bb22_5;
  TNode<HeapObject> tmp42;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_5);
    tmp42 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb22_5, ca_.Uninitialized<JSReceiver>(), tmp41, tmp42);
  }

  TNode<Number> phi_bb21_5;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_5);
    ca_.Goto(&block4, phi_bb21_5);
  }

  TNode<Number> phi_bb20_5;
  TNode<Object> tmp43;
      TNode<Object> tmp45;
      TNode<Object> tmp47;
  TNode<False> tmp48;
  TNode<JSObject> tmp49;
      TNode<Object> tmp51;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_5);
    compiler::CodeAssemblerExceptionHandlerLabel catch44__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch44__label);
    tmp43 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp38}, TNode<Map>{tmp0});
    }
    if (catch44__label.is_used()) {
      compiler::CodeAssemblerLabel catch44_skip(&ca_);
      ca_.Goto(&catch44_skip);
      ca_.Bind(&catch44__label, &tmp45);
      ca_.Goto(&block25, phi_bb20_5);
      ca_.Bind(&catch44_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch46__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch46__label);
    MarkIteratorHelperAsFinishedExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch46__label.is_used()) {
      compiler::CodeAssemblerLabel catch46_skip(&ca_);
      ca_.Goto(&catch46_skip);
      ca_.Bind(&catch46__label, &tmp47);
      ca_.Goto(&block26, phi_bb20_5);
      ca_.Bind(&catch46_skip);
    }
    tmp48 = False_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch50__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch50__label);
    tmp49 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp43}, TNode<Boolean>{tmp48});
    }
    if (catch50__label.is_used()) {
      compiler::CodeAssemblerLabel catch50_skip(&ca_);
      ca_.Goto(&catch50_skip);
      ca_.Bind(&catch50__label, &tmp51);
      ca_.Goto(&block27, phi_bb20_5);
      ca_.Bind(&catch50_skip);
    }
    CodeStubAssembler(state_).Return(tmp49);
  }

  TNode<Number> phi_bb4_5;
      TNode<Object> tmp53;
  TNode<Undefined> tmp54;
  TNode<True> tmp55;
  TNode<JSObject> tmp56;
      TNode<Object> tmp58;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    compiler::CodeAssemblerExceptionHandlerLabel catch52__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch52__label);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    }
    if (catch52__label.is_used()) {
      compiler::CodeAssemblerLabel catch52_skip(&ca_);
      ca_.Goto(&catch52_skip);
      ca_.Bind(&catch52__label, &tmp53);
      ca_.Goto(&block23);
      ca_.Bind(&catch52_skip);
    }
    tmp54 = Undefined_0(state_);
    tmp55 = True_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch57__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch57__label);
    tmp56 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp54}, TNode<Boolean>{tmp55});
    }
    if (catch57__label.is_used()) {
      compiler::CodeAssemblerLabel catch57_skip(&ca_);
      ca_.Goto(&catch57_skip);
      ca_.Bind(&catch57__label, &tmp58);
      ca_.Goto(&block24);
      ca_.Bind(&catch57_skip);
    }
    CodeStubAssembler(state_).Return(tmp56);
  }

  TNode<HeapObject> tmp59;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp59 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb4_5, ca_.Uninitialized<JSReceiver>(), tmp53, tmp59);
  }

  TNode<HeapObject> tmp60;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp60 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb4_5, ca_.Uninitialized<JSReceiver>(), tmp58, tmp60);
  }

  TNode<Number> phi_bb25_5;
  TNode<HeapObject> tmp61;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_5);
    tmp61 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb25_5, tmp38, tmp45, tmp61);
  }

  TNode<Number> phi_bb26_5;
  TNode<HeapObject> tmp62;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_5);
    tmp62 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb26_5, tmp38, tmp47, tmp62);
  }

  TNode<Number> phi_bb27_5;
  TNode<HeapObject> tmp63;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_5);
    tmp63 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, phi_bb27_5, tmp38, tmp51, tmp63);
  }

  TNode<Number> phi_bb2_5;
  TNode<JSReceiver> phi_bb2_6;
  TNode<Object> phi_bb2_7;
  TNode<HeapObject> phi_bb2_8;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5, &phi_bb2_6, &phi_bb2_7, &phi_bb2_8);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb2_7, phi_bb2_8);
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=585&c=1
const char* kFlatMapMethodName_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  return "Iterator.prototype.flatMap";}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=587&c=1
TNode<JSIteratorFlatMapHelper> NewJSIteratorFlatMapHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<JSReceiver> p_mapper) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<False> tmp6;
  TNode<BoolT> tmp7;
  TNode<BoolT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<HeapObject> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Number> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<JSIteratorFlatMapHelper> tmp23;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_FLAT_MAP_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = False_0(state_);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    tmp10 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp9}, TNode<Map>{tmp3}, TNode<BoolT>{tmp7}, TNode<BoolT>{tmp8});
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp10, tmp11}, tmp3);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp10, tmp12}, tmp4);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp10, tmp13}, tmp5);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp10, tmp14}, p_underlying.object);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp10, tmp15}, p_underlying.next);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp10, tmp16}, p_mapper);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp18 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp10, tmp17}, tmp18);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp10, tmp19}, p_underlying.object);
    tmp20 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp20});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp10, tmp21}, p_underlying.next);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
    CodeStubAssembler(state_).StoreReference<Boolean>(CodeStubAssembler::Reference{tmp10, tmp22}, tmp6);
    tmp23 = TORQUE_CAST(TNode<HeapObject>{tmp10});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorFlatMapHelper>{tmp23};
}

TF_BUILTIN(IteratorPrototypeFlatMap, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kMapper);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, kFlatMapMethodName_0(state_));
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledNonCallable, kFlatMapMethodName_0(state_));
  }

  TNode<JSReceiver> tmp4;
  TNode<Object> tmp5;
  TNode<JSIteratorFlatMapHelper> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp4, tmp5) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp6 = NewJSIteratorFlatMapHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp4}, TNode<Object>{tmp5}}, TNode<JSReceiver>{tmp2});
    CodeStubAssembler(state_).Return(tmp6);
  }
}

TF_BUILTIN(IteratorFlatMapHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorFlatMapHelper> parameter1 = UncheckedParameter<JSIteratorFlatMapHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Object, HeapObject> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object> block39(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, JSReceiver, Object> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, JSReceiver, Object> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, JSReceiver, Object> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object> block50(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object> block51(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object> block52(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Object, HeapObject> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Object, HeapObject> block53(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Object, HeapObject, Object, HeapObject> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSReceiver> tmp1;
  TNode<Object> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    std::tie(tmp1, tmp2) = MarkIteratorHelperAsExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}).Flatten();
    ca_.Goto(&block5);
  }

  TNode<BoolT> tmp3;
      TNode<Object> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerExceptionHandlerLabel catch4__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch4__label);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch4__label.is_used()) {
      compiler::CodeAssemblerLabel catch4_skip(&ca_);
      ca_.Goto(&catch4_skip);
      ca_.Bind(&catch4__label, &tmp5);
      ca_.Goto(&block6);
      ca_.Bind(&catch4_skip);
    }
    ca_.Branch(tmp3, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp6;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp5, tmp6);
  }

  TNode<IntPtrT> tmp7;
      TNode<Object> tmp9;
  TNode<Number> tmp10;
  TNode<IntPtrT> tmp11;
      TNode<Object> tmp13;
  TNode<JSReceiver> tmp14;
  TNode<IntPtrT> tmp15;
      TNode<Object> tmp17;
  TNode<IntPtrT> tmp18;
      TNode<Object> tmp20;
  TNode<Object> tmp21;
  TNode<IntPtrT> tmp22;
      TNode<Object> tmp24;
  TNode<Boolean> tmp25;
  TNode<False> tmp26;
  TNode<BoolT> tmp27;
      TNode<Object> tmp29;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerExceptionHandlerLabel catch8__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch8__label);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    }
    if (catch8__label.is_used()) {
      compiler::CodeAssemblerLabel catch8_skip(&ca_);
      ca_.Goto(&catch8_skip);
      ca_.Bind(&catch8__label, &tmp9);
      ca_.Goto(&block7);
      ca_.Bind(&catch8_skip);
    }
    tmp10 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp7});
    compiler::CodeAssemblerExceptionHandlerLabel catch12__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch12__label);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    }
    if (catch12__label.is_used()) {
      compiler::CodeAssemblerLabel catch12_skip(&ca_);
      ca_.Goto(&catch12_skip);
      ca_.Bind(&catch12__label, &tmp13);
      ca_.Goto(&block8);
      ca_.Bind(&catch12_skip);
    }
    tmp14 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp11});
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    tmp15 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block9);
      ca_.Bind(&catch16_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch19__label);
    tmp18 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp15});
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      ca_.Bind(&catch19__label, &tmp20);
      ca_.Goto(&block10);
      ca_.Bind(&catch19_skip);
    }
    tmp21 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{parameter1, tmp18});
    compiler::CodeAssemblerExceptionHandlerLabel catch23__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch23__label);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
    }
    if (catch23__label.is_used()) {
      compiler::CodeAssemblerLabel catch23_skip(&ca_);
      ca_.Goto(&catch23_skip);
      ca_.Bind(&catch23__label, &tmp24);
      ca_.Goto(&block13);
      ca_.Bind(&catch23_skip);
    }
    tmp25 = CodeStubAssembler(state_).LoadReference<Boolean>(CodeStubAssembler::Reference{parameter1, tmp22});
    tmp26 = False_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch28__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch28__label);
    tmp27 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp25}, TNode<HeapObject>{tmp26});
    }
    if (catch28__label.is_used()) {
      compiler::CodeAssemblerLabel catch28_skip(&ca_);
      ca_.Goto(&catch28_skip);
      ca_.Bind(&catch28__label, &tmp29);
      ca_.Goto(&block14);
      ca_.Bind(&catch28_skip);
    }
    ca_.Branch(tmp27, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{tmp14, tmp21});
  }

  TNode<HeapObject> tmp30;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp30 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp9, tmp30);
  }

  TNode<HeapObject> tmp31;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp31 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp13, tmp31);
  }

  TNode<HeapObject> tmp32;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp32 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp17, tmp32);
  }

  TNode<HeapObject> tmp33;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp33 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp20, tmp33);
  }

  TNode<HeapObject> tmp34;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp34 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp24, tmp34);
  }

  TNode<HeapObject> tmp35;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp35 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp29, tmp35);
  }

  TNode<JSReceiver> tmp36;
      TNode<Object> tmp39;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    compiler::CodeAssemblerLabel label37(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch38__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch38__label);
    tmp36 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, TNode<Map>{tmp0}, &label37);
    }
    if (catch38__label.is_used()) {
      compiler::CodeAssemblerLabel catch38_skip(&ca_);
      ca_.Goto(&catch38_skip);
      ca_.Bind(&catch38__label, &tmp39);
      ca_.Goto(&block19);
      ca_.Bind(&catch38_skip);
    }
    ca_.Goto(&block17);
    if (label37.is_used()) {
      ca_.Bind(&label37);
      ca_.Goto(&block18);
    }
  }

  TNode<HeapObject> tmp40;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp40 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp39, tmp40);
  }

      TNode<Object> tmp42;
  TNode<Undefined> tmp43;
  TNode<True> tmp44;
  TNode<JSObject> tmp45;
      TNode<Object> tmp47;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    compiler::CodeAssemblerExceptionHandlerLabel catch41__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch41__label);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    }
    if (catch41__label.is_used()) {
      compiler::CodeAssemblerLabel catch41_skip(&ca_);
      ca_.Goto(&catch41_skip);
      ca_.Bind(&catch41__label, &tmp42);
      ca_.Goto(&block20);
      ca_.Bind(&catch41_skip);
    }
    tmp43 = Undefined_0(state_);
    tmp44 = True_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch46__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch46__label);
    tmp45 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp43}, TNode<Boolean>{tmp44});
    }
    if (catch46__label.is_used()) {
      compiler::CodeAssemblerLabel catch46_skip(&ca_);
      ca_.Goto(&catch46_skip);
      ca_.Bind(&catch46__label, &tmp47);
      ca_.Goto(&block21);
      ca_.Bind(&catch46_skip);
    }
    CodeStubAssembler(state_).Return(tmp45);
  }

  TNode<Object> tmp48;
      TNode<Object> tmp50;
  TNode<IntPtrT> tmp51;
      TNode<Object> tmp53;
  TNode<JSReceiver> tmp54;
  TNode<Undefined> tmp55;
  TNode<Object> tmp56;
      TNode<Object> tmp58;
  TNode<JSReceiver> tmp59;
      TNode<Object> tmp62;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    compiler::CodeAssemblerExceptionHandlerLabel catch49__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch49__label);
    tmp48 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp36}, TNode<Map>{tmp0});
    }
    if (catch49__label.is_used()) {
      compiler::CodeAssemblerLabel catch49_skip(&ca_);
      ca_.Goto(&catch49_skip);
      ca_.Bind(&catch49__label, &tmp50);
      ca_.Goto(&block22);
      ca_.Bind(&catch49_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch52__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch52__label);
    tmp51 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    }
    if (catch52__label.is_used()) {
      compiler::CodeAssemblerLabel catch52_skip(&ca_);
      ca_.Goto(&catch52_skip);
      ca_.Bind(&catch52__label, &tmp53);
      ca_.Goto(&block25);
      ca_.Bind(&catch52_skip);
    }
    tmp54 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp51});
    tmp55 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch57__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch57__label);
    tmp56 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp54}, TNode<Object>{tmp55}, TNode<Object>{tmp48}, TNode<Object>{tmp10});
    }
    if (catch57__label.is_used()) {
      compiler::CodeAssemblerLabel catch57_skip(&ca_);
      ca_.Goto(&catch57_skip);
      ca_.Bind(&catch57__label, &tmp58);
      ca_.Goto(&block26);
      ca_.Bind(&catch57_skip);
    }
    compiler::CodeAssemblerLabel label60(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch61__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch61__label);
    tmp59 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp56}, &label60);
    }
    if (catch61__label.is_used()) {
      compiler::CodeAssemblerLabel catch61_skip(&ca_);
      ca_.Goto(&catch61_skip);
      ca_.Bind(&catch61__label, &tmp62);
      ca_.Goto(&block31);
      ca_.Bind(&catch61_skip);
    }
    ca_.Goto(&block29);
    if (label60.is_used()) {
      ca_.Bind(&label60);
      ca_.Goto(&block30);
    }
  }

  TNode<HeapObject> tmp63;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp63 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp42, tmp63);
  }

  TNode<HeapObject> tmp64;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp64 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp47, tmp64);
  }

  TNode<HeapObject> tmp65;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp65 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp50, tmp65);
  }

  TNode<HeapObject> tmp66;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp66 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp14, tmp21, tmp53, tmp66);
  }

  TNode<HeapObject> tmp67;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp67 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp14, tmp21, tmp58, tmp67);
  }

  TNode<HeapObject> tmp68;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp68 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp14, tmp21, tmp62, tmp68);
  }

      TNode<Object> tmp70;
  if (block30.is_used()) {
    ca_.Bind(&block30);
    compiler::CodeAssemblerExceptionHandlerLabel catch69__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch69__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, kFlatMapMethodName_0(state_));
    }
    if (catch69__label.is_used()) {
      compiler::CodeAssemblerLabel catch69_skip(&ca_);
      ca_.Bind(&catch69__label, &tmp70);
      ca_.Goto(&block32);
    }
  }

  TNode<JSReceiver> tmp71;
  TNode<Object> tmp72;
      TNode<Object> tmp74;
  TNode<IntPtrT> tmp75;
      TNode<Object> tmp77;
  TNode<IntPtrT> tmp78;
      TNode<Object> tmp80;
  TNode<IntPtrT> tmp81;
      TNode<Object> tmp83;
  TNode<IntPtrT> tmp84;
      TNode<Object> tmp86;
  TNode<True> tmp87;
  TNode<IntPtrT> tmp88;
      TNode<Object> tmp90;
  TNode<Number> tmp91;
      TNode<Object> tmp93;
  TNode<Number> tmp94;
      TNode<Object> tmp96;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    compiler::CodeAssemblerExceptionHandlerLabel catch73__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch73__label);
    std::tie(tmp71, tmp72) = GetIteratorFlattenable_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{tmp59}).Flatten();
    }
    if (catch73__label.is_used()) {
      compiler::CodeAssemblerLabel catch73_skip(&ca_);
      ca_.Goto(&catch73_skip);
      ca_.Bind(&catch73__label, &tmp74);
      ca_.Goto(&block33);
      ca_.Bind(&catch73_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch76__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch76__label);
    tmp75 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    }
    if (catch76__label.is_used()) {
      compiler::CodeAssemblerLabel catch76_skip(&ca_);
      ca_.Goto(&catch76_skip);
      ca_.Bind(&catch76__label, &tmp77);
      ca_.Goto(&block34);
      ca_.Bind(&catch76_skip);
    }
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp75}, tmp71);
    compiler::CodeAssemblerExceptionHandlerLabel catch79__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch79__label);
    tmp78 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    }
    if (catch79__label.is_used()) {
      compiler::CodeAssemblerLabel catch79_skip(&ca_);
      ca_.Goto(&catch79_skip);
      ca_.Bind(&catch79__label, &tmp80);
      ca_.Goto(&block35);
      ca_.Bind(&catch79_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch82__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch82__label);
    tmp81 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp75}, TNode<IntPtrT>{tmp78});
    }
    if (catch82__label.is_used()) {
      compiler::CodeAssemblerLabel catch82_skip(&ca_);
      ca_.Goto(&catch82_skip);
      ca_.Bind(&catch82__label, &tmp83);
      ca_.Goto(&block36);
      ca_.Bind(&catch82_skip);
    }
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{parameter1, tmp81}, tmp72);
    compiler::CodeAssemblerExceptionHandlerLabel catch85__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch85__label);
    tmp84 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
    }
    if (catch85__label.is_used()) {
      compiler::CodeAssemblerLabel catch85_skip(&ca_);
      ca_.Goto(&catch85_skip);
      ca_.Bind(&catch85__label, &tmp86);
      ca_.Goto(&block37);
      ca_.Bind(&catch85_skip);
    }
    tmp87 = True_0(state_);
    CodeStubAssembler(state_).StoreReference<Boolean>(CodeStubAssembler::Reference{parameter1, tmp84}, tmp87);
    compiler::CodeAssemblerExceptionHandlerLabel catch89__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch89__label);
    tmp88 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    }
    if (catch89__label.is_used()) {
      compiler::CodeAssemblerLabel catch89_skip(&ca_);
      ca_.Goto(&catch89_skip);
      ca_.Bind(&catch89__label, &tmp90);
      ca_.Goto(&block40);
      ca_.Bind(&catch89_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch92__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch92__label);
    tmp91 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch92__label.is_used()) {
      compiler::CodeAssemblerLabel catch92_skip(&ca_);
      ca_.Goto(&catch92_skip);
      ca_.Bind(&catch92__label, &tmp93);
      ca_.Goto(&block41);
      ca_.Bind(&catch92_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch95__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch95__label);
    tmp94 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp10}, TNode<Number>{tmp91});
    }
    if (catch95__label.is_used()) {
      compiler::CodeAssemblerLabel catch95_skip(&ca_);
      ca_.Goto(&catch95_skip);
      ca_.Bind(&catch95__label, &tmp96);
      ca_.Goto(&block42);
      ca_.Bind(&catch95_skip);
    }
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp88}, tmp94);
    ca_.Goto(&block12, tmp71, tmp72);
  }

  TNode<HeapObject> tmp97;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp97 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp14, tmp21, tmp70, tmp97);
  }

  TNode<HeapObject> tmp98;
  if (block33.is_used()) {
    ca_.Bind(&block33);
    tmp98 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp14, tmp21, tmp74, tmp98);
  }

  TNode<HeapObject> tmp99;
  if (block34.is_used()) {
    ca_.Bind(&block34);
    tmp99 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp71, tmp72, tmp77, tmp99);
  }

  TNode<HeapObject> tmp100;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    tmp100 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp71, tmp72, tmp80, tmp100);
  }

  TNode<HeapObject> tmp101;
  if (block36.is_used()) {
    ca_.Bind(&block36);
    tmp101 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp71, tmp72, tmp83, tmp101);
  }

  TNode<HeapObject> tmp102;
  if (block37.is_used()) {
    ca_.Bind(&block37);
    tmp102 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp71, tmp72, tmp86, tmp102);
  }

  TNode<JSReceiver> phi_bb24_6;
  TNode<Object> phi_bb24_7;
  TNode<Object> phi_bb24_10;
  TNode<HeapObject> phi_bb24_11;
      TNode<Object> tmp104;
      TNode<Object> tmp106;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_6, &phi_bb24_7, &phi_bb24_10, &phi_bb24_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch103__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch103__label);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch103__label.is_used()) {
      compiler::CodeAssemblerLabel catch103_skip(&ca_);
      ca_.Goto(&catch103_skip);
      ca_.Bind(&catch103__label, &tmp104);
      ca_.Goto(&block38, phi_bb24_6, phi_bb24_7);
      ca_.Bind(&catch103_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch105__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch105__label);
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb24_10, phi_bb24_11);
    CodeStubAssembler(state_).Unreachable();
    }
    if (catch105__label.is_used()) {
      compiler::CodeAssemblerLabel catch105_skip(&ca_);
      ca_.Bind(&catch105__label, &tmp106);
      ca_.Goto(&block39, phi_bb24_6, phi_bb24_7);
    }
  }

  TNode<JSReceiver> phi_bb38_6;
  TNode<Object> phi_bb38_7;
  TNode<HeapObject> tmp107;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_6, &phi_bb38_7);
    tmp107 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp104, tmp107);
  }

  TNode<JSReceiver> phi_bb39_6;
  TNode<Object> phi_bb39_7;
  TNode<HeapObject> tmp108;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_6, &phi_bb39_7);
    tmp108 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp106, tmp108);
  }

  TNode<HeapObject> tmp109;
  if (block40.is_used()) {
    ca_.Bind(&block40);
    tmp109 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp90, tmp109);
  }

  TNode<HeapObject> tmp110;
  if (block41.is_used()) {
    ca_.Bind(&block41);
    tmp110 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp93, tmp110);
  }

  TNode<HeapObject> tmp111;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    tmp111 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp96, tmp111);
  }

  TNode<JSReceiver> phi_bb12_6;
  TNode<Object> phi_bb12_7;
  TNode<JSReceiver> tmp112;
      TNode<Object> tmp115;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_6, &phi_bb12_7);
    compiler::CodeAssemblerLabel label113(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch114__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch114__label);
    tmp112 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{phi_bb12_6}, TNode<Object>{phi_bb12_7}}, TNode<Map>{tmp0}, &label113);
    }
    if (catch114__label.is_used()) {
      compiler::CodeAssemblerLabel catch114_skip(&ca_);
      ca_.Goto(&catch114_skip);
      ca_.Bind(&catch114__label, &tmp115);
      ca_.Goto(&block49, phi_bb12_6, phi_bb12_7, phi_bb12_6, phi_bb12_7);
      ca_.Bind(&catch114_skip);
    }
    ca_.Goto(&block47, phi_bb12_6, phi_bb12_7, phi_bb12_6, phi_bb12_7);
    if (label113.is_used()) {
      ca_.Bind(&label113);
      ca_.Goto(&block48, phi_bb12_6, phi_bb12_7, phi_bb12_6, phi_bb12_7);
    }
  }

  TNode<JSReceiver> phi_bb49_6;
  TNode<Object> phi_bb49_7;
  TNode<JSReceiver> phi_bb49_9;
  TNode<Object> phi_bb49_10;
  TNode<HeapObject> tmp116;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_6, &phi_bb49_7, &phi_bb49_9, &phi_bb49_10);
    tmp116 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block46, phi_bb49_6, phi_bb49_7, tmp115, tmp116);
  }

  TNode<JSReceiver> phi_bb48_6;
  TNode<Object> phi_bb48_7;
  TNode<JSReceiver> phi_bb48_9;
  TNode<Object> phi_bb48_10;
  TNode<IntPtrT> tmp117;
      TNode<Object> tmp119;
  TNode<False> tmp120;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_6, &phi_bb48_7, &phi_bb48_9, &phi_bb48_10);
    compiler::CodeAssemblerExceptionHandlerLabel catch118__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch118__label);
    tmp117 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
    }
    if (catch118__label.is_used()) {
      compiler::CodeAssemblerLabel catch118_skip(&ca_);
      ca_.Goto(&catch118_skip);
      ca_.Bind(&catch118__label, &tmp119);
      ca_.Goto(&block55, phi_bb48_6, phi_bb48_7);
      ca_.Bind(&catch118_skip);
    }
    tmp120 = False_0(state_);
    CodeStubAssembler(state_).StoreReference<Boolean>(CodeStubAssembler::Reference{parameter1, tmp117}, tmp120);
    ca_.Goto(&block5);
  }

  TNode<JSReceiver> phi_bb47_6;
  TNode<Object> phi_bb47_7;
  TNode<JSReceiver> phi_bb47_9;
  TNode<Object> phi_bb47_10;
  TNode<Object> tmp121;
      TNode<Object> tmp123;
      TNode<Object> tmp125;
  TNode<False> tmp126;
  TNode<JSObject> tmp127;
      TNode<Object> tmp129;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_6, &phi_bb47_7, &phi_bb47_9, &phi_bb47_10);
    compiler::CodeAssemblerExceptionHandlerLabel catch122__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch122__label);
    tmp121 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp112}, TNode<Map>{tmp0});
    }
    if (catch122__label.is_used()) {
      compiler::CodeAssemblerLabel catch122_skip(&ca_);
      ca_.Goto(&catch122_skip);
      ca_.Bind(&catch122__label, &tmp123);
      ca_.Goto(&block50, phi_bb47_6, phi_bb47_7);
      ca_.Bind(&catch122_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch124__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch124__label);
    MarkIteratorHelperAsFinishedExecuting_0(state_, TNode<JSIteratorHelper>{parameter1}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch124__label.is_used()) {
      compiler::CodeAssemblerLabel catch124_skip(&ca_);
      ca_.Goto(&catch124_skip);
      ca_.Bind(&catch124__label, &tmp125);
      ca_.Goto(&block51, phi_bb47_6, phi_bb47_7);
      ca_.Bind(&catch124_skip);
    }
    tmp126 = False_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch128__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch128__label);
    tmp127 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp121}, TNode<Boolean>{tmp126});
    }
    if (catch128__label.is_used()) {
      compiler::CodeAssemblerLabel catch128_skip(&ca_);
      ca_.Goto(&catch128_skip);
      ca_.Bind(&catch128__label, &tmp129);
      ca_.Goto(&block52, phi_bb47_6, phi_bb47_7);
      ca_.Bind(&catch128_skip);
    }
    CodeStubAssembler(state_).Return(tmp127);
  }

  TNode<JSReceiver> phi_bb50_6;
  TNode<Object> phi_bb50_7;
  TNode<HeapObject> tmp130;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_6, &phi_bb50_7);
    tmp130 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block46, phi_bb50_6, phi_bb50_7, tmp123, tmp130);
  }

  TNode<JSReceiver> phi_bb51_6;
  TNode<Object> phi_bb51_7;
  TNode<HeapObject> tmp131;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_6, &phi_bb51_7);
    tmp131 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block46, phi_bb51_6, phi_bb51_7, tmp125, tmp131);
  }

  TNode<JSReceiver> phi_bb52_6;
  TNode<Object> phi_bb52_7;
  TNode<HeapObject> tmp132;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_6, &phi_bb52_7);
    tmp132 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block46, phi_bb52_6, phi_bb52_7, tmp129, tmp132);
  }

  TNode<JSReceiver> phi_bb46_6;
  TNode<Object> phi_bb46_7;
  TNode<Object> phi_bb46_8;
  TNode<HeapObject> phi_bb46_9;
      TNode<Object> tmp134;
      TNode<Object> tmp136;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_6, &phi_bb46_7, &phi_bb46_8, &phi_bb46_9);
    compiler::CodeAssemblerExceptionHandlerLabel catch133__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch133__label);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    }
    if (catch133__label.is_used()) {
      compiler::CodeAssemblerLabel catch133_skip(&ca_);
      ca_.Goto(&catch133_skip);
      ca_.Bind(&catch133__label, &tmp134);
      ca_.Goto(&block53, phi_bb46_6, phi_bb46_7, phi_bb46_8, phi_bb46_9);
      ca_.Bind(&catch133_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch135__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch135__label);
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb46_8, phi_bb46_9);
    CodeStubAssembler(state_).Unreachable();
    }
    if (catch135__label.is_used()) {
      compiler::CodeAssemblerLabel catch135_skip(&ca_);
      ca_.Bind(&catch135__label, &tmp136);
      ca_.Goto(&block54, phi_bb46_6, phi_bb46_7, phi_bb46_8, phi_bb46_9, phi_bb46_8, phi_bb46_9);
    }
  }

  TNode<JSReceiver> phi_bb53_6;
  TNode<Object> phi_bb53_7;
  TNode<Object> phi_bb53_8;
  TNode<HeapObject> phi_bb53_9;
  TNode<HeapObject> tmp137;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_6, &phi_bb53_7, &phi_bb53_8, &phi_bb53_9);
    tmp137 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp134, tmp137);
  }

  TNode<JSReceiver> phi_bb54_6;
  TNode<Object> phi_bb54_7;
  TNode<Object> phi_bb54_8;
  TNode<HeapObject> phi_bb54_9;
  TNode<Object> phi_bb54_11;
  TNode<HeapObject> phi_bb54_12;
  TNode<HeapObject> tmp138;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_6, &phi_bb54_7, &phi_bb54_8, &phi_bb54_9, &phi_bb54_11, &phi_bb54_12);
    tmp138 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp136, tmp138);
  }

  TNode<JSReceiver> phi_bb55_6;
  TNode<Object> phi_bb55_7;
  TNode<HeapObject> tmp139;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_6, &phi_bb55_7);
    tmp139 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block2, tmp119, tmp139);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> phi_bb2_5;
  TNode<HeapObject> phi_bb2_6;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5, &phi_bb2_6);
    MarkIteratorHelperAsExhausted_0(state_, TNode<JSIteratorHelper>{parameter1});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb2_5, phi_bb2_6);
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(IteratorPrototypeReduce, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Number> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Number> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Number> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Number> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Number, Object, Number> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Number, Object, HeapObject> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Number> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.reduce");
  }

  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<JSReceiver> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp2});
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp3}, &label5);
    ca_.Goto(&block7);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block8);
    }
  }

  TNode<Object> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp6 = FromConstexpr_JSAny_constexpr_string_0(state_, "Iterator.prototype.reduce");
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp6);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSReceiver> tmp7;
  TNode<Object> tmp8;
  TNode<Map> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<BoolT> tmp11;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp7, tmp8) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp9 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    tmp10 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp11 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp10});
    ca_.Branch(tmp11, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<JSReceiver> tmp12;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    compiler::CodeAssemblerLabel label13(&ca_);
    tmp12 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp7}, TNode<Object>{tmp8}}, TNode<Map>{tmp9}, &label13);
    ca_.Goto(&block14);
    if (label13.is_used()) {
      ca_.Bind(&label13);
      ca_.Goto(&block15);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIteratorReduceNoInitial, "Iterator.prototype.reduce");
  }

  TNode<Object> tmp14;
  TNode<Number> tmp15;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp14 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp12}, TNode<Map>{tmp9});
    tmp15 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    ca_.Goto(&block11, tmp12, tmp14, tmp15);
  }

  TNode<IntPtrT> tmp16;
  TNode<Object> tmp17;
  TNode<Number> tmp18;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp16 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp17 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block11, ca_.Uninitialized<JSReceiver>(), tmp17, tmp18);
  }

  TNode<JSReceiver> phi_bb11_11;
  TNode<Object> phi_bb11_12;
  TNode<Number> phi_bb11_13;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_11, &phi_bb11_12, &phi_bb11_13);
    ca_.Goto(&block18, phi_bb11_11, phi_bb11_12, phi_bb11_13);
  }

  TNode<JSReceiver> phi_bb18_11;
  TNode<Object> phi_bb18_12;
  TNode<Number> phi_bb18_13;
  TNode<BoolT> tmp19;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_11, &phi_bb18_12, &phi_bb18_13);
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp19, &block16, std::vector<compiler::Node*>{phi_bb18_11, phi_bb18_12, phi_bb18_13}, &block17, std::vector<compiler::Node*>{phi_bb18_11, phi_bb18_12, phi_bb18_13});
  }

  TNode<JSReceiver> phi_bb16_11;
  TNode<Object> phi_bb16_12;
  TNode<Number> phi_bb16_13;
  TNode<JSReceiver> tmp20;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_11, &phi_bb16_12, &phi_bb16_13);
    compiler::CodeAssemblerLabel label21(&ca_);
    tmp20 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp7}, TNode<Object>{tmp8}}, TNode<Map>{tmp9}, &label21);
    ca_.Goto(&block21, phi_bb16_11, phi_bb16_12, phi_bb16_13);
    if (label21.is_used()) {
      ca_.Bind(&label21);
      ca_.Goto(&block22, phi_bb16_11, phi_bb16_12, phi_bb16_13);
    }
  }

  TNode<JSReceiver> phi_bb22_11;
  TNode<Object> phi_bb22_12;
  TNode<Number> phi_bb22_13;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_11, &phi_bb22_12, &phi_bb22_13);
    arguments.PopAndReturn(phi_bb22_12);
  }

  TNode<JSReceiver> phi_bb21_11;
  TNode<Object> phi_bb21_12;
  TNode<Number> phi_bb21_13;
  TNode<Object> tmp22;
  TNode<Undefined> tmp23;
  TNode<Object> tmp24;
      TNode<Object> tmp26;
  TNode<Number> tmp27;
      TNode<Object> tmp29;
  TNode<Number> tmp30;
      TNode<Object> tmp32;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_11, &phi_bb21_12, &phi_bb21_13);
    tmp22 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp20}, TNode<Map>{tmp9});
    tmp23 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch25__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch25__label);
    tmp24 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp4}, TNode<Object>{tmp23}, TNode<Object>{phi_bb21_12}, TNode<Object>{tmp22}, TNode<Object>{phi_bb21_13});
    }
    if (catch25__label.is_used()) {
      compiler::CodeAssemblerLabel catch25_skip(&ca_);
      ca_.Goto(&catch25_skip);
      ca_.Bind(&catch25__label, &tmp26);
      ca_.Goto(&block25, phi_bb21_12, phi_bb21_13, phi_bb21_12, phi_bb21_13);
      ca_.Bind(&catch25_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch28__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch28__label);
    tmp27 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch28__label.is_used()) {
      compiler::CodeAssemblerLabel catch28_skip(&ca_);
      ca_.Goto(&catch28_skip);
      ca_.Bind(&catch28__label, &tmp29);
      ca_.Goto(&block26, phi_bb21_13, phi_bb21_13, phi_bb21_13);
      ca_.Bind(&catch28_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch31__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch31__label);
    tmp30 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb21_13}, TNode<Number>{tmp27});
    }
    if (catch31__label.is_used()) {
      compiler::CodeAssemblerLabel catch31_skip(&ca_);
      ca_.Goto(&catch31_skip);
      ca_.Bind(&catch31__label, &tmp32);
      ca_.Goto(&block27, phi_bb21_13, phi_bb21_13);
      ca_.Bind(&catch31_skip);
    }
    ca_.Goto(&block18, tmp20, tmp24, tmp30);
  }

  TNode<Object> phi_bb25_12;
  TNode<Number> phi_bb25_13;
  TNode<Object> phi_bb25_18;
  TNode<Number> phi_bb25_20;
  TNode<HeapObject> tmp33;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_12, &phi_bb25_13, &phi_bb25_18, &phi_bb25_20);
    tmp33 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, phi_bb25_12, phi_bb25_13, tmp26, tmp33);
  }

  TNode<Number> phi_bb26_13;
  TNode<Number> phi_bb26_16;
  TNode<Number> phi_bb26_17;
  TNode<HeapObject> tmp34;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_13, &phi_bb26_16, &phi_bb26_17);
    tmp34 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp24, phi_bb26_13, tmp29, tmp34);
  }

  TNode<Number> phi_bb27_13;
  TNode<Number> phi_bb27_16;
  TNode<HeapObject> tmp35;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_13, &phi_bb27_16);
    tmp35 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block24, tmp24, phi_bb27_13, tmp32, tmp35);
  }

  TNode<Object> phi_bb24_12;
  TNode<Number> phi_bb24_13;
  TNode<Object> phi_bb24_15;
  TNode<HeapObject> phi_bb24_16;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_12, &phi_bb24_13, &phi_bb24_15, &phi_bb24_16);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp7}, TNode<Object>{tmp8}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb24_15, phi_bb24_16);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSReceiver> phi_bb17_11;
  TNode<Object> phi_bb17_12;
  TNode<Number> phi_bb17_13;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_11, &phi_bb17_12, &phi_bb17_13);
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(IteratorPrototypeToArray, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSReceiver> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSReceiver> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSReceiver> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.toArray");
  }

  TNode<JSReceiver> tmp2;
  TNode<Object> tmp3;
  TNode<FixedArray> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Map> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    std::tie(tmp2, tmp3) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    std::tie(tmp4, tmp5, tmp6) = NewGrowableFixedArray_0(state_).Flatten();
    tmp7 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    ca_.Goto(&block7, tmp4, tmp5, tmp6, ca_.Uninitialized<JSReceiver>());
  }

  TNode<FixedArray> phi_bb7_5;
  TNode<IntPtrT> phi_bb7_6;
  TNode<IntPtrT> phi_bb7_7;
  TNode<JSReceiver> phi_bb7_9;
  TNode<BoolT> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5, &phi_bb7_6, &phi_bb7_7, &phi_bb7_9);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp8, &block5, std::vector<compiler::Node*>{phi_bb7_5, phi_bb7_6, phi_bb7_7, phi_bb7_9}, &block6, std::vector<compiler::Node*>{phi_bb7_5, phi_bb7_6, phi_bb7_7, phi_bb7_9});
  }

  TNode<FixedArray> phi_bb5_5;
  TNode<IntPtrT> phi_bb5_6;
  TNode<IntPtrT> phi_bb5_7;
  TNode<JSReceiver> phi_bb5_9;
  TNode<JSReceiver> tmp9;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5, &phi_bb5_6, &phi_bb5_7, &phi_bb5_9);
    compiler::CodeAssemblerLabel label10(&ca_);
    tmp9 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp3}}, TNode<Map>{tmp7}, &label10);
    ca_.Goto(&block10, phi_bb5_5, phi_bb5_6, phi_bb5_7, phi_bb5_9);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block11, phi_bb5_5, phi_bb5_6, phi_bb5_7, phi_bb5_9);
    }
  }

  TNode<FixedArray> phi_bb11_5;
  TNode<IntPtrT> phi_bb11_6;
  TNode<IntPtrT> phi_bb11_7;
  TNode<JSReceiver> phi_bb11_9;
  TNode<NativeContext> tmp11;
  TNode<Map> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Hole> tmp14;
  TNode<FixedArray> tmp15;
  TNode<Smi> tmp16;
  TNode<JSArray> tmp17;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_5, &phi_bb11_6, &phi_bb11_7, &phi_bb11_9);
    tmp11 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp12 = CodeStubAssembler(state_).LoadJSArrayElementsMap(ElementsKind::PACKED_ELEMENTS, TNode<NativeContext>{tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = TheHole_0(state_);
    tmp15 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb11_5}, TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{phi_bb11_7}, TNode<IntPtrT>{phi_bb11_7}, TNode<Hole>{tmp14});
    tmp16 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{phi_bb11_7});
    tmp17 = CodeStubAssembler(state_).AllocateJSArray(TNode<Map>{tmp12}, TNode<FixedArrayBase>{tmp15}, TNode<Smi>{tmp16});
    CodeStubAssembler(state_).Return(tmp17);
  }

  TNode<FixedArray> phi_bb10_5;
  TNode<IntPtrT> phi_bb10_6;
  TNode<IntPtrT> phi_bb10_7;
  TNode<JSReceiver> phi_bb10_9;
  TNode<Object> tmp18;
  TNode<BoolT> tmp19;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5, &phi_bb10_6, &phi_bb10_7, &phi_bb10_9);
    tmp18 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp9}, TNode<Map>{tmp7});
    tmp19 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb10_6}, TNode<IntPtrT>{phi_bb10_7});
    ca_.Branch(tmp19, &block32, std::vector<compiler::Node*>{phi_bb10_5, phi_bb10_6, phi_bb10_7}, &block33, std::vector<compiler::Node*>{phi_bb10_5, phi_bb10_6, phi_bb10_7});
  }

  TNode<FixedArray> phi_bb32_5;
  TNode<IntPtrT> phi_bb32_6;
  TNode<IntPtrT> phi_bb32_7;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Hole> tmp26;
  TNode<FixedArray> tmp27;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_5, &phi_bb32_6, &phi_bb32_7);
    tmp20 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp21 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT>{phi_bb32_6}, TNode<IntPtrT>{tmp20});
    tmp22 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb32_6}, TNode<IntPtrT>{tmp21});
    tmp23 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x10ull));
    tmp24 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23});
    tmp25 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp26 = TheHole_0(state_);
    tmp27 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb32_5}, TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{phi_bb32_7}, TNode<IntPtrT>{tmp24}, TNode<Hole>{tmp26});
    ca_.Goto(&block33, tmp27, tmp24, phi_bb32_7);
  }

  TNode<FixedArray> phi_bb33_5;
  TNode<IntPtrT> phi_bb33_6;
  TNode<IntPtrT> phi_bb33_7;
  TNode<Object> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<UintPtrT> tmp33;
  TNode<UintPtrT> tmp34;
  TNode<BoolT> tmp35;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_5, &phi_bb33_6, &phi_bb33_7);
    std::tie(tmp28, tmp29, tmp30) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{phi_bb33_5}).Flatten();
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp32 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb33_7}, TNode<IntPtrT>{tmp31});
    tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb33_7});
    tmp34 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp30});
    tmp35 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp33}, TNode<UintPtrT>{tmp34});
    ca_.Branch(tmp35, &block51, std::vector<compiler::Node*>{phi_bb33_7, phi_bb33_7, phi_bb33_7, phi_bb33_7}, &block52, std::vector<compiler::Node*>{phi_bb33_7, phi_bb33_7, phi_bb33_7, phi_bb33_7});
  }

  TNode<IntPtrT> phi_bb51_17;
  TNode<IntPtrT> phi_bb51_18;
  TNode<IntPtrT> phi_bb51_22;
  TNode<IntPtrT> phi_bb51_23;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<Object> tmp38;
  TNode<IntPtrT> tmp39;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_17, &phi_bb51_18, &phi_bb51_22, &phi_bb51_23);
    tmp36 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb51_23});
    tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp36});
    std::tie(tmp38, tmp39) = NewReference_Object_0(state_, TNode<Object>{tmp28}, TNode<IntPtrT>{tmp37}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp38, tmp39}, tmp18);
    ca_.Goto(&block7, phi_bb33_5, phi_bb33_6, tmp32, tmp9);
  }

  TNode<IntPtrT> phi_bb52_17;
  TNode<IntPtrT> phi_bb52_18;
  TNode<IntPtrT> phi_bb52_22;
  TNode<IntPtrT> phi_bb52_23;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_17, &phi_bb52_18, &phi_bb52_22, &phi_bb52_23);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<FixedArray> phi_bb6_5;
  TNode<IntPtrT> phi_bb6_6;
  TNode<IntPtrT> phi_bb6_7;
  TNode<JSReceiver> phi_bb6_9;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5, &phi_bb6_6, &phi_bb6_7, &phi_bb6_9);
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(IteratorPrototypeForEach, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kFn);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Object, HeapObject> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.forEach");
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<Object> tmp4;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = FromConstexpr_JSAny_constexpr_string_0(state_, "Iterator.prototype.forEach");
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp4);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSReceiver> tmp5;
  TNode<Object> tmp6;
  TNode<Number> tmp7;
  TNode<Map> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp5, tmp6) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    ca_.Goto(&block11, tmp7);
  }

  TNode<Number> phi_bb11_7;
  TNode<BoolT> tmp9;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_7);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp9, &block9, std::vector<compiler::Node*>{phi_bb11_7}, &block10, std::vector<compiler::Node*>{phi_bb11_7});
  }

  TNode<Number> phi_bb9_7;
  TNode<JSReceiver> tmp10;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_7);
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}}, TNode<Map>{tmp8}, &label11);
    ca_.Goto(&block14, phi_bb9_7);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block15, phi_bb9_7);
    }
  }

  TNode<Number> phi_bb15_7;
  TNode<Undefined> tmp12;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_7);
    tmp12 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<Number> phi_bb14_7;
  TNode<Object> tmp13;
  TNode<Undefined> tmp14;
  TNode<Object> tmp15;
      TNode<Object> tmp17;
  TNode<Number> tmp18;
      TNode<Object> tmp20;
  TNode<Number> tmp21;
      TNode<Object> tmp23;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_7);
    tmp13 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp10}, TNode<Map>{tmp8});
    tmp14 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    tmp15 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp2}, TNode<Object>{tmp14}, TNode<Object>{tmp13}, TNode<Object>{phi_bb14_7});
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block18, phi_bb14_7, phi_bb14_7);
      ca_.Bind(&catch16_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch19__label);
    tmp18 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      ca_.Bind(&catch19__label, &tmp20);
      ca_.Goto(&block19, phi_bb14_7, phi_bb14_7, phi_bb14_7);
      ca_.Bind(&catch19_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch22__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch22__label);
    tmp21 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb14_7}, TNode<Number>{tmp18});
    }
    if (catch22__label.is_used()) {
      compiler::CodeAssemblerLabel catch22_skip(&ca_);
      ca_.Goto(&catch22_skip);
      ca_.Bind(&catch22__label, &tmp23);
      ca_.Goto(&block20, phi_bb14_7, phi_bb14_7);
      ca_.Bind(&catch22_skip);
    }
    ca_.Goto(&block11, tmp21);
  }

  TNode<Number> phi_bb18_7;
  TNode<Number> phi_bb18_15;
  TNode<HeapObject> tmp24;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_7, &phi_bb18_15);
    tmp24 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, phi_bb18_7, tmp17, tmp24);
  }

  TNode<Number> phi_bb19_7;
  TNode<Number> phi_bb19_11;
  TNode<Number> phi_bb19_12;
  TNode<HeapObject> tmp25;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_7, &phi_bb19_11, &phi_bb19_12);
    tmp25 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, phi_bb19_7, tmp20, tmp25);
  }

  TNode<Number> phi_bb20_7;
  TNode<Number> phi_bb20_11;
  TNode<HeapObject> tmp26;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_7, &phi_bb20_11);
    tmp26 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block17, phi_bb20_7, tmp23, tmp26);
  }

  TNode<Number> phi_bb17_7;
  TNode<Object> phi_bb17_11;
  TNode<HeapObject> phi_bb17_12;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_7, &phi_bb17_11, &phi_bb17_12);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb17_11, phi_bb17_12);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Number> phi_bb10_7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_7);
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(IteratorPrototypeSome, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kPredicate);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.some");
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<Object> tmp4;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = FromConstexpr_JSAny_constexpr_string_0(state_, "Iterator.prototype.some");
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp4);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSReceiver> tmp5;
  TNode<Object> tmp6;
  TNode<Number> tmp7;
  TNode<Map> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp5, tmp6) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    ca_.Goto(&block11, tmp7);
  }

  TNode<Number> phi_bb11_7;
  TNode<BoolT> tmp9;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_7);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp9, &block9, std::vector<compiler::Node*>{phi_bb11_7}, &block10, std::vector<compiler::Node*>{phi_bb11_7});
  }

  TNode<Number> phi_bb9_7;
  TNode<JSReceiver> tmp10;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_7);
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}}, TNode<Map>{tmp8}, &label11);
    ca_.Goto(&block14, phi_bb9_7);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block15, phi_bb9_7);
    }
  }

  TNode<Number> phi_bb15_7;
  TNode<False> tmp12;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_7);
    tmp12 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<Number> phi_bb14_7;
  TNode<Object> tmp13;
  TNode<Undefined> tmp14;
  TNode<Object> tmp15;
      TNode<Object> tmp17;
  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  TNode<BoolT> tmp20;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_7);
    tmp13 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp10}, TNode<Map>{tmp8});
    tmp14 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    tmp15 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp2}, TNode<Object>{tmp14}, TNode<Object>{tmp13}, TNode<Object>{phi_bb14_7});
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block18, phi_bb14_7, phi_bb14_7);
      ca_.Bind(&catch16_skip);
    }
    tmp18 = ToBoolean_0(state_, TNode<Object>{tmp15});
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp20 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp18}, TNode<BoolT>{tmp19});
    ca_.Branch(tmp20, &block19, std::vector<compiler::Node*>{phi_bb14_7}, &block20, std::vector<compiler::Node*>{phi_bb14_7});
  }

  TNode<Number> phi_bb18_7;
  TNode<Number> phi_bb18_16;
  TNode<HeapObject> tmp21;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_7, &phi_bb18_16);
    tmp21 = GetAndResetPendingMessage_0(state_);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, tmp17, tmp21);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Number> phi_bb19_7;
  TNode<True> tmp22;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_7);
    IteratorClose_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}});
    tmp22 = True_0(state_);
    CodeStubAssembler(state_).Return(tmp22);
  }

  TNode<Number> phi_bb20_7;
  TNode<Number> tmp23;
  TNode<Number> tmp24;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_7);
    tmp23 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp24 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb20_7}, TNode<Number>{tmp23});
    ca_.Goto(&block11, tmp24);
  }

  TNode<Number> phi_bb10_7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_7);
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(IteratorPrototypeEvery, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kPredicate);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.every");
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<Object> tmp4;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = FromConstexpr_JSAny_constexpr_string_0(state_, "Iterator.prototype.every");
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp4);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSReceiver> tmp5;
  TNode<Object> tmp6;
  TNode<Number> tmp7;
  TNode<Map> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp5, tmp6) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    ca_.Goto(&block11, tmp7);
  }

  TNode<Number> phi_bb11_7;
  TNode<BoolT> tmp9;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_7);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp9, &block9, std::vector<compiler::Node*>{phi_bb11_7}, &block10, std::vector<compiler::Node*>{phi_bb11_7});
  }

  TNode<Number> phi_bb9_7;
  TNode<JSReceiver> tmp10;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_7);
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}}, TNode<Map>{tmp8}, &label11);
    ca_.Goto(&block14, phi_bb9_7);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block15, phi_bb9_7);
    }
  }

  TNode<Number> phi_bb15_7;
  TNode<True> tmp12;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_7);
    tmp12 = True_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<Number> phi_bb14_7;
  TNode<Object> tmp13;
  TNode<Undefined> tmp14;
  TNode<Object> tmp15;
      TNode<Object> tmp17;
  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  TNode<BoolT> tmp20;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_7);
    tmp13 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp10}, TNode<Map>{tmp8});
    tmp14 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    tmp15 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp2}, TNode<Object>{tmp14}, TNode<Object>{tmp13}, TNode<Object>{phi_bb14_7});
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block18, phi_bb14_7, phi_bb14_7);
      ca_.Bind(&catch16_skip);
    }
    tmp18 = ToBoolean_0(state_, TNode<Object>{tmp15});
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp20 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp18}, TNode<BoolT>{tmp19});
    ca_.Branch(tmp20, &block19, std::vector<compiler::Node*>{phi_bb14_7}, &block20, std::vector<compiler::Node*>{phi_bb14_7});
  }

  TNode<Number> phi_bb18_7;
  TNode<Number> phi_bb18_16;
  TNode<HeapObject> tmp21;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_7, &phi_bb18_16);
    tmp21 = GetAndResetPendingMessage_0(state_);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, tmp17, tmp21);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Number> phi_bb19_7;
  TNode<False> tmp22;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_7);
    IteratorClose_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}});
    tmp22 = False_0(state_);
    CodeStubAssembler(state_).Return(tmp22);
  }

  TNode<Number> phi_bb20_7;
  TNode<Number> tmp23;
  TNode<Number> tmp24;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_7);
    tmp23 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp24 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb20_7}, TNode<Number>{tmp23});
    ca_.Goto(&block11, tmp24);
  }

  TNode<Number> phi_bb10_7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_7);
    CodeStubAssembler(state_).Unreachable();
  }
}

TF_BUILTIN(IteratorPrototypeFind, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kPredicate);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.find");
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<Object> tmp4;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = FromConstexpr_JSAny_constexpr_string_0(state_, "Iterator.prototype.find");
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp4);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSReceiver> tmp5;
  TNode<Object> tmp6;
  TNode<Number> tmp7;
  TNode<Map> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp5, tmp6) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp8 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    ca_.Goto(&block11, tmp7);
  }

  TNode<Number> phi_bb11_7;
  TNode<BoolT> tmp9;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_7);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp9, &block9, std::vector<compiler::Node*>{phi_bb11_7}, &block10, std::vector<compiler::Node*>{phi_bb11_7});
  }

  TNode<Number> phi_bb9_7;
  TNode<JSReceiver> tmp10;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_7);
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}}, TNode<Map>{tmp8}, &label11);
    ca_.Goto(&block14, phi_bb9_7);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block15, phi_bb9_7);
    }
  }

  TNode<Number> phi_bb15_7;
  TNode<Undefined> tmp12;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_7);
    tmp12 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<Number> phi_bb14_7;
  TNode<Object> tmp13;
  TNode<Undefined> tmp14;
  TNode<Object> tmp15;
      TNode<Object> tmp17;
  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  TNode<BoolT> tmp20;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_7);
    tmp13 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp10}, TNode<Map>{tmp8});
    tmp14 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    tmp15 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp2}, TNode<Object>{tmp14}, TNode<Object>{tmp13}, TNode<Object>{phi_bb14_7});
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block18, phi_bb14_7, phi_bb14_7);
      ca_.Bind(&catch16_skip);
    }
    tmp18 = ToBoolean_0(state_, TNode<Object>{tmp15});
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp20 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp18}, TNode<BoolT>{tmp19});
    ca_.Branch(tmp20, &block19, std::vector<compiler::Node*>{phi_bb14_7}, &block20, std::vector<compiler::Node*>{phi_bb14_7});
  }

  TNode<Number> phi_bb18_7;
  TNode<Number> phi_bb18_16;
  TNode<HeapObject> tmp21;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_7, &phi_bb18_16);
    tmp21 = GetAndResetPendingMessage_0(state_);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, tmp17, tmp21);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Number> phi_bb19_7;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_7);
    IteratorClose_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}});
    CodeStubAssembler(state_).Return(tmp13);
  }

  TNode<Number> phi_bb20_7;
  TNode<Number> tmp22;
  TNode<Number> tmp23;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_7);
    tmp22 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp23 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb20_7}, TNode<Number>{tmp22});
    ca_.Goto(&block11, tmp23);
  }

  TNode<Number> phi_bb10_7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_7);
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=76&c=18
TNode<JSIteratorHelper> Cast_JSIteratorHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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

  TNode<JSIteratorHelper> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorHelper_0(state_, TNode<HeapObject>{tmp0}, &label3);
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
  return TNode<JSIteratorHelper>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=125&c=5
TNode<JSIteratorFlatMapHelper> Cast_JSIteratorFlatMapHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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

  TNode<JSIteratorFlatMapHelper> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorFlatMapHelper_0(state_, TNode<HeapObject>{tmp0}, &label3);
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
  return TNode<JSIteratorFlatMapHelper>{tmp2};
}

} // namespace internal
} // namespace v8
