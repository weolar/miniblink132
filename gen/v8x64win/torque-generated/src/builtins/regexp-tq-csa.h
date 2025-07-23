#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=12&c=1
TNode<BoolT> IsFastRegExpForMatch_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=19&c=1
TNode<BoolT> IsFastRegExpForSearch_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=27&c=1
TNode<BoolT> IsFastRegExpStrict_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=35&c=1
TNode<BoolT> IsFastRegExpPermissive_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=42&c=1
TNode<Object> RegExpExec_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_string);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=86&c=1
TNode<RegExpMatchInfo> RegExpPrototypeExecBodyWithoutResult_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<Number> p_regexpLastIndex, bool p_isFastPath, compiler::CodeAssemblerLabel* label_IfDidNotMatch);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=138&c=1
TNode<RegExpMatchInfo> RegExpPrototypeExecBodyWithoutResultFast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, compiler::CodeAssemblerLabel* label_IfDidNotMatch);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=147&c=1
TNode<RegExpMatchInfo> RegExpPrototypeExecBodyWithoutResultFast_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<Number> p_lastIndex, compiler::CodeAssemblerLabel* label_IfDidNotMatch);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=156&c=1
TNode<Object> RegExpPrototypeExecBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_string, bool p_isFastPath);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=174&c=1
TNode<JSFunction> LoadRegExpFunction_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_nativeContext);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=180&c=1
TNode<BoolT> HasInitialRegExpMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=187&c=1
TNode<BoolT> IsReceiverInitialRegExpPrototype_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=209&c=1
int31_t kNoCounterFlagGetter_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=219&c=1
TNode<Object> FlagGetter_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, JSRegExp::Flag p_flag, int31_t p_counter, const char* p_methodName);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=314&c=1
TNode<String> FastFlagsGetter_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_receiver);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=319&c=1
TNode<String> SlowFlagsGetter_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=347&c=1
TNode<Object> LoadLastIndex_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_regexp, bool p_isFastPath);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=355&c=1
TNode<Number> LoadLastIndexAsLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, bool p_isFastPath);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=376&c=1
void StoreLastIndex_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_regexp, TNode<Number> p_value, bool p_isFastPath);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=404&c=1
TNode<BoolT> IsRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_obj);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=435&c=1
TNode<Object> RegExpCreate_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_maybeString, TNode<String> p_flags);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=448&c=1
TNode<Object> RegExpCreate_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_initialMap, TNode<Object> p_maybeString, TNode<String> p_flags);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=334&c=22
TNode<JSRegExp> Cast_FastJSRegExp_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=362&c=12
TNode<Smi> UnsafeCast_PositiveSmi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp.tq?l=411&c=12
TNode<BoolT> Is_JSRegExp_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_TQ_CSA_H_
