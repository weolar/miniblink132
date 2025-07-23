class StrongDescriptorArray;
class InternalClass;
class SmiPair;
class SmiBox;
class ExportedSubClassBase;
class ExportedSubClass;
class AbstractInternalClass;
class AbstractInternalClassSubclass1;
class AbstractInternalClassSubclass2;
class InternalClassWithStructElements;
class ExportedSubClass2;
class SortState;
class WasmFastApiCallData;
class WasmStringViewIter;
// Alias for IsStrongDescriptorArray() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=31&c=1
V8_EXPORT_PRIVATE bool IsStrongDescriptorArray_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=31&c=1
template <class D, class P>
class TorqueGeneratedStrongDescriptorArray : public P {
  static_assert(
      std::is_same<StrongDescriptorArray, D>::value,
      "Use this class as direct base for StrongDescriptorArray.");
  static_assert(
      std::is_same<DescriptorArray, P>::value,
      "Pass in DescriptorArray as second template parameter for TorqueGeneratedStrongDescriptorArray.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedStrongDescriptorArray<D,P>;

 protected: // not extern or @export
 public:
  DECL_PRINTER(StrongDescriptorArray)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=31&c=1
  V8_EXPORT_PRIVATE void StrongDescriptorArrayVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=31&c=1
  V8_INLINE static constexpr int32_t SizeFor(int number_of_all_descriptors) {
    int32_t size = kHeaderSize;
    size += number_of_all_descriptors * 12;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=31&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->number_of_all_descriptors());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedStrongDescriptorArray() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedStrongDescriptorArray, DAlias>::value,
        "class TorqueGeneratedStrongDescriptorArray should be used as direct base for StrongDescriptorArray.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedStrongDescriptorArray(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedStrongDescriptorArray(Address ptr);
};

class StrongDescriptorArray : public TorqueGeneratedStrongDescriptorArray<StrongDescriptorArray, DescriptorArray> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(StrongDescriptorArray)
};

