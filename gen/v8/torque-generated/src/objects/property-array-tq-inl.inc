// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-array.tq?l=6&c=3
template<class D, class P>
int TorqueGeneratedPropertyArray<D, P>::length_and_hash() const {
  int value = TaggedField<Smi>::load(*this, kLengthAndHashOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-array.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedPropertyArray<D, P>::set_length_and_hash(int value) {
  WRITE_FIELD(*this, kLengthAndHashOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedPropertyArray<D, P>::TorqueGeneratedPropertyArray(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsPropertyArray_NonInline(*this));
}
