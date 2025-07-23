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
#include "torque-generated/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-to-sorted-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-sort.tq?l=8&c=1
const char* kBuiltinNameSort_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    return "%TypedArray%.prototype.sort";
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-sort.tq?l=12&c=1
TNode<Number> CallCompare_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<JSReceiver> p_comparefn,
    TNode<Object> p_a, TNode<Object> p_b)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Undefined> tmp0;
    TNode<Object> tmp1;
    TNode<Number> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Undefined_0(state_);
        tmp1 = CodeStubAssembler(state_).Call(
            TNode<Context> { p_context }, TNode<Object> { p_comparefn }, TNode<Object> { tmp0 }, TNode<Object> { p_a }, TNode<Object> { p_b });
        tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { p_context }, TNode<Object> { tmp1 });
        tmp3 = NumberIsNaN_0(state_, TNode<Number> { tmp2 });
        ca_.Branch(tmp3, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp4;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp4 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block1, tmp4);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block1, tmp2);
    }

    TNode<Number> phi_bb1_5;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_5);
        ca_.Goto(&block4);
    }

    ca_.Bind(&block4);
    return TNode<Number> { phi_bb1_5 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-sort.tq?l=27&c=1
void TypedArrayMerge_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<JSReceiver> p_comparefn,
    TNode<FixedArray> p_source, TNode<UintPtrT> p_from, TNode<UintPtrT> p_middle, TNode<UintPtrT> p_to, TNode<FixedArray> p_target)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block24(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block25(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block82(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block83(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Goto(&block4, p_from, p_middle, p_from);
    }

    TNode<UintPtrT> phi_bb4_8;
    TNode<UintPtrT> phi_bb4_9;
    TNode<UintPtrT> phi_bb4_10;
    TNode<BoolT> tmp0;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_8, &phi_bb4_9, &phi_bb4_10);
        tmp0 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb4_10 }, TNode<UintPtrT> { p_to });
        ca_.Branch(tmp0, &block2, std::vector<compiler::Node*> { phi_bb4_8, phi_bb4_9, phi_bb4_10 }, &block3,
            std::vector<compiler::Node*> { phi_bb4_8, phi_bb4_9, phi_bb4_10 });
    }

    TNode<UintPtrT> phi_bb2_8;
    TNode<UintPtrT> phi_bb2_9;
    TNode<UintPtrT> phi_bb2_10;
    TNode<BoolT> tmp1;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_8, &phi_bb2_9, &phi_bb2_10);
        tmp1 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb2_8 }, TNode<UintPtrT> { p_middle });
        ca_.Branch(tmp1, &block8, std::vector<compiler::Node*> { phi_bb2_8, phi_bb2_9, phi_bb2_10 }, &block9,
            std::vector<compiler::Node*> { phi_bb2_8, phi_bb2_9, phi_bb2_10 });
    }

    TNode<UintPtrT> phi_bb8_8;
    TNode<UintPtrT> phi_bb8_9;
    TNode<UintPtrT> phi_bb8_10;
    TNode<BoolT> tmp2;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_8, &phi_bb8_9, &phi_bb8_10);
        tmp2 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT> { phi_bb8_9 }, TNode<UintPtrT> { p_to });
        ca_.Goto(&block10, phi_bb8_8, phi_bb8_9, phi_bb8_10, tmp2);
    }

    TNode<UintPtrT> phi_bb9_8;
    TNode<UintPtrT> phi_bb9_9;
    TNode<UintPtrT> phi_bb9_10;
    TNode<BoolT> tmp3;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_8, &phi_bb9_9, &phi_bb9_10);
        tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block10, phi_bb9_8, phi_bb9_9, phi_bb9_10, tmp3);
    }

    TNode<UintPtrT> phi_bb10_8;
    TNode<UintPtrT> phi_bb10_9;
    TNode<UintPtrT> phi_bb10_10;
    TNode<BoolT> phi_bb10_12;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_8, &phi_bb10_9, &phi_bb10_10, &phi_bb10_12);
        ca_.Branch(phi_bb10_12, &block6, std::vector<compiler::Node*> { phi_bb10_8, phi_bb10_9, phi_bb10_10 }, &block7,
            std::vector<compiler::Node*> { phi_bb10_8, phi_bb10_9, phi_bb10_10 });
    }

    TNode<UintPtrT> phi_bb6_8;
    TNode<UintPtrT> phi_bb6_9;
    TNode<UintPtrT> phi_bb6_10;
    TNode<Object> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<BoolT> tmp10;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_8, &phi_bb6_9, &phi_bb6_10);
        std::tie(tmp4, tmp5, tmp6) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_target }).Flatten();
        tmp7 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb6_10 });
        tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp7 });
        tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp6 });
        tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp8 }, TNode<UintPtrT> { tmp9 });
        ca_.Branch(tmp10, &block16, std::vector<compiler::Node*> { phi_bb6_8, phi_bb6_9, phi_bb6_10, phi_bb6_10, phi_bb6_10 }, &block17,
            std::vector<compiler::Node*> { phi_bb6_8, phi_bb6_9, phi_bb6_10, phi_bb6_10, phi_bb6_10 });
    }

    TNode<UintPtrT> phi_bb16_8;
    TNode<UintPtrT> phi_bb16_9;
    TNode<UintPtrT> phi_bb16_10;
    TNode<UintPtrT> phi_bb16_15;
    TNode<UintPtrT> phi_bb16_16;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<Object> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Object> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<UintPtrT> tmp21;
    TNode<UintPtrT> tmp22;
    TNode<BoolT> tmp23;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_8, &phi_bb16_9, &phi_bb16_10, &phi_bb16_15, &phi_bb16_16);
        tmp11 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp7 });
        tmp12 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp5 }, TNode<IntPtrT> { tmp11 });
        std::tie(tmp13, tmp14) = NewReference_Object_0(state_, TNode<Object> { tmp4 }, TNode<IntPtrT> { tmp12 }).Flatten();
        std::tie(tmp15, tmp16, tmp17) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_source }).Flatten();
        tmp18 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
        tmp19 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { phi_bb16_8 }, TNode<UintPtrT> { tmp18 });
        tmp20 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb16_8 });
        tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp20 });
        tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp17 });
        tmp23 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp21 }, TNode<UintPtrT> { tmp22 });
        ca_.Branch(tmp23, &block24, std::vector<compiler::Node*> { phi_bb16_9, phi_bb16_10, phi_bb16_15, phi_bb16_16, phi_bb16_8, phi_bb16_8 }, &block25,
            std::vector<compiler::Node*> { phi_bb16_9, phi_bb16_10, phi_bb16_15, phi_bb16_16, phi_bb16_8, phi_bb16_8 });
    }

    TNode<UintPtrT> phi_bb17_8;
    TNode<UintPtrT> phi_bb17_9;
    TNode<UintPtrT> phi_bb17_10;
    TNode<UintPtrT> phi_bb17_15;
    TNode<UintPtrT> phi_bb17_16;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_8, &phi_bb17_9, &phi_bb17_10, &phi_bb17_15, &phi_bb17_16);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb24_9;
    TNode<UintPtrT> phi_bb24_10;
    TNode<UintPtrT> phi_bb24_15;
    TNode<UintPtrT> phi_bb24_16;
    TNode<UintPtrT> phi_bb24_23;
    TNode<UintPtrT> phi_bb24_24;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<Object> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<Object> tmp28;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_9, &phi_bb24_10, &phi_bb24_15, &phi_bb24_16, &phi_bb24_23, &phi_bb24_24);
        tmp24 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp20 });
        tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp16 }, TNode<IntPtrT> { tmp24 });
        std::tie(tmp26, tmp27) = NewReference_Object_0(state_, TNode<Object> { tmp15 }, TNode<IntPtrT> { tmp25 }).Flatten();
        tmp28 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp26, tmp27 });
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp13, tmp14 }, tmp28);
        ca_.Goto(&block11, tmp19, phi_bb24_9, phi_bb24_10);
    }

    TNode<UintPtrT> phi_bb25_9;
    TNode<UintPtrT> phi_bb25_10;
    TNode<UintPtrT> phi_bb25_15;
    TNode<UintPtrT> phi_bb25_16;
    TNode<UintPtrT> phi_bb25_23;
    TNode<UintPtrT> phi_bb25_24;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_9, &phi_bb25_10, &phi_bb25_15, &phi_bb25_16, &phi_bb25_23, &phi_bb25_24);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb7_8;
    TNode<UintPtrT> phi_bb7_9;
    TNode<UintPtrT> phi_bb7_10;
    TNode<BoolT> tmp29;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_8, &phi_bb7_9, &phi_bb7_10);
        tmp29 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb7_8 }, TNode<UintPtrT> { p_middle });
        ca_.Branch(tmp29, &block28, std::vector<compiler::Node*> { phi_bb7_8, phi_bb7_9, phi_bb7_10 }, &block29,
            std::vector<compiler::Node*> { phi_bb7_8, phi_bb7_9, phi_bb7_10 });
    }

    TNode<UintPtrT> phi_bb28_8;
    TNode<UintPtrT> phi_bb28_9;
    TNode<UintPtrT> phi_bb28_10;
    TNode<Object> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<UintPtrT> tmp35;
    TNode<BoolT> tmp36;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_8, &phi_bb28_9, &phi_bb28_10);
        std::tie(tmp30, tmp31, tmp32) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_source }).Flatten();
        tmp33 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb28_8 });
        tmp34 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp33 });
        tmp35 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp32 });
        tmp36 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp34 }, TNode<UintPtrT> { tmp35 });
        ca_.Branch(tmp36, &block35, std::vector<compiler::Node*> { phi_bb28_8, phi_bb28_9, phi_bb28_10, phi_bb28_8, phi_bb28_8 }, &block36,
            std::vector<compiler::Node*> { phi_bb28_8, phi_bb28_9, phi_bb28_10, phi_bb28_8, phi_bb28_8 });
    }

    TNode<UintPtrT> phi_bb35_8;
    TNode<UintPtrT> phi_bb35_9;
    TNode<UintPtrT> phi_bb35_10;
    TNode<UintPtrT> phi_bb35_15;
    TNode<UintPtrT> phi_bb35_16;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<Object> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<UintPtrT> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<BoolT> tmp49;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_8, &phi_bb35_9, &phi_bb35_10, &phi_bb35_15, &phi_bb35_16);
        tmp37 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp33 });
        tmp38 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp31 }, TNode<IntPtrT> { tmp37 });
        std::tie(tmp39, tmp40) = NewReference_Object_0(state_, TNode<Object> { tmp30 }, TNode<IntPtrT> { tmp38 }).Flatten();
        tmp41 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp39, tmp40 });
        tmp42 = UnsafeCast_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp41 });
        std::tie(tmp43, tmp44, tmp45) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_source }).Flatten();
        tmp46 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb35_9 });
        tmp47 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp46 });
        tmp48 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp45 });
        tmp49 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp47 }, TNode<UintPtrT> { tmp48 });
        ca_.Branch(tmp49, &block43, std::vector<compiler::Node*> { phi_bb35_8, phi_bb35_9, phi_bb35_10, phi_bb35_9, phi_bb35_9 }, &block44,
            std::vector<compiler::Node*> { phi_bb35_8, phi_bb35_9, phi_bb35_10, phi_bb35_9, phi_bb35_9 });
    }

    TNode<UintPtrT> phi_bb36_8;
    TNode<UintPtrT> phi_bb36_9;
    TNode<UintPtrT> phi_bb36_10;
    TNode<UintPtrT> phi_bb36_15;
    TNode<UintPtrT> phi_bb36_16;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_8, &phi_bb36_9, &phi_bb36_10, &phi_bb36_15, &phi_bb36_16);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb43_8;
    TNode<UintPtrT> phi_bb43_9;
    TNode<UintPtrT> phi_bb43_10;
    TNode<UintPtrT> phi_bb43_16;
    TNode<UintPtrT> phi_bb43_17;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<Object> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<Object> tmp54;
    TNode<Object> tmp55;
    TNode<Number> tmp56;
    TNode<Number> tmp57;
    TNode<BoolT> tmp58;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_8, &phi_bb43_9, &phi_bb43_10, &phi_bb43_16, &phi_bb43_17);
        tmp50 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp46 });
        tmp51 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp44 }, TNode<IntPtrT> { tmp50 });
        std::tie(tmp52, tmp53) = NewReference_Object_0(state_, TNode<Object> { tmp43 }, TNode<IntPtrT> { tmp51 }).Flatten();
        tmp54 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp52, tmp53 });
        tmp55 = UnsafeCast_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp54 });
        tmp56 = CallCompare_0(state_, TNode<Context> { p_context }, TNode<JSTypedArray> { p_array }, TNode<JSReceiver> { p_comparefn }, TNode<Object> { tmp42 },
            TNode<Object> { tmp55 });
        tmp57 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp58 = NumberIsLessThanOrEqual_0(state_, TNode<Number> { tmp56 }, TNode<Number> { tmp57 });
        ca_.Branch(tmp58, &block47, std::vector<compiler::Node*> { phi_bb43_8, phi_bb43_9, phi_bb43_10 }, &block48,
            std::vector<compiler::Node*> { phi_bb43_8, phi_bb43_9, phi_bb43_10 });
    }

    TNode<UintPtrT> phi_bb44_8;
    TNode<UintPtrT> phi_bb44_9;
    TNode<UintPtrT> phi_bb44_10;
    TNode<UintPtrT> phi_bb44_16;
    TNode<UintPtrT> phi_bb44_17;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_8, &phi_bb44_9, &phi_bb44_10, &phi_bb44_16, &phi_bb44_17);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb47_8;
    TNode<UintPtrT> phi_bb47_9;
    TNode<UintPtrT> phi_bb47_10;
    TNode<Object> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<UintPtrT> tmp63;
    TNode<UintPtrT> tmp64;
    TNode<BoolT> tmp65;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_8, &phi_bb47_9, &phi_bb47_10);
        std::tie(tmp59, tmp60, tmp61) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_target }).Flatten();
        tmp62 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb47_10 });
        tmp63 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp62 });
        tmp64 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp61 });
        tmp65 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp63 }, TNode<UintPtrT> { tmp64 });
        ca_.Branch(tmp65, &block54, std::vector<compiler::Node*> { phi_bb47_8, phi_bb47_9, phi_bb47_10, phi_bb47_10, phi_bb47_10 }, &block55,
            std::vector<compiler::Node*> { phi_bb47_8, phi_bb47_9, phi_bb47_10, phi_bb47_10, phi_bb47_10 });
    }

    TNode<UintPtrT> phi_bb54_8;
    TNode<UintPtrT> phi_bb54_9;
    TNode<UintPtrT> phi_bb54_10;
    TNode<UintPtrT> phi_bb54_17;
    TNode<UintPtrT> phi_bb54_18;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<Object> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<UintPtrT> tmp70;
    TNode<UintPtrT> tmp71;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_8, &phi_bb54_9, &phi_bb54_10, &phi_bb54_17, &phi_bb54_18);
        tmp66 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp62 });
        tmp67 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp60 }, TNode<IntPtrT> { tmp66 });
        std::tie(tmp68, tmp69) = NewReference_Object_0(state_, TNode<Object> { tmp59 }, TNode<IntPtrT> { tmp67 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp68, tmp69 }, tmp42);
        tmp70 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
        tmp71 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { phi_bb54_8 }, TNode<UintPtrT> { tmp70 });
        ca_.Goto(&block49, tmp71, phi_bb54_9, phi_bb54_10);
    }

    TNode<UintPtrT> phi_bb55_8;
    TNode<UintPtrT> phi_bb55_9;
    TNode<UintPtrT> phi_bb55_10;
    TNode<UintPtrT> phi_bb55_17;
    TNode<UintPtrT> phi_bb55_18;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_8, &phi_bb55_9, &phi_bb55_10, &phi_bb55_17, &phi_bb55_18);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb48_8;
    TNode<UintPtrT> phi_bb48_9;
    TNode<UintPtrT> phi_bb48_10;
    TNode<Object> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<UintPtrT> tmp76;
    TNode<UintPtrT> tmp77;
    TNode<BoolT> tmp78;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_8, &phi_bb48_9, &phi_bb48_10);
        std::tie(tmp72, tmp73, tmp74) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_target }).Flatten();
        tmp75 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb48_10 });
        tmp76 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp75 });
        tmp77 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp74 });
        tmp78 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp76 }, TNode<UintPtrT> { tmp77 });
        ca_.Branch(tmp78, &block62, std::vector<compiler::Node*> { phi_bb48_8, phi_bb48_9, phi_bb48_10, phi_bb48_10, phi_bb48_10 }, &block63,
            std::vector<compiler::Node*> { phi_bb48_8, phi_bb48_9, phi_bb48_10, phi_bb48_10, phi_bb48_10 });
    }

    TNode<UintPtrT> phi_bb62_8;
    TNode<UintPtrT> phi_bb62_9;
    TNode<UintPtrT> phi_bb62_10;
    TNode<UintPtrT> phi_bb62_17;
    TNode<UintPtrT> phi_bb62_18;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<Object> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<UintPtrT> tmp84;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_8, &phi_bb62_9, &phi_bb62_10, &phi_bb62_17, &phi_bb62_18);
        tmp79 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp75 });
        tmp80 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp73 }, TNode<IntPtrT> { tmp79 });
        std::tie(tmp81, tmp82) = NewReference_Object_0(state_, TNode<Object> { tmp72 }, TNode<IntPtrT> { tmp80 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp81, tmp82 }, tmp55);
        tmp83 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
        tmp84 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { phi_bb62_9 }, TNode<UintPtrT> { tmp83 });
        ca_.Goto(&block49, phi_bb62_8, tmp84, phi_bb62_10);
    }

    TNode<UintPtrT> phi_bb63_8;
    TNode<UintPtrT> phi_bb63_9;
    TNode<UintPtrT> phi_bb63_10;
    TNode<UintPtrT> phi_bb63_17;
    TNode<UintPtrT> phi_bb63_18;
    if (block63.is_used()) {
        ca_.Bind(&block63, &phi_bb63_8, &phi_bb63_9, &phi_bb63_10, &phi_bb63_17, &phi_bb63_18);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb49_8;
    TNode<UintPtrT> phi_bb49_9;
    TNode<UintPtrT> phi_bb49_10;
    if (block49.is_used()) {
        ca_.Bind(&block49, &phi_bb49_8, &phi_bb49_9, &phi_bb49_10);
        ca_.Goto(&block30, phi_bb49_8, phi_bb49_9, phi_bb49_10);
    }

    TNode<UintPtrT> phi_bb29_8;
    TNode<UintPtrT> phi_bb29_9;
    TNode<UintPtrT> phi_bb29_10;
    TNode<Object> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<UintPtrT> tmp89;
    TNode<UintPtrT> tmp90;
    TNode<BoolT> tmp91;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_8, &phi_bb29_9, &phi_bb29_10);
        std::tie(tmp85, tmp86, tmp87) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_target }).Flatten();
        tmp88 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb29_10 });
        tmp89 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp88 });
        tmp90 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp87 });
        tmp91 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp89 }, TNode<UintPtrT> { tmp90 });
        ca_.Branch(tmp91, &block74, std::vector<compiler::Node*> { phi_bb29_8, phi_bb29_9, phi_bb29_10, phi_bb29_10, phi_bb29_10 }, &block75,
            std::vector<compiler::Node*> { phi_bb29_8, phi_bb29_9, phi_bb29_10, phi_bb29_10, phi_bb29_10 });
    }

    TNode<UintPtrT> phi_bb74_8;
    TNode<UintPtrT> phi_bb74_9;
    TNode<UintPtrT> phi_bb74_10;
    TNode<UintPtrT> phi_bb74_15;
    TNode<UintPtrT> phi_bb74_16;
    TNode<IntPtrT> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<Object> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<Object> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<IntPtrT> tmp98;
    TNode<UintPtrT> tmp99;
    TNode<UintPtrT> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<UintPtrT> tmp102;
    TNode<UintPtrT> tmp103;
    TNode<BoolT> tmp104;
    if (block74.is_used()) {
        ca_.Bind(&block74, &phi_bb74_8, &phi_bb74_9, &phi_bb74_10, &phi_bb74_15, &phi_bb74_16);
        tmp92 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp88 });
        tmp93 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp86 }, TNode<IntPtrT> { tmp92 });
        std::tie(tmp94, tmp95) = NewReference_Object_0(state_, TNode<Object> { tmp85 }, TNode<IntPtrT> { tmp93 }).Flatten();
        std::tie(tmp96, tmp97, tmp98) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_source }).Flatten();
        tmp99 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
        tmp100 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { phi_bb74_9 }, TNode<UintPtrT> { tmp99 });
        tmp101 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb74_9 });
        tmp102 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp101 });
        tmp103 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp98 });
        tmp104 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp102 }, TNode<UintPtrT> { tmp103 });
        ca_.Branch(tmp104, &block82, std::vector<compiler::Node*> { phi_bb74_8, phi_bb74_10, phi_bb74_15, phi_bb74_16, phi_bb74_9, phi_bb74_9 }, &block83,
            std::vector<compiler::Node*> { phi_bb74_8, phi_bb74_10, phi_bb74_15, phi_bb74_16, phi_bb74_9, phi_bb74_9 });
    }

    TNode<UintPtrT> phi_bb75_8;
    TNode<UintPtrT> phi_bb75_9;
    TNode<UintPtrT> phi_bb75_10;
    TNode<UintPtrT> phi_bb75_15;
    TNode<UintPtrT> phi_bb75_16;
    if (block75.is_used()) {
        ca_.Bind(&block75, &phi_bb75_8, &phi_bb75_9, &phi_bb75_10, &phi_bb75_15, &phi_bb75_16);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb82_8;
    TNode<UintPtrT> phi_bb82_10;
    TNode<UintPtrT> phi_bb82_15;
    TNode<UintPtrT> phi_bb82_16;
    TNode<UintPtrT> phi_bb82_23;
    TNode<UintPtrT> phi_bb82_24;
    TNode<IntPtrT> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<Object> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<Object> tmp109;
    if (block82.is_used()) {
        ca_.Bind(&block82, &phi_bb82_8, &phi_bb82_10, &phi_bb82_15, &phi_bb82_16, &phi_bb82_23, &phi_bb82_24);
        tmp105 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp101 });
        tmp106 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp97 }, TNode<IntPtrT> { tmp105 });
        std::tie(tmp107, tmp108) = NewReference_Object_0(state_, TNode<Object> { tmp96 }, TNode<IntPtrT> { tmp106 }).Flatten();
        tmp109 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp107, tmp108 });
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp94, tmp95 }, tmp109);
        ca_.Goto(&block30, phi_bb82_8, tmp100, phi_bb82_10);
    }

    TNode<UintPtrT> phi_bb83_8;
    TNode<UintPtrT> phi_bb83_10;
    TNode<UintPtrT> phi_bb83_15;
    TNode<UintPtrT> phi_bb83_16;
    TNode<UintPtrT> phi_bb83_23;
    TNode<UintPtrT> phi_bb83_24;
    if (block83.is_used()) {
        ca_.Bind(&block83, &phi_bb83_8, &phi_bb83_10, &phi_bb83_15, &phi_bb83_16, &phi_bb83_23, &phi_bb83_24);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb30_8;
    TNode<UintPtrT> phi_bb30_9;
    TNode<UintPtrT> phi_bb30_10;
    if (block30.is_used()) {
        ca_.Bind(&block30, &phi_bb30_8, &phi_bb30_9, &phi_bb30_10);
        ca_.Goto(&block11, phi_bb30_8, phi_bb30_9, phi_bb30_10);
    }

    TNode<UintPtrT> phi_bb11_8;
    TNode<UintPtrT> phi_bb11_9;
    TNode<UintPtrT> phi_bb11_10;
    TNode<UintPtrT> tmp110;
    TNode<UintPtrT> tmp111;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_8, &phi_bb11_9, &phi_bb11_10);
        tmp110 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
        tmp111 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { phi_bb11_10 }, TNode<UintPtrT> { tmp110 });
        ca_.Goto(&block4, phi_bb11_8, phi_bb11_9, tmp111);
    }

    TNode<UintPtrT> phi_bb3_8;
    TNode<UintPtrT> phi_bb3_9;
    TNode<UintPtrT> phi_bb3_10;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_8, &phi_bb3_9, &phi_bb3_10);
        ca_.Goto(&block86);
    }

    ca_.Bind(&block86);
}

