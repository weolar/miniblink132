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
#include "torque-generated/src/builtins/wasm-strings-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/objects/turbofan-types-tq-csa.h"
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/builtins/wasm-strings-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-strings.tq?l=9&c=1
void Trap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, MessageTemplate p_error)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(p_error);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, p_context, tmp0);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(WebAssemblyStringCast, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kArg);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(WebAssemblyStringTest, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kArg);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Is_String_JSAny_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        ca_.Branch(tmp0, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp1;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp1 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        ca_.Goto(&block3, tmp1);
    }

    TNode<Smi> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp2 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block3, tmp2);
    }

    TNode<Smi> phi_bb3_2;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_2);
        CodeStubAssembler(state_).Return(phi_bb3_2);
    }
}

TF_BUILTIN(WebAssemblyStringFromWtf16Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kArrayArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kStartArg);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kEndArg);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    TNode<WasmArray> tmp1;
    TNode<Number> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Number> tmp4;
    TNode<Uint32T> tmp5;
    TNode<String> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = SmiConstant_0(state_, IntegerLiteral(false, 0x10ull));
        tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmCastToSpecialPrimitiveArray, parameter0, parameter1, tmp0));
        tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        tmp3 = NumberToUint32_0(state_, TNode<Number> { tmp2 });
        tmp4 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter3 });
        tmp5 = NumberToUint32_0(state_, TNode<Number> { tmp4 });
        tmp6 = ca_.CallBuiltin<String>(Builtin::kWasmStringNewWtf16Array, TNode<Object>(), tmp1, tmp3, tmp5);
        CodeStubAssembler(state_).Return(tmp6);
    }
}

TF_BUILTIN(WebAssemblyStringFromUtf8Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kArrayArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kStartArg);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kEndArg);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    TNode<WasmArray> tmp1;
    TNode<Number> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Number> tmp4;
    TNode<Uint32T> tmp5;
    TNode<Smi> tmp6;
    TNode<HeapObject> tmp7;
    TNode<String> tmp8;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = SmiConstant_0(state_, IntegerLiteral(false, 0x8ull));
        tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmCastToSpecialPrimitiveArray, parameter0, parameter1, tmp0));
        tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        tmp3 = NumberToUint32_0(state_, TNode<Number> { tmp2 });
        tmp4 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter3 });
        tmp5 = NumberToUint32_0(state_, TNode<Number> { tmp4 });
        tmp6 = CodeStubAssembler(state_).SmiConstant(unibrow::Utf8Variant::kLossyUtf8);
        tmp7 = ca_.CallBuiltin<HeapObject>(Builtin::kWasmStringNewWtf8Array, TNode<Object>(), tmp3, tmp5, tmp1, tmp6);
        tmp8 = TORQUE_CAST(TNode<HeapObject> { tmp7 });
        CodeStubAssembler(state_).Return(tmp8);
    }
}

TF_BUILTIN(WebAssemblyStringIntoUtf8Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kStringArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kArrayArg);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kStartArg);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    TNode<Smi> tmp2;
    TNode<WasmArray> tmp3;
    TNode<Number> tmp4;
    TNode<Uint32T> tmp5;
    TNode<Smi> tmp6;
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = SmiConstant_0(state_, IntegerLiteral(false, 0x8ull));
        tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmCastToSpecialPrimitiveArray, parameter0, parameter2, tmp2));
        tmp4 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter3 });
        tmp5 = NumberToUint32_0(state_, TNode<Number> { tmp4 });
        tmp6 = CodeStubAssembler(state_).SmiConstant(unibrow::Utf8Variant::kLossyUtf8);
        tmp7 = CodeStubAssembler(state_).ChangeUint32ToTagged(TNode<Uint32T> { tmp5 });
        tmp8 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf8Array, parameter0, tmp6, tmp0, tmp3, tmp7));
        CodeStubAssembler(state_).Return(tmp8);
    }
}

TF_BUILTIN(WebAssemblyStringToUtf8Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kStringArg);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    TNode<WasmArray> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringToUtf8Array, parameter0, tmp0));
        CodeStubAssembler(state_).Return(tmp2);
    }
}

