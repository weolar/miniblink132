#include "src/objects/descriptor-array-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=5&c=1
bool IsEnumCache_NonInline(Tagged<HeapObject> o) {
  return IsEnumCache(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedEnumCache<EnumCache, Struct>::EnumCacheVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::EnumCacheVerify(Cast<EnumCache>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=18&c=1
bool IsDescriptorArray_NonInline(Tagged<HeapObject> o) {
  return IsDescriptorArray(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedDescriptorArray<DescriptorArray, HeapObject>::DescriptorArrayVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::DescriptorArrayVerify(Cast<DescriptorArray>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
