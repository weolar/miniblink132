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
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/conversion-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=7&c=1
void ReduceToSmiOrFloat64_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_x, compiler::CodeAssemblerLabel* label_SmiResult,
    compiler::TypedCodeAssemblerVariable<Smi>* label_SmiResult_parameter_0, compiler::CodeAssemblerLabel* label_Float64Result,
    compiler::TypedCodeAssemblerVariable<Float64T>* label_Float64Result_parameter_0)
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
        ca_.Goto(&block5, p_x);
    }

    TNode<Object> phi_bb5_2;
    TNode<BoolT> tmp0;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_2);
        tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp0, &block3, std::vector<compiler::Node*> { phi_bb5_2 }, &block4, std::vector<compiler::Node*> { phi_bb5_2 });
    }

    TNode<Object> phi_bb3_2;
    TNode<Smi> tmp1;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_2);
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_Smi_0(state_, TNode<Object> { phi_bb3_2 }, &label2);
        ca_.Goto(&block8, phi_bb3_2, phi_bb3_2, phi_bb3_2);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block9, phi_bb3_2, phi_bb3_2, phi_bb3_2);
        }
    }

    TNode<Object> phi_bb9_2;
    TNode<Object> phi_bb9_3;
    TNode<Object> phi_bb9_4;
    TNode<HeapNumber> tmp3;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_2, &phi_bb9_3, &phi_bb9_4);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Cast_HeapNumber_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(phi_bb9_3) }, &label4);
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
        *label_SmiResult_parameter_0 = tmp1;
        ca_.Goto(label_SmiResult);
    }

    TNode<Object> phi_bb13_2;
    TNode<Object> phi_bb13_3;
    TNode<Number> tmp5;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_3);
        tmp5 = ca_.CallBuiltin<Number>(Builtin::kNonNumberToNumber, p_context, ca_.UncheckedCast<HeapObject>(phi_bb13_3));
        ca_.Goto(&block5, tmp5);
    }

    TNode<Object> phi_bb12_2;
    TNode<Object> phi_bb12_3;
    TNode<Float64T> tmp6;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_2, &phi_bb12_3);
        tmp6 = Convert_float64_HeapNumber_0(state_, TNode<HeapNumber> { tmp3 });
        *label_Float64Result_parameter_0 = tmp6;
        ca_.Goto(label_Float64Result);
    }

    TNode<Object> phi_bb4_2;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_2);
        VerifiedUnreachable_0(state_);
    }
}

TF_BUILTIN(MathAbs, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        ReduceToSmiOrFloat64_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        if (((CodeStubAssembler(state_).IsIntPtrAbsWithOverflowSupported()))) {
            ca_.Goto(&block9);
        } else {
            ca_.Goto(&block10);
        }
    }

    TNode<Float64T> tmp4;
    TNode<Number> tmp5;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp4 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T> { tmp3.value() });
        tmp5 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }

    TNode<Smi> tmp6;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        compiler::CodeAssemblerLabel label7(&ca_);
        tmp6 = CodeStubAssembler(state_).TrySmiAbs(TNode<Smi> { tmp1.value() }, &label7);
        ca_.Goto(&block12);
        if (label7.is_used()) {
            ca_.Bind(&label7);
            ca_.Goto(&block13);
        }
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block8);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        CodeStubAssembler(state_).Return(tmp6);
    }

    TNode<Smi> tmp8;
    TNode<BoolT> tmp9;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp8 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp9 = CodeStubAssembler(state_).SmiLessThanOrEqual(TNode<Smi> { tmp8 }, TNode<Smi> { tmp1.value() });
        ca_.Branch(tmp9, &block14, std::vector<compiler::Node*> {}, &block15, std::vector<compiler::Node*> {});
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        CodeStubAssembler(state_).Return(tmp1.value());
    }

    TNode<Smi> tmp10;
    TNode<Smi> tmp11;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp10 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        compiler::CodeAssemblerLabel label12(&ca_);
        tmp11 = CodeStubAssembler(state_).TrySmiSub(TNode<Smi> { tmp10 }, TNode<Smi> { tmp1.value() }, &label12);
        ca_.Goto(&block17);
        if (label12.is_used()) {
            ca_.Bind(&label12);
            ca_.Goto(&block18);
        }
    }

    if (block18.is_used()) {
        ca_.Bind(&block18);
        ca_.Goto(&block8);
    }

    if (block17.is_used()) {
        ca_.Bind(&block17);
        CodeStubAssembler(state_).Return(tmp11);
    }

    TNode<Number> tmp13;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp13 = CodeStubAssembler(state_).NumberConstant(0.0 - kSmiMinValue);
        CodeStubAssembler(state_).Return(tmp13);
    }
}

TF_BUILTIN(MathCeil, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        ReduceToSmiOrFloat64_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).Return(tmp1.value());
    }

    TNode<Float64T> tmp4;
    TNode<Number> tmp5;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp4 = CodeStubAssembler(state_).Float64Ceil(TNode<Float64T> { tmp3.value() });
        tmp5 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }
}

TF_BUILTIN(MathFloor, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        ReduceToSmiOrFloat64_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).Return(tmp1.value());
    }

    TNode<Float64T> tmp4;
    TNode<Number> tmp5;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp4 = CodeStubAssembler(state_).Float64Floor(TNode<Float64T> { tmp3.value() });
        tmp5 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }
}

TF_BUILTIN(MathRound, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        ReduceToSmiOrFloat64_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).Return(tmp1.value());
    }

    TNode<Float64T> tmp4;
    TNode<Number> tmp5;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp4 = CodeStubAssembler(state_).Float64Round(TNode<Float64T> { tmp3.value() });
        tmp5 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }
}

