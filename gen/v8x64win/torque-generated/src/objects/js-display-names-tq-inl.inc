// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-display-names.tq?l=19&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDisplayNames<D, P>::internal() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDisplayNames::internal(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-display-names.tq?l=19&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedJSDisplayNames<D, P>::internal(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kInternalOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-display-names.tq?l=19&c=3
template<class D, class P>
void TorqueGeneratedJSDisplayNames<D, P>::set_internal(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kInternalOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInternalOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-display-names.tq?l=20&c=3
template<class D, class P>
int TorqueGeneratedJSDisplayNames<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-display-names.tq?l=20&c=3
template<class D, class P>
void TorqueGeneratedJSDisplayNames<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSDisplayNames<D, P>::TorqueGeneratedJSDisplayNames(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSDisplayNames_NonInline(*this));
}
