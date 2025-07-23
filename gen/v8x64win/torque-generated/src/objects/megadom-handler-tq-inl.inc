// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=7&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedMegaDomHandler<D, P>::accessor() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedMegaDomHandler::accessor(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=7&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedMegaDomHandler<D, P>::accessor(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapObject, MaybeObject, Smi>> value = TaggedField<Tagged<Union<HeapObject, MaybeObject, Smi>>>::load(cage_base, *this, kAccessorOffset);
  DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=7&c=3
template<class D, class P>
void TorqueGeneratedMegaDomHandler<D, P>::set_accessor(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  RELAXED_WRITE_WEAK_FIELD(*this, kAccessorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kAccessorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=8&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedMegaDomHandler<D, P>::context() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedMegaDomHandler::context(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=8&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedMegaDomHandler<D, P>::context(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapObject, MaybeObject, Smi>> value = TaggedField<Tagged<Union<HeapObject, MaybeObject, Smi>>>::load(cage_base, *this, kContextOffset);
  DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedMegaDomHandler<D, P>::set_context(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  RELAXED_WRITE_WEAK_FIELD(*this, kContextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kContextOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedMegaDomHandler<D, P>::TorqueGeneratedMegaDomHandler(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsMegaDomHandler_NonInline(*this));
}
