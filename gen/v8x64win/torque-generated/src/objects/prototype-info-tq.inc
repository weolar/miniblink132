class PrototypeInfo;
// Alias for IsPrototypeInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=9&c=1
V8_EXPORT_PRIVATE bool IsPrototypeInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=9&c=1
template <class D, class P>
class TorqueGeneratedPrototypeInfo : public P {
  static_assert(
      std::is_same<PrototypeInfo, D>::value,
      "Use this class as direct base for PrototypeInfo.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedPrototypeInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPrototypeInfo<D,P>;

  // Torque type: (class Undefined | class JSModuleNamespace)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=14&c=3
  inline Tagged<Union<JSModuleNamespace, Undefined>> module_namespace() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=14&c=3
  inline Tagged<Union<JSModuleNamespace, Undefined>> module_namespace(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=14&c=3
  inline void set_module_namespace(Tagged<Union<JSModuleNamespace, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Zero | class WeakArrayList)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=18&c=3
  inline Tagged<Union<Smi, WeakArrayList>> prototype_users() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=18&c=3
  inline Tagged<Union<Smi, WeakArrayList>> prototype_users(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=18&c=3
  inline void set_prototype_users(Tagged<Union<Smi, WeakArrayList>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class FixedArray | Zero)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=20&c=3
  inline Tagged<Union<FixedArray, Smi, Undefined>> prototype_chain_enum_cache() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=20&c=3
  inline Tagged<Union<FixedArray, Smi, Undefined>> prototype_chain_enum_cache(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=20&c=3
  inline void set_prototype_chain_enum_cache(Tagged<Union<FixedArray, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=24&c=3
  inline int registry_slot() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=24&c=3
  inline void set_registry_slot(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=26&c=3
  inline int bit_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=26&c=3
  inline void set_bit_field(int value);

  // Torque type: (class Undefined | class WeakArrayList)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=31&c=3
  inline Tagged<Union<Undefined, WeakArrayList>> derived_maps() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=31&c=3
  inline Tagged<Union<Undefined, WeakArrayList>> derived_maps(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=31&c=3
  inline void set_derived_maps(Tagged<Union<Undefined, WeakArrayList>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(PrototypeInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=9&c=1
  V8_EXPORT_PRIVATE void PrototypeInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=14&c=3
  static constexpr int kModuleNamespaceOffset = P::kHeaderSize;
  static constexpr int kModuleNamespaceOffsetEnd = kModuleNamespaceOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=18&c=3
  static constexpr int kPrototypeUsersOffset = kModuleNamespaceOffsetEnd + 1;
  static constexpr int kPrototypeUsersOffsetEnd = kPrototypeUsersOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=20&c=3
  static constexpr int kPrototypeChainEnumCacheOffset = kPrototypeUsersOffsetEnd + 1;
  static constexpr int kPrototypeChainEnumCacheOffsetEnd = kPrototypeChainEnumCacheOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=24&c=3
  static constexpr int kRegistrySlotOffset = kPrototypeChainEnumCacheOffsetEnd + 1;
  static constexpr int kRegistrySlotOffsetEnd = kRegistrySlotOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=26&c=3
  static constexpr int kBitFieldOffset = kRegistrySlotOffsetEnd + 1;
  static constexpr int kBitFieldOffsetEnd = kBitFieldOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=31&c=3
  static constexpr int kDerivedMapsOffset = kBitFieldOffsetEnd + 1;
  static constexpr int kDerivedMapsOffsetEnd = kDerivedMapsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDerivedMapsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDerivedMapsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDerivedMapsOffsetEnd + 1;
  static constexpr int kHeaderSize = kDerivedMapsOffsetEnd + 1;
  static constexpr int kSize = kDerivedMapsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=9&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 28);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/prototype-info.tq?l=9&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPrototypeInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPrototypeInfo, DAlias>::value,
        "class TorqueGeneratedPrototypeInfo should be used as direct base for PrototypeInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPrototypeInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPrototypeInfo(Address ptr);
};

