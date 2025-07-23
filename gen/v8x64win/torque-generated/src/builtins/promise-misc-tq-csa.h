#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_MISC_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_MISC_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=44&c=1
TNode<BoolT> PromiseHasHandler_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_promise);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=49&c=1
void PromiseInit_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_promise);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=61&c=1
TNode<JSPromise> InnerNewJSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=80&c=1
TNode<PromiseFulfillReactionJobTask> NewPromiseFulfillReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_handlerContext, TNode<Object> p_argument, TNode<HeapObject> p_handler, TNode<HeapObject> p_promiseOrCapability);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=108&c=1
TNode<PromiseRejectReactionJobTask> NewPromiseRejectReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_handlerContext, TNode<Object> p_argument, TNode<HeapObject> p_handler, TNode<HeapObject> p_promiseOrCapability);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=136&c=1
void RunContextPromiseHookInit_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_parent);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=152&c=1
void RunContextPromiseHookResolve_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=164&c=1
void RunContextPromiseHookResolve_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Uint32T> p_flags);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=171&c=1
void RunContextPromiseHookBefore_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=184&c=1
void RunContextPromiseHookBefore_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability, TNode<Uint32T> p_flags);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=194&c=1
void RunContextPromiseHookAfter_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=207&c=1
void RunContextPromiseHookAfter_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability, TNode<Uint32T> p_flags);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=217&c=1
void RunContextPromiseHook_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_slot, TNode<HeapObject> p_promiseOrCapability, TNode<Uint32T> p_flags);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=251&c=1
void RunAnyPromiseHookInit_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_parent);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=271&c=1
TNode<JSPromise> NewJSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_parent);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=282&c=1
TNode<JSPromise> NewJSPromise_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=289&c=1
TNode<JSPromise> NewJSPromise_2(compiler::CodeAssemblerState* state_, TNode<Context> p_context, Promise::PromiseState p_status, TNode<Object> p_result);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=303&c=1
TNode<PromiseReaction> NewPromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_next, TNode<HeapObject> p_promiseOrCapability, TNode<HeapObject> p_fulfillHandler, TNode<HeapObject> p_rejectHandler);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=334&c=1
TNode<PromiseResolveThenableJobTask> NewPromiseResolveThenableJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promiseToResolve, TNode<JSReceiver> p_thenable, TNode<JSReceiver> p_then);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=411&c=1
TNode<Object> InvokeThen_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=418&c=1
TNode<Object> InvokeThen_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=425&c=1
void BranchIfAccessCheckFailed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_promiseConstructor, TNode<Object> p_executor, compiler::CodeAssemblerLabel* label_IfNoAccess);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=52&c=19
TNode<Smi> SmiTag_JSPromiseFlags_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=139&c=22
TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0 NativeContextSlot_Context_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=142&c=24
TNode<BoolT> Is_JSPromise_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=414&c=10
TNode<Object> InvokeThen_InvokeThenOneArgFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2, TorqueStructInvokeThenOneArgFunctor_0 p_callFunctor);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=421&c=10
TNode<Object> InvokeThen_InvokeThenTwoArgFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2, TorqueStructInvokeThenTwoArgFunctor_0 p_callFunctor);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/promise-misc.tq?l=398&c=8
TNode<BoolT> Is_Smi_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_PROMISE_MISC_TQ_CSA_H_
