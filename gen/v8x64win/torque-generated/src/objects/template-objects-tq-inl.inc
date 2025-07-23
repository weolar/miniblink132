// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=6&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedTemplateObjectDescription<D, P>::raw_strings() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedTemplateObjectDescription::raw_strings(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=6&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedTemplateObjectDescription<D, P>::raw_strings(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kRawStringsOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedTemplateObjectDescription<D, P>::set_raw_strings(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kRawStringsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRawStringsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=7&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedTemplateObjectDescription<D, P>::cooked_strings() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedTemplateObjectDescription::cooked_strings(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=7&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedTemplateObjectDescription<D, P>::cooked_strings(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kCookedStringsOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=7&c=3
template<class D, class P>
void TorqueGeneratedTemplateObjectDescription<D, P>::set_cooked_strings(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kCookedStringsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCookedStringsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedTemplateObjectDescription<D, P>::TorqueGeneratedTemplateObjectDescription(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTemplateObjectDescription_NonInline(*this));
}
