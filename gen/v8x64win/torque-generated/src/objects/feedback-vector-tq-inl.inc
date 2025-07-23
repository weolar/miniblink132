// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceFeedbackVectorRawFeedbackSlots(Tagged<FeedbackVector> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_int31_0(int31_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=204&c=1
inline intptr_t TqRuntimeConvert_intptr_int32_0(int32_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_MaybeObject_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_intptr_0(intptr_t p_i);

#ifndef V8_INTERNAL_DEFINED_TqRuntimeFieldSliceFeedbackVectorRawFeedbackSlots
#define V8_INTERNAL_DEFINED_TqRuntimeFieldSliceFeedbackVectorRawFeedbackSlots

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceFeedbackVectorRawFeedbackSlots(Tagged<FeedbackVector> p_o) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  int32_t tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  intptr_t tmp3{}; USE(tmp3);
  Tagged<Union<HeapObject, TaggedIndex>> tmp4{}; USE(tmp4);
  intptr_t tmp5{}; USE(tmp5);
  intptr_t tmp6{}; USE(tmp6);
  goto block0;

  block0:
  tmp0 = TqRuntimeFromConstexpr_intptr_constexpr_int31_0(4);
  tmp1 = (p_o)->ReadField<int32_t>(tmp0);
  tmp2 = TqRuntimeConvert_intptr_int32_0(tmp1);
  tmp3 = TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral(false, 0x20ull));
  std::tie(tmp4, tmp5, tmp6) = TqRuntimeNewMutableSlice_MaybeObject_0(p_o, tmp3, tmp2);
  goto block2;

  block2:
  return std::make_tuple(tmp4, tmp5, tmp6);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFieldSliceFeedbackVectorRawFeedbackSlots
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
#ifndef V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_int32_0
#define V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_int32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=204&c=1
intptr_t TqRuntimeConvert_intptr_int32_0(int32_t p_i) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  goto block0;

  block0:
  tmp0 = TorqueRuntimeMacroShims::CodeStubAssembler::ChangeInt32ToIntPtr(p_i);
  goto block2;

  block2:
  return tmp0;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_int32_0
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
#ifndef V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_MaybeObject_0
#define V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_MaybeObject_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_MaybeObject_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length) {
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

