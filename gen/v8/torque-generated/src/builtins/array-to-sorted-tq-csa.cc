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
#include "torque-generated/src/builtins/array-to-sorted-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-to-sorted-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/third_party/v8/builtins/array-sort-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-sorted.tq?l=6&c=1
TNode<JSArray> CopyWorkArrayToNewFastJSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<SortState> p_sortState,
    ElementsKind p_elementsKind, TNode<Smi> p_numberOfNonUndefined)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<FixedArrayBase> tmp3;
    TNode<FixedArray> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<FixedArray> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 60);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_sortState, tmp0 });
        tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi> { tmp1 });
        tmp3 = CodeStubAssembler(state_).AllocateFixedArray(p_elementsKind, TNode<IntPtrT> { tmp2 });
        tmp4 = UnsafeCast_FixedArray_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp3 });
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 52);
        tmp6 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { p_sortState, tmp5 });
        tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi> { p_numberOfNonUndefined });
        tmp8 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp9 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).CopyElements(p_elementsKind, TNode<FixedArrayBase> { tmp4 }, TNode<IntPtrT> { tmp8 }, TNode<FixedArrayBase> { tmp6 },
            TNode<IntPtrT> { tmp9 }, TNode<IntPtrT> { tmp7 });
        ca_.Goto(&block23, p_numberOfNonUndefined);
    }

    TNode<Smi> phi_bb23_6;
    TNode<BoolT> tmp10;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_6);
        tmp10 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi> { phi_bb23_6 }, TNode<Smi> { tmp1 });
        ca_.Branch(tmp10, &block21, std::vector<compiler::Node*> { phi_bb23_6 }, &block22, std::vector<compiler::Node*> { phi_bb23_6 });
    }

    TNode<Smi> phi_bb21_6;
    TNode<Object> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<UintPtrT> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<BoolT> tmp17;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_6);
        std::tie(tmp11, tmp12, tmp13) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp4 }).Flatten();
        tmp14 = Convert_intptr_Smi_0(state_, TNode<Smi> { phi_bb21_6 });
        tmp15 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp14 });
        tmp16 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp13 });
        tmp17 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp15 }, TNode<UintPtrT> { tmp16 });
        ca_.Branch(tmp17, &block29, std::vector<compiler::Node*> { phi_bb21_6, phi_bb21_6, phi_bb21_6 }, &block30,
            std::vector<compiler::Node*> { phi_bb21_6, phi_bb21_6, phi_bb21_6 });
    }

    TNode<Smi> phi_bb29_6;
    TNode<Smi> phi_bb29_11;
    TNode<Smi> phi_bb29_12;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<Object> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Undefined> tmp22;
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_6, &phi_bb29_11, &phi_bb29_12);
        tmp18 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp14 });
        tmp19 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp12 }, TNode<IntPtrT> { tmp18 });
        std::tie(tmp20, tmp21) = NewReference_Object_0(state_, TNode<Object> { tmp11 }, TNode<IntPtrT> { tmp19 }).Flatten();
        tmp22 = Undefined_0(state_);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp20, tmp21 }, tmp22);
        tmp23 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
        tmp24 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { phi_bb29_6 }, TNode<Smi> { tmp23 });
        ca_.Goto(&block23, tmp24);
    }

    TNode<Smi> phi_bb30_6;
    TNode<Smi> phi_bb30_11;
    TNode<Smi> phi_bb30_12;
    if (block30.is_used()) {
        ca_.Bind(&block30, &phi_bb30_6, &phi_bb30_11, &phi_bb30_12);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Smi> phi_bb22_6;
    TNode<NativeContext> tmp25;
    TNode<Map> tmp26;
    TNode<JSArray> tmp27;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_6);
        tmp25 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context> { p_context });
        tmp26 = CodeStubAssembler(state_).LoadJSArrayElementsMap(p_elementsKind, TNode<NativeContext> { tmp25 });
        tmp27 = NewJSArray_0(state_, TNode<Context> { p_context }, TNode<Map> { tmp26 }, TNode<FixedArrayBase> { tmp4 });
        ca_.Goto(&block33);
    }

    ca_.Bind(&block33);
    return TNode<JSArray> { tmp27 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-sorted.tq?l=36&c=1
TNode<JSArray> CopyWorkArrayToNewJSArray_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<SortState> p_sortState, TNode<Smi> p_numberOfNonUndefined)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<FixedArray> tmp3;
    TNode<JSArray> tmp4;
    TNode<Smi> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 60);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_sortState, tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 52);
        tmp3 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { p_sortState, tmp2 });
        tmp4 = CodeStubAssembler(state_).ArrayCreate(TNode<Context> { p_context }, TNode<Number> { tmp1 });
        tmp5 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block8, tmp5);
    }

    TNode<Smi> phi_bb8_6;
    TNode<BoolT> tmp6;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_6);
        tmp6 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi> { phi_bb8_6 }, TNode<Smi> { p_numberOfNonUndefined });
        ca_.Branch(tmp6, &block6, std::vector<compiler::Node*> { phi_bb8_6 }, &block7, std::vector<compiler::Node*> { phi_bb8_6 });
    }

    TNode<Smi> phi_bb6_6;
    TNode<Object> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<BoolT> tmp13;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_6);
        std::tie(tmp7, tmp8, tmp9) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp3 }).Flatten();
        tmp10 = Convert_intptr_Smi_0(state_, TNode<Smi> { phi_bb6_6 });
        tmp11 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp10 });
        tmp12 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp9 });
        tmp13 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp11 }, TNode<UintPtrT> { tmp12 });
        ca_.Branch(tmp13, &block14, std::vector<compiler::Node*> { phi_bb6_6, phi_bb6_6, phi_bb6_6, phi_bb6_6 }, &block15,
            std::vector<compiler::Node*> { phi_bb6_6, phi_bb6_6, phi_bb6_6, phi_bb6_6 });
    }

    TNode<Smi> phi_bb14_6;
    TNode<Smi> phi_bb14_8;
    TNode<Smi> phi_bb14_13;
    TNode<Smi> phi_bb14_14;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<Object> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Smi> tmp21;
    TNode<Smi> tmp22;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_6, &phi_bb14_8, &phi_bb14_13, &phi_bb14_14);
        tmp14 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp10 });
        tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp8 }, TNode<IntPtrT> { tmp14 });
        std::tie(tmp16, tmp17) = NewReference_Object_0(state_, TNode<Object> { tmp7 }, TNode<IntPtrT> { tmp15 }).Flatten();
        tmp18 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp16, tmp17 });
        tmp19 = UnsafeCast_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp18 });
        tmp20 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, p_context, tmp4, phi_bb14_8, tmp19);
        tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
        tmp22 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { phi_bb14_6 }, TNode<Smi> { tmp21 });
        ca_.Goto(&block8, tmp22);
    }

    TNode<Smi> phi_bb15_6;
    TNode<Smi> phi_bb15_8;
    TNode<Smi> phi_bb15_13;
    TNode<Smi> phi_bb15_14;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_6, &phi_bb15_8, &phi_bb15_13, &phi_bb15_14);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Smi> phi_bb7_6;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_6);
        ca_.Goto(&block20, phi_bb7_6);
    }

    TNode<Smi> phi_bb20_6;
    TNode<BoolT> tmp23;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_6);
        tmp23 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi> { phi_bb20_6 }, TNode<Smi> { tmp1 });
        ca_.Branch(tmp23, &block18, std::vector<compiler::Node*> { phi_bb20_6 }, &block19, std::vector<compiler::Node*> { phi_bb20_6 });
    }

    TNode<Smi> phi_bb18_6;
    TNode<Undefined> tmp24;
    TNode<Object> tmp25;
    TNode<Smi> tmp26;
    TNode<Smi> tmp27;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_6);
        tmp24 = Undefined_0(state_);
        tmp25 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, p_context, tmp4, phi_bb18_6, tmp24);
        tmp26 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
        tmp27 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { phi_bb18_6 }, TNode<Smi> { tmp26 });
        ca_.Goto(&block20, tmp27);
    }

    TNode<Smi> phi_bb19_6;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_6);
        ca_.Goto(&block22);
    }

    ca_.Bind(&block22);
    return TNode<JSArray> { tmp4 };
}

