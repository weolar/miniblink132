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
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-misc-tq-csa.h"
#include "torque-generated/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetIteratorStep_0(compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kCheckIteratorValueAndMapping_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kIteratorMapping_0(compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetIteratorValueWithMapping_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kAddIteratorValueToTheArray_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetArrayLikeValue_0(compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kCheckArrayLikeValueAndMapping_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetArrayLikeValueWithMapping_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kAddArrayLikeValueToTheArray_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kDoneAndResolvePromise_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kCloseAsyncIterator_0(compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_ArrayFromAsyncLabels_constexpr_kRejectPromise_0(compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncLabels p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o));
        tmp1 = (TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveResumeStateStepSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveResumeStateAwaitedValueSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveResumeStateIndexSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolvePromiseSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolvePromiseFunctionSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveOnFulfilledFunctionSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveOnRejectedFunctionSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveResultArraySlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveIteratorSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveNextMethodSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveErrorSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveMapfnSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveThisArgSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveLength_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveResumeStateStepSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveResumeStateStepSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveResumeStateStepSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveResumeStateAwaitedValueSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveResumeStateAwaitedValueSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveResumeStateAwaitedValueSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveResumeStateIndexSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveResumeStateIndexSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveResumeStateIndexSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolvePromiseSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolvePromiseSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolvePromiseSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolvePromiseFunctionSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolvePromiseFunctionSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolvePromiseFunctionSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveOnFulfilledFunctionSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveOnFulfilledFunctionSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveOnFulfilledFunctionSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveOnRejectedFunctionSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveOnRejectedFunctionSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveOnRejectedFunctionSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveResultArraySlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveResultArraySlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveResultArraySlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveIteratorSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveIteratorSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveIteratorSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveNextMethodSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveNextMethodSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveNextMethodSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveErrorSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveErrorSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveErrorSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveMapfnSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveMapfnSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveMapfnSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=63&c=1
TNode<IntPtrT> kArrayFromAsyncIterableResolveThisArgSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncIterableResolveContextSlots_constexpr_kArrayFromAsyncIterableResolveThisArgSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveThisArgSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=102&c=1
TNode<Context> CreateArrayFromAsyncIterableResolveContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TorqueStructArrayFromAsyncIterableResumeState_0 p_resumeState, TNode<JSPromise> p_promise, TNode<JSReceiver> p_promiseFun, TNode<JSReceiver> p_iterator,
    TNode<Object> p_next, TNode<JSReceiver> p_arr, TNode<Object> p_error, TNode<Object> p_mapfn, TNode<Object> p_thisArg, TNode<NativeContext> p_nativeContext)
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
    TNode<Smi> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<JSFunction> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<JSFunction> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, ArrayBuiltins::ArrayFromAsyncIterableResolveContextSlots::kArrayFromAsyncIterableResolveLength);
        tmp1 = AllocateSyntheticFunctionContext_1(state_, TNode<NativeContext> { p_nativeContext }, TNode<IntPtrT> { tmp0 });
        tmp2 = (TNode<Context> { tmp1 });
        tmp3 = kArrayFromAsyncIterableResolveResumeStateStepSlot_0(state_);
        tmp4 = SmiTag_ArrayFromAsyncLabels_0(state_, TNode<Uint32T> { p_resumeState.step });
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_SmiTagged_ArrayFromAsyncLabels_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp3 }, TNode<Smi> { tmp4 });
        tmp5 = kArrayFromAsyncIterableResolveResumeStateAwaitedValueSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp5 }, TNode<Object> { p_resumeState.awaitedValue });
        tmp6 = kArrayFromAsyncIterableResolveResumeStateIndexSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_Smi_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp6 }, TNode<Smi> { p_resumeState.index });
        tmp7 = kArrayFromAsyncIterableResolvePromiseSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSPromise_JSPromise_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp7 }, TNode<JSPromise> { p_promise });
        tmp8 = kArrayFromAsyncIterableResolvePromiseFunctionSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSReceiver_JSReceiver_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp8 }, TNode<JSReceiver> { p_promiseFun });
        tmp9 = kArrayFromAsyncIterableResolveOnFulfilledFunctionSlot_0(state_);
        tmp10 = CodeStubAssembler(state_).AllocateRootFunctionWithContext(
            RootIndex::kArrayFromAsyncIterableOnFulfilledSharedFun, TNode<Context> { tmp2 }, TNode<NativeContext> { p_nativeContext });
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Undefined_OR_JSFunction_JSFunction_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp9 }, TNode<JSFunction> { tmp10 });
        tmp11 = kArrayFromAsyncIterableResolveOnRejectedFunctionSlot_0(state_);
        tmp12 = CodeStubAssembler(state_).AllocateRootFunctionWithContext(
            RootIndex::kArrayFromAsyncIterableOnRejectedSharedFun, TNode<Context> { tmp2 }, TNode<NativeContext> { p_nativeContext });
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Undefined_OR_JSFunction_JSFunction_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp11 }, TNode<JSFunction> { tmp12 });
        tmp13 = kArrayFromAsyncIterableResolveResultArraySlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSReceiver_JSReceiver_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp13 }, TNode<JSReceiver> { p_arr });
        tmp14 = kArrayFromAsyncIterableResolveIteratorSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSReceiver_JSReceiver_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp14 }, TNode<JSReceiver> { p_iterator });
        tmp15 = kArrayFromAsyncIterableResolveNextMethodSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp15 }, TNode<Object> { p_next });
        tmp16 = kArrayFromAsyncIterableResolveErrorSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp16 }, TNode<Object> { p_error });
        tmp17 = kArrayFromAsyncIterableResolveMapfnSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp17 }, TNode<Object> { p_mapfn });
        tmp18 = kArrayFromAsyncIterableResolveThisArgSlot_0(state_);
        InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp18 }, TNode<Object> { p_thisArg });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Context> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=184&c=1
TorqueStructIteratorRecord GetIteratorRecordFromArrayFromAsyncIterableResolveContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<JSReceiver> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kArrayFromAsyncIterableResolveIteratorSlot_0(state_);
        std::tie(tmp1, tmp2) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSReceiver_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp0 })
                                   .Flatten();
        tmp3 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference { tmp1, tmp2 });
        tmp4 = kArrayFromAsyncIterableResolveNextMethodSlot_0(state_);
        std::tie(tmp5, tmp6) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp4 })
                                   .Flatten();
        tmp7 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp5, tmp6 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructIteratorRecord { TNode<JSReceiver> { tmp3 }, TNode<Object> { tmp7 } };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=199&c=1
