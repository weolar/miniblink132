class PropertyDescriptorObject;
// Alias for IsPropertyDescriptorObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
V8_EXPORT_PRIVATE bool IsPropertyDescriptorObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
template <class D, class P>
class TorqueGeneratedPropertyDescriptorObject : public P {
  static_assert(
      std::is_same<PropertyDescriptorObject, D>::value,
      "Use this class as direct base for PropertyDescriptorObject.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedPropertyDescriptorObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPropertyDescriptorObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
  inline void set_flags(int value);

  // Torque type: (class JSReceiver | class Undefined | class Null | class Boolean | class Symbol | class String | BigInt | class HeapNumber | Smi | TheHole)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
  inline Tagged<Union<BigInt, Boolean, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
  inline Tagged<Union<BigInt, Boolean, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
  inline void set_value(Tagged<Union<BigInt, Boolean, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class JSReceiver | class Undefined | class Null | class Boolean | class Symbol | class String | BigInt | class HeapNumber | Smi | TheHole | class FunctionTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
  inline Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> get() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
  inline Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> get(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
  inline void set_get(Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class JSReceiver | class Undefined | class Null | class Boolean | class Symbol | class String | BigInt | class HeapNumber | Smi | TheHole | class FunctionTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
  inline Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> set() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
  inline Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> set(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
  inline void set_set(Tagged<Union<BigInt, Boolean, FunctionTemplateInfo, HeapNumber, Hole, JSReceiver, Null, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(PropertyDescriptorObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
  V8_EXPORT_PRIVATE void PropertyDescriptorObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=47&c=3
  static constexpr int kFlagsOffset = P::kHeaderSize;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=48&c=3
  static constexpr int kValueOffset = kFlagsOffsetEnd + 1;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=49&c=3
  static constexpr int kGetOffset = kValueOffsetEnd + 1;
  static constexpr int kGetOffsetEnd = kGetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=50&c=3
  static constexpr int kSetOffset = kGetOffsetEnd + 1;
  static constexpr int kSetOffsetEnd = kSetOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSetOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSetOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSetOffsetEnd + 1;
  static constexpr int kHeaderSize = kSetOffsetEnd + 1;
  static constexpr int kSize = kSetOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 20);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/property-descriptor-object.tq?l=19&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPropertyDescriptorObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPropertyDescriptorObject, DAlias>::value,
        "class TorqueGeneratedPropertyDescriptorObject should be used as direct base for PropertyDescriptorObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPropertyDescriptorObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPropertyDescriptorObject(Address ptr);
};

