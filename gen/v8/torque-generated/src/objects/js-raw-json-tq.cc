#include "src/objects/js-raw-json-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-raw-json.tq?l=7&c=1
bool IsJSRawJson_NonInline(Tagged<HeapObject> o)
{
    return IsJSRawJson(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSRawJson<JSRawJson, JSObject>::JSRawJsonVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSRawJsonVerify(Cast<JSRawJson>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
