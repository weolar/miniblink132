#include "src/objects/js-array-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=7&c=1
bool IsJSArrayIterator_NonInline(Tagged<HeapObject> o) {
  return IsJSArrayIterator(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSArrayIterator<JSArrayIterator, JSObject>::JSArrayIteratorVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSArrayIteratorVerify(Cast<JSArrayIterator>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=61&c=1
bool IsJSArray_NonInline(Tagged<HeapObject> o) {
  return IsJSArray(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSArray<JSArray, JSObject>::JSArrayVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSArrayVerify(Cast<JSArray>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=68&c=1
bool IsTemplateLiteralObject_NonInline(Tagged<HeapObject> o) {
  return IsTemplateLiteralObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTemplateLiteralObject<TemplateLiteralObject, JSArray>::TemplateLiteralObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TemplateLiteralObjectVerify(Cast<TemplateLiteralObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
