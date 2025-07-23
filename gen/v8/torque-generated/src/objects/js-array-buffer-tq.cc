#include "src/objects/js-array-buffer-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=63&c=1
bool IsJSArrayBufferView_NonInline(Tagged<HeapObject> o)
{
    return IsJSArrayBufferView(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSArrayBufferView<JSArrayBufferView, JSAPIObjectWithEmbedderSlots>::JSArrayBufferViewVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSArrayBufferViewVerify(Cast<JSArrayBufferView>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=107&c=1
bool IsJSTypedArray_NonInline(Tagged<HeapObject> o)
{
    return IsJSTypedArray(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSTypedArray<JSTypedArray, JSArrayBufferView>::JSTypedArrayVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSTypedArrayVerify(Cast<JSTypedArray>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=14&c=1
bool IsJSArrayBuffer_NonInline(Tagged<HeapObject> o)
{
    return IsJSArrayBuffer(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSArrayBuffer<JSArrayBuffer, JSAPIObjectWithEmbedderSlots>::JSArrayBufferVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSArrayBufferVerify(Cast<JSArrayBuffer>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=125&c=1
bool IsJSDataViewOrRabGsabDataView_NonInline(Tagged<HeapObject> o)
{
    return IsJSDataViewOrRabGsabDataView(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSDataViewOrRabGsabDataView<JSDataViewOrRabGsabDataView, JSArrayBufferView>::JSDataViewOrRabGsabDataViewVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSDataViewOrRabGsabDataViewVerify(Cast<JSDataViewOrRabGsabDataView>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=131&c=1
bool IsJSDataView_NonInline(Tagged<HeapObject> o)
{
    return IsJSDataView(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSDataView<JSDataView, JSDataViewOrRabGsabDataView>::JSDataViewVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSDataViewVerify(Cast<JSDataView>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=133&c=1
bool IsJSRabGsabDataView_NonInline(Tagged<HeapObject> o)
{
    return IsJSRabGsabDataView(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSRabGsabDataView<JSRabGsabDataView, JSDataViewOrRabGsabDataView>::JSRabGsabDataViewVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSRabGsabDataViewVerify(Cast<JSRabGsabDataView>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
