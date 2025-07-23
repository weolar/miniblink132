class FeedbackCell;
// Alias for IsFeedbackCell() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsFeedbackCell_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedFeedbackCell : public P {
  static_assert(
      std::is_same<FeedbackCell, D>::value,
      "Use this class as direct base for FeedbackCell.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedFeedbackCell.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedFeedbackCell<D,P>;

  // Torque type: (class Undefined | class ClosureFeedbackCellArray | class FeedbackVector)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=6&c=3
  inline Tagged<Union<ClosureFeedbackCellArray, FeedbackVector, Undefined>> value() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=6&c=3
  inline Tagged<Union<ClosureFeedbackCellArray, FeedbackVector, Undefined>> value(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=6&c=3
  inline void set_value(Tagged<Union<ClosureFeedbackCellArray, FeedbackVector, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=8&c=3
  inline int32_t interrupt_budget() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=8&c=3
  inline void set_interrupt_budget(int32_t value);

  DECL_PRINTER(FeedbackCell)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=5&c=1
  V8_EXPORT_PRIVATE void FeedbackCellVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=6&c=3
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kValueOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=8&c=3
  static constexpr int kInterruptBudgetOffset = kValueOffsetEnd + 1;
  static constexpr int kInterruptBudgetOffsetEnd = kInterruptBudgetOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kInterruptBudgetOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kInterruptBudgetOffsetEnd + 1;
  static constexpr int kHeaderSize = kInterruptBudgetOffsetEnd + 1;
  static constexpr int kSize = kInterruptBudgetOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedFeedbackCell() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedFeedbackCell, DAlias>::value,
        "class TorqueGeneratedFeedbackCell should be used as direct base for FeedbackCell.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedFeedbackCell(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedFeedbackCell(Address ptr);
};

