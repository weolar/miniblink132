// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=14&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSRelativeTimeFormat<D, P>::locale() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRelativeTimeFormat::locale(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=14&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSRelativeTimeFormat<D, P>::locale(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kLocaleOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedJSRelativeTimeFormat<D, P>::set_locale(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kLocaleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLocaleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=15&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSRelativeTimeFormat<D, P>::numberingSystem() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRelativeTimeFormat::numberingSystem(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=15&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSRelativeTimeFormat<D, P>::numberingSystem(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kNumberingSystemOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedJSRelativeTimeFormat<D, P>::set_numberingSystem(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kNumberingSystemOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNumberingSystemOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=16&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSRelativeTimeFormat<D, P>::icu_formatter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRelativeTimeFormat::icu_formatter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=16&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSRelativeTimeFormat<D, P>::icu_formatter(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuFormatterOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=16&c=3
template<class D, class P>
void TorqueGeneratedJSRelativeTimeFormat<D, P>::set_icu_formatter(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuFormatterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuFormatterOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=17&c=3
template<class D, class P>
int TorqueGeneratedJSRelativeTimeFormat<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-relative-time-format.tq?l=17&c=3
template<class D, class P>
void TorqueGeneratedJSRelativeTimeFormat<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSRelativeTimeFormat<D, P>::TorqueGeneratedJSRelativeTimeFormat(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSRelativeTimeFormat_NonInline(*this));
}
