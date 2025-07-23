// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=8&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSV8BreakIterator<D, P>::locale() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSV8BreakIterator::locale(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=8&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSV8BreakIterator<D, P>::locale(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kLocaleOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedJSV8BreakIterator<D, P>::set_locale(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kLocaleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLocaleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=9&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSV8BreakIterator<D, P>::break_iterator() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSV8BreakIterator::break_iterator(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=9&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSV8BreakIterator<D, P>::break_iterator(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kBreakIteratorOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=9&c=3
template<class D, class P>
void TorqueGeneratedJSV8BreakIterator<D, P>::set_break_iterator(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kBreakIteratorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBreakIteratorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=10&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSV8BreakIterator<D, P>::unicode_string() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSV8BreakIterator::unicode_string(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=10&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSV8BreakIterator<D, P>::unicode_string(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kUnicodeStringOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedJSV8BreakIterator<D, P>::set_unicode_string(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kUnicodeStringOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUnicodeStringOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=11&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_adopt_text() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSV8BreakIterator::bound_adopt_text(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=11&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_adopt_text(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Undefined>> value = TaggedField<Tagged<Union<JSFunction, Undefined>>>::load(cage_base, *this, kBoundAdoptTextOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=11&c=3
template<class D, class P>
void TorqueGeneratedJSV8BreakIterator<D, P>::set_bound_adopt_text(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kBoundAdoptTextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBoundAdoptTextOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=12&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_first() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSV8BreakIterator::bound_first(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=12&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_first(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Undefined>> value = TaggedField<Tagged<Union<JSFunction, Undefined>>>::load(cage_base, *this, kBoundFirstOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=12&c=3
template<class D, class P>
void TorqueGeneratedJSV8BreakIterator<D, P>::set_bound_first(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kBoundFirstOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBoundFirstOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=13&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_next() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSV8BreakIterator::bound_next(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=13&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_next(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Undefined>> value = TaggedField<Tagged<Union<JSFunction, Undefined>>>::load(cage_base, *this, kBoundNextOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=13&c=3
template<class D, class P>
void TorqueGeneratedJSV8BreakIterator<D, P>::set_bound_next(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kBoundNextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBoundNextOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=14&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_current() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSV8BreakIterator::bound_current(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=14&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_current(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Undefined>> value = TaggedField<Tagged<Union<JSFunction, Undefined>>>::load(cage_base, *this, kBoundCurrentOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedJSV8BreakIterator<D, P>::set_bound_current(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kBoundCurrentOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBoundCurrentOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=15&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_break_type() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSV8BreakIterator::bound_break_type(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=15&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedJSV8BreakIterator<D, P>::bound_break_type(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Undefined>> value = TaggedField<Tagged<Union<JSFunction, Undefined>>>::load(cage_base, *this, kBoundBreakTypeOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedJSV8BreakIterator<D, P>::set_bound_break_type(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kBoundBreakTypeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBoundBreakTypeOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSV8BreakIterator<D, P>::TorqueGeneratedJSV8BreakIterator(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSV8BreakIterator_NonInline(*this));
}