#endif // V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_MaybeObject_0
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
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=46&c=9
template<class D, class P>
int32_t TorqueGeneratedFeedbackVector<D, P>::length() const {
  int32_t value = this->template ReadField<int32_t>(kLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=46&c=9
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_length(int32_t value) {
  this->template WriteField<int32_t>(kLengthOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=47&c=3
template<class D, class P>
int32_t TorqueGeneratedFeedbackVector<D, P>::invocation_count() const {
  int32_t value = this->template ReadField<int32_t>(kInvocationCountOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=47&c=3
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_invocation_count(int32_t value) {
  this->template WriteField<int32_t>(kInvocationCountOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=49&c=3
template<class D, class P>
uint8_t TorqueGeneratedFeedbackVector<D, P>::invocation_count_before_stable() const {
  uint8_t value = this->template ReadField<uint8_t>(kInvocationCountBeforeStableOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=49&c=3
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_invocation_count_before_stable(uint8_t value) {
  this->template WriteField<uint8_t>(kInvocationCountBeforeStableOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=50&c=3
template<class D, class P>
uint8_t TorqueGeneratedFeedbackVector<D, P>::osr_state() const {
  uint8_t value = this->template ReadField<uint8_t>(kOsrStateOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=50&c=3
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_osr_state(uint8_t value) {
  this->template WriteField<uint8_t>(kOsrStateOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=51&c=3
template<class D, class P>
uint16_t TorqueGeneratedFeedbackVector<D, P>::flags() const {
  uint16_t value = this->template ReadField<uint16_t>(kFlagsOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=51&c=3
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_flags(uint16_t value) {
  this->template WriteField<uint16_t>(kFlagsOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=52&c=3
template<class D, class P>
Tagged<SharedFunctionInfo> TorqueGeneratedFeedbackVector<D, P>::shared_function_info() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedFeedbackVector::shared_function_info(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=52&c=3
template<class D, class P>
Tagged<SharedFunctionInfo> TorqueGeneratedFeedbackVector<D, P>::shared_function_info(PtrComprCageBase cage_base) const {
  Tagged<SharedFunctionInfo> value = TaggedField<Tagged<SharedFunctionInfo>>::load(cage_base, *this, kSharedFunctionInfoOffset);
  DCHECK(IsSharedFunctionInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=52&c=3
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_shared_function_info(Tagged<SharedFunctionInfo> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSharedFunctionInfo(value));
  WRITE_FIELD(*this, kSharedFunctionInfoOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSharedFunctionInfoOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=53&c=3
template<class D, class P>
Tagged<ClosureFeedbackCellArray> TorqueGeneratedFeedbackVector<D, P>::closure_feedback_cell_array() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedFeedbackVector::closure_feedback_cell_array(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=53&c=3
template<class D, class P>
Tagged<ClosureFeedbackCellArray> TorqueGeneratedFeedbackVector<D, P>::closure_feedback_cell_array(PtrComprCageBase cage_base) const {
  Tagged<ClosureFeedbackCellArray> value = TaggedField<Tagged<ClosureFeedbackCellArray>>::load(cage_base, *this, kClosureFeedbackCellArrayOffset);
  DCHECK(IsClosureFeedbackCellArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=53&c=3
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_closure_feedback_cell_array(Tagged<ClosureFeedbackCellArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsClosureFeedbackCellArray(value));
  WRITE_FIELD(*this, kClosureFeedbackCellArrayOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kClosureFeedbackCellArrayOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=54&c=3
template<class D, class P>
Tagged<FeedbackCell> TorqueGeneratedFeedbackVector<D, P>::parent_feedback_cell() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedFeedbackVector::parent_feedback_cell(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=54&c=3
template<class D, class P>
Tagged<FeedbackCell> TorqueGeneratedFeedbackVector<D, P>::parent_feedback_cell(PtrComprCageBase cage_base) const {
  Tagged<FeedbackCell> value = TaggedField<Tagged<FeedbackCell>>::load(cage_base, *this, kParentFeedbackCellOffset);
  DCHECK(IsFeedbackCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=54&c=3
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_parent_feedback_cell(Tagged<FeedbackCell> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFeedbackCell(value));
  WRITE_FIELD(*this, kParentFeedbackCellOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kParentFeedbackCellOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=55&c=33
template<class D, class P>
Tagged<MaybeObject> TorqueGeneratedFeedbackVector<D, P>::maybe_optimized_code() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedFeedbackVector::maybe_optimized_code(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=55&c=33
template<class D, class P>
Tagged<MaybeObject> TorqueGeneratedFeedbackVector<D, P>::maybe_optimized_code(PtrComprCageBase cage_base) const {
  Tagged<MaybeObject> value = TaggedField<Tagged<MaybeObject>>::load(cage_base, *this, kMaybeOptimizedCodeOffset);
  DCHECK(value.IsCleared() || (value.IsWeak() && IsCodeWrapper(value.GetHeapObjectOrSmi())));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=55&c=33
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_maybe_optimized_code(Tagged<MaybeObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsCleared() || (value.IsWeak() && IsCodeWrapper(value.GetHeapObjectOrSmi())));
  RELAXED_WRITE_WEAK_FIELD(*this, kMaybeOptimizedCodeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMaybeOptimizedCodeOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedFeedbackVector<D, P>::raw_feedback_slots(int i, RelaxedLoadTag) const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedFeedbackVector::raw_feedback_slots(cage_base, i, kRelaxedLoad);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedFeedbackVector<D, P>::raw_feedback_slots(PtrComprCageBase cage_base, int i, RelaxedLoadTag) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->length());
  int offset = kRawFeedbackSlotsOffset + i * kTaggedSize;
  Tagged<Union<HeapObject, MaybeObject, Smi>> value = TaggedField<Tagged<Union<HeapObject, MaybeObject, Smi>>>::Relaxed_Load(cage_base, *this, offset);
  DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
template<class D, class P>
void TorqueGeneratedFeedbackVector<D, P>::set_raw_feedback_slots(int i, Tagged<Union<HeapObject, MaybeObject, Smi>> value, RelaxedStoreTag, WriteBarrierMode mode) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->length());
  int offset = kRawFeedbackSlotsOffset + i * kTaggedSize;
  SLOW_DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  RELAXED_WRITE_WEAK_FIELD(*this, offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, offset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedFeedbackVector<D, P>::TorqueGeneratedFeedbackVector(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsFeedbackVector_NonInline(*this));
}
