class EnumCache;
class DescriptorArray;
// Alias for IsEnumCache() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsEnumCache_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedEnumCache : public P {
  static_assert(
      std::is_same<EnumCache, D>::value,
      "Use this class as direct base for EnumCache.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedEnumCache.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedEnumCache<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
  inline Tagged<FixedArray> keys() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
  inline Tagged<FixedArray> keys(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
  inline void set_keys(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
  inline Tagged<FixedArray> indices() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
  inline Tagged<FixedArray> indices(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
  inline void set_indices(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(EnumCache)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=5&c=1
  V8_EXPORT_PRIVATE void EnumCacheVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=6&c=3
  static constexpr int kKeysOffset = P::kHeaderSize;
  static constexpr int kKeysOffsetEnd = kKeysOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=7&c=3
  static constexpr int kIndicesOffset = kKeysOffsetEnd + 1;
  static constexpr int kIndicesOffsetEnd = kIndicesOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIndicesOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIndicesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIndicesOffsetEnd + 1;
  static constexpr int kHeaderSize = kIndicesOffsetEnd + 1;
  static constexpr int kSize = kIndicesOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedEnumCache() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedEnumCache, DAlias>::value,
        "class TorqueGeneratedEnumCache should be used as direct base for EnumCache.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedEnumCache(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedEnumCache(Address ptr);
};

// Alias for IsDescriptorArray() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=18&c=1
V8_EXPORT_PRIVATE bool IsDescriptorArray_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=18&c=1
template <class D, class P>
class TorqueGeneratedDescriptorArray : public P {
  static_assert(
      std::is_same<DescriptorArray, D>::value,
      "Use this class as direct base for DescriptorArray.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedDescriptorArray.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedDescriptorArray<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=21&c=9
  inline uint16_t number_of_all_descriptors() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=21&c=9
  inline void set_number_of_all_descriptors(uint16_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=22&c=3
  inline uint16_t number_of_descriptors() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=22&c=3
  inline void set_number_of_descriptors(uint16_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=25&c=3
  inline uint32_t raw_gc_state() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=25&c=3
  inline void set_raw_gc_state(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
  inline Tagged<EnumCache> enum_cache() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
  inline Tagged<EnumCache> enum_cache(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
  inline void set_enum_cache(Tagged<EnumCache> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class Name)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline Tagged<Union<Name, Undefined>> descriptors_key(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline Tagged<Union<Name, Undefined>> descriptors_key(PtrComprCageBase cage_base, int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline void set_descriptors_key(int i, Tagged<Union<Name, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Smi)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline Tagged<Union<Smi, Undefined>> descriptors_details(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline Tagged<Union<Smi, Undefined>> descriptors_details(PtrComprCageBase cage_base, int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline void set_descriptors_details(int i, Tagged<Union<Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class JSReceiver | class Undefined | class Null | class Boolean | class Symbol | class String | BigInt | class HeapNumber | Smi | class NumberDictionary | class AccessorInfo | class ClassPositions | class AccessorPair | Weak<class Map>)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline Tagged<Union<AccessorInfo, AccessorPair, BigInt, Boolean, ClassPositions, HeapNumber, JSReceiver, MaybeObject, Null, NumberDictionary, Smi, String, Symbol, Undefined>> descriptors_value(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline Tagged<Union<AccessorInfo, AccessorPair, BigInt, Boolean, ClassPositions, HeapNumber, JSReceiver, MaybeObject, Null, NumberDictionary, Smi, String, Symbol, Undefined>> descriptors_value(PtrComprCageBase cage_base, int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  inline void set_descriptors_value(int i, Tagged<Union<AccessorInfo, AccessorPair, BigInt, Boolean, ClassPositions, HeapNumber, JSReceiver, MaybeObject, Null, NumberDictionary, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(DescriptorArray)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=18&c=1
  V8_EXPORT_PRIVATE void DescriptorArrayVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=21&c=9
  static constexpr int kNumberOfAllDescriptorsOffset = P::kHeaderSize;
  static constexpr int kNumberOfAllDescriptorsOffsetEnd = kNumberOfAllDescriptorsOffset + kUInt16Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=22&c=3
  static constexpr int kNumberOfDescriptorsOffset = kNumberOfAllDescriptorsOffsetEnd + 1;
  static constexpr int kNumberOfDescriptorsOffsetEnd = kNumberOfDescriptorsOffset + kUInt16Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=25&c=3
  static constexpr int kRawGcStateOffset = kNumberOfDescriptorsOffsetEnd + 1;
  static constexpr int kRawGcStateOffsetEnd = kRawGcStateOffset + kInt32Size - 1;
  static constexpr int kStartOfStrongFieldsOffset = kRawGcStateOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=26&c=3
  static constexpr int kEnumCacheOffset = kRawGcStateOffsetEnd + 1;
  static constexpr int kEnumCacheOffsetEnd = kEnumCacheOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kEnumCacheOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kEnumCacheOffsetEnd + 1;
  static constexpr int kHeaderSize = kEnumCacheOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
  static constexpr int kDescriptorsOffset = kEnumCacheOffsetEnd + 1;
  static constexpr int kDescriptorsOffsetEnd = kDescriptorsOffset + 0 - 1;
  static constexpr int kEndOfWeakFieldsOffset = kDescriptorsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=18&c=1
  V8_INLINE static constexpr int32_t SizeFor(int number_of_all_descriptors) {
    int32_t size = kHeaderSize;
    size += number_of_all_descriptors * 12;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=18&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->number_of_all_descriptors());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedDescriptorArray() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedDescriptorArray, DAlias>::value,
        "class TorqueGeneratedDescriptorArray should be used as direct base for DescriptorArray.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedDescriptorArray(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedDescriptorArray(Address ptr);
};

struct TorqueGeneratedDescriptorEntryOffsets {
  static constexpr int kKeyOffset = 0;
  static constexpr int kDetailsOffset = 4;
  static constexpr int kValueOffset = 8;
  static constexpr int kSize = 12;
};