TF_BUILTIN(MathTrunc, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Float64T> tmp3(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label0(&ca_);
        compiler::CodeAssemblerLabel label2(&ca_);
        ReduceToSmiOrFloat64_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label0, &tmp1, &label2, &tmp3);
        if (label0.is_used()) {
            ca_.Bind(&label0);
            ca_.Goto(&block5);
        }
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).Return(tmp1.value());
    }

    TNode<Float64T> tmp4;
    TNode<Number> tmp5;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp4 = CodeStubAssembler(state_).Float64Trunc(TNode<Float64T> { tmp3.value() });
        tmp5 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=119&c=1
TNode<Number> MathPowImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_base, TNode<Object> p_exponent)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context> { p_context }, TNode<Object> { p_base });
        tmp1 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context> { p_context }, TNode<Object> { p_exponent });
        tmp2 = CodeStubAssembler(state_).Float64Pow(TNode<Float64T> { tmp0 }, TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Number> { tmp3 };
}

TF_BUILTIN(MathPow, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kBase);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kExponent);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = MathPowImpl_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, TNode<Object> { parameter2 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(MathMax, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_float64_constexpr_float64_0(state_, -V8_INFINITY);
        tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block3, tmp0, tmp1);
    }

    TNode<Float64T> phi_bb3_5;
    TNode<IntPtrT> phi_bb3_7;
    TNode<BoolT> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_5, &phi_bb3_7);
        tmp2 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb3_7 }, TNode<IntPtrT> { torque_arguments.length });
        ca_.Branch(tmp2, &block1, std::vector<compiler::Node*> { phi_bb3_5, phi_bb3_7 }, &block2, std::vector<compiler::Node*> { phi_bb3_5, phi_bb3_7 });
    }

    TNode<Float64T> phi_bb1_5;
    TNode<IntPtrT> phi_bb1_7;
    TNode<Object> tmp3;
    TNode<Float64T> tmp4;
    TNode<Float64T> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_5, &phi_bb1_7);
        tmp3 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { phi_bb1_7 });
        tmp4 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context> { parameter0 }, TNode<Object> { tmp3 });
        tmp5 = CodeStubAssembler(state_).Float64Max(TNode<Float64T> { phi_bb1_5 }, TNode<Float64T> { tmp4 });
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb1_7 }, TNode<IntPtrT> { tmp6 });
        ca_.Goto(&block3, tmp5, tmp7);
    }

    TNode<Float64T> phi_bb2_5;
    TNode<IntPtrT> phi_bb2_7;
    TNode<Number> tmp8;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_5, &phi_bb2_7);
        tmp8 = Convert_Number_float64_0(state_, TNode<Float64T> { phi_bb2_5 });
        arguments.PopAndReturn(tmp8);
    }
}

TF_BUILTIN(MathMin, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Float64T, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<IntPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
        tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block3, tmp0, tmp1);
    }

    TNode<Float64T> phi_bb3_5;
    TNode<IntPtrT> phi_bb3_7;
    TNode<BoolT> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_5, &phi_bb3_7);
        tmp2 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb3_7 }, TNode<IntPtrT> { torque_arguments.length });
        ca_.Branch(tmp2, &block1, std::vector<compiler::Node*> { phi_bb3_5, phi_bb3_7 }, &block2, std::vector<compiler::Node*> { phi_bb3_5, phi_bb3_7 });
    }

    TNode<Float64T> phi_bb1_5;
    TNode<IntPtrT> phi_bb1_7;
    TNode<Object> tmp3;
    TNode<Float64T> tmp4;
    TNode<Float64T> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_5, &phi_bb1_7);
        tmp3 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { phi_bb1_7 });
        tmp4 = CodeStubAssembler(state_).TruncateTaggedToFloat64(TNode<Context> { parameter0 }, TNode<Object> { tmp3 });
        tmp5 = CodeStubAssembler(state_).Float64Min(TNode<Float64T> { phi_bb1_5 }, TNode<Float64T> { tmp4 });
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb1_7 }, TNode<IntPtrT> { tmp6 });
        ca_.Goto(&block3, tmp5, tmp7);
    }

    TNode<Float64T> phi_bb2_5;
    TNode<IntPtrT> phi_bb2_7;
    TNode<Number> tmp8;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_5, &phi_bb2_7);
        tmp8 = Convert_Number_float64_0(state_, TNode<Float64T> { phi_bb2_5 });
        arguments.PopAndReturn(tmp8);
    }
}

