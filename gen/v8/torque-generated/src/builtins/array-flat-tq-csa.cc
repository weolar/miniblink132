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
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=7&c=1
TNode<Boolean> ArrayIsArray_Inline_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_element)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Boolean> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Boolean> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Is_JSArray_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { p_element });
        ca_.Branch(tmp0, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<True> tmp1;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp1 = True_0(state_);
        ca_.Goto(&block1, tmp1);
    }

    TNode<BoolT> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp2 = Is_JSProxy_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { p_element });
        ca_.Branch(tmp2, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp3;
    TNode<Boolean> tmp4;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp3 = CodeStubAssembler(state_).CallRuntime(Runtime::kArrayIsArray, p_context, p_element);
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = Cast_Boolean_0(state_, TNode<Object> { tmp3 }, &label5);
        ca_.Goto(&block10);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block11);
        }
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        CodeStubAssembler(state_).Unreachable();
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block1, tmp4);
    }

    TNode<False> tmp6;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp6 = False_0(state_);
        ca_.Goto(&block1, tmp6);
    }

    TNode<Boolean> phi_bb1_2;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_2);
        ca_.Goto(&block12, phi_bb1_2);
    }

    TNode<Boolean> phi_bb12_2;
    ca_.Bind(&block12, &phi_bb12_2);
    return TNode<Boolean> { phi_bb12_2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=19&c=1
TNode<Number> FlattenIntoArrayFast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_target, TNode<JSReceiver> p_source,
    TNode<Number> p_sourceLength, TNode<Number> p_start, TNode<Smi> p_depth, bool p_hasMapper, TNode<Object> p_mapfn, TNode<Object> p_thisArgs,
    compiler::CodeAssemblerLabel* label_Bailout, compiler::TypedCodeAssemblerVariable<Number>* label_Bailout_parameter_0,
    compiler::TypedCodeAssemblerVariable<Number>* label_Bailout_parameter_1)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, JSArray> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, JSArray> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, JSArray> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, JSArray> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, JSArray> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, JSArray> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, JSArray> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Smi, Smi> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Smi, Smi, Smi> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Smi, Smi, Smi> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Smi, Smi> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Smi, Smi, Smi> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Smi, Smi, Smi> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Smi, Smi, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block61(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, Boolean, Number> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Smi, JSArray> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    TNode<JSArray> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_FastJSArray_0(state_, TNode<Context> { p_context }, TNode<HeapObject> { p_source }, &label2);
        ca_.Goto(&block5);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block1, p_start, tmp0);
    }

    TNode<JSArray> tmp3;
    TNode<JSArray> tmp4;
    TNode<Map> tmp5;
    TNode<BoolT> tmp6;
    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    TNode<Smi> tmp9;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        std::tie(tmp3, tmp4, tmp5, tmp6, tmp7, tmp8) = NewFastJSArrayWitness_0(state_, TNode<JSArray> { tmp1 }).Flatten();
        tmp9 = UnsafeCast_Smi_0(state_, TNode<Context> { p_context }, TNode<Object> { p_sourceLength });
        ca_.Goto(&block13, p_start, tmp0, tmp4);
    }

    TNode<Number> phi_bb13_8;
    TNode<Smi> phi_bb13_9;
    TNode<JSArray> phi_bb13_12;
    TNode<BoolT> tmp10;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_8, &phi_bb13_9, &phi_bb13_12);
        tmp10 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi> { phi_bb13_9 }, TNode<Smi> { tmp9 });
        ca_.Branch(tmp10, &block11, std::vector<compiler::Node*> { phi_bb13_8, phi_bb13_9, phi_bb13_12 }, &block12,
            std::vector<compiler::Node*> { phi_bb13_8, phi_bb13_9, phi_bb13_12 });
    }

    TNode<Number> phi_bb11_8;
    TNode<Smi> phi_bb11_9;
    TNode<JSArray> phi_bb11_12;
    TNode<IntPtrT> tmp11;
    TNode<Map> tmp12;
    TNode<BoolT> tmp13;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_8, &phi_bb11_9, &phi_bb11_12);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp12 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp3, tmp11 });
        tmp13 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp12 }, TNode<HeapObject> { tmp5 });
        ca_.Branch(tmp13, &block18, std::vector<compiler::Node*> { phi_bb11_8, phi_bb11_9, phi_bb11_12 }, &block19,
            std::vector<compiler::Node*> { phi_bb11_8, phi_bb11_9, phi_bb11_12 });
    }

    TNode<Number> phi_bb18_8;
    TNode<Smi> phi_bb18_9;
    TNode<JSArray> phi_bb18_12;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_8, &phi_bb18_9, &phi_bb18_12);
        ca_.Goto(&block16, phi_bb18_8, phi_bb18_9, phi_bb18_12);
    }

    TNode<Number> phi_bb19_8;
    TNode<Smi> phi_bb19_9;
    TNode<JSArray> phi_bb19_12;
    TNode<BoolT> tmp14;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_8, &phi_bb19_9, &phi_bb19_12);
        tmp14 = CodeStubAssembler(state_).IsNoElementsProtectorCellInvalid();
        ca_.Branch(tmp14, &block20, std::vector<compiler::Node*> { phi_bb19_8, phi_bb19_9, phi_bb19_12 }, &block21,
            std::vector<compiler::Node*> { phi_bb19_8, phi_bb19_9, phi_bb19_12 });
    }

    TNode<Number> phi_bb20_8;
    TNode<Smi> phi_bb20_9;
    TNode<JSArray> phi_bb20_12;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_8, &phi_bb20_9, &phi_bb20_12);
        ca_.Goto(&block16, phi_bb20_8, phi_bb20_9, phi_bb20_12);
    }

    TNode<Number> phi_bb21_8;
    TNode<Smi> phi_bb21_9;
    TNode<JSArray> phi_bb21_12;
    TNode<JSArray> tmp15;
    TNode<Smi> tmp16;
    TNode<BoolT> tmp17;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_8, &phi_bb21_9, &phi_bb21_12);
        tmp15 = (TNode<JSArray> { tmp3 });
        tmp16 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray> { tmp15 });
        tmp17 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi> { phi_bb21_9 }, TNode<Smi> { tmp16 });
        ca_.Branch(tmp17, &block22, std::vector<compiler::Node*> { phi_bb21_8, phi_bb21_9 }, &block23, std::vector<compiler::Node*> { phi_bb21_8, phi_bb21_9 });
    }

    TNode<Number> phi_bb16_8;
    TNode<Smi> phi_bb16_9;
    TNode<JSArray> phi_bb16_12;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_8, &phi_bb16_9, &phi_bb16_12);
        ca_.Goto(&block1, phi_bb16_8, phi_bb16_9);
    }

    TNode<Number> phi_bb22_8;
    TNode<Smi> phi_bb22_9;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_8, &phi_bb22_9);
        ca_.Goto(&block1, phi_bb22_8, phi_bb22_9);
    }

    TNode<Number> phi_bb23_8;
    TNode<Smi> phi_bb23_9;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_8, &phi_bb23_9);
        ca_.Branch(tmp6, &block28, std::vector<compiler::Node*> { phi_bb23_8, phi_bb23_9, phi_bb23_9, phi_bb23_9 }, &block29,
            std::vector<compiler::Node*> { phi_bb23_8, phi_bb23_9, phi_bb23_9, phi_bb23_9 });
    }

    TNode<Number> phi_bb28_8;
    TNode<Smi> phi_bb28_9;
    TNode<Smi> phi_bb28_18;
    TNode<Smi> phi_bb28_21;
    TNode<Object> tmp18;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_8, &phi_bb28_9, &phi_bb28_18, &phi_bb28_21);
        compiler::CodeAssemblerLabel label19(&ca_);
        tmp18 = LoadElementNoHole_FixedDoubleArray_0(state_, TNode<Context> { p_context }, TNode<JSArray> { tmp15 }, TNode<Smi> { phi_bb28_21 }, &label19);
        ca_.Goto(&block31, phi_bb28_8, phi_bb28_9, phi_bb28_18, phi_bb28_21, phi_bb28_21);
        if (label19.is_used()) {
            ca_.Bind(&label19);
            ca_.Goto(&block32, phi_bb28_8, phi_bb28_9, phi_bb28_18, phi_bb28_21, phi_bb28_21);
        }
    }

    TNode<Number> phi_bb32_8;
    TNode<Smi> phi_bb32_9;
    TNode<Smi> phi_bb32_18;
    TNode<Smi> phi_bb32_21;
    TNode<Smi> phi_bb32_23;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_8, &phi_bb32_9, &phi_bb32_18, &phi_bb32_21, &phi_bb32_23);
        ca_.Goto(&block26, phi_bb32_8, phi_bb32_9);
    }

    TNode<Number> phi_bb31_8;
    TNode<Smi> phi_bb31_9;
    TNode<Smi> phi_bb31_18;
    TNode<Smi> phi_bb31_21;
    TNode<Smi> phi_bb31_23;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_8, &phi_bb31_9, &phi_bb31_18, &phi_bb31_21, &phi_bb31_23);
        ca_.Goto(&block27, phi_bb31_8, phi_bb31_9, phi_bb31_18, phi_bb31_21, tmp18);
    }

    TNode<Number> phi_bb29_8;
    TNode<Smi> phi_bb29_9;
    TNode<Smi> phi_bb29_18;
    TNode<Smi> phi_bb29_21;
    TNode<Object> tmp20;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_8, &phi_bb29_9, &phi_bb29_18, &phi_bb29_21);
        compiler::CodeAssemblerLabel label21(&ca_);
        tmp20 = LoadElementNoHole_FixedArray_0(state_, TNode<Context> { p_context }, TNode<JSArray> { tmp15 }, TNode<Smi> { phi_bb29_21 }, &label21);
        ca_.Goto(&block33, phi_bb29_8, phi_bb29_9, phi_bb29_18, phi_bb29_21, phi_bb29_21);
        if (label21.is_used()) {
            ca_.Bind(&label21);
            ca_.Goto(&block34, phi_bb29_8, phi_bb29_9, phi_bb29_18, phi_bb29_21, phi_bb29_21);
        }
    }

    TNode<Number> phi_bb34_8;
    TNode<Smi> phi_bb34_9;
    TNode<Smi> phi_bb34_18;
    TNode<Smi> phi_bb34_21;
    TNode<Smi> phi_bb34_23;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_8, &phi_bb34_9, &phi_bb34_18, &phi_bb34_21, &phi_bb34_23);
        ca_.Goto(&block26, phi_bb34_8, phi_bb34_9);
    }

    TNode<Number> phi_bb33_8;
    TNode<Smi> phi_bb33_9;
    TNode<Smi> phi_bb33_18;
    TNode<Smi> phi_bb33_21;
    TNode<Smi> phi_bb33_23;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_8, &phi_bb33_9, &phi_bb33_18, &phi_bb33_21, &phi_bb33_23);
        ca_.Goto(&block27, phi_bb33_8, phi_bb33_9, phi_bb33_18, phi_bb33_21, tmp20);
    }

    TNode<Number> phi_bb27_8;
    TNode<Smi> phi_bb27_9;
    TNode<Smi> phi_bb27_18;
    TNode<Smi> phi_bb27_21;
    TNode<Object> phi_bb27_22;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_8, &phi_bb27_9, &phi_bb27_18, &phi_bb27_21, &phi_bb27_22);
        if ((p_hasMapper)) {
            ca_.Goto(&block35, phi_bb27_8, phi_bb27_9);
        } else {
            ca_.Goto(&block36, phi_bb27_8, phi_bb27_9);
        }
    }

    TNode<Number> phi_bb26_8;
    TNode<Smi> phi_bb26_9;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_8, &phi_bb26_9);
        ca_.Goto(&block14, phi_bb26_8, phi_bb26_9);
    }

    TNode<Number> phi_bb35_8;
    TNode<Smi> phi_bb35_9;
    TNode<Object> tmp22;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_8, &phi_bb35_9);
        tmp22 = CodeStubAssembler(state_).Call(TNode<Context> { p_context }, TNode<Object> { p_mapfn }, TNode<Object> { p_thisArgs },
            TNode<Object> { phi_bb27_22 }, TNode<Object> { phi_bb35_9 }, TNode<Object> { p_source });
        ca_.Goto(&block37, phi_bb35_8, phi_bb35_9, tmp22);
    }

    TNode<Number> phi_bb36_8;
    TNode<Smi> phi_bb36_9;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_8, &phi_bb36_9);
        ca_.Goto(&block37, phi_bb36_8, phi_bb36_9, phi_bb27_22);
    }

    TNode<Number> phi_bb37_8;
    TNode<Smi> phi_bb37_9;
    TNode<Object> phi_bb37_18;
    TNode<False> tmp23;
    TNode<Number> tmp24;
    TNode<Smi> tmp25;
    TNode<BoolT> tmp26;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_8, &phi_bb37_9, &phi_bb37_18);
        tmp23 = False_0(state_);
        tmp24 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp25 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp26 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi> { p_depth }, TNode<Smi> { tmp25 });
        ca_.Branch(tmp26, &block38, std::vector<compiler::Node*> { phi_bb37_8, phi_bb37_9 }, &block39,
            std::vector<compiler::Node*> { phi_bb37_8, phi_bb37_9, tmp23, tmp24 });
    }

    TNode<Number> phi_bb38_8;
    TNode<Smi> phi_bb38_9;
    TNode<JSArray> tmp27;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_8, &phi_bb38_9);
        compiler::CodeAssemblerLabel label28(&ca_);
        tmp27 = Cast_JSArray_1(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb37_18 }, &label28);
        ca_.Goto(&block42, phi_bb38_8, phi_bb38_9);
        if (label28.is_used()) {
            ca_.Bind(&label28);
            ca_.Goto(&block43, phi_bb38_8, phi_bb38_9);
        }
    }

    TNode<Number> phi_bb43_8;
    TNode<Smi> phi_bb43_9;
    TNode<BoolT> tmp29;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_8, &phi_bb43_9);
        tmp29 = Is_JSProxy_JSAny_0(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb37_18 });
        ca_.Branch(
            tmp29, &block44, std::vector<compiler::Node*> { phi_bb43_8, phi_bb43_9 }, &block45, std::vector<compiler::Node*> { phi_bb43_8, phi_bb43_9, tmp23 });
    }

    TNode<Number> phi_bb42_8;
    TNode<Smi> phi_bb42_9;
    TNode<True> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Number> tmp32;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_8, &phi_bb42_9);
        tmp30 = True_0(state_);
        tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp32 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference { tmp27, tmp31 });
        ca_.Goto(&block40, phi_bb42_8, phi_bb42_9, tmp30, tmp32);
    }

    TNode<Number> phi_bb44_8;
    TNode<Smi> phi_bb44_9;
    TNode<Object> tmp33;
    TNode<Boolean> tmp34;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_8, &phi_bb44_9);
        tmp33 = CodeStubAssembler(state_).CallRuntime(Runtime::kArrayIsArray, p_context, phi_bb37_18);
        compiler::CodeAssemblerLabel label35(&ca_);
        tmp34 = Cast_Boolean_0(state_, TNode<Object> { tmp33 }, &label35);
        ca_.Goto(&block48, phi_bb44_8, phi_bb44_9);
        if (label35.is_used()) {
            ca_.Bind(&label35);
            ca_.Goto(&block49, phi_bb44_8, phi_bb44_9);
        }
    }

    TNode<Number> phi_bb49_8;
    TNode<Smi> phi_bb49_9;
    if (block49.is_used()) {
        ca_.Bind(&block49, &phi_bb49_8, &phi_bb49_9);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Number> phi_bb48_8;
    TNode<Smi> phi_bb48_9;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_8, &phi_bb48_9);
        ca_.Goto(&block45, phi_bb48_8, phi_bb48_9, tmp34);
    }

    TNode<Number> phi_bb45_8;
    TNode<Smi> phi_bb45_9;
    TNode<Boolean> phi_bb45_19;
    TNode<True> tmp36;
    TNode<BoolT> tmp37;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_8, &phi_bb45_9, &phi_bb45_19);
        tmp36 = True_0(state_);
        tmp37 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { phi_bb45_19 }, TNode<HeapObject> { tmp36 });
        ca_.Branch(tmp37, &block50, std::vector<compiler::Node*> { phi_bb45_8, phi_bb45_9, phi_bb45_19 }, &block51,
            std::vector<compiler::Node*> { phi_bb45_8, phi_bb45_9, phi_bb45_19, tmp24 });
    }

    TNode<Number> phi_bb50_8;
    TNode<Smi> phi_bb50_9;
    TNode<Boolean> phi_bb50_19;
    TNode<Number> tmp38;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_8, &phi_bb50_9, &phi_bb50_19);
        tmp38 = GetLengthProperty_0(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb37_18 });
        ca_.Goto(&block51, phi_bb50_8, phi_bb50_9, phi_bb50_19, tmp38);
    }

    TNode<Number> phi_bb51_8;
    TNode<Smi> phi_bb51_9;
    TNode<Boolean> phi_bb51_19;
    TNode<Number> phi_bb51_20;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_8, &phi_bb51_9, &phi_bb51_19, &phi_bb51_20);
        ca_.Goto(&block40, phi_bb51_8, phi_bb51_9, phi_bb51_19, phi_bb51_20);
    }

    TNode<Number> phi_bb40_8;
    TNode<Smi> phi_bb40_9;
    TNode<Boolean> phi_bb40_19;
    TNode<Number> phi_bb40_20;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_8, &phi_bb40_9, &phi_bb40_19, &phi_bb40_20);
        ca_.Goto(&block39, phi_bb40_8, phi_bb40_9, phi_bb40_19, phi_bb40_20);
    }

    TNode<Number> phi_bb39_8;
    TNode<Smi> phi_bb39_9;
    TNode<Boolean> phi_bb39_19;
    TNode<Number> phi_bb39_20;
    TNode<True> tmp39;
    TNode<BoolT> tmp40;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_8, &phi_bb39_9, &phi_bb39_19, &phi_bb39_20);
        tmp39 = True_0(state_);
        tmp40 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { phi_bb39_19 }, TNode<HeapObject> { tmp39 });
        ca_.Branch(tmp40, &block52, std::vector<compiler::Node*> { phi_bb39_8, phi_bb39_9, phi_bb39_19, phi_bb39_20 }, &block53,
            std::vector<compiler::Node*> { phi_bb39_8, phi_bb39_9, phi_bb39_19, phi_bb39_20 });
    }

    TNode<Number> phi_bb52_8;
    TNode<Smi> phi_bb52_9;
    TNode<Boolean> phi_bb52_19;
    TNode<Number> phi_bb52_20;
    TNode<Number> tmp41;
    TNode<BoolT> tmp42;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_8, &phi_bb52_9, &phi_bb52_19, &phi_bb52_20);
        tmp41 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp42 = NumberIsGreaterThan_0(state_, TNode<Number> { phi_bb52_20 }, TNode<Number> { tmp41 });
        ca_.Branch(tmp42, &block55, std::vector<compiler::Node*> { phi_bb52_8, phi_bb52_9, phi_bb52_19, phi_bb52_20 }, &block56,
            std::vector<compiler::Node*> { phi_bb52_8, phi_bb52_9, phi_bb52_19, phi_bb52_20 });
    }

    TNode<Number> phi_bb55_8;
    TNode<Smi> phi_bb55_9;
    TNode<Boolean> phi_bb55_19;
    TNode<Number> phi_bb55_20;
    TNode<JSReceiver> tmp43;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_8, &phi_bb55_9, &phi_bb55_19, &phi_bb55_20);
        compiler::CodeAssemblerLabel label44(&ca_);
        tmp43 = Cast_JSReceiver_1(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb37_18 }, &label44);
        ca_.Goto(&block59, phi_bb55_8, phi_bb55_9, phi_bb55_19, phi_bb55_20);
        if (label44.is_used()) {
            ca_.Bind(&label44);
            ca_.Goto(&block60, phi_bb55_8, phi_bb55_9, phi_bb55_19, phi_bb55_20);
        }
    }

    TNode<Number> phi_bb60_8;
    TNode<Smi> phi_bb60_9;
    TNode<Boolean> phi_bb60_19;
    TNode<Number> phi_bb60_20;
    if (block60.is_used()) {
        ca_.Bind(&block60, &phi_bb60_8, &phi_bb60_9, &phi_bb60_19, &phi_bb60_20);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Number> phi_bb59_8;
    TNode<Smi> phi_bb59_9;
    TNode<Boolean> phi_bb59_19;
    TNode<Number> phi_bb59_20;
    TNode<Smi> tmp45;
    TNode<Smi> tmp46;
    TNode<Number> tmp47;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_8, &phi_bb59_9, &phi_bb59_19, &phi_bb59_20);
        tmp45 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp46 = CodeStubAssembler(state_).SmiSub(TNode<Smi> { p_depth }, TNode<Smi> { tmp45 });
        tmp47 = ca_.CallBuiltin<Number>(Builtin::kFlattenIntoArrayWithoutMapFn, p_context, p_target, tmp43, phi_bb59_20, phi_bb59_8, tmp46);
        ca_.Goto(&block56, tmp47, phi_bb59_9, phi_bb59_19, phi_bb59_20);
    }

    TNode<Number> phi_bb56_8;
    TNode<Smi> phi_bb56_9;
    TNode<Boolean> phi_bb56_19;
    TNode<Number> phi_bb56_20;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_8, &phi_bb56_9, &phi_bb56_19, &phi_bb56_20);
        ca_.Goto(&block54, phi_bb56_8, phi_bb56_9, phi_bb56_19, phi_bb56_20);
    }

    TNode<Number> phi_bb53_8;
    TNode<Smi> phi_bb53_9;
    TNode<Boolean> phi_bb53_19;
    TNode<Number> phi_bb53_20;
    TNode<Number> tmp48;
    TNode<BoolT> tmp49;
    if (block53.is_used()) {
        ca_.Bind(&block53, &phi_bb53_8, &phi_bb53_9, &phi_bb53_19, &phi_bb53_20);
        tmp48 = FromConstexpr_Number_constexpr_float64_0(state_, kMaxSafeInteger);
        tmp49 = NumberIsGreaterThanOrEqual_0(state_, TNode<Number> { phi_bb53_8 }, TNode<Number> { tmp48 });
        ca_.Branch(tmp49, &block61, std::vector<compiler::Node*> { phi_bb53_8, phi_bb53_9, phi_bb53_19, phi_bb53_20 }, &block62,
            std::vector<compiler::Node*> { phi_bb53_8, phi_bb53_9, phi_bb53_19, phi_bb53_20 });
    }

    TNode<Number> phi_bb61_8;
    TNode<Smi> phi_bb61_9;
    TNode<Boolean> phi_bb61_19;
    TNode<Number> phi_bb61_20;
    if (block61.is_used()) {
        ca_.Bind(&block61, &phi_bb61_8, &phi_bb61_9, &phi_bb61_19, &phi_bb61_20);
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { p_context }, MessageTemplate::kFlattenPastSafeLength, TNode<Object> { p_sourceLength }, TNode<Object> { phi_bb61_8 });
    }

    TNode<Number> phi_bb62_8;
    TNode<Smi> phi_bb62_9;
    TNode<Boolean> phi_bb62_19;
    TNode<Number> phi_bb62_20;
    TNode<Object> tmp50;
    TNode<Number> tmp51;
    TNode<Number> tmp52;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_8, &phi_bb62_9, &phi_bb62_19, &phi_bb62_20);
        tmp50 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, p_target, phi_bb62_8, phi_bb37_18);
        tmp51 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
        tmp52 = CodeStubAssembler(state_).NumberAdd(TNode<Number> { phi_bb62_8 }, TNode<Number> { tmp51 });
        ca_.Goto(&block54, tmp52, phi_bb62_9, phi_bb62_19, phi_bb62_20);
    }

    TNode<Number> phi_bb54_8;
    TNode<Smi> phi_bb54_9;
    TNode<Boolean> phi_bb54_19;
    TNode<Number> phi_bb54_20;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_8, &phi_bb54_9, &phi_bb54_19, &phi_bb54_20);
        ca_.Goto(&block14, phi_bb54_8, phi_bb54_9);
    }

    TNode<Number> phi_bb14_8;
    TNode<Smi> phi_bb14_9;
    TNode<Smi> tmp53;
    TNode<Smi> tmp54;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_8, &phi_bb14_9);
        tmp53 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
        tmp54 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { phi_bb14_9 }, TNode<Smi> { tmp53 });
        ca_.Goto(&block13, phi_bb14_8, tmp54, tmp15);
    }

    TNode<Number> phi_bb12_8;
    TNode<Smi> phi_bb12_9;
    TNode<JSArray> phi_bb12_12;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_8, &phi_bb12_9, &phi_bb12_12);
        ca_.Goto(&block63, phi_bb12_8);
    }

    TNode<Number> phi_bb1_0;
    TNode<Number> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_0, &phi_bb1_1);
        *label_Bailout_parameter_1 = phi_bb1_1;
        *label_Bailout_parameter_0 = phi_bb1_0;
        ca_.Goto(label_Bailout);
    }

    TNode<Number> phi_bb63_8;
    ca_.Bind(&block63, &phi_bb63_8);
    return TNode<Number> { phi_bb63_8 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=105&c=1
TNode<Number> FlattenIntoArraySlow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_target, TNode<JSReceiver> p_source,
    TNode<Number> p_sourceIndex, TNode<Number> p_sourceLength, TNode<Number> p_start, TNode<Smi> p_depth, bool p_hasMapper, TNode<Object> p_mapfn,
    TNode<Object> p_thisArgs)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number, Boolean> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        ca_.Goto(&block4, p_start, p_sourceIndex);
    }

    TNode<Number> phi_bb4_9;
    TNode<Number> phi_bb4_10;
    TNode<BoolT> tmp0;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_9, &phi_bb4_10);
        tmp0 = NumberIsLessThan_0(state_, TNode<Number> { phi_bb4_10 }, TNode<Number> { p_sourceLength });
        ca_.Branch(tmp0, &block2, std::vector<compiler::Node*> { phi_bb4_9, phi_bb4_10 }, &block3, std::vector<compiler::Node*> { phi_bb4_9, phi_bb4_10 });
    }

    TNode<Number> phi_bb2_9;
    TNode<Number> phi_bb2_10;
    TNode<Boolean> tmp1;
    TNode<True> tmp2;
    TNode<BoolT> tmp3;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_9, &phi_bb2_10);
        tmp1 = ca_.CallBuiltin<Boolean>(Builtin::kHasProperty, p_context, p_source, phi_bb2_10);
        tmp2 = True_0(state_);
        tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block5, std::vector<compiler::Node*> { phi_bb2_9, phi_bb2_10 }, &block6, std::vector<compiler::Node*> { phi_bb2_9, phi_bb2_10 });
    }

    TNode<Number> phi_bb5_9;
    TNode<Number> phi_bb5_10;
    TNode<Object> tmp4;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_9, &phi_bb5_10);
        tmp4 = CodeStubAssembler(state_).GetProperty(TNode<Context> { p_context }, TNode<Object> { p_source }, TNode<Object> { phi_bb5_10 });
        if ((p_hasMapper)) {
            ca_.Goto(&block7, phi_bb5_9, phi_bb5_10);
        } else {
            ca_.Goto(&block8, phi_bb5_9, phi_bb5_10);
        }
    }

    TNode<Number> phi_bb7_9;
    TNode<Number> phi_bb7_10;
    TNode<Object> tmp5;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_9, &phi_bb7_10);
        tmp5 = CodeStubAssembler(state_).Call(TNode<Context> { p_context }, TNode<Object> { p_mapfn }, TNode<Object> { p_thisArgs }, TNode<Object> { tmp4 },
            TNode<Object> { phi_bb7_10 }, TNode<Object> { p_source });
        ca_.Goto(&block9, phi_bb7_9, phi_bb7_10, tmp5);
    }

    TNode<Number> phi_bb8_9;
    TNode<Number> phi_bb8_10;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_9, &phi_bb8_10);
        ca_.Goto(&block9, phi_bb8_9, phi_bb8_10, tmp4);
    }

    TNode<Number> phi_bb9_9;
    TNode<Number> phi_bb9_10;
    TNode<Object> phi_bb9_12;
    TNode<False> tmp6;
    TNode<Smi> tmp7;
    TNode<BoolT> tmp8;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_9, &phi_bb9_10, &phi_bb9_12);
        tmp6 = False_0(state_);
        tmp7 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp8 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi> { p_depth }, TNode<Smi> { tmp7 });
        ca_.Branch(
            tmp8, &block10, std::vector<compiler::Node*> { phi_bb9_9, phi_bb9_10 }, &block11, std::vector<compiler::Node*> { phi_bb9_9, phi_bb9_10, tmp6 });
    }

    TNode<Number> phi_bb10_9;
    TNode<Number> phi_bb10_10;
    TNode<Boolean> tmp9;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_9, &phi_bb10_10);
        tmp9 = ArrayIsArray_Inline_0(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb9_12 });
        ca_.Goto(&block11, phi_bb10_9, phi_bb10_10, tmp9);
    }

    TNode<Number> phi_bb11_9;
    TNode<Number> phi_bb11_10;
    TNode<Boolean> phi_bb11_13;
    TNode<True> tmp10;
    TNode<BoolT> tmp11;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_9, &phi_bb11_10, &phi_bb11_13);
        tmp10 = True_0(state_);
        tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { phi_bb11_13 }, TNode<HeapObject> { tmp10 });
        ca_.Branch(
            tmp11, &block12, std::vector<compiler::Node*> { phi_bb11_9, phi_bb11_10 }, &block13, std::vector<compiler::Node*> { phi_bb11_9, phi_bb11_10 });
    }

    TNode<Number> phi_bb12_9;
    TNode<Number> phi_bb12_10;
    TNode<Number> tmp12;
    TNode<JSReceiver> tmp13;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_9, &phi_bb12_10);
        tmp12 = GetLengthProperty_0(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb9_12 });
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = Cast_JSReceiver_1(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb9_12 }, &label14);
        ca_.Goto(&block17, phi_bb12_9, phi_bb12_10);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block18, phi_bb12_9, phi_bb12_10);
        }
    }

    TNode<Number> phi_bb18_9;
    TNode<Number> phi_bb18_10;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_9, &phi_bb18_10);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Number> phi_bb17_9;
    TNode<Number> phi_bb17_10;
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<Number> tmp17;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_9, &phi_bb17_10);
        tmp15 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp16 = CodeStubAssembler(state_).SmiSub(TNode<Smi> { p_depth }, TNode<Smi> { tmp15 });
        tmp17 = ca_.CallBuiltin<Number>(Builtin::kFlattenIntoArrayWithoutMapFn, p_context, p_target, tmp13, tmp12, phi_bb17_9, tmp16);
        ca_.Goto(&block14, tmp17, phi_bb17_10);
    }

    TNode<Number> phi_bb13_9;
    TNode<Number> phi_bb13_10;
    TNode<Number> tmp18;
    TNode<BoolT> tmp19;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_9, &phi_bb13_10);
        tmp18 = FromConstexpr_Number_constexpr_float64_0(state_, kMaxSafeInteger);
        tmp19 = NumberIsGreaterThanOrEqual_0(state_, TNode<Number> { phi_bb13_9 }, TNode<Number> { tmp18 });
        ca_.Branch(
            tmp19, &block19, std::vector<compiler::Node*> { phi_bb13_9, phi_bb13_10 }, &block20, std::vector<compiler::Node*> { phi_bb13_9, phi_bb13_10 });
    }

    TNode<Number> phi_bb19_9;
    TNode<Number> phi_bb19_10;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_9, &phi_bb19_10);
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { p_context }, MessageTemplate::kFlattenPastSafeLength, TNode<Object> { p_sourceLength }, TNode<Object> { phi_bb19_9 });
    }

    TNode<Number> phi_bb20_9;
    TNode<Number> phi_bb20_10;
    TNode<Object> tmp20;
    TNode<Number> tmp21;
    TNode<Number> tmp22;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_9, &phi_bb20_10);
        tmp20 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, p_target, phi_bb20_9, phi_bb9_12);
        tmp21 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
        tmp22 = CodeStubAssembler(state_).NumberAdd(TNode<Number> { phi_bb20_9 }, TNode<Number> { tmp21 });
        ca_.Goto(&block14, tmp22, phi_bb20_10);
    }

    TNode<Number> phi_bb14_9;
    TNode<Number> phi_bb14_10;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_9, &phi_bb14_10);
        ca_.Goto(&block6, phi_bb14_9, phi_bb14_10);
    }

    TNode<Number> phi_bb6_9;
    TNode<Number> phi_bb6_10;
    TNode<Number> tmp23;
    TNode<Number> tmp24;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_9, &phi_bb6_10);
        tmp23 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
        tmp24 = CodeStubAssembler(state_).NumberAdd(TNode<Number> { phi_bb6_10 }, TNode<Number> { tmp23 });
        ca_.Goto(&block4, phi_bb6_9, tmp24);
    }

    TNode<Number> phi_bb3_9;
    TNode<Number> phi_bb3_10;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_9, &phi_bb3_10);
        ca_.Goto(&block21, phi_bb3_9);
    }

    TNode<Number> phi_bb21_9;
    ca_.Bind(&block21, &phi_bb21_9);
    return TNode<Number> { phi_bb21_9 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=167&c=1
TNode<Number> FlattenIntoArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_target, TNode<JSReceiver> p_source,
    TNode<Number> p_sourceLength, TNode<Number> p_start, TNode<Smi> p_depth, bool p_hasMapper, TNode<Object> p_mapfn, TNode<Object> p_thisArgs)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    compiler::TypedCodeAssemblerVariable<Number> tmp2(&ca_);
    compiler::TypedCodeAssemblerVariable<Number> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = FlattenIntoArrayFast_0(state_, TNode<Context> { p_context }, TNode<JSReceiver> { p_target }, TNode<JSReceiver> { p_source },
            TNode<Number> { p_sourceLength }, TNode<Number> { p_start }, TNode<Smi> { p_depth }, p_hasMapper, TNode<Object> { p_mapfn },
            TNode<Object> { p_thisArgs }, &label1, &tmp2, &tmp3);
        ca_.Goto(&block4);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block5);
        }
    }

    TNode<Number> tmp4;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp4 = FlattenIntoArraySlow_0(state_, TNode<Context> { p_context }, TNode<JSReceiver> { p_target }, TNode<JSReceiver> { p_source },
            TNode<Number> { tmp3.value() }, TNode<Number> { p_sourceLength }, TNode<Number> { tmp2.value() }, TNode<Smi> { p_depth }, p_hasMapper,
            TNode<Object> { p_mapfn }, TNode<Object> { p_thisArgs });
        ca_.Goto(&block1, tmp4);
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block1, tmp0);
    }

    TNode<Number> phi_bb1_8;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_8);
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Number> { phi_bb1_8 };
}

