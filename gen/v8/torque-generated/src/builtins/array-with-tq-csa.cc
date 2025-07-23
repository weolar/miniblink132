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
#include "torque-generated/src/builtins/array-with-tq-csa.h"
#include "torque-generated/src/builtins/array-at-tq-csa.h"
#include "torque-generated/src/builtins/array-with-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-with.tq?l=6&c=1
TNode<JSArray> TryFastPackedArrayWith_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<Number> p_len,
    TNode<Number> p_actualIndex, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_Slow)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSArray> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_FastJSArray_0(state_, TNode<Context> { p_context }, TNode<HeapObject> { p_receiver }, &label1);
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

    TNode<IntPtrT> tmp2;
    TNode<Map> tmp3;
    TNode<Int32T> tmp4;
    TNode<BoolT> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp0, tmp2 });
        tmp4 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map> { tmp3 });
        tmp5 = CodeStubAssembler(state_).IsFastPackedElementsKind(TNode<Int32T> { tmp4 });
        ca_.Branch(tmp5, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp6;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        compiler::CodeAssemblerLabel label7(&ca_);
        tmp6 = Cast_Smi_0(state_, TNode<Object> { p_len }, &label7);
        ca_.Goto(&block7);
        if (label7.is_used()) {
            ca_.Bind(&label7);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block1);
    }

    TNode<Smi> tmp8;
    TNode<BoolT> tmp9;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp8 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray> { tmp0 });
        tmp9 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi> { tmp6 }, TNode<Smi> { tmp8 });
        ca_.Branch(tmp9, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    TNode<Smi> tmp10;
    TNode<JSArray> tmp11;
    TNode<Object> tmp12;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp11 = ca_.CallBuiltin<JSArray>(Builtin::kExtractFastJSArray, p_context, tmp0, tmp10, tmp6);
        tmp12 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, tmp11, p_actualIndex, p_value);
        ca_.Goto(&block11);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block1);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_Slow);
    }

    ca_.Bind(&block11);
    return TNode<JSArray> { tmp11 };
}

TF_BUILTIN(GenericArrayWith, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<JSReceiver> parameter1 = UncheckedParameter<JSReceiver>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Number> parameter2 = UncheckedParameter<Number>(Descriptor::kLen);
    USE(parameter2);
    TNode<Number> parameter3 = UncheckedParameter<Number>(Descriptor::kActualIndex);
    USE(parameter3);
    TNode<Object> parameter4 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter4);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSArray> tmp0;
    TNode<Number> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ArrayCreate(TNode<Context> { parameter0 }, TNode<Number> { parameter2 });
        tmp1 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block3, tmp1);
    }

    TNode<Number> phi_bb3_6;
    TNode<BoolT> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_6);
        tmp2 = NumberIsLessThan_0(state_, TNode<Number> { phi_bb3_6 }, TNode<Number> { parameter2 });
        ca_.Branch(tmp2, &block1, std::vector<compiler::Node*> { phi_bb3_6 }, &block2, std::vector<compiler::Node*> { phi_bb3_6 });
    }

    TNode<Number> phi_bb1_6;
    TNode<BoolT> tmp3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_6);
        tmp3 = IsNumberEqual_0(state_, TNode<Number> { phi_bb1_6 }, TNode<Number> { parameter3 });
        ca_.Branch(tmp3, &block4, std::vector<compiler::Node*> { phi_bb1_6 }, &block5, std::vector<compiler::Node*> { phi_bb1_6 });
    }

    TNode<Number> phi_bb4_6;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_6);
        ca_.Goto(&block6, phi_bb4_6, parameter4);
    }

    TNode<Number> phi_bb5_6;
    TNode<Object> tmp4;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_6);
        tmp4 = CodeStubAssembler(state_).GetProperty(TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { phi_bb5_6 });
        ca_.Goto(&block6, phi_bb5_6, tmp4);
    }

    TNode<Number> phi_bb6_6;
    TNode<Object> phi_bb6_7;
    TNode<Object> tmp5;
    TNode<Number> tmp6;
    TNode<Number> tmp7;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_6, &phi_bb6_7);
        tmp5 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, parameter0, tmp0, phi_bb6_6, phi_bb6_7);
        tmp6 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
        tmp7 = CodeStubAssembler(state_).NumberAdd(TNode<Number> { phi_bb6_6 }, TNode<Number> { tmp6 });
        ca_.Goto(&block3, tmp7);
    }

    TNode<Number> phi_bb2_6;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_6);
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(ArrayPrototypeWith, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kIndex);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    TNode<Number> tmp1;
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = GetLengthProperty_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp0 });
        tmp2 = ToInteger_Inline_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        compiler::CodeAssemblerLabel label4(&ca_);
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp3 = ConvertRelativeIndex_0(state_, TNode<Number> { tmp2 }, TNode<Number> { tmp1 }, &label4, &label5);
        ca_.Goto(&block3);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block4);
        }
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block5);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block2);
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block2);
    }

    TNode<JSArray> tmp6;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label7(&ca_);
        tmp6 = TryFastPackedArrayWith_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp0 }, TNode<Number> { tmp1 }, TNode<Number> { tmp3 },
            TNode<Object> { parameter3 }, &label7);
        ca_.Goto(&block8);
        if (label7.is_used()) {
            ca_.Bind(&label7);
            ca_.Goto(&block9);
        }
    }

    TNode<JSArray> tmp8;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp8 = ca_.CallBuiltin<JSArray>(Builtin::kGenericArrayWith, parameter0, tmp0, tmp1, tmp3, parameter3);
        CodeStubAssembler(state_).Return(tmp8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        CodeStubAssembler(state_).Return(tmp6);
    }

    TNode<Object> tmp9;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp9 = FromConstexpr_Object_constexpr_string_0(state_, "index");
        CodeStubAssembler(state_).ThrowRangeError(
            TNode<Context> { parameter0 }, MessageTemplate::kInvalid, TNode<Object> { tmp9 }, TNode<Object> { parameter2 });
    }
}

} // namespace internal
} // namespace v8
