class FeedbackVector;
// Alias for IsFeedbackVector() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=44&c=1
V8_EXPORT_PRIVATE bool IsFeedbackVector_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=44&c=1
template <class D, class P>
class TorqueGeneratedFeedbackVector : public P {
  static_assert(
      std::is_same<FeedbackVector, D>::value,
      "Use this class as direct base for FeedbackVector.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedFeedbackVector.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedFeedbackVector<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=46&c=9
  inline int32_t length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=46&c=9
  inline void set_length(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=47&c=3
  inline int32_t invocation_count() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=47&c=3
  inline void set_invocation_count(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=49&c=3
  inline uint8_t invocation_count_before_stable() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=49&c=3
  inline void set_invocation_count_before_stable(uint8_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=50&c=3
  inline uint8_t osr_state() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=50&c=3
  inline void set_osr_state(uint8_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=51&c=3
  inline uint16_t flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=51&c=3
  inline void set_flags(uint16_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=52&c=3
  inline Tagged<SharedFunctionInfo> shared_function_info() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=52&c=3
  inline Tagged<SharedFunctionInfo> shared_function_info(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=52&c=3
  inline void set_shared_function_info(Tagged<SharedFunctionInfo> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=53&c=3
  inline Tagged<ClosureFeedbackCellArray> closure_feedback_cell_array() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=53&c=3
  inline Tagged<ClosureFeedbackCellArray> closure_feedback_cell_array(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=53&c=3
  inline void set_closure_feedback_cell_array(Tagged<ClosureFeedbackCellArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=54&c=3
  inline Tagged<FeedbackCell> parent_feedback_cell() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=54&c=3
  inline Tagged<FeedbackCell> parent_feedback_cell(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=54&c=3
  inline void set_parent_feedback_cell(Tagged<FeedbackCell> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Weak<class CodeWrapper>
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=55&c=33
  inline Tagged<MaybeObject> maybe_optimized_code() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=55&c=33
  inline Tagged<MaybeObject> maybe_optimized_code(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=55&c=33
  inline void set_maybe_optimized_code(Tagged<MaybeObject> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: MaybeObject
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> raw_feedback_slots(int i, RelaxedLoadTag) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> raw_feedback_slots(PtrComprCageBase cage_base, int i, RelaxedLoadTag) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
  inline void set_raw_feedback_slots(int i, Tagged<Union<HeapObject, MaybeObject, Smi>> value, RelaxedStoreTag, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(FeedbackVector)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=44&c=1
  V8_EXPORT_PRIVATE void FeedbackVectorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=46&c=9
  static constexpr int kLengthOffset = P::kHeaderSize;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=47&c=3
  static constexpr int kInvocationCountOffset = kLengthOffsetEnd + 1;
  static constexpr int kInvocationCountOffsetEnd = kInvocationCountOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=49&c=3
  static constexpr int kInvocationCountBeforeStableOffset = kInvocationCountOffsetEnd + 1;
  static constexpr int kInvocationCountBeforeStableOffsetEnd = kInvocationCountBeforeStableOffset + kUInt8Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=50&c=3
  static constexpr int kOsrStateOffset = kInvocationCountBeforeStableOffsetEnd + 1;
  static constexpr int kOsrStateOffsetEnd = kOsrStateOffset + kUInt8Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=51&c=3
  static constexpr int kFlagsOffset = kOsrStateOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kUInt16Size - 1;
  static constexpr int kStartOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=52&c=3
  static constexpr int kSharedFunctionInfoOffset = kFlagsOffsetEnd + 1;
  static constexpr int kSharedFunctionInfoOffsetEnd = kSharedFunctionInfoOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=53&c=3
  static constexpr int kClosureFeedbackCellArrayOffset = kSharedFunctionInfoOffsetEnd + 1;
  static constexpr int kClosureFeedbackCellArrayOffsetEnd = kClosureFeedbackCellArrayOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=54&c=3
  static constexpr int kParentFeedbackCellOffset = kClosureFeedbackCellArrayOffsetEnd + 1;
  static constexpr int kParentFeedbackCellOffsetEnd = kParentFeedbackCellOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kParentFeedbackCellOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kParentFeedbackCellOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=55&c=33
  static constexpr int kMaybeOptimizedCodeOffset = kParentFeedbackCellOffsetEnd + 1;
  static constexpr int kMaybeOptimizedCodeOffsetEnd = kMaybeOptimizedCodeOffset + kTaggedSize - 1;
  static constexpr int kHeaderSize = kMaybeOptimizedCodeOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
  static constexpr int kRawFeedbackSlotsOffset = kMaybeOptimizedCodeOffsetEnd + 1;
  static constexpr int kRawFeedbackSlotsOffsetEnd = kRawFeedbackSlotsOffset + 0 - 1;
  static constexpr int kEndOfWeakFieldsOffset = kRawFeedbackSlotsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=44&c=1
  V8_INLINE static constexpr int32_t SizeFor(int length) {
    int32_t size = kHeaderSize;
    size += length * 4;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=44&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->length());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedFeedbackVector() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedFeedbackVector, DAlias>::value,
        "class TorqueGeneratedFeedbackVector should be used as direct base for FeedbackVector.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedFeedbackVector(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedFeedbackVector(Address ptr);
};

