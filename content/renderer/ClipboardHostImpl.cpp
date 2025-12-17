
#include "content/renderer/ClipboardHostImpl.h"
#include "content/ui/ClipboardUtil.h"
#include "content/common/mbchar.h"
#include "content/common/StringUtil.h"
#include "third_party/blink/public/platform/web_url.h"
#include "third_party/blink/renderer/platform/image-encoders/image_encoder.h"
#include "skia/ext/skia_utils_win.h"
#include "base/strings/utf_string_conversions.h"
#include "base/pickle.h"
#include <windows.h>

bool blink::mojom::blink::ClipboardHost::GetSequenceNumber(::blink::mojom::blink::ClipboardBuffer buffer, ::blink::ClipboardSequenceNumberToken* out_result)
{
    DebugBreak();
    return false;
}

bool blink::mojom::blink::ClipboardHost::IsFormatAvailable(
    ::blink::mojom::blink::ClipboardFormat format, ::blink::mojom::blink::ClipboardBuffer buffer, bool* out_result)
{
    return false;
}

bool blink::mojom::blink::ClipboardHost::ReadAvailableTypes(::blink::mojom::blink::ClipboardBuffer buffer, WTF::Vector<::WTF::String>* out_types)
{
    return false;
}

bool blink::mojom::blink::ClipboardHost::ReadText(::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* out_result)
{
    return false;
}

bool blink::mojom::blink::ClipboardHost::ReadHtml(
    ::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* out_markup, ::blink::KURL* out_url, uint32_t* out_fragment_start, uint32_t* out_fragment_end)
{
    return false;
}

bool blink::mojom::blink::ClipboardHost::ReadRtf(::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* out_result)
{
    return false;
}

bool blink::mojom::blink::ClipboardHost::ReadPng(::blink::mojom::blink::ClipboardBuffer buffer, ::mojo_base::BigBuffer* out_png)
{
    return false;
}

bool blink::mojom::blink::ClipboardHost::ReadFiles(::blink::mojom::blink::ClipboardBuffer buffer, ::blink::mojom::blink::ClipboardFilesPtr* out_result)
{
    return false;
}

bool blink::mojom::blink::ClipboardHost::ReadAvailableCustomAndStandardFormats(WTF::Vector<::WTF::String>* out_format_types)
{
    return false;
}

namespace {

void freeData(unsigned int format, HANDLE data)
{
    if (format == CF_BITMAP)
        ::DeleteObject(static_cast<HBITMAP>(data));
    else
        ::GlobalFree(data);
}

template <class str> void appendEscapedCharForHTMLImpl(typename str::value_type c, str* output)
{
    static const struct {
        char key;
        const char* replacement;
    } kCharsToEscape[] = {
        { '<', "&lt;" },
        { '>', "&gt;" },
        { '&', "&amp;" },
        { '"', "&quot;" },
        { '\'', "&#39;" },
    };
    size_t k;
    for (k = 0; k < std::size(kCharsToEscape); ++k) {
        if (c == kCharsToEscape[k].key) {
            const char* p = kCharsToEscape[k].replacement;
            while (*p)
                //output->push_back(*p++);
                *output += (*p++);
            break;
        }
    }
    if (k == /*arraysize*/ std::size(kCharsToEscape))
        //output->push_back(c);
        *output += c;
}

template <class str> str escapeForHTMLImpl(const str& input)
{
    str result;
    result.reserve(input.size()); // Optimize for no escaping.

    for (typename str::const_iterator i = input.begin(); i != input.end(); ++i)
        appendEscapedCharForHTMLImpl(*i, &result);

    return result;
}

std::string escapeForHTML(const Vector<char>& input)
{
    std::string inputStr(input.data(), input.size());
    return escapeForHTMLImpl(inputStr);
}

std::string escapeForHTML(const std::string input)
{
    return escapeForHTMLImpl(input);
}

std::string URLToMarkup(const blink::WebURL& url, const blink::WebString& title)
{
    std::string markup("<a href=\"");
    markup.append(url.GetString().Utf8());
    markup.append("\">");
    // TODO(darin): HTML escape this
    markup.append(escapeForHTML(title.Utf8()));
    markup.append("</a>");
    return markup;
}

std::string URLToImageMarkup(const blink::WebURL& url, const blink::WebString& title)
{
    std::string markup("<img src=\"");
    markup.append(escapeForHTML(url.GetString().Utf8()));
    markup.append("\"");
    if (!title.IsEmpty()) {
        markup.append(" alt=\"");
        markup.append(escapeForHTML(title.Utf8()));
        markup.append("\"");
    }
    markup.append("/>");
    return markup;
}

// A scoper to impersonate the anonymous token and revert when leaving scope
class AnonymousImpersonator {
public:
    AnonymousImpersonator()
    {
        m_mustRevert = ::ImpersonateAnonymousToken(::GetCurrentThread());
    }

