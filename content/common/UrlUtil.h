
#ifndef content_UrlUtil_h
#define content_UrlUtil_h

#include "content/common/StringUtil.h"
#include "content/common/mbchar.h"

namespace content {

class UrlUtil {
public:
    // 从后往前找这几个字符串
    static int backwardSearch(const std::string& input)
    {
        std::string targets[] = { "\\", "//", "/", "%2f", "%2F", "%5c", "%5C" };
        for (int i = input.length() - 1; i >= 0; --i) {
            for (const auto& target : targets) {
                if (i >= static_cast<int>(target.length()) - 1) {
                    std::string substr = input.substr(i - target.length() + 1, target.length());
                    if (substr == target) {
                        return i + 1;
                    }
                }
            }
        }
        return -1;
    }

    // "1234-sss.ss?sz"  -> "1234-sss.ss"
    // "1234-sss.ss/" -> "1234-sss.ss"
    static std::u16string getSaveNameFromUrl(const std::string& url)
    {
        if (0 == url.size())
            return std::u16string((const char16_t*)mbu16(""));

//         size_t pos1 = url.find_last_of('\\');
//         if (std::string::npos == pos1)
//             pos1 = url.size() - 1;
//         else
//             pos1++;
// 
//         size_t pos2 = url.find_last_of('/');
//         if (std::string::npos == pos2)
//             pos2 = url.size() - 1;
//         else
//             pos2++;
// 
//         size_t pos = pos1 < pos2 ? pos1 : pos2;
        int pos = backwardSearch(url);
        if (-1 == pos || ((int)(url.size() - 1) == pos))
            pos = 0;

        size_t pos3 = url.find('?', pos);
        if (std::string::npos == pos3)
            pos3 = url.size();

        if (pos3 < pos)
            pos3 = url.size();
        std::string path = url.substr(pos, pos3 - pos);
        return utf8ToUtf16(path);
    }
};

}

#endif // content_UrlUtil_h