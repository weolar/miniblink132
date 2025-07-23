// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=38&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalCalendar<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=38&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalCalendar<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSTemporalCalendar<D, P>::TorqueGeneratedJSTemporalCalendar(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalCalendar_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=42&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::years() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::years(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=42&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::years(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kYearsOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=42&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_years(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kYearsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kYearsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=43&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::months() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::months(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=43&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::months(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kMonthsOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=43&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_months(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kMonthsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMonthsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=44&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::weeks() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::weeks(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=44&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::weeks(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kWeeksOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=44&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_weeks(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kWeeksOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kWeeksOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=45&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::days() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::days(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=45&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::days(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kDaysOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=45&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_days(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kDaysOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDaysOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=46&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::hours() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::hours(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=46&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::hours(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kHoursOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=46&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_hours(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kHoursOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kHoursOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=47&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::minutes() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::minutes(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=47&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::minutes(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kMinutesOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=47&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_minutes(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kMinutesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMinutesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=48&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::seconds() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::seconds(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=48&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::seconds(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kSecondsOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=48&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_seconds(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kSecondsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSecondsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=49&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::milliseconds() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::milliseconds(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=49&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::milliseconds(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kMillisecondsOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=49&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_milliseconds(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kMillisecondsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMillisecondsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=50&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::microseconds() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::microseconds(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=50&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::microseconds(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kMicrosecondsOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=50&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_microseconds(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kMicrosecondsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMicrosecondsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=51&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::nanoseconds() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalDuration::nanoseconds(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=51&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSTemporalDuration<D, P>::nanoseconds(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kNanosecondsOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=51&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalDuration<D, P>::set_nanoseconds(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kNanosecondsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNanosecondsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTemporalDuration<D, P>::TorqueGeneratedJSTemporalDuration(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalDuration_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=55&c=3
template<class D, class P>
Tagged<BigInt> TorqueGeneratedJSTemporalInstant<D, P>::nanoseconds() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalInstant::nanoseconds(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=55&c=3
template<class D, class P>
Tagged<BigInt> TorqueGeneratedJSTemporalInstant<D, P>::nanoseconds(PtrComprCageBase cage_base) const {
  Tagged<BigInt> value = TaggedField<Tagged<BigInt>>::load(cage_base, *this, kNanosecondsOffset);
  DCHECK(IsBigInt(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=55&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalInstant<D, P>::set_nanoseconds(Tagged<BigInt> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsBigInt(value));
  WRITE_FIELD(*this, kNanosecondsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNanosecondsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTemporalInstant<D, P>::TorqueGeneratedJSTemporalInstant(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalInstant_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=59&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalPlainDateTime<D, P>::year_month_day() const {
  int value = TaggedField<Smi>::load(*this, kYearMonthDayOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=59&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainDateTime<D, P>::set_year_month_day(int value) {
  WRITE_FIELD(*this, kYearMonthDayOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=60&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalPlainDateTime<D, P>::hour_minute_second() const {
  int value = TaggedField<Smi>::load(*this, kHourMinuteSecondOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=60&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainDateTime<D, P>::set_hour_minute_second(int value) {
  WRITE_FIELD(*this, kHourMinuteSecondOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=61&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalPlainDateTime<D, P>::second_parts() const {
  int value = TaggedField<Smi>::load(*this, kSecondPartsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=61&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainDateTime<D, P>::set_second_parts(int value) {
  WRITE_FIELD(*this, kSecondPartsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=62&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainDateTime<D, P>::calendar() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalPlainDateTime::calendar(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=62&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainDateTime<D, P>::calendar(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kCalendarOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=62&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainDateTime<D, P>::set_calendar(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kCalendarOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCalendarOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTemporalPlainDateTime<D, P>::TorqueGeneratedJSTemporalPlainDateTime(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalPlainDateTime_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=66&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalPlainDate<D, P>::year_month_day() const {
  int value = TaggedField<Smi>::load(*this, kYearMonthDayOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=66&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainDate<D, P>::set_year_month_day(int value) {
  WRITE_FIELD(*this, kYearMonthDayOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=67&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainDate<D, P>::calendar() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalPlainDate::calendar(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=67&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainDate<D, P>::calendar(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kCalendarOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=67&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainDate<D, P>::set_calendar(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kCalendarOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCalendarOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTemporalPlainDate<D, P>::TorqueGeneratedJSTemporalPlainDate(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalPlainDate_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=71&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalPlainMonthDay<D, P>::year_month_day() const {
  int value = TaggedField<Smi>::load(*this, kYearMonthDayOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=71&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainMonthDay<D, P>::set_year_month_day(int value) {
  WRITE_FIELD(*this, kYearMonthDayOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=72&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainMonthDay<D, P>::calendar() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalPlainMonthDay::calendar(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=72&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainMonthDay<D, P>::calendar(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kCalendarOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=72&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainMonthDay<D, P>::set_calendar(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kCalendarOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCalendarOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTemporalPlainMonthDay<D, P>::TorqueGeneratedJSTemporalPlainMonthDay(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalPlainMonthDay_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=76&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalPlainTime<D, P>::hour_minute_second() const {
  int value = TaggedField<Smi>::load(*this, kHourMinuteSecondOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=76&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainTime<D, P>::set_hour_minute_second(int value) {
  WRITE_FIELD(*this, kHourMinuteSecondOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=77&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalPlainTime<D, P>::second_parts() const {
  int value = TaggedField<Smi>::load(*this, kSecondPartsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=77&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainTime<D, P>::set_second_parts(int value) {
  WRITE_FIELD(*this, kSecondPartsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=78&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainTime<D, P>::calendar() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalPlainTime::calendar(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=78&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainTime<D, P>::calendar(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kCalendarOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=78&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainTime<D, P>::set_calendar(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kCalendarOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCalendarOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTemporalPlainTime<D, P>::TorqueGeneratedJSTemporalPlainTime(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalPlainTime_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=82&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalPlainYearMonth<D, P>::year_month_day() const {
  int value = TaggedField<Smi>::load(*this, kYearMonthDayOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=82&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainYearMonth<D, P>::set_year_month_day(int value) {
  WRITE_FIELD(*this, kYearMonthDayOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=83&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainYearMonth<D, P>::calendar() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalPlainYearMonth::calendar(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=83&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalPlainYearMonth<D, P>::calendar(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kCalendarOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=83&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalPlainYearMonth<D, P>::set_calendar(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kCalendarOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCalendarOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTemporalPlainYearMonth<D, P>::TorqueGeneratedJSTemporalPlainYearMonth(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalPlainYearMonth_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=87&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalTimeZone<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=87&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalTimeZone<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=88&c=3
template<class D, class P>
int TorqueGeneratedJSTemporalTimeZone<D, P>::details() const {
  int value = TaggedField<Smi>::load(*this, kDetailsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=88&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalTimeZone<D, P>::set_details(int value) {
  WRITE_FIELD(*this, kDetailsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSTemporalTimeZone<D, P>::TorqueGeneratedJSTemporalTimeZone(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalTimeZone_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=92&c=3
template<class D, class P>
Tagged<BigInt> TorqueGeneratedJSTemporalZonedDateTime<D, P>::nanoseconds() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalZonedDateTime::nanoseconds(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=92&c=3
template<class D, class P>
Tagged<BigInt> TorqueGeneratedJSTemporalZonedDateTime<D, P>::nanoseconds(PtrComprCageBase cage_base) const {
  Tagged<BigInt> value = TaggedField<Tagged<BigInt>>::load(cage_base, *this, kNanosecondsOffset);
  DCHECK(IsBigInt(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=92&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalZonedDateTime<D, P>::set_nanoseconds(Tagged<BigInt> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsBigInt(value));
  WRITE_FIELD(*this, kNanosecondsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNanosecondsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=93&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalZonedDateTime<D, P>::time_zone() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalZonedDateTime::time_zone(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=93&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalZonedDateTime<D, P>::time_zone(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kTimeZoneOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=93&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalZonedDateTime<D, P>::set_time_zone(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kTimeZoneOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTimeZoneOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=94&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalZonedDateTime<D, P>::calendar() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTemporalZonedDateTime::calendar(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=94&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSTemporalZonedDateTime<D, P>::calendar(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kCalendarOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-temporal-objects.tq?l=94&c=3
template<class D, class P>
void TorqueGeneratedJSTemporalZonedDateTime<D, P>::set_calendar(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kCalendarOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCalendarOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTemporalZonedDateTime<D, P>::TorqueGeneratedJSTemporalZonedDateTime(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTemporalZonedDateTime_NonInline(*this));
}
