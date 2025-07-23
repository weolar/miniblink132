// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=9&c=3
template<class D, class P>
int32_t TorqueGeneratedPreparseData<D, P>::data_length() const {
  int32_t value = this->template ReadField<int32_t>(kDataLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=9&c=3
template<class D, class P>
void TorqueGeneratedPreparseData<D, P>::set_data_length(int32_t value) {
  this->template WriteField<int32_t>(kDataLengthOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=10&c=3
template<class D, class P>
int32_t TorqueGeneratedPreparseData<D, P>::children_length() const {
  int32_t value = this->template ReadField<int32_t>(kChildrenLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedPreparseData<D, P>::set_children_length(int32_t value) {
  this->template WriteField<int32_t>(kChildrenLengthOffset, value);
}

template<class D, class P>
inline TorqueGeneratedPreparseData<D, P>::TorqueGeneratedPreparseData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsPreparseData_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedInterpreterData<D, P>::TorqueGeneratedInterpreterData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsInterpreterData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=73&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedSharedFunctionInfo<D, P>::untrusted_function_data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSharedFunctionInfo::untrusted_function_data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=73&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedSharedFunctionInfo<D, P>::untrusted_function_data(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kUntrustedFunctionDataOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=73&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_untrusted_function_data(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kUntrustedFunctionDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUntrustedFunctionDataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=74&c=3
template<class D, class P>
Tagged<Union<ScopeInfo, Smi, String>> TorqueGeneratedSharedFunctionInfo<D, P>::name_or_scope_info() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSharedFunctionInfo::name_or_scope_info(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=74&c=3
template<class D, class P>
Tagged<Union<ScopeInfo, Smi, String>> TorqueGeneratedSharedFunctionInfo<D, P>::name_or_scope_info(PtrComprCageBase cage_base) const {
  Tagged<Union<ScopeInfo, Smi, String>> value = TaggedField<Tagged<Union<ScopeInfo, Smi, String>>>::load(cage_base, *this, kNameOrScopeInfoOffset);
  DCHECK(IsString(value) || IsNoSharedNameSentinel(value) || IsScopeInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=74&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_name_or_scope_info(Tagged<Union<ScopeInfo, Smi, String>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value) || IsNoSharedNameSentinel(value) || IsScopeInfo(value));
  WRITE_FIELD(*this, kNameOrScopeInfoOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNameOrScopeInfoOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=75&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedSharedFunctionInfo<D, P>::outer_scope_info_or_feedback_metadata() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSharedFunctionInfo::outer_scope_info_or_feedback_metadata(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=75&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedSharedFunctionInfo<D, P>::outer_scope_info_or_feedback_metadata(PtrComprCageBase cage_base) const {
  Tagged<HeapObject> value = TaggedField<Tagged<HeapObject>>::load(cage_base, *this, kOuterScopeInfoOrFeedbackMetadataOffset);
  DCHECK(IsHeapObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=75&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_outer_scope_info_or_feedback_metadata(Tagged<HeapObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value));
  WRITE_FIELD(*this, kOuterScopeInfoOrFeedbackMetadataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kOuterScopeInfoOrFeedbackMetadataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=76&c=3
template<class D, class P>
Tagged<Union<Script, Undefined>> TorqueGeneratedSharedFunctionInfo<D, P>::script() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSharedFunctionInfo::script(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=76&c=3
template<class D, class P>
Tagged<Union<Script, Undefined>> TorqueGeneratedSharedFunctionInfo<D, P>::script(PtrComprCageBase cage_base) const {
  Tagged<Union<Script, Undefined>> value = TaggedField<Tagged<Union<Script, Undefined>>>::load(cage_base, *this, kScriptOffset);
  DCHECK(IsUndefined(value) || IsScript(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=76&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_script(Tagged<Union<Script, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsScript(value));
  WRITE_FIELD(*this, kScriptOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kScriptOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=80&c=3
template<class D, class P>
uint16_t TorqueGeneratedSharedFunctionInfo<D, P>::length() const {
  uint16_t value = this->template ReadField<uint16_t>(kLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=80&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_length(uint16_t value) {
  this->template WriteField<uint16_t>(kLengthOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=85&c=3
template<class D, class P>
uint16_t TorqueGeneratedSharedFunctionInfo<D, P>::formal_parameter_count() const {
  uint16_t value = this->template ReadField<uint16_t>(kFormalParameterCountOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=85&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_formal_parameter_count(uint16_t value) {
  this->template WriteField<uint16_t>(kFormalParameterCountOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=86&c=3
template<class D, class P>
uint16_t TorqueGeneratedSharedFunctionInfo<D, P>::function_token_offset() const {
  uint16_t value = this->template ReadField<uint16_t>(kFunctionTokenOffsetOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=86&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_function_token_offset(uint16_t value) {
  this->template WriteField<uint16_t>(kFunctionTokenOffsetOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=89&c=3
template<class D, class P>
uint8_t TorqueGeneratedSharedFunctionInfo<D, P>::expected_nof_properties() const {
  uint8_t value = this->template ReadField<uint8_t>(kExpectedNofPropertiesOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=89&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_expected_nof_properties(uint8_t value) {
  this->template WriteField<uint8_t>(kExpectedNofPropertiesOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=90&c=3
template<class D, class P>
uint8_t TorqueGeneratedSharedFunctionInfo<D, P>::flags2() const {
  uint8_t value = this->template ReadField<uint8_t>(kFlags2Offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=90&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_flags2(uint8_t value) {
  this->template WriteField<uint8_t>(kFlags2Offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=91&c=3
template<class D, class P>
uint32_t TorqueGeneratedSharedFunctionInfo<D, P>::flags() const {
  uint32_t value = this->template ReadField<uint32_t>(kFlagsOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=91&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_flags(uint32_t value) {
  this->template WriteField<uint32_t>(kFlagsOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=95&c=3
template<class D, class P>
int32_t TorqueGeneratedSharedFunctionInfo<D, P>::function_literal_id() const {
  int32_t value = this->template ReadField<int32_t>(kFunctionLiteralIdOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=95&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_function_literal_id(int32_t value) {
  this->template WriteField<int32_t>(kFunctionLiteralIdOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=99&c=3
template<class D, class P>
int32_t TorqueGeneratedSharedFunctionInfo<D, P>::unique_id() const {
  int32_t value = this->template ReadField<int32_t>(kUniqueIdOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=99&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_unique_id(int32_t value) {
  this->template WriteField<int32_t>(kUniqueIdOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=102&c=3
template<class D, class P>
uint16_t TorqueGeneratedSharedFunctionInfo<D, P>::age() const {
  uint16_t value = this->template ReadField<uint16_t>(kAgeOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=102&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_age(uint16_t value) {
  this->template WriteField<uint16_t>(kAgeOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=103&c=3
template<class D, class P>
uint16_t TorqueGeneratedSharedFunctionInfo<D, P>::padding() const {
  uint16_t value = this->template ReadField<uint16_t>(kPaddingOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=103&c=3
template<class D, class P>
void TorqueGeneratedSharedFunctionInfo<D, P>::set_padding(uint16_t value) {
  this->template WriteField<uint16_t>(kPaddingOffset, value);
}

template<class D, class P>
inline TorqueGeneratedSharedFunctionInfo<D, P>::TorqueGeneratedSharedFunctionInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsSharedFunctionInfo_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=143&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedUncompiledData<D, P>::inferred_name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedUncompiledData::inferred_name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=143&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedUncompiledData<D, P>::inferred_name(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kInferredNameOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=143&c=3
template<class D, class P>
void TorqueGeneratedUncompiledData<D, P>::set_inferred_name(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kInferredNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInferredNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=144&c=3
template<class D, class P>
int32_t TorqueGeneratedUncompiledData<D, P>::start_position() const {
  int32_t value = this->template ReadField<int32_t>(kStartPositionOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=144&c=3
template<class D, class P>
void TorqueGeneratedUncompiledData<D, P>::set_start_position(int32_t value) {
  this->template WriteField<int32_t>(kStartPositionOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=145&c=3
template<class D, class P>
int32_t TorqueGeneratedUncompiledData<D, P>::end_position() const {
  int32_t value = this->template ReadField<int32_t>(kEndPositionOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=145&c=3
template<class D, class P>
void TorqueGeneratedUncompiledData<D, P>::set_end_position(int32_t value) {
  this->template WriteField<int32_t>(kEndPositionOffset, value);
}

template<class D, class P>
inline TorqueGeneratedUncompiledData<D, P>::TorqueGeneratedUncompiledData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsUncompiledData_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedUncompiledDataWithoutPreparseData<D, P>::TorqueGeneratedUncompiledDataWithoutPreparseData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsUncompiledDataWithoutPreparseData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=155&c=3
template<class D, class P>
Tagged<PreparseData> TorqueGeneratedUncompiledDataWithPreparseData<D, P>::preparse_data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedUncompiledDataWithPreparseData::preparse_data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=155&c=3
template<class D, class P>
Tagged<PreparseData> TorqueGeneratedUncompiledDataWithPreparseData<D, P>::preparse_data(PtrComprCageBase cage_base) const {
  Tagged<PreparseData> value = TaggedField<Tagged<PreparseData>>::load(cage_base, *this, kPreparseDataOffset);
  DCHECK(IsPreparseData(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=155&c=3
template<class D, class P>
void TorqueGeneratedUncompiledDataWithPreparseData<D, P>::set_preparse_data(Tagged<PreparseData> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsPreparseData(value));
  WRITE_FIELD(*this, kPreparseDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kPreparseDataOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedUncompiledDataWithPreparseData<D, P>::TorqueGeneratedUncompiledDataWithPreparseData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsUncompiledDataWithPreparseData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=162&c=3
template<class D, class P>
Address TorqueGeneratedUncompiledDataWithoutPreparseDataWithJob<D, P>::job() const {
  Address value = this->template ReadField<Address>(kJobOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=162&c=3
template<class D, class P>
void TorqueGeneratedUncompiledDataWithoutPreparseDataWithJob<D, P>::set_job(Address value) {
  this->template WriteField<Address>(kJobOffset, value);
}

template<class D, class P>
inline TorqueGeneratedUncompiledDataWithoutPreparseDataWithJob<D, P>::TorqueGeneratedUncompiledDataWithoutPreparseDataWithJob(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsUncompiledDataWithoutPreparseDataWithJob_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=169&c=3
template<class D, class P>
Address TorqueGeneratedUncompiledDataWithPreparseDataAndJob<D, P>::job() const {
  Address value = this->template ReadField<Address>(kJobOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=169&c=3
template<class D, class P>
void TorqueGeneratedUncompiledDataWithPreparseDataAndJob<D, P>::set_job(Address value) {
  this->template WriteField<Address>(kJobOffset, value);
}

template<class D, class P>
inline TorqueGeneratedUncompiledDataWithPreparseDataAndJob<D, P>::TorqueGeneratedUncompiledDataWithPreparseDataAndJob(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsUncompiledDataWithPreparseDataAndJob_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=184&c=3
template<class D, class P>
Tagged<FixedInt32Array> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::block_ids() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedOnHeapBasicBlockProfilerData::block_ids(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=184&c=3
template<class D, class P>
Tagged<FixedInt32Array> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::block_ids(PtrComprCageBase cage_base) const {
  Tagged<FixedInt32Array> value = TaggedField<Tagged<FixedInt32Array>>::load(cage_base, *this, kBlockIdsOffset);
  DCHECK(IsByteArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=184&c=3
template<class D, class P>
void TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::set_block_ids(Tagged<FixedInt32Array> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsByteArray(value));
  WRITE_FIELD(*this, kBlockIdsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBlockIdsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=185&c=3
template<class D, class P>
Tagged<FixedUInt32Array> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::counts() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedOnHeapBasicBlockProfilerData::counts(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=185&c=3
template<class D, class P>
Tagged<FixedUInt32Array> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::counts(PtrComprCageBase cage_base) const {
  Tagged<FixedUInt32Array> value = TaggedField<Tagged<FixedUInt32Array>>::load(cage_base, *this, kCountsOffset);
  DCHECK(IsByteArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=185&c=3
template<class D, class P>
void TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::set_counts(Tagged<FixedUInt32Array> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsByteArray(value));
  WRITE_FIELD(*this, kCountsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCountsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=186&c=3
template<class D, class P>
Tagged<PodArray<std::pair<int32_t, int32_t>>> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::branches() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedOnHeapBasicBlockProfilerData::branches(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=186&c=3
template<class D, class P>
Tagged<PodArray<std::pair<int32_t, int32_t>>> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::branches(PtrComprCageBase cage_base) const {
  Tagged<PodArray<std::pair<int32_t, int32_t>>> value = TaggedField<Tagged<PodArray<std::pair<int32_t, int32_t>>>>::load(cage_base, *this, kBranchesOffset);
  DCHECK(IsByteArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=186&c=3
template<class D, class P>
void TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::set_branches(Tagged<PodArray<std::pair<int32_t, int32_t>>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsByteArray(value));
  WRITE_FIELD(*this, kBranchesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBranchesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=187&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedOnHeapBasicBlockProfilerData::name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=187&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::name(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kNameOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=187&c=3
template<class D, class P>
void TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::set_name(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=188&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::schedule() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedOnHeapBasicBlockProfilerData::schedule(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=188&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::schedule(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kScheduleOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=188&c=3
template<class D, class P>
void TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::set_schedule(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kScheduleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kScheduleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=189&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::code() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedOnHeapBasicBlockProfilerData::code(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=189&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::code(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kCodeOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=189&c=3
template<class D, class P>
void TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::set_code(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kCodeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCodeOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=190&c=3
template<class D, class P>
int TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::hash() const {
  int value = TaggedField<Smi>::load(*this, kHashOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=190&c=3
template<class D, class P>
void TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::set_hash(int value) {
  WRITE_FIELD(*this, kHashOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedOnHeapBasicBlockProfilerData<D, P>::TorqueGeneratedOnHeapBasicBlockProfilerData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsOnHeapBasicBlockProfilerData_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(OnHeapBasicBlockProfilerData)