TNode<Object> CreateArrayFromIterableAsynchronously_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T, Uint32T> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T, Uint32T> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block35(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T, Uint32T> block51(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T> block52(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Object, Smi> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block56(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block57(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T, Uint32T> block60(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T> block61(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block63(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T, Uint32T> block66(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T> block67(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Smi, Object> block69(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Smi, Smi> block70(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Smi> block71(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Object, Object> block72(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Object, Object> block73(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T, Uint32T> block76(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T> block77(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Smi> block79(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block80(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block81(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T, Uint32T> block84(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T> block85(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block87(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block88(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block93(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T, Uint32T> block96(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object, Uint32T> block97(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block98(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block102(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block103(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Map> tmp0;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Object> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<Object> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Object> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<Object> tmp25;
    TNode<Smi> tmp26;
    TNode<Smi> tmp27;
    TNode<Uint32T> tmp28;
    TNode<Object> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Object> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Object> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<Object> tmp41;
    TNode<Smi> tmp42;
    TNode<Undefined> tmp43;
    TNode<Undefined> tmp44;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerExceptionHandlerLabel catch1__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch1__label);
            tmp0 = GetIteratorResultMap_0(state_, TNode<Context> { p_context });
        }
        if (catch1__label.is_used()) {
            compiler::CodeAssemblerLabel catch1_skip(&ca_);
            ca_.Goto(&catch1_skip);
            ca_.Bind(&catch1__label, &tmp2);
            ca_.Goto(&block4);
            ca_.Bind(&catch1_skip);
        }
        tmp3 = kArrayFromAsyncIterableResolveMapfnSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch6__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch6__label);
            std::tie(tmp4, tmp5) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp3 })
                                       .Flatten();
        }
        if (catch6__label.is_used()) {
            compiler::CodeAssemblerLabel catch6_skip(&ca_);
            ca_.Goto(&catch6_skip);
            ca_.Bind(&catch6__label, &tmp7);
            ca_.Goto(&block5);
            ca_.Bind(&catch6_skip);
        }
        tmp8 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp4, tmp5 });
        tmp9 = kArrayFromAsyncIterableResolveThisArgSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch12__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch12__label);
            std::tie(tmp10, tmp11) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp9 })
                                         .Flatten();
        }
        if (catch12__label.is_used()) {
            compiler::CodeAssemblerLabel catch12_skip(&ca_);
            ca_.Goto(&catch12_skip);
            ca_.Bind(&catch12__label, &tmp13);
            ca_.Goto(&block6);
            ca_.Bind(&catch12_skip);
        }
        tmp14 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp10, tmp11 });
        tmp15 = kArrayFromAsyncIterableResolveResultArraySlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch18__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch18__label);
            std::tie(tmp16, tmp17) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSReceiver_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp15 })
                                         .Flatten();
        }
        if (catch18__label.is_used()) {
            compiler::CodeAssemblerLabel catch18_skip(&ca_);
            ca_.Goto(&catch18_skip);
            ca_.Bind(&catch18__label, &tmp19);
            ca_.Goto(&block7);
            ca_.Bind(&catch18_skip);
        }
        tmp20 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference { tmp16, tmp17 });
        tmp21 = kArrayFromAsyncIterableResolveResumeStateStepSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch24__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch24__label);
            std::tie(tmp22, tmp23) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp21 })
                                         .Flatten();
        }
        if (catch24__label.is_used()) {
            compiler::CodeAssemblerLabel catch24_skip(&ca_);
            ca_.Goto(&catch24_skip);
            ca_.Bind(&catch24__label, &tmp25);
            ca_.Goto(&block8);
            ca_.Bind(&catch24_skip);
        }
        tmp26 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp22, tmp23 });
        tmp27 = (TNode<Smi> { tmp26 });
        compiler::CodeAssemblerExceptionHandlerLabel catch29__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch29__label);
            tmp28 = SmiUntag_ArrayFromAsyncLabels_0(state_, TNode<Smi> { tmp27 });
        }
        if (catch29__label.is_used()) {
            compiler::CodeAssemblerLabel catch29_skip(&ca_);
            ca_.Goto(&catch29_skip);
            ca_.Bind(&catch29__label, &tmp30);
            ca_.Goto(&block9);
            ca_.Bind(&catch29_skip);
        }
        tmp31 = kArrayFromAsyncIterableResolveResumeStateAwaitedValueSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch34__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch34__label);
            std::tie(tmp32, tmp33) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp31 })
                                         .Flatten();
        }
        if (catch34__label.is_used()) {
            compiler::CodeAssemblerLabel catch34_skip(&ca_);
            ca_.Goto(&catch34_skip);
            ca_.Bind(&catch34__label, &tmp35);
            ca_.Goto(&block10);
            ca_.Bind(&catch34_skip);
        }
        tmp36 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp32, tmp33 });
        tmp37 = kArrayFromAsyncIterableResolveResumeStateIndexSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch40__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch40__label);
            std::tie(tmp38, tmp39) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp37 })
                                         .Flatten();
        }
        if (catch40__label.is_used()) {
            compiler::CodeAssemblerLabel catch40_skip(&ca_);
            ca_.Goto(&catch40_skip);
            ca_.Bind(&catch40__label, &tmp41);
            ca_.Goto(&block11);
            ca_.Bind(&catch40_skip);
        }
        tmp42 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp38, tmp39 });
        tmp43 = Undefined_0(state_);
        tmp44 = Undefined_0(state_);
        ca_.Goto(&block14, tmp28, tmp42, tmp43, tmp44);
    }

    TNode<HeapObject> tmp45;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp45 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp2, tmp45);
    }

    TNode<HeapObject> tmp46;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp46 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp7, tmp46);
    }

    TNode<HeapObject> tmp47;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp47 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp13, tmp47);
    }

    TNode<HeapObject> tmp48;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp48 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp19, tmp48);
    }

    TNode<HeapObject> tmp49;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp49 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp25, tmp49);
    }

    TNode<HeapObject> tmp50;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp50 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp30, tmp50);
    }

    TNode<HeapObject> tmp51;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp51 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp35, tmp51);
    }

    TNode<HeapObject> tmp52;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp52 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp41, tmp52);
    }

    TNode<Uint32T> phi_bb14_5;
    TNode<Smi> phi_bb14_7;
    TNode<Object> phi_bb14_8;
    TNode<Object> phi_bb14_9;
    TNode<BoolT> tmp53;
    TNode<Object> tmp55;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_5, &phi_bb14_7, &phi_bb14_8, &phi_bb14_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch54__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch54__label);
            tmp53 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        }
        if (catch54__label.is_used()) {
            compiler::CodeAssemblerLabel catch54_skip(&ca_);
            ca_.Goto(&catch54_skip);
            ca_.Bind(&catch54__label, &tmp55);
            ca_.Goto(&block15, phi_bb14_5, phi_bb14_7, phi_bb14_8, phi_bb14_9);
            ca_.Bind(&catch54_skip);
        }
        ca_.Branch(tmp53, &block12, std::vector<compiler::Node*> { phi_bb14_5, phi_bb14_7, phi_bb14_8, phi_bb14_9 }, &block13,
            std::vector<compiler::Node*> { phi_bb14_5, phi_bb14_7, phi_bb14_8, phi_bb14_9 });
    }

    TNode<Uint32T> phi_bb15_5;
    TNode<Smi> phi_bb15_7;
    TNode<Object> phi_bb15_8;
    TNode<Object> phi_bb15_9;
    TNode<HeapObject> tmp56;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_5, &phi_bb15_7, &phi_bb15_8, &phi_bb15_9);
        tmp56 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp55, tmp56);
    }

    TNode<Uint32T> phi_bb12_5;
    TNode<Smi> phi_bb12_7;
    TNode<Object> phi_bb12_8;
    TNode<Object> phi_bb12_9;
    TNode<Uint32T> tmp57;
    TNode<Object> tmp59;
    TNode<BoolT> tmp60;
    TNode<Object> tmp62;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_5, &phi_bb12_7, &phi_bb12_8, &phi_bb12_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch58__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch58__label);
            tmp57 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetIteratorStep);
        }
        if (catch58__label.is_used()) {
            compiler::CodeAssemblerLabel catch58_skip(&ca_);
            ca_.Goto(&catch58_skip);
            ca_.Bind(&catch58__label, &tmp59);
            ca_.Goto(&block18, phi_bb12_5, phi_bb12_7, phi_bb12_8, phi_bb12_9, phi_bb12_5, phi_bb12_5);
            ca_.Bind(&catch58_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch61__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch61__label);
            tmp60 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb12_5 }, TNode<Uint32T> { tmp57 });
        }
        if (catch61__label.is_used()) {
            compiler::CodeAssemblerLabel catch61_skip(&ca_);
            ca_.Goto(&catch61_skip);
            ca_.Bind(&catch61__label, &tmp62);
            ca_.Goto(&block19, phi_bb12_5, phi_bb12_7, phi_bb12_8, phi_bb12_9, phi_bb12_5);
            ca_.Bind(&catch61_skip);
        }
        ca_.Branch(tmp60, &block16, std::vector<compiler::Node*> { phi_bb12_5, phi_bb12_7, phi_bb12_8, phi_bb12_9 }, &block17,
            std::vector<compiler::Node*> { phi_bb12_5, phi_bb12_7, phi_bb12_8, phi_bb12_9 });
    }

    TNode<Uint32T> phi_bb18_5;
    TNode<Smi> phi_bb18_7;
    TNode<Object> phi_bb18_8;
    TNode<Object> phi_bb18_9;
    TNode<Uint32T> phi_bb18_10;
    TNode<Uint32T> phi_bb18_11;
    TNode<HeapObject> tmp63;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_5, &phi_bb18_7, &phi_bb18_8, &phi_bb18_9, &phi_bb18_10, &phi_bb18_11);
        tmp63 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp59, tmp63);
    }

    TNode<Uint32T> phi_bb19_5;
    TNode<Smi> phi_bb19_7;
    TNode<Object> phi_bb19_8;
    TNode<Object> phi_bb19_9;
    TNode<Uint32T> phi_bb19_10;
    TNode<HeapObject> tmp64;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_5, &phi_bb19_7, &phi_bb19_8, &phi_bb19_9, &phi_bb19_10);
        tmp64 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp62, tmp64);
    }

    TNode<Uint32T> phi_bb16_5;
    TNode<Smi> phi_bb16_7;
    TNode<Object> phi_bb16_8;
    TNode<Object> phi_bb16_9;
    TNode<JSReceiver> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp71;
    TNode<Uint32T> tmp72;
    TNode<Object> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp77;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_5, &phi_bb16_7, &phi_bb16_8, &phi_bb16_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch67__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch67__label);
            std::tie(tmp65, tmp66) = GetIteratorRecordFromArrayFromAsyncIterableResolveContext_0(state_, TNode<Context> { p_context }).Flatten();
        }
        if (catch67__label.is_used()) {
            compiler::CodeAssemblerLabel catch67_skip(&ca_);
            ca_.Goto(&catch67_skip);
            ca_.Bind(&catch67__label, &tmp68);
            ca_.Goto(&block21, phi_bb16_5, phi_bb16_7, phi_bb16_8, phi_bb16_9);
            ca_.Bind(&catch67_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch70__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch70__label);
            tmp69 = CodeStubAssembler(state_).Call(TNode<Context> { p_context }, TNode<Object> { tmp66 }, TNode<Object> { tmp65 });
        }
        if (catch70__label.is_used()) {
            compiler::CodeAssemblerLabel catch70_skip(&ca_);
            ca_.Goto(&catch70_skip);
            ca_.Bind(&catch70__label, &tmp71);
            ca_.Goto(&block22, phi_bb16_5, phi_bb16_7, phi_bb16_8, phi_bb16_9);
            ca_.Bind(&catch70_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch73__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch73__label);
            tmp72 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kCheckIteratorValueAndMapping_0(
                state_, ArrayBuiltins::ArrayFromAsyncLabels::kCheckIteratorValueAndMapping);
        }
        if (catch73__label.is_used()) {
            compiler::CodeAssemblerLabel catch73_skip(&ca_);
            ca_.Goto(&catch73_skip);
            ca_.Bind(&catch73__label, &tmp74);
            ca_.Goto(&block23, phi_bb16_5, phi_bb16_7, phi_bb16_8, phi_bb16_9);
            ca_.Bind(&catch73_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch76__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch76__label);
            tmp75 = ArrayFromAsyncIterableAwaitPoint_0(state_, TNode<Context> { p_context }, TNode<Uint32T> { tmp72 }, TNode<Object> { tmp69 });
        }
        if (catch76__label.is_used()) {
            compiler::CodeAssemblerLabel catch76_skip(&ca_);
            ca_.Goto(&catch76_skip);
            ca_.Bind(&catch76__label, &tmp77);
            ca_.Goto(&block24, phi_bb16_5, phi_bb16_7, phi_bb16_8, phi_bb16_9);
            ca_.Bind(&catch76_skip);
        }
        ca_.Goto(&block1, tmp75);
    }

    TNode<Uint32T> phi_bb21_5;
    TNode<Smi> phi_bb21_7;
    TNode<Object> phi_bb21_8;
    TNode<Object> phi_bb21_9;
    TNode<HeapObject> tmp78;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_5, &phi_bb21_7, &phi_bb21_8, &phi_bb21_9);
        tmp78 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp68, tmp78);
    }

    TNode<Uint32T> phi_bb22_5;
    TNode<Smi> phi_bb22_7;
    TNode<Object> phi_bb22_8;
    TNode<Object> phi_bb22_9;
    TNode<HeapObject> tmp79;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_5, &phi_bb22_7, &phi_bb22_8, &phi_bb22_9);
        tmp79 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp71, tmp79);
    }

    TNode<Uint32T> phi_bb23_5;
    TNode<Smi> phi_bb23_7;
    TNode<Object> phi_bb23_8;
    TNode<Object> phi_bb23_9;
    TNode<HeapObject> tmp80;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_5, &phi_bb23_7, &phi_bb23_8, &phi_bb23_9);
        tmp80 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp74, tmp80);
    }

    TNode<Uint32T> phi_bb24_5;
    TNode<Smi> phi_bb24_7;
    TNode<Object> phi_bb24_8;
    TNode<Object> phi_bb24_9;
    TNode<HeapObject> tmp81;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_5, &phi_bb24_7, &phi_bb24_8, &phi_bb24_9);
        tmp81 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp77, tmp81);
    }

    TNode<Uint32T> phi_bb17_5;
    TNode<Smi> phi_bb17_7;
    TNode<Object> phi_bb17_8;
    TNode<Object> phi_bb17_9;
    TNode<Uint32T> tmp82;
    TNode<Object> tmp84;
    TNode<BoolT> tmp85;
    TNode<Object> tmp87;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_5, &phi_bb17_7, &phi_bb17_8, &phi_bb17_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch83__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch83__label);
            tmp82 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kCheckIteratorValueAndMapping);
        }
        if (catch83__label.is_used()) {
            compiler::CodeAssemblerLabel catch83_skip(&ca_);
            ca_.Goto(&catch83_skip);
            ca_.Bind(&catch83__label, &tmp84);
            ca_.Goto(&block27, phi_bb17_5, phi_bb17_7, phi_bb17_8, phi_bb17_9, phi_bb17_5, phi_bb17_5);
            ca_.Bind(&catch83_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch86__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch86__label);
            tmp85 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb17_5 }, TNode<Uint32T> { tmp82 });
        }
        if (catch86__label.is_used()) {
            compiler::CodeAssemblerLabel catch86_skip(&ca_);
            ca_.Goto(&catch86_skip);
            ca_.Bind(&catch86__label, &tmp87);
            ca_.Goto(&block28, phi_bb17_5, phi_bb17_7, phi_bb17_8, phi_bb17_9, phi_bb17_5);
            ca_.Bind(&catch86_skip);
        }
        ca_.Branch(tmp85, &block25, std::vector<compiler::Node*> { phi_bb17_5, phi_bb17_7, phi_bb17_8, phi_bb17_9 }, &block26,
            std::vector<compiler::Node*> { phi_bb17_5, phi_bb17_7, phi_bb17_8, phi_bb17_9 });
    }

    TNode<Uint32T> phi_bb27_5;
    TNode<Smi> phi_bb27_7;
    TNode<Object> phi_bb27_8;
    TNode<Object> phi_bb27_9;
    TNode<Uint32T> phi_bb27_10;
    TNode<Uint32T> phi_bb27_11;
    TNode<HeapObject> tmp88;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_5, &phi_bb27_7, &phi_bb27_8, &phi_bb27_9, &phi_bb27_10, &phi_bb27_11);
        tmp88 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp84, tmp88);
    }

    TNode<Uint32T> phi_bb28_5;
    TNode<Smi> phi_bb28_7;
    TNode<Object> phi_bb28_8;
    TNode<Object> phi_bb28_9;
    TNode<Uint32T> phi_bb28_10;
    TNode<HeapObject> tmp89;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_5, &phi_bb28_7, &phi_bb28_8, &phi_bb28_9, &phi_bb28_10);
        tmp89 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp87, tmp89);
    }

    TNode<Uint32T> phi_bb25_5;
    TNode<Smi> phi_bb25_7;
    TNode<Object> phi_bb25_8;
    TNode<Object> phi_bb25_9;
    TNode<JSReceiver> tmp90;
    TNode<Object> tmp93;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_5, &phi_bb25_7, &phi_bb25_8, &phi_bb25_9);
        compiler::CodeAssemblerLabel label91(&ca_);
        compiler::CodeAssemblerExceptionHandlerLabel catch92__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch92__label);
            tmp90 = Cast_JSReceiver_1(state_, TNode<Context> { p_context }, TNode<Object> { tmp36 }, &label91);
        }
        if (catch92__label.is_used()) {
            compiler::CodeAssemblerLabel catch92_skip(&ca_);
            ca_.Goto(&catch92_skip);
            ca_.Bind(&catch92__label, &tmp93);
            ca_.Goto(&block34, phi_bb25_5, phi_bb25_7, phi_bb25_8, phi_bb25_9);
            ca_.Bind(&catch92_skip);
        }
        ca_.Goto(&block32, phi_bb25_5, phi_bb25_7, phi_bb25_8, phi_bb25_9);
        if (label91.is_used()) {
            ca_.Bind(&label91);
            ca_.Goto(&block33, phi_bb25_5, phi_bb25_7, phi_bb25_8, phi_bb25_9);
        }
    }

    TNode<Uint32T> phi_bb34_5;
    TNode<Smi> phi_bb34_7;
    TNode<Object> phi_bb34_8;
    TNode<Object> phi_bb34_9;
    TNode<HeapObject> tmp94;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_5, &phi_bb34_7, &phi_bb34_8, &phi_bb34_9);
        tmp94 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp93, tmp94);
    }

    TNode<Uint32T> phi_bb33_5;
    TNode<Smi> phi_bb33_7;
    TNode<Object> phi_bb33_8;
    TNode<Object> phi_bb33_9;
    TNode<Object> tmp96;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_5, &phi_bb33_7, &phi_bb33_8, &phi_bb33_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch95__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch95__label);
            CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kIteratorResultNotAnObject, "Array.fromAsync");
        }
        if (catch95__label.is_used()) {
            compiler::CodeAssemblerLabel catch95_skip(&ca_);
            ca_.Bind(&catch95__label, &tmp96);
            ca_.Goto(&block35, phi_bb33_5, phi_bb33_7, phi_bb33_8, phi_bb33_9);
        }
    }

    TNode<Uint32T> phi_bb32_5;
    TNode<Smi> phi_bb32_7;
    TNode<Object> phi_bb32_8;
    TNode<Object> phi_bb32_9;
    TNode<Object> tmp99;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_5, &phi_bb32_7, &phi_bb32_8, &phi_bb32_9);
        compiler::CodeAssemblerLabel label97(&ca_);
        compiler::CodeAssemblerExceptionHandlerLabel catch98__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch98__label);
            IteratorBuiltinsAssembler(state_).IteratorComplete(TNode<Context> { p_context }, TNode<JSReceiver> { tmp90 }, TNode<Map> { tmp0 }, &label97);
        }
        if (catch98__label.is_used()) {
            compiler::CodeAssemblerLabel catch98_skip(&ca_);
            ca_.Goto(&catch98_skip);
            ca_.Bind(&catch98__label, &tmp99);
            ca_.Goto(&block40, phi_bb32_5, phi_bb32_7, phi_bb32_8, phi_bb32_9);
            ca_.Bind(&catch98_skip);
        }
        ca_.Goto(&block38, phi_bb32_5, phi_bb32_7, phi_bb32_8, phi_bb32_9);
        if (label97.is_used()) {
            ca_.Bind(&label97);
            ca_.Goto(&block39, phi_bb32_5, phi_bb32_7, phi_bb32_8, phi_bb32_9);
        }
    }

    TNode<Uint32T> phi_bb35_5;
    TNode<Smi> phi_bb35_7;
    TNode<Object> phi_bb35_8;
    TNode<Object> phi_bb35_9;
    TNode<HeapObject> tmp100;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_5, &phi_bb35_7, &phi_bb35_8, &phi_bb35_9);
        tmp100 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp96, tmp100);
    }

    TNode<Uint32T> phi_bb40_5;
    TNode<Smi> phi_bb40_7;
    TNode<Object> phi_bb40_8;
    TNode<Object> phi_bb40_9;
    TNode<HeapObject> tmp101;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_5, &phi_bb40_7, &phi_bb40_8, &phi_bb40_9);
        tmp101 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp99, tmp101);
    }

    TNode<Uint32T> phi_bb39_5;
    TNode<Smi> phi_bb39_7;
    TNode<Object> phi_bb39_8;
    TNode<Object> phi_bb39_9;
    TNode<Uint32T> tmp102;
    TNode<Object> tmp104;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_5, &phi_bb39_7, &phi_bb39_8, &phi_bb39_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch103__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch103__label);
            tmp102 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kDoneAndResolvePromise_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kDoneAndResolvePromise);
        }
        if (catch103__label.is_used()) {
            compiler::CodeAssemblerLabel catch103_skip(&ca_);
            ca_.Goto(&catch103_skip);
            ca_.Bind(&catch103__label, &tmp104);
            ca_.Goto(&block48, phi_bb39_5, phi_bb39_7, phi_bb39_8, phi_bb39_9);
            ca_.Bind(&catch103_skip);
        }
        ca_.Goto(&block36, tmp102, phi_bb39_7, phi_bb39_8, phi_bb39_9);
    }

    TNode<Uint32T> phi_bb38_5;
    TNode<Smi> phi_bb38_7;
    TNode<Object> phi_bb38_8;
    TNode<Object> phi_bb38_9;
    TNode<Object> tmp105;
    TNode<Object> tmp107;
    TNode<Undefined> tmp108;
    TNode<BoolT> tmp109;
    TNode<Object> tmp111;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_5, &phi_bb38_7, &phi_bb38_8, &phi_bb38_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch106__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch106__label);
            tmp105 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context> { p_context }, TNode<JSReceiver> { tmp90 }, TNode<Map> { tmp0 });
        }
        if (catch106__label.is_used()) {
            compiler::CodeAssemblerLabel catch106_skip(&ca_);
            ca_.Goto(&catch106_skip);
            ca_.Bind(&catch106__label, &tmp107);
            ca_.Goto(&block41, phi_bb38_5, phi_bb38_7, phi_bb38_8, phi_bb38_9);
            ca_.Bind(&catch106_skip);
        }
        tmp108 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch110__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch110__label);
            tmp109 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp8 }, TNode<HeapObject> { tmp108 });
        }
        if (catch110__label.is_used()) {
            compiler::CodeAssemblerLabel catch110_skip(&ca_);
            ca_.Goto(&catch110_skip);
            ca_.Bind(&catch110__label, &tmp111);
            ca_.Goto(&block42, phi_bb38_5, phi_bb38_7, phi_bb38_8);
            ca_.Bind(&catch110_skip);
        }
        ca_.Branch(tmp109, &block43, std::vector<compiler::Node*> { phi_bb38_5, phi_bb38_7, phi_bb38_8 }, &block44,
            std::vector<compiler::Node*> { phi_bb38_5, phi_bb38_7, phi_bb38_8 });
    }

    TNode<Uint32T> phi_bb41_5;
    TNode<Smi> phi_bb41_7;
    TNode<Object> phi_bb41_8;
    TNode<Object> phi_bb41_9;
    TNode<HeapObject> tmp112;
    if (block41.is_used()) {
        ca_.Bind(&block41, &phi_bb41_5, &phi_bb41_7, &phi_bb41_8, &phi_bb41_9);
        tmp112 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp107, tmp112);
    }

    TNode<Uint32T> phi_bb42_5;
    TNode<Smi> phi_bb42_7;
    TNode<Object> phi_bb42_8;
    TNode<HeapObject> tmp113;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_5, &phi_bb42_7, &phi_bb42_8);
        tmp113 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp111, tmp113);
    }

    TNode<Uint32T> phi_bb43_5;
    TNode<Smi> phi_bb43_7;
    TNode<Object> phi_bb43_8;
    TNode<Uint32T> tmp114;
    TNode<Object> tmp116;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_5, &phi_bb43_7, &phi_bb43_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch115__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch115__label);
            tmp114 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kIteratorMapping_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kIteratorMapping);
        }
        if (catch115__label.is_used()) {
            compiler::CodeAssemblerLabel catch115_skip(&ca_);
            ca_.Goto(&catch115_skip);
            ca_.Bind(&catch115__label, &tmp116);
            ca_.Goto(&block46, phi_bb43_5, phi_bb43_7, phi_bb43_8);
            ca_.Bind(&catch115_skip);
        }
        ca_.Goto(&block45, tmp114, phi_bb43_7, phi_bb43_8);
    }

    TNode<Uint32T> phi_bb46_5;
    TNode<Smi> phi_bb46_7;
    TNode<Object> phi_bb46_8;
    TNode<HeapObject> tmp117;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_5, &phi_bb46_7, &phi_bb46_8);
        tmp117 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp116, tmp117);
    }

    TNode<Uint32T> phi_bb44_5;
    TNode<Smi> phi_bb44_7;
    TNode<Object> phi_bb44_8;
    TNode<Uint32T> tmp118;
    TNode<Object> tmp120;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_5, &phi_bb44_7, &phi_bb44_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch119__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch119__label);
            tmp118 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kAddIteratorValueToTheArray_0(
                state_, ArrayBuiltins::ArrayFromAsyncLabels::kAddIteratorValueToTheArray);
        }
        if (catch119__label.is_used()) {
            compiler::CodeAssemblerLabel catch119_skip(&ca_);
            ca_.Goto(&catch119_skip);
            ca_.Bind(&catch119__label, &tmp120);
            ca_.Goto(&block47, phi_bb44_5, phi_bb44_7);
            ca_.Bind(&catch119_skip);
        }
        ca_.Goto(&block45, tmp118, phi_bb44_7, tmp105);
    }

    TNode<Uint32T> phi_bb47_5;
    TNode<Smi> phi_bb47_7;
    TNode<HeapObject> tmp121;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_5, &phi_bb47_7);
        tmp121 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp120, tmp121);
    }

    TNode<Uint32T> phi_bb45_5;
    TNode<Smi> phi_bb45_7;
    TNode<Object> phi_bb45_8;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_5, &phi_bb45_7, &phi_bb45_8);
        ca_.Goto(&block36, phi_bb45_5, phi_bb45_7, phi_bb45_8, tmp105);
    }

    TNode<Uint32T> phi_bb48_5;
    TNode<Smi> phi_bb48_7;
    TNode<Object> phi_bb48_8;
    TNode<Object> phi_bb48_9;
    TNode<HeapObject> tmp122;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_5, &phi_bb48_7, &phi_bb48_8, &phi_bb48_9);
        tmp122 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp104, tmp122);
    }

    TNode<Uint32T> phi_bb36_5;
    TNode<Smi> phi_bb36_7;
    TNode<Object> phi_bb36_8;
    TNode<Object> phi_bb36_9;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_5, &phi_bb36_7, &phi_bb36_8, &phi_bb36_9);
        ca_.Goto(&block29, phi_bb36_5, phi_bb36_7, phi_bb36_8, phi_bb36_9);
    }

    TNode<Uint32T> phi_bb26_5;
    TNode<Smi> phi_bb26_7;
    TNode<Object> phi_bb26_8;
    TNode<Object> phi_bb26_9;
    TNode<Uint32T> tmp123;
    TNode<Object> tmp125;
    TNode<BoolT> tmp126;
    TNode<Object> tmp128;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_5, &phi_bb26_7, &phi_bb26_8, &phi_bb26_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch124__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch124__label);
            tmp123 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kIteratorMapping);
        }
        if (catch124__label.is_used()) {
            compiler::CodeAssemblerLabel catch124_skip(&ca_);
            ca_.Goto(&catch124_skip);
            ca_.Bind(&catch124__label, &tmp125);
            ca_.Goto(&block51, phi_bb26_5, phi_bb26_7, phi_bb26_8, phi_bb26_9, phi_bb26_5, phi_bb26_5);
            ca_.Bind(&catch124_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch127__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch127__label);
            tmp126 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb26_5 }, TNode<Uint32T> { tmp123 });
        }
        if (catch127__label.is_used()) {
            compiler::CodeAssemblerLabel catch127_skip(&ca_);
            ca_.Goto(&catch127_skip);
            ca_.Bind(&catch127__label, &tmp128);
            ca_.Goto(&block52, phi_bb26_5, phi_bb26_7, phi_bb26_8, phi_bb26_9, phi_bb26_5);
            ca_.Bind(&catch127_skip);
        }
        ca_.Branch(tmp126, &block49, std::vector<compiler::Node*> { phi_bb26_5, phi_bb26_7, phi_bb26_8, phi_bb26_9 }, &block50,
            std::vector<compiler::Node*> { phi_bb26_5, phi_bb26_7, phi_bb26_8, phi_bb26_9 });
    }

    TNode<Uint32T> phi_bb51_5;
    TNode<Smi> phi_bb51_7;
    TNode<Object> phi_bb51_8;
    TNode<Object> phi_bb51_9;
    TNode<Uint32T> phi_bb51_10;
    TNode<Uint32T> phi_bb51_11;
    TNode<HeapObject> tmp129;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_5, &phi_bb51_7, &phi_bb51_8, &phi_bb51_9, &phi_bb51_10, &phi_bb51_11);
        tmp129 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp125, tmp129);
    }

    TNode<Uint32T> phi_bb52_5;
    TNode<Smi> phi_bb52_7;
    TNode<Object> phi_bb52_8;
    TNode<Object> phi_bb52_9;
    TNode<Uint32T> phi_bb52_10;
    TNode<HeapObject> tmp130;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_5, &phi_bb52_7, &phi_bb52_8, &phi_bb52_9, &phi_bb52_10);
        tmp130 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp128, tmp130);
    }

    TNode<Uint32T> phi_bb49_5;
    TNode<Smi> phi_bb49_7;
    TNode<Object> phi_bb49_8;
    TNode<Object> phi_bb49_9;
    TNode<JSReceiver> tmp131;
    TNode<Object> tmp133;
    TNode<Object> tmp134;
    TNode<Object> tmp136;
    TNode<Uint32T> tmp137;
    TNode<Object> tmp139;
    TNode<Object> tmp140;
    TNode<Object> tmp142;
    if (block49.is_used()) {
        ca_.Bind(&block49, &phi_bb49_5, &phi_bb49_7, &phi_bb49_8, &phi_bb49_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch132__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch132__label);
            tmp131 = UnsafeCast_Callable_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp8 });
        }
        if (catch132__label.is_used()) {
            compiler::CodeAssemblerLabel catch132_skip(&ca_);
            ca_.Goto(&catch132_skip);
            ca_.Bind(&catch132__label, &tmp133);
            ca_.Goto(&block54, phi_bb49_5, phi_bb49_7, phi_bb49_8, phi_bb49_9);
            ca_.Bind(&catch132_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch135__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch135__label);
            tmp134 = CodeStubAssembler(state_).Call(
                TNode<Context> { p_context }, TNode<Object> { tmp131 }, TNode<Object> { tmp14 }, TNode<Object> { phi_bb49_9 }, TNode<Object> { phi_bb49_7 });
        }
        if (catch135__label.is_used()) {
            compiler::CodeAssemblerLabel catch135_skip(&ca_);
            ca_.Goto(&catch135_skip);
            ca_.Bind(&catch135__label, &tmp136);
            ca_.Goto(&block55, phi_bb49_5, phi_bb49_7, phi_bb49_8, phi_bb49_9, phi_bb49_9, phi_bb49_7);
            ca_.Bind(&catch135_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch138__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch138__label);
            tmp137 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetIteratorValueWithMapping_0(
                state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetIteratorValueWithMapping);
        }
        if (catch138__label.is_used()) {
            compiler::CodeAssemblerLabel catch138_skip(&ca_);
            ca_.Goto(&catch138_skip);
            ca_.Bind(&catch138__label, &tmp139);
            ca_.Goto(&block56, phi_bb49_5, phi_bb49_7, phi_bb49_8, phi_bb49_9);
            ca_.Bind(&catch138_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch141__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch141__label);
            tmp140 = ArrayFromAsyncIterableAwaitPoint_0(state_, TNode<Context> { p_context }, TNode<Uint32T> { tmp137 }, TNode<Object> { tmp134 });
        }
        if (catch141__label.is_used()) {
            compiler::CodeAssemblerLabel catch141_skip(&ca_);
            ca_.Goto(&catch141_skip);
            ca_.Bind(&catch141__label, &tmp142);
            ca_.Goto(&block57, phi_bb49_5, phi_bb49_7, phi_bb49_8, phi_bb49_9);
            ca_.Bind(&catch141_skip);
        }
        ca_.Goto(&block1, tmp140);
    }

    TNode<Uint32T> phi_bb54_5;
    TNode<Smi> phi_bb54_7;
    TNode<Object> phi_bb54_8;
    TNode<Object> phi_bb54_9;
    TNode<HeapObject> tmp143;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_5, &phi_bb54_7, &phi_bb54_8, &phi_bb54_9);
        tmp143 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp133, tmp143);
    }

    TNode<Uint32T> phi_bb55_5;
    TNode<Smi> phi_bb55_7;
    TNode<Object> phi_bb55_8;
    TNode<Object> phi_bb55_9;
    TNode<Object> phi_bb55_13;
    TNode<Smi> phi_bb55_14;
    TNode<HeapObject> tmp144;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_5, &phi_bb55_7, &phi_bb55_8, &phi_bb55_9, &phi_bb55_13, &phi_bb55_14);
        tmp144 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp136, tmp144);
    }

    TNode<Uint32T> phi_bb56_5;
    TNode<Smi> phi_bb56_7;
    TNode<Object> phi_bb56_8;
    TNode<Object> phi_bb56_9;
    TNode<HeapObject> tmp145;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_5, &phi_bb56_7, &phi_bb56_8, &phi_bb56_9);
        tmp145 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp139, tmp145);
    }

    TNode<Uint32T> phi_bb57_5;
    TNode<Smi> phi_bb57_7;
    TNode<Object> phi_bb57_8;
    TNode<Object> phi_bb57_9;
    TNode<HeapObject> tmp146;
    if (block57.is_used()) {
        ca_.Bind(&block57, &phi_bb57_5, &phi_bb57_7, &phi_bb57_8, &phi_bb57_9);
        tmp146 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp142, tmp146);
    }

    TNode<Uint32T> phi_bb50_5;
    TNode<Smi> phi_bb50_7;
    TNode<Object> phi_bb50_8;
    TNode<Object> phi_bb50_9;
    TNode<Uint32T> tmp147;
    TNode<Object> tmp149;
    TNode<BoolT> tmp150;
    TNode<Object> tmp152;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_5, &phi_bb50_7, &phi_bb50_8, &phi_bb50_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch148__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch148__label);
            tmp147 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetIteratorValueWithMapping);
        }
        if (catch148__label.is_used()) {
            compiler::CodeAssemblerLabel catch148_skip(&ca_);
            ca_.Goto(&catch148_skip);
            ca_.Bind(&catch148__label, &tmp149);
            ca_.Goto(&block60, phi_bb50_5, phi_bb50_7, phi_bb50_8, phi_bb50_9, phi_bb50_5, phi_bb50_5);
            ca_.Bind(&catch148_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch151__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch151__label);
            tmp150 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb50_5 }, TNode<Uint32T> { tmp147 });
        }
        if (catch151__label.is_used()) {
            compiler::CodeAssemblerLabel catch151_skip(&ca_);
            ca_.Goto(&catch151_skip);
            ca_.Bind(&catch151__label, &tmp152);
            ca_.Goto(&block61, phi_bb50_5, phi_bb50_7, phi_bb50_8, phi_bb50_9, phi_bb50_5);
            ca_.Bind(&catch151_skip);
        }
        ca_.Branch(tmp150, &block58, std::vector<compiler::Node*> { phi_bb50_5, phi_bb50_7, phi_bb50_8, phi_bb50_9 }, &block59,
            std::vector<compiler::Node*> { phi_bb50_5, phi_bb50_7, phi_bb50_8, phi_bb50_9 });
    }

    TNode<Uint32T> phi_bb60_5;
    TNode<Smi> phi_bb60_7;
    TNode<Object> phi_bb60_8;
    TNode<Object> phi_bb60_9;
    TNode<Uint32T> phi_bb60_10;
    TNode<Uint32T> phi_bb60_11;
    TNode<HeapObject> tmp153;
    if (block60.is_used()) {
        ca_.Bind(&block60, &phi_bb60_5, &phi_bb60_7, &phi_bb60_8, &phi_bb60_9, &phi_bb60_10, &phi_bb60_11);
        tmp153 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp149, tmp153);
    }

    TNode<Uint32T> phi_bb61_5;
    TNode<Smi> phi_bb61_7;
    TNode<Object> phi_bb61_8;
    TNode<Object> phi_bb61_9;
    TNode<Uint32T> phi_bb61_10;
    TNode<HeapObject> tmp154;
    if (block61.is_used()) {
        ca_.Bind(&block61, &phi_bb61_5, &phi_bb61_7, &phi_bb61_8, &phi_bb61_9, &phi_bb61_10);
        tmp154 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp152, tmp154);
    }

    TNode<Uint32T> phi_bb58_5;
    TNode<Smi> phi_bb58_7;
    TNode<Object> phi_bb58_8;
    TNode<Object> phi_bb58_9;
    TNode<Uint32T> tmp155;
    TNode<Object> tmp157;
    if (block58.is_used()) {
        ca_.Bind(&block58, &phi_bb58_5, &phi_bb58_7, &phi_bb58_8, &phi_bb58_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch156__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch156__label);
            tmp155 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kAddIteratorValueToTheArray_0(
                state_, ArrayBuiltins::ArrayFromAsyncLabels::kAddIteratorValueToTheArray);
        }
        if (catch156__label.is_used()) {
            compiler::CodeAssemblerLabel catch156_skip(&ca_);
            ca_.Goto(&catch156_skip);
            ca_.Bind(&catch156__label, &tmp157);
            ca_.Goto(&block63, phi_bb58_5, phi_bb58_7, phi_bb58_9);
            ca_.Bind(&catch156_skip);
        }
        ca_.Goto(&block62, tmp155, phi_bb58_7, tmp36, phi_bb58_9);
    }

    TNode<Uint32T> phi_bb63_5;
    TNode<Smi> phi_bb63_7;
    TNode<Object> phi_bb63_9;
    TNode<HeapObject> tmp158;
    if (block63.is_used()) {
        ca_.Bind(&block63, &phi_bb63_5, &phi_bb63_7, &phi_bb63_9);
        tmp158 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp157, tmp158);
    }

    TNode<Uint32T> phi_bb59_5;
    TNode<Smi> phi_bb59_7;
    TNode<Object> phi_bb59_8;
    TNode<Object> phi_bb59_9;
    TNode<Uint32T> tmp159;
    TNode<Object> tmp161;
    TNode<BoolT> tmp162;
    TNode<Object> tmp164;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_5, &phi_bb59_7, &phi_bb59_8, &phi_bb59_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch160__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch160__label);
            tmp159 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kAddIteratorValueToTheArray);
        }
        if (catch160__label.is_used()) {
            compiler::CodeAssemblerLabel catch160_skip(&ca_);
            ca_.Goto(&catch160_skip);
            ca_.Bind(&catch160__label, &tmp161);
            ca_.Goto(&block66, phi_bb59_5, phi_bb59_7, phi_bb59_8, phi_bb59_9, phi_bb59_5, phi_bb59_5);
            ca_.Bind(&catch160_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch163__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch163__label);
            tmp162 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb59_5 }, TNode<Uint32T> { tmp159 });
        }
        if (catch163__label.is_used()) {
            compiler::CodeAssemblerLabel catch163_skip(&ca_);
            ca_.Goto(&catch163_skip);
            ca_.Bind(&catch163__label, &tmp164);
            ca_.Goto(&block67, phi_bb59_5, phi_bb59_7, phi_bb59_8, phi_bb59_9, phi_bb59_5);
            ca_.Bind(&catch163_skip);
        }
        ca_.Branch(tmp162, &block64, std::vector<compiler::Node*> { phi_bb59_5, phi_bb59_7, phi_bb59_8, phi_bb59_9 }, &block65,
            std::vector<compiler::Node*> { phi_bb59_5, phi_bb59_7, phi_bb59_8, phi_bb59_9 });
    }

    TNode<Uint32T> phi_bb66_5;
    TNode<Smi> phi_bb66_7;
    TNode<Object> phi_bb66_8;
    TNode<Object> phi_bb66_9;
    TNode<Uint32T> phi_bb66_10;
    TNode<Uint32T> phi_bb66_11;
    TNode<HeapObject> tmp165;
    if (block66.is_used()) {
        ca_.Bind(&block66, &phi_bb66_5, &phi_bb66_7, &phi_bb66_8, &phi_bb66_9, &phi_bb66_10, &phi_bb66_11);
        tmp165 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp161, tmp165);
    }

    TNode<Uint32T> phi_bb67_5;
    TNode<Smi> phi_bb67_7;
    TNode<Object> phi_bb67_8;
    TNode<Object> phi_bb67_9;
    TNode<Uint32T> phi_bb67_10;
    TNode<HeapObject> tmp166;
    if (block67.is_used()) {
        ca_.Bind(&block67, &phi_bb67_5, &phi_bb67_7, &phi_bb67_8, &phi_bb67_9, &phi_bb67_10);
        tmp166 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp164, tmp166);
    }

    TNode<Uint32T> phi_bb64_5;
    TNode<Smi> phi_bb64_7;
    TNode<Object> phi_bb64_8;
    TNode<Object> phi_bb64_9;
    TNode<Object> tmp167;
    TNode<Object> tmp169;
    TNode<Smi> tmp170;
    TNode<Object> tmp172;
    TNode<Smi> tmp173;
    TNode<Object> tmp175;
    TNode<IntPtrT> tmp176;
    TNode<Object> tmp177;
    TNode<IntPtrT> tmp178;
    TNode<Object> tmp180;
    TNode<Uint32T> tmp181;
    TNode<Object> tmp183;
    if (block64.is_used()) {
        ca_.Bind(&block64, &phi_bb64_5, &phi_bb64_7, &phi_bb64_8, &phi_bb64_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch168__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch168__label);
            tmp167 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, tmp20, phi_bb64_7, phi_bb64_8);
        }
        if (catch168__label.is_used()) {
            compiler::CodeAssemblerLabel catch168_skip(&ca_);
            ca_.Goto(&catch168_skip);
            ca_.Bind(&catch168__label, &tmp169);
            ca_.Goto(&block69, phi_bb64_5, phi_bb64_7, phi_bb64_8, phi_bb64_9, phi_bb64_7, phi_bb64_8);
            ca_.Bind(&catch168_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch171__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch171__label);
            tmp170 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
        }
        if (catch171__label.is_used()) {
            compiler::CodeAssemblerLabel catch171_skip(&ca_);
            ca_.Goto(&catch171_skip);
            ca_.Bind(&catch171__label, &tmp172);
            ca_.Goto(&block70, phi_bb64_5, phi_bb64_7, phi_bb64_8, phi_bb64_9, phi_bb64_7, phi_bb64_7);
            ca_.Bind(&catch171_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch174__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch174__label);
            tmp173 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { phi_bb64_7 }, TNode<Smi> { tmp170 });
        }
        if (catch174__label.is_used()) {
            compiler::CodeAssemblerLabel catch174_skip(&ca_);
            ca_.Goto(&catch174_skip);
            ca_.Bind(&catch174__label, &tmp175);
            ca_.Goto(&block71, phi_bb64_5, phi_bb64_7, phi_bb64_8, phi_bb64_9, phi_bb64_7);
            ca_.Bind(&catch174_skip);
        }
        tmp176 = kArrayFromAsyncIterableResolveResumeStateIndexSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch179__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch179__label);
            std::tie(tmp177, tmp178) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp176 })
                                           .Flatten();
        }
        if (catch179__label.is_used()) {
            compiler::CodeAssemblerLabel catch179_skip(&ca_);
            ca_.Goto(&catch179_skip);
            ca_.Bind(&catch179__label, &tmp180);
            ca_.Goto(&block72, phi_bb64_5, phi_bb64_8, phi_bb64_9);
            ca_.Bind(&catch179_skip);
        }
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp177, tmp178 }, tmp173);
        compiler::CodeAssemblerExceptionHandlerLabel catch182__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch182__label);
            tmp181 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetIteratorStep_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetIteratorStep);
        }
        if (catch182__label.is_used()) {
            compiler::CodeAssemblerLabel catch182_skip(&ca_);
            ca_.Goto(&catch182_skip);
            ca_.Bind(&catch182__label, &tmp183);
            ca_.Goto(&block73, phi_bb64_5, phi_bb64_8, phi_bb64_9);
            ca_.Bind(&catch182_skip);
        }
        ca_.Goto(&block68, tmp181, tmp173, phi_bb64_8, phi_bb64_9);
    }

    TNode<Uint32T> phi_bb69_5;
    TNode<Smi> phi_bb69_7;
    TNode<Object> phi_bb69_8;
    TNode<Object> phi_bb69_9;
    TNode<Smi> phi_bb69_11;
    TNode<Object> phi_bb69_12;
    TNode<HeapObject> tmp184;
    if (block69.is_used()) {
        ca_.Bind(&block69, &phi_bb69_5, &phi_bb69_7, &phi_bb69_8, &phi_bb69_9, &phi_bb69_11, &phi_bb69_12);
        tmp184 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp169, tmp184);
    }

    TNode<Uint32T> phi_bb70_5;
    TNode<Smi> phi_bb70_7;
    TNode<Object> phi_bb70_8;
    TNode<Object> phi_bb70_9;
    TNode<Smi> phi_bb70_10;
    TNode<Smi> phi_bb70_11;
    TNode<HeapObject> tmp185;
    if (block70.is_used()) {
        ca_.Bind(&block70, &phi_bb70_5, &phi_bb70_7, &phi_bb70_8, &phi_bb70_9, &phi_bb70_10, &phi_bb70_11);
        tmp185 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp172, tmp185);
    }

    TNode<Uint32T> phi_bb71_5;
    TNode<Smi> phi_bb71_7;
    TNode<Object> phi_bb71_8;
    TNode<Object> phi_bb71_9;
    TNode<Smi> phi_bb71_10;
    TNode<HeapObject> tmp186;
    if (block71.is_used()) {
        ca_.Bind(&block71, &phi_bb71_5, &phi_bb71_7, &phi_bb71_8, &phi_bb71_9, &phi_bb71_10);
        tmp186 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp175, tmp186);
    }

    TNode<Uint32T> phi_bb72_5;
    TNode<Object> phi_bb72_8;
    TNode<Object> phi_bb72_9;
    TNode<HeapObject> tmp187;
    if (block72.is_used()) {
        ca_.Bind(&block72, &phi_bb72_5, &phi_bb72_8, &phi_bb72_9);
        tmp187 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp180, tmp187);
    }

    TNode<Uint32T> phi_bb73_5;
    TNode<Object> phi_bb73_8;
    TNode<Object> phi_bb73_9;
    TNode<HeapObject> tmp188;
    if (block73.is_used()) {
        ca_.Bind(&block73, &phi_bb73_5, &phi_bb73_8, &phi_bb73_9);
        tmp188 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp183, tmp188);
    }

    TNode<Uint32T> phi_bb65_5;
    TNode<Smi> phi_bb65_7;
    TNode<Object> phi_bb65_8;
    TNode<Object> phi_bb65_9;
    TNode<Uint32T> tmp189;
    TNode<Object> tmp191;
    TNode<BoolT> tmp192;
    TNode<Object> tmp194;
    if (block65.is_used()) {
        ca_.Bind(&block65, &phi_bb65_5, &phi_bb65_7, &phi_bb65_8, &phi_bb65_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch190__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch190__label);
            tmp189 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kDoneAndResolvePromise);
        }
        if (catch190__label.is_used()) {
            compiler::CodeAssemblerLabel catch190_skip(&ca_);
            ca_.Goto(&catch190_skip);
            ca_.Bind(&catch190__label, &tmp191);
            ca_.Goto(&block76, phi_bb65_5, phi_bb65_7, phi_bb65_8, phi_bb65_9, phi_bb65_5, phi_bb65_5);
            ca_.Bind(&catch190_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch193__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch193__label);
            tmp192 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb65_5 }, TNode<Uint32T> { tmp189 });
        }
        if (catch193__label.is_used()) {
            compiler::CodeAssemblerLabel catch193_skip(&ca_);
            ca_.Goto(&catch193_skip);
            ca_.Bind(&catch193__label, &tmp194);
            ca_.Goto(&block77, phi_bb65_5, phi_bb65_7, phi_bb65_8, phi_bb65_9, phi_bb65_5);
            ca_.Bind(&catch193_skip);
        }
        ca_.Branch(tmp192, &block74, std::vector<compiler::Node*> { phi_bb65_5, phi_bb65_7, phi_bb65_8, phi_bb65_9 }, &block75,
            std::vector<compiler::Node*> { phi_bb65_5, phi_bb65_7, phi_bb65_8, phi_bb65_9 });
    }

    TNode<Uint32T> phi_bb76_5;
    TNode<Smi> phi_bb76_7;
    TNode<Object> phi_bb76_8;
    TNode<Object> phi_bb76_9;
    TNode<Uint32T> phi_bb76_10;
    TNode<Uint32T> phi_bb76_11;
    TNode<HeapObject> tmp195;
    if (block76.is_used()) {
        ca_.Bind(&block76, &phi_bb76_5, &phi_bb76_7, &phi_bb76_8, &phi_bb76_9, &phi_bb76_10, &phi_bb76_11);
        tmp195 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp191, tmp195);
    }

    TNode<Uint32T> phi_bb77_5;
    TNode<Smi> phi_bb77_7;
    TNode<Object> phi_bb77_8;
    TNode<Object> phi_bb77_9;
    TNode<Uint32T> phi_bb77_10;
    TNode<HeapObject> tmp196;
    if (block77.is_used()) {
        ca_.Bind(&block77, &phi_bb77_5, &phi_bb77_7, &phi_bb77_8, &phi_bb77_9, &phi_bb77_10);
        tmp196 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp194, tmp196);
    }

    TNode<Uint32T> phi_bb74_5;
    TNode<Smi> phi_bb74_7;
    TNode<Object> phi_bb74_8;
    TNode<Object> phi_bb74_9;
    TNode<Object> tmp198;
    TNode<IntPtrT> tmp199;
    TNode<Object> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<Object> tmp203;
    TNode<JSPromise> tmp204;
    TNode<Object> tmp205;
    TNode<Object> tmp207;
    TNode<Undefined> tmp208;
    if (block74.is_used()) {
        ca_.Bind(&block74, &phi_bb74_5, &phi_bb74_7, &phi_bb74_8, &phi_bb74_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch197__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch197__label);
            CodeStubAssembler(state_).SetPropertyLength(TNode<Context> { p_context }, TNode<Object> { tmp20 }, TNode<Number> { phi_bb74_7 });
        }
        if (catch197__label.is_used()) {
            compiler::CodeAssemblerLabel catch197_skip(&ca_);
            ca_.Goto(&catch197_skip);
            ca_.Bind(&catch197__label, &tmp198);
            ca_.Goto(&block79, phi_bb74_5, phi_bb74_7, phi_bb74_8, phi_bb74_9, phi_bb74_7);
            ca_.Bind(&catch197_skip);
        }
        tmp199 = kArrayFromAsyncIterableResolvePromiseSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch202__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch202__label);
            std::tie(tmp200, tmp201) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSPromise_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp199 })
                                           .Flatten();
        }
        if (catch202__label.is_used()) {
            compiler::CodeAssemblerLabel catch202_skip(&ca_);
            ca_.Goto(&catch202_skip);
            ca_.Bind(&catch202__label, &tmp203);
            ca_.Goto(&block80, phi_bb74_5, phi_bb74_7, phi_bb74_8, phi_bb74_9);
            ca_.Bind(&catch202_skip);
        }
        tmp204 = CodeStubAssembler(state_).LoadReference<JSPromise>(CodeStubAssembler::Reference { tmp200, tmp201 });
        compiler::CodeAssemblerExceptionHandlerLabel catch206__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch206__label);
            tmp205 = ca_.CallBuiltin<Object>(Builtin::kResolvePromise, p_context, tmp204, tmp20);
        }
        if (catch206__label.is_used()) {
            compiler::CodeAssemblerLabel catch206_skip(&ca_);
            ca_.Goto(&catch206_skip);
            ca_.Bind(&catch206__label, &tmp207);
            ca_.Goto(&block81, phi_bb74_5, phi_bb74_7, phi_bb74_8, phi_bb74_9);
            ca_.Bind(&catch206_skip);
        }
        tmp208 = Undefined_0(state_);
        ca_.Goto(&block1, tmp208);
    }

    TNode<Uint32T> phi_bb79_5;
    TNode<Smi> phi_bb79_7;
    TNode<Object> phi_bb79_8;
    TNode<Object> phi_bb79_9;
    TNode<Smi> phi_bb79_11;
    TNode<HeapObject> tmp209;
    if (block79.is_used()) {
        ca_.Bind(&block79, &phi_bb79_5, &phi_bb79_7, &phi_bb79_8, &phi_bb79_9, &phi_bb79_11);
        tmp209 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp198, tmp209);
    }

    TNode<Uint32T> phi_bb80_5;
    TNode<Smi> phi_bb80_7;
    TNode<Object> phi_bb80_8;
    TNode<Object> phi_bb80_9;
    TNode<HeapObject> tmp210;
    if (block80.is_used()) {
        ca_.Bind(&block80, &phi_bb80_5, &phi_bb80_7, &phi_bb80_8, &phi_bb80_9);
        tmp210 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp203, tmp210);
    }

    TNode<Uint32T> phi_bb81_5;
    TNode<Smi> phi_bb81_7;
    TNode<Object> phi_bb81_8;
    TNode<Object> phi_bb81_9;
    TNode<HeapObject> tmp211;
    if (block81.is_used()) {
        ca_.Bind(&block81, &phi_bb81_5, &phi_bb81_7, &phi_bb81_8, &phi_bb81_9);
        tmp211 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp207, tmp211);
    }

    TNode<Uint32T> phi_bb75_5;
    TNode<Smi> phi_bb75_7;
    TNode<Object> phi_bb75_8;
    TNode<Object> phi_bb75_9;
    TNode<Uint32T> tmp212;
    TNode<Object> tmp214;
    TNode<BoolT> tmp215;
    TNode<Object> tmp217;
    if (block75.is_used()) {
        ca_.Bind(&block75, &phi_bb75_5, &phi_bb75_7, &phi_bb75_8, &phi_bb75_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch213__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch213__label);
            tmp212 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kCloseAsyncIterator);
        }
        if (catch213__label.is_used()) {
            compiler::CodeAssemblerLabel catch213_skip(&ca_);
            ca_.Goto(&catch213_skip);
            ca_.Bind(&catch213__label, &tmp214);
            ca_.Goto(&block84, phi_bb75_5, phi_bb75_7, phi_bb75_8, phi_bb75_9, phi_bb75_5, phi_bb75_5);
            ca_.Bind(&catch213_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch216__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch216__label);
            tmp215 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb75_5 }, TNode<Uint32T> { tmp212 });
        }
        if (catch216__label.is_used()) {
            compiler::CodeAssemblerLabel catch216_skip(&ca_);
            ca_.Goto(&catch216_skip);
            ca_.Bind(&catch216__label, &tmp217);
            ca_.Goto(&block85, phi_bb75_5, phi_bb75_7, phi_bb75_8, phi_bb75_9, phi_bb75_5);
            ca_.Bind(&catch216_skip);
        }
        ca_.Branch(tmp215, &block82, std::vector<compiler::Node*> { phi_bb75_5, phi_bb75_7, phi_bb75_8, phi_bb75_9 }, &block83,
            std::vector<compiler::Node*> { phi_bb75_5, phi_bb75_7, phi_bb75_8, phi_bb75_9 });
    }

    TNode<Uint32T> phi_bb84_5;
    TNode<Smi> phi_bb84_7;
    TNode<Object> phi_bb84_8;
    TNode<Object> phi_bb84_9;
    TNode<Uint32T> phi_bb84_10;
    TNode<Uint32T> phi_bb84_11;
    TNode<HeapObject> tmp218;
    if (block84.is_used()) {
        ca_.Bind(&block84, &phi_bb84_5, &phi_bb84_7, &phi_bb84_8, &phi_bb84_9, &phi_bb84_10, &phi_bb84_11);
        tmp218 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp214, tmp218);
    }

    TNode<Uint32T> phi_bb85_5;
    TNode<Smi> phi_bb85_7;
    TNode<Object> phi_bb85_8;
    TNode<Object> phi_bb85_9;
    TNode<Uint32T> phi_bb85_10;
    TNode<HeapObject> tmp219;
    if (block85.is_used()) {
        ca_.Bind(&block85, &phi_bb85_5, &phi_bb85_7, &phi_bb85_8, &phi_bb85_9, &phi_bb85_10);
        tmp219 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp217, tmp219);
    }

    TNode<Uint32T> phi_bb82_5;
    TNode<Smi> phi_bb82_7;
    TNode<Object> phi_bb82_8;
    TNode<Object> phi_bb82_9;
    TNode<Uint32T> tmp220;
    TNode<Object> tmp222;
    TNode<JSReceiver> tmp223;
    TNode<Object> tmp224;
    TNode<Object> tmp226;
    TNode<Object> tmp229;
    if (block82.is_used()) {
        ca_.Bind(&block82, &phi_bb82_5, &phi_bb82_7, &phi_bb82_8, &phi_bb82_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch221__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch221__label);
            tmp220 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kRejectPromise_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kRejectPromise);
        }
        if (catch221__label.is_used()) {
            compiler::CodeAssemblerLabel catch221_skip(&ca_);
            ca_.Goto(&catch221_skip);
            ca_.Bind(&catch221__label, &tmp222);
            ca_.Goto(&block87, phi_bb82_5, phi_bb82_7, phi_bb82_8, phi_bb82_9);
            ca_.Bind(&catch221_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch225__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch225__label);
            std::tie(tmp223, tmp224) = GetIteratorRecordFromArrayFromAsyncIterableResolveContext_0(state_, TNode<Context> { p_context }).Flatten();
        }
        if (catch225__label.is_used()) {
            compiler::CodeAssemblerLabel catch225_skip(&ca_);
            ca_.Goto(&catch225_skip);
            ca_.Bind(&catch225__label, &tmp226);
            ca_.Goto(&block88, phi_bb82_7, phi_bb82_8, phi_bb82_9);
            ca_.Bind(&catch225_skip);
        }
        compiler::CodeAssemblerLabel label227(&ca_);
        compiler::CodeAssemblerExceptionHandlerLabel catch228__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch228__label);
            ArrayFromAsyncAsyncIteratorCloseOnException_0(
                state_, TNode<Context> { p_context }, TorqueStructIteratorRecord { TNode<JSReceiver> { tmp223 }, TNode<Object> { tmp224 } }, &label227);
        }
        if (catch228__label.is_used()) {
            compiler::CodeAssemblerLabel catch228_skip(&ca_);
            ca_.Goto(&catch228_skip);
            ca_.Bind(&catch228__label, &tmp229);
            ca_.Goto(&block93, phi_bb82_7, phi_bb82_8, phi_bb82_9);
            ca_.Bind(&catch228_skip);
        }
        ca_.Goto(&block91, phi_bb82_7, phi_bb82_8, phi_bb82_9);
        if (label227.is_used()) {
            ca_.Bind(&label227);
            ca_.Goto(&block92, phi_bb82_7, phi_bb82_8, phi_bb82_9);
        }
    }

    TNode<Uint32T> phi_bb87_5;
    TNode<Smi> phi_bb87_7;
    TNode<Object> phi_bb87_8;
    TNode<Object> phi_bb87_9;
    TNode<HeapObject> tmp230;
    if (block87.is_used()) {
        ca_.Bind(&block87, &phi_bb87_5, &phi_bb87_7, &phi_bb87_8, &phi_bb87_9);
        tmp230 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp222, tmp230);
    }

    TNode<Smi> phi_bb88_7;
    TNode<Object> phi_bb88_8;
    TNode<Object> phi_bb88_9;
    TNode<HeapObject> tmp231;
    if (block88.is_used()) {
        ca_.Bind(&block88, &phi_bb88_7, &phi_bb88_8, &phi_bb88_9);
        tmp231 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp226, tmp231);
    }

    TNode<Smi> phi_bb93_7;
    TNode<Object> phi_bb93_8;
    TNode<Object> phi_bb93_9;
    TNode<HeapObject> tmp232;
    if (block93.is_used()) {
        ca_.Bind(&block93, &phi_bb93_7, &phi_bb93_8, &phi_bb93_9);
        tmp232 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp229, tmp232);
    }

    TNode<Smi> phi_bb92_7;
    TNode<Object> phi_bb92_8;
    TNode<Object> phi_bb92_9;
    if (block92.is_used()) {
        ca_.Bind(&block92, &phi_bb92_7, &phi_bb92_8, &phi_bb92_9);
        ca_.Goto(&block86, tmp220, phi_bb92_7, phi_bb92_8, phi_bb92_9);
    }

    TNode<Smi> phi_bb91_7;
    TNode<Object> phi_bb91_8;
    TNode<Object> phi_bb91_9;
    TNode<Undefined> tmp233;
    if (block91.is_used()) {
        ca_.Bind(&block91, &phi_bb91_7, &phi_bb91_8, &phi_bb91_9);
        tmp233 = Undefined_0(state_);
        ca_.Goto(&block1, tmp233);
    }

    TNode<Uint32T> phi_bb83_5;
    TNode<Smi> phi_bb83_7;
    TNode<Object> phi_bb83_8;
    TNode<Object> phi_bb83_9;
    TNode<Uint32T> tmp234;
    TNode<Object> tmp236;
    TNode<BoolT> tmp237;
    TNode<Object> tmp239;
    if (block83.is_used()) {
        ca_.Bind(&block83, &phi_bb83_5, &phi_bb83_7, &phi_bb83_8, &phi_bb83_9);
        compiler::CodeAssemblerExceptionHandlerLabel catch235__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch235__label);
            tmp234 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kRejectPromise);
        }
        if (catch235__label.is_used()) {
            compiler::CodeAssemblerLabel catch235_skip(&ca_);
            ca_.Goto(&catch235_skip);
            ca_.Bind(&catch235__label, &tmp236);
            ca_.Goto(&block96, phi_bb83_5, phi_bb83_7, phi_bb83_8, phi_bb83_9, phi_bb83_5, phi_bb83_5);
            ca_.Bind(&catch235_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch238__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch238__label);
            tmp237 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb83_5 }, TNode<Uint32T> { tmp234 });
        }
        if (catch238__label.is_used()) {
            compiler::CodeAssemblerLabel catch238_skip(&ca_);
            ca_.Goto(&catch238_skip);
            ca_.Bind(&catch238__label, &tmp239);
            ca_.Goto(&block97, phi_bb83_5, phi_bb83_7, phi_bb83_8, phi_bb83_9, phi_bb83_5);
            ca_.Bind(&catch238_skip);
        }
        ca_.Branch(tmp237, &block94, std::vector<compiler::Node*> { phi_bb83_5, phi_bb83_7, phi_bb83_8, phi_bb83_9 }, &block95,
            std::vector<compiler::Node*> { phi_bb83_5, phi_bb83_7, phi_bb83_8, phi_bb83_9 });
    }

    TNode<Uint32T> phi_bb96_5;
    TNode<Smi> phi_bb96_7;
    TNode<Object> phi_bb96_8;
    TNode<Object> phi_bb96_9;
    TNode<Uint32T> phi_bb96_10;
    TNode<Uint32T> phi_bb96_11;
    TNode<HeapObject> tmp240;
    if (block96.is_used()) {
        ca_.Bind(&block96, &phi_bb96_5, &phi_bb96_7, &phi_bb96_8, &phi_bb96_9, &phi_bb96_10, &phi_bb96_11);
        tmp240 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp236, tmp240);
    }

    TNode<Uint32T> phi_bb97_5;
    TNode<Smi> phi_bb97_7;
    TNode<Object> phi_bb97_8;
    TNode<Object> phi_bb97_9;
    TNode<Uint32T> phi_bb97_10;
    TNode<HeapObject> tmp241;
    if (block97.is_used()) {
        ca_.Bind(&block97, &phi_bb97_5, &phi_bb97_7, &phi_bb97_8, &phi_bb97_9, &phi_bb97_10);
        tmp241 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp239, tmp241);
    }

    TNode<Uint32T> phi_bb94_5;
    TNode<Smi> phi_bb94_7;
    TNode<Object> phi_bb94_8;
    TNode<Object> phi_bb94_9;
    TNode<IntPtrT> tmp242;
    TNode<IntPtrT> tmp243;
    TNode<Object> tmp244;
    TNode<Object> tmp246;
    if (block94.is_used()) {
        ca_.Bind(&block94, &phi_bb94_5, &phi_bb94_7, &phi_bb94_8, &phi_bb94_9);
        tmp242 = kArrayFromAsyncIterableResolveErrorSlot_0(state_);
        tmp243 = kArrayFromAsyncIterableResolvePromiseSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch245__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch245__label);
            tmp244 = RejectArrayFromAsyncPromise_ArrayFromAsyncIterableResolveContext_0(
                state_, TNode<Context> { p_context }, TNode<Context> { p_context }, TNode<IntPtrT> { tmp242 }, TNode<IntPtrT> { tmp243 });
        }
        if (catch245__label.is_used()) {
            compiler::CodeAssemblerLabel catch245_skip(&ca_);
            ca_.Goto(&catch245_skip);
            ca_.Bind(&catch245__label, &tmp246);
            ca_.Goto(&block98, phi_bb94_5, phi_bb94_7, phi_bb94_8, phi_bb94_9);
            ca_.Bind(&catch245_skip);
        }
        ca_.Goto(&block1, tmp244);
    }

    TNode<Uint32T> phi_bb98_5;
    TNode<Smi> phi_bb98_7;
    TNode<Object> phi_bb98_8;
    TNode<Object> phi_bb98_9;
    TNode<HeapObject> tmp247;
    if (block98.is_used()) {
        ca_.Bind(&block98, &phi_bb98_5, &phi_bb98_7, &phi_bb98_8, &phi_bb98_9);
        tmp247 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp246, tmp247);
    }

    TNode<Uint32T> phi_bb95_5;
    TNode<Smi> phi_bb95_7;
    TNode<Object> phi_bb95_8;
    TNode<Object> phi_bb95_9;
    if (block95.is_used()) {
        ca_.Bind(&block95, &phi_bb95_5, &phi_bb95_7, &phi_bb95_8, &phi_bb95_9);
        ca_.Goto(&block86, phi_bb95_5, phi_bb95_7, phi_bb95_8, phi_bb95_9);
    }

    TNode<Uint32T> phi_bb86_5;
    TNode<Smi> phi_bb86_7;
    TNode<Object> phi_bb86_8;
    TNode<Object> phi_bb86_9;
    if (block86.is_used()) {
        ca_.Bind(&block86, &phi_bb86_5, &phi_bb86_7, &phi_bb86_8, &phi_bb86_9);
        ca_.Goto(&block68, phi_bb86_5, phi_bb86_7, phi_bb86_8, phi_bb86_9);
    }

    TNode<Uint32T> phi_bb68_5;
    TNode<Smi> phi_bb68_7;
    TNode<Object> phi_bb68_8;
    TNode<Object> phi_bb68_9;
    if (block68.is_used()) {
        ca_.Bind(&block68, &phi_bb68_5, &phi_bb68_7, &phi_bb68_8, &phi_bb68_9);
        ca_.Goto(&block62, phi_bb68_5, phi_bb68_7, phi_bb68_8, phi_bb68_9);
    }

    TNode<Uint32T> phi_bb62_5;
    TNode<Smi> phi_bb62_7;
    TNode<Object> phi_bb62_8;
    TNode<Object> phi_bb62_9;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_5, &phi_bb62_7, &phi_bb62_8, &phi_bb62_9);
        ca_.Goto(&block29, phi_bb62_5, phi_bb62_7, phi_bb62_8, phi_bb62_9);
    }

    TNode<Uint32T> phi_bb29_5;
    TNode<Smi> phi_bb29_7;
    TNode<Object> phi_bb29_8;
    TNode<Object> phi_bb29_9;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_5, &phi_bb29_7, &phi_bb29_8, &phi_bb29_9);
        ca_.Goto(&block14, phi_bb29_5, phi_bb29_7, phi_bb29_8, phi_bb29_9);
    }

    TNode<Uint32T> phi_bb13_5;
    TNode<Smi> phi_bb13_7;
    TNode<Object> phi_bb13_8;
    TNode<Object> phi_bb13_9;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_5, &phi_bb13_7, &phi_bb13_8, &phi_bb13_9);
        ca_.Goto(&block2);
    }

    TNode<Object> phi_bb3_1;
    TNode<HeapObject> phi_bb3_2;
    TNode<IntPtrT> tmp248;
    TNode<Object> tmp249;
    TNode<IntPtrT> tmp250;
    TNode<JSReceiver> tmp251;
    TNode<Object> tmp252;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_1, &phi_bb3_2);
        tmp248 = kArrayFromAsyncIterableResolveErrorSlot_0(state_);
        std::tie(tmp249, tmp250) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp248 })
                                       .Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp249, tmp250 }, phi_bb3_1);
        std::tie(tmp251, tmp252) = GetIteratorRecordFromArrayFromAsyncIterableResolveContext_0(state_, TNode<Context> { p_context }).Flatten();
        compiler::CodeAssemblerLabel label253(&ca_);
        ArrayFromAsyncAsyncIteratorCloseOnException_0(
            state_, TNode<Context> { p_context }, TorqueStructIteratorRecord { TNode<JSReceiver> { tmp251 }, TNode<Object> { tmp252 } }, &label253);
        ca_.Goto(&block101);
        if (label253.is_used()) {
            ca_.Bind(&label253);
            ca_.Goto(&block102);
        }
    }

    TNode<IntPtrT> tmp254;
    TNode<IntPtrT> tmp255;
    TNode<Object> tmp256;
    if (block102.is_used()) {
        ca_.Bind(&block102);
        tmp254 = kArrayFromAsyncIterableResolveErrorSlot_0(state_);
        tmp255 = kArrayFromAsyncIterableResolvePromiseSlot_0(state_);
        tmp256 = RejectArrayFromAsyncPromise_ArrayFromAsyncIterableResolveContext_0(
            state_, TNode<Context> { p_context }, TNode<Context> { p_context }, TNode<IntPtrT> { tmp254 }, TNode<IntPtrT> { tmp255 });
        ca_.Goto(&block1, tmp256);
    }

    if (block101.is_used()) {
        ca_.Bind(&block101);
        ca_.Goto(&block2);
    }

    TNode<Undefined> tmp257;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp257 = Undefined_0(state_);
        ca_.Goto(&block1, tmp257);
    }

    TNode<Object> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_1);
        ca_.Goto(&block103);
    }

    ca_.Bind(&block103);
    return TNode<Object> { phi_bb1_1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=385&c=1
TNode<Object> ArrayFromAsyncIterableAwaitPoint_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_step, TNode<Object> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Object> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kArrayFromAsyncIterableResolveResumeStateStepSlot_0(state_);
        tmp1 = kArrayFromAsyncIterableResolvePromiseFunctionSlot_0(state_);
        tmp2 = kArrayFromAsyncIterableResolveOnFulfilledFunctionSlot_0(state_);
        tmp3 = kArrayFromAsyncIterableResolveOnRejectedFunctionSlot_0(state_);
        tmp4 = ArrayFromAsyncAwaitPoint_ArrayFromAsyncIterableResolveContext_0(state_, TNode<Context> { p_context }, TNode<Context> { p_context },
            TNode<IntPtrT> { tmp0 }, TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 }, TNode<Uint32T> { p_step },
            TNode<Object> { p_value });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp4 };
}