TF_BUILTIN(MathAcos, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Acos(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathAcosh, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Acosh(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathAsin, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Asin(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathAsinh, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Asinh(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathAtan, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Atan(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathAtan2, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kY);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Number> tmp2;
    TNode<Float64T> tmp3;
    TNode<Float64T> tmp4;
    TNode<Number> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        tmp3 = Convert_float64_Number_0(state_, TNode<Number> { tmp2 });
        tmp4 = CodeStubAssembler(state_).Float64Atan2(TNode<Float64T> { tmp1 }, TNode<Float64T> { tmp3 });
        tmp5 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }
}

TF_BUILTIN(MathAtanh, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Atanh(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathCbrt, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Cbrt(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathClz32, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Int32T> tmp1;
    TNode<Int32T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_int32_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Word32Clz(TNode<Int32T> { tmp1 });
        tmp3 = Convert_Number_int32_0(state_, TNode<Int32T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathCos, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Cos(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathCosh, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Cosh(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathExp, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Exp(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathExpm1, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Expm1(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathFround, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float32T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float32_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = Convert_float64_float32_0(state_, TNode<Float32T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathF16round, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float16RawBitsT> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float16_raw_bits_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = Convert_float64_float16_raw_bits_0(state_, TNode<Float16RawBitsT> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathImul, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kY);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Int32T> tmp1;
    TNode<Number> tmp2;
    TNode<Int32T> tmp3;
    TNode<Int32T> tmp4;
    TNode<Number> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_int32_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        tmp3 = Convert_int32_Number_0(state_, TNode<Number> { tmp2 });
        tmp4 = CodeStubAssembler(state_).Int32Mul(TNode<Int32T> { tmp1 }, TNode<Int32T> { tmp3 });
        tmp5 = Convert_Number_int32_0(state_, TNode<Int32T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }
}

TF_BUILTIN(MathLog, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Log(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathLog1p, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Log1p(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathLog10, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Log10(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathLog2, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Log2(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathSin, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Sin(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathSign, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp3 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T> { tmp1 }, TNode<Float64T> { tmp2 });
        ca_.Branch(tmp3, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp4;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp4 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
        CodeStubAssembler(state_).Return(tmp4);
    }

    TNode<Float64T> tmp5;
    TNode<BoolT> tmp6;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp5 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp6 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T> { tmp1 }, TNode<Float64T> { tmp5 });
        ca_.Branch(tmp6, &block4, std::vector<compiler::Node*> {}, &block5, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp7;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp7 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp7);
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(MathSinh, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Sinh(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathSqrt, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Sqrt(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathTan, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Tan(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

TF_BUILTIN(MathTanh, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kX);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Float64T> tmp1;
    TNode<Float64T> tmp2;
    TNode<Number> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = Convert_float64_Number_0(state_, TNode<Number> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Float64Tanh(TNode<Float64T> { tmp1 });
        tmp3 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=398&c=1
TNode<Number> FastMathHypot_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_arguments, compiler::CodeAssemblerLabel* label_Slow)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
        tmp1 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT> { p_arguments.length }, TNode<IntPtrT> { tmp0 });
        ca_.Branch(tmp1, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(label_Slow);
    }

    TNode<IntPtrT> tmp2;
    TNode<BoolT> tmp3;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp3 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { p_arguments.length }, TNode<IntPtrT> { tmp2 });
        ca_.Branch(tmp3, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp4;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp4 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block2, tmp4);
    }

    TNode<IntPtrT> tmp5;
    TNode<Object> tmp6;
    TNode<Number> tmp7;
    TNode<Float64T> tmp8;
    TNode<Float64T> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<BoolT> tmp11;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp5 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp6 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments { TNode<RawPtrT> { p_arguments.frame }, TNode<RawPtrT> { p_arguments.base },
                                                              TNode<IntPtrT> { p_arguments.length }, TNode<IntPtrT> { p_arguments.actual_count } },
            TNode<IntPtrT> { tmp5 });
        tmp7 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { p_context }, TNode<Object> { tmp6 });
        tmp8 = Convert_float64_Number_0(state_, TNode<Number> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T> { tmp8 });
        tmp10 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp11 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { p_arguments.length }, TNode<IntPtrT> { tmp10 });
        ca_.Branch(tmp11, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp12;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp12 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp9 });
        ca_.Goto(&block2, tmp12);
    }

    TNode<Float64T> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Object> tmp15;
    TNode<Number> tmp16;
    TNode<Float64T> tmp17;
    TNode<Float64T> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<BoolT> tmp20;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp13 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp14 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp15 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments { TNode<RawPtrT> { p_arguments.frame }, TNode<RawPtrT> { p_arguments.base },
                                                               TNode<IntPtrT> { p_arguments.length }, TNode<IntPtrT> { p_arguments.actual_count } },
            TNode<IntPtrT> { tmp14 });
        tmp16 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { p_context }, TNode<Object> { tmp15 });
        tmp17 = Convert_float64_Number_0(state_, TNode<Number> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T> { tmp17 });
        tmp19 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp20 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { p_arguments.length }, TNode<IntPtrT> { tmp19 });
        ca_.Branch(tmp20, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<Float64T> tmp21;
    TNode<BoolT> tmp22;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp21 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
        tmp22 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp9 }, TNode<Float64T> { tmp21 });
        ca_.Branch(tmp22, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp23;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block15, tmp23);
    }

    TNode<Float64T> tmp24;
    TNode<BoolT> tmp25;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp24 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
        tmp25 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp18 }, TNode<Float64T> { tmp24 });
        ca_.Goto(&block15, tmp25);
    }

    TNode<BoolT> phi_bb15_10;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_10);
        ca_.Branch(phi_bb15_10, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp26;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp26 = FromConstexpr_Number_constexpr_float64_0(state_, V8_INFINITY);
        ca_.Goto(&block2, tmp26);
    }

    TNode<Float64T> tmp27;
    TNode<BoolT> tmp28;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp27 = CodeStubAssembler(state_).Float64Max(TNode<Float64T> { tmp9 }, TNode<Float64T> { tmp18 });
        tmp28 = Float64IsNaN_0(state_, TNode<Float64T> { tmp27 });
        ca_.Branch(tmp28, &block16, std::vector<compiler::Node*> {}, &block17, std::vector<compiler::Node*> {});
    }

    TNode<HeapNumber> tmp29;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp29 = kNaN_0(state_);
        ca_.Goto(&block2, tmp29);
    }

    TNode<Float64T> tmp30;
    TNode<BoolT> tmp31;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp30 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp31 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp27 }, TNode<Float64T> { tmp30 });
        ca_.Branch(tmp31, &block18, std::vector<compiler::Node*> {}, &block19, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp32;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp32 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block2, tmp32);
    }

    TNode<Float64T> tmp33;
    TNode<Float64T> tmp34;
    TNode<Float64T> tmp35;
    TNode<Float64T> tmp36;
    TNode<Float64T> tmp37;
    TNode<Float64T> tmp38;
    TNode<Float64T> tmp39;
    TNode<Float64T> tmp40;
    TNode<Float64T> tmp41;
    TNode<Number> tmp42;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp33 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp9 }, TNode<Float64T> { tmp27 });
        tmp34 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp9 }, TNode<Float64T> { tmp27 });
        tmp35 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp33 }, TNode<Float64T> { tmp34 });
        tmp36 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp18 }, TNode<Float64T> { tmp27 });
        tmp37 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp18 }, TNode<Float64T> { tmp27 });
        tmp38 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp36 }, TNode<Float64T> { tmp37 });
        tmp39 = CodeStubAssembler(state_).Float64Add(TNode<Float64T> { tmp35 }, TNode<Float64T> { tmp38 });
        tmp40 = CodeStubAssembler(state_).Float64Sqrt(TNode<Float64T> { tmp39 });
        tmp41 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp40 }, TNode<Float64T> { tmp27 });
        tmp42 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp41 });
        ca_.Goto(&block2, tmp42);
    }

    TNode<IntPtrT> tmp43;
    TNode<BoolT> tmp44;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp43 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
        tmp44 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { p_arguments.length }, TNode<IntPtrT> { tmp43 });
        ca_.Branch(tmp44, &block20, std::vector<compiler::Node*> {}, &block21, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp45;
    TNode<Object> tmp46;
    TNode<Number> tmp47;
    TNode<Float64T> tmp48;
    TNode<Float64T> tmp49;
    TNode<Float64T> tmp50;
    TNode<BoolT> tmp51;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        tmp45 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp46 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments { TNode<RawPtrT> { p_arguments.frame }, TNode<RawPtrT> { p_arguments.base },
                                                               TNode<IntPtrT> { p_arguments.length }, TNode<IntPtrT> { p_arguments.actual_count } },
            TNode<IntPtrT> { tmp45 });
        tmp47 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { p_context }, TNode<Object> { tmp46 });
        tmp48 = Convert_float64_Number_0(state_, TNode<Number> { tmp47 });
        tmp49 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T> { tmp48 });
        tmp50 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
        tmp51 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp9 }, TNode<Float64T> { tmp50 });
        ca_.Branch(tmp51, &block24, std::vector<compiler::Node*> {}, &block25, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp52;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        tmp52 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block26, tmp52);
    }

    TNode<Float64T> tmp53;
    TNode<BoolT> tmp54;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        tmp53 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
        tmp54 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp18 }, TNode<Float64T> { tmp53 });
        ca_.Goto(&block26, tmp54);
    }

    TNode<BoolT> phi_bb26_11;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_11);
        ca_.Branch(phi_bb26_11, &block27, std::vector<compiler::Node*> {}, &block28, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp55;
    if (block27.is_used()) {
        ca_.Bind(&block27);
        tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block29, tmp55);
    }

    TNode<Float64T> tmp56;
    TNode<BoolT> tmp57;
    if (block28.is_used()) {
        ca_.Bind(&block28);
        tmp56 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
        tmp57 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp49 }, TNode<Float64T> { tmp56 });
        ca_.Goto(&block29, tmp57);
    }

    TNode<BoolT> phi_bb29_11;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_11);
        ca_.Branch(phi_bb29_11, &block22, std::vector<compiler::Node*> {}, &block23, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp58;
    if (block22.is_used()) {
        ca_.Bind(&block22);
        tmp58 = FromConstexpr_Number_constexpr_float64_0(state_, V8_INFINITY);
        ca_.Goto(&block2, tmp58);
    }

    TNode<Float64T> tmp59;
    TNode<Float64T> tmp60;
    TNode<BoolT> tmp61;
    if (block23.is_used()) {
        ca_.Bind(&block23);
        tmp59 = CodeStubAssembler(state_).Float64Max(TNode<Float64T> { tmp9 }, TNode<Float64T> { tmp18 });
        tmp60 = CodeStubAssembler(state_).Float64Max(TNode<Float64T> { tmp59 }, TNode<Float64T> { tmp49 });
        tmp61 = Float64IsNaN_0(state_, TNode<Float64T> { tmp60 });
        ca_.Branch(tmp61, &block30, std::vector<compiler::Node*> {}, &block31, std::vector<compiler::Node*> {});
    }

    TNode<HeapNumber> tmp62;
    if (block30.is_used()) {
        ca_.Bind(&block30);
        tmp62 = kNaN_0(state_);
        ca_.Goto(&block2, tmp62);
    }

    TNode<Float64T> tmp63;
    TNode<BoolT> tmp64;
    if (block31.is_used()) {
        ca_.Bind(&block31);
        tmp63 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp64 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { tmp60 }, TNode<Float64T> { tmp63 });
        ca_.Branch(tmp64, &block32, std::vector<compiler::Node*> {}, &block33, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp65;
    if (block32.is_used()) {
        ca_.Bind(&block32);
        tmp65 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block2, tmp65);
    }

    TNode<Float64T> tmp66;
    TNode<Float64T> tmp67;
    TNode<Float64T> tmp68;
    TNode<Float64T> tmp69;
    TNode<Float64T> tmp70;
    TNode<Float64T> tmp71;
    TNode<Float64T> tmp72;
    TNode<Float64T> tmp73;
    TNode<Float64T> tmp74;
    TNode<Float64T> tmp75;
    TNode<Float64T> tmp76;
    TNode<Float64T> tmp77;
    TNode<Float64T> tmp78;
    TNode<Float64T> tmp79;
    TNode<Float64T> tmp80;
    TNode<Float64T> tmp81;
    TNode<Float64T> tmp82;
    TNode<Number> tmp83;
    if (block33.is_used()) {
        ca_.Bind(&block33);
        tmp66 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp9 }, TNode<Float64T> { tmp60 });
        tmp67 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp9 }, TNode<Float64T> { tmp60 });
        tmp68 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp66 }, TNode<Float64T> { tmp67 });
        tmp69 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp18 }, TNode<Float64T> { tmp60 });
        tmp70 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp18 }, TNode<Float64T> { tmp60 });
        tmp71 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp69 }, TNode<Float64T> { tmp70 });
        tmp72 = CodeStubAssembler(state_).Float64Add(TNode<Float64T> { tmp68 }, TNode<Float64T> { tmp71 });
        tmp73 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T> { tmp72 }, TNode<Float64T> { tmp68 });
        tmp74 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T> { tmp73 }, TNode<Float64T> { tmp71 });
        tmp75 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp49 }, TNode<Float64T> { tmp60 });
        tmp76 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp49 }, TNode<Float64T> { tmp60 });
        tmp77 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp75 }, TNode<Float64T> { tmp76 });
        tmp78 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T> { tmp77 }, TNode<Float64T> { tmp74 });
        tmp79 = CodeStubAssembler(state_).Float64Add(TNode<Float64T> { tmp68 }, TNode<Float64T> { tmp71 });
        tmp80 = CodeStubAssembler(state_).Float64Add(TNode<Float64T> { tmp79 }, TNode<Float64T> { tmp78 });
        tmp81 = CodeStubAssembler(state_).Float64Sqrt(TNode<Float64T> { tmp80 });
        tmp82 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp81 }, TNode<Float64T> { tmp60 });
        tmp83 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp82 });
        ca_.Goto(&block2, tmp83);
    }

    if (block21.is_used()) {
        ca_.Bind(&block21);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Number> phi_bb2_5;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_5);
        ca_.Goto(&block34, phi_bb2_5);
    }

    TNode<Number> phi_bb34_5;
    ca_.Bind(&block34, &phi_bb34_5);
    return TNode<Number> { phi_bb34_5 };
}

