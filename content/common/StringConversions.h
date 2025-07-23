
#ifndef content_common_StringConversions_h
#define content_common_StringConversions_h

#include "base/files/file_path.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace content {

base::FilePath stringToFilePath(const WTF::String& str);

}

#endif // content_common_StringConversions_h