TF_BUILTIN(ArrayFromAsyncIterableOnFulfilled, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kResult);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Object> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = kArrayFromAsyncIterableResolveResumeStateAwaitedValueSlot_0(state_);
        std::tie(tmp2, tmp3) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
            state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp1 })
                                   .Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp2, tmp3 }, parameter3);
        tmp4 = CreateArrayFromIterableAsynchronously_0(state_, TNode<Context> { tmp0 });
        CodeStubAssembler(state_).Return(tmp4);
    }
}

TF_BUILTIN(ArrayFromAsyncIterableOnRejected, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kResult);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Uint32T> tmp4;
    TNode<Smi> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Object> tmp9;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = kArrayFromAsyncIterableResolveResumeStateStepSlot_0(state_);
        std::tie(tmp2, tmp3) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_0(
            state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp1 })
                                   .Flatten();
        tmp4 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kCloseAsyncIterator_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kCloseAsyncIterator);
        tmp5 = SmiTag_ArrayFromAsyncLabels_0(state_, TNode<Uint32T> { tmp4 });
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp2, tmp3 }, tmp5);
        tmp6 = kArrayFromAsyncIterableResolveErrorSlot_0(state_);
        std::tie(tmp7, tmp8) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
            state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp6 })
                                   .Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp7, tmp8 }, parameter3);
        tmp9 = CreateArrayFromIterableAsynchronously_0(state_, TNode<Context> { tmp0 });
        CodeStubAssembler(state_).Return(tmp9);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=438&c=1
