class BreakPoint;
class BreakPointInfo;
class DebugInfo;
class CoverageInfo;
class StackFrameInfo;
class StackTraceInfo;
class ErrorStackData;
// Alias for IsBreakPoint() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsBreakPoint_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedBreakPoint : public P {
  static_assert(
      std::is_same<BreakPoint, D>::value,
      "Use this class as direct base for BreakPoint.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedBreakPoint.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedBreakPoint<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=6&c=3
  inline int id() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=6&c=3
  inline void set_id(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
  inline Tagged<String> condition() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
  inline Tagged<String> condition(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
  inline void set_condition(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(BreakPoint)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=5&c=1
  V8_EXPORT_PRIVATE void BreakPointVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=6&c=3
  static constexpr int kIdOffset = P::kHeaderSize;
  static constexpr int kIdOffsetEnd = kIdOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
  static constexpr int kConditionOffset = kIdOffsetEnd + 1;
  static constexpr int kConditionOffsetEnd = kConditionOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kConditionOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kConditionOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kConditionOffsetEnd + 1;
  static constexpr int kHeaderSize = kConditionOffsetEnd + 1;
  static constexpr int kSize = kConditionOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedBreakPoint() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedBreakPoint, DAlias>::value,
        "class TorqueGeneratedBreakPoint should be used as direct base for BreakPoint.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedBreakPoint(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedBreakPoint(Address ptr);
};

// Alias for IsBreakPointInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=10&c=1
V8_EXPORT_PRIVATE bool IsBreakPointInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=10&c=1
template <class D, class P>
class TorqueGeneratedBreakPointInfo : public P {
  static_assert(
      std::is_same<BreakPointInfo, D>::value,
      "Use this class as direct base for BreakPointInfo.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedBreakPointInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedBreakPointInfo<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=12&c=3
  inline int source_position() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=12&c=3
  inline void set_source_position(int value);

  // Torque type: (class Undefined | class FixedArray | class BreakPoint)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
  inline Tagged<Union<BreakPoint, FixedArray, Undefined>> break_points() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
  inline Tagged<Union<BreakPoint, FixedArray, Undefined>> break_points(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
  inline void set_break_points(Tagged<Union<BreakPoint, FixedArray, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(BreakPointInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=10&c=1
  V8_EXPORT_PRIVATE void BreakPointInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=12&c=3
  static constexpr int kSourcePositionOffset = P::kHeaderSize;
  static constexpr int kSourcePositionOffsetEnd = kSourcePositionOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
  static constexpr int kBreakPointsOffset = kSourcePositionOffsetEnd + 1;
  static constexpr int kBreakPointsOffsetEnd = kBreakPointsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBreakPointsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBreakPointsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBreakPointsOffsetEnd + 1;
  static constexpr int kHeaderSize = kBreakPointsOffsetEnd + 1;
  static constexpr int kSize = kBreakPointsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=10&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=10&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedBreakPointInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedBreakPointInfo, DAlias>::value,
        "class TorqueGeneratedBreakPointInfo should be used as direct base for BreakPointInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedBreakPointInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedBreakPointInfo(Address ptr);
};

// Alias for IsDebugInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=33&c=1
V8_EXPORT_PRIVATE bool IsDebugInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=33&c=1
template <class D, class P>
class TorqueGeneratedDebugInfo : public P {
  static_assert(
      std::is_same<DebugInfo, D>::value,
      "Use this class as direct base for DebugInfo.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedDebugInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedDebugInfo<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
  inline Tagged<SharedFunctionInfo> shared() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
  inline Tagged<SharedFunctionInfo> shared(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
  inline void set_shared(Tagged<SharedFunctionInfo> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=36&c=3
  inline int debugger_hints() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=36&c=3
  inline void set_debugger_hints(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
  inline Tagged<FixedArray> break_points() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
  inline Tagged<FixedArray> break_points(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
  inline void set_break_points(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=40&c=36
  inline int flags(RelaxedLoadTag) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=40&c=36
  inline void set_flags(int value, RelaxedStoreTag);

  // Torque type: (class Undefined | class CoverageInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
  inline Tagged<Union<CoverageInfo, Undefined>> coverage_info() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
  inline Tagged<Union<CoverageInfo, Undefined>> coverage_info(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
  inline void set_coverage_info(Tagged<Union<CoverageInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(DebugInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=33&c=1
  V8_EXPORT_PRIVATE void DebugInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
  static constexpr int kSharedOffset = P::kHeaderSize;
  static constexpr int kSharedOffsetEnd = kSharedOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=36&c=3
  static constexpr int kDebuggerHintsOffset = kSharedOffsetEnd + 1;
  static constexpr int kDebuggerHintsOffsetEnd = kDebuggerHintsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
  static constexpr int kBreakPointsOffset = kDebuggerHintsOffsetEnd + 1;
  static constexpr int kBreakPointsOffsetEnd = kBreakPointsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=40&c=36
  static constexpr int kFlagsOffset = kBreakPointsOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
  static constexpr int kCoverageInfoOffset = kFlagsOffsetEnd + 1;
  static constexpr int kCoverageInfoOffsetEnd = kCoverageInfoOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCoverageInfoOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=45&c=3
  static constexpr int kOriginalBytecodeArrayOffset = kCoverageInfoOffsetEnd + 1;
  static constexpr int kOriginalBytecodeArrayOffsetEnd = kOriginalBytecodeArrayOffset + kTrustedPointerSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=49&c=3
  static constexpr int kDebugBytecodeArrayOffset = kOriginalBytecodeArrayOffsetEnd + 1;
  static constexpr int kDebugBytecodeArrayOffsetEnd = kDebugBytecodeArrayOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kDebugBytecodeArrayOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDebugBytecodeArrayOffsetEnd + 1;
  static constexpr int kHeaderSize = kDebugBytecodeArrayOffsetEnd + 1;
  static constexpr int kSize = kDebugBytecodeArrayOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=33&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 32);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=33&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedDebugInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedDebugInfo, DAlias>::value,
        "class TorqueGeneratedDebugInfo should be used as direct base for DebugInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedDebugInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedDebugInfo(Address ptr);
};

// Alias for IsCoverageInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=62&c=1
V8_EXPORT_PRIVATE bool IsCoverageInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=62&c=1
template <class D, class P>
class TorqueGeneratedCoverageInfo : public P {
  static_assert(
      std::is_same<CoverageInfo, D>::value,
      "Use this class as direct base for CoverageInfo.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedCoverageInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedCoverageInfo<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=63&c=9
  inline int32_t slot_count() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=63&c=9
  inline void set_slot_count(int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  inline int32_t slots_start_source_position(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  inline void set_slots_start_source_position(int i, int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  inline int32_t slots_end_source_position(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  inline void set_slots_end_source_position(int i, int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  inline int32_t slots_block_count(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  inline void set_slots_block_count(int i, int32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  inline int32_t slots_padding(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  inline void set_slots_padding(int i, int32_t value);

  DECL_PRINTER(CoverageInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=62&c=1
  V8_EXPORT_PRIVATE void CoverageInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=63&c=9
  static constexpr int kSlotCountOffset = P::kHeaderSize;
  static constexpr int kSlotCountOffsetEnd = kSlotCountOffset + kInt32Size - 1;
  static constexpr int kHeaderSize = kSlotCountOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
  static constexpr int kSlotsOffset = kSlotCountOffsetEnd + 1;
  static constexpr int kSlotsOffsetEnd = kSlotsOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kSlotsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSlotsOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kSlotsOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kSlotsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=62&c=1
  V8_INLINE static constexpr int32_t SizeFor(int slot_count) {
    int32_t size = kHeaderSize;
    size += slot_count * 16;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=62&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->slot_count());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedCoverageInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedCoverageInfo, DAlias>::value,
        "class TorqueGeneratedCoverageInfo should be used as direct base for CoverageInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedCoverageInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedCoverageInfo(Address ptr);
};

// Alias for IsStackFrameInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=72&c=1
V8_EXPORT_PRIVATE bool IsStackFrameInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=72&c=1
template <class D, class P>
class TorqueGeneratedStackFrameInfo : public P {
  static_assert(
      std::is_same<StackFrameInfo, D>::value,
      "Use this class as direct base for StackFrameInfo.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedStackFrameInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedStackFrameInfo<D,P>;

  // Torque type: (class Script | class SharedFunctionInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
  inline Tagged<Union<Script, SharedFunctionInfo>> shared_or_script() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
  inline Tagged<Union<Script, SharedFunctionInfo>> shared_or_script(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
  inline void set_shared_or_script(Tagged<Union<Script, SharedFunctionInfo>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
  inline Tagged<String> function_name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
  inline Tagged<String> function_name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
  inline void set_function_name(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=81&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=81&c=3
  inline void set_flags(int value);

  DECL_PRINTER(StackFrameInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=72&c=1
  V8_EXPORT_PRIVATE void StackFrameInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
  static constexpr int kSharedOrScriptOffset = P::kHeaderSize;
  static constexpr int kSharedOrScriptOffsetEnd = kSharedOrScriptOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
  static constexpr int kFunctionNameOffset = kSharedOrScriptOffsetEnd + 1;
  static constexpr int kFunctionNameOffsetEnd = kFunctionNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=81&c=3
  static constexpr int kFlagsOffset = kFunctionNameOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;
  static constexpr int kSize = kFlagsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=72&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 16);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=72&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedStackFrameInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedStackFrameInfo, DAlias>::value,
        "class TorqueGeneratedStackFrameInfo should be used as direct base for StackFrameInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedStackFrameInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedStackFrameInfo(Address ptr);
};

// Alias for IsStackTraceInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=84&c=1
V8_EXPORT_PRIVATE bool IsStackTraceInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=84&c=1
template <class D, class P>
class TorqueGeneratedStackTraceInfo : public P {
  static_assert(
      std::is_same<StackTraceInfo, D>::value,
      "Use this class as direct base for StackTraceInfo.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedStackTraceInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedStackTraceInfo<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=86&c=3
  inline int id() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=86&c=3
  inline void set_id(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
  inline Tagged<FixedArray> frames() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
  inline Tagged<FixedArray> frames(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
  inline void set_frames(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(StackTraceInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=84&c=1
  V8_EXPORT_PRIVATE void StackTraceInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=86&c=3
  static constexpr int kIdOffset = P::kHeaderSize;
  static constexpr int kIdOffsetEnd = kIdOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
  static constexpr int kFramesOffset = kIdOffsetEnd + 1;
  static constexpr int kFramesOffsetEnd = kFramesOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFramesOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFramesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFramesOffsetEnd + 1;
  static constexpr int kHeaderSize = kFramesOffsetEnd + 1;
  static constexpr int kSize = kFramesOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=84&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=84&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedStackTraceInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedStackTraceInfo, DAlias>::value,
        "class TorqueGeneratedStackTraceInfo should be used as direct base for StackTraceInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedStackTraceInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedStackTraceInfo(Address ptr);
};

// Alias for IsErrorStackData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=104&c=1
V8_EXPORT_PRIVATE bool IsErrorStackData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=104&c=1
template <class D, class P>
class TorqueGeneratedErrorStackData : public P {
  static_assert(
      std::is_same<ErrorStackData, D>::value,
      "Use this class as direct base for ErrorStackData.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedErrorStackData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedErrorStackData<D,P>;

  // Torque type: (class JSReceiver | class Undefined | class Null | class Boolean | class Symbol | class String | BigInt | class HeapNumber | Smi | class FixedArray)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
  inline Tagged<Union<BigInt, Boolean, FixedArray, HeapNumber, JSReceiver, Null, Smi, String, Symbol, Undefined>> call_site_infos_or_formatted_stack() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
  inline Tagged<Union<BigInt, Boolean, FixedArray, HeapNumber, JSReceiver, Null, Smi, String, Symbol, Undefined>> call_site_infos_or_formatted_stack(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
  inline void set_call_site_infos_or_formatted_stack(Tagged<Union<BigInt, Boolean, FixedArray, HeapNumber, JSReceiver, Null, Smi, String, Symbol, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
  inline Tagged<StackTraceInfo> stack_trace() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
  inline Tagged<StackTraceInfo> stack_trace(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
  inline void set_stack_trace(Tagged<StackTraceInfo> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(ErrorStackData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=104&c=1
  V8_EXPORT_PRIVATE void ErrorStackDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
  static constexpr int kCallSiteInfosOrFormattedStackOffset = P::kHeaderSize;
  static constexpr int kCallSiteInfosOrFormattedStackOffsetEnd = kCallSiteInfosOrFormattedStackOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
  static constexpr int kStackTraceOffset = kCallSiteInfosOrFormattedStackOffsetEnd + 1;
  static constexpr int kStackTraceOffsetEnd = kStackTraceOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kStackTraceOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kStackTraceOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kStackTraceOffsetEnd + 1;
  static constexpr int kHeaderSize = kStackTraceOffsetEnd + 1;
  static constexpr int kSize = kStackTraceOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=104&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=104&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedErrorStackData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedErrorStackData, DAlias>::value,
        "class TorqueGeneratedErrorStackData should be used as direct base for ErrorStackData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedErrorStackData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedErrorStackData(Address ptr);
};

struct TorqueGeneratedCoverageInfoSlotOffsets {
  static constexpr int kStartSourcePositionOffset = 0;
  static constexpr int kEndSourcePositionOffset = 4;
  static constexpr int kBlockCountOffset = 8;
  static constexpr int kPaddingOffset = 12;
  static constexpr int kSize = 16;
};

