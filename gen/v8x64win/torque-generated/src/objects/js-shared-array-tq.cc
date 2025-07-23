#include "src/objects/js-shared-array-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-shared-array.tq?l=5&c=1
bool IsJSSharedArray_NonInline(Tagged<HeapObject> o) {
  return IsJSSharedArray(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSSharedArray<JSSharedArray, AlwaysSharedSpaceJSObject>::JSSharedArrayVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSSharedArrayVerify(Cast<JSSharedArray>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
