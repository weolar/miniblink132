class TemplateInfo;
class FunctionTemplateInfo;
class FunctionTemplateRareData;
class ObjectTemplateInfo;
class DictionaryTemplateInfo;
// Alias for IsTemplateInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsTemplateInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedTemplateInfo : public P {
  static_assert(
      std::is_same<TemplateInfo, D>::value,
      "Use this class as direct base for TemplateInfo.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedTemplateInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedTemplateInfo<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=7&c=3
  inline int serial_number() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=7&c=3
  inline void set_serial_number(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=8&c=3
  inline int number_of_properties() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=8&c=3
  inline void set_number_of_properties(int value);

  // Torque type: (class Undefined | class ArrayList)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=9&c=3
  inline Tagged<Union<ArrayList, Undefined>> property_list() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=9&c=3
  inline Tagged<Union<ArrayList, Undefined>> property_list(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=9&c=3
  inline void set_property_list(Tagged<Union<ArrayList, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class ArrayList)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=10&c=3
  inline Tagged<Union<ArrayList, Undefined>> property_accessors() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=10&c=3
  inline Tagged<Union<ArrayList, Undefined>> property_accessors(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=10&c=3
  inline void set_property_accessors(Tagged<Union<ArrayList, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=5&c=1
  V8_EXPORT_PRIVATE void TemplateInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=7&c=3
  static constexpr int kSerialNumberOffset = P::kHeaderSize;
  static constexpr int kSerialNumberOffsetEnd = kSerialNumberOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=8&c=3
  static constexpr int kNumberOfPropertiesOffset = kSerialNumberOffsetEnd + 1;
  static constexpr int kNumberOfPropertiesOffsetEnd = kNumberOfPropertiesOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=9&c=3
  static constexpr int kPropertyListOffset = kNumberOfPropertiesOffsetEnd + 1;
  static constexpr int kPropertyListOffsetEnd = kPropertyListOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=10&c=3
  static constexpr int kPropertyAccessorsOffset = kPropertyListOffsetEnd + 1;
  static constexpr int kPropertyAccessorsOffsetEnd = kPropertyAccessorsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPropertyAccessorsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPropertyAccessorsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPropertyAccessorsOffsetEnd + 1;
  static constexpr int kHeaderSize = kPropertyAccessorsOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedTemplateInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedTemplateInfo, DAlias>::value,
        "class TorqueGeneratedTemplateInfo should be used as direct base for TemplateInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedTemplateInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedTemplateInfo(Address ptr);
};

// Alias for IsFunctionTemplateInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=44&c=1
V8_EXPORT_PRIVATE bool IsFunctionTemplateInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=44&c=1
template <class D, class P>
class TorqueGeneratedFunctionTemplateInfo : public P {
  static_assert(
      std::is_same<FunctionTemplateInfo, D>::value,
      "Use this class as direct base for FunctionTemplateInfo.");
  static_assert(
      std::is_same<TemplateInfo, P>::value,
      "Pass in TemplateInfo as second template parameter for TorqueGeneratedFunctionTemplateInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedFunctionTemplateInfo<D,P>;

  // Torque type: (class Undefined | class String)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=46&c=3
  inline Tagged<Union<String, Undefined>> class_name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=46&c=3
  inline Tagged<Union<String, Undefined>> class_name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=46&c=3
  inline void set_class_name(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class String)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=50&c=3
  inline Tagged<Union<String, Undefined>> interface_name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=50&c=3
  inline Tagged<Union<String, Undefined>> interface_name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=50&c=3
  inline void set_interface_name(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class FunctionTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=55&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> signature() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=55&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> signature(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=55&c=3
  inline void set_signature(Tagged<Union<FunctionTemplateInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class FunctionTemplateRareData)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=61&c=3
  inline Tagged<Union<FunctionTemplateRareData, Undefined>> rare_data(AcquireLoadTag) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=61&c=3
  inline Tagged<Union<FunctionTemplateRareData, Undefined>> rare_data(PtrComprCageBase cage_base, AcquireLoadTag) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=61&c=3
  inline void set_rare_data(Tagged<Union<FunctionTemplateRareData, Undefined>> value, ReleaseStoreTag, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class SharedFunctionInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=62&c=3
  inline Tagged<Union<SharedFunctionInfo, Undefined>> shared_function_info() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=62&c=3
  inline Tagged<Union<SharedFunctionInfo, Undefined>> shared_function_info(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=62&c=3
  inline void set_shared_function_info(Tagged<Union<SharedFunctionInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=66&c=3
  inline Tagged<Object> cached_property_name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=66&c=3
  inline Tagged<Object> cached_property_name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=66&c=3
  inline void set_cached_property_name(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=73&c=36
  inline Tagged<Object> callback_data(AcquireLoadTag) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=73&c=36
  inline Tagged<Object> callback_data(PtrComprCageBase cage_base, AcquireLoadTag) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=73&c=36
  inline void set_callback_data(Tagged<Object> value, ReleaseStoreTag, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=76&c=3
  inline uint32_t flag() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=76&c=3
  inline void set_flag(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=78&c=3
  inline int16_t length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=78&c=3
  inline void set_length(int16_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=81&c=3
  inline InstanceType instance_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=81&c=3
  inline void set_instance_type(InstanceType value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=86&c=3
  inline uint32_t exception_context() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=86&c=3
  inline void set_exception_context(uint32_t value);

  DECL_PRINTER(FunctionTemplateInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=44&c=1
  V8_EXPORT_PRIVATE void FunctionTemplateInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=46&c=3
  static constexpr int kClassNameOffset = P::kHeaderSize;
  static constexpr int kClassNameOffsetEnd = kClassNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=50&c=3
  static constexpr int kInterfaceNameOffset = kClassNameOffsetEnd + 1;
  static constexpr int kInterfaceNameOffsetEnd = kInterfaceNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=55&c=3
  static constexpr int kSignatureOffset = kInterfaceNameOffsetEnd + 1;
  static constexpr int kSignatureOffsetEnd = kSignatureOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=61&c=3
  static constexpr int kRareDataOffset = kSignatureOffsetEnd + 1;
  static constexpr int kRareDataOffsetEnd = kRareDataOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=62&c=3
  static constexpr int kSharedFunctionInfoOffset = kRareDataOffsetEnd + 1;
  static constexpr int kSharedFunctionInfoOffsetEnd = kSharedFunctionInfoOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=66&c=3
  static constexpr int kCachedPropertyNameOffset = kSharedFunctionInfoOffsetEnd + 1;
  static constexpr int kCachedPropertyNameOffsetEnd = kCachedPropertyNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=73&c=36
  static constexpr int kCallbackDataOffset = kCachedPropertyNameOffsetEnd + 1;
  static constexpr int kCallbackDataOffsetEnd = kCallbackDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCallbackDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=76&c=3
  static constexpr int kFlagOffset = kCallbackDataOffsetEnd + 1;
  static constexpr int kFlagOffsetEnd = kFlagOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=78&c=3
  static constexpr int kLengthOffset = kFlagOffsetEnd + 1;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kUInt16Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=81&c=3
  static constexpr int kInstanceTypeOffset = kLengthOffsetEnd + 1;
  static constexpr int kInstanceTypeOffsetEnd = kInstanceTypeOffset + kUInt16Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=86&c=3
  static constexpr int kExceptionContextOffset = kInstanceTypeOffsetEnd + 1;
  static constexpr int kExceptionContextOffsetEnd = kExceptionContextOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=89&c=31
  static constexpr int kOptionalPaddingOffset = kExceptionContextOffsetEnd + 1;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=95&c=3
  static constexpr int kMaybeRedirectedCallbackOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kMaybeRedirectedCallbackOffsetEnd = kMaybeRedirectedCallbackOffset + kExternalPointerSlotSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kMaybeRedirectedCallbackOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kMaybeRedirectedCallbackOffsetEnd + 1;
  static constexpr int kHeaderSize = kMaybeRedirectedCallbackOffsetEnd + 1;
  static constexpr int kSize = kMaybeRedirectedCallbackOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=44&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 68);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=44&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedFunctionTemplateInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedFunctionTemplateInfo, DAlias>::value,
        "class TorqueGeneratedFunctionTemplateInfo should be used as direct base for FunctionTemplateInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedFunctionTemplateInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedFunctionTemplateInfo(Address ptr);
};

// Alias for IsFunctionTemplateRareData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=13&c=1
V8_EXPORT_PRIVATE bool IsFunctionTemplateRareData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=13&c=1
template <class D, class P>
class TorqueGeneratedFunctionTemplateRareData : public P {
  static_assert(
      std::is_same<FunctionTemplateRareData, D>::value,
      "Use this class as direct base for FunctionTemplateRareData.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedFunctionTemplateRareData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedFunctionTemplateRareData<D,P>;

  // Torque type: (class Undefined | class ObjectTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=15&c=3
  inline Tagged<Union<ObjectTemplateInfo, Undefined>> prototype_template() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=15&c=3
  inline Tagged<Union<ObjectTemplateInfo, Undefined>> prototype_template(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=15&c=3
  inline void set_prototype_template(Tagged<Union<ObjectTemplateInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class FunctionTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=16&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> prototype_provider_template() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=16&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> prototype_provider_template(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=16&c=3
  inline void set_prototype_provider_template(Tagged<Union<FunctionTemplateInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class FunctionTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=17&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> parent_template() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=17&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> parent_template(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=17&c=3
  inline void set_parent_template(Tagged<Union<FunctionTemplateInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class InterceptorInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=18&c=3
  inline Tagged<Union<InterceptorInfo, Undefined>> named_property_handler() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=18&c=3
  inline Tagged<Union<InterceptorInfo, Undefined>> named_property_handler(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=18&c=3
  inline void set_named_property_handler(Tagged<Union<InterceptorInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class InterceptorInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=19&c=3
  inline Tagged<Union<InterceptorInfo, Undefined>> indexed_property_handler() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=19&c=3
  inline Tagged<Union<InterceptorInfo, Undefined>> indexed_property_handler(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=19&c=3
  inline void set_indexed_property_handler(Tagged<Union<InterceptorInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class ObjectTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=20&c=3
  inline Tagged<Union<ObjectTemplateInfo, Undefined>> instance_template() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=20&c=3
  inline Tagged<Union<ObjectTemplateInfo, Undefined>> instance_template(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=20&c=3
  inline void set_instance_template(Tagged<Union<ObjectTemplateInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class FunctionTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=21&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> instance_call_handler() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=21&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> instance_call_handler(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=21&c=3
  inline void set_instance_call_handler(Tagged<Union<FunctionTemplateInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class AccessCheckInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=22&c=3
  inline Tagged<Union<AccessCheckInfo, Undefined>> access_check_info() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=22&c=3
  inline Tagged<Union<AccessCheckInfo, Undefined>> access_check_info(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=22&c=3
  inline void set_access_check_info(Tagged<Union<AccessCheckInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=23&c=3
  inline Tagged<FixedArray> c_function_overloads() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=23&c=3
  inline Tagged<FixedArray> c_function_overloads(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=23&c=3
  inline void set_c_function_overloads(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(FunctionTemplateRareData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=13&c=1
  V8_EXPORT_PRIVATE void FunctionTemplateRareDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=15&c=3
  static constexpr int kPrototypeTemplateOffset = P::kHeaderSize;
  static constexpr int kPrototypeTemplateOffsetEnd = kPrototypeTemplateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=16&c=3
  static constexpr int kPrototypeProviderTemplateOffset = kPrototypeTemplateOffsetEnd + 1;
  static constexpr int kPrototypeProviderTemplateOffsetEnd = kPrototypeProviderTemplateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=17&c=3
  static constexpr int kParentTemplateOffset = kPrototypeProviderTemplateOffsetEnd + 1;
  static constexpr int kParentTemplateOffsetEnd = kParentTemplateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=18&c=3
  static constexpr int kNamedPropertyHandlerOffset = kParentTemplateOffsetEnd + 1;
  static constexpr int kNamedPropertyHandlerOffsetEnd = kNamedPropertyHandlerOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=19&c=3
  static constexpr int kIndexedPropertyHandlerOffset = kNamedPropertyHandlerOffsetEnd + 1;
  static constexpr int kIndexedPropertyHandlerOffsetEnd = kIndexedPropertyHandlerOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=20&c=3
  static constexpr int kInstanceTemplateOffset = kIndexedPropertyHandlerOffsetEnd + 1;
  static constexpr int kInstanceTemplateOffsetEnd = kInstanceTemplateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=21&c=3
  static constexpr int kInstanceCallHandlerOffset = kInstanceTemplateOffsetEnd + 1;
  static constexpr int kInstanceCallHandlerOffsetEnd = kInstanceCallHandlerOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=22&c=3
  static constexpr int kAccessCheckInfoOffset = kInstanceCallHandlerOffsetEnd + 1;
  static constexpr int kAccessCheckInfoOffsetEnd = kAccessCheckInfoOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=23&c=3
  static constexpr int kCFunctionOverloadsOffset = kAccessCheckInfoOffsetEnd + 1;
  static constexpr int kCFunctionOverloadsOffsetEnd = kCFunctionOverloadsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCFunctionOverloadsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCFunctionOverloadsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCFunctionOverloadsOffsetEnd + 1;
  static constexpr int kHeaderSize = kCFunctionOverloadsOffsetEnd + 1;
  static constexpr int kSize = kCFunctionOverloadsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=13&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 40);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=13&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedFunctionTemplateRareData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedFunctionTemplateRareData, DAlias>::value,
        "class TorqueGeneratedFunctionTemplateRareData should be used as direct base for FunctionTemplateRareData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedFunctionTemplateRareData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedFunctionTemplateRareData(Address ptr);
};

// Alias for IsObjectTemplateInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=104&c=1
V8_EXPORT_PRIVATE bool IsObjectTemplateInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=104&c=1
template <class D, class P>
class TorqueGeneratedObjectTemplateInfo : public P {
  static_assert(
      std::is_same<ObjectTemplateInfo, D>::value,
      "Use this class as direct base for ObjectTemplateInfo.");
  static_assert(
      std::is_same<TemplateInfo, P>::value,
      "Pass in TemplateInfo as second template parameter for TorqueGeneratedObjectTemplateInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedObjectTemplateInfo<D,P>;

  // Torque type: (class Undefined | class FunctionTemplateInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=106&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> constructor() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=106&c=3
  inline Tagged<Union<FunctionTemplateInfo, Undefined>> constructor(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=106&c=3
  inline void set_constructor(Tagged<Union<FunctionTemplateInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=107&c=3
  inline int data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=107&c=3
  inline void set_data(int value);

  DECL_PRINTER(ObjectTemplateInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=104&c=1
  V8_EXPORT_PRIVATE void ObjectTemplateInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=106&c=3
  static constexpr int kConstructorOffset = P::kHeaderSize;
  static constexpr int kConstructorOffsetEnd = kConstructorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=107&c=3
  static constexpr int kDataOffset = kConstructorOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kDataOffsetEnd + 1;
  static constexpr int kSize = kDataOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=104&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 28);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=104&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedObjectTemplateInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedObjectTemplateInfo, DAlias>::value,
        "class TorqueGeneratedObjectTemplateInfo should be used as direct base for ObjectTemplateInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedObjectTemplateInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedObjectTemplateInfo(Address ptr);
};

// Alias for IsDictionaryTemplateInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=110&c=1
V8_EXPORT_PRIVATE bool IsDictionaryTemplateInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=110&c=1
template <class D, class P>
class TorqueGeneratedDictionaryTemplateInfo : public P {
  static_assert(
      std::is_same<DictionaryTemplateInfo, D>::value,
      "Use this class as direct base for DictionaryTemplateInfo.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedDictionaryTemplateInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedDictionaryTemplateInfo<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=112&c=3
  inline Tagged<FixedArray> property_names() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=112&c=3
  inline Tagged<FixedArray> property_names(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=112&c=3
  inline void set_property_names(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=113&c=3
  inline int serial_number() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=113&c=3
  inline void set_serial_number(int value);

  DECL_PRINTER(DictionaryTemplateInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=110&c=1
  V8_EXPORT_PRIVATE void DictionaryTemplateInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=112&c=3
  static constexpr int kPropertyNamesOffset = P::kHeaderSize;
  static constexpr int kPropertyNamesOffsetEnd = kPropertyNamesOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=113&c=3
  static constexpr int kSerialNumberOffset = kPropertyNamesOffsetEnd + 1;
  static constexpr int kSerialNumberOffsetEnd = kSerialNumberOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSerialNumberOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSerialNumberOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSerialNumberOffsetEnd + 1;
  static constexpr int kHeaderSize = kSerialNumberOffsetEnd + 1;
  static constexpr int kSize = kSerialNumberOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=110&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=110&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedDictionaryTemplateInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedDictionaryTemplateInfo, DAlias>::value,
        "class TorqueGeneratedDictionaryTemplateInfo should be used as direct base for DictionaryTemplateInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedDictionaryTemplateInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedDictionaryTemplateInfo(Address ptr);
};

