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
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
TNode<IntPtrT> FromConstexpr_intptr_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToIntptr(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=12&c=1
TNode<UintPtrT> FromConstexpr_uintptr_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToUintptr(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=16&c=1
TNode<Int32T> FromConstexpr_int32_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToInt32(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=20&c=1
TNode<Uint32T> FromConstexpr_uint32_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_uint32_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToUint32(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=24&c=1
TNode<Int32T> FromConstexpr_int31_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_int31_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToInt31(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=28&c=1
TNode<Int8T> FromConstexpr_int8_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int8T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_int8_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToInt8(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int8T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=32&c=1
TNode<Uint8T> FromConstexpr_uint8_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint8T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint8_constexpr_uint8_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToUint8(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=36&c=1
TNode<Int64T> FromConstexpr_int64_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_int64_constexpr_int64_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToInt64(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=40&c=1
TNode<Uint64T> FromConstexpr_uint64_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint64_constexpr_uint64_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToUint64(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=44&c=1
int31_t FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
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
    return (CodeStubAssembler(state_).ConstexprIntegerLiteralToInt31(p_i));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=48&c=1
int32_t FromConstexpr_constexpr_int32_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
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
    return (CodeStubAssembler(state_).ConstexprIntegerLiteralToInt32(p_i));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=52&c=1
TNode<Number> FromConstexpr_Number_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).NumberConstant((CodeStubAssembler(state_).ConstexprIntegerLiteralToFloat64(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=56&c=1
TNode<Smi> FromConstexpr_Smi_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_Smi_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToInt31(p_i)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=59&c=1
TNode<Uint8T> FromConstexpr_char8_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint8T> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint8_constexpr_IntegerLiteral_0(state_, p_i);
        tmp1 = (TNode<Uint8T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=64&c=1
TNode<Int32T> FromConstexpr_int31_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=67&c=1
TNode<Int32T> FromConstexpr_int32_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=70&c=1
TNode<Int32T> FromConstexpr_int32_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
TNode<IntPtrT> FromConstexpr_intptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=76&c=1
TNode<IntPtrT> FromConstexpr_intptr_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
TNode<IntPtrT> FromConstexpr_intptr_constexpr_intptr_0(compiler::CodeAssemblerState* state_, intptr_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=82&c=1
TNode<UintPtrT> FromConstexpr_uintptr_constexpr_uintptr_0(compiler::CodeAssemblerState* state_, uintptr_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.UintPtrConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=85&c=1
TNode<Smi> FromConstexpr_Smi_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.SmiConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=88&c=1
TNode<Smi> FromConstexpr_PositiveSmi_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.SmiConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=92&c=1
TNode<String> FromConstexpr_String_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.StringConstant(CastToUnderlyingTypeIfEnum(p_s));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<String> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=95&c=1
TNode<Number> FromConstexpr_Number_constexpr_uint32_0(compiler::CodeAssemblerState* state_, uint32_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.NumberConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=98&c=1
TNode<Number> FromConstexpr_Number_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.NumberConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=101&c=1
TNode<Number> FromConstexpr_Number_constexpr_float64_0(compiler::CodeAssemblerState* state_, double p_f)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.NumberConstant(CastToUnderlyingTypeIfEnum(p_f));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=104&c=1
TNode<Number> FromConstexpr_Number_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.NumberConstant(CastToUnderlyingTypeIfEnum(p_i));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=107&c=1
TNode<Uint8T> FromConstexpr_uint8_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<BoolT> tmp2;
    TNode<Uint8T> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_int31_0(state_, p_i);
        tmp1 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffull));
        tmp2 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T> { tmp0 }, TNode<Uint32T> { tmp1 });
        CodeStubAssembler(state_).StaticAssert(
            TNode<BoolT> { tmp2 }, "static_assert(i <= 255) at https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=109&c=3");
        tmp3 = ca_.UncheckedCast<Uint8T>(TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=112&c=1
TNode<Int8T> FromConstexpr_int8_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Int32T> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_int32_constexpr_int31_0(state_, p_i);
        tmp1 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x80ull));
        tmp2 = CodeStubAssembler(state_).Int32LessThanOrEqual(TNode<Int32T> { tmp1 }, TNode<Int32T> { tmp0 });
        ca_.Branch(tmp2, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp3;
    TNode<BoolT> tmp4;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x7full));
        tmp4 = CodeStubAssembler(state_).Int32LessThanOrEqual(TNode<Int32T> { tmp0 }, TNode<Int32T> { tmp3 });
        ca_.Goto(&block4, tmp4);
    }

    TNode<BoolT> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block4, tmp5);
    }

    TNode<BoolT> phi_bb4_2;
    TNode<Int8T> tmp6;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_2);
        CodeStubAssembler(state_).StaticAssert(TNode<BoolT> { phi_bb4_2 },
            "static_assert(-128 <= i && i <= 127) at https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=114&c=3");
        tmp6 = ca_.UncheckedCast<Int8T>(TNode<Int32T> { tmp0 });
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<Int8T> { tmp6 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=117&c=1
TNode<Uint8T> FromConstexpr_char8_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint8T> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint8_constexpr_int31_0(state_, p_i);
        tmp1 = (TNode<Uint8T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=120&c=1
TNode<Uint32T> FromConstexpr_uint32_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Int32Constant(p_i);
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=123&c=1
TNode<Uint8T> FromConstexpr_uint8_constexpr_uint8_0(compiler::CodeAssemblerState* state_, uint8_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_uint32_0(state_, p_i);
        tmp1 = ca_.UncheckedCast<Uint8T>(TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=127&c=1
TNode<Uint32T> FromConstexpr_uint32_constexpr_uint32_0(compiler::CodeAssemblerState* state_, uint32_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_i));
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=130&c=1
TNode<Int64T> FromConstexpr_int64_constexpr_int64_0(compiler::CodeAssemblerState* state_, int64_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Int64Constant(p_i);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=133&c=1
TNode<Uint64T> FromConstexpr_uint64_constexpr_uint64_0(compiler::CodeAssemblerState* state_, uint64_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Uint64Constant(p_i);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=136&c=1
TNode<Uint64T> FromConstexpr_uint64_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint64T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Int32Constant(p_i);
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp0 });
        tmp2 = Convert_uint64_uint32_0(state_, TNode<Uint32T> { tmp1 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint64T> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=139&c=1
TNode<UintPtrT> FromConstexpr_uintptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<UintPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_int31_0(state_, p_i);
        tmp1 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=142&c=1
TNode<Float64T> FromConstexpr_float64_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Float64Constant(p_i);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=145&c=1
TNode<Float64T> FromConstexpr_float64_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Float64Constant(p_i);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=148&c=1
TNode<Float64T> FromConstexpr_float64_constexpr_float64_0(compiler::CodeAssemblerState* state_, double p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Float64Constant(p_i);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=151&c=1
TNode<BoolT> FromConstexpr_bool_constexpr_bool_0(compiler::CodeAssemblerState* state_, bool p_b)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).BoolConstant(p_b);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<BoolT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=154&c=1
TNode<Object> FromConstexpr_Object_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).StringConstant(p_s);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=157&c=1
TNode<Object> FromConstexpr_JSAny_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).StringConstant(p_s);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=160&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ContextSlot_0(compiler::CodeAssemblerState* state_, Context::Field p_c)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).IntPtrConstant(p_c);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=164&c=1
TNode<Smi> FromConstexpr_LanguageModeSmi_constexpr_LanguageMode_0(compiler::CodeAssemblerState* state_, LanguageMode p_c)
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
        tmp0 = CodeStubAssembler(state_).SmiConstant(p_c);
        tmp1 = (TNode<Smi> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=168&c=1
TNode<Int32T> FromConstexpr_PromiseState_constexpr_PromiseState_0(compiler::CodeAssemblerState* state_, Promise::PromiseState p_c)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Int32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Int32Constant(p_c);
        tmp1 = (TNode<Int32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=172&c=1
TNode<Uint16T> FromConstexpr_InstanceType_constexpr_InstanceType_0(compiler::CodeAssemblerState* state_, InstanceType p_c)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint16T> tmp0;
    TNode<Uint16T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Uint16Constant(p_c);
        tmp1 = (TNode<Uint16T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint16T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=177&c=1
TNode<Uint32T> FromConstexpr_IterationKind_constexpr_IterationKind_0(compiler::CodeAssemblerState* state_, IterationKind p_c)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_c));
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp0 });
        tmp2 = (TNode<Uint32T> { tmp1 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=182&c=1
TNode<Uint32T> FromConstexpr_TrimMode_constexpr_TrimMode_0(compiler::CodeAssemblerState* state_, String::TrimMode p_c)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_c));
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp0 });
        tmp2 = (TNode<Uint32T> { tmp1 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=195&c=1
TNode<Boolean> Convert_Boolean_bool_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_b)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Boolean> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Branch(p_b, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<True> tmp0;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp0 = True_0(state_);
        ca_.Goto(&block4, tmp0);
    }

    TNode<False> tmp1;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp1 = False_0(state_);
        ca_.Goto(&block4, tmp1);
    }

    TNode<Boolean> phi_bb4_1;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_1);
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Boolean> { phi_bb4_1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=198&c=1
TNode<Int32T> Convert_int32_bool_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_b)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeBoolToInt32(TNode<BoolT> { p_b });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=201&c=1
TNode<Number> Convert_Number_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeInt32ToTagged(TNode<Int32T> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=204&c=1
TNode<IntPtrT> Convert_intptr_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=207&c=1
TNode<IntPtrT> Convert_intptr_int31_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=210&c=1
TNode<IntPtrT> Convert_intptr_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T> { p_i });
        tmp1 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=213&c=1
TNode<Smi> Convert_Smi_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=216&c=1
TNode<Number> Convert_Number_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUint32ToTagged(TNode<Uint32T> { p_ui });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=219&c=1
TNode<Smi> Convert_Smi_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { p_ui });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=222&c=1
TNode<UintPtrT> Convert_uintptr_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T> { p_ui });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=225&c=1
TNode<Int64T> Convert_int64_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeInt32ToInt64(TNode<Int32T> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=228&c=1
TNode<Uint64T> Convert_uint64_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUint32ToUint64(TNode<Uint32T> { p_ui });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=231&c=1
TNode<IntPtrT> Convert_intptr_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T> { p_ui });
        tmp1 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=234&c=1
TNode<IntPtrT> Convert_intptr_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T> { p_ui });
        tmp1 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=237&c=1
TNode<Uint8T> Convert_uint8_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Uint8T> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT> { p_i });
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp0 });
        tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffull));
        tmp3 = CodeStubAssembler(state_).Word32And(TNode<Uint32T> { tmp1 }, TNode<Uint32T> { tmp2 });
        tmp4 = ca_.UncheckedCast<Uint8T>(TNode<Uint32T> { tmp3 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp4 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=240&c=1
TNode<Int8T> Convert_int8_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Int32T> tmp1;
    TNode<Int32T> tmp2;
    TNode<Int32T> tmp3;
    TNode<Int32T> tmp4;
    TNode<Int8T> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT> { p_i });
        tmp1 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x18ull));
        tmp2 = CodeStubAssembler(state_).Word32Shl(TNode<Int32T> { tmp0 }, TNode<Int32T> { tmp1 });
        tmp3 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x18ull));
        tmp4 = CodeStubAssembler(state_).Word32Sar(TNode<Int32T> { tmp2 }, TNode<Int32T> { tmp3 });
        tmp5 = ca_.UncheckedCast<Int8T>(TNode<Int32T> { tmp4 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int8T> { tmp5 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=243&c=1
TNode<Uint16T> Convert_uint16_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint16T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffffull));
        tmp1 = CodeStubAssembler(state_).Word32And(TNode<Uint32T> { p_i }, TNode<Uint32T> { tmp0 });
        tmp2 = ca_.UncheckedCast<Uint16T>(TNode<Uint32T> { tmp1 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint16T> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=246&c=1
TNode<Int32T> Convert_int32_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Int32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_uint32_uint8_0(state_, TNode<Uint8T> { p_i });
        tmp1 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=249&c=1
TNode<Int32T> Convert_int32_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Int32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_uint32_uint16_0(state_, TNode<Uint16T> { p_i });
        tmp1 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=252&c=1
TNode<Int32T> Convert_int32_char8_OR_char16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Int32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_uint32_char8_OR_char16_0(state_, TNode<Uint16T> { p_i });
        tmp1 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=255&c=1
TNode<IntPtrT> Convert_intptr_char16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=258&c=1
TNode<IntPtrT> Convert_intptr_char8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=261&c=1
TNode<Int32T> Convert_int32_uint31_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Int32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_uint32_uint31_0(state_, TNode<Uint32T> { p_i });
        tmp1 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=264&c=1
TNode<Int32T> Convert_int32_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=267&c=1
TNode<Int32T> Convert_int32_int64_0(compiler::CodeAssemblerState* state_, TNode<Int64T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=270&c=1
TNode<Uint32T> Convert_uint32_uint64_0(compiler::CodeAssemblerState* state_, TNode<Uint64T> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int64T> tmp0;
    TNode<Int32T> tmp1;
    TNode<Uint32T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Signed(TNode<Uint64T> { p_i });
        tmp1 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp1 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=273&c=1
TNode<Int32T> Convert_int32_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Int32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_Smi_0(state_, TNode<Object> { p_n }, &label1);
        ca_.Goto(&block4);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block5);
        }
    }

    TNode<Int32T> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = CodeStubAssembler(state_).TruncateHeapNumberValueToWord32(TNode<HeapNumber> { ca_.UncheckedCast<HeapNumber>(p_n) });
        ca_.Goto(&block1, tmp2);
    }

    TNode<Int32T> tmp3;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = Convert_int32_Smi_0(state_, TNode<Smi> { tmp0 });
        ca_.Goto(&block1, tmp3);
    }

    TNode<Int32T> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_1);
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Int32T> { phi_bb1_1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=284&c=1
TNode<Smi> Convert_Smi_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=287&c=1
TNode<Uint32T> Convert_uint32_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Int32T> tmp1;
    TNode<Uint32T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { p_ui });
        tmp1 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp1 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
