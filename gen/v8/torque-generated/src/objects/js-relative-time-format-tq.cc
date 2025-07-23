#include "src/objects/js-relative-time-format-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=13&c=1
bool IsJSRelativeTimeFormat_NonInline(Tagged<HeapObject> o)
{
    return IsJSRelativeTimeFormat(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSRelativeTimeFormat<JSRelativeTimeFormat, JSObject>::JSRelativeTimeFormatVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSRelativeTimeFormatVerify(Cast<JSRelativeTimeFormat>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
