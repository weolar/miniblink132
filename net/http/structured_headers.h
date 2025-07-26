// Copyright 2019 The minblink Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_STRUCTURED_HEADERS_H_
#define NET_STRUCTURED_HEADERS_H_

#include "absl/strings/string_view.h"
#include "absl/strings/ascii.h"
#include "absl/types/optional.h"
#include "absl/types/variant.h"
#include "base/check.h"
#include <map>
#include <iosfwd>
#include <cmath>

namespace net {
namespace structured_headers {

#define DIGIT "0123456789"
#define LCALPHA "abcdefghijklmnopqrstuvwxyz"
#define UCALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define TCHAR DIGIT LCALPHA UCALPHA "!#$%&'*+-.^_`|~"
// https://tools.ietf.org/html/draft-ietf-httpbis-header-structure-09#section-3.9
const char kTokenChars09[] = DIGIT UCALPHA LCALPHA "_-.:%*/";
// https://www.rfc-editor.org/rfc/rfc8941.html#section-3.3.4
const char kTokenChars[] = TCHAR ":/";
// https://tools.ietf.org/html/draft-ietf-httpbis-header-structure-09#section-3.1
const char kKeyChars09[] = DIGIT LCALPHA "_-";
// https://www.rfc-editor.org/rfc/rfc8941.html#section-3.1.2
const char kKeyChars[] = DIGIT LCALPHA "_-.*";
const char kSP[] = " ";
const char kOWS[] = " \t";
#undef DIGIT
#undef LCALPHA
#undef UCALPHA

// https://www.rfc-editor.org/rfc/rfc8941.html#section-3.3.1
constexpr int64_t kMaxInteger = 999'999'999'999'999L;
constexpr int64_t kMinInteger = -999'999'999'999'999L;

// Smallest value which is too large for an sh-decimal. This is the smallest
// double which will round up to 1e12 when serialized, which exceeds the range
// for sh-decimal. Any float less than this should round down. This behaviour is
// verified by unit tests.
constexpr double kTooLargeDecimal = 1e12 - 0.0005;

class Item {
public:
    enum ItemType { kNullType, kIntegerType, kDecimalType, kStringType, kTokenType, kByteSequenceType, kBooleanType };
    Item();
    explicit Item(int64_t value);
    explicit Item(double value);
    explicit Item(bool value);

    // Constructors for string-like items: Strings, Tokens and Byte Sequences.
    Item(const char* value, Item::ItemType type = kStringType);
    Item(std::string value, Item::ItemType type = kStringType);

    friend bool operator==(const Item& lhs, const Item& rhs);
    inline friend bool operator!=(const Item& lhs, const Item& rhs)
    {
        return !(lhs == rhs);
    }

    bool is_null() const
    {
        return Type() == kNullType;
    }
    bool is_integer() const
    {
        return Type() == kIntegerType;
    }
    bool is_decimal() const
    {
        return Type() == kDecimalType;
    }
    bool is_string() const
    {
        return Type() == kStringType;
    }
    bool is_token() const
    {
        return Type() == kTokenType;
    }
    bool is_byte_sequence() const
    {
        return Type() == kByteSequenceType;
    }
    bool is_boolean() const
    {
        return Type() == kBooleanType;
    }

    int64_t GetInteger() const
    {
        const auto* value = absl::get_if<int64_t>(&value_);
        CHECK(value);
        return *value;
    }
    double GetDecimal() const
    {
        const auto* value = absl::get_if<double>(&value_);
        CHECK(value);
        return *value;
    }
    bool GetBoolean() const
    {
        const auto* value = absl::get_if<bool>(&value_);
        CHECK(value);
        return *value;
    }
    // TODO(iclelland): Split up accessors for String, Token and Byte Sequence.
    const std::string& GetString() const
    {
        struct Visitor {
            const std::string* operator()(const absl::monostate&)
            {
                return nullptr;
            }
            const std::string* operator()(const int64_t&)
            {
                return nullptr;
            }
            const std::string* operator()(const double&)
            {
                return nullptr;
            }
            const std::string* operator()(const std::string& value)
            {
                return &value;
            }
            const std::string* operator()(const bool&)
            {
                return nullptr;
            }
        };
        const std::string* value = absl::visit(Visitor(), value_);
        CHECK(value);
        return *value;
    }

    ItemType Type() const
    {
        return static_cast<ItemType>(value_.index());
    }

private:
    absl::variant<absl::monostate, int64_t, double, std::string, std::string, std::string, bool> value_;
};

absl::string_view ItemTypeToString(Item::ItemType type);

// Holds a ParameterizedIdentifier (draft 9 only). The contained Item must be a
// Token, and there may be any number of parameters. Parameter ordering is not
// significant.
struct ParameterisedIdentifier {
    using Parameters = std::map<std::string, Item>;

    Item identifier;
    Parameters params;