    ~AnonymousImpersonator()
    {
        if (m_mustRevert)
            ::RevertToSelf();
    }

private:
    BOOL m_mustRevert;
};

// A scoper to manage acquiring and automatically releasing the clipboard.
class ScopedClipboard {
public:
    ScopedClipboard()
        : m_isOpened(false)
    {
    }

    ~ScopedClipboard()
    {
        if (m_isOpened)
            release();
    }

    bool acquire(HWND owner)
    {
        const int kMaxAttemptsToOpenClipboard = 5;

        if (m_isOpened) {
            CHECK(false);
            return false;
        }

        // Attempt to open the clipboard, which will acquire the Windows clipboard
        // lock.  This may fail if another process currently holds this lock.
        // We're willing to try a few times in the hopes of acquiring it.
        //
        // This turns out to be an issue when using remote desktop because the
        // rdpclip.exe process likes to read what we've written to the clipboard and
        // send it to the RDP client.  If we open and close the clipboard in quick
        // succession, we might be trying to open it while rdpclip.exe has it open,
        // See Bug 815425.
        //
        // In fact, we believe we'll only spin this loop over remote desktop.  In
        // normal situations, the user is initiating clipboard operations and there
        // shouldn't be contention.

        for (int attempts = 0; attempts < kMaxAttemptsToOpenClipboard; ++attempts) {
            // If we didn't manage to open the clipboard, sleep a bit and be hopeful.
            if (attempts != 0)
                ::Sleep(5);

            if (::OpenClipboard(owner)) {
                m_isOpened = true;
                return true;
            }
        }

        // We failed to acquire the clipboard.
        return false;
    }

    void release()
    {
        if (m_isOpened) {
            // Impersonate the anonymous token during the call to CloseClipboard
            // This prevents Windows 8+ capturing the broker's access token which
            // could be accessed by lower-privileges chrome processes leading to
            // a risk of EoP
            AnonymousImpersonator impersonator;
            ::CloseClipboard();
            m_isOpened = false;
        } else {
            CHECK(false);
        }
    }

private:
    bool m_isOpened;
};

} // namespace

