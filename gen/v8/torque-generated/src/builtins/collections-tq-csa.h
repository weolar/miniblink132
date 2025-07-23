#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_COLLECTIONS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_COLLECTIONS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=103&c=1
TNode<Int32T> LoadOrderedHashTableMetadata_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_table, int32_t p_fieldIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=115&c=1
TorqueStructUnmodifiedOrderedHashSetIterator_0 NewUnmodifiedOrderedHashSetIterator_0(compiler::CodeAssemblerState* state_, TNode<OrderedHashSet> p_table);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=135&c=1
TorqueStructOrderedHashSetIterator_0 NewOrderedHashSetIterator_0(compiler::CodeAssemblerState* state_, TNode<OrderedHashSet> p_table);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=200&c=1
TorqueStructUnmodifiedOrderedHashMapIterator_0 NewUnmodifiedOrderedHashMapIterator_0(compiler::CodeAssemblerState* state_, TNode<OrderedHashMap> p_table);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=220&c=1
TorqueStructKeyValuePair LoadKeyValuePairNoSideEffects_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_MayHaveSideEffects);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=254&c=1
TorqueStructKeyValuePair LoadKeyValuePair_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=270&c=1
TorqueStructSetRecord GetSetRecord_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_obj, const char* p_methodName);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=316&c=1
TorqueStructIteratorRecord GetKeysIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_set, TNode<JSReceiver> p_keys);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=338&c=1
void CheckSetRecordHasJSSetMethods_0(
    compiler::CodeAssemblerState* state_, TorqueStructSetRecord p_setRecord, compiler::CodeAssemblerLabel* label_HasUserProvidedMethods);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=352&c=1
void CheckSetRecordHasJSMapMethods_0(
    compiler::CodeAssemblerState* state_, TorqueStructSetRecord p_setRecord, compiler::CodeAssemblerLabel* label_HasUserProvidedMethods);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=366&c=1
TNode<OrderedHashSet> ShrinkOrderedHashSetIfNeeded_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_numberOfElements, TNode<OrderedHashSet> p_resultSetData);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=425&c=1
TorqueStructStableJSSetBackingTableWitness_0 NewStableBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<JSSet> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=433&c=1
TorqueStructStableJSMapBackingTableWitness_0 NewStableBackingTableWitness_1(compiler::CodeAssemblerState* state_, TNode<JSMap> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=429&c=15
TNode<OrderedHashSet> Cast_StableOrderedHashSet_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/collections.tq?l=437&c=15
TNode<OrderedHashMap> Cast_StableOrderedHashMap_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_COLLECTIONS_TQ_CSA_H_
