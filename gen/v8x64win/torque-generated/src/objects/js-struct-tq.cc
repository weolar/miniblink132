#include "src/objects/js-struct-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-struct.tq?l=8&c=1
bool IsAlwaysSharedSpaceJSObject_NonInline(Tagged<HeapObject> o) {
  return IsAlwaysSharedSpaceJSObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedAlwaysSharedSpaceJSObject<AlwaysSharedSpaceJSObject, JSObject>::AlwaysSharedSpaceJSObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::AlwaysSharedSpaceJSObjectVerify(Cast<AlwaysSharedSpaceJSObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-struct.tq?l=11&c=1
bool IsJSSharedStruct_NonInline(Tagged<HeapObject> o) {
  return IsJSSharedStruct(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSSharedStruct<JSSharedStruct, AlwaysSharedSpaceJSObject>::JSSharedStructVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSSharedStructVerify(Cast<JSSharedStruct>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
