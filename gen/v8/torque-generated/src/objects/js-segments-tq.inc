class JSSegments;
// Alias for IsJSSegments() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=11&c=1
V8_EXPORT_PRIVATE bool IsJSSegments_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=11&c=1
template <class D, class P>
class TorqueGeneratedJSSegments : public P {
  static_assert(
      std::is_same<JSSegments, D>::value,
      "Use this class as direct base for JSSegments.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSSegments.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSegments<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=12&c=3
  inline Tagged<Foreign> icu_break_iterator() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=12&c=3
  inline Tagged<Foreign> icu_break_iterator(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=12&c=3
  inline void set_icu_break_iterator(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=13&c=3
  inline Tagged<String> raw_string() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=13&c=3
  inline Tagged<String> raw_string(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=13&c=3
  inline void set_raw_string(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=14&c=3
  inline Tagged<Foreign> unicode_string() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=14&c=3
  inline Tagged<Foreign> unicode_string(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=14&c=3
  inline void set_unicode_string(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=15&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=15&c=3
  inline void set_flags(int value);

  DECL_PRINTER(JSSegments)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=11&c=1
  V8_EXPORT_PRIVATE void JSSegmentsVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=12&c=3
  static constexpr int kIcuBreakIteratorOffset = P::kHeaderSize;
  static constexpr int kIcuBreakIteratorOffsetEnd = kIcuBreakIteratorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=13&c=3
  static constexpr int kRawStringOffset = kIcuBreakIteratorOffsetEnd + 1;
  static constexpr int kRawStringOffsetEnd = kRawStringOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=14&c=3
  static constexpr int kUnicodeStringOffset = kRawStringOffsetEnd + 1;
  static constexpr int kUnicodeStringOffsetEnd = kUnicodeStringOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-segments.tq?l=15&c=3
  static constexpr int kFlagsOffset = kUnicodeStringOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSegments() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSegments, DAlias>::value,
        "class TorqueGeneratedJSSegments should be used as direct base for JSSegments.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSegments(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSegments(Address ptr);
};

