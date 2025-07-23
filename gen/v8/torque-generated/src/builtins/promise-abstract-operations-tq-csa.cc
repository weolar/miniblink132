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
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-all-tq-csa.h"
#include "torque-generated/src/builtins/promise-misc-tq-csa.h"
#include "torque-generated/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/js-promise-tq-csa.h"
#include "torque-generated/src/objects/promise-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=29&c=1
TNode<Symbol> kPromiseForwardingHandlerSymbol_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Symbol> tmp0;
    tmp0 = CodeStubAssembler(state_).PromiseForwardingHandlerSymbolConstant();
    return TNode<Symbol> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=32&c=1
TNode<Symbol> kPromiseHandledBySymbol_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Symbol> tmp0;
    tmp0 = CodeStubAssembler(state_).PromiseHandledBySymbolConstant();
    return TNode<Symbol> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=34&c=1
TNode<String> kResolveString_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<String> tmp0;
    tmp0 = CodeStubAssembler(state_).ResolveStringConstant();
    return TNode<String> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=47&c=1
TNode<Context> ExtractHandlerContextInternal_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_handler, compiler::CodeAssemblerLabel* label_NotFound)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Goto(&block5, p_handler);
    }

    TNode<Object> phi_bb5_2;
    TNode<BoolT> tmp0;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_2);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp0, &block3, std::vector<compiler::Node*> { phi_bb5_2 }, &block4, std::vector<compiler::Node*> { phi_bb5_2 });
    }

    TNode<Object> phi_bb3_2;
    TNode<JSBoundFunction> tmp1;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_2);
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_JSBoundFunction_1(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb3_2 }, &label2);
        ca_.Goto(&block8, phi_bb3_2, phi_bb3_2, phi_bb3_2);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block9, phi_bb3_2, phi_bb3_2, phi_bb3_2);
        }
    }

    TNode<Object> phi_bb9_2;
    TNode<Object> phi_bb9_3;
    TNode<Object> phi_bb9_4;
    TNode<JSProxy> tmp3;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_2, &phi_bb9_3, &phi_bb9_4);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Cast_JSProxy_1(state_, TNode<Context> { p_context }, TNode<Object> { ca_.UncheckedCast<Object>(phi_bb9_3) }, &label4);
        ca_.Goto(&block12, phi_bb9_2, phi_bb9_3);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block13, phi_bb9_2, phi_bb9_3);
        }
    }

    TNode<Object> phi_bb8_2;
    TNode<Object> phi_bb8_3;
    TNode<Object> phi_bb8_4;
    TNode<IntPtrT> tmp5;
    TNode<JSReceiver> tmp6;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_2, &phi_bb8_3, &phi_bb8_4);
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp6 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference { tmp1, tmp5 });
        ca_.Goto(&block6, tmp6, phi_bb8_3);
    }

    TNode<Object> phi_bb13_2;
    TNode<Object> phi_bb13_3;
    TNode<JSFunction> tmp7;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_3);
        compiler::CodeAssemblerLabel label8(&ca_);
        tmp7 = Cast_JSFunction_1(state_, TNode<Context> { p_context }, TNode<Object> { ca_.UncheckedCast<Object>(phi_bb13_3) }, &label8);
        ca_.Goto(&block16, phi_bb13_2, phi_bb13_3);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block17, phi_bb13_2, phi_bb13_3);
        }
    }

    TNode<Object> phi_bb12_2;
    TNode<Object> phi_bb12_3;
    TNode<IntPtrT> tmp9;
    TNode<HeapObject> tmp10;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_2, &phi_bb12_3);
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp3, tmp9 });
        ca_.Goto(&block6, tmp10, phi_bb12_3);
    }

    TNode<Object> phi_bb17_2;
    TNode<Object> phi_bb17_3;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_2, &phi_bb17_3);
        ca_.Goto(&block4, phi_bb17_2);
    }

    TNode<Object> phi_bb16_2;
    TNode<Object> phi_bb16_3;
    TNode<IntPtrT> tmp11;
    TNode<Context> tmp12;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_2, &phi_bb16_3);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp12 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference { tmp7, tmp11 });
        ca_.Goto(&block18);
    }

    TNode<Object> phi_bb6_2;
    TNode<Object> phi_bb6_3;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_2, &phi_bb6_3);
        ca_.Goto(&block5, phi_bb6_2);
    }

    TNode<Object> phi_bb4_2;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_2);
        ca_.Goto(label_NotFound);
    }

    ca_.Bind(&block18);
    return TNode<Context> { tmp12 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=70&c=1
TNode<Context> ExtractHandlerContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_handler)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Context> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = ExtractHandlerContextInternal_0(state_, TNode<Context> { p_context }, TNode<HeapObject> { p_handler }, &label1);
        ca_.Goto(&block4);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block5);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block1, p_context);
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block1, tmp0);
    }

    TNode<Context> phi_bb1_2;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_2);
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Context> { phi_bb1_2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=79&c=1
TNode<Context> ExtractHandlerContext_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_primary, TNode<HeapObject> p_secondary)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Context> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = ExtractHandlerContextInternal_0(state_, TNode<Context> { p_context }, TNode<HeapObject> { p_primary }, &label1);
        ca_.Goto(&block6);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block7);
        }
    }

    TNode<Context> tmp2;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = ExtractHandlerContextInternal_0(state_, TNode<Context> { p_context }, TNode<HeapObject> { p_secondary }, &label3);
        ca_.Goto(&block8);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block9);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block1, tmp0);
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1, p_context);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block1, tmp2);
    }

    TNode<Context> phi_bb1_3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3);
        ca_.Goto(&block10);
    }

    ca_.Bind(&block10);
    return TNode<Context> { phi_bb1_3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=91&c=1
void MorphAndEnqueuePromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseReaction> p_promiseReaction,
    TNode<Object> p_argument, PromiseReaction::Type p_reactionType)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kFulfill)))) {
            ca_.Goto(&block2);
        } else {
            ca_.Goto(&block3);
        }
    }

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<HeapObject> tmp3;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_promiseReaction, tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp3 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_promiseReaction, tmp2 });
        ca_.Goto(&block4, tmp1, tmp3);
    }

    TNode<BoolT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<HeapObject> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<HeapObject> tmp8;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kReject)));
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { tmp4 },
            "static_assert(reactionType == kPromiseReactionReject) at "
            "https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=100&c=5");
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp6 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_promiseReaction, tmp5 });
        tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp8 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_promiseReaction, tmp7 });
        ca_.Goto(&block4, tmp6, tmp8);
    }

    TNode<HeapObject> phi_bb4_3;
    TNode<HeapObject> phi_bb4_4;
    TNode<Context> tmp9;
    TNode<BoolT> tmp10;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        tmp9 = ExtractHandlerContext_1(state_, TNode<Context> { p_context }, TNode<HeapObject> { phi_bb4_3 }, TNode<HeapObject> { phi_bb4_4 });
        tmp10 = FromConstexpr_bool_constexpr_bool_0(
            state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kSize, PromiseReactionJobTask::kSizeOfAllPromiseReactionJobTasks)));
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { tmp10 },
            "static_assert(kPromiseReactionSize ==\n      kPromiseReactionJobTaskSizeOfAllPromiseReactionJobTasks) at "
            "https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=114&c=3");
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kFulfill)))) {
            ca_.Goto(&block5);
        } else {
            ca_.Goto(&block6);
        }
    }

    TNode<IntPtrT> tmp11;
    TNode<Object> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Map> tmp14;
    TNode<PromiseFulfillReactionJobTask> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<Undefined> tmp18;
    TNode<BoolT> tmp19;
    TNode<BoolT> tmp20;
    TNode<BoolT> tmp21;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        std::tie(tmp12, tmp13) = UnsafeConstCast_Map_0(
            state_, TorqueStructReference_Map_0 { TNode<Object> { p_promiseReaction }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        tmp14 = CodeStubAssembler(state_).PromiseFulfillReactionJobTaskMapConstant();
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp12, tmp13 }, tmp14);
        tmp15 = UnsafeCast_PromiseFulfillReactionJobTask_0(state_, TNode<Context> { p_context }, TNode<Object> { p_promiseReaction });
        tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp15, tmp16 }, p_argument);
        tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference { tmp15, tmp17 }, tmp9);
        tmp18 = ca_.CallBuiltin<Undefined>(Builtin::kEnqueueMicrotask, tmp9, tmp15);
        tmp19 = FromConstexpr_bool_constexpr_bool_0(
            state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kFulfillHandlerOffset, PromiseReactionJobTask::kHandlerOffset)));
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { tmp19 },
            "static_assert(kPromiseReactionFulfillHandlerOffset ==\n        kPromiseReactionJobTaskHandlerOffset) at "
            "https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=125&c=5");
        tmp20 = FromConstexpr_bool_constexpr_bool_0(state_,
            (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kPromiseOrCapabilityOffset, PromiseReactionJobTask::kPromiseOrCapabilityOffset)));
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { tmp20 },
            "static_assert(kPromiseReactionPromiseOrCapabilityOffset ==\n        kPromiseReactionJobTaskPromiseOrCapabilityOffset) at "
            "https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=128&c=5");
        tmp21 = FromConstexpr_bool_constexpr_bool_0(state_,
            (CodeStubAssembler(state_).ConstexprInt31Equal(
                PromiseReaction::kContinuationPreservedEmbedderDataOffset, PromiseReactionJobTask::kContinuationPreservedEmbedderDataOffset)));
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { tmp21 },
            "static_assert(kPromiseReactionContinuationPreservedEmbedderDataOffset ==\n          "
            "kPromiseReactionJobTaskContinuationPreservedEmbedderDataOffset) at "
            "https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=132&c=7");
        ca_.Goto(&block7);
    }

    TNode<BoolT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<Object> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<Map> tmp26;
    TNode<PromiseRejectReactionJobTask> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<Undefined> tmp31;
    TNode<BoolT> tmp32;
    TNode<BoolT> tmp33;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kReject)));
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { tmp22 },
            "static_assert(reactionType == kPromiseReactionReject) at "
            "https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=136&c=5");
        tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        std::tie(tmp24, tmp25) = UnsafeConstCast_Map_0(
            state_, TorqueStructReference_Map_0 { TNode<Object> { p_promiseReaction }, TNode<IntPtrT> { tmp23 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        tmp26 = CodeStubAssembler(state_).PromiseRejectReactionJobTaskMapConstant();
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp24, tmp25 }, tmp26);
        tmp27 = UnsafeCast_PromiseRejectReactionJobTask_0(state_, TNode<Context> { p_context }, TNode<Object> { p_promiseReaction });
        tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp27, tmp28 }, p_argument);
        tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference { tmp27, tmp29 }, tmp9);
        tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { tmp27, tmp30 }, phi_bb4_3);
        tmp31 = ca_.CallBuiltin<Undefined>(Builtin::kEnqueueMicrotask, tmp9, tmp27);
        tmp32 = FromConstexpr_bool_constexpr_bool_0(state_,
            (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kPromiseOrCapabilityOffset, PromiseReactionJobTask::kPromiseOrCapabilityOffset)));
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { tmp32 },
            "static_assert(kPromiseReactionPromiseOrCapabilityOffset ==\n        kPromiseReactionJobTaskPromiseOrCapabilityOffset) at "
            "https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=145&c=5");
        tmp33 = FromConstexpr_bool_constexpr_bool_0(state_,
            (CodeStubAssembler(state_).ConstexprInt31Equal(
                PromiseReaction::kContinuationPreservedEmbedderDataOffset, PromiseReactionJobTask::kContinuationPreservedEmbedderDataOffset)));
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { tmp33 },
            "static_assert(kPromiseReactionContinuationPreservedEmbedderDataOffset ==\n          "
            "kPromiseReactionJobTaskContinuationPreservedEmbedderDataOffset) at "
            "https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=149&c=7");
        ca_.Goto(&block7);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        ca_.Goto(&block8);
    }

    ca_.Bind(&block8);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=156&c=1