TF_BUILTIN(TypedArrayMergeSort, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<FixedArray> parameter1 = UncheckedParameter<FixedArray>(Descriptor::kSource);
    USE(parameter1);
    TNode<UintPtrT> parameter2 = UncheckedParameter<UintPtrT>(Descriptor::kFrom);
    USE(parameter2);
    TNode<UintPtrT> parameter3 = UncheckedParameter<UintPtrT>(Descriptor::kTo);
    USE(parameter3);
    TNode<FixedArray> parameter4 = UncheckedParameter<FixedArray>(Descriptor::kTarget);
    USE(parameter4);
    TNode<JSTypedArray> parameter5 = UncheckedParameter<JSTypedArray>(Descriptor::kArray);
    USE(parameter5);
    TNode<JSReceiver> parameter6 = UncheckedParameter<JSReceiver>(Descriptor::kComparefn);
    USE(parameter6);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<UintPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<UintPtrT> tmp5;
    TNode<BoolT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT> { parameter3 }, TNode<UintPtrT> { parameter2 });
        tmp1 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp2 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT> { tmp0 }, TNode<UintPtrT> { tmp1 });
        tmp3 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { parameter2 }, TNode<UintPtrT> { tmp2 });
        tmp4 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { parameter2 });
        tmp5 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp6 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { tmp4 }, TNode<UintPtrT> { tmp5 });
        ca_.Branch(tmp6, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp7;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp7 = ca_.CallBuiltin<Object>(Builtin::kTypedArrayMergeSort, parameter0, parameter4, parameter2, tmp3, parameter1, parameter5, parameter6);
        ca_.Goto(&block6);
    }

    TNode<UintPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<BoolT> tmp10;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp8 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT> { parameter3 }, TNode<UintPtrT> { tmp3 });
        tmp9 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp10 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { tmp8 }, TNode<UintPtrT> { tmp9 });
        ca_.Branch(tmp10, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp11;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp11 = ca_.CallBuiltin<Object>(Builtin::kTypedArrayMergeSort, parameter0, parameter4, tmp3, parameter3, parameter1, parameter5, parameter6);
        ca_.Goto(&block8);
    }

    TNode<Undefined> tmp12;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        TypedArrayMerge_0(state_, TNode<Context> { parameter0 }, TNode<JSTypedArray> { parameter5 }, TNode<JSReceiver> { parameter6 },
            TNode<FixedArray> { parameter1 }, TNode<UintPtrT> { parameter2 }, TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { parameter3 },
            TNode<FixedArray> { parameter4 });
        tmp12 = Undefined_0(state_);
        CodeStubAssembler(state_).Return(tmp12);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-sort.tq?l=81&c=1
