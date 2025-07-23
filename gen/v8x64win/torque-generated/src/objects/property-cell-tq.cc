#include "src/objects/property-cell-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=6&c=1
bool IsPropertyCell_NonInline(Tagged<HeapObject> o) {
  return IsPropertyCell(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedPropertyCell<PropertyCell, HeapObject>::PropertyCellVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::PropertyCellVerify(Cast<PropertyCell>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=14&c=1
bool IsContextSidePropertyCell_NonInline(Tagged<HeapObject> o) {
  return IsContextSidePropertyCell(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedContextSidePropertyCell<ContextSidePropertyCell, HeapObject>::ContextSidePropertyCellVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::ContextSidePropertyCellVerify(Cast<ContextSidePropertyCell>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
