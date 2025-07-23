#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_FROM_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_FROM_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-from.tq?l=7&c=1
TNode<JSValidIteratorWrapper> NewJSValidIteratorWrapper_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-from.tq?l=19&c=1
TorqueStructIteratorRecord GetIteratorFlattenable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_obj);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-from.tq?l=95&c=13
TNode<JSValidIteratorWrapper> Cast_JSValidIteratorWrapper_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_FROM_TQ_CSA_H_
