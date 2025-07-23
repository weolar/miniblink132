class JSArrayBufferView;
class JSTypedArray;
class JSArrayBuffer;
class JSDataViewOrRabGsabDataView;
class JSDataView;
class JSRabGsabDataView;
// Alias for IsJSArrayBufferView() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=63&c=1
V8_EXPORT_PRIVATE bool IsJSArrayBufferView_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=63&c=1
template <class D, class P>
class TorqueGeneratedJSArrayBufferView : public P {
  static_assert(
      std::is_same<JSArrayBufferView, D>::value,
      "Use this class as direct base for JSArrayBufferView.");
  static_assert(
      std::is_same<JSAPIObjectWithEmbedderSlots, P>::value,
      "Pass in JSAPIObjectWithEmbedderSlots as second template parameter for TorqueGeneratedJSArrayBufferView.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSArrayBufferView<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
  inline Tagged<JSArrayBuffer> buffer() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
  inline Tagged<JSArrayBuffer> buffer(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
  inline void set_buffer(Tagged<JSArrayBuffer> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=66&c=3
  inline uint32_t bit_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=66&c=3
  inline void set_bit_field(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=69&c=3
  inline uintptr_t raw_byte_offset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=69&c=3
  inline void set_raw_byte_offset(uintptr_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=71&c=3
  inline uintptr_t raw_byte_length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=71&c=3
  inline void set_raw_byte_length(uintptr_t value);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=63&c=1
  V8_EXPORT_PRIVATE void JSArrayBufferViewVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=65&c=3
  static constexpr int kBufferOffset = P::kHeaderSize;
  static constexpr int kBufferOffsetEnd = kBufferOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBufferOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=66&c=3
  static constexpr int kBitFieldOffset = kBufferOffsetEnd + 1;
  static constexpr int kBitFieldOffsetEnd = kBitFieldOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=69&c=3
  static constexpr int kRawByteOffsetOffset = kBitFieldOffsetEnd + 1;
  static constexpr int kRawByteOffsetOffsetEnd = kRawByteOffsetOffset + kIntptrSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=71&c=3
  static constexpr int kRawByteLengthOffset = kRawByteOffsetOffsetEnd + 1;
  static constexpr int kRawByteLengthOffsetEnd = kRawByteLengthOffset + kIntptrSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kRawByteLengthOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kRawByteLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kRawByteLengthOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSArrayBufferView() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSArrayBufferView, DAlias>::value,
        "class TorqueGeneratedJSArrayBufferView should be used as direct base for JSArrayBufferView.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSArrayBufferView(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSArrayBufferView(Address ptr);
};

// Alias for IsJSTypedArray() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=107&c=1
V8_EXPORT_PRIVATE bool IsJSTypedArray_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=107&c=1
template <class D, class P>
class TorqueGeneratedJSTypedArray : public P {
  static_assert(
      std::is_same<JSTypedArray, D>::value,
      "Use this class as direct base for JSTypedArray.");
  static_assert(
      std::is_same<JSArrayBufferView, P>::value,
      "Pass in JSArrayBufferView as second template parameter for TorqueGeneratedJSTypedArray.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSTypedArray<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=109&c=3
  inline uintptr_t raw_length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=109&c=3
  inline void set_raw_length(uintptr_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=111&c=3
  inline Address external_pointer() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=111&c=3
  inline void set_external_pointer(Address value);

  // Torque type: (Smi | class ByteArray)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
  inline Tagged<Union<ByteArray, Smi>> base_pointer() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
  inline Tagged<Union<ByteArray, Smi>> base_pointer(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
  inline void set_base_pointer(Tagged<Union<ByteArray, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSTypedArray)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=107&c=1
  V8_EXPORT_PRIVATE void JSTypedArrayVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=109&c=3
  static constexpr int kRawLengthOffset = P::kHeaderSize;
  static constexpr int kRawLengthOffsetEnd = kRawLengthOffset + kIntptrSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=111&c=3
  static constexpr int kExternalPointerOffset = kRawLengthOffsetEnd + 1;
  static constexpr int kExternalPointerOffsetEnd = kExternalPointerOffset + kSystemPointerSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kExternalPointerOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=112&c=3
  static constexpr int kBasePointerOffset = kExternalPointerOffsetEnd + 1;
  static constexpr int kBasePointerOffsetEnd = kBasePointerOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBasePointerOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBasePointerOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBasePointerOffsetEnd + 1;
  static constexpr int kHeaderSize = kBasePointerOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSTypedArray() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSTypedArray, DAlias>::value,
        "class TorqueGeneratedJSTypedArray should be used as direct base for JSTypedArray.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSTypedArray(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSTypedArray(Address ptr);
};

// Alias for IsJSArrayBuffer() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=14&c=1
V8_EXPORT_PRIVATE bool IsJSArrayBuffer_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=14&c=1
template <class D, class P>
class TorqueGeneratedJSArrayBuffer : public P {
  static_assert(
      std::is_same<JSArrayBuffer, D>::value,
      "Use this class as direct base for JSArrayBuffer.");
  static_assert(
      std::is_same<JSAPIObjectWithEmbedderSlots, P>::value,
      "Pass in JSAPIObjectWithEmbedderSlots as second template parameter for TorqueGeneratedJSArrayBuffer.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSArrayBuffer<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
  inline Tagged<Object> detach_key() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
  inline Tagged<Object> detach_key(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
  inline void set_detach_key(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=17&c=3
  inline uintptr_t raw_byte_length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=17&c=3
  inline void set_raw_byte_length(uintptr_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=19&c=3
  inline uintptr_t raw_max_byte_length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=19&c=3
  inline void set_raw_max_byte_length(uintptr_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=21&c=3
  inline Address backing_store() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=21&c=3
  inline void set_backing_store(Address value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=23&c=3
  inline uint32_t bit_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=23&c=3
  inline void set_bit_field(uint32_t value);

  DECL_PRINTER(JSArrayBuffer)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=14&c=1
  V8_EXPORT_PRIVATE void JSArrayBufferVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=15&c=3
  static constexpr int kDetachKeyOffset = P::kHeaderSize;
  static constexpr int kDetachKeyOffsetEnd = kDetachKeyOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDetachKeyOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=17&c=3
  static constexpr int kRawByteLengthOffset = kDetachKeyOffsetEnd + 1;
  static constexpr int kRawByteLengthOffsetEnd = kRawByteLengthOffset + kIntptrSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=19&c=3
  static constexpr int kRawMaxByteLengthOffset = kRawByteLengthOffsetEnd + 1;
  static constexpr int kRawMaxByteLengthOffsetEnd = kRawMaxByteLengthOffset + kIntptrSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=21&c=3
  static constexpr int kBackingStoreOffset = kRawMaxByteLengthOffsetEnd + 1;
  static constexpr int kBackingStoreOffsetEnd = kBackingStoreOffset + kSystemPointerSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=22&c=3
  static constexpr int kExtensionOffset = kBackingStoreOffsetEnd + 1;
  static constexpr int kExtensionOffsetEnd = kExtensionOffset + kExternalPointerSlotSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=23&c=3
  static constexpr int kBitFieldOffset = kExtensionOffsetEnd + 1;
  static constexpr int kBitFieldOffsetEnd = kBitFieldOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=26&c=31
  static constexpr int kOptionalPaddingOffset = kBitFieldOffsetEnd + 1;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kHeaderSize = kOptionalPaddingOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSArrayBuffer() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSArrayBuffer, DAlias>::value,
        "class TorqueGeneratedJSArrayBuffer should be used as direct base for JSArrayBuffer.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSArrayBuffer(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSArrayBuffer(Address ptr);
};

// Alias for IsJSDataViewOrRabGsabDataView() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=125&c=1
V8_EXPORT_PRIVATE bool IsJSDataViewOrRabGsabDataView_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=125&c=1
template <class D, class P>
class TorqueGeneratedJSDataViewOrRabGsabDataView : public P {
  static_assert(
      std::is_same<JSDataViewOrRabGsabDataView, D>::value,
      "Use this class as direct base for JSDataViewOrRabGsabDataView.");
  static_assert(
      std::is_same<JSArrayBufferView, P>::value,
      "Pass in JSArrayBufferView as second template parameter for TorqueGeneratedJSDataViewOrRabGsabDataView.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSDataViewOrRabGsabDataView<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=128&c=3
  inline Address data_pointer() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=128&c=3
  inline void set_data_pointer(Address value);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=125&c=1
  V8_EXPORT_PRIVATE void JSDataViewOrRabGsabDataViewVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=128&c=3
  static constexpr int kDataPointerOffset = P::kHeaderSize;
  static constexpr int kDataPointerOffsetEnd = kDataPointerOffset + kSystemPointerSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kDataPointerOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDataPointerOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kDataPointerOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataPointerOffsetEnd + 1;
  static constexpr int kHeaderSize = kDataPointerOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSDataViewOrRabGsabDataView() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSDataViewOrRabGsabDataView, DAlias>::value,
        "class TorqueGeneratedJSDataViewOrRabGsabDataView should be used as direct base for JSDataViewOrRabGsabDataView.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSDataViewOrRabGsabDataView(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSDataViewOrRabGsabDataView(Address ptr);
};

// Alias for IsJSDataView() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=131&c=1
V8_EXPORT_PRIVATE bool IsJSDataView_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=131&c=1
template <class D, class P>
class TorqueGeneratedJSDataView : public P {
  static_assert(
      std::is_same<JSDataView, D>::value,
      "Use this class as direct base for JSDataView.");
  static_assert(
      std::is_same<JSDataViewOrRabGsabDataView, P>::value,
      "Pass in JSDataViewOrRabGsabDataView as second template parameter for TorqueGeneratedJSDataView.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSDataView<D,P>;

  DECL_PRINTER(JSDataView)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=131&c=1
  V8_EXPORT_PRIVATE void JSDataViewVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSDataView() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSDataView, DAlias>::value,
        "class TorqueGeneratedJSDataView should be used as direct base for JSDataView.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSDataView(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSDataView(Address ptr);
};

// Alias for IsJSRabGsabDataView() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=133&c=1
V8_EXPORT_PRIVATE bool IsJSRabGsabDataView_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=133&c=1
template <class D, class P>
class TorqueGeneratedJSRabGsabDataView : public P {
  static_assert(
      std::is_same<JSRabGsabDataView, D>::value,
      "Use this class as direct base for JSRabGsabDataView.");
  static_assert(
      std::is_same<JSDataViewOrRabGsabDataView, P>::value,
      "Pass in JSDataViewOrRabGsabDataView as second template parameter for TorqueGeneratedJSRabGsabDataView.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSRabGsabDataView<D,P>;

  DECL_PRINTER(JSRabGsabDataView)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array-buffer.tq?l=133&c=1
  V8_EXPORT_PRIVATE void JSRabGsabDataViewVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSRabGsabDataView() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSRabGsabDataView, DAlias>::value,
        "class TorqueGeneratedJSRabGsabDataView should be used as direct base for JSRabGsabDataView.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSRabGsabDataView(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSRabGsabDataView(Address ptr);
};