TF_BUILTIN(ArrayTimSortIntoCopy, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<SortState> parameter1 = UncheckedParameter<SortState>(Descriptor::kSortState);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    TNode<BoolT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CompactReceiverElementsIntoWorkArray_0(state_, TNode<Context> { parameter0 }, TNode<SortState> { parameter1 }, true);
        ArrayTimSortImpl_0(state_, TNode<Context> { parameter0 }, TNode<SortState> { parameter1 }, TNode<Smi> { tmp0 });
        tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 60);
        tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { parameter1, tmp1 });
        tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, JSArray::kMaxFastArrayLength);
        tmp4 = CodeStubAssembler(state_).SmiLessThanOrEqual(TNode<Smi> { tmp2 }, TNode<Smi> { tmp3 });
        ca_.Branch(tmp4, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp5;
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    TNode<BoolT> tmp8;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 64);
        tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { parameter1, tmp5 });
        tmp7 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp8 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi> { tmp6 }, TNode<Smi> { tmp7 });
        ca_.Branch(tmp8, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block4);
    }

    TNode<IntPtrT> tmp9;
    TNode<FixedArray> tmp10;
    TNode<Smi> tmp11;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 52);
        tmp10 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { parameter1, tmp9 });
        tmp11 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block13, tmp11);
    }

    TNode<Smi> phi_bb13_4;
    TNode<BoolT> tmp12;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_4);
        tmp12 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi> { phi_bb13_4 }, TNode<Smi> { tmp0 });
        ca_.Branch(tmp12, &block11, std::vector<compiler::Node*> { phi_bb13_4 }, &block12, std::vector<compiler::Node*> { phi_bb13_4 });
    }

    TNode<Smi> phi_bb11_4;
    TNode<Object> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<UintPtrT> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<BoolT> tmp19;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_4);
        std::tie(tmp13, tmp14, tmp15) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp10 }).Flatten();
        tmp16 = Convert_intptr_Smi_0(state_, TNode<Smi> { phi_bb11_4 });
        tmp17 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp16 });
        tmp18 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp15 });
        tmp19 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp17 }, TNode<UintPtrT> { tmp18 });
        ca_.Branch(tmp19, &block19, std::vector<compiler::Node*> { phi_bb11_4, phi_bb11_4, phi_bb11_4 }, &block20,
            std::vector<compiler::Node*> { phi_bb11_4, phi_bb11_4, phi_bb11_4 });
    }

    TNode<Smi> phi_bb19_4;
    TNode<Smi> phi_bb19_9;
    TNode<Smi> phi_bb19_10;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Object> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<BoolT> tmp26;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_4, &phi_bb19_9, &phi_bb19_10);
        tmp20 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp16 });
        tmp21 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp14 }, TNode<IntPtrT> { tmp20 });
        std::tie(tmp22, tmp23) = NewReference_Object_0(state_, TNode<Object> { tmp13 }, TNode<IntPtrT> { tmp21 }).Flatten();
        tmp24 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp22, tmp23 });
        tmp25 = UnsafeCast_JSAny_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp24 });
        tmp26 = CodeStubAssembler(state_).TaggedIsNotSmi(TNode<Object> { tmp25 });
        ca_.Branch(tmp26, &block23, std::vector<compiler::Node*> { phi_bb19_4 }, &block24, std::vector<compiler::Node*> { phi_bb19_4 });
    }

    TNode<Smi> phi_bb20_4;
    TNode<Smi> phi_bb20_9;
    TNode<Smi> phi_bb20_10;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_4, &phi_bb20_9, &phi_bb20_10);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Smi> phi_bb23_4;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_4);
        ca_.Goto(&block4);
    }

    TNode<Smi> phi_bb24_4;
    TNode<Smi> tmp27;
    TNode<Smi> tmp28;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_4);
        tmp27 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
        tmp28 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { phi_bb24_4 }, TNode<Smi> { tmp27 });
        ca_.Goto(&block13, tmp28);
    }

    TNode<Smi> phi_bb12_4;
    TNode<JSArray> tmp29;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_4);
        tmp29 = CopyWorkArrayToNewFastJSArray_0(
            state_, TNode<Context> { parameter0 }, TNode<SortState> { parameter1 }, ElementsKind::PACKED_SMI_ELEMENTS, TNode<Smi> { tmp0 });
        CodeStubAssembler(state_).Return(tmp29);
    }

    TNode<JSArray> tmp30;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp30 = CopyWorkArrayToNewFastJSArray_0(
            state_, TNode<Context> { parameter0 }, TNode<SortState> { parameter1 }, ElementsKind::PACKED_ELEMENTS, TNode<Smi> { tmp0 });
        CodeStubAssembler(state_).Return(tmp30);
    }

    TNode<JSArray> tmp31;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp31 = CopyWorkArrayToNewJSArray_0(state_, TNode<Context> { parameter0 }, TNode<SortState> { parameter1 }, TNode<Smi> { tmp0 });
        CodeStubAssembler(state_).Return(tmp31);
    }
}

