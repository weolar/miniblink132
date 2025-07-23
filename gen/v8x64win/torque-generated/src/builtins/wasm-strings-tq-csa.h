#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_STRINGS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_STRINGS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-strings.tq?l=9&c=1
void Trap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, MessageTemplate p_error);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-strings.tq?l=51&c=10
TNode<BoolT> Is_String_String_OR_WasmNull_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm-strings.tq?l=136&c=12
TNode<Smi> SmiTag_char16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_value);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_STRINGS_TQ_CSA_H_
