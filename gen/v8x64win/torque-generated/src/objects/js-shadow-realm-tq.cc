#include "src/objects/js-shadow-realm-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-shadow-realm.tq?l=5&c=1
bool IsJSShadowRealm_NonInline(Tagged<HeapObject> o) {
  return IsJSShadowRealm(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSShadowRealm<JSShadowRealm, JSObject>::JSShadowRealmVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSShadowRealmVerify(Cast<JSShadowRealm>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
