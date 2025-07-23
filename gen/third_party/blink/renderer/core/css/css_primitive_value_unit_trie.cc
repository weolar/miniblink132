// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/css/templates/css_primitive_value_unit_trie.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/css_primitive_value_units.json5

#include "third_party/blink/renderer/core/css/css_primitive_value.h"

namespace blink {

namespace {

template <typename CharacterType> CSSPrimitiveValue::UnitType cssPrimitiveValueUnitFromTrie(const CharacterType* data, unsigned length)
{
    DCHECK(data);
    DCHECK(length);
    switch (length) {
    case 1:
        switch (ToASCIILower(data[0])) {
        case 'q':
            return CSSPrimitiveValue::UnitType::kQuarterMillimeters;
        case 's':
            return CSSPrimitiveValue::UnitType::kSeconds;
        case 'x':
            return CSSPrimitiveValue::UnitType::kX;
        }
        break;
    case 2:
        switch (ToASCIILower(data[0])) {
        case 'c':
            switch (ToASCIILower(data[1])) {
            case 'h':
                return CSSPrimitiveValue::UnitType::kChs;
            case 'm':
                return CSSPrimitiveValue::UnitType::kCentimeters;
            }
            break;
        case 'e':
            switch (ToASCIILower(data[1])) {
            case 'm':
                return CSSPrimitiveValue::UnitType::kEms;
            case 'x':
                return CSSPrimitiveValue::UnitType::kExs;
            }
            break;
        case 'f':
            if (ToASCIILower(data[1]) == 'r') {
                return CSSPrimitiveValue::UnitType::kFlex;
            }
            break;
        case 'h':
            if (ToASCIILower(data[1]) == 'z') {
                return CSSPrimitiveValue::UnitType::kHertz;
            }
            break;
        case 'i':
            switch (ToASCIILower(data[1])) {
            case 'c':
                return CSSPrimitiveValue::UnitType::kIcs;
            case 'n':
                return CSSPrimitiveValue::UnitType::kInches;
            }
            break;
        case 'l':
            if (ToASCIILower(data[1]) == 'h') {
                return CSSPrimitiveValue::UnitType::kLhs;
            }
            break;
        case 'm':
            switch (ToASCIILower(data[1])) {
            case 'm':
                return CSSPrimitiveValue::UnitType::kMillimeters;
            case 's':
                return CSSPrimitiveValue::UnitType::kMilliseconds;
            }
            break;
        case 'p':
            switch (ToASCIILower(data[1])) {
            case 'c':
                return CSSPrimitiveValue::UnitType::kPicas;
            case 't':
                return CSSPrimitiveValue::UnitType::kPoints;
            case 'x':
                return CSSPrimitiveValue::UnitType::kPixels;
            }
            break;
        case 'v':
            switch (ToASCIILower(data[1])) {
            case 'b':
                return CSSPrimitiveValue::UnitType::kViewportBlockSize;
            case 'h':
                return CSSPrimitiveValue::UnitType::kViewportHeight;
            case 'i':
                return CSSPrimitiveValue::UnitType::kViewportInlineSize;
            case 'w':
                return CSSPrimitiveValue::UnitType::kViewportWidth;
            }
            break;
        }
        break;
    case 3:
        switch (ToASCIILower(data[0])) {
        case 'c':
            switch (ToASCIILower(data[1])) {
            case 'a':
                if (ToASCIILower(data[2]) == 'p') {
                    return CSSPrimitiveValue::UnitType::kCaps;
                }
                break;
            case 'q':
                switch (ToASCIILower(data[2])) {
                case 'b':
                    return CSSPrimitiveValue::UnitType::kContainerBlockSize;
                case 'h':
                    return CSSPrimitiveValue::UnitType::kContainerHeight;
                case 'i':
                    return CSSPrimitiveValue::UnitType::kContainerInlineSize;
                case 'w':
                    return CSSPrimitiveValue::UnitType::kContainerWidth;
                }
                break;
            }
            break;
        case 'd':
            switch (ToASCIILower(data[1])) {
            case 'e':
                if (ToASCIILower(data[2]) == 'g') {
                    return CSSPrimitiveValue::UnitType::kDegrees;
                }
                break;
            case 'p':
                if (ToASCIILower(data[2]) == 'i') {
                    return CSSPrimitiveValue::UnitType::kDotsPerInch;
                }
                break;
            case 'v':
                switch (ToASCIILower(data[2])) {
                case 'b':
                    return CSSPrimitiveValue::UnitType::kDynamicViewportBlockSize;
                case 'h':
                    return CSSPrimitiveValue::UnitType::kDynamicViewportHeight;
                case 'i':
                    return CSSPrimitiveValue::UnitType::kDynamicViewportInlineSize;
                case 'w':
                    return CSSPrimitiveValue::UnitType::kDynamicViewportWidth;
                }
                break;
            }
            break;
        case 'k':
            if (ToASCIILower(data[1]) == 'h' && ToASCIILower(data[2]) == 'z') {
                return CSSPrimitiveValue::UnitType::kKilohertz;
            }
            break;
        case 'l':
            switch (ToASCIILower(data[1])) {
            case 'v':
                switch (ToASCIILower(data[2])) {
                case 'b':
                    return CSSPrimitiveValue::UnitType::kLargeViewportBlockSize;
                case 'h':
                    return CSSPrimitiveValue::UnitType::kLargeViewportHeight;
                case 'i':
                    return CSSPrimitiveValue::UnitType::kLargeViewportInlineSize;
                case 'w':
                    return CSSPrimitiveValue::UnitType::kLargeViewportWidth;
                }
                break;
            }
            break;
        case 'r':
            switch (ToASCIILower(data[1])) {
            case 'a':
                if (ToASCIILower(data[2]) == 'd') {
                    return CSSPrimitiveValue::UnitType::kRadians;
                }
                break;
            case 'c':
                if (ToASCIILower(data[2]) == 'h') {
                    return CSSPrimitiveValue::UnitType::kRchs;
                }
                break;
            case 'e':
                switch (ToASCIILower(data[2])) {
                case 'm':
                    return CSSPrimitiveValue::UnitType::kRems;
                case 'x':
                    return CSSPrimitiveValue::UnitType::kRexs;
                }
                break;
            case 'i':
                if (ToASCIILower(data[2]) == 'c') {
                    return CSSPrimitiveValue::UnitType::kRics;
                }
                break;
            case 'l':
                if (ToASCIILower(data[2]) == 'h') {
                    return CSSPrimitiveValue::UnitType::kRlhs;
                }
                break;
            }
            break;
        case 's':
            switch (ToASCIILower(data[1])) {
            case 'v':
                switch (ToASCIILower(data[2])) {
                case 'b':
                    return CSSPrimitiveValue::UnitType::kSmallViewportBlockSize;
                case 'h':
                    return CSSPrimitiveValue::UnitType::kSmallViewportHeight;
                case 'i':
                    return CSSPrimitiveValue::UnitType::kSmallViewportInlineSize;
                case 'w':
                    return CSSPrimitiveValue::UnitType::kSmallViewportWidth;
                }
                break;
            }
            break;
        }
        break;
    case 4:
        switch (ToASCIILower(data[0])) {
        case 'd':
            switch (ToASCIILower(data[1])) {
            case 'p':
                switch (ToASCIILower(data[2])) {
                case 'c':
                    if (ToASCIILower(data[3]) == 'm') {
                        return CSSPrimitiveValue::UnitType::kDotsPerCentimeter;
                    }
                    break;
                case 'p':
                    if (ToASCIILower(data[3]) == 'x') {
                        return CSSPrimitiveValue::UnitType::kDotsPerPixel;
                    }
                    break;
                }
                break;
            }
            break;
        case 'g':
            if (ToASCIILower(data[1]) == 'r' && ToASCIILower(data[2]) == 'a' && ToASCIILower(data[3]) == 'd') {
                return CSSPrimitiveValue::UnitType::kGradians;
            }
            break;
        case 'r':
            if (ToASCIILower(data[1]) == 'c' && ToASCIILower(data[2]) == 'a' && ToASCIILower(data[3]) == 'p') {
                return CSSPrimitiveValue::UnitType::kRcaps;
            }
            break;
        case 't':
            if (ToASCIILower(data[1]) == 'u' && ToASCIILower(data[2]) == 'r' && ToASCIILower(data[3]) == 'n') {
                return CSSPrimitiveValue::UnitType::kTurns;
            }
            break;
        case 'v':
            switch (ToASCIILower(data[1])) {
            case 'm':
                switch (ToASCIILower(data[2])) {
                case 'a':
                    if (ToASCIILower(data[3]) == 'x') {
                        return CSSPrimitiveValue::UnitType::kViewportMax;
                    }
                    break;
                case 'i':
                    if (ToASCIILower(data[3]) == 'n') {
                        return CSSPrimitiveValue::UnitType::kViewportMin;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 5:
        switch (ToASCIILower(data[0])) {
        case '_':
            if (ToASCIILower(data[1]) == '_' && ToASCIILower(data[2]) == 'q' && ToASCIILower(data[3]) == 'e' && ToASCIILower(data[4]) == 'm') {
                return CSSPrimitiveValue::UnitType::kQuirkyEms;
            }
            break;
        case 'c':
            switch (ToASCIILower(data[1])) {
            case 'q':
                switch (ToASCIILower(data[2])) {
                case 'm':
                    switch (ToASCIILower(data[3])) {
                    case 'a':
                        if (ToASCIILower(data[4]) == 'x') {
                            return CSSPrimitiveValue::UnitType::kContainerMax;
                        }
                        break;
                    case 'i':
                        if (ToASCIILower(data[4]) == 'n') {
                            return CSSPrimitiveValue::UnitType::kContainerMin;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 'd':
            switch (ToASCIILower(data[1])) {
            case 'v':
                switch (ToASCIILower(data[2])) {
                case 'm':
                    switch (ToASCIILower(data[3])) {
                    case 'a':
                        if (ToASCIILower(data[4]) == 'x') {
                            return CSSPrimitiveValue::UnitType::kDynamicViewportMax;
                        }
                        break;
                    case 'i':
                        if (ToASCIILower(data[4]) == 'n') {
                            return CSSPrimitiveValue::UnitType::kDynamicViewportMin;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 'l':
            switch (ToASCIILower(data[1])) {
            case 'v':
                switch (ToASCIILower(data[2])) {
                case 'm':
                    switch (ToASCIILower(data[3])) {
                    case 'a':
                        if (ToASCIILower(data[4]) == 'x') {
                            return CSSPrimitiveValue::UnitType::kLargeViewportMax;
                        }
                        break;
                    case 'i':
                        if (ToASCIILower(data[4]) == 'n') {
                            return CSSPrimitiveValue::UnitType::kLargeViewportMin;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            switch (ToASCIILower(data[1])) {
            case 'v':
                switch (ToASCIILower(data[2])) {
                case 'm':
                    switch (ToASCIILower(data[3])) {
                    case 'a':
                        if (ToASCIILower(data[4]) == 'x') {
                            return CSSPrimitiveValue::UnitType::kSmallViewportMax;
                        }
                        break;
                    case 'i':
                        if (ToASCIILower(data[4]) == 'n') {
                            return CSSPrimitiveValue::UnitType::kSmallViewportMin;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    }

    return CSSPrimitiveValue::UnitType::kUnknown;
}

} // namespace

CSSPrimitiveValue::UnitType CSSPrimitiveValue::StringToUnitType(const LChar* characters8, unsigned length)
{
    return cssPrimitiveValueUnitFromTrie(characters8, length);
}

CSSPrimitiveValue::UnitType CSSPrimitiveValue::StringToUnitType(const UChar* characters16, unsigned length)
{
    return cssPrimitiveValueUnitFromTrie(characters16, length);
}

} // namespace blink
