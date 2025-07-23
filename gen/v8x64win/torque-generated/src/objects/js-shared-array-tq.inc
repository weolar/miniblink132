class JSSharedArray;
// Alias for IsJSSharedArray() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-shared-array.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsJSSharedArray_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-shared-array.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedJSSharedArray : public P {
  static_assert(
      std::is_same<JSSharedArray, D>::value,
      "Use this class as direct base for JSSharedArray.");
  static_assert(
      std::is_same<AlwaysSharedSpaceJSObject, P>::value,
      "Pass in AlwaysSharedSpaceJSObject as second template parameter for TorqueGeneratedJSSharedArray.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSharedArray<D,P>;

  DECL_PRINTER(JSSharedArray)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-shared-array.tq?l=5&c=1
  V8_EXPORT_PRIVATE void JSSharedArrayVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSharedArray() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSharedArray, DAlias>::value,
        "class TorqueGeneratedJSSharedArray should be used as direct base for JSSharedArray.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSharedArray(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSharedArray(Address ptr);
};