void TriggerPromiseReactions_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_reactions, TNode<Object> p_argument, PromiseReaction::Type p_reactionType)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZero_0(state_);
        ca_.Goto(&block4, p_reactions, tmp0);
    }

    TNode<Object> phi_bb4_3;
    TNode<Object> phi_bb4_4;
    TNode<BoolT> tmp1;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp1, &block2, std::vector<compiler::Node*> { phi_bb4_3, phi_bb4_4 }, &block3, std::vector<compiler::Node*> { phi_bb4_3, phi_bb4_4 });
    }

    TNode<Object> phi_bb2_3;
    TNode<Object> phi_bb2_4;
    TNode<Smi> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_3, &phi_bb2_4);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_Zero_0(state_, TNode<Object> { phi_bb2_3 }, &label3);
        ca_.Goto(&block7, phi_bb2_3, phi_bb2_4, phi_bb2_3, phi_bb2_3);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8, phi_bb2_3, phi_bb2_4, phi_bb2_3, phi_bb2_3);
        }
    }

    TNode<Object> phi_bb8_3;
    TNode<Object> phi_bb8_4;
    TNode<Object> phi_bb8_5;
    TNode<Object> phi_bb8_6;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_3, &phi_bb8_4, &phi_bb8_5, &phi_bb8_6);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { ca_.UncheckedCast<PromiseReaction>(phi_bb8_5), tmp4 });
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { ca_.UncheckedCast<PromiseReaction>(phi_bb8_5), tmp6 }, phi_bb8_4);
        ca_.Goto(&block4, tmp5, ca_.UncheckedCast<PromiseReaction>(phi_bb8_5));
    }

    TNode<Object> phi_bb7_3;
    TNode<Object> phi_bb7_4;
    TNode<Object> phi_bb7_5;
    TNode<Object> phi_bb7_6;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_3, &phi_bb7_4, &phi_bb7_5, &phi_bb7_6);
        ca_.Goto(&block3, phi_bb7_3, phi_bb7_4);
    }

    TNode<Object> phi_bb3_3;
    TNode<Object> phi_bb3_4;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_3, &phi_bb3_4);
        ca_.Goto(&block11, phi_bb3_4, phi_bb3_4);
    }

    TNode<Object> phi_bb11_3;
    TNode<Object> phi_bb11_4;
    TNode<BoolT> tmp7;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_3, &phi_bb11_4);
        tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp7, &block9, std::vector<compiler::Node*> { phi_bb11_3, phi_bb11_4 }, &block10, std::vector<compiler::Node*> { phi_bb11_3, phi_bb11_4 });
    }

    TNode<Object> phi_bb9_3;
    TNode<Object> phi_bb9_4;
    TNode<Smi> tmp8;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_3, &phi_bb9_4);
        compiler::CodeAssemblerLabel label9(&ca_);
        tmp8 = Cast_Zero_0(state_, TNode<Object> { phi_bb9_3 }, &label9);
        ca_.Goto(&block14, phi_bb9_3, phi_bb9_4, phi_bb9_3, phi_bb9_3);
        if (label9.is_used()) {
            ca_.Bind(&label9);
            ca_.Goto(&block15, phi_bb9_3, phi_bb9_4, phi_bb9_3, phi_bb9_3);
        }
    }

    TNode<Object> phi_bb15_3;
    TNode<Object> phi_bb15_4;
    TNode<Object> phi_bb15_5;
    TNode<Object> phi_bb15_6;
    TNode<IntPtrT> tmp10;
    TNode<Object> tmp11;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_3, &phi_bb15_4, &phi_bb15_5, &phi_bb15_6);
        tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { ca_.UncheckedCast<PromiseReaction>(phi_bb15_5), tmp10 });
        MorphAndEnqueuePromiseReaction_0(state_, TNode<Context> { p_context }, TNode<PromiseReaction> { ca_.UncheckedCast<PromiseReaction>(phi_bb15_5) },
            TNode<Object> { p_argument }, p_reactionType);
        ca_.Goto(&block11, tmp11, phi_bb15_4);
    }

    TNode<Object> phi_bb14_3;
    TNode<Object> phi_bb14_4;
    TNode<Object> phi_bb14_5;
    TNode<Object> phi_bb14_6;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_3, &phi_bb14_4, &phi_bb14_5, &phi_bb14_6);
        ca_.Goto(&block10, phi_bb14_3, phi_bb14_4);
    }

    TNode<Object> phi_bb10_3;
    TNode<Object> phi_bb10_4;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_3, &phi_bb10_4);
        ca_.Goto(&block16);
    }

    ca_.Bind(&block16);
}

