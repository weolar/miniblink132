#include "src/objects/js-iterator-helpers-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=5&c=1
bool IsJSIteratorHelper_NonInline(Tagged<HeapObject> o) {
  return IsJSIteratorHelper(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSIteratorHelper<JSIteratorHelper, JSObject>::JSIteratorHelperVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSIteratorHelperVerify(Cast<JSIteratorHelper>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=13&c=1
bool IsJSIteratorMapHelper_NonInline(Tagged<HeapObject> o) {
  return IsJSIteratorMapHelper(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSIteratorMapHelper<JSIteratorMapHelper, JSIteratorHelper>::JSIteratorMapHelperVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSIteratorMapHelperVerify(Cast<JSIteratorMapHelper>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=18&c=1
bool IsJSIteratorFilterHelper_NonInline(Tagged<HeapObject> o) {
  return IsJSIteratorFilterHelper(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSIteratorFilterHelper<JSIteratorFilterHelper, JSIteratorHelper>::JSIteratorFilterHelperVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSIteratorFilterHelperVerify(Cast<JSIteratorFilterHelper>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=23&c=1
bool IsJSIteratorTakeHelper_NonInline(Tagged<HeapObject> o) {
  return IsJSIteratorTakeHelper(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSIteratorTakeHelper<JSIteratorTakeHelper, JSIteratorHelper>::JSIteratorTakeHelperVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSIteratorTakeHelperVerify(Cast<JSIteratorTakeHelper>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=27&c=1
bool IsJSIteratorDropHelper_NonInline(Tagged<HeapObject> o) {
  return IsJSIteratorDropHelper(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSIteratorDropHelper<JSIteratorDropHelper, JSIteratorHelper>::JSIteratorDropHelperVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSIteratorDropHelperVerify(Cast<JSIteratorDropHelper>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=31&c=1
bool IsJSIteratorFlatMapHelper_NonInline(Tagged<HeapObject> o) {
  return IsJSIteratorFlatMapHelper(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSIteratorFlatMapHelper<JSIteratorFlatMapHelper, JSIteratorHelper>::JSIteratorFlatMapHelperVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSIteratorFlatMapHelperVerify(Cast<JSIteratorFlatMapHelper>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
