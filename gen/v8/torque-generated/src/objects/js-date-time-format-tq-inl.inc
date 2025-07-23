// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=17&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSDateTimeFormat<D, P>::locale() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDateTimeFormat::locale(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=17&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSDateTimeFormat<D, P>::locale(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kLocaleOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=17&c=3
template<class D, class P>
void TorqueGeneratedJSDateTimeFormat<D, P>::set_locale(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kLocaleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLocaleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=18&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDateTimeFormat<D, P>::icu_locale() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDateTimeFormat::icu_locale(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=18&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDateTimeFormat<D, P>::icu_locale(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuLocaleOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=18&c=3
template<class D, class P>
void TorqueGeneratedJSDateTimeFormat<D, P>::set_icu_locale(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuLocaleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuLocaleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=19&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDateTimeFormat<D, P>::icu_simple_date_format() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDateTimeFormat::icu_simple_date_format(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=19&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDateTimeFormat<D, P>::icu_simple_date_format(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuSimpleDateFormatOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=19&c=3
template<class D, class P>
void TorqueGeneratedJSDateTimeFormat<D, P>::set_icu_simple_date_format(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuSimpleDateFormatOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuSimpleDateFormatOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=20&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDateTimeFormat<D, P>::icu_date_interval_format() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDateTimeFormat::icu_date_interval_format(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=20&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDateTimeFormat<D, P>::icu_date_interval_format(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuDateIntervalFormatOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=20&c=3
template<class D, class P>
void TorqueGeneratedJSDateTimeFormat<D, P>::set_icu_date_interval_format(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuDateIntervalFormatOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuDateIntervalFormatOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=21&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSDateTimeFormat<D, P>::bound_format() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDateTimeFormat::bound_format(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=21&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSDateTimeFormat<D, P>::bound_format(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Undefined>> value = TaggedField<Tagged<Union<JSFunction, Undefined>>>::load(cage_base, *this, kBoundFormatOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=21&c=3
template<class D, class P>
void TorqueGeneratedJSDateTimeFormat<D, P>::set_bound_format(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kBoundFormatOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBoundFormatOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=22&c=3
template<class D, class P>
int TorqueGeneratedJSDateTimeFormat<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=22&c=3
template<class D, class P>
void TorqueGeneratedJSDateTimeFormat<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSDateTimeFormat<D, P>::TorqueGeneratedJSDateTimeFormat(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSDateTimeFormat_NonInline(*this));
}
