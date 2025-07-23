#include "src/objects/js-segments-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=11&c=1
bool IsJSSegments_NonInline(Tagged<HeapObject> o)
{
    return IsJSSegments(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSSegments<JSSegments, JSObject>::JSSegmentsVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSSegmentsVerify(Cast<JSSegments>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
