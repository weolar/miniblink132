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
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-bigint-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kAdd_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kSubtract_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kMultiply_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kDivide_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kModulus_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kExponentiate_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kBitwiseAnd_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kBitwiseOr_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kBitwiseXor_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kShiftLeft_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kShiftRight_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kShiftRightLogical_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kBitwiseNot_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kNegate_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kIncrement_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kDecrement_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kEqual_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kStrictEqual_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kLessThan_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kLessThanOrEqual_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kGreaterThan_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=7&c=1
TNode<Uint32T> FromConstexpr_Operation_constexpr_kGreaterThanOrEqual_0(compiler::CodeAssemblerState* state_, Operation p_o)
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=55&c=1
TNode<Number> ThisNumberValue_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, const char* p_method)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<Number> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToThisValue(TNode<Context> { p_context }, TNode<Object> { p_receiver }, PrimitiveType::kNumber, p_method);
        tmp1 = UnsafeCast_Number_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=62&c=1
TNode<Uint8T> ToCharCode_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_input)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint8T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp1 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { p_input }, TNode<Uint32T> { tmp0 });
        ca_.Branch(tmp1, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Uint8T> tmp4;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x30ull));
        tmp3 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { p_input }, TNode<Uint32T> { tmp2 });
        tmp4 = ca_.UncheckedCast<Uint8T>(TNode<Uint32T> { tmp3 });
        ca_.Goto(&block8, tmp4);
    }

    TNode<Uint32T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<Uint32T> tmp7;
    TNode<Uint32T> tmp8;
    TNode<Uint8T> tmp9;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp5 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp6 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { p_input }, TNode<Uint32T> { tmp5 });
        tmp7 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x61ull));
        tmp8 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp6 }, TNode<Uint32T> { tmp7 });
        tmp9 = ca_.UncheckedCast<Uint8T>(TNode<Uint32T> { tmp8 });
        ca_.Goto(&block8, tmp9);
    }

    TNode<Uint8T> phi_bb8_1;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_1);
        ca_.Goto(&block10);
    }

    ca_.Bind(&block10);
    return TNode<Uint8T> { phi_bb8_1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=69&c=1
TNode<String> IntToDecimalStringImpl_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_x, TNode<RawPtrT> p_log10OffsetsTable, bool p_isPositive)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, p_isPositive);
        ca_.Branch(tmp0, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp1;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { p_x });
        ca_.Goto(&block8, tmp1);
    }

    TNode<Int32T> tmp2;
    TNode<Int32T> tmp3;
    TNode<Uint32T> tmp4;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp2 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp3 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp2 }, TNode<Int32T> { p_x });
        tmp4 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp3 });
        ca_.Goto(&block8, tmp4);
    }

    TNode<Uint32T> phi_bb8_2;
    TNode<Int32T> tmp5;
    TNode<Int32T> tmp6;
    TNode<Int32T> tmp7;
    TNode<Int32T> tmp8;
    TNode<Int32T> tmp9;
    TNode<Int32T> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<Uint64T> tmp12;
    TNode<Uint64T> tmp13;
    TNode<Uint64T> tmp14;
    TNode<Uint64T> tmp15;
    TNode<Uint64T> tmp16;
    TNode<Uint32T> tmp17;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_2);
        tmp5 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { phi_bb8_2 });
        tmp6 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp7 = CodeStubAssembler(state_).Word32Or(TNode<Int32T> { tmp5 }, TNode<Int32T> { tmp6 });
        tmp8 = CodeStubAssembler(state_).Word32Clz(TNode<Int32T> { tmp7 });
        tmp9 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1full));
        tmp10 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp9 }, TNode<Int32T> { tmp8 });
        tmp11 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp10 });
        tmp12 = CodeStubAssembler(state_).LoadUint64Ptr(TNode<RawPtrT> { p_log10OffsetsTable }, TNode<IntPtrT> { tmp11 });
        tmp13 = Convert_uint64_uint32_0(state_, TNode<Uint32T> { phi_bb8_2 });
        tmp14 = CodeStubAssembler(state_).Uint64Add(TNode<Uint64T> { tmp13 }, TNode<Uint64T> { tmp12 });
        tmp15 = FromConstexpr_uint64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
        tmp16 = CodeStubAssembler(state_).Word64Shr(TNode<Uint64T> { tmp14 }, TNode<Uint64T> { tmp15 });
        tmp17 = Convert_uint32_uint64_0(state_, TNode<Uint64T> { tmp16 });
        if (((CodeStubAssembler(state_).ConstexprBoolNot(p_isPositive)))) {
            ca_.Goto(&block10);
        } else {
            ca_.Goto(&block11);
        }
    }

    TNode<Uint32T> tmp18;
    TNode<Uint32T> tmp19;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp18 = FromConstexpr_uint32_constexpr_int31_0(state_, 1);
        tmp19 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Goto(&block12, tmp19);
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block12, tmp17);
    }

    TNode<Uint32T> phi_bb12_6;
    TNode<SeqOneByteString> tmp20;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_6);
        tmp20 = AllocateNonEmptySeqOneByteString_0(state_, TNode<Uint32T> { phi_bb12_6 });
        if ((p_isPositive)) {
            ca_.Goto(&block13);
        } else {
            ca_.Goto(&block14);
        }
    }

    TNode<IntPtrT> tmp21;
    TNode<Uint32T> tmp22;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp22 = MakeArrayIndexHash_0(state_, TNode<Uint32T> { phi_bb8_2 }, TNode<Uint32T> { phi_bb12_6 });
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { tmp20, tmp21 }, tmp22);
        ca_.Goto(&block15);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block15);
    }

    TNode<Int32T> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<Object> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp23 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { phi_bb12_6 });
        tmp24 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp23 });
        tmp25 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp26 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { tmp24 }, TNode<IntPtrT> { tmp25 });
        std::tie(tmp27, tmp28, tmp29) = FieldSliceSeqOneByteStringChars_0(state_, TNode<SeqOneByteString> { tmp20 }).Flatten();
        ca_.Goto(&block18, phi_bb8_2, tmp26);
    }

    TNode<Uint32T> phi_bb18_2;
    TNode<IntPtrT> phi_bb18_9;
    TNode<BoolT> tmp30;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_2, &phi_bb18_9);
        tmp30 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp30, &block16, std::vector<compiler::Node*> { phi_bb18_2, phi_bb18_9 }, &block17, std::vector<compiler::Node*> { phi_bb18_2, phi_bb18_9 });
    }

    TNode<Uint32T> phi_bb16_2;
    TNode<IntPtrT> phi_bb16_9;
    TNode<Uint64T> tmp31;
    TNode<Uint64T> tmp32;
    TNode<Uint64T> tmp33;
    TNode<Uint64T> tmp34;
    TNode<Uint64T> tmp35;
    TNode<Uint32T> tmp36;
    TNode<Uint32T> tmp37;
    TNode<Uint32T> tmp38;
    TNode<Uint32T> tmp39;
    TNode<Uint32T> tmp40;
    TNode<Uint32T> tmp41;
    TNode<Uint8T> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<Object> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<Object> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<Uint32T> tmp51;
    TNode<BoolT> tmp52;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_2, &phi_bb16_9);
        tmp31 = FromConstexpr_uint64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xcccccccdull));
        tmp32 = Convert_uint64_uint32_0(state_, TNode<Uint32T> { phi_bb16_2 });
        tmp33 = CodeStubAssembler(state_).Uint64Mul(TNode<Uint64T> { tmp32 }, TNode<Uint64T> { tmp31 });
        tmp34 = FromConstexpr_uint64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x23ull));
        tmp35 = CodeStubAssembler(state_).Word64Shr(TNode<Uint64T> { tmp33 }, TNode<Uint64T> { tmp34 });
        tmp36 = Convert_uint32_uint64_0(state_, TNode<Uint64T> { tmp35 });
        tmp37 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp38 = CodeStubAssembler(state_).Uint32Mul(TNode<Uint32T> { tmp36 }, TNode<Uint32T> { tmp37 });
        tmp39 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { phi_bb16_2 }, TNode<Uint32T> { tmp38 });
        tmp40 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x30ull));
        tmp41 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { tmp39 }, TNode<Uint32T> { tmp40 });
        tmp42 = ca_.UncheckedCast<Uint8T>(TNode<Uint32T> { tmp41 });
        tmp43 = TimesSizeOf_char8_0(state_, TNode<IntPtrT> { phi_bb16_9 });
        tmp44 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp28 }, TNode<IntPtrT> { tmp43 });
        std::tie(tmp45, tmp46) = NewReference_char8_0(state_, TNode<Object> { tmp27 }, TNode<IntPtrT> { tmp44 }).Flatten();
        std::tie(tmp47, tmp48)
            = UnsafeConstCast_char8_0(state_, TorqueStructReference_char8_0 { TNode<Object> { tmp45 }, TNode<IntPtrT> { tmp46 }, TorqueStructUnsafe_0 {} })
                  .Flatten();
        CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference { tmp47, tmp48 }, tmp42);
        tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp50 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { phi_bb16_9 }, TNode<IntPtrT> { tmp49 });
        tmp51 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp52 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp36 }, TNode<Uint32T> { tmp51 });
        ca_.Branch(tmp52, &block20, std::vector<compiler::Node*> {}, &block21, std::vector<compiler::Node*> {});
    }

    if (block20.is_used()) {
        ca_.Bind(&block20);
        ca_.Goto(&block17, tmp36, tmp50);
    }

    if (block21.is_used()) {
        ca_.Bind(&block21);
        ca_.Goto(&block18, tmp36, tmp50);
    }

    TNode<Uint32T> phi_bb17_2;
    TNode<IntPtrT> phi_bb17_9;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_2, &phi_bb17_9);
        if (((CodeStubAssembler(state_).ConstexprBoolNot(p_isPositive)))) {
            ca_.Goto(&block22, phi_bb17_2, phi_bb17_9);
        } else {
            ca_.Goto(&block23, phi_bb17_2, phi_bb17_9);
        }
    }

    TNode<Uint32T> phi_bb22_2;
    TNode<IntPtrT> phi_bb22_9;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<Object> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<Object> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<Uint8T> tmp60;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_2, &phi_bb22_9);
        tmp53 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp54 = TimesSizeOf_char8_0(state_, TNode<IntPtrT> { tmp53 });
        tmp55 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp28 }, TNode<IntPtrT> { tmp54 });
        std::tie(tmp56, tmp57) = NewReference_char8_0(state_, TNode<Object> { tmp27 }, TNode<IntPtrT> { tmp55 }).Flatten();
        std::tie(tmp58, tmp59)
            = UnsafeConstCast_char8_0(state_, TorqueStructReference_char8_0 { TNode<Object> { tmp56 }, TNode<IntPtrT> { tmp57 }, TorqueStructUnsafe_0 {} })
                  .Flatten();
        tmp60 = FromConstexpr_char8_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2dull));
        CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference { tmp58, tmp59 }, tmp60);
        ca_.Goto(&block24, phi_bb22_2, phi_bb22_9);
    }

    TNode<Uint32T> phi_bb23_2;
    TNode<IntPtrT> phi_bb23_9;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_2, &phi_bb23_9);
        ca_.Goto(&block24, phi_bb23_2, phi_bb23_9);
    }

    TNode<Uint32T> phi_bb24_2;
    TNode<IntPtrT> phi_bb24_9;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_2, &phi_bb24_9);
        ca_.Goto(&block26);
    }

    ca_.Bind(&block26);
    return TNode<String> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=104&c=1
