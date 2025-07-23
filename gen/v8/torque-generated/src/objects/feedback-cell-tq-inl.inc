// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=6&c=3
template<class D, class P>
Tagged<Union<ClosureFeedbackCellArray, FeedbackVector, Undefined>> TorqueGeneratedFeedbackCell<D, P>::value() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedFeedbackCell::value(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=6&c=3
template<class D, class P>
Tagged<Union<ClosureFeedbackCellArray, FeedbackVector, Undefined>> TorqueGeneratedFeedbackCell<D, P>::value(PtrComprCageBase cage_base) const {
  Tagged<Union<ClosureFeedbackCellArray, FeedbackVector, Undefined>> value = TaggedField<Tagged<Union<ClosureFeedbackCellArray, FeedbackVector, Undefined>>>::load(cage_base, *this, kValueOffset);
  DCHECK(IsUndefined(value) || IsClosureFeedbackCellArray(value) || IsFeedbackVector(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedFeedbackCell<D, P>::set_value(Tagged<Union<ClosureFeedbackCellArray, FeedbackVector, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsClosureFeedbackCellArray(value) || IsFeedbackVector(value));
  WRITE_FIELD(*this, kValueOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kValueOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=8&c=3
template<class D, class P>
int32_t TorqueGeneratedFeedbackCell<D, P>::interrupt_budget() const {
  int32_t value = this->template ReadField<int32_t>(kInterruptBudgetOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-cell.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedFeedbackCell<D, P>::set_interrupt_budget(int32_t value) {
  this->template WriteField<int32_t>(kInterruptBudgetOffset, value);
}

template<class D, class P>
inline TorqueGeneratedFeedbackCell<D, P>::TorqueGeneratedFeedbackCell(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsFeedbackCell_NonInline(*this));
}
