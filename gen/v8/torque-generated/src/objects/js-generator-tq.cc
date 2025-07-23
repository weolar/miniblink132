#include "src/objects/js-generator-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-generator.tq?l=5&c=1
bool IsJSGeneratorObject_NonInline(Tagged<HeapObject> o)
{
    return IsJSGeneratorObject(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSGeneratorObject<JSGeneratorObject, JSObject>::JSGeneratorObjectVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSGeneratorObjectVerify(Cast<JSGeneratorObject>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-generator.tq?l=28&c=1
bool IsJSAsyncFunctionObject_NonInline(Tagged<HeapObject> o)
{
    return IsJSAsyncFunctionObject(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSAsyncFunctionObject<JSAsyncFunctionObject, JSGeneratorObject>::JSAsyncFunctionObjectVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSAsyncFunctionObjectVerify(Cast<JSAsyncFunctionObject>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-generator.tq?l=32&c=1
bool IsJSAsyncGeneratorObject_NonInline(Tagged<HeapObject> o)
{
    return IsJSAsyncGeneratorObject(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSAsyncGeneratorObject<JSAsyncGeneratorObject, JSGeneratorObject>::JSAsyncGeneratorObjectVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSAsyncGeneratorObjectVerify(Cast<JSAsyncGeneratorObject>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-generator.tq?l=40&c=1
bool IsAsyncGeneratorRequest_NonInline(Tagged<HeapObject> o)
{
    return IsAsyncGeneratorRequest(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedAsyncGeneratorRequest<AsyncGeneratorRequest, Struct>::AsyncGeneratorRequestVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::AsyncGeneratorRequestVerify(Cast<AsyncGeneratorRequest>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
