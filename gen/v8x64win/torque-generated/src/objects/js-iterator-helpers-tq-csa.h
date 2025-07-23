#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ITERATOR_HELPERS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ITERATOR_HELPERS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=5&c=1
TNode<JSIteratorHelper> Cast_JSIteratorHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=13&c=1
TNode<JSIteratorMapHelper> Cast_JSIteratorMapHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=18&c=1
TNode<JSIteratorFilterHelper> Cast_JSIteratorFilterHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=23&c=1
TNode<JSIteratorTakeHelper> Cast_JSIteratorTakeHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=27&c=1
TNode<JSIteratorDropHelper> Cast_JSIteratorDropHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=31&c=1
TNode<JSIteratorFlatMapHelper> Cast_JSIteratorFlatMapHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
TNode<HeapObject> LoadJSIteratorHelperUnderlyingObject_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
void StoreJSIteratorHelperUnderlyingObject_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
TNode<Object> LoadJSIteratorHelperUnderlyingNext_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
void StoreJSIteratorHelperUnderlyingNext_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorHelper> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
TNode<JSReceiver> LoadJSIteratorMapHelperMapper_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorMapHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
void StoreJSIteratorMapHelperMapper_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorMapHelper> p_o, TNode<JSReceiver> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
TNode<Number> LoadJSIteratorMapHelperCounter_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorMapHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
void StoreJSIteratorMapHelperCounter_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorMapHelper> p_o, TNode<Number> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
TNode<JSReceiver> LoadJSIteratorFilterHelperPredicate_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFilterHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
void StoreJSIteratorFilterHelperPredicate_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFilterHelper> p_o, TNode<JSReceiver> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
TNode<Number> LoadJSIteratorFilterHelperCounter_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFilterHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
void StoreJSIteratorFilterHelperCounter_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFilterHelper> p_o, TNode<Number> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
TNode<Number> LoadJSIteratorTakeHelperRemaining_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorTakeHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
void StoreJSIteratorTakeHelperRemaining_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorTakeHelper> p_o, TNode<Number> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
TNode<Number> LoadJSIteratorDropHelperRemaining_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorDropHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
void StoreJSIteratorDropHelperRemaining_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorDropHelper> p_o, TNode<Number> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
TNode<JSReceiver> LoadJSIteratorFlatMapHelperMapper_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFlatMapHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
void StoreJSIteratorFlatMapHelperMapper_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFlatMapHelper> p_o, TNode<JSReceiver> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
TNode<Number> LoadJSIteratorFlatMapHelperCounter_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFlatMapHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
void StoreJSIteratorFlatMapHelperCounter_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFlatMapHelper> p_o, TNode<Number> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
TorqueStructIteratorRecord LoadJSIteratorFlatMapHelperInnerIterator_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFlatMapHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
void StoreJSIteratorFlatMapHelperInnerIterator_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFlatMapHelper> p_o, TorqueStructIteratorRecord p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
TNode<Boolean> LoadJSIteratorFlatMapHelperInnerAlive_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFlatMapHelper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
void StoreJSIteratorFlatMapHelperInnerAlive_0(compiler::CodeAssemblerState* state_, TNode<JSIteratorFlatMapHelper> p_o, TNode<Boolean> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=5&c=1
TNode<JSIteratorHelper> DownCastForTorqueClass_JSIteratorHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=13&c=1
TNode<JSIteratorMapHelper> DownCastForTorqueClass_JSIteratorMapHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=18&c=1
TNode<JSIteratorFilterHelper> DownCastForTorqueClass_JSIteratorFilterHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=23&c=1
TNode<JSIteratorTakeHelper> DownCastForTorqueClass_JSIteratorTakeHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=27&c=1
TNode<JSIteratorDropHelper> DownCastForTorqueClass_JSIteratorDropHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=31&c=1
TNode<JSIteratorFlatMapHelper> DownCastForTorqueClass_JSIteratorFlatMapHelper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ITERATOR_HELPERS_TQ_CSA_H_
