// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/shadow/shadow_element_names.json5

#include "third_party/blink/renderer/core/html/shadow/shadow_element_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace shadow_element_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kPseudoInternalDatetimeContainer = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kPseudoInternalInputSuggested = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kPseudoMediaControlsSegmentedTrack = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kPseudoInternalPermissionTextSpan = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kSelectAutofillPreview = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kSelectAutofillPreviewText = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kPseudoCalendarPickerIndicator = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kPseudoWebKitDetailsMarker = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kPseudoFileUploadButton = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kPseudoInputPlaceholder = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kPseudoMediaSliderContainer = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kPseudoMediaSliderThumb = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kPseudoMeterInnerElement = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kPseudoSliderContainer = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kPseudoSliderTrack = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kPseudoSliderThumb = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kPseudoTextFieldDecorationContainer = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kIdClearButton = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kIdDateTimeEdit = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kIdDetailsContent = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kIdDetailsMarker = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kIdDetailsSummary = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kIdEditingViewPort = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kIdFileUploadButton = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kIdOptGroupLabel = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kIdPasswordRevealButton = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kIdPickerIndicator = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kPickerSelect = reinterpret_cast<AtomicString*>(&names_storage)[27];
const AtomicString& kIdPlaceholder = reinterpret_cast<AtomicString*>(&names_storage)[28];
const AtomicString& kIdSearchClearButton = reinterpret_cast<AtomicString*>(&names_storage)[29];
const AtomicString& kSelectButton = reinterpret_cast<AtomicString*>(&names_storage)[30];
const AtomicString& kSelectOptions = reinterpret_cast<AtomicString*>(&names_storage)[31];
const AtomicString& kSelectPopoverOptions = reinterpret_cast<AtomicString*>(&names_storage)[32];
const AtomicString& kIdSpinButton = reinterpret_cast<AtomicString*>(&names_storage)[33];
const AtomicString& kIdTextFieldContainer = reinterpret_cast<AtomicString*>(&names_storage)[34];
const AtomicString& kIdSliderThumb = reinterpret_cast<AtomicString*>(&names_storage)[35];
const AtomicString& kIdSliderTrack = reinterpret_cast<AtomicString*>(&names_storage)[36];

void Init()
{
    static bool is_loaded = false;
    if (is_loaded)
        return;
    is_loaded = true;

    struct NameEntry {
        const char* name;
        unsigned char length;
    };

    static const NameEntry kNames[] = {
        { "-internal-datetime-container", 28 },
        { "-internal-input-suggested", 25 },
        { "-internal-media-controls-segmented-track", 40 },
        { "-internal-permission-text", 25 },
        { "-internal-select-autofill-preview", 33 },
        { "-internal-select-autofill-preview-text", 38 },
        { "-webkit-calendar-picker-indicator", 33 },
        { "-webkit-details-marker", 22 },
        { "-webkit-file-upload-button", 26 },
        { "-webkit-input-placeholder", 25 },
        { "-webkit-media-slider-container", 30 },
        { "-webkit-media-slider-thumb", 26 },
        { "-webkit-meter-inner-element", 27 },
        { "-webkit-slider-container", 24 },
        { "-webkit-slider-runnable-track", 29 },
        { "-webkit-slider-thumb", 20 },
        { "-webkit-textfield-decoration-container", 38 },
        { "clear", 5 },
        { "date-time-edit", 14 },
        { "details-content", 15 },
        { "details-marker", 14 },
        { "details-summary", 15 },
        { "editing-view-port", 17 },
        { "file-upload-button", 18 },
        { "optgroup-label", 14 },
        { "password-reveal", 15 },
        { "picker", 6 },
        { "picker(select)", 14 },
        { "placeholder", 11 },
        { "search-clear", 12 },
        { "select-button", 13 },
        { "select-options", 14 },
        { "select-popover-options", 22 },
        { "spin", 4 },
        { "text-field-container", 20 },
        { "thumb", 5 },
        { "track", 5 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace shadow_element_names
} // namespace blink
