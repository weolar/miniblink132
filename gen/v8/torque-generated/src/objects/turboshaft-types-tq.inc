class TurboshaftType;
class TurboshaftWord32Type;
class TurboshaftWord32RangeType;
class TurboshaftWord32SetType;
class TurboshaftWord64Type;
class TurboshaftWord64RangeType;
class TurboshaftWord64SetType;
class TurboshaftFloat64Type;
class TurboshaftFloat64RangeType;
class TurboshaftFloat64SetType;
// Alias for IsTurboshaftType() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=17&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftType_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=17&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftType : public P {
  static_assert(
      std::is_same<TurboshaftType, D>::value,
      "Use this class as direct base for TurboshaftType.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedTurboshaftType.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftType<D,P>;

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=17&c=1
  V8_EXPORT_PRIVATE void TurboshaftTypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftType() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftType, DAlias>::value,
        "class TorqueGeneratedTurboshaftType should be used as direct base for TurboshaftType.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftType(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftType(Address ptr);
};

// Alias for IsTurboshaftWord32Type() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=20&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftWord32Type_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=20&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftWord32Type : public P {
  static_assert(
      std::is_same<TurboshaftWord32Type, D>::value,
      "Use this class as direct base for TurboshaftWord32Type.");
  static_assert(
      std::is_same<TurboshaftType, P>::value,
      "Pass in TurboshaftType as second template parameter for TorqueGeneratedTurboshaftWord32Type.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftWord32Type<D,P>;

  DECL_PRINTER(TurboshaftWord32Type)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=20&c=1
  V8_EXPORT_PRIVATE void TurboshaftWord32TypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=20&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 4);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=20&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftWord32Type() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftWord32Type, DAlias>::value,
        "class TorqueGeneratedTurboshaftWord32Type should be used as direct base for TurboshaftWord32Type.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftWord32Type(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftWord32Type(Address ptr);
};

