// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/cell.tq?l=6&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedCell<D, P>::value() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCell::value(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/cell.tq?l=6&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedCell<D, P>::value(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kValueOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/cell.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedCell<D, P>::set_value(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kValueOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kValueOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedCell<D, P>::TorqueGeneratedCell(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsCell_NonInline(*this));
}
