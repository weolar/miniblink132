// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=8&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSArrayIterator<D, P>::iterated_object() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSArrayIterator::iterated_object(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=8&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSArrayIterator<D, P>::iterated_object(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kIteratedObjectOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedJSArrayIterator<D, P>::set_iterated_object(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kIteratedObjectOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIteratedObjectOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=33&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSArrayIterator<D, P>::next_index() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSArrayIterator::next_index(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=33&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSArrayIterator<D, P>::next_index(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kNextIndexOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=33&c=3
template<class D, class P>
void TorqueGeneratedJSArrayIterator<D, P>::set_next_index(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kNextIndexOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNextIndexOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=35&c=3
template<class D, class P>
int TorqueGeneratedJSArrayIterator<D, P>::kind() const {
  int value = TaggedField<Smi>::load(*this, kKindOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=35&c=3
template<class D, class P>
void TorqueGeneratedJSArrayIterator<D, P>::set_kind(int value) {
  WRITE_FIELD(*this, kKindOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSArrayIterator<D, P>::TorqueGeneratedJSArrayIterator(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSArrayIterator_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=65&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSArray<D, P>::length() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSArray::length(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=65&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedJSArray<D, P>::length(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kLengthOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=65&c=3
template<class D, class P>
void TorqueGeneratedJSArray<D, P>::set_length(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kLengthOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLengthOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSArray<D, P>::TorqueGeneratedJSArray(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSArray_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=71&c=3
template<class D, class P>
Tagged<JSArray> TorqueGeneratedTemplateLiteralObject<D, P>::raw() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedTemplateLiteralObject::raw(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=71&c=3
template<class D, class P>
Tagged<JSArray> TorqueGeneratedTemplateLiteralObject<D, P>::raw(PtrComprCageBase cage_base) const {
  Tagged<JSArray> value = TaggedField<Tagged<JSArray>>::load(cage_base, *this, kRawOffset);
  DCHECK(IsJSArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=71&c=3
template<class D, class P>
void TorqueGeneratedTemplateLiteralObject<D, P>::set_raw(Tagged<JSArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSArray(value));
  WRITE_FIELD(*this, kRawOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRawOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=72&c=3
template<class D, class P>
int TorqueGeneratedTemplateLiteralObject<D, P>::function_literal_id() const {
  int value = TaggedField<Smi>::load(*this, kFunctionLiteralIdOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=72&c=3
template<class D, class P>
void TorqueGeneratedTemplateLiteralObject<D, P>::set_function_literal_id(int value) {
  WRITE_FIELD(*this, kFunctionLiteralIdOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=73&c=3
template<class D, class P>
int TorqueGeneratedTemplateLiteralObject<D, P>::slot_id() const {
  int value = TaggedField<Smi>::load(*this, kSlotIdOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=73&c=3
template<class D, class P>
void TorqueGeneratedTemplateLiteralObject<D, P>::set_slot_id(int value) {
  WRITE_FIELD(*this, kSlotIdOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedTemplateLiteralObject<D, P>::TorqueGeneratedTemplateLiteralObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTemplateLiteralObject_NonInline(*this));
}
