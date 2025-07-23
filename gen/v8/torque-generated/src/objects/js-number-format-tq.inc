class JSNumberFormat;
// Alias for IsJSNumberFormat() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=7&c=1
V8_EXPORT_PRIVATE bool IsJSNumberFormat_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=7&c=1
template <class D, class P>
class TorqueGeneratedJSNumberFormat : public P {
  static_assert(
      std::is_same<JSNumberFormat, D>::value,
      "Use this class as direct base for JSNumberFormat.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSNumberFormat.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSNumberFormat<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=8&c=3
  inline Tagged<String> locale() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=8&c=3
  inline Tagged<String> locale(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=8&c=3
  inline void set_locale(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=9&c=3
  inline Tagged<Foreign> icu_number_formatter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=9&c=3
  inline Tagged<Foreign> icu_number_formatter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=9&c=3
  inline void set_icu_number_formatter(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=11&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_format() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=11&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_format(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=11&c=3
  inline void set_bound_format(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSNumberFormat)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=7&c=1
  V8_EXPORT_PRIVATE void JSNumberFormatVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=8&c=3
  static constexpr int kLocaleOffset = P::kHeaderSize;
  static constexpr int kLocaleOffsetEnd = kLocaleOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=9&c=3
  static constexpr int kIcuNumberFormatterOffset = kLocaleOffsetEnd + 1;
  static constexpr int kIcuNumberFormatterOffsetEnd = kIcuNumberFormatterOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-number-format.tq?l=11&c=3
  static constexpr int kBoundFormatOffset = kIcuNumberFormatterOffsetEnd + 1;
  static constexpr int kBoundFormatOffsetEnd = kBoundFormatOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBoundFormatOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBoundFormatOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBoundFormatOffsetEnd + 1;
  static constexpr int kHeaderSize = kBoundFormatOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSNumberFormat() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSNumberFormat, DAlias>::value,
        "class TorqueGeneratedJSNumberFormat should be used as direct base for JSNumberFormat.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSNumberFormat(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSNumberFormat(Address ptr);
};

