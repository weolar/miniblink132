
#include "content/common/WebMimeRegistryImpl.h"

#include "third_party/blink/renderer/platform/wtf/text/ascii_ctype.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hash.h"

// https://opensource.apple.com/source/Libc/Libc-262/gen/fnmatch.c.auto.html
// https://www.cnblogs.com/oloroso/p/6861576.html
#define EOS '\0'

#define RANGE_MATCH 1
#define RANGE_NOMATCH 0
#define RANGE_ERROR (-1)

#define FNM_NOMATCH 1 /* Match failed. */

#define FNM_NOESCAPE 0x01 /* 禁用反斜杠进行转义 */
#define FNM_PATHNAME 0x02 /* 斜杠只能被斜杠匹配(即不能被*或者?匹配) */
#define FNM_PERIOD 0x04 /* Period must be matched by period. */
/*如果这个标志设置了，string 里的起始点号必须匹配 pattern 里的点号。
一个点号被认为是起始点号，如果它是string 第一个字符，或者如果同时设
置了 FNM_PATHNAME，紧跟在斜杠后面的点号。
*/
#define FNM_LEADING_DIR 0x08 /* Ignore /<tail> after Imatch. */
/*如果这个标志(GNU 扩展)设置了，模式必须匹配跟随在斜杠之后的 string
的初始片断。这个标志主要是给 glibc 内部使用并且只在一定条件下实现。
即只匹配目录路径部分，不匹配到具体文件名
*/
#define FNM_CASEFOLD 0x10 /* 模式匹配忽略大小写. */
#define FNM_PREFIX_DIRS 0x20 /* Directory prefixes of pattern match too. */

// 字符范围匹配
// pattern传入如 [a-x]*** 形式的字符串
// 匹配失败或匹配到EOS结束(也是失败)，返回NULL
// 成功返回匹配串的下一个匹配成分首地址
static const char* rangematch(const char* pattern, char test, int flags)
{
    // 此处没有对c进行初始化，可能出问题（栈上变量默认值未定）
    int negate, ok;
    char c, c2;

    /*
    * A bracket expression starting with an unquoted circumflex
    * character produces unspecified results
    * 以无引号 ^ 字符开始的方括号表达式，将产生未指定的结果
    * (IEEE 1003.2-1992,3.13.2).  此实现将其视为 '!',以与正则表达式语法保持一致.
    * J.T. Conklin (conklin@ngai.kaleida.com)
    */
    // 检测方括号表达式中第一个字符
    // 如果为!或者^，则对后面匹配的结果取反
    if ((negate = (*pattern == '!' || *pattern == '^'))) {
        ++pattern;
    }

    // 忽略大小写，则转为小写处理
    if (flags & FNM_CASEFOLD) {
        test = WTF::ToASCIILower((unsigned char)test);
    }
    // 循环到方括号表达式结束
    for (ok = 0; (c = *pattern++) != ']';) {
        // 如果没有禁用转义，获取字符
        if (c == '\\' && !(flags & FNM_NOESCAPE)) {
            c = *pattern++;
        }
        // 匹配结束
        if (c == EOS) {
            return (NULL);
        }
        // 忽略大小写，则转为小写
        if (flags & FNM_CASEFOLD) {
            c = WTF::ToASCIILower((unsigned char)c);
        }
        // 如果当前匹配项c 的下一个是'-'，则获取'-'后面的一个字符
        // 例如，匹配串为 [a-x] 当前c为a,则c2为x，表示匹配a-x之间字符
        if (*pattern == '-' && (c2 = *(pattern + 1)) != EOS && c2 != ']') {
            pattern += 2;
            // 判断是否需要转义
            if (c2 == '\\' && !(flags & FNM_NOESCAPE)) {
                c2 = *pattern++;
            }
            if (c2 == EOS) {
                return (NULL);
            }
            // 判断是否区分大小写
            if (flags & FNM_CASEFOLD) {
                c2 = WTF::ToASCIILower((unsigned char)c2);
            }
            // 判断test是否位于 [c,c2]区间
            if ((unsigned char)c <= (unsigned char)test && (unsigned char)test <= (unsigned char)c2) {
                ok = 1;
            }
        } else if (c == test) {
            ok = 1;
        }
    }
    // 返回匹配结果
    return (ok == negate ? NULL : pattern);
}