TF_BUILTIN(FulfillPromise, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<JSPromise> parameter1 = UncheckedParameter<JSPromise>(Descriptor::kPromise);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Undefined> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        RunContextPromiseHookResolve_0(state_, TNode<Context> { parameter0 }, TNode<JSPromise> { parameter1 });
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { parameter1, tmp0 });
        tmp2 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { parameter1, tmp3 }, parameter2);
        Method_JSPromise_SetStatus_0(state_, TNode<JSPromise> { parameter1 }, Promise::PromiseState::kFulfilled);
        TriggerPromiseReactions_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp2 }, TNode<Object> { parameter2 }, PromiseReaction::kFulfill);
        tmp4 = Undefined_0(state_);
        CodeStubAssembler(state_).Return(tmp4);
    }
}

TF_BUILTIN(RejectPromise, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<JSPromise> parameter1 = UncheckedParameter<JSPromise>(Descriptor::kPromise);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kReason);
    USE(parameter2);
    TNode<Boolean> parameter3 = UncheckedParameter<Boolean>(Descriptor::kDebugEvent);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = PromiseBuiltinsAssembler(state_).PromiseHookFlags();
        tmp1 = PromiseBuiltinsAssembler(state_).IsIsolatePromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate(TNode<Uint32T> { tmp0 });
        ca_.Branch(tmp1, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block5, tmp2);
    }

    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = Method_JSPromise_HasHandler_0(state_, TNode<JSPromise> { parameter1 });
        tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp3 });
        ca_.Goto(&block5, tmp4);
    }

    TNode<BoolT> phi_bb5_6;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_6);
        ca_.Branch(phi_bb5_6, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp5;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp5 = CodeStubAssembler(state_).CallRuntime(Runtime::kRejectPromise, parameter0, parameter1, parameter2, parameter3);
        CodeStubAssembler(state_).Return(tmp5);
    }

    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Undefined> tmp10;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        RunContextPromiseHookResolve_1(state_, TNode<Context> { parameter0 }, TNode<JSPromise> { parameter1 }, TNode<Uint32T> { tmp0 });
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp7 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { parameter1, tmp6 });
        tmp8 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp7 });
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { parameter1, tmp9 }, parameter2);
        Method_JSPromise_SetStatus_0(state_, TNode<JSPromise> { parameter1 }, Promise::PromiseState::kRejected);
        TriggerPromiseReactions_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp8 }, TNode<Object> { parameter2 }, PromiseReaction::kReject);
        tmp10 = Undefined_0(state_);
        CodeStubAssembler(state_).Return(tmp10);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=272&c=1
