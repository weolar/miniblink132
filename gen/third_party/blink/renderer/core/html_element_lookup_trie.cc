// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_lookup_trie.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#include "third_party/blink/renderer/core/html_element_lookup_trie.h"

#include "third_party/blink/renderer/core/html_names.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

CORE_EXPORT html_names::HTMLTag lookupHTMLTag(const UChar* data, unsigned length)
{
    DCHECK(data);
    DCHECK(length);
    switch (length) {
    case 1:
        switch (data[0]) {
        case 'a':
            return html_names::HTMLTag::kA;
        case 'b':
            return html_names::HTMLTag::kB;
        case 'i':
            return html_names::HTMLTag::kI;
        case 'p':
            return html_names::HTMLTag::kP;
        case 'q':
            return html_names::HTMLTag::kQ;
        case 's':
            return html_names::HTMLTag::kS;
        case 'u':
            return html_names::HTMLTag::kU;
        }
        break;
    case 2:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'r') {
                return html_names::HTMLTag::kBr;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'd':
                return html_names::HTMLTag::kDd;
            case 'l':
                return html_names::HTMLTag::kDl;
            case 't':
                return html_names::HTMLTag::kDt;
            }
            break;
        case 'e':
            if (data[1] == 'm') {
                return html_names::HTMLTag::kEm;
            }
            break;
        case 'h':
            switch (data[1]) {
            case '1':
                return html_names::HTMLTag::kH1;
            case '2':
                return html_names::HTMLTag::kH2;
            case '3':
                return html_names::HTMLTag::kH3;
            case '4':
                return html_names::HTMLTag::kH4;
            case '5':
                return html_names::HTMLTag::kH5;
            case '6':
                return html_names::HTMLTag::kH6;
            case 'r':
                return html_names::HTMLTag::kHr;
            }
            break;
        case 'l':
            if (data[1] == 'i') {
                return html_names::HTMLTag::kLi;
            }
            break;
        case 'o':
            if (data[1] == 'l') {
                return html_names::HTMLTag::kOl;
            }
            break;
        case 'r':
            switch (data[1]) {
            case 'b':
                return html_names::HTMLTag::kRb;
            case 'p':
                return html_names::HTMLTag::kRp;
            case 't':
                return html_names::HTMLTag::kRt;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'd':
                return html_names::HTMLTag::kTd;
            case 'h':
                return html_names::HTMLTag::kTh;
            case 'r':
                return html_names::HTMLTag::kTr;
            case 't':
                return html_names::HTMLTag::kTt;
            }
            break;
        case 'u':
            if (data[1] == 'l') {
                return html_names::HTMLTag::kUl;
            }
            break;
        }
        break;
    case 3:
        switch (data[0]) {
        case 'b':
            switch (data[1]) {
            case 'd':
                switch (data[2]) {
                case 'i':
                    return html_names::HTMLTag::kBdi;
                case 'o':
                    return html_names::HTMLTag::kBdo;
                }
                break;
            case 'i':
                if (data[2] == 'g') {
                    return html_names::HTMLTag::kBig;
                }
                break;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"ol", 2 * 2) == 0) {
                return html_names::HTMLTag::kCol;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'l') {
                    return html_names::HTMLTag::kDel;
                }
                break;
            case 'f':
                if (data[2] == 'n') {
                    return html_names::HTMLTag::kDfn;
                }
                break;
            case 'i':
                switch (data[2]) {
                case 'r':
                    return html_names::HTMLTag::kDir;
                case 'v':
                    return html_names::HTMLTag::kDiv;
                }
                break;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'g') {
                    return html_names::HTMLTag::kImg;
                }
                break;
            case 'n':
                if (data[2] == 's') {
                    return html_names::HTMLTag::kIns;
                }
                break;
            }
            break;
        case 'k':
            if (memcmp(data + 1, u"bd", 2 * 2) == 0) {
                return html_names::HTMLTag::kKbd;
            }
            break;
        case 'm':
            if (memcmp(data + 1, u"ap", 2 * 2) == 0) {
                return html_names::HTMLTag::kMap;
            }
            break;
        case 'n':
            if (memcmp(data + 1, u"av", 2 * 2) == 0) {
                return html_names::HTMLTag::kNav;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"re", 2 * 2) == 0) {
                return html_names::HTMLTag::kPre;
            }
            break;
        case 'r':
            if (memcmp(data + 1, u"tc", 2 * 2) == 0) {
                return html_names::HTMLTag::kRTC;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'u':
                switch (data[2]) {
                case 'b':
                    return html_names::HTMLTag::kSub;
                case 'p':
                    return html_names::HTMLTag::kSup;
                }
                break;
            }
            break;
        case 'v':
            if (memcmp(data + 1, u"ar", 2 * 2) == 0) {
                return html_names::HTMLTag::kVar;
            }
            break;
        case 'w':
            if (memcmp(data + 1, u"br", 2 * 2) == 0) {
                return html_names::HTMLTag::kWbr;
            }
            break;
        case 'x':
            if (memcmp(data + 1, u"mp", 2 * 2) == 0) {
                return html_names::HTMLTag::kXmp;
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
                    return html_names::HTMLTag::kAbbr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"ea", 2 * 2) == 0) {
                    return html_names::HTMLTag::kArea;
                }
                break;
            }
            break;
        case 'b':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"se", 2 * 2) == 0) {
                    return html_names::HTMLTag::kBase;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"dy", 2 * 2) == 0) {
                    return html_names::HTMLTag::kBody;
                }
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, u"te", 2 * 2) == 0) {
                    return html_names::HTMLTag::kCite;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"de", 2 * 2) == 0) {
                    return html_names::HTMLTag::kCode;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, u"ata", 2 * 3) == 0) {
                return html_names::HTMLTag::kData;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 't') {
                        return html_names::HTMLTag::kFont;
                    }
                    break;
                case 'r':
                    if (data[3] == 'm') {
                        return html_names::HTMLTag::kForm;
                    }
                    break;
                }
                break;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, u"ad", 2 * 2) == 0) {
                    return html_names::HTMLTag::kHead;
                }
                break;
            case 't':
                if (memcmp(data + 2, u"ml", 2 * 2) == 0) {
                    return html_names::HTMLTag::kHTML;
                }
                break;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"ink", 2 * 3) == 0) {
                return html_names::HTMLTag::kLink;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'i':
                    if (data[3] == 'n') {
                        return html_names::HTMLTag::kMain;
                    }
                    break;
                case 'r':
                    if (data[3] == 'k') {
                        return html_names::HTMLTag::kMark;
                    }
                    break;
                }
                break;
            case 'e':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 'u') {
                        return html_names::HTMLTag::kMenu;
                    }
                    break;
                case 't':
                    if (data[3] == 'a') {
                        return html_names::HTMLTag::kMeta;
                    }
                    break;
                }
                break;
            }
            break;
        case 'n':
            if (memcmp(data + 1, u"obr", 2 * 3) == 0) {
                return html_names::HTMLTag::kNobr;
            }
            break;
        case 'r':
            if (memcmp(data + 1, u"uby", 2 * 3) == 0) {
                return html_names::HTMLTag::kRuby;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"mp", 2 * 2) == 0) {
                    return html_names::HTMLTag::kSamp;
                }
                break;
            case 'l':
                if (memcmp(data + 2, u"ot", 2 * 2) == 0) {
                    return html_names::HTMLTag::kSlot;
                }
                break;
            case 'p':
                if (memcmp(data + 2, u"an", 2 * 2) == 0) {
                    return html_names::HTMLTag::kSpan;
                }
                break;
            }
            break;
        case 't':
            if (memcmp(data + 1, u"ime", 2 * 3) == 0) {
                return html_names::HTMLTag::kTime;
            }
            break;
        }
        break;
    case 5:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 's':
                if (memcmp(data + 2, u"ide", 2 * 3) == 0) {
                    return html_names::HTMLTag::kAside;
                }
                break;
            case 'u':
                if (memcmp(data + 2, u"dio", 2 * 3) == 0) {
                    return html_names::HTMLTag::kAudio;
                }
                break;
            }
            break;
        case 'e':
            if (memcmp(data + 1, u"mbed", 2 * 4) == 0) {
                return html_names::HTMLTag::kEmbed;
            }
            break;
        case 'f':
            if (memcmp(data + 1, u"rame", 2 * 4) == 0) {
                return html_names::HTMLTag::kFrame;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'm':
                if (memcmp(data + 2, u"age", 2 * 3) == 0) {
                    return html_names::HTMLTag::kImage;
                }
                break;
            case 'n':
                if (memcmp(data + 2, u"put", 2 * 3) == 0) {
                    return html_names::HTMLTag::kInput;
                }
                break;
            }
            break;
        case 'l':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'b':
                    if (memcmp(data + 3, u"el", 2 * 2) == 0) {
                        return html_names::HTMLTag::kLabel;
                    }
                    break;
                case 'y':
                    if (memcmp(data + 3, u"er", 2 * 2) == 0) {
                        return html_names::HTMLTag::kLayer;
                    }
                    break;
                }
                break;
            }
            break;
        case 'm':
            if (memcmp(data + 1, u"eter", 2 * 4) == 0) {
                return html_names::HTMLTag::kMeter;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"aram", 2 * 4) == 0) {
                return html_names::HTMLTag::kParam;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'm':
                if (memcmp(data + 2, u"all", 2 * 3) == 0) {
                    return html_names::HTMLTag::kSmall;
                }
                break;
            case 't':
                if (memcmp(data + 2, u"yle", 2 * 3) == 0) {
                    return html_names::HTMLTag::kStyle;
                }
                break;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"ble", 2 * 3) == 0) {
                    return html_names::HTMLTag::kTable;
                }
                break;
            case 'b':
                if (memcmp(data + 2, u"ody", 2 * 3) == 0) {
                    return html_names::HTMLTag::kTbody;
                }
                break;
            case 'f':
                if (memcmp(data + 2, u"oot", 2 * 3) == 0) {
                    return html_names::HTMLTag::kTfoot;
                }
                break;
            case 'h':
                if (memcmp(data + 2, u"ead", 2 * 3) == 0) {
                    return html_names::HTMLTag::kThead;
                }
                break;
            case 'i':
                if (memcmp(data + 2, u"tle", 2 * 3) == 0) {
                    return html_names::HTMLTag::kTitle;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"ack", 2 * 3) == 0) {
                    return html_names::HTMLTag::kTrack;
                }
                break;
            }
            break;
        case 'v':
            if (memcmp(data + 1, u"ideo", 2 * 4) == 0) {
                return html_names::HTMLTag::kVideo;
            }
            break;
        }
        break;
    case 6:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, u"pplet", 2 * 5) == 0) {
                return html_names::HTMLTag::kApplet;
            }
            break;
        case 'b':
            if (memcmp(data + 1, u"utton", 2 * 5) == 0) {
                return html_names::HTMLTag::kButton;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"nvas", 2 * 4) == 0) {
                    return html_names::HTMLTag::kCanvas;
                }
                break;
            case 'e':
                if (memcmp(data + 2, u"nter", 2 * 4) == 0) {
                    return html_names::HTMLTag::kCenter;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, u"ialog", 2 * 5) == 0) {
                return html_names::HTMLTag::kDialog;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, u"gure", 2 * 4) == 0) {
                    return html_names::HTMLTag::kFigure;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"oter", 2 * 4) == 0) {
                    return html_names::HTMLTag::kFooter;
                }
                break;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, u"ader", 2 * 4) == 0) {
                    return html_names::HTMLTag::kHeader;
                }
                break;
            case 'g':
                if (memcmp(data + 2, u"roup", 2 * 4) == 0) {
                    return html_names::HTMLTag::kHgroup;
                }
                break;
            }
            break;
        case 'i':
            if (memcmp(data + 1, u"frame", 2 * 5) == 0) {
                return html_names::HTMLTag::kIFrame;
            }
            break;
        case 'k':
            if (memcmp(data + 1, u"eygen", 2 * 5) == 0) {
                return html_names::HTMLTag::kKeygen;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"egend", 2 * 5) == 0) {
                return html_names::HTMLTag::kLegend;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'b':
                if (memcmp(data + 2, u"ject", 2 * 4) == 0) {
                    return html_names::HTMLTag::kObject;
                }
                break;
            case 'p':
                if (memcmp(data + 2, u"tion", 2 * 4) == 0) {
                    return html_names::HTMLTag::kOption;
                }
                break;
            case 'u':
                if (memcmp(data + 2, u"tput", 2 * 4) == 0) {
                    return html_names::HTMLTag::kOutput;
                }
                break;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, u"ript", 2 * 4) == 0) {
                    return html_names::HTMLTag::kScript;
                }
                break;
            case 'e':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, u"rch", 2 * 3) == 0) {
                        return html_names::HTMLTag::kSearch;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, u"ect", 2 * 3) == 0) {
                        return html_names::HTMLTag::kSelect;
                    }
                    break;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"urce", 2 * 4) == 0) {
                    return html_names::HTMLTag::kSource;
                }
                break;
            case 't':
                switch (data[2]) {
                case 'r':
                    switch (data[3]) {
                    case 'i':
                        if (memcmp(data + 4, u"ke", 2 * 2) == 0) {
                            return html_names::HTMLTag::kStrike;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, u"ng", 2 * 2) == 0) {
                            return html_names::HTMLTag::kStrong;
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
    case 7:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, u"ronym", 2 * 5) == 0) {
                    return html_names::HTMLTag::kAcronym;
                }
                break;
            case 'd':
                if (memcmp(data + 2, u"dress", 2 * 5) == 0) {
                    return html_names::HTMLTag::kAddress;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"ticle", 2 * 5) == 0) {
                    return html_names::HTMLTag::kArticle;
                }
                break;
            }
            break;
        case 'b':
            if (memcmp(data + 1, u"gsound", 2 * 6) == 0) {
                return html_names::HTMLTag::kBgsound;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, u"ption", 2 * 5) == 0) {
                    return html_names::HTMLTag::kCaption;
                }
                break;
            case 'o':
                if (memcmp(data + 2, u"mmand", 2 * 5) == 0) {
                    return html_names::HTMLTag::kCommand;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, u"etails", 2 * 6) == 0) {
                return html_names::HTMLTag::kDetails;
            }
            break;
        case 'l':
            if (memcmp(data + 1, u"isting", 2 * 6) == 0) {
                return html_names::HTMLTag::kListing;
            }
            break;
        case 'm':
            if (memcmp(data + 1, u"arquee", 2 * 6) == 0) {
                return html_names::HTMLTag::kMarquee;
            }
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'e':
                    if (memcmp(data + 3, u"mbed", 2 * 4) == 0) {
                        return html_names::HTMLTag::kNoembed;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, u"ayer", 2 * 4) == 0) {
                        return html_names::HTMLTag::kNolayer;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"icture", 2 * 6) == 0) {
                return html_names::HTMLTag::kPicture;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, u"ction", 2 * 5) == 0) {
                    return html_names::HTMLTag::kSection;
                }
                break;
            case 'u':
                if (memcmp(data + 2, u"mmary", 2 * 5) == 0) {
                    return html_names::HTMLTag::kSummary;
                }
                break;
            }
            break;
        }
        break;
    case 8:
        switch (data[0]) {
        case 'b':
            if (memcmp(data + 1, u"asefont", 2 * 7) == 0) {
                return html_names::HTMLTag::kBasefont;
            }
            break;
        case 'c':
            if (memcmp(data + 1, u"olgroup", 2 * 7) == 0) {
                return html_names::HTMLTag::kColgroup;
            }
            break;
        case 'd':
            if (memcmp(data + 1, u"atalist", 2 * 7) == 0) {
                return html_names::HTMLTag::kDatalist;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, u"eldset", 2 * 6) == 0) {
                    return html_names::HTMLTag::kFieldset;
                }
                break;
            case 'r':
                if (memcmp(data + 2, u"ameset", 2 * 6) == 0) {
                    return html_names::HTMLTag::kFrameset;
                }
                break;
            }
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'f':
                    if (memcmp(data + 3, u"rames", 2 * 5) == 0) {
                        return html_names::HTMLTag::kNoframes;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, u"cript", 2 * 5) == 0) {
                        return html_names::HTMLTag::kNoscript;
                    }
                    break;
                }
                break;
            }
            break;
        case 'o':
            if (memcmp(data + 1, u"ptgroup", 2 * 7) == 0) {
                return html_names::HTMLTag::kOptgroup;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"rogress", 2 * 7) == 0) {
                return html_names::HTMLTag::kProgress;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'm':
                    if (memcmp(data + 3, u"plate", 2 * 5) == 0) {
                        return html_names::HTMLTag::kTemplate;
                    }
                    break;
                case 'x':
                    if (memcmp(data + 3, u"tarea", 2 * 5) == 0) {
                        return html_names::HTMLTag::kTextarea;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 9:
        switch (data[0]) {
        case 'p':
            if (memcmp(data + 1, u"laintext", 2 * 8) == 0) {
                return html_names::HTMLTag::kPlaintext;
            }
            break;
        }
        break;
    case 10:
        switch (data[0]) {
        case 'b':
            if (memcmp(data + 1, u"lockquote", 2 * 9) == 0) {
                return html_names::HTMLTag::kBlockquote;
            }
            break;
        case 'f':
            if (memcmp(data + 1, u"igcaption", 2 * 9) == 0) {
                return html_names::HTMLTag::kFigcaption;
            }
            break;
        case 'p':
            if (memcmp(data + 1, u"ermission", 2 * 9) == 0) {
                return html_names::HTMLTag::kPermissionOrUnknown;
            }
            break;
        }
        break;
    case 11:
        switch (data[0]) {
        case 'f':
            if (memcmp(data + 1, u"encedframe", 2 * 10) == 0) {
                return html_names::HTMLTag::kFencedframeOrUnknown;
            }
            break;
        }
        break;
    case 15:
        switch (data[0]) {
        case 's':
            if (memcmp(data + 1, u"electedcontent", 2 * 14) == 0) {
                return (RuntimeEnabledFeatures::CustomizableSelectEnabled()
                        // If this code fails to compile because the
                        // RuntimeEnabledFeatures method requires an argument
                        // (because the feature can be affected by origin trials),
                        // this means you need to add runtimeFlagHasOriginTrial to
                        // the appropriate entry in html_tag_names.json5 .  Also
                        // see the documentation in html_tag_names.json5 for
                        // additional things you should test when doing this.
                        ? html_names::HTMLTag::kSelectedcontent
                        : html_names::HTMLTag::kUnknown);
            }
            break;
        }
        break;
    }

    return html_names::HTMLTag::kUnknown;
}

