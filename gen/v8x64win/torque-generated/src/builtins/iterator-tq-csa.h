#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=107&c=1
TorqueStructIteratorRecord GetIteratorRecordAfterCreateAsyncFromSyncIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_asyncIterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=119&c=1
TNode<Object> GetLazyReceiver_0(compiler::CodeAssemblerState* state_, TNode<Object> p_receiver);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=141&c=1
void IteratorCloseOnException_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_iterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=163&c=1
void IteratorClose_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_iterator);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=208&c=1
TNode<Object> SetterThatIgnoresPrototypeProperties_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<JSObject> p_home, TNode<Object> p_key, TNode<Object> p_value, const char* p_methodName);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=317&c=1
intptr_t kAsyncIteratorPrototypeAsyncDisposeResolveContextLength_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator.tq?l=366&c=11
TNode<JSPromise> UnsafeCast_JSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_TQ_CSA_H_
