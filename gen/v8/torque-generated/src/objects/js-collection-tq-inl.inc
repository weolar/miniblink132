// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-collection.tq?l=10&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSCollection<D, P>::table() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSCollection::table(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-collection.tq?l=10&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSCollection<D, P>::table(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kTableOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-collection.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedJSCollection<D, P>::set_table(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kTableOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTableOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSCollection<D, P>::TorqueGeneratedJSCollection(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSCollection_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSSet<D, P>::TorqueGeneratedJSSet(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSSet_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSMap<D, P>::TorqueGeneratedJSMap(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSMap_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-collection.tq?l=18&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSWeakCollection<D, P>::table() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSWeakCollection::table(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-collection.tq?l=18&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSWeakCollection<D, P>::table(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kTableOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-collection.tq?l=18&c=3
template<class D, class P>
void TorqueGeneratedJSWeakCollection<D, P>::set_table(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kTableOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTableOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSWeakCollection<D, P>::TorqueGeneratedJSWeakCollection(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSWeakCollection_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSWeakSet<D, P>::TorqueGeneratedJSWeakSet(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSWeakSet_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSWeakMap<D, P>::TorqueGeneratedJSWeakMap(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSWeakMap_NonInline(*this));
}
