// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-locale.tq?l=8&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSLocale<D, P>::icu_locale() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSLocale::icu_locale(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-locale.tq?l=8&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSLocale<D, P>::icu_locale(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuLocaleOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-locale.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedJSLocale<D, P>::set_icu_locale(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuLocaleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuLocaleOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSLocale<D, P>::TorqueGeneratedJSLocale(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSLocale_NonInline(*this));
}
