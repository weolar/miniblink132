// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=52&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedJSRegExp<D, P>::source() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExp::source(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=52&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedJSRegExp<D, P>::source(PtrComprCageBase cage_base) const {
  Tagged<Union<String, Undefined>> value = TaggedField<Tagged<Union<String, Undefined>>>::load(cage_base, *this, kSourceOffset);
  DCHECK(IsUndefined(value) || IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=52&c=3
template<class D, class P>
void TorqueGeneratedJSRegExp<D, P>::set_source(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsString(value));
  WRITE_FIELD(*this, kSourceOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSourceOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=53&c=3
template<class D, class P>
Tagged<Union<Smi, Undefined>> TorqueGeneratedJSRegExp<D, P>::flags() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExp::flags(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=53&c=3
template<class D, class P>
Tagged<Union<Smi, Undefined>> TorqueGeneratedJSRegExp<D, P>::flags(PtrComprCageBase cage_base) const {
  Tagged<Union<Smi, Undefined>> value = TaggedField<Tagged<Union<Smi, Undefined>>>::load(cage_base, *this, kFlagsOffset);
  DCHECK(IsUndefined(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=53&c=3
template<class D, class P>
void TorqueGeneratedJSRegExp<D, P>::set_flags(Tagged<Union<Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value));
  WRITE_FIELD(*this, kFlagsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kFlagsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSRegExp<D, P>::TorqueGeneratedJSRegExp(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSRegExp_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=80&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResult<D, P>::index() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpResult::index(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=80&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResult<D, P>::index(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kIndexOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=80&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpResult<D, P>::set_index(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kIndexOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIndexOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=81&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResult<D, P>::input() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpResult::input(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=81&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResult<D, P>::input(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kInputOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=81&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpResult<D, P>::set_input(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kInputOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInputOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=82&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResult<D, P>::groups() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpResult::groups(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=82&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResult<D, P>::groups(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kGroupsOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=82&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpResult<D, P>::set_groups(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kGroupsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kGroupsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=85&c=3
template<class D, class P>
Tagged<Union<FixedArray, Undefined>> TorqueGeneratedJSRegExpResult<D, P>::names() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpResult::names(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=85&c=3
template<class D, class P>
Tagged<Union<FixedArray, Undefined>> TorqueGeneratedJSRegExpResult<D, P>::names(PtrComprCageBase cage_base) const {
  Tagged<Union<FixedArray, Undefined>> value = TaggedField<Tagged<Union<FixedArray, Undefined>>>::load(cage_base, *this, kNamesOffset);
  DCHECK(IsUndefined(value) || IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=85&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpResult<D, P>::set_names(Tagged<Union<FixedArray, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsFixedArray(value));
  WRITE_FIELD(*this, kNamesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNamesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=86&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSRegExpResult<D, P>::regexp_input() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpResult::regexp_input(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=86&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSRegExpResult<D, P>::regexp_input(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kRegexpInputOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=86&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpResult<D, P>::set_regexp_input(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kRegexpInputOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRegexpInputOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=87&c=3
template<class D, class P>
int TorqueGeneratedJSRegExpResult<D, P>::regexp_last_index() const {
  int value = TaggedField<Smi>::load(*this, kRegexpLastIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=87&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpResult<D, P>::set_regexp_last_index(int value) {
  WRITE_FIELD(*this, kRegexpLastIndexOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSRegExpResult<D, P>::TorqueGeneratedJSRegExpResult(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSArray_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=91&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResultWithIndices<D, P>::indices() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpResultWithIndices::indices(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=91&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResultWithIndices<D, P>::indices(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kIndicesOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=91&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpResultWithIndices<D, P>::set_indices(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kIndicesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIndicesOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSRegExpResultWithIndices<D, P>::TorqueGeneratedJSRegExpResultWithIndices(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSArray_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=97&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResultIndices<D, P>::groups() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpResultIndices::groups(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=97&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSRegExpResultIndices<D, P>::groups(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kGroupsOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=97&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpResultIndices<D, P>::set_groups(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kGroupsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kGroupsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSRegExpResultIndices<D, P>::TorqueGeneratedJSRegExpResultIndices(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSArray_NonInline(*this));
}