TF_BUILTIN(WebAssemblyStringToWtf16Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kStringArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kArrayArg);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kStartArg);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    TNode<Smi> tmp2;
    TNode<WasmArray> tmp3;
    TNode<Number> tmp4;
    TNode<Uint32T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<Smi> tmp7;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = SmiConstant_0(state_, IntegerLiteral(false, 0x10ull));
        tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmCastToSpecialPrimitiveArray, parameter0, parameter2, tmp2));
        tmp4 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter3 });
        tmp5 = NumberToUint32_0(state_, TNode<Number> { tmp4 });
        tmp6 = ca_.CallBuiltin<Uint32T>(Builtin::kWasmStringEncodeWtf16Array, TNode<Object>(), tmp0, tmp3, tmp5);
        tmp7 = Convert_Smi_uint32_0(state_, TNode<Uint32T> { tmp6 });
        CodeStubAssembler(state_).Return(tmp7);
    }
}

TF_BUILTIN(WebAssemblyStringFromCharCode, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kCodeArg);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Uint16T> tmp4;
    TNode<String> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = NumberToUint32_0(state_, TNode<Number> { tmp0 });
        tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffffull));
        tmp3 = CodeStubAssembler(state_).Word32And(TNode<Uint32T> { tmp1 }, TNode<Uint32T> { tmp2 });
        tmp4 = ca_.UncheckedCast<Uint16T>(TNode<Uint32T> { tmp3 });
        tmp5 = CodeStubAssembler(state_).StringFromSingleCharCode(TNode<Uint16T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }
}

TF_BUILTIN(WebAssemblyStringFromCodePoint, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kCodeArg);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = NumberToUint32_0(state_, TNode<Number> { tmp0 });
        tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffffull));
        tmp3 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T> { tmp1 }, TNode<Uint32T> { tmp2 });
        ca_.Branch(tmp3, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Uint16T> tmp4;
    TNode<String> tmp5;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp4 = ca_.UncheckedCast<Uint16T>(TNode<Uint32T> { tmp1 });
        tmp5 = CodeStubAssembler(state_).StringFromSingleCharCode(TNode<Uint16T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }

    TNode<String> tmp6;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp6 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringFromCodePoint, parameter0, tmp0));
        CodeStubAssembler(state_).Return(tmp6);
    }
}

TF_BUILTIN(WebAssemblyStringCodePointAt, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kStringArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kIndexArg);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block7);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    TNode<Number> tmp2;
    TNode<Uint32T> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Int32T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        tmp3 = NumberToUint32_0(state_, TNode<Number> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp0, tmp4 });
        tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp5 });
        tmp7 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapStringOffsetOutOfBounds);
    }

    TNode<IntPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<Int32T> tmp11;
    TNode<Smi> tmp12;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp8 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String> { tmp0 });
        tmp9 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp3 });
        tmp10 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp9 });
        tmp11 = StringBuiltinsAssembler(state_).LoadSurrogatePairAt(
            TNode<String> { tmp0 }, TNode<IntPtrT> { tmp8 }, TNode<IntPtrT> { tmp10 }, UnicodeEncoding::UTF32);
        tmp12 = Convert_Smi_int32_0(state_, TNode<Int32T> { tmp11 });
        CodeStubAssembler(state_).Return(tmp12);
    }
}

TF_BUILTIN(WebAssemblyStringCharCodeAt, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kStringArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kIndexArg);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block7);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    TNode<Number> tmp2;
    TNode<Uint32T> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Int32T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        tmp3 = NumberToUint32_0(state_, TNode<Number> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp0, tmp4 });
        tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp5 });
        tmp7 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapStringOffsetOutOfBounds);
    }

    TNode<UintPtrT> tmp8;
    TNode<Uint16T> tmp9;
    TNode<Smi> tmp10;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp8 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp3 });
        tmp9 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp0 }, TNode<UintPtrT> { tmp8 });
        tmp10 = SmiTag_char16_0(state_, TNode<Uint16T> { tmp9 });
        CodeStubAssembler(state_).Return(tmp10);
    }
}

TF_BUILTIN(WebAssemblyStringLength, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kStringArg);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    TNode<Smi> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String> { tmp0 });
        CodeStubAssembler(state_).Return(tmp2);
    }
}

TF_BUILTIN(WebAssemblyStringMeasureUtf8, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kStringArg);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    TNode<Number> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringMeasureWtf8, parameter0, tmp0));
        CodeStubAssembler(state_).Return(tmp2);
    }
}

TF_BUILTIN(WebAssemblyStringConcat, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kFirstArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kSecondArg);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block2);
    }

    TNode<String> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label3);
        ca_.Goto(&block9);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block10);
        }
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block2);
    }

    TNode<String> tmp4;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp4 = ca_.CallBuiltin<String>(Builtin::kStringAdd_CheckNone, parameter0, tmp0, tmp2);
        CodeStubAssembler(state_).Return(tmp4);
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }
}

