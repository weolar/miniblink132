#include "src/objects/literal-objects-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

#include "src/objects/literal-objects.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=5&c=1
class TorqueGeneratedObjectBoilerplateDescriptionAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(HeapObjectLayout);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=7&c=9
  static constexpr int kLengthOffset = sizeof(HeapObjectLayout);
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=8&c=3
  static constexpr int kBackingStoreSizeOffset = kLengthOffsetEnd + 1;
  static constexpr int kBackingStoreSizeOffsetEnd = kBackingStoreSizeOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=9&c=3
  static constexpr int kFlagsOffset = kBackingStoreSizeOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=3
  static constexpr int kRawEntriesOffset = kFlagsOffsetEnd + 1;
  static constexpr int kRawEntriesOffsetEnd = kRawEntriesOffset + 0 - 1;
  static constexpr int kEndOfStrongFieldsOffset = kRawEntriesOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kRawEntriesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kRawEntriesOffsetEnd + 1;

  static_assert(kLengthOffset == offsetof(ObjectBoilerplateDescription, length_),
                "Value of ObjectBoilerplateDescription::kLengthOffset defined in Torque and offset of field ObjectBoilerplateDescription::length in C++ do not match");
  static_assert(kBackingStoreSizeOffset == offsetof(ObjectBoilerplateDescription, backing_store_size_),
                "Value of ObjectBoilerplateDescription::kBackingStoreSizeOffset defined in Torque and offset of field ObjectBoilerplateDescription::backing_store_size in C++ do not match");
  static_assert(kFlagsOffset == offsetof(ObjectBoilerplateDescription, flags_),
                "Value of ObjectBoilerplateDescription::kFlagsOffset defined in Torque and offset of field ObjectBoilerplateDescription::flags in C++ do not match");
  static_assert(kRawEntriesOffset == OFFSET_OF_DATA_START(ObjectBoilerplateDescription),
                "Value of ObjectBoilerplateDescription::kRawEntriesOffset defined in Torque and offset of field ObjectBoilerplateDescription::raw_entries in C++ do not match");
};

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=13&c=1
bool IsArrayBoilerplateDescription_NonInline(Tagged<HeapObject> o) {
  return IsArrayBoilerplateDescription(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedArrayBoilerplateDescription<ArrayBoilerplateDescription, Struct>::ArrayBoilerplateDescriptionVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::ArrayBoilerplateDescriptionVerify(Cast<ArrayBoilerplateDescription>(*this), isolate);
}


#endif  // VERIFY_HEAP
// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=18&c=1
class TorqueGeneratedRegExpBoilerplateDescriptionAsserts {
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=20&c=3
  static constexpr int kDataOffset = Struct::kHeaderSize;
  static constexpr int kDataOffsetEnd = kDataOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=21&c=3
  static constexpr int kSourceOffset = kDataOffsetEnd + 1;
  static constexpr int kSourceOffsetEnd = kSourceOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=22&c=3
  static constexpr int kFlagsOffset = kSourceOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;
  static constexpr int kSize = kFlagsOffsetEnd + 1;

  static_assert(kDataOffset == RegExpBoilerplateDescription::kDataOffset,
                "Values of RegExpBoilerplateDescription::kDataOffset defined in Torque and C++ do not match");
  static_assert(kSourceOffset == RegExpBoilerplateDescription::kSourceOffset,
                "Values of RegExpBoilerplateDescription::kSourceOffset defined in Torque and C++ do not match");
  static_assert(kFlagsOffset == RegExpBoilerplateDescription::kFlagsOffset,
                "Values of RegExpBoilerplateDescription::kFlagsOffset defined in Torque and C++ do not match");
  static_assert(kSize == RegExpBoilerplateDescription::kSize);
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=25&c=1
class TorqueGeneratedClassBoilerplateAsserts {
  static constexpr int kStartOfStrongFieldsOffset = Struct::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=27&c=3
  static constexpr int kArgumentsCountOffset = Struct::kHeaderSize;
  static constexpr int kArgumentsCountOffsetEnd = kArgumentsCountOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=28&c=3
  static constexpr int kStaticPropertiesTemplateOffset = kArgumentsCountOffsetEnd + 1;
  static constexpr int kStaticPropertiesTemplateOffsetEnd = kStaticPropertiesTemplateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=29&c=3
  static constexpr int kStaticElementsTemplateOffset = kStaticPropertiesTemplateOffsetEnd + 1;
  static constexpr int kStaticElementsTemplateOffsetEnd = kStaticElementsTemplateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=30&c=3
  static constexpr int kStaticComputedPropertiesOffset = kStaticElementsTemplateOffsetEnd + 1;
  static constexpr int kStaticComputedPropertiesOffsetEnd = kStaticComputedPropertiesOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=31&c=3
  static constexpr int kInstancePropertiesTemplateOffset = kStaticComputedPropertiesOffsetEnd + 1;
  static constexpr int kInstancePropertiesTemplateOffsetEnd = kInstancePropertiesTemplateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=32&c=3
  static constexpr int kInstanceElementsTemplateOffset = kInstancePropertiesTemplateOffsetEnd + 1;
  static constexpr int kInstanceElementsTemplateOffsetEnd = kInstanceElementsTemplateOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=33&c=3
  static constexpr int kInstanceComputedPropertiesOffset = kInstanceElementsTemplateOffsetEnd + 1;
  static constexpr int kInstanceComputedPropertiesOffsetEnd = kInstanceComputedPropertiesOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kInstanceComputedPropertiesOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kInstanceComputedPropertiesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kInstanceComputedPropertiesOffsetEnd + 1;
  static constexpr int kHeaderSize = kInstanceComputedPropertiesOffsetEnd + 1;
  static constexpr int kSize = kInstanceComputedPropertiesOffsetEnd + 1;

  static_assert(kArgumentsCountOffset == ClassBoilerplate::kArgumentsCountOffset,
                "Values of ClassBoilerplate::kArgumentsCountOffset defined in Torque and C++ do not match");
  static_assert(kStaticPropertiesTemplateOffset == ClassBoilerplate::kStaticPropertiesTemplateOffset,
                "Values of ClassBoilerplate::kStaticPropertiesTemplateOffset defined in Torque and C++ do not match");
  static_assert(kStaticElementsTemplateOffset == ClassBoilerplate::kStaticElementsTemplateOffset,
                "Values of ClassBoilerplate::kStaticElementsTemplateOffset defined in Torque and C++ do not match");
  static_assert(kStaticComputedPropertiesOffset == ClassBoilerplate::kStaticComputedPropertiesOffset,
                "Values of ClassBoilerplate::kStaticComputedPropertiesOffset defined in Torque and C++ do not match");
  static_assert(kInstancePropertiesTemplateOffset == ClassBoilerplate::kInstancePropertiesTemplateOffset,
                "Values of ClassBoilerplate::kInstancePropertiesTemplateOffset defined in Torque and C++ do not match");
  static_assert(kInstanceElementsTemplateOffset == ClassBoilerplate::kInstanceElementsTemplateOffset,
                "Values of ClassBoilerplate::kInstanceElementsTemplateOffset defined in Torque and C++ do not match");
  static_assert(kInstanceComputedPropertiesOffset == ClassBoilerplate::kInstanceComputedPropertiesOffset,
                "Values of ClassBoilerplate::kInstanceComputedPropertiesOffset defined in Torque and C++ do not match");
  static_assert(kSize == ClassBoilerplate::kSize);
};

} // namespace internal
} // namespace v8