TNode<IntPtrT> FromConstexpr_PromiseResolvingFunctionContextSlot_constexpr_kPromiseSlot_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseResolvingFunctionContextSlot p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=272&c=1
TNode<IntPtrT> FromConstexpr_PromiseResolvingFunctionContextSlot_constexpr_kAlreadyResolvedSlot_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseResolvingFunctionContextSlot p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=272&c=1
TNode<IntPtrT> FromConstexpr_PromiseResolvingFunctionContextSlot_constexpr_kDebugEventSlot_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseResolvingFunctionContextSlot p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=272&c=1
TNode<IntPtrT> FromConstexpr_PromiseResolvingFunctionContextSlot_constexpr_kPromiseContextLength_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseResolvingFunctionContextSlot p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=272&c=1
TNode<IntPtrT> kPromiseSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseResolvingFunctionContextSlot_constexpr_kPromiseSlot_0(
        state_, PromiseBuiltins::PromiseResolvingFunctionContextSlot::kPromiseSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=272&c=1
TNode<IntPtrT> kAlreadyResolvedSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseResolvingFunctionContextSlot_constexpr_kAlreadyResolvedSlot_0(
        state_, PromiseBuiltins::PromiseResolvingFunctionContextSlot::kAlreadyResolvedSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=272&c=1
TNode<IntPtrT> kDebugEventSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_PromiseResolvingFunctionContextSlot_constexpr_kDebugEventSlot_0(
        state_, PromiseBuiltins::PromiseResolvingFunctionContextSlot::kDebugEventSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=281&c=1
TNode<IntPtrT> FromConstexpr_FunctionContextSlot_constexpr_kCapabilitySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::FunctionContextSlot p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=281&c=1
TNode<IntPtrT> FromConstexpr_FunctionContextSlot_constexpr_kCapabilitiesContextLength_0(
    compiler::CodeAssemblerState* state_, PromiseBuiltins::FunctionContextSlot p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=281&c=1
TNode<IntPtrT> kCapabilitySlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_FunctionContextSlot_constexpr_kCapabilitySlot_0(state_, PromiseBuiltins::FunctionContextSlot::kCapabilitySlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=287&c=1
TNode<Context> CreatePromiseCapabilitiesExecutorContext_0(
    compiler::CodeAssemblerState* state_, TNode<NativeContext> p_nativeContext, TNode<PromiseCapability> p_capability)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Context> tmp1;
    TNode<Context> tmp2;
    TNode<IntPtrT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, PromiseBuiltins::FunctionContextSlot::kCapabilitiesContextLength);
        tmp1 = AllocateSyntheticFunctionContext_1(state_, TNode<NativeContext> { p_nativeContext }, TNode<IntPtrT> { tmp0 });
        tmp2 = (TNode<Context> { tmp1 });
        tmp3 = kCapabilitySlot_0(state_);
        InitContextSlot_PromiseCapabilitiesExecutorContext_PromiseCapabilitiesExecutorContext_PromiseCapability_PromiseCapability_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp3 }, TNode<PromiseCapability> { p_capability });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Context> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=300&c=1
TNode<PromiseCapability> CreatePromiseCapability_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_promise, TNode<HeapObject> p_resolve, TNode<HeapObject> p_reject)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Map> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<PromiseCapability> tmp9;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kPromiseCapabilityMap_0(state_);
        tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp4 = AllocateFromNew_0(state_, TNode<IntPtrT> { tmp3 }, TNode<Map> { tmp0 }, TNode<BoolT> { tmp1 }, TNode<BoolT> { tmp2 });
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp4, tmp5 }, tmp0);
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { tmp4, tmp6 }, p_promise);
        tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp4, tmp7 }, p_resolve);
        tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp4, tmp8 }, p_reject);
        tmp9 = TORQUE_CAST(TNode<HeapObject> { tmp4 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<PromiseCapability> { tmp9 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=324&c=1
TorqueStructPromiseResolvingFunctions CreatePromiseResolvingFunctions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TNode<JSPromise> p_promise, TNode<Boolean> p_debugEvent, TNode<NativeContext> p_nativeContext)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<JSFunction> tmp1;
    TNode<JSFunction> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CreatePromiseResolvingFunctionsContext_0(
            state_, TNode<Context> { p_context }, TNode<JSPromise> { p_promise }, TNode<Boolean> { p_debugEvent }, TNode<NativeContext> { p_nativeContext });
        tmp1 = CodeStubAssembler(state_).AllocateRootFunctionWithContext(
            RootIndex::kPromiseCapabilityDefaultResolveSharedFun, TNode<Context> { tmp0 }, TNode<NativeContext> { p_nativeContext });
        tmp2 = CodeStubAssembler(state_).AllocateRootFunctionWithContext(
            RootIndex::kPromiseCapabilityDefaultRejectSharedFun, TNode<Context> { tmp0 }, TNode<NativeContext> { p_nativeContext });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructPromiseResolvingFunctions { TNode<JSFunction> { tmp1 }, TNode<JSFunction> { tmp2 }, TNode<Context> { tmp0 } };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=345&c=1
TNode<PromiseCapability> InnerNewPromiseCapability_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_constructor, TNode<Boolean> p_debugEvent)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<PromiseCapability> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<PromiseCapability> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<JSFunction> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context> { p_context });
        tmp1 = PROMISE_FUNCTION_INDEX_0(state_);
        std::tie(tmp2, tmp3) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext> { tmp0 }, TNode<IntPtrT> { tmp1 }).Flatten();
        tmp4 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference { tmp2, tmp3 });
        tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { p_constructor }, TNode<HeapObject> { tmp4 });
        ca_.Branch(tmp5, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<JSPromise> tmp6;
    TNode<JSFunction> tmp7;
    TNode<JSFunction> tmp8;
    TNode<Context> tmp9;
    TNode<PromiseCapability> tmp10;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp6 = NewJSPromise_1(state_, TNode<Context> { p_context });
        std::tie(tmp7, tmp8, tmp9) = CreatePromiseResolvingFunctions_0(
            state_, TNode<Context> { p_context }, TNode<JSPromise> { tmp6 }, TNode<Boolean> { p_debugEvent }, TNode<NativeContext> { tmp0 })
                                         .Flatten();
        tmp10 = CreatePromiseCapability_0(state_, TNode<HeapObject> { tmp6 }, TNode<HeapObject> { tmp7 }, TNode<HeapObject> { tmp8 });
        ca_.Goto(&block1, tmp10);
    }

    TNode<Undefined> tmp11;
    TNode<Undefined> tmp12;
    TNode<Undefined> tmp13;
    TNode<PromiseCapability> tmp14;
    TNode<Context> tmp15;
    TNode<JSFunction> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<JSReceiver> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<Object> tmp21;
    TNode<BoolT> tmp22;
    TNode<BoolT> tmp23;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp11 = Undefined_0(state_);
        tmp12 = Undefined_0(state_);
        tmp13 = Undefined_0(state_);
        tmp14 = CreatePromiseCapability_0(state_, TNode<HeapObject> { tmp11 }, TNode<HeapObject> { tmp12 }, TNode<HeapObject> { tmp13 });
        tmp15 = CreatePromiseCapabilitiesExecutorContext_0(state_, TNode<NativeContext> { tmp0 }, TNode<PromiseCapability> { tmp14 });
        tmp16 = CodeStubAssembler(state_).AllocateRootFunctionWithContext(
            RootIndex::kPromiseGetCapabilitiesExecutorSharedFun, TNode<Context> { tmp15 }, TNode<NativeContext> { tmp0 });
        tmp17 = UnsafeCast_Constructor_0(state_, TNode<Context> { p_context }, TNode<Object> { p_constructor });
        tmp18 = CodeStubAssembler(state_).Construct(TNode<Context> { p_context }, TNode<JSReceiver> { tmp17 }, TNode<Object> { tmp16 });
        tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { tmp14, tmp19 }, tmp18);
        tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp21 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp14, tmp20 });
        tmp22 = Is_Callable_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp21 });
        tmp23 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp22 });
        ca_.Branch(tmp23, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp24;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block9, tmp24);
    }

    TNode<IntPtrT> tmp25;
    TNode<Object> tmp26;
    TNode<BoolT> tmp27;
    TNode<BoolT> tmp28;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp26 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp14, tmp25 });
        tmp27 = Is_Callable_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp26 });
        tmp28 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp27 });
        ca_.Goto(&block9, tmp28);
    }

    TNode<BoolT> phi_bb9_10;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_10);
        ca_.Branch(phi_bb9_10, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kPromiseNonCallable);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block1, tmp14);
    }

    TNode<PromiseCapability> phi_bb1_3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3);
        ca_.Goto(&block10, phi_bb1_3);
    }

    TNode<PromiseCapability> phi_bb10_3;
    ca_.Bind(&block10, &phi_bb10_3);
    return TNode<PromiseCapability> { phi_bb10_3 };
}

