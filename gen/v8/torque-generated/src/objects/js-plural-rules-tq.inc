class JSPluralRules;
// Alias for IsJSPluralRules() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=12&c=1
V8_EXPORT_PRIVATE bool IsJSPluralRules_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=12&c=1
template <class D, class P>
class TorqueGeneratedJSPluralRules : public P {
  static_assert(
      std::is_same<JSPluralRules, D>::value,
      "Use this class as direct base for JSPluralRules.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSPluralRules.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSPluralRules<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=13&c=3
  inline Tagged<String> locale() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=13&c=3
  inline Tagged<String> locale(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=13&c=3
  inline void set_locale(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=14&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=14&c=3
  inline void set_flags(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=15&c=3
  inline Tagged<Foreign> icu_plural_rules() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=15&c=3
  inline Tagged<Foreign> icu_plural_rules(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=15&c=3
  inline void set_icu_plural_rules(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=16&c=3
  inline Tagged<Foreign> icu_number_formatter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=16&c=3
  inline Tagged<Foreign> icu_number_formatter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=16&c=3
  inline void set_icu_number_formatter(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSPluralRules)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=12&c=1
  V8_EXPORT_PRIVATE void JSPluralRulesVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=13&c=3
  static constexpr int kLocaleOffset = P::kHeaderSize;
  static constexpr int kLocaleOffsetEnd = kLocaleOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=14&c=3
  static constexpr int kFlagsOffset = kLocaleOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=15&c=3
  static constexpr int kIcuPluralRulesOffset = kFlagsOffsetEnd + 1;
  static constexpr int kIcuPluralRulesOffsetEnd = kIcuPluralRulesOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-plural-rules.tq?l=16&c=3
  static constexpr int kIcuNumberFormatterOffset = kIcuPluralRulesOffsetEnd + 1;
  static constexpr int kIcuNumberFormatterOffsetEnd = kIcuNumberFormatterOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIcuNumberFormatterOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIcuNumberFormatterOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIcuNumberFormatterOffsetEnd + 1;
  static constexpr int kHeaderSize = kIcuNumberFormatterOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSPluralRules() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSPluralRules, DAlias>::value,
        "class TorqueGeneratedJSPluralRules should be used as direct base for JSPluralRules.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSPluralRules(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSPluralRules(Address ptr);
};

