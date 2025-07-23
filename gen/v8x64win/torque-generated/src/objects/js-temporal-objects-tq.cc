#include "src/objects/js-temporal-objects-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=37&c=1
bool IsJSTemporalCalendar_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalCalendar(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalCalendar<JSTemporalCalendar, JSObject>::JSTemporalCalendarVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalCalendarVerify(Cast<JSTemporalCalendar>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=41&c=1
bool IsJSTemporalDuration_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalDuration(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalDuration<JSTemporalDuration, JSObject>::JSTemporalDurationVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalDurationVerify(Cast<JSTemporalDuration>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=54&c=1
bool IsJSTemporalInstant_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalInstant(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalInstant<JSTemporalInstant, JSObject>::JSTemporalInstantVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalInstantVerify(Cast<JSTemporalInstant>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=58&c=1
bool IsJSTemporalPlainDateTime_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalPlainDateTime(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalPlainDateTime<JSTemporalPlainDateTime, JSObject>::JSTemporalPlainDateTimeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalPlainDateTimeVerify(Cast<JSTemporalPlainDateTime>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=65&c=1
bool IsJSTemporalPlainDate_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalPlainDate(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalPlainDate<JSTemporalPlainDate, JSObject>::JSTemporalPlainDateVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalPlainDateVerify(Cast<JSTemporalPlainDate>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=70&c=1
bool IsJSTemporalPlainMonthDay_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalPlainMonthDay(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalPlainMonthDay<JSTemporalPlainMonthDay, JSObject>::JSTemporalPlainMonthDayVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalPlainMonthDayVerify(Cast<JSTemporalPlainMonthDay>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=75&c=1
bool IsJSTemporalPlainTime_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalPlainTime(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalPlainTime<JSTemporalPlainTime, JSObject>::JSTemporalPlainTimeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalPlainTimeVerify(Cast<JSTemporalPlainTime>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=81&c=1
bool IsJSTemporalPlainYearMonth_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalPlainYearMonth(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalPlainYearMonth<JSTemporalPlainYearMonth, JSObject>::JSTemporalPlainYearMonthVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalPlainYearMonthVerify(Cast<JSTemporalPlainYearMonth>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=86&c=1
bool IsJSTemporalTimeZone_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalTimeZone(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalTimeZone<JSTemporalTimeZone, JSObject>::JSTemporalTimeZoneVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalTimeZoneVerify(Cast<JSTemporalTimeZone>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=91&c=1
bool IsJSTemporalZonedDateTime_NonInline(Tagged<HeapObject> o) {
  return IsJSTemporalZonedDateTime(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedJSTemporalZonedDateTime<JSTemporalZonedDateTime, JSObject>::JSTemporalZonedDateTimeVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::JSTemporalZonedDateTimeVerify(Cast<JSTemporalZonedDateTime>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
