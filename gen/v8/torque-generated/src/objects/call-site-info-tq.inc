class CallSiteInfo;
// Alias for IsCallSiteInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=19&c=1
V8_EXPORT_PRIVATE bool IsCallSiteInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=19&c=1
template <class D, class P>
class TorqueGeneratedCallSiteInfo : public P {
  static_assert(
      std::is_same<CallSiteInfo, D>::value,
      "Use this class as direct base for CallSiteInfo.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedCallSiteInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedCallSiteInfo<D,P>;

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=23&c=3
  inline Tagged<JSAny> receiver_or_instance() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=23&c=3
  inline Tagged<JSAny> receiver_or_instance(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=23&c=3
  inline void set_receiver_or_instance(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=24&c=3
  inline Tagged<Union<JSFunction, Smi>> function() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=24&c=3
  inline Tagged<Union<JSFunction, Smi>> function(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=24&c=3
  inline void set_function(Tagged<Union<JSFunction, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=25&c=3
  inline int code_offset_or_source_position() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=25&c=3
  inline void set_code_offset_or_source_position(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=26&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=26&c=3
  inline void set_flags(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=27&c=3
  inline Tagged<FixedArray> parameters() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=27&c=3
  inline Tagged<FixedArray> parameters(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=27&c=3
  inline void set_parameters(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(CallSiteInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=19&c=1
  V8_EXPORT_PRIVATE void CallSiteInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=22&c=3
  static constexpr int kCodeObjectOffset = P::kHeaderSize;
  static constexpr int kCodeObjectOffsetEnd = kCodeObjectOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kCodeObjectOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=23&c=3
  static constexpr int kReceiverOrInstanceOffset = kCodeObjectOffsetEnd + 1;
  static constexpr int kReceiverOrInstanceOffsetEnd = kReceiverOrInstanceOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=24&c=3
  static constexpr int kFunctionOffset = kReceiverOrInstanceOffsetEnd + 1;
  static constexpr int kFunctionOffsetEnd = kFunctionOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=25&c=3
  static constexpr int kCodeOffsetOrSourcePositionOffset = kFunctionOffsetEnd + 1;
  static constexpr int kCodeOffsetOrSourcePositionOffsetEnd = kCodeOffsetOrSourcePositionOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=26&c=3
  static constexpr int kFlagsOffset = kCodeOffsetOrSourcePositionOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=27&c=3
  static constexpr int kParametersOffset = kFlagsOffsetEnd + 1;
  static constexpr int kParametersOffsetEnd = kParametersOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kParametersOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kParametersOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kParametersOffsetEnd + 1;
  static constexpr int kHeaderSize = kParametersOffsetEnd + 1;
  static constexpr int kSize = kParametersOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=19&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 28);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=19&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedCallSiteInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedCallSiteInfo, DAlias>::value,
        "class TorqueGeneratedCallSiteInfo should be used as direct base for CallSiteInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedCallSiteInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedCallSiteInfo(Address ptr);
};

