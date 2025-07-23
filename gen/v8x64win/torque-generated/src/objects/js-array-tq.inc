class JSArrayIterator;
class JSArray;
class TemplateLiteralObject;
// Alias for IsJSArrayIterator() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=7&c=1
V8_EXPORT_PRIVATE bool IsJSArrayIterator_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=7&c=1
template <class D, class P>
class TorqueGeneratedJSArrayIterator : public P {
  static_assert(
      std::is_same<JSArrayIterator, D>::value,
      "Use this class as direct base for JSArrayIterator.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSArrayIterator.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSArrayIterator<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=8&c=3
  inline Tagged<JSReceiver> iterated_object() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=8&c=3
  inline Tagged<JSReceiver> iterated_object(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=8&c=3
  inline void set_iterated_object(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=33&c=3
  inline Tagged<Number> next_index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=33&c=3
  inline Tagged<Number> next_index(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=33&c=3
  inline void set_next_index(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=35&c=3
  inline int kind() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=35&c=3
  inline void set_kind(int value);

  DECL_PRINTER(JSArrayIterator)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=7&c=1
  V8_EXPORT_PRIVATE void JSArrayIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=8&c=3
  static constexpr int kIteratedObjectOffset = P::kHeaderSize;
  static constexpr int kIteratedObjectOffsetEnd = kIteratedObjectOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=33&c=3
  static constexpr int kNextIndexOffset = kIteratedObjectOffsetEnd + 1;
  static constexpr int kNextIndexOffsetEnd = kNextIndexOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=35&c=3
  static constexpr int kKindOffset = kNextIndexOffsetEnd + 1;
  static constexpr int kKindOffsetEnd = kKindOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kKindOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kKindOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kKindOffsetEnd + 1;
  static constexpr int kHeaderSize = kKindOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSArrayIterator() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSArrayIterator, DAlias>::value,
        "class TorqueGeneratedJSArrayIterator should be used as direct base for JSArrayIterator.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSArrayIterator(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSArrayIterator(Address ptr);
};

// Alias for IsJSArray() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=61&c=1
V8_EXPORT_PRIVATE bool IsJSArray_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=61&c=1
template <class D, class P>
class TorqueGeneratedJSArray : public P {
  static_assert(
      std::is_same<JSArray, D>::value,
      "Use this class as direct base for JSArray.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSArray.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSArray<D,P>;

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=65&c=3
  inline Tagged<Number> length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=65&c=3
  inline Tagged<Number> length(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=65&c=3
  inline void set_length(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSArray)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=61&c=1
  V8_EXPORT_PRIVATE void JSArrayVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=65&c=3
  static constexpr int kLengthOffset = P::kHeaderSize;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSArray() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSArray, DAlias>::value,
        "class TorqueGeneratedJSArray should be used as direct base for JSArray.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSArray(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSArray(Address ptr);
};

// Alias for IsTemplateLiteralObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=68&c=1
V8_EXPORT_PRIVATE bool IsTemplateLiteralObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=68&c=1
template <class D, class P>
class TorqueGeneratedTemplateLiteralObject : public P {
  static_assert(
      std::is_same<TemplateLiteralObject, D>::value,
      "Use this class as direct base for TemplateLiteralObject.");
  static_assert(
      std::is_same<JSArray, P>::value,
      "Pass in JSArray as second template parameter for TorqueGeneratedTemplateLiteralObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTemplateLiteralObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=71&c=3
  inline Tagged<JSArray> raw() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=71&c=3
  inline Tagged<JSArray> raw(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=71&c=3
  inline void set_raw(Tagged<JSArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=72&c=3
  inline int function_literal_id() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=72&c=3
  inline void set_function_literal_id(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=73&c=3
  inline int slot_id() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=73&c=3
  inline void set_slot_id(int value);

  DECL_PRINTER(TemplateLiteralObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=68&c=1
  V8_EXPORT_PRIVATE void TemplateLiteralObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=71&c=3
  static constexpr int kRawOffset = P::kHeaderSize;
  static constexpr int kRawOffsetEnd = kRawOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=72&c=3
  static constexpr int kFunctionLiteralIdOffset = kRawOffsetEnd + 1;
  static constexpr int kFunctionLiteralIdOffsetEnd = kFunctionLiteralIdOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-array.tq?l=73&c=3
  static constexpr int kSlotIdOffset = kFunctionLiteralIdOffsetEnd + 1;
  static constexpr int kSlotIdOffsetEnd = kSlotIdOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSlotIdOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSlotIdOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSlotIdOffsetEnd + 1;
  static constexpr int kHeaderSize = kSlotIdOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTemplateLiteralObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTemplateLiteralObject, DAlias>::value,
        "class TorqueGeneratedTemplateLiteralObject should be used as direct base for TemplateLiteralObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTemplateLiteralObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTemplateLiteralObject(Address ptr);
};

