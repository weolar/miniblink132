class TemplateObjectDescription;
// Alias for IsTemplateObjectDescription() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsTemplateObjectDescription_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedTemplateObjectDescription : public P {
  static_assert(
      std::is_same<TemplateObjectDescription, D>::value,
      "Use this class as direct base for TemplateObjectDescription.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedTemplateObjectDescription.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTemplateObjectDescription<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=6&c=3
  inline Tagged<FixedArray> raw_strings() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=6&c=3
  inline Tagged<FixedArray> raw_strings(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=6&c=3
  inline void set_raw_strings(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=7&c=3
  inline Tagged<FixedArray> cooked_strings() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=7&c=3
  inline Tagged<FixedArray> cooked_strings(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=7&c=3
  inline void set_cooked_strings(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(TemplateObjectDescription)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=5&c=1
  V8_EXPORT_PRIVATE void TemplateObjectDescriptionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=6&c=3
  static constexpr int kRawStringsOffset = P::kHeaderSize;
  static constexpr int kRawStringsOffsetEnd = kRawStringsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=7&c=3
  static constexpr int kCookedStringsOffset = kRawStringsOffsetEnd + 1;
  static constexpr int kCookedStringsOffsetEnd = kCookedStringsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCookedStringsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCookedStringsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCookedStringsOffsetEnd + 1;
  static constexpr int kHeaderSize = kCookedStringsOffsetEnd + 1;
  static constexpr int kSize = kCookedStringsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTemplateObjectDescription() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTemplateObjectDescription, DAlias>::value,
        "class TorqueGeneratedTemplateObjectDescription should be used as direct base for TemplateObjectDescription.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTemplateObjectDescription(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTemplateObjectDescription(Address ptr);
};

