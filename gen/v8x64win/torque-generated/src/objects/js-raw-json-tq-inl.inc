template<class D, class P>
inline TorqueGeneratedJSRawJson<D, P>::TorqueGeneratedJSRawJson(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSRawJson_NonInline(*this));
}