// Alias for IsInternalClass() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=759&c=1
V8_EXPORT_PRIVATE bool IsInternalClass_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=759&c=1
template <class D, class P>
class TorqueGeneratedInternalClass : public P {
  static_assert(
      std::is_same<InternalClass, D>::value,
      "Use this class as direct base for InternalClass.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedInternalClass.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedInternalClass<D,P>;

 protected: // not extern or @export
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=765&c=3
  inline int a() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=765&c=3
  inline void set_a(int value);

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=766&c=3
  inline Tagged<Number> b() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=766&c=3
  inline Tagged<Number> b(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=766&c=3
  inline void set_b(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

 public:
  DECL_PRINTER(InternalClass)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=759&c=1
  V8_EXPORT_PRIVATE void InternalClassVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=765&c=3
  static constexpr int kAOffset = P::kHeaderSize;
  static constexpr int kAOffsetEnd = kAOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=766&c=3
  static constexpr int kBOffset = kAOffsetEnd + 1;
  static constexpr int kBOffsetEnd = kBOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kHeaderSize = kBOffsetEnd + 1;
  static constexpr int kSize = kBOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=759&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=759&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedInternalClass() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedInternalClass, DAlias>::value,
        "class TorqueGeneratedInternalClass should be used as direct base for InternalClass.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedInternalClass(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedInternalClass(Address ptr);
};

class InternalClass : public TorqueGeneratedInternalClass<InternalClass, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(InternalClass)
};

// Alias for IsSmiPair() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=825&c=1
V8_EXPORT_PRIVATE bool IsSmiPair_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=825&c=1
template <class D, class P>
class TorqueGeneratedSmiPair : public P {
  static_assert(
      std::is_same<SmiPair, D>::value,
      "Use this class as direct base for SmiPair.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedSmiPair.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedSmiPair<D,P>;

 protected: // not extern or @export
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=829&c=3
  inline int a() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=829&c=3
  inline void set_a(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=830&c=3
  inline int b() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=830&c=3
  inline void set_b(int value);

 public:
  DECL_PRINTER(SmiPair)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=825&c=1
  V8_EXPORT_PRIVATE void SmiPairVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=829&c=3
  static constexpr int kAOffset = P::kHeaderSize;
  static constexpr int kAOffsetEnd = kAOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=830&c=3
  static constexpr int kBOffset = kAOffsetEnd + 1;
  static constexpr int kBOffsetEnd = kBOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kHeaderSize = kBOffsetEnd + 1;
  static constexpr int kSize = kBOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=825&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=825&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedSmiPair() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedSmiPair, DAlias>::value,
        "class TorqueGeneratedSmiPair should be used as direct base for SmiPair.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedSmiPair(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedSmiPair(Address ptr);
};

class SmiPair : public TorqueGeneratedSmiPair<SmiPair, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(SmiPair)
};

// Alias for IsSmiBox() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=926&c=1
V8_EXPORT_PRIVATE bool IsSmiBox_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=926&c=1
template <class D, class P>
class TorqueGeneratedSmiBox : public P {
  static_assert(
      std::is_same<SmiBox, D>::value,
      "Use this class as direct base for SmiBox.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedSmiBox.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedSmiBox<D,P>;

 protected: // not extern or @export
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=927&c=3
  inline int value() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=927&c=3
  inline void set_value(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=928&c=3
  inline int unrelated() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=928&c=3
  inline void set_unrelated(int value);

 public:
  DECL_PRINTER(SmiBox)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=926&c=1
  V8_EXPORT_PRIVATE void SmiBoxVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=927&c=3
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=928&c=3
  static constexpr int kUnrelatedOffset = kValueOffsetEnd + 1;
  static constexpr int kUnrelatedOffsetEnd = kUnrelatedOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kUnrelatedOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kUnrelatedOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kUnrelatedOffsetEnd + 1;
  static constexpr int kHeaderSize = kUnrelatedOffsetEnd + 1;
  static constexpr int kSize = kUnrelatedOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=926&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=926&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedSmiBox() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedSmiBox, DAlias>::value,
        "class TorqueGeneratedSmiBox should be used as direct base for SmiBox.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedSmiBox(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedSmiBox(Address ptr);
};

class SmiBox : public TorqueGeneratedSmiBox<SmiBox, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(SmiBox)
};

// Alias for IsExportedSubClassBase() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1177&c=1
V8_EXPORT_PRIVATE bool IsExportedSubClassBase_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1177&c=1
template <class D, class P>
class TorqueGeneratedExportedSubClassBase : public P {
  static_assert(
      std::is_same<ExportedSubClassBase, D>::value,
      "Use this class as direct base for ExportedSubClassBase.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedExportedSubClassBase.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedExportedSubClassBase<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1179&c=3
  inline Tagged<HeapObject> a() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1179&c=3
  inline Tagged<HeapObject> a(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1179&c=3
  inline void set_a(Tagged<HeapObject> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1180&c=3
  inline Tagged<HeapObject> b() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1180&c=3
  inline Tagged<HeapObject> b(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1180&c=3
  inline void set_b(Tagged<HeapObject> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(ExportedSubClassBase)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1177&c=1
  V8_EXPORT_PRIVATE void ExportedSubClassBaseVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1179&c=3
  static constexpr int kAOffset = P::kHeaderSize;
  static constexpr int kAOffsetEnd = kAOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1180&c=3
  static constexpr int kBOffset = kAOffsetEnd + 1;
  static constexpr int kBOffsetEnd = kBOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kHeaderSize = kBOffsetEnd + 1;
  static constexpr int kSize = kBOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1177&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1177&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedExportedSubClassBase() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedExportedSubClassBase, DAlias>::value,
        "class TorqueGeneratedExportedSubClassBase should be used as direct base for ExportedSubClassBase.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedExportedSubClassBase(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedExportedSubClassBase(Address ptr);
};

class ExportedSubClassBase : public TorqueGeneratedExportedSubClassBase<ExportedSubClassBase, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(ExportedSubClassBase)
};

// Alias for IsExportedSubClass() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1170&c=1
V8_EXPORT_PRIVATE bool IsExportedSubClass_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1170&c=1
template <class D, class P>
class TorqueGeneratedExportedSubClass : public P {
  static_assert(
      std::is_same<ExportedSubClass, D>::value,
      "Use this class as direct base for ExportedSubClass.");
  static_assert(
      std::is_same<ExportedSubClassBase, P>::value,
      "Pass in ExportedSubClassBase as second template parameter for TorqueGeneratedExportedSubClass.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedExportedSubClass<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1172&c=3
  inline int32_t c_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1172&c=3
  inline void set_c_field(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1173&c=3
  inline int32_t d_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1173&c=3
  inline void set_d_field(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1174&c=3
  inline int e_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1174&c=3
  inline void set_e_field(int value);

  DECL_PRINTER(ExportedSubClass)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1170&c=1
  V8_EXPORT_PRIVATE void ExportedSubClassVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1172&c=3
  static constexpr int kCFieldOffset = P::kHeaderSize;
  static constexpr int kCFieldOffsetEnd = kCFieldOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1173&c=3
  static constexpr int kDFieldOffset = kCFieldOffsetEnd + 1;
  static constexpr int kDFieldOffsetEnd = kDFieldOffset + kInt32Size - 1;
  static constexpr int kStartOfStrongFieldsOffset = kDFieldOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1174&c=3
  static constexpr int kEFieldOffset = kDFieldOffsetEnd + 1;
  static constexpr int kEFieldOffsetEnd = kEFieldOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kEFieldOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kEFieldOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kEFieldOffsetEnd + 1;
  static constexpr int kHeaderSize = kEFieldOffsetEnd + 1;
  static constexpr int kSize = kEFieldOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1170&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1170&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedExportedSubClass() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedExportedSubClass, DAlias>::value,
        "class TorqueGeneratedExportedSubClass should be used as direct base for ExportedSubClass.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedExportedSubClass(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedExportedSubClass(Address ptr);
};

class ExportedSubClass : public TorqueGeneratedExportedSubClass<ExportedSubClass, ExportedSubClassBase> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(ExportedSubClass)
};

// Alias for IsAbstractInternalClass() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1183&c=1
V8_EXPORT_PRIVATE bool IsAbstractInternalClass_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1183&c=1
template <class D, class P>
class TorqueGeneratedAbstractInternalClass : public P {
  static_assert(
      std::is_same<AbstractInternalClass, D>::value,
      "Use this class as direct base for AbstractInternalClass.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedAbstractInternalClass.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAbstractInternalClass<D,P>;

 protected: // not extern or @export
 public:
  DECL_PRINTER(AbstractInternalClass)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1183&c=1
  V8_EXPORT_PRIVATE void AbstractInternalClassVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAbstractInternalClass() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAbstractInternalClass, DAlias>::value,
        "class TorqueGeneratedAbstractInternalClass should be used as direct base for AbstractInternalClass.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAbstractInternalClass(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAbstractInternalClass(Address ptr);
};

class AbstractInternalClass : public TorqueGeneratedAbstractInternalClass<AbstractInternalClass, HeapObject> {
 public:
  TQ_OBJECT_CONSTRUCTORS(AbstractInternalClass)
};

// Alias for IsAbstractInternalClassSubclass1() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1186&c=1
V8_EXPORT_PRIVATE bool IsAbstractInternalClassSubclass1_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1186&c=1
template <class D, class P>
class TorqueGeneratedAbstractInternalClassSubclass1 : public P {
  static_assert(
      std::is_same<AbstractInternalClassSubclass1, D>::value,
      "Use this class as direct base for AbstractInternalClassSubclass1.");
  static_assert(
      std::is_same<AbstractInternalClass, P>::value,
      "Pass in AbstractInternalClass as second template parameter for TorqueGeneratedAbstractInternalClassSubclass1.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAbstractInternalClassSubclass1<D,P>;

 protected: // not extern or @export
 public:
  DECL_PRINTER(AbstractInternalClassSubclass1)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1186&c=1
  V8_EXPORT_PRIVATE void AbstractInternalClassSubclass1Verify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1186&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 4);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1186&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAbstractInternalClassSubclass1() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAbstractInternalClassSubclass1, DAlias>::value,
        "class TorqueGeneratedAbstractInternalClassSubclass1 should be used as direct base for AbstractInternalClassSubclass1.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAbstractInternalClassSubclass1(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAbstractInternalClassSubclass1(Address ptr);
};

class AbstractInternalClassSubclass1 : public TorqueGeneratedAbstractInternalClassSubclass1<AbstractInternalClassSubclass1, AbstractInternalClass> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(AbstractInternalClassSubclass1)
};

// Alias for IsAbstractInternalClassSubclass2() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1188&c=1
V8_EXPORT_PRIVATE bool IsAbstractInternalClassSubclass2_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1188&c=1
template <class D, class P>
class TorqueGeneratedAbstractInternalClassSubclass2 : public P {
  static_assert(
      std::is_same<AbstractInternalClassSubclass2, D>::value,
      "Use this class as direct base for AbstractInternalClassSubclass2.");
  static_assert(
      std::is_same<AbstractInternalClass, P>::value,
      "Pass in AbstractInternalClass as second template parameter for TorqueGeneratedAbstractInternalClassSubclass2.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAbstractInternalClassSubclass2<D,P>;

 protected: // not extern or @export
 public:
  DECL_PRINTER(AbstractInternalClassSubclass2)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1188&c=1
  V8_EXPORT_PRIVATE void AbstractInternalClassSubclass2Verify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1188&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 4);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1188&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAbstractInternalClassSubclass2() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAbstractInternalClassSubclass2, DAlias>::value,
        "class TorqueGeneratedAbstractInternalClassSubclass2 should be used as direct base for AbstractInternalClassSubclass2.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAbstractInternalClassSubclass2(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAbstractInternalClassSubclass2(Address ptr);
};

class AbstractInternalClassSubclass2 : public TorqueGeneratedAbstractInternalClassSubclass2<AbstractInternalClassSubclass2, AbstractInternalClass> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(AbstractInternalClassSubclass2)
};

// Alias for IsInternalClassWithStructElements() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1195&c=1
V8_EXPORT_PRIVATE bool IsInternalClassWithStructElements_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1195&c=1
template <class D, class P>
class TorqueGeneratedInternalClassWithStructElements : public P {
  static_assert(
      std::is_same<InternalClassWithStructElements, D>::value,
      "Use this class as direct base for InternalClassWithStructElements.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedInternalClassWithStructElements.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedInternalClassWithStructElements<D,P>;

 protected: // not extern or @export
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1196&c=3
  inline int32_t dummy1() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1196&c=3
  inline void set_dummy1(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1197&c=3
  inline int32_t dummy2() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1197&c=3
  inline void set_dummy2(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1198&c=9
  inline int count() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1198&c=9
  inline void set_count(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1199&c=3
  inline int data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1199&c=3
  inline void set_data(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1200&c=3
  inline Tagged<Object> object() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1200&c=3
  inline Tagged<Object> object(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1200&c=3
  inline void set_object(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1201&c=3
  inline int entries(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1201&c=3
  inline void set_entries(int i, int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
  inline int more_entries_a(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
  inline void set_more_entries_a(int i, int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
  inline int more_entries_b(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
  inline void set_more_entries_b(int i, int value);

 public:
  DECL_PRINTER(InternalClassWithStructElements)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1195&c=1
  V8_EXPORT_PRIVATE void InternalClassWithStructElementsVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1196&c=3
  static constexpr int kDummy1Offset = P::kHeaderSize;
  static constexpr int kDummy1OffsetEnd = kDummy1Offset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1197&c=3
  static constexpr int kDummy2Offset = kDummy1OffsetEnd + 1;
  static constexpr int kDummy2OffsetEnd = kDummy2Offset + kInt32Size - 1;
  static constexpr int kStartOfStrongFieldsOffset = kDummy2OffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1198&c=9
  static constexpr int kCountOffset = kDummy2OffsetEnd + 1;
  static constexpr int kCountOffsetEnd = kCountOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1199&c=3
  static constexpr int kDataOffset = kCountOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1200&c=3
  static constexpr int kObjectOffset = kDataOffsetEnd + 1;
  static constexpr int kObjectOffsetEnd = kObjectOffset + kTaggedSize - 1;
  static constexpr int kHeaderSize = kObjectOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1201&c=3
  static constexpr int kEntriesOffset = kObjectOffsetEnd + 1;
  static constexpr int kEntriesOffsetEnd = kEntriesOffset + 0 - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
  inline int MoreEntriesOffset() const;
  static constexpr int kEndOfStrongFieldsOffset = kEntriesOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kEntriesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kEntriesOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1195&c=1
  V8_INLINE static constexpr int32_t SizeFor(int count) {
    int32_t size = kHeaderSize;
    size += count * 4;
    size += count * 8;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1195&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->count());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedInternalClassWithStructElements() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedInternalClassWithStructElements, DAlias>::value,
        "class TorqueGeneratedInternalClassWithStructElements should be used as direct base for InternalClassWithStructElements.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedInternalClassWithStructElements(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedInternalClassWithStructElements(Address ptr);
};

class InternalClassWithStructElements : public TorqueGeneratedInternalClassWithStructElements<InternalClassWithStructElements, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(InternalClassWithStructElements)
};

// Alias for IsExportedSubClass2() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1212&c=1
V8_EXPORT_PRIVATE bool IsExportedSubClass2_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1212&c=1
template <class D, class P>
class TorqueGeneratedExportedSubClass2 : public P {
  static_assert(
      std::is_same<ExportedSubClass2, D>::value,
      "Use this class as direct base for ExportedSubClass2.");
  static_assert(
      std::is_same<ExportedSubClassBase, P>::value,
      "Pass in ExportedSubClassBase as second template parameter for TorqueGeneratedExportedSubClass2.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedExportedSubClass2<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1214&c=3
  inline int32_t x_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1214&c=3
  inline void set_x_field(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1215&c=3
  inline int32_t y_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1215&c=3
  inline void set_y_field(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1216&c=3
  inline int z_field() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1216&c=3
  inline void set_z_field(int value);

  DECL_PRINTER(ExportedSubClass2)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1212&c=1
  V8_EXPORT_PRIVATE void ExportedSubClass2Verify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1214&c=3
  static constexpr int kXFieldOffset = P::kHeaderSize;
  static constexpr int kXFieldOffsetEnd = kXFieldOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1215&c=3
  static constexpr int kYFieldOffset = kXFieldOffsetEnd + 1;
  static constexpr int kYFieldOffsetEnd = kYFieldOffset + kInt32Size - 1;
  static constexpr int kStartOfStrongFieldsOffset = kYFieldOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1216&c=3
  static constexpr int kZFieldOffset = kYFieldOffsetEnd + 1;
  static constexpr int kZFieldOffsetEnd = kZFieldOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kZFieldOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kZFieldOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kZFieldOffsetEnd + 1;
  static constexpr int kHeaderSize = kZFieldOffsetEnd + 1;
  static constexpr int kSize = kZFieldOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1212&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1212&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedExportedSubClass2() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedExportedSubClass2, DAlias>::value,
        "class TorqueGeneratedExportedSubClass2 should be used as direct base for ExportedSubClass2.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedExportedSubClass2(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedExportedSubClass2(Address ptr);
};

class ExportedSubClass2 : public TorqueGeneratedExportedSubClass2<ExportedSubClass2, ExportedSubClassBase> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(ExportedSubClass2)
};

// Alias for IsSortState() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=17&c=1
V8_EXPORT_PRIVATE bool IsSortState_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=17&c=1
template <class D, class P>
class TorqueGeneratedSortState : public P {
  static_assert(
      std::is_same<SortState, D>::value,
      "Use this class as direct base for SortState.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedSortState.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedSortState<D,P>;

 protected: // not extern or @export
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=47&c=3
  inline Tagged<JSReceiver> receiver() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=47&c=3
  inline Tagged<JSReceiver> receiver(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=47&c=3
  inline void set_receiver(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=52&c=3
  inline Tagged<Map> initialReceiverMap() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=52&c=3
  inline Tagged<Map> initialReceiverMap(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=52&c=3
  inline void set_initialReceiverMap(Tagged<Map> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=53&c=3
  inline Tagged<Number> initialReceiverLength() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=53&c=3
  inline Tagged<Number> initialReceiverLength(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=53&c=3
  inline void set_initialReceiverLength(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction | CallableApiObject | CallableJSProxy | class JSWrappedFunction | class JSBoundFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=56&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> userCmpFn() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=56&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> userCmpFn(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=56&c=3
  inline void set_userCmpFn(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=61&c=3
  inline int sortComparePtr() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=61&c=3
  inline void set_sortComparePtr(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=66&c=3
  inline int loadFn() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=66&c=3
  inline void set_loadFn(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=67&c=3
  inline int storeFn() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=67&c=3
  inline void set_storeFn(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=68&c=3
  inline int deleteFn() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=68&c=3
  inline void set_deleteFn(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=69&c=3
  inline int canUseSameAccessorFn() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=69&c=3
  inline void set_canUseSameAccessorFn(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=74&c=3
  inline int minGallop() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=74&c=3
  inline void set_minGallop(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=86&c=3
  inline int pendingRunsSize() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=86&c=3
  inline void set_pendingRunsSize(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=87&c=3
  inline Tagged<FixedArray> pendingRuns() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=87&c=3
  inline Tagged<FixedArray> pendingRuns(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=87&c=3
  inline void set_pendingRuns(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=92&c=3
  inline Tagged<FixedArray> workArray() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=92&c=3
  inline Tagged<FixedArray> workArray(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=92&c=3
  inline void set_workArray(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=95&c=3
  inline Tagged<FixedArray> tempArray() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=95&c=3
  inline Tagged<FixedArray> tempArray(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=95&c=3
  inline void set_tempArray(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=98&c=3
  inline int sortLength() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=98&c=3
  inline void set_sortLength(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=102&c=3
  inline int numberOfUndefined() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=102&c=3
  inline void set_numberOfUndefined(int value);

 public:
  DECL_PRINTER(SortState)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=17&c=1
  V8_EXPORT_PRIVATE void SortStateVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=47&c=3
  static constexpr int kReceiverOffset = P::kHeaderSize;
  static constexpr int kReceiverOffsetEnd = kReceiverOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=52&c=3
  static constexpr int kInitialReceiverMapOffset = kReceiverOffsetEnd + 1;
  static constexpr int kInitialReceiverMapOffsetEnd = kInitialReceiverMapOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=53&c=3
  static constexpr int kInitialReceiverLengthOffset = kInitialReceiverMapOffsetEnd + 1;
  static constexpr int kInitialReceiverLengthOffsetEnd = kInitialReceiverLengthOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=56&c=3
  static constexpr int kUserCmpFnOffset = kInitialReceiverLengthOffsetEnd + 1;
  static constexpr int kUserCmpFnOffsetEnd = kUserCmpFnOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=61&c=3
  static constexpr int kSortComparePtrOffset = kUserCmpFnOffsetEnd + 1;
  static constexpr int kSortComparePtrOffsetEnd = kSortComparePtrOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=66&c=3
  static constexpr int kLoadFnOffset = kSortComparePtrOffsetEnd + 1;
  static constexpr int kLoadFnOffsetEnd = kLoadFnOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=67&c=3
  static constexpr int kStoreFnOffset = kLoadFnOffsetEnd + 1;
  static constexpr int kStoreFnOffsetEnd = kStoreFnOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=68&c=3
  static constexpr int kDeleteFnOffset = kStoreFnOffsetEnd + 1;
  static constexpr int kDeleteFnOffsetEnd = kDeleteFnOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=69&c=3
  static constexpr int kCanUseSameAccessorFnOffset = kDeleteFnOffsetEnd + 1;
  static constexpr int kCanUseSameAccessorFnOffsetEnd = kCanUseSameAccessorFnOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=74&c=3
  static constexpr int kMinGallopOffset = kCanUseSameAccessorFnOffsetEnd + 1;
  static constexpr int kMinGallopOffsetEnd = kMinGallopOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=86&c=3
  static constexpr int kPendingRunsSizeOffset = kMinGallopOffsetEnd + 1;
  static constexpr int kPendingRunsSizeOffsetEnd = kPendingRunsSizeOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=87&c=3
  static constexpr int kPendingRunsOffset = kPendingRunsSizeOffsetEnd + 1;
  static constexpr int kPendingRunsOffsetEnd = kPendingRunsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=92&c=3
  static constexpr int kWorkArrayOffset = kPendingRunsOffsetEnd + 1;
  static constexpr int kWorkArrayOffsetEnd = kWorkArrayOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=95&c=3
  static constexpr int kTempArrayOffset = kWorkArrayOffsetEnd + 1;
  static constexpr int kTempArrayOffsetEnd = kTempArrayOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=98&c=3
  static constexpr int kSortLengthOffset = kTempArrayOffsetEnd + 1;
  static constexpr int kSortLengthOffsetEnd = kSortLengthOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=102&c=3
  static constexpr int kNumberOfUndefinedOffset = kSortLengthOffsetEnd + 1;
  static constexpr int kNumberOfUndefinedOffsetEnd = kNumberOfUndefinedOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kNumberOfUndefinedOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kNumberOfUndefinedOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kNumberOfUndefinedOffsetEnd + 1;
  static constexpr int kHeaderSize = kNumberOfUndefinedOffsetEnd + 1;
  static constexpr int kSize = kNumberOfUndefinedOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=17&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 68);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=17&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedSortState() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedSortState, DAlias>::value,
        "class TorqueGeneratedSortState should be used as direct base for SortState.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedSortState(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedSortState(Address ptr);
};

class SortState : public TorqueGeneratedSortState<SortState, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(SortState)
};

// Alias for IsWasmFastApiCallData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
V8_EXPORT_PRIVATE bool IsWasmFastApiCallData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
template <class D, class P>
class TorqueGeneratedWasmFastApiCallData : public P {
  static_assert(
      std::is_same<WasmFastApiCallData, D>::value,
      "Use this class as direct base for WasmFastApiCallData.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedWasmFastApiCallData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmFastApiCallData<D,P>;

 protected: // not extern or @export
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
  inline Tagged<HeapObject> signature() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
  inline Tagged<HeapObject> signature(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
  inline void set_signature(Tagged<HeapObject> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
  inline Tagged<Object> callback_data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
  inline Tagged<Object> callback_data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
  inline void set_callback_data(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Null | Weak<class Map>)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
  inline Tagged<Union<MaybeObject, Null>> cached_map() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
  inline Tagged<Union<MaybeObject, Null>> cached_map(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
  inline void set_cached_map(Tagged<Union<MaybeObject, Null>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

 public:
  DECL_PRINTER(WasmFastApiCallData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
  V8_EXPORT_PRIVATE void WasmFastApiCallDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
  static constexpr int kSignatureOffset = P::kHeaderSize;
  static constexpr int kSignatureOffsetEnd = kSignatureOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
  static constexpr int kCallbackDataOffset = kSignatureOffsetEnd + 1;
  static constexpr int kCallbackDataOffsetEnd = kCallbackDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCallbackDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCallbackDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
  static constexpr int kCachedMapOffset = kCallbackDataOffsetEnd + 1;
  static constexpr int kCachedMapOffsetEnd = kCachedMapOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kCachedMapOffsetEnd + 1;
  static constexpr int kHeaderSize = kCachedMapOffsetEnd + 1;
  static constexpr int kSize = kCachedMapOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 16);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmFastApiCallData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmFastApiCallData, DAlias>::value,
        "class TorqueGeneratedWasmFastApiCallData should be used as direct base for WasmFastApiCallData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmFastApiCallData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmFastApiCallData(Address ptr);
};

class WasmFastApiCallData : public TorqueGeneratedWasmFastApiCallData<WasmFastApiCallData, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(WasmFastApiCallData)
};

// Alias for IsWasmStringViewIter() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
V8_EXPORT_PRIVATE bool IsWasmStringViewIter_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
template <class D, class P>
class TorqueGeneratedWasmStringViewIter : public P {
  static_assert(
      std::is_same<WasmStringViewIter, D>::value,
      "Use this class as direct base for WasmStringViewIter.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedWasmStringViewIter.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmStringViewIter<D,P>;

 protected: // not extern or @export
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
  inline Tagged<String> string() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
  inline Tagged<String> string(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
  inline void set_string(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
  inline uint32_t offset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
  inline void set_offset(uint32_t value);

 public:
  DECL_PRINTER(WasmStringViewIter)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
  V8_EXPORT_PRIVATE void WasmStringViewIterVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
  static constexpr int kStringOffset = P::kHeaderSize;
  static constexpr int kStringOffsetEnd = kStringOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kStringOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
  static constexpr int kOffsetOffset = kStringOffsetEnd + 1;
  static constexpr int kOffsetOffsetEnd = kOffsetOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=318&c=31
  static constexpr int kOptionalPaddingOffset = kOffsetOffsetEnd + 1;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kHeaderSize = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kSize = kOptionalPaddingOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmStringViewIter() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmStringViewIter, DAlias>::value,
        "class TorqueGeneratedWasmStringViewIter should be used as direct base for WasmStringViewIter.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmStringViewIter(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmStringViewIter(Address ptr);
};

class WasmStringViewIter : public TorqueGeneratedWasmStringViewIter<WasmStringViewIter, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(WasmStringViewIter)
};

