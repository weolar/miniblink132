class JSRawJson;
// Alias for IsJSRawJson() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-raw-json.tq?l=7&c=1
V8_EXPORT_PRIVATE bool IsJSRawJson_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-raw-json.tq?l=7&c=1
template <class D, class P>
class TorqueGeneratedJSRawJson : public P {
  static_assert(
      std::is_same<JSRawJson, D>::value,
      "Use this class as direct base for JSRawJson.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSRawJson.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSRawJson<D,P>;

  DECL_PRINTER(JSRawJson)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-raw-json.tq?l=7&c=1
  V8_EXPORT_PRIVATE void JSRawJsonVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSRawJson() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSRawJson, DAlias>::value,
        "class TorqueGeneratedJSRawJson should be used as direct base for JSRawJson.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSRawJson(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSRawJson(Address ptr);
};

