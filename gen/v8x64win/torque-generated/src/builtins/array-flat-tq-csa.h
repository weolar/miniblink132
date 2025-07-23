#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_FLAT_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_FLAT_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=7&c=1
TNode<Boolean> ArrayIsArray_Inline_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_element);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=19&c=1
TNode<Number> FlattenIntoArrayFast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_target, TNode<JSReceiver> p_source, TNode<Number> p_sourceLength, TNode<Number> p_start, TNode<Smi> p_depth, bool p_hasMapper, TNode<Object> p_mapfn, TNode<Object> p_thisArgs, compiler::CodeAssemblerLabel* label_Bailout, compiler::TypedCodeAssemblerVariable<Number>* label_Bailout_parameter_0, compiler::TypedCodeAssemblerVariable<Number>* label_Bailout_parameter_1);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=105&c=1
TNode<Number> FlattenIntoArraySlow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_target, TNode<JSReceiver> p_source, TNode<Number> p_sourceIndex, TNode<Number> p_sourceLength, TNode<Number> p_start, TNode<Smi> p_depth, bool p_hasMapper, TNode<Object> p_mapfn, TNode<Object> p_thisArgs);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=167&c=1
TNode<Number> FlattenIntoArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_target, TNode<JSReceiver> p_source, TNode<Number> p_sourceLength, TNode<Number> p_start, TNode<Smi> p_depth, bool p_hasMapper, TNode<Object> p_mapfn, TNode<Object> p_thisArgs);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=9&c=7
TNode<BoolT> Is_JSArray_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=11&c=14
TNode<BoolT> Is_JSProxy_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=34&c=10
TNode<BoolT> Is_Smi_Number_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Number> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=35&c=27
TNode<Smi> UnsafeCast_Smi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-flat.tq?l=65&c=13
TNode<JSArray> Cast_JSArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_FLAT_TQ_CSA_H_