TF_BUILTIN(NewPromiseCapability, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kMaybeConstructor);
    USE(parameter1);
    TNode<Boolean> parameter2 = UncheckedParameter<Boolean>(Descriptor::kDebugEvent);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_Smi_0(state_, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    TNode<BoolT> tmp2;
    TNode<BoolT> tmp3;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp2 = CodeStubAssembler(state_).IsConstructor(TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter1) });
        tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp2 });
        ca_.Branch(tmp3, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { parameter0 }, MessageTemplate::kNotConstructor, TNode<Object> { parameter1 });
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { parameter0 }, MessageTemplate::kNotConstructor, TNode<Object> { parameter1 });
    }

    TNode<PromiseCapability> tmp4;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp4 = InnerNewPromiseCapability_0(
            state_, TNode<Context> { parameter0 }, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter1) }, TNode<Boolean> { parameter2 });
        CodeStubAssembler(state_).Return(tmp4);
    }
}

TF_BUILTIN(PromiseCapabilityDefaultReject, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kReason);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<JSPromise> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Boolean> tmp8;
    TNode<True> tmp9;
    TNode<BoolT> tmp10;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = kPromiseSlot_0(state_);
        std::tie(tmp2, tmp3)
            = ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_JSPromise_0(state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp1 })
                  .Flatten();
        tmp4 = CodeStubAssembler(state_).LoadReference<JSPromise>(CodeStubAssembler::Reference { tmp2, tmp3 });
        tmp5 = kAlreadyResolvedSlot_0(state_);
        std::tie(tmp6, tmp7)
            = ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_Boolean_0(state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp5 })
                  .Flatten();
        tmp8 = CodeStubAssembler(state_).LoadReference<Boolean>(CodeStubAssembler::Reference { tmp6, tmp7 });
        tmp9 = True_0(state_);
        tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { tmp8 }, TNode<HeapObject> { tmp9 });
        ca_.Branch(tmp10, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp11;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp11 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRejectAfterResolved, tmp0, tmp4, parameter2);
        CodeStubAssembler(state_).Return(tmp11);
    }

    TNode<IntPtrT> tmp12;
    TNode<Object> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<True> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<Object> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Boolean> tmp19;
    TNode<Object> tmp20;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp12 = kAlreadyResolvedSlot_0(state_);
        std::tie(tmp13, tmp14)
            = ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_Boolean_0(state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp12 })
                  .Flatten();
        tmp15 = True_0(state_);
        CodeStubAssembler(state_).StoreReference<Boolean>(CodeStubAssembler::Reference { tmp13, tmp14 }, tmp15);
        tmp16 = kDebugEventSlot_0(state_);
        std::tie(tmp17, tmp18)
            = ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_Boolean_0(state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp16 })
                  .Flatten();
        tmp19 = CodeStubAssembler(state_).LoadReference<Boolean>(CodeStubAssembler::Reference { tmp17, tmp18 });
        tmp20 = ca_.CallBuiltin<Object>(Builtin::kRejectPromise, tmp0, tmp4, parameter2, tmp19);
        CodeStubAssembler(state_).Return(tmp20);
    }
}

