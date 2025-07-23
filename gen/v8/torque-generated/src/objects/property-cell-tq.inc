class PropertyCell;
class ContextSidePropertyCell;
// Alias for IsPropertyCell() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=6&c=1
V8_EXPORT_PRIVATE bool IsPropertyCell_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=6&c=1
template <class D, class P>
class TorqueGeneratedPropertyCell : public P {
  static_assert(
      std::is_same<PropertyCell, D>::value,
      "Use this class as direct base for PropertyCell.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedPropertyCell.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPropertyCell<D,P>;

  // Torque type: AnyName
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
  inline Tagged<Union<String, Symbol>> name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
  inline Tagged<Union<String, Symbol>> name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
  inline void set_name(Tagged<Union<String, Symbol>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=8&c=3
  inline int property_details_raw() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=8&c=3
  inline void set_property_details_raw(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
  inline Tagged<Object> value() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
  inline Tagged<Object> value(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
  inline void set_value(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: DependentCode
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
  inline Tagged<WeakArrayList> dependent_code() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
  inline Tagged<WeakArrayList> dependent_code(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
  inline void set_dependent_code(Tagged<WeakArrayList> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(PropertyCell)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=6&c=1
  V8_EXPORT_PRIVATE void PropertyCellVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=7&c=3
  static constexpr int kNameOffset = P::kHeaderSize;
  static constexpr int kNameOffsetEnd = kNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=8&c=3
  static constexpr int kPropertyDetailsRawOffset = kNameOffsetEnd + 1;
  static constexpr int kPropertyDetailsRawOffsetEnd = kPropertyDetailsRawOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=9&c=3
  static constexpr int kValueOffset = kPropertyDetailsRawOffsetEnd + 1;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=10&c=3
  static constexpr int kDependentCodeOffset = kValueOffsetEnd + 1;
  static constexpr int kDependentCodeOffsetEnd = kDependentCodeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDependentCodeOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDependentCodeOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDependentCodeOffsetEnd + 1;
  static constexpr int kHeaderSize = kDependentCodeOffsetEnd + 1;
  static constexpr int kSize = kDependentCodeOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=6&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 20);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=6&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPropertyCell() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPropertyCell, DAlias>::value,
        "class TorqueGeneratedPropertyCell should be used as direct base for PropertyCell.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPropertyCell(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPropertyCell(Address ptr);
};

// Alias for IsContextSidePropertyCell() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=14&c=1
V8_EXPORT_PRIVATE bool IsContextSidePropertyCell_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=14&c=1
template <class D, class P>
class TorqueGeneratedContextSidePropertyCell : public P {
  static_assert(
      std::is_same<ContextSidePropertyCell, D>::value,
      "Use this class as direct base for ContextSidePropertyCell.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedContextSidePropertyCell.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedContextSidePropertyCell<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=15&c=3
  inline int property_details_raw() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=15&c=3
  inline void set_property_details_raw(int value);

  // Torque type: DependentCode
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
  inline Tagged<WeakArrayList> dependent_code() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
  inline Tagged<WeakArrayList> dependent_code(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
  inline void set_dependent_code(Tagged<WeakArrayList> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(ContextSidePropertyCell)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=14&c=1
  V8_EXPORT_PRIVATE void ContextSidePropertyCellVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=15&c=3
  static constexpr int kPropertyDetailsRawOffset = P::kHeaderSize;
  static constexpr int kPropertyDetailsRawOffsetEnd = kPropertyDetailsRawOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=16&c=3
  static constexpr int kDependentCodeOffset = kPropertyDetailsRawOffsetEnd + 1;
  static constexpr int kDependentCodeOffsetEnd = kDependentCodeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDependentCodeOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDependentCodeOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDependentCodeOffsetEnd + 1;
  static constexpr int kHeaderSize = kDependentCodeOffsetEnd + 1;
  static constexpr int kSize = kDependentCodeOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=14&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-cell.tq?l=14&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedContextSidePropertyCell() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedContextSidePropertyCell, DAlias>::value,
        "class TorqueGeneratedContextSidePropertyCell should be used as direct base for ContextSidePropertyCell.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedContextSidePropertyCell(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedContextSidePropertyCell(Address ptr);
};