void ArrayFromAsyncAsyncIteratorCloseOnException_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_iterator, compiler::CodeAssemblerLabel* label_RejectPromise)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<String> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp4;
    TNode<Undefined> tmp5;
    TNode<BoolT> tmp6;
    TNode<Object> tmp8;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { p_context });
        tmp1 = kReturnString_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch3__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch3__label);
            tmp2 = CodeStubAssembler(state_).GetProperty(TNode<Context> { tmp0 }, TNode<Object> { p_iterator.object }, TNode<Object> { tmp1 });
        }
        if (catch3__label.is_used()) {
            compiler::CodeAssemblerLabel catch3_skip(&ca_);
            ca_.Goto(&catch3_skip);
            ca_.Bind(&catch3__label, &tmp4);
            ca_.Goto(&block5);
            ca_.Bind(&catch3_skip);
        }
        tmp5 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch7__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch7__label);
            tmp6 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { tmp2 }, TNode<HeapObject> { tmp5 });
        }
        if (catch7__label.is_used()) {
            compiler::CodeAssemblerLabel catch7_skip(&ca_);
            ca_.Goto(&catch7_skip);
            ca_.Bind(&catch7__label, &tmp8);
            ca_.Goto(&block8);
            ca_.Bind(&catch7_skip);
        }
        ca_.Branch(tmp6, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<HeapObject> tmp9;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp9 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block4, tmp4, tmp9);
    }

    TNode<HeapObject> tmp10;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp10 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block4, tmp8, tmp10);
    }

    TNode<BoolT> tmp11;
    TNode<Object> tmp13;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        compiler::CodeAssemblerExceptionHandlerLabel catch12__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch12__label);
            tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        }
        if (catch12__label.is_used()) {
            compiler::CodeAssemblerLabel catch12_skip(&ca_);
            ca_.Goto(&catch12_skip);
            ca_.Bind(&catch12__label, &tmp13);
            ca_.Goto(&block12);
            ca_.Bind(&catch12_skip);
        }
        ca_.Goto(&block11, tmp11);
    }

    TNode<HeapObject> tmp14;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp14 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block4, tmp13, tmp14);
    }

    TNode<Null> tmp15;
    TNode<BoolT> tmp16;
    TNode<Object> tmp18;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp15 = Null_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch17__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch17__label);
            tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { tmp2 }, TNode<HeapObject> { tmp15 });
        }
        if (catch17__label.is_used()) {
            compiler::CodeAssemblerLabel catch17_skip(&ca_);
            ca_.Goto(&catch17_skip);
            ca_.Bind(&catch17__label, &tmp18);
            ca_.Goto(&block13);
            ca_.Bind(&catch17_skip);
        }
        ca_.Goto(&block11, tmp16);
    }

    TNode<HeapObject> tmp19;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp19 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block4, tmp18, tmp19);
    }

    TNode<BoolT> phi_bb11_6;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_6);
        ca_.Branch(phi_bb11_6, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(label_RejectPromise);
    }

    TNode<Object> tmp20;
    TNode<Object> tmp22;
    TNode<Uint32T> tmp23;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp28;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerExceptionHandlerLabel catch21__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch21__label);
            tmp20 = CodeStubAssembler(state_).Call(TNode<Context> { tmp0 }, TNode<Object> { tmp2 }, TNode<Object> { p_iterator.object });
        }
        if (catch21__label.is_used()) {
            compiler::CodeAssemblerLabel catch21_skip(&ca_);
            ca_.Goto(&catch21_skip);
            ca_.Bind(&catch21__label, &tmp22);
            ca_.Goto(&block14);
            ca_.Bind(&catch21_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch24__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch24__label);
            tmp23 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kRejectPromise_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kRejectPromise);
        }
        if (catch24__label.is_used()) {
            compiler::CodeAssemblerLabel catch24_skip(&ca_);
            ca_.Goto(&catch24_skip);
            ca_.Bind(&catch24__label, &tmp25);
            ca_.Goto(&block15);
            ca_.Bind(&catch24_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch27__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch27__label);
            tmp26 = ArrayFromAsyncIterableAwaitPoint_0(state_, TNode<Context> { tmp0 }, TNode<Uint32T> { tmp23 }, TNode<Object> { tmp20 });
        }
        if (catch27__label.is_used()) {
            compiler::CodeAssemblerLabel catch27_skip(&ca_);
            ca_.Goto(&catch27_skip);
            ca_.Bind(&catch27__label, &tmp28);
            ca_.Goto(&block16);
            ca_.Bind(&catch27_skip);
        }
        ca_.Goto(&block3);
    }

    TNode<HeapObject> tmp29;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp29 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block4, tmp22, tmp29);
    }

    TNode<HeapObject> tmp30;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp30 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block4, tmp25, tmp30);
    }

    TNode<HeapObject> tmp31;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp31 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block4, tmp28, tmp31);
    }

    TNode<Object> phi_bb4_3;
    TNode<HeapObject> phi_bb4_4;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        ca_.Goto(&block3);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block17);
    }

    ca_.Bind(&block17);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResumeStateStepSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResumeStateAwaitedValueSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResumeStateLenSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResumeStateIndexSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolvePromiseSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolvePromiseFunctionSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveOnFulfilledFunctionSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveOnRejectedFunctionSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResultArraySlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveArrayLikeSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveErrorSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveMapfnSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveThisArgSlot_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveLength_0(
    compiler::CodeAssemblerState* state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveResumeStateStepSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResumeStateStepSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveResumeStateStepSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveResumeStateAwaitedValueSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResumeStateAwaitedValueSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveResumeStateAwaitedValueSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveResumeStateLenSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResumeStateLenSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveResumeStateLenSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveResumeStateIndexSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResumeStateIndexSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveResumeStateIndexSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolvePromiseSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolvePromiseSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolvePromiseSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolvePromiseFunctionSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolvePromiseFunctionSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolvePromiseFunctionSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveOnFulfilledFunctionSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveOnFulfilledFunctionSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveOnFulfilledFunctionSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveOnRejectedFunctionSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveOnRejectedFunctionSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveOnRejectedFunctionSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveResultArraySlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveResultArraySlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveResultArraySlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveArrayLikeSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveArrayLikeSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveArrayLikeSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveErrorSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveErrorSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveErrorSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveMapfnSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveMapfnSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveMapfnSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=483&c=1
TNode<IntPtrT> kArrayFromAsyncArrayLikeResolveThisArgSlot_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ArrayFromAsyncArrayLikeResolveContextSlots_constexpr_kArrayFromAsyncArrayLikeResolveThisArgSlot_0(
        state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveThisArgSlot);
    TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT> { tmp0 });
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=519&c=1
TNode<Context> CreateArrayFromAsyncArrayLikeResolveContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TorqueStructArrayFromAsyncArrayLikeResumeState_0 p_resumeState, TNode<JSPromise> p_promise, TNode<JSReceiver> p_promiseFun, TNode<JSReceiver> p_arrayLike,
    TNode<JSReceiver> p_arr, TNode<Object> p_error, TNode<Object> p_mapfn, TNode<Object> p_thisArg, TNode<NativeContext> p_nativeContext)
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
    TNode<Smi> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<JSFunction> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<JSFunction> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0
            = FromConstexpr_intptr_constexpr_intptr_0(state_, ArrayBuiltins::ArrayFromAsyncArrayLikeResolveContextSlots::kArrayFromAsyncArrayLikeResolveLength);
        tmp1 = AllocateSyntheticFunctionContext_1(state_, TNode<NativeContext> { p_nativeContext }, TNode<IntPtrT> { tmp0 });
        tmp2 = (TNode<Context> { tmp1 });
        tmp3 = kArrayFromAsyncArrayLikeResolveResumeStateStepSlot_0(state_);
        tmp4 = SmiTag_ArrayFromAsyncLabels_0(state_, TNode<Uint32T> { p_resumeState.step });
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_SmiTagged_ArrayFromAsyncLabels_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp3 }, TNode<Smi> { tmp4 });
        tmp5 = kArrayFromAsyncArrayLikeResolveResumeStateAwaitedValueSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp5 }, TNode<Object> { p_resumeState.awaitedValue });
        tmp6 = kArrayFromAsyncArrayLikeResolveResumeStateLenSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Number_Number_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp6 }, TNode<Number> { p_resumeState.len });
        tmp7 = kArrayFromAsyncArrayLikeResolveResumeStateIndexSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_Smi_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp7 }, TNode<Smi> { p_resumeState.index });
        tmp8 = kArrayFromAsyncArrayLikeResolvePromiseSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSPromise_JSPromise_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp8 }, TNode<JSPromise> { p_promise });
        tmp9 = kArrayFromAsyncArrayLikeResolvePromiseFunctionSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSReceiver_JSReceiver_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp9 }, TNode<JSReceiver> { p_promiseFun });
        tmp10 = kArrayFromAsyncArrayLikeResolveOnFulfilledFunctionSlot_0(state_);
        tmp11 = CodeStubAssembler(state_).AllocateRootFunctionWithContext(
            RootIndex::kArrayFromAsyncArrayLikeOnFulfilledSharedFun, TNode<Context> { tmp2 }, TNode<NativeContext> { p_nativeContext });
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Undefined_OR_JSFunction_JSFunction_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp10 }, TNode<JSFunction> { tmp11 });
        tmp12 = kArrayFromAsyncArrayLikeResolveOnRejectedFunctionSlot_0(state_);
        tmp13 = CodeStubAssembler(state_).AllocateRootFunctionWithContext(
            RootIndex::kArrayFromAsyncArrayLikeOnRejectedSharedFun, TNode<Context> { tmp2 }, TNode<NativeContext> { p_nativeContext });
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Undefined_OR_JSFunction_JSFunction_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp12 }, TNode<JSFunction> { tmp13 });
        tmp14 = kArrayFromAsyncArrayLikeResolveResultArraySlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSReceiver_JSReceiver_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp14 }, TNode<JSReceiver> { p_arr });
        tmp15 = kArrayFromAsyncArrayLikeResolveArrayLikeSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSReceiver_JSReceiver_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp15 }, TNode<JSReceiver> { p_arrayLike });
        tmp16 = kArrayFromAsyncArrayLikeResolveErrorSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp16 }, TNode<Object> { p_error });
        tmp17 = kArrayFromAsyncArrayLikeResolveMapfnSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp17 }, TNode<Object> { p_mapfn });
        tmp18 = kArrayFromAsyncArrayLikeResolveThisArgSlot_0(state_);
        InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_JSAny_0(
            state_, TNode<Context> { tmp2 }, TNode<IntPtrT> { tmp18 }, TNode<Object> { p_thisArg });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Context> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=601&c=1
