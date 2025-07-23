class JSV8BreakIterator;
// Alias for IsJSV8BreakIterator() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=7&c=1
V8_EXPORT_PRIVATE bool IsJSV8BreakIterator_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=7&c=1
template <class D, class P>
class TorqueGeneratedJSV8BreakIterator : public P {
  static_assert(
      std::is_same<JSV8BreakIterator, D>::value,
      "Use this class as direct base for JSV8BreakIterator.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSV8BreakIterator.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSV8BreakIterator<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=8&c=3
  inline Tagged<String> locale() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=8&c=3
  inline Tagged<String> locale(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=8&c=3
  inline void set_locale(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=9&c=3
  inline Tagged<Foreign> break_iterator() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=9&c=3
  inline Tagged<Foreign> break_iterator(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=9&c=3
  inline void set_break_iterator(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=10&c=3
  inline Tagged<Foreign> unicode_string() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=10&c=3
  inline Tagged<Foreign> unicode_string(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=10&c=3
  inline void set_unicode_string(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=11&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_adopt_text() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=11&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_adopt_text(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=11&c=3
  inline void set_bound_adopt_text(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=12&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_first() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=12&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_first(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=12&c=3
  inline void set_bound_first(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=13&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_next() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=13&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_next(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=13&c=3
  inline void set_bound_next(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=14&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_current() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=14&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_current(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=14&c=3
  inline void set_bound_current(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=15&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_break_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=15&c=3
  inline Tagged<Union<JSFunction, Undefined>> bound_break_type(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=15&c=3
  inline void set_bound_break_type(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSV8BreakIterator)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=7&c=1
  V8_EXPORT_PRIVATE void JSV8BreakIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=8&c=3
  static constexpr int kLocaleOffset = P::kHeaderSize;
  static constexpr int kLocaleOffsetEnd = kLocaleOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=9&c=3
  static constexpr int kBreakIteratorOffset = kLocaleOffsetEnd + 1;
  static constexpr int kBreakIteratorOffsetEnd = kBreakIteratorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=10&c=3
  static constexpr int kUnicodeStringOffset = kBreakIteratorOffsetEnd + 1;
  static constexpr int kUnicodeStringOffsetEnd = kUnicodeStringOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=11&c=3
  static constexpr int kBoundAdoptTextOffset = kUnicodeStringOffsetEnd + 1;
  static constexpr int kBoundAdoptTextOffsetEnd = kBoundAdoptTextOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=12&c=3
  static constexpr int kBoundFirstOffset = kBoundAdoptTextOffsetEnd + 1;
  static constexpr int kBoundFirstOffsetEnd = kBoundFirstOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=13&c=3
  static constexpr int kBoundNextOffset = kBoundFirstOffsetEnd + 1;
  static constexpr int kBoundNextOffsetEnd = kBoundNextOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=14&c=3
  static constexpr int kBoundCurrentOffset = kBoundNextOffsetEnd + 1;
  static constexpr int kBoundCurrentOffsetEnd = kBoundCurrentOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-break-iterator.tq?l=15&c=3
  static constexpr int kBoundBreakTypeOffset = kBoundCurrentOffsetEnd + 1;
  static constexpr int kBoundBreakTypeOffsetEnd = kBoundBreakTypeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBoundBreakTypeOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBoundBreakTypeOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBoundBreakTypeOffsetEnd + 1;
  static constexpr int kHeaderSize = kBoundBreakTypeOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSV8BreakIterator() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSV8BreakIterator, DAlias>::value,
        "class TorqueGeneratedJSV8BreakIterator should be used as direct base for JSV8BreakIterator.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSV8BreakIterator(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSV8BreakIterator(Address ptr);
};

