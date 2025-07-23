#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_REPLACE_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_REPLACE_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=23&c=1
TNode<IntPtrT> RegExpReplaceCallableNoExplicitCaptures_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_matchesElements, TNode<IntPtrT> p_matchesCapacity, TNode<String> p_string, TNode<JSReceiver> p_replaceFn);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=71&c=1
TNode<IntPtrT> RegExpReplaceCallableWithExplicitCaptures_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_matchesElements, TNode<IntPtrT> p_matchesCapacity, TNode<JSReceiver> p_replaceFn);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=94&c=1
TNode<String> RegExpReplaceFastGlobalCallable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<JSReceiver> p_replaceFn);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=132&c=1
TNode<String> RegExpReplaceFastString_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<String> p_replaceString);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-replace.tq?l=193&c=10
TNode<BoolT> Is_FastJSRegExp_FastJSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_REPLACE_TQ_CSA_H_
