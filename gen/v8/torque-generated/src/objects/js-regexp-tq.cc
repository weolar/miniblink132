#include "src/objects/js-regexp-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

#include "src/objects/js-regexp.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=17&c=1
class TorqueGeneratedRegExpDataAsserts {
    static constexpr int kStartOfStrongFieldsOffset = ExposedTrustedObject::kHeaderSize;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=19&c=3
    static constexpr int kTypeTagOffset = ExposedTrustedObject::kHeaderSize;
    static constexpr int kTypeTagOffsetEnd = kTypeTagOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=20&c=3
    static constexpr int kSourceOffset = kTypeTagOffsetEnd + 1;
    static constexpr int kSourceOffsetEnd = kSourceOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=21&c=3
    static constexpr int kFlagsOffset = kSourceOffsetEnd + 1;
    static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=22&c=3
    static constexpr int kWrapperOffset = kFlagsOffsetEnd + 1;
    static constexpr int kWrapperOffsetEnd = kWrapperOffset + kTaggedSize - 1;
    static constexpr int kEndOfStrongFieldsOffset = kWrapperOffsetEnd + 1;
    static constexpr int kStartOfWeakFieldsOffset = kWrapperOffsetEnd + 1;
    static constexpr int kEndOfWeakFieldsOffset = kWrapperOffsetEnd + 1;
    static constexpr int kHeaderSize = kWrapperOffsetEnd + 1;
    static constexpr int kSize = kWrapperOffsetEnd + 1;

    static_assert(kTypeTagOffset == RegExpData::kTypeTagOffset, "Values of RegExpData::kTypeTagOffset defined in Torque and C++ do not match");
    static_assert(kSourceOffset == RegExpData::kSourceOffset, "Values of RegExpData::kSourceOffset defined in Torque and C++ do not match");
    static_assert(kFlagsOffset == RegExpData::kFlagsOffset, "Values of RegExpData::kFlagsOffset defined in Torque and C++ do not match");
    static_assert(kWrapperOffset == RegExpData::kWrapperOffset, "Values of RegExpData::kWrapperOffset defined in Torque and C++ do not match");
    static_assert(kSize == RegExpData::kSize);
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=25&c=1
class TorqueGeneratedAtomRegExpDataAsserts {
    static constexpr int kStartOfStrongFieldsOffset = RegExpData::kHeaderSize;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=27&c=9
    static constexpr int kPatternOffset = RegExpData::kHeaderSize;
    static constexpr int kPatternOffsetEnd = kPatternOffset + kTaggedSize - 1;
    static constexpr int kEndOfStrongFieldsOffset = kPatternOffsetEnd + 1;
    static constexpr int kStartOfWeakFieldsOffset = kPatternOffsetEnd + 1;
    static constexpr int kEndOfWeakFieldsOffset = kPatternOffsetEnd + 1;
    static constexpr int kHeaderSize = kPatternOffsetEnd + 1;
    static constexpr int kSize = kPatternOffsetEnd + 1;

    static_assert(kPatternOffset == AtomRegExpData::kPatternOffset, "Values of AtomRegExpData::kPatternOffset defined in Torque and C++ do not match");
    static_assert(kSize == AtomRegExpData::kSize);
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=30&c=1
class TorqueGeneratedIrRegExpDataAsserts {
    static constexpr int kStartOfWeakFieldsOffset = RegExpData::kHeaderSize;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=34&c=3
    static constexpr int kLatin1BytecodeOffset = RegExpData::kHeaderSize;
    static constexpr int kLatin1BytecodeOffsetEnd = kLatin1BytecodeOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=35&c=3
    static constexpr int kUc16BytecodeOffset = kLatin1BytecodeOffsetEnd + 1;
    static constexpr int kUc16BytecodeOffsetEnd = kUc16BytecodeOffset + kTaggedSize - 1;
    static constexpr int kEndOfWeakFieldsOffset = kUc16BytecodeOffsetEnd + 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=36&c=3
    static constexpr int kLatin1CodeOffset = kUc16BytecodeOffsetEnd + 1;
    static constexpr int kLatin1CodeOffsetEnd = kLatin1CodeOffset + kTrustedPointerSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=37&c=3
    static constexpr int kUc16CodeOffset = kLatin1CodeOffsetEnd + 1;
    static constexpr int kUc16CodeOffsetEnd = kUc16CodeOffset + kTrustedPointerSize - 1;
    static constexpr int kStartOfStrongFieldsOffset = kUc16CodeOffsetEnd + 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=38&c=3
    static constexpr int kCaptureNameMapOffset = kUc16CodeOffsetEnd + 1;
    static constexpr int kCaptureNameMapOffsetEnd = kCaptureNameMapOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=39&c=3
    static constexpr int kMaxRegisterCountOffset = kCaptureNameMapOffsetEnd + 1;
    static constexpr int kMaxRegisterCountOffsetEnd = kMaxRegisterCountOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=40&c=3
    static constexpr int kCaptureCountOffset = kMaxRegisterCountOffsetEnd + 1;
    static constexpr int kCaptureCountOffsetEnd = kCaptureCountOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=41&c=3
    static constexpr int kTicksUntilTierUpOffset = kCaptureCountOffsetEnd + 1;
    static constexpr int kTicksUntilTierUpOffsetEnd = kTicksUntilTierUpOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=42&c=3
    static constexpr int kBacktrackLimitOffset = kTicksUntilTierUpOffsetEnd + 1;
    static constexpr int kBacktrackLimitOffsetEnd = kBacktrackLimitOffset + kTaggedSize - 1;
    static constexpr int kEndOfStrongFieldsOffset = kBacktrackLimitOffsetEnd + 1;
    static constexpr int kHeaderSize = kBacktrackLimitOffsetEnd + 1;
    static constexpr int kSize = kBacktrackLimitOffsetEnd + 1;

