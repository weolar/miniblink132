
#include "net/http/http_response_headers.h"

namespace net {

HttpResponseHeaders::~HttpResponseHeaders() = default;

bool HttpResponseHeaders::GetNormalizedHeader(base::StringPiece name, std::string* value) const
{
    //   // If you hit this assertion, please use EnumerateHeader instead!
    //   DCHECK(!HttpUtil::IsNonCoalescingHeader(name));
    //
    //   value->clear();
    //
    //   bool found = false;
    //   size_t i = 0;
    //   while (i < parsed_.size()) {
    //     i = FindHeader(i, name);
    //     if (i == std::string::npos)
    //       break;
    //
    //     if (found)
    //       value->append(", ");
    //
    //     found = true;
    //
    //     std::string::const_iterator value_begin = parsed_[i].value_begin;
    //     std::string::const_iterator value_end = parsed_[i].value_end;
    //     while (++i < parsed_.size() && parsed_[i].is_continuation())
    //       value_end = parsed_[i].value_end;
    //     value->append(value_begin, value_end);
    //   }
    //
    //   return found;
    *(int*)1 = 1;
    return false;
}

}