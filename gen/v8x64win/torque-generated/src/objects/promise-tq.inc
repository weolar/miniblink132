class PromiseCapability;
class PromiseReaction;
class PromiseReactionJobTask;
class PromiseFulfillReactionJobTask;
class PromiseRejectReactionJobTask;
class PromiseResolveThenableJobTask;
// Alias for IsPromiseCapability() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsPromiseCapability_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedPromiseCapability : public P {
  static_assert(
      std::is_same<PromiseCapability, D>::value,
      "Use this class as direct base for PromiseCapability.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedPromiseCapability.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPromiseCapability<D,P>;

  // Torque type: (class JSReceiver | class Undefined)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=6&c=3
  inline Tagged<Union<JSReceiver, Undefined>> promise() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=6&c=3
  inline Tagged<Union<JSReceiver, Undefined>> promise(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=6&c=3
  inline void set_promise(Tagged<Union<JSReceiver, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=12&c=3
  inline Tagged<JSAny> resolve() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=12&c=3
  inline Tagged<JSAny> resolve(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=12&c=3
  inline void set_resolve(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=13&c=3
  inline Tagged<JSAny> reject() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=13&c=3
  inline Tagged<JSAny> reject(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=13&c=3
  inline void set_reject(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(PromiseCapability)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=5&c=1
  V8_EXPORT_PRIVATE void PromiseCapabilityVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=6&c=3
  static constexpr int kPromiseOffset = P::kHeaderSize;
  static constexpr int kPromiseOffsetEnd = kPromiseOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=12&c=3
  static constexpr int kResolveOffset = kPromiseOffsetEnd + 1;
  static constexpr int kResolveOffsetEnd = kResolveOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=13&c=3
  static constexpr int kRejectOffset = kResolveOffsetEnd + 1;
  static constexpr int kRejectOffsetEnd = kRejectOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kRejectOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kRejectOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kRejectOffsetEnd + 1;
  static constexpr int kHeaderSize = kRejectOffsetEnd + 1;
  static constexpr int kSize = kRejectOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 16);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseCapability() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPromiseCapability, DAlias>::value,
        "class TorqueGeneratedPromiseCapability should be used as direct base for PromiseCapability.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPromiseCapability(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPromiseCapability(Address ptr);
};

// Alias for IsPromiseReaction() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=32&c=1
V8_EXPORT_PRIVATE bool IsPromiseReaction_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=32&c=1
template <class D, class P>
class TorqueGeneratedPromiseReaction : public P {
  static_assert(
      std::is_same<PromiseReaction, D>::value,
      "Use this class as direct base for PromiseReaction.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedPromiseReaction.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPromiseReaction<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=34&c=3
  inline Tagged<Object> continuation_preserved_embedder_data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=34&c=3
  inline Tagged<Object> continuation_preserved_embedder_data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=34&c=3
  inline void set_continuation_preserved_embedder_data(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Zero | class PromiseReaction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=35&c=3
  inline Tagged<Union<PromiseReaction, Smi>> next() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=35&c=3
  inline Tagged<Union<PromiseReaction, Smi>> next(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=35&c=3
  inline void set_next(Tagged<Union<PromiseReaction, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction | CallableApiObject | CallableJSProxy | class JSWrappedFunction | class JSBoundFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=36&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> reject_handler() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=36&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> reject_handler(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=36&c=3
  inline void set_reject_handler(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction | CallableApiObject | CallableJSProxy | class JSWrappedFunction | class JSBoundFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=37&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> fulfill_handler() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=37&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> fulfill_handler(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=37&c=3
  inline void set_fulfill_handler(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSPromise | class PromiseCapability)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=40&c=3
  inline Tagged<Union<JSPromise, PromiseCapability, Undefined>> promise_or_capability() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=40&c=3
  inline Tagged<Union<JSPromise, PromiseCapability, Undefined>> promise_or_capability(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=40&c=3
  inline void set_promise_or_capability(Tagged<Union<JSPromise, PromiseCapability, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(PromiseReaction)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=32&c=1
  V8_EXPORT_PRIVATE void PromiseReactionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=34&c=3
  static constexpr int kContinuationPreservedEmbedderDataOffset = P::kHeaderSize;
  static constexpr int kContinuationPreservedEmbedderDataOffsetEnd = kContinuationPreservedEmbedderDataOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=35&c=3
  static constexpr int kNextOffset = kContinuationPreservedEmbedderDataOffsetEnd + 1;
  static constexpr int kNextOffsetEnd = kNextOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=36&c=3
  static constexpr int kRejectHandlerOffset = kNextOffsetEnd + 1;
  static constexpr int kRejectHandlerOffsetEnd = kRejectHandlerOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=37&c=3
  static constexpr int kFulfillHandlerOffset = kRejectHandlerOffsetEnd + 1;
  static constexpr int kFulfillHandlerOffsetEnd = kFulfillHandlerOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=40&c=3
  static constexpr int kPromiseOrCapabilityOffset = kFulfillHandlerOffsetEnd + 1;
  static constexpr int kPromiseOrCapabilityOffsetEnd = kPromiseOrCapabilityOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kHeaderSize = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kSize = kPromiseOrCapabilityOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=32&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=32&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseReaction() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPromiseReaction, DAlias>::value,
        "class TorqueGeneratedPromiseReaction should be used as direct base for PromiseReaction.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPromiseReaction(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPromiseReaction(Address ptr);
};

// Alias for IsPromiseReactionJobTask() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=56&c=1
V8_EXPORT_PRIVATE bool IsPromiseReactionJobTask_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=56&c=1
template <class D, class P>
class TorqueGeneratedPromiseReactionJobTask : public P {
  static_assert(
      std::is_same<PromiseReactionJobTask, D>::value,
      "Use this class as direct base for PromiseReactionJobTask.");
  static_assert(
      std::is_same<Microtask, P>::value,
      "Pass in Microtask as second template parameter for TorqueGeneratedPromiseReactionJobTask.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPromiseReactionJobTask<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=58&c=3
  inline Tagged<Object> argument() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=58&c=3
  inline Tagged<Object> argument(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=58&c=3
  inline void set_argument(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=59&c=3
  inline Tagged<Context> context() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=59&c=3
  inline Tagged<Context> context(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=59&c=3
  inline void set_context(Tagged<Context> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction | CallableApiObject | CallableJSProxy | class JSWrappedFunction | class JSBoundFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=60&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> handler() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=60&c=3
  inline Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> handler(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=60&c=3
  inline void set_handler(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSPromise | class PromiseCapability)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=63&c=3
  inline Tagged<Union<JSPromise, PromiseCapability, Undefined>> promise_or_capability() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=63&c=3
  inline Tagged<Union<JSPromise, PromiseCapability, Undefined>> promise_or_capability(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=63&c=3
  inline void set_promise_or_capability(Tagged<Union<JSPromise, PromiseCapability, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=56&c=1
  V8_EXPORT_PRIVATE void PromiseReactionJobTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=58&c=3
  static constexpr int kArgumentOffset = P::kHeaderSize;
  static constexpr int kArgumentOffsetEnd = kArgumentOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=59&c=3
  static constexpr int kContextOffset = kArgumentOffsetEnd + 1;
  static constexpr int kContextOffsetEnd = kContextOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=60&c=3
  static constexpr int kHandlerOffset = kContextOffsetEnd + 1;
  static constexpr int kHandlerOffsetEnd = kHandlerOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=63&c=3
  static constexpr int kPromiseOrCapabilityOffset = kHandlerOffsetEnd + 1;
  static constexpr int kPromiseOrCapabilityOffsetEnd = kPromiseOrCapabilityOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kHeaderSize = kPromiseOrCapabilityOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseReactionJobTask() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPromiseReactionJobTask, DAlias>::value,
        "class TorqueGeneratedPromiseReactionJobTask should be used as direct base for PromiseReactionJobTask.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPromiseReactionJobTask(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPromiseReactionJobTask(Address ptr);
};

// Alias for IsPromiseFulfillReactionJobTask() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=66&c=1
V8_EXPORT_PRIVATE bool IsPromiseFulfillReactionJobTask_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=66&c=1
template <class D, class P>
class TorqueGeneratedPromiseFulfillReactionJobTask : public P {
  static_assert(
      std::is_same<PromiseFulfillReactionJobTask, D>::value,
      "Use this class as direct base for PromiseFulfillReactionJobTask.");
  static_assert(
      std::is_same<PromiseReactionJobTask, P>::value,
      "Pass in PromiseReactionJobTask as second template parameter for TorqueGeneratedPromiseFulfillReactionJobTask.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPromiseFulfillReactionJobTask<D,P>;

  DECL_PRINTER(PromiseFulfillReactionJobTask)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=66&c=1
  V8_EXPORT_PRIVATE void PromiseFulfillReactionJobTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=66&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=66&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseFulfillReactionJobTask() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPromiseFulfillReactionJobTask, DAlias>::value,
        "class TorqueGeneratedPromiseFulfillReactionJobTask should be used as direct base for PromiseFulfillReactionJobTask.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPromiseFulfillReactionJobTask(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPromiseFulfillReactionJobTask(Address ptr);
};

// Alias for IsPromiseRejectReactionJobTask() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=68&c=1
V8_EXPORT_PRIVATE bool IsPromiseRejectReactionJobTask_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=68&c=1
template <class D, class P>
class TorqueGeneratedPromiseRejectReactionJobTask : public P {
  static_assert(
      std::is_same<PromiseRejectReactionJobTask, D>::value,
      "Use this class as direct base for PromiseRejectReactionJobTask.");
  static_assert(
      std::is_same<PromiseReactionJobTask, P>::value,
      "Pass in PromiseReactionJobTask as second template parameter for TorqueGeneratedPromiseRejectReactionJobTask.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPromiseRejectReactionJobTask<D,P>;

  DECL_PRINTER(PromiseRejectReactionJobTask)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=68&c=1
  V8_EXPORT_PRIVATE void PromiseRejectReactionJobTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=68&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=68&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseRejectReactionJobTask() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPromiseRejectReactionJobTask, DAlias>::value,
        "class TorqueGeneratedPromiseRejectReactionJobTask should be used as direct base for PromiseRejectReactionJobTask.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPromiseRejectReactionJobTask(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPromiseRejectReactionJobTask(Address ptr);
};

// Alias for IsPromiseResolveThenableJobTask() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=70&c=1
V8_EXPORT_PRIVATE bool IsPromiseResolveThenableJobTask_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=70&c=1
template <class D, class P>
class TorqueGeneratedPromiseResolveThenableJobTask : public P {
  static_assert(
      std::is_same<PromiseResolveThenableJobTask, D>::value,
      "Use this class as direct base for PromiseResolveThenableJobTask.");
  static_assert(
      std::is_same<Microtask, P>::value,
      "Pass in Microtask as second template parameter for TorqueGeneratedPromiseResolveThenableJobTask.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedPromiseResolveThenableJobTask<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=71&c=3
  inline Tagged<Context> context() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=71&c=3
  inline Tagged<Context> context(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=71&c=3
  inline void set_context(Tagged<Context> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=72&c=3
  inline Tagged<JSPromise> promise_to_resolve() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=72&c=3
  inline Tagged<JSPromise> promise_to_resolve(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=72&c=3
  inline void set_promise_to_resolve(Tagged<JSPromise> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=73&c=3
  inline Tagged<JSReceiver> thenable() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=73&c=3
  inline Tagged<JSReceiver> thenable(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=73&c=3
  inline void set_thenable(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=74&c=3
  inline Tagged<JSReceiver> then() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=74&c=3
  inline Tagged<JSReceiver> then(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=74&c=3
  inline void set_then(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(PromiseResolveThenableJobTask)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=70&c=1
  V8_EXPORT_PRIVATE void PromiseResolveThenableJobTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=71&c=3
  static constexpr int kContextOffset = P::kHeaderSize;
  static constexpr int kContextOffsetEnd = kContextOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=72&c=3
  static constexpr int kPromiseToResolveOffset = kContextOffsetEnd + 1;
  static constexpr int kPromiseToResolveOffsetEnd = kPromiseToResolveOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=73&c=3
  static constexpr int kThenableOffset = kPromiseToResolveOffsetEnd + 1;
  static constexpr int kThenableOffsetEnd = kThenableOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=74&c=3
  static constexpr int kThenOffset = kThenableOffsetEnd + 1;
  static constexpr int kThenOffsetEnd = kThenOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kThenOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kThenOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kThenOffsetEnd + 1;
  static constexpr int kHeaderSize = kThenOffsetEnd + 1;
  static constexpr int kSize = kThenOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=70&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/promise.tq?l=70&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseResolveThenableJobTask() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedPromiseResolveThenableJobTask, DAlias>::value,
        "class TorqueGeneratedPromiseResolveThenableJobTask should be used as direct base for PromiseResolveThenableJobTask.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedPromiseResolveThenableJobTask(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedPromiseResolveThenableJobTask(Address ptr);
};

