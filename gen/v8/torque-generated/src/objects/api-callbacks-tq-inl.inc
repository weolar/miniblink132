// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=14&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::getter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInterceptorInfo::getter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=14&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::getter(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi, Undefined>> value = TaggedField<Tagged<Union<Foreign, Smi, Undefined>>>::load(cage_base, *this, kGetterOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_getter(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  WRITE_FIELD(*this, kGetterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kGetterOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=15&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::setter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInterceptorInfo::setter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=15&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::setter(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi, Undefined>> value = TaggedField<Tagged<Union<Foreign, Smi, Undefined>>>::load(cage_base, *this, kSetterOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_setter(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  WRITE_FIELD(*this, kSetterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSetterOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=16&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::query() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInterceptorInfo::query(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=16&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::query(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi, Undefined>> value = TaggedField<Tagged<Union<Foreign, Smi, Undefined>>>::load(cage_base, *this, kQueryOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=16&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_query(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  WRITE_FIELD(*this, kQueryOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kQueryOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=17&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::descriptor() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInterceptorInfo::descriptor(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=17&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::descriptor(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi, Undefined>> value = TaggedField<Tagged<Union<Foreign, Smi, Undefined>>>::load(cage_base, *this, kDescriptorOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=17&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_descriptor(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  WRITE_FIELD(*this, kDescriptorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDescriptorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=18&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::deleter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInterceptorInfo::deleter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=18&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::deleter(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi, Undefined>> value = TaggedField<Tagged<Union<Foreign, Smi, Undefined>>>::load(cage_base, *this, kDeleterOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=18&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_deleter(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  WRITE_FIELD(*this, kDeleterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDeleterOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=19&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::enumerator() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInterceptorInfo::enumerator(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=19&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::enumerator(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi, Undefined>> value = TaggedField<Tagged<Union<Foreign, Smi, Undefined>>>::load(cage_base, *this, kEnumeratorOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=19&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_enumerator(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  WRITE_FIELD(*this, kEnumeratorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEnumeratorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=20&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::definer() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInterceptorInfo::definer(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=20&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedInterceptorInfo<D, P>::definer(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi, Undefined>> value = TaggedField<Tagged<Union<Foreign, Smi, Undefined>>>::load(cage_base, *this, kDefinerOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=20&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_definer(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsNonNullForeign(value));
  WRITE_FIELD(*this, kDefinerOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDefinerOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=21&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedInterceptorInfo<D, P>::data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInterceptorInfo::data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=21&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedInterceptorInfo<D, P>::data(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kDataOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=21&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_data(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=22&c=3
template<class D, class P>
int TorqueGeneratedInterceptorInfo<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=22&c=3
template<class D, class P>
void TorqueGeneratedInterceptorInfo<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedInterceptorInfo<D, P>::TorqueGeneratedInterceptorInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsInterceptorInfo_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedAccessCheckInfo<D, P>::callback() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAccessCheckInfo::callback(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
template<class D, class P>
Tagged<Union<Foreign, Smi, Undefined>> TorqueGeneratedAccessCheckInfo<D, P>::callback(PtrComprCageBase cage_base) const {
  Tagged<Union<Foreign, Smi, Undefined>> value = TaggedField<Tagged<Union<Foreign, Smi, Undefined>>>::load(cage_base, *this, kCallbackOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
template<class D, class P>
void TorqueGeneratedAccessCheckInfo<D, P>::set_callback(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsForeign(value));
  WRITE_FIELD(*this, kCallbackOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallbackOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
template<class D, class P>
Tagged<Union<InterceptorInfo, Smi, Undefined>> TorqueGeneratedAccessCheckInfo<D, P>::named_interceptor() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAccessCheckInfo::named_interceptor(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
template<class D, class P>
Tagged<Union<InterceptorInfo, Smi, Undefined>> TorqueGeneratedAccessCheckInfo<D, P>::named_interceptor(PtrComprCageBase cage_base) const {
  Tagged<Union<InterceptorInfo, Smi, Undefined>> value = TaggedField<Tagged<Union<InterceptorInfo, Smi, Undefined>>>::load(cage_base, *this, kNamedInterceptorOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsInterceptorInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
template<class D, class P>
void TorqueGeneratedAccessCheckInfo<D, P>::set_named_interceptor(Tagged<Union<InterceptorInfo, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsInterceptorInfo(value));
  WRITE_FIELD(*this, kNamedInterceptorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNamedInterceptorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
template<class D, class P>
Tagged<Union<InterceptorInfo, Smi, Undefined>> TorqueGeneratedAccessCheckInfo<D, P>::indexed_interceptor() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAccessCheckInfo::indexed_interceptor(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
template<class D, class P>
Tagged<Union<InterceptorInfo, Smi, Undefined>> TorqueGeneratedAccessCheckInfo<D, P>::indexed_interceptor(PtrComprCageBase cage_base) const {
  Tagged<Union<InterceptorInfo, Smi, Undefined>> value = TaggedField<Tagged<Union<InterceptorInfo, Smi, Undefined>>>::load(cage_base, *this, kIndexedInterceptorOffset);
  DCHECK(IsUndefined(value) || IsZero(value) || IsInterceptorInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
template<class D, class P>
void TorqueGeneratedAccessCheckInfo<D, P>::set_indexed_interceptor(Tagged<Union<InterceptorInfo, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsZero(value) || IsInterceptorInfo(value));
  WRITE_FIELD(*this, kIndexedInterceptorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIndexedInterceptorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedAccessCheckInfo<D, P>::data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAccessCheckInfo::data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedAccessCheckInfo<D, P>::data(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kDataOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
template<class D, class P>
void TorqueGeneratedAccessCheckInfo<D, P>::set_data(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDataOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedAccessCheckInfo<D, P>::TorqueGeneratedAccessCheckInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAccessCheckInfo_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=43&c=3
template<class D, class P>
Tagged<Name> TorqueGeneratedAccessorInfo<D, P>::name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAccessorInfo::name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=43&c=3
template<class D, class P>
Tagged<Name> TorqueGeneratedAccessorInfo<D, P>::name(PtrComprCageBase cage_base) const {
  Tagged<Name> value = TaggedField<Tagged<Name>>::load(cage_base, *this, kNameOffset);
  DCHECK(IsName(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=43&c=3
template<class D, class P>
void TorqueGeneratedAccessorInfo<D, P>::set_name(Tagged<Name> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsName(value));
  WRITE_FIELD(*this, kNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=44&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedAccessorInfo<D, P>::data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAccessorInfo::data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=44&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedAccessorInfo<D, P>::data(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kDataOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=44&c=3
template<class D, class P>
void TorqueGeneratedAccessorInfo<D, P>::set_data(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=50&c=3
template<class D, class P>
uint32_t TorqueGeneratedAccessorInfo<D, P>::flags() const {
  uint32_t value = this->template ReadField<uint32_t>(kFlagsOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=50&c=3
template<class D, class P>
void TorqueGeneratedAccessorInfo<D, P>::set_flags(uint32_t value) {
  this->template WriteField<uint32_t>(kFlagsOffset, value);
}

template<class D, class P>
inline TorqueGeneratedAccessorInfo<D, P>::TorqueGeneratedAccessorInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAccessorInfo_NonInline(*this));
}