TNode<String> IntToDecimalString_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_x)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        if (((CodeStubAssembler(state_).Is64()))) {
            ca_.Goto(&block2);
        } else {
            ca_.Goto(&block3);
        }
    }

    TNode<RawPtrT> tmp0;
    TNode<Int32T> tmp1;
    TNode<BoolT> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp0 = CodeStubAssembler(state_).Log10OffsetTable();
        tmp1 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp2 = CodeStubAssembler(state_).Int32GreaterThanOrEqual(TNode<Int32T> { p_x }, TNode<Int32T> { tmp1 });
        ca_.Branch(tmp2, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp3;
    TNode<BoolT> tmp4;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp3 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp4 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T> { p_x }, TNode<Int32T> { tmp3 });
        ca_.Branch(tmp4, &block8, std::vector<compiler::Node*> {}, &block9, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp5;
    TNode<BoolT> tmp6;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp5 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { p_x }, TNode<Int32T> { tmp5 });
        ca_.Branch(tmp6, &block10, std::vector<compiler::Node*> {}, &block11, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp7;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp7 = CodeStubAssembler(state_).ZeroStringConstant();
        ca_.Goto(&block1, tmp7);
    }

    TNode<Uint32T> tmp8;
    TNode<Uint8T> tmp9;
    TNode<String> tmp10;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp8 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { p_x });
        tmp9 = ToCharCode_0(state_, TNode<Uint32T> { tmp8 });
        tmp10 = CodeStubAssembler(state_).StringFromSingleCharCode(TNode<Uint8T> { tmp9 });
        ca_.Goto(&block1, tmp10);
    }

    TNode<String> tmp11;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp11 = IntToDecimalStringImpl_0(state_, TNode<Int32T> { p_x }, TNode<RawPtrT> { tmp0 }, true);
        ca_.Goto(&block1, tmp11);
    }

    TNode<String> tmp12;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp12 = IntToDecimalStringImpl_0(state_, TNode<Int32T> { p_x }, TNode<RawPtrT> { tmp0 }, false);
        ca_.Goto(&block1, tmp12);
    }

    TNode<Uint32T> tmp13;
    TNode<String> tmp14;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp13 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp14 = IntToString_0(state_, TNode<Int32T> { p_x }, TNode<Uint32T> { tmp13 });
        ca_.Goto(&block1, tmp14);
    }

    TNode<String> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_1);
        ca_.Goto(&block12);
    }

    ca_.Bind(&block12);
    return TNode<String> { phi_bb1_1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=125&c=1
TNode<String> IntToString_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_x, TNode<Uint32T> p_radix)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Int32T> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Int32T> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Int32T> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Int32T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Int32T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block38(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Int32T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block39(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, Int32T, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        if (((CodeStubAssembler(state_).Is64()))) {
            ca_.Goto(&block2);
        } else {
            ca_.Goto(&block3);
        }
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        ca_.Goto(&block4);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block4);
    }

    TNode<Int32T> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp0 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T> { p_x }, TNode<Int32T> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp1 });
        ca_.Branch(tmp2, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp3;
    TNode<BoolT> tmp4;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp3 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { p_x });
        tmp4 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { p_radix });
        ca_.Branch(tmp4, &block12, std::vector<compiler::Node*> {}, &block13, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp5;
    TNode<BoolT> tmp6;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp5 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp5 });
        ca_.Branch(tmp6, &block14, std::vector<compiler::Node*> {}, &block15, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp7;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp7 = CodeStubAssembler(state_).ZeroStringConstant();
        ca_.Goto(&block1, tmp7);
    }

    TNode<Uint8T> tmp8;
    TNode<String> tmp9;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp8 = ToCharCode_0(state_, TNode<Uint32T> { tmp3 });
        tmp9 = CodeStubAssembler(state_).StringFromSingleCharCode(TNode<Uint8T> { tmp8 });
        ca_.Goto(&block1, tmp9);
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block11, tmp3);
    }

    TNode<Int32T> tmp10;
    TNode<Int32T> tmp11;
    TNode<Uint32T> tmp12;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp10 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp11 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp10 }, TNode<Int32T> { p_x });
        tmp12 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp11 });
        ca_.Goto(&block11, tmp12);
    }

    TNode<Uint32T> phi_bb11_3;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_3);
        ca_.Branch(tmp1, &block20, std::vector<compiler::Node*> {}, &block21, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp13;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        tmp13 = Convert_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        ca_.Goto(&block22, tmp13);
    }

    TNode<Int32T> tmp14;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp14 = Convert_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block22, tmp14);
    }

    TNode<Int32T> phi_bb22_5;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_5);
        ca_.Goto(&block26, phi_bb11_3, phi_bb22_5);
    }

    TNode<Uint32T> phi_bb26_4;
    TNode<Int32T> phi_bb26_5;
    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_4, &phi_bb26_5);
        tmp15 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp16 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { phi_bb26_4 }, TNode<Uint32T> { tmp15 });
        ca_.Branch(tmp16, &block24, std::vector<compiler::Node*> { phi_bb26_4, phi_bb26_5 }, &block25, std::vector<compiler::Node*> { phi_bb26_4, phi_bb26_5 });
    }

    TNode<Uint32T> phi_bb24_4;
    TNode<Int32T> phi_bb24_5;
    TNode<Uint32T> tmp17;
    TNode<Int32T> tmp18;
    TNode<Int32T> tmp19;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_4, &phi_bb24_5);
        tmp17 = CodeStubAssembler(state_).Uint32Div(TNode<Uint32T> { phi_bb24_4 }, TNode<Uint32T> { p_radix });
        tmp18 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp19 = CodeStubAssembler(state_).Int32Add(TNode<Int32T> { phi_bb24_5 }, TNode<Int32T> { tmp18 });
        ca_.Goto(&block26, tmp17, tmp19);
    }

    TNode<Uint32T> phi_bb25_4;
    TNode<Int32T> phi_bb25_5;
    TNode<Uint32T> tmp20;
    TNode<SeqOneByteString> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_4, &phi_bb25_5);
        tmp20 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { phi_bb25_5 });
        tmp21 = AllocateNonEmptySeqOneByteString_0(state_, TNode<Uint32T> { tmp20 });
        tmp22 = Convert_intptr_int32_0(state_, TNode<Int32T> { phi_bb25_5 });
        tmp23 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp24 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { tmp22 }, TNode<IntPtrT> { tmp23 });
        ca_.Goto(&block33, phi_bb11_3, phi_bb25_4, phi_bb25_5, tmp24);
    }

    TNode<Uint32T> phi_bb33_3;
    TNode<Uint32T> phi_bb33_4;
    TNode<Int32T> phi_bb33_5;
    TNode<IntPtrT> phi_bb33_7;
    TNode<Uint32T> tmp25;
    TNode<BoolT> tmp26;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_3, &phi_bb33_4, &phi_bb33_5, &phi_bb33_7);
        tmp25 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp26 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { phi_bb33_3 }, TNode<Uint32T> { tmp25 });
        ca_.Branch(tmp26, &block31, std::vector<compiler::Node*> { phi_bb33_3, phi_bb33_4, phi_bb33_5, phi_bb33_7 }, &block32,
            std::vector<compiler::Node*> { phi_bb33_3, phi_bb33_4, phi_bb33_5, phi_bb33_7 });
    }

    TNode<Uint32T> phi_bb31_3;
    TNode<Uint32T> phi_bb31_4;
    TNode<Int32T> phi_bb31_5;
    TNode<IntPtrT> phi_bb31_7;
    TNode<Uint32T> tmp27;
    TNode<Uint32T> tmp28;
    TNode<Object> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<UintPtrT> tmp32;
    TNode<UintPtrT> tmp33;
    TNode<BoolT> tmp34;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_3, &phi_bb31_4, &phi_bb31_5, &phi_bb31_7);
        tmp27 = CodeStubAssembler(state_).Uint32Mod(TNode<Uint32T> { phi_bb31_3 }, TNode<Uint32T> { p_radix });
        tmp28 = CodeStubAssembler(state_).Uint32Div(TNode<Uint32T> { phi_bb31_3 }, TNode<Uint32T> { p_radix });
        std::tie(tmp29, tmp30, tmp31) = FieldSliceSeqOneByteStringChars_0(state_, TNode<SeqOneByteString> { tmp21 }).Flatten();
        tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb31_7 });
        tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp31 });
        tmp34 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp32 }, TNode<UintPtrT> { tmp33 });
        ca_.Branch(tmp34, &block38, std::vector<compiler::Node*> { phi_bb31_4, phi_bb31_5, phi_bb31_7, phi_bb31_7, phi_bb31_7, phi_bb31_7, phi_bb31_7 },
            &block39, std::vector<compiler::Node*> { phi_bb31_4, phi_bb31_5, phi_bb31_7, phi_bb31_7, phi_bb31_7, phi_bb31_7, phi_bb31_7 });
    }

    TNode<Uint32T> phi_bb38_4;
    TNode<Int32T> phi_bb38_5;
    TNode<IntPtrT> phi_bb38_7;
    TNode<IntPtrT> phi_bb38_13;
    TNode<IntPtrT> phi_bb38_14;
    TNode<IntPtrT> phi_bb38_18;
    TNode<IntPtrT> phi_bb38_19;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<Object> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<Object> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<Uint8T> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_4, &phi_bb38_5, &phi_bb38_7, &phi_bb38_13, &phi_bb38_14, &phi_bb38_18, &phi_bb38_19);
        tmp35 = TimesSizeOf_char8_0(state_, TNode<IntPtrT> { phi_bb38_19 });
        tmp36 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp30 }, TNode<IntPtrT> { tmp35 });
        std::tie(tmp37, tmp38) = NewReference_char8_0(state_, TNode<Object> { tmp29 }, TNode<IntPtrT> { tmp36 }).Flatten();
        std::tie(tmp39, tmp40)
            = UnsafeConstCast_char8_0(state_, TorqueStructReference_char8_0 { TNode<Object> { tmp37 }, TNode<IntPtrT> { tmp38 }, TorqueStructUnsafe_0 {} })
                  .Flatten();
        tmp41 = ToCharCode_0(state_, TNode<Uint32T> { tmp27 });
        CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference { tmp39, tmp40 }, tmp41);
        tmp42 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp43 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { phi_bb38_7 }, TNode<IntPtrT> { tmp42 });
        ca_.Goto(&block33, tmp28, phi_bb38_4, phi_bb38_5, tmp43);
    }

    TNode<Uint32T> phi_bb39_4;
    TNode<Int32T> phi_bb39_5;
    TNode<IntPtrT> phi_bb39_7;
    TNode<IntPtrT> phi_bb39_13;
    TNode<IntPtrT> phi_bb39_14;
    TNode<IntPtrT> phi_bb39_18;
    TNode<IntPtrT> phi_bb39_19;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_4, &phi_bb39_5, &phi_bb39_7, &phi_bb39_13, &phi_bb39_14, &phi_bb39_18, &phi_bb39_19);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Uint32T> phi_bb32_3;
    TNode<Uint32T> phi_bb32_4;
    TNode<Int32T> phi_bb32_5;
    TNode<IntPtrT> phi_bb32_7;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_3, &phi_bb32_4, &phi_bb32_5, &phi_bb32_7);
        ca_.Branch(tmp1, &block42, std::vector<compiler::Node*> { phi_bb32_3, phi_bb32_4, phi_bb32_5, phi_bb32_7 }, &block43,
            std::vector<compiler::Node*> { phi_bb32_3, phi_bb32_4, phi_bb32_5, phi_bb32_7 });
    }

    TNode<Uint32T> phi_bb42_3;
    TNode<Uint32T> phi_bb42_4;
    TNode<Int32T> phi_bb42_5;
    TNode<IntPtrT> phi_bb42_7;
    TNode<Object> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<UintPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<UintPtrT> tmp49;
    TNode<UintPtrT> tmp50;
    TNode<BoolT> tmp51;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_3, &phi_bb42_4, &phi_bb42_5, &phi_bb42_7);
        std::tie(tmp44, tmp45, tmp46) = FieldSliceSeqOneByteStringChars_0(state_, TNode<SeqOneByteString> { tmp21 }).Flatten();
        tmp47 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp48 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { tmp47 });
        tmp49 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp48 });
        tmp50 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp46 });
        tmp51 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp49 }, TNode<UintPtrT> { tmp50 });
        ca_.Branch(tmp51, &block54, std::vector<compiler::Node*> { phi_bb42_3, phi_bb42_4, phi_bb42_5, phi_bb42_7 }, &block55,
            std::vector<compiler::Node*> { phi_bb42_3, phi_bb42_4, phi_bb42_5, phi_bb42_7 });
    }

    TNode<Uint32T> phi_bb54_3;
    TNode<Uint32T> phi_bb54_4;
    TNode<Int32T> phi_bb54_5;
    TNode<IntPtrT> phi_bb54_7;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<Object> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<Object> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<Uint8T> tmp58;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_3, &phi_bb54_4, &phi_bb54_5, &phi_bb54_7);
        tmp52 = TimesSizeOf_char8_0(state_, TNode<IntPtrT> { tmp48 });
        tmp53 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp45 }, TNode<IntPtrT> { tmp52 });
        std::tie(tmp54, tmp55) = NewReference_char8_0(state_, TNode<Object> { tmp44 }, TNode<IntPtrT> { tmp53 }).Flatten();
        std::tie(tmp56, tmp57)
            = UnsafeConstCast_char8_0(state_, TorqueStructReference_char8_0 { TNode<Object> { tmp54 }, TNode<IntPtrT> { tmp55 }, TorqueStructUnsafe_0 {} })
                  .Flatten();
        tmp58 = FromConstexpr_char8_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2dull));
        CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference { tmp56, tmp57 }, tmp58);
        ca_.Goto(&block44, phi_bb54_3, phi_bb54_4, phi_bb54_5, phi_bb54_7);
    }

    TNode<Uint32T> phi_bb55_3;
    TNode<Uint32T> phi_bb55_4;
    TNode<Int32T> phi_bb55_5;
    TNode<IntPtrT> phi_bb55_7;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_3, &phi_bb55_4, &phi_bb55_5, &phi_bb55_7);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Uint32T> phi_bb43_3;
    TNode<Uint32T> phi_bb43_4;
    TNode<Int32T> phi_bb43_5;
    TNode<IntPtrT> phi_bb43_7;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_3, &phi_bb43_4, &phi_bb43_5, &phi_bb43_7);
        if (((CodeStubAssembler(state_).ConstexprBoolNot((CodeStubAssembler(state_).Is64()))))) {
            ca_.Goto(&block62, phi_bb43_3, phi_bb43_4, phi_bb43_5, phi_bb43_7);
        } else {
            ca_.Goto(&block63, phi_bb43_3, phi_bb43_4, phi_bb43_5, phi_bb43_7);
        }
    }

    TNode<Uint32T> phi_bb62_3;
    TNode<Uint32T> phi_bb62_4;
    TNode<Int32T> phi_bb62_5;
    TNode<IntPtrT> phi_bb62_7;
    TNode<Uint32T> tmp59;
    TNode<BoolT> tmp60;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_3, &phi_bb62_4, &phi_bb62_5, &phi_bb62_7);
        tmp59 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp60 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { p_radix }, TNode<Uint32T> { tmp59 });
        ca_.Branch(tmp60, &block65, std::vector<compiler::Node*> { phi_bb62_3, phi_bb62_4, phi_bb62_5, phi_bb62_7 }, &block66,
            std::vector<compiler::Node*> { phi_bb62_3, phi_bb62_4, phi_bb62_5, phi_bb62_7 });
    }

    TNode<Uint32T> phi_bb65_3;
    TNode<Uint32T> phi_bb65_4;
    TNode<Int32T> phi_bb65_5;
    TNode<IntPtrT> phi_bb65_7;
    TNode<IntPtrT> tmp61;
    TNode<Uint32T> tmp62;
    TNode<Uint32T> tmp63;
    TNode<Uint32T> tmp64;
    if (block65.is_used()) {
        ca_.Bind(&block65, &phi_bb65_3, &phi_bb65_4, &phi_bb65_5, &phi_bb65_7);
        tmp61 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp62 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { p_x });
        tmp63 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { phi_bb65_5 });
        tmp64 = MakeArrayIndexHash_0(state_, TNode<Uint32T> { tmp62 }, TNode<Uint32T> { tmp63 });
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { tmp21, tmp61 }, tmp64);
        ca_.Goto(&block66, phi_bb65_3, phi_bb65_4, phi_bb65_5, phi_bb65_7);
    }

    TNode<Uint32T> phi_bb66_3;
    TNode<Uint32T> phi_bb66_4;
    TNode<Int32T> phi_bb66_5;
    TNode<IntPtrT> phi_bb66_7;
    if (block66.is_used()) {
        ca_.Bind(&block66, &phi_bb66_3, &phi_bb66_4, &phi_bb66_5, &phi_bb66_7);
        ca_.Goto(&block64, phi_bb66_3, phi_bb66_4, phi_bb66_5, phi_bb66_7);
    }

    TNode<Uint32T> phi_bb63_3;
    TNode<Uint32T> phi_bb63_4;
    TNode<Int32T> phi_bb63_5;
    TNode<IntPtrT> phi_bb63_7;
    if (block63.is_used()) {
        ca_.Bind(&block63, &phi_bb63_3, &phi_bb63_4, &phi_bb63_5, &phi_bb63_7);
        ca_.Goto(&block64, phi_bb63_3, phi_bb63_4, phi_bb63_5, phi_bb63_7);
    }

    TNode<Uint32T> phi_bb64_3;
    TNode<Uint32T> phi_bb64_4;
    TNode<Int32T> phi_bb64_5;
    TNode<IntPtrT> phi_bb64_7;
    if (block64.is_used()) {
        ca_.Bind(&block64, &phi_bb64_3, &phi_bb64_4, &phi_bb64_5, &phi_bb64_7);
        ca_.Goto(&block44, phi_bb64_3, phi_bb64_4, phi_bb64_5, phi_bb64_7);
    }

    TNode<Uint32T> phi_bb44_3;
    TNode<Uint32T> phi_bb44_4;
    TNode<Int32T> phi_bb44_5;
    TNode<IntPtrT> phi_bb44_7;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_3, &phi_bb44_4, &phi_bb44_5, &phi_bb44_7);
        ca_.Goto(&block1, tmp21);
    }

    TNode<String> phi_bb1_2;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_2);
        ca_.Goto(&block71);
    }

    ca_.Bind(&block71);
    return TNode<String> { phi_bb1_2 };
}