    ParameterisedIdentifier(const ParameterisedIdentifier&);
    ParameterisedIdentifier& operator=(const ParameterisedIdentifier&);
    ParameterisedIdentifier(Item, Parameters);
    ~ParameterisedIdentifier();
};

inline bool operator==(const ParameterisedIdentifier& lhs, const ParameterisedIdentifier& rhs)
{
    return std::tie(lhs.identifier, lhs.params) == std::tie(rhs.identifier, rhs.params);
}

using Parameters = std::vector<std::pair<std::string, Item>>;

struct ParameterizedItem {
    Item item;
    Parameters params;

    ParameterizedItem(const ParameterizedItem&);
    ParameterizedItem& operator=(const ParameterizedItem&);
    ParameterizedItem(Item, Parameters);
    ~ParameterizedItem();
};

inline bool operator==(const ParameterizedItem& lhs, const ParameterizedItem& rhs)
{
    return std::tie(lhs.item, lhs.params) == std::tie(rhs.item, rhs.params);
}

inline bool operator!=(const ParameterizedItem& lhs, const ParameterizedItem& rhs)
{
    return !(lhs == rhs);
}

// Holds a ParameterizedMember, which may be either an single Item, or an Inner
// List of ParameterizedItems, along with any number of parameters. Parameter
// ordering is significant.
struct ParameterizedMember {
    std::vector<ParameterizedItem> member;
    // If false, then |member| should only hold one Item.
    bool member_is_inner_list = false;

    Parameters params;

    ParameterizedMember();
    ParameterizedMember(const ParameterizedMember&);
    ParameterizedMember& operator=(const ParameterizedMember&);
    ParameterizedMember(std::vector<ParameterizedItem>, bool member_is_inner_list, Parameters);
    // Shorthand constructor for a member which is an inner list.
    ParameterizedMember(std::vector<ParameterizedItem>, Parameters);
    // Shorthand constructor for a member which is a single Item.
    ParameterizedMember(Item, Parameters);
    ~ParameterizedMember();
};

using List = std::vector<ParameterizedMember>;

// Serializer for (a subset of) Structured Field Values for HTTP defined in
// [RFC8941]. Note that this serializer does not attempt to support [SH09].
class StructuredHeaderSerializer {
public:
    StructuredHeaderSerializer() = default;
    ~StructuredHeaderSerializer() = default;
    StructuredHeaderSerializer(const StructuredHeaderSerializer&) = delete;
    StructuredHeaderSerializer& operator=(const StructuredHeaderSerializer&) = delete;

    std::string Output()
    {
        return output_ /*.str()*/;
    }

    // Serializes a List ([RFC8941] 4.1.1).
    bool WriteList(const List& value)
    {
        bool first = true;
        for (const auto& member : value) {
            if (!first)
                output_ += ", ";
            if (!WriteParameterizedMember(member))
                return false;
            first = false;
        }
        return true;
    }

    // Serializes an Item ([RFC8941] 4.1.3).
    bool WriteItem(const ParameterizedItem& value)
    {
        if (!WriteBareItem(value.item))
            return false;
        return WriteParameters(value.params);
    }

