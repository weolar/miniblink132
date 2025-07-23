#include "src/objects/js-date-time-format-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=16&c=1
bool IsJSDateTimeFormat_NonInline(Tagged<HeapObject> o) {
  return IsJSDateTimeFormat(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSDateTimeFormat<JSDateTimeFormat, JSObject>::JSDateTimeFormatVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSDateTimeFormatVerify(Cast<JSDateTimeFormat>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
