class Foreign;
class TrustedForeign;
// Alias for IsForeign() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsForeign_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedForeign : public P {
  static_assert(
      std::is_same<Foreign, D>::value,
      "Use this class as direct base for Foreign.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedForeign.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedForeign<D,P>;

  DECL_PRINTER(Foreign)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=5&c=1
  V8_EXPORT_PRIVATE void ForeignVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=7&c=3
  static constexpr int kForeignAddressOffset = P::kHeaderSize;
  static constexpr int kForeignAddressOffsetEnd = kForeignAddressOffset + kExternalPointerSlotSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kForeignAddressOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kForeignAddressOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kForeignAddressOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kForeignAddressOffsetEnd + 1;
  static constexpr int kHeaderSize = kForeignAddressOffsetEnd + 1;
  static constexpr int kSize = kForeignAddressOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 8);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedForeign() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedForeign, DAlias>::value,
        "class TorqueGeneratedForeign should be used as direct base for Foreign.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedForeign(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedForeign(Address ptr);
};

// Alias for IsTrustedForeign() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=10&c=1
V8_EXPORT_PRIVATE bool IsTrustedForeign_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=10&c=1
template <class D, class P>
class TorqueGeneratedTrustedForeign : public P {
  static_assert(
      std::is_same<TrustedForeign, D>::value,
      "Use this class as direct base for TrustedForeign.");
  static_assert(
      std::is_same<TrustedObject, P>::value,
      "Pass in TrustedObject as second template parameter for TorqueGeneratedTrustedForeign.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTrustedForeign<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=11&c=3
  inline Address foreign_address() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=11&c=3
  inline void set_foreign_address(Address value);

  DECL_PRINTER(TrustedForeign)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=10&c=1
  V8_EXPORT_PRIVATE void TrustedForeignVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=11&c=3
  static constexpr int kForeignAddressOffset = P::kHeaderSize;
  static constexpr int kForeignAddressOffsetEnd = kForeignAddressOffset + kSystemPointerSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kForeignAddressOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kForeignAddressOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kForeignAddressOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kForeignAddressOffsetEnd + 1;
  static constexpr int kHeaderSize = kForeignAddressOffsetEnd + 1;
  static constexpr int kSize = kForeignAddressOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=10&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 8);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=10&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTrustedForeign() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTrustedForeign, DAlias>::value,
        "class TorqueGeneratedTrustedForeign should be used as direct base for TrustedForeign.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTrustedForeign(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTrustedForeign(Address ptr);
};

