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
#include "torque-generated/src/builtins/js-to-js-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/js-to-js-tq-csa.h"
#include "torque-generated/src/builtins/js-to-wasm-tq-csa.h"
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/builtins/wasm-to-js-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=18&c=1
TNode<Object> ConvertToAndFromWasm_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Int32T> p_wasmType, TNode<Object> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
        tmp1 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { p_wasmType }, TNode<Int32T> { tmp0 });
        ca_.Branch(tmp1, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_Smi_0(state_, TNode<Object> { p_value }, &label3);
        ca_.Goto(&block7);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block8);
        }
    }

    TNode<Int32T> tmp4;
    TNode<Number> tmp5;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp4 = ca_.CallBuiltin<Int32T>(Builtin::kWasmTaggedNonSmiToInt32, p_context, ca_.UncheckedCast<HeapObject>(p_value));
        tmp5 = Convert_Number_int32_0(state_, TNode<Int32T> { tmp4 });
        ca_.Goto(&block1, tmp5);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        ca_.Goto(&block1, tmp2);
    }

    TNode<Int32T> tmp6;
    TNode<BoolT> tmp7;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp6 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
        tmp7 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { p_wasmType }, TNode<Int32T> { tmp6 });
        ca_.Branch(tmp7, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        if (((CodeStubAssembler(state_).Is64()))) {
            ca_.Goto(&block12);
        } else {
            ca_.Goto(&block13);
        }
    }

    TNode<IntPtrT> tmp8;
    TNode<BigInt> tmp9;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp8 = TruncateBigIntToI64_0(state_, TNode<Context> { p_context }, TNode<Object> { p_value });
        tmp9 = ca_.CallBuiltin<BigInt>(Builtin::kI64ToBigInt, TNode<Object>(), tmp8);
        ca_.Goto(&block1, tmp9);
    }

    TNode<BigInt> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<BigInt> tmp15;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp10 = CodeStubAssembler(state_).ToBigInt(TNode<Context> { p_context }, TNode<Object> { p_value });
        std::tie(tmp11, tmp12) = CodeStubAssembler(state_).BigIntToRawBytes(TNode<BigInt> { tmp10 }).Flatten();
        tmp13 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp11 });
        tmp14 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp12 });
        tmp15 = ca_.CallBuiltin<BigInt>(Builtin::kI32PairToBigInt, TNode<Object>(), tmp13, tmp14);
        ca_.Goto(&block1, tmp15);
    }

    TNode<Int32T> tmp16;
    TNode<BoolT> tmp17;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp16 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
        tmp17 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { p_wasmType }, TNode<Int32T> { tmp16 });
        ca_.Branch(tmp17, &block15, std::vector<compiler::Node*> {}, &block16, std::vector<compiler::Node*> {});
    }

    TNode<Float32T> tmp18;
    TNode<Number> tmp19;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp18 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_value);
        tmp19 = Convert_Number_float32_0(state_, TNode<Float32T> { tmp18 });
        ca_.Goto(&block1, tmp19);
    }

    TNode<Int32T> tmp20;
    TNode<BoolT> tmp21;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp20 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
        tmp21 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { p_wasmType }, TNode<Int32T> { tmp20 });
        ca_.Branch(tmp21, &block18, std::vector<compiler::Node*> {}, &block19, std::vector<compiler::Node*> {});
    }

    TNode<Float64T> tmp22;
    TNode<Number> tmp23;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp22 = ca_.CallBuiltin<Float64T>(Builtin::kWasmTaggedToFloat64, p_context, p_value);
        tmp23 = Convert_Number_float64_0(state_, TNode<Float64T> { tmp22 });
        ca_.Goto(&block1, tmp23);
    }

    TNode<Int32T> tmp24;
    TNode<Int32T> tmp25;
    TNode<Null> tmp26;
    TNode<BoolT> tmp27;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp24 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
        tmp25 = CodeStubAssembler(state_).Word32And(TNode<Int32T> { p_wasmType }, TNode<Int32T> { tmp24 });
        tmp26 = Null_0(state_);
        tmp27 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { p_value }, TNode<HeapObject> { tmp26 });
        ca_.Branch(tmp27, &block28, std::vector<compiler::Node*> {}, &block29, std::vector<compiler::Node*> {});
    }

    if (block28.is_used()) {
        ca_.Bind(&block28);
        ca_.Goto(&block1, p_value);
    }

    TNode<Int32T> tmp28;
    TNode<Int32T> tmp29;
    TNode<Int32T> tmp30;
    TNode<Int32T> tmp31;
    TNode<Int32T> tmp32;
    TNode<BoolT> tmp33;
    if (block29.is_used()) {
        ca_.Bind(&block29);
        tmp28 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueType::kKindBits);
        tmp29 = CodeStubAssembler(state_).Word32Sar(TNode<Int32T> { p_wasmType }, TNode<Int32T> { tmp28 });
        tmp30 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmHeapTypeBitsMask);
        tmp31 = CodeStubAssembler(state_).Word32And(TNode<Int32T> { tmp29 }, TNode<Int32T> { tmp30 });
        tmp32 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kFunc);
        tmp33 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T> { tmp31 }, TNode<Int32T> { tmp32 });
        ca_.Branch(tmp33, &block30, std::vector<compiler::Node*> {}, &block31, std::vector<compiler::Node*> {});
    }

    if (block30.is_used()) {
        ca_.Bind(&block30);
        ca_.Goto(&block1, p_value);
    }

    TNode<Smi> tmp34;
    TNode<Boolean> tmp35;
    TNode<True> tmp36;
    TNode<BoolT> tmp37;
    if (block31.is_used()) {
        ca_.Bind(&block31);
        tmp34 = kNoContext_0(state_);
        tmp35 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kIsWasmExternalFunction, tmp34, p_value));
        tmp36 = True_0(state_);
        tmp37 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp35 }, TNode<HeapObject> { tmp36 });
        ca_.Branch(tmp37, &block32, std::vector<compiler::Node*> {}, &block33, std::vector<compiler::Node*> {});
    }

    if (block32.is_used()) {
        ca_.Bind(&block32);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kWasmTrapJSTypeError);
    }

    if (block33.is_used()) {
        ca_.Bind(&block33);
        ca_.Goto(&block1, p_value);
    }

    TNode<Object> phi_bb1_3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3);
        ca_.Goto(&block34);
    }

    ca_.Bind(&block34);
    return TNode<Object> { phi_bb1_3 };
}

