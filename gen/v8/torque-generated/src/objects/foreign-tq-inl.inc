template<class D, class P>
inline TorqueGeneratedForeign<D, P>::TorqueGeneratedForeign(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsForeign_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=11&c=3
template<class D, class P>
Address TorqueGeneratedTrustedForeign<D, P>::foreign_address() const {
  Address value = this->template ReadField<Address>(kForeignAddressOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=11&c=3
template<class D, class P>
void TorqueGeneratedTrustedForeign<D, P>::set_foreign_address(Address value) {
  this->template WriteField<Address>(kForeignAddressOffset, value);
}

template<class D, class P>
inline TorqueGeneratedTrustedForeign<D, P>::TorqueGeneratedTrustedForeign(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsTrustedForeign_NonInline(*this));
}
