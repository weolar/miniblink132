// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=12&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSSegments<D, P>::icu_break_iterator() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegments::icu_break_iterator(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=12&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSSegments<D, P>::icu_break_iterator(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuBreakIteratorOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=12&c=3
template<class D, class P>
void TorqueGeneratedJSSegments<D, P>::set_icu_break_iterator(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuBreakIteratorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuBreakIteratorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=13&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSSegments<D, P>::raw_string() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegments::raw_string(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=13&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSSegments<D, P>::raw_string(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kRawStringOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=13&c=3
template<class D, class P>
void TorqueGeneratedJSSegments<D, P>::set_raw_string(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kRawStringOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRawStringOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=14&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSSegments<D, P>::unicode_string() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegments::unicode_string(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=14&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSSegments<D, P>::unicode_string(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kUnicodeStringOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedJSSegments<D, P>::set_unicode_string(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kUnicodeStringOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUnicodeStringOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=15&c=3
template<class D, class P>
int TorqueGeneratedJSSegments<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedJSSegments<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSSegments<D, P>::TorqueGeneratedJSSegments(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSSegments_NonInline(*this));
}
