// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
template<class D, class P>
Tagged<Union<String, Symbol>> TorqueGeneratedPropertyCell<D, P>::name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedPropertyCell::name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
template<class D, class P>
Tagged<Union<String, Symbol>> TorqueGeneratedPropertyCell<D, P>::name(PtrComprCageBase cage_base) const {
  Tagged<Union<String, Symbol>> value = TaggedField<Tagged<Union<String, Symbol>>>::load(cage_base, *this, kNameOffset);
  DCHECK(IsString(value) || IsPublicSymbol(value) || IsPrivateSymbol(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
template<class D, class P>
void TorqueGeneratedPropertyCell<D, P>::set_name(Tagged<Union<String, Symbol>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value) || IsPublicSymbol(value) || IsPrivateSymbol(value));
  WRITE_FIELD(*this, kNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=8&c=3
template<class D, class P>
int TorqueGeneratedPropertyCell<D, P>::property_details_raw() const {
  int value = TaggedField<Smi>::load(*this, kPropertyDetailsRawOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedPropertyCell<D, P>::set_property_details_raw(int value) {
  WRITE_FIELD(*this, kPropertyDetailsRawOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedPropertyCell<D, P>::value() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedPropertyCell::value(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedPropertyCell<D, P>::value(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kValueOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
template<class D, class P>
void TorqueGeneratedPropertyCell<D, P>::set_value(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kValueOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kValueOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
template<class D, class P>
Tagged<WeakArrayList> TorqueGeneratedPropertyCell<D, P>::dependent_code() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedPropertyCell::dependent_code(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
template<class D, class P>
Tagged<WeakArrayList> TorqueGeneratedPropertyCell<D, P>::dependent_code(PtrComprCageBase cage_base) const {
  Tagged<WeakArrayList> value = TaggedField<Tagged<WeakArrayList>>::load(cage_base, *this, kDependentCodeOffset);
  DCHECK(IsDependentCode(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedPropertyCell<D, P>::set_dependent_code(Tagged<WeakArrayList> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsDependentCode(value));
  WRITE_FIELD(*this, kDependentCodeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDependentCodeOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedPropertyCell<D, P>::TorqueGeneratedPropertyCell(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsPropertyCell_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=15&c=3
template<class D, class P>
int TorqueGeneratedContextSidePropertyCell<D, P>::property_details_raw() const {
  int value = TaggedField<Smi>::load(*this, kPropertyDetailsRawOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedContextSidePropertyCell<D, P>::set_property_details_raw(int value) {
  WRITE_FIELD(*this, kPropertyDetailsRawOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
template<class D, class P>
Tagged<WeakArrayList> TorqueGeneratedContextSidePropertyCell<D, P>::dependent_code() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedContextSidePropertyCell::dependent_code(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
template<class D, class P>
Tagged<WeakArrayList> TorqueGeneratedContextSidePropertyCell<D, P>::dependent_code(PtrComprCageBase cage_base) const {
  Tagged<WeakArrayList> value = TaggedField<Tagged<WeakArrayList>>::load(cage_base, *this, kDependentCodeOffset);
  DCHECK(IsDependentCode(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
template<class D, class P>
void TorqueGeneratedContextSidePropertyCell<D, P>::set_dependent_code(Tagged<WeakArrayList> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsDependentCode(value));
  WRITE_FIELD(*this, kDependentCodeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDependentCodeOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedContextSidePropertyCell<D, P>::TorqueGeneratedContextSidePropertyCell(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsContextSidePropertyCell_NonInline(*this));
}
