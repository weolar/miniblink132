#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ATOMICS_SYNCHRONIZATION_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ATOMICS_SYNCHRONIZATION_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=5&c=1
TNode<JSSynchronizationPrimitive> Cast_JSSynchronizationPrimitive_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=11&c=1
TNode<JSAtomicsMutex> Cast_JSAtomicsMutex_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=15&c=1
TNode<JSAtomicsCondition> Cast_JSAtomicsCondition_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=7&c=3
TNode<ExternalPointerT> LoadJSSynchronizationPrimitiveWaiterQueueHead_0(compiler::CodeAssemblerState* state_, TNode<JSSynchronizationPrimitive> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=7&c=3
void StoreJSSynchronizationPrimitiveWaiterQueueHead_0(compiler::CodeAssemblerState* state_, TNode<JSSynchronizationPrimitive> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=8&c=3
TNode<Uint32T> LoadJSSynchronizationPrimitiveState_0(compiler::CodeAssemblerState* state_, TNode<JSSynchronizationPrimitive> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=8&c=3
void StoreJSSynchronizationPrimitiveState_0(compiler::CodeAssemblerState* state_, TNode<JSSynchronizationPrimitive> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=12&c=3
TNode<Int32T> LoadJSAtomicsMutexOwnerThreadId_0(compiler::CodeAssemblerState* state_, TNode<JSAtomicsMutex> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=12&c=3
void StoreJSAtomicsMutexOwnerThreadId_0(compiler::CodeAssemblerState* state_, TNode<JSAtomicsMutex> p_o, TNode<Int32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=5&c=1
TNode<JSSynchronizationPrimitive> DownCastForTorqueClass_JSSynchronizationPrimitive_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=11&c=1
TNode<JSAtomicsMutex> DownCastForTorqueClass_JSAtomicsMutex_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=15&c=1
TNode<JSAtomicsCondition> DownCastForTorqueClass_JSAtomicsCondition_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ATOMICS_SYNCHRONIZATION_TQ_CSA_H_