TNode<JSTypedArray> TypedArraySortCommon_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<UintPtrT> p_len,
    TNode<HeapObject> p_comparefnArg, bool p_isSort)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, UintPtrT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp1 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { p_len }, TNode<UintPtrT> { tmp0 });
        ca_.Branch(tmp1, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        ca_.Goto(&block1, p_array);
    }

    TNode<Undefined> tmp2;
    TNode<BoolT> tmp3;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp2 = Undefined_0(state_);
        tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { p_comparefnArg }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block4, std::vector<compiler::Node*> {}, &block5, std::vector<compiler::Node*> {});
    }

    TNode<JSTypedArray> tmp4;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kTypedArraySortFast, p_context, p_array));
        ca_.Goto(&block1, tmp4);
    }

    TNode<UintPtrT> tmp5;
    TNode<BoolT> tmp6;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp5 = FromConstexpr_uintptr_constexpr_int31_0(state_, FixedArray::kMaxLength);
        tmp6 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { p_len }, TNode<UintPtrT> { tmp5 });
        ca_.Branch(tmp6, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kTypedArrayTooLargeToSort);
    }

    TNode<JSReceiver> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerLabel label8(&ca_);
        tmp7 = Cast_Callable_0(state_, TNode<HeapObject> { p_comparefnArg }, &label8);
        ca_.Goto(&block10);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block11);
        }
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Int32T> tmp9;
    TNode<BuiltinPtr> tmp10;
    TNode<BuiltinPtr> tmp11;
    TNode<BuiltinPtr> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<FixedArray> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<FixedArray> tmp16;
    TNode<UintPtrT> tmp17;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp9 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray> { p_array });
        std::tie(tmp10, tmp11, tmp12) = GetTypedArrayAccessor_0(state_, TNode<Int32T> { tmp9 }).Flatten();
        tmp13 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { p_len });
        tmp14 = CodeStubAssembler(state_).AllocateZeroedFixedArray(TNode<IntPtrT> { tmp13 });
        tmp15 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { p_len });
        tmp16 = CodeStubAssembler(state_).AllocateZeroedFixedArray(TNode<IntPtrT> { tmp15 });
        tmp17 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block14, tmp17);
    }

    TNode<UintPtrT> phi_bb14_10;
    TNode<BoolT> tmp18;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_10);
        tmp18 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb14_10 }, TNode<UintPtrT> { p_len });
        ca_.Branch(tmp18, &block12, std::vector<compiler::Node*> { phi_bb14_10 }, &block13, std::vector<compiler::Node*> { phi_bb14_10 });
    }

    TNode<UintPtrT> phi_bb12_10;
    TNode<Numeric> tmp19;
    TNode<Object> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<UintPtrT> tmp24;
    TNode<UintPtrT> tmp25;
    TNode<BoolT> tmp26;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_10);
        tmp19 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(
            Builtins::CallInterfaceDescriptorFor(ExampleBuiltinForTorqueFunctionPointerType(1)), tmp10, TNode<Object>(), p_array, phi_bb12_10));
        std::tie(tmp20, tmp21, tmp22) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp14 }).Flatten();
        tmp23 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb12_10 });
        tmp24 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp23 });
        tmp25 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp22 });
        tmp26 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp24 }, TNode<UintPtrT> { tmp25 });
        ca_.Branch(tmp26, &block21, std::vector<compiler::Node*> { phi_bb12_10, phi_bb12_10, phi_bb12_10 }, &block22,
            std::vector<compiler::Node*> { phi_bb12_10, phi_bb12_10, phi_bb12_10 });
    }

    TNode<UintPtrT> phi_bb21_10;
    TNode<UintPtrT> phi_bb21_16;
    TNode<UintPtrT> phi_bb21_17;
    TNode<IntPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<Object> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<Object> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<UintPtrT> tmp35;
    TNode<UintPtrT> tmp36;
    TNode<BoolT> tmp37;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_10, &phi_bb21_16, &phi_bb21_17);
        tmp27 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp23 });
        tmp28 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp21 }, TNode<IntPtrT> { tmp27 });
        std::tie(tmp29, tmp30) = NewReference_Object_0(state_, TNode<Object> { tmp20 }, TNode<IntPtrT> { tmp28 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp29, tmp30 }, tmp19);
        std::tie(tmp31, tmp32, tmp33) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp16 }).Flatten();
        tmp34 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb21_10 });
        tmp35 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp34 });
        tmp36 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp33 });
        tmp37 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp35 }, TNode<UintPtrT> { tmp36 });
        ca_.Branch(tmp37, &block29, std::vector<compiler::Node*> { phi_bb21_10, phi_bb21_10, phi_bb21_10 }, &block30,
            std::vector<compiler::Node*> { phi_bb21_10, phi_bb21_10, phi_bb21_10 });
    }

    TNode<UintPtrT> phi_bb22_10;
    TNode<UintPtrT> phi_bb22_16;
    TNode<UintPtrT> phi_bb22_17;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_10, &phi_bb22_16, &phi_bb22_17);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb29_10;
    TNode<UintPtrT> phi_bb29_16;
    TNode<UintPtrT> phi_bb29_17;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<Object> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<UintPtrT> tmp42;
    TNode<UintPtrT> tmp43;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_10, &phi_bb29_16, &phi_bb29_17);
        tmp38 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp34 });
        tmp39 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp32 }, TNode<IntPtrT> { tmp38 });
        std::tie(tmp40, tmp41) = NewReference_Object_0(state_, TNode<Object> { tmp31 }, TNode<IntPtrT> { tmp39 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp40, tmp41 }, tmp19);
        tmp42 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
        tmp43 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { phi_bb29_10 }, TNode<UintPtrT> { tmp42 });
        ca_.Goto(&block14, tmp43);
    }

    TNode<UintPtrT> phi_bb30_10;
    TNode<UintPtrT> phi_bb30_16;
    TNode<UintPtrT> phi_bb30_17;
    if (block30.is_used()) {
        ca_.Bind(&block30, &phi_bb30_10, &phi_bb30_16, &phi_bb30_17);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb13_10;
    TNode<UintPtrT> tmp44;
    TNode<Object> tmp45;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_10);
        tmp44 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp45 = ca_.CallBuiltin<Object>(Builtin::kTypedArrayMergeSort, p_context, tmp16, tmp44, p_len, tmp14, p_array, tmp7);
        if ((p_isSort)) {
            ca_.Goto(&block33);
        } else {
            ca_.Goto(&block34);
        }
    }

    TNode<UintPtrT> tmp46;
    if (block33.is_used()) {
        ca_.Bind(&block33);
        compiler::CodeAssemblerLabel label47(&ca_);
        tmp46 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray> { p_array }, &label47);
        ca_.Goto(&block38);
        if (label47.is_used()) {
            ca_.Bind(&label47);
            ca_.Goto(&block39);
        }
    }

    TNode<UintPtrT> tmp48;
    if (block39.is_used()) {
        ca_.Bind(&block39);
        tmp48 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block36, tmp48);
    }

    TNode<BoolT> tmp49;
    if (block38.is_used()) {
        ca_.Bind(&block38);
        tmp49 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp46 }, TNode<UintPtrT> { p_len });
        ca_.Branch(tmp49, &block40, std::vector<compiler::Node*> {}, &block41, std::vector<compiler::Node*> { p_len });
    }

    if (block40.is_used()) {
        ca_.Bind(&block40);
        ca_.Goto(&block41, tmp46);
    }

    TNode<UintPtrT> phi_bb41_10;
    if (block41.is_used()) {
        ca_.Bind(&block41, &phi_bb41_10);
        ca_.Goto(&block36, phi_bb41_10);
    }

    TNode<UintPtrT> phi_bb36_10;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_10);
        ca_.Goto(&block35, phi_bb36_10);
    }

    if (block34.is_used()) {
        ca_.Bind(&block34);
        ca_.Goto(&block35, p_len);
    }

    TNode<UintPtrT> phi_bb35_10;
    TNode<UintPtrT> tmp50;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_10);
        tmp50 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block52, phi_bb35_10, tmp50);
    }

    TNode<UintPtrT> phi_bb52_10;
    TNode<UintPtrT> phi_bb52_11;
    TNode<BoolT> tmp51;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_10, &phi_bb52_11);
        tmp51 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb52_11 }, TNode<UintPtrT> { phi_bb52_10 });
        ca_.Branch(
            tmp51, &block50, std::vector<compiler::Node*> { phi_bb52_10, phi_bb52_11 }, &block51, std::vector<compiler::Node*> { phi_bb52_10, phi_bb52_11 });
    }

    TNode<UintPtrT> phi_bb50_10;
    TNode<UintPtrT> phi_bb50_11;
    TNode<Object> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<UintPtrT> tmp56;
    TNode<UintPtrT> tmp57;
    TNode<BoolT> tmp58;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_10, &phi_bb50_11);
        std::tie(tmp52, tmp53, tmp54) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp14 }).Flatten();
        tmp55 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { phi_bb50_11 });
        tmp56 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp55 });
        tmp57 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp54 });
        tmp58 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp56 }, TNode<UintPtrT> { tmp57 });
        ca_.Branch(tmp58, &block58, std::vector<compiler::Node*> { phi_bb50_10, phi_bb50_11, phi_bb50_11, phi_bb50_11, phi_bb50_11 }, &block59,
            std::vector<compiler::Node*> { phi_bb50_10, phi_bb50_11, phi_bb50_11, phi_bb50_11, phi_bb50_11 });
    }

    TNode<UintPtrT> phi_bb58_10;
    TNode<UintPtrT> phi_bb58_11;
    TNode<UintPtrT> phi_bb58_17;
    TNode<UintPtrT> phi_bb58_22;
    TNode<UintPtrT> phi_bb58_23;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<Object> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<Object> tmp63;
    TNode<Numeric> tmp64;
    TNode<Smi> tmp65;
    TNode<UintPtrT> tmp66;
    TNode<UintPtrT> tmp67;
    if (block58.is_used()) {
        ca_.Bind(&block58, &phi_bb58_10, &phi_bb58_11, &phi_bb58_17, &phi_bb58_22, &phi_bb58_23);
        tmp59 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp55 });
        tmp60 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp53 }, TNode<IntPtrT> { tmp59 });
        std::tie(tmp61, tmp62) = NewReference_Object_0(state_, TNode<Object> { tmp52 }, TNode<IntPtrT> { tmp60 }).Flatten();
        tmp63 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp61, tmp62 });
        tmp64 = UnsafeCast_Numeric_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp63 });
        tmp65 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(
            Builtins::CallInterfaceDescriptorFor(ExampleBuiltinForTorqueFunctionPointerType(2)), tmp11, p_context, p_array, phi_bb58_17, tmp64));
        tmp66 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
        tmp67 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { phi_bb58_11 }, TNode<UintPtrT> { tmp66 });
        ca_.Goto(&block52, phi_bb58_10, tmp67);
    }

    TNode<UintPtrT> phi_bb59_10;
    TNode<UintPtrT> phi_bb59_11;
    TNode<UintPtrT> phi_bb59_17;
    TNode<UintPtrT> phi_bb59_22;
    TNode<UintPtrT> phi_bb59_23;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_10, &phi_bb59_11, &phi_bb59_17, &phi_bb59_22, &phi_bb59_23);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb51_10;
    TNode<UintPtrT> phi_bb51_11;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_10, &phi_bb51_11);
        ca_.Goto(&block1, p_array);
    }

    TNode<JSTypedArray> phi_bb1_4;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_4);
        ca_.Goto(&block67, phi_bb1_4);
    }

    TNode<JSTypedArray> phi_bb67_4;
    ca_.Bind(&block67, &phi_bb67_4);
    return TNode<JSTypedArray> { phi_bb67_4 };
}

TF_BUILTIN(TypedArrayPrototypeSort, CodeStubAssembler)
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
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    TNode<HeapObject> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp0 });
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_1(
            state_, TNode<Context> { parameter0 }, TNode<Object> { tmp1 }, &label3);
        ca_.Goto(&block3);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { parameter0 }, MessageTemplate::kBadSortComparisonFunction, TNode<Object> { tmp1 });
    }

    TNode<UintPtrT> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<JSTypedArray> tmp6;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArrayAndGetLength(
            TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, kBuiltinNameSort_0(state_));
        tmp5 = UnsafeCast_JSTypedArray_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp6 = TypedArraySortCommon_0(
            state_, TNode<Context> { parameter0 }, TNode<JSTypedArray> { tmp5 }, TNode<UintPtrT> { tmp4 }, TNode<HeapObject> { tmp2 }, true);
        arguments.PopAndReturn(tmp6);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-sort.tq?l=146&c=28
TNode<Numeric> UnsafeCast_Numeric_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Numeric> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Numeric> { tmp0 };
}

} // namespace internal
} // namespace v8
