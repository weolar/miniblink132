#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_JS_TO_WASM_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_JS_TO_WASM_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=70&c=1
TNode<Int32T> FromConstexpr_ValueKind_constexpr_kRef_0(compiler::CodeAssemblerState* state_, wasm::ValueKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=70&c=1
TNode<Int32T> FromConstexpr_ValueKind_constexpr_kRefNull_0(compiler::CodeAssemblerState* state_, wasm::ValueKind p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=76&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kPromise_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=76&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kNoPromise_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=76&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kStressSwitch_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kExtern_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoExtern_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kString_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kEq_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kI31_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kStruct_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kArray_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kAny_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNone_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kFunc_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoFunc_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kExn_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoExn_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=148&c=1
TNode<Uint32T> Bitcast_uint32_float32_0(compiler::CodeAssemblerState* state_, TNode<Float32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=157&c=1
TNode<IntPtrT> TruncateBigIntToI64_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_input);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=265&c=1
TorqueStructReturnSlotAllocator_0 NewReturnSlotAllocator_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=391&c=1
TorqueStructLocationAllocator_0 LocationAllocatorForParams_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_paramBuffer);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=412&c=1
TorqueStructLocationAllocator_0 LocationAllocatorForReturns_0(
    compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_gpRegs, TNode<RawPtrT> p_fpRegs, TNode<RawPtrT> p_stack);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=427&c=1
TNode<Object> JSToWasmObject_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<HeapObject> p_trustedInstanceDataOrUndefined,
    TNode<Int32T> p_targetType, TNode<Object> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=462&c=1
void HandleF32Params_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TorqueStructLocationAllocator_0 p_locationAllocator,
    TorqueStructReference_intptr_0 p_toRef, TNode<Object> p_param);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=484&c=1
TNode<Object> JSToWasmWrapperHelper_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<Object> p__receiver,
    TNode<JSFunction> p_target, TorqueStructArguments p_arguments, wasm::Promise p_promise);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=797&c=1
TNode<Object> WasmToJSObject_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<Object> p_value, TNode<Int32T> p_retType);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=405&c=32
int31_t SizeOf_float64_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=467&c=8
TorqueStructReference_float64_0 RefCast_float64_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=470&c=8
TorqueStructReference_float32_0 RefCast_float32_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=508&c=30
TorqueStructReference_intptr_0 GetRefAt_intptr_RawFunctionSigPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=513&c=17
TorqueStructReference_WasmCodePointer_0 GetRefAt_WasmCodePointer_RawFunctionSigPtr_0(
    compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=612&c=19
TorqueStructReference_intptr_0 NewReference_intptr_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=693&c=7
TNode<WasmSuspenderObject> UnsafeCast_WasmSuspenderObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=734&c=4
TorqueStructReference_int32_0 GetRefAt_int32_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=735&c=4
TorqueStructReference_bool_0 GetRefAt_bool_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=736&c=4
TorqueStructReference_WasmCodePointer_0 GetRefAt_WasmCodePointer_RawPtr_intptr_0(
    compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=737&c=4
TorqueStructReference_intptr_0 GetRefAt_intptr_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=741&c=4
TorqueStructReference_RawPtr_intptr_0 GetRefAt_RawPtr_intptr_RawPtr_intptr_0(
    compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=848&c=22
TorqueStructReference_int32_0 GetRefAt_int32_WasmCodePointer_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=852&c=37
TorqueStructReference_int64_0 GetRefAt_int64_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=861&c=58
TorqueStructReference_float64_0 GetRefAt_float64_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=871&c=13
TorqueStructReference_float32_0 GetRefAt_float32_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=893&c=23
TorqueStructReference_uintptr_0 GetRefAt_uintptr_RawPtr_uintptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=964&c=37
TorqueStructReference_int64_0 RefCast_int64_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=966&c=16
TorqueStructReference_int32_0 RefCast_int32_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=154&c=10
TorqueStructReference_float32_0 NewReference_float32_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=154&c=10
TorqueStructReference_int64_0 NewReference_int64_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_JS_TO_WASM_TQ_CSA_H_
