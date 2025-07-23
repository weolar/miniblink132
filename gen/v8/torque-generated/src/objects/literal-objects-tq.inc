class ArrayBoilerplateDescription;
// Alias for IsArrayBoilerplateDescription() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=1
V8_EXPORT_PRIVATE bool IsArrayBoilerplateDescription_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=1
template <class D, class P>
class TorqueGeneratedArrayBoilerplateDescription : public P {
  static_assert(
      std::is_same<ArrayBoilerplateDescription, D>::value,
      "Use this class as direct base for ArrayBoilerplateDescription.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedArrayBoilerplateDescription.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedArrayBoilerplateDescription<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=14&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=14&c=3
  inline void set_flags(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
  inline Tagged<FixedArrayBase> constant_elements() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
  inline Tagged<FixedArrayBase> constant_elements(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
  inline void set_constant_elements(Tagged<FixedArrayBase> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(ArrayBoilerplateDescription)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=1
  V8_EXPORT_PRIVATE void ArrayBoilerplateDescriptionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=14&c=3
  static constexpr int kFlagsOffset = P::kHeaderSize;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=15&c=3
  static constexpr int kConstantElementsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kConstantElementsOffsetEnd = kConstantElementsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kHeaderSize = kConstantElementsOffsetEnd + 1;
  static constexpr int kSize = kConstantElementsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedArrayBoilerplateDescription() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedArrayBoilerplateDescription, DAlias>::value,
        "class TorqueGeneratedArrayBoilerplateDescription should be used as direct base for ArrayBoilerplateDescription.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedArrayBoilerplateDescription(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedArrayBoilerplateDescription(Address ptr);
};

