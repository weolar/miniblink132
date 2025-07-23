// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=13&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSPluralRules<D, P>::locale() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSPluralRules::locale(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=13&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSPluralRules<D, P>::locale(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kLocaleOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=13&c=3
template<class D, class P>
void TorqueGeneratedJSPluralRules<D, P>::set_locale(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kLocaleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLocaleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=14&c=3
template<class D, class P>
int TorqueGeneratedJSPluralRules<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedJSPluralRules<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=15&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSPluralRules<D, P>::icu_plural_rules() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSPluralRules::icu_plural_rules(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=15&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSPluralRules<D, P>::icu_plural_rules(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuPluralRulesOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedJSPluralRules<D, P>::set_icu_plural_rules(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuPluralRulesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuPluralRulesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=16&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSPluralRules<D, P>::icu_number_formatter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSPluralRules::icu_number_formatter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=16&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSPluralRules<D, P>::icu_number_formatter(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuNumberFormatterOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=16&c=3
template<class D, class P>
void TorqueGeneratedJSPluralRules<D, P>::set_icu_number_formatter(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuNumberFormatterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuNumberFormatterOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSPluralRules<D, P>::TorqueGeneratedJSPluralRules(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSPluralRules_NonInline(*this));
}
