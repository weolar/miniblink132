// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_attribute_name_lookup_trie.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_attribute_names.json5

#include "third_party/blink/renderer/core/html_element_attribute_name_lookup_trie.h"

#include "third_party/blink/renderer/core/html_names.h"

namespace blink {

const QualifiedName& LookupHTMLAttributeName(const UChar* data, unsigned length)
{
    DCHECK(data);
    DCHECK(length);
    switch (length) {
    case 2:
        switch (data[0]) {
        case 'a':
            if (data[1] == 's') {
                return html_names::kAsAttr;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'd':
                return html_names::kIdAttr;
            case 's':
                return html_names::kIsAttr;
            }
            break;
        }
        break;
    case 3:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"lt", 2 * 2) == 0) {
                return html_names::kAltAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"sp", 2 * 2) == 0) {
                return html_names::kCspAttr;
            }
            break;
        case 'd':
            if (memcmp(data + 1, u"ir", 2 * 2) == 0) {
                return html_names::kDirAttr;
            }
            break;
        case 'e':
            if (memcmp(data + 1, u"nd", 2 * 2) == 0) {
                return html_names::kEndAttr;
            }
            break;
        case 'f':
            if (memcmp(data + 1, u"or", 2 * 2) == 0) {
                return html_names::kForAttr;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"ow", 2 * 2) == 0) {
                return html_names::kLowAttr;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'x') {
                    return html_names::kMaxAttr;
                }
                break;
            case 'i':
                if (data[2] == 'n') {
                    return html_names::kMinAttr;
                }
                break;
            }
            break;
        case 'r':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'l':
                    return html_names::kRelAttr;
                case 'v':
                    return html_names::kRevAttr;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"rc", 2 * 2) == 0) {
                return html_names::kSrcAttr;
            }
            break;
        }
        break;
    case 4:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'b':
                if (memcmp(data + 2, u"br", 2 * 2) == 0) {
                    return html_names::kAbbrAttr;
                }
                break;
            case 'x':
                if (memcmp(data + 2, u"is", 2 * 2) == 0) {
                    return html_names::kAxisAttr;
                }
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'h':
                if (memcmp(data + 2, u"ar", 2 * 2) == 0) {
                    return html_names::kCharAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, u"te", 2 * 2) == 0) {
                    return html_names::kCiteAttr;
                }
                break;
            case 'o':
                switch (data[2]) {
                case 'd':
                    if (data[3] == 'e') {
                        return html_names::kCodeAttr;
                    }
                    break;
                case 'l':
                    if (data[3] == 's') {
                        return html_names::kColsAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, u"ata", 2 * 3) == 0) {
                return html_names::kDataAttr;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"ce", 2 * 2) == 0) {
                    return html_names::kFaceAttr;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"rm", 2 * 2) == 0) {
                    return html_names::kFormAttr;
                }
                break;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, u"gh", 2 * 2) == 0) {
                    return html_names::kHighAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"ef", 2 * 2) == 0) {
                    return html_names::kHrefAttr;
                }
                break;
            }
            break;
        case 'k':
            if (memcmp(data + 1, u"ind", 2 * 3) == 0) {
                return html_names::kKindAttr;
            }
            break;
        case 'l':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"ng", 2 * 2) == 0) {
                    return html_names::kLangAttr;
                }
                break;
            case 'i':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 'k') {
                        return html_names::kLinkAttr;
                    }
                    break;
                case 's':
                    if (data[3] == 't') {
                        return html_names::kListAttr;
                    }
                    break;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"op", 2 * 2) == 0) {
                    return html_names::kLoopAttr;
                }
                break;
            }
            break;
        case 'n':
            if (memcmp(data + 1, u"ame", 2 * 3) == 0) {
                return html_names::kNameAttr;
            }
            break;
        case 'o':
            if (memcmp(data + 1, u"pen", 2 * 3) == 0) {
                return html_names::kOpenAttr;
            }
            break;
        case 'p':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"rt", 2 * 2) == 0) {
                    return html_names::kPartAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, u"ng", 2 * 2) == 0) {
                    return html_names::kPingAttr;
                }
                break;
            }
            break;
        case 'r':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'l':
                    if (data[3] == 'e') {
                        return html_names::kRoleAttr;
                    }
                    break;
                case 'w':
                    if (data[3] == 's') {
                        return html_names::kRowsAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, u"ze", 2 * 2) == 0) {
                    return html_names::kSizeAttr;
                }
                break;
            case 'l':
                if (memcmp(data + 2, u"ot", 2 * 2) == 0) {
                    return html_names::kSlotAttr;
                }
                break;
            case 'p':
                if (memcmp(data + 2, u"an", 2 * 2) == 0) {
                    return html_names::kSpanAttr;
                }
                break;
            case 't':
                if (memcmp(data + 2, u"ep", 2 * 2) == 0) {
                    return html_names::kStepAttr;
                }
                break;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, u"xt", 2 * 2) == 0) {
                    return html_names::kTextAttr;
                }
                break;
            case 'y':
                if (memcmp(data + 2, u"pe", 2 * 2) == 0) {
                    return html_names::kTypeAttr;
                }
                break;
            }
            break;
        case 'w':
            if (memcmp(data + 1, u"rap", 2 * 3) == 0) {
                return html_names::kWrapAttr;
            }
            break;
        }
        break;
    case 5:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'i':
                    switch (data[3]) {
                    case 'g':
                        if (data[4] == 'n') {
                            return html_names::kAlignAttr;
                        }
                        break;
                    case 'n':
                        if (data[4] == 'k') {
                            return html_names::kAlinkAttr;
                        }
                        break;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, u"ow", 2 * 2) == 0) {
                        return html_names::kAllowAttr;
                    }
                    break;
                }
                break;
            case 's':
                if (memcmp(data + 2, u"ync", 2 * 3) == 0) {
                    return html_names::kAsyncAttr;
                }
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"ss", 2 * 2) == 0) {
                        return html_names::kClassAttr;
                    }
                    break;
                case 'e':
                    if (memcmp(data + 3, u"ar", 2 * 2) == 0) {
                        return html_names::kClearAttr;
                    }
                    break;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"lor", 2 * 3) == 0) {
                    return html_names::kColorAttr;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, u"efer", 2 * 4) == 0) {
                return html_names::kDeferAttr;
            }
            break;
        case 'e':
            if (memcmp(data + 1, u"vent", 2 * 4) == 0) {
                return html_names::kEventAttr;
            }
            break;
        case 'f':
            if (memcmp(data + 1, u"rame", 2 * 4) == 0) {
                return html_names::kFrameAttr;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'n':
                if (memcmp(data + 2, u"ert", 2 * 3) == 0) {
                    return html_names::kInertAttr;
                }
                break;
            case 's':
                if (memcmp(data + 2, u"map", 2 * 3) == 0) {
                    return html_names::kIsmapAttr;
                }
                break;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"abel", 2 * 4) == 0) {
                return html_names::kLabelAttr;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, u"dia", 2 * 3) == 0) {
                    return html_names::kMediaAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, u"ted", 2 * 3) == 0) {
                    return html_names::kMutedAttr;
                }
                break;
            }
            break;
        case 'n':
            if (memcmp(data + 1, u"once", 2 * 4) == 0) {
                return html_names::kNonceAttr;
            }
            break;
        case 'o':
            if (memcmp(data + 1, u"ncut", 2 * 4) == 0) {
                return html_names::kOncutAttr;
            }
            break;
        case 'r':
            if (memcmp(data + 1, u"ules", 2 * 4) == 0) {
                return html_names::kRulesAttr;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, u"ope", 2 * 3) == 0) {
                    return html_names::kScopeAttr;
                }
                break;
            case 'h':
                if (memcmp(data + 2, u"ape", 2 * 3) == 0) {
                    return html_names::kShapeAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, u"zes", 2 * 3) == 0) {
                    return html_names::kSizesAttr;
                }
                break;
            case 't':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"rt", 2 * 2) == 0) {
                        return html_names::kStartAttr;
                    }
                    break;
                case 'y':
                    if (memcmp(data + 3, u"le", 2 * 2) == 0) {
                        return html_names::kStyleAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 't':
            if (memcmp(data + 1, u"itle", 2 * 4) == 0) {
                return html_names::kTitleAttr;
            }
            break;
        case 'v':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"lue", 2 * 3) == 0) {
                    return html_names::kValueAttr;
                }
                break;
            case 'l':
                if (memcmp(data + 2, u"ink", 2 * 3) == 0) {
                    return html_names::kVlinkAttr;
                }
                break;
            }
            break;
        case 'w':
            if (memcmp(data + 1, u"idth", 2 * 4) == 0) {
                return html_names::kWidthAttr;
            }
            break;
        }
        break;
    case 6:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, u"ept", 2 * 3) == 0) {
                        return html_names::kAcceptAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, u"ion", 2 * 3) == 0) {
                        return html_names::kActionAttr;
                    }
                    break;
                }
                break;
            case 'n':
                if (memcmp(data + 2, u"chor", 2 * 4) == 0) {
                    return html_names::kAnchorAttr;
                }
                break;
            }
            break;
        case 'b':
            if (memcmp(data + 1, u"order", 2 * 5) == 0) {
                return html_names::kBorderAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"oords", 2 * 5) == 0) {
                return html_names::kCoordsAttr;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, u"ight", 2 * 4) == 0) {
                    return html_names::kHeightAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, u"dden", 2 * 4) == 0) {
                    return html_names::kHiddenAttr;
                }
                break;
            case 's':
                if (memcmp(data + 2, u"pace", 2 * 4) == 0) {
                    return html_names::kHspaceAttr;
                }
                break;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"owsrc", 2 * 5) == 0) {
                return html_names::kLowsrcAttr;
            }
            break;
        case 'm':
            if (memcmp(data + 1, u"ethod", 2 * 5) == 0) {
                return html_names::kMethodAttr;
            }
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'h':
                    if (memcmp(data + 3, u"ref", 2 * 3) == 0) {
                        return html_names::kNohrefAttr;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, u"rap", 2 * 3) == 0) {
                        return html_names::kNowrapAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'b':
                if (memcmp(data + 2, u"ject", 2 * 4) == 0) {
                    return html_names::kObjectAttr;
                }
                break;
            case 'n':
                switch (data[2]) {
                case 'b':
                    if (memcmp(data + 3, u"lur", 2 * 3) == 0) {
                        return html_names::kOnblurAttr;
                    }
                    break;
                case 'c':
                    if (memcmp(data + 3, u"opy", 2 * 3) == 0) {
                        return html_names::kOncopyAttr;
                    }
                    break;
                case 'd':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'a':
                            if (data[5] == 'g') {
                                return html_names::kOndragAttr;
                            }
                            break;
                        case 'o':
                            if (data[5] == 'p') {
                                return html_names::kOndropAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, u"oad", 2 * 3) == 0) {
                        return html_names::kOnloadAttr;
                    }
                    break;
                case 'm':
                    if (memcmp(data + 3, u"ove", 2 * 3) == 0) {
                        return html_names::kOnmoveAttr;
                    }
                    break;
                case 'p':
                    if (memcmp(data + 3, u"lay", 2 * 3) == 0) {
                        return html_names::kOnplayAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"how", 2 * 3) == 0) {
                        return html_names::kOnshowAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'l':
                    if (memcmp(data + 3, u"icy", 2 * 3) == 0) {
                        return html_names::kPolicyAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"ter", 2 * 3) == 0) {
                        return html_names::kPosterAttr;
                    }
                    break;
                }
                break;
            case 's':
                if (memcmp(data + 2, u"eudo", 2 * 4) == 0) {
                    return html_names::kPseudoAttr;
                }
                break;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, u"heme", 2 * 4) == 0) {
                    return html_names::kSchemeAttr;
                }
                break;
            case 'e':
                if (memcmp(data + 2, u"lect", 2 * 4) == 0) {
                    return html_names::kSelectAttr;
                }
                break;
            case 'r':
                switch (data[2]) {
                case 'c':
                    switch (data[3]) {
                    case 'd':
                        if (memcmp(data + 4, u"oc", 2 * 2) == 0) {
                            return html_names::kSrcdocAttr;
                        }
                        break;
                    case 's':
                        if (memcmp(data + 4, u"et", 2 * 2) == 0) {
                            return html_names::kSrcsetAttr;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 't':
            if (memcmp(data + 1, u"arget", 2 * 5) == 0) {
                return html_names::kTargetAttr;
            }
            break;
        case 'u':
            if (memcmp(data + 1, u"semap", 2 * 5) == 0) {
                return html_names::kUsemapAttr;
            }
            break;
        case 'v':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"lign", 2 * 4) == 0) {
                    return html_names::kValignAttr;
                }
                break;
            case 's':
                if (memcmp(data + 2, u"pace", 2 * 4) == 0) {
                    return html_names::kVspaceAttr;
                }
                break;
            }
            break;
        }
        break;
    case 7:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"rchive", 2 * 6) == 0) {
                return html_names::kArchiveAttr;
            }
            break;
        case 'b':
            if (memcmp(data + 1, u"gcolor", 2 * 6) == 0) {
                return html_names::kBgcolorAttr;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"pture", 2 * 5) == 0) {
                    return html_names::kCaptureAttr;
                }
                break;
            case 'h':
                switch (data[2]) {
                case 'a':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'o':
                            if (memcmp(data + 5, u"ff", 2 * 2) == 0) {
                                return html_names::kCharoffAttr;
                            }
                            break;
                        case 's':
                            if (memcmp(data + 5, u"et", 2 * 2) == 0) {
                                return html_names::kCharsetAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'e':
                    if (memcmp(data + 3, u"cked", 2 * 4) == 0) {
                        return html_names::kCheckedAttr;
                    }
                    break;
                }
                break;
            case 'l':
                if (memcmp(data + 2, u"assid", 2 * 5) == 0) {
                    return html_names::kClassidAttr;
                }
                break;
            case 'o':
                switch (data[2]) {
                case 'l':
                    if (memcmp(data + 3, u"span", 2 * 4) == 0) {
                        return html_names::kColspanAttr;
                    }
                    break;
                case 'm':
                    switch (data[3]) {
                    case 'm':
                        if (memcmp(data + 4, u"and", 2 * 3) == 0) {
                            return html_names::kCommandAttr;
                        }
                        break;
                    case 'p':
                        if (memcmp(data + 4, u"act", 2 * 3) == 0) {
                            return html_names::kCompactAttr;
                        }
                        break;
                    }
                    break;
                case 'n':
                    if (memcmp(data + 3, u"tent", 2 * 4) == 0) {
                        return html_names::kContentAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, u"lare", 2 * 4) == 0) {
                        return html_names::kDeclareAttr;
                    }
                    break;
                case 'f':
                    if (memcmp(data + 3, u"ault", 2 * 4) == 0) {
                        return html_names::kDefaultAttr;
                    }
                    break;
                }
                break;
            case 'i':
                if (memcmp(data + 2, u"rname", 2 * 5) == 0) {
                    return html_names::kDirnameAttr;
                }
                break;
            }
            break;
        case 'e':
            if (memcmp(data + 1, u"nctype", 2 * 6) == 0) {
                return html_names::kEnctypeAttr;
            }
            break;
        case 'h':
            if (memcmp(data + 1, u"eaders", 2 * 6) == 0) {
                return html_names::kHeadersAttr;
            }
            break;
        case 'k':
            if (memcmp(data + 1, u"eytype", 2 * 6) == 0) {
                return html_names::kKeytypeAttr;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"oading", 2 * 6) == 0) {
                return html_names::kLoadingAttr;
            }
            break;
        case 'n':
            if (memcmp(data + 1, u"oshade", 2 * 6) == 0) {
                return html_names::kNoshadeAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"bort", 2 * 4) == 0) {
                        return html_names::kOnabortAttr;
                    }
                    break;
                case 'c':
                    switch (data[3]) {
                    case 'l':
                        switch (data[4]) {
                        case 'i':
                            if (memcmp(data + 5, u"ck", 2 * 2) == 0) {
                                return html_names::kOnclickAttr;
                            }
                            break;
                        case 'o':
                            if (memcmp(data + 5, u"se", 2 * 2) == 0) {
                                return html_names::kOncloseAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'e':
                    switch (data[3]) {
                    case 'n':
                        if (memcmp(data + 4, u"ded", 2 * 3) == 0) {
                            return html_names::kOnendedAttr;
                        }
                        break;
                    case 'r':
                        if (memcmp(data + 4, u"ror", 2 * 3) == 0) {
                            return html_names::kOnerrorAttr;
                        }
                        break;
                    }
                    break;
                case 'f':
                    if (memcmp(data + 3, u"ocus", 2 * 4) == 0) {
                        return html_names::kOnfocusAttr;
                    }
                    break;
                case 'i':
                    if (memcmp(data + 3, u"nput", 2 * 4) == 0) {
                        return html_names::kOninputAttr;
                    }
                    break;
                case 'k':
                    if (memcmp(data + 3, u"eyup", 2 * 4) == 0) {
                        return html_names::kOnkeyupAttr;
                    }
                    break;
                case 'p':
                    switch (data[3]) {
                    case 'a':
                        switch (data[4]) {
                        case 's':
                            if (memcmp(data + 5, u"te", 2 * 2) == 0) {
                                return html_names::kOnpasteAttr;
                            }
                            break;
                        case 'u':
                            if (memcmp(data + 5, u"se", 2 * 2) == 0) {
                                return html_names::kOnpauseAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, u"eset", 2 * 4) == 0) {
                        return html_names::kOnresetAttr;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, u"heel", 2 * 4) == 0) {
                        return html_names::kOnwheelAttr;
                    }
                    break;
                }
                break;
            case 'p':
                if (memcmp(data + 2, u"timum", 2 * 5) == 0) {
                    return html_names::kOptimumAttr;
                }
                break;
            }
            break;
        case 'p':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"ttern", 2 * 5) == 0) {
                    return html_names::kPatternAttr;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"pover", 2 * 5) == 0) {
                    return html_names::kPopoverAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"eload", 2 * 5) == 0) {
                    return html_names::kPreloadAttr;
                }
                break;
            }
            break;
        case 'r':
            if (memcmp(data + 1, u"owspan", 2 * 6) == 0) {
                return html_names::kRowspanAttr;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"ndbox", 2 * 5) == 0) {
                    return html_names::kSandboxAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"clang", 2 * 5) == 0) {
                    return html_names::kSrclangAttr;
                }
                break;
            case 't':
                if (memcmp(data + 2, u"andby", 2 * 5) == 0) {
                    return html_names::kStandbyAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, u"mmary", 2 * 5) == 0) {
                    return html_names::kSummaryAttr;
                }
                break;
            }
            break;
        case 'v':
            if (memcmp(data + 1, u"ersion", 2 * 6) == 0) {
                return html_names::kVersionAttr;
            }
            break;
        }
        break;
    case 8:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"utoplay", 2 * 7) == 0) {
                return html_names::kAutoplayAttr;
            }
            break;
        case 'b':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, u"havior", 2 * 6) == 0) {
                    return html_names::kBehaviorAttr;
                }
                break;
            case 'l':
                if (memcmp(data + 2, u"ocking", 2 * 6) == 0) {
                    return html_names::kBlockingAttr;
                }
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'l':
                if (memcmp(data + 2, u"osedby", 2 * 6) == 0) {
                    return html_names::kClosedbyAttr;
                }
                break;
            case 'o':
                switch (data[2]) {
                case 'd':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'b':
                            if (memcmp(data + 5, u"ase", 2 * 3) == 0) {
                                return html_names::kCodebaseAttr;
                            }
                            break;
                        case 't':
                            if (memcmp(data + 5, u"ype", 2 * 3) == 0) {
                                return html_names::kCodetypeAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'n':
                    if (memcmp(data + 3, u"trols", 2 * 5) == 0) {
                        return html_names::kControlsAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 't':
                    switch (data[3]) {
                    case 'a':
                        if (memcmp(data + 4, u"-src", 2 * 4) == 0) {
                            return html_names::kDataSrcAttr;
                        }
                        break;
                    case 'e':
                        if (memcmp(data + 4, u"time", 2 * 4) == 0) {
                            return html_names::kDatetimeAttr;
                        }
                        break;
                    }
                    break;
                }
                break;
            case 'e':
                if (memcmp(data + 2, u"coding", 2 * 6) == 0) {
                    return html_names::kDecodingAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, u"sabled", 2 * 6) == 0) {
                    return html_names::kDisabledAttr;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"wnload", 2 * 6) == 0) {
                    return html_names::kDownloadAttr;
                }
                break;
            }
            break;
        case 'h':
            if (memcmp(data + 1, u"reflang", 2 * 7) == 0) {
                return html_names::kHreflangAttr;
            }
            break;
        case 'i':
            if (memcmp(data + 1, u"temprop", 2 * 7) == 0) {
                return html_names::kItempropAttr;
            }
            break;
        case 'l':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"nguage", 2 * 6) == 0) {
                    return html_names::kLanguageAttr;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"ngdesc", 2 * 6) == 0) {
                    return html_names::kLongdescAttr;
                }
                break;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"nifest", 2 * 6) == 0) {
                    return html_names::kManifestAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, u"ltiple", 2 * 6) == 0) {
                    return html_names::kMultipleAttr;
                }
                break;
            }
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'm':
                    if (memcmp(data + 3, u"odule", 2 * 5) == 0) {
                        return html_names::kNomoduleAttr;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, u"esize", 2 * 5) == 0) {
                        return html_names::kNoresizeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    switch (data[3]) {
                    case 'a':
                        if (memcmp(data + 4, u"ncel", 2 * 4) == 0) {
                            return html_names::kOncancelAttr;
                        }
                        break;
                    case 'h':
                        if (memcmp(data + 4, u"ange", 2 * 4) == 0) {
                            return html_names::kOnchangeAttr;
                        }
                        break;
                    }
                    break;
                case 'o':
                    if (memcmp(data + 3, u"nline", 2 * 5) == 0) {
                        return html_names::kOnonlineAttr;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, u"esize", 2 * 5) == 0) {
                        return html_names::kOnresizeAttr;
                    }
                    break;
                case 's':
                    switch (data[3]) {
                    case 'c':
                        if (memcmp(data + 4, u"roll", 2 * 4) == 0) {
                            return html_names::kOnscrollAttr;
                        }
                        break;
                    case 'e':
                        switch (data[4]) {
                        case 'a':
                            if (memcmp(data + 5, u"rch", 2 * 3) == 0) {
                                return html_names::kOnsearchAttr;
                            }
                            break;
                        case 'e':
                            if (memcmp(data + 5, u"ked", 2 * 3) == 0) {
                                return html_names::kOnseekedAttr;
                            }
                            break;
                        case 'l':
                            if (memcmp(data + 5, u"ect", 2 * 3) == 0) {
                                return html_names::kOnselectAttr;
                            }
                            break;
                        }
                        break;
                    case 'u':
                        if (memcmp(data + 4, u"bmit", 2 * 4) == 0) {
                            return html_names::kOnsubmitAttr;
                        }
                        break;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, u"oggle", 2 * 5) == 0) {
                        return html_names::kOntoggleAttr;
                    }
                    break;
                case 'u':
                    if (memcmp(data + 3, u"nload", 2 * 5) == 0) {
                        return html_names::kOnunloadAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"roperty", 2 * 7) == 0) {
                return html_names::kPropertyAttr;
            }
            break;
        case 'r':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"donly", 2 * 5) == 0) {
                        return html_names::kReadonlyAttr;
                    }
                    break;
                case 'q':
                    if (memcmp(data + 3, u"uired", 2 * 5) == 0) {
                        return html_names::kRequiredAttr;
                    }
                    break;
                case 'v':
                    if (memcmp(data + 3, u"ersed", 2 * 5) == 0) {
                        return html_names::kReversedAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"elected", 2 * 7) == 0) {
                return html_names::kSelectedAttr;
            }
            break;
        case 't':
            if (memcmp(data + 1, u"abindex", 2 * 7) == 0) {
                return html_names::kTabindexAttr;
            }
            break;
        }
        break;
    case 9:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, u"cesskey", 2 * 7) == 0) {
                    return html_names::kAccesskeyAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, u"tofocus", 2 * 7) == 0) {
                    return html_names::kAutofocusAttr;
                }
                break;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"hallenge", 2 * 8) == 0) {
                return html_names::kChallengeAttr;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, u"rection", 2 * 7) == 0) {
                    return html_names::kDirectionAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"aggable", 2 * 7) == 0) {
                    return html_names::kDraggableAttr;
                }
                break;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'p':
                    if (memcmp(data + 3, u"utmode", 2 * 6) == 0) {
                        return html_names::kInputmodeAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, u"egrity", 2 * 6) == 0) {
                        return html_names::kIntegrityAttr;
                    }
                    break;
                case 'v':
                    if (memcmp(data + 3, u"isible", 2 * 6) == 0) {
                        return html_names::kInvisibleAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'x':
                    if (memcmp(data + 3, u"length", 2 * 6) == 0) {
                        return html_names::kMaxlengthAttr;
                    }
                    break;
                case 'y':
                    if (memcmp(data + 3, u"script", 2 * 6) == 0) {
                        return html_names::kMayscriptAttr;
                    }
                    break;
                }
                break;
            case 'i':
                if (memcmp(data + 2, u"nlength", 2 * 7) == 0) {
                    return html_names::kMinlengthAttr;
                }
                break;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, u"anplay", 2 * 6) == 0) {
                        return html_names::kOncanplayAttr;
                    }
                    break;
                case 'd':
                    switch (data[3]) {
                    case 'i':
                        if (memcmp(data + 4, u"smiss", 2 * 5) == 0) {
                            return html_names::kOndismissAttr;
                        }
                        break;
                    case 'r':
                        if (memcmp(data + 4, u"agend", 2 * 5) == 0) {
                            return html_names::kOndragendAttr;
                        }
                        break;
                    }
                    break;
                case 'e':
                    if (memcmp(data + 3, u"mptied", 2 * 6) == 0) {
                        return html_names::kOnemptiedAttr;
                    }
                    break;
                case 'f':
                    if (memcmp(data + 3, u"ocusin", 2 * 6) == 0) {
                        return html_names::kOnfocusinAttr;
                    }
                    break;
                case 'i':
                    if (memcmp(data + 3, u"nvalid", 2 * 6) == 0) {
                        return html_names::kOninvalidAttr;
                    }
                    break;
                case 'k':
                    if (memcmp(data + 3, u"eydown", 2 * 6) == 0) {
                        return html_names::kOnkeydownAttr;
                    }
                    break;
                case 'm':
                    switch (data[3]) {
                    case 'e':
                        if (memcmp(data + 4, u"ssage", 2 * 5) == 0) {
                            return html_names::kOnmessageAttr;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, u"useup", 2 * 5) == 0) {
                            return html_names::kOnmouseupAttr;
                        }
                        break;
                    }
                    break;
                case 'o':
                    if (memcmp(data + 3, u"ffline", 2 * 6) == 0) {
                        return html_names::kOnofflineAttr;
                    }
                    break;
                case 'p':
                    if (memcmp(data + 3, u"laying", 2 * 6) == 0) {
                        return html_names::kOnplayingAttr;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, u"esolve", 2 * 6) == 0) {
                        return html_names::kOnresolveAttr;
                    }
                    break;
                case 's':
                    switch (data[3]) {
                    case 'e':
                        if (memcmp(data + 4, u"eking", 2 * 5) == 0) {
                            return html_names::kOnseekingAttr;
                        }
                        break;
                    case 't':
                        switch (data[4]) {
                        case 'a':
                            if (memcmp(data + 5, u"lled", 2 * 4) == 0) {
                                return html_names::kOnstalledAttr;
                            }
                            break;
                        case 'o':
                            if (memcmp(data + 5, u"rage", 2 * 4) == 0) {
                                return html_names::kOnstorageAttr;
                            }
                            break;
                        }
                        break;
                    case 'u':
                        if (memcmp(data + 4, u"spend", 2 * 5) == 0) {
                            return html_names::kOnsuspendAttr;
                        }
                        break;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, u"aiting", 2 * 6) == 0) {
                        return html_names::kOnwaitingAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"crolling", 2 * 8) == 0) {
                return html_names::kScrollingAttr;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'o':
                if (memcmp(data + 2, u"pmargin", 2 * 7) == 0) {
                    return html_names::kTopmarginAttr;
                }
                break;
            case 'r':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"nslate", 2 * 6) == 0) {
                        return html_names::kTranslateAttr;
                    }
                    break;
                case 'u':
                    if (memcmp(data + 3, u"espeed", 2 * 6) == 0) {
                        return html_names::kTruespeedAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'v':
            if (memcmp(data + 1, u"aluetype", 2 * 8) == 0) {
                return html_names::kValuetypeAttr;
            }
            break;
        }
        break;
    case 10:
        switch (data[0]) {
        case 'b':
            if (memcmp(data + 1, u"ackground", 2 * 9) == 0) {
                return html_names::kBackgroundAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"ommandfor", 2 * 9) == 0) {
                return html_names::kCommandforAttr;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, u"usgroup", 2 * 7) == 0) {
                        return html_names::kFocusgroupAttr;
                    }
                    break;
                case 'r':
                    switch (data[3]) {
                    case 'm':
                        switch (data[4]) {
                        case 'a':
                            if (memcmp(data + 5, u"ction", 2 * 5) == 0) {
                                return html_names::kFormactionAttr;
                            }
                            break;
                        case 'm':
                            if (memcmp(data + 5, u"ethod", 2 * 5) == 0) {
                                return html_names::kFormmethodAttr;
                            }
                            break;
                        case 't':
                            if (memcmp(data + 5, u"arget", 2 * 5) == 0) {
                                return html_names::kFormtargetAttr;
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
        case 'h':
            if (memcmp(data + 1, u"ttp-equiv", 2 * 9) == 0) {
                return html_names::kHttpEquivAttr;
            }
            break;
        case 'i':
            if (memcmp(data + 1, u"magesizes", 2 * 9) == 0) {
                return html_names::kImagesizesAttr;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"eftmargin", 2 * 9) == 0) {
                return html_names::kLeftmarginAttr;
            }
            break;
        case 'n':
            if (memcmp(data + 1, u"ovalidate", 2 * 9) == 0) {
                return html_names::kNovalidateAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"uxclick", 2 * 7) == 0) {
                        return html_names::kOnauxclickAttr;
                    }
                    break;
                case 'd':
                    switch (data[3]) {
                    case 'b':
                        if (memcmp(data + 4, u"lclick", 2 * 6) == 0) {
                            return html_names::kOndblclickAttr;
                        }
                        break;
                    case 'r':
                        if (memcmp(data + 4, u"agover", 2 * 6) == 0) {
                            return html_names::kOndragoverAttr;
                        }
                        break;
                    }
                    break;
                case 'f':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'c':
                            if (memcmp(data + 5, u"usout", 2 * 5) == 0) {
                                return html_names::kOnfocusoutAttr;
                            }
                            break;
                        case 'r':
                            if (memcmp(data + 5, u"mdata", 2 * 5) == 0) {
                                return html_names::kOnformdataAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'k':
                    if (memcmp(data + 3, u"eypress", 2 * 7) == 0) {
                        return html_names::kOnkeypressAttr;
                    }
                    break;
                case 'm':
                    if (memcmp(data + 3, u"ouseout", 2 * 7) == 0) {
                        return html_names::kOnmouseoutAttr;
                    }
                    break;
                case 'p':
                    switch (data[3]) {
                    case 'a':
                        switch (data[4]) {
                        case 'g':
                            switch (data[5]) {
                            case 'e':
                                switch (data[6]) {
                                case 'h':
                                    if (memcmp(data + 7, u"ide", 2 * 3) == 0) {
                                        return html_names::kOnpagehideAttr;
                                    }
                                    break;
                                case 's':
                                    if (memcmp(data + 7, u"how", 2 * 3) == 0) {
                                        return html_names::kOnpageshowAttr;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, u"pstate", 2 * 6) == 0) {
                            return html_names::kOnpopstateAttr;
                        }
                        break;
                    case 'r':
                        if (memcmp(data + 4, u"ogress", 2 * 6) == 0) {
                            return html_names::kOnprogressAttr;
                        }
                        break;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, u"ouchend", 2 * 7) == 0) {
                        return html_names::kOntouchendAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"arseparts", 2 * 9) == 0) {
                return html_names::kParsepartsAttr;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'h':
                if (memcmp(data + 2, u"adowroot", 2 * 8) == 0) {
                    return html_names::kShadowrootAttr;
                }
                break;
            case 'p':
                if (memcmp(data + 2, u"ellcheck", 2 * 8) == 0) {
                    return html_names::kSpellcheckAttr;
                }
                break;
            }
            break;
        }
        break;
    case 11:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"utocorrect", 2 * 10) == 0) {
                return html_names::kAutocorrectAttr;
            }
            break;
        case 'b':
            if (memcmp(data + 1, u"ordercolor", 2 * 10) == 0) {
                return html_names::kBordercolorAttr;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'l':
                    switch (data[3]) {
                    case 'l':
                        switch (data[4]) {
                        case 'p':
                            if (memcmp(data + 5, u"adding", 2 * 6) == 0) {
                                return html_names::kCellpaddingAttr;
                            }
                            break;
                        case 's':
                            if (memcmp(data + 5, u"pacing", 2 * 6) == 0) {
                                return html_names::kCellspacingAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"ossorigin", 2 * 9) == 0) {
                    return html_names::kCrossoriginAttr;
                }
                break;
            }
            break;
        case 'e':
            if (memcmp(data + 1, u"xportparts", 2 * 10) == 0) {
                return html_names::kExportpartsAttr;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'o':
                if (memcmp(data + 2, u"rmenctype", 2 * 9) == 0) {
                    return html_names::kFormenctypeAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"ameborder", 2 * 9) == 0) {
                    return html_names::kFrameborderAttr;
                }
                break;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'm':
                if (memcmp(data + 2, u"agesrcset", 2 * 9) == 0) {
                    return html_names::kImagesrcsetAttr;
                }
                break;
            case 'n':
                if (memcmp(data + 2, u"cremental", 2 * 9) == 0) {
                    return html_names::kIncrementalAttr;
                }
                break;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"atencyhint", 2 * 10) == 0) {
                return html_names::kLatencyhintAttr;
            }
            break;
        case 'm':
            if (memcmp(data + 1, u"arginwidth", 2 * 10) == 0) {
                return html_names::kMarginwidthAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'b':
                    if (memcmp(data + 3, u"eforecut", 2 * 8) == 0) {
                        return html_names::kOnbeforecutAttr;
                    }
                    break;
                case 'c':
                    if (memcmp(data + 3, u"uechange", 2 * 8) == 0) {
                        return html_names::kOncuechangeAttr;
                    }
                    break;
                case 'd':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'a':
                            switch (data[5]) {
                            case 'g':
                                switch (data[6]) {
                                case 'e':
                                    if (memcmp(data + 7, u"nter", 2 * 4) == 0) {
                                        return html_names::kOndragenterAttr;
                                    }
                                    break;
                                case 'l':
                                    if (memcmp(data + 7, u"eave", 2 * 4) == 0) {
                                        return html_names::kOndragleaveAttr;
                                    }
                                    break;
                                case 's':
                                    if (memcmp(data + 7, u"tart", 2 * 4) == 0) {
                                        return html_names::kOndragstartAttr;
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
                case 'l':
                    if (memcmp(data + 3, u"oadstart", 2 * 8) == 0) {
                        return html_names::kOnloadstartAttr;
                    }
                    break;
                case 'm':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'u':
                            switch (data[5]) {
                            case 's':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'd':
                                        if (memcmp(data + 8, u"own", 2 * 3) == 0) {
                                            return html_names::kOnmousedownAttr;
                                        }
                                        break;
                                    case 'm':
                                        if (memcmp(data + 8, u"ove", 2 * 3) == 0) {
                                            return html_names::kOnmousemoveAttr;
                                        }
                                        break;
                                    case 'o':
                                        if (memcmp(data + 8, u"ver", 2 * 3) == 0) {
                                            return html_names::kOnmouseoverAttr;
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
                    break;
                case 'p':
                    if (memcmp(data + 3, u"ointerup", 2 * 8) == 0) {
                        return html_names::kOnpointerupAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"crollend", 2 * 8) == 0) {
                        return html_names::kOnscrollendAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, u"ouchmove", 2 * 8) == 0) {
                        return html_names::kOntouchmoveAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'a':
                    switch (data[3]) {
                    case 'c':
                        if (memcmp(data + 4, u"eholder", 2 * 7) == 0) {
                            return html_names::kPlaceholderAttr;
                        }
                        break;
                    case 'y':
                        if (memcmp(data + 4, u"sinline", 2 * 7) == 0) {
                            return html_names::kPlaysinlineAttr;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"crolldelay", 2 * 10) == 0) {
                return html_names::kScrolldelayAttr;
            }
            break;
        }
        break;
    case 12:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"utocomplete", 2 * 11) == 0) {
                return html_names::kAutocompleteAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"ontrolslist", 2 * 11) == 0) {
                return html_names::kControlslistAttr;
            }
            break;
        case 'e':
            if (memcmp(data + 1, u"nterkeyhint", 2 * 11) == 0) {
                return html_names::kEnterkeyhintAttr;
            }
            break;
        case 'm':
            if (memcmp(data + 1, u"arginheight", 2 * 11) == 0) {
                return html_names::kMarginheightAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"fterprint", 2 * 9) == 0) {
                        return html_names::kOnafterprintAttr;
                    }
                    break;
                case 'b':
                    if (memcmp(data + 3, u"eforecopy", 2 * 9) == 0) {
                        return html_names::kOnbeforecopyAttr;
                    }
                    break;
                case 'h':
                    if (memcmp(data + 3, u"ashchange", 2 * 9) == 0) {
                        return html_names::kOnhashchangeAttr;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, u"oadeddata", 2 * 9) == 0) {
                        return html_names::kOnloadeddataAttr;
                    }
                    break;
                case 'm':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'u':
                            switch (data[5]) {
                            case 's':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'e':
                                        if (memcmp(data + 8, u"nter", 2 * 4) == 0) {
                                            return html_names::kOnmouseenterAttr;
                                        }
                                        break;
                                    case 'l':
                                        if (memcmp(data + 8, u"eave", 2 * 4) == 0) {
                                            return html_names::kOnmouseleaveAttr;
                                        }
                                        break;
                                    case 'w':
                                        if (memcmp(data + 8, u"heel", 2 * 4) == 0) {
                                            return html_names::kOnmousewheelAttr;
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
                    break;
                case 'o':
                    if (memcmp(data + 3, u"verscroll", 2 * 9) == 0) {
                        return html_names::kOnoverscrollAttr;
                    }
                    break;
                case 'p':
                    if (memcmp(data + 3, u"ointerout", 2 * 9) == 0) {
                        return html_names::kOnpointeroutAttr;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, u"atechange", 2 * 9) == 0) {
                        return html_names::kOnratechangeAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"lotchange", 2 * 9) == 0) {
                        return html_names::kOnslotchangeAttr;
                    }
                    break;
                case 't':
                    switch (data[3]) {
                    case 'i':
                        if (memcmp(data + 4, u"meupdate", 2 * 8) == 0) {
                            return html_names::kOntimeupdateAttr;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, u"uchstart", 2 * 8) == 0) {
                            return html_names::kOntouchstartAttr;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"rivatetoken", 2 * 11) == 0) {
                return html_names::kPrivatetokenAttr;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"crollamount", 2 * 11) == 0) {
                return html_names::kScrollamountAttr;
            }
            break;
        }
        break;
    case 13:
        switch (data[0]) {
        case 'e':
            if (memcmp(data + 1, u"lementtiming", 2 * 12) == 0) {
                return html_names::kElementtimingAttr;
            }
            break;
        case 'f':
            if (memcmp(data + 1, u"etchpriority", 2 * 12) == 0) {
                return html_names::kFetchpriorityAttr;
            }
            break;
        case 'h':
            if (memcmp(data + 1, u"reftranslate", 2 * 12) == 0) {
                return html_names::kHreftranslateAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'b':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'f':
                            switch (data[5]) {
                            case 'o':
                                switch (data[6]) {
                                case 'r':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'i':
                                            if (memcmp(data + 9, u"nput", 2 * 4) == 0) {
                                                return html_names::kOnbeforeinputAttr;
                                            }
                                            break;
                                        case 'p':
                                            switch (data[9]) {
                                            case 'a':
                                                if (memcmp(data + 10, u"ste", 2 * 3) == 0) {
                                                    return html_names::kOnbeforepasteAttr;
                                                }
                                                break;
                                            case 'r':
                                                if (memcmp(data + 10, u"int", 2 * 3) == 0) {
                                                    return html_names::kOnbeforeprintAttr;
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
                            break;
                        }
                        break;
                    }
                    break;
                case 'c':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'n':
                            switch (data[5]) {
                            case 't':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'x':
                                        switch (data[8]) {
                                        case 't':
                                            switch (data[9]) {
                                            case 'l':
                                                if (memcmp(data + 10, u"ost", 2 * 3) == 0) {
                                                    return html_names::kOncontextlostAttr;
                                                }
                                                break;
                                            case 'm':
                                                if (memcmp(data + 10, u"enu", 2 * 3) == 0) {
                                                    return html_names::kOncontextmenuAttr;
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
                            break;
                        }
                        break;
                    }
                    break;
                case 'p':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'i':
                            switch (data[5]) {
                            case 'n':
                                switch (data[6]) {
                                case 't':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'r':
                                            switch (data[9]) {
                                            case 'd':
                                                if (memcmp(data + 10, u"own", 2 * 3) == 0) {
                                                    return html_names::kOnpointerdownAttr;
                                                }
                                                break;
                                            case 'm':
                                                if (memcmp(data + 10, u"ove", 2 * 3) == 0) {
                                                    return html_names::kOnpointermoveAttr;
                                                }
                                                break;
                                            case 'o':
                                                if (memcmp(data + 10, u"ver", 2 * 3) == 0) {
                                                    return html_names::kOnpointeroverAttr;
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
                            break;
                        }
                        break;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"electstart", 2 * 10) == 0) {
                        return html_names::kOnselectstartAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, u"ouchcancel", 2 * 10) == 0) {
                        return html_names::kOntouchcancelAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"opovertarget", 2 * 12) == 0) {
                return html_names::kPopovertargetAttr;
            }
            break;
        }
        break;
    case 14:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, u"cept-charset", 2 * 12) == 0) {
                    return html_names::kAcceptCharsetAttr;
                }
                break;
            case 't':
                if (memcmp(data + 2, u"tributionsrc", 2 * 12) == 0) {
                    return html_names::kAttributionsrcAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, u"tocapitalize", 2 * 12) == 0) {
                    return html_names::kAutocapitalizeAttr;
                }
                break;
            }
            break;
        case 'b':
            if (memcmp(data + 1, u"rowsingtopics", 2 * 13) == 0) {
                return html_names::kBrowsingtopicsAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"redentialless", 2 * 13) == 0) {
                return html_names::kCredentiallessAttr;
            }
            break;
        case 'd':
            if (memcmp(data + 1, u"elegatesfocus", 2 * 13) == 0) {
                return html_names::kDelegatesfocusAttr;
            }
            break;
        case 'f':
            if (memcmp(data + 1, u"ormnovalidate", 2 * 13) == 0) {
                return html_names::kFormnovalidateAttr;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 't':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'r':
                            switch (data[5]) {
                            case 'e':
                                switch (data[6]) {
                                case 's':
                                    switch (data[7]) {
                                    case 't':
                                        switch (data[8]) {
                                        case 'a':
                                            if (memcmp(data + 9, u"ction", 2 * 5) == 0) {
                                                return html_names::kInterestactionAttr;
                                            }
                                            break;
                                        case 't':
                                            if (memcmp(data + 9, u"arget", 2 * 5) == 0) {
                                                return html_names::kInteresttargetAttr;
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
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"nimationend", 2 * 11) == 0) {
                        return html_names::kOnanimationendAttr;
                    }
                    break;
                case 'b':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'f':
                            switch (data[5]) {
                            case 'o':
                                switch (data[6]) {
                                case 'r':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 't':
                                            if (memcmp(data + 9, u"oggle", 2 * 5) == 0) {
                                                return html_names::kOnbeforetoggleAttr;
                                            }
                                            break;
                                        case 'u':
                                            if (memcmp(data + 9, u"nload", 2 * 5) == 0) {
                                                return html_names::kOnbeforeunloadAttr;
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
                        break;
                    }
                    break;
                case 'm':
                    if (memcmp(data + 3, u"essageerror", 2 * 11) == 0) {
                        return html_names::kOnmessageerrorAttr;
                    }
                    break;
                case 'p':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'i':
                            switch (data[5]) {
                            case 'n':
                                switch (data[6]) {
                                case 't':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'r':
                                            switch (data[9]) {
                                            case 'e':
                                                if (memcmp(data + 10, u"nter", 2 * 4) == 0) {
                                                    return html_names::kOnpointerenterAttr;
                                                }
                                                break;
                                            case 'l':
                                                if (memcmp(data + 10, u"eave", 2 * 4) == 0) {
                                                    return html_names::kOnpointerleaveAttr;
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
                            break;
                        }
                        break;
                    }
                    break;
                case 'v':
                    if (memcmp(data + 3, u"olumechange", 2 * 11) == 0) {
                        return html_names::kOnvolumechangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'r':
            if (memcmp(data + 1, u"eferrerpolicy", 2 * 13) == 0) {
                return html_names::kReferrerpolicyAttr;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"hadowrootmode", 2 * 13) == 0) {
                return html_names::kShadowrootmodeAttr;
            }
            break;
        }
        break;
    case 15:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"llowfullscreen", 2 * 14) == 0) {
                return html_names::kAllowfullscreenAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"ontenteditable", 2 * 14) == 0) {
                return html_names::kContenteditableAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'p':
                    if (memcmp(data + 3, u"ointercancel", 2 * 12) == 0) {
                        return html_names::kOnpointercancelAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, u"ransitionend", 2 * 12) == 0) {
                        return html_names::kOntransitionendAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"reciselocation", 2 * 14) == 0) {
                return html_names::kPreciselocationAttr;
            }
            break;
        case 'w':
            if (memcmp(data + 1, u"ebkitdirectory", 2 * 14) == 0) {
                return html_names::kWebkitdirectoryAttr;
            }
            break;
        }
        break;
    case 16:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"dauctionheaders", 2 * 15) == 0) {
                return html_names::kAdauctionheadersAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"nimationstart", 2 * 13) == 0) {
                        return html_names::kOnanimationstartAttr;
                    }
                    break;
                case 'c':
                    if (memcmp(data + 3, u"anplaythrough", 2 * 13) == 0) {
                        return html_names::kOncanplaythroughAttr;
                    }
                    break;
                case 'd':
                    if (memcmp(data + 3, u"urationchange", 2 * 13) == 0) {
                        return html_names::kOndurationchangeAttr;
                    }
                    break;
                case 'l':
                    switch (data[3]) {
                    case 'a':
                        if (memcmp(data + 4, u"nguagechange", 2 * 12) == 0) {
                            return html_names::kOnlanguagechangeAttr;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, u"adedmetadata", 2 * 12) == 0) {
                            return html_names::kOnloadedmetadataAttr;
                        }
                        break;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, u"imezonechange", 2 * 13) == 0) {
                        return html_names::kOntimezonechangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 17:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, u"ontextrestored", 2 * 14) == 0) {
                        return html_names::kOncontextrestoredAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"electionchange", 2 * 14) == 0) {
                        return html_names::kOnselectionchangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 18:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'p':
                    if (memcmp(data + 3, u"ointerrawupdate", 2 * 15) == 0) {
                        return html_names::kOnpointerrawupdateAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"crollsnapchange", 2 * 15) == 0) {
                        return html_names::kOnscrollsnapchangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"hadowrootclonable", 2 * 17) == 0) {
                return html_names::kShadowrootclonableAttr;
            }
            break;
        case 'w':
            if (memcmp(data + 1, u"ritingsuggestions", 2 * 17) == 0) {
                return html_names::kWritingsuggestionsAttr;
            }
            break;
        }
        break;
    case 19:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"llowpaymentrequest", 2 * 18) == 0) {
                return html_names::kAllowpaymentrequestAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'g':
                    if (memcmp(data + 3, u"otpointercapture", 2 * 16) == 0) {
                        return html_names::kOngotpointercaptureAttr;
                    }
                    break;
                case 'o':
                    if (memcmp(data + 3, u"rientationchange", 2 * 16) == 0) {
                        return html_names::kOnorientationchangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"opovertargetaction", 2 * 18) == 0) {
                return html_names::kPopovertargetactionAttr;
            }
            break;
        }
        break;
    case 20:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"nimationiteration", 2 * 17) == 0) {
                        return html_names::kOnanimationiterationAttr;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, u"ostpointercapture", 2 * 17) == 0) {
                        return html_names::kOnlostpointercaptureAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"crollsnapchanging", 2 * 17) == 0) {
                        return html_names::kOnscrollsnapchangingAttr;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, u"ebkitanimationend", 2 * 17) == 0) {
                        return html_names::kOnwebkitanimationendAttr;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 21:
        switch (data[0]) {
        case 'd':
            if (memcmp(data + 1, u"isableremoteplayback", 2 * 20) == 0) {
                return html_names::kDisableremoteplaybackAttr;
            }
            break;
        case 'o':
            if (memcmp(data + 1, u"nwebkittransitionend", 2 * 20) == 0) {
                return html_names::kOnwebkittransitionendAttr;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"haredstoragewritable", 2 * 20) == 0) {
                return html_names::kSharedstoragewritableAttr;
            }
            break;
        case 'v':
            if (memcmp(data + 1, u"irtualkeyboardpolicy", 2 * 20) == 0) {
                return html_names::kVirtualkeyboardpolicyAttr;
            }
            break;
        }
        break;
    case 22:
        switch (data[0]) {
        case 'o':
            if (memcmp(data + 1, u"nwebkitanimationstart", 2 * 21) == 0) {
                return html_names::kOnwebkitanimationstartAttr;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, u"lectedcontentelement", 2 * 20) == 0) {
                    return html_names::kSelectedcontentelementAttr;
                }
                break;
            case 'h':
                if (memcmp(data + 2, u"adowrootserializable", 2 * 20) == 0) {
                    return html_names::kShadowrootserializableAttr;
                }
                break;
            }
            break;
        }
        break;
    case 23:
        switch (data[0]) {
        case 'd':
            if (memcmp(data + 1, u"isablepictureinpicture", 2 * 22) == 0) {
                return html_names::kDisablepictureinpictureAttr;
            }
            break;
        case 'o':
            if (memcmp(data + 1, u"nwebkitfullscreenerror", 2 * 22) == 0) {
                return html_names::kOnwebkitfullscreenerrorAttr;
            }
            break;
        }
        break;
    case 24:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'v':
                    if (memcmp(data + 3, u"alidationstatuschange", 2 * 21) == 0) {
                        return html_names::kOnvalidationstatuschangeAttr;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, u"ebkitfullscreenchange", 2 * 21) == 0) {
                        return html_names::kOnwebkitfullscreenchangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"hadowrootdelegatesfocus", 2 * 23) == 0) {
                return html_names::kShadowrootdelegatesfocusAttr;
            }
            break;
        }
        break;
    case 25:
        switch (data[0]) {
        case 'o':
            if (memcmp(data + 1, u"nsecuritypolicyviolation", 2 * 24) == 0) {
                return html_names::kOnsecuritypolicyviolationAttr;
            }
            break;
        case 's':
            if (memcmp(data + 1, u"hadowrootreferencetarget", 2 * 24) == 0) {
                return html_names::kShadowrootreferencetargetAttr;
            }
            break;
        }
        break;
    case 26:
        switch (data[0]) {
        case 'o':
            if (memcmp(data + 1, u"nwebkitanimationiteration", 2 * 25) == 0) {
                return html_names::kOnwebkitanimationiterationAttr;
            }
            break;
        }
        break;
    case 34:
        switch (data[0]) {
        case 'o':
            if (memcmp(data + 1, u"ncontentvisibilityautostatechange", 2 * 33) == 0) {
                return html_names::kOncontentvisibilityautostatechangeAttr;
            }
            break;
        }
        break;
    }

    return g_null_name;
}

