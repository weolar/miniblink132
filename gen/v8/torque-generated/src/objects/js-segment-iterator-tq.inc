class JSSegmentIterator;
class JSSegmentDataObject;
class JSSegmentDataObjectWithIsWordLike;
// Alias for IsJSSegmentIterator() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=11&c=1
V8_EXPORT_PRIVATE bool IsJSSegmentIterator_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=11&c=1
template <class D, class P>
class TorqueGeneratedJSSegmentIterator : public P {
  static_assert(
      std::is_same<JSSegmentIterator, D>::value,
      "Use this class as direct base for JSSegmentIterator.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSSegmentIterator.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSegmentIterator<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=12&c=3
  inline Tagged<Foreign> icu_break_iterator() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=12&c=3
  inline Tagged<Foreign> icu_break_iterator(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=12&c=3
  inline void set_icu_break_iterator(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=13&c=3
  inline Tagged<String> raw_string() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=13&c=3
  inline Tagged<String> raw_string(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=13&c=3
  inline void set_raw_string(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=14&c=3
  inline Tagged<Foreign> unicode_string() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=14&c=3
  inline Tagged<Foreign> unicode_string(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=14&c=3
  inline void set_unicode_string(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=15&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=15&c=3
  inline void set_flags(int value);

  DECL_PRINTER(JSSegmentIterator)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=11&c=1
  V8_EXPORT_PRIVATE void JSSegmentIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=12&c=3
  static constexpr int kIcuBreakIteratorOffset = P::kHeaderSize;
  static constexpr int kIcuBreakIteratorOffsetEnd = kIcuBreakIteratorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=13&c=3
  static constexpr int kRawStringOffset = kIcuBreakIteratorOffsetEnd + 1;
  static constexpr int kRawStringOffsetEnd = kRawStringOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=14&c=3
  static constexpr int kUnicodeStringOffset = kRawStringOffsetEnd + 1;
  static constexpr int kUnicodeStringOffsetEnd = kUnicodeStringOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=15&c=3
  static constexpr int kFlagsOffset = kUnicodeStringOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSegmentIterator() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSegmentIterator, DAlias>::value,
        "class TorqueGeneratedJSSegmentIterator should be used as direct base for JSSegmentIterator.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSegmentIterator(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSegmentIterator(Address ptr);
};

// Alias for IsJSSegmentDataObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=18&c=1
V8_EXPORT_PRIVATE bool IsJSSegmentDataObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=18&c=1
template <class D, class P>
class TorqueGeneratedJSSegmentDataObject : public P {
  static_assert(
      std::is_same<JSSegmentDataObject, D>::value,
      "Use this class as direct base for JSSegmentDataObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSSegmentDataObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSegmentDataObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=21&c=3
  inline Tagged<String> segment() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=21&c=3
  inline Tagged<String> segment(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=21&c=3
  inline void set_segment(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=22&c=3
  inline Tagged<Number> index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=22&c=3
  inline Tagged<Number> index(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=22&c=3
  inline void set_index(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=23&c=3
  inline Tagged<String> input() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=23&c=3
  inline Tagged<String> input(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=23&c=3
  inline void set_input(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSSegmentDataObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=18&c=1
  V8_EXPORT_PRIVATE void JSSegmentDataObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=21&c=3
  static constexpr int kSegmentOffset = P::kHeaderSize;
  static constexpr int kSegmentOffsetEnd = kSegmentOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=22&c=3
  static constexpr int kIndexOffset = kSegmentOffsetEnd + 1;
  static constexpr int kIndexOffsetEnd = kIndexOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=23&c=3
  static constexpr int kInputOffset = kIndexOffsetEnd + 1;
  static constexpr int kInputOffsetEnd = kInputOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kInputOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kInputOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kInputOffsetEnd + 1;
  static constexpr int kHeaderSize = kInputOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSegmentDataObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSegmentDataObject, DAlias>::value,
        "class TorqueGeneratedJSSegmentDataObject should be used as direct base for JSSegmentDataObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSegmentDataObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSegmentDataObject(Address ptr);
};

// Alias for IsJSSegmentDataObjectWithIsWordLike() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=26&c=1
V8_EXPORT_PRIVATE bool IsJSSegmentDataObjectWithIsWordLike_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=26&c=1
template <class D, class P>
class TorqueGeneratedJSSegmentDataObjectWithIsWordLike : public P {
  static_assert(
      std::is_same<JSSegmentDataObjectWithIsWordLike, D>::value,
      "Use this class as direct base for JSSegmentDataObjectWithIsWordLike.");
  static_assert(
      std::is_same<JSSegmentDataObject, P>::value,
      "Pass in JSSegmentDataObject as second template parameter for TorqueGeneratedJSSegmentDataObjectWithIsWordLike.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSegmentDataObjectWithIsWordLike<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=29&c=3
  inline Tagged<Boolean> is_word_like() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=29&c=3
  inline Tagged<Boolean> is_word_like(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=29&c=3
  inline void set_is_word_like(Tagged<Boolean> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSSegmentDataObjectWithIsWordLike)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=26&c=1
  V8_EXPORT_PRIVATE void JSSegmentDataObjectWithIsWordLikeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segment-iterator.tq?l=29&c=3
  static constexpr int kIsWordLikeOffset = P::kHeaderSize;
  static constexpr int kIsWordLikeOffsetEnd = kIsWordLikeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIsWordLikeOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIsWordLikeOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIsWordLikeOffsetEnd + 1;
  static constexpr int kHeaderSize = kIsWordLikeOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSegmentDataObjectWithIsWordLike() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSegmentDataObjectWithIsWordLike, DAlias>::value,
        "class TorqueGeneratedJSSegmentDataObjectWithIsWordLike should be used as direct base for JSSegmentDataObjectWithIsWordLike.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSegmentDataObjectWithIsWordLike(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSegmentDataObjectWithIsWordLike(Address ptr);
};

