// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
template<class D, class P>
int TorqueGeneratedPropertyDescriptorObject<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
template<class D, class P>
void TorqueGeneratedPropertyDescriptorObject<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
template<class D, class P>
Tagged<Union<BigInt, Boolean, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> TorqueGeneratedPropertyDescriptorObject<D, P>::value() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedPropertyDescriptorObject::value(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
template<class D, class P>
Tagged<Union<BigInt, Boolean, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> TorqueGeneratedPropertyDescriptorObject<D, P>::value(PtrComprCageBase cage_base) const {
  Tagged<Union<BigInt, Boolean, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value = TaggedField<Tagged<Union<BigInt, Boolean, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>>>::load(cage_base, *this, kValueOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value) || IsTheHole(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
template<class D, class P>
void TorqueGeneratedPropertyDescriptorObject<D, P>::set_value(Tagged<Union<BigInt, Boolean, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value) || IsTheHole(value));
  WRITE_FIELD(*this, kValueOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kValueOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
template<class D, class P>
Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> TorqueGeneratedPropertyDescriptorObject<D, P>::get() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedPropertyDescriptorObject::get(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
template<class D, class P>
Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> TorqueGeneratedPropertyDescriptorObject<D, P>::get(PtrComprCageBase cage_base) const {
  Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value = TaggedField<Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>>>::load(cage_base, *this, kGetOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value) || IsTheHole(value) || IsFunctionTemplateInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
template<class D, class P>
void TorqueGeneratedPropertyDescriptorObject<D, P>::set_get(Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value) || IsTheHole(value) || IsFunctionTemplateInfo(value));
  WRITE_FIELD(*this, kGetOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kGetOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
template<class D, class P>
Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> TorqueGeneratedPropertyDescriptorObject<D, P>::set() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedPropertyDescriptorObject::set(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
template<class D, class P>
Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> TorqueGeneratedPropertyDescriptorObject<D, P>::set(PtrComprCageBase cage_base) const {
  Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value = TaggedField<Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>>>::load(cage_base, *this, kSetOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value) || IsTheHole(value) || IsFunctionTemplateInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
template<class D, class P>
void TorqueGeneratedPropertyDescriptorObject<D, P>::set_set(Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value) || IsTheHole(value) || IsFunctionTemplateInfo(value));
  WRITE_FIELD(*this, kSetOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSetOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedPropertyDescriptorObject<D, P>::TorqueGeneratedPropertyDescriptorObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsPropertyDescriptorObject_NonInline(*this));
}
