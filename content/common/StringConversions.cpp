
#include "content/common/StringConversions.h"
#include "base/strings/utf_string_conversions.h"
#include "third_party/blink/public/platform/file_path_conversion.h"
#include <windows.h>

namespace content {

base::FilePath stringToFilePath(const WTF::String& str)
{
    // #if defined(OS_WIN)
    //     //std::u16string strW = base::UTF8ToUTF16(base::StringPiece(str.Utf8().c_str()));
    //     return base::FilePath::FromUTF8Unsafe(str.Utf8().c_str());
    // #else
    //     return base::FilePath::FromUTF8Unsafe(str.Utf8().c_str());
    // #endif
    return blink::StringToFilePath(str);
}

}
