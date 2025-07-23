// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceCoverageInfoSlots(Tagged<CoverageInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_int31_0(int31_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=204&c=1
inline intptr_t TqRuntimeConvert_intptr_int32_0(int32_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_CoverageInfoSlot_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_intptr_0(intptr_t p_i);

#ifndef V8_INTERNAL_DEFINED_TqRuntimeFieldSliceCoverageInfoSlots
#define V8_INTERNAL_DEFINED_TqRuntimeFieldSliceCoverageInfoSlots

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceCoverageInfoSlots(Tagged<CoverageInfo> p_o) {
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
  tmp3 = TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral(false, 0x8ull));
  std::tie(tmp4, tmp5, tmp6) = TqRuntimeNewMutableSlice_CoverageInfoSlot_0(p_o, tmp3, tmp2);
  goto block2;

  block2:
  return std::make_tuple(tmp4, tmp5, tmp6);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFieldSliceCoverageInfoSlots
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
#ifndef V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_CoverageInfoSlot_0
#define V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_CoverageInfoSlot_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_CoverageInfoSlot_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length) {
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

#endif // V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_CoverageInfoSlot_0
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
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=6&c=3
template<class D, class P>
int TorqueGeneratedBreakPoint<D, P>::id() const {
  int value = TaggedField<Smi>::load(*this, kIdOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedBreakPoint<D, P>::set_id(int value) {
  WRITE_FIELD(*this, kIdOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedBreakPoint<D, P>::condition() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedBreakPoint::condition(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedBreakPoint<D, P>::condition(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kConditionOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
template<class D, class P>
void TorqueGeneratedBreakPoint<D, P>::set_condition(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kConditionOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kConditionOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedBreakPoint<D, P>::TorqueGeneratedBreakPoint(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsBreakPoint_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=12&c=3
template<class D, class P>
int TorqueGeneratedBreakPointInfo<D, P>::source_position() const {
  int value = TaggedField<Smi>::load(*this, kSourcePositionOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=12&c=3
template<class D, class P>
void TorqueGeneratedBreakPointInfo<D, P>::set_source_position(int value) {
  WRITE_FIELD(*this, kSourcePositionOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
template<class D, class P>
Tagged<Union<BreakPoint, FixedArray, Undefined>> TorqueGeneratedBreakPointInfo<D, P>::break_points() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedBreakPointInfo::break_points(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
template<class D, class P>
Tagged<Union<BreakPoint, FixedArray, Undefined>> TorqueGeneratedBreakPointInfo<D, P>::break_points(PtrComprCageBase cage_base) const {
  Tagged<Union<BreakPoint, FixedArray, Undefined>> value = TaggedField<Tagged<Union<BreakPoint, FixedArray, Undefined>>>::load(cage_base, *this, kBreakPointsOffset);
  DCHECK(IsUndefined(value) || IsFixedArray(value) || IsBreakPoint(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedBreakPointInfo<D, P>::set_break_points(Tagged<Union<BreakPoint, FixedArray, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsFixedArray(value) || IsBreakPoint(value));
  WRITE_FIELD(*this, kBreakPointsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBreakPointsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedBreakPointInfo<D, P>::TorqueGeneratedBreakPointInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsBreakPointInfo_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
template<class D, class P>
Tagged<SharedFunctionInfo> TorqueGeneratedDebugInfo<D, P>::shared() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDebugInfo::shared(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
template<class D, class P>
Tagged<SharedFunctionInfo> TorqueGeneratedDebugInfo<D, P>::shared(PtrComprCageBase cage_base) const {
  Tagged<SharedFunctionInfo> value = TaggedField<Tagged<SharedFunctionInfo>>::load(cage_base, *this, kSharedOffset);
  DCHECK(IsSharedFunctionInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
template<class D, class P>
void TorqueGeneratedDebugInfo<D, P>::set_shared(Tagged<SharedFunctionInfo> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSharedFunctionInfo(value));
  WRITE_FIELD(*this, kSharedOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSharedOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=36&c=3
template<class D, class P>
int TorqueGeneratedDebugInfo<D, P>::debugger_hints() const {
  int value = TaggedField<Smi>::load(*this, kDebuggerHintsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=36&c=3
template<class D, class P>
void TorqueGeneratedDebugInfo<D, P>::set_debugger_hints(int value) {
  WRITE_FIELD(*this, kDebuggerHintsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedDebugInfo<D, P>::break_points() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDebugInfo::break_points(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedDebugInfo<D, P>::break_points(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kBreakPointsOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
template<class D, class P>
void TorqueGeneratedDebugInfo<D, P>::set_break_points(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kBreakPointsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBreakPointsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=40&c=36
template<class D, class P>
int TorqueGeneratedDebugInfo<D, P>::flags(RelaxedLoadTag) const {
  int value = TaggedField<Smi>::Relaxed_Load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=40&c=36
template<class D, class P>
void TorqueGeneratedDebugInfo<D, P>::set_flags(int value, RelaxedStoreTag) {
  RELAXED_WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
template<class D, class P>
Tagged<Union<CoverageInfo, Undefined>> TorqueGeneratedDebugInfo<D, P>::coverage_info() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDebugInfo::coverage_info(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
template<class D, class P>
Tagged<Union<CoverageInfo, Undefined>> TorqueGeneratedDebugInfo<D, P>::coverage_info(PtrComprCageBase cage_base) const {
  Tagged<Union<CoverageInfo, Undefined>> value = TaggedField<Tagged<Union<CoverageInfo, Undefined>>>::load(cage_base, *this, kCoverageInfoOffset);
  DCHECK(IsUndefined(value) || IsCoverageInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
template<class D, class P>
void TorqueGeneratedDebugInfo<D, P>::set_coverage_info(Tagged<Union<CoverageInfo, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsCoverageInfo(value));
  WRITE_FIELD(*this, kCoverageInfoOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCoverageInfoOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedDebugInfo<D, P>::TorqueGeneratedDebugInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsDebugInfo_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=63&c=9
template<class D, class P>
int32_t TorqueGeneratedCoverageInfo<D, P>::slot_count() const {
  int32_t value = this->template ReadField<int32_t>(kSlotCountOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=63&c=9
template<class D, class P>
void TorqueGeneratedCoverageInfo<D, P>::set_slot_count(int32_t value) {
  this->template WriteField<int32_t>(kSlotCountOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
template<class D, class P>
int32_t TorqueGeneratedCoverageInfo<D, P>::slots_start_source_position(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->slot_count());
  int offset = kSlotsOffset + 0 + i * 16;
  int32_t value = this->template ReadField<int32_t>(offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
template<class D, class P>
void TorqueGeneratedCoverageInfo<D, P>::set_slots_start_source_position(int i, int32_t value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->slot_count());
  int offset = kSlotsOffset + 0 + i * 16;
  this->template WriteField<int32_t>(offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
template<class D, class P>
int32_t TorqueGeneratedCoverageInfo<D, P>::slots_end_source_position(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->slot_count());
  int offset = kSlotsOffset + 4 + i * 16;
  int32_t value = this->template ReadField<int32_t>(offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
template<class D, class P>
void TorqueGeneratedCoverageInfo<D, P>::set_slots_end_source_position(int i, int32_t value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->slot_count());
  int offset = kSlotsOffset + 4 + i * 16;
  this->template WriteField<int32_t>(offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
template<class D, class P>
int32_t TorqueGeneratedCoverageInfo<D, P>::slots_block_count(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->slot_count());
  int offset = kSlotsOffset + 8 + i * 16;
  int32_t value = this->template ReadField<int32_t>(offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
template<class D, class P>
void TorqueGeneratedCoverageInfo<D, P>::set_slots_block_count(int i, int32_t value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->slot_count());
  int offset = kSlotsOffset + 8 + i * 16;
  this->template WriteField<int32_t>(offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
template<class D, class P>
int32_t TorqueGeneratedCoverageInfo<D, P>::slots_padding(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->slot_count());
  int offset = kSlotsOffset + 12 + i * 16;
  int32_t value = this->template ReadField<int32_t>(offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
template<class D, class P>
void TorqueGeneratedCoverageInfo<D, P>::set_slots_padding(int i, int32_t value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->slot_count());
  int offset = kSlotsOffset + 12 + i * 16;
  this->template WriteField<int32_t>(offset, value);
}

template<class D, class P>
inline TorqueGeneratedCoverageInfo<D, P>::TorqueGeneratedCoverageInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsCoverageInfo_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
template<class D, class P>
Tagged<Union<Script, SharedFunctionInfo>> TorqueGeneratedStackFrameInfo<D, P>::shared_or_script() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedStackFrameInfo::shared_or_script(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
template<class D, class P>
Tagged<Union<Script, SharedFunctionInfo>> TorqueGeneratedStackFrameInfo<D, P>::shared_or_script(PtrComprCageBase cage_base) const {
  Tagged<Union<Script, SharedFunctionInfo>> value = TaggedField<Tagged<Union<Script, SharedFunctionInfo>>>::load(cage_base, *this, kSharedOrScriptOffset);
  DCHECK(IsScript(value) || IsSharedFunctionInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
template<class D, class P>
void TorqueGeneratedStackFrameInfo<D, P>::set_shared_or_script(Tagged<Union<Script, SharedFunctionInfo>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsScript(value) || IsSharedFunctionInfo(value));
  WRITE_FIELD(*this, kSharedOrScriptOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSharedOrScriptOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedStackFrameInfo<D, P>::function_name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedStackFrameInfo::function_name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedStackFrameInfo<D, P>::function_name(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kFunctionNameOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
template<class D, class P>
void TorqueGeneratedStackFrameInfo<D, P>::set_function_name(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kFunctionNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kFunctionNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=81&c=3
template<class D, class P>
int TorqueGeneratedStackFrameInfo<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=81&c=3
template<class D, class P>
void TorqueGeneratedStackFrameInfo<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedStackFrameInfo<D, P>::TorqueGeneratedStackFrameInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsStackFrameInfo_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=86&c=3
template<class D, class P>
int TorqueGeneratedStackTraceInfo<D, P>::id() const {
  int value = TaggedField<Smi>::load(*this, kIdOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=86&c=3
template<class D, class P>
void TorqueGeneratedStackTraceInfo<D, P>::set_id(int value) {
  WRITE_FIELD(*this, kIdOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedStackTraceInfo<D, P>::frames() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedStackTraceInfo::frames(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedStackTraceInfo<D, P>::frames(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kFramesOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
template<class D, class P>
void TorqueGeneratedStackTraceInfo<D, P>::set_frames(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kFramesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kFramesOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedStackTraceInfo<D, P>::TorqueGeneratedStackTraceInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsStackTraceInfo_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
template<class D, class P>
Tagged<Union<BigInt, Boolean, FixedArray, HeapNumber, JSReceiver, Null, Smi, String, Symbol, Undefined>> TorqueGeneratedErrorStackData<D, P>::call_site_infos_or_formatted_stack() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedErrorStackData::call_site_infos_or_formatted_stack(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
template<class D, class P>
Tagged<Union<BigInt, Boolean, FixedArray, HeapNumber, JSReceiver, Null, Smi, String, Symbol, Undefined>> TorqueGeneratedErrorStackData<D, P>::call_site_infos_or_formatted_stack(PtrComprCageBase cage_base) const {
  Tagged<Union<BigInt, Boolean, FixedArray, HeapNumber, JSReceiver, Null, Smi, String, Symbol, Undefined>> value = TaggedField<Tagged<Union<BigInt, Boolean, FixedArray, HeapNumber, JSReceiver, Null, Smi, String, Symbol, Undefined>>>::load(cage_base, *this, kCallSiteInfosOrFormattedStackOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value) || IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
template<class D, class P>
void TorqueGeneratedErrorStackData<D, P>::set_call_site_infos_or_formatted_stack(Tagged<Union<BigInt, Boolean, FixedArray, HeapNumber, JSReceiver, Null, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value) || IsFixedArray(value));
  WRITE_FIELD(*this, kCallSiteInfosOrFormattedStackOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallSiteInfosOrFormattedStackOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
template<class D, class P>
Tagged<StackTraceInfo> TorqueGeneratedErrorStackData<D, P>::stack_trace() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedErrorStackData::stack_trace(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
template<class D, class P>
Tagged<StackTraceInfo> TorqueGeneratedErrorStackData<D, P>::stack_trace(PtrComprCageBase cage_base) const {
  Tagged<StackTraceInfo> value = TaggedField<Tagged<StackTraceInfo>>::load(cage_base, *this, kStackTraceOffset);
  DCHECK(IsStackTraceInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
template<class D, class P>
void TorqueGeneratedErrorStackData<D, P>::set_stack_trace(Tagged<StackTraceInfo> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsStackTraceInfo(value));
  WRITE_FIELD(*this, kStackTraceOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kStackTraceOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedErrorStackData<D, P>::TorqueGeneratedErrorStackData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsErrorStackData_NonInline(*this));
}
