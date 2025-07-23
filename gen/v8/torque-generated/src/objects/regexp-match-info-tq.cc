#include "src/objects/regexp-match-info.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=5&c=1
class TorqueGeneratedRegExpMatchInfoAsserts {
    static constexpr int kStartOfStrongFieldsOffset = sizeof(HeapObjectLayout);
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=14&c=9
    static constexpr int kLengthOffset = sizeof(HeapObjectLayout);
    static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=15&c=3
    static constexpr int kNumberOfCaptureRegistersOffset = kLengthOffsetEnd + 1;
    static constexpr int kNumberOfCaptureRegistersOffsetEnd = kNumberOfCaptureRegistersOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=16&c=3
    static constexpr int kLastSubjectOffset = kNumberOfCaptureRegistersOffsetEnd + 1;
    static constexpr int kLastSubjectOffsetEnd = kLastSubjectOffset + kTaggedSize - 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=17&c=3
    static constexpr int kLastInputOffset = kLastSubjectOffsetEnd + 1;
    static constexpr int kLastInputOffsetEnd = kLastInputOffset + kTaggedSize - 1;
    static constexpr int kHeaderSize = kLastInputOffsetEnd + 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=19&c=3
    static constexpr int kObjectsOffset = kLastInputOffsetEnd + 1;
    static constexpr int kObjectsOffsetEnd = kObjectsOffset + 0 - 1;
    static constexpr int kEndOfStrongFieldsOffset = kObjectsOffsetEnd + 1;
    static constexpr int kStartOfWeakFieldsOffset = kObjectsOffsetEnd + 1;
    static constexpr int kEndOfWeakFieldsOffset = kObjectsOffsetEnd + 1;

    static_assert(kLengthOffset == offsetof(RegExpMatchInfo, length_),
        "Value of RegExpMatchInfo::kLengthOffset defined in Torque and offset of field RegExpMatchInfo::length in C++ do not match");
    static_assert(kNumberOfCaptureRegistersOffset == offsetof(RegExpMatchInfo, number_of_capture_registers_),
        "Value of RegExpMatchInfo::kNumberOfCaptureRegistersOffset defined in Torque and offset of field RegExpMatchInfo::number_of_capture_registers in C++ "
        "do not match");
    static_assert(kLastSubjectOffset == offsetof(RegExpMatchInfo, last_subject_),
        "Value of RegExpMatchInfo::kLastSubjectOffset defined in Torque and offset of field RegExpMatchInfo::last_subject in C++ do not match");
    static_assert(kLastInputOffset == offsetof(RegExpMatchInfo, last_input_),
        "Value of RegExpMatchInfo::kLastInputOffset defined in Torque and offset of field RegExpMatchInfo::last_input in C++ do not match");
    static_assert(kObjectsOffset == OFFSET_OF_DATA_START(RegExpMatchInfo),
        "Value of RegExpMatchInfo::kObjectsOffset defined in Torque and offset of field RegExpMatchInfo::objects in C++ do not match");
};

} // namespace internal
} // namespace v8
