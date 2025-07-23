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
#include "torque-generated/src/builtins/typed-array-to-reversed-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(TypedArrayPrototypeToReversed, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<UintPtrT> tmp0;
  TNode<JSTypedArray> tmp1;
  TNode<JSTypedArray> tmp2;
  TNode<Int32T> tmp3;
  TNode<BuiltinPtr> tmp4;
  TNode<BuiltinPtr> tmp5;
  TNode<BuiltinPtr> tmp6;
  TNode<UintPtrT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArrayAndGetLength(TNode<Context>{parameter0}, TNode<Object>{parameter1}, "%TypedArray%.prototype.toReversed");
    tmp1 = UnsafeCast_JSTypedArray_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1});
    tmp2 = TypedArrayCreateSameType_0(state_, TNode<Context>{parameter0}, TNode<JSTypedArray>{tmp1}, TNode<UintPtrT>{tmp0});
    tmp3 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp2});
    std::tie(tmp4, tmp5, tmp6) = GetTypedArrayAccessor_0(state_, TNode<Int32T>{tmp3}).Flatten();
    tmp7 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block3, tmp7);
  }

  TNode<UintPtrT> phi_bb3_12;
  TNode<BoolT> tmp8;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_12);
    tmp8 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{phi_bb3_12}, TNode<UintPtrT>{tmp0});
    ca_.Branch(tmp8, &block1, std::vector<compiler::Node*>{phi_bb3_12}, &block2, std::vector<compiler::Node*>{phi_bb3_12});
  }

  TNode<UintPtrT> phi_bb1_12;
  TNode<UintPtrT> tmp9;
  TNode<UintPtrT> tmp10;
  TNode<UintPtrT> tmp11;
  TNode<Numeric> tmp12;
  TNode<Smi> tmp13;
  TNode<UintPtrT> tmp14;
  TNode<UintPtrT> tmp15;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_12);
    tmp9 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp0}, TNode<UintPtrT>{phi_bb1_12});
    tmp10 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp11 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp10});
tmp12 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallInterfaceDescriptorFor(ExampleBuiltinForTorqueFunctionPointerType(1)), tmp4, TNode<Object>(), tmp1, tmp11));
tmp13 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallInterfaceDescriptorFor(ExampleBuiltinForTorqueFunctionPointerType(2)), tmp5, parameter0, tmp2, phi_bb1_12, tmp12));
    tmp14 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    tmp15 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{phi_bb1_12}, TNode<UintPtrT>{tmp14});
    ca_.Goto(&block3, tmp15);
  }

  TNode<UintPtrT> phi_bb2_12;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_12);
    arguments.PopAndReturn(tmp2);
  }
}

} // namespace internal
} // namespace v8
