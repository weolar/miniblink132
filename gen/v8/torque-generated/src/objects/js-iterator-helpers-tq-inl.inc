// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Null, Undefined>> TorqueGeneratedJSIteratorHelper<D, P>::underlying_object() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorHelper::underlying_object(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Null, Undefined>> TorqueGeneratedJSIteratorHelper<D, P>::underlying_object(PtrComprCageBase cage_base) const {
  Tagged<Union<JSReceiver, Null, Undefined>> value = TaggedField<Tagged<Union<JSReceiver, Null, Undefined>>>::load(cage_base, *this, kUnderlyingObjectOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorHelper<D, P>::set_underlying_object(Tagged<Union<JSReceiver, Null, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value));
  WRITE_FIELD(*this, kUnderlyingObjectOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUnderlyingObjectOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSIteratorHelper<D, P>::underlying_next() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorHelper::underlying_next(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSIteratorHelper<D, P>::underlying_next(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kUnderlyingNextOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorHelper<D, P>::set_underlying_next(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kUnderlyingNextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUnderlyingNextOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSIteratorHelper<D, P>::TorqueGeneratedJSIteratorHelper(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSIteratorHelper_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> TorqueGeneratedJSIteratorMapHelper<D, P>::mapper() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorMapHelper::mapper(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> TorqueGeneratedJSIteratorMapHelper<D, P>::mapper(PtrComprCageBase cage_base) const {
  Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value = TaggedField<Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>>>::load(cage_base, *this, kMapperOffset);
  DCHECK(IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorMapHelper<D, P>::set_mapper(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  WRITE_FIELD(*this, kMapperOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMapperOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorMapHelper<D, P>::counter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorMapHelper::counter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorMapHelper<D, P>::counter(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kCounterOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorMapHelper<D, P>::set_counter(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kCounterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCounterOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSIteratorMapHelper<D, P>::TorqueGeneratedJSIteratorMapHelper(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSIteratorMapHelper_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> TorqueGeneratedJSIteratorFilterHelper<D, P>::predicate() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorFilterHelper::predicate(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> TorqueGeneratedJSIteratorFilterHelper<D, P>::predicate(PtrComprCageBase cage_base) const {
  Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value = TaggedField<Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>>>::load(cage_base, *this, kPredicateOffset);
  DCHECK(IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorFilterHelper<D, P>::set_predicate(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  WRITE_FIELD(*this, kPredicateOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kPredicateOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorFilterHelper<D, P>::counter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorFilterHelper::counter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorFilterHelper<D, P>::counter(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kCounterOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorFilterHelper<D, P>::set_counter(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kCounterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCounterOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSIteratorFilterHelper<D, P>::TorqueGeneratedJSIteratorFilterHelper(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSIteratorFilterHelper_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorTakeHelper<D, P>::remaining() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorTakeHelper::remaining(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorTakeHelper<D, P>::remaining(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kRemainingOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorTakeHelper<D, P>::set_remaining(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kRemainingOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRemainingOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSIteratorTakeHelper<D, P>::TorqueGeneratedJSIteratorTakeHelper(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSIteratorTakeHelper_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorDropHelper<D, P>::remaining() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorDropHelper::remaining(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorDropHelper<D, P>::remaining(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kRemainingOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorDropHelper<D, P>::set_remaining(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kRemainingOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRemainingOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSIteratorDropHelper<D, P>::TorqueGeneratedJSIteratorDropHelper(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSIteratorDropHelper_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::mapper() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorFlatMapHelper::mapper(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::mapper(PtrComprCageBase cage_base) const {
  Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value = TaggedField<Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>>>::load(cage_base, *this, kMapperOffset);
  DCHECK(IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorFlatMapHelper<D, P>::set_mapper(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  WRITE_FIELD(*this, kMapperOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMapperOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::counter() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorFlatMapHelper::counter(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::counter(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kCounterOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorFlatMapHelper<D, P>::set_counter(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kCounterOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCounterOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::innerIterator_object() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorFlatMapHelper::innerIterator_object(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::innerIterator_object(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kInnerIteratorOffset + 0);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorFlatMapHelper<D, P>::set_innerIterator_object(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kInnerIteratorOffset + 0, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInnerIteratorOffset + 0, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::innerIterator_next() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorFlatMapHelper::innerIterator_next(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::innerIterator_next(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kInnerIteratorOffset + 4);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorFlatMapHelper<D, P>::set_innerIterator_next(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kInnerIteratorOffset + 4, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInnerIteratorOffset + 4, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
template<class D, class P>
Tagged<Boolean> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::innerAlive() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSIteratorFlatMapHelper::innerAlive(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
template<class D, class P>
Tagged<Boolean> TorqueGeneratedJSIteratorFlatMapHelper<D, P>::innerAlive(PtrComprCageBase cage_base) const {
  Tagged<Boolean> value = TaggedField<Tagged<Boolean>>::load(cage_base, *this, kInnerAliveOffset);
  DCHECK(IsBoolean(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
template<class D, class P>
void TorqueGeneratedJSIteratorFlatMapHelper<D, P>::set_innerAlive(Tagged<Boolean> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsBoolean(value));
  WRITE_FIELD(*this, kInnerAliveOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInnerAliveOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSIteratorFlatMapHelper<D, P>::TorqueGeneratedJSIteratorFlatMapHelper(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSIteratorFlatMapHelper_NonInline(*this));
}
