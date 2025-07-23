class Microtask;
class CallbackTask;
class CallableTask;
// Alias for IsMicrotask() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsMicrotask_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedMicrotask : public P {
  static_assert(
      std::is_same<Microtask, D>::value,
      "Use this class as direct base for Microtask.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedMicrotask.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedMicrotask<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=8&c=3
  inline Tagged<Object> continuation_preserved_embedder_data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=8&c=3
  inline Tagged<Object> continuation_preserved_embedder_data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=8&c=3
  inline void set_continuation_preserved_embedder_data(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=5&c=1
  V8_EXPORT_PRIVATE void MicrotaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=8&c=3
  static constexpr int kContinuationPreservedEmbedderDataOffset = P::kHeaderSize;
  static constexpr int kContinuationPreservedEmbedderDataOffsetEnd = kContinuationPreservedEmbedderDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kContinuationPreservedEmbedderDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kContinuationPreservedEmbedderDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kContinuationPreservedEmbedderDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kContinuationPreservedEmbedderDataOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedMicrotask() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedMicrotask, DAlias>::value,
        "class TorqueGeneratedMicrotask should be used as direct base for Microtask.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedMicrotask(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedMicrotask(Address ptr);
};

// Alias for IsCallbackTask() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=11&c=1
V8_EXPORT_PRIVATE bool IsCallbackTask_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=11&c=1
template <class D, class P>
class TorqueGeneratedCallbackTask : public P {
  static_assert(
      std::is_same<CallbackTask, D>::value,
      "Use this class as direct base for CallbackTask.");
  static_assert(
      std::is_same<Microtask, P>::value,
      "Pass in Microtask as second template parameter for TorqueGeneratedCallbackTask.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedCallbackTask<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=12&c=3
  inline Tagged<Foreign> callback() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=12&c=3
  inline Tagged<Foreign> callback(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=12&c=3
  inline void set_callback(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=13&c=3
  inline Tagged<Foreign> data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=13&c=3
  inline Tagged<Foreign> data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=13&c=3
  inline void set_data(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(CallbackTask)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=11&c=1
  V8_EXPORT_PRIVATE void CallbackTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=12&c=3
  static constexpr int kCallbackOffset = P::kHeaderSize;
  static constexpr int kCallbackOffsetEnd = kCallbackOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=13&c=3
  static constexpr int kDataOffset = kCallbackOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kDataOffsetEnd + 1;
  static constexpr int kSize = kDataOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=11&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 16);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=11&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedCallbackTask() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedCallbackTask, DAlias>::value,
        "class TorqueGeneratedCallbackTask should be used as direct base for CallbackTask.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedCallbackTask(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedCallbackTask(Address ptr);
};

// Alias for IsCallableTask() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=16&c=1
V8_EXPORT_PRIVATE bool IsCallableTask_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=16&c=1
template <class D, class P>
class TorqueGeneratedCallableTask : public P {
  static_assert(
      std::is_same<CallableTask, D>::value,
      "Use this class as direct base for CallableTask.");
  static_assert(
      std::is_same<Microtask, P>::value,
      "Pass in Microtask as second template parameter for TorqueGeneratedCallableTask.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedCallableTask<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=17&c=3
  inline Tagged<JSReceiver> callable() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=17&c=3
  inline Tagged<JSReceiver> callable(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=17&c=3
  inline void set_callable(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=18&c=3
  inline Tagged<Context> context() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=18&c=3
  inline Tagged<Context> context(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=18&c=3
  inline void set_context(Tagged<Context> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(CallableTask)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=16&c=1
  V8_EXPORT_PRIVATE void CallableTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=17&c=3
  static constexpr int kCallableOffset = P::kHeaderSize;
  static constexpr int kCallableOffsetEnd = kCallableOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=18&c=3
  static constexpr int kContextOffset = kCallableOffsetEnd + 1;
  static constexpr int kContextOffsetEnd = kContextOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kHeaderSize = kContextOffsetEnd + 1;
  static constexpr int kSize = kContextOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=16&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 16);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=16&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedCallableTask() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedCallableTask, DAlias>::value,
        "class TorqueGeneratedCallableTask should be used as direct base for CallableTask.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedCallableTask(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedCallableTask(Address ptr);
};

