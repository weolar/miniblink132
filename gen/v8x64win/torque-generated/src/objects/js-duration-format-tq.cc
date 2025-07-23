#include "src/objects/js-duration-format-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=43&c=1
bool IsJSDurationFormat_NonInline(Tagged<HeapObject> o) {
  return IsJSDurationFormat(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSDurationFormat<JSDurationFormat, JSObject>::JSDurationFormatVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSDurationFormatVerify(Cast<JSDurationFormat>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
