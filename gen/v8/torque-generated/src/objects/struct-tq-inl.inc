template<class D, class P>
inline TorqueGeneratedStruct<D, P>::TorqueGeneratedStruct(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsStruct_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=14&c=3
template<class D, class P>
int TorqueGeneratedClassPositions<D, P>::start() const {
  int value = TaggedField<Smi>::load(*this, kStartOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedClassPositions<D, P>::set_start(int value) {
  WRITE_FIELD(*this, kStartOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=15&c=3
template<class D, class P>
int TorqueGeneratedClassPositions<D, P>::end() const {
  int value = TaggedField<Smi>::load(*this, kEndOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedClassPositions<D, P>::set_end(int value) {
  WRITE_FIELD(*this, kEndOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedClassPositions<D, P>::TorqueGeneratedClassPositions(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsClassPositions_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=19&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedAccessorPair<D, P>::getter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAccessorPair::getter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=19&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedAccessorPair<D, P>::getter(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kGetterOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=19&c=3
template<class D, class P>
void TorqueGeneratedAccessorPair<D, P>::set_getter(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kGetterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kGetterOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=20&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedAccessorPair<D, P>::setter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAccessorPair::setter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=20&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedAccessorPair<D, P>::setter(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kSetterOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=20&c=3
template<class D, class P>
void TorqueGeneratedAccessorPair<D, P>::set_setter(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kSetterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSetterOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedAccessorPair<D, P>::TorqueGeneratedAccessorPair(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAccessorPair_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=9&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedTuple2<D, P>::value1() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedTuple2::value1(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=9&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedTuple2<D, P>::value1(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kValue1Offset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=9&c=3
template<class D, class P>
void TorqueGeneratedTuple2<D, P>::set_value1(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kValue1Offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kValue1Offset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=10&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedTuple2<D, P>::value2() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedTuple2::value2(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=10&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedTuple2<D, P>::value2(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kValue2Offset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedTuple2<D, P>::set_value2(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kValue2Offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kValue2Offset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedTuple2<D, P>::TorqueGeneratedTuple2(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTuple2_NonInline(*this));
}
