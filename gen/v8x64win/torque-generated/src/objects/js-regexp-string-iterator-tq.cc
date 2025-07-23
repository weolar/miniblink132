#include "src/objects/js-regexp-string-iterator-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=11&c=1
bool IsJSRegExpStringIterator_NonInline(Tagged<HeapObject> o) {
  return IsJSRegExpStringIterator(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSRegExpStringIterator<JSRegExpStringIterator, JSObject>::JSRegExpStringIteratorVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSRegExpStringIteratorVerify(Cast<JSRegExpStringIterator>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
