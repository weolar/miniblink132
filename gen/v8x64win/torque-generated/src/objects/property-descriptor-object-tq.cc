#include "src/objects/property-descriptor-object-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
bool IsPropertyDescriptorObject_NonInline(Tagged<HeapObject> o) {
  return IsPropertyDescriptorObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedPropertyDescriptorObject<PropertyDescriptorObject, Struct>::PropertyDescriptorObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::PropertyDescriptorObjectVerify(Cast<PropertyDescriptorObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