TNode<Object> CreateArrayFromArrayLikeAsynchronously_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T, Uint32T> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Smi> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Smi> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T, Uint32T> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block39(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T, Uint32T> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T> block43(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Smi> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T, Uint32T> block51(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T> block52(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Smi> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Smi, Smi> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Smi> block56(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block57(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block58(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T, Uint32T> block61(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T> block62(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Smi> block64(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block65(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block66(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T, Uint32T> block69(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object, Uint32T> block70(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block71(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Smi, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<Object> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Object> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Object> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<Object> tmp22;
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    TNode<Uint32T> tmp25;
    TNode<Object> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<Object> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<Object> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<Object> tmp38;
    TNode<Number> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<Object> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<Object> tmp44;
    TNode<Smi> tmp45;
    TNode<Undefined> tmp46;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kArrayFromAsyncArrayLikeResolveMapfnSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch3__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch3__label);
            std::tie(tmp1, tmp2) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp0 })
                                       .Flatten();
        }
        if (catch3__label.is_used()) {
            compiler::CodeAssemblerLabel catch3_skip(&ca_);
            ca_.Goto(&catch3_skip);
            ca_.Bind(&catch3__label, &tmp4);
            ca_.Goto(&block4);
            ca_.Bind(&catch3_skip);
        }
        tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp1, tmp2 });
        tmp6 = kArrayFromAsyncArrayLikeResolveThisArgSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch9__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch9__label);
            std::tie(tmp7, tmp8) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp6 })
                                       .Flatten();
        }
        if (catch9__label.is_used()) {
            compiler::CodeAssemblerLabel catch9_skip(&ca_);
            ca_.Goto(&catch9_skip);
            ca_.Bind(&catch9__label, &tmp10);
            ca_.Goto(&block5);
            ca_.Bind(&catch9_skip);
        }
        tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp7, tmp8 });
        tmp12 = kArrayFromAsyncArrayLikeResolveResultArraySlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch15__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch15__label);
            std::tie(tmp13, tmp14) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSReceiver_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp12 })
                                         .Flatten();
        }
        if (catch15__label.is_used()) {
            compiler::CodeAssemblerLabel catch15_skip(&ca_);
            ca_.Goto(&catch15_skip);
            ca_.Bind(&catch15__label, &tmp16);
            ca_.Goto(&block6);
            ca_.Bind(&catch15_skip);
        }
        tmp17 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference { tmp13, tmp14 });
        tmp18 = kArrayFromAsyncArrayLikeResolveResumeStateStepSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch21__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch21__label);
            std::tie(tmp19, tmp20) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp18 })
                                         .Flatten();
        }
        if (catch21__label.is_used()) {
            compiler::CodeAssemblerLabel catch21_skip(&ca_);
            ca_.Goto(&catch21_skip);
            ca_.Bind(&catch21__label, &tmp22);
            ca_.Goto(&block7);
            ca_.Bind(&catch21_skip);
        }
        tmp23 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp19, tmp20 });
        tmp24 = (TNode<Smi> { tmp23 });
        compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
            tmp25 = SmiUntag_ArrayFromAsyncLabels_0(state_, TNode<Smi> { tmp24 });
        }
        if (catch26__label.is_used()) {
            compiler::CodeAssemblerLabel catch26_skip(&ca_);
            ca_.Goto(&catch26_skip);
            ca_.Bind(&catch26__label, &tmp27);
            ca_.Goto(&block8);
            ca_.Bind(&catch26_skip);
        }
        tmp28 = kArrayFromAsyncArrayLikeResolveResumeStateAwaitedValueSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch31__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch31__label);
            std::tie(tmp29, tmp30) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp28 })
                                         .Flatten();
        }
        if (catch31__label.is_used()) {
            compiler::CodeAssemblerLabel catch31_skip(&ca_);
            ca_.Goto(&catch31_skip);
            ca_.Bind(&catch31__label, &tmp32);
            ca_.Goto(&block9);
            ca_.Bind(&catch31_skip);
        }
        tmp33 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp29, tmp30 });
        tmp34 = kArrayFromAsyncArrayLikeResolveResumeStateLenSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch37__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch37__label);
            std::tie(tmp35, tmp36) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Number_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp34 })
                                         .Flatten();
        }
        if (catch37__label.is_used()) {
            compiler::CodeAssemblerLabel catch37_skip(&ca_);
            ca_.Goto(&catch37_skip);
            ca_.Bind(&catch37__label, &tmp38);
            ca_.Goto(&block10);
            ca_.Bind(&catch37_skip);
        }
        tmp39 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference { tmp35, tmp36 });
        tmp40 = kArrayFromAsyncArrayLikeResolveResumeStateIndexSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch43__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch43__label);
            std::tie(tmp41, tmp42) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp40 })
                                         .Flatten();
        }
        if (catch43__label.is_used()) {
            compiler::CodeAssemblerLabel catch43_skip(&ca_);
            ca_.Goto(&catch43_skip);
            ca_.Bind(&catch43__label, &tmp44);
            ca_.Goto(&block11);
            ca_.Bind(&catch43_skip);
        }
        tmp45 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp41, tmp42 });
        tmp46 = Undefined_0(state_);
        ca_.Goto(&block14, tmp25, tmp45, tmp46);
    }

    TNode<HeapObject> tmp47;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp47 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp4, tmp47);
    }

    TNode<HeapObject> tmp48;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp48 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp10, tmp48);
    }

    TNode<HeapObject> tmp49;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp49 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp16, tmp49);
    }

    TNode<HeapObject> tmp50;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp50 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp22, tmp50);
    }

    TNode<HeapObject> tmp51;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp51 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp27, tmp51);
    }

    TNode<HeapObject> tmp52;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp52 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp32, tmp52);
    }

    TNode<HeapObject> tmp53;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp53 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp38, tmp53);
    }

    TNode<HeapObject> tmp54;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp54 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp44, tmp54);
    }

    TNode<Uint32T> phi_bb14_4;
    TNode<Smi> phi_bb14_7;
    TNode<Object> phi_bb14_8;
    TNode<BoolT> tmp55;
    TNode<Object> tmp57;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_4, &phi_bb14_7, &phi_bb14_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch56__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch56__label);
            tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        }
        if (catch56__label.is_used()) {
            compiler::CodeAssemblerLabel catch56_skip(&ca_);
            ca_.Goto(&catch56_skip);
            ca_.Bind(&catch56__label, &tmp57);
            ca_.Goto(&block15, phi_bb14_4, phi_bb14_7, phi_bb14_8);
            ca_.Bind(&catch56_skip);
        }
        ca_.Branch(tmp55, &block12, std::vector<compiler::Node*> { phi_bb14_4, phi_bb14_7, phi_bb14_8 }, &block13,
            std::vector<compiler::Node*> { phi_bb14_4, phi_bb14_7, phi_bb14_8 });
    }

    TNode<Uint32T> phi_bb15_4;
    TNode<Smi> phi_bb15_7;
    TNode<Object> phi_bb15_8;
    TNode<HeapObject> tmp58;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_4, &phi_bb15_7, &phi_bb15_8);
        tmp58 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp57, tmp58);
    }

    TNode<Uint32T> phi_bb12_4;
    TNode<Smi> phi_bb12_7;
    TNode<Object> phi_bb12_8;
    TNode<Uint32T> tmp59;
    TNode<Object> tmp61;
    TNode<BoolT> tmp62;
    TNode<Object> tmp64;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_4, &phi_bb12_7, &phi_bb12_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch60__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch60__label);
            tmp59 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetArrayLikeValue);
        }
        if (catch60__label.is_used()) {
            compiler::CodeAssemblerLabel catch60_skip(&ca_);
            ca_.Goto(&catch60_skip);
            ca_.Bind(&catch60__label, &tmp61);
            ca_.Goto(&block18, phi_bb12_4, phi_bb12_7, phi_bb12_8, phi_bb12_4, phi_bb12_4);
            ca_.Bind(&catch60_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch63__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch63__label);
            tmp62 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb12_4 }, TNode<Uint32T> { tmp59 });
        }
        if (catch63__label.is_used()) {
            compiler::CodeAssemblerLabel catch63_skip(&ca_);
            ca_.Goto(&catch63_skip);
            ca_.Bind(&catch63__label, &tmp64);
            ca_.Goto(&block19, phi_bb12_4, phi_bb12_7, phi_bb12_8, phi_bb12_4);
            ca_.Bind(&catch63_skip);
        }
        ca_.Branch(tmp62, &block16, std::vector<compiler::Node*> { phi_bb12_4, phi_bb12_7, phi_bb12_8 }, &block17,
            std::vector<compiler::Node*> { phi_bb12_4, phi_bb12_7, phi_bb12_8 });
    }

    TNode<Uint32T> phi_bb18_4;
    TNode<Smi> phi_bb18_7;
    TNode<Object> phi_bb18_8;
    TNode<Uint32T> phi_bb18_9;
    TNode<Uint32T> phi_bb18_10;
    TNode<HeapObject> tmp65;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_4, &phi_bb18_7, &phi_bb18_8, &phi_bb18_9, &phi_bb18_10);
        tmp65 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp61, tmp65);
    }

    TNode<Uint32T> phi_bb19_4;
    TNode<Smi> phi_bb19_7;
    TNode<Object> phi_bb19_8;
    TNode<Uint32T> phi_bb19_9;
    TNode<HeapObject> tmp66;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_4, &phi_bb19_7, &phi_bb19_8, &phi_bb19_9);
        tmp66 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp64, tmp66);
    }

    TNode<Uint32T> phi_bb16_4;
    TNode<Smi> phi_bb16_7;
    TNode<Object> phi_bb16_8;
    TNode<IntPtrT> tmp67;
    TNode<Object> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<Object> tmp71;
    TNode<JSReceiver> tmp72;
    TNode<BoolT> tmp73;
    TNode<Object> tmp75;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_4, &phi_bb16_7, &phi_bb16_8);
        tmp67 = kArrayFromAsyncArrayLikeResolveArrayLikeSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch70__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch70__label);
            std::tie(tmp68, tmp69) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSReceiver_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp67 })
                                         .Flatten();
        }
        if (catch70__label.is_used()) {
            compiler::CodeAssemblerLabel catch70_skip(&ca_);
            ca_.Goto(&catch70_skip);
            ca_.Bind(&catch70__label, &tmp71);
            ca_.Goto(&block21, phi_bb16_4, phi_bb16_7, phi_bb16_8);
            ca_.Bind(&catch70_skip);
        }
        tmp72 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference { tmp68, tmp69 });
        compiler::CodeAssemblerExceptionHandlerLabel catch74__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch74__label);
            tmp73 = NumberIsLessThan_0(state_, TNode<Number> { phi_bb16_7 }, TNode<Number> { tmp39 });
        }
        if (catch74__label.is_used()) {
            compiler::CodeAssemblerLabel catch74_skip(&ca_);
            ca_.Goto(&catch74_skip);
            ca_.Bind(&catch74__label, &tmp75);
            ca_.Goto(&block24, phi_bb16_4, phi_bb16_7, phi_bb16_8, phi_bb16_7);
            ca_.Bind(&catch74_skip);
        }
        ca_.Branch(tmp73, &block22, std::vector<compiler::Node*> { phi_bb16_4, phi_bb16_7, phi_bb16_8 }, &block23,
            std::vector<compiler::Node*> { phi_bb16_4, phi_bb16_7, phi_bb16_8 });
    }

    TNode<Uint32T> phi_bb21_4;
    TNode<Smi> phi_bb21_7;
    TNode<Object> phi_bb21_8;
    TNode<HeapObject> tmp76;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_4, &phi_bb21_7, &phi_bb21_8);
        tmp76 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp71, tmp76);
    }

    TNode<Uint32T> phi_bb24_4;
    TNode<Smi> phi_bb24_7;
    TNode<Object> phi_bb24_8;
    TNode<Smi> phi_bb24_10;
    TNode<HeapObject> tmp77;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_4, &phi_bb24_7, &phi_bb24_8, &phi_bb24_10);
        tmp77 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp75, tmp77);
    }

    TNode<Uint32T> phi_bb22_4;
    TNode<Smi> phi_bb22_7;
    TNode<Object> phi_bb22_8;
    TNode<Object> tmp78;
    TNode<Object> tmp80;
    TNode<Uint32T> tmp81;
    TNode<Object> tmp83;
    TNode<Object> tmp84;
    TNode<Object> tmp86;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_4, &phi_bb22_7, &phi_bb22_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch79__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch79__label);
            tmp78 = CodeStubAssembler(state_).GetProperty(TNode<Context> { p_context }, TNode<Object> { tmp72 }, TNode<Object> { phi_bb22_7 });
        }
        if (catch79__label.is_used()) {
            compiler::CodeAssemblerLabel catch79_skip(&ca_);
            ca_.Goto(&catch79_skip);
            ca_.Bind(&catch79__label, &tmp80);
            ca_.Goto(&block25, phi_bb22_4, phi_bb22_7, phi_bb22_8, phi_bb22_7);
            ca_.Bind(&catch79_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch82__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch82__label);
            tmp81 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kCheckArrayLikeValueAndMapping_0(
                state_, ArrayBuiltins::ArrayFromAsyncLabels::kCheckArrayLikeValueAndMapping);
        }
        if (catch82__label.is_used()) {
            compiler::CodeAssemblerLabel catch82_skip(&ca_);
            ca_.Goto(&catch82_skip);
            ca_.Bind(&catch82__label, &tmp83);
            ca_.Goto(&block26, phi_bb22_4, phi_bb22_7, phi_bb22_8);
            ca_.Bind(&catch82_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch85__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch85__label);
            tmp84 = ArrayFromAsyncArrayLikeAwaitPoint_0(state_, TNode<Context> { p_context }, TNode<Uint32T> { tmp81 }, TNode<Object> { tmp78 });
        }
        if (catch85__label.is_used()) {
            compiler::CodeAssemblerLabel catch85_skip(&ca_);
            ca_.Goto(&catch85_skip);
            ca_.Bind(&catch85__label, &tmp86);
            ca_.Goto(&block27, phi_bb22_4, phi_bb22_7, phi_bb22_8);
            ca_.Bind(&catch85_skip);
        }
        ca_.Goto(&block1, tmp84);
    }

    TNode<Uint32T> phi_bb25_4;
    TNode<Smi> phi_bb25_7;
    TNode<Object> phi_bb25_8;
    TNode<Smi> phi_bb25_11;
    TNode<HeapObject> tmp87;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_4, &phi_bb25_7, &phi_bb25_8, &phi_bb25_11);
        tmp87 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp80, tmp87);
    }

    TNode<Uint32T> phi_bb26_4;
    TNode<Smi> phi_bb26_7;
    TNode<Object> phi_bb26_8;
    TNode<HeapObject> tmp88;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_4, &phi_bb26_7, &phi_bb26_8);
        tmp88 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp83, tmp88);
    }

    TNode<Uint32T> phi_bb27_4;
    TNode<Smi> phi_bb27_7;
    TNode<Object> phi_bb27_8;
    TNode<HeapObject> tmp89;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_4, &phi_bb27_7, &phi_bb27_8);
        tmp89 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp86, tmp89);
    }

    TNode<Uint32T> phi_bb23_4;
    TNode<Smi> phi_bb23_7;
    TNode<Object> phi_bb23_8;
    TNode<Uint32T> tmp90;
    TNode<Object> tmp92;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_4, &phi_bb23_7, &phi_bb23_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch91__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch91__label);
            tmp90 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kDoneAndResolvePromise_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kDoneAndResolvePromise);
        }
        if (catch91__label.is_used()) {
            compiler::CodeAssemblerLabel catch91_skip(&ca_);
            ca_.Goto(&catch91_skip);
            ca_.Bind(&catch91__label, &tmp92);
            ca_.Goto(&block28, phi_bb23_4, phi_bb23_7, phi_bb23_8);
            ca_.Bind(&catch91_skip);
        }
        ca_.Goto(&block20, tmp90, phi_bb23_7, phi_bb23_8);
    }

    TNode<Uint32T> phi_bb28_4;
    TNode<Smi> phi_bb28_7;
    TNode<Object> phi_bb28_8;
    TNode<HeapObject> tmp93;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_4, &phi_bb28_7, &phi_bb28_8);
        tmp93 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp92, tmp93);
    }

    TNode<Uint32T> phi_bb17_4;
    TNode<Smi> phi_bb17_7;
    TNode<Object> phi_bb17_8;
    TNode<Uint32T> tmp94;
    TNode<Object> tmp96;
    TNode<BoolT> tmp97;
    TNode<Object> tmp99;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_4, &phi_bb17_7, &phi_bb17_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch95__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch95__label);
            tmp94 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kCheckArrayLikeValueAndMapping);
        }
        if (catch95__label.is_used()) {
            compiler::CodeAssemblerLabel catch95_skip(&ca_);
            ca_.Goto(&catch95_skip);
            ca_.Bind(&catch95__label, &tmp96);
            ca_.Goto(&block31, phi_bb17_4, phi_bb17_7, phi_bb17_8, phi_bb17_4, phi_bb17_4);
            ca_.Bind(&catch95_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch98__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch98__label);
            tmp97 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb17_4 }, TNode<Uint32T> { tmp94 });
        }
        if (catch98__label.is_used()) {
            compiler::CodeAssemblerLabel catch98_skip(&ca_);
            ca_.Goto(&catch98_skip);
            ca_.Bind(&catch98__label, &tmp99);
            ca_.Goto(&block32, phi_bb17_4, phi_bb17_7, phi_bb17_8, phi_bb17_4);
            ca_.Bind(&catch98_skip);
        }
        ca_.Branch(tmp97, &block29, std::vector<compiler::Node*> { phi_bb17_4, phi_bb17_7, phi_bb17_8 }, &block30,
            std::vector<compiler::Node*> { phi_bb17_4, phi_bb17_7, phi_bb17_8 });
    }

    TNode<Uint32T> phi_bb31_4;
    TNode<Smi> phi_bb31_7;
    TNode<Object> phi_bb31_8;
    TNode<Uint32T> phi_bb31_9;
    TNode<Uint32T> phi_bb31_10;
    TNode<HeapObject> tmp100;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_4, &phi_bb31_7, &phi_bb31_8, &phi_bb31_9, &phi_bb31_10);
        tmp100 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp96, tmp100);
    }

    TNode<Uint32T> phi_bb32_4;
    TNode<Smi> phi_bb32_7;
    TNode<Object> phi_bb32_8;
    TNode<Uint32T> phi_bb32_9;
    TNode<HeapObject> tmp101;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_4, &phi_bb32_7, &phi_bb32_8, &phi_bb32_9);
        tmp101 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp99, tmp101);
    }

    TNode<Uint32T> phi_bb29_4;
    TNode<Smi> phi_bb29_7;
    TNode<Object> phi_bb29_8;
    TNode<Undefined> tmp102;
    TNode<BoolT> tmp103;
    TNode<Object> tmp105;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_4, &phi_bb29_7, &phi_bb29_8);
        tmp102 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch104__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch104__label);
            tmp103 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp5 }, TNode<HeapObject> { tmp102 });
        }
        if (catch104__label.is_used()) {
            compiler::CodeAssemblerLabel catch104_skip(&ca_);
            ca_.Goto(&catch104_skip);
            ca_.Bind(&catch104__label, &tmp105);
            ca_.Goto(&block34, phi_bb29_4, phi_bb29_7, phi_bb29_8);
            ca_.Bind(&catch104_skip);
        }
        ca_.Branch(tmp103, &block35, std::vector<compiler::Node*> { phi_bb29_4, phi_bb29_7, phi_bb29_8 }, &block36,
            std::vector<compiler::Node*> { phi_bb29_4, phi_bb29_7, phi_bb29_8 });
    }

    TNode<Uint32T> phi_bb34_4;
    TNode<Smi> phi_bb34_7;
    TNode<Object> phi_bb34_8;
    TNode<HeapObject> tmp106;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_4, &phi_bb34_7, &phi_bb34_8);
        tmp106 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp105, tmp106);
    }

    TNode<Uint32T> phi_bb35_4;
    TNode<Smi> phi_bb35_7;
    TNode<Object> phi_bb35_8;
    TNode<Uint32T> tmp107;
    TNode<Object> tmp109;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_4, &phi_bb35_7, &phi_bb35_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch108__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch108__label);
            tmp107 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetArrayLikeValueWithMapping_0(
                state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetArrayLikeValueWithMapping);
        }
        if (catch108__label.is_used()) {
            compiler::CodeAssemblerLabel catch108_skip(&ca_);
            ca_.Goto(&catch108_skip);
            ca_.Bind(&catch108__label, &tmp109);
            ca_.Goto(&block38, phi_bb35_4, phi_bb35_7, phi_bb35_8);
            ca_.Bind(&catch108_skip);
        }
        ca_.Goto(&block37, tmp107, phi_bb35_7, phi_bb35_8);
    }

    TNode<Uint32T> phi_bb38_4;
    TNode<Smi> phi_bb38_7;
    TNode<Object> phi_bb38_8;
    TNode<HeapObject> tmp110;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_4, &phi_bb38_7, &phi_bb38_8);
        tmp110 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp109, tmp110);
    }

    TNode<Uint32T> phi_bb36_4;
    TNode<Smi> phi_bb36_7;
    TNode<Object> phi_bb36_8;
    TNode<Uint32T> tmp111;
    TNode<Object> tmp113;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_4, &phi_bb36_7, &phi_bb36_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch112__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch112__label);
            tmp111 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kAddArrayLikeValueToTheArray_0(
                state_, ArrayBuiltins::ArrayFromAsyncLabels::kAddArrayLikeValueToTheArray);
        }
        if (catch112__label.is_used()) {
            compiler::CodeAssemblerLabel catch112_skip(&ca_);
            ca_.Goto(&catch112_skip);
            ca_.Bind(&catch112__label, &tmp113);
            ca_.Goto(&block39, phi_bb36_4, phi_bb36_7, phi_bb36_8);
            ca_.Bind(&catch112_skip);
        }
        ca_.Goto(&block37, tmp111, phi_bb36_7, phi_bb36_8);
    }

    TNode<Uint32T> phi_bb39_4;
    TNode<Smi> phi_bb39_7;
    TNode<Object> phi_bb39_8;
    TNode<HeapObject> tmp114;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_4, &phi_bb39_7, &phi_bb39_8);
        tmp114 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp113, tmp114);
    }

    TNode<Uint32T> phi_bb37_4;
    TNode<Smi> phi_bb37_7;
    TNode<Object> phi_bb37_8;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_4, &phi_bb37_7, &phi_bb37_8);
        ca_.Goto(&block33, phi_bb37_4, phi_bb37_7, phi_bb37_8);
    }

    TNode<Uint32T> phi_bb30_4;
    TNode<Smi> phi_bb30_7;
    TNode<Object> phi_bb30_8;
    TNode<Uint32T> tmp115;
    TNode<Object> tmp117;
    TNode<BoolT> tmp118;
    TNode<Object> tmp120;
    if (block30.is_used()) {
        ca_.Bind(&block30, &phi_bb30_4, &phi_bb30_7, &phi_bb30_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch116__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch116__label);
            tmp115 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetArrayLikeValueWithMapping);
        }
        if (catch116__label.is_used()) {
            compiler::CodeAssemblerLabel catch116_skip(&ca_);
            ca_.Goto(&catch116_skip);
            ca_.Bind(&catch116__label, &tmp117);
            ca_.Goto(&block42, phi_bb30_4, phi_bb30_7, phi_bb30_8, phi_bb30_4, phi_bb30_4);
            ca_.Bind(&catch116_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch119__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch119__label);
            tmp118 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb30_4 }, TNode<Uint32T> { tmp115 });
        }
        if (catch119__label.is_used()) {
            compiler::CodeAssemblerLabel catch119_skip(&ca_);
            ca_.Goto(&catch119_skip);
            ca_.Bind(&catch119__label, &tmp120);
            ca_.Goto(&block43, phi_bb30_4, phi_bb30_7, phi_bb30_8, phi_bb30_4);
            ca_.Bind(&catch119_skip);
        }
        ca_.Branch(tmp118, &block40, std::vector<compiler::Node*> { phi_bb30_4, phi_bb30_7, phi_bb30_8 }, &block41,
            std::vector<compiler::Node*> { phi_bb30_4, phi_bb30_7, phi_bb30_8 });
    }

    TNode<Uint32T> phi_bb42_4;
    TNode<Smi> phi_bb42_7;
    TNode<Object> phi_bb42_8;
    TNode<Uint32T> phi_bb42_9;
    TNode<Uint32T> phi_bb42_10;
    TNode<HeapObject> tmp121;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_4, &phi_bb42_7, &phi_bb42_8, &phi_bb42_9, &phi_bb42_10);
        tmp121 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp117, tmp121);
    }

    TNode<Uint32T> phi_bb43_4;
    TNode<Smi> phi_bb43_7;
    TNode<Object> phi_bb43_8;
    TNode<Uint32T> phi_bb43_9;
    TNode<HeapObject> tmp122;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_4, &phi_bb43_7, &phi_bb43_8, &phi_bb43_9);
        tmp122 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp120, tmp122);
    }

    TNode<Uint32T> phi_bb40_4;
    TNode<Smi> phi_bb40_7;
    TNode<Object> phi_bb40_8;
    TNode<JSReceiver> tmp123;
    TNode<Object> tmp125;
    TNode<Object> tmp126;
    TNode<Object> tmp128;
    TNode<Uint32T> tmp129;
    TNode<Object> tmp131;
    TNode<Object> tmp132;
    TNode<Object> tmp134;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_4, &phi_bb40_7, &phi_bb40_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch124__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch124__label);
            tmp123 = UnsafeCast_Callable_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp5 });
        }
        if (catch124__label.is_used()) {
            compiler::CodeAssemblerLabel catch124_skip(&ca_);
            ca_.Goto(&catch124_skip);
            ca_.Bind(&catch124__label, &tmp125);
            ca_.Goto(&block45, phi_bb40_4, phi_bb40_7, phi_bb40_8);
            ca_.Bind(&catch124_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch127__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch127__label);
            tmp126 = CodeStubAssembler(state_).Call(
                TNode<Context> { p_context }, TNode<Object> { tmp123 }, TNode<Object> { tmp11 }, TNode<Object> { tmp33 }, TNode<Object> { phi_bb40_7 });
        }
        if (catch127__label.is_used()) {
            compiler::CodeAssemblerLabel catch127_skip(&ca_);
            ca_.Goto(&catch127_skip);
            ca_.Bind(&catch127__label, &tmp128);
            ca_.Goto(&block46, phi_bb40_4, phi_bb40_7, phi_bb40_8, phi_bb40_7);
            ca_.Bind(&catch127_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch130__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch130__label);
            tmp129 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kAddArrayLikeValueToTheArray_0(
                state_, ArrayBuiltins::ArrayFromAsyncLabels::kAddArrayLikeValueToTheArray);
        }
        if (catch130__label.is_used()) {
            compiler::CodeAssemblerLabel catch130_skip(&ca_);
            ca_.Goto(&catch130_skip);
            ca_.Bind(&catch130__label, &tmp131);
            ca_.Goto(&block47, phi_bb40_4, phi_bb40_7, phi_bb40_8);
            ca_.Bind(&catch130_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch133__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch133__label);
            tmp132 = ArrayFromAsyncArrayLikeAwaitPoint_0(state_, TNode<Context> { p_context }, TNode<Uint32T> { tmp129 }, TNode<Object> { tmp126 });
        }
        if (catch133__label.is_used()) {
            compiler::CodeAssemblerLabel catch133_skip(&ca_);
            ca_.Goto(&catch133_skip);
            ca_.Bind(&catch133__label, &tmp134);
            ca_.Goto(&block48, phi_bb40_4, phi_bb40_7, phi_bb40_8);
            ca_.Bind(&catch133_skip);
        }
        ca_.Goto(&block1, tmp132);
    }

    TNode<Uint32T> phi_bb45_4;
    TNode<Smi> phi_bb45_7;
    TNode<Object> phi_bb45_8;
    TNode<HeapObject> tmp135;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_4, &phi_bb45_7, &phi_bb45_8);
        tmp135 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp125, tmp135);
    }

    TNode<Uint32T> phi_bb46_4;
    TNode<Smi> phi_bb46_7;
    TNode<Object> phi_bb46_8;
    TNode<Smi> phi_bb46_13;
    TNode<HeapObject> tmp136;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_4, &phi_bb46_7, &phi_bb46_8, &phi_bb46_13);
        tmp136 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp128, tmp136);
    }

    TNode<Uint32T> phi_bb47_4;
    TNode<Smi> phi_bb47_7;
    TNode<Object> phi_bb47_8;
    TNode<HeapObject> tmp137;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_4, &phi_bb47_7, &phi_bb47_8);
        tmp137 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp131, tmp137);
    }

    TNode<Uint32T> phi_bb48_4;
    TNode<Smi> phi_bb48_7;
    TNode<Object> phi_bb48_8;
    TNode<HeapObject> tmp138;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_4, &phi_bb48_7, &phi_bb48_8);
        tmp138 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp134, tmp138);
    }

    TNode<Uint32T> phi_bb41_4;
    TNode<Smi> phi_bb41_7;
    TNode<Object> phi_bb41_8;
    TNode<Uint32T> tmp139;
    TNode<Object> tmp141;
    TNode<BoolT> tmp142;
    TNode<Object> tmp144;
    if (block41.is_used()) {
        ca_.Bind(&block41, &phi_bb41_4, &phi_bb41_7, &phi_bb41_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch140__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch140__label);
            tmp139 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kAddArrayLikeValueToTheArray);
        }
        if (catch140__label.is_used()) {
            compiler::CodeAssemblerLabel catch140_skip(&ca_);
            ca_.Goto(&catch140_skip);
            ca_.Bind(&catch140__label, &tmp141);
            ca_.Goto(&block51, phi_bb41_4, phi_bb41_7, phi_bb41_8, phi_bb41_4, phi_bb41_4);
            ca_.Bind(&catch140_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch143__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch143__label);
            tmp142 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb41_4 }, TNode<Uint32T> { tmp139 });
        }
        if (catch143__label.is_used()) {
            compiler::CodeAssemblerLabel catch143_skip(&ca_);
            ca_.Goto(&catch143_skip);
            ca_.Bind(&catch143__label, &tmp144);
            ca_.Goto(&block52, phi_bb41_4, phi_bb41_7, phi_bb41_8, phi_bb41_4);
            ca_.Bind(&catch143_skip);
        }
        ca_.Branch(tmp142, &block49, std::vector<compiler::Node*> { phi_bb41_4, phi_bb41_7, phi_bb41_8 }, &block50,
            std::vector<compiler::Node*> { phi_bb41_4, phi_bb41_7, phi_bb41_8 });
    }

    TNode<Uint32T> phi_bb51_4;
    TNode<Smi> phi_bb51_7;
    TNode<Object> phi_bb51_8;
    TNode<Uint32T> phi_bb51_9;
    TNode<Uint32T> phi_bb51_10;
    TNode<HeapObject> tmp145;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_4, &phi_bb51_7, &phi_bb51_8, &phi_bb51_9, &phi_bb51_10);
        tmp145 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp141, tmp145);
    }

    TNode<Uint32T> phi_bb52_4;
    TNode<Smi> phi_bb52_7;
    TNode<Object> phi_bb52_8;
    TNode<Uint32T> phi_bb52_9;
    TNode<HeapObject> tmp146;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_4, &phi_bb52_7, &phi_bb52_8, &phi_bb52_9);
        tmp146 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp144, tmp146);
    }

    TNode<Uint32T> phi_bb49_4;
    TNode<Smi> phi_bb49_7;
    TNode<Object> phi_bb49_8;
    TNode<Object> tmp147;
    TNode<Object> tmp149;
    TNode<Smi> tmp150;
    TNode<Object> tmp152;
    TNode<Smi> tmp153;
    TNode<Object> tmp155;
    TNode<IntPtrT> tmp156;
    TNode<Object> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<Object> tmp160;
    TNode<Uint32T> tmp161;
    TNode<Object> tmp163;
    if (block49.is_used()) {
        ca_.Bind(&block49, &phi_bb49_4, &phi_bb49_7, &phi_bb49_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch148__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch148__label);
            tmp147 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, tmp17, phi_bb49_7, tmp33);
        }
        if (catch148__label.is_used()) {
            compiler::CodeAssemblerLabel catch148_skip(&ca_);
            ca_.Goto(&catch148_skip);
            ca_.Bind(&catch148__label, &tmp149);
            ca_.Goto(&block54, phi_bb49_4, phi_bb49_7, phi_bb49_7);
            ca_.Bind(&catch148_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch151__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch151__label);
            tmp150 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
        }
        if (catch151__label.is_used()) {
            compiler::CodeAssemblerLabel catch151_skip(&ca_);
            ca_.Goto(&catch151_skip);
            ca_.Bind(&catch151__label, &tmp152);
            ca_.Goto(&block55, phi_bb49_4, phi_bb49_7, phi_bb49_7, phi_bb49_7);
            ca_.Bind(&catch151_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch154__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch154__label);
            tmp153 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { phi_bb49_7 }, TNode<Smi> { tmp150 });
        }
        if (catch154__label.is_used()) {
            compiler::CodeAssemblerLabel catch154_skip(&ca_);
            ca_.Goto(&catch154_skip);
            ca_.Bind(&catch154__label, &tmp155);
            ca_.Goto(&block56, phi_bb49_4, phi_bb49_7, phi_bb49_7);
            ca_.Bind(&catch154_skip);
        }
        tmp156 = kArrayFromAsyncArrayLikeResolveResumeStateIndexSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch159__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch159__label);
            std::tie(tmp157, tmp158) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp156 })
                                           .Flatten();
        }
        if (catch159__label.is_used()) {
            compiler::CodeAssemblerLabel catch159_skip(&ca_);
            ca_.Goto(&catch159_skip);
            ca_.Bind(&catch159__label, &tmp160);
            ca_.Goto(&block57, phi_bb49_4);
            ca_.Bind(&catch159_skip);
        }
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp157, tmp158 }, tmp153);
        compiler::CodeAssemblerExceptionHandlerLabel catch162__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch162__label);
            tmp161 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetArrayLikeValue_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetArrayLikeValue);
        }
        if (catch162__label.is_used()) {
            compiler::CodeAssemblerLabel catch162_skip(&ca_);
            ca_.Goto(&catch162_skip);
            ca_.Bind(&catch162__label, &tmp163);
            ca_.Goto(&block58, phi_bb49_4);
            ca_.Bind(&catch162_skip);
        }
        ca_.Goto(&block53, tmp161, tmp153, tmp33);
    }

    TNode<Uint32T> phi_bb54_4;
    TNode<Smi> phi_bb54_7;
    TNode<Smi> phi_bb54_10;
    TNode<HeapObject> tmp164;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_4, &phi_bb54_7, &phi_bb54_10);
        tmp164 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp149, tmp164);
    }

    TNode<Uint32T> phi_bb55_4;
    TNode<Smi> phi_bb55_7;
    TNode<Smi> phi_bb55_9;
    TNode<Smi> phi_bb55_10;
    TNode<HeapObject> tmp165;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_4, &phi_bb55_7, &phi_bb55_9, &phi_bb55_10);
        tmp165 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp152, tmp165);
    }

    TNode<Uint32T> phi_bb56_4;
    TNode<Smi> phi_bb56_7;
    TNode<Smi> phi_bb56_9;
    TNode<HeapObject> tmp166;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_4, &phi_bb56_7, &phi_bb56_9);
        tmp166 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp155, tmp166);
    }

    TNode<Uint32T> phi_bb57_4;
    TNode<HeapObject> tmp167;
    if (block57.is_used()) {
        ca_.Bind(&block57, &phi_bb57_4);
        tmp167 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp160, tmp167);
    }

    TNode<Uint32T> phi_bb58_4;
    TNode<HeapObject> tmp168;
    if (block58.is_used()) {
        ca_.Bind(&block58, &phi_bb58_4);
        tmp168 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp163, tmp168);
    }

    TNode<Uint32T> phi_bb50_4;
    TNode<Smi> phi_bb50_7;
    TNode<Object> phi_bb50_8;
    TNode<Uint32T> tmp169;
    TNode<Object> tmp171;
    TNode<BoolT> tmp172;
    TNode<Object> tmp174;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_4, &phi_bb50_7, &phi_bb50_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch170__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch170__label);
            tmp169 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kDoneAndResolvePromise);
        }
        if (catch170__label.is_used()) {
            compiler::CodeAssemblerLabel catch170_skip(&ca_);
            ca_.Goto(&catch170_skip);
            ca_.Bind(&catch170__label, &tmp171);
            ca_.Goto(&block61, phi_bb50_4, phi_bb50_7, phi_bb50_8, phi_bb50_4, phi_bb50_4);
            ca_.Bind(&catch170_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch173__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch173__label);
            tmp172 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb50_4 }, TNode<Uint32T> { tmp169 });
        }
        if (catch173__label.is_used()) {
            compiler::CodeAssemblerLabel catch173_skip(&ca_);
            ca_.Goto(&catch173_skip);
            ca_.Bind(&catch173__label, &tmp174);
            ca_.Goto(&block62, phi_bb50_4, phi_bb50_7, phi_bb50_8, phi_bb50_4);
            ca_.Bind(&catch173_skip);
        }
        ca_.Branch(tmp172, &block59, std::vector<compiler::Node*> { phi_bb50_4, phi_bb50_7, phi_bb50_8 }, &block60,
            std::vector<compiler::Node*> { phi_bb50_4, phi_bb50_7, phi_bb50_8 });
    }

    TNode<Uint32T> phi_bb61_4;
    TNode<Smi> phi_bb61_7;
    TNode<Object> phi_bb61_8;
    TNode<Uint32T> phi_bb61_9;
    TNode<Uint32T> phi_bb61_10;
    TNode<HeapObject> tmp175;
    if (block61.is_used()) {
        ca_.Bind(&block61, &phi_bb61_4, &phi_bb61_7, &phi_bb61_8, &phi_bb61_9, &phi_bb61_10);
        tmp175 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp171, tmp175);
    }

    TNode<Uint32T> phi_bb62_4;
    TNode<Smi> phi_bb62_7;
    TNode<Object> phi_bb62_8;
    TNode<Uint32T> phi_bb62_9;
    TNode<HeapObject> tmp176;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_4, &phi_bb62_7, &phi_bb62_8, &phi_bb62_9);
        tmp176 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp174, tmp176);
    }

    TNode<Uint32T> phi_bb59_4;
    TNode<Smi> phi_bb59_7;
    TNode<Object> phi_bb59_8;
    TNode<Object> tmp178;
    TNode<IntPtrT> tmp179;
    TNode<Object> tmp180;
    TNode<IntPtrT> tmp181;
    TNode<Object> tmp183;
    TNode<JSPromise> tmp184;
    TNode<Object> tmp185;
    TNode<Object> tmp187;
    TNode<Undefined> tmp188;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_4, &phi_bb59_7, &phi_bb59_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch177__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch177__label);
            CodeStubAssembler(state_).SetPropertyLength(TNode<Context> { p_context }, TNode<Object> { tmp17 }, TNode<Number> { phi_bb59_7 });
        }
        if (catch177__label.is_used()) {
            compiler::CodeAssemblerLabel catch177_skip(&ca_);
            ca_.Goto(&catch177_skip);
            ca_.Bind(&catch177__label, &tmp178);
            ca_.Goto(&block64, phi_bb59_4, phi_bb59_7, phi_bb59_8, phi_bb59_7);
            ca_.Bind(&catch177_skip);
        }
        tmp179 = kArrayFromAsyncArrayLikeResolvePromiseSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch182__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch182__label);
            std::tie(tmp180, tmp181) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSPromise_0(
                state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp179 })
                                           .Flatten();
        }
        if (catch182__label.is_used()) {
            compiler::CodeAssemblerLabel catch182_skip(&ca_);
            ca_.Goto(&catch182_skip);
            ca_.Bind(&catch182__label, &tmp183);
            ca_.Goto(&block65, phi_bb59_4, phi_bb59_7, phi_bb59_8);
            ca_.Bind(&catch182_skip);
        }
        tmp184 = CodeStubAssembler(state_).LoadReference<JSPromise>(CodeStubAssembler::Reference { tmp180, tmp181 });
        compiler::CodeAssemblerExceptionHandlerLabel catch186__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch186__label);
            tmp185 = ca_.CallBuiltin<Object>(Builtin::kResolvePromise, p_context, tmp184, tmp17);
        }
        if (catch186__label.is_used()) {
            compiler::CodeAssemblerLabel catch186_skip(&ca_);
            ca_.Goto(&catch186_skip);
            ca_.Bind(&catch186__label, &tmp187);
            ca_.Goto(&block66, phi_bb59_4, phi_bb59_7, phi_bb59_8);
            ca_.Bind(&catch186_skip);
        }
        tmp188 = Undefined_0(state_);
        ca_.Goto(&block1, tmp188);
    }

    TNode<Uint32T> phi_bb64_4;
    TNode<Smi> phi_bb64_7;
    TNode<Object> phi_bb64_8;
    TNode<Smi> phi_bb64_10;
    TNode<HeapObject> tmp189;
    if (block64.is_used()) {
        ca_.Bind(&block64, &phi_bb64_4, &phi_bb64_7, &phi_bb64_8, &phi_bb64_10);
        tmp189 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp178, tmp189);
    }

    TNode<Uint32T> phi_bb65_4;
    TNode<Smi> phi_bb65_7;
    TNode<Object> phi_bb65_8;
    TNode<HeapObject> tmp190;
    if (block65.is_used()) {
        ca_.Bind(&block65, &phi_bb65_4, &phi_bb65_7, &phi_bb65_8);
        tmp190 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp183, tmp190);
    }

    TNode<Uint32T> phi_bb66_4;
    TNode<Smi> phi_bb66_7;
    TNode<Object> phi_bb66_8;
    TNode<HeapObject> tmp191;
    if (block66.is_used()) {
        ca_.Bind(&block66, &phi_bb66_4, &phi_bb66_7, &phi_bb66_8);
        tmp191 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp187, tmp191);
    }

    TNode<Uint32T> phi_bb60_4;
    TNode<Smi> phi_bb60_7;
    TNode<Object> phi_bb60_8;
    TNode<Uint32T> tmp192;
    TNode<Object> tmp194;
    TNode<BoolT> tmp195;
    TNode<Object> tmp197;
    if (block60.is_used()) {
        ca_.Bind(&block60, &phi_bb60_4, &phi_bb60_7, &phi_bb60_8);
        compiler::CodeAssemblerExceptionHandlerLabel catch193__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch193__label);
            tmp192 = FromConstexpr_uint32_constexpr_uint32_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kRejectPromise);
        }
        if (catch193__label.is_used()) {
            compiler::CodeAssemblerLabel catch193_skip(&ca_);
            ca_.Goto(&catch193_skip);
            ca_.Bind(&catch193__label, &tmp194);
            ca_.Goto(&block69, phi_bb60_4, phi_bb60_7, phi_bb60_8, phi_bb60_4, phi_bb60_4);
            ca_.Bind(&catch193_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch196__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch196__label);
            tmp195 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb60_4 }, TNode<Uint32T> { tmp192 });
        }
        if (catch196__label.is_used()) {
            compiler::CodeAssemblerLabel catch196_skip(&ca_);
            ca_.Goto(&catch196_skip);
            ca_.Bind(&catch196__label, &tmp197);
            ca_.Goto(&block70, phi_bb60_4, phi_bb60_7, phi_bb60_8, phi_bb60_4);
            ca_.Bind(&catch196_skip);
        }
        ca_.Branch(tmp195, &block67, std::vector<compiler::Node*> { phi_bb60_4, phi_bb60_7, phi_bb60_8 }, &block68,
            std::vector<compiler::Node*> { phi_bb60_4, phi_bb60_7, phi_bb60_8 });
    }

    TNode<Uint32T> phi_bb69_4;
    TNode<Smi> phi_bb69_7;
    TNode<Object> phi_bb69_8;
    TNode<Uint32T> phi_bb69_9;
    TNode<Uint32T> phi_bb69_10;
    TNode<HeapObject> tmp198;
    if (block69.is_used()) {
        ca_.Bind(&block69, &phi_bb69_4, &phi_bb69_7, &phi_bb69_8, &phi_bb69_9, &phi_bb69_10);
        tmp198 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp194, tmp198);
    }

    TNode<Uint32T> phi_bb70_4;
    TNode<Smi> phi_bb70_7;
    TNode<Object> phi_bb70_8;
    TNode<Uint32T> phi_bb70_9;
    TNode<HeapObject> tmp199;
    if (block70.is_used()) {
        ca_.Bind(&block70, &phi_bb70_4, &phi_bb70_7, &phi_bb70_8, &phi_bb70_9);
        tmp199 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp197, tmp199);
    }

    TNode<Uint32T> phi_bb67_4;
    TNode<Smi> phi_bb67_7;
    TNode<Object> phi_bb67_8;
    TNode<IntPtrT> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<Object> tmp202;
    TNode<Object> tmp204;
    if (block67.is_used()) {
        ca_.Bind(&block67, &phi_bb67_4, &phi_bb67_7, &phi_bb67_8);
        tmp200 = kArrayFromAsyncArrayLikeResolveErrorSlot_0(state_);
        tmp201 = kArrayFromAsyncArrayLikeResolvePromiseSlot_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch203__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch203__label);
            tmp202 = RejectArrayFromAsyncPromise_ArrayFromAsyncArrayLikeResolveContext_0(
                state_, TNode<Context> { p_context }, TNode<Context> { p_context }, TNode<IntPtrT> { tmp200 }, TNode<IntPtrT> { tmp201 });
        }
        if (catch203__label.is_used()) {
            compiler::CodeAssemblerLabel catch203_skip(&ca_);
            ca_.Goto(&catch203_skip);
            ca_.Bind(&catch203__label, &tmp204);
            ca_.Goto(&block71, phi_bb67_4, phi_bb67_7, phi_bb67_8);
            ca_.Bind(&catch203_skip);
        }
        ca_.Goto(&block1, tmp202);
    }

    TNode<Uint32T> phi_bb71_4;
    TNode<Smi> phi_bb71_7;
    TNode<Object> phi_bb71_8;
    TNode<HeapObject> tmp205;
    if (block71.is_used()) {
        ca_.Bind(&block71, &phi_bb71_4, &phi_bb71_7, &phi_bb71_8);
        tmp205 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block3, tmp204, tmp205);
    }

    TNode<Uint32T> phi_bb68_4;
    TNode<Smi> phi_bb68_7;
    TNode<Object> phi_bb68_8;
    if (block68.is_used()) {
        ca_.Bind(&block68, &phi_bb68_4, &phi_bb68_7, &phi_bb68_8);
        ca_.Goto(&block53, phi_bb68_4, phi_bb68_7, phi_bb68_8);
    }

    TNode<Uint32T> phi_bb53_4;
    TNode<Smi> phi_bb53_7;
    TNode<Object> phi_bb53_8;
    if (block53.is_used()) {
        ca_.Bind(&block53, &phi_bb53_4, &phi_bb53_7, &phi_bb53_8);
        ca_.Goto(&block33, phi_bb53_4, phi_bb53_7, phi_bb53_8);
    }

    TNode<Uint32T> phi_bb33_4;
    TNode<Smi> phi_bb33_7;
    TNode<Object> phi_bb33_8;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_4, &phi_bb33_7, &phi_bb33_8);
        ca_.Goto(&block20, phi_bb33_4, phi_bb33_7, phi_bb33_8);
    }

    TNode<Uint32T> phi_bb20_4;
    TNode<Smi> phi_bb20_7;
    TNode<Object> phi_bb20_8;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_4, &phi_bb20_7, &phi_bb20_8);
        ca_.Goto(&block14, phi_bb20_4, phi_bb20_7, phi_bb20_8);
    }

    TNode<Uint32T> phi_bb13_4;
    TNode<Smi> phi_bb13_7;
    TNode<Object> phi_bb13_8;
    TNode<Undefined> tmp206;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_4, &phi_bb13_7, &phi_bb13_8);
        tmp206 = Undefined_0(state_);
        ca_.Goto(&block1, tmp206);
    }

    TNode<Object> phi_bb3_1;
    TNode<HeapObject> phi_bb3_2;
    TNode<IntPtrT> tmp207;
    TNode<Object> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<IntPtrT> tmp211;
    TNode<Object> tmp212;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_1, &phi_bb3_2);
        tmp207 = kArrayFromAsyncArrayLikeResolveErrorSlot_0(state_);
        std::tie(tmp208, tmp209) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_0(
            state_, TNode<Context> { p_context }, TNode<IntPtrT> { tmp207 })
                                       .Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp208, tmp209 }, phi_bb3_1);
        tmp210 = kArrayFromAsyncArrayLikeResolveErrorSlot_0(state_);
        tmp211 = kArrayFromAsyncArrayLikeResolvePromiseSlot_0(state_);
        tmp212 = RejectArrayFromAsyncPromise_ArrayFromAsyncArrayLikeResolveContext_0(
            state_, TNode<Context> { p_context }, TNode<Context> { p_context }, TNode<IntPtrT> { tmp210 }, TNode<IntPtrT> { tmp211 });
        ca_.Goto(&block1, tmp212);
    }

    TNode<Object> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_1);
        ca_.Goto(&block72);
    }

    ca_.Bind(&block72);
    return TNode<Object> { phi_bb1_1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=745&c=1
TNode<Object> ArrayFromAsyncArrayLikeAwaitPoint_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_step, TNode<Object> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Object> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kArrayFromAsyncArrayLikeResolveResumeStateStepSlot_0(state_);
        tmp1 = kArrayFromAsyncArrayLikeResolvePromiseFunctionSlot_0(state_);
        tmp2 = kArrayFromAsyncArrayLikeResolveOnFulfilledFunctionSlot_0(state_);
        tmp3 = kArrayFromAsyncArrayLikeResolveOnRejectedFunctionSlot_0(state_);
        tmp4 = ArrayFromAsyncAwaitPoint_ArrayFromAsyncArrayLikeResolveContext_0(state_, TNode<Context> { p_context }, TNode<Context> { p_context },
            TNode<IntPtrT> { tmp0 }, TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 }, TNode<Uint32T> { p_step },
            TNode<Object> { p_value });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp4 };
}