TF_BUILTIN(JSToJSWrapperInvalidSig, CodeStubAssembler)
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
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        CodeStubAssembler(state_).CallRuntime(Runtime::kWasmThrowJSTypeError, parameter0);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(JSToJSWrapper, CodeStubAssembler)
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
    TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
    USE(parameter2);
    TNode<JSDispatchHandleT> parameter3 = InvalidDispatchHandleConstant();
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, Object> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<SharedFunctionInfo> tmp1;
    TNode<WasmJSFunctionData> tmp2;
    TNode<WasmInternalFunction> tmp3;
    TNode<TrustedObject> tmp4;
    TNode<WasmImportData> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<RawPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<RawPtrT> tmp10;
    TNode<Object> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<RawPtrT> tmp17;
    TNode<RawPtrT> tmp18;
    TNode<Object> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<RawPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<RawPtrT> tmp25;
    TNode<RawPtrT> tmp26;
    TNode<Object> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<Object> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<Object> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        CodeStubAssembler(state_).SetSupportsDynamicParameterCount(TNode<JSFunction> { parameter2 }, TNode<JSDispatchHandleT> { parameter3 });
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference { parameter2, tmp0 });
        tmp2 = CodeStubAssembler(state_).LoadSharedFunctionInfoWasmJSFunctionData(TNode<SharedFunctionInfo> { tmp1 });
        tmp3 = CodeStubAssembler(state_).LoadWasmInternalFunctionFromFunctionData(TNode<WasmFunctionData> { tmp2 });
        tmp4 = CodeStubAssembler(state_).LoadImplicitArgFromWasmInternalFunction(TNode<WasmInternalFunction> { tmp3 });
        tmp5 = UnsafeCast_WasmImportData_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp4 });
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp7 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { tmp5, tmp6 });
        tmp8 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp9 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT> { tmp7 }, TNode<IntPtrT> { tmp8 });
        tmp10 = (TNode<RawPtrT> { tmp9 });
        std::tie(tmp11, tmp12) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT> { tmp10 }).Flatten();
        tmp13 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference { tmp11, tmp12 });
        tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp15 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { tmp5, tmp14 });
        tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
        tmp17 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT> { tmp15 }, TNode<IntPtrT> { tmp16 });
        tmp18 = (TNode<RawPtrT> { tmp17 });
        std::tie(tmp19, tmp20) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT> { tmp18 }).Flatten();
        tmp21 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference { tmp19, tmp20 });
        tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp23 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { tmp5, tmp22 });
        tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_,
            (CodeStubAssembler(state_).ConstexprInt31Mul(
                (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))), (SizeOf_intptr_0(state_)))));
        tmp25 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT> { tmp23 }, TNode<IntPtrT> { tmp24 });
        tmp26 = (TNode<RawPtrT> { tmp25 });
        std::tie(tmp27, tmp28) = NewOffHeapReference_RawPtr_int32_0(state_, TNode<RawPtrT> { tmp26 }).Flatten();
        tmp29 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { tmp27, tmp28 });
        tmp30 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp21 }, TNode<IntPtrT> { tmp13 });
        std::tie(tmp31, tmp32, tmp33) = NewOffHeapConstSlice_int32_0(state_, TNode<RawPtrT> { tmp29 }, TNode<IntPtrT> { tmp30 }).Flatten();
        tmp34 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        compiler::CodeAssemblerLabel label38(&ca_);
        std::tie(tmp35, tmp36, tmp37) = Subslice_int32_0(state_,
            TorqueStructSlice_int32_ConstReference_int32_0 {
                TNode<Object> { tmp31 }, TNode<IntPtrT> { tmp32 }, TNode<IntPtrT> { tmp33 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { tmp34 }, TNode<IntPtrT> { tmp13 }, &label38)
                                            .Flatten();
        ca_.Goto(&block3);
        if (label38.is_used()) {
            ca_.Bind(&label38);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Object> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label42(&ca_);
        std::tie(tmp39, tmp40, tmp41) = Subslice_int32_0(state_,
            TorqueStructSlice_int32_ConstReference_int32_0 {
                TNode<Object> { tmp31 }, TNode<IntPtrT> { tmp32 }, TNode<IntPtrT> { tmp33 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { tmp13 }, TNode<IntPtrT> { tmp21 }, &label42)
                                            .Flatten();
        ca_.Goto(&block7);
        if (label42.is_used()) {
            ca_.Bind(&label42);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<FixedArray> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<Object> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<UintPtrT> tmp52;
    TNode<UintPtrT> tmp53;
    TNode<BoolT> tmp54;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp43 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp44 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp21 }, TNode<IntPtrT> { tmp43 });
        tmp45 = ca_.CallBuiltin<FixedArray>(Builtin::kWasmAllocateZeroedFixedArray, TNode<Object>(), tmp44);
        tmp46 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        std::tie(tmp47, tmp48, tmp49) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp45 }).Flatten();
        tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp51 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp46 }, TNode<IntPtrT> { tmp50 });
        tmp52 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp46 });
        tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp49 });
        tmp54 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp52 }, TNode<UintPtrT> { tmp53 });
        ca_.Branch(tmp54, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<Object> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<Undefined> tmp59;
    TNode<IntPtrT> tmp60;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp55 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp46 });
        tmp56 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp48 }, TNode<IntPtrT> { tmp55 });
        std::tie(tmp57, tmp58) = NewReference_Object_0(state_, TNode<Object> { tmp47 }, TNode<IntPtrT> { tmp56 }).Flatten();
        tmp59 = Undefined_0(state_);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp57, tmp58 }, tmp59);
        tmp60 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block19, tmp51, tmp60);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb19_24;
    TNode<IntPtrT> phi_bb19_25;
    TNode<BoolT> tmp61;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_24, &phi_bb19_25);
        tmp61 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb19_25 }, TNode<IntPtrT> { tmp21 });
        ca_.Branch(
            tmp61, &block17, std::vector<compiler::Node*> { phi_bb19_24, phi_bb19_25 }, &block18, std::vector<compiler::Node*> { phi_bb19_24, phi_bb19_25 });
    }

    TNode<IntPtrT> phi_bb17_24;
    TNode<IntPtrT> phi_bb17_25;
    TNode<Object> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<Object> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<Int32T> tmp67;
    TNode<Object> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<UintPtrT> tmp73;
    TNode<UintPtrT> tmp74;
    TNode<BoolT> tmp75;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_24, &phi_bb17_25);
        tmp62 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { phi_bb17_25 });
        tmp63 = TimesSizeOf_int32_0(state_, TNode<IntPtrT> { phi_bb17_25 });
        tmp64 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp40 }, TNode<IntPtrT> { tmp63 });
        std::tie(tmp65, tmp66) = NewReference_int32_0(state_, TNode<Object> { tmp39 }, TNode<IntPtrT> { tmp64 }).Flatten();
        tmp67 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp65, tmp66 });
        std::tie(tmp68, tmp69, tmp70) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp45 }).Flatten();
        tmp71 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp72 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb17_24 }, TNode<IntPtrT> { tmp71 });
        tmp73 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb17_24 });
        tmp74 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp70 });
        tmp75 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp73 }, TNode<UintPtrT> { tmp74 });
        ca_.Branch(tmp75, &block26, std::vector<compiler::Node*> { phi_bb17_25, phi_bb17_24, phi_bb17_24, phi_bb17_24, phi_bb17_24 }, &block27,
            std::vector<compiler::Node*> { phi_bb17_25, phi_bb17_24, phi_bb17_24, phi_bb17_24, phi_bb17_24 });
    }

    TNode<IntPtrT> phi_bb26_25;
    TNode<IntPtrT> phi_bb26_32;
    TNode<IntPtrT> phi_bb26_33;
    TNode<IntPtrT> phi_bb26_37;
    TNode<IntPtrT> phi_bb26_38;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<Object> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<Object> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_25, &phi_bb26_32, &phi_bb26_33, &phi_bb26_37, &phi_bb26_38);
        tmp76 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { phi_bb26_38 });
        tmp77 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp69 }, TNode<IntPtrT> { tmp76 });
        std::tie(tmp78, tmp79) = NewReference_Object_0(state_, TNode<Object> { tmp68 }, TNode<IntPtrT> { tmp77 }).Flatten();
        tmp80 = ConvertToAndFromWasm_0(state_, TNode<Context> { parameter0 }, TNode<Int32T> { tmp67 }, TNode<Object> { tmp62 });
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp78, tmp79 }, tmp80);
        tmp81 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp82 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb26_25 }, TNode<IntPtrT> { tmp81 });
        ca_.Goto(&block19, tmp72, tmp82);
    }

    TNode<IntPtrT> phi_bb27_25;
    TNode<IntPtrT> phi_bb27_32;
    TNode<IntPtrT> phi_bb27_33;
    TNode<IntPtrT> phi_bb27_37;
    TNode<IntPtrT> phi_bb27_38;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_25, &phi_bb27_32, &phi_bb27_33, &phi_bb27_37, &phi_bb27_38);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb18_24;
    TNode<IntPtrT> phi_bb18_25;
    TNode<IntPtrT> tmp83;
    TNode<HeapObject> tmp84;
    TNode<Int32T> tmp85;
    TNode<Int32T> tmp86;
    TNode<Object> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<BoolT> tmp89;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_24, &phi_bb18_25);
        tmp83 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp84 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp5, tmp83 });
        tmp85 = Convert_int32_intptr_0(state_, TNode<IntPtrT> { tmp44 });
        tmp86 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp87 = ca_.CallBuiltin<Object>(Builtin::kCallVarargs, parameter0, tmp84, tmp86, tmp85, tmp45);
        tmp88 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp89 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { tmp13 }, TNode<IntPtrT> { tmp88 });
        ca_.Branch(tmp89, &block34, std::vector<compiler::Node*> { phi_bb18_24 }, &block35, std::vector<compiler::Node*> { phi_bb18_24 });
    }

    TNode<IntPtrT> phi_bb34_24;
    TNode<Undefined> tmp90;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_24);
        tmp90 = Undefined_0(state_);
        ca_.Goto(&block36, phi_bb34_24, tmp90);
    }

    TNode<IntPtrT> phi_bb35_24;
    TNode<IntPtrT> tmp91;
    TNode<BoolT> tmp92;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_24);
        tmp91 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp92 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { tmp13 }, TNode<IntPtrT> { tmp91 });
        ca_.Branch(tmp92, &block37, std::vector<compiler::Node*> { phi_bb35_24 }, &block38, std::vector<compiler::Node*> { phi_bb35_24 });
    }

    TNode<IntPtrT> phi_bb37_24;
    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<Object> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<Int32T> tmp98;
    TNode<Object> tmp99;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_24);
        tmp93 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp94 = TimesSizeOf_int32_0(state_, TNode<IntPtrT> { tmp93 });
        tmp95 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp36 }, TNode<IntPtrT> { tmp94 });
        std::tie(tmp96, tmp97) = NewReference_int32_0(state_, TNode<Object> { tmp35 }, TNode<IntPtrT> { tmp95 }).Flatten();
        tmp98 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp96, tmp97 });
        tmp99 = ConvertToAndFromWasm_0(state_, TNode<Context> { parameter0 }, TNode<Int32T> { tmp98 }, TNode<Object> { tmp87 });
        ca_.Goto(&block39, phi_bb37_24, tmp99);
    }

    TNode<IntPtrT> phi_bb38_24;
    TNode<Smi> tmp100;
    TNode<FixedArray> tmp101;
    TNode<Smi> tmp102;
    TNode<JSArray> tmp103;
    TNode<IntPtrT> tmp104;
    TNode<FixedArrayBase> tmp105;
    TNode<FixedArray> tmp106;
    TNode<IntPtrT> tmp107;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_24);
        tmp100 = Convert_Smi_intptr_0(state_, TNode<IntPtrT> { tmp13 });
        tmp101 = ca_.CallBuiltin<FixedArray>(Builtin::kIterableToFixedArrayForWasm, parameter0, tmp87, tmp100);
        tmp102 = Convert_Smi_intptr_0(state_, TNode<IntPtrT> { tmp13 });
        tmp103 = ca_.CallBuiltin<JSArray>(Builtin::kWasmAllocateJSArray, parameter0, tmp102);
        tmp104 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp105 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference { tmp103, tmp104 });
        tmp106 = UnsafeCast_FixedArray_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp105 });
        tmp107 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block43, phi_bb38_24, tmp107);
    }

    TNode<IntPtrT> phi_bb43_24;
    TNode<IntPtrT> phi_bb43_30;
    TNode<BoolT> tmp108;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_24, &phi_bb43_30);
        tmp108 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb43_30 }, TNode<IntPtrT> { tmp13 });
        ca_.Branch(
            tmp108, &block41, std::vector<compiler::Node*> { phi_bb43_24, phi_bb43_30 }, &block42, std::vector<compiler::Node*> { phi_bb43_24, phi_bb43_30 });
    }

    TNode<IntPtrT> phi_bb41_24;
    TNode<IntPtrT> phi_bb41_30;
    TNode<Object> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<UintPtrT> tmp112;
    TNode<UintPtrT> tmp113;
    TNode<BoolT> tmp114;
    if (block41.is_used()) {
        ca_.Bind(&block41, &phi_bb41_24, &phi_bb41_30);
        std::tie(tmp109, tmp110, tmp111) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp101 }).Flatten();
        tmp112 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb41_30 });
        tmp113 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp111 });
        tmp114 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp112 }, TNode<UintPtrT> { tmp113 });
        ca_.Branch(tmp114, &block49, std::vector<compiler::Node*> { phi_bb41_24, phi_bb41_30, phi_bb41_30, phi_bb41_30, phi_bb41_30, phi_bb41_30 }, &block50,
            std::vector<compiler::Node*> { phi_bb41_24, phi_bb41_30, phi_bb41_30, phi_bb41_30, phi_bb41_30, phi_bb41_30 });
    }

    TNode<IntPtrT> phi_bb49_24;
    TNode<IntPtrT> phi_bb49_30;
    TNode<IntPtrT> phi_bb49_35;
    TNode<IntPtrT> phi_bb49_36;
    TNode<IntPtrT> phi_bb49_40;
    TNode<IntPtrT> phi_bb49_41;
    TNode<IntPtrT> tmp115;
    TNode<IntPtrT> tmp116;
    TNode<Object> tmp117;
    TNode<IntPtrT> tmp118;
    TNode<Object> tmp119;
    TNode<Object> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<Object> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<Int32T> tmp125;
    TNode<Object> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<UintPtrT> tmp129;
    TNode<UintPtrT> tmp130;
    TNode<BoolT> tmp131;
    if (block49.is_used()) {
        ca_.Bind(&block49, &phi_bb49_24, &phi_bb49_30, &phi_bb49_35, &phi_bb49_36, &phi_bb49_40, &phi_bb49_41);
        tmp115 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { phi_bb49_41 });
        tmp116 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp110 }, TNode<IntPtrT> { tmp115 });
        std::tie(tmp117, tmp118) = NewReference_Object_0(state_, TNode<Object> { tmp109 }, TNode<IntPtrT> { tmp116 }).Flatten();
        tmp119 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp117, tmp118 });
        tmp120 = UnsafeCast_JSAny_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp119 });
        tmp121 = TimesSizeOf_int32_0(state_, TNode<IntPtrT> { phi_bb49_30 });
        tmp122 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp36 }, TNode<IntPtrT> { tmp121 });
        std::tie(tmp123, tmp124) = NewReference_int32_0(state_, TNode<Object> { tmp35 }, TNode<IntPtrT> { tmp122 }).Flatten();
        tmp125 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp123, tmp124 });
        std::tie(tmp126, tmp127, tmp128) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp106 }).Flatten();
        tmp129 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb49_30 });
        tmp130 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp128 });
        tmp131 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp129 }, TNode<UintPtrT> { tmp130 });
        ca_.Branch(tmp131, &block58, std::vector<compiler::Node*> { phi_bb49_24, phi_bb49_30, phi_bb49_30, phi_bb49_30, phi_bb49_30, phi_bb49_30 }, &block59,
            std::vector<compiler::Node*> { phi_bb49_24, phi_bb49_30, phi_bb49_30, phi_bb49_30, phi_bb49_30, phi_bb49_30 });
    }

    TNode<IntPtrT> phi_bb50_24;
    TNode<IntPtrT> phi_bb50_30;
    TNode<IntPtrT> phi_bb50_35;
    TNode<IntPtrT> phi_bb50_36;
    TNode<IntPtrT> phi_bb50_40;
    TNode<IntPtrT> phi_bb50_41;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_24, &phi_bb50_30, &phi_bb50_35, &phi_bb50_36, &phi_bb50_40, &phi_bb50_41);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb58_24;
    TNode<IntPtrT> phi_bb58_30;
    TNode<IntPtrT> phi_bb58_37;
    TNode<IntPtrT> phi_bb58_38;
    TNode<IntPtrT> phi_bb58_42;
    TNode<IntPtrT> phi_bb58_43;
    TNode<IntPtrT> tmp132;
    TNode<IntPtrT> tmp133;
    TNode<Object> tmp134;
    TNode<IntPtrT> tmp135;
    TNode<Object> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<IntPtrT> tmp138;
    if (block58.is_used()) {
        ca_.Bind(&block58, &phi_bb58_24, &phi_bb58_30, &phi_bb58_37, &phi_bb58_38, &phi_bb58_42, &phi_bb58_43);
        tmp132 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { phi_bb58_43 });
        tmp133 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp127 }, TNode<IntPtrT> { tmp132 });
        std::tie(tmp134, tmp135) = NewReference_Object_0(state_, TNode<Object> { tmp126 }, TNode<IntPtrT> { tmp133 }).Flatten();
        tmp136 = ConvertToAndFromWasm_0(state_, TNode<Context> { parameter0 }, TNode<Int32T> { tmp125 }, TNode<Object> { tmp120 });
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp134, tmp135 }, tmp136);
        tmp137 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp138 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb58_30 }, TNode<IntPtrT> { tmp137 });
        ca_.Goto(&block43, phi_bb58_24, tmp138);
    }

    TNode<IntPtrT> phi_bb59_24;
    TNode<IntPtrT> phi_bb59_30;
    TNode<IntPtrT> phi_bb59_37;
    TNode<IntPtrT> phi_bb59_38;
    TNode<IntPtrT> phi_bb59_42;
    TNode<IntPtrT> phi_bb59_43;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_24, &phi_bb59_30, &phi_bb59_37, &phi_bb59_38, &phi_bb59_42, &phi_bb59_43);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb42_24;
    TNode<IntPtrT> phi_bb42_30;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_24, &phi_bb42_30);
        ca_.Goto(&block39, phi_bb42_24, tmp103);
    }

    TNode<IntPtrT> phi_bb39_24;
    TNode<Object> phi_bb39_26;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_24, &phi_bb39_26);
        ca_.Goto(&block36, phi_bb39_24, phi_bb39_26);
    }

    TNode<IntPtrT> phi_bb36_24;
    TNode<Object> phi_bb36_26;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_24, &phi_bb36_26);
        arguments.PopAndReturn(phi_bb36_26);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=84&c=7
