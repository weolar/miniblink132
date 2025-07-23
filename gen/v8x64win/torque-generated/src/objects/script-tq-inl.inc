// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=21&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedScript<D, P>::source() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::source(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=21&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedScript<D, P>::source(PtrComprCageBase cage_base) const {
  Tagged<Union<String, Undefined>> value = TaggedField<Tagged<Union<String, Undefined>>>::load(cage_base, *this, kSourceOffset);
  DCHECK(IsUndefined(value) || IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=21&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_source(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsString(value));
  WRITE_FIELD(*this, kSourceOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=24&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedScript<D, P>::name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=24&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedScript<D, P>::name(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kNameOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=24&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_name(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=27&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::line_offset() const {
  int value = TaggedField<Smi>::load(*this, kLineOffsetOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=27&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_line_offset(int value) {
  WRITE_FIELD(*this, kLineOffsetOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=31&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::column_offset() const {
  int value = TaggedField<Smi>::load(*this, kColumnOffsetOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=31&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_column_offset(int value) {
  WRITE_FIELD(*this, kColumnOffsetOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=34&c=3
template<class D, class P>
Tagged<Union<Smi, Symbol, Undefined>> TorqueGeneratedScript<D, P>::context_data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::context_data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=34&c=3
template<class D, class P>
Tagged<Union<Smi, Symbol, Undefined>> TorqueGeneratedScript<D, P>::context_data(PtrComprCageBase cage_base) const {
  Tagged<Union<Smi, Symbol, Undefined>> value = TaggedField<Tagged<Union<Smi, Symbol, Undefined>>>::load(cage_base, *this, kContextDataOffset);
  DCHECK(IsUndefined(value) || IsSymbol(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=34&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_context_data(Tagged<Union<Smi, Symbol, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSymbol(value) || IsSmi(value));
  WRITE_FIELD(*this, kContextDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kContextDataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=36&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::script_type() const {
  int value = TaggedField<Smi>::load(*this, kScriptTypeOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=36&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_script_type(int value) {
  WRITE_FIELD(*this, kScriptTypeOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=39&c=3
template<class D, class P>
Tagged<Union<FixedArray, Smi>> TorqueGeneratedScript<D, P>::line_ends() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::line_ends(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=39&c=3
template<class D, class P>
Tagged<Union<FixedArray, Smi>> TorqueGeneratedScript<D, P>::line_ends(PtrComprCageBase cage_base) const {
  Tagged<Union<FixedArray, Smi>> value = TaggedField<Tagged<Union<FixedArray, Smi>>>::load(cage_base, *this, kLineEndsOffset);
  DCHECK(IsSmi(value) || IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=39&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_line_ends(Tagged<Union<FixedArray, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsFixedArray(value));
  WRITE_FIELD(*this, kLineEndsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLineEndsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=42&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::id() const {
  int value = TaggedField<Smi>::load(*this, kIdOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=42&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_id(int value) {
  WRITE_FIELD(*this, kIdOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=47&c=3
template<class D, class P>
Tagged<Union<FixedArray, SharedFunctionInfo, Undefined>> TorqueGeneratedScript<D, P>::eval_from_shared_or_wrapped_arguments() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::eval_from_shared_or_wrapped_arguments(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=47&c=3
template<class D, class P>
Tagged<Union<FixedArray, SharedFunctionInfo, Undefined>> TorqueGeneratedScript<D, P>::eval_from_shared_or_wrapped_arguments(PtrComprCageBase cage_base) const {
  Tagged<Union<FixedArray, SharedFunctionInfo, Undefined>> value = TaggedField<Tagged<Union<FixedArray, SharedFunctionInfo, Undefined>>>::load(cage_base, *this, kEvalFromSharedOrWrappedArgumentsOffset);
  DCHECK(IsUndefined(value) || IsFixedArray(value) || IsSharedFunctionInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=47&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_eval_from_shared_or_wrapped_arguments(Tagged<Union<FixedArray, SharedFunctionInfo, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsFixedArray(value) || IsSharedFunctionInfo(value));
  WRITE_FIELD(*this, kEvalFromSharedOrWrappedArgumentsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEvalFromSharedOrWrappedArgumentsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi>> TorqueGeneratedScript<D, P>::eval_from_position() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::eval_from_position(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi>> TorqueGeneratedScript<D, P>::eval_from_position(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi>> value = TaggedField<Tagged<Union<Foreign, Smi>>>::load(cage_base, *this, kEvalFromPositionOffset);
  DCHECK(IsSmi(value) || IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_eval_from_position(Tagged<Union<Foreign, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsForeign(value));
  WRITE_FIELD(*this, kEvalFromPositionOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEvalFromPositionOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=50&c=3
template<class D, class P>
Tagged<Union<WeakArrayList, WeakFixedArray>> TorqueGeneratedScript<D, P>::infos() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::infos(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=50&c=3
template<class D, class P>
Tagged<Union<WeakArrayList, WeakFixedArray>> TorqueGeneratedScript<D, P>::infos(PtrComprCageBase cage_base) const {
  Tagged<Union<WeakArrayList, WeakFixedArray>> value = TaggedField<Tagged<Union<WeakArrayList, WeakFixedArray>>>::load(cage_base, *this, kInfosOffset);
  DCHECK(IsWeakFixedArray(value) || IsWeakArrayList(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=50&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_infos(Tagged<Union<WeakArrayList, WeakFixedArray>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsWeakFixedArray(value) || IsWeakArrayList(value));
  WRITE_FIELD(*this, kInfosOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInfosOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=54&c=3
template<class D, class P>
Tagged<Union<ArrayList, Undefined>> TorqueGeneratedScript<D, P>::compiled_lazy_function_positions() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::compiled_lazy_function_positions(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=54&c=3
template<class D, class P>
Tagged<Union<ArrayList, Undefined>> TorqueGeneratedScript<D, P>::compiled_lazy_function_positions(PtrComprCageBase cage_base) const {
  Tagged<Union<ArrayList, Undefined>> value = TaggedField<Tagged<Union<ArrayList, Undefined>>>::load(cage_base, *this, kCompiledLazyFunctionPositionsOffset);
  DCHECK(IsUndefined(value) || IsArrayList(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=54&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_compiled_lazy_function_positions(Tagged<Union<ArrayList, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsArrayList(value));
  WRITE_FIELD(*this, kCompiledLazyFunctionPositionsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCompiledLazyFunctionPositionsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=57&c=3
template<class D, class P>
int TorqueGeneratedScript<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=57&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=60&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedScript<D, P>::source_url() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::source_url(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=60&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedScript<D, P>::source_url(PtrComprCageBase cage_base) const {
  Tagged<Union<String, Undefined>> value = TaggedField<Tagged<Union<String, Undefined>>>::load(cage_base, *this, kSourceUrlOffset);
  DCHECK(IsUndefined(value) || IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=60&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_source_url(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsString(value));
  WRITE_FIELD(*this, kSourceUrlOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceUrlOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=63&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedScript<D, P>::source_mapping_url() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::source_mapping_url(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=63&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedScript<D, P>::source_mapping_url(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kSourceMappingUrlOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=63&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_source_mapping_url(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kSourceMappingUrlOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceMappingUrlOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=66&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedScript<D, P>::host_defined_options() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::host_defined_options(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=66&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedScript<D, P>::host_defined_options(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kHostDefinedOptionsOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=66&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_host_defined_options(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kHostDefinedOptionsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kHostDefinedOptionsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=75&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedScript<D, P>::source_hash() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScript::source_hash(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=75&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedScript<D, P>::source_hash(PtrComprCageBase cage_base) const {
  Tagged<Union<String, Undefined>> value = TaggedField<Tagged<Union<String, Undefined>>>::load(cage_base, *this, kSourceHashOffset);
  DCHECK(IsUndefined(value) || IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=75&c=3
template<class D, class P>
void TorqueGeneratedScript<D, P>::set_source_hash(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsString(value));
  WRITE_FIELD(*this, kSourceHashOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceHashOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedScript<D, P>::TorqueGeneratedScript(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsScript_NonInline(*this));
}
