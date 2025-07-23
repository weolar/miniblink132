class JSDurationFormat;
// Alias for IsJSDurationFormat() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=43&c=1
V8_EXPORT_PRIVATE bool IsJSDurationFormat_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=43&c=1
template <class D, class P>
class TorqueGeneratedJSDurationFormat : public P {
  static_assert(
      std::is_same<JSDurationFormat, D>::value,
      "Use this class as direct base for JSDurationFormat.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSDurationFormat.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSDurationFormat<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=44&c=3
  inline int style_flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=44&c=3
  inline void set_style_flags(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=45&c=3
  inline int display_flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=45&c=3
  inline void set_display_flags(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=46&c=3
  inline Tagged<Foreign> icu_locale() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=46&c=3
  inline Tagged<Foreign> icu_locale(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=46&c=3
  inline void set_icu_locale(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=47&c=3
  inline Tagged<Foreign> icu_number_formatter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=47&c=3
  inline Tagged<Foreign> icu_number_formatter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=47&c=3
  inline void set_icu_number_formatter(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSDurationFormat)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=43&c=1
  V8_EXPORT_PRIVATE void JSDurationFormatVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=44&c=3
  static constexpr int kStyleFlagsOffset = P::kHeaderSize;
  static constexpr int kStyleFlagsOffsetEnd = kStyleFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=45&c=3
  static constexpr int kDisplayFlagsOffset = kStyleFlagsOffsetEnd + 1;
  static constexpr int kDisplayFlagsOffsetEnd = kDisplayFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=46&c=3
  static constexpr int kIcuLocaleOffset = kDisplayFlagsOffsetEnd + 1;
  static constexpr int kIcuLocaleOffsetEnd = kIcuLocaleOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-duration-format.tq?l=47&c=3
  static constexpr int kIcuNumberFormatterOffset = kIcuLocaleOffsetEnd + 1;
  static constexpr int kIcuNumberFormatterOffsetEnd = kIcuNumberFormatterOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIcuNumberFormatterOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIcuNumberFormatterOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIcuNumberFormatterOffsetEnd + 1;
  static constexpr int kHeaderSize = kIcuNumberFormatterOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSDurationFormat() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSDurationFormat, DAlias>::value,
        "class TorqueGeneratedJSDurationFormat should be used as direct base for JSDurationFormat.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSDurationFormat(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSDurationFormat(Address ptr);
};

