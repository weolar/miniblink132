class FreeSpace;
// Alias for IsFreeSpace() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsFreeSpace_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedFreeSpace : public P {
  static_assert(
      std::is_same<FreeSpace, D>::value,
      "Use this class as direct base for FreeSpace.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedFreeSpace.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedFreeSpace<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=6&c=3
  inline int size() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=6&c=3
  inline void set_size(int value);

  // Torque type: (Smi | Uninitialized | class FreeSpace)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=7&c=3
  inline Tagged<Union<FreeSpace, MaybeObject, Smi>> next() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=7&c=3
  inline Tagged<Union<FreeSpace, MaybeObject, Smi>> next(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=7&c=3
  inline void set_next(Tagged<Union<FreeSpace, MaybeObject, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(FreeSpace)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=5&c=1
  V8_EXPORT_PRIVATE void FreeSpaceVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=6&c=3
  static constexpr int kSizeOffset = P::kHeaderSize;
  static constexpr int kSizeOffsetEnd = kSizeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSizeOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSizeOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=7&c=3
  static constexpr int kNextOffset = kSizeOffsetEnd + 1;
  static constexpr int kNextOffsetEnd = kNextOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kNextOffsetEnd + 1;
  static constexpr int kHeaderSize = kNextOffsetEnd + 1;
  static constexpr int kSize = kNextOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/free-space.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedFreeSpace() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedFreeSpace, DAlias>::value,
        "class TorqueGeneratedFreeSpace should be used as direct base for FreeSpace.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedFreeSpace(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedFreeSpace(Address ptr);
};

