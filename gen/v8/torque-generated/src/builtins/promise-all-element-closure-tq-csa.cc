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
#include "torque-generated/src/builtins/promise-all-element-closure-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/promise-all-element-closure-tq-csa.h"
#include "torque-generated/src/builtins/promise-any-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=69&c=1
TNode<IntPtrT> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementRemainingSlot_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<IntPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=69&c=1
TNode<IntPtrT> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementCapabilitySlot_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<IntPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=69&c=1
TNode<IntPtrT> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementValuesSlot_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<IntPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=69&c=1
TNode<IntPtrT> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementLength_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<IntPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=69&c=1
TNode<IntPtrT> kPromiseAllResolveElementRemainingSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementRemainingSlot_0(
        state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=69&c=1
TNode<IntPtrT> kPromiseAllResolveElementCapabilitySlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementCapabilitySlot_0(
        state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=69&c=1
TNode<IntPtrT> kPromiseAllResolveElementValuesSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementValuesSlot_0(
        state_, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

TF_BUILTIN(PromiseAllResolveElementClosure, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<Object> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(state_, TNode<Context> { tmp0 }, TNode<Object> { parameter3 },
            TNode<JSFunction> { parameter2 }, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0 {});
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(PromiseAllSettledResolveElementClosure, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<Object> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(state_, TNode<Context> { tmp0 }, TNode<Object> { parameter3 },
            TNode<JSFunction> { parameter2 }, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0 {});
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(PromiseAllSettledRejectElementClosure, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<Object> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(state_, TNode<Context> { tmp0 }, TNode<Object> { parameter3 },
            TNode<JSFunction> { parameter2 }, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0 {});
        CodeStubAssembler(state_).Return(tmp1);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=172&c=10
TNode<Object> PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<JSReceiver> { p_function }, &label1);
        ca_.Goto(&block8);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block9);
        }
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    TNode<BoolT> tmp11;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp2 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T> { tmp0 });
        tmp3 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp5 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { tmp3 }, TNode<IntPtrT> { tmp4 });
        tmp6 = kPromiseAllResolveElementRemainingSlot_0(state_);
        std::tie(tmp7, tmp8)
            = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp6 })
                  .Flatten();
        tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp7, tmp8 });
        tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp11 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp9 }, TNode<Smi> { tmp10 });
        ca_.Branch(tmp11, &block14, std::vector<compiler::Node*> {}, &block15, std::vector<compiler::Node*> {});
    }

    TNode<Undefined> tmp12;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp12 = Undefined_0(state_);
        ca_.Goto(&block1, tmp12);
    }

    TNode<IntPtrT> tmp13;
    TNode<Object> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<FixedArray> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<BoolT> tmp20;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp13 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp14, tmp15) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp13 })
                                     .Flatten();
        tmp16 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { tmp14, tmp15 });
        tmp17 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp18 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp5 }, TNode<IntPtrT> { tmp17 });
        tmp19 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp16 });
        tmp20 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT> { tmp18 }, TNode<IntPtrT> { tmp19 });
        ca_.Branch(tmp20, &block16, std::vector<compiler::Node*> {}, &block17, std::vector<compiler::Node*> { tmp16 });
    }

    TNode<IntPtrT> tmp21;
    TNode<Hole> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<FixedArray> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<Object> tmp26;
    TNode<IntPtrT> tmp27;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp21 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp16 });
        tmp22 = PromiseHole_0(state_);
        tmp23 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp24 = ExtractFixedArray_0(
            state_, TNode<FixedArray> { tmp16 }, TNode<IntPtrT> { tmp23 }, TNode<IntPtrT> { tmp21 }, TNode<IntPtrT> { tmp18 }, TNode<Hole> { tmp22 });
        tmp25 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp26, tmp27) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp25 })
                                     .Flatten();
        CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference { tmp26, tmp27 }, tmp24);
        ca_.Goto(&block17, tmp24);
    }

    TNode<FixedArray> phi_bb17_6;
    TNode<Object> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<UintPtrT> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<BoolT> tmp33;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_6);
        std::tie(tmp28, tmp29, tmp30) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { phi_bb17_6 }).Flatten();
        tmp31 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp5 });
        tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp30 });
        tmp33 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp31 }, TNode<UintPtrT> { tmp32 });
        ca_.Branch(tmp33, &block24, std::vector<compiler::Node*> {}, &block25, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<Object> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Object> tmp38;
    TNode<Hole> tmp39;
    TNode<BoolT> tmp40;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        tmp34 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp5 });
        tmp35 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp29 }, TNode<IntPtrT> { tmp34 });
        std::tie(tmp36, tmp37) = NewReference_Object_0(state_, TNode<Object> { tmp28 }, TNode<IntPtrT> { tmp35 }).Flatten();
        tmp38 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp36, tmp37 });
        tmp39 = PromiseHole_0(state_);
        tmp40 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp38 }, TNode<HeapObject> { tmp39 });
        ca_.Branch(tmp40, &block18, std::vector<compiler::Node*> {}, &block19, std::vector<compiler::Node*> {});
    }

    if (block25.is_used()) {
        ca_.Bind(&block25);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Undefined> tmp41;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp41 = Undefined_0(state_);
        ca_.Goto(&block1, tmp41);
    }

    TNode<NativeContext> tmp42;
    TNode<Hole> tmp43;
    TNode<BoolT> tmp44;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp42 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context> { p_context });
        tmp43 = PromiseHole_0(state_);
        tmp44 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { p_value }, TNode<HeapObject> { tmp43 });
        ca_.Branch(tmp44, &block29, std::vector<compiler::Node*> {}, &block30, std::vector<compiler::Node*> {});
    }

    if (block30.is_used()) {
        ca_.Bind(&block30);
        {
            auto pos_stack = ca_.GetMacroSourcePositionStack();
            pos_stack.push_back({ "src/builtins/promise-all-element-closure.tq", 15 });
            CodeStubAssembler(state_).FailAssert("Torque assert 'value != PromiseHole' failed", pos_stack);
        }
    }

    TNode<Object> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<UintPtrT> tmp49;
    TNode<BoolT> tmp50;
    if (block29.is_used()) {
        ca_.Bind(&block29);
        std::tie(tmp45, tmp46, tmp47) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { phi_bb17_6 }).Flatten();
        tmp48 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp5 });
        tmp49 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp47 });
        tmp50 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp48 }, TNode<UintPtrT> { tmp49 });
        ca_.Branch(tmp50, &block35, std::vector<compiler::Node*> {}, &block36, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<Object> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<Smi> tmp55;
    TNode<Smi> tmp56;
    TNode<Smi> tmp57;
    TNode<BoolT> tmp58;
    if (block35.is_used()) {
        ca_.Bind(&block35);
        tmp51 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp5 });
        tmp52 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp46 }, TNode<IntPtrT> { tmp51 });
        std::tie(tmp53, tmp54) = NewReference_Object_0(state_, TNode<Object> { tmp45 }, TNode<IntPtrT> { tmp52 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp53, tmp54 }, p_value);
        tmp55 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp56 = CodeStubAssembler(state_).SmiSub(TNode<Smi> { tmp9 }, TNode<Smi> { tmp55 });
        tmp57 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp58 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi> { tmp56 }, TNode<Smi> { tmp57 });
        ca_.Branch(tmp58, &block39, std::vector<compiler::Node*> {}, &block40, std::vector<compiler::Node*> {});
    }

    if (block36.is_used()) {
        ca_.Bind(&block36);
        CodeStubAssembler(state_).Unreachable();
    }

    if (block40.is_used()) {
        ca_.Bind(&block40);
        {
            auto pos_stack = ca_.GetMacroSourcePositionStack();
            pos_stack.push_back({ "src/builtins/promise-all-element-closure.tq", 140 });
            CodeStubAssembler(state_).FailAssert("Torque assert 'remainingElementsCount >= 0' failed", pos_stack);
        }
    }

    TNode<IntPtrT> tmp59;
    TNode<Object> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<Smi> tmp62;
    TNode<BoolT> tmp63;
    if (block39.is_used()) {
        ca_.Bind(&block39);
        tmp59 = kPromiseAllResolveElementRemainingSlot_0(state_);
        std::tie(tmp60, tmp61)
            = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp59 })
                  .Flatten();
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp60, tmp61 }, tmp56);
        tmp62 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp63 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp56 }, TNode<Smi> { tmp62 });
        ca_.Branch(tmp63, &block41, std::vector<compiler::Node*> {}, &block42, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp64;
    TNode<Object> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<PromiseCapability> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<Object> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<Map> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<Object> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<FixedArray> tmp78;
    TNode<JSArray> tmp79;
    TNode<Undefined> tmp80;
    TNode<Object> tmp81;
    if (block41.is_used()) {
        ca_.Bind(&block41);
        tmp64 = kPromiseAllResolveElementCapabilitySlot_0(state_);
        std::tie(tmp65, tmp66) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_PromiseCapability_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp64 })
                                     .Flatten();
        tmp67 = CodeStubAssembler(state_).LoadReference<PromiseCapability>(CodeStubAssembler::Reference { tmp65, tmp66 });
        tmp68 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp69 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp67, tmp68 });
        tmp70 = UnsafeCast_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp69 });
        tmp71 = JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_);
        std::tie(tmp72, tmp73) = NativeContextSlot_Map_1(state_, TNode<NativeContext> { tmp42 }, TNode<IntPtrT> { tmp71 }).Flatten();
        tmp74 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp72, tmp73 });
        tmp75 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp76, tmp77) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp75 })
                                     .Flatten();
        tmp78 = kEmptyFixedArray_0(state_);
        CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference { tmp76, tmp77 }, tmp78);
        tmp79 = NewJSArray_0(state_, TNode<Context> { p_context }, TNode<Map> { tmp74 }, TNode<FixedArrayBase> { phi_bb17_6 });
        tmp80 = Undefined_0(state_);
        tmp81 = CodeStubAssembler(state_).Call(TNode<Context> { p_context }, TNode<Object> { tmp70 }, TNode<Object> { tmp80 }, TNode<Object> { tmp79 });
        ca_.Goto(&block42);
    }

    TNode<Undefined> tmp82;
    if (block42.is_used()) {
        ca_.Bind(&block42);
        tmp82 = Undefined_0(state_);
        ca_.Goto(&block1, tmp82);
    }

    TNode<Object> phi_bb1_3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3);
        ca_.Goto(&block43, phi_bb1_3);
    }

    TNode<Object> phi_bb43_3;
    ca_.Bind(&block43, &phi_bb43_3);
    return TNode<Object> { phi_bb43_3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=180&c=10
TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<JSReceiver> { p_function }, &label1);
        ca_.Goto(&block8);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block9);
        }
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    TNode<BoolT> tmp11;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp2 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T> { tmp0 });
        tmp3 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp5 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { tmp3 }, TNode<IntPtrT> { tmp4 });
        tmp6 = kPromiseAllResolveElementRemainingSlot_0(state_);
        std::tie(tmp7, tmp8)
            = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp6 })
                  .Flatten();
        tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp7, tmp8 });
        tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp11 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp9 }, TNode<Smi> { tmp10 });
        ca_.Branch(tmp11, &block14, std::vector<compiler::Node*> {}, &block15, std::vector<compiler::Node*> {});
    }

    TNode<Undefined> tmp12;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp12 = Undefined_0(state_);
        ca_.Goto(&block1, tmp12);
    }

    TNode<IntPtrT> tmp13;
    TNode<Object> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<FixedArray> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<BoolT> tmp20;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp13 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp14, tmp15) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp13 })
                                     .Flatten();
        tmp16 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { tmp14, tmp15 });
        tmp17 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp18 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp5 }, TNode<IntPtrT> { tmp17 });
        tmp19 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp16 });
        tmp20 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT> { tmp18 }, TNode<IntPtrT> { tmp19 });
        ca_.Branch(tmp20, &block16, std::vector<compiler::Node*> {}, &block17, std::vector<compiler::Node*> { tmp16 });
    }

    TNode<IntPtrT> tmp21;
    TNode<Hole> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<FixedArray> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<Object> tmp26;
    TNode<IntPtrT> tmp27;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp21 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp16 });
        tmp22 = PromiseHole_0(state_);
        tmp23 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp24 = ExtractFixedArray_0(
            state_, TNode<FixedArray> { tmp16 }, TNode<IntPtrT> { tmp23 }, TNode<IntPtrT> { tmp21 }, TNode<IntPtrT> { tmp18 }, TNode<Hole> { tmp22 });
        tmp25 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp26, tmp27) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp25 })
                                     .Flatten();
        CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference { tmp26, tmp27 }, tmp24);
        ca_.Goto(&block17, tmp24);
    }

    TNode<FixedArray> phi_bb17_6;
    TNode<Object> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<UintPtrT> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<BoolT> tmp33;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_6);
        std::tie(tmp28, tmp29, tmp30) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { phi_bb17_6 }).Flatten();
        tmp31 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp5 });
        tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp30 });
        tmp33 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp31 }, TNode<UintPtrT> { tmp32 });
        ca_.Branch(tmp33, &block24, std::vector<compiler::Node*> {}, &block25, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<Object> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Object> tmp38;
    TNode<Hole> tmp39;
    TNode<BoolT> tmp40;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        tmp34 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp5 });
        tmp35 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp29 }, TNode<IntPtrT> { tmp34 });
        std::tie(tmp36, tmp37) = NewReference_Object_0(state_, TNode<Object> { tmp28 }, TNode<IntPtrT> { tmp35 }).Flatten();
        tmp38 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp36, tmp37 });
        tmp39 = PromiseHole_0(state_);
        tmp40 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp38 }, TNode<HeapObject> { tmp39 });
        ca_.Branch(tmp40, &block18, std::vector<compiler::Node*> {}, &block19, std::vector<compiler::Node*> {});
    }

    if (block25.is_used()) {
        ca_.Bind(&block25);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Undefined> tmp41;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp41 = Undefined_0(state_);
        ca_.Goto(&block1, tmp41);
    }

    TNode<NativeContext> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<Object> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<JSFunction> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<HeapObject> tmp48;
    TNode<Map> tmp49;
    TNode<JSObject> tmp50;
    TNode<String> tmp51;
    TNode<String> tmp52;
    TNode<Object> tmp53;
    TNode<String> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<UintPtrT> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<BoolT> tmp61;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp42 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context> { p_context });
        tmp43 = OBJECT_FUNCTION_INDEX_0(state_);
        std::tie(tmp44, tmp45) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext> { tmp42 }, TNode<IntPtrT> { tmp43 }).Flatten();
        tmp46 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference { tmp44, tmp45 });
        tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp48 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp46, tmp47 });
        tmp49 = UnsafeCast_Map_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp48 });
        tmp50 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map> { tmp49 });
        tmp51 = CodeStubAssembler(state_).StringConstant("status");
        tmp52 = CodeStubAssembler(state_).StringConstant("fulfilled");
        tmp53 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, tmp50, tmp51, tmp52);
        tmp54 = CodeStubAssembler(state_).StringConstant("value");
        tmp55 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, tmp50, tmp54, p_value);
        std::tie(tmp56, tmp57, tmp58) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { phi_bb17_6 }).Flatten();
        tmp59 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp5 });
        tmp60 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp58 });
        tmp61 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp59 }, TNode<UintPtrT> { tmp60 });
        ca_.Branch(tmp61, &block33, std::vector<compiler::Node*> {}, &block34, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Object> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<Smi> tmp66;
    TNode<Smi> tmp67;
    TNode<Smi> tmp68;
    TNode<BoolT> tmp69;
    if (block33.is_used()) {
        ca_.Bind(&block33);
        tmp62 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp5 });
        tmp63 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp57 }, TNode<IntPtrT> { tmp62 });
        std::tie(tmp64, tmp65) = NewReference_Object_0(state_, TNode<Object> { tmp56 }, TNode<IntPtrT> { tmp63 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp64, tmp65 }, tmp50);
        tmp66 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp67 = CodeStubAssembler(state_).SmiSub(TNode<Smi> { tmp9 }, TNode<Smi> { tmp66 });
        tmp68 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp69 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi> { tmp67 }, TNode<Smi> { tmp68 });
        ca_.Branch(tmp69, &block37, std::vector<compiler::Node*> {}, &block38, std::vector<compiler::Node*> {});
    }

    if (block34.is_used()) {
        ca_.Bind(&block34);
        CodeStubAssembler(state_).Unreachable();
    }

    if (block38.is_used()) {
        ca_.Bind(&block38);
        {
            auto pos_stack = ca_.GetMacroSourcePositionStack();
            pos_stack.push_back({ "src/builtins/promise-all-element-closure.tq", 140 });
            CodeStubAssembler(state_).FailAssert("Torque assert 'remainingElementsCount >= 0' failed", pos_stack);
        }
    }

    TNode<IntPtrT> tmp70;
    TNode<Object> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<Smi> tmp73;
    TNode<BoolT> tmp74;
    if (block37.is_used()) {
        ca_.Bind(&block37);
        tmp70 = kPromiseAllResolveElementRemainingSlot_0(state_);
        std::tie(tmp71, tmp72)
            = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp70 })
                  .Flatten();
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp71, tmp72 }, tmp67);
        tmp73 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp74 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp67 }, TNode<Smi> { tmp73 });
        ca_.Branch(tmp74, &block39, std::vector<compiler::Node*> {}, &block40, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp75;
    TNode<Object> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<PromiseCapability> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<Object> tmp80;
    TNode<Object> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<Object> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<Map> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<Object> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<FixedArray> tmp89;
    TNode<JSArray> tmp90;
    TNode<Undefined> tmp91;
    TNode<Object> tmp92;
    if (block39.is_used()) {
        ca_.Bind(&block39);
        tmp75 = kPromiseAllResolveElementCapabilitySlot_0(state_);
        std::tie(tmp76, tmp77) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_PromiseCapability_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp75 })
                                     .Flatten();
        tmp78 = CodeStubAssembler(state_).LoadReference<PromiseCapability>(CodeStubAssembler::Reference { tmp76, tmp77 });
        tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp80 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp78, tmp79 });
        tmp81 = UnsafeCast_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp80 });
        tmp82 = JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_);
        std::tie(tmp83, tmp84) = NativeContextSlot_Map_1(state_, TNode<NativeContext> { tmp42 }, TNode<IntPtrT> { tmp82 }).Flatten();
        tmp85 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp83, tmp84 });
        tmp86 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp87, tmp88) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp86 })
                                     .Flatten();
        tmp89 = kEmptyFixedArray_0(state_);
        CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference { tmp87, tmp88 }, tmp89);
        tmp90 = NewJSArray_0(state_, TNode<Context> { p_context }, TNode<Map> { tmp85 }, TNode<FixedArrayBase> { phi_bb17_6 });
        tmp91 = Undefined_0(state_);
        tmp92 = CodeStubAssembler(state_).Call(TNode<Context> { p_context }, TNode<Object> { tmp81 }, TNode<Object> { tmp91 }, TNode<Object> { tmp90 });
        ca_.Goto(&block40);
    }

    TNode<Undefined> tmp93;
    if (block40.is_used()) {
        ca_.Bind(&block40);
        tmp93 = Undefined_0(state_);
        ca_.Goto(&block1, tmp93);
    }

    TNode<Object> phi_bb1_3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3);
        ca_.Goto(&block41, phi_bb1_3);
    }

    TNode<Object> phi_bb41_3;
    ca_.Bind(&block41, &phi_bb41_3);
    return TNode<Object> { phi_bb41_3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=188&c=10
TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0 p_wrapResultFunctor)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<JSReceiver> { p_function }, &label1);
        ca_.Goto(&block8);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block9);
        }
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    TNode<BoolT> tmp11;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp2 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T> { tmp0 });
        tmp3 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp5 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { tmp3 }, TNode<IntPtrT> { tmp4 });
        tmp6 = kPromiseAllResolveElementRemainingSlot_0(state_);
        std::tie(tmp7, tmp8)
            = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp6 })
                  .Flatten();
        tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp7, tmp8 });
        tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp11 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp9 }, TNode<Smi> { tmp10 });
        ca_.Branch(tmp11, &block14, std::vector<compiler::Node*> {}, &block15, std::vector<compiler::Node*> {});
    }

    TNode<Undefined> tmp12;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp12 = Undefined_0(state_);
        ca_.Goto(&block1, tmp12);
    }

    TNode<IntPtrT> tmp13;
    TNode<Object> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<FixedArray> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<BoolT> tmp20;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp13 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp14, tmp15) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp13 })
                                     .Flatten();
        tmp16 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { tmp14, tmp15 });
        tmp17 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp18 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp5 }, TNode<IntPtrT> { tmp17 });
        tmp19 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp16 });
        tmp20 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT> { tmp18 }, TNode<IntPtrT> { tmp19 });
        ca_.Branch(tmp20, &block16, std::vector<compiler::Node*> {}, &block17, std::vector<compiler::Node*> { tmp16 });
    }

    TNode<IntPtrT> tmp21;
    TNode<Hole> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<FixedArray> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<Object> tmp26;
    TNode<IntPtrT> tmp27;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp21 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp16 });
        tmp22 = PromiseHole_0(state_);
        tmp23 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp24 = ExtractFixedArray_0(
            state_, TNode<FixedArray> { tmp16 }, TNode<IntPtrT> { tmp23 }, TNode<IntPtrT> { tmp21 }, TNode<IntPtrT> { tmp18 }, TNode<Hole> { tmp22 });
        tmp25 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp26, tmp27) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp25 })
                                     .Flatten();
        CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference { tmp26, tmp27 }, tmp24);
        ca_.Goto(&block17, tmp24);
    }

    TNode<FixedArray> phi_bb17_6;
    TNode<Object> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<UintPtrT> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<BoolT> tmp33;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_6);
        std::tie(tmp28, tmp29, tmp30) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { phi_bb17_6 }).Flatten();
        tmp31 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp5 });
        tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp30 });
        tmp33 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp31 }, TNode<UintPtrT> { tmp32 });
        ca_.Branch(tmp33, &block24, std::vector<compiler::Node*> {}, &block25, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<Object> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Object> tmp38;
    TNode<Hole> tmp39;
    TNode<BoolT> tmp40;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        tmp34 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp5 });
        tmp35 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp29 }, TNode<IntPtrT> { tmp34 });
        std::tie(tmp36, tmp37) = NewReference_Object_0(state_, TNode<Object> { tmp28 }, TNode<IntPtrT> { tmp35 }).Flatten();
        tmp38 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp36, tmp37 });
        tmp39 = PromiseHole_0(state_);
        tmp40 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp38 }, TNode<HeapObject> { tmp39 });
        ca_.Branch(tmp40, &block18, std::vector<compiler::Node*> {}, &block19, std::vector<compiler::Node*> {});
    }

    if (block25.is_used()) {
        ca_.Bind(&block25);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Undefined> tmp41;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp41 = Undefined_0(state_);
        ca_.Goto(&block1, tmp41);
    }

    TNode<NativeContext> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<Object> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<JSFunction> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<HeapObject> tmp48;
    TNode<Map> tmp49;
    TNode<JSObject> tmp50;
    TNode<String> tmp51;
    TNode<String> tmp52;
    TNode<Object> tmp53;
    TNode<String> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<UintPtrT> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<BoolT> tmp61;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp42 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context> { p_context });
        tmp43 = OBJECT_FUNCTION_INDEX_0(state_);
        std::tie(tmp44, tmp45) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext> { tmp42 }, TNode<IntPtrT> { tmp43 }).Flatten();
        tmp46 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference { tmp44, tmp45 });
        tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp48 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp46, tmp47 });
        tmp49 = UnsafeCast_Map_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp48 });
        tmp50 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map> { tmp49 });
        tmp51 = CodeStubAssembler(state_).StringConstant("status");
        tmp52 = CodeStubAssembler(state_).StringConstant("rejected");
        tmp53 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, tmp50, tmp51, tmp52);
        tmp54 = CodeStubAssembler(state_).StringConstant("reason");
        tmp55 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, tmp50, tmp54, p_value);
        std::tie(tmp56, tmp57, tmp58) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { phi_bb17_6 }).Flatten();
        tmp59 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp5 });
        tmp60 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp58 });
        tmp61 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp59 }, TNode<UintPtrT> { tmp60 });
        ca_.Branch(tmp61, &block33, std::vector<compiler::Node*> {}, &block34, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Object> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<Smi> tmp66;
    TNode<Smi> tmp67;
    TNode<Smi> tmp68;
    TNode<BoolT> tmp69;
    if (block33.is_used()) {
        ca_.Bind(&block33);
        tmp62 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp5 });
        tmp63 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp57 }, TNode<IntPtrT> { tmp62 });
        std::tie(tmp64, tmp65) = NewReference_Object_0(state_, TNode<Object> { tmp56 }, TNode<IntPtrT> { tmp63 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp64, tmp65 }, tmp50);
        tmp66 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp67 = CodeStubAssembler(state_).SmiSub(TNode<Smi> { tmp9 }, TNode<Smi> { tmp66 });
        tmp68 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp69 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi> { tmp67 }, TNode<Smi> { tmp68 });
        ca_.Branch(tmp69, &block37, std::vector<compiler::Node*> {}, &block38, std::vector<compiler::Node*> {});
    }

    if (block34.is_used()) {
        ca_.Bind(&block34);
        CodeStubAssembler(state_).Unreachable();
    }

    if (block38.is_used()) {
        ca_.Bind(&block38);
        {
            auto pos_stack = ca_.GetMacroSourcePositionStack();
            pos_stack.push_back({ "src/builtins/promise-all-element-closure.tq", 140 });
            CodeStubAssembler(state_).FailAssert("Torque assert 'remainingElementsCount >= 0' failed", pos_stack);
        }
    }

    TNode<IntPtrT> tmp70;
    TNode<Object> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<Smi> tmp73;
    TNode<BoolT> tmp74;
    if (block37.is_used()) {
        ca_.Bind(&block37);
        tmp70 = kPromiseAllResolveElementRemainingSlot_0(state_);
        std::tie(tmp71, tmp72)
            = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp70 })
                  .Flatten();
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp71, tmp72 }, tmp67);
        tmp73 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp74 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp67 }, TNode<Smi> { tmp73 });
        ca_.Branch(tmp74, &block39, std::vector<compiler::Node*> {}, &block40, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp75;
    TNode<Object> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<PromiseCapability> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<Object> tmp80;
    TNode<Object> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<Object> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<Map> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<Object> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<FixedArray> tmp89;
    TNode<JSArray> tmp90;
    TNode<Undefined> tmp91;
    TNode<Object> tmp92;
    if (block39.is_used()) {
        ca_.Bind(&block39);
        tmp75 = kPromiseAllResolveElementCapabilitySlot_0(state_);
        std::tie(tmp76, tmp77) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_PromiseCapability_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp75 })
                                     .Flatten();
        tmp78 = CodeStubAssembler(state_).LoadReference<PromiseCapability>(CodeStubAssembler::Reference { tmp76, tmp77 });
        tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp80 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp78, tmp79 });
        tmp81 = UnsafeCast_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp80 });
        tmp82 = JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_);
        std::tie(tmp83, tmp84) = NativeContextSlot_Map_1(state_, TNode<NativeContext> { tmp42 }, TNode<IntPtrT> { tmp82 }).Flatten();
        tmp85 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp83, tmp84 });
        tmp86 = kPromiseAllResolveElementValuesSlot_0(state_);
        std::tie(tmp87, tmp88) = ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp86 })
                                     .Flatten();
        tmp89 = kEmptyFixedArray_0(state_);
        CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference { tmp87, tmp88 }, tmp89);
        tmp90 = NewJSArray_0(state_, TNode<Context> { p_context }, TNode<Map> { tmp85 }, TNode<FixedArrayBase> { phi_bb17_6 });
        tmp91 = Undefined_0(state_);
        tmp92 = CodeStubAssembler(state_).Call(TNode<Context> { p_context }, TNode<Object> { tmp81 }, TNode<Object> { tmp91 }, TNode<Object> { tmp90 });
        ca_.Goto(&block40);
    }

    TNode<Undefined> tmp93;
    if (block40.is_used()) {
        ca_.Bind(&block40);
        tmp93 = Undefined_0(state_);
        ca_.Goto(&block1, tmp93);
    }

    TNode<Object> phi_bb1_3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3);
        ca_.Goto(&block41, phi_bb1_3);
    }

    TNode<Object> phi_bb41_3;
    ca_.Bind(&block41, &phi_bb41_3);
    return TNode<Object> { phi_bb41_3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=100&c=33
TorqueStructReference_Smi_0 ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_Smi_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context> { p_context }).Flatten();
        tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_index });
        tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { tmp4 });
        ca_.Branch(tmp5, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    TNode<IntPtrT> tmp11;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp6 });
        std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp7 }).Flatten();
        std::tie(tmp10, tmp11)
            = ReferenceCast_Smi_Object_0(state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                  .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_Smi_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=111&c=17
TorqueStructReference_FixedArray_0 ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_FixedArray_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context> { p_context }).Flatten();
        tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_index });
        tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { tmp4 });
        ca_.Branch(tmp5, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    TNode<IntPtrT> tmp11;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp6 });
        std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp7 }).Flatten();
        std::tie(tmp10, tmp11) = ReferenceCast_FixedArray_Object_0(
            state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_FixedArray_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-all-element-closure.tq?l=147&c=25
TorqueStructReference_PromiseCapability_0 ContextSlot_PromiseAllResolveElementContext_PromiseAllResolveElementContext_PromiseCapability_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context> { p_context }).Flatten();
        tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_index });
        tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { tmp4 });
        ca_.Branch(tmp5, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    TNode<IntPtrT> tmp11;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp6 });
        std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp7 }).Flatten();
        std::tie(tmp10, tmp11) = ReferenceCast_PromiseCapability_Object_0(
            state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_PromiseCapability_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

} // namespace internal
} // namespace v8
