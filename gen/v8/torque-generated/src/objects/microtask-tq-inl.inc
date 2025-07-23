// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=8&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedMicrotask<D, P>::continuation_preserved_embedder_data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedMicrotask::continuation_preserved_embedder_data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=8&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedMicrotask<D, P>::continuation_preserved_embedder_data(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kContinuationPreservedEmbedderDataOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedMicrotask<D, P>::set_continuation_preserved_embedder_data(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kContinuationPreservedEmbedderDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kContinuationPreservedEmbedderDataOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedMicrotask<D, P>::TorqueGeneratedMicrotask(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsMicrotask_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=12&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedCallbackTask<D, P>::callback() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallbackTask::callback(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=12&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedCallbackTask<D, P>::callback(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kCallbackOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=12&c=3
template<class D, class P>
void TorqueGeneratedCallbackTask<D, P>::set_callback(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kCallbackOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallbackOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=13&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedCallbackTask<D, P>::data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallbackTask::data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=13&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedCallbackTask<D, P>::data(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kDataOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=13&c=3
template<class D, class P>
void TorqueGeneratedCallbackTask<D, P>::set_data(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDataOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedCallbackTask<D, P>::TorqueGeneratedCallbackTask(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsCallbackTask_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=17&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedCallableTask<D, P>::callable() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallableTask::callable(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=17&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedCallableTask<D, P>::callable(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kCallableOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=17&c=3
template<class D, class P>
void TorqueGeneratedCallableTask<D, P>::set_callable(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kCallableOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallableOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=18&c=3
template<class D, class P>
Tagged<Context> TorqueGeneratedCallableTask<D, P>::context() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallableTask::context(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=18&c=3
template<class D, class P>
Tagged<Context> TorqueGeneratedCallableTask<D, P>::context(PtrComprCageBase cage_base) const {
  Tagged<Context> value = TaggedField<Tagged<Context>>::load(cage_base, *this, kContextOffset);
  DCHECK(IsContext(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/microtask.tq?l=18&c=3
template<class D, class P>
void TorqueGeneratedCallableTask<D, P>::set_context(Tagged<Context> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsContext(value));
  WRITE_FIELD(*this, kContextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kContextOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedCallableTask<D, P>::TorqueGeneratedCallableTask(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsCallableTask_NonInline(*this));
}
