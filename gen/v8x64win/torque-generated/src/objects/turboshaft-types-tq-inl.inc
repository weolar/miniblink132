// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceTurboshaftWord32SetTypeElements(Tagged<TurboshaftWord32SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsHigh(Tagged<TurboshaftWord64SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsLow(Tagged<TurboshaftWord64SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceTurboshaftFloat64SetTypeElements(Tagged<TurboshaftFloat64SetType> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_int31_0(int31_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=210&c=1
inline intptr_t TqRuntimeConvert_intptr_uint32_0(uint32_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_uint32_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_float64_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_intptr_0(intptr_t p_i);

#ifndef V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord32SetTypeElements
#define V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord32SetTypeElements

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceTurboshaftWord32SetTypeElements(Tagged<TurboshaftWord32SetType> p_o) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  uint32_t tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  intptr_t tmp3{}; USE(tmp3);
  Tagged<Union<HeapObject, TaggedIndex>> tmp4{}; USE(tmp4);
  intptr_t tmp5{}; USE(tmp5);
  intptr_t tmp6{}; USE(tmp6);
  goto block0;

  block0:
  tmp0 = TqRuntimeFromConstexpr_intptr_constexpr_int31_0(4);
  tmp1 = (p_o)->ReadField<uint32_t>(tmp0);
  tmp2 = TqRuntimeConvert_intptr_uint32_0(tmp1);
  tmp3 = TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral(false, 0x8ull));
  std::tie(tmp4, tmp5, tmp6) = TqRuntimeNewMutableSlice_uint32_0(p_o, tmp3, tmp2);
  goto block2;

  block2:
  return std::make_tuple(tmp4, tmp5, tmp6);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord32SetTypeElements
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsHigh
#define V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsHigh

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsHigh(Tagged<TurboshaftWord64SetType> p_o) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  uint32_t tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  intptr_t tmp3{}; USE(tmp3);
  Tagged<Union<HeapObject, TaggedIndex>> tmp4{}; USE(tmp4);
  intptr_t tmp5{}; USE(tmp5);
  intptr_t tmp6{}; USE(tmp6);
  goto block0;

  block0:
  tmp0 = TqRuntimeFromConstexpr_intptr_constexpr_int31_0(4);
  tmp1 = (p_o)->ReadField<uint32_t>(tmp0);
  tmp2 = TqRuntimeConvert_intptr_uint32_0(tmp1);
  tmp3 = TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral(false, 0x8ull));
  std::tie(tmp4, tmp5, tmp6) = TqRuntimeNewMutableSlice_uint32_0(p_o, tmp3, tmp2);
  goto block2;

  block2:
  return std::make_tuple(tmp4, tmp5, tmp6);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsHigh
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsLow
#define V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsLow

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsLow(Tagged<TurboshaftWord64SetType> p_o) {
  DisallowGarbageCollection no_gc;
  Tagged<Union<HeapObject, TaggedIndex>> tmp0{}; USE(tmp0);
  intptr_t tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  intptr_t tmp3{}; USE(tmp3);
  intptr_t tmp4{}; USE(tmp4);
  intptr_t tmp5{}; USE(tmp5);
  intptr_t tmp6{}; USE(tmp6);
  uint32_t tmp7{}; USE(tmp7);
  intptr_t tmp8{}; USE(tmp8);
  Tagged<Union<HeapObject, TaggedIndex>> tmp9{}; USE(tmp9);
  intptr_t tmp10{}; USE(tmp10);
  intptr_t tmp11{}; USE(tmp11);
  goto block0;

  block0:
  std::tie(tmp0, tmp1, tmp2) = TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsHigh(p_o);
  tmp3 = TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral(false, 0x4ull));
  tmp4 = TorqueRuntimeMacroShims::CodeStubAssembler::IntPtrMul(tmp3, tmp2);
  tmp5 = TorqueRuntimeMacroShims::CodeStubAssembler::IntPtrAdd(tmp1, tmp4);
  tmp6 = TqRuntimeFromConstexpr_intptr_constexpr_int31_0(4);
  tmp7 = (p_o)->ReadField<uint32_t>(tmp6);
  tmp8 = TqRuntimeConvert_intptr_uint32_0(tmp7);
  std::tie(tmp9, tmp10, tmp11) = TqRuntimeNewMutableSlice_uint32_0(p_o, tmp5, tmp8);
  goto block2;

  block2:
  return std::make_tuple(tmp9, tmp10, tmp11);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsLow
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftFloat64SetTypeElements
#define V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftFloat64SetTypeElements

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceTurboshaftFloat64SetTypeElements(Tagged<TurboshaftFloat64SetType> p_o) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  uint32_t tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  intptr_t tmp3{}; USE(tmp3);
  Tagged<Union<HeapObject, TaggedIndex>> tmp4{}; USE(tmp4);
  intptr_t tmp5{}; USE(tmp5);
  intptr_t tmp6{}; USE(tmp6);
  goto block0;

  block0:
  tmp0 = TqRuntimeFromConstexpr_intptr_constexpr_int31_0(8);
  tmp1 = (p_o)->ReadField<uint32_t>(tmp0);
  tmp2 = TqRuntimeConvert_intptr_uint32_0(tmp1);
  tmp3 = TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral(false, 0xcull));
  std::tie(tmp4, tmp5, tmp6) = TqRuntimeNewMutableSlice_float64_0(p_o, tmp3, tmp2);
  goto block2;

  block2:
  return std::make_tuple(tmp4, tmp5, tmp6);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFieldSliceTurboshaftFloat64SetTypeElements
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
#ifndef V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_uint32_0
#define V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_uint32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=210&c=1
intptr_t TqRuntimeConvert_intptr_uint32_0(uint32_t p_i) {
  DisallowGarbageCollection no_gc;
  uintptr_t tmp0{}; USE(tmp0);
  intptr_t tmp1{}; USE(tmp1);
  goto block0;

  block0:
  tmp0 = TorqueRuntimeMacroShims::CodeStubAssembler::ChangeUint32ToWord(p_i);
  tmp1 = TorqueRuntimeMacroShims::CodeStubAssembler::Signed(tmp0);
  goto block2;

  block2:
  return tmp1;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_uint32_0
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
#ifndef V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_uint32_0
#define V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_uint32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_uint32_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length) {
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

#endif // V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_uint32_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_float64_0
#define V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_float64_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_float64_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length) {
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

#endif // V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_float64_0
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
template<class D, class P>
inline TorqueGeneratedTurboshaftType<D, P>::TorqueGeneratedTurboshaftType(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftType_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedTurboshaftWord32Type<D, P>::TorqueGeneratedTurboshaftWord32Type(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftWord32Type_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=29&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord32RangeType<D, P>::from() const {
  uint32_t value = this->template ReadField<uint32_t>(kFromOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=29&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord32RangeType<D, P>::set_from(uint32_t value) {
  this->template WriteField<uint32_t>(kFromOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=30&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord32RangeType<D, P>::to() const {
  uint32_t value = this->template ReadField<uint32_t>(kToOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=30&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord32RangeType<D, P>::set_to(uint32_t value) {
  this->template WriteField<uint32_t>(kToOffset, value);
}

template<class D, class P>
inline TorqueGeneratedTurboshaftWord32RangeType<D, P>::TorqueGeneratedTurboshaftWord32RangeType(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftWord32RangeType_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=37&c=9
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord32SetType<D, P>::set_size() const {
  uint32_t value = this->template ReadField<uint32_t>(kSetSizeOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=37&c=9
template<class D, class P>
void TorqueGeneratedTurboshaftWord32SetType<D, P>::set_set_size(uint32_t value) {
  this->template WriteField<uint32_t>(kSetSizeOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord32SetType<D, P>::elements(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->set_size());
  int offset = kElementsOffset + i * kInt32Size;
  uint32_t value = this->template ReadField<uint32_t>(offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord32SetType<D, P>::set_elements(int i, uint32_t value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->set_size());
  int offset = kElementsOffset + i * kInt32Size;
  this->template WriteField<uint32_t>(offset, value);
}

template<class D, class P>
inline TorqueGeneratedTurboshaftWord32SetType<D, P>::TorqueGeneratedTurboshaftWord32SetType(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftWord32SetType_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedTurboshaftWord64Type<D, P>::TorqueGeneratedTurboshaftWord64Type(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftWord64Type_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=50&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord64RangeType<D, P>::from_high() const {
  uint32_t value = this->template ReadField<uint32_t>(kFromHighOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=50&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord64RangeType<D, P>::set_from_high(uint32_t value) {
  this->template WriteField<uint32_t>(kFromHighOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=51&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord64RangeType<D, P>::from_low() const {
  uint32_t value = this->template ReadField<uint32_t>(kFromLowOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=51&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord64RangeType<D, P>::set_from_low(uint32_t value) {
  this->template WriteField<uint32_t>(kFromLowOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=52&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord64RangeType<D, P>::to_high() const {
  uint32_t value = this->template ReadField<uint32_t>(kToHighOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=52&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord64RangeType<D, P>::set_to_high(uint32_t value) {
  this->template WriteField<uint32_t>(kToHighOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=53&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord64RangeType<D, P>::to_low() const {
  uint32_t value = this->template ReadField<uint32_t>(kToLowOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=53&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord64RangeType<D, P>::set_to_low(uint32_t value) {
  this->template WriteField<uint32_t>(kToLowOffset, value);
}

template<class D, class P>
inline TorqueGeneratedTurboshaftWord64RangeType<D, P>::TorqueGeneratedTurboshaftWord64RangeType(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftWord64RangeType_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=60&c=9
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord64SetType<D, P>::set_size() const {
  uint32_t value = this->template ReadField<uint32_t>(kSetSizeOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=60&c=9
template<class D, class P>
void TorqueGeneratedTurboshaftWord64SetType<D, P>::set_set_size(uint32_t value) {
  this->template WriteField<uint32_t>(kSetSizeOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord64SetType<D, P>::elements_high(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->set_size());
  int offset = kElementsHighOffset + i * kInt32Size;
  uint32_t value = this->template ReadField<uint32_t>(offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord64SetType<D, P>::set_elements_high(int i, uint32_t value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->set_size());
  int offset = kElementsHighOffset + i * kInt32Size;
  this->template WriteField<uint32_t>(offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftWord64SetType<D, P>::elements_low(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->set_size());
  int offset = ElementsLowOffset() + i * kInt32Size;
  uint32_t value = this->template ReadField<uint32_t>(offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftWord64SetType<D, P>::set_elements_low(int i, uint32_t value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->set_size());
  int offset = ElementsLowOffset() + i * kInt32Size;
  this->template WriteField<uint32_t>(offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
template<class D, class P>
int TorqueGeneratedTurboshaftWord64SetType<D, P>::ElementsLowOffset() const {
  return static_cast<int>(std::get<1>(TqRuntimeFieldSliceTurboshaftWord64SetTypeElementsLow(*static_cast<const D*>(this))));
}

template<class D, class P>
inline TorqueGeneratedTurboshaftWord64SetType<D, P>::TorqueGeneratedTurboshaftWord64SetType(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftWord64SetType_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=69&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftFloat64Type<D, P>::special_values() const {
  uint32_t value = this->template ReadField<uint32_t>(kSpecialValuesOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=69&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftFloat64Type<D, P>::set_special_values(uint32_t value) {
  this->template WriteField<uint32_t>(kSpecialValuesOffset, value);
}

template<class D, class P>
inline TorqueGeneratedTurboshaftFloat64Type<D, P>::TorqueGeneratedTurboshaftFloat64Type(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftFloat64Type_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=76&c=3
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftFloat64RangeType<D, P>::_padding() const {
  uint32_t value = this->template ReadField<uint32_t>(kPaddingOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=76&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftFloat64RangeType<D, P>::set__padding(uint32_t value) {
  this->template WriteField<uint32_t>(kPaddingOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=77&c=3
template<class D, class P>
double TorqueGeneratedTurboshaftFloat64RangeType<D, P>::min() const {
  double value = this->template ReadField<double>(kMinOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=77&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftFloat64RangeType<D, P>::set_min(double value) {
  this->template WriteField<double>(kMinOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=78&c=3
template<class D, class P>
double TorqueGeneratedTurboshaftFloat64RangeType<D, P>::max() const {
  double value = this->template ReadField<double>(kMaxOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=78&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftFloat64RangeType<D, P>::set_max(double value) {
  this->template WriteField<double>(kMaxOffset, value);
}

template<class D, class P>
inline TorqueGeneratedTurboshaftFloat64RangeType<D, P>::TorqueGeneratedTurboshaftFloat64RangeType(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftFloat64RangeType_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=85&c=9
template<class D, class P>
uint32_t TorqueGeneratedTurboshaftFloat64SetType<D, P>::set_size() const {
  uint32_t value = this->template ReadField<uint32_t>(kSetSizeOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=85&c=9
template<class D, class P>
void TorqueGeneratedTurboshaftFloat64SetType<D, P>::set_set_size(uint32_t value) {
  this->template WriteField<uint32_t>(kSetSizeOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
template<class D, class P>
double TorqueGeneratedTurboshaftFloat64SetType<D, P>::elements(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->set_size());
  int offset = kElementsOffset + i * kDoubleSize;
  double value = this->template ReadField<double>(offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
template<class D, class P>
void TorqueGeneratedTurboshaftFloat64SetType<D, P>::set_elements(int i, double value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->set_size());
  int offset = kElementsOffset + i * kDoubleSize;
  this->template WriteField<double>(offset, value);
}

template<class D, class P>
inline TorqueGeneratedTurboshaftFloat64SetType<D, P>::TorqueGeneratedTurboshaftFloat64SetType(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTurboshaftFloat64SetType_NonInline(*this));
}
