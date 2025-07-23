// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceDescriptorArrayDescriptors(Tagged<DescriptorArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_int31_0(int31_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=231&c=1
inline intptr_t TqRuntimeConvert_intptr_uint16_0(uint16_t p_ui);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_DescriptorEntry_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_intptr_0(intptr_t p_i);

#ifndef V8_INTERNAL_DEFINED_TqRuntimeFieldSliceDescriptorArrayDescriptors
#define V8_INTERNAL_DEFINED_TqRuntimeFieldSliceDescriptorArrayDescriptors

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceDescriptorArrayDescriptors(Tagged<DescriptorArray> p_o) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  uint16_t tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  intptr_t tmp3{}; USE(tmp3);
  Tagged<Union<HeapObject, TaggedIndex>> tmp4{}; USE(tmp4);
  intptr_t tmp5{}; USE(tmp5);
  intptr_t tmp6{}; USE(tmp6);
  goto block0;

  block0:
  tmp0 = TqRuntimeFromConstexpr_intptr_constexpr_int31_0(4);
  tmp1 = (p_o)->ReadField<uint16_t>(tmp0);
  tmp2 = TqRuntimeConvert_intptr_uint16_0(tmp1);
  tmp3 = TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral(false, 0x10ull));
  std::tie(tmp4, tmp5, tmp6) = TqRuntimeNewMutableSlice_DescriptorEntry_0(p_o, tmp3, tmp2);
  goto block2;

  block2:
  return std::make_tuple(tmp4, tmp5, tmp6);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFieldSliceDescriptorArrayDescriptors
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
intptr_t TqRuntimeFromConstexpr_intptr_constexpr_int31_0(int31_t p_i) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  goto block0;

  block0:
  tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
  goto block2;

  block2:
  return tmp0;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_uint16_0
#define V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_uint16_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=231&c=1
intptr_t TqRuntimeConvert_intptr_uint16_0(uint16_t p_ui) {
  DisallowGarbageCollection no_gc;
  uintptr_t tmp0{}; USE(tmp0);
  intptr_t tmp1{}; USE(tmp1);
  goto block0;

  block0:
  tmp0 = TorqueRuntimeMacroShims::CodeStubAssembler::ChangeUint32ToWord(p_ui);
  tmp1 = TorqueRuntimeMacroShims::CodeStubAssembler::Signed(tmp0);
  goto block2;

  block2:
  return tmp1;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_uint16_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
intptr_t TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral p_i) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  goto block0;

  block0:
  tmp0 = TqRuntimeFromConstexpr_intptr_constexpr_intptr_0((TorqueRuntimeMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(p_i)));
  goto block2;

  block2:
  return tmp0;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_DescriptorEntry_0
#define V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_DescriptorEntry_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_DescriptorEntry_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length) {
  DisallowGarbageCollection no_gc;
  Tagged<Union<HeapObject, TaggedIndex>> tmp0{}; USE(tmp0);
  intptr_t tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  goto block0;

  block0:
  std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
  goto block2;

  block2:
  return std::make_tuple(tmp0, tmp1, tmp2);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_DescriptorEntry_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