TF_BUILTIN(NumberPrototypeToString, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Object> tmp2;
    TNode<Undefined> tmp3;
    TNode<BoolT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ThisNumberValue_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, "Number.prototype.toString");
        tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp2 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp1 });
        tmp3 = Undefined_0(state_);
        tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { tmp2 }, TNode<HeapObject> { tmp3 });
        ca_.Branch(tmp4, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp5;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        ca_.Goto(&block3, tmp5);
    }

    TNode<Number> tmp6;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp6 = ToInteger_Inline_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp2 });
        ca_.Goto(&block3, tmp6);
    }

    TNode<Number> phi_bb3_8;
    TNode<Number> tmp7;
    TNode<BoolT> tmp8;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_8);
        tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp8 = NumberIsLessThan_0(state_, TNode<Number> { phi_bb3_8 }, TNode<Number> { tmp7 });
        ca_.Branch(tmp8, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp9;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block9, tmp9);
    }

    TNode<Number> tmp10;
    TNode<BoolT> tmp11;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp10 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x24ull));
        tmp11 = NumberIsGreaterThan_0(state_, TNode<Number> { phi_bb3_8 }, TNode<Number> { tmp10 });
        ca_.Goto(&block9, tmp11);
    }

    TNode<BoolT> phi_bb9_10;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_10);
        ca_.Branch(phi_bb9_10, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { parameter0 }, MessageTemplate::kToRadixFormatRange);
    }

    TNode<Number> tmp12;
    TNode<BoolT> tmp13;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp12 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp13 = IsNumberEqual_0(state_, TNode<Number> { phi_bb3_8 }, TNode<Number> { tmp12 });
        ca_.Branch(tmp13, &block10, std::vector<compiler::Node*> {}, &block11, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp14;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp14 = CodeStubAssembler(state_).NumberToString(TNode<Number> { tmp0 });
        arguments.PopAndReturn(tmp14);
    }

    TNode<BoolT> tmp15;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp15 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object> { tmp0 });
        ca_.Branch(tmp15, &block12, std::vector<compiler::Node*> {}, &block13, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp16;
    TNode<Int32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<String> tmp19;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp16 = Convert_int32_Number_0(state_, TNode<Number> { tmp0 });
        tmp17 = Convert_int32_Number_0(state_, TNode<Number> { phi_bb3_8 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp17 });
        tmp19 = IntToString_0(state_, TNode<Int32T> { tmp16 }, TNode<Uint32T> { tmp18 });
        arguments.PopAndReturn(tmp19);
    }

    TNode<Number> tmp20;
    TNode<BoolT> tmp21;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp20 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp21 = IsNumberEqual_0(state_, TNode<Number> { tmp0 }, TNode<Number> { tmp20 });
        ca_.Branch(tmp21, &block14, std::vector<compiler::Node*> {}, &block15, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp22;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp22 = CodeStubAssembler(state_).ZeroStringConstant();
        arguments.PopAndReturn(tmp22);
    }

    TNode<BoolT> tmp23;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp23 = NumberIsNaN_0(state_, TNode<Number> { tmp0 });
        ca_.Branch(tmp23, &block17, std::vector<compiler::Node*> {}, &block18, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp24;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp24 = CodeStubAssembler(state_).NaNStringConstant();
        arguments.PopAndReturn(tmp24);
    }

    TNode<Number> tmp25;
    TNode<BoolT> tmp26;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp25 = FromConstexpr_Number_constexpr_float64_0(state_, V8_INFINITY);
        tmp26 = IsNumberEqual_0(state_, TNode<Number> { tmp0 }, TNode<Number> { tmp25 });
        ca_.Branch(tmp26, &block20, std::vector<compiler::Node*> {}, &block21, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp27;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        tmp27 = CodeStubAssembler(state_).InfinityStringConstant();
        arguments.PopAndReturn(tmp27);
    }

    TNode<Number> tmp28;
    TNode<BoolT> tmp29;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp28 = FromConstexpr_Number_constexpr_float64_0(state_, -V8_INFINITY);
        tmp29 = IsNumberEqual_0(state_, TNode<Number> { tmp0 }, TNode<Number> { tmp28 });
        ca_.Branch(tmp29, &block23, std::vector<compiler::Node*> {}, &block24, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp30;
    if (block23.is_used()) {
        ca_.Bind(&block23);
        tmp30 = CodeStubAssembler(state_).MinusInfinityStringConstant();
        arguments.PopAndReturn(tmp30);
    }

    TNode<String> tmp31;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        tmp31 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kDoubleToStringWithRadix, parameter0, tmp0, phi_bb3_8));
        arguments.PopAndReturn(tmp31);
    }
}

TF_BUILTIN(NumberIsFinite, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_Smi_0(state_, TNode<Object> { parameter2 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    TNode<HeapNumber> tmp2;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter2) }, &label3);
        ca_.Goto(&block7);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8);
        }
    }

    TNode<True> tmp4;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = True_0(state_);
        CodeStubAssembler(state_).Return(tmp4);
    }

    TNode<False> tmp5;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp5 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp5);
    }

    TNode<Float64T> tmp6;
    TNode<Float64T> tmp7;
    TNode<BoolT> tmp8;
    TNode<BoolT> tmp9;
    TNode<Boolean> tmp10;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp6 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp2 });
        tmp7 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T> { tmp6 }, TNode<Float64T> { tmp6 });
        tmp8 = Float64IsNaN_0(state_, TNode<Float64T> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp8 });
        tmp10 = Convert_Boolean_bool_0(state_, TNode<BoolT> { tmp9 });
        CodeStubAssembler(state_).Return(tmp10);
    }
}

TF_BUILTIN(NumberIsInteger, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    TNode<Boolean> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).IsInteger(TNode<Object> { parameter1 });
        tmp1 = CodeStubAssembler(state_).SelectBooleanConstant(TNode<BoolT> { tmp0 });
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(NumberIsNaN, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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

    TNode<HeapNumber> tmp2;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter1) }, &label3);
        ca_.Goto(&block7);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8);
        }
    }

    TNode<False> tmp4;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp4);
    }

    TNode<False> tmp5;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp5 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp5);
    }

    TNode<Float64T> tmp6;
    TNode<BoolT> tmp7;
    TNode<Boolean> tmp8;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp6 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp2 });
        tmp7 = Float64IsNaN_0(state_, TNode<Float64T> { tmp6 });
        tmp8 = Convert_Boolean_bool_0(state_, TNode<BoolT> { tmp7 });
        CodeStubAssembler(state_).Return(tmp8);
    }
}

TF_BUILTIN(NumberIsSafeInteger, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    TNode<Boolean> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).IsSafeInteger(TNode<Object> { parameter1 });
        tmp1 = CodeStubAssembler(state_).SelectBooleanConstant(TNode<BoolT> { tmp0 });
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(NumberPrototypeValueOf, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToThisValue(
            TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, PrimitiveType::kNumber, "Number.prototype.valueOf");
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(NumberParseFloat, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_Smi_0(state_, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    TNode<HeapNumber> tmp2;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter1) }, &label3);
        ca_.Goto(&block9);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block10);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).Return(tmp0);
    }

    TNode<String> tmp4;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = Cast_String_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter1) }, &label5);
        ca_.Goto(&block17);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block18);
        }
    }

    TNode<Float64T> tmp6;
    TNode<Float64T> tmp7;
    TNode<BoolT> tmp8;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp6 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp2 });
        tmp7 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp8 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp6 }, TNode<Float64T> { tmp7 });
        ca_.Branch(tmp8, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp9;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp9 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block13, tmp9);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block13, tmp2);
    }

    TNode<Number> phi_bb13_4;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_4);
        CodeStubAssembler(state_).Return(phi_bb13_4);
    }

    TNode<String> tmp10;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp10 = ca_.CallBuiltin<String>(Builtin::kToString, parameter0, parameter1);
        ca_.Goto(&block2, tmp10);
    }

    if (block17.is_used()) {
        ca_.Bind(&block17);
        ca_.Goto(&block2, tmp4);
    }

    TNode<String> phi_bb2_2;
    TNode<IntPtrT> tmp11;
    TNode<Uint32T> tmp12;
    TNode<BoolT> tmp13;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_2);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp12 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { phi_bb2_2, tmp11 });
        tmp13 = IsIntegerIndex_0(state_, TNode<Uint32T> { tmp12 });
        ca_.Branch(tmp13, &block21, std::vector<compiler::Node*> {}, &block22, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp14;
    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp14
            = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 26, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp12)));
        tmp15 = FromConstexpr_uint32_constexpr_uint32_0(state_, Name::kMaxCachedArrayIndexLength);
        tmp16 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp14 }, TNode<Uint32T> { tmp15 });
        ca_.Goto(&block23, tmp16);
    }

    TNode<BoolT> tmp17;
    if (block22.is_used()) {
        ca_.Bind(&block22);
        tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block23, tmp17);
    }

    TNode<BoolT> phi_bb23_5;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_5);
        ca_.Branch(phi_bb23_5, &block19, std::vector<compiler::Node*> {}, &block20, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp18;
    TNode<Smi> tmp19;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp18
            = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 2, 24, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp12)));
        tmp19 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { tmp18 });
        CodeStubAssembler(state_).Return(tmp19);
    }

    TNode<Number> tmp20;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        tmp20 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringParseFloat, parameter0, phi_bb2_2));
        CodeStubAssembler(state_).Return(tmp20);
    }
}

TF_BUILTIN(ParseInt, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kInput);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRadix);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Undefined> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Undefined_0(state_);
        tmp1 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { parameter2 }, TNode<HeapObject> { tmp0 });
        ca_.Branch(tmp1, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp2;
    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp2 = SmiConstant_0(state_, IntegerLiteral(false, 0xaull));
        tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { parameter2 }, TNode<MaybeObject> { tmp2 });
        tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp3 });
        ca_.Goto(&block11, tmp4);
    }

    TNode<BoolT> tmp5;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block11, tmp5);
    }

    TNode<BoolT> phi_bb11_4;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_4);
        ca_.Branch(phi_bb11_4, &block12, std::vector<compiler::Node*> {}, &block13, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp6;
    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp6 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        tmp7 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { parameter2 }, TNode<MaybeObject> { tmp6 });
        tmp8 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp7 });
        ca_.Goto(&block14, tmp8);
    }

    TNode<BoolT> tmp9;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block14, tmp9);
    }

    TNode<BoolT> phi_bb14_4;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_4);
        ca_.Branch(phi_bb14_4, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp10;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        compiler::CodeAssemblerLabel label11(&ca_);
        tmp10 = Cast_Smi_0(state_, TNode<Object> { parameter1 }, &label11);
        ca_.Goto(&block17);
        if (label11.is_used()) {
            ca_.Bind(&label11);
            ca_.Goto(&block18);
        }
    }

    TNode<HeapNumber> tmp12;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        compiler::CodeAssemblerLabel label13(&ca_);
        tmp12 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter1) }, &label13);
        ca_.Goto(&block21);
        if (label13.is_used()) {
            ca_.Bind(&label13);
            ca_.Goto(&block22);
        }
    }

    if (block17.is_used()) {
        ca_.Bind(&block17);
        CodeStubAssembler(state_).Return(tmp10);
    }

    TNode<String> tmp14;
    if (block22.is_used()) {
        ca_.Bind(&block22);
        compiler::CodeAssemblerLabel label15(&ca_);
        tmp14 = Cast_String_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter1) }, &label15);
        ca_.Goto(&block32);
        if (label15.is_used()) {
            ca_.Bind(&label15);
            ca_.Goto(&block33);
        }
    }

    TNode<Float64T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Int32T> tmp18;
    TNode<Float64T> tmp19;
    TNode<BoolT> tmp20;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp16 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp12 });
        tmp17 = CodeStubAssembler(state_).TruncateFloat64ToWord32(TNode<Float64T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { tmp17 });
        tmp19 = CodeStubAssembler(state_).ChangeInt32ToFloat64(TNode<Int32T> { tmp18 });
        tmp20 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp16 }, TNode<Float64T> { tmp19 });
        ca_.Branch(tmp20, &block23, std::vector<compiler::Node*> {}, &block24, std::vector<compiler::Node*> {});
    }

    if (block23.is_used()) {
        ca_.Bind(&block23);
        ca_.Goto(&block6);
    }

    TNode<Float64T> tmp21;
    TNode<Float64T> tmp22;
    TNode<BoolT> tmp23;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        tmp21 = FromConstexpr_float64_constexpr_float64_0(state_, 2147483648);
        tmp22 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T> { tmp16 });
        tmp23 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T> { tmp22 }, TNode<Float64T> { tmp21 });
        ca_.Branch(tmp23, &block27, std::vector<compiler::Node*> {}, &block28, std::vector<compiler::Node*> {});
    }

    TNode<Float64T> tmp24;
    TNode<BoolT> tmp25;
    if (block27.is_used()) {
        ca_.Bind(&block27);
        tmp24 = FromConstexpr_float64_constexpr_float64_0(state_, 1);
        tmp25 = CodeStubAssembler(state_).Float64GreaterThanOrEqual(TNode<Float64T> { tmp22 }, TNode<Float64T> { tmp24 });
        ca_.Goto(&block29, tmp25);
    }

    TNode<BoolT> tmp26;
    if (block28.is_used()) {
        ca_.Bind(&block28);
        tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block29, tmp26);
    }

    TNode<BoolT> phi_bb29_10;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_10);
        ca_.Branch(phi_bb29_10, &block25, std::vector<compiler::Node*> {}, &block26, std::vector<compiler::Node*> {});
    }

    if (block25.is_used()) {
        ca_.Bind(&block25);
        ca_.Goto(&block6);
    }

    if (block26.is_used()) {
        ca_.Bind(&block26);
        ca_.Goto(&block2);
    }

    if (block33.is_used()) {
        ca_.Bind(&block33);
        ca_.Goto(&block2);
    }

    TNode<IntPtrT> tmp27;
    TNode<Uint32T> tmp28;
    TNode<BoolT> tmp29;
    if (block32.is_used()) {
        ca_.Bind(&block32);
        tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp28 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { tmp14, tmp27 });
        tmp29 = IsIntegerIndex_0(state_, TNode<Uint32T> { tmp28 });
        ca_.Branch(tmp29, &block36, std::vector<compiler::Node*> {}, &block37, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp30;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp30 = CodeStubAssembler(state_).ChangeInt32ToTagged(TNode<Int32T> { tmp18 });
        CodeStubAssembler(state_).Return(tmp30);
    }

    TNode<Uint32T> tmp31;
    TNode<Uint32T> tmp32;
    TNode<BoolT> tmp33;
    if (block36.is_used()) {
        ca_.Bind(&block36);
        tmp31
            = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 26, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp28)));
        tmp32 = FromConstexpr_uint32_constexpr_uint32_0(state_, Name::kMaxCachedArrayIndexLength);
        tmp33 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp31 }, TNode<Uint32T> { tmp32 });
        ca_.Goto(&block38, tmp33);
    }

    TNode<BoolT> tmp34;
    if (block37.is_used()) {
        ca_.Bind(&block37);
        tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block38, tmp34);
    }

    TNode<BoolT> phi_bb38_6;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_6);
        ca_.Branch(phi_bb38_6, &block34, std::vector<compiler::Node*> {}, &block35, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp35;
    TNode<Smi> tmp36;
    if (block34.is_used()) {
        ca_.Bind(&block34);
        tmp35
            = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 2, 24, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp28)));
        tmp36 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { tmp35 });
        CodeStubAssembler(state_).Return(tmp36);
    }

    if (block35.is_used()) {
        ca_.Bind(&block35);
        ca_.Goto(&block2);
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kStringParseInt, parameter0, parameter1, parameter2);
    }
}