TF_BUILTIN(ArrayFromAsyncArrayLikeOnFulfilled, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kResult);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Object> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = kArrayFromAsyncArrayLikeResolveResumeStateAwaitedValueSlot_0(state_);
        std::tie(tmp2, tmp3) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_0(
            state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp1 })
                                   .Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp2, tmp3 }, parameter3);
        tmp4 = CreateArrayFromArrayLikeAsynchronously_0(state_, TNode<Context> { tmp0 });
        CodeStubAssembler(state_).Return(tmp4);
    }
}

TF_BUILTIN(ArrayFromAsyncArrayLikeOnRejected, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kResult);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Context> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Uint32T> tmp4;
    TNode<Smi> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Object> tmp9;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Context> { parameter0 });
        tmp1 = kArrayFromAsyncArrayLikeResolveResumeStateStepSlot_0(state_);
        std::tie(tmp2, tmp3) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_0(
            state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp1 })
                                   .Flatten();
        tmp4 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kRejectPromise_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kRejectPromise);
        tmp5 = SmiTag_ArrayFromAsyncLabels_0(state_, TNode<Uint32T> { tmp4 });
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp2, tmp3 }, tmp5);
        tmp6 = kArrayFromAsyncArrayLikeResolveErrorSlot_0(state_);
        std::tie(tmp7, tmp8) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_0(
            state_, TNode<Context> { tmp0 }, TNode<IntPtrT> { tmp6 })
                                   .Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp7, tmp8 }, parameter3);
        tmp9 = CreateArrayFromArrayLikeAsynchronously_0(state_, TNode<Context> { tmp0 });
        CodeStubAssembler(state_).Return(tmp9);
    }
}

