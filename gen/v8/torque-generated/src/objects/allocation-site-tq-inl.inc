// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=8&c=3
template<class D, class P>
Tagged<AllocationSite> TorqueGeneratedAllocationMemento<D, P>::allocation_site() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAllocationMemento::allocation_site(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=8&c=3
template<class D, class P>
Tagged<AllocationSite> TorqueGeneratedAllocationMemento<D, P>::allocation_site(PtrComprCageBase cage_base) const {
  Tagged<AllocationSite> value = TaggedField<Tagged<AllocationSite>>::load(cage_base, *this, kAllocationSiteOffset);
  DCHECK(IsAllocationSite(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/allocation-site.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedAllocationMemento<D, P>::set_allocation_site(Tagged<AllocationSite> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsAllocationSite(value));
  WRITE_FIELD(*this, kAllocationSiteOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kAllocationSiteOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedAllocationMemento<D, P>::TorqueGeneratedAllocationMemento(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAllocationMemento_NonInline(*this));
}