namespace content {

bool ClipboardHostImpl::GetSequenceNumber(::blink::mojom::blink::ClipboardBuffer buffer, ::blink::ClipboardSequenceNumberToken* out_result)
{
    uint64_t sequence = ::GetClipboardSequenceNumber();
    std::optional<base::UnguessableToken> token = base::UnguessableToken::Deserialize(sequence, 0);
    if (!token.has_value())
        return false;
    *out_result = ::blink::ClipboardSequenceNumberToken(token.value());
    return true;
}

//using GetSequenceNumberCallback = base::OnceCallback<void(const ::blink::ClipboardSequenceNumberToken&)>;
void ClipboardHostImpl::GetSequenceNumber(::blink::mojom::blink::ClipboardBuffer buffer, GetSequenceNumberCallback callback)
{
    uint64_t sequence = ::GetClipboardSequenceNumber();        
    std::optional<base::UnguessableToken> token = base::UnguessableToken::Deserialize(sequence, 0);

    if (token.has_value())    
        std::move(callback).Run(::blink::ClipboardSequenceNumberToken(token.value()));
    else
        std::move(callback).Run(::blink::ClipboardSequenceNumberToken());
}

bool convertBufferType(::blink::mojom::ClipboardBuffer buffer, ClipboardType* result)
{
    *result = CLIPBOARD_TYPE_COPY_PASTE;
    switch (buffer) {
    case ::blink::mojom::ClipboardBuffer::kStandard:
        break;
    case ::blink::mojom::ClipboardBuffer::kSelection:
        // Chrome OS and non-X11 unix builds do not support
        // the X selection clipboad.
        // TODO: remove the need for this case, see http://crbug.com/361753
        return false;
    default:
        CHECK(false);
        return false;
    }
    return true;
}

bool ClipboardHostImpl::IsFormatAvailable(::blink::mojom::blink::ClipboardFormat format, ::blink::mojom::blink::ClipboardBuffer buffer, bool* out_result)
{
#if defined(OS_WIN)
    switch (format) {
    case blink::mojom::ClipboardFormat::kPlaintext:
        *out_result = ::IsClipboardFormatAvailable(CF_UNICODETEXT) || ::IsClipboardFormatAvailable(CF_TEXT);
        return true;
    case blink::mojom::ClipboardFormat::kHtml:
        *out_result = ::IsClipboardFormatAvailable(ClipboardUtil::getHtmlFormatType());
        return true;
    case blink::mojom::ClipboardFormat::kSmartPaste:
        *out_result = ::IsClipboardFormatAvailable(ClipboardUtil::getWebKitSmartPasteFormatType());
        return true;
    case blink::mojom::ClipboardFormat::kBookmark:
        *out_result = ::IsClipboardFormatAvailable(ClipboardUtil::getUrlWFormatType());
        return true;
    default:
        CHECK(false);
    }
#endif
    return false;
}

//using IsFormatAvailableCallback = base::OnceCallback<void(bool)>;
void ClipboardHostImpl::IsFormatAvailable(
    ::blink::mojom::blink::ClipboardFormat format, ::blink::mojom::blink::ClipboardBuffer buffer, IsFormatAvailableCallback callback)
{
    CHECK(false);
    std::move(callback).Run(false);
}

void ClipboardHostImpl::readAvailableTypes(ClipboardType type, WTF::Vector<WTF::String>* types, bool* containsFilenames) const
{
#if defined(OS_WIN)
    if (!types || !containsFilenames) {
        CHECK(false);
        return;
    }

    *containsFilenames = false;
    types->clear();

    if (::IsClipboardFormatAvailable(CF_TEXT))
        types->push_back(WTF::String::FromUTF8(kMimeTypeText));
    if (::IsClipboardFormatAvailable(ClipboardUtil::getHtmlFormatType()))
        types->push_back(WTF::String::FromUTF8(kMimeTypeHTML));
    if (::IsClipboardFormatAvailable(ClipboardUtil::getRtfFormatType()))
        types->push_back(WTF::String::FromUTF8(kMimeTypeRTF));

    if (::IsClipboardFormatAvailable(CF_DIB)) {
        types->push_back(WTF::String::FromUTF8(kMimeTypePNG));
        return; // DataObjectItem::createFromPasteboard里只认识png格式。 不返回的话，wangEditor里会出现粘贴不了的问题
    }

    if (::IsClipboardFormatAvailable(CF_BITMAP))
        types->push_back(WTF::String::FromUTF8(kMimeTypeBMP));
#endif
}

bool ClipboardHostImpl::ReadAvailableTypes(::blink::mojom::blink::ClipboardBuffer buffer, WTF::Vector<::WTF::String>* types)
{
    bool containsFilenames = false;
    ClipboardType clipboardType;
    if (convertBufferType(buffer, &clipboardType))
        readAvailableTypes(clipboardType, types, &containsFilenames);

    return true;
}

//using ReadAvailableTypesCallback = base::OnceCallback<void(const WTF::Vector<::WTF::String>&)>;
void ClipboardHostImpl::ReadAvailableTypes(::blink::mojom::blink::ClipboardBuffer buffer, ReadAvailableTypesCallback callback)
{
    CHECK(false);
    std::move(callback).Run(WTF::Vector<::WTF::String>());
}

bool ClipboardHostImpl::ReadText(::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* text)
{
    ClipboardType clipboardType;
    if (!convertBufferType(buffer, &clipboardType))
        return false;

    // Acquire the clipboard.
    ScopedClipboard clipboard;
    if (!clipboard.acquire(getClipboardWindow()))
        return false;

    HANDLE data = ::GetClipboardData(CF_UNICODETEXT);
    if (!data)
        return false;

    LPCWSTR dataText = (LPCWSTR)::GlobalLock(data);
    *text = String(base::span<const UChar>((const UChar*)dataText, (unsigned)u16len((const UChar*)dataText)));
    ::GlobalUnlock(data);

    return true;
}

//using ReadTextCallback = base::OnceCallback<void(const ::WTF::String&)>;
void ClipboardHostImpl::ReadText(::blink::mojom::blink::ClipboardBuffer buffer, ReadTextCallback callback)
{
    CHECK(false);
    std::move(callback).Run(::WTF::String());
}

static int getOffsetOfUtf8ToUtf16(const std::string& utf8Str, int offset)
{
    int length = utf8Str.size();
    if (offset >= length)
        offset = length - 1;

    std::vector<char> subStr;
    subStr.resize(offset + 1);
    memcpy(subStr.data(), utf8Str.c_str(), offset + 1);

    //std::vector<UChar> temp;
    //mulByteToUtf16(subStr.data(), subStr.size(), &temp, CP_UTF8);
    std::u16string utf16Str = mulByteToUtf16(std::string(subStr.data(), subStr.size()), CP_UTF8);

    return utf16Str.size() > 0 ? utf16Str.size() - 1 : 0;
}

bool ClipboardHostImpl::ReadHtml(
    ::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* outMarkup, ::blink::KURL* out_url, uint32_t* outFragmentStart, uint32_t* outFragmentEnd)
{
    ClipboardType clipboardType;
    if (!convertBufferType(buffer, &clipboardType))
        return false;

    CHECK(clipboardType == CLIPBOARD_TYPE_COPY_PASTE);

    std::string srcUrl;

    *outFragmentStart = 0;
    *outFragmentEnd = 0;

    std::vector<char> utf8CfHtml;
    {
        // Acquire the clipboard.
        ScopedClipboard clipboard;
        if (!clipboard.acquire(getClipboardWindow()))
            return false;

        HANDLE data = ::GetClipboardData(ClipboardUtil::getHtmlFormatType());
        if (!data)
            return false;

        const char* cfHtml = static_cast<const char*>(::GlobalLock(data));
        if (!cfHtml)
            return false;

        int sizeOfHtml = GlobalSize(data);
        if (0 == sizeOfHtml)
            return false;

        if (sizeOfHtml > 5 && '\0' == cfHtml[1]) {
            for (int i = 0; i < sizeOfHtml / 2; ++i) {
                if ('\0' == *((const wchar_t*)cfHtml + i)) {
                    sizeOfHtml = i;
                    break;
                }
            }

            WCharToMByte((const wchar_t*)cfHtml, sizeOfHtml, &utf8CfHtml, CP_UTF8);
        } else {
            for (int i = 0; i < sizeOfHtml; ++i) {
                if ('\0' == *((const char*)cfHtml + i)) {
                    sizeOfHtml = i;
                    break;
                }
            }

            if (!isTextUTF8(cfHtml, sizeOfHtml)) { // GBK -> utf8
                mulByteToUtf8(cfHtml, sizeOfHtml, &utf8CfHtml, CP_ACP);
            } else {
                utf8CfHtml.resize(sizeOfHtml);
                memcpy(&utf8CfHtml[0], cfHtml, sizeOfHtml);
            }
        }

        ::GlobalUnlock(data);
    }

    if (0 == utf8CfHtml.size())
        return false;
    utf8CfHtml.push_back('\0');

    size_t htmlStart = std::string::npos;
    size_t startIndex = std::string::npos;
    size_t endIndex = std::string::npos;
    ClipboardUtil::cfHtmlExtractMetadata(&utf8CfHtml[0], &srcUrl, &htmlStart, &startIndex, &endIndex);

    // This might happen if the contents of the clipboard changed and CF_HTML is
    // no longer available.
    if (startIndex == std::string::npos || endIndex == std::string::npos || htmlStart == std::string::npos)
        return false;

    if (startIndex < htmlStart || endIndex < startIndex)
        return false;

    startIndex -= htmlStart;
    endIndex -= htmlStart;

    std::string utf8CfHtmlStart = &utf8CfHtml[0] + htmlStart;

    startIndex = getOffsetOfUtf8ToUtf16(utf8CfHtmlStart, startIndex);
    endIndex = getOffsetOfUtf8ToUtf16(utf8CfHtmlStart, endIndex);

    *outFragmentStart = startIndex;
    *outFragmentEnd = endIndex;

    //std::vector<UChar> result;
    //WTF::MByteToWChar(utf8CfHtmlStart.c_str(), utf8CfHtmlStart.size(), &result, CP_UTF8);
    //blink::WebString resultStr;
    //out_markup->Assign(&result[0], result.size());
    *outMarkup = blink::WebString::FromUTF8(std::string_view(utf8CfHtmlStart.c_str(), utf8CfHtmlStart.size()));

    return true;
}

//using ReadHtmlCallback = base::OnceCallback<void(const ::WTF::String&, const ::blink::KURL&, uint32_t, uint32_t)>;
void ClipboardHostImpl::ReadHtml(::blink::mojom::blink::ClipboardBuffer buffer, ReadHtmlCallback callback)
{
    CHECK(false);
    std::move(callback).Run(::WTF::String(), ::blink::KURL(), 0, 0);
}

//using ReadSvgCallback = base::OnceCallback<void(const ::WTF::String&)>;
void ClipboardHostImpl::ReadSvg(::blink::mojom::blink::ClipboardBuffer buffer, ReadSvgCallback callback)
{
    CHECK(false);
    std::move(callback).Run(::WTF::String());
}

bool ClipboardHostImpl::ReadRtf(::blink::mojom::blink::ClipboardBuffer buffer, ::WTF::String* out_result)
{
    CHECK(false);
    return false;
}

//using ReadRtfCallback = base::OnceCallback<void(const ::WTF::String&)>;
void ClipboardHostImpl::ReadRtf(::blink::mojom::blink::ClipboardBuffer buffer, ReadRtfCallback callback)
{
    CHECK(false);
    std::move(callback).Run(::WTF::String());
}

bool bitmapHasInvalidPremultipliedColors(const SkBitmap& bitmap)
{
    for (int x = 0; x < bitmap.width(); ++x) {
        for (int y = 0; y < bitmap.height(); ++y) {
            uint32_t pixel = *bitmap.getAddr32(x, y);
            if (SkColorGetR(pixel) > SkColorGetA(pixel) ||
                SkColorGetG(pixel) > SkColorGetA(pixel) ||
                SkColorGetB(pixel) > SkColorGetA(pixel))
                return true;
        }
    }
    return false;
}

static void makeBitmapOpaque(const SkBitmap& bitmap)
{
    for (int x = 0; x < bitmap.width(); ++x) {
        for (int y = 0; y < bitmap.height(); ++y) {
            uint32_t* addr = bitmap.getAddr32(x, y);
            *addr = SkColorSetA(*addr, 0xFF);
        }
    }
}

static BYTE* flipDIBVertically(BYTE* pBits, int width, int height, bool isDib32Or24)
{
    const int count = isDib32Or24 ? 4 : 3;
    // 计算每行的字节数（可能包含填充字节）
    int stride = (width * count + 3) & ~3; // 向上对齐到4字节

    BYTE* pFlippedBits = new BYTE[height * (width * count + 3)];
    for (int y = 0; y < height; y++) {
        memcpy(
            pFlippedBits + (height - 1 - y) * stride,  // 目标行
            pBits + y * stride,                       // 源行
            stride                                    // 行大小
        );
    }
    return pFlippedBits;
}

struct Bitmap32ConvertResult {
    size_t totalSize = 0;            // 总内存大小
    BITMAPINFO* pBitmapInfo = nullptr; // 指向BITMAPINFO部分的指针[BITMAPINFO][颜色表][32位像素数据]
    BYTE* pPixelData = nullptr;       // 指向像素数据部分的指针（方便访问）
    int width = 0;                   // 图像宽度
    int height = 0;                  // 图像高度
    bool success = false;
    const char* errorMsg = nullptr;
};

static Bitmap32ConvertResult convert24BitTo32BitBitmapInfo(const BITMAPINFO* pBmi)
{
    Bitmap32ConvertResult result;

    // 将输入视为BITMAPINFO结构
    const BITMAPINFOHEADER& header = pBmi->bmiHeader;

    // 验证是否为24位
    if (header.biBitCount != 24) {
        result.errorMsg = "Input is not 24-bit bitmap";
        return result;
    }

    if (header.biCompression != BI_RGB) {
        result.errorMsg = "Compressed bitmaps not supported";
        return result;
    }

    // 计算尺寸参数
    int width = header.biWidth;
    int height = abs(header.biHeight);
    bool topDown = (header.biHeight < 0);
    result.width = width;
    result.height = height;

    // 计算颜色表大小
    UINT colorTableSize = 0;
    if (header.biBitCount <= 8) {
        colorTableSize = (header.biClrUsed > 0) ? header.biClrUsed : (1u << header.biBitCount);
    }

    // 定位输入像素数据起始位置
    const BYTE* pPixelData24 = nullptr;

    if (colorTableSize > 0 && pBmi->bmiColors) {
        // 如果有颜色表，像素数据在颜色表之后
        pPixelData24 = reinterpret_cast<const BYTE*>(pBmi->bmiColors + colorTableSize);
    } else {
        // 如果没有颜色表（24位通常如此），像素数据紧跟在BITMAPINFOHEADER之后
        pPixelData24 = reinterpret_cast<const BYTE*>(pBmi) + sizeof(BITMAPINFOHEADER);
    }

    // 计算24位行字节数（4字节对齐）
    int srcRowSize = ((width * 24 + 31) / 32) * 4;
    // 计算32位行字节数
    int dstRowSize = width * 4;  // 32位，每像素4字节
    size_t pixelDataSize = dstRowSize * height;

    // 计算总内存大小：[BITMAPINFOHEADER][颜色表][32位像素数据]
    size_t totalSize = sizeof(BITMAPINFOHEADER) + colorTableSize * sizeof(RGBQUAD) + pixelDataSize;

    BYTE* pAllData = new BYTE[totalSize];
    if (!pAllData) {
        result.errorMsg = "Memory allocation failed";
        return result;
    }

    memset(pAllData, 0, totalSize);

    // 设置各个部分的指针
    result.pBitmapInfo = reinterpret_cast<BITMAPINFO*>(pAllData);
    result.pPixelData = pAllData + sizeof(BITMAPINFOHEADER) + colorTableSize * sizeof(RGBQUAD);

    BITMAPINFOHEADER& newHeader = result.pBitmapInfo->bmiHeader;
    newHeader = header;                           // 复制基础信息
    newHeader.biBitCount = 32;                    // 改为32位
    newHeader.biSizeImage = static_cast<DWORD>(pixelDataSize);  // 更新图像数据大小
    newHeader.biClrUsed = 0;                      // 32位不使用调色板

    // 复制颜色表（如果有）
    if (colorTableSize > 0) {
        // 对于32位，我们仍然保留颜色表结构（虽然不使用）
        // 复制原始颜色表以保持兼容性
        if (pBmi->bmiColors) {
            memcpy(result.pBitmapInfo->bmiColors, pBmi->bmiColors, colorTableSize * sizeof(RGBQUAD));
        }
    }

    // 执行像素格式转换：24位BGR -> 32位BGRA，并直接存储到内联缓冲区
    for (int y = 0; y < height; y++) {
        int srcY = topDown ? y : (height - 1 - y);
        const BYTE* pSrcRow = pPixelData24 + srcY * srcRowSize;
        BYTE* pDstRow = result.pPixelData + y * dstRowSize;

        for (int x = 0; x < width; x++) {
            // 24位格式：BGR (Blue, Green, Red)
            BYTE blue = pSrcRow[x * 3 + 0];
            BYTE green = pSrcRow[x * 3 + 1];
            BYTE red = pSrcRow[x * 3 + 2];

            // 32位格式：BGRA (Blue, Green, Red, Alpha)
            pDstRow[x * 4 + 0] = blue;   // Blue
            pDstRow[x * 4 + 1] = green;  // Green
            pDstRow[x * 4 + 2] = red;    // Red  
            pDstRow[x * 4 + 3] = 255;    // Alpha (完全不透明)
        }
    }

    result.totalSize = totalSize;
    result.success = true;

    return result;
}

static void onReleaseProc(void* addr, void* context)
{
    delete context;
}

bool ClipboardHostImpl::ReadPng(::blink::mojom::blink::ClipboardBuffer buffer, ::mojo_base::BigBuffer* outPng)
{
    ClipboardType clipboardType;
    if (!convertBufferType(buffer, &clipboardType))
        return false;

    HWND hWnd = getClipboardWindow();
    ScopedClipboard clipboard;
    if (!clipboard.acquire(hWnd))
        return false;

    // We use a DIB rather than a DDB here since ::GetObject() with the
    // HBITMAP returned from ::GetClipboardData(CF_BITMAP) always reports a color
    // depth of 32bpp.
    HANDLE hBitmap = ::GetClipboardData(CF_DIB);
    if (!hBitmap)
        return false;

    SkBitmap skBitmap;
    HDC hdcMem = nullptr;
    BYTE* bitmapBitsCopy = nullptr;
    bool isOk = false;
    BITMAPINFO* bmi = static_cast<BITMAPINFO*>(GlobalLock(hBitmap));
    BITMAPINFO* newBmi = nullptr;
    void* needFreeByte = nullptr;
    bool needLoop = false;
    do {
        needLoop = false;
        if (!bmi)
            break;
        int colorTableLength = 0;
        switch (bmi->bmiHeader.biBitCount) {
            case 1:
            case 4:
            case 8:
                colorTableLength = bmi->bmiHeader.biClrUsed ? bmi->bmiHeader.biClrUsed : 1 << bmi->bmiHeader.biBitCount;
                break;
            case 16:
            case 32:
                if (bmi->bmiHeader.biCompression == BI_BITFIELDS)
                    colorTableLength = 3;
                break;
            case 24:
                break;
            default:
                CHECK(false);
        }
        if (32 != bmi->bmiHeader.biBitCount && 24 != bmi->bmiHeader.biBitCount) // 只管这两种色深，其他的应该没系统会出现吧？
            break;
        if (24 == bmi->bmiHeader.biBitCount) {
            Bitmap32ConvertResult convertResult = convert24BitTo32BitBitmapInfo(bmi);
            newBmi = convertResult.pBitmapInfo;
            ::GlobalUnlock(hBitmap);
            hBitmap = nullptr;
            bmi = newBmi;
            if (!convertResult.success)
                break;
            needLoop = true;
            continue;
        }

        const void* bitmapBits = reinterpret_cast<const char*>(bmi) + bmi->bmiHeader.biSize + colorTableLength * sizeof(RGBQUAD);
        int width = std::abs((int)bmi->bmiHeader.biWidth);
        int height = std::abs((int)bmi->bmiHeader.biHeight);

        if (newBmi) {
            bitmapBitsCopy = (BYTE*)bitmapBits;
            needFreeByte = newBmi;
        } else {
            bitmapBitsCopy = flipDIBVertically((BYTE*)bitmapBits, width, height, bmi->bmiHeader.biBitCount == 32);
            needFreeByte = bitmapBitsCopy;
        }

        SkImageInfo skInfo = SkImageInfo::MakeN32Premul(width, height);
        if (!skBitmap.installPixels(skInfo, (void*)bitmapBitsCopy, skInfo.minRowBytes(), onReleaseProc, needFreeByte))
            break;
        newBmi = nullptr; // 在onReleaseProc里会自动释放
        needFreeByte = nullptr;

        // Windows doesn't really handle alpha channels well in many situations. When
        // the source image is < 32 bpp, we force the bitmap to be opaque. When the
        // source image is 32 bpp, the alpha channel might still contain garbage data.
        // Since Windows uses premultiplied alpha, we scan for instances where
        // (R, G, B) > A. If there are any invalid premultiplied colors in the image,
        // we assume the alpha channel contains garbage and force the bitmap to be
        // opaque as well. Note that this  heuristic will fail on a transparent bitmap
        // containing only black pixels...
        {
            bool hasInvalidAlphaChannel = bmi->bmiHeader.biBitCount >= 32 && bitmapHasInvalidPremultipliedColors(skBitmap);
            if (hasInvalidAlphaChannel)
                makeBitmapOpaque(skBitmap);
        }

        isOk = true;
    } while (needLoop);

    if (hdcMem)
        ::DeleteDC(hdcMem);
    if (hBitmap)
        ::GlobalUnlock(hBitmap);

    if (needFreeByte)
        delete needFreeByte;

    if (newBmi)
        delete newBmi;

    if (!isOk)
        return false;

    WTF::Vector<unsigned char> output;
    SkPngEncoder::Options opt;
    if (!blink::ImageEncoder::Encode(&output, skBitmap.pixmap(), opt))
        return false;

    ::mojo_base::BigBuffer bigBuf(base::span<const uint8_t>(output.data(), output.size()));
    *outPng = std::move(bigBuf);

    return true;
}

//using ReadPngCallback = base::OnceCallback<void(::mojo_base::BigBuffer)>;
void ClipboardHostImpl::ReadPng(::blink::mojom::blink::ClipboardBuffer buffer, ReadPngCallback callback)
{
    std::move(callback).Run(::mojo_base::BigBuffer());
}

bool ClipboardHostImpl::ReadFiles(::blink::mojom::blink::ClipboardBuffer buffer, ::blink::mojom::blink::ClipboardFilesPtr* out_result)
{
    return false;
}

//using ReadFilesCallback = base::OnceCallback<void(ClipboardFilesPtr)>;
void ClipboardHostImpl::ReadFiles(::blink::mojom::blink::ClipboardBuffer buffer, ReadFilesCallback callback)
{
    std::move(callback).Run(::blink::mojom::blink::ClipboardFiles::New());
}

// bool ClipboardHostImpl::ReadCustomData(::blink::mojom::blink::ClipboardBuffer buffer, const ::WTF::String& type, ::WTF::String* out_result)
// {
//     return false;
// }
// 
// //using ReadCustomDataCallback = base::OnceCallback<void(const ::WTF::String&)>;
// void ClipboardHostImpl::ReadCustomData(::blink::mojom::blink::ClipboardBuffer buffer, const ::WTF::String& type, ReadCustomDataCallback callback)
// {
//     std::move(callback).Run(::WTF::String());
// }

bool ClipboardHostImpl::ReadAvailableCustomAndStandardFormats(WTF::Vector<::WTF::String>* out_format_types)
{
    return false;
}

//using ReadAvailableCustomAndStandardFormatsCallback = base::OnceCallback<void(const WTF::Vector<::WTF::String>&)>;
void ClipboardHostImpl::ReadAvailableCustomAndStandardFormats(ReadAvailableCustomAndStandardFormatsCallback callback)
{
    std::move(callback).Run(WTF::Vector<::WTF::String>());
}

//using ReadUnsanitizedCustomFormatCallback = base::OnceCallback<void(::mojo_base::BigBuffer)>;
void ClipboardHostImpl::ReadUnsanitizedCustomFormat(const ::WTF::String& format, ReadUnsanitizedCustomFormatCallback callback)
{
    std::move(callback).Run(::mojo_base::BigBuffer());
}

bool ClipboardHostImpl::ReadDataTransferCustomData(blink::mojom::blink::ClipboardBuffer buffer, const ::WTF::String& type, ::WTF::String* out_result)
{
    *(int*)1 = 1;
    return false;
}

void ClipboardHostImpl::ReadDataTransferCustomData(blink::mojom::blink::ClipboardBuffer buffer, const ::WTF::String& type, ReadDataTransferCustomDataCallback callback)
{
    *(int*)1 = 1;
}

// O:\chromium\ele32fp\ui\base\clipboard\scoped_clipboard_writer.cc
// O:\chromium\ele32fp\ui\base\clipboard\clipboard_win.cc
// O:\chromium\ele32fp\ui\base\clipboard\clipboard.cc
// O:\chromium\ele32fp\content\browser\renderer_host\clipboard_host_impl.cc

const UINT getDataTransferCustomType()
{
    // TODO(http://crbug.com/106449): Standardize this name.
    static UINT format = ::RegisterClipboardFormat(L"Chromium Web Custom MIME Data Format");
    return format;
}

void writeCustomDataToPickle(const WTF::HashMap<::WTF::String, ::WTF::String>& data, base::Pickle* pickle)
{
    pickle->WriteUInt32(data.size());
    for (WTF::HashMap<::WTF::String, ::WTF::String>::const_iterator it = data.begin(); it != data.end(); ++it) {
        String key = it->key;
        String value = it->value;

        pickle->WriteString(key.Utf8());
        pickle->WriteString(value.Utf8());
    }
}

void ClipboardHostImpl::WriteDataTransferCustomData(const WTF::HashMap<::WTF::String, ::WTF::String>& data)
{
    if (0 == data.size())
        return;
    base::Pickle pickle;
    writeCustomDataToPickle(data, &pickle);

    ScopedClipboard clipboard;
    if (!clipboard.acquire(getClipboardWindow()))
        return;

    HGLOBAL glob = ClipboardUtil::createGlobalDataByByte(pickle.data(), pickle.size());
    writeToClipboardInternal(getDataTransferCustomType(), glob);
    ::GlobalFree(glob);
}

void ClipboardHostImpl::writeToClipboardInternal(unsigned int format, HANDLE handle)
{
    DCHECK(m_clipboardOwner != NULL);
    if (handle && !::SetClipboardData(format, handle)) {
        DCHECK(ERROR_CLIPBOARD_NOT_OPEN != GetLastError());
        freeData(format, handle);
    }
}

void ClipboardHostImpl::writeTextInternal(const WTF::String& string)
{
    if (string.empty())
        return;

    std::u16string strW;
    HGLOBAL glob = NULL;
    if (string.Is8Bit()) {
        strW = base::UTF8ToUTF16(string.Utf8());
    } else
        strW.assign((const char16_t*)string.Characters16(), string.length());

    glob = ClipboardUtil::createGlobalData<char16_t>(strW);

    writeToClipboardInternal(CF_UNICODETEXT, glob);
}

void ClipboardHostImpl::WriteText(const ::WTF::String& text)
{
    ScopedClipboard clipboard;
    if (!clipboard.acquire(getClipboardWindow()))
        return;

    ::EmptyClipboard();

    writeTextInternal(text);
}

void ClipboardHostImpl::WriteHtml(const ::WTF::String& markup, const ::blink::KURL& url)
{
}

void ClipboardHostImpl::WriteSvg(const ::WTF::String& markup)
{
}

void ClipboardHostImpl::WriteSmartPasteMarker()
{
}

void ClipboardHostImpl::WriteBookmark(const WTF::String& url, const ::WTF::String& title)
{
}

void ClipboardHostImpl::WriteImage(const ::SkBitmap& image)
{
}

void ClipboardHostImpl::WriteUnsanitizedCustomFormat(const ::WTF::String& format, ::mojo_base::BigBuffer data)
{
}

void ClipboardHostImpl::CommitWrite()
{
}

extern "C" LRESULT __stdcall clipboardOwnerWndProc(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    LRESULT result = 0;
    switch (message) {
    case WM_RENDERFORMAT:
        // This message comes when SetClipboardData was sent a null data handle
        // and now it's come time to put the data on the clipboard.
        // We always set data, so there isn't a need to actually do anything here.
        break;
    case WM_RENDERALLFORMATS:
        // This message comes when SetClipboardData was sent a null data handle
        // and now this application is about to quit, so it must put data on
        // the clipboard before it exits.
        // We always set data, so there isn't a need to actually do anything here.
        break;
    case WM_DRAWCLIPBOARD:
        break;
    case WM_DESTROY:
        break;
    case WM_CHANGECBCHAIN:
        break;
    default:
        return DefWindowProcW(hWnd, message, wparam, lparam);
    }

    return result;
}

HWND ClipboardHostImpl::m_clipboardOwner = nullptr;

HWND ClipboardHostImpl::getClipboardWindow()
{
    if (INVALID_HANDLE_VALUE != m_clipboardOwner && NULL != m_clipboardOwner)
        return m_clipboardOwner;

    WNDCLASSEXW windowClass;
    windowClass.cbSize = sizeof(windowClass);
    windowClass.style = 0;
    windowClass.lpfnWndProc = clipboardOwnerWndProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = nullptr;
    windowClass.hIcon = NULL;
    windowClass.hCursor = NULL;
    windowClass.hbrBackground = NULL;
    windowClass.lpszMenuName = NULL;
    windowClass.lpszClassName = mbu16("WebClipboardImplMessageWindow");
    windowClass.hIconSm = NULL;
    ATOM atom = RegisterClassExW(&windowClass);

    m_clipboardOwner = ::CreateWindowW(MAKEINTATOM(atom), mbu16("window_name"), 0, 0, 0, 1, 1, HWND_MESSAGE, 0, NULL, NULL);

    return m_clipboardOwner;
}

}