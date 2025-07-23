class DataHandler;
// Alias for IsDataHandler() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=7&c=1
V8_EXPORT_PRIVATE bool IsDataHandler_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=7&c=1
template <class D, class P>
class TorqueGeneratedDataHandler : public P {
  static_assert(
      std::is_same<DataHandler, D>::value,
      "Use this class as direct base for DataHandler.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedDataHandler.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedDataHandler<D,P>;

  // Torque type: (Smi | class Code)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=13&c=3
  inline Tagged<Union<Code, Smi>> smi_handler() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=13&c=3
  inline Tagged<Union<Code, Smi>> smi_handler(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=13&c=3
  inline void set_smi_handler(Tagged<Union<Code, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | class Cell)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=16&c=3
  inline Tagged<Union<Cell, Smi>> validity_cell() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=16&c=3
  inline Tagged<Union<Cell, Smi>> validity_cell(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=16&c=3
  inline void set_validity_cell(Tagged<Union<Cell, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: MaybeObject
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=19&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> data1() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=19&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> data1(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=19&c=3
  inline void set_data1(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: MaybeObject
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=20&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> data2() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=20&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> data2(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=20&c=3
  inline void set_data2(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: MaybeObject
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=21&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> data3() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=21&c=3
  inline Tagged<Union<HeapObject, MaybeObject, Smi>> data3(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=21&c=3
  inline void set_data3(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=7&c=1
  V8_EXPORT_PRIVATE void DataHandlerVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=13&c=3
  static constexpr int kSmiHandlerOffset = P::kHeaderSize;
  static constexpr int kSmiHandlerOffsetEnd = kSmiHandlerOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=16&c=3
  static constexpr int kValidityCellOffset = kSmiHandlerOffsetEnd + 1;
  static constexpr int kValidityCellOffsetEnd = kValidityCellOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kValidityCellOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kValidityCellOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=19&c=3
  static constexpr int kData1Offset = kValidityCellOffsetEnd + 1;
  static constexpr int kData1OffsetEnd = kData1Offset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=20&c=3
  static constexpr int kData2Offset = kData1OffsetEnd + 1;
  static constexpr int kData2OffsetEnd = kData2Offset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=21&c=3
  static constexpr int kData3Offset = kData2OffsetEnd + 1;
  static constexpr int kData3OffsetEnd = kData3Offset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kData3OffsetEnd + 1;
  static constexpr int kHeaderSize = kData3OffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedDataHandler() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedDataHandler, DAlias>::value,
        "class TorqueGeneratedDataHandler should be used as direct base for DataHandler.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedDataHandler(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedDataHandler(Address ptr);
};