TF_BUILTIN(PromiseCapabilityDefaultResolve, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kResolution);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<JSPromise> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Boolean> tmp8;
    TNode<True> tmp9;
    TNode<BoolT> tmp10;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = kPromiseSlot_0(state_);
        std::tie(tmp2, tmp3)
            = ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_JSPromise_0(state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp1 })
                  .Flatten();
        tmp4 = CodeStubAssembler(state_).LoadReference<JSPromise>(CodeStubAssembler::Reference { tmp2, tmp3 });
        tmp5 = kAlreadyResolvedSlot_0(state_);
        std::tie(tmp6, tmp7)
            = ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_Boolean_0(state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp5 })
                  .Flatten();
        tmp8 = CodeStubAssembler(state_).LoadReference<Boolean>(CodeStubAssembler::Reference { tmp6, tmp7 });
        tmp9 = True_0(state_);
        tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { tmp8 }, TNode<HeapObject> { tmp9 });
        ca_.Branch(tmp10, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp11;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp11 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseResolveAfterResolved, tmp0, tmp4, parameter2);
        CodeStubAssembler(state_).Return(tmp11);
    }

    TNode<IntPtrT> tmp12;
    TNode<Object> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<True> tmp15;
    TNode<Object> tmp16;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp12 = kAlreadyResolvedSlot_0(state_);
        std::tie(tmp13, tmp14)
            = ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_Boolean_0(state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp12 })
                  .Flatten();
        tmp15 = True_0(state_);
        CodeStubAssembler(state_).StoreReference<Boolean>(CodeStubAssembler::Reference { tmp13, tmp14 }, tmp15);
        tmp16 = ca_.CallBuiltin<Object>(Builtin::kResolvePromise, tmp0, tmp4, parameter2);
        CodeStubAssembler(state_).Return(tmp16);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=450&c=1
void PerformPromiseThenImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<HeapObject> p_onFulfilled,
    TNode<HeapObject> p_onRejected, TNode<HeapObject> p_resultPromiseOrCapability)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<PromiseReactionJobTask, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Int32T> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Method_JSPromise_Status_0(state_, TNode<JSPromise> { p_promise });
        tmp1 = FromConstexpr_PromiseState_constexpr_kPending_0(state_, Promise::PromiseState::kPending);
        tmp2 = PromiseStateEquals_0(state_, TNode<Int32T> { tmp0 }, TNode<Int32T> { tmp1 });
        ca_.Branch(tmp2, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<PromiseReaction> tmp6;
    TNode<IntPtrT> tmp7;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp4 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { p_promise, tmp3 });
        tmp5 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp4 });
        tmp6 = NewPromiseReaction_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp5 }, TNode<HeapObject> { p_resultPromiseOrCapability },
            TNode<HeapObject> { p_onFulfilled }, TNode<HeapObject> { p_onRejected });
        tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { p_promise, tmp7 }, tmp6);
        ca_.Goto(&block4);
    }

    TNode<IntPtrT> tmp8;
    TNode<Object> tmp9;
    TNode<Int32T> tmp10;
    TNode<Int32T> tmp11;
    TNode<BoolT> tmp12;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp9 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { p_promise, tmp8 });
        tmp10 = Method_JSPromise_Status_0(state_, TNode<JSPromise> { p_promise });
        tmp11 = FromConstexpr_PromiseState_constexpr_kFulfilled_0(state_, Promise::PromiseState::kFulfilled);
        tmp12 = PromiseStateEquals_0(state_, TNode<Int32T> { tmp10 }, TNode<Int32T> { tmp11 });
        ca_.Branch(tmp12, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Context> tmp13;
    TNode<PromiseFulfillReactionJobTask> tmp14;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp13 = ExtractHandlerContext_1(state_, TNode<Context> { p_context }, TNode<HeapObject> { p_onFulfilled }, TNode<HeapObject> { p_onRejected });
        tmp14 = NewPromiseFulfillReactionJobTask_0(state_, TNode<Context> { p_context }, TNode<Context> { tmp13 }, TNode<Object> { tmp9 },
            TNode<HeapObject> { p_onFulfilled }, TNode<HeapObject> { p_resultPromiseOrCapability });
        ca_.Goto(&block7, tmp14, tmp13);
    }

    TNode<Context> tmp15;
    TNode<PromiseRejectReactionJobTask> tmp16;
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp15 = ExtractHandlerContext_1(state_, TNode<Context> { p_context }, TNode<HeapObject> { p_onRejected }, TNode<HeapObject> { p_onFulfilled });
        tmp16 = NewPromiseRejectReactionJobTask_0(state_, TNode<Context> { p_context }, TNode<Context> { tmp15 }, TNode<Object> { tmp9 },
            TNode<HeapObject> { p_onRejected }, TNode<HeapObject> { p_resultPromiseOrCapability });
        tmp17 = Method_JSPromise_HasHandler_0(state_, TNode<JSPromise> { p_promise });
        tmp18 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp17 });
        ca_.Branch(tmp18, &block12, std::vector<compiler::Node*> {}, &block13, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp19;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp19 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRevokeReject, p_context, p_promise);
        ca_.Goto(&block13);
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block7, tmp16, tmp15);
    }

    TNode<PromiseReactionJobTask> phi_bb7_6;
    TNode<Context> phi_bb7_7;
    TNode<Undefined> tmp20;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_6, &phi_bb7_7);
        tmp20 = ca_.CallBuiltin<Undefined>(Builtin::kEnqueueMicrotask, phi_bb7_7, phi_bb7_6);
        ca_.Goto(&block4);
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        Method_JSPromise_SetHasHandler_0(state_, TNode<JSPromise> { p_promise });
        ca_.Goto(&block14);
    }

    ca_.Bind(&block14);
}

TF_BUILTIN(PerformPromiseThenFunction, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kOnFulfilled);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kOnRejected);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSPromise> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_JSPromise_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<JSReceiver> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_Callable_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label3);
        ca_.Goto(&block7);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<JSReceiver> tmp4;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = Cast_Callable_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter3 }, &label5);
        ca_.Goto(&block11);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block12);
        }
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Undefined> tmp6;
    TNode<Undefined> tmp7;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp6 = Undefined_0(state_);
        PerformPromiseThenImpl_0(state_, TNode<Context> { parameter0 }, TNode<JSPromise> { tmp0 }, TNode<HeapObject> { tmp2 }, TNode<HeapObject> { tmp4 },
            TNode<HeapObject> { tmp6 });
        tmp7 = Undefined_0(state_);
        CodeStubAssembler(state_).Return(tmp7);
    }
}

