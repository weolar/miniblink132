
#ifndef content_StringUtil_h
#define content_StringUtil_h

#include <string>
#include <vector>
#include <memory>

#if defined(WIN32)
typedef wchar_t WCHAR;
// namespace base {
// typedef std::wstring string16;
// }
#else
// #include "base/strings/string16.h"
typedef char16_t WCHAR;
#endif

namespace content {

std::string utf16ToUtf8(const WCHAR* lpszSrc);
std::string utf16ToMulByte(const WCHAR* lpszSrc, size_t len, unsigned int codepage);

void mulByteToUtf8(const char* lpMCharStr, size_t cchMChar, std::vector<char>* out, unsigned int codePage);
void WCharToMByte(const WCHAR* lpWideCharStr, size_t cchWideChar, std::vector<char>* out, unsigned int codePage);
void MByteToWChar(const char* lpcszStr, size_t cbMultiByte, std::vector<WCHAR>* out, unsigned int codePage);

std::u16string utf8ToUtf16(const std::string& utf8);
std::u16string mulByteToUtf16(const std::string& str, unsigned int codepage);
bool isTextUTF8(const char* str, size_t length);

std::string base64Encode(const unsigned char* bytesToEncode, unsigned int inLen);
std::vector<unsigned char> base64Decode(const std::string& encodedString);

std::u16string createPathFromDllPath(const std::u16string& fileName);

bool isLocalDebugMachine();

void setPluginDirectory(const std::u16string& dir);
std::u16string getPluginDirectory();

std::unique_ptr<std::string> urlNormalization(const char* url);

unsigned int hashStringA(const std::string& p);
unsigned int hashStringW(const std::u16string& p);

}

#endif // base_StringUtil_h