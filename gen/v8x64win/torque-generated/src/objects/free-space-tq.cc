#include "src/objects/free-space-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=5&c=1
bool IsFreeSpace_NonInline(Tagged<HeapObject> o) {
  return IsFreeSpace(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedFreeSpace<FreeSpace, HeapObject>::FreeSpaceVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::FreeSpaceVerify(Cast<FreeSpace>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
