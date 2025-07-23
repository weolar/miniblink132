class AllocationMemento;
// Alias for IsAllocationMemento() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=7&c=1
V8_EXPORT_PRIVATE bool IsAllocationMemento_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=7&c=1
template <class D, class P>
class TorqueGeneratedAllocationMemento : public P {
  static_assert(
      std::is_same<AllocationMemento, D>::value,
      "Use this class as direct base for AllocationMemento.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedAllocationMemento.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAllocationMemento<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=8&c=3
  inline Tagged<AllocationSite> allocation_site() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=8&c=3
  inline Tagged<AllocationSite> allocation_site(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=8&c=3
  inline void set_allocation_site(Tagged<AllocationSite> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(AllocationMemento)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=7&c=1
  V8_EXPORT_PRIVATE void AllocationMementoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=8&c=3
  static constexpr int kAllocationSiteOffset = P::kHeaderSize;
  static constexpr int kAllocationSiteOffsetEnd = kAllocationSiteOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kAllocationSiteOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kAllocationSiteOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kAllocationSiteOffsetEnd + 1;
  static constexpr int kHeaderSize = kAllocationSiteOffsetEnd + 1;
  static constexpr int kSize = kAllocationSiteOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=7&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 8);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=7&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAllocationMemento() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAllocationMemento, DAlias>::value,
        "class TorqueGeneratedAllocationMemento should be used as direct base for AllocationMemento.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAllocationMemento(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAllocationMemento(Address ptr);
};