TF_BUILTIN(ArrayPrototypeToSorted, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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

    TNode<JSReceiver> tmp4;
    TNode<Number> tmp5;
    TNode<Number> tmp6;
    TNode<BoolT> tmp7;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = ca_.CallBuiltin<JSReceiver>(Builtin::kToObject, parameter0, parameter1);
        tmp5 = GetLengthProperty_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp4 });
        tmp6 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp7 = IsNumberEqual_0(state_, TNode<Number> { tmp5 }, TNode<Number> { tmp6 });
        ca_.Branch(tmp7, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp8;
    TNode<JSArray> tmp9;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp8 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp9 = CodeStubAssembler(state_).ArrayCreate(TNode<Context> { parameter0 }, TNode<Number> { tmp8 });
        arguments.PopAndReturn(tmp9);
    }

    TNode<Number> tmp10;
    TNode<BoolT> tmp11;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp10 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp11 = IsNumberEqual_0(state_, TNode<Number> { tmp5 }, TNode<Number> { tmp10 });
        ca_.Branch(tmp11, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp12;
    TNode<JSArray> tmp13;
    TNode<Smi> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp12 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp13 = CodeStubAssembler(state_).ArrayCreate(TNode<Context> { parameter0 }, TNode<Number> { tmp12 });
        tmp14 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp15 = CodeStubAssembler(state_).GetProperty(TNode<Context> { parameter0 }, TNode<Object> { tmp4 }, TNode<Object> { tmp14 });
        tmp16 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, parameter0, tmp13, tmp14, tmp15);
        arguments.PopAndReturn(tmp13);
    }

    TNode<Number> tmp17;
    TNode<BoolT> tmp18;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp17 = FromConstexpr_Number_constexpr_uint32_0(state_, JSArray::kMaxArrayLength);
        tmp18 = NumberIsGreaterThan_0(state_, TNode<Number> { tmp5 }, TNode<Number> { tmp17 });
        ca_.Branch(tmp18, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { parameter0 }, MessageTemplate::kInvalidArrayLength, TNode<Object> { tmp5 });
    }

    TNode<SortState> tmp19;
    TNode<JSArray> tmp20;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp19 = NewSortState_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp4 }, TNode<HeapObject> { tmp2 }, TNode<Number> { tmp5 }, true);
        tmp20 = ca_.CallBuiltin<JSArray>(Builtin::kArrayTimSortIntoCopy, parameter0, tmp19);
        arguments.PopAndReturn(tmp20);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-sorted.tq?l=93&c=21
TNode<HeapObject> Cast_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_1(
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

    TNode<HeapObject> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0(
            state_, TNode<HeapObject> { tmp0 }, &label3);
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
    return TNode<HeapObject> { tmp2 };
}

} // namespace internal
} // namespace v8
