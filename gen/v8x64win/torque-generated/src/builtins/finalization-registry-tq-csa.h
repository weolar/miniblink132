#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_FINALIZATION_REGISTRY_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_FINALIZATION_REGISTRY_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=20&c=1
TNode<HeapObject> SplitOffTail_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_weakCell);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=34&c=1
TNode<HeapObject> PopClearedCell_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationRegistry> p_finalizationRegistry);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=59&c=1
void PushCell_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationRegistry> p_finalizationRegistry, TNode<WeakCell> p_cell);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=72&c=1
void FinalizationRegistryCleanupLoop_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFinalizationRegistry> p_finalizationRegistry, TNode<JSReceiver> p_callback);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=115&c=32
TNode<JSFinalizationRegistry> UnsafeCast_JSFinalizationRegistry_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=123&c=7
TNode<Smi> SmiTag_FinalizationRegistryFlags_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=137&c=32
TNode<JSFinalizationRegistry> Cast_JSFinalizationRegistry_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/finalization-registry.tq?l=145&c=18
TNode<HeapObject> UnsafeCast_JSReceiver_OR_Symbol_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_FINALIZATION_REGISTRY_TQ_CSA_H_
