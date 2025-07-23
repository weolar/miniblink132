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
#include "torque-generated/src/builtins/typed-array-with-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-with-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-with.tq?l=6&c=1
const char* kBuiltinNameWith_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  return "%TypedArray%.prototype.with";}

TF_BUILTIN(TypedArrayPrototypeWith, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kIndex);
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValueArg);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSTypedArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSTypedArray_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block7);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kNotTypedArray, kBuiltinNameWith_0(state_));
  }

  TNode<JSTypedArray> tmp2;
  TNode<UintPtrT> tmp3;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    compiler::CodeAssemblerLabel label4(&ca_);
    std::tie(tmp2, tmp3) = EnsureAttachedAndReadLength_0(state_, TNode<JSTypedArray>{tmp0}, &label4).Flatten();
    ca_.Goto(&block9);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kDetachedOperation, kBuiltinNameWith_0(state_));
  }

  TNode<Int32T> tmp5;
  TNode<BoolT> tmp6;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp5 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp0});
    tmp6 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T>{tmp5});
    ca_.Branch(tmp6, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  TNode<BigInt> tmp7;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp7 = CodeStubAssembler(state_).ToBigInt(TNode<Context>{parameter0}, TNode<Object>{parameter3});
    ca_.Goto(&block13, tmp7);
  }

  TNode<Number> tmp8;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp8 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter3});
    ca_.Goto(&block13, tmp8);
  }

  TNode<Object> phi_bb13_8;
  TNode<Number> tmp9;
  TNode<UintPtrT> tmp10;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_8);
    tmp9 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2});
    compiler::CodeAssemblerLabel label11(&ca_);
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp10 = ConvertRelativeIndex_1(state_, TNode<Number>{tmp9}, TNode<UintPtrT>{tmp3}, &label11, &label12);
    ca_.Goto(&block14);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block15);
    }
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block16);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block6);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block6);
  }

  TNode<JSTypedArray> tmp13;
  TNode<UintPtrT> tmp14;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    compiler::CodeAssemblerLabel label15(&ca_);
    std::tie(tmp13, tmp14) = EnsureAttachedAndReadLength_0(state_, TNode<JSTypedArray>{tmp0}, &label15).Flatten();
    ca_.Goto(&block17);
    if (label15.is_used()) {
      ca_.Bind(&label15);
      ca_.Goto(&block18);
    }
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block6);
  }

  TNode<BoolT> tmp16;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp16 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT>{tmp10}, TNode<UintPtrT>{tmp14});
    ca_.Branch(tmp16, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block6);
  }

  TNode<JSTypedArray> tmp17;
  TNode<UintPtrT> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<Int32T> tmp20;
  TNode<UintPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<BoolT> tmp23;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp17 = TypedArrayCreateSameType_0(state_, TNode<Context>{parameter0}, TNode<JSTypedArray>{tmp0}, TNode<UintPtrT>{tmp3});
    tmp18 = CodeStubAssembler(state_).UintPtrMin(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp14});
    std::tie(tmp19, tmp20) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<JSTypedArray>{tmp17}).Flatten();
    tmp21 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
    tmp22 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT>{tmp21}, TNode<UintPtrT>{tmp19});
    tmp23 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp22});
    ca_.Branch(tmp23, &block24, std::vector<compiler::Node*>{}, &block25, std::vector<compiler::Node*>{});
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<UintPtrT> tmp24;
  TNode<RawPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<JSArrayBuffer> tmp27;
  TNode<BoolT> tmp28;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp24 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp19});
    tmp25 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp0});
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp27 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp0, tmp26});
    tmp28 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer>{tmp27});
    ca_.Branch(tmp28, &block26, std::vector<compiler::Node*>{}, &block27, std::vector<compiler::Node*>{});
  }

  TNode<RawPtrT> tmp29;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp29 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp17});
    TypedArrayBuiltinsAssembler(state_).CallCRelaxedMemmove(TNode<RawPtrT>{tmp29}, TNode<RawPtrT>{tmp25}, TNode<UintPtrT>{tmp24});
    ca_.Goto(&block28);
  }

  TNode<RawPtrT> tmp30;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp30 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray>{tmp17});
    TypedArrayBuiltinsAssembler(state_).CallCMemmove(TNode<RawPtrT>{tmp30}, TNode<RawPtrT>{tmp25}, TNode<UintPtrT>{tmp24});
    ca_.Goto(&block28);
  }

  TNode<Int32T> tmp31;
  TNode<BuiltinPtr> tmp32;
  TNode<BuiltinPtr> tmp33;
  TNode<BuiltinPtr> tmp34;
  TNode<Smi> tmp35;
  TNode<Smi> tmp36;
  TNode<BoolT> tmp37;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp31 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp17});
    std::tie(tmp32, tmp33, tmp34) = GetTypedArrayAccessor_0(state_, TNode<Int32T>{tmp31}).Flatten();
