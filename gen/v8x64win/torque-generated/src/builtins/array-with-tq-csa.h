#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_WITH_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_WITH_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-with.tq?l=6&c=1
TNode<JSArray> TryFastPackedArrayWith_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<Number> p_len, TNode<Number> p_actualIndex, TNode<Object> p_value, compiler::CodeAssemblerLabel* label_Slow);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_WITH_TQ_CSA_H_
