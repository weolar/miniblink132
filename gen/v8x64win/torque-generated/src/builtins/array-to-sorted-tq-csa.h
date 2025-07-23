#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TO_SORTED_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TO_SORTED_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-sorted.tq?l=6&c=1
TNode<JSArray> CopyWorkArrayToNewFastJSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<SortState> p_sortState, ElementsKind p_elementsKind, TNode<Smi> p_numberOfNonUndefined);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-sorted.tq?l=36&c=1
TNode<JSArray> CopyWorkArrayToNewJSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<SortState> p_sortState, TNode<Smi> p_numberOfNonUndefined);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-sorted.tq?l=93&c=21
TNode<HeapObject> Cast_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TO_SORTED_TQ_CSA_H_