TNode<IntPtrT> Convert_intptr_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_s)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiUntag(TNode<Smi> { p_s });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=293&c=1
TNode<UintPtrT> Convert_uintptr_PositiveSmi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_ps)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<UintPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiUntag(TNode<Smi> { p_ps });
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=296&c=1
TNode<IntPtrT> Convert_intptr_TaggedIndex_0(compiler::CodeAssemblerState* state_, TNode<TaggedIndex> p_ti)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).TaggedIndexToIntPtr(TNode<TaggedIndex> { p_ti });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=299&c=1
TNode<TaggedIndex> Convert_TaggedIndex_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).IntPtrToTaggedIndex(TNode<IntPtrT> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TaggedIndex> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=302&c=1
TNode<IntPtrT> Convert_intptr_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { p_ui });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=307&c=1
TNode<Smi> Convert_PositiveSmi_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT> { p_i });
        tmp1 = (TNode<Smi> { tmp0 });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=311&c=1
TNode<Smi> Convert_PositiveSmi_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui, compiler::CodeAssemblerLabel* label_IfOverflow)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, kSmiMaxValue);
        tmp1 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { p_ui }, TNode<UintPtrT> { tmp0 });
        ca_.Branch(tmp1, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(label_IfOverflow);
    }

    TNode<IntPtrT> tmp2;
    TNode<Smi> tmp3;
    TNode<Smi> tmp4;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp2 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { p_ui });
        tmp3 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT> { tmp2 });
        tmp4 = (TNode<Smi> { tmp3 });
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<Smi> { tmp4 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=317&c=1
TNode<Smi> Convert_PositiveSmi_intptr_1(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i, compiler::CodeAssemblerLabel* label_IfOverflow)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT> { p_i });
        ca_.Branch(tmp0, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp1;
    TNode<Smi> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp1 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT> { p_i });
        tmp2 = (TNode<Smi> { tmp1 });
        ca_.Goto(&block6);
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_IfOverflow);
    }

    ca_.Bind(&block6);
    return TNode<Smi> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=325&c=1
