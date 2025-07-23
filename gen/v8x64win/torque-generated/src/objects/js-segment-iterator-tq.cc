#include "src/objects/js-segment-iterator-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=11&c=1
bool IsJSSegmentIterator_NonInline(Tagged<HeapObject> o) {
  return IsJSSegmentIterator(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSSegmentIterator<JSSegmentIterator, JSObject>::JSSegmentIteratorVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSSegmentIteratorVerify(Cast<JSSegmentIterator>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=18&c=1
bool IsJSSegmentDataObject_NonInline(Tagged<HeapObject> o) {
  return IsJSSegmentDataObject(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSSegmentDataObject<JSSegmentDataObject, JSObject>::JSSegmentDataObjectVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSSegmentDataObjectVerify(Cast<JSSegmentDataObject>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=26&c=1
bool IsJSSegmentDataObjectWithIsWordLike_NonInline(Tagged<HeapObject> o) {
  return IsJSSegmentDataObjectWithIsWordLike(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSSegmentDataObjectWithIsWordLike<JSSegmentDataObjectWithIsWordLike, JSSegmentDataObject>::JSSegmentDataObjectWithIsWordLikeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSSegmentDataObjectWithIsWordLikeVerify(Cast<JSSegmentDataObjectWithIsWordLike>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