int fnmatch(const char* pattern, const char* string, int flags)
{
    const char* stringstart;
    char c, test;

    for (int i = 0; 0 != string[i]; ++i) {
        if (' ' != string[i]) {
            string = string + i;
            break;
        }
    }

    for (stringstart = string;;) {
        // 逐个取匹配字符串中的成分(分为*?和range三种)
        switch (c = *pattern++) {
        case EOS: // 没有匹配串的情况
            // 如果忽略'/'后面的部分，则匹配成功
            if ((flags & FNM_LEADING_DIR) && *string == '/') {
                return (0);
            }
            // 如果string也是空串，则匹配成功
            return (*string == EOS ? 0 : FNM_NOMATCH);
        case '?': // 匹配单个任意字符
            // string为空则不能匹配
            if (*string == EOS) {
                return (FNM_NOMATCH);
            }
            // 判断'/'是否只能由'/'进行匹配
            if (*string == '/' && (flags & FNM_PATHNAME)) {
                return (FNM_NOMATCH);
            }
            // 判断是否string中的起始'.'必须匹配pattern中的'.'（即'?'不能匹配'.'）
            if (*string == '.' && (flags & FNM_PERIOD) && (string == stringstart || ((flags & FNM_PATHNAME) && *(string - 1) == '/'))) {
                return (FNM_NOMATCH);
            }
            // 匹配成功则匹配string的下一个字符
            ++string;
            break;
        case '*': // 匹配单个或多个任意字符
            c = *pattern;
            /* 多个'*'当做一个 */
            while (c == '*') {
                c = *++pattern;
            }
            // 判断是否需要对'.'进行处理
            if (*string == '.' && (flags & FNM_PERIOD) && (string == stringstart || ((flags & FNM_PATHNAME) && *(string - 1) == '/'))) {
                return (FNM_NOMATCH);
            }

            /* 优化 * 在匹配串结尾或者在 /. 之前的匹配*/
            if (c == EOS) { // 在结尾
                // 判断 * 是否不匹配斜杠
                if (flags & FNM_PATHNAME) {
                    // 不匹配斜杠，则判断是否忽略'/'之后部分
                    return ((flags & FNM_LEADING_DIR) || ((strchr(string, '/') == NULL) ? 0 : FNM_NOMATCH));
                } else {
                    return (0);
                }
            } else if (c == '/' && flags & FNM_PATHNAME) { // 在 /. 之前
                // 如果string后没有 '/'则匹配失败
                if ((string = strchr(string, '/')) == NULL) {
                    return (FNM_NOMATCH);
                }
                break;
            }

            /* 非特殊情况下，递归匹配 */
            while ((test = *string) != EOS) {
                // 不对'.'进行特殊处理，进行匹配（则只需判断'/'匹配情况）
                if (!fnmatch(pattern, string, flags & ~FNM_PERIOD)) {
                    return (0); // 匹配成功
                }
                // 对 '/'进行处理（斜杠只匹配斜杠，则匹配失败）
                if (test == '/' && flags & FNM_PATHNAME) {
                    break;
                }
                ++string;
            }
            // 返回匹配失败（即*没有匹配成功,'.'和'/'上的匹配没有成功）
            return (FNM_NOMATCH);
        case '[': // range 范围匹配
            if (*string == EOS) {
                return (FNM_NOMATCH); // 空串匹配失败
            }
            if (*string == '/' && flags & FNM_PATHNAME) {
                return (FNM_NOMATCH); // '/'匹配失败
            }
            if ((pattern = rangematch(pattern, *string, flags)) == NULL) {
                return (FNM_NOMATCH); // 范围匹配失败
            }
            ++string;
            break;
        case '\\': // 斜杠匹配（判断是否需要转义）
            if (!(flags & FNM_NOESCAPE)) {
                if ((c = *pattern++) == EOS) {
                    c = '\\';
                    --pattern;
                }
            }
            /* 非上述部分，则直接匹配单个字符 */
        default:
            if (c == *string) {
                ; // 直接匹配上了
            } else if ((flags & FNM_CASEFOLD) && (WTF::ToASCIILower((unsigned char)c) == WTF::ToASCIILower((unsigned char)*string))) {
                ; // 忽略大小写匹配成功
            } else if ((flags & FNM_PREFIX_DIRS) && *string == EOS
                && ((c == '/' && string != stringstart) || (string == stringstart + 1 && *stringstart == '/'))) {
                return (0); // 匹配成功
            } else {
                return (FNM_NOMATCH); // 匹配失败
            }
            string++;
            break;
        }
    }
    /* NOTREACHED */
}

