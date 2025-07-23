class JSDateTimeFormat;
// Alias for IsJSDateTimeFormat() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=16&c=1
V8_EXPORT_PRIVATE bool IsJSDateTimeFormat_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=16&c=1
template <class D, class P>
class TorqueGeneratedJSDateTimeFormat : public P {
  static_assert(
      std::is_same<JSDateTimeFormat, D>::value,
      "Use this class as direct base for JSDateTimeFormat.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSDateTimeFormat.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSDateTimeFormat<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=17&c=3
  inline Tagged<String> locale() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=17&c=3
  inline Tagged<String> locale(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=17&c=3
  inline void set_locale(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=18&c=3
  inline Tagged<Foreign> icu_locale() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=18&c=3
  inline Tagged<Foreign> icu_locale(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=18&c=3
  inline void set_icu_locale(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=19&c=3
  inline Tagged<Foreign> icu_simple_date_format() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=19&c=3
  inline Tagged<Foreign> icu_simple_date_format(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=19&c=3
  inline void set_icu_simple_date_format(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=20&c=3
  inline Tagged<Foreign> icu_date_interval_format() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=20&c=3
  inline Tagged<Foreign> icu_date_interval_format(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=20&c=3
  inline void set_icu_date_interval_format(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=21&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_format() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=21&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_format(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=21&c=3
  inline void set_bound_format(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=22&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=22&c=3
  inline void set_flags(int value);

  DECL_PRINTER(JSDateTimeFormat)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=16&c=1
  V8_EXPORT_PRIVATE void JSDateTimeFormatVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=17&c=3
  static constexpr int kLocaleOffset = P::kHeaderSize;
  static constexpr int kLocaleOffsetEnd = kLocaleOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=18&c=3
  static constexpr int kIcuLocaleOffset = kLocaleOffsetEnd + 1;
  static constexpr int kIcuLocaleOffsetEnd = kIcuLocaleOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=19&c=3
  static constexpr int kIcuSimpleDateFormatOffset = kIcuLocaleOffsetEnd + 1;
  static constexpr int kIcuSimpleDateFormatOffsetEnd = kIcuSimpleDateFormatOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=20&c=3
  static constexpr int kIcuDateIntervalFormatOffset = kIcuSimpleDateFormatOffsetEnd + 1;
  static constexpr int kIcuDateIntervalFormatOffsetEnd = kIcuDateIntervalFormatOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=21&c=3
  static constexpr int kBoundFormatOffset = kIcuDateIntervalFormatOffsetEnd + 1;
  static constexpr int kBoundFormatOffsetEnd = kBoundFormatOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=22&c=3
  static constexpr int kFlagsOffset = kBoundFormatOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSDateTimeFormat() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSDateTimeFormat, DAlias>::value,
        "class TorqueGeneratedJSDateTimeFormat should be used as direct base for JSDateTimeFormat.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSDateTimeFormat(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSDateTimeFormat(Address ptr);
};