TF_BUILTIN(MathHypot, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block16(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block17(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block42(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block43(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, Float64T, Float64T, Float64T, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = FastMathHypot_0(state_, TNode<Context> { parameter0 },
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    TNode<FixedDoubleArray> tmp2;
    TNode<BoolT> tmp3;
    TNode<Float64T> tmp4;
    TNode<IntPtrT> tmp5;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp2 = CodeStubAssembler(state_).AllocateZeroedFixedDoubleArray(TNode<IntPtrT> { torque_arguments.length });
        tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp4 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp5 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block7, tmp3, tmp4, tmp5);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        arguments.PopAndReturn(tmp0);
    }

    TNode<BoolT> phi_bb7_8;
    TNode<Float64T> phi_bb7_9;
    TNode<IntPtrT> phi_bb7_10;
    TNode<BoolT> tmp6;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_8, &phi_bb7_9, &phi_bb7_10);
        tmp6 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb7_10 }, TNode<IntPtrT> { torque_arguments.length });
        ca_.Branch(tmp6, &block5, std::vector<compiler::Node*> { phi_bb7_8, phi_bb7_9, phi_bb7_10 }, &block6,
            std::vector<compiler::Node*> { phi_bb7_8, phi_bb7_9, phi_bb7_10 });
    }

    TNode<BoolT> phi_bb5_8;
    TNode<Float64T> phi_bb5_9;
    TNode<IntPtrT> phi_bb5_10;
    TNode<Object> tmp7;
    TNode<Number> tmp8;
    TNode<Float64T> tmp9;
    TNode<BoolT> tmp10;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_8, &phi_bb5_9, &phi_bb5_10);
        tmp7 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { phi_bb5_10 });
        tmp8 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { tmp7 });
        tmp9 = Convert_float64_Number_0(state_, TNode<Number> { tmp8 });
        tmp10 = Float64IsNaN_0(state_, TNode<Float64T> { tmp9 });
        ca_.Branch(tmp10, &block9, std::vector<compiler::Node*> { phi_bb5_8, phi_bb5_9, phi_bb5_10 }, &block10,
            std::vector<compiler::Node*> { phi_bb5_8, phi_bb5_9, phi_bb5_10 });
    }

    TNode<BoolT> phi_bb9_8;
    TNode<Float64T> phi_bb9_9;
    TNode<IntPtrT> phi_bb9_10;
    TNode<BoolT> tmp11;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_8, &phi_bb9_9, &phi_bb9_10);
        tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block11, tmp11, phi_bb9_9, phi_bb9_10);
    }

    TNode<BoolT> phi_bb10_8;
    TNode<Float64T> phi_bb10_9;
    TNode<IntPtrT> phi_bb10_10;
    TNode<Float64T> tmp12;
    TNode<Object> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<UintPtrT> tmp17;
    TNode<BoolT> tmp18;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_8, &phi_bb10_9, &phi_bb10_10);
        tmp12 = CodeStubAssembler(state_).Float64Abs(TNode<Float64T> { tmp9 });
        std::tie(tmp13, tmp14, tmp15) = FieldSliceFixedDoubleArrayValues_0(state_, TNode<FixedDoubleArray> { tmp2 }).Flatten();
        tmp16 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb10_10 });
        tmp17 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp15 });
        tmp18 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp16 }, TNode<UintPtrT> { tmp17 });
        ca_.Branch(tmp18, &block16, std::vector<compiler::Node*> { phi_bb10_8, phi_bb10_9, phi_bb10_10, phi_bb10_10, phi_bb10_10, phi_bb10_10, phi_bb10_10 },
            &block17, std::vector<compiler::Node*> { phi_bb10_8, phi_bb10_9, phi_bb10_10, phi_bb10_10, phi_bb10_10, phi_bb10_10, phi_bb10_10 });
    }

    TNode<BoolT> phi_bb16_8;
    TNode<Float64T> phi_bb16_9;
    TNode<IntPtrT> phi_bb16_10;
    TNode<IntPtrT> phi_bb16_17;
    TNode<IntPtrT> phi_bb16_18;
    TNode<IntPtrT> phi_bb16_22;
    TNode<IntPtrT> phi_bb16_23;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<Object> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<BoolT> tmp23;
    TNode<Float64T> tmp24;
    TNode<BoolT> tmp25;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_8, &phi_bb16_9, &phi_bb16_10, &phi_bb16_17, &phi_bb16_18, &phi_bb16_22, &phi_bb16_23);
        tmp19 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT> { phi_bb16_23 });
        tmp20 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp14 }, TNode<IntPtrT> { tmp19 });
        std::tie(tmp21, tmp22) = NewReference_float64_or_hole_0(state_, TNode<Object> { tmp13 }, TNode<IntPtrT> { tmp20 }).Flatten();
        std::tie(tmp23, tmp24) = Convert_float64_or_hole_float64_0(state_, TNode<Float64T> { tmp12 }).Flatten();
        StoreFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0 { TNode<Object> { tmp21 }, TNode<IntPtrT> { tmp22 }, TorqueStructUnsafe_0 {} },
            TorqueStructfloat64_or_hole_0 { TNode<BoolT> { tmp23 }, TNode<Float64T> { tmp24 } });
        tmp25 = CodeStubAssembler(state_).Float64GreaterThan(TNode<Float64T> { tmp12 }, TNode<Float64T> { phi_bb16_9 });
        ca_.Branch(tmp25, &block20, std::vector<compiler::Node*> { phi_bb16_8, phi_bb16_9, phi_bb16_10 }, &block21,
            std::vector<compiler::Node*> { phi_bb16_8, phi_bb16_9, phi_bb16_10 });
    }

    TNode<BoolT> phi_bb17_8;
    TNode<Float64T> phi_bb17_9;
    TNode<IntPtrT> phi_bb17_10;
    TNode<IntPtrT> phi_bb17_17;
    TNode<IntPtrT> phi_bb17_18;
    TNode<IntPtrT> phi_bb17_22;
    TNode<IntPtrT> phi_bb17_23;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_8, &phi_bb17_9, &phi_bb17_10, &phi_bb17_17, &phi_bb17_18, &phi_bb17_22, &phi_bb17_23);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<BoolT> phi_bb20_8;
    TNode<Float64T> phi_bb20_9;
    TNode<IntPtrT> phi_bb20_10;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_8, &phi_bb20_9, &phi_bb20_10);
        ca_.Goto(&block21, phi_bb20_8, tmp12, phi_bb20_10);
    }

    TNode<BoolT> phi_bb21_8;
    TNode<Float64T> phi_bb21_9;
    TNode<IntPtrT> phi_bb21_10;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_8, &phi_bb21_9, &phi_bb21_10);
        ca_.Goto(&block11, phi_bb21_8, phi_bb21_9, phi_bb21_10);
    }

    TNode<BoolT> phi_bb11_8;
    TNode<Float64T> phi_bb11_9;
    TNode<IntPtrT> phi_bb11_10;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_8, &phi_bb11_9, &phi_bb11_10);
        tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb11_10 }, TNode<IntPtrT> { tmp26 });
        ca_.Goto(&block7, phi_bb11_8, phi_bb11_9, tmp27);
    }

    TNode<BoolT> phi_bb6_8;
    TNode<Float64T> phi_bb6_9;
    TNode<IntPtrT> phi_bb6_10;
    TNode<Float64T> tmp28;
    TNode<BoolT> tmp29;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_8, &phi_bb6_9, &phi_bb6_10);
        tmp28 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
        tmp29 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { phi_bb6_9 }, TNode<Float64T> { tmp28 });
        ca_.Branch(tmp29, &block22, std::vector<compiler::Node*> { phi_bb6_8, phi_bb6_9 }, &block23, std::vector<compiler::Node*> { phi_bb6_8, phi_bb6_9 });
    }

    TNode<BoolT> phi_bb22_8;
    TNode<Float64T> phi_bb22_9;
    TNode<Number> tmp30;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_8, &phi_bb22_9);
        tmp30 = FromConstexpr_Number_constexpr_float64_0(state_, V8_INFINITY);
        arguments.PopAndReturn(tmp30);
    }

    TNode<BoolT> phi_bb23_8;
    TNode<Float64T> phi_bb23_9;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_8, &phi_bb23_9);
        ca_.Branch(
            phi_bb23_8, &block25, std::vector<compiler::Node*> { phi_bb23_8, phi_bb23_9 }, &block26, std::vector<compiler::Node*> { phi_bb23_8, phi_bb23_9 });
    }

    TNode<BoolT> phi_bb25_8;
    TNode<Float64T> phi_bb25_9;
    TNode<HeapNumber> tmp31;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_8, &phi_bb25_9);
        tmp31 = kNaN_0(state_);
        arguments.PopAndReturn(tmp31);
    }

    TNode<BoolT> phi_bb26_8;
    TNode<Float64T> phi_bb26_9;
    TNode<Float64T> tmp32;
    TNode<BoolT> tmp33;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_8, &phi_bb26_9);
        tmp32 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp33 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T> { phi_bb26_9 }, TNode<Float64T> { tmp32 });
        ca_.Branch(tmp33, &block28, std::vector<compiler::Node*> { phi_bb26_8, phi_bb26_9 }, &block29, std::vector<compiler::Node*> { phi_bb26_8, phi_bb26_9 });
    }

    TNode<BoolT> phi_bb28_8;
    TNode<Float64T> phi_bb28_9;
    TNode<Number> tmp34;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_8, &phi_bb28_9);
        tmp34 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        arguments.PopAndReturn(tmp34);
    }

    TNode<BoolT> phi_bb29_8;
    TNode<Float64T> phi_bb29_9;
    TNode<Float64T> tmp35;
    TNode<Float64T> tmp36;
    TNode<IntPtrT> tmp37;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_8, &phi_bb29_9);
        tmp35 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp36 = FromConstexpr_float64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp37 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block36, phi_bb29_8, phi_bb29_9, tmp35, tmp36, tmp37);
    }

    TNode<BoolT> phi_bb36_8;
    TNode<Float64T> phi_bb36_9;
    TNode<Float64T> phi_bb36_10;
    TNode<Float64T> phi_bb36_11;
    TNode<IntPtrT> phi_bb36_12;
    TNode<BoolT> tmp38;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_8, &phi_bb36_9, &phi_bb36_10, &phi_bb36_11, &phi_bb36_12);
        tmp38 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb36_12 }, TNode<IntPtrT> { torque_arguments.length });
        ca_.Branch(tmp38, &block34, std::vector<compiler::Node*> { phi_bb36_8, phi_bb36_9, phi_bb36_10, phi_bb36_11, phi_bb36_12 }, &block35,
            std::vector<compiler::Node*> { phi_bb36_8, phi_bb36_9, phi_bb36_10, phi_bb36_11, phi_bb36_12 });
    }

    TNode<BoolT> phi_bb34_8;
    TNode<Float64T> phi_bb34_9;
    TNode<Float64T> phi_bb34_10;
    TNode<Float64T> phi_bb34_11;
    TNode<IntPtrT> phi_bb34_12;
    TNode<Object> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<UintPtrT> tmp42;
    TNode<UintPtrT> tmp43;
    TNode<BoolT> tmp44;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_8, &phi_bb34_9, &phi_bb34_10, &phi_bb34_11, &phi_bb34_12);
        std::tie(tmp39, tmp40, tmp41) = FieldSliceFixedDoubleArrayValues_0(state_, TNode<FixedDoubleArray> { tmp2 }).Flatten();
        tmp42 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb34_12 });
        tmp43 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp41 });
        tmp44 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp42 }, TNode<UintPtrT> { tmp43 });
        ca_.Branch(tmp44, &block42,
            std::vector<compiler::Node*> { phi_bb34_8, phi_bb34_9, phi_bb34_10, phi_bb34_11, phi_bb34_12, phi_bb34_12, phi_bb34_12, phi_bb34_12, phi_bb34_12 },
            &block43,
            std::vector<compiler::Node*> { phi_bb34_8, phi_bb34_9, phi_bb34_10, phi_bb34_11, phi_bb34_12, phi_bb34_12, phi_bb34_12, phi_bb34_12, phi_bb34_12 });
    }

    TNode<BoolT> phi_bb42_8;
    TNode<Float64T> phi_bb42_9;
    TNode<Float64T> phi_bb42_10;
    TNode<Float64T> phi_bb42_11;
    TNode<IntPtrT> phi_bb42_12;
    TNode<IntPtrT> phi_bb42_17;
    TNode<IntPtrT> phi_bb42_18;
    TNode<IntPtrT> phi_bb42_22;
    TNode<IntPtrT> phi_bb42_23;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<Object> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<BoolT> tmp49;
    TNode<Float64T> tmp50;
    TNode<Float64T> tmp51;
    TNode<Float64T> tmp52;
    TNode<Float64T> tmp53;
    TNode<Float64T> tmp54;
    TNode<Float64T> tmp55;
    TNode<Float64T> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_8, &phi_bb42_9, &phi_bb42_10, &phi_bb42_11, &phi_bb42_12, &phi_bb42_17, &phi_bb42_18, &phi_bb42_22, &phi_bb42_23);
        tmp45 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT> { phi_bb42_23 });
        tmp46 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp40 }, TNode<IntPtrT> { tmp45 });
        std::tie(tmp47, tmp48) = NewReference_float64_or_hole_0(state_, TNode<Object> { tmp39 }, TNode<IntPtrT> { tmp46 }).Flatten();
        std::tie(tmp49, tmp50) = LoadFloat64OrHole_0(
            state_, TorqueStructReference_float64_or_hole_0 { TNode<Object> { tmp47 }, TNode<IntPtrT> { tmp48 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        tmp51 = CodeStubAssembler(state_).Float64Div(TNode<Float64T> { tmp50 }, TNode<Float64T> { phi_bb42_9 });
        tmp52 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp51 }, TNode<Float64T> { tmp51 });
        tmp53 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T> { tmp52 }, TNode<Float64T> { phi_bb42_11 });
        tmp54 = CodeStubAssembler(state_).Float64Add(TNode<Float64T> { phi_bb42_10 }, TNode<Float64T> { tmp53 });
        tmp55 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T> { tmp54 }, TNode<Float64T> { phi_bb42_10 });
        tmp56 = CodeStubAssembler(state_).Float64Sub(TNode<Float64T> { tmp55 }, TNode<Float64T> { tmp53 });
        tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp58 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb42_12 }, TNode<IntPtrT> { tmp57 });
        ca_.Goto(&block36, phi_bb42_8, phi_bb42_9, tmp54, tmp56, tmp58);
    }

    TNode<BoolT> phi_bb43_8;
    TNode<Float64T> phi_bb43_9;
    TNode<Float64T> phi_bb43_10;
    TNode<Float64T> phi_bb43_11;
    TNode<IntPtrT> phi_bb43_12;
    TNode<IntPtrT> phi_bb43_17;
    TNode<IntPtrT> phi_bb43_18;
    TNode<IntPtrT> phi_bb43_22;
    TNode<IntPtrT> phi_bb43_23;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_8, &phi_bb43_9, &phi_bb43_10, &phi_bb43_11, &phi_bb43_12, &phi_bb43_17, &phi_bb43_18, &phi_bb43_22, &phi_bb43_23);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<BoolT> phi_bb35_8;
    TNode<Float64T> phi_bb35_9;
    TNode<Float64T> phi_bb35_10;
    TNode<Float64T> phi_bb35_11;
    TNode<IntPtrT> phi_bb35_12;
    TNode<Float64T> tmp59;
    TNode<Float64T> tmp60;
    TNode<Number> tmp61;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_8, &phi_bb35_9, &phi_bb35_10, &phi_bb35_11, &phi_bb35_12);
        tmp59 = CodeStubAssembler(state_).Float64Sqrt(TNode<Float64T> { phi_bb35_10 });
        tmp60 = CodeStubAssembler(state_).Float64Mul(TNode<Float64T> { tmp59 }, TNode<Float64T> { phi_bb35_9 });
        tmp61 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp60 });
        arguments.PopAndReturn(tmp61);
    }
}