TF_BUILTIN(ArrayFromAsync, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSReceiver> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block52(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block60(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block61(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block62(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block63(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSReceiver> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block64(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block65(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block66(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block67(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).HasBuiltinSubclassingFlag();
        ca_.Branch(tmp0, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(&block3, parameter1);
    }

    TNode<JSFunction> tmp1;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp1 = GetArrayFunction_0(state_, TNode<Context> { parameter0 });
        ca_.Goto(&block3, tmp1);
    }

    TNode<Object> phi_bb3_6;
    TNode<IntPtrT> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    TNode<JSPromise> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<JSFunction> tmp12;
    TNode<Undefined> tmp13;
    TNode<Undefined> tmp14;
    TNode<Undefined> tmp15;
    TNode<BoolT> tmp16;
    TNode<Object> tmp18;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_6);
        tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp3 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp5 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp4 });
        tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp7 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp6 });
        tmp8 = NewJSPromise_1(state_, TNode<Context> { parameter0 });
        tmp9 = PROMISE_FUNCTION_INDEX_0(state_);
        std::tie(tmp10, tmp11) = NativeContextSlot_JSFunction_0(state_, TNode<NativeContext> { parameter0 }, TNode<IntPtrT> { tmp9 }).Flatten();
        tmp12 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference { tmp10, tmp11 });
        tmp13 = Undefined_0(state_);
        tmp14 = Undefined_0(state_);
        tmp15 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch17__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch17__label);
            tmp16 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp5 }, TNode<HeapObject> { tmp15 });
        }
        if (catch17__label.is_used()) {
            compiler::CodeAssemblerLabel catch17_skip(&ca_);
            ca_.Goto(&catch17_skip);
            ca_.Bind(&catch17__label, &tmp18);
            ca_.Goto(&block9);
            ca_.Bind(&catch17_skip);
        }
        ca_.Branch(tmp16, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<HeapObject> tmp19;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp19 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp18, tmp19);
    }

    TNode<BoolT> tmp20;
    TNode<Object> tmp22;
    TNode<BoolT> tmp23;
    TNode<Object> tmp25;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerExceptionHandlerLabel catch21__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch21__label);
            tmp20 = Is_Callable_JSAny_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp5 });
        }
        if (catch21__label.is_used()) {
            compiler::CodeAssemblerLabel catch21_skip(&ca_);
            ca_.Goto(&catch21_skip);
            ca_.Bind(&catch21__label, &tmp22);
            ca_.Goto(&block12);
            ca_.Bind(&catch21_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch24__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch24__label);
            tmp23 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp20 });
        }
        if (catch24__label.is_used()) {
            compiler::CodeAssemblerLabel catch24_skip(&ca_);
            ca_.Goto(&catch24_skip);
            ca_.Bind(&catch24__label, &tmp25);
            ca_.Goto(&block13);
            ca_.Bind(&catch24_skip);
        }
        ca_.Branch(tmp23, &block10, std::vector<compiler::Node*> {}, &block11, std::vector<compiler::Node*> {});
    }

    TNode<HeapObject> tmp26;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp26 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp22, tmp26);
    }

    TNode<HeapObject> tmp27;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp27 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp25, tmp27);
    }

    TNode<Object> tmp29;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        compiler::CodeAssemblerExceptionHandlerLabel catch28__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch28__label);
            CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { parameter0 }, MessageTemplate::kCalledNonCallable, TNode<Object> { tmp5 });
        }
        if (catch28__label.is_used()) {
            compiler::CodeAssemblerLabel catch28_skip(&ca_);
            ca_.Bind(&catch28__label, &tmp29);
            ca_.Goto(&block14);
        }
    }

    TNode<HeapObject> tmp30;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp30 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp29, tmp30);
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block8);
    }

    TNode<Symbol> tmp31;
    TNode<Object> tmp33;
    TNode<JSReceiver> tmp34;
    compiler::TypedCodeAssemblerVariable<Object> tmp37(&ca_);
    TNode<Object> tmp39;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        compiler::CodeAssemblerExceptionHandlerLabel catch32__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch32__label);
            tmp31 = CodeStubAssembler(state_).AsyncIteratorSymbolConstant();
        }
        if (catch32__label.is_used()) {
            compiler::CodeAssemblerLabel catch32_skip(&ca_);
            ca_.Goto(&catch32_skip);
            ca_.Bind(&catch32__label, &tmp33);
            ca_.Goto(&block23);
            ca_.Bind(&catch32_skip);
        }
        compiler::CodeAssemblerLabel label35(&ca_);
        compiler::CodeAssemblerLabel label36(&ca_);
        compiler::CodeAssemblerExceptionHandlerLabel catch38__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch38__label);
            tmp34 = GetMethod_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp3 }, TNode<Name> { tmp31 }, &label35, &label36, &tmp37);
        }
        if (catch38__label.is_used()) {
            compiler::CodeAssemblerLabel catch38_skip(&ca_);
            ca_.Goto(&catch38_skip);
            ca_.Bind(&catch38__label, &tmp39);
            ca_.Goto(&block27);
            ca_.Bind(&catch38_skip);
        }
        ca_.Goto(&block24);
        if (label35.is_used()) {
            ca_.Bind(&label35);
            ca_.Goto(&block25);
        }
        if (label36.is_used()) {
            ca_.Bind(&label36);
            ca_.Goto(&block26);
        }
    }

    TNode<HeapObject> tmp40;
    if (block23.is_used()) {
        ca_.Bind(&block23);
        tmp40 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp33, tmp40);
    }

    TNode<HeapObject> tmp41;
    if (block27.is_used()) {
        ca_.Bind(&block27);
        tmp41 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp39, tmp41);
    }

    TNode<Symbol> tmp42;
    TNode<Object> tmp44;
    TNode<JSReceiver> tmp45;
    compiler::TypedCodeAssemblerVariable<Object> tmp48(&ca_);
    TNode<Object> tmp50;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        compiler::CodeAssemblerExceptionHandlerLabel catch43__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch43__label);
            tmp42 = CodeStubAssembler(state_).IteratorSymbolConstant();
        }
        if (catch43__label.is_used()) {
            compiler::CodeAssemblerLabel catch43_skip(&ca_);
            ca_.Goto(&catch43_skip);
            ca_.Bind(&catch43__label, &tmp44);
            ca_.Goto(&block28);
            ca_.Bind(&catch43_skip);
        }
        compiler::CodeAssemblerLabel label46(&ca_);
        compiler::CodeAssemblerLabel label47(&ca_);
        compiler::CodeAssemblerExceptionHandlerLabel catch49__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch49__label);
            tmp45 = GetMethod_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp3 }, TNode<Name> { tmp42 }, &label46, &label47, &tmp48);
        }
        if (catch49__label.is_used()) {
            compiler::CodeAssemblerLabel catch49_skip(&ca_);
            ca_.Goto(&catch49_skip);
            ca_.Bind(&catch49__label, &tmp50);
            ca_.Goto(&block32);
            ca_.Bind(&catch49_skip);
        }
        ca_.Goto(&block29);
        if (label46.is_used()) {
            ca_.Bind(&label46);
            ca_.Goto(&block30);
        }
        if (label47.is_used()) {
            ca_.Bind(&label47);
            ca_.Goto(&block31);
        }
    }

    TNode<Object> tmp52;
    if (block26.is_used()) {
        ca_.Bind(&block26);
        compiler::CodeAssemblerExceptionHandlerLabel catch51__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch51__label);
            CodeStubAssembler(state_).ThrowTypeError(
                TNode<Context> { parameter0 }, MessageTemplate::kFirstArgumentAsyncIteratorSymbolNonCallable, "Array.fromAsync");
        }
        if (catch51__label.is_used()) {
            compiler::CodeAssemblerLabel catch51_skip(&ca_);
            ca_.Bind(&catch51__label, &tmp52);
            ca_.Goto(&block47);
        }
    }

    if (block24.is_used()) {
        ca_.Bind(&block24);
        ca_.Goto(&block21, tmp34, tmp14);
    }

    TNode<HeapObject> tmp53;
    if (block28.is_used()) {
        ca_.Bind(&block28);
        tmp53 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp44, tmp53);
    }

    TNode<HeapObject> tmp54;
    if (block32.is_used()) {
        ca_.Bind(&block32);
        tmp54 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp50, tmp54);
    }

    TNode<JSReceiver> tmp55;
    TNode<Object> tmp57;
    TNode<Number> tmp58;
    TNode<Object> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<Object> tmp64;
    if (block30.is_used()) {
        ca_.Bind(&block30);
        compiler::CodeAssemblerExceptionHandlerLabel catch56__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch56__label);
            tmp55 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context> { parameter0 }, TNode<Object> { tmp3 });
        }
        if (catch56__label.is_used()) {
            compiler::CodeAssemblerLabel catch56_skip(&ca_);
            ca_.Goto(&catch56_skip);
            ca_.Bind(&catch56__label, &tmp57);
            ca_.Goto(&block33);
            ca_.Bind(&catch56_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch59__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch59__label);
            tmp58 = GetLengthProperty_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp55 });
        }
        if (catch59__label.is_used()) {
            compiler::CodeAssemblerLabel catch59_skip(&ca_);
            ca_.Goto(&catch59_skip);
            ca_.Bind(&catch59__label, &tmp60);
            ca_.Goto(&block34);
            ca_.Bind(&catch59_skip);
        }
        compiler::CodeAssemblerLabel label62(&ca_);
        compiler::CodeAssemblerExceptionHandlerLabel catch63__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch63__label);
            tmp61 = Cast_Constructor_1(state_, TNode<Context> { parameter0 }, TNode<Object> { phi_bb3_6 }, &label62);
        }
        if (catch63__label.is_used()) {
            compiler::CodeAssemblerLabel catch63_skip(&ca_);
            ca_.Goto(&catch63_skip);
            ca_.Bind(&catch63__label, &tmp64);
            ca_.Goto(&block39);
            ca_.Bind(&catch63_skip);
        }
        ca_.Goto(&block37);
        if (label62.is_used()) {
            ca_.Bind(&label62);
            ca_.Goto(&block38);
        }
    }

    TNode<Object> tmp66;
    if (block31.is_used()) {
        ca_.Bind(&block31);
        compiler::CodeAssemblerExceptionHandlerLabel catch65__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch65__label);
            CodeStubAssembler(state_).ThrowTypeError(
                TNode<Context> { parameter0 }, MessageTemplate::kFirstArgumentIteratorSymbolNonCallable, "Array.fromAsync");
        }
        if (catch65__label.is_used()) {
            compiler::CodeAssemblerLabel catch65_skip(&ca_);
            ca_.Bind(&catch65__label, &tmp66);
            ca_.Goto(&block46);
        }
    }

    if (block29.is_used()) {
        ca_.Bind(&block29);
        ca_.Goto(&block21, tmp13, tmp45);
    }

    TNode<Object> phi_bb21_12;
    TNode<Object> phi_bb21_13;
    TNode<Undefined> tmp67;
    TNode<BoolT> tmp68;
    TNode<Object> tmp70;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_12, &phi_bb21_13);
        tmp67 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch69__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch69__label);
            tmp68 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { phi_bb21_12 }, TNode<HeapObject> { tmp67 });
        }
        if (catch69__label.is_used()) {
            compiler::CodeAssemblerLabel catch69_skip(&ca_);
            ca_.Goto(&catch69_skip);
            ca_.Bind(&catch69__label, &tmp70);
            ca_.Goto(&block52);
            ca_.Bind(&catch69_skip);
        }
        ca_.Branch(tmp68, &block48, std::vector<compiler::Node*> {}, &block49, std::vector<compiler::Node*> {});
    }

    TNode<HeapObject> tmp71;
    if (block33.is_used()) {
        ca_.Bind(&block33);
        tmp71 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp57, tmp71);
    }

    TNode<HeapObject> tmp72;
    if (block34.is_used()) {
        ca_.Bind(&block34);
        tmp72 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp60, tmp72);
    }

    TNode<HeapObject> tmp73;
    if (block39.is_used()) {
        ca_.Bind(&block39);
        tmp73 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp64, tmp73);
    }

    TNode<JSArray> tmp74;
    TNode<Object> tmp76;
    if (block38.is_used()) {
        ca_.Bind(&block38);
        compiler::CodeAssemblerExceptionHandlerLabel catch75__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch75__label);
            tmp74 = CodeStubAssembler(state_).ArrayCreate(TNode<Context> { parameter0 }, TNode<Number> { tmp58 });
        }
        if (catch75__label.is_used()) {
            compiler::CodeAssemblerLabel catch75_skip(&ca_);
            ca_.Goto(&catch75_skip);
            ca_.Bind(&catch75__label, &tmp76);
            ca_.Goto(&block41);
            ca_.Bind(&catch75_skip);
        }
        ca_.Goto(&block35, tmp74);
    }

    TNode<JSReceiver> tmp77;
    TNode<Object> tmp79;
    if (block37.is_used()) {
        ca_.Bind(&block37);
        compiler::CodeAssemblerExceptionHandlerLabel catch78__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch78__label);
            tmp77 = CodeStubAssembler(state_).Construct(TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp61 }, TNode<Object> { tmp58 });
        }
        if (catch78__label.is_used()) {
            compiler::CodeAssemblerLabel catch78_skip(&ca_);
            ca_.Goto(&catch78_skip);
            ca_.Bind(&catch78__label, &tmp79);
            ca_.Goto(&block40);
            ca_.Bind(&catch78_skip);
        }
        ca_.Goto(&block35, tmp77);
    }

    TNode<HeapObject> tmp80;
    if (block40.is_used()) {
        ca_.Bind(&block40);
        tmp80 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp79, tmp80);
    }

    TNode<HeapObject> tmp81;
    if (block41.is_used()) {
        ca_.Bind(&block41);
        tmp81 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp76, tmp81);
    }

    TNode<JSReceiver> phi_bb35_16;
    TNode<Undefined> tmp82;
    TNode<Uint32T> tmp83;
    TNode<Object> tmp85;
    TNode<Smi> tmp86;
    TNode<Object> tmp88;
    TNode<Undefined> tmp89;
    TNode<Context> tmp90;
    TNode<Object> tmp92;
    TNode<Object> tmp93;
    TNode<Object> tmp95;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_16);
        tmp82 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch84__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch84__label);
            tmp83 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetArrayLikeValue_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetArrayLikeValue);
        }
        if (catch84__label.is_used()) {
            compiler::CodeAssemblerLabel catch84_skip(&ca_);
            ca_.Goto(&catch84_skip);
            ca_.Bind(&catch84__label, &tmp85);
            ca_.Goto(&block42);
            ca_.Bind(&catch84_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch87__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch87__label);
            tmp86 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        }
        if (catch87__label.is_used()) {
            compiler::CodeAssemblerLabel catch87_skip(&ca_);
            ca_.Goto(&catch87_skip);
            ca_.Bind(&catch87__label, &tmp88);
            ca_.Goto(&block43);
            ca_.Bind(&catch87_skip);
        }
        tmp89 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch91__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch91__label);
            tmp90 = CreateArrayFromAsyncArrayLikeResolveContext_0(state_, TNode<Context> { parameter0 },
                TorqueStructArrayFromAsyncArrayLikeResumeState_0 {
                    TNode<Uint32T> { tmp83 }, TNode<Object> { tmp82 }, TNode<Number> { tmp58 }, TNode<Smi> { tmp86 } },
                TNode<JSPromise> { tmp8 }, TNode<JSReceiver> { tmp12 }, TNode<JSReceiver> { tmp55 }, TNode<JSReceiver> { phi_bb35_16 }, TNode<Object> { tmp89 },
                TNode<Object> { tmp5 }, TNode<Object> { tmp7 }, TNode<NativeContext> { parameter0 });
        }
        if (catch91__label.is_used()) {
            compiler::CodeAssemblerLabel catch91_skip(&ca_);
            ca_.Goto(&catch91_skip);
            ca_.Bind(&catch91__label, &tmp92);
            ca_.Goto(&block44);
            ca_.Bind(&catch91_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch94__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch94__label);
            tmp93 = CreateArrayFromArrayLikeAsynchronously_0(state_, TNode<Context> { tmp90 });
        }
        if (catch94__label.is_used()) {
            compiler::CodeAssemblerLabel catch94_skip(&ca_);
            ca_.Goto(&catch94_skip);
            ca_.Bind(&catch94__label, &tmp95);
            ca_.Goto(&block45);
            ca_.Bind(&catch94_skip);
        }
        arguments.PopAndReturn(tmp8);
    }

    TNode<HeapObject> tmp96;
    if (block42.is_used()) {
        ca_.Bind(&block42);
        tmp96 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp85, tmp96);
    }

    TNode<HeapObject> tmp97;
    if (block43.is_used()) {
        ca_.Bind(&block43);
        tmp97 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp88, tmp97);
    }

    TNode<HeapObject> tmp98;
    if (block44.is_used()) {
        ca_.Bind(&block44);
        tmp98 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp92, tmp98);
    }

    TNode<HeapObject> tmp99;
    if (block45.is_used()) {
        ca_.Bind(&block45);
        tmp99 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp95, tmp99);
    }

    TNode<HeapObject> tmp100;
    if (block46.is_used()) {
        ca_.Bind(&block46);
        tmp100 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp66, tmp100);
    }

    TNode<HeapObject> tmp101;
    if (block47.is_used()) {
        ca_.Bind(&block47);
        tmp101 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, tmp13, tmp14, tmp52, tmp101);
    }

    TNode<HeapObject> tmp102;
    if (block52.is_used()) {
        ca_.Bind(&block52);
        tmp102 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp70, tmp102);
    }

    TNode<JSReceiver> tmp103;
    TNode<Object> tmp104;
    TNode<Object> tmp106;
    if (block48.is_used()) {
        ca_.Bind(&block48);
        compiler::CodeAssemblerExceptionHandlerLabel catch105__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch105__label);
            std::tie(tmp103, tmp104)
                = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context> { parameter0 }, TNode<Object> { tmp3 }, TNode<Object> { phi_bb21_12 }).Flatten();
        }
        if (catch105__label.is_used()) {
            compiler::CodeAssemblerLabel catch105_skip(&ca_);
            ca_.Goto(&catch105_skip);
            ca_.Bind(&catch105__label, &tmp106);
            ca_.Goto(&block53);
            ca_.Bind(&catch105_skip);
        }
        ca_.Goto(&block50, tmp103, tmp104);
    }

    TNode<HeapObject> tmp107;
    if (block53.is_used()) {
        ca_.Bind(&block53);
        tmp107 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp106, tmp107);
    }

    TNode<JSReceiver> tmp108;
    TNode<Object> tmp109;
    TNode<Object> tmp111;
    TNode<JSReceiver> tmp112;
    TNode<Object> tmp113;
    TNode<Object> tmp115;
    if (block49.is_used()) {
        ca_.Bind(&block49);
        compiler::CodeAssemblerExceptionHandlerLabel catch110__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch110__label);
            std::tie(tmp108, tmp109)
                = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context> { parameter0 }, TNode<Object> { tmp3 }, TNode<Object> { phi_bb21_13 }).Flatten();
        }
        if (catch110__label.is_used()) {
            compiler::CodeAssemblerLabel catch110_skip(&ca_);
            ca_.Goto(&catch110_skip);
            ca_.Bind(&catch110__label, &tmp111);
            ca_.Goto(&block54);
            ca_.Bind(&catch110_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch114__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch114__label);
            std::tie(tmp112, tmp113) = GetIteratorRecordAfterCreateAsyncFromSyncIterator_0(state_, TNode<Context> { parameter0 },
                TorqueStructIteratorRecord { TNode<JSReceiver> { tmp108 },
                    TNode<Object> {
                        tmp109 } }).Flatten();
        }
        if (catch114__label.is_used()) {
            compiler::CodeAssemblerLabel catch114_skip(&ca_);
            ca_.Goto(&catch114_skip);
            ca_.Bind(&catch114__label, &tmp115);
            ca_.Goto(&block55);
            ca_.Bind(&catch114_skip);
        }
        ca_.Goto(&block50, tmp112, tmp113);
    }

    TNode<HeapObject> tmp116;
    if (block54.is_used()) {
        ca_.Bind(&block54);
        tmp116 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp111, tmp116);
    }

    TNode<HeapObject> tmp117;
    if (block55.is_used()) {
        ca_.Bind(&block55);
        tmp117 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp115, tmp117);
    }

    TNode<JSReceiver> phi_bb50_14;
    TNode<Object> phi_bb50_15;
    TNode<JSReceiver> tmp118;
    TNode<Object> tmp121;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_14, &phi_bb50_15);
        compiler::CodeAssemblerLabel label119(&ca_);
        compiler::CodeAssemblerExceptionHandlerLabel catch120__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch120__label);
            tmp118 = Cast_Constructor_1(state_, TNode<Context> { parameter0 }, TNode<Object> { phi_bb3_6 }, &label119);
        }
        if (catch120__label.is_used()) {
            compiler::CodeAssemblerLabel catch120_skip(&ca_);
            ca_.Goto(&catch120_skip);
            ca_.Bind(&catch120__label, &tmp121);
            ca_.Goto(&block60);
            ca_.Bind(&catch120_skip);
        }
        ca_.Goto(&block58);
        if (label119.is_used()) {
            ca_.Bind(&label119);
            ca_.Goto(&block59);
        }
    }

    TNode<HeapObject> tmp122;
    if (block60.is_used()) {
        ca_.Bind(&block60);
        tmp122 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp121, tmp122);
    }

    TNode<Number> tmp123;
    TNode<Object> tmp125;
    TNode<JSArray> tmp126;
    TNode<Object> tmp128;
    if (block59.is_used()) {
        ca_.Bind(&block59);
        compiler::CodeAssemblerExceptionHandlerLabel catch124__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch124__label);
            tmp123 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        }
        if (catch124__label.is_used()) {
            compiler::CodeAssemblerLabel catch124_skip(&ca_);
            ca_.Goto(&catch124_skip);
            ca_.Bind(&catch124__label, &tmp125);
            ca_.Goto(&block62);
            ca_.Bind(&catch124_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch127__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch127__label);
            tmp126 = CodeStubAssembler(state_).ArrayCreate(TNode<Context> { parameter0 }, TNode<Number> { tmp123 });
        }
        if (catch127__label.is_used()) {
            compiler::CodeAssemblerLabel catch127_skip(&ca_);
            ca_.Goto(&catch127_skip);
            ca_.Bind(&catch127__label, &tmp128);
            ca_.Goto(&block63);
            ca_.Bind(&catch127_skip);
        }
        ca_.Goto(&block56, tmp126);
    }

    TNode<JSReceiver> tmp129;
    TNode<Object> tmp131;
    if (block58.is_used()) {
        ca_.Bind(&block58);
        compiler::CodeAssemblerExceptionHandlerLabel catch130__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch130__label);
            tmp129 = CodeStubAssembler(state_).Construct(TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp118 });
        }
        if (catch130__label.is_used()) {
            compiler::CodeAssemblerLabel catch130_skip(&ca_);
            ca_.Goto(&catch130_skip);
            ca_.Bind(&catch130__label, &tmp131);
            ca_.Goto(&block61);
            ca_.Bind(&catch130_skip);
        }
        ca_.Goto(&block56, tmp129);
    }

    TNode<HeapObject> tmp132;
    if (block61.is_used()) {
        ca_.Bind(&block61);
        tmp132 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp131, tmp132);
    }

    TNode<HeapObject> tmp133;
    if (block62.is_used()) {
        ca_.Bind(&block62);
        tmp133 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp125, tmp133);
    }

    TNode<HeapObject> tmp134;
    if (block63.is_used()) {
        ca_.Bind(&block63);
        tmp134 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp128, tmp134);
    }

    TNode<JSReceiver> phi_bb56_16;
    TNode<Undefined> tmp135;
    TNode<Uint32T> tmp136;
    TNode<Object> tmp138;
    TNode<Smi> tmp139;
    TNode<Object> tmp141;
    TNode<Undefined> tmp142;
    TNode<Context> tmp143;
    TNode<Object> tmp145;
    TNode<Object> tmp146;
    TNode<Object> tmp148;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_16);
        tmp135 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch137__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch137__label);
            tmp136 = FromConstexpr_ArrayFromAsyncLabels_constexpr_kGetIteratorStep_0(state_, ArrayBuiltins::ArrayFromAsyncLabels::kGetIteratorStep);
        }
        if (catch137__label.is_used()) {
            compiler::CodeAssemblerLabel catch137_skip(&ca_);
            ca_.Goto(&catch137_skip);
            ca_.Bind(&catch137__label, &tmp138);
            ca_.Goto(&block64);
            ca_.Bind(&catch137_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch140__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch140__label);
            tmp139 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        }
        if (catch140__label.is_used()) {
            compiler::CodeAssemblerLabel catch140_skip(&ca_);
            ca_.Goto(&catch140_skip);
            ca_.Bind(&catch140__label, &tmp141);
            ca_.Goto(&block65);
            ca_.Bind(&catch140_skip);
        }
        tmp142 = Undefined_0(state_);
        compiler::CodeAssemblerExceptionHandlerLabel catch144__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch144__label);
            tmp143 = CreateArrayFromAsyncIterableResolveContext_0(state_, TNode<Context> { parameter0 },
                TorqueStructArrayFromAsyncIterableResumeState_0 { TNode<Uint32T> { tmp136 }, TNode<Object> { tmp135 }, TNode<Smi> { tmp139 } },
                TNode<JSPromise> { tmp8 }, TNode<JSReceiver> { tmp12 }, TNode<JSReceiver> { phi_bb50_14 }, TNode<Object> { phi_bb50_15 },
                TNode<JSReceiver> { phi_bb56_16 }, TNode<Object> { tmp142 }, TNode<Object> { tmp5 }, TNode<Object> { tmp7 },
                TNode<NativeContext> { parameter0 });
        }
        if (catch144__label.is_used()) {
            compiler::CodeAssemblerLabel catch144_skip(&ca_);
            ca_.Goto(&catch144_skip);
            ca_.Bind(&catch144__label, &tmp145);
            ca_.Goto(&block66);
            ca_.Bind(&catch144_skip);
        }
        compiler::CodeAssemblerExceptionHandlerLabel catch147__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
        {
            compiler::ScopedExceptionHandler s(&ca_, &catch147__label);
            tmp146 = CreateArrayFromIterableAsynchronously_0(state_, TNode<Context> { tmp143 });
        }
        if (catch147__label.is_used()) {
            compiler::CodeAssemblerLabel catch147_skip(&ca_);
            ca_.Goto(&catch147_skip);
            ca_.Bind(&catch147__label, &tmp148);
            ca_.Goto(&block67);
            ca_.Bind(&catch147_skip);
        }
        arguments.PopAndReturn(tmp8);
    }

    TNode<HeapObject> tmp149;
    if (block64.is_used()) {
        ca_.Bind(&block64);
        tmp149 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp138, tmp149);
    }

    TNode<HeapObject> tmp150;
    if (block65.is_used()) {
        ca_.Bind(&block65);
        tmp150 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp141, tmp150);
    }

    TNode<HeapObject> tmp151;
    if (block66.is_used()) {
        ca_.Bind(&block66);
        tmp151 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp145, tmp151);
    }

    TNode<HeapObject> tmp152;
    if (block67.is_used()) {
        ca_.Bind(&block67);
        tmp152 = GetAndResetPendingMessage_0(state_);
        ca_.Goto(&block6, phi_bb21_12, phi_bb21_13, tmp148, tmp152);
    }

    TNode<Object> phi_bb6_12;
    TNode<Object> phi_bb6_13;
    TNode<Object> phi_bb6_14;
    TNode<HeapObject> phi_bb6_15;
    TNode<False> tmp153;
    TNode<Object> tmp154;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_12, &phi_bb6_13, &phi_bb6_14, &phi_bb6_15);
        tmp153 = False_0(state_);
        tmp154 = ca_.CallBuiltin<Object>(Builtin::kRejectPromise, parameter0, tmp8, phi_bb6_14, tmp153);
        arguments.PopAndReturn(tmp8);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=116&c=7