const QualifiedName& LookupHTMLAttributeName(const LChar* data, unsigned length)
{
    DCHECK(data);
    DCHECK(length);
    switch (length) {
    case 2:
        switch (data[0]) {
        case 'a':
            if (data[1] == 's') {
                return html_names::kAsAttr;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'd':
                return html_names::kIdAttr;
            case 's':
                return html_names::kIsAttr;
            }
            break;
        }
        break;
    case 3:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "lt", 2) == 0) {
                return html_names::kAltAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "sp", 2) == 0) {
                return html_names::kCspAttr;
            }
            break;
        case 'd':
            if (memcmp(data + 1, "ir", 2) == 0) {
                return html_names::kDirAttr;
            }
            break;
        case 'e':
            if (memcmp(data + 1, "nd", 2) == 0) {
                return html_names::kEndAttr;
            }
            break;
        case 'f':
            if (memcmp(data + 1, "or", 2) == 0) {
                return html_names::kForAttr;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "ow", 2) == 0) {
                return html_names::kLowAttr;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'x') {
                    return html_names::kMaxAttr;
                }
                break;
            case 'i':
                if (data[2] == 'n') {
                    return html_names::kMinAttr;
                }
                break;
            }
            break;
        case 'r':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'l':
                    return html_names::kRelAttr;
                case 'v':
                    return html_names::kRevAttr;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, "rc", 2) == 0) {
                return html_names::kSrcAttr;
            }
            break;
        }
        break;
    case 4:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'b':
                if (memcmp(data + 2, "br", 2) == 0) {
                    return html_names::kAbbrAttr;
                }
                break;
            case 'x':
                if (memcmp(data + 2, "is", 2) == 0) {
                    return html_names::kAxisAttr;
                }
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'h':
                if (memcmp(data + 2, "ar", 2) == 0) {
                    return html_names::kCharAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, "te", 2) == 0) {
                    return html_names::kCiteAttr;
                }
                break;
            case 'o':
                switch (data[2]) {
                case 'd':
                    if (data[3] == 'e') {
                        return html_names::kCodeAttr;
                    }
                    break;
                case 'l':
                    if (data[3] == 's') {
                        return html_names::kColsAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, "ata", 3) == 0) {
                return html_names::kDataAttr;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "ce", 2) == 0) {
                    return html_names::kFaceAttr;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "rm", 2) == 0) {
                    return html_names::kFormAttr;
                }
                break;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, "gh", 2) == 0) {
                    return html_names::kHighAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "ef", 2) == 0) {
                    return html_names::kHrefAttr;
                }
                break;
            }
            break;
        case 'k':
            if (memcmp(data + 1, "ind", 3) == 0) {
                return html_names::kKindAttr;
            }
            break;
        case 'l':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "ng", 2) == 0) {
                    return html_names::kLangAttr;
                }
                break;
            case 'i':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 'k') {
                        return html_names::kLinkAttr;
                    }
                    break;
                case 's':
                    if (data[3] == 't') {
                        return html_names::kListAttr;
                    }
                    break;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "op", 2) == 0) {
                    return html_names::kLoopAttr;
                }
                break;
            }
            break;
        case 'n':
            if (memcmp(data + 1, "ame", 3) == 0) {
                return html_names::kNameAttr;
            }
            break;
        case 'o':
            if (memcmp(data + 1, "pen", 3) == 0) {
                return html_names::kOpenAttr;
            }
            break;
        case 'p':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "rt", 2) == 0) {
                    return html_names::kPartAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, "ng", 2) == 0) {
                    return html_names::kPingAttr;
                }
                break;
            }
            break;
        case 'r':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'l':
                    if (data[3] == 'e') {
                        return html_names::kRoleAttr;
                    }
                    break;
                case 'w':
                    if (data[3] == 's') {
                        return html_names::kRowsAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, "ze", 2) == 0) {
                    return html_names::kSizeAttr;
                }
                break;
            case 'l':
                if (memcmp(data + 2, "ot", 2) == 0) {
                    return html_names::kSlotAttr;
                }
                break;
            case 'p':
                if (memcmp(data + 2, "an", 2) == 0) {
                    return html_names::kSpanAttr;
                }
                break;
            case 't':
                if (memcmp(data + 2, "ep", 2) == 0) {
                    return html_names::kStepAttr;
                }
                break;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, "xt", 2) == 0) {
                    return html_names::kTextAttr;
                }
                break;
            case 'y':
                if (memcmp(data + 2, "pe", 2) == 0) {
                    return html_names::kTypeAttr;
                }
                break;
            }
            break;
        case 'w':
            if (memcmp(data + 1, "rap", 3) == 0) {
                return html_names::kWrapAttr;
            }
            break;
        }
        break;
    case 5:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'i':
                    switch (data[3]) {
                    case 'g':
                        if (data[4] == 'n') {
                            return html_names::kAlignAttr;
                        }
                        break;
                    case 'n':
                        if (data[4] == 'k') {
                            return html_names::kAlinkAttr;
                        }
                        break;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, "ow", 2) == 0) {
                        return html_names::kAllowAttr;
                    }
                    break;
                }
                break;
            case 's':
                if (memcmp(data + 2, "ync", 3) == 0) {
                    return html_names::kAsyncAttr;
                }
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "ss", 2) == 0) {
                        return html_names::kClassAttr;
                    }
                    break;
                case 'e':
                    if (memcmp(data + 3, "ar", 2) == 0) {
                        return html_names::kClearAttr;
                    }
                    break;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "lor", 3) == 0) {
                    return html_names::kColorAttr;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, "efer", 4) == 0) {
                return html_names::kDeferAttr;
            }
            break;
        case 'e':
            if (memcmp(data + 1, "vent", 4) == 0) {
                return html_names::kEventAttr;
            }
            break;
        case 'f':
            if (memcmp(data + 1, "rame", 4) == 0) {
                return html_names::kFrameAttr;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'n':
                if (memcmp(data + 2, "ert", 3) == 0) {
                    return html_names::kInertAttr;
                }
                break;
            case 's':
                if (memcmp(data + 2, "map", 3) == 0) {
                    return html_names::kIsmapAttr;
                }
                break;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "abel", 4) == 0) {
                return html_names::kLabelAttr;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, "dia", 3) == 0) {
                    return html_names::kMediaAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, "ted", 3) == 0) {
                    return html_names::kMutedAttr;
                }
                break;
            }
            break;
        case 'n':
            if (memcmp(data + 1, "once", 4) == 0) {
                return html_names::kNonceAttr;
            }
            break;
        case 'o':
            if (memcmp(data + 1, "ncut", 4) == 0) {
                return html_names::kOncutAttr;
            }
            break;
        case 'r':
            if (memcmp(data + 1, "ules", 4) == 0) {
                return html_names::kRulesAttr;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, "ope", 3) == 0) {
                    return html_names::kScopeAttr;
                }
                break;
            case 'h':
                if (memcmp(data + 2, "ape", 3) == 0) {
                    return html_names::kShapeAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, "zes", 3) == 0) {
                    return html_names::kSizesAttr;
                }
                break;
            case 't':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "rt", 2) == 0) {
                        return html_names::kStartAttr;
                    }
                    break;
                case 'y':
                    if (memcmp(data + 3, "le", 2) == 0) {
                        return html_names::kStyleAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 't':
            if (memcmp(data + 1, "itle", 4) == 0) {
                return html_names::kTitleAttr;
            }
            break;
        case 'v':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "lue", 3) == 0) {
                    return html_names::kValueAttr;
                }
                break;
            case 'l':
                if (memcmp(data + 2, "ink", 3) == 0) {
                    return html_names::kVlinkAttr;
                }
                break;
            }
            break;
        case 'w':
            if (memcmp(data + 1, "idth", 4) == 0) {
                return html_names::kWidthAttr;
            }
            break;
        }
        break;
    case 6:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, "ept", 3) == 0) {
                        return html_names::kAcceptAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, "ion", 3) == 0) {
                        return html_names::kActionAttr;
                    }
                    break;
                }
                break;
            case 'n':
                if (memcmp(data + 2, "chor", 4) == 0) {
                    return html_names::kAnchorAttr;
                }
                break;
            }
            break;
        case 'b':
            if (memcmp(data + 1, "order", 5) == 0) {
                return html_names::kBorderAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "oords", 5) == 0) {
                return html_names::kCoordsAttr;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, "ight", 4) == 0) {
                    return html_names::kHeightAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, "dden", 4) == 0) {
                    return html_names::kHiddenAttr;
                }
                break;
            case 's':
                if (memcmp(data + 2, "pace", 4) == 0) {
                    return html_names::kHspaceAttr;
                }
                break;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "owsrc", 5) == 0) {
                return html_names::kLowsrcAttr;
            }
            break;
        case 'm':
            if (memcmp(data + 1, "ethod", 5) == 0) {
                return html_names::kMethodAttr;
            }
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'h':
                    if (memcmp(data + 3, "ref", 3) == 0) {
                        return html_names::kNohrefAttr;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, "rap", 3) == 0) {
                        return html_names::kNowrapAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'b':
                if (memcmp(data + 2, "ject", 4) == 0) {
                    return html_names::kObjectAttr;
                }
                break;
            case 'n':
                switch (data[2]) {
                case 'b':
                    if (memcmp(data + 3, "lur", 3) == 0) {
                        return html_names::kOnblurAttr;
                    }
                    break;
                case 'c':
                    if (memcmp(data + 3, "opy", 3) == 0) {
                        return html_names::kOncopyAttr;
                    }
                    break;
                case 'd':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'a':
                            if (data[5] == 'g') {
                                return html_names::kOndragAttr;
                            }
                            break;
                        case 'o':
                            if (data[5] == 'p') {
                                return html_names::kOndropAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, "oad", 3) == 0) {
                        return html_names::kOnloadAttr;
                    }
                    break;
                case 'm':
                    if (memcmp(data + 3, "ove", 3) == 0) {
                        return html_names::kOnmoveAttr;
                    }
                    break;
                case 'p':
                    if (memcmp(data + 3, "lay", 3) == 0) {
                        return html_names::kOnplayAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "how", 3) == 0) {
                        return html_names::kOnshowAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'l':
                    if (memcmp(data + 3, "icy", 3) == 0) {
                        return html_names::kPolicyAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "ter", 3) == 0) {
                        return html_names::kPosterAttr;
                    }
                    break;
                }
                break;
            case 's':
                if (memcmp(data + 2, "eudo", 4) == 0) {
                    return html_names::kPseudoAttr;
                }
                break;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, "heme", 4) == 0) {
                    return html_names::kSchemeAttr;
                }
                break;
            case 'e':
                if (memcmp(data + 2, "lect", 4) == 0) {
                    return html_names::kSelectAttr;
                }
                break;
            case 'r':
                switch (data[2]) {
                case 'c':
                    switch (data[3]) {
                    case 'd':
                        if (memcmp(data + 4, "oc", 2) == 0) {
                            return html_names::kSrcdocAttr;
                        }
                        break;
                    case 's':
                        if (memcmp(data + 4, "et", 2) == 0) {
                            return html_names::kSrcsetAttr;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 't':
            if (memcmp(data + 1, "arget", 5) == 0) {
                return html_names::kTargetAttr;
            }
            break;
        case 'u':
            if (memcmp(data + 1, "semap", 5) == 0) {
                return html_names::kUsemapAttr;
            }
            break;
        case 'v':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "lign", 4) == 0) {
                    return html_names::kValignAttr;
                }
                break;
            case 's':
                if (memcmp(data + 2, "pace", 4) == 0) {
                    return html_names::kVspaceAttr;
                }
                break;
            }
            break;
        }
        break;
    case 7:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "rchive", 6) == 0) {
                return html_names::kArchiveAttr;
            }
            break;
        case 'b':
            if (memcmp(data + 1, "gcolor", 6) == 0) {
                return html_names::kBgcolorAttr;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "pture", 5) == 0) {
                    return html_names::kCaptureAttr;
                }
                break;
            case 'h':
                switch (data[2]) {
                case 'a':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'o':
                            if (memcmp(data + 5, "ff", 2) == 0) {
                                return html_names::kCharoffAttr;
                            }
                            break;
                        case 's':
                            if (memcmp(data + 5, "et", 2) == 0) {
                                return html_names::kCharsetAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'e':
                    if (memcmp(data + 3, "cked", 4) == 0) {
                        return html_names::kCheckedAttr;
                    }
                    break;
                }
                break;
            case 'l':
                if (memcmp(data + 2, "assid", 5) == 0) {
                    return html_names::kClassidAttr;
                }
                break;
            case 'o':
                switch (data[2]) {
                case 'l':
                    if (memcmp(data + 3, "span", 4) == 0) {
                        return html_names::kColspanAttr;
                    }
                    break;
                case 'm':
                    switch (data[3]) {
                    case 'm':
                        if (memcmp(data + 4, "and", 3) == 0) {
                            return html_names::kCommandAttr;
                        }
                        break;
                    case 'p':
                        if (memcmp(data + 4, "act", 3) == 0) {
                            return html_names::kCompactAttr;
                        }
                        break;
                    }
                    break;
                case 'n':
                    if (memcmp(data + 3, "tent", 4) == 0) {
                        return html_names::kContentAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, "lare", 4) == 0) {
                        return html_names::kDeclareAttr;
                    }
                    break;
                case 'f':
                    if (memcmp(data + 3, "ault", 4) == 0) {
                        return html_names::kDefaultAttr;
                    }
                    break;
                }
                break;
            case 'i':
                if (memcmp(data + 2, "rname", 5) == 0) {
                    return html_names::kDirnameAttr;
                }
                break;
            }
            break;
        case 'e':
            if (memcmp(data + 1, "nctype", 6) == 0) {
                return html_names::kEnctypeAttr;
            }
            break;
        case 'h':
            if (memcmp(data + 1, "eaders", 6) == 0) {
                return html_names::kHeadersAttr;
            }
            break;
        case 'k':
            if (memcmp(data + 1, "eytype", 6) == 0) {
                return html_names::kKeytypeAttr;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "oading", 6) == 0) {
                return html_names::kLoadingAttr;
            }
            break;
        case 'n':
            if (memcmp(data + 1, "oshade", 6) == 0) {
                return html_names::kNoshadeAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "bort", 4) == 0) {
                        return html_names::kOnabortAttr;
                    }
                    break;
                case 'c':
                    switch (data[3]) {
                    case 'l':
                        switch (data[4]) {
                        case 'i':
                            if (memcmp(data + 5, "ck", 2) == 0) {
                                return html_names::kOnclickAttr;
                            }
                            break;
                        case 'o':
                            if (memcmp(data + 5, "se", 2) == 0) {
                                return html_names::kOncloseAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'e':
                    switch (data[3]) {
                    case 'n':
                        if (memcmp(data + 4, "ded", 3) == 0) {
                            return html_names::kOnendedAttr;
                        }
                        break;
                    case 'r':
                        if (memcmp(data + 4, "ror", 3) == 0) {
                            return html_names::kOnerrorAttr;
                        }
                        break;
                    }
                    break;
                case 'f':
                    if (memcmp(data + 3, "ocus", 4) == 0) {
                        return html_names::kOnfocusAttr;
                    }
                    break;
                case 'i':
                    if (memcmp(data + 3, "nput", 4) == 0) {
                        return html_names::kOninputAttr;
                    }
                    break;
                case 'k':
                    if (memcmp(data + 3, "eyup", 4) == 0) {
                        return html_names::kOnkeyupAttr;
                    }
                    break;
                case 'p':
                    switch (data[3]) {
                    case 'a':
                        switch (data[4]) {
                        case 's':
                            if (memcmp(data + 5, "te", 2) == 0) {
                                return html_names::kOnpasteAttr;
                            }
                            break;
                        case 'u':
                            if (memcmp(data + 5, "se", 2) == 0) {
                                return html_names::kOnpauseAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, "eset", 4) == 0) {
                        return html_names::kOnresetAttr;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, "heel", 4) == 0) {
                        return html_names::kOnwheelAttr;
                    }
                    break;
                }
                break;
            case 'p':
                if (memcmp(data + 2, "timum", 5) == 0) {
                    return html_names::kOptimumAttr;
                }
                break;
            }
            break;
        case 'p':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "ttern", 5) == 0) {
                    return html_names::kPatternAttr;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "pover", 5) == 0) {
                    return html_names::kPopoverAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "eload", 5) == 0) {
                    return html_names::kPreloadAttr;
                }
                break;
            }
            break;
        case 'r':
            if (memcmp(data + 1, "owspan", 6) == 0) {
                return html_names::kRowspanAttr;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "ndbox", 5) == 0) {
                    return html_names::kSandboxAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "clang", 5) == 0) {
                    return html_names::kSrclangAttr;
                }
                break;
            case 't':
                if (memcmp(data + 2, "andby", 5) == 0) {
                    return html_names::kStandbyAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, "mmary", 5) == 0) {
                    return html_names::kSummaryAttr;
                }
                break;
            }
            break;
        case 'v':
            if (memcmp(data + 1, "ersion", 6) == 0) {
                return html_names::kVersionAttr;
            }
            break;
        }
        break;
    case 8:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "utoplay", 7) == 0) {
                return html_names::kAutoplayAttr;
            }
            break;
        case 'b':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, "havior", 6) == 0) {
                    return html_names::kBehaviorAttr;
                }
                break;
            case 'l':
                if (memcmp(data + 2, "ocking", 6) == 0) {
                    return html_names::kBlockingAttr;
                }
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'l':
                if (memcmp(data + 2, "osedby", 6) == 0) {
                    return html_names::kClosedbyAttr;
                }
                break;
            case 'o':
                switch (data[2]) {
                case 'd':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'b':
                            if (memcmp(data + 5, "ase", 3) == 0) {
                                return html_names::kCodebaseAttr;
                            }
                            break;
                        case 't':
                            if (memcmp(data + 5, "ype", 3) == 0) {
                                return html_names::kCodetypeAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'n':
                    if (memcmp(data + 3, "trols", 5) == 0) {
                        return html_names::kControlsAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 't':
                    switch (data[3]) {
                    case 'a':
                        if (memcmp(data + 4, "-src", 4) == 0) {
                            return html_names::kDataSrcAttr;
                        }
                        break;
                    case 'e':
                        if (memcmp(data + 4, "time", 4) == 0) {
                            return html_names::kDatetimeAttr;
                        }
                        break;
                    }
                    break;
                }
                break;
            case 'e':
                if (memcmp(data + 2, "coding", 6) == 0) {
                    return html_names::kDecodingAttr;
                }
                break;
            case 'i':
                if (memcmp(data + 2, "sabled", 6) == 0) {
                    return html_names::kDisabledAttr;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "wnload", 6) == 0) {
                    return html_names::kDownloadAttr;
                }
                break;
            }
            break;
        case 'h':
            if (memcmp(data + 1, "reflang", 7) == 0) {
                return html_names::kHreflangAttr;
            }
            break;
        case 'i':
            if (memcmp(data + 1, "temprop", 7) == 0) {
                return html_names::kItempropAttr;
            }
            break;
        case 'l':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "nguage", 6) == 0) {
                    return html_names::kLanguageAttr;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "ngdesc", 6) == 0) {
                    return html_names::kLongdescAttr;
                }
                break;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "nifest", 6) == 0) {
                    return html_names::kManifestAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, "ltiple", 6) == 0) {
                    return html_names::kMultipleAttr;
                }
                break;
            }
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'm':
                    if (memcmp(data + 3, "odule", 5) == 0) {
                        return html_names::kNomoduleAttr;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, "esize", 5) == 0) {
                        return html_names::kNoresizeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    switch (data[3]) {
                    case 'a':
                        if (memcmp(data + 4, "ncel", 4) == 0) {
                            return html_names::kOncancelAttr;
                        }
                        break;
                    case 'h':
                        if (memcmp(data + 4, "ange", 4) == 0) {
                            return html_names::kOnchangeAttr;
                        }
                        break;
                    }
                    break;
                case 'o':
                    if (memcmp(data + 3, "nline", 5) == 0) {
                        return html_names::kOnonlineAttr;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, "esize", 5) == 0) {
                        return html_names::kOnresizeAttr;
                    }
                    break;
                case 's':
                    switch (data[3]) {
                    case 'c':
                        if (memcmp(data + 4, "roll", 4) == 0) {
                            return html_names::kOnscrollAttr;
                        }
                        break;
                    case 'e':
                        switch (data[4]) {
                        case 'a':
                            if (memcmp(data + 5, "rch", 3) == 0) {
                                return html_names::kOnsearchAttr;
                            }
                            break;
                        case 'e':
                            if (memcmp(data + 5, "ked", 3) == 0) {
                                return html_names::kOnseekedAttr;
                            }
                            break;
                        case 'l':
                            if (memcmp(data + 5, "ect", 3) == 0) {
                                return html_names::kOnselectAttr;
                            }
                            break;
                        }
                        break;
                    case 'u':
                        if (memcmp(data + 4, "bmit", 4) == 0) {
                            return html_names::kOnsubmitAttr;
                        }
                        break;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, "oggle", 5) == 0) {
                        return html_names::kOntoggleAttr;
                    }
                    break;
                case 'u':
                    if (memcmp(data + 3, "nload", 5) == 0) {
                        return html_names::kOnunloadAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "roperty", 7) == 0) {
                return html_names::kPropertyAttr;
            }
            break;
        case 'r':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "donly", 5) == 0) {
                        return html_names::kReadonlyAttr;
                    }
                    break;
                case 'q':
                    if (memcmp(data + 3, "uired", 5) == 0) {
                        return html_names::kRequiredAttr;
                    }
                    break;
                case 'v':
                    if (memcmp(data + 3, "ersed", 5) == 0) {
                        return html_names::kReversedAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, "elected", 7) == 0) {
                return html_names::kSelectedAttr;
            }
            break;
        case 't':
            if (memcmp(data + 1, "abindex", 7) == 0) {
                return html_names::kTabindexAttr;
            }
            break;
        }
        break;
    case 9:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, "cesskey", 7) == 0) {
                    return html_names::kAccesskeyAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, "tofocus", 7) == 0) {
                    return html_names::kAutofocusAttr;
                }
                break;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "hallenge", 8) == 0) {
                return html_names::kChallengeAttr;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, "rection", 7) == 0) {
                    return html_names::kDirectionAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "aggable", 7) == 0) {
                    return html_names::kDraggableAttr;
                }
                break;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'p':
                    if (memcmp(data + 3, "utmode", 6) == 0) {
                        return html_names::kInputmodeAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, "egrity", 6) == 0) {
                        return html_names::kIntegrityAttr;
                    }
                    break;
                case 'v':
                    if (memcmp(data + 3, "isible", 6) == 0) {
                        return html_names::kInvisibleAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'x':
                    if (memcmp(data + 3, "length", 6) == 0) {
                        return html_names::kMaxlengthAttr;
                    }
                    break;
                case 'y':
                    if (memcmp(data + 3, "script", 6) == 0) {
                        return html_names::kMayscriptAttr;
                    }
                    break;
                }
                break;
            case 'i':
                if (memcmp(data + 2, "nlength", 7) == 0) {
                    return html_names::kMinlengthAttr;
                }
                break;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, "anplay", 6) == 0) {
                        return html_names::kOncanplayAttr;
                    }
                    break;
                case 'd':
                    switch (data[3]) {
                    case 'i':
                        if (memcmp(data + 4, "smiss", 5) == 0) {
                            return html_names::kOndismissAttr;
                        }
                        break;
                    case 'r':
                        if (memcmp(data + 4, "agend", 5) == 0) {
                            return html_names::kOndragendAttr;
                        }
                        break;
                    }
                    break;
                case 'e':
                    if (memcmp(data + 3, "mptied", 6) == 0) {
                        return html_names::kOnemptiedAttr;
                    }
                    break;
                case 'f':
                    if (memcmp(data + 3, "ocusin", 6) == 0) {
                        return html_names::kOnfocusinAttr;
                    }
                    break;
                case 'i':
                    if (memcmp(data + 3, "nvalid", 6) == 0) {
                        return html_names::kOninvalidAttr;
                    }
                    break;
                case 'k':
                    if (memcmp(data + 3, "eydown", 6) == 0) {
                        return html_names::kOnkeydownAttr;
                    }
                    break;
                case 'm':
                    switch (data[3]) {
                    case 'e':
                        if (memcmp(data + 4, "ssage", 5) == 0) {
                            return html_names::kOnmessageAttr;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, "useup", 5) == 0) {
                            return html_names::kOnmouseupAttr;
                        }
                        break;
                    }
                    break;
                case 'o':
                    if (memcmp(data + 3, "ffline", 6) == 0) {
                        return html_names::kOnofflineAttr;
                    }
                    break;
                case 'p':
                    if (memcmp(data + 3, "laying", 6) == 0) {
                        return html_names::kOnplayingAttr;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, "esolve", 6) == 0) {
                        return html_names::kOnresolveAttr;
                    }
                    break;
                case 's':
                    switch (data[3]) {
                    case 'e':
                        if (memcmp(data + 4, "eking", 5) == 0) {
                            return html_names::kOnseekingAttr;
                        }
                        break;
                    case 't':
                        switch (data[4]) {
                        case 'a':
                            if (memcmp(data + 5, "lled", 4) == 0) {
                                return html_names::kOnstalledAttr;
                            }
                            break;
                        case 'o':
                            if (memcmp(data + 5, "rage", 4) == 0) {
                                return html_names::kOnstorageAttr;
                            }
                            break;
                        }
                        break;
                    case 'u':
                        if (memcmp(data + 4, "spend", 5) == 0) {
                            return html_names::kOnsuspendAttr;
                        }
                        break;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, "aiting", 6) == 0) {
                        return html_names::kOnwaitingAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, "crolling", 8) == 0) {
                return html_names::kScrollingAttr;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'o':
                if (memcmp(data + 2, "pmargin", 7) == 0) {
                    return html_names::kTopmarginAttr;
                }
                break;
            case 'r':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "nslate", 6) == 0) {
                        return html_names::kTranslateAttr;
                    }
                    break;
                case 'u':
                    if (memcmp(data + 3, "espeed", 6) == 0) {
                        return html_names::kTruespeedAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'v':
            if (memcmp(data + 1, "aluetype", 8) == 0) {
                return html_names::kValuetypeAttr;
            }
            break;
        }
        break;
    case 10:
        switch (data[0]) {
        case 'b':
            if (memcmp(data + 1, "ackground", 9) == 0) {
                return html_names::kBackgroundAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "ommandfor", 9) == 0) {
                return html_names::kCommandforAttr;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, "usgroup", 7) == 0) {
                        return html_names::kFocusgroupAttr;
                    }
                    break;
                case 'r':
                    switch (data[3]) {
                    case 'm':
                        switch (data[4]) {
                        case 'a':
                            if (memcmp(data + 5, "ction", 5) == 0) {
                                return html_names::kFormactionAttr;
                            }
                            break;
                        case 'm':
                            if (memcmp(data + 5, "ethod", 5) == 0) {
                                return html_names::kFormmethodAttr;
                            }
                            break;
                        case 't':
                            if (memcmp(data + 5, "arget", 5) == 0) {
                                return html_names::kFormtargetAttr;
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
        case 'h':
            if (memcmp(data + 1, "ttp-equiv", 9) == 0) {
                return html_names::kHttpEquivAttr;
            }
            break;
        case 'i':
            if (memcmp(data + 1, "magesizes", 9) == 0) {
                return html_names::kImagesizesAttr;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "eftmargin", 9) == 0) {
                return html_names::kLeftmarginAttr;
            }
            break;
        case 'n':
            if (memcmp(data + 1, "ovalidate", 9) == 0) {
                return html_names::kNovalidateAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "uxclick", 7) == 0) {
                        return html_names::kOnauxclickAttr;
                    }
                    break;
                case 'd':
                    switch (data[3]) {
                    case 'b':
                        if (memcmp(data + 4, "lclick", 6) == 0) {
                            return html_names::kOndblclickAttr;
                        }
                        break;
                    case 'r':
                        if (memcmp(data + 4, "agover", 6) == 0) {
                            return html_names::kOndragoverAttr;
                        }
                        break;
                    }
                    break;
                case 'f':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'c':
                            if (memcmp(data + 5, "usout", 5) == 0) {
                                return html_names::kOnfocusoutAttr;
                            }
                            break;
                        case 'r':
                            if (memcmp(data + 5, "mdata", 5) == 0) {
                                return html_names::kOnformdataAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                case 'k':
                    if (memcmp(data + 3, "eypress", 7) == 0) {
                        return html_names::kOnkeypressAttr;
                    }
                    break;
                case 'm':
                    if (memcmp(data + 3, "ouseout", 7) == 0) {
                        return html_names::kOnmouseoutAttr;
                    }
                    break;
                case 'p':
                    switch (data[3]) {
                    case 'a':
                        switch (data[4]) {
                        case 'g':
                            switch (data[5]) {
                            case 'e':
                                switch (data[6]) {
                                case 'h':
                                    if (memcmp(data + 7, "ide", 3) == 0) {
                                        return html_names::kOnpagehideAttr;
                                    }
                                    break;
                                case 's':
                                    if (memcmp(data + 7, "how", 3) == 0) {
                                        return html_names::kOnpageshowAttr;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, "pstate", 6) == 0) {
                            return html_names::kOnpopstateAttr;
                        }
                        break;
                    case 'r':
                        if (memcmp(data + 4, "ogress", 6) == 0) {
                            return html_names::kOnprogressAttr;
                        }
                        break;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, "ouchend", 7) == 0) {
                        return html_names::kOntouchendAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "arseparts", 9) == 0) {
                return html_names::kParsepartsAttr;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'h':
                if (memcmp(data + 2, "adowroot", 8) == 0) {
                    return html_names::kShadowrootAttr;
                }
                break;
            case 'p':
                if (memcmp(data + 2, "ellcheck", 8) == 0) {
                    return html_names::kSpellcheckAttr;
                }
                break;
            }
            break;
        }
        break;
    case 11:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "utocorrect", 10) == 0) {
                return html_names::kAutocorrectAttr;
            }
            break;
        case 'b':
            if (memcmp(data + 1, "ordercolor", 10) == 0) {
                return html_names::kBordercolorAttr;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'l':
                    switch (data[3]) {
                    case 'l':
                        switch (data[4]) {
                        case 'p':
                            if (memcmp(data + 5, "adding", 6) == 0) {
                                return html_names::kCellpaddingAttr;
                            }
                            break;
                        case 's':
                            if (memcmp(data + 5, "pacing", 6) == 0) {
                                return html_names::kCellspacingAttr;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "ossorigin", 9) == 0) {
                    return html_names::kCrossoriginAttr;
                }
                break;
            }
            break;
        case 'e':
            if (memcmp(data + 1, "xportparts", 10) == 0) {
                return html_names::kExportpartsAttr;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'o':
                if (memcmp(data + 2, "rmenctype", 9) == 0) {
                    return html_names::kFormenctypeAttr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "ameborder", 9) == 0) {
                    return html_names::kFrameborderAttr;
                }
                break;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'm':
                if (memcmp(data + 2, "agesrcset", 9) == 0) {
                    return html_names::kImagesrcsetAttr;
                }
                break;
            case 'n':
                if (memcmp(data + 2, "cremental", 9) == 0) {
                    return html_names::kIncrementalAttr;
                }
                break;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "atencyhint", 10) == 0) {
                return html_names::kLatencyhintAttr;
            }
            break;
        case 'm':
            if (memcmp(data + 1, "arginwidth", 10) == 0) {
                return html_names::kMarginwidthAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'b':
                    if (memcmp(data + 3, "eforecut", 8) == 0) {
                        return html_names::kOnbeforecutAttr;
                    }
                    break;
                case 'c':
                    if (memcmp(data + 3, "uechange", 8) == 0) {
                        return html_names::kOncuechangeAttr;
                    }
                    break;
                case 'd':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'a':
                            switch (data[5]) {
                            case 'g':
                                switch (data[6]) {
                                case 'e':
                                    if (memcmp(data + 7, "nter", 4) == 0) {
                                        return html_names::kOndragenterAttr;
                                    }
                                    break;
                                case 'l':
                                    if (memcmp(data + 7, "eave", 4) == 0) {
                                        return html_names::kOndragleaveAttr;
                                    }
                                    break;
                                case 's':
                                    if (memcmp(data + 7, "tart", 4) == 0) {
                                        return html_names::kOndragstartAttr;
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
                case 'l':
                    if (memcmp(data + 3, "oadstart", 8) == 0) {
                        return html_names::kOnloadstartAttr;
                    }
                    break;
                case 'm':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'u':
                            switch (data[5]) {
                            case 's':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'd':
                                        if (memcmp(data + 8, "own", 3) == 0) {
                                            return html_names::kOnmousedownAttr;
                                        }
                                        break;
                                    case 'm':
                                        if (memcmp(data + 8, "ove", 3) == 0) {
                                            return html_names::kOnmousemoveAttr;
                                        }
                                        break;
                                    case 'o':
                                        if (memcmp(data + 8, "ver", 3) == 0) {
                                            return html_names::kOnmouseoverAttr;
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
                    break;
                case 'p':
                    if (memcmp(data + 3, "ointerup", 8) == 0) {
                        return html_names::kOnpointerupAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "crollend", 8) == 0) {
                        return html_names::kOnscrollendAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, "ouchmove", 8) == 0) {
                        return html_names::kOntouchmoveAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'a':
                    switch (data[3]) {
                    case 'c':
                        if (memcmp(data + 4, "eholder", 7) == 0) {
                            return html_names::kPlaceholderAttr;
                        }
                        break;
                    case 'y':
                        if (memcmp(data + 4, "sinline", 7) == 0) {
                            return html_names::kPlaysinlineAttr;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, "crolldelay", 10) == 0) {
                return html_names::kScrolldelayAttr;
            }
            break;
        }
        break;
    case 12:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "utocomplete", 11) == 0) {
                return html_names::kAutocompleteAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "ontrolslist", 11) == 0) {
                return html_names::kControlslistAttr;
            }
            break;
        case 'e':
            if (memcmp(data + 1, "nterkeyhint", 11) == 0) {
                return html_names::kEnterkeyhintAttr;
            }
            break;
        case 'm':
            if (memcmp(data + 1, "arginheight", 11) == 0) {
                return html_names::kMarginheightAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "fterprint", 9) == 0) {
                        return html_names::kOnafterprintAttr;
                    }
                    break;
                case 'b':
                    if (memcmp(data + 3, "eforecopy", 9) == 0) {
                        return html_names::kOnbeforecopyAttr;
                    }
                    break;
                case 'h':
                    if (memcmp(data + 3, "ashchange", 9) == 0) {
                        return html_names::kOnhashchangeAttr;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, "oadeddata", 9) == 0) {
                        return html_names::kOnloadeddataAttr;
                    }
                    break;
                case 'm':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'u':
                            switch (data[5]) {
                            case 's':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'e':
                                        if (memcmp(data + 8, "nter", 4) == 0) {
                                            return html_names::kOnmouseenterAttr;
                                        }
                                        break;
                                    case 'l':
                                        if (memcmp(data + 8, "eave", 4) == 0) {
                                            return html_names::kOnmouseleaveAttr;
                                        }
                                        break;
                                    case 'w':
                                        if (memcmp(data + 8, "heel", 4) == 0) {
                                            return html_names::kOnmousewheelAttr;
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
                    break;
                case 'o':
                    if (memcmp(data + 3, "verscroll", 9) == 0) {
                        return html_names::kOnoverscrollAttr;
                    }
                    break;
                case 'p':
                    if (memcmp(data + 3, "ointerout", 9) == 0) {
                        return html_names::kOnpointeroutAttr;
                    }
                    break;
                case 'r':
                    if (memcmp(data + 3, "atechange", 9) == 0) {
                        return html_names::kOnratechangeAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "lotchange", 9) == 0) {
                        return html_names::kOnslotchangeAttr;
                    }
                    break;
                case 't':
                    switch (data[3]) {
                    case 'i':
                        if (memcmp(data + 4, "meupdate", 8) == 0) {
                            return html_names::kOntimeupdateAttr;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, "uchstart", 8) == 0) {
                            return html_names::kOntouchstartAttr;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "rivatetoken", 11) == 0) {
                return html_names::kPrivatetokenAttr;
            }
            break;
        case 's':
            if (memcmp(data + 1, "crollamount", 11) == 0) {
                return html_names::kScrollamountAttr;
            }
            break;
        }
        break;
    case 13:
        switch (data[0]) {
        case 'e':
            if (memcmp(data + 1, "lementtiming", 12) == 0) {
                return html_names::kElementtimingAttr;
            }
            break;
        case 'f':
            if (memcmp(data + 1, "etchpriority", 12) == 0) {
                return html_names::kFetchpriorityAttr;
            }
            break;
        case 'h':
            if (memcmp(data + 1, "reftranslate", 12) == 0) {
                return html_names::kHreftranslateAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'b':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'f':
                            switch (data[5]) {
                            case 'o':
                                switch (data[6]) {
                                case 'r':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'i':
                                            if (memcmp(data + 9, "nput", 4) == 0) {
                                                return html_names::kOnbeforeinputAttr;
                                            }
                                            break;
                                        case 'p':
                                            switch (data[9]) {
                                            case 'a':
                                                if (memcmp(data + 10, "ste", 3) == 0) {
                                                    return html_names::kOnbeforepasteAttr;
                                                }
                                                break;
                                            case 'r':
                                                if (memcmp(data + 10, "int", 3) == 0) {
                                                    return html_names::kOnbeforeprintAttr;
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
                            break;
                        }
                        break;
                    }
                    break;
                case 'c':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'n':
                            switch (data[5]) {
                            case 't':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'x':
                                        switch (data[8]) {
                                        case 't':
                                            switch (data[9]) {
                                            case 'l':
                                                if (memcmp(data + 10, "ost", 3) == 0) {
                                                    return html_names::kOncontextlostAttr;
                                                }
                                                break;
                                            case 'm':
                                                if (memcmp(data + 10, "enu", 3) == 0) {
                                                    return html_names::kOncontextmenuAttr;
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
                            break;
                        }
                        break;
                    }
                    break;
                case 'p':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'i':
                            switch (data[5]) {
                            case 'n':
                                switch (data[6]) {
                                case 't':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'r':
                                            switch (data[9]) {
                                            case 'd':
                                                if (memcmp(data + 10, "own", 3) == 0) {
                                                    return html_names::kOnpointerdownAttr;
                                                }
                                                break;
                                            case 'm':
                                                if (memcmp(data + 10, "ove", 3) == 0) {
                                                    return html_names::kOnpointermoveAttr;
                                                }
                                                break;
                                            case 'o':
                                                if (memcmp(data + 10, "ver", 3) == 0) {
                                                    return html_names::kOnpointeroverAttr;
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
                            break;
                        }
                        break;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "electstart", 10) == 0) {
                        return html_names::kOnselectstartAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, "ouchcancel", 10) == 0) {
                        return html_names::kOntouchcancelAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "opovertarget", 12) == 0) {
                return html_names::kPopovertargetAttr;
            }
            break;
        }
        break;
    case 14:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, "cept-charset", 12) == 0) {
                    return html_names::kAcceptCharsetAttr;
                }
                break;
            case 't':
                if (memcmp(data + 2, "tributionsrc", 12) == 0) {
                    return html_names::kAttributionsrcAttr;
                }
                break;
            case 'u':
                if (memcmp(data + 2, "tocapitalize", 12) == 0) {
                    return html_names::kAutocapitalizeAttr;
                }
                break;
            }
            break;
        case 'b':
            if (memcmp(data + 1, "rowsingtopics", 13) == 0) {
                return html_names::kBrowsingtopicsAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "redentialless", 13) == 0) {
                return html_names::kCredentiallessAttr;
            }
            break;
        case 'd':
            if (memcmp(data + 1, "elegatesfocus", 13) == 0) {
                return html_names::kDelegatesfocusAttr;
            }
            break;
        case 'f':
            if (memcmp(data + 1, "ormnovalidate", 13) == 0) {
                return html_names::kFormnovalidateAttr;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 't':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'r':
                            switch (data[5]) {
                            case 'e':
                                switch (data[6]) {
                                case 's':
                                    switch (data[7]) {
                                    case 't':
                                        switch (data[8]) {
                                        case 'a':
                                            if (memcmp(data + 9, "ction", 5) == 0) {
                                                return html_names::kInterestactionAttr;
                                            }
                                            break;
                                        case 't':
                                            if (memcmp(data + 9, "arget", 5) == 0) {
                                                return html_names::kInteresttargetAttr;
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
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "nimationend", 11) == 0) {
                        return html_names::kOnanimationendAttr;
                    }
                    break;
                case 'b':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'f':
                            switch (data[5]) {
                            case 'o':
                                switch (data[6]) {
                                case 'r':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 't':
                                            if (memcmp(data + 9, "oggle", 5) == 0) {
                                                return html_names::kOnbeforetoggleAttr;
                                            }
                                            break;
                                        case 'u':
                                            if (memcmp(data + 9, "nload", 5) == 0) {
                                                return html_names::kOnbeforeunloadAttr;
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
                        break;
                    }
                    break;
                case 'm':
                    if (memcmp(data + 3, "essageerror", 11) == 0) {
                        return html_names::kOnmessageerrorAttr;
                    }
                    break;
                case 'p':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'i':
                            switch (data[5]) {
                            case 'n':
                                switch (data[6]) {
                                case 't':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'r':
                                            switch (data[9]) {
                                            case 'e':
                                                if (memcmp(data + 10, "nter", 4) == 0) {
                                                    return html_names::kOnpointerenterAttr;
                                                }
                                                break;
                                            case 'l':
                                                if (memcmp(data + 10, "eave", 4) == 0) {
                                                    return html_names::kOnpointerleaveAttr;
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
                            break;
                        }
                        break;
                    }
                    break;
                case 'v':
                    if (memcmp(data + 3, "olumechange", 11) == 0) {
                        return html_names::kOnvolumechangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'r':
            if (memcmp(data + 1, "eferrerpolicy", 13) == 0) {
                return html_names::kReferrerpolicyAttr;
            }
            break;
        case 's':
            if (memcmp(data + 1, "hadowrootmode", 13) == 0) {
                return html_names::kShadowrootmodeAttr;
            }
            break;
        }
        break;
    case 15:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "llowfullscreen", 14) == 0) {
                return html_names::kAllowfullscreenAttr;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "ontenteditable", 14) == 0) {
                return html_names::kContenteditableAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'p':
                    if (memcmp(data + 3, "ointercancel", 12) == 0) {
                        return html_names::kOnpointercancelAttr;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, "ransitionend", 12) == 0) {
                        return html_names::kOntransitionendAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "reciselocation", 14) == 0) {
                return html_names::kPreciselocationAttr;
            }
            break;
        case 'w':
            if (memcmp(data + 1, "ebkitdirectory", 14) == 0) {
                return html_names::kWebkitdirectoryAttr;
            }
            break;
        }
        break;
    case 16:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "dauctionheaders", 15) == 0) {
                return html_names::kAdauctionheadersAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "nimationstart", 13) == 0) {
                        return html_names::kOnanimationstartAttr;
                    }
                    break;
                case 'c':
                    if (memcmp(data + 3, "anplaythrough", 13) == 0) {
                        return html_names::kOncanplaythroughAttr;
                    }
                    break;
                case 'd':
                    if (memcmp(data + 3, "urationchange", 13) == 0) {
                        return html_names::kOndurationchangeAttr;
                    }
                    break;
                case 'l':
                    switch (data[3]) {
                    case 'a':
                        if (memcmp(data + 4, "nguagechange", 12) == 0) {
                            return html_names::kOnlanguagechangeAttr;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, "adedmetadata", 12) == 0) {
                            return html_names::kOnloadedmetadataAttr;
                        }
                        break;
                    }
                    break;
                case 't':
                    if (memcmp(data + 3, "imezonechange", 13) == 0) {
                        return html_names::kOntimezonechangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 17:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    if (memcmp(data + 3, "ontextrestored", 14) == 0) {
                        return html_names::kOncontextrestoredAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "electionchange", 14) == 0) {
                        return html_names::kOnselectionchangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 18:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'p':
                    if (memcmp(data + 3, "ointerrawupdate", 15) == 0) {
                        return html_names::kOnpointerrawupdateAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "crollsnapchange", 15) == 0) {
                        return html_names::kOnscrollsnapchangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, "hadowrootclonable", 17) == 0) {
                return html_names::kShadowrootclonableAttr;
            }
            break;
        case 'w':
            if (memcmp(data + 1, "ritingsuggestions", 17) == 0) {
                return html_names::kWritingsuggestionsAttr;
            }
            break;
        }
        break;
    case 19:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "llowpaymentrequest", 18) == 0) {
                return html_names::kAllowpaymentrequestAttr;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'g':
                    if (memcmp(data + 3, "otpointercapture", 16) == 0) {
                        return html_names::kOngotpointercaptureAttr;
                    }
                    break;
                case 'o':
                    if (memcmp(data + 3, "rientationchange", 16) == 0) {
                        return html_names::kOnorientationchangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "opovertargetaction", 18) == 0) {
                return html_names::kPopovertargetactionAttr;
            }
            break;
        }
        break;
    case 20:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "nimationiteration", 17) == 0) {
                        return html_names::kOnanimationiterationAttr;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, "ostpointercapture", 17) == 0) {
                        return html_names::kOnlostpointercaptureAttr;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "crollsnapchanging", 17) == 0) {
                        return html_names::kOnscrollsnapchangingAttr;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, "ebkitanimationend", 17) == 0) {
                        return html_names::kOnwebkitanimationendAttr;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 21:
        switch (data[0]) {
        case 'd':
            if (memcmp(data + 1, "isableremoteplayback", 20) == 0) {
                return html_names::kDisableremoteplaybackAttr;
            }
            break;
        case 'o':
            if (memcmp(data + 1, "nwebkittransitionend", 20) == 0) {
                return html_names::kOnwebkittransitionendAttr;
            }
            break;
        case 's':
            if (memcmp(data + 1, "haredstoragewritable", 20) == 0) {
                return html_names::kSharedstoragewritableAttr;
            }
            break;
        case 'v':
            if (memcmp(data + 1, "irtualkeyboardpolicy", 20) == 0) {
                return html_names::kVirtualkeyboardpolicyAttr;
            }
            break;
        }
        break;
    case 22:
        switch (data[0]) {
        case 'o':
            if (memcmp(data + 1, "nwebkitanimationstart", 21) == 0) {
                return html_names::kOnwebkitanimationstartAttr;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, "lectedcontentelement", 20) == 0) {
                    return html_names::kSelectedcontentelementAttr;
                }
                break;
            case 'h':
                if (memcmp(data + 2, "adowrootserializable", 20) == 0) {
                    return html_names::kShadowrootserializableAttr;
                }
                break;
            }
            break;
        }
        break;
    case 23:
        switch (data[0]) {
        case 'd':
            if (memcmp(data + 1, "isablepictureinpicture", 22) == 0) {
                return html_names::kDisablepictureinpictureAttr;
            }
            break;
        case 'o':
            if (memcmp(data + 1, "nwebkitfullscreenerror", 22) == 0) {
                return html_names::kOnwebkitfullscreenerrorAttr;
            }
            break;
        }
        break;
    case 24:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'v':
                    if (memcmp(data + 3, "alidationstatuschange", 21) == 0) {
                        return html_names::kOnvalidationstatuschangeAttr;
                    }
                    break;
                case 'w':
                    if (memcmp(data + 3, "ebkitfullscreenchange", 21) == 0) {
                        return html_names::kOnwebkitfullscreenchangeAttr;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            if (memcmp(data + 1, "hadowrootdelegatesfocus", 23) == 0) {
                return html_names::kShadowrootdelegatesfocusAttr;
            }
            break;
        }
        break;
    case 25:
        switch (data[0]) {
        case 'o':
            if (memcmp(data + 1, "nsecuritypolicyviolation", 24) == 0) {
                return html_names::kOnsecuritypolicyviolationAttr;
            }
            break;
        case 's':
            if (memcmp(data + 1, "hadowrootreferencetarget", 24) == 0) {
                return html_names::kShadowrootreferencetargetAttr;
            }
            break;
        }
        break;
    case 26:
        switch (data[0]) {
        case 'o':
            if (memcmp(data + 1, "nwebkitanimationiteration", 25) == 0) {
                return html_names::kOnwebkitanimationiterationAttr;
            }
            break;
        }
        break;
    case 34:
        switch (data[0]) {
        case 'o':
            if (memcmp(data + 1, "ncontentvisibilityautostatechange", 33) == 0) {
                return html_names::kOncontentvisibilityautostatechangeAttr;
            }
            break;
        }
        break;
    }

    return g_null_name;
}

} // namespace blink
