#include "src/objects/js-disposable-stack-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=23&c=1
bool IsJSDisposableStackBase_NonInline(Tagged<HeapObject> o) {
  return IsJSDisposableStackBase(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSDisposableStackBase<JSDisposableStackBase, JSObject>::JSDisposableStackBaseVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSDisposableStackBaseVerify(Cast<JSDisposableStackBase>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=34&c=1
bool IsJSSyncDisposableStack_NonInline(Tagged<HeapObject> o) {
  return IsJSSyncDisposableStack(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSSyncDisposableStack<JSSyncDisposableStack, JSDisposableStackBase>::JSSyncDisposableStackVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSSyncDisposableStackVerify(Cast<JSSyncDisposableStack>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=36&c=1
bool IsJSAsyncDisposableStack_NonInline(Tagged<HeapObject> o) {
  return IsJSAsyncDisposableStack(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSAsyncDisposableStack<JSAsyncDisposableStack, JSDisposableStackBase>::JSAsyncDisposableStackVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSAsyncDisposableStackVerify(Cast<JSAsyncDisposableStack>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
