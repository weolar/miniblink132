#include "src/objects/turboshaft-types-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=17&c=1
bool IsTurboshaftType_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftType(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftType<TurboshaftType, HeapObject>::TurboshaftTypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftTypeVerify(Cast<TurboshaftType>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=20&c=1
bool IsTurboshaftWord32Type_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftWord32Type(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftWord32Type<TurboshaftWord32Type, TurboshaftType>::TurboshaftWord32TypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftWord32TypeVerify(Cast<TurboshaftWord32Type>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=25&c=1
bool IsTurboshaftWord32RangeType_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftWord32RangeType(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftWord32RangeType<TurboshaftWord32RangeType, TurboshaftWord32Type>::TurboshaftWord32RangeTypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftWord32RangeTypeVerify(Cast<TurboshaftWord32RangeType>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=33&c=1
bool IsTurboshaftWord32SetType_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftWord32SetType(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftWord32SetType<TurboshaftWord32SetType, TurboshaftWord32Type>::TurboshaftWord32SetTypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftWord32SetTypeVerify(Cast<TurboshaftWord32SetType>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=41&c=1
bool IsTurboshaftWord64Type_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftWord64Type(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftWord64Type<TurboshaftWord64Type, TurboshaftType>::TurboshaftWord64TypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftWord64TypeVerify(Cast<TurboshaftWord64Type>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=46&c=1
bool IsTurboshaftWord64RangeType_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftWord64RangeType(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftWord64RangeType<TurboshaftWord64RangeType, TurboshaftWord64Type>::TurboshaftWord64RangeTypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftWord64RangeTypeVerify(Cast<TurboshaftWord64RangeType>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=56&c=1
bool IsTurboshaftWord64SetType_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftWord64SetType(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftWord64SetType<TurboshaftWord64SetType, TurboshaftWord64Type>::TurboshaftWord64SetTypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftWord64SetTypeVerify(Cast<TurboshaftWord64SetType>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=65&c=1
bool IsTurboshaftFloat64Type_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftFloat64Type(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftFloat64Type<TurboshaftFloat64Type, TurboshaftType>::TurboshaftFloat64TypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftFloat64TypeVerify(Cast<TurboshaftFloat64Type>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=72&c=1
bool IsTurboshaftFloat64RangeType_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftFloat64RangeType(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftFloat64RangeType<TurboshaftFloat64RangeType, TurboshaftFloat64Type>::TurboshaftFloat64RangeTypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftFloat64RangeTypeVerify(Cast<TurboshaftFloat64RangeType>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=81&c=1
bool IsTurboshaftFloat64SetType_NonInline(Tagged<HeapObject> o) {
  return IsTurboshaftFloat64SetType(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTurboshaftFloat64SetType<TurboshaftFloat64SetType, TurboshaftFloat64Type>::TurboshaftFloat64SetTypeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::TurboshaftFloat64SetTypeVerify(Cast<TurboshaftFloat64SetType>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
