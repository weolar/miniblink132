// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_

#include "base/notreached.h"
#include "third_party/blink/renderer/core/css/css_property_names.h"
#include "third_party/blink/renderer/platform/wtf/text/string_view.h"
#include <string.h>

namespace blink {

enum class AtRuleDescriptorID {
    Invalid = 0,
    AdditiveSymbols = 1,
    AscentOverride = 2,
    BasePalette = 3,
    DescentOverride = 4,
    FontDisplay = 5,
    FontFamily = 6,
    FontFeatureSettings = 7,
    FontStretch = 8,
    FontStyle = 9,
    FontVariant = 10,
    FontWeight = 11,
    Inherits = 12,
    InitialValue = 13,
    Fallback = 14,
    LineGapOverride = 15,
    Negative = 16,
    OverrideColors = 17,
    Pad = 18,
    Prefix = 19,
    Range = 20,
    Navigation = 21,
    Types = 22,
    SizeAdjust = 23,
    SpeakAs = 24,
    Src = 25,
    Suffix = 26,
    Symbols = 27,
    Syntax = 28,
    System = 29,
    UnicodeRange = 30,
};

const int numAtRuleDescriptors = 31;

const char* getValueName(AtRuleDescriptorID);

AtRuleDescriptorID AsAtRuleDescriptorID(StringView string);

CSSPropertyID AtRuleDescriptorIDAsCSSPropertyID(AtRuleDescriptorID);
AtRuleDescriptorID CSSPropertyIDAsAtRuleDescriptor(CSSPropertyID id);

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