TF_BUILTIN(NumberParseInt, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRadix);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.CallBuiltin<Number>(Builtin::kParseInt, parameter0, parameter1, parameter2);
        CodeStubAssembler(state_).Return(tmp0);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=385&c=1
TNode<Object> ToNumericOrPrimitive_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_JSReceiver_1(state_, TNode<Context> { p_context }, TNode<Object> { p_value }, &label1);
        ca_.Goto(&block4);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block5);
        }
    }

    TNode<Numeric> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = ca_.CallBuiltin<Numeric>(Builtin::kNonNumberToNumeric, p_context, ca_.UncheckedCast<Object>(p_value));
        ca_.Goto(&block1, tmp2);
    }

    TNode<Object> tmp3;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = ca_.CallBuiltin<Object>(Builtin::kNonPrimitiveToPrimitive_Default, p_context, tmp0);
        ca_.Goto(&block1, tmp3);
    }

    TNode<Object> phi_bb1_2;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_2);
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Object> { phi_bb1_2 };
}

TF_BUILTIN(Add, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeftArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRightArg);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block78(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, String> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Numeric, Numeric> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Float64T, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Goto(&block11, parameter1, parameter2);
    }

    TNode<Object> phi_bb11_3;
    TNode<Object> phi_bb11_4;
    TNode<BoolT> tmp0;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_3, &phi_bb11_4);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp0, &block9, std::vector<compiler::Node*> { phi_bb11_3, phi_bb11_4 }, &block10, std::vector<compiler::Node*> { phi_bb11_3, phi_bb11_4 });
    }

    TNode<Object> phi_bb9_3;
    TNode<Object> phi_bb9_4;
    TNode<Smi> tmp1;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_3, &phi_bb9_4);
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_Smi_0(state_, TNode<Object> { phi_bb9_3 }, &label2);
        ca_.Goto(&block14, phi_bb9_3, phi_bb9_4, phi_bb9_3, phi_bb9_3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block15, phi_bb9_3, phi_bb9_4, phi_bb9_3, phi_bb9_3);
        }
    }

    TNode<Object> phi_bb15_3;
    TNode<Object> phi_bb15_4;
    TNode<Object> phi_bb15_5;
    TNode<Object> phi_bb15_6;
    TNode<HeapNumber> tmp3;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_3, &phi_bb15_4, &phi_bb15_5, &phi_bb15_6);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb15_5) }, &label4);
        ca_.Goto(&block38, phi_bb15_3, phi_bb15_4, phi_bb15_5);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block39, phi_bb15_3, phi_bb15_4, phi_bb15_5);
        }
    }

    TNode<Object> phi_bb14_3;
    TNode<Object> phi_bb14_4;
    TNode<Object> phi_bb14_5;
    TNode<Object> phi_bb14_6;
    TNode<Smi> tmp5;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_3, &phi_bb14_4, &phi_bb14_5, &phi_bb14_6);
        compiler::CodeAssemblerLabel label6(&ca_);
        tmp5 = Cast_Smi_0(state_, TNode<Object> { phi_bb14_4 }, &label6);
        ca_.Goto(&block18, phi_bb14_3, phi_bb14_4, phi_bb14_5, phi_bb14_4, phi_bb14_4);
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block19, phi_bb14_3, phi_bb14_4, phi_bb14_5, phi_bb14_4, phi_bb14_4);
        }
    }

    TNode<Object> phi_bb19_3;
    TNode<Object> phi_bb19_4;
    TNode<Object> phi_bb19_5;
    TNode<Object> phi_bb19_7;
    TNode<Object> phi_bb19_8;
    TNode<HeapNumber> tmp7;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_3, &phi_bb19_4, &phi_bb19_5, &phi_bb19_7, &phi_bb19_8);
        compiler::CodeAssemblerLabel label8(&ca_);
        tmp7 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb19_7) }, &label8);
        ca_.Goto(&block26, phi_bb19_3, phi_bb19_4, phi_bb19_5, phi_bb19_7);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block27, phi_bb19_3, phi_bb19_4, phi_bb19_5, phi_bb19_7);
        }
    }

    TNode<Object> phi_bb18_3;
    TNode<Object> phi_bb18_4;
    TNode<Object> phi_bb18_5;
    TNode<Object> phi_bb18_7;
    TNode<Object> phi_bb18_8;
    TNode<Smi> tmp9;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_3, &phi_bb18_4, &phi_bb18_5, &phi_bb18_7, &phi_bb18_8);
        compiler::CodeAssemblerLabel label10(&ca_);
        tmp9 = CodeStubAssembler(state_).TrySmiAdd(TNode<Smi> { tmp1 }, TNode<Smi> { tmp5 }, &label10);
        ca_.Goto(&block22, phi_bb18_3, phi_bb18_4, phi_bb18_5, phi_bb18_7);
        if (label10.is_used()) {
            ca_.Bind(&label10);
            ca_.Goto(&block23, phi_bb18_3, phi_bb18_4, phi_bb18_5, phi_bb18_7);
        }
    }

    TNode<Object> phi_bb23_3;
    TNode<Object> phi_bb23_4;
    TNode<Object> phi_bb23_5;
    TNode<Object> phi_bb23_7;
    TNode<Float64T> tmp11;
    TNode<Float64T> tmp12;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_3, &phi_bb23_4, &phi_bb23_5, &phi_bb23_7);
        tmp11 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp1 });
        tmp12 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp5 });
        ca_.Goto(&block2, phi_bb23_3, phi_bb23_4, tmp11, tmp12);
    }

    TNode<Object> phi_bb22_3;
    TNode<Object> phi_bb22_4;
    TNode<Object> phi_bb22_5;
    TNode<Object> phi_bb22_7;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_3, &phi_bb22_4, &phi_bb22_5, &phi_bb22_7);
        CodeStubAssembler(state_).Return(tmp9);
    }

    TNode<Object> phi_bb27_3;
    TNode<Object> phi_bb27_4;
    TNode<Object> phi_bb27_5;
    TNode<Object> phi_bb27_7;
    TNode<BigInt> tmp13;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_3, &phi_bb27_4, &phi_bb27_5, &phi_bb27_7);
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb27_7) }, &label14);
        ca_.Goto(&block30, phi_bb27_3, phi_bb27_4, phi_bb27_5, phi_bb27_7);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block31, phi_bb27_3, phi_bb27_4, phi_bb27_5, phi_bb27_7);
        }
    }

    TNode<Object> phi_bb26_3;
    TNode<Object> phi_bb26_4;
    TNode<Object> phi_bb26_5;
    TNode<Object> phi_bb26_7;
    TNode<Float64T> tmp15;
    TNode<Float64T> tmp16;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_3, &phi_bb26_4, &phi_bb26_5, &phi_bb26_7);
        tmp15 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp1 });
        tmp16 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp7 });
        ca_.Goto(&block2, phi_bb26_3, phi_bb26_4, tmp15, tmp16);
    }

    TNode<Object> phi_bb31_3;
    TNode<Object> phi_bb31_4;
    TNode<Object> phi_bb31_5;
    TNode<Object> phi_bb31_7;
    TNode<String> tmp17;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_3, &phi_bb31_4, &phi_bb31_5, &phi_bb31_7);
        compiler::CodeAssemblerLabel label18(&ca_);
        tmp17 = Cast_String_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb31_7) }, &label18);
        ca_.Goto(&block34, phi_bb31_3, phi_bb31_4, phi_bb31_5, phi_bb31_7);
        if (label18.is_used()) {
            ca_.Bind(&label18);
            ca_.Goto(&block35, phi_bb31_3, phi_bb31_4, phi_bb31_5, phi_bb31_7);
        }
    }

    TNode<Object> phi_bb30_3;
    TNode<Object> phi_bb30_4;
    TNode<Object> phi_bb30_5;
    TNode<Object> phi_bb30_7;
    if (block30.is_used()) {
        ca_.Bind(&block30, &phi_bb30_3, &phi_bb30_4, &phi_bb30_5, &phi_bb30_7);
        ca_.Goto(&block4, phi_bb30_3, phi_bb30_4, tmp1, tmp13);
    }

    TNode<Object> phi_bb35_3;
    TNode<Object> phi_bb35_4;
    TNode<Object> phi_bb35_5;
    TNode<Object> phi_bb35_7;
    TNode<Object> tmp19;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_3, &phi_bb35_4, &phi_bb35_5, &phi_bb35_7);
        tmp19 = ToNumericOrPrimitive_0(state_, TNode<Context> { parameter0 }, TNode<Object> { phi_bb35_4 });
        ca_.Goto(&block11, phi_bb35_3, tmp19);
    }

    TNode<Object> phi_bb34_3;
    TNode<Object> phi_bb34_4;
    TNode<Object> phi_bb34_5;
    TNode<Object> phi_bb34_7;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_3, &phi_bb34_4, &phi_bb34_5, &phi_bb34_7);
        ca_.Goto(&block8, phi_bb34_3, phi_bb34_4, tmp1, tmp17);
    }

    TNode<Object> phi_bb39_3;
    TNode<Object> phi_bb39_4;
    TNode<Object> phi_bb39_5;
    TNode<BigInt> tmp20;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_3, &phi_bb39_4, &phi_bb39_5);
        compiler::CodeAssemblerLabel label21(&ca_);
        tmp20 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb39_5) }, &label21);
        ca_.Goto(&block58, phi_bb39_3, phi_bb39_4, phi_bb39_5);
        if (label21.is_used()) {
            ca_.Bind(&label21);
            ca_.Goto(&block59, phi_bb39_3, phi_bb39_4, phi_bb39_5);
        }
    }

    TNode<Object> phi_bb38_3;
    TNode<Object> phi_bb38_4;
    TNode<Object> phi_bb38_5;
    TNode<Smi> tmp22;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_3, &phi_bb38_4, &phi_bb38_5);
        compiler::CodeAssemblerLabel label23(&ca_);
        tmp22 = Cast_Smi_0(state_, TNode<Object> { phi_bb38_4 }, &label23);
        ca_.Goto(&block42, phi_bb38_3, phi_bb38_4, phi_bb38_5, phi_bb38_4, phi_bb38_4);
        if (label23.is_used()) {
            ca_.Bind(&label23);
            ca_.Goto(&block43, phi_bb38_3, phi_bb38_4, phi_bb38_5, phi_bb38_4, phi_bb38_4);
        }
    }

    TNode<Object> phi_bb43_3;
    TNode<Object> phi_bb43_4;
    TNode<Object> phi_bb43_5;
    TNode<Object> phi_bb43_7;
    TNode<Object> phi_bb43_8;
    TNode<HeapNumber> tmp24;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_3, &phi_bb43_4, &phi_bb43_5, &phi_bb43_7, &phi_bb43_8);
        compiler::CodeAssemblerLabel label25(&ca_);
        tmp24 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb43_7) }, &label25);
        ca_.Goto(&block46, phi_bb43_3, phi_bb43_4, phi_bb43_5, phi_bb43_7);
        if (label25.is_used()) {
            ca_.Bind(&label25);
            ca_.Goto(&block47, phi_bb43_3, phi_bb43_4, phi_bb43_5, phi_bb43_7);
        }
    }

    TNode<Object> phi_bb42_3;
    TNode<Object> phi_bb42_4;
    TNode<Object> phi_bb42_5;
    TNode<Object> phi_bb42_7;
    TNode<Object> phi_bb42_8;
    TNode<Float64T> tmp26;
    TNode<Float64T> tmp27;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_3, &phi_bb42_4, &phi_bb42_5, &phi_bb42_7, &phi_bb42_8);
        tmp26 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp3 });
        tmp27 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp22 });
        ca_.Goto(&block2, phi_bb42_3, phi_bb42_4, tmp26, tmp27);
    }

    TNode<Object> phi_bb47_3;
    TNode<Object> phi_bb47_4;
    TNode<Object> phi_bb47_5;
    TNode<Object> phi_bb47_7;
    TNode<BigInt> tmp28;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_3, &phi_bb47_4, &phi_bb47_5, &phi_bb47_7);
        compiler::CodeAssemblerLabel label29(&ca_);
        tmp28 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb47_7) }, &label29);
        ca_.Goto(&block50, phi_bb47_3, phi_bb47_4, phi_bb47_5, phi_bb47_7);
        if (label29.is_used()) {
            ca_.Bind(&label29);
            ca_.Goto(&block51, phi_bb47_3, phi_bb47_4, phi_bb47_5, phi_bb47_7);
        }
    }

    TNode<Object> phi_bb46_3;
    TNode<Object> phi_bb46_4;
    TNode<Object> phi_bb46_5;
    TNode<Object> phi_bb46_7;
    TNode<Float64T> tmp30;
    TNode<Float64T> tmp31;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_3, &phi_bb46_4, &phi_bb46_5, &phi_bb46_7);
        tmp30 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp3 });
        tmp31 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp24 });
        ca_.Goto(&block2, phi_bb46_3, phi_bb46_4, tmp30, tmp31);
    }

    TNode<Object> phi_bb51_3;
    TNode<Object> phi_bb51_4;
    TNode<Object> phi_bb51_5;
    TNode<Object> phi_bb51_7;
    TNode<String> tmp32;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_3, &phi_bb51_4, &phi_bb51_5, &phi_bb51_7);
        compiler::CodeAssemblerLabel label33(&ca_);
        tmp32 = Cast_String_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb51_7) }, &label33);
        ca_.Goto(&block54, phi_bb51_3, phi_bb51_4, phi_bb51_5, phi_bb51_7);
        if (label33.is_used()) {
            ca_.Bind(&label33);
            ca_.Goto(&block55, phi_bb51_3, phi_bb51_4, phi_bb51_5, phi_bb51_7);
        }
    }

    TNode<Object> phi_bb50_3;
    TNode<Object> phi_bb50_4;
    TNode<Object> phi_bb50_5;
    TNode<Object> phi_bb50_7;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_3, &phi_bb50_4, &phi_bb50_5, &phi_bb50_7);
        ca_.Goto(&block4, phi_bb50_3, phi_bb50_4, tmp3, tmp28);
    }

    TNode<Object> phi_bb55_3;
    TNode<Object> phi_bb55_4;
    TNode<Object> phi_bb55_5;
    TNode<Object> phi_bb55_7;
    TNode<Object> tmp34;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_3, &phi_bb55_4, &phi_bb55_5, &phi_bb55_7);
        tmp34 = ToNumericOrPrimitive_0(state_, TNode<Context> { parameter0 }, TNode<Object> { phi_bb55_4 });
        ca_.Goto(&block11, phi_bb55_3, tmp34);
    }

    TNode<Object> phi_bb54_3;
    TNode<Object> phi_bb54_4;
    TNode<Object> phi_bb54_5;
    TNode<Object> phi_bb54_7;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_3, &phi_bb54_4, &phi_bb54_5, &phi_bb54_7);
        ca_.Goto(&block8, phi_bb54_3, phi_bb54_4, tmp3, tmp32);
    }

    TNode<Object> phi_bb59_3;
    TNode<Object> phi_bb59_4;
    TNode<Object> phi_bb59_5;
    TNode<String> tmp35;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_3, &phi_bb59_4, &phi_bb59_5);
        compiler::CodeAssemblerLabel label36(&ca_);
        tmp35 = Cast_String_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb59_5) }, &label36);
        ca_.Goto(&block70, phi_bb59_3, phi_bb59_4, phi_bb59_5);
        if (label36.is_used()) {
            ca_.Bind(&label36);
            ca_.Goto(&block71, phi_bb59_3, phi_bb59_4, phi_bb59_5);
        }
    }

    TNode<Object> phi_bb58_3;
    TNode<Object> phi_bb58_4;
    TNode<Object> phi_bb58_5;
    TNode<Numeric> tmp37;
    if (block58.is_used()) {
        ca_.Bind(&block58, &phi_bb58_3, &phi_bb58_4, &phi_bb58_5);
        compiler::CodeAssemblerLabel label38(&ca_);
        tmp37 = Cast_Numeric_0(state_, TNode<Object> { phi_bb58_4 }, &label38);
        ca_.Goto(&block62, phi_bb58_3, phi_bb58_4, phi_bb58_5, phi_bb58_4, phi_bb58_4);
        if (label38.is_used()) {
            ca_.Bind(&label38);
            ca_.Goto(&block63, phi_bb58_3, phi_bb58_4, phi_bb58_5, phi_bb58_4, phi_bb58_4);
        }
    }

    TNode<Object> phi_bb63_3;
    TNode<Object> phi_bb63_4;
    TNode<Object> phi_bb63_5;
    TNode<Object> phi_bb63_7;
    TNode<Object> phi_bb63_8;
    TNode<String> tmp39;
    if (block63.is_used()) {
        ca_.Bind(&block63, &phi_bb63_3, &phi_bb63_4, &phi_bb63_5, &phi_bb63_7, &phi_bb63_8);
        compiler::CodeAssemblerLabel label40(&ca_);
        tmp39 = Cast_String_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb63_7) }, &label40);
        ca_.Goto(&block66, phi_bb63_3, phi_bb63_4, phi_bb63_5, phi_bb63_7);
        if (label40.is_used()) {
            ca_.Bind(&label40);
            ca_.Goto(&block67, phi_bb63_3, phi_bb63_4, phi_bb63_5, phi_bb63_7);
        }
    }

    TNode<Object> phi_bb62_3;
    TNode<Object> phi_bb62_4;
    TNode<Object> phi_bb62_5;
    TNode<Object> phi_bb62_7;
    TNode<Object> phi_bb62_8;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_3, &phi_bb62_4, &phi_bb62_5, &phi_bb62_7, &phi_bb62_8);
        ca_.Goto(&block4, phi_bb62_3, phi_bb62_4, tmp20, tmp37);
    }

    TNode<Object> phi_bb67_3;
    TNode<Object> phi_bb67_4;
    TNode<Object> phi_bb67_5;
    TNode<Object> phi_bb67_7;
    TNode<Object> tmp41;
    if (block67.is_used()) {
        ca_.Bind(&block67, &phi_bb67_3, &phi_bb67_4, &phi_bb67_5, &phi_bb67_7);
        tmp41 = ToNumericOrPrimitive_0(state_, TNode<Context> { parameter0 }, TNode<Object> { phi_bb67_4 });
        ca_.Goto(&block11, phi_bb67_3, tmp41);
    }

    TNode<Object> phi_bb66_3;
    TNode<Object> phi_bb66_4;
    TNode<Object> phi_bb66_5;
    TNode<Object> phi_bb66_7;
    if (block66.is_used()) {
        ca_.Bind(&block66, &phi_bb66_3, &phi_bb66_4, &phi_bb66_5, &phi_bb66_7);
        ca_.Goto(&block8, phi_bb66_3, phi_bb66_4, tmp20, tmp39);
    }

    TNode<Object> phi_bb71_3;
    TNode<Object> phi_bb71_4;
    TNode<Object> phi_bb71_5;
    TNode<JSReceiver> tmp42;
    if (block71.is_used()) {
        ca_.Bind(&block71, &phi_bb71_3, &phi_bb71_4, &phi_bb71_5);
        compiler::CodeAssemblerLabel label43(&ca_);
        tmp42 = Cast_JSReceiver_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb71_5) }, &label43);
        ca_.Goto(&block74, phi_bb71_3, phi_bb71_4, phi_bb71_5);
        if (label43.is_used()) {
            ca_.Bind(&label43);
            ca_.Goto(&block75, phi_bb71_3, phi_bb71_4, phi_bb71_5);
        }
    }

    TNode<Object> phi_bb70_3;
    TNode<Object> phi_bb70_4;
    TNode<Object> phi_bb70_5;
    if (block70.is_used()) {
        ca_.Bind(&block70, &phi_bb70_3, &phi_bb70_4, &phi_bb70_5);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kStringAddConvertRight, parameter0, tmp35, phi_bb70_4);
    }

    TNode<Object> phi_bb75_3;
    TNode<Object> phi_bb75_4;
    TNode<Object> phi_bb75_5;
    TNode<String> tmp44;
    if (block75.is_used()) {
        ca_.Bind(&block75, &phi_bb75_3, &phi_bb75_4, &phi_bb75_5);
        compiler::CodeAssemblerLabel label45(&ca_);
        tmp44 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { phi_bb75_4 }, &label45);
        ca_.Goto(&block78, phi_bb75_3, phi_bb75_4, phi_bb75_5, phi_bb75_4, phi_bb75_4);
        if (label45.is_used()) {
            ca_.Bind(&label45);
            ca_.Goto(&block79, phi_bb75_3, phi_bb75_4, phi_bb75_5, phi_bb75_4, phi_bb75_4);
        }
    }

    TNode<Object> phi_bb74_3;
    TNode<Object> phi_bb74_4;
    TNode<Object> phi_bb74_5;
    TNode<Object> tmp46;
    if (block74.is_used()) {
        ca_.Bind(&block74, &phi_bb74_3, &phi_bb74_4, &phi_bb74_5);
        tmp46 = ToPrimitiveDefault_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp42 });
        ca_.Goto(&block11, tmp46, phi_bb74_4);
    }

    TNode<Object> phi_bb79_3;
    TNode<Object> phi_bb79_4;
    TNode<Object> phi_bb79_5;
    TNode<Object> phi_bb79_7;
    TNode<Object> phi_bb79_8;
    TNode<JSReceiver> tmp47;
    if (block79.is_used()) {
        ca_.Bind(&block79, &phi_bb79_3, &phi_bb79_4, &phi_bb79_5, &phi_bb79_7, &phi_bb79_8);
        compiler::CodeAssemblerLabel label48(&ca_);
        tmp47 = Cast_JSReceiver_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(phi_bb79_7) }, &label48);
        ca_.Goto(&block82, phi_bb79_3, phi_bb79_4, phi_bb79_5, phi_bb79_7);
        if (label48.is_used()) {
            ca_.Bind(&label48);
            ca_.Goto(&block83, phi_bb79_3, phi_bb79_4, phi_bb79_5, phi_bb79_7);
        }
    }

    TNode<Object> phi_bb78_3;
    TNode<Object> phi_bb78_4;
    TNode<Object> phi_bb78_5;
    TNode<Object> phi_bb78_7;
    TNode<Object> phi_bb78_8;
    if (block78.is_used()) {
        ca_.Bind(&block78, &phi_bb78_3, &phi_bb78_4, &phi_bb78_5, &phi_bb78_7, &phi_bb78_8);
        ca_.Goto(&block8, phi_bb78_3, phi_bb78_4, phi_bb78_3, tmp44);
    }

    TNode<Object> phi_bb83_3;
    TNode<Object> phi_bb83_4;
    TNode<Object> phi_bb83_5;
    TNode<Object> phi_bb83_7;
    TNode<Numeric> tmp49;
    if (block83.is_used()) {
        ca_.Bind(&block83, &phi_bb83_3, &phi_bb83_4, &phi_bb83_5, &phi_bb83_7);
        tmp49 = ca_.CallBuiltin<Numeric>(Builtin::kNonNumberToNumeric, parameter0, phi_bb83_3);
        ca_.Goto(&block11, tmp49, phi_bb83_4);
    }

    TNode<Object> phi_bb82_3;
    TNode<Object> phi_bb82_4;
    TNode<Object> phi_bb82_5;
    TNode<Object> phi_bb82_7;
    TNode<Object> tmp50;
    if (block82.is_used()) {
        ca_.Bind(&block82, &phi_bb82_3, &phi_bb82_4, &phi_bb82_5, &phi_bb82_7);
        tmp50 = ToPrimitiveDefault_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp47 });
        ca_.Goto(&block11, phi_bb82_3, tmp50);
    }

    TNode<Object> phi_bb10_3;
    TNode<Object> phi_bb10_4;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_3, &phi_bb10_4);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Object> phi_bb8_3;
    TNode<Object> phi_bb8_4;
    TNode<Object> phi_bb8_5;
    TNode<String> phi_bb8_6;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_3, &phi_bb8_4, &phi_bb8_5, &phi_bb8_6);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kStringAddConvertLeft, parameter0, phi_bb8_5, phi_bb8_6);
    }

    TNode<Object> phi_bb4_3;
    TNode<Object> phi_bb4_4;
    TNode<Numeric> phi_bb4_5;
    TNode<Numeric> phi_bb4_6;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4, &phi_bb4_5, &phi_bb4_6);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kBigIntAdd, parameter0, phi_bb4_5, phi_bb4_6);
    }

    TNode<Object> phi_bb2_3;
    TNode<Object> phi_bb2_4;
    TNode<Float64T> phi_bb2_5;
    TNode<Float64T> phi_bb2_6;
    TNode<Float64T> tmp51;
    TNode<HeapNumber> tmp52;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_3, &phi_bb2_4, &phi_bb2_5, &phi_bb2_6);
        tmp51 = CodeStubAssembler(state_).Float64Add(TNode<Float64T> { phi_bb2_5 }, TNode<Float64T> { phi_bb2_6 });
        tmp52 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp51 });
        CodeStubAssembler(state_).Return(tmp52);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=499&c=1
