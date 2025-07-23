template<class D, class P>
inline TorqueGeneratedJSSharedArray<D, P>::TorqueGeneratedJSSharedArray(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSSharedArray_NonInline(*this));
}
