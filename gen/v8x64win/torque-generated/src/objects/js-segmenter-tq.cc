#include "src/objects/js-segmenter-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segmenter.tq?l=13&c=1
bool IsJSSegmenter_NonInline(Tagged<HeapObject> o) {
  return IsJSSegmenter(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSSegmenter<JSSegmenter, JSObject>::JSSegmenterVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSSegmenterVerify(Cast<JSSegmenter>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