TF_BUILTIN(PerformPromiseThen, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<JSPromise> parameter1 = UncheckedParameter<JSPromise>(Descriptor::kPromise);
    USE(parameter1);
    TNode<HeapObject> parameter2 = UncheckedParameter<HeapObject>(Descriptor::kOnFulfilled);
    USE(parameter2);
    TNode<HeapObject> parameter3 = UncheckedParameter<HeapObject>(Descriptor::kOnRejected);
    USE(parameter3);
    TNode<HeapObject> parameter4 = UncheckedParameter<HeapObject>(Descriptor::kResultPromise);
    USE(parameter4);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        PerformPromiseThenImpl_0(state_, TNode<Context> { parameter0 }, TNode<JSPromise> { parameter1 }, TNode<HeapObject> { parameter2 },
            TNode<HeapObject> { parameter3 }, TNode<HeapObject> { parameter4 });
        CodeStubAssembler(state_).Return(parameter4);
    }
}

TF_BUILTIN(PromiseReject, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kReason);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { parameter0 }, MessageTemplate::kCalledOnNonObject, "PromiseReject");
    }

    TNode<IntPtrT> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<JSFunction> tmp5;
    TNode<BoolT> tmp6;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp2 = PROMISE_FUNCTION_INDEX_0(state_);
        std::tie(tmp3, tmp4) = NativeContextSlot_NativeContext_JSFunction_0(state_, TNode<NativeContext> { parameter0 }, TNode<IntPtrT> { tmp2 }).Flatten();
        tmp5 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference { tmp3, tmp4 });
        tmp6 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { tmp5 }, TNode<HeapObject> { tmp0 });
        ca_.Branch(tmp6, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<JSPromise> tmp7;
    TNode<Object> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp7 = NewJSPromise_2(state_, TNode<Context> { parameter0 }, Promise::PromiseState::kRejected, TNode<Object> { parameter2 });
        tmp8 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRejectEventFromStack, parameter0, tmp7, parameter2);
        CodeStubAssembler(state_).Return(tmp7);
    }

    TNode<True> tmp9;
    TNode<PromiseCapability> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<Object> tmp12;
    TNode<JSReceiver> tmp13;
    TNode<Undefined> tmp14;
    TNode<Object> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<HeapObject> tmp17;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp9 = True_0(state_);
        tmp10 = ca_.CallBuiltin<PromiseCapability>(Builtin::kNewPromiseCapability, parameter0, tmp0, tmp9);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp12 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp10, tmp11 });
        tmp13 = UnsafeCast_Callable_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp12 });
        tmp14 = Undefined_0(state_);
        tmp15 = CodeStubAssembler(state_).Call(TNode<Context> { parameter0 }, TNode<Object> { tmp13 }, TNode<Object> { tmp14 }, TNode<Object> { parameter2 });
        tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp17 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp10, tmp16 });
        CodeStubAssembler(state_).Return(tmp17);
    }
}

TF_BUILTIN(PromiseGetCapabilitiesExecutor, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kResolve);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kReject);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<PromiseCapability> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Object> tmp6;
    TNode<Undefined> tmp7;
    TNode<BoolT> tmp8;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = kCapabilitySlot_0(state_);
        std::tie(tmp2, tmp3) = ContextSlot_PromiseCapabilitiesExecutorContext_PromiseCapabilitiesExecutorContext_PromiseCapability_0(
            state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp1 })
                                   .Flatten();
        tmp4 = CodeStubAssembler(state_).LoadReference<PromiseCapability>(CodeStubAssembler::Reference { tmp2, tmp3 });
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp6 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp4, tmp5 });
        tmp7 = Undefined_0(state_);
        tmp8 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp6 }, TNode<HeapObject> { tmp7 });
        ca_.Branch(tmp8, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp9;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block5, tmp9);
    }

    TNode<IntPtrT> tmp10;
    TNode<Object> tmp11;
    TNode<Undefined> tmp12;
    TNode<BoolT> tmp13;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp4, tmp10 });
        tmp12 = Undefined_0(state_);
        tmp13 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp11 }, TNode<HeapObject> { tmp12 });
        ca_.Goto(&block5, tmp13);
    }

    TNode<BoolT> phi_bb5_7;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_7);
        ca_.Branch(phi_bb5_7, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { tmp0 }, MessageTemplate::kPromiseExecutorAlreadyInvoked);
    }

    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<Undefined> tmp16;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp4, tmp14 }, parameter2);
        tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp4, tmp15 }, parameter3);
        tmp16 = Undefined_0(state_);
        CodeStubAssembler(state_).Return(tmp16);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=559&c=1