TNode<WasmImportData> UnsafeCast_WasmImportData_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmImportData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<WasmImportData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=86&c=24
TorqueStructReference_intptr_0 NewOffHeapReference_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_intptr_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_intptr_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_intptr_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=90&c=28
int31_t SizeOf_intptr_0(compiler::CodeAssemblerState* state_)
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
    return kIntptrSize;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=91&c=30
TorqueStructReference_RawPtr_int32_0 NewOffHeapReference_RawPtr_int32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_RawPtr_int32_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_RawPtr_int32_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_RawPtr_int32_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=95&c=7
TorqueStructSlice_int32_ConstReference_int32_0 NewOffHeapConstSlice_int32_0(
    compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_startPointer, TNode<IntPtrT> p_length)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_int32_0(state_, TNode<RawPtrT> { p_startPointer });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6, tmp7) = (TorqueStructSlice_int32_ConstReference_int32_0 {
                                          TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TNode<IntPtrT> { p_length }, TorqueStructUnsafe_0 {} })
                                         .Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructSlice_int32_ConstReference_int32_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TNode<IntPtrT> { tmp7 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=98&c=7
TorqueStructSlice_int32_ConstReference_int32_0 Subslice_int32_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_int32_ConstReference_int32_0 p_slice,
    TNode<IntPtrT> p_start, TNode<IntPtrT> p_length, compiler::CodeAssemblerLabel* label_OutOfBounds)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { p_length });
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { p_slice.length });
        tmp2 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { tmp0 }, TNode<UintPtrT> { tmp1 });
        ca_.Branch(tmp2, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block1);
    }

    TNode<UintPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<UintPtrT> tmp5;
    TNode<BoolT> tmp6;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { p_start });
        tmp4 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { p_slice.length }, TNode<IntPtrT> { p_length });
        tmp5 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { tmp4 });
        tmp6 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { tmp5 });
        ca_.Branch(tmp6, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block1);
    }

    TNode<IntPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Object> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp7 = TimesSizeOf_int32_0(state_, TNode<IntPtrT> { p_start });
        tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp7 });
        std::tie(tmp9, tmp10, tmp11)
            = NewConstSlice_int32_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp8 }, TNode<IntPtrT> { p_length }).Flatten();
        ca_.Goto(&block7);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_OutOfBounds);
    }

    ca_.Bind(&block7);
    return TorqueStructSlice_int32_ConstReference_int32_0 { TNode<Object> { tmp9 }, TNode<IntPtrT> { tmp10 }, TNode<IntPtrT> { tmp11 },
        TorqueStructUnsafe_0 {} };
}

} // namespace internal
} // namespace v8
