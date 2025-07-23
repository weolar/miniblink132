template<class D, class P>
inline TorqueGeneratedAlwaysSharedSpaceJSObject<D, P>::TorqueGeneratedAlwaysSharedSpaceJSObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAlwaysSharedSpaceJSObject_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSSharedStruct<D, P>::TorqueGeneratedJSSharedStruct(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSSharedStruct_NonInline(*this));
}
