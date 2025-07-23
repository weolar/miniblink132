#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_HELPERS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_HELPERS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=14&c=1
TNode<Null> kIteratorHelperExhausted_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=16&c=1
TNode<Undefined> kIteratorHelperExecuting_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=18&c=1
TNode<BoolT> IsIteratorHelperExhausted_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=22&c=1
void MarkIteratorHelperAsExhausted_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=26&c=1
TNode<BoolT> IsIteratorHelperExecuting_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=32&c=1
void ThrowIfIteratorHelperExecuting_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSIteratorHelper> p_helper);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=39&c=1
TorqueStructIteratorRecord MarkIteratorHelperAsExecuting_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=48&c=1
void MarkIteratorHelperAsFinishedExecuting_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_helper, TorqueStructIteratorRecord p_underlying);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=56&c=1
TorqueStructIteratorRecord GetIteratorDirect_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_obj);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=181&c=1
TNode<JSIteratorMapHelper> NewJSIteratorMapHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<JSReceiver> p_mapper);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=276&c=1
TNode<JSIteratorFilterHelper> NewJSIteratorFilterHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<JSReceiver> p_predicate);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=378&c=1
TNode<JSIteratorTakeHelper> NewJSIteratorTakeHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<Number> p_limit);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=482&c=1
TNode<JSIteratorDropHelper> NewJSIteratorDropHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<Number> p_limit);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=585&c=1
const char* kFlatMapMethodName_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=587&c=1
TNode<JSIteratorFlatMapHelper> NewJSIteratorFlatMapHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<JSReceiver> p_mapper);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=76&c=18
TNode<JSIteratorHelper> Cast_JSIteratorHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=125&c=5
TNode<JSIteratorFlatMapHelper> Cast_JSIteratorFlatMapHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ITERATOR_HELPERS_TQ_CSA_H_
