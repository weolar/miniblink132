#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SET_INTERSECTION_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SET_INTERSECTION_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-intersection.tq?l=40&c=27
TNode<OrderedHashSet> FastIntersect_StableJSSetBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TorqueStructStableJSSetBackingTableWitness_0 p_collectionToIterate, TorqueStructStableJSSetBackingTableWitness_0 p_tableToLookup,
    TNode<String> p_methodName, TNode<OrderedHashSet> p_resultSetData);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-intersection.tq?l=58&c=27
TNode<OrderedHashSet> FastIntersect_StableJSMapBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TorqueStructStableJSSetBackingTableWitness_0 p_collectionToIterate, TorqueStructStableJSMapBackingTableWitness_0 p_tableToLookup,
    TNode<String> p_methodName, TNode<OrderedHashSet> p_resultSetData);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SET_INTERSECTION_TQ_CSA_H_