TF_BUILTIN(FlattenIntoArrayWithoutMapFn, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<JSReceiver> parameter1 = UncheckedParameter<JSReceiver>(Descriptor::kTarget);
    USE(parameter1);
    TNode<JSReceiver> parameter2 = UncheckedParameter<JSReceiver>(Descriptor::kSource);
    USE(parameter2);
    TNode<Number> parameter3 = UncheckedParameter<Number>(Descriptor::kSourceLength);
    USE(parameter3);
    TNode<Number> parameter4 = UncheckedParameter<Number>(Descriptor::kStart);
    USE(parameter4);
    TNode<Smi> parameter5 = UncheckedParameter<Smi>(Descriptor::kDepth);
    USE(parameter5);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Undefined> tmp0;
    TNode<Undefined> tmp1;
    TNode<Number> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        CodeStubAssembler(state_).PerformStackCheck(TNode<Context> { parameter0 });
        tmp0 = Undefined_0(state_);
        tmp1 = Undefined_0(state_);
        tmp2 = FlattenIntoArray_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { parameter1 }, TNode<JSReceiver> { parameter2 },
            TNode<Number> { parameter3 }, TNode<Number> { parameter4 }, TNode<Smi> { parameter5 }, false, TNode<Object> { tmp0 }, TNode<Object> { tmp1 });
        CodeStubAssembler(state_).Return(tmp2);
    }
}

