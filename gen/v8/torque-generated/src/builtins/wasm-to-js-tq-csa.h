#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_TO_JS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_TO_JS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-to-js.tq?l=28&c=1
void HandleF32Returns_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TorqueStructLocationAllocator_0 p_locationAllocator,
    TorqueStructReference_intptr_0 p_toRef, TNode<Object> p_retVal);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-to-js.tq?l=50&c=1
TorqueStructWasmToJSResult WasmToJSWrapper_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_data);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-to-js.tq?l=53&c=10
TNode<BoolT> Is_WasmImportData_WasmImportData_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<WasmImportData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-to-js.tq?l=58&c=4
TorqueStructReference_WasmCodePointer_0 GetRefAt_WasmCodePointer_WasmCodePointer_0(
    compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-to-js.tq?l=187&c=4
TorqueStructReference_intptr_0 GetRefAt_intptr_WasmCodePointer_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-to-js.tq?l=266&c=11
TNode<WasmTrustedInstanceData> UnsafeCast_WasmTrustedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-to-js.tq?l=312&c=15
TorqueStructReference_float64_0 GetRefAt_float64_RawPtr_float64_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_TO_JS_TQ_CSA_H_