    // Serializes an Item ([RFC8941] 4.1.3).
    bool WriteBareItem(const Item& value)
    {
        if (value.is_string()) {
            // Serializes a String ([RFC8941] 4.1.6).
            output_ += "\"";
            for (const char& c : value.GetString()) {
                if (!absl::ascii_isprint(c))
                    return false;
                if (c == '\\' || c == '\"')
                    output_ += "\\";
                output_ += c;
            }
            output_ += "\"";
            return true;
        }
        if (value.is_token()) {
            // Serializes a Token ([RFC8941] 4.1.7).
            if (value.GetString().empty() || !(absl::ascii_isalpha(value.GetString().front()) || value.GetString().front() == '*'))
                return false;
            if (value.GetString().find_first_not_of(kTokenChars) != std::string::npos)
                return false;
            output_ += value.GetString();
            return true;
        }
        if (value.is_byte_sequence()) {
            // Serializes a Byte Sequence ([RFC8941] 4.1.8).
            //             output_ += ":";
            //             output_ += absl::Base64Escape(value.GetString());
            //             output_ += ":";
            *(int*)1 = 1;
            return true;
        }
        if (value.is_integer()) {
            // Serializes an Integer ([RFC8941] 4.1.4).
            if (value.GetInteger() > kMaxInteger || value.GetInteger() < kMinInteger)
                return false;
            output_ += value.GetInteger();
            return true;
        }
        if (value.is_decimal()) {
            // Serializes a Decimal ([RFC8941] 4.1.5).
            double decimal_value = value.GetDecimal();
            if (!std::isfinite(decimal_value) || fabs(decimal_value) >= kTooLargeDecimal)
                return false;

            // Handle sign separately to simplify the rest of the formatting.
            if (decimal_value < 0)
                output_ += "-";
            // Unconditionally take absolute value to ensure that -0 is serialized as
            // "0.0", with no negative sign, as required by spec. (4.1.5, step 2).
            decimal_value = fabs(decimal_value);
            double remainder = fmod(decimal_value, 0.002);
            if (remainder == 0.0005) {
                // Value ended in exactly 0.0005, 0.0025, 0.0045, etc. Round down.
                decimal_value -= 0.0005;
            } else if (remainder == 0.0015) {
                // Value ended in exactly 0.0015, 0.0035, 0,0055, etc. Round up.
                decimal_value += 0.0005;
            } else {
                // Standard rounding will work in all other cases.
                decimal_value = round(decimal_value * 1000.0) / 1000.0;
            }

            // Use standard library functions to write the decimal, and then truncate
            // if necessary to conform to spec.

            // Maximum is 12 integer digits, one decimal point, three fractional
            // digits, and a null terminator.
            char buffer[17];
            //absl::SNPrintF(buffer, std::size(buffer), "%#.3f", decimal_value);
            sprintf(buffer, "%#.3f", decimal_value);

            // Strip any trailing 0s after the decimal point, but leave at least one
            // digit after it in all cases. (So 1.230 becomes 1.23, but 1.000 becomes
            // 1.0.)
            std::string formatted_number(buffer);
            size_t truncate_index = formatted_number.find_last_not_of('0');
            if (formatted_number[truncate_index] == '.')
                truncate_index++;
            output_ += formatted_number.substr(0, truncate_index + 1);
            return true;
        }
        if (value.is_boolean()) {
            // Serializes a Boolean ([RFC8941] 4.1.9).
            output_ += (value.GetBoolean() ? "?1" : "?0");
            return true;
        }
        return false;
    }

    // Serializes a Dictionary ([RFC8941] 4.1.2).
    //     bool WriteDictionary(const Dictionary& value) {
    //         bool first = true;
    //         for (const auto& [dict_key, dict_value] : value) {
    //             if (!first) output_ += ", ";
    //             if (!WriteKey(dict_key)) return false;
    //             first = false;
    //             if (!dict_value.member_is_inner_list && !dict_value.member.empty() &&
    //                 dict_value.member.front().item.is_boolean() &&
    //                 dict_value.member.front().item.GetBoolean()) {
    //                 if (!WriteParameters(dict_value.params)) return false;
    //             } else {
    //                 output_ += "=";
    //                 if (!WriteParameterizedMember(dict_value)) return false;
    //             }
    //         }
    //         return true;
    //     }

private:
    bool WriteParameterizedMember(const ParameterizedMember& value)
    {
        // Serializes a parameterized member ([RFC8941] 4.1.1).
        if (value.member_is_inner_list) {
            if (!WriteInnerList(value.member))
                return false;
        } else {
            CHECK(value.member.size() == 1UL);
            if (!WriteItem(value.member[0]))
                return false;
        }
        return WriteParameters(value.params);
    }

    bool WriteInnerList(const std::vector<ParameterizedItem>& value)
    {
        // Serializes an inner list ([RFC8941] 4.1.1.1).
        output_ += "(";
        bool first = true;
        for (const ParameterizedItem& member : value) {
            if (!first)
                output_ += " ";
            if (!WriteItem(member))
                return false;
            first = false;
        }
        output_ += ")";
        return true;
    }

    bool WriteParameters(const Parameters& value)
    {
        // Serializes a parameter list ([RFC8941] 4.1.1.2).
        for (const auto& param_name_and_value : value) {
            const std::string& param_name = param_name_and_value.first;
            const Item& param_value = param_name_and_value.second;
            output_ += ";";
            if (!WriteKey(param_name))
                return false;
            if (!param_value.is_null()) {
                if (param_value.is_boolean() && param_value.GetBoolean())
                    continue;
                output_ += "=";
                if (!WriteBareItem(param_value))
                    return false;
            }
        }
        return true;
    }

    bool WriteKey(const std::string& value)
    {
        // Serializes a Key ([RFC8941] 4.1.1.3).
        if (value.empty())
            return false;
        if (value.find_first_not_of(kKeyChars) != std::string::npos)
            return false;
        if (!absl::ascii_islower(value[0]) && value[0] != '*')
            return false;
        output_ += value;
        return true;
    }

    std::string output_;
};

absl::optional<std::string> SerializeList(const List& value);

// Structured Headers Draft 09 Parameterised List.
using ParameterisedList = std::vector<ParameterisedIdentifier>;

// Structured Headers Draft 09 List of Lists.
using ListOfLists = std::vector<std::vector<Item>>;
// Structured Headers RFC8941 List.

absl::optional<std::string> SerializeItem(const Item& value);
absl::optional<std::string> SerializeItem(const ParameterizedItem& value);

}
}

#endif