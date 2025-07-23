// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=44&c=3
template<class D, class P>
int TorqueGeneratedJSDurationFormat<D, P>::style_flags() const {
  int value = TaggedField<Smi>::load(*this, kStyleFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=44&c=3
template<class D, class P>
void TorqueGeneratedJSDurationFormat<D, P>::set_style_flags(int value) {
  WRITE_FIELD(*this, kStyleFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=45&c=3
template<class D, class P>
int TorqueGeneratedJSDurationFormat<D, P>::display_flags() const {
  int value = TaggedField<Smi>::load(*this, kDisplayFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=45&c=3
template<class D, class P>
void TorqueGeneratedJSDurationFormat<D, P>::set_display_flags(int value) {
  WRITE_FIELD(*this, kDisplayFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=46&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDurationFormat<D, P>::icu_locale() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDurationFormat::icu_locale(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=46&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDurationFormat<D, P>::icu_locale(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuLocaleOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=46&c=3
template<class D, class P>
void TorqueGeneratedJSDurationFormat<D, P>::set_icu_locale(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuLocaleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuLocaleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=47&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDurationFormat<D, P>::icu_number_formatter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDurationFormat::icu_number_formatter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=47&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDurationFormat<D, P>::icu_number_formatter(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuNumberFormatterOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=47&c=3
template<class D, class P>
void TorqueGeneratedJSDurationFormat<D, P>::set_icu_number_formatter(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuNumberFormatterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuNumberFormatterOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSDurationFormat<D, P>::TorqueGeneratedJSDurationFormat(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSDurationFormat_NonInline(*this));
}