TNode<Smi> Convert_PositiveSmi_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui, compiler::CodeAssemblerLabel* label_IfOverflow)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { p_ui });
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Convert_PositiveSmi_uintptr_0(state_, TNode<UintPtrT> { tmp0 }, &label2);
        ca_.Goto(&block3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_IfOverflow);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=328&c=1
TNode<Int32T> Convert_int32_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_s)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { p_s });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=331&c=1
TNode<Float64T> Convert_float64_HeapNumber_0(compiler::CodeAssemblerState* state_, TNode<HeapNumber> p_h)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadHeapNumberValue_0(state_, TNode<HeapNumber> { p_h });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=334&c=1
TNode<Float64T> Convert_float64_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeNumberToFloat64(TNode<Number> { p_n });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=337&c=1
TNode<UintPtrT> Convert_uintptr_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ChangeUintPtrNumberToUintPtr_0(state_, TNode<Number> { p_n });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=340&c=1
TNode<Float64T> Convert_float64_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_f)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeInt32ToFloat64(TNode<Int32T> { p_f });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=343&c=1
TNode<Float64T> Convert_float64_float32_0(compiler::CodeAssemblerState* state_, TNode<Float32T> p_f)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeFloat32ToFloat64(TNode<Float32T> { p_f });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=346&c=1
TorqueStructfloat64_or_hole_0 Convert_float64_or_hole_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_f)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructfloat64_or_hole_0 { TNode<BoolT> { tmp0 }, TNode<Float64T> { p_f } };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=349&c=1
TorqueStructfloat64_or_hole_0 Convert_float64_or_hole_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<BoolT> tmp1;
    TNode<Float64T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_float64_Number_0(state_, TNode<Number> { p_n });
        std::tie(tmp1, tmp2) = Convert_float64_or_hole_float64_0(state_, TNode<Float64T> { tmp0 }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructfloat64_or_hole_0 { TNode<BoolT> { tmp1 }, TNode<Float64T> { tmp2 } };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=352&c=1
TNode<Float32T> Convert_float32_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_f)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).TruncateFloat64ToFloat32(TNode<Float64T> { p_f });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=355&c=1
TNode<Float32T> Convert_float32_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<Float32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeNumberToFloat64(TNode<Number> { p_n });
        tmp1 = Convert_float32_float64_0(state_, TNode<Float64T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=358&c=1
TNode<Float16RawBitsT> Convert_float16_raw_bits_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<Float16RawBitsT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeNumberToFloat64(TNode<Number> { p_n });
        tmp1 = CodeStubAssembler(state_).TruncateFloat64ToFloat16(TNode<Float64T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float16RawBitsT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=362&c=1
TNode<Float64T> Convert_float64_float16_raw_bits_0(compiler::CodeAssemblerState* state_, TNode<Float16RawBitsT> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeFloat16ToFloat64(TNode<Float16RawBitsT> { p_n });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=365&c=1
TNode<Float32T> Convert_float32_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).RoundInt32ToFloat32(TNode<Int32T> { p_n });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=368&c=1
TNode<Float32T> Convert_float32_HeapNumber_0(compiler::CodeAssemblerState* state_, TNode<HeapNumber> p_h)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<Float32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadHeapNumberValue_0(state_, TNode<HeapNumber> { p_h });
        tmp1 = Convert_float32_float64_0(state_, TNode<Float64T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=371&c=1
TNode<Number> Convert_Number_float32_0(compiler::CodeAssemblerState* state_, TNode<Float32T> p_d)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeFloat32ToTagged(TNode<Float32T> { p_d });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=374&c=1
TNode<Number> Convert_Number_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_d)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeFloat64ToTagged(TNode<Float64T> { p_d });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=377&c=1
TNode<Float64T> Convert_float64_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUintPtrToFloat64(TNode<UintPtrT> { p_ui });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=380&c=1
TNode<Number> Convert_Number_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUintPtrToTagged(TNode<UintPtrT> { p_ui });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=383&c=1
TNode<Number> Convert_Number_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<Number> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { p_i });
        tmp1 = CodeStubAssembler(state_).ChangeUintPtrToTagged(TNode<UintPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=386&c=1
TNode<UintPtrT> Convert_uintptr_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_d)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeFloat64ToUintPtr(TNode<Float64T> { p_d });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=389&c=1
TNode<UintPtrT> Convert_uintptr_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { p_i });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=392&c=1
TNode<UintPtrT> Convert_uintptr_WasmCodePointer_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_r)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Unsigned(TNode<RawPtrT> { p_r });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<UintPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=395&c=1
TNode<IntPtrT> Convert_intptr_WasmCodePointer_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_r)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Signed(TNode<RawPtrT> { p_r });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=398&c=1
TNode<IntPtrT> Convert_intptr_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeNumberToFloat64(TNode<Number> { p_n });
        tmp1 = CodeStubAssembler(state_).ChangeFloat64ToIntPtr(TNode<Float64T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=401&c=1
TNode<BInt> Convert_bint_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<BInt> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_intptr_int32_0(state_, TNode<Int32T> { p_v });
        tmp1 = CodeStubAssembler(state_).IntPtrToBInt(TNode<IntPtrT> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<BInt> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=405&c=1
TNode<Float64T> FromConstexpr_float64_constexpr_IntegerLiteral_0(compiler::CodeAssemblerState* state_, IntegerLiteral p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_float64_constexpr_float64_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToFloat64(p_v)));
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Float64T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=410&c=1
TNode<BInt> Convert_bint_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BInt> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).IntPtrToBInt(TNode<IntPtrT> { p_v });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<BInt> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=414&c=1
TNode<IntPtrT> Convert_intptr_bint_0(compiler::CodeAssemblerState* state_, TNode<BInt> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).BIntToIntPtr(TNode<BInt> { p_v });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=418&c=1
TNode<BInt> Convert_bint_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BInt> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiToBInt(TNode<Smi> { p_v });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<BInt> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=422&c=1
TNode<Smi> Convert_Smi_bint_0(compiler::CodeAssemblerState* state_, TNode<BInt> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).BIntToSmi(TNode<BInt> { p_v });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=425&c=1
TNode<Int32T> Convert_PromiseState_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_s)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = (TNode<Int32T> { p_s });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=428&c=1
TNode<I8x16T> Convert_I8X16_Simd128_0(compiler::CodeAssemblerState* state_, TNode<Simd128T> p_s)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<I8x16T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.UncheckedCast<I8x16T>(TNode<Simd128T> { p_s });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<I8x16T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=57&c=10
TNode<Smi> Convert_Smi_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, p_i);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=247&c=17
TNode<Uint32T> Convert_uint32_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i)
{
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
    return TNode<Uint32T> { p_i };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=250&c=17
TNode<Uint32T> Convert_uint32_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i)
{
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
    return TNode<Uint32T> { p_i };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=253&c=17
TNode<Uint32T> Convert_uint32_char8_OR_char16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i)
{
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
    return TNode<Uint32T> { p_i };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=262&c=17
TNode<Uint32T> Convert_uint32_uint31_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i)
{
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
    return TNode<Uint32T> { p_i };
}

} // namespace internal
} // namespace v8
