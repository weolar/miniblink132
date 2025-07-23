class JSReceiver;
class JSObject;
class JSObjectWithEmbedderSlots;
class JSAPIObjectWithEmbedderSlots;
class JSCustomElementsObject;
class JSSpecialObject;
class JSExternalObject;
class JSGlobalProxy;
class JSGlobalObject;
class JSPrimitiveWrapper;
class JSMessageObject;
class JSDate;
class JSAsyncFromSyncIterator;
class JSStringIterator;
class JSValidIteratorWrapper;
// Alias for IsJSReceiver() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=6&c=1
V8_EXPORT_PRIVATE bool IsJSReceiver_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=6&c=1
template <class D, class P>
class TorqueGeneratedJSReceiver : public P {
  static_assert(
      std::is_same<JSReceiver, D>::value,
      "Use this class as direct base for JSReceiver.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedJSReceiver.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSReceiver<D,P>;

  // Torque type: (Smi | class FixedArrayBase | class PropertyArray | class SwissNameDictionary)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=9&c=3
  inline Tagged<Union<FixedArrayBase, PropertyArray, Smi, SwissNameDictionary>> properties_or_hash() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=9&c=3
  inline Tagged<Union<FixedArrayBase, PropertyArray, Smi, SwissNameDictionary>> properties_or_hash(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=9&c=3
  inline void set_properties_or_hash(Tagged<Union<FixedArrayBase, PropertyArray, Smi, SwissNameDictionary>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=6&c=1
  V8_EXPORT_PRIVATE void JSReceiverVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=9&c=3
  static constexpr int kPropertiesOrHashOffset = P::kHeaderSize;
  static constexpr int kPropertiesOrHashOffsetEnd = kPropertiesOrHashOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPropertiesOrHashOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPropertiesOrHashOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPropertiesOrHashOffsetEnd + 1;
  static constexpr int kHeaderSize = kPropertiesOrHashOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSReceiver() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSReceiver, DAlias>::value,
        "class TorqueGeneratedJSReceiver should be used as direct base for JSReceiver.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSReceiver(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSReceiver(Address ptr);
};

// Alias for IsJSObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=14&c=1
V8_EXPORT_PRIVATE bool IsJSObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=14&c=1
template <class D, class P>
class TorqueGeneratedJSObject : public P {
  static_assert(
      std::is_same<JSObject, D>::value,
      "Use this class as direct base for JSObject.");
  static_assert(
      std::is_same<JSReceiver, P>::value,
      "Pass in JSReceiver as second template parameter for TorqueGeneratedJSObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=33&c=3
  inline Tagged<FixedArrayBase> elements() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=33&c=3
  inline Tagged<FixedArrayBase> elements(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=33&c=3
  inline void set_elements(Tagged<FixedArrayBase> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=14&c=1
  V8_EXPORT_PRIVATE void JSObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=33&c=3
  static constexpr int kElementsOffset = P::kHeaderSize;
  static constexpr int kElementsOffsetEnd = kElementsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kHeaderSize = kElementsOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSObject, DAlias>::value,
        "class TorqueGeneratedJSObject should be used as direct base for JSObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSObject(Address ptr);
};

// Alias for IsJSObjectWithEmbedderSlots() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=50&c=1
V8_EXPORT_PRIVATE bool IsJSObjectWithEmbedderSlots_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=50&c=1
template <class D, class P>
class TorqueGeneratedJSObjectWithEmbedderSlots : public P {
  static_assert(
      std::is_same<JSObjectWithEmbedderSlots, D>::value,
      "Use this class as direct base for JSObjectWithEmbedderSlots.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSObjectWithEmbedderSlots.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSObjectWithEmbedderSlots<D,P>;

  DECL_PRINTER(JSObjectWithEmbedderSlots)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=50&c=1
  V8_EXPORT_PRIVATE void JSObjectWithEmbedderSlotsVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSObjectWithEmbedderSlots() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSObjectWithEmbedderSlots, DAlias>::value,
        "class TorqueGeneratedJSObjectWithEmbedderSlots should be used as direct base for JSObjectWithEmbedderSlots.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSObjectWithEmbedderSlots(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSObjectWithEmbedderSlots(Address ptr);
};

// Alias for IsJSAPIObjectWithEmbedderSlots() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=54&c=1
V8_EXPORT_PRIVATE bool IsJSAPIObjectWithEmbedderSlots_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=54&c=1
template <class D, class P>
class TorqueGeneratedJSAPIObjectWithEmbedderSlots : public P {
  static_assert(
      std::is_same<JSAPIObjectWithEmbedderSlots, D>::value,
      "Use this class as direct base for JSAPIObjectWithEmbedderSlots.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSAPIObjectWithEmbedderSlots.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSAPIObjectWithEmbedderSlots<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=56&c=3
  inline CppHeapPointer_t cpp_heap_wrappable() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=56&c=3
  inline void set_cpp_heap_wrappable(CppHeapPointer_t value);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=54&c=1
  V8_EXPORT_PRIVATE void JSAPIObjectWithEmbedderSlotsVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=56&c=3
  static constexpr int kCppHeapWrappableOffset = P::kHeaderSize;
  static constexpr int kCppHeapWrappableOffsetEnd = kCppHeapWrappableOffset + kCppHeapPointerSlotSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kCppHeapWrappableOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCppHeapWrappableOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kCppHeapWrappableOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kCppHeapWrappableOffsetEnd + 1;
  static constexpr int kHeaderSize = kCppHeapWrappableOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSAPIObjectWithEmbedderSlots() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSAPIObjectWithEmbedderSlots, DAlias>::value,
        "class TorqueGeneratedJSAPIObjectWithEmbedderSlots should be used as direct base for JSAPIObjectWithEmbedderSlots.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSAPIObjectWithEmbedderSlots(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSAPIObjectWithEmbedderSlots(Address ptr);
};

// Alias for IsJSCustomElementsObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=59&c=1
V8_EXPORT_PRIVATE bool IsJSCustomElementsObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=59&c=1
template <class D, class P>
class TorqueGeneratedJSCustomElementsObject : public P {
  static_assert(
      std::is_same<JSCustomElementsObject, D>::value,
      "Use this class as direct base for JSCustomElementsObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSCustomElementsObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSCustomElementsObject<D,P>;

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=59&c=1
  V8_EXPORT_PRIVATE void JSCustomElementsObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSCustomElementsObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSCustomElementsObject, DAlias>::value,
        "class TorqueGeneratedJSCustomElementsObject should be used as direct base for JSCustomElementsObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSCustomElementsObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSCustomElementsObject(Address ptr);
};

// Alias for IsJSSpecialObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=66&c=1
V8_EXPORT_PRIVATE bool IsJSSpecialObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=66&c=1
template <class D, class P>
class TorqueGeneratedJSSpecialObject : public P {
  static_assert(
      std::is_same<JSSpecialObject, D>::value,
      "Use this class as direct base for JSSpecialObject.");
  static_assert(
      std::is_same<JSCustomElementsObject, P>::value,
      "Pass in JSCustomElementsObject as second template parameter for TorqueGeneratedJSSpecialObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSpecialObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=70&c=3
  inline CppHeapPointer_t cpp_heap_wrappable() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=70&c=3
  inline void set_cpp_heap_wrappable(CppHeapPointer_t value);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=66&c=1
  V8_EXPORT_PRIVATE void JSSpecialObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=70&c=3
  static constexpr int kCppHeapWrappableOffset = P::kHeaderSize;
  static constexpr int kCppHeapWrappableOffsetEnd = kCppHeapWrappableOffset + kCppHeapPointerSlotSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kCppHeapWrappableOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCppHeapWrappableOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kCppHeapWrappableOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kCppHeapWrappableOffsetEnd + 1;
  static constexpr int kHeaderSize = kCppHeapWrappableOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSpecialObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSpecialObject, DAlias>::value,
        "class TorqueGeneratedJSSpecialObject should be used as direct base for JSSpecialObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSpecialObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSpecialObject(Address ptr);
};

// Alias for IsJSExternalObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=43&c=1
V8_EXPORT_PRIVATE bool IsJSExternalObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=43&c=1
template <class D, class P>
class TorqueGeneratedJSExternalObject : public P {
  static_assert(
      std::is_same<JSExternalObject, D>::value,
      "Use this class as direct base for JSExternalObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSExternalObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSExternalObject<D,P>;

  DECL_PRINTER(JSExternalObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=43&c=1
  V8_EXPORT_PRIVATE void JSExternalObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=44&c=3
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kExternalPointerSlotSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kHeaderSize = kValueOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSExternalObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSExternalObject, DAlias>::value,
        "class TorqueGeneratedJSExternalObject should be used as direct base for JSExternalObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSExternalObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSExternalObject(Address ptr);
};

// Alias for IsJSGlobalProxy() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=116&c=1
V8_EXPORT_PRIVATE bool IsJSGlobalProxy_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=116&c=1
template <class D, class P>
class TorqueGeneratedJSGlobalProxy : public P {
  static_assert(
      std::is_same<JSGlobalProxy, D>::value,
      "Use this class as direct base for JSGlobalProxy.");
  static_assert(
      std::is_same<JSSpecialObject, P>::value,
      "Pass in JSSpecialObject as second template parameter for TorqueGeneratedJSGlobalProxy.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSGlobalProxy<D,P>;

  DECL_PRINTER(JSGlobalProxy)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=116&c=1
  V8_EXPORT_PRIVATE void JSGlobalProxyVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSGlobalProxy() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSGlobalProxy, DAlias>::value,
        "class TorqueGeneratedJSGlobalProxy should be used as direct base for JSGlobalProxy.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSGlobalProxy(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSGlobalProxy(Address ptr);
};

// Alias for IsJSGlobalObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=118&c=1
V8_EXPORT_PRIVATE bool IsJSGlobalObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=118&c=1
template <class D, class P>
class TorqueGeneratedJSGlobalObject : public P {
  static_assert(
      std::is_same<JSGlobalObject, D>::value,
      "Use this class as direct base for JSGlobalObject.");
  static_assert(
      std::is_same<JSSpecialObject, P>::value,
      "Pass in JSSpecialObject as second template parameter for TorqueGeneratedJSGlobalObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSGlobalObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=120&c=3
  inline Tagged<JSGlobalProxy> global_proxy() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=120&c=3
  inline Tagged<JSGlobalProxy> global_proxy(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=120&c=3
  inline void set_global_proxy(Tagged<JSGlobalProxy> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSGlobalObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=118&c=1
  V8_EXPORT_PRIVATE void JSGlobalObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=120&c=3
  static constexpr int kGlobalProxyOffset = P::kHeaderSize;
  static constexpr int kGlobalProxyOffsetEnd = kGlobalProxyOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kGlobalProxyOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kGlobalProxyOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kGlobalProxyOffsetEnd + 1;
  static constexpr int kHeaderSize = kGlobalProxyOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSGlobalObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSGlobalObject, DAlias>::value,
        "class TorqueGeneratedJSGlobalObject should be used as direct base for JSGlobalObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSGlobalObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSGlobalObject(Address ptr);
};

// Alias for IsJSPrimitiveWrapper() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=123&c=1
V8_EXPORT_PRIVATE bool IsJSPrimitiveWrapper_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=123&c=1
template <class D, class P>
class TorqueGeneratedJSPrimitiveWrapper : public P {
  static_assert(
      std::is_same<JSPrimitiveWrapper, D>::value,
      "Use this class as direct base for JSPrimitiveWrapper.");
  static_assert(
      std::is_same<JSCustomElementsObject, P>::value,
      "Pass in JSCustomElementsObject as second template parameter for TorqueGeneratedJSPrimitiveWrapper.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSPrimitiveWrapper<D,P>;

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=124&c=3
  inline Tagged<JSAny> value() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=124&c=3
  inline Tagged<JSAny> value(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=124&c=3
  inline void set_value(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSPrimitiveWrapper)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=123&c=1
  V8_EXPORT_PRIVATE void JSPrimitiveWrapperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=124&c=3
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kHeaderSize = kValueOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSPrimitiveWrapper() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSPrimitiveWrapper, DAlias>::value,
        "class TorqueGeneratedJSPrimitiveWrapper should be used as direct base for JSPrimitiveWrapper.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSPrimitiveWrapper(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSPrimitiveWrapper(Address ptr);
};

// Alias for IsJSMessageObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=127&c=1
V8_EXPORT_PRIVATE bool IsJSMessageObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=127&c=1
template <class D, class P>
class TorqueGeneratedJSMessageObject : public P {
  static_assert(
      std::is_same<JSMessageObject, D>::value,
      "Use this class as direct base for JSMessageObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSMessageObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSMessageObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=129&c=3
  inline int message_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=129&c=3
  inline void set_message_type(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=131&c=3
  inline Tagged<Object> argument() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=131&c=3
  inline Tagged<Object> argument(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=131&c=3
  inline void set_argument(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=133&c=3
  inline Tagged<Script> script() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=133&c=3
  inline Tagged<Script> script(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=133&c=3
  inline void set_script(Tagged<Script> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (TheHole | class StackTraceInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=135&c=3
  inline Tagged<Union<Hole, StackTraceInfo>> stack_trace() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=135&c=3
  inline Tagged<Union<Hole, StackTraceInfo>> stack_trace(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=135&c=3
  inline void set_stack_trace(Tagged<Union<Hole, StackTraceInfo>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | class SharedFunctionInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=136&c=3
  inline Tagged<Union<SharedFunctionInfo, Smi>> shared_info() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=136&c=3
  inline Tagged<Union<SharedFunctionInfo, Smi>> shared_info(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=136&c=3
  inline void set_shared_info(Tagged<Union<SharedFunctionInfo, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=140&c=3
  inline int bytecode_offset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=140&c=3
  inline void set_bytecode_offset(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=141&c=3
  inline int start_position() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=141&c=3
  inline void set_start_position(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=142&c=3
  inline int end_position() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=142&c=3
  inline void set_end_position(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=143&c=3
  inline int error_level() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=143&c=3
  inline void set_error_level(int value);

  DECL_PRINTER(JSMessageObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=127&c=1
  V8_EXPORT_PRIVATE void JSMessageObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=129&c=3
  static constexpr int kMessageTypeOffset = P::kHeaderSize;
  static constexpr int kMessageTypeOffsetEnd = kMessageTypeOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=131&c=3
  static constexpr int kArgumentOffset = kMessageTypeOffsetEnd + 1;
  static constexpr int kArgumentOffsetEnd = kArgumentOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=133&c=3
  static constexpr int kScriptOffset = kArgumentOffsetEnd + 1;
  static constexpr int kScriptOffsetEnd = kScriptOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=135&c=3
  static constexpr int kStackTraceOffset = kScriptOffsetEnd + 1;
  static constexpr int kStackTraceOffsetEnd = kStackTraceOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=136&c=3
  static constexpr int kSharedInfoOffset = kStackTraceOffsetEnd + 1;
  static constexpr int kSharedInfoOffsetEnd = kSharedInfoOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=140&c=3
  static constexpr int kBytecodeOffsetOffset = kSharedInfoOffsetEnd + 1;
  static constexpr int kBytecodeOffsetOffsetEnd = kBytecodeOffsetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=141&c=3
  static constexpr int kStartPositionOffset = kBytecodeOffsetOffsetEnd + 1;
  static constexpr int kStartPositionOffsetEnd = kStartPositionOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=142&c=3
  static constexpr int kEndPositionOffset = kStartPositionOffsetEnd + 1;
  static constexpr int kEndPositionOffsetEnd = kEndPositionOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=143&c=3
  static constexpr int kErrorLevelOffset = kEndPositionOffsetEnd + 1;
  static constexpr int kErrorLevelOffsetEnd = kErrorLevelOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kErrorLevelOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kErrorLevelOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kErrorLevelOffsetEnd + 1;
  static constexpr int kHeaderSize = kErrorLevelOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSMessageObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSMessageObject, DAlias>::value,
        "class TorqueGeneratedJSMessageObject should be used as direct base for JSMessageObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSMessageObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSMessageObject(Address ptr);
};

// Alias for IsJSDate() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=146&c=1
V8_EXPORT_PRIVATE bool IsJSDate_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=146&c=1
template <class D, class P>
class TorqueGeneratedJSDate : public P {
  static_assert(
      std::is_same<JSDate, D>::value,
      "Use this class as direct base for JSDate.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSDate.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSDate<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=150&c=3
  inline double value() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=150&c=3
  inline void set_value(double value);

  // Torque type: (class Undefined | Smi | NaN)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=153&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> year() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=153&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> year(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=153&c=3
  inline void set_year(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Smi | NaN)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=154&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> month() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=154&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> month(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=154&c=3
  inline void set_month(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Smi | NaN)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=155&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> day() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=155&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> day(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=155&c=3
  inline void set_day(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Smi | NaN)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=156&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> weekday() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=156&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> weekday(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=156&c=3
  inline void set_weekday(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Smi | NaN)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=157&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> hour() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=157&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> hour(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=157&c=3
  inline void set_hour(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Smi | NaN)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=158&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> min() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=158&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> min(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=158&c=3
  inline void set_min(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Smi | NaN)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=159&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> sec() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=159&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> sec(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=159&c=3
  inline void set_sec(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | Smi | NaN)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=163&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> cache_stamp() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=163&c=3
  inline Tagged<Union<HeapNumber, Smi, Undefined>> cache_stamp(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=163&c=3
  inline void set_cache_stamp(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSDate)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=146&c=1
  V8_EXPORT_PRIVATE void JSDateVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=150&c=3
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kDoubleSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kValueOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=153&c=3
  static constexpr int kYearOffset = kValueOffsetEnd + 1;
  static constexpr int kYearOffsetEnd = kYearOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=154&c=3
  static constexpr int kMonthOffset = kYearOffsetEnd + 1;
  static constexpr int kMonthOffsetEnd = kMonthOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=155&c=3
  static constexpr int kDayOffset = kMonthOffsetEnd + 1;
  static constexpr int kDayOffsetEnd = kDayOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=156&c=3
  static constexpr int kWeekdayOffset = kDayOffsetEnd + 1;
  static constexpr int kWeekdayOffsetEnd = kWeekdayOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=157&c=3
  static constexpr int kHourOffset = kWeekdayOffsetEnd + 1;
  static constexpr int kHourOffsetEnd = kHourOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=158&c=3
  static constexpr int kMinOffset = kHourOffsetEnd + 1;
  static constexpr int kMinOffsetEnd = kMinOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=159&c=3
  static constexpr int kSecOffset = kMinOffsetEnd + 1;
  static constexpr int kSecOffsetEnd = kSecOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=163&c=3
  static constexpr int kCacheStampOffset = kSecOffsetEnd + 1;
  static constexpr int kCacheStampOffsetEnd = kCacheStampOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCacheStampOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCacheStampOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCacheStampOffsetEnd + 1;
  static constexpr int kHeaderSize = kCacheStampOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSDate() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSDate, DAlias>::value,
        "class TorqueGeneratedJSDate should be used as direct base for JSDate.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSDate(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSDate(Address ptr);
};

// Alias for IsJSAsyncFromSyncIterator() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=166&c=1
V8_EXPORT_PRIVATE bool IsJSAsyncFromSyncIterator_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=166&c=1
template <class D, class P>
class TorqueGeneratedJSAsyncFromSyncIterator : public P {
  static_assert(
      std::is_same<JSAsyncFromSyncIterator, D>::value,
      "Use this class as direct base for JSAsyncFromSyncIterator.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSAsyncFromSyncIterator.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSAsyncFromSyncIterator<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=167&c=3
  inline Tagged<JSReceiver> sync_iterator() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=167&c=3
  inline Tagged<JSReceiver> sync_iterator(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=167&c=3
  inline void set_sync_iterator(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=170&c=3
  inline Tagged<Object> next() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=170&c=3
  inline Tagged<Object> next(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=170&c=3
  inline void set_next(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSAsyncFromSyncIterator)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=166&c=1
  V8_EXPORT_PRIVATE void JSAsyncFromSyncIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=167&c=3
  static constexpr int kSyncIteratorOffset = P::kHeaderSize;
  static constexpr int kSyncIteratorOffsetEnd = kSyncIteratorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=170&c=3
  static constexpr int kNextOffset = kSyncIteratorOffsetEnd + 1;
  static constexpr int kNextOffsetEnd = kNextOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kNextOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kNextOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kNextOffsetEnd + 1;
  static constexpr int kHeaderSize = kNextOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSAsyncFromSyncIterator() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSAsyncFromSyncIterator, DAlias>::value,
        "class TorqueGeneratedJSAsyncFromSyncIterator should be used as direct base for JSAsyncFromSyncIterator.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSAsyncFromSyncIterator(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSAsyncFromSyncIterator(Address ptr);
};

// Alias for IsJSStringIterator() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=173&c=1
V8_EXPORT_PRIVATE bool IsJSStringIterator_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=173&c=1
template <class D, class P>
class TorqueGeneratedJSStringIterator : public P {
  static_assert(
      std::is_same<JSStringIterator, D>::value,
      "Use this class as direct base for JSStringIterator.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSStringIterator.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSStringIterator<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=175&c=3
  inline Tagged<String> string() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=175&c=3
  inline Tagged<String> string(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=175&c=3
  inline void set_string(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=177&c=3
  inline int index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=177&c=3
  inline void set_index(int value);

  DECL_PRINTER(JSStringIterator)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=173&c=1
  V8_EXPORT_PRIVATE void JSStringIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=175&c=3
  static constexpr int kStringOffset = P::kHeaderSize;
  static constexpr int kStringOffsetEnd = kStringOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=177&c=3
  static constexpr int kIndexOffset = kStringOffsetEnd + 1;
  static constexpr int kIndexOffsetEnd = kIndexOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kHeaderSize = kIndexOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSStringIterator() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSStringIterator, DAlias>::value,
        "class TorqueGeneratedJSStringIterator should be used as direct base for JSStringIterator.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSStringIterator(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSStringIterator(Address ptr);
};

// Alias for IsJSValidIteratorWrapper() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=182&c=1
V8_EXPORT_PRIVATE bool IsJSValidIteratorWrapper_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=182&c=1
template <class D, class P>
class TorqueGeneratedJSValidIteratorWrapper : public P {
  static_assert(
      std::is_same<JSValidIteratorWrapper, D>::value,
      "Use this class as direct base for JSValidIteratorWrapper.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSValidIteratorWrapper.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSValidIteratorWrapper<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
  inline Tagged<JSReceiver> underlying_object() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
  inline Tagged<JSReceiver> underlying_object(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
  inline void set_underlying_object(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
  inline Tagged<JSAny> underlying_next() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
  inline Tagged<JSAny> underlying_next(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
  inline void set_underlying_next(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSValidIteratorWrapper)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=182&c=1
  V8_EXPORT_PRIVATE void JSValidIteratorWrapperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
  static constexpr int kUnderlyingOffset = P::kHeaderSize;
  static constexpr int kUnderlyingOffsetEnd = kUnderlyingOffset + 8 - 1;
  static constexpr int kEndOfStrongFieldsOffset = kUnderlyingOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kUnderlyingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kUnderlyingOffsetEnd + 1;
  static constexpr int kHeaderSize = kUnderlyingOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSValidIteratorWrapper() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSValidIteratorWrapper, DAlias>::value,
        "class TorqueGeneratedJSValidIteratorWrapper should be used as direct base for JSValidIteratorWrapper.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSValidIteratorWrapper(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSValidIteratorWrapper(Address ptr);
};