TF_BUILTIN(FlattenIntoArrayWithMapFn, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<JSReceiver> parameter1 = UncheckedParameter<JSReceiver>(Descriptor::kTarget);
    USE(parameter1);
    TNode<JSReceiver> parameter2 = UncheckedParameter<JSReceiver>(Descriptor::kSource);
    USE(parameter2);
    TNode<Number> parameter3 = UncheckedParameter<Number>(Descriptor::kSourceLength);
    USE(parameter3);
    TNode<Number> parameter4 = UncheckedParameter<Number>(Descriptor::kStart);
    USE(parameter4);
    TNode<Smi> parameter5 = UncheckedParameter<Smi>(Descriptor::kDepth);
    USE(parameter5);
    TNode<Object> parameter6 = UncheckedParameter<Object>(Descriptor::kMapfn);
    USE(parameter6);
    TNode<Object> parameter7 = UncheckedParameter<Object>(Descriptor::kThisArgs);
    USE(parameter7);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FlattenIntoArray_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { parameter1 }, TNode<JSReceiver> { parameter2 },
            TNode<Number> { parameter3 }, TNode<Number> { parameter4 }, TNode<Smi> { parameter5 }, true, TNode<Object> { parameter6 },
            TNode<Object> { parameter7 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(ArrayPrototypeFlat, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    TNode<Number> tmp1;
    TNode<Number> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Object> tmp4;
    TNode<Undefined> tmp5;
    TNode<BoolT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = GetLengthProperty_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp0 });
        tmp2 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp4 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp3 });
        tmp5 = Undefined_0(state_);
        tmp6 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp4 }, TNode<HeapObject> { tmp5 });
        ca_.Branch(tmp6, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> { tmp2 });
    }

    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<Number> tmp9;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp7 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp8 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp7 });
        tmp9 = ToInteger_Inline_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp8 });
        ca_.Goto(&block2, tmp9);
    }

    TNode<Number> phi_bb2_8;
    TNode<Smi> tmp10;
    TNode<Smi> tmp11;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_8);
        tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        compiler::CodeAssemblerLabel label12(&ca_);
        tmp11 = Cast_PositiveSmi_0(state_, TNode<Object> { phi_bb2_8 }, &label12);
        ca_.Goto(&block5);
        if (label12.is_used()) {
            ca_.Bind(&label12);
            ca_.Goto(&block6);
        }
    }

    TNode<Number> tmp13;
    TNode<BoolT> tmp14;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp13 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp14 = NumberIsLessThanOrEqual_0(state_, TNode<Number> { phi_bb2_8 }, TNode<Number> { tmp13 });
        ca_.Branch(tmp14, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block3, tmp11);
    }

    TNode<Smi> tmp15;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp15 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block9, tmp15);
    }

    TNode<UintPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<Smi> tmp18;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp16 = kSmiMax_0(state_);
        tmp17 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { tmp16 });
        tmp18 = Convert_Smi_intptr_0(state_, TNode<IntPtrT> { tmp17 });
        ca_.Goto(&block9, tmp18);
    }

    TNode<Smi> phi_bb9_9;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_9);
        ca_.Goto(&block3, phi_bb9_9);
    }

    TNode<Smi> phi_bb3_9;
    TNode<Number> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<Number> tmp21;
    TNode<Number> tmp22;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_9);
        tmp19 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp20 = CodeStubAssembler(state_).ArraySpeciesCreate(TNode<Context> { parameter0 }, TNode<Object> { tmp0 }, TNode<Number> { tmp19 });
        tmp21 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp22 = ca_.CallBuiltin<Number>(Builtin::kFlattenIntoArrayWithoutMapFn, parameter0, tmp20, tmp0, tmp1, tmp21, phi_bb3_9);
        arguments.PopAndReturn(tmp20);
    }
}