    static_assert(
        kLatin1BytecodeOffset == IrRegExpData::kLatin1BytecodeOffset, "Values of IrRegExpData::kLatin1BytecodeOffset defined in Torque and C++ do not match");
    static_assert(
        kUc16BytecodeOffset == IrRegExpData::kUc16BytecodeOffset, "Values of IrRegExpData::kUc16BytecodeOffset defined in Torque and C++ do not match");
    static_assert(kLatin1CodeOffset == IrRegExpData::kLatin1CodeOffset, "Values of IrRegExpData::kLatin1CodeOffset defined in Torque and C++ do not match");
    static_assert(kUc16CodeOffset == IrRegExpData::kUc16CodeOffset, "Values of IrRegExpData::kUc16CodeOffset defined in Torque and C++ do not match");
    static_assert(
        kCaptureNameMapOffset == IrRegExpData::kCaptureNameMapOffset, "Values of IrRegExpData::kCaptureNameMapOffset defined in Torque and C++ do not match");
    static_assert(kMaxRegisterCountOffset == IrRegExpData::kMaxRegisterCountOffset,
        "Values of IrRegExpData::kMaxRegisterCountOffset defined in Torque and C++ do not match");
    static_assert(
        kCaptureCountOffset == IrRegExpData::kCaptureCountOffset, "Values of IrRegExpData::kCaptureCountOffset defined in Torque and C++ do not match");
    static_assert(kTicksUntilTierUpOffset == IrRegExpData::kTicksUntilTierUpOffset,
        "Values of IrRegExpData::kTicksUntilTierUpOffset defined in Torque and C++ do not match");
    static_assert(
        kBacktrackLimitOffset == IrRegExpData::kBacktrackLimitOffset, "Values of IrRegExpData::kBacktrackLimitOffset defined in Torque and C++ do not match");
    static_assert(kSize == IrRegExpData::kSize);
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=45&c=1
class TorqueGeneratedRegExpDataWrapperAsserts {
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=47&c=3
    static constexpr int kDataOffset = Struct::kHeaderSize;
    static constexpr int kDataOffsetEnd = kDataOffset + kTrustedPointerSize - 1;
    static constexpr int kStartOfWeakFieldsOffset = kDataOffsetEnd + 1;
    static constexpr int kEndOfWeakFieldsOffset = kDataOffsetEnd + 1;
    static constexpr int kStartOfStrongFieldsOffset = kDataOffsetEnd + 1;
    static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
    static constexpr int kHeaderSize = kDataOffsetEnd + 1;
    static constexpr int kSize = kDataOffsetEnd + 1;

    static_assert(kDataOffset == RegExpDataWrapper::kDataOffset, "Values of RegExpDataWrapper::kDataOffset defined in Torque and C++ do not match");
    static_assert(kSize == RegExpDataWrapper::kSize);
};

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=50&c=1
bool IsJSRegExp_NonInline(Tagged<HeapObject> o)
{
    return IsJSRegExp(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSRegExp<JSRegExp, JSObject>::JSRegExpVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSRegExpVerify(Cast<JSRegExp>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