void UnaryOp1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_Number,
    compiler::TypedCodeAssemblerVariable<Number>* label_Number_parameter_0, compiler::CodeAssemblerLabel* label_BigInt,
    compiler::TypedCodeAssemblerVariable<BigInt>* label_BigInt_parameter_0)
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
    compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Goto(&block5, p_value);
    }

    TNode<Object> phi_bb5_2;
    TNode<BoolT> tmp0;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_2);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp0, &block3, std::vector<compiler::Node*> { phi_bb5_2 }, &block4, std::vector<compiler::Node*> { phi_bb5_2 });
    }

    TNode<Object> phi_bb3_2;
    TNode<Number> tmp1;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_2);
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_Number_0(state_, TNode<Object> { phi_bb3_2 }, &label2);
        ca_.Goto(&block8, phi_bb3_2, phi_bb3_2, phi_bb3_2);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block9, phi_bb3_2, phi_bb3_2, phi_bb3_2);
        }
    }

    TNode<Object> phi_bb9_2;
    TNode<Object> phi_bb9_3;
    TNode<Object> phi_bb9_4;
    TNode<BigInt> tmp3;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_2, &phi_bb9_3, &phi_bb9_4);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb9_3) }, &label4);
        ca_.Goto(&block12, phi_bb9_2, phi_bb9_3);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block13, phi_bb9_2, phi_bb9_3);
        }
    }

    TNode<Object> phi_bb8_2;
    TNode<Object> phi_bb8_3;
    TNode<Object> phi_bb8_4;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_2, &phi_bb8_3, &phi_bb8_4);
        *label_Number_parameter_0 = tmp1;
        ca_.Goto(label_Number);
    }

    TNode<Object> phi_bb13_2;
    TNode<Object> phi_bb13_3;
    TNode<Numeric> tmp5;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_3);
        tmp5 = ca_.CallBuiltin<Numeric>(Builtin::kNonNumberToNumeric, p_context, phi_bb13_2);
        ca_.Goto(&block5, tmp5);
    }

    TNode<Object> phi_bb12_2;
    TNode<Object> phi_bb12_3;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_2, &phi_bb12_3);
        *label_BigInt_parameter_0 = tmp3;
        ca_.Goto(label_BigInt);
    }

    TNode<Object> phi_bb4_2;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_2);
        CodeStubAssembler(state_).Unreachable();
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=519&c=1
void UnaryOp2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_Smi,
    compiler::TypedCodeAssemblerVariable<Smi>* label_Smi_parameter_0, compiler::CodeAssemblerLabel* label_HeapNumber,
    compiler::TypedCodeAssemblerVariable<HeapNumber>* label_HeapNumber_parameter_0, compiler::CodeAssemblerLabel* label_BigInt,
    compiler::TypedCodeAssemblerVariable<BigInt>* label_BigInt_parameter_0)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Goto(&block6, p_value);
    }

    TNode<Object> phi_bb6_2;
    TNode<BoolT> tmp0;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_2);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp0, &block4, std::vector<compiler::Node*> { phi_bb6_2 }, &block5, std::vector<compiler::Node*> { phi_bb6_2 });
    }

    TNode<Object> phi_bb4_2;
    TNode<Smi> tmp1;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_2);
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_Smi_0(state_, TNode<Object> { phi_bb4_2 }, &label2);
        ca_.Goto(&block9, phi_bb4_2, phi_bb4_2, phi_bb4_2);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block10, phi_bb4_2, phi_bb4_2, phi_bb4_2);
        }
    }

    TNode<Object> phi_bb10_2;
    TNode<Object> phi_bb10_3;
    TNode<Object> phi_bb10_4;
    TNode<HeapNumber> tmp3;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_2, &phi_bb10_3, &phi_bb10_4);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb10_3) }, &label4);
        ca_.Goto(&block13, phi_bb10_2, phi_bb10_3);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block14, phi_bb10_2, phi_bb10_3);
        }
    }

    TNode<Object> phi_bb9_2;
    TNode<Object> phi_bb9_3;
    TNode<Object> phi_bb9_4;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_2, &phi_bb9_3, &phi_bb9_4);
        *label_Smi_parameter_0 = tmp1;
        ca_.Goto(label_Smi);
    }

    TNode<Object> phi_bb14_2;
    TNode<Object> phi_bb14_3;
    TNode<BigInt> tmp5;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_2, &phi_bb14_3);
        compiler::CodeAssemblerLabel label6(&ca_);
        tmp5 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb14_3) }, &label6);
        ca_.Goto(&block17, phi_bb14_2, phi_bb14_3);
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block18, phi_bb14_2, phi_bb14_3);
        }
    }

    TNode<Object> phi_bb13_2;
    TNode<Object> phi_bb13_3;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_3);
        *label_HeapNumber_parameter_0 = tmp3;
        ca_.Goto(label_HeapNumber);
    }

    TNode<Object> phi_bb18_2;
    TNode<Object> phi_bb18_3;
    TNode<Numeric> tmp7;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_2, &phi_bb18_3);
        tmp7 = ca_.CallBuiltin<Numeric>(Builtin::kNonNumberToNumeric, p_context, phi_bb18_2);
        ca_.Goto(&block6, tmp7);
    }

    TNode<Object> phi_bb17_2;
    TNode<Object> phi_bb17_3;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_2, &phi_bb17_3);
        *label_BigInt_parameter_0 = tmp5;
        ca_.Goto(label_BigInt);
    }

    TNode<Object> phi_bb5_2;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_2);
        CodeStubAssembler(state_).Unreachable();
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=542&c=1
void BinaryOp1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_leftVal, TNode<Object> p_rightVal,
    compiler::CodeAssemblerLabel* label_Number, compiler::TypedCodeAssemblerVariable<Number>* label_Number_parameter_0,
    compiler::TypedCodeAssemblerVariable<Number>* label_Number_parameter_1, compiler::CodeAssemblerLabel* label_AtLeastOneBigInt,
    compiler::TypedCodeAssemblerVariable<Numeric>* label_AtLeastOneBigInt_parameter_0,
    compiler::TypedCodeAssemblerVariable<Numeric>* label_AtLeastOneBigInt_parameter_1)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Numeric, Numeric> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Goto(&block5, p_leftVal, p_rightVal);
    }

    TNode<Object> phi_bb5_3;
    TNode<Object> phi_bb5_4;
    TNode<BoolT> tmp0;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_3, &phi_bb5_4);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp0, &block3, std::vector<compiler::Node*> { phi_bb5_3, phi_bb5_4 }, &block4, std::vector<compiler::Node*> { phi_bb5_3, phi_bb5_4 });
    }

    TNode<Object> phi_bb3_3;
    TNode<Object> phi_bb3_4;
    TNode<Number> tmp1;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_3, &phi_bb3_4);
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_Number_0(state_, TNode<Object> { phi_bb3_3 }, &label2);
        ca_.Goto(&block10, phi_bb3_3, phi_bb3_4, phi_bb3_3, phi_bb3_3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block11, phi_bb3_3, phi_bb3_4, phi_bb3_3, phi_bb3_3);
        }
    }

    TNode<Object> phi_bb11_3;
    TNode<Object> phi_bb11_4;
    TNode<Object> phi_bb11_5;
    TNode<Object> phi_bb11_6;
    TNode<BigInt> tmp3;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_3, &phi_bb11_4, &phi_bb11_5, &phi_bb11_6);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb11_5) }, &label4);
        ca_.Goto(&block22, phi_bb11_3, phi_bb11_4, phi_bb11_5);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block23, phi_bb11_3, phi_bb11_4, phi_bb11_5);
        }
    }

    TNode<Object> phi_bb10_3;
    TNode<Object> phi_bb10_4;
    TNode<Object> phi_bb10_5;
    TNode<Object> phi_bb10_6;
    TNode<Number> tmp5;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_3, &phi_bb10_4, &phi_bb10_5, &phi_bb10_6);
        compiler::CodeAssemblerLabel label6(&ca_);
        tmp5 = Cast_Number_0(state_, TNode<Object> { phi_bb10_4 }, &label6);
        ca_.Goto(&block14, phi_bb10_3, phi_bb10_4, phi_bb10_5, phi_bb10_4, phi_bb10_4);
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block15, phi_bb10_3, phi_bb10_4, phi_bb10_5, phi_bb10_4, phi_bb10_4);
        }
    }

    TNode<Object> phi_bb15_3;
    TNode<Object> phi_bb15_4;
    TNode<Object> phi_bb15_5;
    TNode<Object> phi_bb15_7;
    TNode<Object> phi_bb15_8;
    TNode<BigInt> tmp7;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_3, &phi_bb15_4, &phi_bb15_5, &phi_bb15_7, &phi_bb15_8);
        compiler::CodeAssemblerLabel label8(&ca_);
        tmp7 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb15_7) }, &label8);
        ca_.Goto(&block18, phi_bb15_3, phi_bb15_4, phi_bb15_5, phi_bb15_7);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block19, phi_bb15_3, phi_bb15_4, phi_bb15_5, phi_bb15_7);
        }
    }

    TNode<Object> phi_bb14_3;
    TNode<Object> phi_bb14_4;
    TNode<Object> phi_bb14_5;
    TNode<Object> phi_bb14_7;
    TNode<Object> phi_bb14_8;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_3, &phi_bb14_4, &phi_bb14_5, &phi_bb14_7, &phi_bb14_8);
        *label_Number_parameter_1 = tmp5;
        *label_Number_parameter_0 = tmp1;
        ca_.Goto(label_Number);
    }

    TNode<Object> phi_bb19_3;
    TNode<Object> phi_bb19_4;
    TNode<Object> phi_bb19_5;
    TNode<Object> phi_bb19_7;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_3, &phi_bb19_4, &phi_bb19_5, &phi_bb19_7);
        ca_.Goto(&block7, phi_bb19_3, phi_bb19_4);
    }

    TNode<Object> phi_bb18_3;
    TNode<Object> phi_bb18_4;
    TNode<Object> phi_bb18_5;
    TNode<Object> phi_bb18_7;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_3, &phi_bb18_4, &phi_bb18_5, &phi_bb18_7);
        ca_.Goto(&block2, tmp1, tmp7);
    }

    TNode<Object> phi_bb23_3;
    TNode<Object> phi_bb23_4;
    TNode<Object> phi_bb23_5;
    TNode<Numeric> tmp9;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_3, &phi_bb23_4, &phi_bb23_5);
        tmp9 = ca_.CallBuiltin<Numeric>(Builtin::kNonNumberToNumeric, p_context, phi_bb23_3);
        ca_.Goto(&block6, tmp9, phi_bb23_4);
    }

    TNode<Object> phi_bb22_3;
    TNode<Object> phi_bb22_4;
    TNode<Object> phi_bb22_5;
    TNode<Numeric> tmp10;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_3, &phi_bb22_4, &phi_bb22_5);
        compiler::CodeAssemblerLabel label11(&ca_);
        tmp10 = Cast_Numeric_0(state_, TNode<Object> { phi_bb22_4 }, &label11);
        ca_.Goto(&block26, phi_bb22_3, phi_bb22_4, phi_bb22_5, phi_bb22_4, phi_bb22_4);
        if (label11.is_used()) {
            ca_.Bind(&label11);
            ca_.Goto(&block27, phi_bb22_3, phi_bb22_4, phi_bb22_5, phi_bb22_4, phi_bb22_4);
        }
    }

    TNode<Object> phi_bb27_3;
    TNode<Object> phi_bb27_4;
    TNode<Object> phi_bb27_5;
    TNode<Object> phi_bb27_7;
    TNode<Object> phi_bb27_8;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_3, &phi_bb27_4, &phi_bb27_5, &phi_bb27_7, &phi_bb27_8);
        ca_.Goto(&block7, phi_bb27_3, phi_bb27_4);
    }

    TNode<Object> phi_bb26_3;
    TNode<Object> phi_bb26_4;
    TNode<Object> phi_bb26_5;
    TNode<Object> phi_bb26_7;
    TNode<Object> phi_bb26_8;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_3, &phi_bb26_4, &phi_bb26_5, &phi_bb26_7, &phi_bb26_8);
        ca_.Goto(&block2, tmp3, tmp10);
    }

    TNode<Object> phi_bb7_3;
    TNode<Object> phi_bb7_4;
    TNode<Numeric> tmp12;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_3, &phi_bb7_4);
        tmp12 = ca_.CallBuiltin<Numeric>(Builtin::kNonNumberToNumeric, p_context, phi_bb7_4);
        ca_.Goto(&block6, phi_bb7_3, tmp12);
    }

    TNode<Object> phi_bb6_3;
    TNode<Object> phi_bb6_4;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_3, &phi_bb6_4);
        ca_.Goto(&block5, phi_bb6_3, phi_bb6_4);
    }

    TNode<Object> phi_bb4_3;
    TNode<Object> phi_bb4_4;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Numeric> phi_bb2_0;
    TNode<Numeric> phi_bb2_1;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_0, &phi_bb2_1);
        *label_AtLeastOneBigInt_parameter_1 = phi_bb2_1;
        *label_AtLeastOneBigInt_parameter_0 = phi_bb2_0;
        ca_.Goto(label_AtLeastOneBigInt);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=585&c=1