TF_BUILTIN(ArrayPrototypeFlatMap, CodeStubAssembler)
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

    TNode<JSReceiver> tmp0;
    TNode<Number> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Object> tmp3;
    TNode<JSReceiver> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = GetLengthProperty_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp3 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp2 });
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = Cast_Callable_1(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp3 }, &label5);
        ca_.Goto(&block3);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block4);
        }
    }

    TNode<IntPtrT> tmp6;
    TNode<Object> tmp7;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp7 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp6 });
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp7);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp8;
    TNode<Object> tmp9;
    TNode<Number> tmp10;
    TNode<JSReceiver> tmp11;
    TNode<Number> tmp12;
    TNode<Smi> tmp13;
    TNode<Number> tmp14;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp8 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp9 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp8 });
        tmp10 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp11 = CodeStubAssembler(state_).ArraySpeciesCreate(TNode<Context> { parameter0 }, TNode<Object> { tmp0 }, TNode<Number> { tmp10 });
        tmp12 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp13 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp14 = ca_.CallBuiltin<Number>(Builtin::kFlattenIntoArrayWithMapFn, parameter0, tmp11, tmp0, tmp1, tmp12, tmp13, tmp4, tmp9);
        arguments.PopAndReturn(tmp11);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=9&c=7
TNode<BoolT> Is_JSArray_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSArray> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_JSArray_1(state_, TNode<Context> { p_context }, TNode<Object> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=11&c=14
TNode<BoolT> Is_JSProxy_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSProxy> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_JSProxy_1(state_, TNode<Context> { p_context }, TNode<Object> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=34&c=10
TNode<BoolT> Is_Smi_Number_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Number> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_Smi_0(state_, TNode<Object> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=35&c=27
TNode<Smi> UnsafeCast_Smi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<Smi> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=65&c=13
TNode<JSArray> Cast_JSArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError)
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

    TNode<JSArray> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_JSArray_0(state_, TNode<HeapObject> { tmp0 }, &label3);
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
    return TNode<JSArray> { tmp2 };
}

} // namespace internal
} // namespace v8
