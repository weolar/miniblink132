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
#include "torque-generated/src/builtins/typed-array-subarray-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(TypedArrayPrototypeSubArray, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSTypedArray> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_JSTypedArray_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    TNode<Object> tmp2;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp2 = FromConstexpr_Object_constexpr_string_0(state_, "%TypedArray%.prototype.subarray");
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { parameter0 }, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object> { tmp2 }, TNode<Object> { parameter1 });
    }

    TNode<JSArrayBuffer> tmp3;
    TNode<UintPtrT> tmp4;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp3 = CodeStubAssembler(state_).GetTypedArrayBuffer(TNode<Context> { parameter0 }, TNode<JSTypedArray> { tmp0 });
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray> { tmp0 }, &label5);
        ca_.Goto(&block7);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block8);
        }
    }

    TNode<UintPtrT> tmp6;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp6 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block5, tmp6);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        ca_.Goto(&block5, tmp4);
    }

    TNode<UintPtrT> phi_bb5_8;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<Undefined> tmp9;
    TNode<BoolT> tmp10;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_8);
        tmp7 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp8 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp7 });
        tmp9 = Undefined_0(state_);
        tmp10 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp8 }, TNode<HeapObject> { tmp9 });
        ca_.Branch(tmp10, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<UintPtrT> tmp11;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp11 = ConvertAndClampRelativeIndex_1(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp8 }, TNode<UintPtrT> { phi_bb5_8 });
        ca_.Goto(&block11, tmp11);
    }

    TNode<UintPtrT> tmp12;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp12 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block11, tmp12);
    }

    TNode<UintPtrT> phi_bb11_10;
    TNode<IntPtrT> tmp13;
    TNode<Object> tmp14;
    TNode<Undefined> tmp15;
    TNode<BoolT> tmp16;
    TNode<BoolT> tmp17;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_10);
        tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp14 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp13 });
        tmp15 = Undefined_0(state_);
        tmp16 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp14 }, TNode<HeapObject> { tmp15 });
        tmp17 = IsLengthTrackingJSArrayBufferView_0(state_, TNode<JSArrayBufferView> { tmp0 });
        ca_.Branch(tmp17, &block15, std::vector<compiler::Node*> {}, &block16, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp18;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp18 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp16 });
        ca_.Goto(&block17, tmp18);
    }

    TNode<BoolT> tmp19;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block17, tmp19);
    }

    TNode<BoolT> phi_bb17_15;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_15);
        ca_.Branch(phi_bb17_15, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    TNode<Undefined> tmp20;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp20 = Undefined_0(state_);
        ca_.Goto(&block18, tmp20);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Branch(tmp16, &block19, std::vector<compiler::Node*> {}, &block20, std::vector<compiler::Node*> {});
    }

    TNode<UintPtrT> tmp21;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp21 = ConvertAndClampRelativeIndex_1(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp14 }, TNode<UintPtrT> { phi_bb5_8 });
        ca_.Goto(&block21, tmp21);
    }

    if (block20.is_used()) {
        ca_.Bind(&block20);
        ca_.Goto(&block21, phi_bb5_8);
    }

    TNode<UintPtrT> phi_bb21_14;
    TNode<UintPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<UintPtrT> tmp26;
    TNode<Number> tmp27;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_14);
        tmp22 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT> { phi_bb21_14 }, TNode<UintPtrT> { phi_bb11_10 });
        tmp23 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp22 });
        tmp24 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp25 = CodeStubAssembler(state_).IntPtrMax(TNode<IntPtrT> { tmp23 }, TNode<IntPtrT> { tmp24 });
        tmp26 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { tmp25 });
        tmp27 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { tmp26 });
        ca_.Goto(&block18, tmp27);
    }

    TNode<Object> phi_bb18_13;
    TNode<UintPtrT> tmp28;
    TNode<Int32T> tmp29;
    TNode<UintPtrT> tmp30;
    TNode<UintPtrT> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<BoolT> tmp33;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_13);
        std::tie(tmp28, tmp29) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<JSTypedArray> { tmp0 }).Flatten();
        tmp30 = CodeStubAssembler(state_).LoadJSArrayBufferViewByteOffset(TNode<JSArrayBufferView> { tmp0 });
        tmp31 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
        tmp32 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT> { tmp31 }, TNode<UintPtrT> { tmp28 });
        tmp33 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { phi_bb11_10 }, TNode<UintPtrT> { tmp32 });
        ca_.Branch(tmp33, &block26, std::vector<compiler::Node*> { phi_bb18_13 }, &block27, std::vector<compiler::Node*> { phi_bb18_13 });
    }

    TNode<Object> phi_bb26_13;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_13);
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { parameter0 }, MessageTemplate::kInvalidArrayBufferLength);
    }

    TNode<Object> phi_bb27_13;
    TNode<UintPtrT> tmp34;
    TNode<UintPtrT> tmp35;
    TNode<JSTypedArray> tmp36;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_13);
        tmp34 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT> { phi_bb11_10 }, TNode<UintPtrT> { tmp28 });
        tmp35 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { tmp30 }, TNode<UintPtrT> { tmp34 });
        tmp36 = TypedArraySpeciesCreateByBuffer_0(state_, TNode<Context> { parameter0 }, "%TypedArray%.prototype.subarray", TNode<JSTypedArray> { tmp0 },
            TNode<JSArrayBuffer> { tmp3 }, TNode<UintPtrT> { tmp35 }, TNode<Object> { phi_bb27_13 });
        arguments.PopAndReturn(tmp36);
    }
}

} // namespace internal
} // namespace v8