tmp35 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallInterfaceDescriptorFor(ExampleBuiltinForTorqueFunctionPointerType(3)), tmp34, parameter0, tmp17, tmp10, phi_bb13_8));
    tmp36 = kStoreSucceded_0(state_);
    tmp37 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp35}, TNode<Smi>{tmp36});
    ca_.Branch(tmp37, &block30, std::vector<compiler::Node*>{}, &block31, std::vector<compiler::Node*>{});
  }

  if (block31.is_used()) {
    ca_.Bind(&block31);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array.tq", 119});
      CodeStubAssembler(state_).FailAssert("Torque assert 'result == kStoreSucceded' failed", pos_stack);
    }
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    ca_.Goto(&block34, tmp18);
  }

  TNode<UintPtrT> phi_bb34_20;
  TNode<UintPtrT> tmp38;
  TNode<BoolT> tmp39;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_20);
    tmp38 = CodeStubAssembler(state_).LoadJSTypedArrayLength(TNode<JSTypedArray>{tmp17});
    tmp39 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{phi_bb34_20}, TNode<UintPtrT>{tmp38});
    ca_.Branch(tmp39, &block32, std::vector<compiler::Node*>{phi_bb34_20}, &block33, std::vector<compiler::Node*>{phi_bb34_20});
  }

  TNode<UintPtrT> phi_bb32_20;
  TNode<Undefined> tmp40;
  TNode<Smi> tmp41;
  TNode<Smi> tmp42;
  TNode<BoolT> tmp43;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_20);
    tmp40 = Undefined_0(state_);
tmp41 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallInterfaceDescriptorFor(ExampleBuiltinForTorqueFunctionPointerType(3)), tmp34, parameter0, tmp17, phi_bb32_20, tmp40));
    tmp42 = kStoreSucceded_0(state_);
    tmp43 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp41}, TNode<Smi>{tmp42});
    ca_.Branch(tmp43, &block36, std::vector<compiler::Node*>{phi_bb32_20, phi_bb32_20, phi_bb32_20}, &block37, std::vector<compiler::Node*>{phi_bb32_20, phi_bb32_20, phi_bb32_20});
  }

  TNode<UintPtrT> phi_bb37_20;
  TNode<UintPtrT> phi_bb37_26;
  TNode<UintPtrT> phi_bb37_30;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_20, &phi_bb37_26, &phi_bb37_30);
    {
      auto pos_stack = ca_.GetMacroSourcePositionStack();
      pos_stack.push_back({"src/builtins/typed-array.tq", 119});
      CodeStubAssembler(state_).FailAssert("Torque assert 'result == kStoreSucceded' failed", pos_stack);
    }
  }

  TNode<UintPtrT> phi_bb36_20;
  TNode<UintPtrT> phi_bb36_26;
  TNode<UintPtrT> phi_bb36_30;
  TNode<UintPtrT> tmp44;
  TNode<UintPtrT> tmp45;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_20, &phi_bb36_26, &phi_bb36_30);
    tmp44 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    tmp45 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{phi_bb36_20}, TNode<UintPtrT>{tmp44});
    ca_.Goto(&block34, tmp45);
  }

  TNode<UintPtrT> phi_bb33_20;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_20);
    CodeStubAssembler(state_).Return(tmp17);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{parameter0}, MessageTemplate::kInvalidTypedArrayIndex);
  }
}

} // namespace internal
} // namespace v8