TNode<Smi> SmiTag_ArrayFromAsyncLabels_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { p_value });
        tmp1 = (TNode<Smi> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=112&c=3
void InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_SmiTagged_ArrayFromAsyncLabels_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<Smi> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=117&c=3
void InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_JSAny_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<Object> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=122&c=3
void InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_Smi_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<Smi> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=127&c=3
void InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSPromise_JSPromise_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<JSPromise> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=132&c=3
void InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSReceiver_JSReceiver_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<JSReceiver> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=137&c=3
void InitContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Undefined_OR_JSFunction_JSFunction_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<JSFunction> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=186&c=21
TorqueStructReference_JSReceiver_0 ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSReceiver_0(
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
        std::tie(tmp10, tmp11) = ReferenceCast_JSReceiver_Object_0(
            state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_JSReceiver_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=191&c=23
TorqueStructReference_JSAny_0 ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
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
            = ReferenceCast_JSAny_Object_0(state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                  .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_JSAny_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=221&c=58
TorqueStructReference_Smi_0 ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_0(
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=220&c=13
TNode<Uint32T> SmiUntag_ArrayFromAsyncLabels_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    TNode<Int32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<Uint32T> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_Smi_SmiTagged_ArrayFromAsyncLabels_0(state_, TNode<Smi> { p_value });
        tmp1 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp1 });
        tmp3 = (TNode<Uint32T> { tmp2 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=297&c=22
TNode<JSReceiver> UnsafeCast_Callable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=332&c=26
TorqueStructReference_JSPromise_0 ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSPromise_0(
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=353&c=16
TNode<Object> RejectArrayFromAsyncPromise_ArrayFromAsyncIterableResolveContext_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_resolveContext, TNode<IntPtrT> p_errorSlot, TNode<IntPtrT> p_promiseSlot)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<JSPromise> tmp5;
    TNode<False> tmp6;
    TNode<Object> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSAny_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_errorSlot })
                                   .Flatten();
        tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp0, tmp1 });
        std::tie(tmp3, tmp4) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSPromise_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_promiseSlot })
                                   .Flatten();
        tmp5 = CodeStubAssembler(state_).LoadReference<JSPromise>(CodeStubAssembler::Reference { tmp3, tmp4 });
        tmp6 = False_0(state_);
        tmp7 = ca_.CallBuiltin<Object>(Builtin::kRejectPromise, p_context, tmp5, tmp2, tmp6);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp7 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=388&c=10
TNode<Object> ArrayFromAsyncAwaitPoint_ArrayFromAsyncIterableResolveContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TNode<Context> p_resolveContext, TNode<IntPtrT> p_stepSlot, TNode<IntPtrT> p_promiseFunSlot, TNode<IntPtrT> p_resolveSlot, TNode<IntPtrT> p_rejectSlot,
    TNode<Uint32T> p_step, TNode<Object> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Smi> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<JSReceiver> tmp5;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<HeapObject> tmp8;
    TNode<Object> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<HeapObject> tmp11;
    TNode<Object> tmp12;
    TNode<JSPromise> tmp13;
    TNode<Undefined> tmp14;
    TNode<Undefined> tmp15;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Smi_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_stepSlot })
                                   .Flatten();
        tmp2 = SmiTag_ArrayFromAsyncLabels_0(state_, TNode<Uint32T> { p_step });
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp0, tmp1 }, tmp2);
        std::tie(tmp3, tmp4) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_JSReceiver_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_promiseFunSlot })
                                   .Flatten();
        tmp5 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference { tmp3, tmp4 });
        std::tie(tmp6, tmp7) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Undefined_OR_JSFunction_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_resolveSlot })
                                   .Flatten();
        tmp8 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp6, tmp7 });
        std::tie(tmp9, tmp10) = ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Undefined_OR_JSFunction_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_rejectSlot })
                                    .Flatten();
        tmp11 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp9, tmp10 });
        tmp12 = ca_.CallBuiltin<Object>(Builtin::kPromiseResolve, p_context, tmp5, p_value);
        tmp13 = UnsafeCast_JSPromise_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp12 });
        tmp14 = Undefined_0(state_);
        PerformPromiseThenImpl_0(state_, TNode<Context> { p_context }, TNode<JSPromise> { tmp13 }, TNode<HeapObject> { tmp8 }, TNode<HeapObject> { tmp11 },
            TNode<HeapObject> { tmp14 });
        tmp15 = Undefined_0(state_);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp15 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=529&c=3
void InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_SmiTagged_ArrayFromAsyncLabels_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<Smi> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=534&c=3
void InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_JSAny_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<Object> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=539&c=3
void InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Number_Number_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<Number> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=544&c=3
void InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_Smi_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<Smi> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=549&c=3
void InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSPromise_JSPromise_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<JSPromise> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=554&c=3
void InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSReceiver_JSReceiver_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<JSReceiver> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=559&c=3
void InitContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Undefined_OR_JSFunction_JSFunction_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<JSFunction> p_value)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=604&c=20
TorqueStructReference_JSAny_0 ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_0(
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
            = ReferenceCast_JSAny_Object_0(state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                  .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_JSAny_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=614&c=18
TorqueStructReference_JSReceiver_0 ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSReceiver_0(
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
        std::tie(tmp10, tmp11) = ReferenceCast_JSReceiver_Object_0(
            state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_JSReceiver_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=621&c=58
TorqueStructReference_Smi_0 ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_0(
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=629&c=13
TorqueStructReference_Number_0 ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Number_0(
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
            = ReferenceCast_Number_Object_0(state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                  .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_Number_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=712&c=26
TorqueStructReference_JSPromise_0 ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSPromise_0(
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=720&c=16
TNode<Object> RejectArrayFromAsyncPromise_ArrayFromAsyncArrayLikeResolveContext_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_resolveContext, TNode<IntPtrT> p_errorSlot, TNode<IntPtrT> p_promiseSlot)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<JSPromise> tmp5;
    TNode<False> tmp6;
    TNode<Object> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSAny_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_errorSlot })
                                   .Flatten();
        tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp0, tmp1 });
        std::tie(tmp3, tmp4) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSPromise_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_promiseSlot })
                                   .Flatten();
        tmp5 = CodeStubAssembler(state_).LoadReference<JSPromise>(CodeStubAssembler::Reference { tmp3, tmp4 });
        tmp6 = False_0(state_);
        tmp7 = ca_.CallBuiltin<Object>(Builtin::kRejectPromise, p_context, tmp5, tmp2, tmp6);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp7 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=748&c=10
TNode<Object> ArrayFromAsyncAwaitPoint_ArrayFromAsyncArrayLikeResolveContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TNode<Context> p_resolveContext, TNode<IntPtrT> p_stepSlot, TNode<IntPtrT> p_promiseFunSlot, TNode<IntPtrT> p_resolveSlot, TNode<IntPtrT> p_rejectSlot,
    TNode<Uint32T> p_step, TNode<Object> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Smi> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<JSReceiver> tmp5;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<HeapObject> tmp8;
    TNode<Object> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<HeapObject> tmp11;
    TNode<Object> tmp12;
    TNode<JSPromise> tmp13;
    TNode<Undefined> tmp14;
    TNode<Undefined> tmp15;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Smi_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_stepSlot })
                                   .Flatten();
        tmp2 = SmiTag_ArrayFromAsyncLabels_0(state_, TNode<Uint32T> { p_step });
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp0, tmp1 }, tmp2);
        std::tie(tmp3, tmp4) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_JSReceiver_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_promiseFunSlot })
                                   .Flatten();
        tmp5 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference { tmp3, tmp4 });
        std::tie(tmp6, tmp7) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Undefined_OR_JSFunction_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_resolveSlot })
                                   .Flatten();
        tmp8 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp6, tmp7 });
        std::tie(tmp9, tmp10) = ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Undefined_OR_JSFunction_0(
            state_, TNode<Context> { p_resolveContext }, TNode<IntPtrT> { p_rejectSlot })
                                    .Flatten();
        tmp11 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp9, tmp10 });
        tmp12 = ca_.CallBuiltin<Object>(Builtin::kPromiseResolve, p_context, tmp5, p_value);
        tmp13 = UnsafeCast_JSPromise_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp12 });
        tmp14 = Undefined_0(state_);
        PerformPromiseThenImpl_0(state_, TNode<Context> { p_context }, TNode<JSPromise> { tmp13 }, TNode<HeapObject> { tmp8 }, TNode<HeapObject> { tmp11 },
            TNode<HeapObject> { tmp14 });
        tmp15 = Undefined_0(state_);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp15 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=819&c=23
TorqueStructReference_JSFunction_0 NativeContextSlot_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index)
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
        std::tie(tmp0, tmp1)
            = ContextSlot_NativeContext_NativeContext_JSFunction_0(state_, TNode<NativeContext> { p_context }, TNode<IntPtrT> { p_index }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_JSFunction_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp1 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=832&c=12
TNode<BoolT> Is_Callable_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_Callable_1(state_, TNode<Context> { p_context }, TNode<Object> { p_o }, &label1);
        ca_.Goto(&block4);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block5);
        }
    }

    TNode<BoolT> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block1, tmp2);
    }

    TNode<BoolT> tmp3;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block1, tmp3);
    }

    TNode<BoolT> phi_bb1_2;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_2);
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<BoolT> { phi_bb1_2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=865&c=9
TNode<JSReceiver> Cast_Constructor_1(
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

    TNode<JSReceiver> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_Constructor_0(state_, TNode<HeapObject> { tmp0 }, &label3);
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
    return TNode<JSReceiver> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=32&c=20
TorqueStructReference_Undefined_OR_JSFunction_0 ContextSlot_ArrayFromAsyncIterableResolveContext_ArrayFromAsyncIterableResolveContext_Undefined_OR_JSFunction_0(
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
        std::tie(tmp10, tmp11) = ReferenceCast_Undefined_OR_JSFunction_Object_0(
            state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_Undefined_OR_JSFunction_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-from-async.tq?l=32&c=20
TorqueStructReference_Undefined_OR_JSFunction_0
ContextSlot_ArrayFromAsyncArrayLikeResolveContext_ArrayFromAsyncArrayLikeResolveContext_Undefined_OR_JSFunction_0(
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
        std::tie(tmp10, tmp11) = ReferenceCast_Undefined_OR_JSFunction_Object_0(
            state_, TorqueStructReference_Object_0 { TNode<Object> { tmp8 }, TNode<IntPtrT> { tmp9 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TorqueStructReference_Undefined_OR_JSFunction_0 { TNode<Object> { tmp10 }, TNode<IntPtrT> { tmp11 }, TorqueStructUnsafe_0 {} };
}

} // namespace internal
} // namespace v8
