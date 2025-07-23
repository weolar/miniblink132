#include "src/objects/promise-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=5&c=1
bool IsPromiseCapability_NonInline(Tagged<HeapObject> o) {
  return IsPromiseCapability(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedPromiseCapability<PromiseCapability, Struct>::PromiseCapabilityVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::PromiseCapabilityVerify(Cast<PromiseCapability>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=32&c=1
bool IsPromiseReaction_NonInline(Tagged<HeapObject> o) {
  return IsPromiseReaction(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedPromiseReaction<PromiseReaction, Struct>::PromiseReactionVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::PromiseReactionVerify(Cast<PromiseReaction>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=56&c=1
bool IsPromiseReactionJobTask_NonInline(Tagged<HeapObject> o) {
  return IsPromiseReactionJobTask(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedPromiseReactionJobTask<PromiseReactionJobTask, Microtask>::PromiseReactionJobTaskVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::PromiseReactionJobTaskVerify(Cast<PromiseReactionJobTask>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=66&c=1
bool IsPromiseFulfillReactionJobTask_NonInline(Tagged<HeapObject> o) {
  return IsPromiseFulfillReactionJobTask(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedPromiseFulfillReactionJobTask<PromiseFulfillReactionJobTask, PromiseReactionJobTask>::PromiseFulfillReactionJobTaskVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::PromiseFulfillReactionJobTaskVerify(Cast<PromiseFulfillReactionJobTask>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=68&c=1
bool IsPromiseRejectReactionJobTask_NonInline(Tagged<HeapObject> o) {
  return IsPromiseRejectReactionJobTask(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedPromiseRejectReactionJobTask<PromiseRejectReactionJobTask, PromiseReactionJobTask>::PromiseRejectReactionJobTaskVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::PromiseRejectReactionJobTaskVerify(Cast<PromiseRejectReactionJobTask>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=70&c=1
bool IsPromiseResolveThenableJobTask_NonInline(Tagged<HeapObject> o) {
  return IsPromiseResolveThenableJobTask(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedPromiseResolveThenableJobTask<PromiseResolveThenableJobTask, Microtask>::PromiseResolveThenableJobTaskVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::PromiseResolveThenableJobTaskVerify(Cast<PromiseResolveThenableJobTask>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
