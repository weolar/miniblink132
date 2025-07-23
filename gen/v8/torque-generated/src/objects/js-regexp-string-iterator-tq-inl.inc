// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=13&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSRegExpStringIterator<D, P>::iterating_reg_exp() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpStringIterator::iterating_reg_exp(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=13&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSRegExpStringIterator<D, P>::iterating_reg_exp(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kIteratingRegExpOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=13&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpStringIterator<D, P>::set_iterating_reg_exp(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kIteratingRegExpOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIteratingRegExpOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=15&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSRegExpStringIterator<D, P>::iterated_string() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSRegExpStringIterator::iterated_string(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=15&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSRegExpStringIterator<D, P>::iterated_string(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kIteratedStringOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpStringIterator<D, P>::set_iterated_string(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kIteratedStringOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kIteratedStringOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=16&c=3
template<class D, class P>
int TorqueGeneratedJSRegExpStringIterator<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp-string-iterator.tq?l=16&c=3
template<class D, class P>
void TorqueGeneratedJSRegExpStringIterator<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSRegExpStringIterator<D, P>::TorqueGeneratedJSRegExpStringIterator(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSRegExpStringIterator_NonInline(*this));
}
