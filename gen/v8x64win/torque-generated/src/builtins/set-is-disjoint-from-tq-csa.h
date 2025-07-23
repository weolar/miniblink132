#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SET_IS_DISJOINT_FROM_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SET_IS_DISJOINT_FROM_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-is-disjoint-from.tq?l=38&c=18
TNode<Boolean> FastIsDisjointFrom_StableJSSetBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructStableJSSetBackingTableWitness_0 p_collectionToIterate, TorqueStructStableJSSetBackingTableWitness_0 p_tableToLookup);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-is-disjoint-from.tq?l=53&c=18
TNode<Boolean> FastIsDisjointFrom_StableJSMapBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructStableJSSetBackingTableWitness_0 p_collectionToIterate, TorqueStructStableJSMapBackingTableWitness_0 p_tableToLookup);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SET_IS_DISJOINT_FROM_TQ_CSA_H_
