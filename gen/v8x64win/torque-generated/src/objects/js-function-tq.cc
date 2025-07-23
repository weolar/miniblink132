#include "src/objects/js-function-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-function.tq?l=5&c=1
bool IsJSFunctionOrBoundFunctionOrWrappedFunction_NonInline(Tagged<HeapObject> o) {
  return IsJSFunctionOrBoundFunctionOrWrappedFunction(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSFunctionOrBoundFunctionOrWrappedFunction<JSFunctionOrBoundFunctionOrWrappedFunction, JSObject>::JSFunctionOrBoundFunctionOrWrappedFunctionVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSFunctionOrBoundFunctionOrWrappedFunctionVerify(Cast<JSFunctionOrBoundFunctionOrWrappedFunction>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-function.tq?l=30&c=1
bool IsJSFunction_NonInline(Tagged<HeapObject> o) {
  return IsJSFunction(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSFunction<JSFunction, JSFunctionOrBoundFunctionOrWrappedFunction>::JSFunctionVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSFunctionVerify(Cast<JSFunction>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-function.tq?l=20&c=1
bool IsJSWrappedFunction_NonInline(Tagged<HeapObject> o) {
  return IsJSWrappedFunction(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSWrappedFunction<JSWrappedFunction, JSFunctionOrBoundFunctionOrWrappedFunction>::JSWrappedFunctionVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSWrappedFunctionVerify(Cast<JSWrappedFunction>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-function.tq?l=8&c=1
bool IsJSBoundFunction_NonInline(Tagged<HeapObject> o) {
  return IsJSBoundFunction(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSBoundFunction<JSBoundFunction, JSFunctionOrBoundFunctionOrWrappedFunction>::JSBoundFunctionVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSBoundFunctionVerify(Cast<JSBoundFunction>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
