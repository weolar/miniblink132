class JSIteratorHelper;
class JSIteratorMapHelper;
class JSIteratorFilterHelper;
class JSIteratorTakeHelper;
class JSIteratorDropHelper;
class JSIteratorFlatMapHelper;
// Alias for IsJSIteratorHelper() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsJSIteratorHelper_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedJSIteratorHelper : public P {
  static_assert(
      std::is_same<JSIteratorHelper, D>::value,
      "Use this class as direct base for JSIteratorHelper.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSIteratorHelper.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSIteratorHelper<D,P>;

  // Torque type: (class JSReceiver | class Undefined | class Null)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
  inline Tagged<Union<JSReceiver, Null, Undefined>> underlying_object() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
  inline Tagged<Union<JSReceiver, Null, Undefined>> underlying_object(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
  inline void set_underlying_object(Tagged<Union<JSReceiver, Null, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
  inline Tagged<JSAny> underlying_next() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
  inline Tagged<JSAny> underlying_next(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
  inline void set_underlying_next(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=5&c=1
  V8_EXPORT_PRIVATE void JSIteratorHelperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=9&c=3
  static constexpr int kUnderlyingObjectOffset = P::kHeaderSize;
  static constexpr int kUnderlyingObjectOffsetEnd = kUnderlyingObjectOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=10&c=3
  static constexpr int kUnderlyingNextOffset = kUnderlyingObjectOffsetEnd + 1;
  static constexpr int kUnderlyingNextOffsetEnd = kUnderlyingNextOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kUnderlyingNextOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kUnderlyingNextOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kUnderlyingNextOffsetEnd + 1;
  static constexpr int kHeaderSize = kUnderlyingNextOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSIteratorHelper() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSIteratorHelper, DAlias>::value,
        "class TorqueGeneratedJSIteratorHelper should be used as direct base for JSIteratorHelper.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSIteratorHelper(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSIteratorHelper(Address ptr);
};

// Alias for IsJSIteratorMapHelper() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=13&c=1
V8_EXPORT_PRIVATE bool IsJSIteratorMapHelper_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=13&c=1
template <class D, class P>
class TorqueGeneratedJSIteratorMapHelper : public P {
  static_assert(
      std::is_same<JSIteratorMapHelper, D>::value,
      "Use this class as direct base for JSIteratorMapHelper.");
  static_assert(
      std::is_same<JSIteratorHelper, P>::value,
      "Pass in JSIteratorHelper as second template parameter for TorqueGeneratedJSIteratorMapHelper.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSIteratorMapHelper<D,P>;

  // Torque type: Callable
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> mapper() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> mapper(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
  inline void set_mapper(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
  inline Tagged<Number> counter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
  inline Tagged<Number> counter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
  inline void set_counter(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSIteratorMapHelper)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=13&c=1
  V8_EXPORT_PRIVATE void JSIteratorMapHelperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=14&c=3
  static constexpr int kMapperOffset = P::kHeaderSize;
  static constexpr int kMapperOffsetEnd = kMapperOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=15&c=3
  static constexpr int kCounterOffset = kMapperOffsetEnd + 1;
  static constexpr int kCounterOffsetEnd = kCounterOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCounterOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCounterOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCounterOffsetEnd + 1;
  static constexpr int kHeaderSize = kCounterOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSIteratorMapHelper() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSIteratorMapHelper, DAlias>::value,
        "class TorqueGeneratedJSIteratorMapHelper should be used as direct base for JSIteratorMapHelper.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSIteratorMapHelper(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSIteratorMapHelper(Address ptr);
};

// Alias for IsJSIteratorFilterHelper() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=18&c=1
V8_EXPORT_PRIVATE bool IsJSIteratorFilterHelper_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=18&c=1
template <class D, class P>
class TorqueGeneratedJSIteratorFilterHelper : public P {
  static_assert(
      std::is_same<JSIteratorFilterHelper, D>::value,
      "Use this class as direct base for JSIteratorFilterHelper.");
  static_assert(
      std::is_same<JSIteratorHelper, P>::value,
      "Pass in JSIteratorHelper as second template parameter for TorqueGeneratedJSIteratorFilterHelper.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSIteratorFilterHelper<D,P>;

  // Torque type: Callable
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> predicate() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> predicate(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
  inline void set_predicate(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
  inline Tagged<Number> counter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
  inline Tagged<Number> counter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
  inline void set_counter(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSIteratorFilterHelper)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=18&c=1
  V8_EXPORT_PRIVATE void JSIteratorFilterHelperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=19&c=3
  static constexpr int kPredicateOffset = P::kHeaderSize;
  static constexpr int kPredicateOffsetEnd = kPredicateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=20&c=3
  static constexpr int kCounterOffset = kPredicateOffsetEnd + 1;
  static constexpr int kCounterOffsetEnd = kCounterOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCounterOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCounterOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCounterOffsetEnd + 1;
  static constexpr int kHeaderSize = kCounterOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSIteratorFilterHelper() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSIteratorFilterHelper, DAlias>::value,
        "class TorqueGeneratedJSIteratorFilterHelper should be used as direct base for JSIteratorFilterHelper.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSIteratorFilterHelper(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSIteratorFilterHelper(Address ptr);
};

// Alias for IsJSIteratorTakeHelper() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=23&c=1
V8_EXPORT_PRIVATE bool IsJSIteratorTakeHelper_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=23&c=1
template <class D, class P>
class TorqueGeneratedJSIteratorTakeHelper : public P {
  static_assert(
      std::is_same<JSIteratorTakeHelper, D>::value,
      "Use this class as direct base for JSIteratorTakeHelper.");
  static_assert(
      std::is_same<JSIteratorHelper, P>::value,
      "Pass in JSIteratorHelper as second template parameter for TorqueGeneratedJSIteratorTakeHelper.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSIteratorTakeHelper<D,P>;

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
  inline Tagged<Number> remaining() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
  inline Tagged<Number> remaining(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
  inline void set_remaining(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSIteratorTakeHelper)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=23&c=1
  V8_EXPORT_PRIVATE void JSIteratorTakeHelperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=24&c=3
  static constexpr int kRemainingOffset = P::kHeaderSize;
  static constexpr int kRemainingOffsetEnd = kRemainingOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kRemainingOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kRemainingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kRemainingOffsetEnd + 1;
  static constexpr int kHeaderSize = kRemainingOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSIteratorTakeHelper() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSIteratorTakeHelper, DAlias>::value,
        "class TorqueGeneratedJSIteratorTakeHelper should be used as direct base for JSIteratorTakeHelper.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSIteratorTakeHelper(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSIteratorTakeHelper(Address ptr);
};

// Alias for IsJSIteratorDropHelper() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=27&c=1
V8_EXPORT_PRIVATE bool IsJSIteratorDropHelper_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=27&c=1
template <class D, class P>
class TorqueGeneratedJSIteratorDropHelper : public P {
  static_assert(
      std::is_same<JSIteratorDropHelper, D>::value,
      "Use this class as direct base for JSIteratorDropHelper.");
  static_assert(
      std::is_same<JSIteratorHelper, P>::value,
      "Pass in JSIteratorHelper as second template parameter for TorqueGeneratedJSIteratorDropHelper.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSIteratorDropHelper<D,P>;

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
  inline Tagged<Number> remaining() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
  inline Tagged<Number> remaining(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
  inline void set_remaining(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSIteratorDropHelper)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=27&c=1
  V8_EXPORT_PRIVATE void JSIteratorDropHelperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=28&c=3
  static constexpr int kRemainingOffset = P::kHeaderSize;
  static constexpr int kRemainingOffsetEnd = kRemainingOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kRemainingOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kRemainingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kRemainingOffsetEnd + 1;
  static constexpr int kHeaderSize = kRemainingOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSIteratorDropHelper() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSIteratorDropHelper, DAlias>::value,
        "class TorqueGeneratedJSIteratorDropHelper should be used as direct base for JSIteratorDropHelper.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSIteratorDropHelper(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSIteratorDropHelper(Address ptr);
};

// Alias for IsJSIteratorFlatMapHelper() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=31&c=1
V8_EXPORT_PRIVATE bool IsJSIteratorFlatMapHelper_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=31&c=1
template <class D, class P>
class TorqueGeneratedJSIteratorFlatMapHelper : public P {
  static_assert(
      std::is_same<JSIteratorFlatMapHelper, D>::value,
      "Use this class as direct base for JSIteratorFlatMapHelper.");
  static_assert(
      std::is_same<JSIteratorHelper, P>::value,
      "Pass in JSIteratorHelper as second template parameter for TorqueGeneratedJSIteratorFlatMapHelper.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSIteratorFlatMapHelper<D,P>;

  // Torque type: Callable
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> mapper() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> mapper(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
  inline void set_mapper(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Number
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
  inline Tagged<Number> counter() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
  inline Tagged<Number> counter(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
  inline void set_counter(Tagged<Number> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
  inline Tagged<JSReceiver> innerIterator_object() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
  inline Tagged<JSReceiver> innerIterator_object(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
  inline void set_innerIterator_object(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
  inline Tagged<JSAny> innerIterator_next() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
  inline Tagged<JSAny> innerIterator_next(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
  inline void set_innerIterator_next(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
  inline Tagged<Boolean> innerAlive() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
  inline Tagged<Boolean> innerAlive(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
  inline void set_innerAlive(Tagged<Boolean> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSIteratorFlatMapHelper)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=31&c=1
  V8_EXPORT_PRIVATE void JSIteratorFlatMapHelperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=32&c=3
  static constexpr int kMapperOffset = P::kHeaderSize;
  static constexpr int kMapperOffsetEnd = kMapperOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=33&c=3
  static constexpr int kCounterOffset = kMapperOffsetEnd + 1;
  static constexpr int kCounterOffsetEnd = kCounterOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=34&c=3
  static constexpr int kInnerIteratorOffset = kCounterOffsetEnd + 1;
  static constexpr int kInnerIteratorOffsetEnd = kInnerIteratorOffset + 8 - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-iterator-helpers.tq?l=35&c=3
  static constexpr int kInnerAliveOffset = kInnerIteratorOffsetEnd + 1;
  static constexpr int kInnerAliveOffsetEnd = kInnerAliveOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kInnerAliveOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kInnerAliveOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kInnerAliveOffsetEnd + 1;
  static constexpr int kHeaderSize = kInnerAliveOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSIteratorFlatMapHelper() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSIteratorFlatMapHelper, DAlias>::value,
        "class TorqueGeneratedJSIteratorFlatMapHelper should be used as direct base for JSIteratorFlatMapHelper.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSIteratorFlatMapHelper(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSIteratorFlatMapHelper(Address ptr);
};