void BinaryOp2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_leftVal, TNode<Object> p_rightVal,
    compiler::CodeAssemblerLabel* label_Smis, compiler::TypedCodeAssemblerVariable<Smi>* label_Smis_parameter_0,
    compiler::TypedCodeAssemblerVariable<Smi>* label_Smis_parameter_1, compiler::CodeAssemblerLabel* label_Float64s,
    compiler::TypedCodeAssemblerVariable<Float64T>* label_Float64s_parameter_0, compiler::TypedCodeAssemblerVariable<Float64T>* label_Float64s_parameter_1,
    compiler::CodeAssemblerLabel* label_AtLeastOneBigInt, compiler::TypedCodeAssemblerVariable<Numeric>* label_AtLeastOneBigInt_parameter_0,
    compiler::TypedCodeAssemblerVariable<Numeric>* label_AtLeastOneBigInt_parameter_1)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object, Object> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, Float64T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Numeric, Numeric> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Goto(&block6, p_leftVal, p_rightVal);
    }

    TNode<Object> phi_bb6_3;
    TNode<Object> phi_bb6_4;
    TNode<BoolT> tmp0;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_3, &phi_bb6_4);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp0, &block4, std::vector<compiler::Node*> { phi_bb6_3, phi_bb6_4 }, &block5, std::vector<compiler::Node*> { phi_bb6_3, phi_bb6_4 });
    }

    TNode<Object> phi_bb4_3;
    TNode<Object> phi_bb4_4;
    TNode<Smi> tmp1;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_Smi_0(state_, TNode<Object> { phi_bb4_3 }, &label2);
        ca_.Goto(&block11, phi_bb4_3, phi_bb4_4, phi_bb4_3, phi_bb4_3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block12, phi_bb4_3, phi_bb4_4, phi_bb4_3, phi_bb4_3);
        }
    }

    TNode<Object> phi_bb12_3;
    TNode<Object> phi_bb12_4;
    TNode<Object> phi_bb12_5;
    TNode<Object> phi_bb12_6;
    TNode<HeapNumber> tmp3;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_3, &phi_bb12_4, &phi_bb12_5, &phi_bb12_6);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb12_5) }, &label4);
        ca_.Goto(&block27, phi_bb12_3, phi_bb12_4, phi_bb12_5);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block28, phi_bb12_3, phi_bb12_4, phi_bb12_5);
        }
    }

    TNode<Object> phi_bb11_3;
    TNode<Object> phi_bb11_4;
    TNode<Object> phi_bb11_5;
    TNode<Object> phi_bb11_6;
    TNode<Smi> tmp5;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_3, &phi_bb11_4, &phi_bb11_5, &phi_bb11_6);
        compiler::CodeAssemblerLabel label6(&ca_);
        tmp5 = Cast_Smi_0(state_, TNode<Object> { phi_bb11_4 }, &label6);
        ca_.Goto(&block15, phi_bb11_3, phi_bb11_4, phi_bb11_5, phi_bb11_4, phi_bb11_4);
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block16, phi_bb11_3, phi_bb11_4, phi_bb11_5, phi_bb11_4, phi_bb11_4);
        }
    }

    TNode<Object> phi_bb16_3;
    TNode<Object> phi_bb16_4;
    TNode<Object> phi_bb16_5;
    TNode<Object> phi_bb16_7;
    TNode<Object> phi_bb16_8;
    TNode<HeapNumber> tmp7;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_3, &phi_bb16_4, &phi_bb16_5, &phi_bb16_7, &phi_bb16_8);
        compiler::CodeAssemblerLabel label8(&ca_);
        tmp7 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb16_7) }, &label8);
        ca_.Goto(&block19, phi_bb16_3, phi_bb16_4, phi_bb16_5, phi_bb16_7);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block20, phi_bb16_3, phi_bb16_4, phi_bb16_5, phi_bb16_7);
        }
    }

    TNode<Object> phi_bb15_3;
    TNode<Object> phi_bb15_4;
    TNode<Object> phi_bb15_5;
    TNode<Object> phi_bb15_7;
    TNode<Object> phi_bb15_8;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_3, &phi_bb15_4, &phi_bb15_5, &phi_bb15_7, &phi_bb15_8);
        *label_Smis_parameter_1 = tmp5;
        *label_Smis_parameter_0 = tmp1;
        ca_.Goto(label_Smis);
    }

    TNode<Object> phi_bb20_3;
    TNode<Object> phi_bb20_4;
    TNode<Object> phi_bb20_5;
    TNode<Object> phi_bb20_7;
    TNode<BigInt> tmp9;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_3, &phi_bb20_4, &phi_bb20_5, &phi_bb20_7);
        compiler::CodeAssemblerLabel label10(&ca_);
        tmp9 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb20_7) }, &label10);
        ca_.Goto(&block23, phi_bb20_3, phi_bb20_4, phi_bb20_5, phi_bb20_7);
        if (label10.is_used()) {
            ca_.Bind(&label10);
            ca_.Goto(&block24, phi_bb20_3, phi_bb20_4, phi_bb20_5, phi_bb20_7);
        }
    }

    TNode<Object> phi_bb19_3;
    TNode<Object> phi_bb19_4;
    TNode<Object> phi_bb19_5;
    TNode<Object> phi_bb19_7;
    TNode<Float64T> tmp11;
    TNode<Float64T> tmp12;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_3, &phi_bb19_4, &phi_bb19_5, &phi_bb19_7);
        tmp11 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp1 });
        tmp12 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp7 });
        ca_.Goto(&block2, tmp11, tmp12);
    }

    TNode<Object> phi_bb24_3;
    TNode<Object> phi_bb24_4;
    TNode<Object> phi_bb24_5;
    TNode<Object> phi_bb24_7;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_3, &phi_bb24_4, &phi_bb24_5, &phi_bb24_7);
        ca_.Goto(&block8, phi_bb24_3, phi_bb24_4);
    }

    TNode<Object> phi_bb23_3;
    TNode<Object> phi_bb23_4;
    TNode<Object> phi_bb23_5;
    TNode<Object> phi_bb23_7;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_3, &phi_bb23_4, &phi_bb23_5, &phi_bb23_7);
        ca_.Goto(&block3, tmp1, tmp9);
    }

    TNode<Object> phi_bb28_3;
    TNode<Object> phi_bb28_4;
    TNode<Object> phi_bb28_5;
    TNode<BigInt> tmp13;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_3, &phi_bb28_4, &phi_bb28_5);
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb28_5) }, &label14);
        ca_.Goto(&block43, phi_bb28_3, phi_bb28_4, phi_bb28_5);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block44, phi_bb28_3, phi_bb28_4, phi_bb28_5);
        }
    }

    TNode<Object> phi_bb27_3;
    TNode<Object> phi_bb27_4;
    TNode<Object> phi_bb27_5;
    TNode<Smi> tmp15;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_3, &phi_bb27_4, &phi_bb27_5);
        compiler::CodeAssemblerLabel label16(&ca_);
        tmp15 = Cast_Smi_0(state_, TNode<Object> { phi_bb27_4 }, &label16);
        ca_.Goto(&block31, phi_bb27_3, phi_bb27_4, phi_bb27_5, phi_bb27_4, phi_bb27_4);
        if (label16.is_used()) {
            ca_.Bind(&label16);
            ca_.Goto(&block32, phi_bb27_3, phi_bb27_4, phi_bb27_5, phi_bb27_4, phi_bb27_4);
        }
    }

    TNode<Object> phi_bb32_3;
    TNode<Object> phi_bb32_4;
    TNode<Object> phi_bb32_5;
    TNode<Object> phi_bb32_7;
    TNode<Object> phi_bb32_8;
    TNode<HeapNumber> tmp17;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_3, &phi_bb32_4, &phi_bb32_5, &phi_bb32_7, &phi_bb32_8);
        compiler::CodeAssemblerLabel label18(&ca_);
        tmp17 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb32_7) }, &label18);
        ca_.Goto(&block35, phi_bb32_3, phi_bb32_4, phi_bb32_5, phi_bb32_7);
        if (label18.is_used()) {
            ca_.Bind(&label18);
            ca_.Goto(&block36, phi_bb32_3, phi_bb32_4, phi_bb32_5, phi_bb32_7);
        }
    }

    TNode<Object> phi_bb31_3;
    TNode<Object> phi_bb31_4;
    TNode<Object> phi_bb31_5;
    TNode<Object> phi_bb31_7;
    TNode<Object> phi_bb31_8;
    TNode<Float64T> tmp19;
    TNode<Float64T> tmp20;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_3, &phi_bb31_4, &phi_bb31_5, &phi_bb31_7, &phi_bb31_8);
        tmp19 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp3 });
        tmp20 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp15 });
        ca_.Goto(&block2, tmp19, tmp20);
    }

    TNode<Object> phi_bb36_3;
    TNode<Object> phi_bb36_4;
    TNode<Object> phi_bb36_5;
    TNode<Object> phi_bb36_7;
    TNode<BigInt> tmp21;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_3, &phi_bb36_4, &phi_bb36_5, &phi_bb36_7);
        compiler::CodeAssemblerLabel label22(&ca_);
        tmp21 = Cast_BigInt_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb36_7) }, &label22);
        ca_.Goto(&block39, phi_bb36_3, phi_bb36_4, phi_bb36_5, phi_bb36_7);
        if (label22.is_used()) {
            ca_.Bind(&label22);
            ca_.Goto(&block40, phi_bb36_3, phi_bb36_4, phi_bb36_5, phi_bb36_7);
        }
    }

    TNode<Object> phi_bb35_3;
    TNode<Object> phi_bb35_4;
    TNode<Object> phi_bb35_5;
    TNode<Object> phi_bb35_7;
    TNode<Float64T> tmp23;
    TNode<Float64T> tmp24;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_3, &phi_bb35_4, &phi_bb35_5, &phi_bb35_7);
        tmp23 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp3 });
        tmp24 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp17 });
        ca_.Goto(&block2, tmp23, tmp24);
    }

    TNode<Object> phi_bb40_3;
    TNode<Object> phi_bb40_4;
    TNode<Object> phi_bb40_5;
    TNode<Object> phi_bb40_7;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_3, &phi_bb40_4, &phi_bb40_5, &phi_bb40_7);
        ca_.Goto(&block8, phi_bb40_3, phi_bb40_4);
    }

    TNode<Object> phi_bb39_3;
    TNode<Object> phi_bb39_4;
    TNode<Object> phi_bb39_5;
    TNode<Object> phi_bb39_7;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_3, &phi_bb39_4, &phi_bb39_5, &phi_bb39_7);
        ca_.Goto(&block3, tmp3, tmp21);
    }

    TNode<Object> phi_bb44_3;
    TNode<Object> phi_bb44_4;
    TNode<Object> phi_bb44_5;
    TNode<Numeric> tmp25;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_3, &phi_bb44_4, &phi_bb44_5);
        tmp25 = ca_.CallBuiltin<Numeric>(Builtin::kNonNumberToNumeric, p_context, phi_bb44_3);
        ca_.Goto(&block7, tmp25, phi_bb44_4);
    }

    TNode<Object> phi_bb43_3;
    TNode<Object> phi_bb43_4;
    TNode<Object> phi_bb43_5;
    TNode<Numeric> tmp26;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_3, &phi_bb43_4, &phi_bb43_5);
        compiler::CodeAssemblerLabel label27(&ca_);
        tmp26 = Cast_Numeric_0(state_, TNode<Object> { phi_bb43_4 }, &label27);
        ca_.Goto(&block47, phi_bb43_3, phi_bb43_4, phi_bb43_5, phi_bb43_4, phi_bb43_4);
        if (label27.is_used()) {
            ca_.Bind(&label27);
            ca_.Goto(&block48, phi_bb43_3, phi_bb43_4, phi_bb43_5, phi_bb43_4, phi_bb43_4);
        }
    }

    TNode<Object> phi_bb48_3;
    TNode<Object> phi_bb48_4;
    TNode<Object> phi_bb48_5;
    TNode<Object> phi_bb48_7;
    TNode<Object> phi_bb48_8;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_3, &phi_bb48_4, &phi_bb48_5, &phi_bb48_7, &phi_bb48_8);
        ca_.Goto(&block8, phi_bb48_3, phi_bb48_4);
    }

    TNode<Object> phi_bb47_3;
    TNode<Object> phi_bb47_4;
    TNode<Object> phi_bb47_5;
    TNode<Object> phi_bb47_7;
    TNode<Object> phi_bb47_8;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_3, &phi_bb47_4, &phi_bb47_5, &phi_bb47_7, &phi_bb47_8);
        ca_.Goto(&block3, tmp13, tmp26);
    }

    TNode<Object> phi_bb8_3;
    TNode<Object> phi_bb8_4;
    TNode<Numeric> tmp28;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_3, &phi_bb8_4);
        tmp28 = ca_.CallBuiltin<Numeric>(Builtin::kNonNumberToNumeric, p_context, phi_bb8_4);
        ca_.Goto(&block7, phi_bb8_3, tmp28);
    }

    TNode<Object> phi_bb7_3;
    TNode<Object> phi_bb7_4;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_3, &phi_bb7_4);
        ca_.Goto(&block6, phi_bb7_3, phi_bb7_4);
    }

    TNode<Object> phi_bb5_3;
    TNode<Object> phi_bb5_4;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_3, &phi_bb5_4);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Float64T> phi_bb2_0;
    TNode<Float64T> phi_bb2_1;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_0, &phi_bb2_1);
        *label_Float64s_parameter_1 = phi_bb2_1;
        *label_Float64s_parameter_0 = phi_bb2_0;
        ca_.Goto(label_Float64s);
    }

    TNode<Numeric> phi_bb3_0;
    TNode<Numeric> phi_bb3_1;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_0, &phi_bb3_1);
        *label_AtLeastOneBigInt_parameter_1 = phi_bb3_1;
        *label_AtLeastOneBigInt_parameter_0 = phi_bb3_0;
        ca_.Goto(label_AtLeastOneBigInt);
    }
}

