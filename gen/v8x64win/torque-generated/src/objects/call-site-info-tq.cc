#include "src/objects/call-site-info-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=19&c=1
bool IsCallSiteInfo_NonInline(Tagged<HeapObject> o) {
  return IsCallSiteInfo(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedCallSiteInfo<CallSiteInfo, Struct>::CallSiteInfoVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::CallSiteInfoVerify(Cast<CallSiteInfo>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
