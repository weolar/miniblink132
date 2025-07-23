#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ARRAY_BUFFER_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ARRAY_BUFFER_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=14&c=1
TNode<JSArrayBuffer> Cast_JSArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=37&c=1
TNode<BoolT> IsDetachedBuffer_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=42&c=1
TNode<BoolT> IsSharedArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=47&c=1
TNode<BoolT> IsResizableArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=63&c=1
TNode<JSArrayBufferView> Cast_JSArrayBufferView_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=83&c=1
TNode<BoolT> IsVariableLengthJSArrayBufferView_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_array);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=88&c=1
TNode<BoolT> IsLengthTrackingJSArrayBufferView_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_array);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=96&c=1
TNode<UintPtrT> LoadJSArrayBufferViewByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_view, TNode<JSArrayBuffer> p_buffer,
    compiler::CodeAssemblerLabel* label_DetachedOrOutOfBounds);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=107&c=1
TNode<JSTypedArray> Cast_JSTypedArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=119&c=1
TNode<BoolT> IsOnHeapTypedArray_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_array);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=125&c=1
TNode<JSDataViewOrRabGsabDataView> Cast_JSDataViewOrRabGsabDataView_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=131&c=1
TNode<JSDataView> Cast_JSDataView_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=133&c=1
TNode<JSRabGsabDataView> Cast_JSRabGsabDataView_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
TNode<JSArrayBuffer> LoadJSArrayBufferViewBuffer_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
void StoreJSArrayBufferViewBuffer_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o, TNode<JSArrayBuffer> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=66&c=3
TNode<Uint32T> LoadJSArrayBufferViewBitField_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=66&c=3
void StoreJSArrayBufferViewBitField_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=69&c=3
TNode<UintPtrT> LoadJSArrayBufferViewRawByteOffset_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=69&c=3
void StoreJSArrayBufferViewRawByteOffset_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o, TNode<UintPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=71&c=3
TNode<UintPtrT> LoadJSArrayBufferViewRawByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=71&c=3
void StoreJSArrayBufferViewRawByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_o, TNode<UintPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=109&c=3
TNode<UintPtrT> LoadJSTypedArrayRawLength_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=109&c=3
void StoreJSTypedArrayRawLength_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o, TNode<UintPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=111&c=3
TNode<RawPtrT> LoadJSTypedArrayExternalPointer_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=111&c=3
void StoreJSTypedArrayExternalPointer_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o, TNode<RawPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
TNode<Object> LoadJSTypedArrayBasePointer_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
void StoreJSTypedArrayBasePointer_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
TNode<Object> LoadJSArrayBufferDetachKey_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
void StoreJSArrayBufferDetachKey_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=17&c=3
TNode<UintPtrT> LoadJSArrayBufferRawByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=17&c=3
void StoreJSArrayBufferRawByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o, TNode<UintPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=19&c=3
TNode<UintPtrT> LoadJSArrayBufferRawMaxByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=19&c=3
void StoreJSArrayBufferRawMaxByteLength_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o, TNode<UintPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=21&c=3
TNode<RawPtrT> LoadJSArrayBufferBackingStore_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=21&c=3
void StoreJSArrayBufferBackingStore_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o, TNode<RawPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=22&c=3
TNode<ExternalPointerT> LoadJSArrayBufferExtension_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=22&c=3
void StoreJSArrayBufferExtension_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=23&c=3
TNode<Uint32T> LoadJSArrayBufferBitField_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=23&c=3
void StoreJSArrayBufferBitField_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=128&c=3
TNode<RawPtrT> LoadJSDataViewOrRabGsabDataViewDataPointer_0(compiler::CodeAssemblerState* state_, TNode<JSDataViewOrRabGsabDataView> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=128&c=3
void StoreJSDataViewOrRabGsabDataViewDataPointer_0(compiler::CodeAssemblerState* state_, TNode<JSDataViewOrRabGsabDataView> p_o, TNode<RawPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=14&c=1
TNode<JSArrayBuffer> DownCastForTorqueClass_JSArrayBuffer_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=63&c=1
TNode<JSArrayBufferView> DownCastForTorqueClass_JSArrayBufferView_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=107&c=1
TNode<JSTypedArray> DownCastForTorqueClass_JSTypedArray_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=125&c=1
TNode<JSDataViewOrRabGsabDataView> DownCastForTorqueClass_JSDataViewOrRabGsabDataView_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=131&c=1
TNode<JSDataView> DownCastForTorqueClass_JSDataView_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=133&c=1
TNode<JSRabGsabDataView> DownCastForTorqueClass_JSRabGsabDataView_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_ARRAY_BUFFER_TQ_CSA_H_