CORE_EXPORT html_names::HTMLTag lookupHTMLTag(const LChar* data, unsigned length)
{
    DCHECK(data);
    DCHECK(length);
    switch (length) {
    case 1:
        switch (data[0]) {
        case 'a':
            return html_names::HTMLTag::kA;
        case 'b':
            return html_names::HTMLTag::kB;
        case 'i':
            return html_names::HTMLTag::kI;
        case 'p':
            return html_names::HTMLTag::kP;
        case 'q':
            return html_names::HTMLTag::kQ;
        case 's':
            return html_names::HTMLTag::kS;
        case 'u':
            return html_names::HTMLTag::kU;
        }
        break;
    case 2:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'r') {
                return html_names::HTMLTag::kBr;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'd':
                return html_names::HTMLTag::kDd;
            case 'l':
                return html_names::HTMLTag::kDl;
            case 't':
                return html_names::HTMLTag::kDt;
            }
            break;
        case 'e':
            if (data[1] == 'm') {
                return html_names::HTMLTag::kEm;
            }
            break;
        case 'h':
            switch (data[1]) {
            case '1':
                return html_names::HTMLTag::kH1;
            case '2':
                return html_names::HTMLTag::kH2;
            case '3':
                return html_names::HTMLTag::kH3;
            case '4':
                return html_names::HTMLTag::kH4;
            case '5':
                return html_names::HTMLTag::kH5;
            case '6':
                return html_names::HTMLTag::kH6;
            case 'r':
                return html_names::HTMLTag::kHr;
            }
            break;
        case 'l':
            if (data[1] == 'i') {
                return html_names::HTMLTag::kLi;
            }
            break;
        case 'o':
            if (data[1] == 'l') {
                return html_names::HTMLTag::kOl;
            }
            break;
        case 'r':
            switch (data[1]) {
            case 'b':
                return html_names::HTMLTag::kRb;
            case 'p':
                return html_names::HTMLTag::kRp;
            case 't':
                return html_names::HTMLTag::kRt;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'd':
                return html_names::HTMLTag::kTd;
            case 'h':
                return html_names::HTMLTag::kTh;
            case 'r':
                return html_names::HTMLTag::kTr;
            case 't':
                return html_names::HTMLTag::kTt;
            }
            break;
        case 'u':
            if (data[1] == 'l') {
                return html_names::HTMLTag::kUl;
            }
            break;
        }
        break;
    case 3:
        switch (data[0]) {
        case 'b':
            switch (data[1]) {
            case 'd':
                switch (data[2]) {
                case 'i':
                    return html_names::HTMLTag::kBdi;
                case 'o':
                    return html_names::HTMLTag::kBdo;
                }
                break;
            case 'i':
                if (data[2] == 'g') {
                    return html_names::HTMLTag::kBig;
                }
                break;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "ol", 2) == 0) {
                return html_names::HTMLTag::kCol;
            }
            break;
        case 'd':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'l') {
                    return html_names::HTMLTag::kDel;
                }
                break;
            case 'f':
                if (data[2] == 'n') {
                    return html_names::HTMLTag::kDfn;
                }
                break;
            case 'i':
                switch (data[2]) {
                case 'r':
                    return html_names::HTMLTag::kDir;
                case 'v':
                    return html_names::HTMLTag::kDiv;
                }
                break;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'g') {
                    return html_names::HTMLTag::kImg;
                }
                break;
            case 'n':
                if (data[2] == 's') {
                    return html_names::HTMLTag::kIns;
                }
                break;
            }
            break;
        case 'k':
            if (memcmp(data + 1, "bd", 2) == 0) {
                return html_names::HTMLTag::kKbd;
            }
            break;
        case 'm':
            if (memcmp(data + 1, "ap", 2) == 0) {
                return html_names::HTMLTag::kMap;
            }
            break;
        case 'n':
            if (memcmp(data + 1, "av", 2) == 0) {
                return html_names::HTMLTag::kNav;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "re", 2) == 0) {
                return html_names::HTMLTag::kPre;
            }
            break;
        case 'r':
            if (memcmp(data + 1, "tc", 2) == 0) {
                return html_names::HTMLTag::kRTC;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'u':
                switch (data[2]) {
                case 'b':
                    return html_names::HTMLTag::kSub;
                case 'p':
                    return html_names::HTMLTag::kSup;
                }
                break;
            }
            break;
        case 'v':
            if (memcmp(data + 1, "ar", 2) == 0) {
                return html_names::HTMLTag::kVar;
            }
            break;
        case 'w':
            if (memcmp(data + 1, "br", 2) == 0) {
                return html_names::HTMLTag::kWbr;
            }
            break;
        case 'x':
            if (memcmp(data + 1, "mp", 2) == 0) {
                return html_names::HTMLTag::kXmp;
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
                    return html_names::HTMLTag::kAbbr;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "ea", 2) == 0) {
                    return html_names::HTMLTag::kArea;
                }
                break;
            }
            break;
        case 'b':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "se", 2) == 0) {
                    return html_names::HTMLTag::kBase;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "dy", 2) == 0) {
                    return html_names::HTMLTag::kBody;
                }
                break;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, "te", 2) == 0) {
                    return html_names::HTMLTag::kCite;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "de", 2) == 0) {
                    return html_names::HTMLTag::kCode;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, "ata", 3) == 0) {
                return html_names::HTMLTag::kData;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 't') {
                        return html_names::HTMLTag::kFont;
                    }
                    break;
                case 'r':
                    if (data[3] == 'm') {
                        return html_names::HTMLTag::kForm;
                    }
                    break;
                }
                break;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, "ad", 2) == 0) {
                    return html_names::HTMLTag::kHead;
                }
                break;
            case 't':
                if (memcmp(data + 2, "ml", 2) == 0) {
                    return html_names::HTMLTag::kHTML;
                }
                break;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "ink", 3) == 0) {
                return html_names::HTMLTag::kLink;
            }
            break;
        case 'm':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'i':
                    if (data[3] == 'n') {
                        return html_names::HTMLTag::kMain;
                    }
                    break;
                case 'r':
                    if (data[3] == 'k') {
                        return html_names::HTMLTag::kMark;
                    }
                    break;
                }
                break;
            case 'e':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 'u') {
                        return html_names::HTMLTag::kMenu;
                    }
                    break;
                case 't':
                    if (data[3] == 'a') {
                        return html_names::HTMLTag::kMeta;
                    }
                    break;
                }
                break;
            }
            break;
        case 'n':
            if (memcmp(data + 1, "obr", 3) == 0) {
                return html_names::HTMLTag::kNobr;
            }
            break;
        case 'r':
            if (memcmp(data + 1, "uby", 3) == 0) {
                return html_names::HTMLTag::kRuby;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "mp", 2) == 0) {
                    return html_names::HTMLTag::kSamp;
                }
                break;
            case 'l':
                if (memcmp(data + 2, "ot", 2) == 0) {
                    return html_names::HTMLTag::kSlot;
                }
                break;
            case 'p':
                if (memcmp(data + 2, "an", 2) == 0) {
                    return html_names::HTMLTag::kSpan;
                }
                break;
            }
            break;
        case 't':
            if (memcmp(data + 1, "ime", 3) == 0) {
                return html_names::HTMLTag::kTime;
            }
            break;
        }
        break;
    case 5:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 's':
                if (memcmp(data + 2, "ide", 3) == 0) {
                    return html_names::HTMLTag::kAside;
                }
                break;
            case 'u':
                if (memcmp(data + 2, "dio", 3) == 0) {
                    return html_names::HTMLTag::kAudio;
                }
                break;
            }
            break;
        case 'e':
            if (memcmp(data + 1, "mbed", 4) == 0) {
                return html_names::HTMLTag::kEmbed;
            }
            break;
        case 'f':
            if (memcmp(data + 1, "rame", 4) == 0) {
                return html_names::HTMLTag::kFrame;
            }
            break;
        case 'i':
            switch (data[1]) {
            case 'm':
                if (memcmp(data + 2, "age", 3) == 0) {
                    return html_names::HTMLTag::kImage;
                }
                break;
            case 'n':
                if (memcmp(data + 2, "put", 3) == 0) {
                    return html_names::HTMLTag::kInput;
                }
                break;
            }
            break;
        case 'l':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'b':
                    if (memcmp(data + 3, "el", 2) == 0) {
                        return html_names::HTMLTag::kLabel;
                    }
                    break;
                case 'y':
                    if (memcmp(data + 3, "er", 2) == 0) {
                        return html_names::HTMLTag::kLayer;
                    }
                    break;
                }
                break;
            }
            break;
        case 'm':
            if (memcmp(data + 1, "eter", 4) == 0) {
                return html_names::HTMLTag::kMeter;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "aram", 4) == 0) {
                return html_names::HTMLTag::kParam;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'm':
                if (memcmp(data + 2, "all", 3) == 0) {
                    return html_names::HTMLTag::kSmall;
                }
                break;
            case 't':
                if (memcmp(data + 2, "yle", 3) == 0) {
                    return html_names::HTMLTag::kStyle;
                }
                break;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "ble", 3) == 0) {
                    return html_names::HTMLTag::kTable;
                }
                break;
            case 'b':
                if (memcmp(data + 2, "ody", 3) == 0) {
                    return html_names::HTMLTag::kTbody;
                }
                break;
            case 'f':
                if (memcmp(data + 2, "oot", 3) == 0) {
                    return html_names::HTMLTag::kTfoot;
                }
                break;
            case 'h':
                if (memcmp(data + 2, "ead", 3) == 0) {
                    return html_names::HTMLTag::kThead;
                }
                break;
            case 'i':
                if (memcmp(data + 2, "tle", 3) == 0) {
                    return html_names::HTMLTag::kTitle;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "ack", 3) == 0) {
                    return html_names::HTMLTag::kTrack;
                }
                break;
            }
            break;
        case 'v':
            if (memcmp(data + 1, "ideo", 4) == 0) {
                return html_names::HTMLTag::kVideo;
            }
            break;
        }
        break;
    case 6:
        switch (data[0]) {
        case 'a':
            if (memcmp(data + 1, "pplet", 5) == 0) {
                return html_names::HTMLTag::kApplet;
            }
            break;
        case 'b':
            if (memcmp(data + 1, "utton", 5) == 0) {
                return html_names::HTMLTag::kButton;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "nvas", 4) == 0) {
                    return html_names::HTMLTag::kCanvas;
                }
                break;
            case 'e':
                if (memcmp(data + 2, "nter", 4) == 0) {
                    return html_names::HTMLTag::kCenter;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, "ialog", 5) == 0) {
                return html_names::HTMLTag::kDialog;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, "gure", 4) == 0) {
                    return html_names::HTMLTag::kFigure;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "oter", 4) == 0) {
                    return html_names::HTMLTag::kFooter;
                }
                break;
            }
            break;
        case 'h':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, "ader", 4) == 0) {
                    return html_names::HTMLTag::kHeader;
                }
                break;
            case 'g':
                if (memcmp(data + 2, "roup", 4) == 0) {
                    return html_names::HTMLTag::kHgroup;
                }
                break;
            }
            break;
        case 'i':
            if (memcmp(data + 1, "frame", 5) == 0) {
                return html_names::HTMLTag::kIFrame;
            }
            break;
        case 'k':
            if (memcmp(data + 1, "eygen", 5) == 0) {
                return html_names::HTMLTag::kKeygen;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "egend", 5) == 0) {
                return html_names::HTMLTag::kLegend;
            }
            break;
        case 'o':
            switch (data[1]) {
            case 'b':
                if (memcmp(data + 2, "ject", 4) == 0) {
                    return html_names::HTMLTag::kObject;
                }
                break;
            case 'p':
                if (memcmp(data + 2, "tion", 4) == 0) {
                    return html_names::HTMLTag::kOption;
                }
                break;
            case 'u':
                if (memcmp(data + 2, "tput", 4) == 0) {
                    return html_names::HTMLTag::kOutput;
                }
                break;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, "ript", 4) == 0) {
                    return html_names::HTMLTag::kScript;
                }
                break;
            case 'e':
                switch (data[2]) {
                case 'a':
                    if (memcmp(data + 3, "rch", 3) == 0) {
                        return html_names::HTMLTag::kSearch;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, "ect", 3) == 0) {
                        return html_names::HTMLTag::kSelect;
                    }
                    break;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "urce", 4) == 0) {
                    return html_names::HTMLTag::kSource;
                }
                break;
            case 't':
                switch (data[2]) {
                case 'r':
                    switch (data[3]) {
                    case 'i':
                        if (memcmp(data + 4, "ke", 2) == 0) {
                            return html_names::HTMLTag::kStrike;
                        }
                        break;
                    case 'o':
                        if (memcmp(data + 4, "ng", 2) == 0) {
                            return html_names::HTMLTag::kStrong;
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
    case 7:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (memcmp(data + 2, "ronym", 5) == 0) {
                    return html_names::HTMLTag::kAcronym;
                }
                break;
            case 'd':
                if (memcmp(data + 2, "dress", 5) == 0) {
                    return html_names::HTMLTag::kAddress;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "ticle", 5) == 0) {
                    return html_names::HTMLTag::kArticle;
                }
                break;
            }
            break;
        case 'b':
            if (memcmp(data + 1, "gsound", 6) == 0) {
                return html_names::HTMLTag::kBgsound;
            }
            break;
        case 'c':
            switch (data[1]) {
            case 'a':
                if (memcmp(data + 2, "ption", 5) == 0) {
                    return html_names::HTMLTag::kCaption;
                }
                break;
            case 'o':
                if (memcmp(data + 2, "mmand", 5) == 0) {
                    return html_names::HTMLTag::kCommand;
                }
                break;
            }
            break;
        case 'd':
            if (memcmp(data + 1, "etails", 6) == 0) {
                return html_names::HTMLTag::kDetails;
            }
            break;
        case 'l':
            if (memcmp(data + 1, "isting", 6) == 0) {
                return html_names::HTMLTag::kListing;
            }
            break;
        case 'm':
            if (memcmp(data + 1, "arquee", 6) == 0) {
                return html_names::HTMLTag::kMarquee;
            }
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'e':
                    if (memcmp(data + 3, "mbed", 4) == 0) {
                        return html_names::HTMLTag::kNoembed;
                    }
                    break;
                case 'l':
                    if (memcmp(data + 3, "ayer", 4) == 0) {
                        return html_names::HTMLTag::kNolayer;
                    }
                    break;
                }
                break;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "icture", 6) == 0) {
                return html_names::HTMLTag::kPicture;
            }
            break;
        case 's':
            switch (data[1]) {
            case 'e':
                if (memcmp(data + 2, "ction", 5) == 0) {
                    return html_names::HTMLTag::kSection;
                }
                break;
            case 'u':
                if (memcmp(data + 2, "mmary", 5) == 0) {
                    return html_names::HTMLTag::kSummary;
                }
                break;
            }
            break;
        }
        break;
    case 8:
        switch (data[0]) {
        case 'b':
            if (memcmp(data + 1, "asefont", 7) == 0) {
                return html_names::HTMLTag::kBasefont;
            }
            break;
        case 'c':
            if (memcmp(data + 1, "olgroup", 7) == 0) {
                return html_names::HTMLTag::kColgroup;
            }
            break;
        case 'd':
            if (memcmp(data + 1, "atalist", 7) == 0) {
                return html_names::HTMLTag::kDatalist;
            }
            break;
        case 'f':
            switch (data[1]) {
            case 'i':
                if (memcmp(data + 2, "eldset", 6) == 0) {
                    return html_names::HTMLTag::kFieldset;
                }
                break;
            case 'r':
                if (memcmp(data + 2, "ameset", 6) == 0) {
                    return html_names::HTMLTag::kFrameset;
                }
                break;
            }
            break;
        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'f':
                    if (memcmp(data + 3, "rames", 5) == 0) {
                        return html_names::HTMLTag::kNoframes;
                    }
                    break;
                case 's':
                    if (memcmp(data + 3, "cript", 5) == 0) {
                        return html_names::HTMLTag::kNoscript;
                    }
                    break;
                }
                break;
            }
            break;
        case 'o':
            if (memcmp(data + 1, "ptgroup", 7) == 0) {
                return html_names::HTMLTag::kOptgroup;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "rogress", 7) == 0) {
                return html_names::HTMLTag::kProgress;
            }
            break;
        case 't':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'm':
                    if (memcmp(data + 3, "plate", 5) == 0) {
                        return html_names::HTMLTag::kTemplate;
                    }
                    break;
                case 'x':
                    if (memcmp(data + 3, "tarea", 5) == 0) {
                        return html_names::HTMLTag::kTextarea;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;
    case 9:
        switch (data[0]) {
        case 'p':
            if (memcmp(data + 1, "laintext", 8) == 0) {
                return html_names::HTMLTag::kPlaintext;
            }
            break;
        }
        break;
    case 10:
        switch (data[0]) {
        case 'b':
            if (memcmp(data + 1, "lockquote", 9) == 0) {
                return html_names::HTMLTag::kBlockquote;
            }
            break;
        case 'f':
            if (memcmp(data + 1, "igcaption", 9) == 0) {
                return html_names::HTMLTag::kFigcaption;
            }
            break;
        case 'p':
            if (memcmp(data + 1, "ermission", 9) == 0) {
                return html_names::HTMLTag::kPermissionOrUnknown;
            }
            break;
        }
        break;
    case 11:
        switch (data[0]) {
        case 'f':
            if (memcmp(data + 1, "encedframe", 10) == 0) {
                return html_names::HTMLTag::kFencedframeOrUnknown;
            }
            break;
        }
        break;
    case 15:
        switch (data[0]) {
        case 's':
            if (memcmp(data + 1, "electedcontent", 14) == 0) {
                return (RuntimeEnabledFeatures::CustomizableSelectEnabled()
                        // If this code fails to compile because the
                        // RuntimeEnabledFeatures method requires an argument
                        // (because the feature can be affected by origin trials),
                        // this means you need to add runtimeFlagHasOriginTrial to
                        // the appropriate entry in html_tag_names.json5 .  Also
                        // see the documentation in html_tag_names.json5 for
                        // additional things you should test when doing this.
                        ? html_names::HTMLTag::kSelectedcontent
                        : html_names::HTMLTag::kUnknown);
            }
            break;
        }
        break;
    }

    return html_names::HTMLTag::kUnknown;
}

} // namespace blink
