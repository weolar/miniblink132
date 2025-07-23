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
#include "torque-generated/src/builtins/promise-try-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/arguments-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(PromiseTry, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
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
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_JSReceiver_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { parameter0 }, MessageTemplate::kCalledOnNonObject, "Promise.try");
    }

    TNode<False> tmp2;
    TNode<PromiseCapability> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp8;
    TNode<BoolT> tmp9;
    TNode<Object> tmp11;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp2 = False_0(state_);
        tmp3 = ca_.CallBuiltin<PromiseCapability>(Builtin::kNewPromiseCapability, parameter0, tmp0, tmp2);
        tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp5 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp4 });
        compiler::CodeAssemblerExceptionHandlerLabel catch7__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch7__label);
            tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        }
        if (catch7__label.is_used()) {
            compiler::CodeAssemblerLabel catch7_skip(&ca_);
            ca_.Goto(&catch7_skip);
            ca_.Bind(&catch7__label, &tmp8);
            ca_.Goto(&block9);
            ca_.Bind(&catch7_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch10__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch10__label);
            tmp9 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { tmp6 });
        }
        if (catch10__label.is_used()) {
            compiler::CodeAssemblerLabel catch10_skip(&ca_);
            ca_.Goto(&catch10_skip);
            ca_.Bind(&catch10__label, &tmp11);
            ca_.Goto(&block10);
            ca_.Bind(&catch10_skip);
        }
        ca_.Branch(tmp9, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<HeapObject> tmp12;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp12 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp8, tmp12);
    }

    TNode<HeapObject> tmp13;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp13 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp11, tmp13);
    }

    TNode<Undefined> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp17;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp14 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
            tmp15 = CodeStubAssembler(state_).Call(TNode<Context> { parameter0 }, TNode<Object> { tmp5 }, TNode<Object> { tmp14 });
        }
        if (catch16__label.is_used()) {
            compiler::CodeAssemblerLabel catch16_skip(&ca_);
            ca_.Goto(&catch16_skip);
            ca_.Bind(&catch16__label, &tmp17);
            ca_.Goto(&block12);
            ca_.Bind(&catch16_skip);
        }
        ca_.Goto(&block11, tmp15);
    }

    TNode<HeapObject> tmp18;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp18 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp17, tmp18);
    }

    TNode<IntPtrT> tmp19;
    TNode<Object> tmp21;
    TNode<JSArray> tmp22;
    TNode<Object> tmp24;
    TNode<JSReceiver> tmp25;
    TNode<Object> tmp27;
    TNode<Undefined> tmp28;
    TNode<Undefined> tmp29;
    TNode<Object> tmp30;
    TNode<Object> tmp32;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        compiler::CodeAssemblerExceptionHandlerLabel catch20__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch20__label);
            tmp19 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        }
        if (catch20__label.is_used()) {
            compiler::CodeAssemblerLabel catch20_skip(&ca_);
            ca_.Goto(&catch20_skip);
            ca_.Bind(&catch20__label, &tmp21);
            ca_.Goto(&block13);
            ca_.Bind(&catch20_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch23__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch23__label);
            tmp22 = NewRestArgumentsFromArguments_0(state_, TNode<Context> { parameter0 },
                TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                    TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
                TNode<IntPtrT> { tmp19 });
        }
        if (catch23__label.is_used()) {
            compiler::CodeAssemblerLabel catch23_skip(&ca_);
            ca_.Goto(&catch23_skip);
            ca_.Bind(&catch23__label, &tmp24);
            ca_.Goto(&block14);
            ca_.Bind(&catch23_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
            tmp25 = GetReflectApply_0(state_, TNode<Context> { parameter0 });
        }
        if (catch26__label.is_used()) {
            compiler::CodeAssemblerLabel catch26_skip(&ca_);
            ca_.Goto(&catch26_skip);
            ca_.Bind(&catch26__label, &tmp27);
            ca_.Goto(&block15);
            ca_.Bind(&catch26_skip);
        }
        tmp28 = Undefined_0(state_);
        tmp29 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch31__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch31__label);
            tmp30 = CodeStubAssembler(state_).Call(TNode<Context> { parameter0 }, TNode<Object> { tmp25 }, TNode<Object> { tmp28 }, TNode<Object> { tmp5 },
                TNode<Object> { tmp29 }, TNode<Object> { tmp22 });
        }
        if (catch31__label.is_used()) {
            compiler::CodeAssemblerLabel catch31_skip(&ca_);
            ca_.Goto(&catch31_skip);
            ca_.Bind(&catch31__label, &tmp32);
            ca_.Goto(&block16);
            ca_.Bind(&catch31_skip);
        }
        ca_.Goto(&block11, tmp30);
    }

    TNode<HeapObject> tmp33;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp33 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp21, tmp33);
    }

    TNode<HeapObject> tmp34;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp34 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp24, tmp34);
    }

    TNode<HeapObject> tmp35;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp35 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp27, tmp35);
    }

    TNode<HeapObject> tmp36;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp36 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp32, tmp36);
    }

    TNode<Object> phi_bb11_9;
    TNode<IntPtrT> tmp37;
    TNode<Object> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Undefined> tmp40;
    TNode<Object> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<HeapObject> tmp43;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_9);
        tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp38 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp3, tmp37 });
        tmp39 = UnsafeCast_Callable_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp38 });
        tmp40 = Undefined_0(state_);
        tmp41 = CodeStubAssembler(state_).Call(TNode<Context> { parameter0 }, TNode<Object> { tmp39 }, TNode<Object> { tmp40 }, TNode<Object> { phi_bb11_9 });
        tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp43 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp3, tmp42 });
        arguments.PopAndReturn(tmp43);
    }

    TNode<Object> phi_bb6_10;
    TNode<HeapObject> phi_bb6_11;
    TNode<IntPtrT> tmp44;
    TNode<Object> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<Undefined> tmp47;
    TNode<Object> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<HeapObject> tmp50;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_10, &phi_bb6_11);
        tmp44 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp45 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp3, tmp44 });
        tmp46 = UnsafeCast_Callable_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp45 });
        tmp47 = Undefined_0(state_);
        tmp48 = CodeStubAssembler(state_).Call(TNode<Context> { parameter0 }, TNode<Object> { tmp46 }, TNode<Object> { tmp47 }, TNode<Object> { phi_bb6_10 });
        tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp50 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp3, tmp49 });
        arguments.PopAndReturn(tmp50);
    }
}

} // namespace internal
} // namespace v8