TF_BUILTIN(WebAssemblyStringSubstring, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kStringArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kStartArg);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kEndArg);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }

    TNode<Number> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Number> tmp4;
    TNode<Uint32T> tmp5;
    TNode<String> tmp6;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        tmp3 = NumberToUint32_0(state_, TNode<Number> { tmp2 });
        tmp4 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter3 });
        tmp5 = NumberToUint32_0(state_, TNode<Number> { tmp4 });
        tmp6 = ca_.CallBuiltin<String>(Builtin::kWasmStringViewWtf16Slice, TNode<Object>(), tmp0, tmp3, tmp5);
        CodeStubAssembler(state_).Return(tmp6);
    }
}

TF_BUILTIN(WebAssemblyStringEquals, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kA);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kB);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<Null> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Null_0(state_);
        tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { parameter1 }, TNode<HeapObject> { tmp0 });
        ca_.Branch(tmp1, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<Null> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_Null_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label3);
        ca_.Goto(&block7);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8);
        }
    }

    TNode<String> tmp4;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(parameter2) }, &label5);
        ca_.Goto(&block11);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block12);
        }
    }

    TNode<Smi> tmp6;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp6 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp6);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp7;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp7 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).Return(tmp7);
    }

    TNode<String> tmp8;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        compiler::CodeAssemblerLabel label9(&ca_);
        tmp8 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label9);
        ca_.Goto(&block15);
        if (label9.is_used()) {
            ca_.Bind(&label9);
            ca_.Goto(&block16);
        }
    }

    if (block16.is_used()) {
        ca_.Bind(&block16);
        ca_.Goto(&block2);
    }

    TNode<Null> tmp10;
    TNode<BoolT> tmp11;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp10 = Null_0(state_);
        tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { parameter2 }, TNode<HeapObject> { tmp10 });
        ca_.Branch(tmp11, &block17, std::vector<compiler::Node*> {}, &block18, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp12;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp12 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).Return(tmp12);
    }

    TNode<String> tmp13;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label14);
        ca_.Goto(&block21);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block22);
        }
    }

    if (block22.is_used()) {
        ca_.Bind(&block22);
        ca_.Goto(&block2);
    }

    TNode<BoolT> tmp15;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp15 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { parameter1 }, TNode<MaybeObject> { parameter2 });
        ca_.Branch(tmp15, &block23, std::vector<compiler::Node*> {}, &block24, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp16;
    if (block23.is_used()) {
        ca_.Bind(&block23);
        tmp16 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp16);
    }

    TNode<IntPtrT> tmp17;
    TNode<Int32T> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<Int32T> tmp20;
    TNode<BoolT> tmp21;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp18 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp8, tmp17 });
        tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp20 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp13, tmp19 });
        tmp21 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T> { tmp18 }, TNode<Int32T> { tmp20 });
        ca_.Branch(tmp21, &block25, std::vector<compiler::Node*> {}, &block26, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp22;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        tmp22 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).Return(tmp22);
    }

    TNode<Smi> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<Boolean> tmp25;
    TNode<True> tmp26;
    TNode<BoolT> tmp27;
    if (block26.is_used()) {
        ca_.Bind(&block26);
        tmp23 = kNoContext_0(state_);
        tmp24 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String> { tmp8 });
        tmp25 = ca_.CallBuiltin<Boolean>(Builtin::kStringEqual, tmp23, tmp8, tmp13, tmp24);
        tmp26 = True_0(state_);
        tmp27 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { tmp25 }, TNode<HeapObject> { tmp26 });
        ca_.Branch(tmp27, &block27, std::vector<compiler::Node*> {}, &block28, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp28;
    if (block27.is_used()) {
        ca_.Bind(&block27);
        tmp28 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp28);
    }

    TNode<Smi> tmp29;
    if (block28.is_used()) {
        ca_.Bind(&block28);
        tmp29 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).Return(tmp29);
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }
}

TF_BUILTIN(WebAssemblyStringCompare, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kFirstArg);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kSecondArg);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block2);
    }

    TNode<String> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_String_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label3);
        ca_.Goto(&block9);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block10);
        }
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp4;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp4 = ca_.CallBuiltin<Smi>(Builtin::kStringCompare, TNode<Object>(), tmp0, tmp2);
        CodeStubAssembler(state_).Return(tmp4);
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        Trap_0(state_, TNode<Context> { parameter0 }, MessageTemplate::kWasmTrapIllegalCast);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-strings.tq?l=51&c=10
TNode<BoolT> Is_String_String_OR_WasmNull_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<String> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_String_0(state_, TNode<HeapObject> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-strings.tq?l=136&c=12
TNode<Smi> SmiTag_char16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_value)
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