TF_BUILTIN(MathRandom, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Smi> tmp3;
    TNode<Smi> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = MATH_RANDOM_INDEX_INDEX_0(state_);
        std::tie(tmp1, tmp2) = NativeContextSlot_NativeContext_Smi_0(state_, TNode<NativeContext> { parameter0 }, TNode<IntPtrT> { tmp0 }).Flatten();
        tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp1, tmp2 });
        tmp4 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp5 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp3 }, TNode<Smi> { tmp4 });
        ca_.Branch(tmp5, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> { tmp3 });
    }

    TNode<Smi> tmp6;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp6 = CodeStubAssembler(state_).RefillMathRandom(TNode<NativeContext> { parameter0 });
        ca_.Goto(&block2, tmp6);
    }

    TNode<Smi> phi_bb2_2;
    TNode<Smi> tmp7;
    TNode<Smi> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<Object> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<FixedDoubleArray> tmp15;
    TNode<Object> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<UintPtrT> tmp20;
    TNode<UintPtrT> tmp21;
    TNode<BoolT> tmp22;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_2);
        tmp7 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp8 = CodeStubAssembler(state_).SmiSub(TNode<Smi> { phi_bb2_2 }, TNode<Smi> { tmp7 });
        tmp9 = MATH_RANDOM_INDEX_INDEX_0(state_);
        std::tie(tmp10, tmp11) = NativeContextSlot_NativeContext_Smi_0(state_, TNode<NativeContext> { parameter0 }, TNode<IntPtrT> { tmp9 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { tmp10, tmp11 }, tmp8);
        tmp12 = MATH_RANDOM_CACHE_INDEX_0(state_);
        std::tie(tmp13, tmp14)
            = NativeContextSlot_NativeContext_FixedDoubleArray_0(state_, TNode<NativeContext> { parameter0 }, TNode<IntPtrT> { tmp12 }).Flatten();
        tmp15 = CodeStubAssembler(state_).LoadReference<FixedDoubleArray>(CodeStubAssembler::Reference { tmp13, tmp14 });
        std::tie(tmp16, tmp17, tmp18) = FieldSliceFixedDoubleArrayValues_0(state_, TNode<FixedDoubleArray> { tmp15 }).Flatten();
        tmp19 = Convert_intptr_Smi_0(state_, TNode<Smi> { tmp8 });
        tmp20 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp19 });
        tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp18 });
        tmp22 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp20 }, TNode<UintPtrT> { tmp21 });
        ca_.Branch(tmp22, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<Object> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<BoolT> tmp27;
    TNode<Float64T> tmp28;
    TNode<HeapNumber> tmp29;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp23 = TimesSizeOf_float64_or_hole_0(state_, TNode<IntPtrT> { tmp19 });
        tmp24 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp17 }, TNode<IntPtrT> { tmp23 });
        std::tie(tmp25, tmp26) = NewReference_float64_or_hole_0(state_, TNode<Object> { tmp16 }, TNode<IntPtrT> { tmp24 }).Flatten();
        std::tie(tmp27, tmp28) = LoadFloat64OrHole_0(
            state_, TorqueStructReference_float64_or_hole_0 { TNode<Object> { tmp25 }, TNode<IntPtrT> { tmp26 }, TorqueStructUnsafe_0 {} })
                                     .Flatten();
        tmp29 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp28 });
        CodeStubAssembler(state_).Return(tmp29);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        CodeStubAssembler(state_).Unreachable();
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=516&c=24
TorqueStructReference_Smi_0 NativeContextSlot_NativeContext_Smi_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index)
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
        std::tie(tmp0, tmp1) = NativeContextSlot_Smi_0(state_, TNode<NativeContext> { p_context }, TNode<IntPtrT> { p_index }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_Smi_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp1 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/math.tq?l=525&c=8
TorqueStructReference_FixedDoubleArray_0 NativeContextSlot_NativeContext_FixedDoubleArray_0(
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
        std::tie(tmp0, tmp1) = NativeContextSlot_FixedDoubleArray_0(state_, TNode<NativeContext> { p_context }, TNode<IntPtrT> { p_index }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_FixedDoubleArray_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp1 }, TorqueStructUnsafe_0 {} };
}

} // namespace internal
} // namespace v8
