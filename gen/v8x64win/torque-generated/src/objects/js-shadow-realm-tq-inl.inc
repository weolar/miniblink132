// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-shadow-realm.tq?l=6&c=3
template<class D, class P>
Tagged<NativeContext> TorqueGeneratedJSShadowRealm<D, P>::native_context() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSShadowRealm::native_context(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-shadow-realm.tq?l=6&c=3
template<class D, class P>
Tagged<NativeContext> TorqueGeneratedJSShadowRealm<D, P>::native_context(PtrComprCageBase cage_base) const {
  Tagged<NativeContext> value = TaggedField<Tagged<NativeContext>>::load(cage_base, *this, kNativeContextOffset);
  DCHECK(IsNativeContext(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-shadow-realm.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedJSShadowRealm<D, P>::set_native_context(Tagged<NativeContext> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsNativeContext(value));
  WRITE_FIELD(*this, kNativeContextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNativeContextOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSShadowRealm<D, P>::TorqueGeneratedJSShadowRealm(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSShadowRealm_NonInline(*this));
}
