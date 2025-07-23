
#include "content/common/StringUtil.h"

#include <string>
#include <string.h>
#include <vector>
#include <windows.h>
#include <shlwapi.h>
#include "content/common/mbchar.h"
#if defined(OS_LINUX)
#include <iconv.h>
#endif

extern HMODULE g_hModule;

namespace content {

std::string utf16ToUtf8(const WCHAR* lpszSrc)
{
    return utf16ToMulByte(lpszSrc, u16len((const UChar*)lpszSrc), CP_UTF8);
}

void mulByteToUtf8(const char* lpMCharStr, size_t cchMChar, std::vector<char>* out, unsigned int codePage)
{
    out->resize(0);

    std::vector<WCHAR> tempBuf;
    MByteToWChar(lpMCharStr, cchMChar, &tempBuf, codePage);
    if (0 == tempBuf.size())
        return;
    WCharToMByte(&tempBuf[0], tempBuf.size(), out, CP_UTF8);
}

void WCharToMByte(const WCHAR* lpWideCharStr, size_t cchWideChar, std::vector<char>* out, unsigned int codePage)
{
    out->clear();
    if (0 == cchWideChar || nullptr == lpWideCharStr)
        return;

#if !defined(OS_WIN)
    cchWideChar *= sizeof(WCHAR);
    out->resize(cchWideChar * 4);

    iconv_t cd;
    char* data = out->data();
    char* pIn = (char*)lpWideCharStr;
    char** ppIn = &pIn;
    char** ppOut = &data;
    size_t outlen = out->size();
    size_t oldSize = outlen;

    if (CP_UTF8 == codePage) {
        cd = iconv_open("UTF-8//IGNORE", "UTF-16le");
    } else {
        cd = iconv_open("gb2312//IGNORE", "UTF-16le");
    }
    if (cd == 0)
        return;

    memset(data, 0, outlen);
    if (iconv(cd, ppIn, &cchWideChar, ppOut, &outlen) == -1)
        return;
    iconv_close(cd);

    size_t len = *ppOut - out->data();
    if (len != oldSize - outlen)
        *(int*)1 = 1;
    out->resize(len);
#else
    DWORD dwMinSize;
    dwMinSize = WideCharToMultiByte(codePage, 0, (const WCHAR*)lpWideCharStr, cchWideChar, NULL, 0, NULL, FALSE);
    if (0 == dwMinSize)
        return;

    out->resize(dwMinSize);

    // Convert headers from ASCII to Unicode.
    WideCharToMultiByte(codePage, 0, (const WCHAR*)lpWideCharStr, cchWideChar, &out->at(0), dwMinSize, NULL, FALSE);
#endif
}

std::string utf16ToMulByte(const WCHAR* lpszSrc, size_t len, unsigned int codepage)
{
#if !defined(OS_WIN)
    std::vector<char> out;
    WCharToMByte(lpszSrc, /*u16len(lpszSrc)*/len, &out, codepage);
    if (0 == out.size())
        return std::string();
    std::string ret;
    ret.assign(out.size(), '\0');
    memcpy((void*)ret.c_str(), out.data(), out.size());
    return ret;
#else
    std::string sResult;
    if (lpszSrc != NULL) {
        int nUTF8Len = WideCharToMultiByte(codepage, 0, lpszSrc, len, NULL, 0, NULL, NULL);
        char* pUTF8 = new char[nUTF8Len + 1];
        if (pUTF8 != NULL) {
            ZeroMemory(pUTF8, nUTF8Len + 1);
            WideCharToMultiByte(codepage, 0, lpszSrc, len, pUTF8, nUTF8Len, NULL, NULL);
            sResult = pUTF8;
            delete[] pUTF8;
        }
    }
    return sResult;
#endif // __clang__
}

void MByteToWChar(const char* lpcszStr, size_t cbMultiByte, std::vector<WCHAR>* out, unsigned int codePage)
{
    out->clear();
    if (nullptr == lpcszStr || 0 == cbMultiByte)
        return;
#if defined(OS_LINUX)
    out->resize(cbMultiByte * 4 / sizeof(WCHAR));

    iconv_t cd;
    char* data = (char*)out->data();
    char* pIn = (char*)lpcszStr;
    char** ppIn = &pIn;
    char** ppOut = &data;
    size_t outlen = out->size() * sizeof(WCHAR);
    size_t oldSize = outlen;

    if (CP_UTF8 == codePage) {
        cd = iconv_open("UTF-16le//IGNORE", "UTF-8");
    } else {
        cd = iconv_open("UTF-16le//IGNORE", "gb2312");
    }
    if (cd == 0)
        return;

    memset(data, 0, outlen);
    if (iconv(cd, ppIn, &cbMultiByte, ppOut, &outlen) == -1)
        return;
    iconv_close(cd);

    size_t len = (((const WCHAR*)*ppOut) - out->data()) * sizeof(WCHAR);
    if (len != oldSize - outlen) {
        printf("MByteToWChar fail, len:%zu, oldSize:%zu, %p, %p, outlen: %zu\n", len, oldSize, *ppOut, out->data(), outlen);
        *(int*)1 = 1;
    }

    size_t pre = len % sizeof(WCHAR);
    len += pre;
    if (len > oldSize)
        len = oldSize;

    out->resize(len / sizeof(WCHAR));
#else
    DWORD dwMinSize;
    dwMinSize = MultiByteToWideChar(codePage, 0, lpcszStr, cbMultiByte, NULL, 0);
    if (0 == dwMinSize)
        return;

    out->resize(dwMinSize);

    // Convert headers from ASCII to Unicode.
    MultiByteToWideChar(codePage, 0, lpcszStr, cbMultiByte, (WCHAR*)(out->data()), dwMinSize);
#endif
}

std::u16string utf8ToUtf16(const std::string& utf8)
{
    return mulByteToUtf16(utf8, CP_UTF8);
}

std::u16string mulByteToUtf16(const std::string& str, unsigned int codepage)
{
#ifdef __clang__
    std::vector<WCHAR> out;
    MByteToWChar(str.c_str(), str.size(), &out, codepage);
    if (0 == out.size())
        return std::u16string();
    std::u16string ret;
    ret.assign(out.size(), L'\0');
    memcpy((void*)ret.c_str(), out.data(), out.size() * sizeof(WCHAR));
    return ret;
#else
    std::u16string utf16;
    size_t n = ::MultiByteToWideChar(codepage, 0, str.c_str(), (int)str.size(), nullptr, 0);
    if (0 == n)
        return (const char16_t*)L"";
    std::vector<WCHAR> wbuf(n);
    ::MultiByteToWideChar(codepage, 0, str.c_str(), (int)str.size(), wbuf.data(), n);
    utf16.resize(n + 5);
    utf16.assign((const char16_t*)(wbuf.data()), n);
    return utf16;
#endif // __clang__
}

static const std::string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                       "abcdefghijklmnopqrstuvwxyz"
                                       "0123456789+/";

static inline bool isBase64(unsigned char c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64Encode(const unsigned char* bytesToEncode, unsigned int inLen)
{
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char charArray3[3];
    unsigned char charArray4[4];

    while (inLen--) {
        charArray3[i++] = *(bytesToEncode++);
        if (i == 3) {
            charArray4[0] = (charArray3[0] & 0xfc) >> 2;
            charArray4[1] = ((charArray3[0] & 0x03) << 4) + ((charArray3[1] & 0xf0) >> 4);
            charArray4[2] = ((charArray3[1] & 0x0f) << 2) + ((charArray3[2] & 0xc0) >> 6);
            charArray4[3] = charArray3[2] & 0x3f;

            for (i = 0; (i < 4); i++)
                ret += base64Chars[charArray4[i]];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 3; j++)
            charArray3[j] = '\0';

        charArray4[0] = (charArray3[0] & 0xfc) >> 2;
        charArray4[1] = ((charArray3[0] & 0x03) << 4) + ((charArray3[1] & 0xf0) >> 4);
        charArray4[2] = ((charArray3[1] & 0x0f) << 2) + ((charArray3[2] & 0xc0) >> 6);
        charArray4[3] = charArray3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
            ret += base64Chars[charArray4[j]];

        while ((i++ < 3))
            ret += '=';
    }

    return ret;
}

std::vector<unsigned char> base64Decode(const std::string& encodedString)
{
    size_t inLen = encodedString.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char charArray4[4], charArray3[3];
    std::vector<unsigned char> ret;

    while (inLen-- && (encodedString[in_] != '=') && isBase64(encodedString[in_])) {
        charArray4[i++] = encodedString[in_];
        in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                charArray4[i] = (unsigned char)base64Chars.find(charArray4[i]);

            charArray3[0] = (charArray4[0] << 2) + ((charArray4[1] & 0x30) >> 4);
            charArray3[1] = ((charArray4[1] & 0xf) << 4) + ((charArray4[2] & 0x3c) >> 2);
            charArray3[2] = ((charArray4[2] & 0x3) << 6) + charArray4[3];

            for (i = 0; (i < 3); i++)
                ret.push_back(charArray3[i]);
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            charArray4[j] = 0;

        for (j = 0; j < 4; j++)
            charArray4[j] = (unsigned char)base64Chars.find(charArray4[j]);

        charArray3[0] = (charArray4[0] << 2) + ((charArray4[1] & 0x30) >> 4);
        charArray3[1] = ((charArray4[1] & 0xf) << 4) + ((charArray4[2] & 0x3c) >> 2);
        charArray3[2] = ((charArray4[2] & 0x3) << 6) + charArray4[3];

        for (j = 0; (j < i - 1); j++)
            ret.push_back(charArray3[j]);
    }

    return ret;
}

bool isTextUTF8(const char* str, size_t length)
{
    size_t i = 0;
    DWORD nBytes = 0; // UFT8可用1-6个字节编码,ASCII用一个字节
    UCHAR chr = 0;
    bool bAllAscii = true; // 如果全部都是ASCII, 说明不是UTF-8
    for (i = 0; i < length; ++i) {
        chr = (UCHAR) * (str + i);

        if ((chr & 0x80) != 0) // 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx
            bAllAscii = false;

        if (nBytes == 0) { // 如果不是ASCII码,应该是多字节符,计算字节数

            if (chr >= 0x80) {
                if (chr >= 0xFC && chr <= 0xFD)
                    nBytes = 6;
                else if (chr >= 0xF8)
                    nBytes = 5;
                else if (chr >= 0xF0)
                    nBytes = 4;
                else if (chr >= 0xE0)
                    nBytes = 3;
                else if (chr >= 0xC0)
                    nBytes = 2;
                else {
                    return false;
                }
                nBytes--;
            }
        } else { // 多字节符的非首字节,应为 10xxxxxx
            if ((chr & 0xC0) != 0x80)
                return false;
            nBytes--;
        }
    }
    if (nBytes > 0) //违返规则
        return false;

    if (bAllAscii) //如果全部都是ASCII, 说明不是UTF-8
        return false;
    return true;
}

std::u16string createPathFromDllPath(const std::u16string& fileName)
{
#if defined(WIN32)
    std::vector<WCHAR> path;
    path.resize(MAX_PATH + 1);
    memset(&path.at(0), 0, sizeof(WCHAR) * (MAX_PATH + 1));
    ::GetModuleFileNameW(g_hModule, &path.at(0), MAX_PATH);
    ::PathRemoveFileSpecW(&path.at(0));

    ::PathAppendW(&path.at(0), (const WCHAR*)(fileName.c_str()));

    std::u16string result((const char16_t*)(path.data()), wcslen(&path.at(0)));

    if (L'\\' != result[result.size() - 1])
        result += L'\\';

    return result;
#else
    DebugBreak();
    return std::u16string();
#endif
}

bool isLocalDebugMachine()
{
#if defined(WIN32)
    return !!::PathFileExistsW(L"E:\\mycode\\mtmb\\mtmb\\printing\\Printing.cpp");
#else
    DebugBreak();
    return false;
#endif
}

static std::u16string* g_pluginDirectory;

void setPluginDirectory(const std::u16string& dir)
{
    if (0 == dir.size())
        return;

    if (g_pluginDirectory)
        delete g_pluginDirectory;
    g_pluginDirectory = new std::u16string(dir);

    if (g_pluginDirectory->at(g_pluginDirectory->size() - 1) != mbu16('\\'))
        *g_pluginDirectory += u'\\';
}

std::u16string getPluginDirectory()
{
    if (g_pluginDirectory)
        return *g_pluginDirectory;

    g_pluginDirectory = new std::u16string(createPathFromDllPath(u"plugins\\"));
    return *g_pluginDirectory;
}

unsigned int hashStringW(const std::u16string& p)
{
    std::string str((const char*)p.c_str(), p.size() * sizeof(WCHAR));
    return hashStringA(str);
}

unsigned int hashStringA(const std::string& p)
{
    int prime = 25013;
    unsigned int h = 0;
    unsigned int g;

    for (size_t i = 0; i < p.size(); ++i) {
        h = (h << 4) + p[i];
        g = h & 0xF0000000;
        if (g) {
            h ^= (g >> 24);
            h ^= g;
        }
    }
    return h % prime;
}

}