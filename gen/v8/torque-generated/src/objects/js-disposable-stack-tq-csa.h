#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_DISPOSABLE_STACK_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_DISPOSABLE_STACK_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=5&c=1
TNode<Uint32T> FromConstexpr_DisposableStackState_constexpr_kDisposed_0(compiler::CodeAssemblerState* state_, DisposableStackState p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=5&c=1
TNode<Uint32T> FromConstexpr_DisposableStackState_constexpr_kPending_0(compiler::CodeAssemblerState* state_, DisposableStackState p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=6&c=1
TNode<Uint32T> FromConstexpr_DisposeMethodCallType_constexpr_kValueIsReceiver_0(compiler::CodeAssemblerState* state_, DisposeMethodCallType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=6&c=1
TNode<Uint32T> FromConstexpr_DisposeMethodCallType_constexpr_kValueIsArgument_0(compiler::CodeAssemblerState* state_, DisposeMethodCallType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=10&c=1
TNode<Uint32T> FromConstexpr_DisposeMethodHint_constexpr_kSyncDispose_0(compiler::CodeAssemblerState* state_, DisposeMethodHint p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=10&c=1
TNode<Uint32T> FromConstexpr_DisposeMethodHint_constexpr_kAsyncDispose_0(compiler::CodeAssemblerState* state_, DisposeMethodHint p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=11&c=1
TNode<Uint32T> FromConstexpr_DisposableStackResourcesType_constexpr_kAllSync_0(compiler::CodeAssemblerState* state_, DisposableStackResourcesType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=11&c=1
TNode<Uint32T> FromConstexpr_DisposableStackResourcesType_constexpr_kAtLeastOneAsync_0(compiler::CodeAssemblerState* state_, DisposableStackResourcesType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=23&c=1
TNode<JSDisposableStackBase> Cast_JSDisposableStackBase_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=34&c=1
TNode<JSSyncDisposableStack> Cast_JSSyncDisposableStack_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=36&c=1
TNode<JSAsyncDisposableStack> Cast_JSAsyncDisposableStack_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=29&c=3
TNode<FixedArray> LoadJSDisposableStackBaseStack_0(compiler::CodeAssemblerState* state_, TNode<JSDisposableStackBase> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=29&c=3
void StoreJSDisposableStackBaseStack_0(compiler::CodeAssemblerState* state_, TNode<JSDisposableStackBase> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=30&c=3
TNode<Smi> LoadJSDisposableStackBaseStatus_0(compiler::CodeAssemblerState* state_, TNode<JSDisposableStackBase> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=30&c=3
void StoreJSDisposableStackBaseStatus_0(compiler::CodeAssemblerState* state_, TNode<JSDisposableStackBase> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=31&c=3
TNode<Object> LoadJSDisposableStackBaseError_0(compiler::CodeAssemblerState* state_, TNode<JSDisposableStackBase> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=31&c=3
void StoreJSDisposableStackBaseError_0(compiler::CodeAssemblerState* state_, TNode<JSDisposableStackBase> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=23&c=1
TNode<JSDisposableStackBase> DownCastForTorqueClass_JSDisposableStackBase_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=34&c=1
TNode<JSSyncDisposableStack> DownCastForTorqueClass_JSSyncDisposableStack_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=36&c=1
TNode<JSAsyncDisposableStack> DownCastForTorqueClass_JSAsyncDisposableStack_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_DISPOSABLE_STACK_TQ_CSA_H_
