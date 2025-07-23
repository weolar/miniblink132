class AlwaysSharedSpaceJSObject;
class JSSharedStruct;
// Alias for IsAlwaysSharedSpaceJSObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-struct.tq?l=8&c=1
V8_EXPORT_PRIVATE bool IsAlwaysSharedSpaceJSObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-struct.tq?l=8&c=1
template <class D, class P>
class TorqueGeneratedAlwaysSharedSpaceJSObject : public P {
  static_assert(
      std::is_same<AlwaysSharedSpaceJSObject, D>::value,
      "Use this class as direct base for AlwaysSharedSpaceJSObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedAlwaysSharedSpaceJSObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAlwaysSharedSpaceJSObject<D,P>;

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-struct.tq?l=8&c=1
  V8_EXPORT_PRIVATE void AlwaysSharedSpaceJSObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAlwaysSharedSpaceJSObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAlwaysSharedSpaceJSObject, DAlias>::value,
        "class TorqueGeneratedAlwaysSharedSpaceJSObject should be used as direct base for AlwaysSharedSpaceJSObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAlwaysSharedSpaceJSObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAlwaysSharedSpaceJSObject(Address ptr);
};

// Alias for IsJSSharedStruct() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-struct.tq?l=11&c=1
V8_EXPORT_PRIVATE bool IsJSSharedStruct_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-struct.tq?l=11&c=1
template <class D, class P>
class TorqueGeneratedJSSharedStruct : public P {
  static_assert(
      std::is_same<JSSharedStruct, D>::value,
      "Use this class as direct base for JSSharedStruct.");
  static_assert(
      std::is_same<AlwaysSharedSpaceJSObject, P>::value,
      "Pass in AlwaysSharedSpaceJSObject as second template parameter for TorqueGeneratedJSSharedStruct.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSharedStruct<D,P>;

  DECL_PRINTER(JSSharedStruct)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-struct.tq?l=11&c=1
  V8_EXPORT_PRIVATE void JSSharedStructVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSharedStruct() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSharedStruct, DAlias>::value,
        "class TorqueGeneratedJSSharedStruct should be used as direct base for JSSharedStruct.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSharedStruct(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSharedStruct(Address ptr);
};

