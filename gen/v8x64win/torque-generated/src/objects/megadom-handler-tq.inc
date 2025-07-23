class MegaDomHandler;
// Alias for IsMegaDomHandler() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsMegaDomHandler_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedMegaDomHandler : public P {
  static_assert(
      std::is_same<MegaDomHandler, D>::value,
      "Use this class as direct base for MegaDomHandler.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedMegaDomHandler.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedMegaDomHandler<D,P>;

  // Torque type: MaybeObject
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=7&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> accessor() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=7&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> accessor(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=7&c=3
  inline void set_accessor(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: MaybeObject
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=8&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> context() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=8&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> context(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=8&c=3
  inline void set_context(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(MegaDomHandler)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=5&c=1
  V8_EXPORT_PRIVATE void MegaDomHandlerVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=7&c=3
  static constexpr int kAccessorOffset = P::kHeaderSize;
  static constexpr int kAccessorOffsetEnd = kAccessorOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=8&c=3
  static constexpr int kContextOffset = kAccessorOffsetEnd + 1;
  static constexpr int kContextOffsetEnd = kContextOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kHeaderSize = kContextOffsetEnd + 1;
  static constexpr int kSize = kContextOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedMegaDomHandler() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedMegaDomHandler, DAlias>::value,
        "class TorqueGeneratedMegaDomHandler should be used as direct base for MegaDomHandler.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedMegaDomHandler(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedMegaDomHandler(Address ptr);
};