// Alias for IsTurboshaftWord32RangeType() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=25&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftWord32RangeType_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=25&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftWord32RangeType : public P {
  static_assert(
      std::is_same<TurboshaftWord32RangeType, D>::value,
      "Use this class as direct base for TurboshaftWord32RangeType.");
  static_assert(
      std::is_same<TurboshaftWord32Type, P>::value,
      "Pass in TurboshaftWord32Type as second template parameter for TorqueGeneratedTurboshaftWord32RangeType.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftWord32RangeType<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=29&c=3
  inline uint32_t from() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=29&c=3
  inline void set_from(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=30&c=3
  inline uint32_t to() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=30&c=3
  inline void set_to(uint32_t value);

  DECL_PRINTER(TurboshaftWord32RangeType)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=25&c=1
  V8_EXPORT_PRIVATE void TurboshaftWord32RangeTypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=29&c=3
  static constexpr int kFromOffset = P::kHeaderSize;
  static constexpr int kFromOffsetEnd = kFromOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=30&c=3
  static constexpr int kToOffset = kFromOffsetEnd + 1;
  static constexpr int kToOffsetEnd = kToOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kToOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kToOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kToOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kToOffsetEnd + 1;
  static constexpr int kHeaderSize = kToOffsetEnd + 1;
  static constexpr int kSize = kToOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=25&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=25&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftWord32RangeType() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftWord32RangeType, DAlias>::value,
        "class TorqueGeneratedTurboshaftWord32RangeType should be used as direct base for TurboshaftWord32RangeType.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftWord32RangeType(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftWord32RangeType(Address ptr);
};

// Alias for IsTurboshaftWord32SetType() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=33&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftWord32SetType_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=33&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftWord32SetType : public P {
  static_assert(
      std::is_same<TurboshaftWord32SetType, D>::value,
      "Use this class as direct base for TurboshaftWord32SetType.");
  static_assert(
      std::is_same<TurboshaftWord32Type, P>::value,
      "Pass in TurboshaftWord32Type as second template parameter for TorqueGeneratedTurboshaftWord32SetType.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftWord32SetType<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=37&c=9
  inline uint32_t set_size() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=37&c=9
  inline void set_set_size(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
  inline uint32_t elements(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
  inline void set_elements(int i, uint32_t value);

  DECL_PRINTER(TurboshaftWord32SetType)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=33&c=1
  V8_EXPORT_PRIVATE void TurboshaftWord32SetTypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=37&c=9
  static constexpr int kSetSizeOffset = P::kHeaderSize;
  static constexpr int kSetSizeOffsetEnd = kSetSizeOffset + kInt32Size - 1;
  static constexpr int kHeaderSize = kSetSizeOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
  static constexpr int kElementsOffset = kSetSizeOffsetEnd + 1;
  static constexpr int kElementsOffsetEnd = kElementsOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kElementsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=33&c=1
  V8_INLINE static constexpr int32_t SizeFor(int set_size) {
    int32_t size = kHeaderSize;
    size += set_size * 4;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=33&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->set_size());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftWord32SetType() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftWord32SetType, DAlias>::value,
        "class TorqueGeneratedTurboshaftWord32SetType should be used as direct base for TurboshaftWord32SetType.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftWord32SetType(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftWord32SetType(Address ptr);
};

// Alias for IsTurboshaftWord64Type() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=41&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftWord64Type_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=41&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftWord64Type : public P {
  static_assert(
      std::is_same<TurboshaftWord64Type, D>::value,
      "Use this class as direct base for TurboshaftWord64Type.");
  static_assert(
      std::is_same<TurboshaftType, P>::value,
      "Pass in TurboshaftType as second template parameter for TorqueGeneratedTurboshaftWord64Type.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftWord64Type<D,P>;

  DECL_PRINTER(TurboshaftWord64Type)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=41&c=1
  V8_EXPORT_PRIVATE void TurboshaftWord64TypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=41&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 4);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=41&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftWord64Type() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftWord64Type, DAlias>::value,
        "class TorqueGeneratedTurboshaftWord64Type should be used as direct base for TurboshaftWord64Type.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftWord64Type(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftWord64Type(Address ptr);
};

// Alias for IsTurboshaftWord64RangeType() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=46&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftWord64RangeType_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=46&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftWord64RangeType : public P {
  static_assert(
      std::is_same<TurboshaftWord64RangeType, D>::value,
      "Use this class as direct base for TurboshaftWord64RangeType.");
  static_assert(
      std::is_same<TurboshaftWord64Type, P>::value,
      "Pass in TurboshaftWord64Type as second template parameter for TorqueGeneratedTurboshaftWord64RangeType.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftWord64RangeType<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=50&c=3
  inline uint32_t from_high() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=50&c=3
  inline void set_from_high(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=51&c=3
  inline uint32_t from_low() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=51&c=3
  inline void set_from_low(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=52&c=3
  inline uint32_t to_high() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=52&c=3
  inline void set_to_high(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=53&c=3
  inline uint32_t to_low() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=53&c=3
  inline void set_to_low(uint32_t value);

  DECL_PRINTER(TurboshaftWord64RangeType)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=46&c=1
  V8_EXPORT_PRIVATE void TurboshaftWord64RangeTypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=50&c=3
  static constexpr int kFromHighOffset = P::kHeaderSize;
  static constexpr int kFromHighOffsetEnd = kFromHighOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=51&c=3
  static constexpr int kFromLowOffset = kFromHighOffsetEnd + 1;
  static constexpr int kFromLowOffsetEnd = kFromLowOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=52&c=3
  static constexpr int kToHighOffset = kFromLowOffsetEnd + 1;
  static constexpr int kToHighOffsetEnd = kToHighOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=53&c=3
  static constexpr int kToLowOffset = kToHighOffsetEnd + 1;
  static constexpr int kToLowOffsetEnd = kToLowOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kToLowOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kToLowOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kToLowOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kToLowOffsetEnd + 1;
  static constexpr int kHeaderSize = kToLowOffsetEnd + 1;
  static constexpr int kSize = kToLowOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=46&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 20);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=46&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftWord64RangeType() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftWord64RangeType, DAlias>::value,
        "class TorqueGeneratedTurboshaftWord64RangeType should be used as direct base for TurboshaftWord64RangeType.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftWord64RangeType(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftWord64RangeType(Address ptr);
};

// Alias for IsTurboshaftWord64SetType() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=56&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftWord64SetType_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=56&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftWord64SetType : public P {
  static_assert(
      std::is_same<TurboshaftWord64SetType, D>::value,
      "Use this class as direct base for TurboshaftWord64SetType.");
  static_assert(
      std::is_same<TurboshaftWord64Type, P>::value,
      "Pass in TurboshaftWord64Type as second template parameter for TorqueGeneratedTurboshaftWord64SetType.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftWord64SetType<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=60&c=9
  inline uint32_t set_size() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=60&c=9
  inline void set_set_size(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
  inline uint32_t elements_high(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
  inline void set_elements_high(int i, uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
  inline uint32_t elements_low(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
  inline void set_elements_low(int i, uint32_t value);

  DECL_PRINTER(TurboshaftWord64SetType)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=56&c=1
  V8_EXPORT_PRIVATE void TurboshaftWord64SetTypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=60&c=9
  static constexpr int kSetSizeOffset = P::kHeaderSize;
  static constexpr int kSetSizeOffsetEnd = kSetSizeOffset + kInt32Size - 1;
  static constexpr int kHeaderSize = kSetSizeOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
  static constexpr int kElementsHighOffset = kSetSizeOffsetEnd + 1;
  static constexpr int kElementsHighOffsetEnd = kElementsHighOffset + 0 - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
  inline int ElementsLowOffset() const;
  static constexpr int kStartOfWeakFieldsOffset = kElementsHighOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kElementsHighOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kElementsHighOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kElementsHighOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=56&c=1
  V8_INLINE static constexpr int32_t SizeFor(int set_size) {
    int32_t size = kHeaderSize;
    size += set_size * 4;
    size += set_size * 4;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=56&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->set_size());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftWord64SetType() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftWord64SetType, DAlias>::value,
        "class TorqueGeneratedTurboshaftWord64SetType should be used as direct base for TurboshaftWord64SetType.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftWord64SetType(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftWord64SetType(Address ptr);
};

// Alias for IsTurboshaftFloat64Type() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=65&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftFloat64Type_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=65&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftFloat64Type : public P {
  static_assert(
      std::is_same<TurboshaftFloat64Type, D>::value,
      "Use this class as direct base for TurboshaftFloat64Type.");
  static_assert(
      std::is_same<TurboshaftType, P>::value,
      "Pass in TurboshaftType as second template parameter for TorqueGeneratedTurboshaftFloat64Type.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftFloat64Type<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=69&c=3
  inline uint32_t special_values() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=69&c=3
  inline void set_special_values(uint32_t value);

  DECL_PRINTER(TurboshaftFloat64Type)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=65&c=1
  V8_EXPORT_PRIVATE void TurboshaftFloat64TypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=69&c=3
  static constexpr int kSpecialValuesOffset = P::kHeaderSize;
  static constexpr int kSpecialValuesOffsetEnd = kSpecialValuesOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kSpecialValuesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSpecialValuesOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kSpecialValuesOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kSpecialValuesOffsetEnd + 1;
  static constexpr int kHeaderSize = kSpecialValuesOffsetEnd + 1;
  static constexpr int kSize = kSpecialValuesOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=65&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 8);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=65&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftFloat64Type() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftFloat64Type, DAlias>::value,
        "class TorqueGeneratedTurboshaftFloat64Type should be used as direct base for TurboshaftFloat64Type.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftFloat64Type(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftFloat64Type(Address ptr);
};

// Alias for IsTurboshaftFloat64RangeType() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=72&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftFloat64RangeType_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=72&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftFloat64RangeType : public P {
  static_assert(
      std::is_same<TurboshaftFloat64RangeType, D>::value,
      "Use this class as direct base for TurboshaftFloat64RangeType.");
  static_assert(
      std::is_same<TurboshaftFloat64Type, P>::value,
      "Pass in TurboshaftFloat64Type as second template parameter for TorqueGeneratedTurboshaftFloat64RangeType.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftFloat64RangeType<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=76&c=3
  inline uint32_t _padding() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=76&c=3
  inline void set__padding(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=77&c=3
  inline double min() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=77&c=3
  inline void set_min(double value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=78&c=3
  inline double max() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=78&c=3
  inline void set_max(double value);

  DECL_PRINTER(TurboshaftFloat64RangeType)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=72&c=1
  V8_EXPORT_PRIVATE void TurboshaftFloat64RangeTypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=76&c=3
  static constexpr int kPaddingOffset = P::kHeaderSize;
  static constexpr int kPaddingOffsetEnd = kPaddingOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=77&c=3
  static constexpr int kMinOffset = kPaddingOffsetEnd + 1;
  static constexpr int kMinOffsetEnd = kMinOffset + kDoubleSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=78&c=3
  static constexpr int kMaxOffset = kMinOffsetEnd + 1;
  static constexpr int kMaxOffsetEnd = kMaxOffset + kDoubleSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kMaxOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kMaxOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kMaxOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kMaxOffsetEnd + 1;
  static constexpr int kHeaderSize = kMaxOffsetEnd + 1;
  static constexpr int kSize = kMaxOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=72&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 28);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=72&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftFloat64RangeType() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftFloat64RangeType, DAlias>::value,
        "class TorqueGeneratedTurboshaftFloat64RangeType should be used as direct base for TurboshaftFloat64RangeType.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftFloat64RangeType(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftFloat64RangeType(Address ptr);
};

// Alias for IsTurboshaftFloat64SetType() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=81&c=1
V8_EXPORT_PRIVATE bool IsTurboshaftFloat64SetType_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=81&c=1
template <class D, class P>
class TorqueGeneratedTurboshaftFloat64SetType : public P {
  static_assert(
      std::is_same<TurboshaftFloat64SetType, D>::value,
      "Use this class as direct base for TurboshaftFloat64SetType.");
  static_assert(
      std::is_same<TurboshaftFloat64Type, P>::value,
      "Pass in TurboshaftFloat64Type as second template parameter for TorqueGeneratedTurboshaftFloat64SetType.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTurboshaftFloat64SetType<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=85&c=9
  inline uint32_t set_size() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=85&c=9
  inline void set_set_size(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
  inline double elements(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
  inline void set_elements(int i, double value);

  DECL_PRINTER(TurboshaftFloat64SetType)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=81&c=1
  V8_EXPORT_PRIVATE void TurboshaftFloat64SetTypeVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=85&c=9
  static constexpr int kSetSizeOffset = P::kHeaderSize;
  static constexpr int kSetSizeOffsetEnd = kSetSizeOffset + kInt32Size - 1;
  static constexpr int kHeaderSize = kSetSizeOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
  static constexpr int kElementsOffset = kSetSizeOffsetEnd + 1;
  static constexpr int kElementsOffsetEnd = kElementsOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kElementsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=81&c=1
  V8_INLINE static constexpr int32_t SizeFor(int set_size) {
    int32_t size = kHeaderSize;
    size += set_size * 8;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=81&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->set_size());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTurboshaftFloat64SetType() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTurboshaftFloat64SetType, DAlias>::value,
        "class TorqueGeneratedTurboshaftFloat64SetType should be used as direct base for TurboshaftFloat64SetType.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTurboshaftFloat64SetType(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTurboshaftFloat64SetType(Address ptr);
};

