// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
template<class D, class P>
Tagged<JSArrayBuffer> TorqueGeneratedJSArrayBufferView<D, P>::buffer() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSArrayBufferView::buffer(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
template<class D, class P>
Tagged<JSArrayBuffer> TorqueGeneratedJSArrayBufferView<D, P>::buffer(PtrComprCageBase cage_base) const {
  Tagged<JSArrayBuffer> value = TaggedField<Tagged<JSArrayBuffer>>::load(cage_base, *this, kBufferOffset);
  DCHECK(IsJSArrayBuffer(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBufferView<D, P>::set_buffer(Tagged<JSArrayBuffer> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSArrayBuffer(value));
  WRITE_FIELD(*this, kBufferOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBufferOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=66&c=3
template<class D, class P>
uint32_t TorqueGeneratedJSArrayBufferView<D, P>::bit_field() const {
  uint32_t value = this->template ReadField<uint32_t>(kBitFieldOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=66&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBufferView<D, P>::set_bit_field(uint32_t value) {
  this->template WriteField<uint32_t>(kBitFieldOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=69&c=3
template<class D, class P>
uintptr_t TorqueGeneratedJSArrayBufferView<D, P>::raw_byte_offset() const {
  uintptr_t value = this->template ReadField<uintptr_t>(kRawByteOffsetOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=69&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBufferView<D, P>::set_raw_byte_offset(uintptr_t value) {
  this->template WriteField<uintptr_t>(kRawByteOffsetOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=71&c=3
template<class D, class P>
uintptr_t TorqueGeneratedJSArrayBufferView<D, P>::raw_byte_length() const {
  uintptr_t value = this->template ReadField<uintptr_t>(kRawByteLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=71&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBufferView<D, P>::set_raw_byte_length(uintptr_t value) {
  this->template WriteField<uintptr_t>(kRawByteLengthOffset, value);
}

template<class D, class P>
inline TorqueGeneratedJSArrayBufferView<D, P>::TorqueGeneratedJSArrayBufferView(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSArrayBufferView_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=109&c=3
template<class D, class P>
uintptr_t TorqueGeneratedJSTypedArray<D, P>::raw_length() const {
  uintptr_t value = this->template ReadField<uintptr_t>(kRawLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=109&c=3
template<class D, class P>
void TorqueGeneratedJSTypedArray<D, P>::set_raw_length(uintptr_t value) {
  this->template WriteField<uintptr_t>(kRawLengthOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=111&c=3
template<class D, class P>
Address TorqueGeneratedJSTypedArray<D, P>::external_pointer() const {
  Address value = this->template ReadField<Address>(kExternalPointerOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=111&c=3
template<class D, class P>
void TorqueGeneratedJSTypedArray<D, P>::set_external_pointer(Address value) {
  this->template WriteField<Address>(kExternalPointerOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
template<class D, class P>
Tagged<Union<ByteArray, Smi>> TorqueGeneratedJSTypedArray<D, P>::base_pointer() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSTypedArray::base_pointer(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
template<class D, class P>
Tagged<Union<ByteArray, Smi>> TorqueGeneratedJSTypedArray<D, P>::base_pointer(PtrComprCageBase cage_base) const {
  Tagged<Union<ByteArray, Smi>> value = TaggedField<Tagged<Union<ByteArray, Smi>>>::load(cage_base, *this, kBasePointerOffset);
  DCHECK(IsSmi(value) || IsByteArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
template<class D, class P>
void TorqueGeneratedJSTypedArray<D, P>::set_base_pointer(Tagged<Union<ByteArray, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsByteArray(value));
  WRITE_FIELD(*this, kBasePointerOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBasePointerOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSTypedArray<D, P>::TorqueGeneratedJSTypedArray(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSTypedArray_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSArrayBuffer<D, P>::detach_key() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSArrayBuffer::detach_key(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSArrayBuffer<D, P>::detach_key(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kDetachKeyOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBuffer<D, P>::set_detach_key(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kDetachKeyOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDetachKeyOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=17&c=3
template<class D, class P>
uintptr_t TorqueGeneratedJSArrayBuffer<D, P>::raw_byte_length() const {
  uintptr_t value = this->template ReadField<uintptr_t>(kRawByteLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=17&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBuffer<D, P>::set_raw_byte_length(uintptr_t value) {
  this->template WriteField<uintptr_t>(kRawByteLengthOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=19&c=3
template<class D, class P>
uintptr_t TorqueGeneratedJSArrayBuffer<D, P>::raw_max_byte_length() const {
  uintptr_t value = this->template ReadField<uintptr_t>(kRawMaxByteLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=19&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBuffer<D, P>::set_raw_max_byte_length(uintptr_t value) {
  this->template WriteField<uintptr_t>(kRawMaxByteLengthOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=21&c=3
template<class D, class P>
Address TorqueGeneratedJSArrayBuffer<D, P>::backing_store() const {
  Address value = this->template ReadField<Address>(kBackingStoreOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=21&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBuffer<D, P>::set_backing_store(Address value) {
  this->template WriteField<Address>(kBackingStoreOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=23&c=3
template<class D, class P>
uint32_t TorqueGeneratedJSArrayBuffer<D, P>::bit_field() const {
  uint32_t value = this->template ReadField<uint32_t>(kBitFieldOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=23&c=3
template<class D, class P>
void TorqueGeneratedJSArrayBuffer<D, P>::set_bit_field(uint32_t value) {
  this->template WriteField<uint32_t>(kBitFieldOffset, value);
}

template<class D, class P>
inline TorqueGeneratedJSArrayBuffer<D, P>::TorqueGeneratedJSArrayBuffer(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSArrayBuffer_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=128&c=3
template<class D, class P>
Address TorqueGeneratedJSDataViewOrRabGsabDataView<D, P>::data_pointer() const {
  Address value = this->template ReadField<Address>(kDataPointerOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=128&c=3
template<class D, class P>
void TorqueGeneratedJSDataViewOrRabGsabDataView<D, P>::set_data_pointer(Address value) {
  this->template WriteField<Address>(kDataPointerOffset, value);
}

template<class D, class P>
inline TorqueGeneratedJSDataViewOrRabGsabDataView<D, P>::TorqueGeneratedJSDataViewOrRabGsabDataView(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSDataViewOrRabGsabDataView_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSDataView<D, P>::TorqueGeneratedJSDataView(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSDataView_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSRabGsabDataView<D, P>::TorqueGeneratedJSRabGsabDataView(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSRabGsabDataView_NonInline(*this));
}
