#include "src/objects/scope-info-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=114&c=1
bool IsScopeInfo_NonInline(Tagged<HeapObject> o) {
  return IsScopeInfo(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedScopeInfo<ScopeInfo, HeapObject>::ScopeInfoVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::ScopeInfoVerify(Cast<ScopeInfo>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