TF_BUILTIN(Subtract, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, Float64T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Smi> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp4(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp5(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp7(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp8(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        compiler::CodeAssemblerLabel label6(&ca_);
        BinaryOp2_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, &label0, &tmp1, &tmp2, &label3, &tmp4,
            &tmp5, &label6, &tmp7, &tmp8);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block7);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8);
        }
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block9);
        }
    }

    TNode<Smi> tmp9;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerLabel label10(&ca_);
        tmp9 = CodeStubAssembler(state_).TrySmiSub(TNode<Smi> { tmp1.value() }, TNode<Smi> { tmp2.value() }, &label10);
        ca_.Goto(&block12);
        if (label10.is_used()) {
            ca_.Bind(&label10);
            ca_.Goto(&block13);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block4, tmp4.value(), tmp5.value());
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kBigIntSubtract, parameter0, tmp7.value(), tmp8.value());
    }

    TNode<Float64T> tmp11;
    TNode<Float64T> tmp12;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp11 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp1.value() });
        tmp12 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp2.value() });
        ca_.Goto(&block4, tmp11, tmp12);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        CodeStubAssembler(state_).Return(tmp9);
    }

    TNode<Float64T> phi_bb4_3;
    TNode<Float64T> phi_bb4_4;
    TNode<Float64T> tmp13;
    TNode<HeapNumber> tmp14;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        tmp13 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T> { phi_bb4_3 }, TNode<Float64T> { phi_bb4_4 });
        tmp14 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp13 });
        CodeStubAssembler(state_).Return(tmp14);
    }
}

TF_BUILTIN(Multiply, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Smi> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp4(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp5(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp7(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp8(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        compiler::CodeAssemblerLabel label6(&ca_);
        BinaryOp2_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, &label0, &tmp1, &tmp2, &label3, &tmp4,
            &tmp5, &label6, &tmp7, &tmp8);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block7);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8);
        }
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block9);
        }
    }

    TNode<Number> tmp9;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp9 = CodeStubAssembler(state_).SmiMul(TNode<Smi> { tmp1.value() }, TNode<Smi> { tmp2.value() });
        CodeStubAssembler(state_).Return(tmp9);
    }

    TNode<Float64T> tmp10;
    TNode<HeapNumber> tmp11;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp10 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp4.value() }, TNode<Float64T> { tmp5.value() });
        tmp11 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp10 });
        CodeStubAssembler(state_).Return(tmp11);
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kBigIntMultiply, parameter0, tmp7.value(), tmp8.value());
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=680&c=1
TNode<Int32T> kMinimumDividend_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_,
            (CodeStubAssembler(state_).ConstexprInt32Equal(
                kSmiValueSize, (FromConstexpr_constexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull))))));
        ca_.Branch(tmp0, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp1;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp1 = FromConstexpr_int32_constexpr_int32_0(state_, kMinInt);
        ca_.Goto(&block3, tmp1);
    }

    TNode<Int32T> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp2 = FromConstexpr_int32_constexpr_int32_0(state_, kMinInt31);
        ca_.Goto(&block3, tmp2);
    }

    TNode<Int32T> phi_bb3_0;
    ca_.Bind(&block3, &phi_bb3_0);
    return TNode<Int32T> { phi_bb3_0 };
}

