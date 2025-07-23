// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CORE_BROWSER_FORM_PARSING_REGEX_PATTERNS_INL_H_
#define COMPONENTS_AUTOFILL_CORE_BROWSER_FORM_PARSING_REGEX_PATTERNS_INL_H_

#include <array>
#include <string_view>

#include "base/containers/fixed_flat_map.h"
#include "base/containers/fixed_flat_set.h"
#include "base/containers/span.h"

#include "components/autofill/core/browser/form_parsing/regex_patterns.h"
#include "components/autofill/core/common/dense_set.h"
#include "components/autofill/core/browser/form_parsing/autofill_parsing_utils.h"

namespace autofill {

// Wrapper of MatchPatternRef's private constructor.
// It's a friend of MatchPatternRef.
constexpr MatchPatternRef MakeMatchPatternRef(bool is_supplementary, MatchPatternRef::UnderlyingType index)
{
    return MatchPatternRef(is_supplementary, index);
}

// A pair of const char* used as keys in the `kPatternMap`.
struct NameAndLanguage {
    using StringViewPair = std::pair<std::string_view, std::string_view>;

    // By this implicit conversion, the below comparator can be called for
    // NameAndLanguageComparator and StringViewPairs alike.
    constexpr operator StringViewPair() const
    {
        return { std::string_view(name), std::string_view(lang) };
    }

    const char* name; // A pattern name.
    const char* lang; // A language code.
};

// A less-than relation on NameAndLanguage and/or std::string_view pairs.
struct NameAndLanguageComparator {
    using is_transparent = void;

    // By way of the implicit conversion from NameAndLanguage to StringViewPair,
    // this function also accepts NameAndLanguage.
    //
    // To implement constexpr lexicographic comparison of const char* with the
    // standard library, we need to compute both the lengths of the strings before
    // we can actually compare the strings. A simple way of doing so is to convert
    // each const char* to a std::string_view and then comparing the
    // std::string_views.
    //
    // This is exactly what the comparator does: when an argument is a
    // NameAndLanguage, it is implicitly converted to a StringViewPair, which
    // is then compared to the other StringViewPair.
    constexpr bool operator()(NameAndLanguage::StringViewPair a, NameAndLanguage::StringViewPair b) const
    {
        int cmp = a.first.compare(b.first);
        return cmp < 0 || (cmp == 0 && a.second.compare(b.second) < 0);
    }
};

// A less-than relation on const char* and std::string_view, in particular for
// language codes.
struct LanguageComparator {
    using is_transparent = void;

