// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=12&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSSegmentIterator<D, P>::icu_break_iterator() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegmentIterator::icu_break_iterator(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=12&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSSegmentIterator<D, P>::icu_break_iterator(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kIcuBreakIteratorOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=12&c=3
template<class D, class P>
void TorqueGeneratedJSSegmentIterator<D, P>::set_icu_break_iterator(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kIcuBreakIteratorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIcuBreakIteratorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=13&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSSegmentIterator<D, P>::raw_string() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegmentIterator::raw_string(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=13&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSSegmentIterator<D, P>::raw_string(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kRawStringOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=13&c=3
template<class D, class P>
void TorqueGeneratedJSSegmentIterator<D, P>::set_raw_string(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kRawStringOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRawStringOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=14&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSSegmentIterator<D, P>::unicode_string() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegmentIterator::unicode_string(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=14&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSSegmentIterator<D, P>::unicode_string(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kUnicodeStringOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedJSSegmentIterator<D, P>::set_unicode_string(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kUnicodeStringOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUnicodeStringOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=15&c=3
template<class D, class P>
int TorqueGeneratedJSSegmentIterator<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedJSSegmentIterator<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSSegmentIterator<D, P>::TorqueGeneratedJSSegmentIterator(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSSegmentIterator_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=21&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSSegmentDataObject<D, P>::segment() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegmentDataObject::segment(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=21&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSSegmentDataObject<D, P>::segment(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kSegmentOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=21&c=3
template<class D, class P>
void TorqueGeneratedJSSegmentDataObject<D, P>::set_segment(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kSegmentOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSegmentOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=22&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSSegmentDataObject<D, P>::index() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegmentDataObject::index(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=22&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSSegmentDataObject<D, P>::index(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kIndexOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=22&c=3
template<class D, class P>
void TorqueGeneratedJSSegmentDataObject<D, P>::set_index(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kIndexOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIndexOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=23&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSSegmentDataObject<D, P>::input() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegmentDataObject::input(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=23&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSSegmentDataObject<D, P>::input(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kInputOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=23&c=3
template<class D, class P>
void TorqueGeneratedJSSegmentDataObject<D, P>::set_input(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kInputOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInputOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSSegmentDataObject<D, P>::TorqueGeneratedJSSegmentDataObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSSegmentDataObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=29&c=3
template<class D, class P>
Tagged<Boolean> TorqueGeneratedJSSegmentDataObjectWithIsWordLike<D, P>::is_word_like() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSSegmentDataObjectWithIsWordLike::is_word_like(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=29&c=3
template<class D, class P>
Tagged<Boolean> TorqueGeneratedJSSegmentDataObjectWithIsWordLike<D, P>::is_word_like(PtrComprCageBase cage_base) const {
  Tagged<Boolean> value = TaggedField<Tagged<Boolean>>::load(cage_base, *this, kIsWordLikeOffset);
  DCHECK(IsBoolean(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=29&c=3
template<class D, class P>
void TorqueGeneratedJSSegmentDataObjectWithIsWordLike<D, P>::set_is_word_like(Tagged<Boolean> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsBoolean(value));
  WRITE_FIELD(*this, kIsWordLikeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIsWordLikeOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSSegmentDataObjectWithIsWordLike<D, P>::TorqueGeneratedJSSegmentDataObjectWithIsWordLike(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSSegmentDataObjectWithIsWordLike_NonInline(*this));
}