TNode<BoolT> IsPromiseResolveLookupChainIntact_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<JSReceiver> p_constructor)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = IsForceSlowPath_0(state_);
        ca_.Branch(tmp0, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp1;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block1, tmp1);
    }

    TNode<IntPtrT> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<JSFunction> tmp5;
    TNode<BoolT> tmp6;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp2 = PROMISE_FUNCTION_INDEX_0(state_);
        std::tie(tmp3, tmp4) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext> { p_nativeContext }, TNode<IntPtrT> { tmp2 }).Flatten();
        tmp5 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference { tmp3, tmp4 });
        tmp6 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { tmp5 }, TNode<HeapObject> { p_constructor });
        ca_.Branch(tmp6, &block4, std::vector<compiler::Node*> {}, &block5, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp7 = CodeStubAssembler(state_).IsPromiseResolveProtectorCellInvalid();
        tmp8 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp7 });
        ca_.Goto(&block6, tmp8);
    }

    TNode<BoolT> tmp9;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block6, tmp9);
    }

    TNode<BoolT> phi_bb6_5;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_5);
        ca_.Goto(&block1, phi_bb6_5);
    }

    TNode<BoolT> phi_bb1_3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3);
        ca_.Goto(&block7, phi_bb1_3);
    }

    TNode<BoolT> phi_bb7_3;
    ca_.Bind(&block7, &phi_bb7_3);
    return TNode<BoolT> { phi_bb7_3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=569&c=1
TNode<Object> GetPromiseResolve_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<JSReceiver> p_constructor)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Undefined> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Undefined_0(state_);
        tmp1 = IsPromiseResolveLookupChainIntact_0(
            state_, TNode<Context> { p_context }, TNode<NativeContext> { p_nativeContext }, TNode<JSReceiver> { p_constructor });
        tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp1 });
        ca_.Branch(tmp2, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> { tmp0 });
    }

    TNode<String> tmp3;
    TNode<Object> tmp4;
    TNode<JSReceiver> tmp5;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = kResolveString_0(state_);
        tmp4 = CodeStubAssembler(state_).GetProperty(TNode<Context> { p_context }, TNode<Object> { p_constructor }, TNode<Object> { tmp3 });
        compiler::CodeAssemblerLabel label6(&ca_);
        tmp5 = Cast_Callable_1(state_, TNode<Context> { p_context }, TNode<Object> { tmp4 }, &label6);
        ca_.Goto(&block6);
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block7);
        }
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kCalledNonCallable, "resolve");
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block3, tmp5);
    }

    TNode<Object> phi_bb3_3;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_3);
        ca_.Goto(&block8, phi_bb3_3);
    }

    TNode<Object> phi_bb8_3;
    ca_.Bind(&block8, &phi_bb8_3);
    return TNode<Object> { phi_bb8_3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=596&c=1
TNode<Object> CallResolve_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<Object> p_resolve, TNode<Object> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Undefined> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Undefined_0(state_);
        tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { p_resolve }, TNode<HeapObject> { tmp0 });
        ca_.Branch(tmp1, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp2 = ca_.CallBuiltin<Object>(Builtin::kPromiseResolve, p_context, p_constructor, p_value);
        ca_.Goto(&block1, tmp2);
    }

    TNode<JSReceiver> tmp3;
    TNode<Object> tmp4;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp3 = UnsafeCast_Callable_0(state_, TNode<Context> { p_context }, TNode<Object> { p_resolve });
        tmp4 = CodeStubAssembler(state_).Call(TNode<Context> { p_context }, TNode<Object> { tmp3 }, TNode<Object> { p_constructor }, TNode<Object> { p_value });
        ca_.Goto(&block1, tmp4);
    }

    TNode<Object> phi_bb1_4;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_4);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<Object> { phi_bb1_4 };
}

TF_BUILTIN(PromiseConstructorLazyDeoptContinuation, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kPromise);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kReject);
    USE(parameter3);
    TNode<Object> parameter4 = UncheckedParameter<Object>(Descriptor::kException);
    USE(parameter4);
    TNode<Object> parameter5 = UncheckedParameter<Object>(Descriptor::kResult);
    USE(parameter5);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Hole> tmp0;
    TNode<Hole> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TheHole_0(state_);
        CodeStubAssembler(state_).SetPendingMessage(TNode<HeapObject> { tmp0 });
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_TheHole_0(state_, TNode<Object> { parameter4 }, &label2);
        ca_.Goto(&block3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block4);
        }
    }

    TNode<Undefined> tmp3;
    TNode<Object> tmp4;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = Undefined_0(state_);
        tmp4 = CodeStubAssembler(state_).Call(
            TNode<Context> { parameter0 }, TNode<Object> { parameter3 }, TNode<Object> { tmp3 }, TNode<Object> { ca_.UncheckedCast<Object>(parameter4) });
        ca_.Goto(&block1);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block1);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        CodeStubAssembler(state_).Return(parameter2);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=118&c=6
TorqueStructReference_Map_0 UnsafeConstCast_Map_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Map_0 p_r)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1) = (TorqueStructReference_Map_0 { TNode<Object> { p_r.object }, TNode<IntPtrT> { p_r.offset }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_Map_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp1 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=121&c=9
TNode<PromiseFulfillReactionJobTask> UnsafeCast_PromiseFulfillReactionJobTask_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<PromiseFulfillReactionJobTask> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<PromiseFulfillReactionJobTask> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=140&c=9
TNode<PromiseRejectReactionJobTask> UnsafeCast_PromiseRejectReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<PromiseRejectReactionJobTask> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<PromiseRejectReactionJobTask> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=207&c=7
TNode<Object> UnsafeCast_Zero_OR_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Object> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=295&c=3
void InitContextSlot_PromiseCapabilitiesExecutorContext_PromiseCapabilitiesExecutorContext_PromiseCapability_PromiseCapability_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<PromiseCapability> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
        ca_.Branch(tmp5, &block18, std::vector<compiler::Node*> {}, &block19, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp6 });
        std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp7 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp8, tmp9 }, p_value);
        ca_.Goto(&block22);
    }

    if (block19.is_used()) {
        ca_.Bind(&block19);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block22);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=367&c=32
TNode<JSReceiver> UnsafeCast_Constructor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<JSReceiver> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=401&c=8
TorqueStructReference_JSPromise_0 ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_JSPromise_0(
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
        std::tie(tmp10, tmp11) = ReferenceCast_JSPromise_Object_0(
            state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_JSPromise_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=404&c=28
TorqueStructReference_Boolean_0 ContextSlot_PromiseResolvingFunctionContext_PromiseResolvingFunctionContext_Boolean_0(
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
        std::tie(tmp10, tmp11) = ReferenceCast_Boolean_Object_0(
            state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_Boolean_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=494&c=21
TNode<JSPromise> Cast_JSPromise_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
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
        tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object> { p_o }, &label1);
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

    TNode<JSPromise> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_JSPromise_0(state_, TNode<HeapObject> { tmp0 }, &label3);
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
    return TNode<JSPromise> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=521&c=23
TorqueStructReference_JSFunction_0 NativeContextSlot_NativeContext_JSFunction_0(
    compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext> { p_context }, TNode<IntPtrT> { p_index }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_JSFunction_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp1 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-abstract-operations.tq?l=548&c=8
TorqueStructReference_PromiseCapability_0 ContextSlot_PromiseCapabilitiesExecutorContext_PromiseCapabilitiesExecutorContext_PromiseCapability_0(
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
