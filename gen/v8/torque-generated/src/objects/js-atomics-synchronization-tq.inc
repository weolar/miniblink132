class JSSynchronizationPrimitive;
class JSAtomicsMutex;
class JSAtomicsCondition;
// Alias for IsJSSynchronizationPrimitive() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsJSSynchronizationPrimitive_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedJSSynchronizationPrimitive : public P {
  static_assert(
      std::is_same<JSSynchronizationPrimitive, D>::value,
      "Use this class as direct base for JSSynchronizationPrimitive.");
  static_assert(
      std::is_same<AlwaysSharedSpaceJSObject, P>::value,
      "Pass in AlwaysSharedSpaceJSObject as second template parameter for TorqueGeneratedJSSynchronizationPrimitive.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSynchronizationPrimitive<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=8&c=3
  inline uint32_t state() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=8&c=3
  inline void set_state(uint32_t value);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=5&c=1
  V8_EXPORT_PRIVATE void JSSynchronizationPrimitiveVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=7&c=3
  static constexpr int kWaiterQueueHeadOffset = P::kHeaderSize;
  static constexpr int kWaiterQueueHeadOffsetEnd = kWaiterQueueHeadOffset + kExternalPointerSlotSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=8&c=3
  static constexpr int kStateOffset = kWaiterQueueHeadOffsetEnd + 1;
  static constexpr int kStateOffsetEnd = kStateOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kStateOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kStateOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kStateOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kStateOffsetEnd + 1;
  static constexpr int kHeaderSize = kStateOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSynchronizationPrimitive() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSynchronizationPrimitive, DAlias>::value,
        "class TorqueGeneratedJSSynchronizationPrimitive should be used as direct base for JSSynchronizationPrimitive.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSynchronizationPrimitive(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSynchronizationPrimitive(Address ptr);
};

// Alias for IsJSAtomicsMutex() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=11&c=1
V8_EXPORT_PRIVATE bool IsJSAtomicsMutex_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=11&c=1
template <class D, class P>
class TorqueGeneratedJSAtomicsMutex : public P {
  static_assert(
      std::is_same<JSAtomicsMutex, D>::value,
      "Use this class as direct base for JSAtomicsMutex.");
  static_assert(
      std::is_same<JSSynchronizationPrimitive, P>::value,
      "Pass in JSSynchronizationPrimitive as second template parameter for TorqueGeneratedJSAtomicsMutex.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSAtomicsMutex<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=12&c=3
  inline int32_t owner_thread_id() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=12&c=3
  inline void set_owner_thread_id(int32_t value);

  DECL_PRINTER(JSAtomicsMutex)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=11&c=1
  V8_EXPORT_PRIVATE void JSAtomicsMutexVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=12&c=3
  static constexpr int kOwnerThreadIdOffset = P::kHeaderSize;
  static constexpr int kOwnerThreadIdOffsetEnd = kOwnerThreadIdOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kOwnerThreadIdOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kOwnerThreadIdOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kOwnerThreadIdOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kOwnerThreadIdOffsetEnd + 1;
  static constexpr int kHeaderSize = kOwnerThreadIdOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSAtomicsMutex() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSAtomicsMutex, DAlias>::value,
        "class TorqueGeneratedJSAtomicsMutex should be used as direct base for JSAtomicsMutex.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSAtomicsMutex(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSAtomicsMutex(Address ptr);
};

// Alias for IsJSAtomicsCondition() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=15&c=1
V8_EXPORT_PRIVATE bool IsJSAtomicsCondition_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=15&c=1
template <class D, class P>
class TorqueGeneratedJSAtomicsCondition : public P {
  static_assert(
      std::is_same<JSAtomicsCondition, D>::value,
      "Use this class as direct base for JSAtomicsCondition.");
  static_assert(
      std::is_same<JSSynchronizationPrimitive, P>::value,
      "Pass in JSSynchronizationPrimitive as second template parameter for TorqueGeneratedJSAtomicsCondition.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSAtomicsCondition<D,P>;

  DECL_PRINTER(JSAtomicsCondition)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=15&c=1
  V8_EXPORT_PRIVATE void JSAtomicsConditionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=17&c=31
  static constexpr int kOptionalPaddingOffset = P::kHeaderSize;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kHeaderSize = kOptionalPaddingOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSAtomicsCondition() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSAtomicsCondition, DAlias>::value,
        "class TorqueGeneratedJSAtomicsCondition should be used as direct base for JSAtomicsCondition.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSAtomicsCondition(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSAtomicsCondition(Address ptr);
};

