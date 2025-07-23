// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=14&c=3
template<class D, class P>
int TorqueGeneratedArrayBoilerplateDescription<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedArrayBoilerplateDescription<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
template<class D, class P>
Tagged<FixedArrayBase> TorqueGeneratedArrayBoilerplateDescription<D, P>::constant_elements() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedArrayBoilerplateDescription::constant_elements(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
template<class D, class P>
Tagged<FixedArrayBase> TorqueGeneratedArrayBoilerplateDescription<D, P>::constant_elements(PtrComprCageBase cage_base) const {
  Tagged<FixedArrayBase> value = TaggedField<Tagged<FixedArrayBase>>::load(cage_base, *this, kConstantElementsOffset);
  DCHECK(IsFixedArrayBase(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedArrayBoilerplateDescription<D, P>::set_constant_elements(Tagged<FixedArrayBase> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArrayBase(value));
  WRITE_FIELD(*this, kConstantElementsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kConstantElementsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedArrayBoilerplateDescription<D, P>::TorqueGeneratedArrayBoilerplateDescription(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsArrayBoilerplateDescription_NonInline(*this));
}