TF_BUILTIN(Divide, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, Float64T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Smi> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp4(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp5(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp7(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp8(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        compiler::CodeAssemblerLabel label6(&ca_);
        BinaryOp2_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, &label0, &tmp1, &tmp2, &label3, &tmp4,
            &tmp5, &label6, &tmp7, &tmp8);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block9);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block10);
        }
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block11);
        }
    }

    TNode<Smi> tmp9;
    TNode<BoolT> tmp10;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp9 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp10 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp2.value() }, TNode<Smi> { tmp9 });
        ca_.Branch(tmp10, &block12, std::vector<compiler::Node*> {}, &block13, std::vector<compiler::Node*> {});
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block4, tmp4.value(), tmp5.value());
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kBigIntDivide, parameter0, tmp7.value(), tmp8.value());
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block6);
    }

    TNode<Smi> tmp11;
    TNode<BoolT> tmp12;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp11 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp12 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp1.value() }, TNode<Smi> { tmp11 });
        ca_.Branch(tmp12, &block16, std::vector<compiler::Node*> {}, &block17, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp13;
    TNode<BoolT> tmp14;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp13 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp14 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi> { tmp2.value() }, TNode<Smi> { tmp13 });
        ca_.Goto(&block18, tmp14);
    }

    TNode<BoolT> tmp15;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp15 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block18, tmp15);
    }

    TNode<BoolT> phi_bb18_6;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_6);
        ca_.Branch(phi_bb18_6, &block14, std::vector<compiler::Node*> {}, &block15, std::vector<compiler::Node*> {});
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block6);
    }

    TNode<Int32T> tmp16;
    TNode<Int32T> tmp17;
    TNode<Int32T> tmp18;
    TNode<BoolT> tmp19;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp16 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp1.value() });
        tmp17 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp2.value() });
        tmp18 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
        tmp19 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { tmp17 }, TNode<Int32T> { tmp18 });
        ca_.Branch(tmp19, &block21, std::vector<compiler::Node*> {}, &block22, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp20;
    TNode<BoolT> tmp21;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp20 = kMinimumDividend_0(state_);
        tmp21 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { tmp16 }, TNode<Int32T> { tmp20 });
        ca_.Goto(&block23, tmp21);
    }

    TNode<BoolT> tmp22;
    if (block22.is_used()) {
        ca_.Bind(&block22);
        tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block23, tmp22);
    }

    TNode<BoolT> phi_bb23_8;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_8);
        ca_.Branch(phi_bb23_8, &block19, std::vector<compiler::Node*> {}, &block20, std::vector<compiler::Node*> {});
    }

    if (block19.is_used()) {
        ca_.Bind(&block19);
        ca_.Goto(&block6);
    }

    TNode<Int32T> tmp23;
    TNode<Int32T> tmp24;
    TNode<BoolT> tmp25;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        tmp23 = CodeStubAssembler(state_).Int32Div(TNode<Int32T> { tmp16 }, TNode<Int32T> { tmp17 });
        tmp24 = CodeStubAssembler(state_).Int32Mul(TNode<Int32T> { tmp23 }, TNode<Int32T> { tmp17 });
        tmp25 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T> { tmp16 }, TNode<Int32T> { tmp24 });
        ca_.Branch(tmp25, &block24, std::vector<compiler::Node*> {}, &block25, std::vector<compiler::Node*> {});
    }

    if (block24.is_used()) {
        ca_.Bind(&block24);
        ca_.Goto(&block6);
    }

    TNode<Smi> tmp26;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        tmp26 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T> { tmp23 });
        CodeStubAssembler(state_).Return(tmp26);
    }

    TNode<Float64T> tmp27;
    TNode<Float64T> tmp28;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp27 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp1.value() });
        tmp28 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi> { tmp2.value() });
        ca_.Goto(&block4, tmp27, tmp28);
    }

    TNode<Float64T> phi_bb4_3;
    TNode<Float64T> phi_bb4_4;
    TNode<Float64T> tmp29;
    TNode<HeapNumber> tmp30;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        tmp29 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { phi_bb4_3 }, TNode<Float64T> { phi_bb4_4 });
        tmp30 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp29 });
        CodeStubAssembler(state_).Return(tmp30);
    }
}

TF_BUILTIN(Modulus, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Smi> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp4(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp5(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp7(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp8(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        compiler::CodeAssemblerLabel label6(&ca_);
        BinaryOp2_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, &label0, &tmp1, &tmp2, &label3, &tmp4,
            &tmp5, &label6, &tmp7, &tmp8);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block7);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8);
        }
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block9);
        }
    }

    TNode<Number> tmp9;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp9 = CodeStubAssembler(state_).SmiMod(TNode<Smi> { tmp1.value() }, TNode<Smi> { tmp2.value() });
        CodeStubAssembler(state_).Return(tmp9);
    }

    TNode<Float64T> tmp10;
    TNode<HeapNumber> tmp11;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp10 = CodeStubAssembler(state_).Float64Mod(TNode<Float64T> { tmp4.value() }, TNode<Float64T> { tmp5.value() });
        tmp11 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp10 });
        CodeStubAssembler(state_).Return(tmp11);
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kBigIntModulus, parameter0, tmp7.value(), tmp8.value());
    }
}

TF_BUILTIN(Exponentiate, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Number> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Number> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp4(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp5(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        BinaryOp1_0(
            state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, &label0, &tmp1, &tmp2, &label3, &tmp4, &tmp5);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block6);
        }
    }

    TNode<Number> tmp6;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp6 = MathPowImpl_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp1.value() }, TNode<Object> { tmp2.value() });
        CodeStubAssembler(state_).Return(tmp6);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kBigIntExponentiate, parameter0, tmp4.value(), tmp5.value());
    }
}

TF_BUILTIN(Negate, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<HeapNumber> tmp3(&ca_);
    compiler::TypedCodeAssemblerVariable<BigInt> tmp5(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        compiler::CodeAssemblerLabel label4(&ca_);
        UnaryOp2_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3, &label4, &tmp5);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block7);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block8);
        }
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block9);
        }
    }

    TNode<Smi> tmp6;
    TNode<Number> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp6 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
        tmp7 = CodeStubAssembler(state_).SmiMul(TNode<Smi> { tmp1.value() }, TNode<Smi> { tmp6 });
        CodeStubAssembler(state_).Return(tmp7);
    }

    TNode<Float64T> tmp8;
    TNode<Float64T> tmp9;
    TNode<Float64T> tmp10;
    TNode<HeapNumber> tmp11;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp8 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp3.value() });
        tmp9 = FromConstexpr_float64_constexpr_float64_0(state_, -1);
        tmp10 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp8 }, TNode<Float64T> { tmp9 });
        tmp11 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp10 });
        CodeStubAssembler(state_).Return(tmp11);
    }

    TNode<Uint32T> tmp12;
    TNode<Smi> tmp13;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp12 = FromConstexpr_Operation_constexpr_kNegate_0(state_, Operation::kNegate);
        tmp13 = SmiTag_Operation_0(state_, TNode<Uint32T> { tmp12 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kBigIntUnaryOp, parameter0, tmp5.value(), tmp13);
    }
}

TF_BUILTIN(BitwiseNot, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Number> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<BigInt> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        UnaryOp1_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    TNode<Int32T> tmp4;
    TNode<Int32T> tmp5;
    TNode<Number> tmp6;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp4 = CodeStubAssembler(state_).TruncateNumberToWord32(TNode<Number> { tmp1.value() });
        tmp5 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
        tmp6 = CodeStubAssembler(state_).BitwiseOp(TNode<Int32T> { tmp4 }, TNode<Int32T> { tmp5 }, Operation::kBitwiseXor);
        CodeStubAssembler(state_).Return(tmp6);
    }

    TNode<Uint32T> tmp7;
    TNode<Smi> tmp8;
    TNode<BigInt> tmp9;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp7 = FromConstexpr_Operation_constexpr_kBitwiseNot_0(state_, Operation::kBitwiseNot);
        tmp8 = SmiTag_Operation_0(state_, TNode<Uint32T> { tmp7 });
        tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kBigIntUnaryOp, parameter0, tmp3.value(), tmp8));
        CodeStubAssembler(state_).Return(tmp9);
    }
}

TF_BUILTIN(Decrement, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Number> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<BigInt> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        UnaryOp1_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    TNode<Number> tmp4;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp4 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kSubtract, parameter0, tmp1.value(), tmp4);
    }

    TNode<Uint32T> tmp5;
    TNode<Smi> tmp6;
    TNode<BigInt> tmp7;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp5 = FromConstexpr_Operation_constexpr_kDecrement_0(state_, Operation::kDecrement);
        tmp6 = SmiTag_Operation_0(state_, TNode<Uint32T> { tmp5 });
        tmp7 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kBigIntUnaryOp, parameter0, tmp3.value(), tmp6));
        CodeStubAssembler(state_).Return(tmp7);
    }
}

TF_BUILTIN(Increment, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Number> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<BigInt> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        UnaryOp1_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    TNode<Number> tmp4;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp4 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kAdd, parameter0, tmp1.value(), tmp4);
    }

    TNode<Uint32T> tmp5;
    TNode<Smi> tmp6;
    TNode<BigInt> tmp7;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp5 = FromConstexpr_Operation_constexpr_kIncrement_0(state_, Operation::kIncrement);
        tmp6 = SmiTag_Operation_0(state_, TNode<Uint32T> { tmp5 });
        tmp7 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kBigIntUnaryOp, parameter0, tmp3.value(), tmp6));
        CodeStubAssembler(state_).Return(tmp7);
    }
}

TF_BUILTIN(ShiftLeft, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = BinaryOpAssembler(state_).Generate_BitwiseBinaryOp(
            Operation::kShiftLeft, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, TNode<Context> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(ShiftRight, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = BinaryOpAssembler(state_).Generate_BitwiseBinaryOp(
            Operation::kShiftRight, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, TNode<Context> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(ShiftRightLogical, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = BinaryOpAssembler(state_).Generate_BitwiseBinaryOp(
            Operation::kShiftRightLogical, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, TNode<Context> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(BitwiseAnd, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Number> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Number> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp4(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp5(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        BinaryOp1_0(
            state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, &label0, &tmp1, &tmp2, &label3, &tmp4, &tmp5);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block6);
        }
    }

    TNode<Int32T> tmp6;
    TNode<Int32T> tmp7;
    TNode<Number> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp6 = CodeStubAssembler(state_).TruncateNumberToWord32(TNode<Number> { tmp1.value() });
        tmp7 = CodeStubAssembler(state_).TruncateNumberToWord32(TNode<Number> { tmp2.value() });
        tmp8 = CodeStubAssembler(state_).BitwiseOp(TNode<Int32T> { tmp6 }, TNode<Int32T> { tmp7 }, Operation::kBitwiseAnd);
        CodeStubAssembler(state_).Return(tmp8);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kBigIntBitwiseAnd, parameter0, tmp4.value(), tmp5.value());
    }
}

TF_BUILTIN(BitwiseOr, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Number> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Number> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp4(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp5(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        BinaryOp1_0(
            state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, &label0, &tmp1, &tmp2, &label3, &tmp4, &tmp5);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block6);
        }
    }

    TNode<Int32T> tmp6;
    TNode<Int32T> tmp7;
    TNode<Number> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp6 = CodeStubAssembler(state_).TruncateNumberToWord32(TNode<Number> { tmp1.value() });
        tmp7 = CodeStubAssembler(state_).TruncateNumberToWord32(TNode<Number> { tmp2.value() });
        tmp8 = CodeStubAssembler(state_).BitwiseOp(TNode<Int32T> { tmp6 }, TNode<Int32T> { tmp7 }, Operation::kBitwiseOr);
        CodeStubAssembler(state_).Return(tmp8);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kBigIntBitwiseOr, parameter0, tmp4.value(), tmp5.value());
    }
}

TF_BUILTIN(BitwiseXor, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Number> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Number> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp4(&ca_);
    compiler::TypedCodeAssemblerVariable<Numeric> tmp5(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        BinaryOp1_0(
            state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, &label0, &tmp1, &tmp2, &label3, &tmp4, &tmp5);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block6);
        }
    }

    TNode<Int32T> tmp6;
    TNode<Int32T> tmp7;
    TNode<Number> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp6 = CodeStubAssembler(state_).TruncateNumberToWord32(TNode<Number> { tmp1.value() });
        tmp7 = CodeStubAssembler(state_).TruncateNumberToWord32(TNode<Number> { tmp2.value() });
        tmp8 = CodeStubAssembler(state_).BitwiseOp(TNode<Int32T> { tmp6 }, TNode<Int32T> { tmp7 }, Operation::kBitwiseXor);
        CodeStubAssembler(state_).Return(tmp8);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kBigIntBitwiseXor, parameter0, tmp4.value(), tmp5.value());
    }
}

TF_BUILTIN(LessThan, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Boolean> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).RelationalComparison(
            Operation::kLessThan, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, TNode<Context> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(LessThanOrEqual, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Boolean> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).RelationalComparison(
            Operation::kLessThanOrEqual, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, TNode<Context> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(GreaterThan, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Boolean> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).RelationalComparison(
            Operation::kGreaterThan, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, TNode<Context> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(GreaterThanOrEqual, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Boolean> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).RelationalComparison(
            Operation::kGreaterThanOrEqual, TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, TNode<Context> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(Equal, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Boolean> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Equal(TNode<Object> { parameter1 }, TNode<Object> { parameter2 }, TNode<Context> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(StrictEqual, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kLeft);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kRight);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Boolean> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).StrictEqual(TNode<Object> { parameter1 }, TNode<Object> { parameter2 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=58&c=10
TNode<Number> UnsafeCast_Number_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=93&c=6
TorqueStructReference_char8_0 UnsafeConstCast_char8_0(compiler::CodeAssemblerState* state_, TorqueStructReference_char8_0 p_r)
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
            = (TorqueStructReference_char8_0 { TNode<Object> { p_r.object }, TNode<IntPtrT> { p_r.offset }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_char8_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp1 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=147&c=36
TNode<Int32T> Convert_int32_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, p_i);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/number.tq?l=750&c=21
TNode<Smi> SmiTag_Operation_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_value)
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

} // namespace internal
} // namespace v8
