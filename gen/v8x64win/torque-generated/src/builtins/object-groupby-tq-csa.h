#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_OBJECT_GROUPBY_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_OBJECT_GROUPBY_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object-groupby.tq?l=15&c=1
TNode<Object> CoerceGroupKey_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_key, TNode<Boolean> p_coerceToProperty);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object-groupby.tq?l=94&c=1
TNode<OrderedHashMap> GroupByImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_items, TNode<Object> p_callback, TNode<Boolean> p_coerceToProperty, const char* p_methodName);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/object-groupby.tq?l=109&c=7
TNode<JSArray> Cast_FastJSArrayForReadWithNoCustomIteration_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_OBJECT_GROUPBY_TQ_CSA_H_
