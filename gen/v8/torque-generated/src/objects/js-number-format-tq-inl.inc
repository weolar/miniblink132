// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=8&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSNumberFormat<D, P>::locale() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSNumberFormat::locale(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=8&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSNumberFormat<D, P>::locale(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kLocaleOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedJSNumberFormat<D, P>::set_locale(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kLocaleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLocaleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=9&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSNumberFormat<D, P>::icu_number_formatter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSNumberFormat::icu_number_formatter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=9&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSNumberFormat<D, P>::icu_number_formatter(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuNumberFormatterOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=9&c=3
template<class D, class P>
void TorqueGeneratedJSNumberFormat<D, P>::set_icu_number_formatter(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuNumberFormatterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuNumberFormatterOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=11&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSNumberFormat<D, P>::bound_format() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSNumberFormat::bound_format(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=11&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSNumberFormat<D, P>::bound_format(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Undefined>> value = TaggedField<Tagged<Union<JSFunction, Undefined>>>::load(cage_base, *this, kBoundFormatOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=11&c=3
template<class D, class P>
void TorqueGeneratedJSNumberFormat<D, P>::set_bound_format(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kBoundFormatOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBoundFormatOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSNumberFormat<D, P>::TorqueGeneratedJSNumberFormat(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSNumberFormat_NonInline(*this));
}