intptr_t TqRuntimeFromConstexpr_intptr_constexpr_intptr_0(intptr_t p_i) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  goto block0;

  block0:
  tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
  goto block2;

  block2:
  return tmp0;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_intptr_0
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedEnumCache<D, P>::keys() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedEnumCache::keys(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedEnumCache<D, P>::keys(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kKeysOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedEnumCache<D, P>::set_keys(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kKeysOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kKeysOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedEnumCache<D, P>::indices() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedEnumCache::indices(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedEnumCache<D, P>::indices(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kIndicesOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
template<class D, class P>
void TorqueGeneratedEnumCache<D, P>::set_indices(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kIndicesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIndicesOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedEnumCache<D, P>::TorqueGeneratedEnumCache(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsEnumCache_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=21&c=9
template<class D, class P>
uint16_t TorqueGeneratedDescriptorArray<D, P>::number_of_all_descriptors() const {
  uint16_t value = this->template ReadField<uint16_t>(kNumberOfAllDescriptorsOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=21&c=9
template<class D, class P>
void TorqueGeneratedDescriptorArray<D, P>::set_number_of_all_descriptors(uint16_t value) {
  this->template WriteField<uint16_t>(kNumberOfAllDescriptorsOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=22&c=3
template<class D, class P>
uint16_t TorqueGeneratedDescriptorArray<D, P>::number_of_descriptors() const {
  uint16_t value = this->template ReadField<uint16_t>(kNumberOfDescriptorsOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=22&c=3
template<class D, class P>
void TorqueGeneratedDescriptorArray<D, P>::set_number_of_descriptors(uint16_t value) {
  this->template WriteField<uint16_t>(kNumberOfDescriptorsOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=25&c=3
template<class D, class P>
uint32_t TorqueGeneratedDescriptorArray<D, P>::raw_gc_state() const {
  uint32_t value = this->template ReadField<uint32_t>(kRawGcStateOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=25&c=3
template<class D, class P>
void TorqueGeneratedDescriptorArray<D, P>::set_raw_gc_state(uint32_t value) {
  this->template WriteField<uint32_t>(kRawGcStateOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
template<class D, class P>
Tagged<EnumCache> TorqueGeneratedDescriptorArray<D, P>::enum_cache() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDescriptorArray::enum_cache(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
template<class D, class P>
Tagged<EnumCache> TorqueGeneratedDescriptorArray<D, P>::enum_cache(PtrComprCageBase cage_base) const {
  Tagged<EnumCache> value = TaggedField<Tagged<EnumCache>>::load(cage_base, *this, kEnumCacheOffset);
  DCHECK(IsEnumCache(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
template<class D, class P>
void TorqueGeneratedDescriptorArray<D, P>::set_enum_cache(Tagged<EnumCache> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsEnumCache(value));
  WRITE_FIELD(*this, kEnumCacheOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEnumCacheOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
Tagged<Union<Name, Undefined>> TorqueGeneratedDescriptorArray<D, P>::descriptors_key(int i) const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDescriptorArray::descriptors_key(cage_base, i);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
Tagged<Union<Name, Undefined>> TorqueGeneratedDescriptorArray<D, P>::descriptors_key(PtrComprCageBase cage_base, int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->number_of_all_descriptors());
  int offset = kDescriptorsOffset + 0 + i * 12;
  Tagged<Union<Name, Undefined>> value = TaggedField<Tagged<Union<Name, Undefined>>>::load(cage_base, *this, offset);
  DCHECK(IsUndefined(value) || IsName(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
void TorqueGeneratedDescriptorArray<D, P>::set_descriptors_key(int i, Tagged<Union<Name, Undefined>> value, WriteBarrierMode mode) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->number_of_all_descriptors());
  int offset = kDescriptorsOffset + 0 + i * 12;
  SLOW_DCHECK(IsUndefined(value) || IsName(value));
  WRITE_FIELD(*this, offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, offset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
Tagged<Union<Smi, Undefined>> TorqueGeneratedDescriptorArray<D, P>::descriptors_details(int i) const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDescriptorArray::descriptors_details(cage_base, i);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
Tagged<Union<Smi, Undefined>> TorqueGeneratedDescriptorArray<D, P>::descriptors_details(PtrComprCageBase cage_base, int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->number_of_all_descriptors());
  int offset = kDescriptorsOffset + 4 + i * 12;
  Tagged<Union<Smi, Undefined>> value = TaggedField<Tagged<Union<Smi, Undefined>>>::load(cage_base, *this, offset);
  DCHECK(IsUndefined(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
void TorqueGeneratedDescriptorArray<D, P>::set_descriptors_details(int i, Tagged<Union<Smi, Undefined>> value, WriteBarrierMode mode) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->number_of_all_descriptors());
  int offset = kDescriptorsOffset + 4 + i * 12;
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value));
  WRITE_FIELD(*this, offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, offset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
Tagged<Union<AccessorInfo, AccessorPair, BigInt, Boolean, ClassPositions, HeapNumber, JSReceiver, MaybeObject, Null, NumberDictionary, Smi, String, Symbol, Undefined>> TorqueGeneratedDescriptorArray<D, P>::descriptors_value(int i) const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDescriptorArray::descriptors_value(cage_base, i);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
Tagged<Union<AccessorInfo, AccessorPair, BigInt, Boolean, ClassPositions, HeapNumber, JSReceiver, MaybeObject, Null, NumberDictionary, Smi, String, Symbol, Undefined>> TorqueGeneratedDescriptorArray<D, P>::descriptors_value(PtrComprCageBase cage_base, int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->number_of_all_descriptors());
  int offset = kDescriptorsOffset + 8 + i * 12;
  Tagged<Union<AccessorInfo, AccessorPair, BigInt, Boolean, ClassPositions, HeapNumber, JSReceiver, MaybeObject, Null, NumberDictionary, Smi, String, Symbol, Undefined>> value = TaggedField<Tagged<Union<AccessorInfo, AccessorPair, BigInt, Boolean, ClassPositions, HeapNumber, JSReceiver, MaybeObject, Null, NumberDictionary, Smi, String, Symbol, Undefined>>>::load(cage_base, *this, offset);
  DCHECK(value.IsCleared() || (!value.IsWeak() && IsJSReceiver(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsUndefined(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsNull(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsBoolean(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSymbol(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsString(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsBigInt(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsHeapNumber(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsNumberDictionary(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsAccessorInfo(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsClassPositions(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsAccessorPair(value.GetHeapObjectOrSmi())) || (value.IsWeak() && IsMap(value.GetHeapObjectOrSmi())));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
template<class D, class P>
void TorqueGeneratedDescriptorArray<D, P>::set_descriptors_value(int i, Tagged<Union<AccessorInfo, AccessorPair, BigInt, Boolean, ClassPositions, HeapNumber, JSReceiver, MaybeObject, Null, NumberDictionary, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->number_of_all_descriptors());
  int offset = kDescriptorsOffset + 8 + i * 12;
  SLOW_DCHECK(value.IsCleared() || (!value.IsWeak() && IsJSReceiver(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsUndefined(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsNull(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsBoolean(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSymbol(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsString(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsBigInt(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsHeapNumber(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsNumberDictionary(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsAccessorInfo(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsClassPositions(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsAccessorPair(value.GetHeapObjectOrSmi())) || (value.IsWeak() && IsMap(value.GetHeapObjectOrSmi())));
  RELAXED_WRITE_WEAK_FIELD(*this, offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, offset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedDescriptorArray<D, P>::TorqueGeneratedDescriptorArray(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsDescriptorArray_NonInline(*this));
}