    // This function also accepts const char* by implicit conversion to
    // std::string_view.
    //
    // This comparator facilitates constexpr comparison among const char*
    // similarly to the above NameAndLanguageComparator.
    constexpr bool operator()(std::string_view a, std::string_view b) const
    {
        return a.compare(b) < 0;
    }
};

// The patterns. Referred to by their index in MatchPatternRef.
constexpr auto kPatterns = std::to_array<MatchingPattern>({
    /*[0]=*/MatchingPattern {
        .positive_pattern = u"wohnung",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[1]=*/
    MatchingPattern {
        .positive_pattern = u"apartment",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[2]=*/
    MatchingPattern {
        .positive_pattern = u"interior|n\u00famero.*apartamento|departamento|(?:(?<!tel\u00e9fo)no|n[\u00fau]m(?:ero)?)\\.?\\s*(int\\b|interno)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[3]=*/
    MatchingPattern {
        .positive_pattern = u"num\u00e9ro.*appartement",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[4]=*/
    MatchingPattern {
        .positive_pattern = u"numero.*appartamento",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[5]=*/
    MatchingPattern {
        .positive_pattern = u"(?:nr|numer)?[.\\s]*(?:lokalu|(?<!za)mieszkani[ae])",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[6]=*/
    MatchingPattern {
        .positive_pattern = u"\u043a\u0432\u0430\u0440\u0442\u0438\u0440",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[7]=*/
    MatchingPattern {
        .positive_pattern = u"neighbo(u)?rhood",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types
        = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch, FormControlType::kTextArea },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[8]=*/
    MatchingPattern {
        .positive_pattern = u"colonia",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types
        = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch, FormControlType::kTextArea },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[9]=*/
    MatchingPattern {
        .positive_pattern = u"kecamatan",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types
        = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch, FormControlType::kTextArea },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[10]=*/
    MatchingPattern {
        .positive_pattern = u"bairro",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types
        = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch, FormControlType::kTextArea },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[11]=*/
    MatchingPattern {
        .positive_pattern = u"mahalle|k\u00f6y",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types
        = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch, FormControlType::kTextArea },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[12]=*/
    MatchingPattern {
        .positive_pattern = u"(haus.?|^)(nummer|nr)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[13]=*/
    MatchingPattern {
        .positive_pattern = u"(house.?|street.?|^)(number|no\\.?$)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[14]=*/
    MatchingPattern {
        .positive_pattern = u"exterior|(?:no|n[\u00fau]m(?:ero)?)\\.?\\s*ext",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[15]=*/
    MatchingPattern {
        .positive_pattern = u"civico",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[16]=*/
    MatchingPattern {
        .positive_pattern = u"(?:nr|numer)[.\\s]*(?:domu|budynku)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[17]=*/
    MatchingPattern {
        .positive_pattern = u"^\\*?.?n\u00famero(.?\\*?$| da resid\u00eancia)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[18]=*/
    MatchingPattern {
        .positive_pattern = u"\u0434\u043e\u043c|\u043d\u043e\u043c\u0435\u0440.?\u0434\u043e\u043c\u0430",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[19]=*/
    MatchingPattern {
        .positive_pattern = u"(?:domu|budynku)(?:[.,\\s/]|nr|numer)*(?:lokalu|mieszkani[ae])",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[20]=*/
    MatchingPattern {
        .positive_pattern = u"calle y n\u00famero",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[21]=*/
    MatchingPattern {
        .positive_pattern = u"stra(ss|\u00df)e",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[22]=*/
    MatchingPattern {
        .positive_pattern = u"street",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[23]=*/
    MatchingPattern {
        .positive_pattern = u"calle",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[24]=*/
    MatchingPattern {
        .positive_pattern = u"indirizzo|piazza",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[25]=*/
    MatchingPattern {
        .positive_pattern = u"ulica|ulicy",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[26]=*/
    MatchingPattern {
        .positive_pattern = u"rua|avenida|endere[\u00e7c]o|logradouro|direcci\u00f3n",
        .negative_pattern = u"(do |de )endere[\u00e7c]o",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[27]=*/
    MatchingPattern {
        .positive_pattern = u"\u0443\u043b\u0438\u0446\u0430|\u043d\u0430\u0437\u0432\u0430\u043d\u0438\u0435.?\u0443\u043b\u0438\u0446\u044b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[28]=*/
    MatchingPattern {
        .positive_pattern = u"strasse|stra\u00dfe",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[29]=*/
    MatchingPattern {
        .positive_pattern = u"^address$|address[_-]?line(one)?|address1|addr1|street|(?:shipping|billing)address$|house.?name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[30]=*/
    MatchingPattern {
        .positive_pattern
        = u"(^\\W*address)|(address\\W*$)|(?:shipping|billing|mailing|pick.?up|drop.?off|delivery|sender|postal|recipient|home|work|office|school|business|"
          u"mail)[\\s\\-]+address|address\\s+(of|for|to|from)|street.*(house|building|apartment|floor)|(house|building|apartment|floor).*street",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[31]=*/
    MatchingPattern {
        .positive_pattern = u"direccion|direcci\u00f3n",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[32]=*/
    MatchingPattern {
        .positive_pattern = u"adresse",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[33]=*/
    MatchingPattern {
        .positive_pattern = u"^alamat",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[34]=*/
    MatchingPattern {
        .positive_pattern = u"^alamat",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[35]=*/
    MatchingPattern {
        .positive_pattern = u"indirizzo",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[36]=*/
    MatchingPattern {
        .positive_pattern = u"^\u4f4f\u6240$|\u4f4f\u62401",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[37]=*/
    MatchingPattern {
        .positive_pattern = u"\u4f4f\u6240",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[38]=*/
    MatchingPattern {
        .positive_pattern = u"^\uc8fc\uc18c.?$|\uc8fc\uc18c.?1",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[39]=*/
    MatchingPattern {
        .positive_pattern = u"\uc8fc\uc18c",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[40]=*/
    MatchingPattern {
        .positive_pattern = u"morada|endere\u00e7o",
        .negative_pattern = u"(do |de )endere\u00e7o",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[41]=*/
    MatchingPattern {
        .positive_pattern = u"\u0410\u0434\u0440\u0435\u0441",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[42]=*/
    MatchingPattern {
        .positive_pattern = u"\u0443\u043b\u0438\u0446.*(\u0434\u043e\u043c|\u043a\u043e\u0440\u043f\u0443\u0441|\u043a\u0432\u0430\u0440\u0442\u0438\u0440|"
                            u"\u044d\u0442\u0430\u0436)|(\u0434\u043e\u043c|\u043a\u043e\u0440\u043f\u0443\u0441|\u043a\u0432\u0430\u0440\u0442\u0438\u0440|"
                            u"\u044d\u0442\u0430\u0436).*\u0443\u043b\u0438\u0446",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[43]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_)adres(\\b|_)",
        .negative_pattern = u"(\\b|_)adres tarifi(\\b|_)",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[44]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_)adres(\\b|_)|(sokak|cadde).*(apartman|bina|daire|mahalle)|(apartman|bina|daire|mahalle).*(sokak|cadde)",
        .negative_pattern = u"(\\b|_)adres tarifi(\\b|_)",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[45]=*/
    MatchingPattern {
        .positive_pattern = u"\u5730\u5740",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[46]=*/
    MatchingPattern {
        .positive_pattern = u"adresszusatz|erg\u00e4nzende.?angaben|adresszeile 2",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[47]=*/
    MatchingPattern {
        .positive_pattern = u"address[_-]?line(2|two)|address2|addr2|street|suite|unit",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[48]=*/
    MatchingPattern {
        .positive_pattern = u"address|line",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[49]=*/
    MatchingPattern {
        .positive_pattern = u"direcci[\u00f3o]n.*2|informaci[\u00f3o]n\\s*adicional|complemento.*direcci[\u00f3o]n",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[50]=*/
    MatchingPattern {
        .positive_pattern = u"addresssuppl|complementnom|appartement",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[51]=*/
    MatchingPattern {
        .positive_pattern = u"adresse",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[52]=*/
    MatchingPattern {
        .positive_pattern = u"indirizzo2",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[53]=*/
    MatchingPattern {
        .positive_pattern = u"indirizzo",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[54]=*/
    MatchingPattern {
        .positive_pattern = u"\u4f4f\u62402",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[55]=*/
    MatchingPattern {
        .positive_pattern = u"\uc8fc\uc18c.?2",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[56]=*/
    MatchingPattern {
        .positive_pattern = u"\uc8fc\uc18c",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[57]=*/
    MatchingPattern {
        .positive_pattern = u"complemento|addrcomplement",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[58]=*/
    MatchingPattern {
        .positive_pattern = u"\u0423\u043b\u0438\u0446\u0430",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[59]=*/
    MatchingPattern {
        .positive_pattern = u"\u5730\u57402",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[60]=*/
    MatchingPattern {
        .positive_pattern = u"\u5730\u5740",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[61]=*/
    MatchingPattern {
        .positive_pattern = u"address.*line[3-9]|address[3-9]|addr[3-9]|street|line[3-9]",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[62]=*/
    MatchingPattern {
        .positive_pattern = u"batiment|residence",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[63]=*/
    MatchingPattern {
        .positive_pattern = u"indirizzo[3-9]",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[64]=*/
    MatchingPattern {
        .positive_pattern = u"lookup",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[65]=*/
    MatchingPattern {
        .positive_pattern = u"(?:address|location).*(?:nickname|label|type)",
        .negative_pattern = u"e.?mail|re.?type|typed",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[66]=*/
    MatchingPattern {
        .positive_pattern = u"(?:alias|identificador|nombre).*direcci\u00f3n",
        .negative_pattern = u"e.?mail|correo|apellido|nombres",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[67]=*/
    MatchingPattern {
        .positive_pattern = u"(?:label|judul|nama) alamat",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[68]=*/
    MatchingPattern {
        .positive_pattern = u"(?:tipo|nome|apelido|identifica\u00e7\u00e3o|t\u00edtulo).*(?:endere\u00e7o|local da entrega)",
        .negative_pattern = u"e.?mail|eletr\u00f3nico|usu\u00e1rio|nomes",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[69]=*/
    MatchingPattern {
        .positive_pattern = u"adres (?:[\u0130i]sim|ba\u015fl\u0131\u011f\u0131|ad\u0131)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[70]=*/
    MatchingPattern {
        .positive_pattern = u"municipio|delegaci[o\u00f3]n",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types
        = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch, FormControlType::kSelectOne },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[71]=*/
    MatchingPattern {
        .positive_pattern = u"munic\u00edpio",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types
        = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch, FormControlType::kSelectOne },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[72]=*/
    MatchingPattern {
        .positive_pattern = u"family-phonetic-name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[73]=*/
    MatchingPattern {
        .positive_pattern = u"full-phonetic-name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[74]=*/
    MatchingPattern {
        .positive_pattern = u"given-phonetic-name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[75]=*/
    MatchingPattern {
        .positive_pattern = u"attention|attn",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[76]=*/
    MatchingPattern {
        .positive_pattern = u"^[^0-9+]*(?:\\+|00)\\s*([1-9]\\d{0,3})\\D*$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[77]=*/
    MatchingPattern {
        .positive_pattern = u"(cross|between).*street",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[78]=*/
    MatchingPattern {
        .positive_pattern = u"entre.*calles",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[79]=*/
    MatchingPattern {
        .positive_pattern = u"entre.*calle(.*1)?",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[80]=*/
    MatchingPattern {
        .positive_pattern = u"entre.*calle(.*2)?|y.*calle",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[81]=*/
    MatchingPattern {
        .positive_pattern = u"(cross|between).*street.*landmark|landmark.*(cross|between).*street",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[82]=*/
    MatchingPattern {
        .positive_pattern = u"entre.*calle.*referencia|referencia.*entre.*calle",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[83]=*/
    MatchingPattern {
        .positive_pattern = u"\\bort\\b|stadt",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[84]=*/
    MatchingPattern {
        .positive_pattern = u"city|town|suburb",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[85]=*/
    MatchingPattern {
        .positive_pattern = u"ciudad|localidad|poblacion",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[86]=*/
    MatchingPattern {
        .positive_pattern = u"\u0634\u0647\u0631",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[87]=*/
    MatchingPattern {
        .positive_pattern = u"ville|commune",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[88]=*/
    MatchingPattern {
        .positive_pattern = u"\u0936\u0939\u0930|\u0917\u094d\u0930\u093e\u092e|\u0917\u093e\u0901\u0935",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[89]=*/
    MatchingPattern {
        .positive_pattern = u"kota|kabupaten",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[90]=*/
    MatchingPattern {
        .positive_pattern = u"citt[\u00e0a]\\b|localita",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[91]=*/
    MatchingPattern {
        .positive_pattern = u"\u5e02\u533a\u753a\u6751",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[92]=*/
    MatchingPattern {
        .positive_pattern = u"^\uc2dc[^\ub3c4\u00b7\u30fb]|\uc2dc[\u00b7\u30fb]?\uad70[\u00b7\u30fb]?\uad6c",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[93]=*/
    MatchingPattern {
        .positive_pattern = u"\u0d28\u0d17\u0d30\u0d02|\u0d17\u0d4d\u0d30\u0d3e\u0d2e\u0d02",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[94]=*/
    MatchingPattern {
        .positive_pattern = u"miasto|miejscowo\u015b\u0107",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[95]=*/
    MatchingPattern {
        .positive_pattern = u"cidade",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[96]=*/
    MatchingPattern {
        .positive_pattern
        = u"\u0413\u043e\u0440\u043e\u0434|\u041d\u0430\u0441\u0435\u043b(\u0435|\u0451)\u043d\u043d\u044b\u0439.?\u043f\u0443\u043d\u043a\u0442",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[97]=*/
    MatchingPattern {
        .positive_pattern = u"((\\b|_|\\*)([\u0130ii\u0307]l[c\u00e7]e(miz|niz)?)(\\b|_|\\*))",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[98]=*/
    MatchingPattern {
        .positive_pattern = u"\u5e02|\u5206\u5340",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[99]=*/
    MatchingPattern {
        .positive_pattern = u"firma|firmenname",
        .negative_pattern = u"confirma",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[100]=*/
    MatchingPattern {
        .positive_pattern = u"company|business|organization|organisation",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[101]=*/
    MatchingPattern {
        .positive_pattern = u"empresa",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[102]=*/
    MatchingPattern {
        .positive_pattern = u"\u0634\u0631\u06a9\u062a",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[103]=*/
    MatchingPattern {
        .positive_pattern = u"societe|soci\u00e9t\u00e9",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[104]=*/
    MatchingPattern {
        .positive_pattern = u"(nama.?)?perusahaan",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[105]=*/
    MatchingPattern {
        .positive_pattern = u"ragione.?sociale",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[106]=*/
    MatchingPattern {
        .positive_pattern = u"\u4f1a\u793e",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[107]=*/
    MatchingPattern {
        .positive_pattern = u"\ud68c\uc0ac|\uc9c1\uc7a5",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[108]=*/
    MatchingPattern {
        .positive_pattern = u"\u043d\u0430\u0437\u0432\u0430\u043d\u0438\u0435.?\u043a\u043e\u043c\u043f\u0430\u043d\u0438\u0438",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[109]=*/
    MatchingPattern {
        .positive_pattern = u"\u5355\u4f4d|\u516c\u53f8",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[110]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_)land(\\b|_)",
        .negative_pattern = u"(\\b|_)land(\\b|_).*mark.*",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[111]=*/
    MatchingPattern {
        .positive_pattern = u"country|countries",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[112]=*/
    MatchingPattern {
        .positive_pattern = u"pa\u00eds|pais",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[113]=*/
    MatchingPattern {
        .positive_pattern = u"\u06a9\u0634\u0648\u0631",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[114]=*/
    MatchingPattern {
        .positive_pattern = u"\\bpays\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[115]=*/
    MatchingPattern {
        .positive_pattern = u"negara",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[116]=*/
    MatchingPattern {
        .positive_pattern = u"\\bpaese\\b|\\bnazione\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[117]=*/
    MatchingPattern {
        .positive_pattern = u"\u56fd",
        .negative_pattern = u"(\u5165|\u51fa)\u56fd",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[118]=*/
    MatchingPattern {
        .positive_pattern = u"\uad6d\uac00|\ub098\ub77c",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[119]=*/
    MatchingPattern {
        .positive_pattern = u"(?<!o)kraj|pa[n\u0144]stwo",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[120]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_)(\u00fclke|ulce|ulke)(\\b|_)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[121]=*/
    MatchingPattern {
        .positive_pattern = u"\u56fd\u5bb6",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[122]=*/
    MatchingPattern {
        .positive_pattern = u"location",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[123]=*/
    MatchingPattern {
        .positive_pattern = u"gueltig|g\u00fcltig",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[124]=*/
    MatchingPattern {
        .positive_pattern = u"expir|exp.*date|^expfield$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[125]=*/
    MatchingPattern {
        .positive_pattern = u"fecha",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[126]=*/
    MatchingPattern {
        .positive_pattern = u"date.*exp",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[127]=*/
    MatchingPattern {
        .positive_pattern = u"scadenza",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[128]=*/
    MatchingPattern {
        .positive_pattern = u"\u6709\u52b9\u671f\u9650",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[129]=*/
    MatchingPattern {
        .positive_pattern = u"validade",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[130]=*/
    MatchingPattern {
        .positive_pattern = u"\u0421\u0440\u043e\u043a \u0434\u0435\u0439\u0441\u0442\u0432\u0438\u044f \u043a\u0430\u0440\u0442\u044b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[131]=*/
    MatchingPattern {
        .positive_pattern = u"(?:exp.*date[^y\\n\\r]*|mm\\s*[-/]?\\s*)(?:yy(?!y)|aa(?!a)|jj(?!j))",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[132]=*/
    MatchingPattern {
        .positive_pattern = u"(?:exp.*date[^y\\n\\r]*|mm\\s*[-/]?\\s*)(?:yyyy(?!y)|aaaa(?!a)|jjjj(?!j))",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[133]=*/
    MatchingPattern {
        .positive_pattern = u"gueltig|g\u00fcltig|monat",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[134]=*/
    MatchingPattern {
        .positive_pattern = u"expir|exp.*mo|exp.*date|cc.?month|cardmonth|addmonth",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[135]=*/
    MatchingPattern {
        .positive_pattern = u"masa berlaku|berlaku hingga",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[136]=*/
    MatchingPattern {
        .positive_pattern = u"validade|\\bm\u00eas\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[137]=*/
    MatchingPattern {
        .positive_pattern = u"\u6708",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[138]=*/
    MatchingPattern {
        .positive_pattern = u"^mm$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[139]=*/
    MatchingPattern {
        .positive_pattern = u"ablaufdatum|gueltig|g\u00fcltig|jahr",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[140]=*/
    MatchingPattern {
        .positive_pattern = u"exp|^/|year",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[141]=*/
    MatchingPattern {
        .positive_pattern = u"fecha|a\u00f1o",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[142]=*/
    MatchingPattern {
        .positive_pattern = u"validade|\\bano\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[143]=*/
    MatchingPattern {
        .positive_pattern = u"\u5e74|\u6709\u6548\u671f",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[144]=*/
    MatchingPattern {
        .positive_pattern = u"^(yy|yyyy)$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[145]=*/
    MatchingPattern {
        .positive_pattern = u"^(yy|yyyy|aa|aaaa|jj|jjjj)$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[146]=*/
    MatchingPattern {
        .positive_pattern = u"nummer",
        .negative_pattern = u"telefon|telefoon|haus|person|f\u00f8dsels|kunden|post|mobil|mobiel|handy|produkt|sendungs|verfolgungs|artikel|konto",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[147]=*/
    MatchingPattern {
        .positive_pattern = u"karten.?nr",
        .negative_pattern = u"sim|kunden|geschenk|freundschafts|benachrichtigungs|service|personal|more|leistungs",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[148]=*/
    MatchingPattern {
        .positive_pattern = u"(?:card|cc|acct).?(?:number|#|no|num|field(?!s)|pan)|0000 ?0000 ?0000 ?0000|1234 ?1234 ?1234 ?1234|^xxxx ?xxxx ?xxxx ?xxxx$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[149]=*/
    MatchingPattern {
        .positive_pattern = u"(numero|n\u00famero|num\u00e9ro)",
        .negative_pattern = u"(numero|n\u00famero|num\u00e9ro).*(document|fono|phone|r\u00e9servation)",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[150]=*/
    MatchingPattern {
        .positive_pattern = u"no.*kartu",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[151]=*/
    MatchingPattern {
        .positive_pattern = u"\u30ab\u30fc\u30c9\u756a\u53f7",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[152]=*/
    MatchingPattern {
        .positive_pattern = u"\uce74\ub4dc",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[153]=*/
    MatchingPattern {
        .positive_pattern = u"\u041d\u043e\u043c\u0435\u0440.*\u043a\u0430\u0440\u0442\u044b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[154]=*/
    MatchingPattern {
        .positive_pattern = u"\u4fe1\u7528\u5361\u53f7|\u4fe1\u7528\u5361\u53f7\u7801",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[155]=*/
    MatchingPattern {
        .positive_pattern = u"\u4fe1\u7528\u5361\u5361\u865f",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[156]=*/
    MatchingPattern {
        .positive_pattern = u"c\u00f3digo de seguran\u00e7a",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[157]=*/
    MatchingPattern {
        .positive_pattern = u"karten.?pr\u00fcfn",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[158]=*/
    MatchingPattern {
        .positive_pattern = u"verification|card.?identification|security.?code|card.?code|security.?value|security.?number|card.?pin|c-v-v|(?:cvn|cvv|cvc|csc|"
                            u"cvd|ccv)|\\bcid\\b|cccid",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[159]=*/
    MatchingPattern {
        .positive_pattern = u"c\u00f3digo de seguridad",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputPassword,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[160]=*/
    MatchingPattern {
        .positive_pattern = u"day",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[161]=*/
    MatchingPattern {
        .positive_pattern = u"debit.*card",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber,
            FormControlType::kInputSearch, FormControlType::kInputPassword },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[162]=*/
    MatchingPattern {
        .positive_pattern = u"(?:visa|mastercard|discover|amex|american express).*gift.?card",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber,
            FormControlType::kInputSearch, FormControlType::kInputPassword },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[163]=*/
    MatchingPattern {
        .positive_pattern = u"e.?mail",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[164]=*/
    MatchingPattern {
        .positive_pattern = u"correo.*electr(o|\u00f3)nico",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[165]=*/
    MatchingPattern {
        .positive_pattern = u"\u0627\u06cc\u0645\u06cc\u0644|\u067e\u0633\u062a.*\u0627\u0644\u06a9\u062a\u0631\u0648\u0646\u06cc\u06a9",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[166]=*/
    MatchingPattern {
        .positive_pattern = u"courriel",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[167]=*/
    MatchingPattern {
        .positive_pattern = u"\u0908\u092e\u0947\u0932|\u0907\u0932\u0945\u0915\u094d\u091f\u094d\u0930\u0949\u0928\u093f\u0915.?\u092e\u0947\u0932",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[168]=*/
    MatchingPattern {
        .positive_pattern = u"\u30e1\u30fc\u30eb\u30a2\u30c9\u30ec\u30b9",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[169]=*/
    MatchingPattern {
        .positive_pattern = u"(?:\uc774\uba54\uc77c|\uc804\uc790.?\uc6b0\ud3b8|[Ee]-?mail)(.?\uc8fc\uc18c)?",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[170]=*/
    MatchingPattern {
        .positive_pattern = u"\u0d07-\u0d2e\u0d46\u0d2f\u0d3f\u0d32\u0d4d\u200d|\u0d07\u0d32\u0d15\u0d4d\u0d1f\u0d4d\u0d30\u0d4b\u0d23\u0d3f\u0d15\u0d4d.?"
                            u"\u0d2e\u0d46\u0d2f\u0d3f\u0d7d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[171]=*/
    MatchingPattern {
        .positive_pattern = u"\u042d\u043b\u0435\u043a\u0442\u0440\u043e\u043d\u043d(\u0430\u044f|\u043e\u0439).?\u041f\u043e\u0447\u0442(\u0430|\u044b)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[172]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_)eposta(\\b|_)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[173]=*/
    MatchingPattern {
        .positive_pattern = u"\u90ae\u4ef6|\u90ae\u7bb1|\u96fb\u5b50\u90f5\u4ef6",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[174]=*/
    MatchingPattern {
        .positive_pattern = u"\u96fb\u90f5\u5730\u5740|\u96fb\u5b50\u4fe1\u7bb1",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputEmail },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[175]=*/
    MatchingPattern {
        .positive_pattern = u"vorname",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[176]=*/
    MatchingPattern {
        .positive_pattern = u"first.*name|initials|fname|first$|given.*name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[177]=*/
    MatchingPattern {
        .positive_pattern = u"nombre",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[178]=*/
    MatchingPattern {
        .positive_pattern = u"\u0646\u0627\u0645",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[179]=*/
    MatchingPattern {
        .positive_pattern = u"forename|pr\u00e9nom|prenom",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[180]=*/
    MatchingPattern {
        .positive_pattern = u"\u0928\u093e\u092e",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[181]=*/
    MatchingPattern {
        .positive_pattern = u"nama depan",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[182]=*/
    MatchingPattern {
        .positive_pattern = u"\u540d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[183]=*/
    MatchingPattern {
        .positive_pattern = u"\uc774\ub984",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[184]=*/
    MatchingPattern {
        .positive_pattern = u"\u0d2a\u0d47\u0d30\u0d4d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[185]=*/
    MatchingPattern {
        .positive_pattern = u"nome",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[186]=*/
    MatchingPattern {
        .positive_pattern = u"\u0418\u043c\u044f",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[187]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_|\\*)(isim|ad|ad(i|\u0131|iniz|\u0131n\u0131z)?)(\\b|_|\\*)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[188]=*/
    MatchingPattern {
        .positive_pattern = u"airline|flight",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[189]=*/
    MatchingPattern {
        .positive_pattern = u"aerol(i|\u00ed)nea|n(u|\u00fa)mero.*vuelo",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[190]=*/
    MatchingPattern {
        .positive_pattern = u"\u4fbf\u540d|\u822a\u7a7a\u4f1a\u793e",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[191]=*/
    MatchingPattern {
        .positive_pattern = u"vollst\u00e4ndiger.?name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[192]=*/
    MatchingPattern {
        .positive_pattern
        = u"^name|full.?name|your.?name|customer.?name|bill.?name|ship.?name|name.*first.*last|firstandlastname|contact.?(name|person)|receiver",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[193]=*/
    MatchingPattern {
        .positive_pattern = u"nombre.*y.*apellidos",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[194]=*/
    MatchingPattern {
        .positive_pattern = u"\u0646\u0627\u0645.*\u0646\u0627\u0645.*\u062e\u0627\u0646\u0648\u0627\u062f\u06af\u06cc",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[195]=*/
    MatchingPattern {
        .positive_pattern = u"^nom",
        .negative_pattern = u"^nom[a-zA-Z]",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[196]=*/
    MatchingPattern {
        .positive_pattern = u"nama.?(lengkap|penerima|kamu)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[197]=*/
    MatchingPattern {
        .positive_pattern = u"\u304a\u540d\u524d|\u6c0f\u540d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[198]=*/
    MatchingPattern {
        .positive_pattern = u"\uc131\uba85",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[199]=*/
    MatchingPattern {
        .positive_pattern = u"^nome",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[200]=*/
    MatchingPattern {
        .positive_pattern = u"\u043a\u043e\u043d\u0442\u0430\u043a\u0442\u043d\u043e\u0435.?\u043b\u0438\u0446\u043e",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[201]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_|\\*)ad[\u0131]? soyad[\u0131]?(\\b|_|\\*)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[202]=*/
    MatchingPattern {
        .positive_pattern = u"\u59d3\\s*\u540d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[203]=*/
    MatchingPattern {
        .positive_pattern = u"gift.?(card|cert)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber,
            FormControlType::kInputSearch, FormControlType::kInputPassword },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[204]=*/
    MatchingPattern {
        .positive_pattern = u"anrede|titel",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[205]=*/
    MatchingPattern {
        .positive_pattern = u"\u03c0\u03c1\u03bf\u03c3\u03c6\u03ce\u03bd\u03b7\u03c3\u03b7",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[206]=*/
    MatchingPattern {
        .positive_pattern = u"^title:?$|salutation",
        .negative_pattern = u"salutation and given name",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[207]=*/
    MatchingPattern {
        .positive_pattern = u"tratamiento|encabezamiento",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[208]=*/
    MatchingPattern {
        .positive_pattern = u"titre",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[209]=*/
    MatchingPattern {
        .positive_pattern = u"titolo",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[210]=*/
    MatchingPattern {
        .positive_pattern = u"\u043e\u0431\u0440\u0430\u0449\u0435\u043d\u0438\u0435|\u0437\u0432\u0430\u043d\u0438\u0435",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[211]=*/
    MatchingPattern {
        .positive_pattern = u"hitap",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[212]=*/
    MatchingPattern {
        .positive_pattern = u"(\\biban(\\b|_)|international bank account number)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[213]=*/
    MatchingPattern {
        .positive_pattern = u"area|locality|street|colony|sector|town|village",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[214]=*/
    MatchingPattern {
        .positive_pattern = u"house.?no|building|flat|apartment",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[215]=*/
    MatchingPattern {
        .positive_pattern = u"landmark",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[216]=*/
    MatchingPattern {
        .positive_pattern = u"ref[\u00eae]r[\u00eae]ncia",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[217]=*/
    MatchingPattern {
        .positive_pattern = u"nachname",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[218]=*/
    MatchingPattern {
        .positive_pattern = u"last.*name|lname|surname|last$|secondname|family.*name",
        .negative_pattern = u"surname\\d",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[219]=*/
    MatchingPattern {
        .positive_pattern = u"apellidos?",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[220]=*/
    MatchingPattern {
        .positive_pattern = u"\u0646\u0627\u0645.*\u062e\u0627\u0646\u0648\u0627\u062f\u06af\u06cc",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[221]=*/
    MatchingPattern {
        .positive_pattern = u"famille|^nom",
        .negative_pattern = u"^nom[a-zA-Z]",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[222]=*/
    MatchingPattern {
        .positive_pattern = u"\u0909\u092a\u0928\u093e\u092e",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[223]=*/
    MatchingPattern {
        .positive_pattern = u"nama belakang",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[224]=*/
    MatchingPattern {
        .positive_pattern = u"cognome",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[225]=*/
    MatchingPattern {
        .positive_pattern = u"\u59d3",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[226]=*/
    MatchingPattern {
        .positive_pattern = u"\\b\uc131(?:[^\uba85]|\\b)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[227]=*/
    MatchingPattern {
        .positive_pattern = u"\u0d2e\u0d31\u0d41\u0d2a\u0d47\u0d30\u0d4d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[228]=*/
    MatchingPattern {
        .positive_pattern = u"apelidos|surename|sobrenome",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[229]=*/
    MatchingPattern {
        .positive_pattern = u"\u0424\u0430\u043c\u0438\u043b\u0438\u044f",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[230]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_|\\*)(soyisim|soyad(i|\u0131|iniz|\u0131n\u0131z)?)(\\b|_|\\*)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[231]=*/
    MatchingPattern {
        .positive_pattern = u"(primer.*apellido)|(apellido1)|(apellido.*paterno)|surname_?1|first(\\s|_)?surname",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[232]=*/
    MatchingPattern {
        .positive_pattern = u"(segund.*apellido)|(apellido2)|(apellido.*materno)|surname_?2|second(\\s|_)?surname",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[233]=*/
    MatchingPattern {
        .positive_pattern = u"(promo(tion|tional)?|gift|discount|coupon)[-_. ]*code",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[234]=*/
    MatchingPattern {
        .positive_pattern = u"middle.*initial|m\\.i\\.|mi$|\\bmi\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[235]=*/
    MatchingPattern {
        .positive_pattern = u"middle.*name|mname|middle$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[236]=*/
    MatchingPattern {
        .positive_pattern = u"^name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[237]=*/
    MatchingPattern {
        .positive_pattern = u"^nom",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[238]=*/
    MatchingPattern {
        .positive_pattern = u"user.?name|user.?id|nickname|maiden name|title|prefix|suffix|mail",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[239]=*/
    MatchingPattern {
        .positive_pattern = u"(?:\uc0ac\uc6a9\uc790.?)?\uc544\uc774\ub514|\uc0ac\uc6a9\uc790.?ID",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[240]=*/
    MatchingPattern {
        .positive_pattern = u"\u7528\u6237\u540d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[241]=*/
    MatchingPattern {
        .positive_pattern = u"karteninhaber",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[242]=*/
    MatchingPattern {
        .positive_pattern = u"card.?(?:holder|owner)|name.*on.*card|(?:card|cc).?name|cc.?full.?name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[243]=*/
    MatchingPattern {
        .positive_pattern = u"nombre.*tarjeta|nombre.*titular|titular.*tarjeta",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[244]=*/
    MatchingPattern {
        .positive_pattern = u"nom.*carte",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[245]=*/
    MatchingPattern {
        .positive_pattern = u"nama.*kartu",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[246]=*/
    MatchingPattern {
        .positive_pattern = u"nome.*cart",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[247]=*/
    MatchingPattern {
        .positive_pattern = u"\u540d\u524d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[248]=*/
    MatchingPattern {
        .positive_pattern = u"nome do titular|nome impresso no cart\u00e3o|titular do cart\u00e3o",
        .negative_pattern = u"do titular do cart\u00e3o",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[249]=*/
    MatchingPattern {
        .positive_pattern = u"\u0418\u043c\u044f.*\u043a\u0430\u0440\u0442\u044b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[250]=*/
    MatchingPattern {
        .positive_pattern = u"\u4fe1\u7528\u5361\u5f00\u6237\u540d|\u5f00\u6237\u540d|\u6301\u5361\u4eba\u59d3\u540d|\u6301\u5361\u4eba\u59d3\u540d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[251]=*/
    MatchingPattern {
        .positive_pattern = u"name",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[252]=*/
    MatchingPattern {
        .positive_pattern = u"size|height|quantity|length|amount",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kTextArea,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[253]=*/
    MatchingPattern {
        .positive_pattern = u"adresszusatz",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[254]=*/
    MatchingPattern {
        .positive_pattern = u"compl[e\u00e9]ment[\\s]*d[\\'\\\u2019]adresse",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[255]=*/
    MatchingPattern {
        .positive_pattern = u"indirizzo[.\\s]*aggiuntivo",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[256]=*/
    MatchingPattern {
        .positive_pattern = u"complemento|informa\u00e7\u00f5es adicionais",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[257]=*/
    MatchingPattern {
        .positive_pattern = u"complement and reference",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[258]=*/
    MatchingPattern {
        .positive_pattern = u"complemento e.*refer\u00eancia|complement and reference",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[259]=*/
    MatchingPattern {
        .positive_pattern = u"document.*number|passport",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[260]=*/
    MatchingPattern {
        .positive_pattern = u"numero.*documento|pasaporte",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[261]=*/
    MatchingPattern {
        .positive_pattern = u"passeport",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[262]=*/
    MatchingPattern {
        .positive_pattern = u"\u66f8\u985e",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[263]=*/
    MatchingPattern {
        .positive_pattern = u"legacy",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> {},
        .form_control_types = DenseSet<FormControlType> {},
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[264]=*/
    MatchingPattern {
        .positive_pattern = u"telefonnummer",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[265]=*/
    MatchingPattern {
        .positive_pattern = u"phone|mobile|contact.?number",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[266]=*/
    MatchingPattern {
        .positive_pattern = u"telefono|tel\u00e9fono",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[267]=*/
    MatchingPattern {
        .positive_pattern = u"telfixe",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[268]=*/
    MatchingPattern {
        .positive_pattern = u"\u092e\u094b\u092c\u093e\u0907\u0932",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[269]=*/
    MatchingPattern {
        .positive_pattern = u"telepon|ponsel|(nomor|no\\.?).?(hp|handphone)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[270]=*/
    MatchingPattern {
        .positive_pattern = u"\u96fb\u8a71",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[271]=*/
    MatchingPattern {
        .positive_pattern = u"(?:\uc804\ud654|\ud578\ub4dc\ud3f0|\ud734\ub300\ud3f0|\ud734\ub300\uc804\ud654)(?:.?\ubc88\ud638)?",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[272]=*/
    MatchingPattern {
        .positive_pattern = u"\u0d2e\u0d4a\u0d2c\u0d48\u0d32\u0d4d\u200d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[273]=*/
    MatchingPattern {
        .positive_pattern = u"telefone|telemovel",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[274]=*/
    MatchingPattern {
        .positive_pattern = u"\u0442\u0435\u043b\u0435\u0444\u043e\u043d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[275]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_|\\*)telefon(\\b|_|\\*)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[276]=*/
    MatchingPattern {
        .positive_pattern = u"\u7535\u8bdd",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[277]=*/
    MatchingPattern {
        .positive_pattern = u"area.*code|acode|area|^\\($",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[278]=*/
    MatchingPattern {
        .positive_pattern = u"\uc9c0\uc5ed.?\ubc88\ud638",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[279]=*/
    MatchingPattern {
        .positive_pattern = u"^\\($",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[280]=*/
    MatchingPattern {
        .positive_pattern = u"country.*code|ccode|_cc|phone.*code|user.*phone.*code",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kSelectOne,
            FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[281]=*/
    MatchingPattern {
        .positive_pattern = u"\\bext|ext\\b|extension",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[282]=*/
    MatchingPattern {
        .positive_pattern = u"ramal",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[283]=*/
    MatchingPattern {
        .positive_pattern = u"prefix|exchange",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[284]=*/
    MatchingPattern {
        .positive_pattern = u"preselection",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[285]=*/
    MatchingPattern {
        .positive_pattern = u"ddd",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[286]=*/
    MatchingPattern {
        .positive_pattern = u"^-$|^\\)$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[287]=*/
    MatchingPattern {
        .positive_pattern = u"suffix",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[288]=*/
    MatchingPattern {
        .positive_pattern = u"^-$",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[289]=*/
    MatchingPattern {
        .positive_pattern = u"\u0642\u06cc\u0645\u0629\u200e|\u0633\u0639\u0631\u200e",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kTextArea,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[290]=*/
    MatchingPattern {
        .positive_pattern = u"\\bprice\\b|\\brate\\b|\\bcost\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kTextArea,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[291]=*/
    MatchingPattern {
        .positive_pattern = u"\u0642\u06cc\u0645\u062a",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kTextArea,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[292]=*/
    MatchingPattern {
        .positive_pattern = u"\\bprix\\b|\\bco\u00fbt\\b|\\bcout\\b|\\btarif\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kTextArea,
            FormControlType::kInputNumber, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[293]=*/
    MatchingPattern {
        .positive_pattern = u"province|region|other",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[294]=*/
    MatchingPattern {
        .positive_pattern = u"provincia",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[295]=*/
    MatchingPattern {
        .positive_pattern = u"bairro|suburb",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[296]=*/
    MatchingPattern {
        .positive_pattern = u"suche.*",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[297]=*/
    MatchingPattern {
        .positive_pattern = u"^q$|search|query|qry",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[298]=*/
    MatchingPattern {
        .positive_pattern = u"\u062c\u0633\u062a\u062c\u0648",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[299]=*/
    MatchingPattern {
        .positive_pattern = u"recherch.*",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[300]=*/
    MatchingPattern {
        .positive_pattern = u"\u63a2\u3059|\u691c\u7d22",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[301]=*/
    MatchingPattern {
        .positive_pattern = u"busca",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[302]=*/
    MatchingPattern {
        .positive_pattern = u"\u0438\u0441\u043a\u0430\u0442\u044c|\u043d\u0430\u0439\u0442\u0438|\u043f\u043e\u0438\u0441\u043a",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[303]=*/
    MatchingPattern {
        .positive_pattern = u"\u641c\u7d22",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kTextArea, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[304]=*/
    MatchingPattern {
        .positive_pattern = u"(?<!(united|hist|history).?)state|region|province|county|principality",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[305]=*/
    MatchingPattern {
        .positive_pattern = u"\u0627\u0633\u062a\u0627\u0646",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[306]=*/
    MatchingPattern {
        .positive_pattern = u"\u0930\u093e\u091c\u094d\u092f",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[307]=*/
    MatchingPattern {
        .positive_pattern = u"provinsi|propinsi",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[308]=*/
    MatchingPattern {
        .positive_pattern = u"\u90fd\u9053\u5e9c\u770c",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[309]=*/
    MatchingPattern {
        .positive_pattern = u"^\uc2dc[\u00b7\u30fb]?\ub3c4",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[310]=*/
    MatchingPattern {
        .positive_pattern = u"\u0d38\u0d02\u0d38\u0d4d\u0d25\u0d3e\u0d28\u0d02",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[311]=*/
    MatchingPattern {
        .positive_pattern = u"estado|provincia",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[312]=*/
    MatchingPattern {
        .positive_pattern = u"\u043e\u0431\u043b\u0430\u0441\u0442\u044c",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[313]=*/
    MatchingPattern {
        .positive_pattern = u"((\\b|_|\\*)(eyalet|[\u015fs]ehir|[\u0130ii\u0307]l(imiz)?|kent)(\\b|_|\\*))",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[314]=*/
    MatchingPattern {
        .positive_pattern = u"\u7701|\u5730\u5340",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kSelectOne, FormControlType::kInputSearch },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[315]=*/
    MatchingPattern {
        .positive_pattern = u"departure",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[316]=*/
    MatchingPattern {
        .positive_pattern = u"fecha.*salida|destino",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[317]=*/
    MatchingPattern {
        .positive_pattern = u"\u51fa\u56fd",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[318]=*/
    MatchingPattern {
        .positive_pattern = u"point.*of.*entry|arrival",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[319]=*/
    MatchingPattern {
        .positive_pattern = u"punto.*internaci(o|\u00f3)n|fecha.*llegada",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[320]=*/
    MatchingPattern {
        .positive_pattern = u"\u5165\u56fd",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[321]=*/
    MatchingPattern {
        .positive_pattern = u"zip|^-$|post2",
        .negative_pattern = u"\\.zip",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[322]=*/
    MatchingPattern {
        .positive_pattern = u"codpos2",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[323]=*/
    MatchingPattern {
        .positive_pattern = u"postleitzahl|\\bplz\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[324]=*/
    MatchingPattern {
        .positive_pattern = u"(?<!\\.)zip|postal|post.*code|pcode|pin.?code",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[325]=*/
    MatchingPattern {
        .positive_pattern = u"\\bcp\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[326]=*/
    MatchingPattern {
        .positive_pattern = u"\\bcdp\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[327]=*/
    MatchingPattern {
        .positive_pattern = u"\u092a\u093f\u0928.?\u0915\u094b\u0921",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[328]=*/
    MatchingPattern {
        .positive_pattern = u"kode.?pos",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[329]=*/
    MatchingPattern {
        .positive_pattern = u"\\bcap\\b",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[330]=*/
    MatchingPattern {
        .positive_pattern = u"\u90f5\u4fbf\u756a\u53f7",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[331]=*/
    MatchingPattern {
        .positive_pattern = u"\uc6b0\ud3b8.?\ubc88\ud638",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[332]=*/
    MatchingPattern {
        .positive_pattern = u"\u0d2a\u0d3f\u0d28\u0d4d\u200d\u0d15\u0d4b\u0d21\u0d4d",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[333]=*/
    MatchingPattern {
        .positive_pattern = u"kod.?pocztowy",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[334]=*/
    MatchingPattern {
        .positive_pattern = u"codigo|codpos|\\bcep\\b",
        .negative_pattern = u"codigo.*segur",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[335]=*/
    MatchingPattern {
        .positive_pattern = u"\u041f\u043e\u0447\u0442\u043e\u0432\u044b\u0439.?\u0418\u043d\u0434\u0435\u043a\u0441",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[336]=*/
    MatchingPattern {
        .positive_pattern = u"(\\b|_)posta kodu(\\b|_)",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[337]=*/
    MatchingPattern {
        .positive_pattern = u"\u90ae\u653f\u7f16\u7801|\u90ae\u7f16",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
    /*[338]=*/
    MatchingPattern {
        .positive_pattern = u"\u90f5\u905e\u5340\u865f",
        .negative_pattern = u"",
        .match_field_attributes = DenseSet<MatchAttribute> { MatchAttribute::kLabel, MatchAttribute::kName },
        .form_control_types = DenseSet<FormControlType> { FormControlType::kInputText, FormControlType::kInputTelephone, FormControlType::kInputNumber },
        .feature = OptionalRegexFeatureWithState(),
    },
});

// The patterns for field types and languages.
// They are sorted by the patterns MatchingPattern::positive_score.
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_APT_NUM[] { MakeMatchPatternRef(false, 0), MakeMatchPatternRef(false, 1), MakeMatchPatternRef(false, 2),
    MakeMatchPatternRef(false, 3), MakeMatchPatternRef(false, 4), MakeMatchPatternRef(false, 5), MakeMatchPatternRef(false, 6) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_APT_NUM__de[] { MakeMatchPatternRef(false, 0), MakeMatchPatternRef(true, 1) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_APT_NUM__en[] { MakeMatchPatternRef(false, 1) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_APT_NUM__es[] { MakeMatchPatternRef(true, 1), MakeMatchPatternRef(false, 2) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_APT_NUM__fr[] { MakeMatchPatternRef(true, 1), MakeMatchPatternRef(false, 3) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_APT_NUM__it[] { MakeMatchPatternRef(true, 1), MakeMatchPatternRef(false, 4) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_APT_NUM__pl[] { MakeMatchPatternRef(true, 1), MakeMatchPatternRef(false, 5) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_APT_NUM__ru[] { MakeMatchPatternRef(true, 1), MakeMatchPatternRef(false, 6) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY[] { MakeMatchPatternRef(false, 7), MakeMatchPatternRef(false, 8),
    MakeMatchPatternRef(false, 9), MakeMatchPatternRef(false, 10), MakeMatchPatternRef(false, 11) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__en[] { MakeMatchPatternRef(false, 7) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__es[] { MakeMatchPatternRef(true, 7), MakeMatchPatternRef(false, 8) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__id[] { MakeMatchPatternRef(true, 7), MakeMatchPatternRef(false, 9) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__pt[] { MakeMatchPatternRef(true, 7), MakeMatchPatternRef(false, 10) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__tr[] { MakeMatchPatternRef(true, 7), MakeMatchPatternRef(false, 11) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER[] { MakeMatchPatternRef(false, 12), MakeMatchPatternRef(false, 13),
    MakeMatchPatternRef(false, 14), MakeMatchPatternRef(false, 15), MakeMatchPatternRef(false, 16), MakeMatchPatternRef(false, 17),
    MakeMatchPatternRef(false, 18) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__de[] { MakeMatchPatternRef(false, 12), MakeMatchPatternRef(true, 13) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__en[] { MakeMatchPatternRef(false, 13) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__es[] { MakeMatchPatternRef(true, 13), MakeMatchPatternRef(false, 14) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__it[] { MakeMatchPatternRef(true, 13), MakeMatchPatternRef(false, 15) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__pl[] { MakeMatchPatternRef(true, 13), MakeMatchPatternRef(false, 16) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__pt[] { MakeMatchPatternRef(true, 13), MakeMatchPatternRef(false, 17) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__ru[] { MakeMatchPatternRef(true, 13), MakeMatchPatternRef(false, 18) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER_AND_APT[] { MakeMatchPatternRef(false, 19) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER_AND_APT__pl[] { MakeMatchPatternRef(false, 19) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_LOCATION[] { MakeMatchPatternRef(false, 20) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_LOCATION__es[] { MakeMatchPatternRef(false, 20) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_NAME[] { MakeMatchPatternRef(false, 21), MakeMatchPatternRef(false, 22),
    MakeMatchPatternRef(false, 23), MakeMatchPatternRef(false, 24), MakeMatchPatternRef(false, 25), MakeMatchPatternRef(false, 26),
    MakeMatchPatternRef(false, 27) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_NAME__de[] { MakeMatchPatternRef(false, 21), MakeMatchPatternRef(true, 22) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_NAME__en[] { MakeMatchPatternRef(false, 22) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_NAME__es[] { MakeMatchPatternRef(true, 22), MakeMatchPatternRef(false, 23) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_NAME__it[] { MakeMatchPatternRef(true, 22), MakeMatchPatternRef(false, 24) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_NAME__pl[] { MakeMatchPatternRef(true, 22), MakeMatchPatternRef(false, 25) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_NAME__pt[] { MakeMatchPatternRef(true, 22), MakeMatchPatternRef(false, 26) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_HOME_STREET_NAME__ru[] { MakeMatchPatternRef(true, 22), MakeMatchPatternRef(false, 27) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1[] { MakeMatchPatternRef(false, 28), MakeMatchPatternRef(false, 29), MakeMatchPatternRef(false, 30),
    MakeMatchPatternRef(false, 31), MakeMatchPatternRef(false, 32), MakeMatchPatternRef(false, 33), MakeMatchPatternRef(false, 34),
    MakeMatchPatternRef(false, 35), MakeMatchPatternRef(false, 36), MakeMatchPatternRef(false, 37), MakeMatchPatternRef(false, 38),
    MakeMatchPatternRef(false, 39), MakeMatchPatternRef(false, 25), MakeMatchPatternRef(false, 40), MakeMatchPatternRef(false, 41),
    MakeMatchPatternRef(false, 42), MakeMatchPatternRef(false, 43), MakeMatchPatternRef(false, 44), MakeMatchPatternRef(false, 45) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__de[] { MakeMatchPatternRef(false, 28), MakeMatchPatternRef(true, 29) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__en[] { MakeMatchPatternRef(false, 29), MakeMatchPatternRef(false, 30) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__es[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 31) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__fr[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 32) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__id[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 33), MakeMatchPatternRef(false, 34) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__it[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 35) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__ja[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 36), MakeMatchPatternRef(false, 37) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__ko[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 38), MakeMatchPatternRef(false, 39) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__pl[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 25) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__pt[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 40) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__ru[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 41), MakeMatchPatternRef(false, 42) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__tr[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 43), MakeMatchPatternRef(false, 44) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_1__zh_CN[] { MakeMatchPatternRef(true, 29), MakeMatchPatternRef(false, 45) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2[] { MakeMatchPatternRef(false, 46), MakeMatchPatternRef(false, 47), MakeMatchPatternRef(false, 48),
    MakeMatchPatternRef(false, 49), MakeMatchPatternRef(false, 50), MakeMatchPatternRef(false, 51), MakeMatchPatternRef(false, 52),
    MakeMatchPatternRef(false, 53), MakeMatchPatternRef(false, 54), MakeMatchPatternRef(false, 55), MakeMatchPatternRef(false, 56),
    MakeMatchPatternRef(false, 57), MakeMatchPatternRef(false, 58), MakeMatchPatternRef(false, 59), MakeMatchPatternRef(false, 60) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__de[] { MakeMatchPatternRef(false, 46), MakeMatchPatternRef(true, 47) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__en[] { MakeMatchPatternRef(false, 47), MakeMatchPatternRef(false, 48) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__es[] { MakeMatchPatternRef(true, 47), MakeMatchPatternRef(false, 49) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__fr[] { MakeMatchPatternRef(true, 47), MakeMatchPatternRef(false, 50), MakeMatchPatternRef(false, 51) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__it[] { MakeMatchPatternRef(true, 47), MakeMatchPatternRef(false, 52), MakeMatchPatternRef(false, 53) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__ja[] { MakeMatchPatternRef(true, 47), MakeMatchPatternRef(false, 54) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__ko[] { MakeMatchPatternRef(true, 47), MakeMatchPatternRef(false, 55), MakeMatchPatternRef(false, 56) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__pt[] { MakeMatchPatternRef(true, 47), MakeMatchPatternRef(false, 57) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__ru[] { MakeMatchPatternRef(true, 47), MakeMatchPatternRef(false, 58) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_2__zh_CN[] { MakeMatchPatternRef(true, 47), MakeMatchPatternRef(false, 59),
    MakeMatchPatternRef(false, 60) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_EXTRA[] { MakeMatchPatternRef(false, 61), MakeMatchPatternRef(false, 62), MakeMatchPatternRef(false, 63) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_EXTRA__en[] { MakeMatchPatternRef(false, 61) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_EXTRA__fr[] { MakeMatchPatternRef(true, 61), MakeMatchPatternRef(false, 62) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LINE_EXTRA__it[] { MakeMatchPatternRef(true, 61), MakeMatchPatternRef(false, 63) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LOOKUP[] { MakeMatchPatternRef(false, 64) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_LOOKUP__en[] { MakeMatchPatternRef(false, 64) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_NAME_IGNORED[] { MakeMatchPatternRef(false, 65), MakeMatchPatternRef(false, 66), MakeMatchPatternRef(false, 67),
    MakeMatchPatternRef(false, 68), MakeMatchPatternRef(false, 69) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_NAME_IGNORED__en[] { MakeMatchPatternRef(false, 65) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_NAME_IGNORED__es[] { MakeMatchPatternRef(true, 65), MakeMatchPatternRef(false, 66) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_NAME_IGNORED__id[] { MakeMatchPatternRef(true, 65), MakeMatchPatternRef(false, 67) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_NAME_IGNORED__pt[] { MakeMatchPatternRef(true, 65), MakeMatchPatternRef(false, 68) };
constexpr MatchPatternRef kPatterns__0__ADDRESS_NAME_IGNORED__tr[] { MakeMatchPatternRef(true, 65), MakeMatchPatternRef(false, 69) };
constexpr MatchPatternRef kPatterns__0__ADMIN_LEVEL_2[] { MakeMatchPatternRef(false, 70), MakeMatchPatternRef(false, 71) };
constexpr MatchPatternRef kPatterns__0__ADMIN_LEVEL_2__es[] { MakeMatchPatternRef(false, 70) };
constexpr MatchPatternRef kPatterns__0__ADMIN_LEVEL_2__pt[] { MakeMatchPatternRef(false, 71) };
constexpr MatchPatternRef kPatterns__0__ALTERNATIVE_FAMILY_NAME[] { MakeMatchPatternRef(false, 72) };
constexpr MatchPatternRef kPatterns__0__ALTERNATIVE_FAMILY_NAME__en[] { MakeMatchPatternRef(false, 72) };
constexpr MatchPatternRef kPatterns__0__ALTERNATIVE_FULL_NAME[] { MakeMatchPatternRef(false, 73) };
constexpr MatchPatternRef kPatterns__0__ALTERNATIVE_FULL_NAME__en[] { MakeMatchPatternRef(false, 73) };
constexpr MatchPatternRef kPatterns__0__ALTERNATIVE_GIVEN_NAME[] { MakeMatchPatternRef(false, 74) };
constexpr MatchPatternRef kPatterns__0__ALTERNATIVE_GIVEN_NAME__en[] { MakeMatchPatternRef(false, 74) };
constexpr MatchPatternRef kPatterns__0__ATTENTION_IGNORED[] { MakeMatchPatternRef(false, 75) };
constexpr MatchPatternRef kPatterns__0__ATTENTION_IGNORED__en[] { MakeMatchPatternRef(false, 75) };
constexpr MatchPatternRef kPatterns__0__AUGMENTED_PHONE_COUNTRY_CODE[] { MakeMatchPatternRef(false, 76) };
constexpr MatchPatternRef kPatterns__0__AUGMENTED_PHONE_COUNTRY_CODE__en[] { MakeMatchPatternRef(false, 76) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS[] { MakeMatchPatternRef(false, 77), MakeMatchPatternRef(false, 78) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS__en[] { MakeMatchPatternRef(false, 77) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS__es[] { MakeMatchPatternRef(true, 77), MakeMatchPatternRef(false, 78) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS_LINE_1[] { MakeMatchPatternRef(false, 79) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS_LINE_1__es[] { MakeMatchPatternRef(false, 79) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS_LINE_2[] { MakeMatchPatternRef(false, 80) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS_LINE_2__es[] { MakeMatchPatternRef(false, 80) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS_OR_LANDMARK[] { MakeMatchPatternRef(false, 81), MakeMatchPatternRef(false, 82) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS_OR_LANDMARK__en[] { MakeMatchPatternRef(false, 81) };
constexpr MatchPatternRef kPatterns__0__BETWEEN_STREETS_OR_LANDMARK__es[] { MakeMatchPatternRef(true, 81), MakeMatchPatternRef(false, 82) };
constexpr MatchPatternRef kPatterns__0__CITY[] { MakeMatchPatternRef(false, 83), MakeMatchPatternRef(false, 84), MakeMatchPatternRef(false, 85),
    MakeMatchPatternRef(false, 86), MakeMatchPatternRef(false, 87), MakeMatchPatternRef(false, 88), MakeMatchPatternRef(false, 89),
    MakeMatchPatternRef(false, 90), MakeMatchPatternRef(false, 91), MakeMatchPatternRef(false, 92), MakeMatchPatternRef(false, 93),
    MakeMatchPatternRef(false, 94), MakeMatchPatternRef(false, 95), MakeMatchPatternRef(false, 96), MakeMatchPatternRef(false, 97),
    MakeMatchPatternRef(false, 98) };
constexpr MatchPatternRef kPatterns__0__CITY__de[] { MakeMatchPatternRef(false, 83), MakeMatchPatternRef(true, 84) };
constexpr MatchPatternRef kPatterns__0__CITY__en[] { MakeMatchPatternRef(false, 84) };
constexpr MatchPatternRef kPatterns__0__CITY__es[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 85) };
constexpr MatchPatternRef kPatterns__0__CITY__fa[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 86) };
constexpr MatchPatternRef kPatterns__0__CITY__fr[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 87) };
constexpr MatchPatternRef kPatterns__0__CITY__hi[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 88) };
constexpr MatchPatternRef kPatterns__0__CITY__id[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 89) };
constexpr MatchPatternRef kPatterns__0__CITY__it[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 90) };
constexpr MatchPatternRef kPatterns__0__CITY__ja[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 91) };
constexpr MatchPatternRef kPatterns__0__CITY__ko[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 92) };
constexpr MatchPatternRef kPatterns__0__CITY__ml[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 93) };
constexpr MatchPatternRef kPatterns__0__CITY__pl[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 94) };
constexpr MatchPatternRef kPatterns__0__CITY__pt[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 95) };
constexpr MatchPatternRef kPatterns__0__CITY__ru[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 96) };
constexpr MatchPatternRef kPatterns__0__CITY__tr[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 97) };
constexpr MatchPatternRef kPatterns__0__CITY__zh_TW[] { MakeMatchPatternRef(true, 84), MakeMatchPatternRef(false, 98) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME[] { MakeMatchPatternRef(false, 99), MakeMatchPatternRef(false, 100), MakeMatchPatternRef(false, 101),
    MakeMatchPatternRef(false, 102), MakeMatchPatternRef(false, 103), MakeMatchPatternRef(false, 104), MakeMatchPatternRef(false, 105),
    MakeMatchPatternRef(false, 106), MakeMatchPatternRef(false, 107), MakeMatchPatternRef(false, 108), MakeMatchPatternRef(false, 109) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__de[] { MakeMatchPatternRef(false, 99), MakeMatchPatternRef(true, 100) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__en[] { MakeMatchPatternRef(false, 100) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__es[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 101) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__fa[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 102) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__fr[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 103) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__id[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 104) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__it[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 105) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__ja[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 106) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__ko[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 107) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__ru[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 108) };
constexpr MatchPatternRef kPatterns__0__COMPANY_NAME__zh_CN[] { MakeMatchPatternRef(true, 100), MakeMatchPatternRef(false, 109) };
constexpr MatchPatternRef kPatterns__0__COUNTRY[] { MakeMatchPatternRef(false, 110), MakeMatchPatternRef(false, 111), MakeMatchPatternRef(false, 112),
    MakeMatchPatternRef(false, 113), MakeMatchPatternRef(false, 114), MakeMatchPatternRef(false, 115), MakeMatchPatternRef(false, 116),
    MakeMatchPatternRef(false, 117), MakeMatchPatternRef(false, 118), MakeMatchPatternRef(false, 119), MakeMatchPatternRef(false, 120),
    MakeMatchPatternRef(false, 121) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__de[] { MakeMatchPatternRef(false, 110), MakeMatchPatternRef(true, 111) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__en[] { MakeMatchPatternRef(false, 111) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__es[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 112) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__fa[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 113) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__fr[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 114) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__id[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 115) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__it[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 116) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__ja[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 117) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__ko[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 118) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__pl[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 119) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__tr[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 120) };
constexpr MatchPatternRef kPatterns__0__COUNTRY__zh_CN[] { MakeMatchPatternRef(true, 111), MakeMatchPatternRef(false, 121) };
constexpr MatchPatternRef kPatterns__0__COUNTRY_LOCATION[] { MakeMatchPatternRef(false, 122) };
constexpr MatchPatternRef kPatterns__0__COUNTRY_LOCATION__en[] { MakeMatchPatternRef(false, 122) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE[] { MakeMatchPatternRef(false, 123), MakeMatchPatternRef(false, 124),
    MakeMatchPatternRef(false, 125), MakeMatchPatternRef(false, 126), MakeMatchPatternRef(false, 127), MakeMatchPatternRef(false, 128),
    MakeMatchPatternRef(false, 129), MakeMatchPatternRef(false, 130) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE__de[] { MakeMatchPatternRef(false, 123), MakeMatchPatternRef(true, 124) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE__en[] { MakeMatchPatternRef(false, 124) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE__es[] { MakeMatchPatternRef(true, 124), MakeMatchPatternRef(false, 125) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE__fr[] { MakeMatchPatternRef(true, 124), MakeMatchPatternRef(false, 126) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE__it[] { MakeMatchPatternRef(true, 124), MakeMatchPatternRef(false, 127) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE__ja[] { MakeMatchPatternRef(true, 124), MakeMatchPatternRef(false, 128) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE__pt[] { MakeMatchPatternRef(true, 124), MakeMatchPatternRef(false, 129) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE__ru[] { MakeMatchPatternRef(true, 124), MakeMatchPatternRef(false, 130) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE_2_DIGIT_YEAR[] { MakeMatchPatternRef(false, 131) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE_2_DIGIT_YEAR__en[] { MakeMatchPatternRef(false, 131) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE_4_DIGIT_YEAR[] { MakeMatchPatternRef(false, 132) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_DATE_4_DIGIT_YEAR__en[] { MakeMatchPatternRef(false, 132) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH[] { MakeMatchPatternRef(false, 133), MakeMatchPatternRef(false, 134),
    MakeMatchPatternRef(false, 125), MakeMatchPatternRef(false, 126), MakeMatchPatternRef(false, 135), MakeMatchPatternRef(false, 127),
    MakeMatchPatternRef(false, 128), MakeMatchPatternRef(false, 136), MakeMatchPatternRef(false, 130), MakeMatchPatternRef(false, 137) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__de[] { MakeMatchPatternRef(false, 133), MakeMatchPatternRef(true, 134) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__en[] { MakeMatchPatternRef(false, 134) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__es[] { MakeMatchPatternRef(true, 134), MakeMatchPatternRef(false, 125) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__fr[] { MakeMatchPatternRef(true, 134), MakeMatchPatternRef(false, 126) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__id[] { MakeMatchPatternRef(true, 134), MakeMatchPatternRef(false, 135) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__it[] { MakeMatchPatternRef(true, 134), MakeMatchPatternRef(false, 127) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__ja[] { MakeMatchPatternRef(true, 134), MakeMatchPatternRef(false, 128) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__pt[] { MakeMatchPatternRef(true, 134), MakeMatchPatternRef(false, 136) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__ru[] { MakeMatchPatternRef(true, 134), MakeMatchPatternRef(false, 130) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH__zh_CN[] { MakeMatchPatternRef(true, 134), MakeMatchPatternRef(false, 137) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH_BEFORE_YEAR[] { MakeMatchPatternRef(false, 138) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_MONTH_BEFORE_YEAR__en[] { MakeMatchPatternRef(false, 138) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR[] { MakeMatchPatternRef(false, 139), MakeMatchPatternRef(false, 140),
    MakeMatchPatternRef(false, 141), MakeMatchPatternRef(false, 135), MakeMatchPatternRef(false, 127), MakeMatchPatternRef(false, 128),
    MakeMatchPatternRef(false, 142), MakeMatchPatternRef(false, 130), MakeMatchPatternRef(false, 143) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__de[] { MakeMatchPatternRef(false, 139), MakeMatchPatternRef(true, 140) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__en[] { MakeMatchPatternRef(false, 140) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__es[] { MakeMatchPatternRef(true, 140), MakeMatchPatternRef(false, 141) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__id[] { MakeMatchPatternRef(true, 140), MakeMatchPatternRef(false, 135) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__it[] { MakeMatchPatternRef(true, 140), MakeMatchPatternRef(false, 127) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__ja[] { MakeMatchPatternRef(true, 140), MakeMatchPatternRef(false, 128) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__pt[] { MakeMatchPatternRef(true, 140), MakeMatchPatternRef(false, 142) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__ru[] { MakeMatchPatternRef(true, 140), MakeMatchPatternRef(false, 130) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR__zh_CN[] { MakeMatchPatternRef(true, 140), MakeMatchPatternRef(false, 143) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR_AFTER_MONTH[] { MakeMatchPatternRef(false, 144) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR_AFTER_MONTH__en[] { MakeMatchPatternRef(false, 144) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR_AFTER_MONTH_EXPERIMENTAL[] { MakeMatchPatternRef(false, 145) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_EXP_YEAR_AFTER_MONTH_EXPERIMENTAL__en[] { MakeMatchPatternRef(false, 145) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER[] { MakeMatchPatternRef(false, 146), MakeMatchPatternRef(false, 147),
    MakeMatchPatternRef(false, 148), MakeMatchPatternRef(false, 149), MakeMatchPatternRef(false, 149), MakeMatchPatternRef(false, 150),
    MakeMatchPatternRef(false, 151), MakeMatchPatternRef(false, 152), MakeMatchPatternRef(false, 149), MakeMatchPatternRef(false, 153),
    MakeMatchPatternRef(false, 154), MakeMatchPatternRef(false, 155) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__de[] { MakeMatchPatternRef(false, 146), MakeMatchPatternRef(false, 147),
    MakeMatchPatternRef(true, 148) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__en[] { MakeMatchPatternRef(false, 148) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__es[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 149) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__fr[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 149) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__id[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 150) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__ja[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 151) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__ko[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 152) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__pt[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 149) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__ru[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 153) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__zh_CN[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 154) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_NUMBER__zh_TW[] { MakeMatchPatternRef(true, 148), MakeMatchPatternRef(false, 155) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_VERIFICATION_CODE[] { MakeMatchPatternRef(false, 156), MakeMatchPatternRef(false, 157),
    MakeMatchPatternRef(false, 158), MakeMatchPatternRef(false, 159) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_VERIFICATION_CODE__br[] { MakeMatchPatternRef(false, 156), MakeMatchPatternRef(true, 158) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_VERIFICATION_CODE__de[] { MakeMatchPatternRef(false, 157), MakeMatchPatternRef(true, 158) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_VERIFICATION_CODE__en[] { MakeMatchPatternRef(false, 158) };
constexpr MatchPatternRef kPatterns__0__CREDIT_CARD_VERIFICATION_CODE__es[] { MakeMatchPatternRef(true, 158), MakeMatchPatternRef(false, 159) };
constexpr MatchPatternRef kPatterns__0__DAY[] { MakeMatchPatternRef(false, 160) };
constexpr MatchPatternRef kPatterns__0__DAY__en[] { MakeMatchPatternRef(false, 160) };
constexpr MatchPatternRef kPatterns__0__DEBIT_CARD[] { MakeMatchPatternRef(false, 161) };
constexpr MatchPatternRef kPatterns__0__DEBIT_CARD__en[] { MakeMatchPatternRef(false, 161) };
constexpr MatchPatternRef kPatterns__0__DEBIT_GIFT_CARD[] { MakeMatchPatternRef(false, 162) };
constexpr MatchPatternRef kPatterns__0__DEBIT_GIFT_CARD__en[] { MakeMatchPatternRef(false, 162) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS[] { MakeMatchPatternRef(false, 163), MakeMatchPatternRef(false, 164), MakeMatchPatternRef(false, 165),
    MakeMatchPatternRef(false, 166), MakeMatchPatternRef(false, 167), MakeMatchPatternRef(false, 168), MakeMatchPatternRef(false, 169),
    MakeMatchPatternRef(false, 170), MakeMatchPatternRef(false, 171), MakeMatchPatternRef(false, 172), MakeMatchPatternRef(false, 173),
    MakeMatchPatternRef(false, 174) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__en[] { MakeMatchPatternRef(false, 163) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__es[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 164) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__fa[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 165) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__fr[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 166) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__hi[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 167) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__ja[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 168) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__ko[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 169) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__ml[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 170) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__ru[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 171) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__tr[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 172) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__zh_CN[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 173) };
constexpr MatchPatternRef kPatterns__0__EMAIL_ADDRESS__zh_TW[] { MakeMatchPatternRef(true, 163), MakeMatchPatternRef(false, 174) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME[] { MakeMatchPatternRef(false, 175), MakeMatchPatternRef(false, 176), MakeMatchPatternRef(false, 177),
    MakeMatchPatternRef(false, 178), MakeMatchPatternRef(false, 179), MakeMatchPatternRef(false, 180), MakeMatchPatternRef(false, 181),
    MakeMatchPatternRef(false, 182), MakeMatchPatternRef(false, 183), MakeMatchPatternRef(false, 184), MakeMatchPatternRef(false, 185),
    MakeMatchPatternRef(false, 186), MakeMatchPatternRef(false, 187) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__de[] { MakeMatchPatternRef(false, 175), MakeMatchPatternRef(true, 176) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__en[] { MakeMatchPatternRef(false, 176) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__es[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 177) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__fa[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 178) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__fr[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 179) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__hi[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 180) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__id[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 181) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__ja[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 182) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__ko[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 183) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__ml[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 184) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__pt[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 185) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__ru[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 186) };
constexpr MatchPatternRef kPatterns__0__FIRST_NAME__tr[] { MakeMatchPatternRef(true, 176), MakeMatchPatternRef(false, 187) };
constexpr MatchPatternRef kPatterns__0__FLIGHT[] { MakeMatchPatternRef(false, 188), MakeMatchPatternRef(false, 189), MakeMatchPatternRef(false, 190) };
constexpr MatchPatternRef kPatterns__0__FLIGHT__en[] { MakeMatchPatternRef(false, 188) };
constexpr MatchPatternRef kPatterns__0__FLIGHT__es[] { MakeMatchPatternRef(true, 188), MakeMatchPatternRef(false, 189) };
constexpr MatchPatternRef kPatterns__0__FLIGHT__ja[] { MakeMatchPatternRef(true, 188), MakeMatchPatternRef(false, 190) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME[] { MakeMatchPatternRef(false, 191), MakeMatchPatternRef(false, 192), MakeMatchPatternRef(false, 193),
    MakeMatchPatternRef(false, 194), MakeMatchPatternRef(false, 195), MakeMatchPatternRef(false, 196), MakeMatchPatternRef(false, 197),
    MakeMatchPatternRef(false, 198), MakeMatchPatternRef(false, 199), MakeMatchPatternRef(false, 200), MakeMatchPatternRef(false, 201),
    MakeMatchPatternRef(false, 202) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__de[] { MakeMatchPatternRef(false, 191), MakeMatchPatternRef(true, 192) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__en[] { MakeMatchPatternRef(false, 192) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__es[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 193) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__fa[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 194) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__fr[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 195) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__id[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 196) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__ja[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 197) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__ko[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 198) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__pt[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 199) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__ru[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 200) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__tr[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 201) };
constexpr MatchPatternRef kPatterns__0__FULL_NAME__zh_CN[] { MakeMatchPatternRef(true, 192), MakeMatchPatternRef(false, 202) };
constexpr MatchPatternRef kPatterns__0__GIFT_CARD[] { MakeMatchPatternRef(false, 203) };
constexpr MatchPatternRef kPatterns__0__GIFT_CARD__en[] { MakeMatchPatternRef(false, 203) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX[] { MakeMatchPatternRef(false, 204), MakeMatchPatternRef(false, 205), MakeMatchPatternRef(false, 206),
    MakeMatchPatternRef(false, 207), MakeMatchPatternRef(false, 208), MakeMatchPatternRef(false, 209), MakeMatchPatternRef(false, 210),
    MakeMatchPatternRef(false, 211) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX__de[] { MakeMatchPatternRef(false, 204), MakeMatchPatternRef(true, 206) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX__el[] { MakeMatchPatternRef(false, 205), MakeMatchPatternRef(true, 206) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX__en[] { MakeMatchPatternRef(false, 206) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX__es[] { MakeMatchPatternRef(true, 206), MakeMatchPatternRef(false, 207) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX__fr[] { MakeMatchPatternRef(true, 206), MakeMatchPatternRef(false, 208) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX__it[] { MakeMatchPatternRef(true, 206), MakeMatchPatternRef(false, 209) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX__ru[] { MakeMatchPatternRef(true, 206), MakeMatchPatternRef(false, 210) };
constexpr MatchPatternRef kPatterns__0__HONORIFIC_PREFIX__tr[] { MakeMatchPatternRef(true, 206), MakeMatchPatternRef(false, 211) };
constexpr MatchPatternRef kPatterns__0__IBAN_VALUE[] { MakeMatchPatternRef(false, 212) };
constexpr MatchPatternRef kPatterns__0__IBAN_VALUE__en[] { MakeMatchPatternRef(false, 212) };
constexpr MatchPatternRef kPatterns__0__IN_DEPENDENT_LOCALITY[] { MakeMatchPatternRef(false, 213) };
constexpr MatchPatternRef kPatterns__0__IN_DEPENDENT_LOCALITY__en[] { MakeMatchPatternRef(false, 213) };
constexpr MatchPatternRef kPatterns__0__IN_STREET_LOCATION[] { MakeMatchPatternRef(false, 214) };
constexpr MatchPatternRef kPatterns__0__IN_STREET_LOCATION__en[] { MakeMatchPatternRef(false, 214) };
constexpr MatchPatternRef kPatterns__0__LANDMARK[] { MakeMatchPatternRef(false, 215), MakeMatchPatternRef(false, 216), MakeMatchPatternRef(false, 216) };
constexpr MatchPatternRef kPatterns__0__LANDMARK__en[] { MakeMatchPatternRef(false, 215) };
constexpr MatchPatternRef kPatterns__0__LANDMARK__es[] { MakeMatchPatternRef(true, 215), MakeMatchPatternRef(false, 216) };
constexpr MatchPatternRef kPatterns__0__LANDMARK__pt[] { MakeMatchPatternRef(true, 215), MakeMatchPatternRef(false, 216) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME[] { MakeMatchPatternRef(false, 217), MakeMatchPatternRef(false, 218), MakeMatchPatternRef(false, 219),
    MakeMatchPatternRef(false, 220), MakeMatchPatternRef(false, 221), MakeMatchPatternRef(false, 222), MakeMatchPatternRef(false, 223),
    MakeMatchPatternRef(false, 224), MakeMatchPatternRef(false, 225), MakeMatchPatternRef(false, 226), MakeMatchPatternRef(false, 227),
    MakeMatchPatternRef(false, 228), MakeMatchPatternRef(false, 229), MakeMatchPatternRef(false, 230) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__de[] { MakeMatchPatternRef(false, 217), MakeMatchPatternRef(true, 218) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__en[] { MakeMatchPatternRef(false, 218) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__es[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 219) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__fa[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 220) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__fr[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 221) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__hi[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 222) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__id[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 223) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__it[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 224) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__ja[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 225) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__ko[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 226) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__ml[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 227) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__pt[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 228) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__ru[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 229) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME__tr[] { MakeMatchPatternRef(true, 218), MakeMatchPatternRef(false, 230) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME_FIRST[] { MakeMatchPatternRef(false, 231) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME_FIRST__es[] { MakeMatchPatternRef(false, 231) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME_SECOND[] { MakeMatchPatternRef(false, 232) };
constexpr MatchPatternRef kPatterns__0__LAST_NAME_SECOND__es[] { MakeMatchPatternRef(false, 232) };
constexpr MatchPatternRef kPatterns__0__MERCHANT_PROMO_CODE[] { MakeMatchPatternRef(false, 233) };
constexpr MatchPatternRef kPatterns__0__MERCHANT_PROMO_CODE__en[] { MakeMatchPatternRef(false, 233) };
constexpr MatchPatternRef kPatterns__0__MIDDLE_INITIAL[] { MakeMatchPatternRef(false, 234) };
constexpr MatchPatternRef kPatterns__0__MIDDLE_INITIAL__en[] { MakeMatchPatternRef(false, 234) };
constexpr MatchPatternRef kPatterns__0__MIDDLE_NAME[] { MakeMatchPatternRef(false, 235) };
constexpr MatchPatternRef kPatterns__0__MIDDLE_NAME__en[] { MakeMatchPatternRef(false, 235) };
constexpr MatchPatternRef kPatterns__0__NAME_GENERIC[] { MakeMatchPatternRef(false, 236), MakeMatchPatternRef(false, 237), MakeMatchPatternRef(false, 199) };
constexpr MatchPatternRef kPatterns__0__NAME_GENERIC__en[] { MakeMatchPatternRef(false, 236) };
constexpr MatchPatternRef kPatterns__0__NAME_GENERIC__fr[] { MakeMatchPatternRef(true, 236), MakeMatchPatternRef(false, 237) };
constexpr MatchPatternRef kPatterns__0__NAME_GENERIC__pt[] { MakeMatchPatternRef(true, 236), MakeMatchPatternRef(false, 199) };
constexpr MatchPatternRef kPatterns__0__NAME_IGNORED[] { MakeMatchPatternRef(false, 238), MakeMatchPatternRef(false, 239), MakeMatchPatternRef(false, 240) };
constexpr MatchPatternRef kPatterns__0__NAME_IGNORED__en[] { MakeMatchPatternRef(false, 238) };
constexpr MatchPatternRef kPatterns__0__NAME_IGNORED__ko[] { MakeMatchPatternRef(true, 238), MakeMatchPatternRef(false, 239) };
constexpr MatchPatternRef kPatterns__0__NAME_IGNORED__zh_CN[] { MakeMatchPatternRef(true, 238), MakeMatchPatternRef(false, 240) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD[] { MakeMatchPatternRef(false, 241), MakeMatchPatternRef(false, 242), MakeMatchPatternRef(false, 243),
    MakeMatchPatternRef(false, 244), MakeMatchPatternRef(false, 245), MakeMatchPatternRef(false, 246), MakeMatchPatternRef(false, 247),
    MakeMatchPatternRef(false, 248), MakeMatchPatternRef(false, 249), MakeMatchPatternRef(false, 250) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__de[] { MakeMatchPatternRef(false, 241), MakeMatchPatternRef(true, 242) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__en[] { MakeMatchPatternRef(false, 242) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__es[] { MakeMatchPatternRef(true, 242), MakeMatchPatternRef(false, 243) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__fr[] { MakeMatchPatternRef(true, 242), MakeMatchPatternRef(false, 244) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__id[] { MakeMatchPatternRef(true, 242), MakeMatchPatternRef(false, 245) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__it[] { MakeMatchPatternRef(true, 242), MakeMatchPatternRef(false, 246) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__ja[] { MakeMatchPatternRef(true, 242), MakeMatchPatternRef(false, 247) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__pt[] { MakeMatchPatternRef(true, 242), MakeMatchPatternRef(false, 248) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__ru[] { MakeMatchPatternRef(true, 242), MakeMatchPatternRef(false, 249) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD__zh_CN[] { MakeMatchPatternRef(true, 242), MakeMatchPatternRef(false, 250) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD_CONTEXTUAL[] { MakeMatchPatternRef(false, 251) };
constexpr MatchPatternRef kPatterns__0__NAME_ON_CARD_CONTEXTUAL__en[] { MakeMatchPatternRef(false, 251) };
constexpr MatchPatternRef kPatterns__0__NUMERIC_QUANTITY[] { MakeMatchPatternRef(false, 252) };
constexpr MatchPatternRef kPatterns__0__NUMERIC_QUANTITY__en[] { MakeMatchPatternRef(false, 252) };
constexpr MatchPatternRef kPatterns__0__OVERFLOW[] { MakeMatchPatternRef(false, 253), MakeMatchPatternRef(false, 254), MakeMatchPatternRef(false, 255),
    MakeMatchPatternRef(false, 256) };
constexpr MatchPatternRef kPatterns__0__OVERFLOW__de[] { MakeMatchPatternRef(false, 253) };
constexpr MatchPatternRef kPatterns__0__OVERFLOW__fr[] { MakeMatchPatternRef(false, 254) };
constexpr MatchPatternRef kPatterns__0__OVERFLOW__it[] { MakeMatchPatternRef(false, 255) };
constexpr MatchPatternRef kPatterns__0__OVERFLOW__pt[] { MakeMatchPatternRef(false, 256) };
constexpr MatchPatternRef kPatterns__0__OVERFLOW_AND_LANDMARK[] { MakeMatchPatternRef(false, 257), MakeMatchPatternRef(false, 258) };
constexpr MatchPatternRef kPatterns__0__OVERFLOW_AND_LANDMARK__en[] { MakeMatchPatternRef(false, 257) };
constexpr MatchPatternRef kPatterns__0__OVERFLOW_AND_LANDMARK__pt[] { MakeMatchPatternRef(true, 257), MakeMatchPatternRef(false, 258) };
constexpr MatchPatternRef kPatterns__0__PASSPORT[] { MakeMatchPatternRef(false, 259), MakeMatchPatternRef(false, 260), MakeMatchPatternRef(false, 261),
    MakeMatchPatternRef(false, 262) };
constexpr MatchPatternRef kPatterns__0__PASSPORT__en[] { MakeMatchPatternRef(false, 259) };
constexpr MatchPatternRef kPatterns__0__PASSPORT__es[] { MakeMatchPatternRef(true, 259), MakeMatchPatternRef(false, 260) };
constexpr MatchPatternRef kPatterns__0__PASSPORT__fr[] { MakeMatchPatternRef(true, 259), MakeMatchPatternRef(false, 261) };
constexpr MatchPatternRef kPatterns__0__PASSPORT__ja[] { MakeMatchPatternRef(true, 259), MakeMatchPatternRef(false, 262) };
constexpr MatchPatternRef kPatterns__0__PATTERN_SOURCE_DUMMY[] { MakeMatchPatternRef(false, 263) };
constexpr MatchPatternRef kPatterns__0__PATTERN_SOURCE_DUMMY__en[] { MakeMatchPatternRef(false, 263) };
constexpr MatchPatternRef kPatterns__0__PHONE[] { MakeMatchPatternRef(false, 264), MakeMatchPatternRef(false, 265), MakeMatchPatternRef(false, 266),
    MakeMatchPatternRef(false, 267), MakeMatchPatternRef(false, 268), MakeMatchPatternRef(false, 269), MakeMatchPatternRef(false, 270),
    MakeMatchPatternRef(false, 271), MakeMatchPatternRef(false, 272), MakeMatchPatternRef(false, 273), MakeMatchPatternRef(false, 274),
    MakeMatchPatternRef(false, 275), MakeMatchPatternRef(false, 276) };
constexpr MatchPatternRef kPatterns__0__PHONE__de[] { MakeMatchPatternRef(false, 264), MakeMatchPatternRef(true, 265) };
constexpr MatchPatternRef kPatterns__0__PHONE__en[] { MakeMatchPatternRef(false, 265) };
constexpr MatchPatternRef kPatterns__0__PHONE__es[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 266) };
constexpr MatchPatternRef kPatterns__0__PHONE__fr[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 267) };
constexpr MatchPatternRef kPatterns__0__PHONE__hi[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 268) };
constexpr MatchPatternRef kPatterns__0__PHONE__id[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 269) };
constexpr MatchPatternRef kPatterns__0__PHONE__ja[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 270) };
constexpr MatchPatternRef kPatterns__0__PHONE__ko[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 271) };
constexpr MatchPatternRef kPatterns__0__PHONE__ml[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 272) };
constexpr MatchPatternRef kPatterns__0__PHONE__pt[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 273) };
constexpr MatchPatternRef kPatterns__0__PHONE__ru[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 274) };
constexpr MatchPatternRef kPatterns__0__PHONE__tr[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 275) };
constexpr MatchPatternRef kPatterns__0__PHONE__zh_CN[] { MakeMatchPatternRef(true, 265), MakeMatchPatternRef(false, 276) };
constexpr MatchPatternRef kPatterns__0__PHONE_AREA_CODE[] { MakeMatchPatternRef(false, 277), MakeMatchPatternRef(false, 278) };
constexpr MatchPatternRef kPatterns__0__PHONE_AREA_CODE__en[] { MakeMatchPatternRef(false, 277) };
constexpr MatchPatternRef kPatterns__0__PHONE_AREA_CODE__ko[] { MakeMatchPatternRef(true, 277), MakeMatchPatternRef(false, 278) };
constexpr MatchPatternRef kPatterns__0__PHONE_AREA_CODE_NO_TEXT[] { MakeMatchPatternRef(false, 279) };
constexpr MatchPatternRef kPatterns__0__PHONE_AREA_CODE_NO_TEXT__en[] { MakeMatchPatternRef(false, 279) };
constexpr MatchPatternRef kPatterns__0__PHONE_COUNTRY_CODE[] { MakeMatchPatternRef(false, 280) };
constexpr MatchPatternRef kPatterns__0__PHONE_COUNTRY_CODE__en[] { MakeMatchPatternRef(false, 280) };
constexpr MatchPatternRef kPatterns__0__PHONE_EXTENSION[] { MakeMatchPatternRef(false, 281), MakeMatchPatternRef(false, 282) };
constexpr MatchPatternRef kPatterns__0__PHONE_EXTENSION__en[] { MakeMatchPatternRef(false, 281) };
constexpr MatchPatternRef kPatterns__0__PHONE_EXTENSION__pt[] { MakeMatchPatternRef(true, 281), MakeMatchPatternRef(false, 282) };
constexpr MatchPatternRef kPatterns__0__PHONE_PREFIX[] { MakeMatchPatternRef(false, 283), MakeMatchPatternRef(false, 284), MakeMatchPatternRef(false, 285) };
constexpr MatchPatternRef kPatterns__0__PHONE_PREFIX__en[] { MakeMatchPatternRef(false, 283) };
constexpr MatchPatternRef kPatterns__0__PHONE_PREFIX__fr[] { MakeMatchPatternRef(true, 283), MakeMatchPatternRef(false, 284) };
constexpr MatchPatternRef kPatterns__0__PHONE_PREFIX__pt[] { MakeMatchPatternRef(true, 283), MakeMatchPatternRef(false, 285) };
constexpr MatchPatternRef kPatterns__0__PHONE_PREFIX_SEPARATOR[] { MakeMatchPatternRef(false, 286) };
constexpr MatchPatternRef kPatterns__0__PHONE_PREFIX_SEPARATOR__en[] { MakeMatchPatternRef(false, 286) };
constexpr MatchPatternRef kPatterns__0__PHONE_SUFFIX[] { MakeMatchPatternRef(false, 287) };
constexpr MatchPatternRef kPatterns__0__PHONE_SUFFIX__en[] { MakeMatchPatternRef(false, 287) };
constexpr MatchPatternRef kPatterns__0__PHONE_SUFFIX_SEPARATOR[] { MakeMatchPatternRef(false, 288) };
constexpr MatchPatternRef kPatterns__0__PHONE_SUFFIX_SEPARATOR__en[] { MakeMatchPatternRef(false, 288) };
constexpr MatchPatternRef kPatterns__0__PRICE[] { MakeMatchPatternRef(false, 289), MakeMatchPatternRef(false, 290), MakeMatchPatternRef(false, 291),
    MakeMatchPatternRef(false, 292) };
constexpr MatchPatternRef kPatterns__0__PRICE__ar[] { MakeMatchPatternRef(false, 289), MakeMatchPatternRef(true, 290) };
constexpr MatchPatternRef kPatterns__0__PRICE__en[] { MakeMatchPatternRef(false, 290) };
constexpr MatchPatternRef kPatterns__0__PRICE__fa[] { MakeMatchPatternRef(true, 290), MakeMatchPatternRef(false, 291) };
constexpr MatchPatternRef kPatterns__0__PRICE__fr[] { MakeMatchPatternRef(true, 290), MakeMatchPatternRef(false, 292) };
constexpr MatchPatternRef kPatterns__0__REGION_IGNORED[] { MakeMatchPatternRef(false, 293), MakeMatchPatternRef(false, 294), MakeMatchPatternRef(false, 295) };
constexpr MatchPatternRef kPatterns__0__REGION_IGNORED__en[] { MakeMatchPatternRef(false, 293) };
constexpr MatchPatternRef kPatterns__0__REGION_IGNORED__es[] { MakeMatchPatternRef(true, 293), MakeMatchPatternRef(false, 294) };
constexpr MatchPatternRef kPatterns__0__REGION_IGNORED__pt[] { MakeMatchPatternRef(true, 293), MakeMatchPatternRef(false, 295) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM[] { MakeMatchPatternRef(false, 296), MakeMatchPatternRef(false, 297), MakeMatchPatternRef(false, 298),
    MakeMatchPatternRef(false, 299), MakeMatchPatternRef(false, 300), MakeMatchPatternRef(false, 301), MakeMatchPatternRef(false, 302),
    MakeMatchPatternRef(false, 303) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM__de[] { MakeMatchPatternRef(false, 296), MakeMatchPatternRef(true, 297) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM__en[] { MakeMatchPatternRef(false, 297) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM__fa[] { MakeMatchPatternRef(true, 297), MakeMatchPatternRef(false, 298) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM__fr[] { MakeMatchPatternRef(true, 297), MakeMatchPatternRef(false, 299) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM__ja[] { MakeMatchPatternRef(true, 297), MakeMatchPatternRef(false, 300) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM__pt[] { MakeMatchPatternRef(true, 297), MakeMatchPatternRef(false, 301) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM__ru[] { MakeMatchPatternRef(true, 297), MakeMatchPatternRef(false, 302) };
constexpr MatchPatternRef kPatterns__0__SEARCH_TERM__zh_CN[] { MakeMatchPatternRef(true, 297), MakeMatchPatternRef(false, 303) };
constexpr MatchPatternRef kPatterns__0__STATE[] { MakeMatchPatternRef(false, 304), MakeMatchPatternRef(false, 305), MakeMatchPatternRef(false, 306),
    MakeMatchPatternRef(false, 307), MakeMatchPatternRef(false, 308), MakeMatchPatternRef(false, 309), MakeMatchPatternRef(false, 310),
    MakeMatchPatternRef(false, 311), MakeMatchPatternRef(false, 312), MakeMatchPatternRef(false, 313), MakeMatchPatternRef(false, 314) };
constexpr MatchPatternRef kPatterns__0__STATE__en[] { MakeMatchPatternRef(false, 304) };
constexpr MatchPatternRef kPatterns__0__STATE__fa[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 305) };
constexpr MatchPatternRef kPatterns__0__STATE__hi[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 306) };
constexpr MatchPatternRef kPatterns__0__STATE__id[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 307) };
constexpr MatchPatternRef kPatterns__0__STATE__ja[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 308) };
constexpr MatchPatternRef kPatterns__0__STATE__ko[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 309) };
constexpr MatchPatternRef kPatterns__0__STATE__ml[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 310) };
constexpr MatchPatternRef kPatterns__0__STATE__pt[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 311) };
constexpr MatchPatternRef kPatterns__0__STATE__ru[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 312) };
constexpr MatchPatternRef kPatterns__0__STATE__tr[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 313) };
constexpr MatchPatternRef kPatterns__0__STATE__zh_TW[] { MakeMatchPatternRef(true, 304), MakeMatchPatternRef(false, 314) };
constexpr MatchPatternRef kPatterns__0__TRAVEL_DESTINATION[] { MakeMatchPatternRef(false, 315), MakeMatchPatternRef(false, 316),
    MakeMatchPatternRef(false, 317) };
constexpr MatchPatternRef kPatterns__0__TRAVEL_DESTINATION__en[] { MakeMatchPatternRef(false, 315) };
constexpr MatchPatternRef kPatterns__0__TRAVEL_DESTINATION__es[] { MakeMatchPatternRef(true, 315), MakeMatchPatternRef(false, 316) };
constexpr MatchPatternRef kPatterns__0__TRAVEL_DESTINATION__ja[] { MakeMatchPatternRef(true, 315), MakeMatchPatternRef(false, 317) };
constexpr MatchPatternRef kPatterns__0__TRAVEL_ORIGIN[] { MakeMatchPatternRef(false, 318), MakeMatchPatternRef(false, 319), MakeMatchPatternRef(false, 320) };
constexpr MatchPatternRef kPatterns__0__TRAVEL_ORIGIN__en[] { MakeMatchPatternRef(false, 318) };
constexpr MatchPatternRef kPatterns__0__TRAVEL_ORIGIN__es[] { MakeMatchPatternRef(true, 318), MakeMatchPatternRef(false, 319) };
constexpr MatchPatternRef kPatterns__0__TRAVEL_ORIGIN__ja[] { MakeMatchPatternRef(true, 318), MakeMatchPatternRef(false, 320) };
constexpr MatchPatternRef kPatterns__0__ZIP_4[] { MakeMatchPatternRef(false, 321), MakeMatchPatternRef(false, 322) };
constexpr MatchPatternRef kPatterns__0__ZIP_4__en[] { MakeMatchPatternRef(false, 321) };
constexpr MatchPatternRef kPatterns__0__ZIP_4__pt[] { MakeMatchPatternRef(true, 321), MakeMatchPatternRef(false, 322) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE[] { MakeMatchPatternRef(false, 323), MakeMatchPatternRef(false, 324), MakeMatchPatternRef(false, 325),
    MakeMatchPatternRef(false, 326), MakeMatchPatternRef(false, 327), MakeMatchPatternRef(false, 328), MakeMatchPatternRef(false, 329),
    MakeMatchPatternRef(false, 330), MakeMatchPatternRef(false, 331), MakeMatchPatternRef(false, 332), MakeMatchPatternRef(false, 333),
    MakeMatchPatternRef(false, 334), MakeMatchPatternRef(false, 335), MakeMatchPatternRef(false, 336), MakeMatchPatternRef(false, 337),
    MakeMatchPatternRef(false, 338) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__de[] { MakeMatchPatternRef(false, 323), MakeMatchPatternRef(true, 324) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__en[] { MakeMatchPatternRef(false, 324) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__es[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 325) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__fr[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 326) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__hi[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 327) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__id[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 328) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__it[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 329) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__ja[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 330) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__ko[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 331) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__ml[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 332) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__pl[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 333) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__pt[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 334) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__ru[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 335) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__tr[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 336) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__zh_CN[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 337) };
constexpr MatchPatternRef kPatterns__0__ZIP_CODE__zh_TW[] { MakeMatchPatternRef(true, 324), MakeMatchPatternRef(false, 338) };

// The lookup map for field types and langs.
//
// The key type in the map is essentially a pair of const char*.
// It also allows for lookup by std::string_view pairs (because the
// comparator transparently accepts std::string_view pairs).
//
// The value type is an array of spans of MatchPatternRefs. The
// indices of the array correspond to the pattern source: the patterns
// from the first input JSON file are stored at index 0, etc.
//
// This design exploits that the different JSON files by and large
// contain the same pattern names and languages. If instead we
// generated an individual map for each JSON file, then, assuming four
// JSON files, the duplicate keys would cause 60% overhead, which
// adds up to >10K binary size on Android.
constexpr auto kPatternMap = base::MakeFixedFlatMap<NameAndLanguage, std::array<base::span<const MatchPatternRef>, 1>>(
    {
        { { "ADDRESS_HOME_APT_NUM", "" }, { kPatterns__0__ADDRESS_HOME_APT_NUM } },
        { { "ADDRESS_HOME_APT_NUM", "de" }, { kPatterns__0__ADDRESS_HOME_APT_NUM__de } },
        { { "ADDRESS_HOME_APT_NUM", "en" }, { kPatterns__0__ADDRESS_HOME_APT_NUM__en } },
        { { "ADDRESS_HOME_APT_NUM", "es" }, { kPatterns__0__ADDRESS_HOME_APT_NUM__es } },
        { { "ADDRESS_HOME_APT_NUM", "fr" }, { kPatterns__0__ADDRESS_HOME_APT_NUM__fr } },
        { { "ADDRESS_HOME_APT_NUM", "it" }, { kPatterns__0__ADDRESS_HOME_APT_NUM__it } },
        { { "ADDRESS_HOME_APT_NUM", "pl" }, { kPatterns__0__ADDRESS_HOME_APT_NUM__pl } },
        { { "ADDRESS_HOME_APT_NUM", "ru" }, { kPatterns__0__ADDRESS_HOME_APT_NUM__ru } },
        { { "ADDRESS_HOME_DEPENDENT_LOCALITY", "" }, { kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY } },
        { { "ADDRESS_HOME_DEPENDENT_LOCALITY", "en" }, { kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__en } },
        { { "ADDRESS_HOME_DEPENDENT_LOCALITY", "es" }, { kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__es } },
        { { "ADDRESS_HOME_DEPENDENT_LOCALITY", "id" }, { kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__id } },
        { { "ADDRESS_HOME_DEPENDENT_LOCALITY", "pt" }, { kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__pt } },
        { { "ADDRESS_HOME_DEPENDENT_LOCALITY", "tr" }, { kPatterns__0__ADDRESS_HOME_DEPENDENT_LOCALITY__tr } },
        { { "ADDRESS_HOME_HOUSE_NUMBER", "" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER } },
        { { "ADDRESS_HOME_HOUSE_NUMBER", "de" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__de } },
        { { "ADDRESS_HOME_HOUSE_NUMBER", "en" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__en } },
        { { "ADDRESS_HOME_HOUSE_NUMBER", "es" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__es } },
        { { "ADDRESS_HOME_HOUSE_NUMBER", "it" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__it } },
        { { "ADDRESS_HOME_HOUSE_NUMBER", "pl" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__pl } },
        { { "ADDRESS_HOME_HOUSE_NUMBER", "pt" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__pt } },
        { { "ADDRESS_HOME_HOUSE_NUMBER", "ru" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER__ru } },
        { { "ADDRESS_HOME_HOUSE_NUMBER_AND_APT", "" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER_AND_APT } },
        { { "ADDRESS_HOME_HOUSE_NUMBER_AND_APT", "pl" }, { kPatterns__0__ADDRESS_HOME_HOUSE_NUMBER_AND_APT__pl } },
        { { "ADDRESS_HOME_STREET_LOCATION", "" }, { kPatterns__0__ADDRESS_HOME_STREET_LOCATION } },
        { { "ADDRESS_HOME_STREET_LOCATION", "es" }, { kPatterns__0__ADDRESS_HOME_STREET_LOCATION__es } },
        { { "ADDRESS_HOME_STREET_NAME", "" }, { kPatterns__0__ADDRESS_HOME_STREET_NAME } },
        { { "ADDRESS_HOME_STREET_NAME", "de" }, { kPatterns__0__ADDRESS_HOME_STREET_NAME__de } },
        { { "ADDRESS_HOME_STREET_NAME", "en" }, { kPatterns__0__ADDRESS_HOME_STREET_NAME__en } },
        { { "ADDRESS_HOME_STREET_NAME", "es" }, { kPatterns__0__ADDRESS_HOME_STREET_NAME__es } },
        { { "ADDRESS_HOME_STREET_NAME", "it" }, { kPatterns__0__ADDRESS_HOME_STREET_NAME__it } },
        { { "ADDRESS_HOME_STREET_NAME", "pl" }, { kPatterns__0__ADDRESS_HOME_STREET_NAME__pl } },
        { { "ADDRESS_HOME_STREET_NAME", "pt" }, { kPatterns__0__ADDRESS_HOME_STREET_NAME__pt } },
        { { "ADDRESS_HOME_STREET_NAME", "ru" }, { kPatterns__0__ADDRESS_HOME_STREET_NAME__ru } },
        { { "ADDRESS_LINE_1", "" }, { kPatterns__0__ADDRESS_LINE_1 } },
        { { "ADDRESS_LINE_1", "de" }, { kPatterns__0__ADDRESS_LINE_1__de } },
        { { "ADDRESS_LINE_1", "en" }, { kPatterns__0__ADDRESS_LINE_1__en } },
        { { "ADDRESS_LINE_1", "es" }, { kPatterns__0__ADDRESS_LINE_1__es } },
        { { "ADDRESS_LINE_1", "fr" }, { kPatterns__0__ADDRESS_LINE_1__fr } },
        { { "ADDRESS_LINE_1", "id" }, { kPatterns__0__ADDRESS_LINE_1__id } },
        { { "ADDRESS_LINE_1", "it" }, { kPatterns__0__ADDRESS_LINE_1__it } },
        { { "ADDRESS_LINE_1", "ja" }, { kPatterns__0__ADDRESS_LINE_1__ja } },
        { { "ADDRESS_LINE_1", "ko" }, { kPatterns__0__ADDRESS_LINE_1__ko } },
        { { "ADDRESS_LINE_1", "pl" }, { kPatterns__0__ADDRESS_LINE_1__pl } },
        { { "ADDRESS_LINE_1", "pt" }, { kPatterns__0__ADDRESS_LINE_1__pt } },
        { { "ADDRESS_LINE_1", "ru" }, { kPatterns__0__ADDRESS_LINE_1__ru } },
        { { "ADDRESS_LINE_1", "tr" }, { kPatterns__0__ADDRESS_LINE_1__tr } },
        { { "ADDRESS_LINE_1", "zh-CN" }, { kPatterns__0__ADDRESS_LINE_1__zh_CN } },
        { { "ADDRESS_LINE_2", "" }, { kPatterns__0__ADDRESS_LINE_2 } },
        { { "ADDRESS_LINE_2", "de" }, { kPatterns__0__ADDRESS_LINE_2__de } },
        { { "ADDRESS_LINE_2", "en" }, { kPatterns__0__ADDRESS_LINE_2__en } },
        { { "ADDRESS_LINE_2", "es" }, { kPatterns__0__ADDRESS_LINE_2__es } },
        { { "ADDRESS_LINE_2", "fr" }, { kPatterns__0__ADDRESS_LINE_2__fr } },
        { { "ADDRESS_LINE_2", "it" }, { kPatterns__0__ADDRESS_LINE_2__it } },
        { { "ADDRESS_LINE_2", "ja" }, { kPatterns__0__ADDRESS_LINE_2__ja } },
        { { "ADDRESS_LINE_2", "ko" }, { kPatterns__0__ADDRESS_LINE_2__ko } },
        { { "ADDRESS_LINE_2", "pt" }, { kPatterns__0__ADDRESS_LINE_2__pt } },
        { { "ADDRESS_LINE_2", "ru" }, { kPatterns__0__ADDRESS_LINE_2__ru } },
        { { "ADDRESS_LINE_2", "zh-CN" }, { kPatterns__0__ADDRESS_LINE_2__zh_CN } },
        { { "ADDRESS_LINE_EXTRA", "" }, { kPatterns__0__ADDRESS_LINE_EXTRA } },
        { { "ADDRESS_LINE_EXTRA", "en" }, { kPatterns__0__ADDRESS_LINE_EXTRA__en } },
        { { "ADDRESS_LINE_EXTRA", "fr" }, { kPatterns__0__ADDRESS_LINE_EXTRA__fr } },
        { { "ADDRESS_LINE_EXTRA", "it" }, { kPatterns__0__ADDRESS_LINE_EXTRA__it } },
        { { "ADDRESS_LOOKUP", "" }, { kPatterns__0__ADDRESS_LOOKUP } },
        { { "ADDRESS_LOOKUP", "en" }, { kPatterns__0__ADDRESS_LOOKUP__en } },
        { { "ADDRESS_NAME_IGNORED", "" }, { kPatterns__0__ADDRESS_NAME_IGNORED } },
        { { "ADDRESS_NAME_IGNORED", "en" }, { kPatterns__0__ADDRESS_NAME_IGNORED__en } },
        { { "ADDRESS_NAME_IGNORED", "es" }, { kPatterns__0__ADDRESS_NAME_IGNORED__es } },
        { { "ADDRESS_NAME_IGNORED", "id" }, { kPatterns__0__ADDRESS_NAME_IGNORED__id } },
        { { "ADDRESS_NAME_IGNORED", "pt" }, { kPatterns__0__ADDRESS_NAME_IGNORED__pt } },
        { { "ADDRESS_NAME_IGNORED", "tr" }, { kPatterns__0__ADDRESS_NAME_IGNORED__tr } },
        { { "ADMIN_LEVEL_2", "" }, { kPatterns__0__ADMIN_LEVEL_2 } },
        { { "ADMIN_LEVEL_2", "es" }, { kPatterns__0__ADMIN_LEVEL_2__es } },
        { { "ADMIN_LEVEL_2", "pt" }, { kPatterns__0__ADMIN_LEVEL_2__pt } },
        { { "ALTERNATIVE_FAMILY_NAME", "" }, { kPatterns__0__ALTERNATIVE_FAMILY_NAME } },
        { { "ALTERNATIVE_FAMILY_NAME", "en" }, { kPatterns__0__ALTERNATIVE_FAMILY_NAME__en } },
        { { "ALTERNATIVE_FULL_NAME", "" }, { kPatterns__0__ALTERNATIVE_FULL_NAME } },
        { { "ALTERNATIVE_FULL_NAME", "en" }, { kPatterns__0__ALTERNATIVE_FULL_NAME__en } },
        { { "ALTERNATIVE_GIVEN_NAME", "" }, { kPatterns__0__ALTERNATIVE_GIVEN_NAME } },
        { { "ALTERNATIVE_GIVEN_NAME", "en" }, { kPatterns__0__ALTERNATIVE_GIVEN_NAME__en } },
        { { "ATTENTION_IGNORED", "" }, { kPatterns__0__ATTENTION_IGNORED } },
        { { "ATTENTION_IGNORED", "en" }, { kPatterns__0__ATTENTION_IGNORED__en } },
        { { "AUGMENTED_PHONE_COUNTRY_CODE", "" }, { kPatterns__0__AUGMENTED_PHONE_COUNTRY_CODE } },
        { { "AUGMENTED_PHONE_COUNTRY_CODE", "en" }, { kPatterns__0__AUGMENTED_PHONE_COUNTRY_CODE__en } },
        { { "BETWEEN_STREETS", "" }, { kPatterns__0__BETWEEN_STREETS } },
        { { "BETWEEN_STREETS", "en" }, { kPatterns__0__BETWEEN_STREETS__en } },
        { { "BETWEEN_STREETS", "es" }, { kPatterns__0__BETWEEN_STREETS__es } },
        { { "BETWEEN_STREETS_LINE_1", "" }, { kPatterns__0__BETWEEN_STREETS_LINE_1 } },
        { { "BETWEEN_STREETS_LINE_1", "es" }, { kPatterns__0__BETWEEN_STREETS_LINE_1__es } },
        { { "BETWEEN_STREETS_LINE_2", "" }, { kPatterns__0__BETWEEN_STREETS_LINE_2 } },
        { { "BETWEEN_STREETS_LINE_2", "es" }, { kPatterns__0__BETWEEN_STREETS_LINE_2__es } },
        { { "BETWEEN_STREETS_OR_LANDMARK", "" }, { kPatterns__0__BETWEEN_STREETS_OR_LANDMARK } },
        { { "BETWEEN_STREETS_OR_LANDMARK", "en" }, { kPatterns__0__BETWEEN_STREETS_OR_LANDMARK__en } },
        { { "BETWEEN_STREETS_OR_LANDMARK", "es" }, { kPatterns__0__BETWEEN_STREETS_OR_LANDMARK__es } },
        { { "CITY", "" }, { kPatterns__0__CITY } },
        { { "CITY", "de" }, { kPatterns__0__CITY__de } },
        { { "CITY", "en" }, { kPatterns__0__CITY__en } },
        { { "CITY", "es" }, { kPatterns__0__CITY__es } },
        { { "CITY", "fa" }, { kPatterns__0__CITY__fa } },
        { { "CITY", "fr" }, { kPatterns__0__CITY__fr } },
        { { "CITY", "hi" }, { kPatterns__0__CITY__hi } },
        { { "CITY", "id" }, { kPatterns__0__CITY__id } },
        { { "CITY", "it" }, { kPatterns__0__CITY__it } },
        { { "CITY", "ja" }, { kPatterns__0__CITY__ja } },
        { { "CITY", "ko" }, { kPatterns__0__CITY__ko } },
        { { "CITY", "ml" }, { kPatterns__0__CITY__ml } },
        { { "CITY", "pl" }, { kPatterns__0__CITY__pl } },
        { { "CITY", "pt" }, { kPatterns__0__CITY__pt } },
        { { "CITY", "ru" }, { kPatterns__0__CITY__ru } },
        { { "CITY", "tr" }, { kPatterns__0__CITY__tr } },
        { { "CITY", "zh-TW" }, { kPatterns__0__CITY__zh_TW } },
        { { "COMPANY_NAME", "" }, { kPatterns__0__COMPANY_NAME } },
        { { "COMPANY_NAME", "de" }, { kPatterns__0__COMPANY_NAME__de } },
        { { "COMPANY_NAME", "en" }, { kPatterns__0__COMPANY_NAME__en } },
        { { "COMPANY_NAME", "es" }, { kPatterns__0__COMPANY_NAME__es } },
        { { "COMPANY_NAME", "fa" }, { kPatterns__0__COMPANY_NAME__fa } },
        { { "COMPANY_NAME", "fr" }, { kPatterns__0__COMPANY_NAME__fr } },
        { { "COMPANY_NAME", "id" }, { kPatterns__0__COMPANY_NAME__id } },
        { { "COMPANY_NAME", "it" }, { kPatterns__0__COMPANY_NAME__it } },
        { { "COMPANY_NAME", "ja" }, { kPatterns__0__COMPANY_NAME__ja } },
        { { "COMPANY_NAME", "ko" }, { kPatterns__0__COMPANY_NAME__ko } },
        { { "COMPANY_NAME", "ru" }, { kPatterns__0__COMPANY_NAME__ru } },
        { { "COMPANY_NAME", "zh-CN" }, { kPatterns__0__COMPANY_NAME__zh_CN } },
        { { "COUNTRY", "" }, { kPatterns__0__COUNTRY } },
        { { "COUNTRY", "de" }, { kPatterns__0__COUNTRY__de } },
        { { "COUNTRY", "en" }, { kPatterns__0__COUNTRY__en } },
        { { "COUNTRY", "es" }, { kPatterns__0__COUNTRY__es } },
        { { "COUNTRY", "fa" }, { kPatterns__0__COUNTRY__fa } },
        { { "COUNTRY", "fr" }, { kPatterns__0__COUNTRY__fr } },
        { { "COUNTRY", "id" }, { kPatterns__0__COUNTRY__id } },
        { { "COUNTRY", "it" }, { kPatterns__0__COUNTRY__it } },
        { { "COUNTRY", "ja" }, { kPatterns__0__COUNTRY__ja } },
        { { "COUNTRY", "ko" }, { kPatterns__0__COUNTRY__ko } },
        { { "COUNTRY", "pl" }, { kPatterns__0__COUNTRY__pl } },
        { { "COUNTRY", "tr" }, { kPatterns__0__COUNTRY__tr } },
        { { "COUNTRY", "zh-CN" }, { kPatterns__0__COUNTRY__zh_CN } },
        { { "COUNTRY_LOCATION", "" }, { kPatterns__0__COUNTRY_LOCATION } },
        { { "COUNTRY_LOCATION", "en" }, { kPatterns__0__COUNTRY_LOCATION__en } },
        { { "CREDIT_CARD_EXP_DATE", "" }, { kPatterns__0__CREDIT_CARD_EXP_DATE } },
        { { "CREDIT_CARD_EXP_DATE", "de" }, { kPatterns__0__CREDIT_CARD_EXP_DATE__de } },
        { { "CREDIT_CARD_EXP_DATE", "en" }, { kPatterns__0__CREDIT_CARD_EXP_DATE__en } },
        { { "CREDIT_CARD_EXP_DATE", "es" }, { kPatterns__0__CREDIT_CARD_EXP_DATE__es } },
        { { "CREDIT_CARD_EXP_DATE", "fr" }, { kPatterns__0__CREDIT_CARD_EXP_DATE__fr } },
        { { "CREDIT_CARD_EXP_DATE", "it" }, { kPatterns__0__CREDIT_CARD_EXP_DATE__it } },
        { { "CREDIT_CARD_EXP_DATE", "ja" }, { kPatterns__0__CREDIT_CARD_EXP_DATE__ja } },
        { { "CREDIT_CARD_EXP_DATE", "pt" }, { kPatterns__0__CREDIT_CARD_EXP_DATE__pt } },
        { { "CREDIT_CARD_EXP_DATE", "ru" }, { kPatterns__0__CREDIT_CARD_EXP_DATE__ru } },
        { { "CREDIT_CARD_EXP_DATE_2_DIGIT_YEAR", "" }, { kPatterns__0__CREDIT_CARD_EXP_DATE_2_DIGIT_YEAR } },
        { { "CREDIT_CARD_EXP_DATE_2_DIGIT_YEAR", "en" }, { kPatterns__0__CREDIT_CARD_EXP_DATE_2_DIGIT_YEAR__en } },
        { { "CREDIT_CARD_EXP_DATE_4_DIGIT_YEAR", "" }, { kPatterns__0__CREDIT_CARD_EXP_DATE_4_DIGIT_YEAR } },
        { { "CREDIT_CARD_EXP_DATE_4_DIGIT_YEAR", "en" }, { kPatterns__0__CREDIT_CARD_EXP_DATE_4_DIGIT_YEAR__en } },
        { { "CREDIT_CARD_EXP_MONTH", "" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH } },
        { { "CREDIT_CARD_EXP_MONTH", "de" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__de } },
        { { "CREDIT_CARD_EXP_MONTH", "en" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__en } },
        { { "CREDIT_CARD_EXP_MONTH", "es" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__es } },
        { { "CREDIT_CARD_EXP_MONTH", "fr" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__fr } },
        { { "CREDIT_CARD_EXP_MONTH", "id" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__id } },
        { { "CREDIT_CARD_EXP_MONTH", "it" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__it } },
        { { "CREDIT_CARD_EXP_MONTH", "ja" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__ja } },
        { { "CREDIT_CARD_EXP_MONTH", "pt" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__pt } },
        { { "CREDIT_CARD_EXP_MONTH", "ru" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__ru } },
        { { "CREDIT_CARD_EXP_MONTH", "zh-CN" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH__zh_CN } },
        { { "CREDIT_CARD_EXP_MONTH_BEFORE_YEAR", "" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH_BEFORE_YEAR } },
        { { "CREDIT_CARD_EXP_MONTH_BEFORE_YEAR", "en" }, { kPatterns__0__CREDIT_CARD_EXP_MONTH_BEFORE_YEAR__en } },
        { { "CREDIT_CARD_EXP_YEAR", "" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR } },
        { { "CREDIT_CARD_EXP_YEAR", "de" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__de } },
        { { "CREDIT_CARD_EXP_YEAR", "en" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__en } },
        { { "CREDIT_CARD_EXP_YEAR", "es" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__es } },
        { { "CREDIT_CARD_EXP_YEAR", "id" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__id } },
        { { "CREDIT_CARD_EXP_YEAR", "it" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__it } },
        { { "CREDIT_CARD_EXP_YEAR", "ja" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__ja } },
        { { "CREDIT_CARD_EXP_YEAR", "pt" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__pt } },
        { { "CREDIT_CARD_EXP_YEAR", "ru" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__ru } },
        { { "CREDIT_CARD_EXP_YEAR", "zh-CN" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR__zh_CN } },
        { { "CREDIT_CARD_EXP_YEAR_AFTER_MONTH", "" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR_AFTER_MONTH } },
        { { "CREDIT_CARD_EXP_YEAR_AFTER_MONTH", "en" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR_AFTER_MONTH__en } },
        { { "CREDIT_CARD_EXP_YEAR_AFTER_MONTH_EXPERIMENTAL", "" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR_AFTER_MONTH_EXPERIMENTAL } },
        { { "CREDIT_CARD_EXP_YEAR_AFTER_MONTH_EXPERIMENTAL", "en" }, { kPatterns__0__CREDIT_CARD_EXP_YEAR_AFTER_MONTH_EXPERIMENTAL__en } },
        { { "CREDIT_CARD_NUMBER", "" }, { kPatterns__0__CREDIT_CARD_NUMBER } },
        { { "CREDIT_CARD_NUMBER", "de" }, { kPatterns__0__CREDIT_CARD_NUMBER__de } },
        { { "CREDIT_CARD_NUMBER", "en" }, { kPatterns__0__CREDIT_CARD_NUMBER__en } },
        { { "CREDIT_CARD_NUMBER", "es" }, { kPatterns__0__CREDIT_CARD_NUMBER__es } },
        { { "CREDIT_CARD_NUMBER", "fr" }, { kPatterns__0__CREDIT_CARD_NUMBER__fr } },
        { { "CREDIT_CARD_NUMBER", "id" }, { kPatterns__0__CREDIT_CARD_NUMBER__id } },
        { { "CREDIT_CARD_NUMBER", "ja" }, { kPatterns__0__CREDIT_CARD_NUMBER__ja } },
        { { "CREDIT_CARD_NUMBER", "ko" }, { kPatterns__0__CREDIT_CARD_NUMBER__ko } },
        { { "CREDIT_CARD_NUMBER", "pt" }, { kPatterns__0__CREDIT_CARD_NUMBER__pt } },
        { { "CREDIT_CARD_NUMBER", "ru" }, { kPatterns__0__CREDIT_CARD_NUMBER__ru } },
        { { "CREDIT_CARD_NUMBER", "zh-CN" }, { kPatterns__0__CREDIT_CARD_NUMBER__zh_CN } },
        { { "CREDIT_CARD_NUMBER", "zh-TW" }, { kPatterns__0__CREDIT_CARD_NUMBER__zh_TW } },
        { { "CREDIT_CARD_VERIFICATION_CODE", "" }, { kPatterns__0__CREDIT_CARD_VERIFICATION_CODE } },
        { { "CREDIT_CARD_VERIFICATION_CODE", "br" }, { kPatterns__0__CREDIT_CARD_VERIFICATION_CODE__br } },
        { { "CREDIT_CARD_VERIFICATION_CODE", "de" }, { kPatterns__0__CREDIT_CARD_VERIFICATION_CODE__de } },
        { { "CREDIT_CARD_VERIFICATION_CODE", "en" }, { kPatterns__0__CREDIT_CARD_VERIFICATION_CODE__en } },
        { { "CREDIT_CARD_VERIFICATION_CODE", "es" }, { kPatterns__0__CREDIT_CARD_VERIFICATION_CODE__es } },
        { { "DAY", "" }, { kPatterns__0__DAY } },
        { { "DAY", "en" }, { kPatterns__0__DAY__en } },
        { { "DEBIT_CARD", "" }, { kPatterns__0__DEBIT_CARD } },
        { { "DEBIT_CARD", "en" }, { kPatterns__0__DEBIT_CARD__en } },
        { { "DEBIT_GIFT_CARD", "" }, { kPatterns__0__DEBIT_GIFT_CARD } },
        { { "DEBIT_GIFT_CARD", "en" }, { kPatterns__0__DEBIT_GIFT_CARD__en } },
        { { "EMAIL_ADDRESS", "" }, { kPatterns__0__EMAIL_ADDRESS } },
        { { "EMAIL_ADDRESS", "en" }, { kPatterns__0__EMAIL_ADDRESS__en } },
        { { "EMAIL_ADDRESS", "es" }, { kPatterns__0__EMAIL_ADDRESS__es } },
        { { "EMAIL_ADDRESS", "fa" }, { kPatterns__0__EMAIL_ADDRESS__fa } },
        { { "EMAIL_ADDRESS", "fr" }, { kPatterns__0__EMAIL_ADDRESS__fr } },
        { { "EMAIL_ADDRESS", "hi" }, { kPatterns__0__EMAIL_ADDRESS__hi } },
        { { "EMAIL_ADDRESS", "ja" }, { kPatterns__0__EMAIL_ADDRESS__ja } },
        { { "EMAIL_ADDRESS", "ko" }, { kPatterns__0__EMAIL_ADDRESS__ko } },
        { { "EMAIL_ADDRESS", "ml" }, { kPatterns__0__EMAIL_ADDRESS__ml } },
        { { "EMAIL_ADDRESS", "ru" }, { kPatterns__0__EMAIL_ADDRESS__ru } },
        { { "EMAIL_ADDRESS", "tr" }, { kPatterns__0__EMAIL_ADDRESS__tr } },
        { { "EMAIL_ADDRESS", "zh-CN" }, { kPatterns__0__EMAIL_ADDRESS__zh_CN } },
        { { "EMAIL_ADDRESS", "zh-TW" }, { kPatterns__0__EMAIL_ADDRESS__zh_TW } },
        { { "FIRST_NAME", "" }, { kPatterns__0__FIRST_NAME } },
        { { "FIRST_NAME", "de" }, { kPatterns__0__FIRST_NAME__de } },
        { { "FIRST_NAME", "en" }, { kPatterns__0__FIRST_NAME__en } },
        { { "FIRST_NAME", "es" }, { kPatterns__0__FIRST_NAME__es } },
        { { "FIRST_NAME", "fa" }, { kPatterns__0__FIRST_NAME__fa } },
        { { "FIRST_NAME", "fr" }, { kPatterns__0__FIRST_NAME__fr } },
        { { "FIRST_NAME", "hi" }, { kPatterns__0__FIRST_NAME__hi } },
        { { "FIRST_NAME", "id" }, { kPatterns__0__FIRST_NAME__id } },
        { { "FIRST_NAME", "ja" }, { kPatterns__0__FIRST_NAME__ja } },
        { { "FIRST_NAME", "ko" }, { kPatterns__0__FIRST_NAME__ko } },
        { { "FIRST_NAME", "ml" }, { kPatterns__0__FIRST_NAME__ml } },
        { { "FIRST_NAME", "pt" }, { kPatterns__0__FIRST_NAME__pt } },
        { { "FIRST_NAME", "ru" }, { kPatterns__0__FIRST_NAME__ru } },
        { { "FIRST_NAME", "tr" }, { kPatterns__0__FIRST_NAME__tr } },
        { { "FLIGHT", "" }, { kPatterns__0__FLIGHT } },
        { { "FLIGHT", "en" }, { kPatterns__0__FLIGHT__en } },
        { { "FLIGHT", "es" }, { kPatterns__0__FLIGHT__es } },
        { { "FLIGHT", "ja" }, { kPatterns__0__FLIGHT__ja } },
        { { "FULL_NAME", "" }, { kPatterns__0__FULL_NAME } },
        { { "FULL_NAME", "de" }, { kPatterns__0__FULL_NAME__de } },
        { { "FULL_NAME", "en" }, { kPatterns__0__FULL_NAME__en } },
        { { "FULL_NAME", "es" }, { kPatterns__0__FULL_NAME__es } },
        { { "FULL_NAME", "fa" }, { kPatterns__0__FULL_NAME__fa } },
        { { "FULL_NAME", "fr" }, { kPatterns__0__FULL_NAME__fr } },
        { { "FULL_NAME", "id" }, { kPatterns__0__FULL_NAME__id } },
        { { "FULL_NAME", "ja" }, { kPatterns__0__FULL_NAME__ja } },
        { { "FULL_NAME", "ko" }, { kPatterns__0__FULL_NAME__ko } },
        { { "FULL_NAME", "pt" }, { kPatterns__0__FULL_NAME__pt } },
        { { "FULL_NAME", "ru" }, { kPatterns__0__FULL_NAME__ru } },
        { { "FULL_NAME", "tr" }, { kPatterns__0__FULL_NAME__tr } },
        { { "FULL_NAME", "zh-CN" }, { kPatterns__0__FULL_NAME__zh_CN } },
        { { "GIFT_CARD", "" }, { kPatterns__0__GIFT_CARD } },
        { { "GIFT_CARD", "en" }, { kPatterns__0__GIFT_CARD__en } },
        { { "HONORIFIC_PREFIX", "" }, { kPatterns__0__HONORIFIC_PREFIX } },
        { { "HONORIFIC_PREFIX", "de" }, { kPatterns__0__HONORIFIC_PREFIX__de } },
        { { "HONORIFIC_PREFIX", "el" }, { kPatterns__0__HONORIFIC_PREFIX__el } },
        { { "HONORIFIC_PREFIX", "en" }, { kPatterns__0__HONORIFIC_PREFIX__en } },
        { { "HONORIFIC_PREFIX", "es" }, { kPatterns__0__HONORIFIC_PREFIX__es } },
        { { "HONORIFIC_PREFIX", "fr" }, { kPatterns__0__HONORIFIC_PREFIX__fr } },
        { { "HONORIFIC_PREFIX", "it" }, { kPatterns__0__HONORIFIC_PREFIX__it } },
        { { "HONORIFIC_PREFIX", "ru" }, { kPatterns__0__HONORIFIC_PREFIX__ru } },
        { { "HONORIFIC_PREFIX", "tr" }, { kPatterns__0__HONORIFIC_PREFIX__tr } },
        { { "IBAN_VALUE", "" }, { kPatterns__0__IBAN_VALUE } },
        { { "IBAN_VALUE", "en" }, { kPatterns__0__IBAN_VALUE__en } },
        { { "IN_DEPENDENT_LOCALITY", "" }, { kPatterns__0__IN_DEPENDENT_LOCALITY } },
        { { "IN_DEPENDENT_LOCALITY", "en" }, { kPatterns__0__IN_DEPENDENT_LOCALITY__en } },
        { { "IN_STREET_LOCATION", "" }, { kPatterns__0__IN_STREET_LOCATION } },
        { { "IN_STREET_LOCATION", "en" }, { kPatterns__0__IN_STREET_LOCATION__en } },
        { { "LANDMARK", "" }, { kPatterns__0__LANDMARK } },
        { { "LANDMARK", "en" }, { kPatterns__0__LANDMARK__en } },
        { { "LANDMARK", "es" }, { kPatterns__0__LANDMARK__es } },
        { { "LANDMARK", "pt" }, { kPatterns__0__LANDMARK__pt } },
        { { "LAST_NAME", "" }, { kPatterns__0__LAST_NAME } },
        { { "LAST_NAME", "de" }, { kPatterns__0__LAST_NAME__de } },
        { { "LAST_NAME", "en" }, { kPatterns__0__LAST_NAME__en } },
        { { "LAST_NAME", "es" }, { kPatterns__0__LAST_NAME__es } },
        { { "LAST_NAME", "fa" }, { kPatterns__0__LAST_NAME__fa } },
        { { "LAST_NAME", "fr" }, { kPatterns__0__LAST_NAME__fr } },
        { { "LAST_NAME", "hi" }, { kPatterns__0__LAST_NAME__hi } },
        { { "LAST_NAME", "id" }, { kPatterns__0__LAST_NAME__id } },
        { { "LAST_NAME", "it" }, { kPatterns__0__LAST_NAME__it } },
        { { "LAST_NAME", "ja" }, { kPatterns__0__LAST_NAME__ja } },
        { { "LAST_NAME", "ko" }, { kPatterns__0__LAST_NAME__ko } },
        { { "LAST_NAME", "ml" }, { kPatterns__0__LAST_NAME__ml } },
        { { "LAST_NAME", "pt" }, { kPatterns__0__LAST_NAME__pt } },
        { { "LAST_NAME", "ru" }, { kPatterns__0__LAST_NAME__ru } },
        { { "LAST_NAME", "tr" }, { kPatterns__0__LAST_NAME__tr } },
        { { "LAST_NAME_FIRST", "" }, { kPatterns__0__LAST_NAME_FIRST } },
        { { "LAST_NAME_FIRST", "es" }, { kPatterns__0__LAST_NAME_FIRST__es } },
        { { "LAST_NAME_SECOND", "" }, { kPatterns__0__LAST_NAME_SECOND } },
        { { "LAST_NAME_SECOND", "es" }, { kPatterns__0__LAST_NAME_SECOND__es } },
        { { "MERCHANT_PROMO_CODE", "" }, { kPatterns__0__MERCHANT_PROMO_CODE } },
        { { "MERCHANT_PROMO_CODE", "en" }, { kPatterns__0__MERCHANT_PROMO_CODE__en } },
        { { "MIDDLE_INITIAL", "" }, { kPatterns__0__MIDDLE_INITIAL } },
        { { "MIDDLE_INITIAL", "en" }, { kPatterns__0__MIDDLE_INITIAL__en } },
        { { "MIDDLE_NAME", "" }, { kPatterns__0__MIDDLE_NAME } },
        { { "MIDDLE_NAME", "en" }, { kPatterns__0__MIDDLE_NAME__en } },
        { { "NAME_GENERIC", "" }, { kPatterns__0__NAME_GENERIC } },
        { { "NAME_GENERIC", "en" }, { kPatterns__0__NAME_GENERIC__en } },
        { { "NAME_GENERIC", "fr" }, { kPatterns__0__NAME_GENERIC__fr } },
        { { "NAME_GENERIC", "pt" }, { kPatterns__0__NAME_GENERIC__pt } },
        { { "NAME_IGNORED", "" }, { kPatterns__0__NAME_IGNORED } },
        { { "NAME_IGNORED", "en" }, { kPatterns__0__NAME_IGNORED__en } },
        { { "NAME_IGNORED", "ko" }, { kPatterns__0__NAME_IGNORED__ko } },
        { { "NAME_IGNORED", "zh-CN" }, { kPatterns__0__NAME_IGNORED__zh_CN } },
        { { "NAME_ON_CARD", "" }, { kPatterns__0__NAME_ON_CARD } },
        { { "NAME_ON_CARD", "de" }, { kPatterns__0__NAME_ON_CARD__de } },
        { { "NAME_ON_CARD", "en" }, { kPatterns__0__NAME_ON_CARD__en } },
        { { "NAME_ON_CARD", "es" }, { kPatterns__0__NAME_ON_CARD__es } },
        { { "NAME_ON_CARD", "fr" }, { kPatterns__0__NAME_ON_CARD__fr } },
        { { "NAME_ON_CARD", "id" }, { kPatterns__0__NAME_ON_CARD__id } },
        { { "NAME_ON_CARD", "it" }, { kPatterns__0__NAME_ON_CARD__it } },
        { { "NAME_ON_CARD", "ja" }, { kPatterns__0__NAME_ON_CARD__ja } },
        { { "NAME_ON_CARD", "pt" }, { kPatterns__0__NAME_ON_CARD__pt } },
        { { "NAME_ON_CARD", "ru" }, { kPatterns__0__NAME_ON_CARD__ru } },
        { { "NAME_ON_CARD", "zh-CN" }, { kPatterns__0__NAME_ON_CARD__zh_CN } },
        { { "NAME_ON_CARD_CONTEXTUAL", "" }, { kPatterns__0__NAME_ON_CARD_CONTEXTUAL } },
        { { "NAME_ON_CARD_CONTEXTUAL", "en" }, { kPatterns__0__NAME_ON_CARD_CONTEXTUAL__en } },
        { { "NUMERIC_QUANTITY", "" }, { kPatterns__0__NUMERIC_QUANTITY } },
        { { "NUMERIC_QUANTITY", "en" }, { kPatterns__0__NUMERIC_QUANTITY__en } },
        { { "OVERFLOW", "" }, { kPatterns__0__OVERFLOW } },
        { { "OVERFLOW", "de" }, { kPatterns__0__OVERFLOW__de } },
        { { "OVERFLOW", "fr" }, { kPatterns__0__OVERFLOW__fr } },
        { { "OVERFLOW", "it" }, { kPatterns__0__OVERFLOW__it } },
        { { "OVERFLOW", "pt" }, { kPatterns__0__OVERFLOW__pt } },
        { { "OVERFLOW_AND_LANDMARK", "" }, { kPatterns__0__OVERFLOW_AND_LANDMARK } },
        { { "OVERFLOW_AND_LANDMARK", "en" }, { kPatterns__0__OVERFLOW_AND_LANDMARK__en } },
        { { "OVERFLOW_AND_LANDMARK", "pt" }, { kPatterns__0__OVERFLOW_AND_LANDMARK__pt } },
        { { "PASSPORT", "" }, { kPatterns__0__PASSPORT } },
        { { "PASSPORT", "en" }, { kPatterns__0__PASSPORT__en } },
        { { "PASSPORT", "es" }, { kPatterns__0__PASSPORT__es } },
        { { "PASSPORT", "fr" }, { kPatterns__0__PASSPORT__fr } },
        { { "PASSPORT", "ja" }, { kPatterns__0__PASSPORT__ja } },
        { { "PATTERN_SOURCE_DUMMY", "" }, { kPatterns__0__PATTERN_SOURCE_DUMMY } },
        { { "PATTERN_SOURCE_DUMMY", "en" }, { kPatterns__0__PATTERN_SOURCE_DUMMY__en } },
        { { "PHONE", "" }, { kPatterns__0__PHONE } },
        { { "PHONE", "de" }, { kPatterns__0__PHONE__de } },
        { { "PHONE", "en" }, { kPatterns__0__PHONE__en } },
        { { "PHONE", "es" }, { kPatterns__0__PHONE__es } },
        { { "PHONE", "fr" }, { kPatterns__0__PHONE__fr } },
        { { "PHONE", "hi" }, { kPatterns__0__PHONE__hi } },
        { { "PHONE", "id" }, { kPatterns__0__PHONE__id } },
        { { "PHONE", "ja" }, { kPatterns__0__PHONE__ja } },
        { { "PHONE", "ko" }, { kPatterns__0__PHONE__ko } },
        { { "PHONE", "ml" }, { kPatterns__0__PHONE__ml } },
        { { "PHONE", "pt" }, { kPatterns__0__PHONE__pt } },
        { { "PHONE", "ru" }, { kPatterns__0__PHONE__ru } },
        { { "PHONE", "tr" }, { kPatterns__0__PHONE__tr } },
        { { "PHONE", "zh-CN" }, { kPatterns__0__PHONE__zh_CN } },
        { { "PHONE_AREA_CODE", "" }, { kPatterns__0__PHONE_AREA_CODE } },
        { { "PHONE_AREA_CODE", "en" }, { kPatterns__0__PHONE_AREA_CODE__en } },
        { { "PHONE_AREA_CODE", "ko" }, { kPatterns__0__PHONE_AREA_CODE__ko } },
        { { "PHONE_AREA_CODE_NO_TEXT", "" }, { kPatterns__0__PHONE_AREA_CODE_NO_TEXT } },
        { { "PHONE_AREA_CODE_NO_TEXT", "en" }, { kPatterns__0__PHONE_AREA_CODE_NO_TEXT__en } },
        { { "PHONE_COUNTRY_CODE", "" }, { kPatterns__0__PHONE_COUNTRY_CODE } },
        { { "PHONE_COUNTRY_CODE", "en" }, { kPatterns__0__PHONE_COUNTRY_CODE__en } },
        { { "PHONE_EXTENSION", "" }, { kPatterns__0__PHONE_EXTENSION } },
        { { "PHONE_EXTENSION", "en" }, { kPatterns__0__PHONE_EXTENSION__en } },
        { { "PHONE_EXTENSION", "pt" }, { kPatterns__0__PHONE_EXTENSION__pt } },
        { { "PHONE_PREFIX", "" }, { kPatterns__0__PHONE_PREFIX } },
        { { "PHONE_PREFIX", "en" }, { kPatterns__0__PHONE_PREFIX__en } },
        { { "PHONE_PREFIX", "fr" }, { kPatterns__0__PHONE_PREFIX__fr } },
        { { "PHONE_PREFIX", "pt" }, { kPatterns__0__PHONE_PREFIX__pt } },
        { { "PHONE_PREFIX_SEPARATOR", "" }, { kPatterns__0__PHONE_PREFIX_SEPARATOR } },
        { { "PHONE_PREFIX_SEPARATOR", "en" }, { kPatterns__0__PHONE_PREFIX_SEPARATOR__en } },
        { { "PHONE_SUFFIX", "" }, { kPatterns__0__PHONE_SUFFIX } },
        { { "PHONE_SUFFIX", "en" }, { kPatterns__0__PHONE_SUFFIX__en } },
        { { "PHONE_SUFFIX_SEPARATOR", "" }, { kPatterns__0__PHONE_SUFFIX_SEPARATOR } },
        { { "PHONE_SUFFIX_SEPARATOR", "en" }, { kPatterns__0__PHONE_SUFFIX_SEPARATOR__en } },
        { { "PRICE", "" }, { kPatterns__0__PRICE } },
        { { "PRICE", "ar" }, { kPatterns__0__PRICE__ar } },
        { { "PRICE", "en" }, { kPatterns__0__PRICE__en } },
        { { "PRICE", "fa" }, { kPatterns__0__PRICE__fa } },
        { { "PRICE", "fr" }, { kPatterns__0__PRICE__fr } },
        { { "REGION_IGNORED", "" }, { kPatterns__0__REGION_IGNORED } },
        { { "REGION_IGNORED", "en" }, { kPatterns__0__REGION_IGNORED__en } },
        { { "REGION_IGNORED", "es" }, { kPatterns__0__REGION_IGNORED__es } },
        { { "REGION_IGNORED", "pt" }, { kPatterns__0__REGION_IGNORED__pt } },
        { { "SEARCH_TERM", "" }, { kPatterns__0__SEARCH_TERM } },
        { { "SEARCH_TERM", "de" }, { kPatterns__0__SEARCH_TERM__de } },
        { { "SEARCH_TERM", "en" }, { kPatterns__0__SEARCH_TERM__en } },
        { { "SEARCH_TERM", "fa" }, { kPatterns__0__SEARCH_TERM__fa } },
        { { "SEARCH_TERM", "fr" }, { kPatterns__0__SEARCH_TERM__fr } },
        { { "SEARCH_TERM", "ja" }, { kPatterns__0__SEARCH_TERM__ja } },
        { { "SEARCH_TERM", "pt" }, { kPatterns__0__SEARCH_TERM__pt } },
        { { "SEARCH_TERM", "ru" }, { kPatterns__0__SEARCH_TERM__ru } },
        { { "SEARCH_TERM", "zh-CN" }, { kPatterns__0__SEARCH_TERM__zh_CN } },
        { { "STATE", "" }, { kPatterns__0__STATE } },
        { { "STATE", "en" }, { kPatterns__0__STATE__en } },
        { { "STATE", "fa" }, { kPatterns__0__STATE__fa } },
        { { "STATE", "hi" }, { kPatterns__0__STATE__hi } },
        { { "STATE", "id" }, { kPatterns__0__STATE__id } },
        { { "STATE", "ja" }, { kPatterns__0__STATE__ja } },
        { { "STATE", "ko" }, { kPatterns__0__STATE__ko } },
        { { "STATE", "ml" }, { kPatterns__0__STATE__ml } },
        { { "STATE", "pt" }, { kPatterns__0__STATE__pt } },
        { { "STATE", "ru" }, { kPatterns__0__STATE__ru } },
        { { "STATE", "tr" }, { kPatterns__0__STATE__tr } },
        { { "STATE", "zh-TW" }, { kPatterns__0__STATE__zh_TW } },
        { { "TRAVEL_DESTINATION", "" }, { kPatterns__0__TRAVEL_DESTINATION } },
        { { "TRAVEL_DESTINATION", "en" }, { kPatterns__0__TRAVEL_DESTINATION__en } },
        { { "TRAVEL_DESTINATION", "es" }, { kPatterns__0__TRAVEL_DESTINATION__es } },
        { { "TRAVEL_DESTINATION", "ja" }, { kPatterns__0__TRAVEL_DESTINATION__ja } },
        { { "TRAVEL_ORIGIN", "" }, { kPatterns__0__TRAVEL_ORIGIN } },
        { { "TRAVEL_ORIGIN", "en" }, { kPatterns__0__TRAVEL_ORIGIN__en } },
        { { "TRAVEL_ORIGIN", "es" }, { kPatterns__0__TRAVEL_ORIGIN__es } },
        { { "TRAVEL_ORIGIN", "ja" }, { kPatterns__0__TRAVEL_ORIGIN__ja } },
        { { "ZIP_4", "" }, { kPatterns__0__ZIP_4 } },
        { { "ZIP_4", "en" }, { kPatterns__0__ZIP_4__en } },
        { { "ZIP_4", "pt" }, { kPatterns__0__ZIP_4__pt } },
        { { "ZIP_CODE", "" }, { kPatterns__0__ZIP_CODE } },
        { { "ZIP_CODE", "de" }, { kPatterns__0__ZIP_CODE__de } },
        { { "ZIP_CODE", "en" }, { kPatterns__0__ZIP_CODE__en } },
        { { "ZIP_CODE", "es" }, { kPatterns__0__ZIP_CODE__es } },
        { { "ZIP_CODE", "fr" }, { kPatterns__0__ZIP_CODE__fr } },
        { { "ZIP_CODE", "hi" }, { kPatterns__0__ZIP_CODE__hi } },
        { { "ZIP_CODE", "id" }, { kPatterns__0__ZIP_CODE__id } },
        { { "ZIP_CODE", "it" }, { kPatterns__0__ZIP_CODE__it } },
        { { "ZIP_CODE", "ja" }, { kPatterns__0__ZIP_CODE__ja } },
        { { "ZIP_CODE", "ko" }, { kPatterns__0__ZIP_CODE__ko } },
        { { "ZIP_CODE", "ml" }, { kPatterns__0__ZIP_CODE__ml } },
        { { "ZIP_CODE", "pl" }, { kPatterns__0__ZIP_CODE__pl } },
        { { "ZIP_CODE", "pt" }, { kPatterns__0__ZIP_CODE__pt } },
        { { "ZIP_CODE", "ru" }, { kPatterns__0__ZIP_CODE__ru } },
        { { "ZIP_CODE", "tr" }, { kPatterns__0__ZIP_CODE__tr } },
        { { "ZIP_CODE", "zh-CN" }, { kPatterns__0__ZIP_CODE__zh_CN } },
        { { "ZIP_CODE", "zh-TW" }, { kPatterns__0__ZIP_CODE__zh_TW } },
    },
    NameAndLanguageComparator());

// The set of language codes across all language source ids and
// pattern names.
constexpr auto kLanguages = base::MakeFixedFlatSet<const char*>(
    { "ar", "br", "de", "el", "en", "es", "fa", "fr", "hi", "id", "it", "ja", "ko", "ml", "pl", "pt", "ru", "tr", "zh-CN", "zh-TW" }, LanguageComparator());

} // namespace autofill

#endif // COMPONENTS_AUTOFILL_CORE_BROWSER_FORM_PARSING_REGEX_PATTERNS_INL_H_
