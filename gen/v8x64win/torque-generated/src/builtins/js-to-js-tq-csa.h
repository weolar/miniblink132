#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_JS_TO_JS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_JS_TO_JS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=18&c=1
TNode<Object> ConvertToAndFromWasm_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Int32T> p_wasmType, TNode<Object> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=84&c=7
TNode<WasmImportData> UnsafeCast_WasmImportData_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=86&c=24
TorqueStructReference_intptr_0 NewOffHeapReference_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=90&c=28
int31_t SizeOf_intptr_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=91&c=30
TorqueStructReference_RawPtr_int32_0 NewOffHeapReference_RawPtr_int32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=95&c=7
TorqueStructSlice_int32_ConstReference_int32_0 NewOffHeapConstSlice_int32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_startPointer, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-js.tq?l=98&c=7
TorqueStructSlice_int32_ConstReference_int32_0 Subslice_int32_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_int32_ConstReference_int32_0 p_slice, TNode<IntPtrT> p_start, TNode<IntPtrT> p_length, compiler::CodeAssemblerLabel* label_OutOfBounds);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_JS_TO_JS_TQ_CSA_H_