namespace content {

WebMimeRegistryImpl::WebMimeRegistryImpl()
{
    m_supportedMIMETypes = nullptr;
    m_supportedImageResourceMIMETypes = nullptr;
    m_supportedJavaScriptMIMETypes = nullptr;
    m_supportedNonImageMIMETypes = nullptr;
    m_mimetypeMap = nullptr;
    m_mimetypeToExtMap = nullptr;
}

WebMimeRegistryImpl::~WebMimeRegistryImpl()
{
    if (m_supportedMIMETypes)
        delete m_supportedMIMETypes;
    m_supportedMIMETypes = nullptr;

    if (m_supportedImageResourceMIMETypes)
        delete m_supportedImageResourceMIMETypes;
    m_supportedImageResourceMIMETypes = nullptr;

    if (m_supportedJavaScriptMIMETypes)
        delete m_supportedJavaScriptMIMETypes;
    m_supportedJavaScriptMIMETypes = nullptr;

    if (m_supportedNonImageMIMETypes)
        delete m_supportedNonImageMIMETypes;
    m_supportedNonImageMIMETypes = nullptr;

    if (m_mimetypeMap)
        delete m_mimetypeMap;
    m_mimetypeMap = nullptr;

    if (m_mimetypeToExtMap)
        delete m_mimetypeMap;
    m_mimetypeMap = nullptr;
}

WebMimeRegistryImpl::SupportsType WebMimeRegistryImpl::supportsImagePrefixedMIMEType(const blink::WebString& mimeType)
{
    return IsNotSupported;
}

static WTF::String checkAndEnsureBit8String(const blink::WebString& ext)
{
    if (ext.IsEmpty())
        return WTF::String();

    WTF::String extension = ext;
    if (!extension.Is8Bit()) {
        std::string utf8String = extension.Utf8();
        extension = WTF::String(base::span<const char>(utf8String.c_str(), utf8String.size()));
    }

    return extension;
}

// WebMimeRegistry methods:
WebMimeRegistryImpl::SupportsType WebMimeRegistryImpl::supportsMIMEType(const blink::WebString& ext)
{
    WTF::String extension = checkAndEnsureBit8String(ext);
    if (extension.empty())
        return WebMimeRegistryImpl::IsSupported;
    extension = extension.LowerASCII();

    if (!m_supportedMIMETypes) {
        m_supportedMIMETypes = new WTF::HashSet<WTF::String>();

        static const char* types[] = {
            "text/plain",
            "text/html",
            "text/xml",
            "multipart/related",
            "application/x-javascript",
            "application/xhtml+xml",
            "application/json",
            "application/pdf",
            "image/svg+xml",
            "image/jpeg",
            "image/png",
            "image/tiff",
            "image/ico",
            "image/bmp",
            "image/gif",
            "application/x-shockwave-flash",
        };
        for (size_t i = 0; i < std::size(types); ++i)
            m_supportedMIMETypes->insert(types[i]);
    }

    return m_supportedMIMETypes->Contains(extension) ? WebMimeRegistryImpl::IsSupported : WebMimeRegistryImpl::IsNotSupported;
}

WebMimeRegistryImpl::SupportsType WebMimeRegistryImpl::supportsImageMIMEType(const blink::WebString& ext)
{
    WTF::String extension = checkAndEnsureBit8String(ext);
    if (extension.empty())
        return WebMimeRegistryImpl::IsNotSupported;
    extension = extension.LowerASCII();

    if (!m_supportedImageResourceMIMETypes) {
        m_supportedImageResourceMIMETypes = new WTF::HashSet<WTF::String>();
        static const char* types[] = {
            //"image/svg+xml",
            "image/jpeg",
            "image/png",
            "image/tiff",
            //"application/x-javascript",
            "image/ico",
            "image/bmp",
            "image/gif",
        };
        for (size_t i = 0; i < std::size(types); ++i)
            m_supportedImageResourceMIMETypes->insert(types[i]);
    }

    return m_supportedImageResourceMIMETypes->Contains(extension) ? WebMimeRegistryImpl::IsSupported : WebMimeRegistryImpl::IsNotSupported;
}

WebMimeRegistryImpl::SupportsType WebMimeRegistryImpl::supportsJavaScriptMIMEType(const blink::WebString& ext)
{
    WTF::String extension = checkAndEnsureBit8String(ext);
    if (extension.empty())
        return WebMimeRegistryImpl::IsNotSupported;
    extension = extension.LowerASCII();

    if (!m_supportedJavaScriptMIMETypes) {
        m_supportedJavaScriptMIMETypes = new WTF::HashSet<WTF::String>();
        /*
        Mozilla 1.8 and WinIE 7 both accept text/javascript and text/ecmascript.
        Mozilla 1.8 accepts application/javascript, application/ecmascript, and application/x-javascript, but WinIE 7 doesn't.
        WinIE 7 accepts text/javascript1.1 - text/javascript1.3, text/jscript, and text/livescript, but Mozilla 1.8 doesn't.
        Mozilla 1.8 allows leading and trailing whitespace, but WinIE 7 doesn't.
        Mozilla 1.8 and WinIE 7 both accept the empty string, but neither accept a whitespace-only string.
        We want to accept all the values that either of these browsers accept, but not other values.
        */
        static const char* types[]
            = { "text/javascript",
                  "text/ecmascript",
                  "application/javascript",
                  "application/ecmascript",
                  "application/x-javascript",
                  "text/javascript1.1",
                  "text/javascript1.2",
                  "text/javascript1.3",
                  "text/jscript",
                  "text/livescript",
#if 1 // V8_MAJOR_VERSION >= 7
                  "module",
#endif
              };
        for (size_t i = 0; i < std::size(types); ++i)
            m_supportedJavaScriptMIMETypes->insert(types[i]);
    }

    return m_supportedJavaScriptMIMETypes->Contains(extension) ? WebMimeRegistryImpl::IsSupported : WebMimeRegistryImpl::IsNotSupported;
}

static HashSet<String>& mimeTypeMediaCache()
{
    static HashSet<String>* cache = nullptr;
    if (!cache) {
        cache = new HashSet<String>();
        const char* mimeTypes[] = {
            "video/mp4",
            "audio/mp4",
            "audio/mpeg",
            "video/mpeg",
            "audio/mp3",
            "video/mp3",
        };
        for (auto& type : mimeTypes)
            cache->insert(type);
    }

    return *cache;
}

static bool supportsCodecs(const String& codecs)
{
    static Vector<const char*>* supportedCodecs = nullptr;
    if (!supportedCodecs) {
        supportedCodecs = new Vector<const char*>();
        supportedCodecs->push_back("avc*");
        supportedCodecs->push_back("mp4a*");
        supportedCodecs->push_back("mpeg");
        supportedCodecs->push_back("x-h264");
    }
    Vector<String> codecEntries;
    codecs.Split(',', false, codecEntries);

    for (String codec : codecEntries) {
        bool isCodecSupported = false;

        // If the codec is named like a mimetype (eg: video/avc) remove the "video/" part.
        size_t slashIndex = codec.find('/');
        if (slashIndex != WTF::kNotFound)
            codec = codec.Substring(slashIndex + 1);

        std::string codecData = codec.Utf8();
        for (size_t i = 0; i < supportedCodecs->size(); ++i) {
            const char* pattern = supportedCodecs->at(i);
            isCodecSupported = !fnmatch(pattern, codecData.data(), 0);
            if (isCodecSupported)
                break;
        }
        if (!isCodecSupported)
            return false;
    }

    return true;
}

WebMimeRegistryImpl::SupportsType WebMimeRegistryImpl::supportsMediaMIMEType(
    const blink::WebString& type, const blink::WebString& typeCodecs, const blink::WebString& system)
{
    //     std::string temp = "supportsMediaMIMEType:";
    //     temp += type.utf8();
    //     temp += ",,,,";
    //     temp += typeCodecs.utf8();
    //     temp += "\n";
    //     OutputDebugStringA(temp.c_str());

    SupportsType result = WebMimeRegistryImpl::IsNotSupported;
    // Spec says we should not return "probably" if the typeCodecs string is empty.
    if (mimeTypeMediaCache().Contains(type)) {
        if (typeCodecs.IsEmpty())
            result = WebMimeRegistryImpl::MayBeSupported;
        else
            result = supportsCodecs(typeCodecs) ? WebMimeRegistryImpl::IsSupported : WebMimeRegistryImpl::IsNotSupported;
    }

    return result;

    //     String typeString = type;
    //     if (wke::g_onIsMediaPlayerSupportsMIMETypeCallback) {
    //         std::string typeStr = type.utf8();
    //         bool isSupported = wke::g_onIsMediaPlayerSupportsMIMETypeCallback(typeStr.c_str());
    //         if (isSupported) // if (WTF::kNotFound != typeString.find("video/mp4"))
    //             return WebMimeRegistryImpl::IsSupported;
    //     }
    //
    //     return WebMimeRegistryImpl::IsNotSupported;
}

bool WebMimeRegistryImpl::supportsMediaSourceMIMEType(const blink::WebString& type, const blink::WebString& typeCodecs)
{
    std::string temp = "supportsMediaSourceMIMEType:";
    temp += type.Utf8();
    temp += ",,,,";
    temp += typeCodecs.Utf8();
    temp += "\n";

    return supportsMediaMIMEType(type, typeCodecs, "") == WebMimeRegistryImpl::IsSupported;
}

WebMimeRegistryImpl::SupportsType WebMimeRegistryImpl::supportsNonImageMIMEType(const blink::WebString& ext)
{
    WTF::String extension = checkAndEnsureBit8String(ext);
    if (extension.empty())
        return WebMimeRegistryImpl::IsNotSupported;
    extension = extension.LowerASCII();

    if (!m_supportedNonImageMIMETypes) {
        m_supportedNonImageMIMETypes = new HashSet<String>();

        static const char* types[] = {
            "text/html", "text/xml", "text/xsl", "text/plain", "text/", "application/xml", "application/xhtml+xml", "application/vnd.wap.xhtml+xml",
            "application/rss+xml", "application/atom+xml", "application/json",
            //#if ENABLE(SVG)
            "image/svg+xml",
            //#endif
            "application/x-ftp-directory", "multipart/x-mixed-replace", "multipart/related",
            //"application/x-shockwave-flash",
            // Note: ADDING a new type here will probably render it as HTML. This can
            // result in cross-site scripting.
        };
        //COMPILE_ASSERT(sizeof(types) / sizeof(types[0]) <= 16, "nonimage_mime_types_must_be_less_than_or_equal_to_16");

        for (size_t i = 0; i < std::size(types); ++i)
            m_supportedNonImageMIMETypes->insert(types[i]);
    }

    return m_supportedNonImageMIMETypes->Contains(extension) ? WebMimeRegistryImpl::IsSupported : WebMimeRegistryImpl::IsNotSupported;
}

void WebMimeRegistryImpl::MimetypeToExtMap::add(const char* mime, ...)
{
    va_list arg_list;
    va_start(arg_list, mime);

    WebMimeRegistryImpl::MimetypeToExt* it = new WebMimeRegistryImpl::MimetypeToExt();
    it->mime = mime;

    do {
        const char* ext = va_arg(arg_list, const char*);
        if (!ext)
            break;

        it->exts.push_back(ext);
    } while (true);
    m_map.push_back(it);
}

void WebMimeRegistryImpl::ensureMimeTypeMap()
{
    if (m_mimetypeMap)
        return;

    m_mimetypeMap = new WTF::HashMap<WTF::String, WTF::String>();
    //fill with initial values
    m_mimetypeMap->insert("txt", "text/plain");
    m_mimetypeMap->insert("pdf", "application/pdf");
    m_mimetypeMap->insert("ps", "application/postscript");
    m_mimetypeMap->insert("html", "text/html");
    m_mimetypeMap->insert("htm", "text/html");
    m_mimetypeMap->insert("xml", "text/xml");
    m_mimetypeMap->insert("xsl", "text/xsl");
    m_mimetypeMap->insert("xls", "application/xls+vnd.ms-excel");
    m_mimetypeMap->insert("js", "application/x-javascript");
    m_mimetypeMap->insert("xhtml", "application/xhtml+xml");
    m_mimetypeMap->insert("rss", "application/rss+xml");
    m_mimetypeMap->insert("webarchive", "application/x-webarchive");
    m_mimetypeMap->insert("svg", "image/svg+xml");
    m_mimetypeMap->insert("svgz", "image/svg+xml");
    m_mimetypeMap->insert("jpg", "image/jpeg");
    m_mimetypeMap->insert("jpeg", "image/jpeg");
    m_mimetypeMap->insert("png", "image/png");
    m_mimetypeMap->insert("gif", "image/gif");
    m_mimetypeMap->insert("tif", "image/tiff");
    m_mimetypeMap->insert("tiff", "image/tiff");
    m_mimetypeMap->insert("ico", "image/ico");
    m_mimetypeMap->insert("cur", "image/ico");
    m_mimetypeMap->insert("bmp", "image/bmp");
    m_mimetypeMap->insert("wml", "text/vnd.wap.wml");
    m_mimetypeMap->insert("wmlc", "application/vnd.wap.wmlc");
    m_mimetypeMap->insert("swf", "application/x-shockwave-flash");
    m_mimetypeMap->insert("mp4", "video/mp4");
    m_mimetypeMap->insert("ogg", "video/ogg");
    m_mimetypeMap->insert("webm", "video/webm");
    m_mimetypeMap->insert("mht", "multipart/related");
    m_mimetypeMap->insert("mhtml", "multipart/related");

    m_mimetypeMap->insert("hex", "application/hex");
    m_mimetypeMap->insert("rbf", "application/rbf");
    m_mimetypeMap->insert("bin", "application/bin");
    m_mimetypeMap->insert("zip", "application/zip");
    m_mimetypeMap->insert("rar", "application/rar");
    m_mimetypeMap->insert("doc", "application/doc");
    m_mimetypeMap->insert("docx", "application/docx");

    m_mimetypeMap->insert("pcx", "image/pcx");
    m_mimetypeMap->insert("tga", "image/tga");
    m_mimetypeMap->insert("exif", "image/exif");
    m_mimetypeMap->insert("fpx", "image/fpx");
    m_mimetypeMap->insert("psd", "image/psd");
    m_mimetypeMap->insert("cdr", "image/cdr");
    m_mimetypeMap->insert("pcd", "image/pcd");
    m_mimetypeMap->insert("dxf", "image/dxf");
    m_mimetypeMap->insert("ufo", "image/ufo");
    m_mimetypeMap->insert("eps", "image/eps");
    m_mimetypeMap->insert("ai", "image/ai");
    m_mimetypeMap->insert("raw", "image/raw");
    m_mimetypeMap->insert("wmf", "image/wmf");
    m_mimetypeMap->insert("webp", "image/webp");

    m_mimetypeToExtMap = new MimetypeToExtMap();
    m_mimetypeToExtMap->add("application/rss+xml", "rss", nullptr);
    m_mimetypeToExtMap->add("image/jpeg", "jpeg", nullptr);
    m_mimetypeToExtMap->add("application/pdf", "pdf", nullptr);
    m_mimetypeToExtMap->add("image/ico", "cur", nullptr);
    m_mimetypeToExtMap->add("application/xls+vnd.ms-excel", "xls", nullptr);
    m_mimetypeToExtMap->add("image/svg+xml", "svg", nullptr);
    m_mimetypeToExtMap->add("image/webp", "webp", nullptr);
    m_mimetypeToExtMap->add("application/zip", "zip", nullptr);
    m_mimetypeToExtMap->add("image/svg+xml", "svgz", nullptr);
    m_mimetypeToExtMap->add("image/psd", "psd", nullptr);
    m_mimetypeToExtMap->add("application/x-shockwave-flash", "swf", nullptr);
    m_mimetypeToExtMap->add("image/jpeg", "jpg", "pjp", "jpeg", "pjpeg", "jfif", nullptr);
    m_mimetypeToExtMap->add("multipart/related", "mhtml", nullptr);
    m_mimetypeToExtMap->add("image/bmp", "bmp", "dib", nullptr);
    m_mimetypeToExtMap->add("application/postscript", "ps", nullptr);
    m_mimetypeToExtMap->add("application/vnd.wap.wmlc", "wmlc", nullptr);
    m_mimetypeToExtMap->add("application/x-webarchive", "webarchive", nullptr);
    m_mimetypeToExtMap->add("application/rbf", "rbf", nullptr);
    m_mimetypeToExtMap->add("text/xml", "xml", nullptr);
    m_mimetypeToExtMap->add("image/raw", "raw", nullptr);
    m_mimetypeToExtMap->add("application/docx", "docx", nullptr);
    m_mimetypeToExtMap->add("application/x-javascript", "js", nullptr);
    m_mimetypeToExtMap->add("image/tiff", "tiff", nullptr);
    m_mimetypeToExtMap->add("text/html", "html", nullptr);
    m_mimetypeToExtMap->add("image/png", "png", nullptr);
    m_mimetypeToExtMap->add("image/x-png", "png", nullptr);
    m_mimetypeToExtMap->add("text/html", "htm", nullptr);
    m_mimetypeToExtMap->add("image/tiff", "tif", nullptr);
    m_mimetypeToExtMap->add("video/webm", "webm", nullptr);
    m_mimetypeToExtMap->add("application/rar", "rar", nullptr);
    m_mimetypeToExtMap->add("application/doc", "doc", nullptr);
    m_mimetypeToExtMap->add("image/exif", "exif", nullptr);
    m_mimetypeToExtMap->add("video/ogg", "ogg", nullptr);
    m_mimetypeToExtMap->add("text/plain", "txt", nullptr);
    m_mimetypeToExtMap->add("image/ico", "ico", nullptr);
    m_mimetypeToExtMap->add("application/xhtml+xml", "xhtml", nullptr);
    m_mimetypeToExtMap->add("multipart/related", "mht", nullptr);
    m_mimetypeToExtMap->add("image/eps", "eps", nullptr);
    m_mimetypeToExtMap->add("image/tga", "tga", nullptr);
    m_mimetypeToExtMap->add("text/vnd.wap.wml", "wml", nullptr);
    m_mimetypeToExtMap->add("image/gif", "gif", nullptr);
    m_mimetypeToExtMap->add("image/ai", "ai", nullptr);
    m_mimetypeToExtMap->add("image/cdr", "cdr", nullptr);
    m_mimetypeToExtMap->add("application/hex", "hex", nullptr);
    m_mimetypeToExtMap->add("image/ufo", "ufo", nullptr);
    m_mimetypeToExtMap->add("text/xsl", "xsl", nullptr);
    m_mimetypeToExtMap->add("image/dxf", "dxf", nullptr);
    m_mimetypeToExtMap->add("application/bin", "bin", nullptr);
    m_mimetypeToExtMap->add("image/wmf", "wmf", nullptr);
    m_mimetypeToExtMap->add("image/pcd", "pcd", nullptr);
    m_mimetypeToExtMap->add("video/mp4", "mp4", nullptr);
    m_mimetypeToExtMap->add("image/pcx", "pcx", nullptr);
    m_mimetypeToExtMap->add("image/fpx", "fpx", nullptr);
}

blink::WebString WebMimeRegistryImpl::mimeTypeForExtension(const blink::WebString& ext)
{
    //ASSERT(isMainThread());

    if (ext.IsEmpty())
        return blink::WebString();

    ensureMimeTypeMap();
    WTF::String extension = ext.Utf8().c_str();
    extension = extension.LowerASCII();
    WTF::HashMap<WTF::String, WTF::String>::const_iterator it = m_mimetypeMap->find(extension);
    if (it == m_mimetypeMap->end())
        return blink::WebString();

    WTF::String result = it->value;
    return result;
}

blink::WebString WebMimeRegistryImpl::wellKnownMimeTypeForExtension(const blink::WebString& ext)
{
    return mimeTypeForExtension(ext);
}

blink::WebString WebMimeRegistryImpl::mimeTypeFromFile(const blink::WebString& ext)
{
    return blink::WebString();
}

blink::WebString WebMimeRegistryImpl::extensionForMimeType(const blink::WebString& mime)
{
    //ASSERT(isMainThread());

    if (mime.IsEmpty())
        return blink::WebString();

    ensureMimeTypeMap();
    for (WTF::HashMap<WTF::String, WTF::String>::iterator it = m_mimetypeMap->begin(); it != m_mimetypeMap->end(); ++it) {
        if (WTF::CodeUnitCompareIgnoringASCIICase(it->value.Impl(), String(mime).Impl()))
            return it->key;
    }
    return blink::WebString();
}

static bool doMatch(const char* pattern, const char* content)
{
    // if we reatch both end of two string, we are done
    if ('\0' == *pattern && '\0' == *content)
        return true;

    // make sure that the characters after '*' are present in second string.
    // this function assumes that the first string will not contain two
    // consecutive '*'
    if ('*' == *pattern && '\0' != *(pattern + 1) && '\0' == *content)
        return false;

    // if the first string contains '?', or current characters of both
    // strings match
    if ('?' == *pattern || *pattern == *content)
        return doMatch(pattern + 1, content + 1);

    // if there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if ('*' == *pattern)
        return doMatch(pattern + 1, content) || doMatch(pattern, content + 1);
    return false;
}

static bool wildcardMatch(const WTF::String& pattern, const WTF::String& content)
{
    std::string patternStr = pattern.Utf8();
    std::string contentStr = content.Utf8();
    bool result = doMatch(patternStr.data(), contentStr.data());
    if (!result)
        result = (WTF::kNotFound != content.Find(pattern));

    return result;
}

Vector<blink::WebString> WebMimeRegistryImpl::extensionsForMimeType(const blink::WebString& mime)
{
    //ASSERT(isMainThread());

    Vector<blink::WebString> result;
    if (mime.IsEmpty())
        return result;

    String mimeStr = mime;
    if (WTF::kNotFound == mimeStr.find('*') && WTF::kNotFound == mimeStr.find('/')) {
        result.push_back(mimeStr);
        return result;
    }

    ensureMimeTypeMap();
    for (size_t i = 0; i < m_mimetypeToExtMap->m_map.size(); ++i) {
        MimetypeToExt* it = m_mimetypeToExtMap->m_map[i];
        if (!wildcardMatch(mime, it->mime))
            continue;
        for (size_t j = 0; j < it->exts.size(); ++j) {
            WTF::String ext = it->exts[j];
            result.push_back(ext);
        }
    }
    return result;
}

WebMimeRegistryImpl* WebMimeRegistryImpl::get()
{
    static WebMimeRegistryImpl* s_inst = nullptr;
    if (!s_inst)
        s_inst = new WebMimeRegistryImpl();
    return s_inst;
}

} // namespace content