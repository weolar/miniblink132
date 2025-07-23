class InterceptorInfo;
class AccessCheckInfo;
class AccessorInfo;
// Alias for IsInterceptorInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=13&c=1
V8_EXPORT_PRIVATE bool IsInterceptorInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=13&c=1
template <class D, class P>
class TorqueGeneratedInterceptorInfo : public P {
  static_assert(
      std::is_same<InterceptorInfo, D>::value,
      "Use this class as direct base for InterceptorInfo.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedInterceptorInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedInterceptorInfo<D,P>;

  // Torque type: (class Undefined | Zero | NonNullForeign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=14&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> getter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=14&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> getter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=14&c=3
  inline void set_getter(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Zero | NonNullForeign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=15&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> setter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=15&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> setter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=15&c=3
  inline void set_setter(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Zero | NonNullForeign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=16&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> query() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=16&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> query(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=16&c=3
  inline void set_query(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Zero | NonNullForeign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=17&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> descriptor() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=17&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> descriptor(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=17&c=3
  inline void set_descriptor(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Zero | NonNullForeign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=18&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> deleter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=18&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> deleter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=18&c=3
  inline void set_deleter(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Zero | NonNullForeign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=19&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> enumerator() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=19&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> enumerator(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=19&c=3
  inline void set_enumerator(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Zero | NonNullForeign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=20&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> definer() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=20&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> definer(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=20&c=3
  inline void set_definer(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=21&c=3
  inline Tagged<Object> data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=21&c=3
  inline Tagged<Object> data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=21&c=3
  inline void set_data(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=22&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=22&c=3
  inline void set_flags(int value);

  DECL_PRINTER(InterceptorInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=13&c=1
  V8_EXPORT_PRIVATE void InterceptorInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=14&c=3
  static constexpr int kGetterOffset = P::kHeaderSize;
  static constexpr int kGetterOffsetEnd = kGetterOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=15&c=3
  static constexpr int kSetterOffset = kGetterOffsetEnd + 1;
  static constexpr int kSetterOffsetEnd = kSetterOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=16&c=3
  static constexpr int kQueryOffset = kSetterOffsetEnd + 1;
  static constexpr int kQueryOffsetEnd = kQueryOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=17&c=3
  static constexpr int kDescriptorOffset = kQueryOffsetEnd + 1;
  static constexpr int kDescriptorOffsetEnd = kDescriptorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=18&c=3
  static constexpr int kDeleterOffset = kDescriptorOffsetEnd + 1;
  static constexpr int kDeleterOffsetEnd = kDeleterOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=19&c=3
  static constexpr int kEnumeratorOffset = kDeleterOffsetEnd + 1;
  static constexpr int kEnumeratorOffsetEnd = kEnumeratorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=20&c=3
  static constexpr int kDefinerOffset = kEnumeratorOffsetEnd + 1;
  static constexpr int kDefinerOffsetEnd = kDefinerOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=21&c=3
  static constexpr int kDataOffset = kDefinerOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=22&c=3
  static constexpr int kFlagsOffset = kDataOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;
  static constexpr int kSize = kFlagsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=13&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 40);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=13&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedInterceptorInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedInterceptorInfo, DAlias>::value,
        "class TorqueGeneratedInterceptorInfo should be used as direct base for InterceptorInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedInterceptorInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedInterceptorInfo(Address ptr);
};

// Alias for IsAccessCheckInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=25&c=1
V8_EXPORT_PRIVATE bool IsAccessCheckInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=25&c=1
template <class D, class P>
class TorqueGeneratedAccessCheckInfo : public P {
  static_assert(
      std::is_same<AccessCheckInfo, D>::value,
      "Use this class as direct base for AccessCheckInfo.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedAccessCheckInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAccessCheckInfo<D,P>;

  // Torque type: (class Undefined | Zero | class Foreign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> callback() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
  inline Tagged<Union<Foreign, Smi, Undefined>> callback(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
  inline void set_callback(Tagged<Union<Foreign, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Zero | class InterceptorInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
  inline Tagged<Union<InterceptorInfo, Smi, Undefined>> named_interceptor() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
  inline Tagged<Union<InterceptorInfo, Smi, Undefined>> named_interceptor(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
  inline void set_named_interceptor(Tagged<Union<InterceptorInfo, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Zero | class InterceptorInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
  inline Tagged<Union<InterceptorInfo, Smi, Undefined>> indexed_interceptor() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
  inline Tagged<Union<InterceptorInfo, Smi, Undefined>> indexed_interceptor(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
  inline void set_indexed_interceptor(Tagged<Union<InterceptorInfo, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
  inline Tagged<Object> data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
  inline Tagged<Object> data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
  inline void set_data(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(AccessCheckInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=25&c=1
  V8_EXPORT_PRIVATE void AccessCheckInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=26&c=3
  static constexpr int kCallbackOffset = P::kHeaderSize;
  static constexpr int kCallbackOffsetEnd = kCallbackOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=27&c=3
  static constexpr int kNamedInterceptorOffset = kCallbackOffsetEnd + 1;
  static constexpr int kNamedInterceptorOffsetEnd = kNamedInterceptorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=28&c=3
  static constexpr int kIndexedInterceptorOffset = kNamedInterceptorOffsetEnd + 1;
  static constexpr int kIndexedInterceptorOffsetEnd = kIndexedInterceptorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=29&c=3
  static constexpr int kDataOffset = kIndexedInterceptorOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kDataOffsetEnd + 1;
  static constexpr int kSize = kDataOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=25&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 20);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=25&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAccessCheckInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAccessCheckInfo, DAlias>::value,
        "class TorqueGeneratedAccessCheckInfo should be used as direct base for AccessCheckInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAccessCheckInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAccessCheckInfo(Address ptr);
};

// Alias for IsAccessorInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=42&c=1
V8_EXPORT_PRIVATE bool IsAccessorInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=42&c=1
template <class D, class P>
class TorqueGeneratedAccessorInfo : public P {
  static_assert(
      std::is_same<AccessorInfo, D>::value,
      "Use this class as direct base for AccessorInfo.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedAccessorInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAccessorInfo<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=43&c=3
  inline Tagged<Name> name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=43&c=3
  inline Tagged<Name> name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=43&c=3
  inline void set_name(Tagged<Name> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=44&c=3
  inline Tagged<Object> data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=44&c=3
  inline Tagged<Object> data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=44&c=3
  inline void set_data(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=50&c=3
  inline uint32_t flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=50&c=3
  inline void set_flags(uint32_t value);

  DECL_PRINTER(AccessorInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=42&c=1
  V8_EXPORT_PRIVATE void AccessorInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=43&c=3
  static constexpr int kNameOffset = P::kHeaderSize;
  static constexpr int kNameOffsetEnd = kNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=44&c=3
  static constexpr int kDataOffset = kNameOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=48&c=3
  static constexpr int kMaybeRedirectedGetterOffset = kDataOffsetEnd + 1;
  static constexpr int kMaybeRedirectedGetterOffsetEnd = kMaybeRedirectedGetterOffset + kExternalPointerSlotSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=49&c=3
  static constexpr int kSetterOffset = kMaybeRedirectedGetterOffsetEnd + 1;
  static constexpr int kSetterOffsetEnd = kSetterOffset + kExternalPointerSlotSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=50&c=3
  static constexpr int kFlagsOffset = kSetterOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=52&c=31
  static constexpr int kOptionalPaddingOffset = kFlagsOffsetEnd + 1;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kHeaderSize = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kSize = kOptionalPaddingOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=42&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=42&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAccessorInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAccessorInfo, DAlias>::value,
        "class TorqueGeneratedAccessorInfo should be used as direct base for AccessorInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAccessorInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAccessorInfo(Address ptr);
};

