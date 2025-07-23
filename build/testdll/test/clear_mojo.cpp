
#if 1

#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <set>
#include <windows.h>
#include <vector>
#include <Shlwapi.h>
//#include "G:/mycode/mb/wke/wkedefine.h"

#include <vector>
#include <algorithm>

std::wstring utf8ToUtf16(const std::string& utf8);
std::string utf16ToChar(LPCWSTR lpszSrc, UINT codepage);
std::string utf16ToUtf8(LPCWSTR lpszSrc);

void readFile(const wchar_t* path, std::vector<char>* buffer);
bool saveDumpFile(const std::wstring& url, const char* buffer, unsigned int size);

void readFileToBuf(const wchar_t* path, std::vector<char>* buffer)
{
    buffer->clear();
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
        return;

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (0 == bufferSize)
        return;

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
}

std::vector<std::string> splitString(const std::string& str, char delimiter)
{
    //   std::string str = "hello world, this is a string";
    //   char delimiter = ' ';

    std::vector<std::string> result;
    size_t posA = 0;
    size_t posB = 0;

    for (int i = 0; i < str.size(); ++i, ++posB) {
        char current = str[i];
        if (current == delimiter) {
            if (posA == posB) {
                result.push_back(std::string()/* + delimiter*/);
            } else {
                std::string sub = str.substr(posA + 0, posB - posA);
                result.push_back(sub);
            }
            posA = posB + 1;
        } else {
            if (i == str.size() - 1) {
                std::string sub = str.substr(posA + 0, posB + 1 - posA);
                result.push_back(sub);
            }
        }
    }

    return result;
}

void replaceAll(std::string* str, const std::string& old_value, const std::string& new_value)
{
    while (true) {
        std::string::size_type pos(0);
        if ((pos = str->find(old_value)) != std::string::npos)
            str->replace(pos, old_value.length(), new_value);
        else
            break;
    }
}

bool isEndWith(const std::string& str, const std::string& subStr)
{
    if (str.length() < subStr.length())
        return false;
    std::string suffix = str.substr(str.length() - subStr.length(), std::string::npos);
    return suffix == subStr;
}

bool isStartWith(const std::string& str, const std::string& subStr)
{
    if (str.length() < subStr.length())
        return false;
    std::string suffix = str.substr(0, subStr.length());
    return suffix == subStr;
}

// 清理namespace WTF {}里的
bool doClear_WTF(std::vector<std::string> lines)
{
    for (size_t i = 0; i < lines.size(); ++i) {
        std::string line = lines[i];
        if (isStartWith(line, "namespace WTF {")) {
            for (size_t j = i; j < lines.size(); ++j) {
                std::string line2 = lines[i];
                if (std::string::npos != line2.find("// namespace WTF")) {
                    lines.erase(lines.begin() + i, lines.begin() + j);
                    return true;
                }
            }
        }
    }
    return false;
}

void clear_WTF(std::vector<std::string> lines)
{
    do {
        ;
    } while (doClear_WTF(lines));
}

std::vector<std::string> splitStr(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == delimiter) {
            tokens.push_back(token);
            token.clear();
        } else {
            token += s[i];
        }
    }
    tokens.push_back(token);
    return tokens;
}

size_t findClassNamePosImpl(const std::string& str, size_t pos, std::string* className, const char* kClass)
{
    //const char kClass[] = "class CORE_EXPORT ";
    size_t kLen = strlen(kClass);
    size_t classNameEnd = 0;
    size_t classNameBegin = 0;
    size_t i = pos;

    while (true) {
        size_t nextPos = str.find(kClass, i + 1);
        classNameBegin = nextPos + kLen;
        if (std::string::npos == nextPos)
            return std::string::npos;

        // class CORE_EXPORT KeepAliveHandle  : xx
        i = nextPos + kLen;
        for (; i < str.size(); ++i) {
            if (str[i] != ' ')
                break;
        }

        classNameEnd = str.find(' ', i);
        if (std::string::npos == nextPos)
            return std::string::npos;

        bool find = false;
        i = classNameEnd;
        for (; i < str.size(); ++i) {
            if (str[i] == ' ')
                continue;

            find = (str[i] == ':');
            break;
        }

        if (find)
            continue;
        break;
    }

    *className = str.substr(classNameBegin, classNameEnd - classNameBegin - 0);
    return classNameEnd;
}

const char* kClassNames[] = {
    "class CORE_EXPORT ",
    "class  ",
    "class CORE_TEMPLATE_EXPORT ",
    "class PLATFORM_EXPORT ",
    "class BLINK_COMMON_EXPORT ",
    "class BLINK_PLATFORM_EXPORT ",
    "class BLINK_MODULES_EXPORT ",
    "class BLINK_EXPORT ",
    nullptr
};

int isDigitOrAlpha(char c) 
{
    return isdigit((unsigned char)c) || isalpha((unsigned char)c);
}

size_t findClassNamePos(const std::string& str, size_t pos, std::string* className)
{
    size_t ret = std::string::npos;
    for (size_t i = 0; kClassNames[i]; ++i) {
        ret = findClassNamePosImpl(str, pos, className, kClassNames[i]);
        if (std::string::npos != ret)
            return ret;
    }

    // 查找这类型的: "class xxx {\n"
    const char kClassName[] = "class ";
    while (true) {
        ret = str.find(kClassName, pos);
        if (std::string::npos == ret)
            return ret;
        pos = ret + sizeof(kClassName) - 1;

        for (size_t i = ret; i < str.size(); ++i) {
            if ('\n' == str[i])
                break;
            if ('{' == str[i]) {
                ret += sizeof(kClassName) - 1;
                size_t j = ret;
                int spaceCount = 0; // 空格的数量。按理说只有1个空格
                for (; j < i; ++j) {
                    char c = str[j];
                    if (':' == c) // 防止这种的：class BLINK_PLATFORM_EXPORT WebBluetoothServiceInterceptorForTesting : public WebBluetoothService {
                        break;
                    if (' ' == c)
                        spaceCount++;
                }
                if (1 != spaceCount)
                    break;
                *className = str.substr(ret, i - ret - 1);
                return ret;
            }
        }
    }
    
    return std::string::npos;
}

bool findClassName(const std::string& str, std::string* className)
{
    if (std::string::npos != str.find("BLINK_COMMON_EXPORT LocalFrameHostProxy"))
        OutputDebugStringA("");

    for (int i = 0; kClassNames[i]; ++i) {
        size_t begin = str.find(kClassNames[i]);
        if (std::string::npos == begin)
            continue;

        size_t classNameBegin = begin + strlen(kClassNames[i]);
        size_t end = str.find(' ', classNameBegin);
        if (std::string::npos == end)
            end = str.size();

        *className = str.substr(classNameBegin, end - classNameBegin);
        return true;
    }
    return false;
}

// FindOptions();
// 
// FindOptions(
//   bool forward,
//   bool match_case,
//   bool new_session,
//   bool find_match,
//   bool force,
//   bool run_synchronously_for_testing);
// 
// ~FindOptions();
bool fixConstructorNoParam(std::string* str, const std::string& cppStr, const std::string& className)
{
    const std::string kConstructorStr = className + "()";
    size_t pos1 = str->find(" " + kConstructorStr);
    if (std::string::npos == pos1)
        return false;
    pos1++;

    if ((*str)[pos1 + kConstructorStr.size() + 0] != ';') {
        const char* ptr = str->c_str() + pos1;
        return false;
    }

    size_t pos1End = pos1 + kConstructorStr.size();

    const std::string kConstructorCppStr = className + "::" + className + "()";
    size_t pos2 = cppStr.find(kConstructorCppStr);
    if (std::string::npos == pos2)
        return false;

    size_t pos2End = cppStr.find("{", pos2);
    if (std::string::npos == pos2End)
        return false;
    if (cppStr[pos2End + 1] != '}' && cppStr[pos2End + 1] != '\n')
        return false;

    if (cppStr[pos2End + 1] == '}')
        pos2End = cppStr.find("{}", pos2);
    if (cppStr[pos2End + 1] == '\n')
        pos2End = cppStr.find("\n}", pos2) + 1;

    const std::string constructorBody = cppStr.substr(pos2 + kConstructorCppStr.size(), pos2End - kConstructorCppStr.size() - pos2 + 3);
    if (0 == constructorBody.size())
        return false;

    str->replace(pos1End, 1, constructorBody);
    return true;
}

// 找到下面第二个这个带参数的
// BrowserControlsOffsetTagsInfo()
//     : content_offset_tag()
//     , top_controls_offset_tag()
//     , top_controls_height()
//     , top_controls_hairline_height()
// {
// 
// 
//     BrowserControlsOffsetTagsInfo(::viz::mojom::blink::OffsetTagPtr content_offset_tag, ::viz::mojom::blink::OffsetTagPtr top_controls_offset_tag,
//         int32_t top_controls_height, int32_t top_controls_hairline_height);
bool fixConstructorWithParam(std::string* str, const std::string& cppStr, const std::string& className)
{
    const std::string kConstructorStr = className + "(";
    size_t pos1 = str->find(" " + kConstructorStr);
    if (std::string::npos == pos1)
        return false;
    char c = (*str)[pos1 + kConstructorStr.size() + 1];
    if (c != ')')
        return false;
    pos1 = str->find(" " + kConstructorStr, pos1 + 1);
    pos1++;

    size_t pos1End = str->find(")", pos1);
    if ((*str)[pos1End + 1] != ';')
        return false;
    pos1End = str->find(");", pos1);

    // 然后找对应cpp的:
    //BrowserControlsOffsetTagsInfo::BrowserControlsOffsetTagsInfo()
    //     : content_offset_tag()
    //         , top_controls_offset_tag()
    //         , top_controls_height()
    //         , top_controls_hairline_height()
    //     {
    //     }
    // 
    //     BrowserControlsOffsetTagsInfo::BrowserControlsOffsetTagsInfo(::viz::mojom::blink::OffsetTagPtr content_offset_tag_in,
    //         ::viz::mojom::blink::OffsetTagPtr top_controls_offset_tag_in, int32_t top_controls_height_in, int32_t top_controls_hairline_height_in)
    //         : content_offset_tag(std::move(content_offset_tag_in))
    //         , top_controls_offset_tag(std::move(top_controls_offset_tag_in))
    //         , top_controls_height(std::move(top_controls_height_in))
    //         , top_controls_hairline_height(std::move(top_controls_hairline_height_in))
    //     {
    //     }
    const std::string kConstructorCppStr = className + "::" + className + "(";
    size_t pos2 = cppStr.find(kConstructorCppStr);
    if (std::string::npos == pos2)
        return false;
    pos2 = cppStr.find(kConstructorCppStr, pos2 + 1);
    if (std::string::npos == pos2)
        return false;

    size_t pos3 = cppStr.find(")", pos2);
    if (std::string::npos == pos3)
        return false;
   
    size_t pos2End = cppStr.find("{", pos2);
    if (cppStr[pos2End + 1] != '}' && cppStr[pos2End + 1] != '\n')
        return false;

    if (cppStr[pos2End + 1] == '}')
        pos2End = cppStr.find("{}", pos2);
    if (cppStr[pos2End + 1] == '\n')
        pos2End = cppStr.find("{\n}", pos2) - 2;

    std::string constructorBody = cppStr.substr(pos2 + kConstructorCppStr.size() + 0, pos2End - pos2 - kConstructorCppStr.size() + 1);
    if (0 == constructorBody.size())
        return false;
    constructorBody += "{\n}";
    str->replace(pos1 + kConstructorStr.size() + 0, pos1End - pos1 - kConstructorStr.size() + 2, constructorBody);
    return true;
}

// 分两种情况：
// CSPViolation::~CSPViolation() = default;
// AllowCSPFromHeaderValue::~AllowCSPFromHeaderValue()
// {
//     DestroyActive();
// }
bool fixDeconstructor(std::string* str, const std::string& cppStr, const std::string& className)
{
    const std::string kDeconstructorStr1 = "~" + className + "() = default;";
    const std::string kDeconstructorStr2 = "~" + className + "()\n";
    const std::string kDeconstructorStr = "~" + className + "();";

    size_t pos1 = cppStr.find(kDeconstructorStr1);
    if (std::string::npos != pos1) {
        pos1 = str->find(kDeconstructorStr);
        if (std::string::npos == pos1)
            return false;
        if (std::string::npos != str->find("~" + className + "() = default;"))
            return false;

        str->replace(pos1 + kDeconstructorStr.size() - 1, 1, " = default;");
        return true;
    }

    pos1 = cppStr.find(kDeconstructorStr2);
    if (std::string::npos != pos1) {
        size_t pos2 = cppStr.find("\n}", pos1);
        std::string deconstructorBody = cppStr.substr(pos1 + kDeconstructorStr2.size(), pos2 - pos1 - kDeconstructorStr2.size() + 2);

        size_t pos3 = str->find(kDeconstructorStr);
        if (std::string::npos == pos3)
            DebugBreak();
        str->replace(pos3 + kDeconstructorStr2.size() - 1, 1, deconstructorBody);
        return true;
    }
    return false;
}

const char* kOldGenDir = nullptr;
const char* kNewGenDir = nullptr;

void fixMojoConstructor(LPCWSTR filePath, int* count)
{
    std::string filePathUtf8 = utf16ToUtf8(filePath);
    if (filePathUtf8.find(".mojom") == std::string::npos || !isEndWith(filePathUtf8, ".h"))
        return;

    std::string cppPath = filePathUtf8;
    cppPath[cppPath.size() - 1] = 'c';
    cppPath += 'c';
    if (!::PathFileExistsW(utf8ToUtf16(cppPath).c_str())) {
        replaceAll(&cppPath, "-internal.cc", ".cc");
        if (!::PathFileExistsW(utf8ToUtf16(cppPath).c_str()))
            return;
    }

    std::vector<char> buffer;
    readFileToBuf(filePath, &buffer);
    if (buffer.size() == 0)
        return;
    buffer.push_back(0);

    std::string str = buffer.data();
    replaceAll(&str, "\r", "");

    readFileToBuf(utf8ToUtf16(cppPath).c_str(), &buffer);
    if (buffer.size() == 0)
        return;
    buffer.push_back(0);
    std::string cppStr = buffer.data();

    bool needSave = false;
    size_t pos = 0;
    for (;;) {
        std::string className;
        pos = findClassNamePos(str, pos, &className); // 找到class名字
        if (std::string::npos == pos)
            break;

        needSave = fixDeconstructor(&str, cppStr, className);
        if (!needSave)
            continue;
        needSave = fixConstructorNoParam(&str, cppStr, className);
        if (!needSave)
            continue;
        needSave = fixConstructorWithParam(&str, cppStr, className);
        if (!needSave)
            continue;
        replaceAll(&cppStr, className + "::" + className, className + "__" + className);
    }

    if (!needSave)
        return;

    replaceAll(&filePathUtf8, kOldGenDir, kNewGenDir);

    std::vector<char> output;
    output.resize(filePathUtf8.size() + 100);
    sprintf_s(output.data(), output.size() - 1, "%d, %s\n", *count, filePathUtf8.c_str());
    OutputDebugStringA(output.data());
    ++(*count);

    saveDumpFile(utf8ToUtf16(filePathUtf8).c_str(), str.c_str(), str.length());
}

static size_t findNextClassEnd(const std::vector<std::string>& lines, size_t lineNum)
{
    for (size_t i = lineNum; i < lines.size(); ++i) {
        if (std::string::npos != lines[i].find("};")) {
            return i;
        }
    }
    return std::string::npos;
}

static void addComments(std::vector<std::string>* lines, size_t begin, size_t end)
{
    for (size_t i = begin; i <= end; ++i) {
        if (isStartWith(lines->at(i), "//"))
            return;
        lines->at(i).insert(0, "//");
    }
}

static std::string arrayToString(const std::vector<std::string>& lines)
{
    std::string ret;
    for (size_t i = 0; i < lines.size(); ++i) {
        ret += lines[i];
        if (lines[i] != "\n")
            ret += '\n';
    }
    return ret;
}

static bool findNeedDeleteProxyStubPos(const std::vector<std::string>& lines, size_t begin, size_t* nextClassEnd)
{
    std::string className;
    if (!findClassName(lines[begin], &className))
        return false;

    if (!isEndWith(className, "StubDispatch") && !isEndWith(className, "Proxy") && !isEndWith(className, "Stub"))
        return false;

    *nextClassEnd = findNextClassEnd(lines, begin);
    return true;
}

// 找这种类型的：
// class BLINK_COMMON_EXPORT KeepAliveHandleRequestValidator : public mojo::MessageReceiver {
// public:
//     bool Accept(mojo::Message* message) override;
// };
static bool findNeedDeleteValidator(const std::vector<std::string>& lines, size_t begin, size_t* nextClassEnd)
{
    std::string line = lines[begin];
    if (std::string::npos == line.find("class ") || std::string::npos == line.find("Validator : public "))
        return false;

    *nextClassEnd = findNextClassEnd(lines, begin);
    return true;
}


// 找这种的：
// template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AttributionHost>> class AttributionHostStub : public mojo::MessageReceiverWithResponderStatus {
// public:
// 找这种类型的：
// template <typename ImplRefTraits =
//     mojo::RawPtrImplRefTraits<KeepAliveHandle>>
//     class KeepAliveHandleStub
//     : public mojo::MessageReceiverWithResponderStatus {
static bool findNeedDeleteProxyStubPos2(const std::vector<std::string>& lines, size_t begin, size_t* nextClassEnd)
{
    std::string line = lines[begin];
    if (std::string::npos == line.find("template <"))
        return false;

    int angleBracketsLeftCount = 0;
    int angleBracketsRightCount = 0;

    for (size_t i = begin; i < lines.size(); ++i) {
        line = lines[i];
        for (size_t j = 0; j < line.size(); ++j) {
            if ('<' == line[j])
                angleBracketsLeftCount++;
            else if ('>' == line[j])
                angleBracketsRightCount++;

            if (0 == angleBracketsLeftCount || angleBracketsLeftCount != angleBracketsRightCount)
                continue;

            std::string nextLine = lines[i];
            if (isStartWith(nextLine, "template <typename ImplRefTraits = mojo::RawPtrImplRefTraits") && isEndWith(nextLine, "{")) {
                std::string className = nextLine.substr(sizeof("class ") - 1);
                *nextClassEnd = findNextClassEnd(lines, begin);
                return true;
            }
            nextLine = lines[i + 1];
            if (isStartWith(nextLine, "class ") && !isEndWith(nextLine, ";")) {
                std::string className = nextLine.substr(sizeof("class ") - 1);
                *nextClassEnd = findNextClassEnd(lines, begin);
                return true;
            }
            return false;
        }
    }
    return false;
}

void deleteProxyStubDispatch(LPCWSTR filePath, int* count)
{
    std::string filePathUtf8 = utf16ToUtf8(filePath);
    if (!isEndWith(filePathUtf8, ".h"))
        return;

    std::vector<char> buffer;
    readFileToBuf(filePath, &buffer);
    if (buffer.size() == 0)
        return;
    buffer.push_back(0);

    std::string str = buffer.data();
    replaceAll(&str, "\r", "");
    replaceAll(&str, "\n\n\n", "\n");

    bool needSave = false;
    std::vector<std::string> lines = splitString(str, '\n');
    for (size_t i = 0; i < lines.size(); ++i) {
        size_t nextClassEnd = 0;
        if (findNeedDeleteProxyStubPos(lines, i, &nextClassEnd) || 
            findNeedDeleteProxyStubPos2(lines, i, &nextClassEnd) ||
            findNeedDeleteValidator(lines, i, &nextClassEnd)) {
            addComments(&lines, i, nextClassEnd);
            i = nextClassEnd - 1;
            needSave = true;
            continue;
        }
    }

    replaceAll(&filePathUtf8, kOldGenDir, kNewGenDir);

    std::vector<char> output;
    output.resize(filePathUtf8.size() + 100);
    sprintf_s(output.data(), output.size() - 1, "%d, %s\n", *count, filePathUtf8.c_str());
    OutputDebugStringA(output.data());
    ++(*count);

//     if (!needSave)
//         return;

    std::string ret = arrayToString(lines);
    saveDumpFile(utf8ToUtf16(filePathUtf8).c_str(), ret.c_str(), ret.length());
}

void clearMojoMain(LPCWSTR filePath, int* count);

void traverseMojoDirectory(LPCWSTR lpFolder, int* count)
{
    WIN32_FIND_DATAW findData;
    HANDLE hFind;
    std::wstring filePath;

    filePath = lpFolder;
    filePath.append(L"\\*.*");

    hFind = ::FindFirstFileW(filePath.c_str(), &findData);
    if (hFind == INVALID_HANDLE_VALUE)
        return;

    do {
        if (wcscmp(findData.cFileName, L".") == 0 || wcscmp(findData.cFileName, L"..") == 0)
            continue;

        filePath = lpFolder;
        filePath.append(L"\\");
        filePath.append(findData.cFileName);

        if (wcscmp(findData.cFileName, L"hdr_metadata.mojom-shared-internal.h") == 0)
            OutputDebugStringA("");

        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            traverseMojoDirectory(filePath.c_str(), count);
        } else {
            clearMojoMain(filePath.c_str(), count);
        }
    } while (::FindNextFileW(hFind, &findData));

    ::FindClose(hFind);
}

void clearMojoMain(LPCWSTR filePath, int* count)
{
    // 先来一次fixMojo，再执行下面的deleteProxy
    fixMojoConstructor(filePath, count);
    //deleteProxyStubDispatch(filePath, count);
}

void clearMojo()
{
    // 先执行fixMojoConstructor放到gen_132_format，再执行deleteProxyStubDispatch到mb132\\gen
    kOldGenDir = "G:\\test\\temp\\clearmojo\\gen132";
    kNewGenDir = "G:\\test\\temp\\clearmojo\\gen_132_format";

//     kOldGenDir = "G:\\test\\temp\\clearmojo\\gen_132_format";
//     kNewGenDir = "W:\\mycode\\mb132\\gen";

    int count = 0;
    std::wstring path = utf8ToUtf16(kOldGenDir);
    //traverseMojoDirectory(path.c_str(), &count);

    //clearMojoMain(L"G:\\test\\temp\\clearmojo\\gen132\\services\\network\\public\\mojom\\content_security_policy.mojom-blink.h", &count);
    //G:\test\temp\clearmojo\gen132\services\network\public\mojom\content_security_policy.mojom-blink.h
    //clearMojoMain(L"G:\\test\\temp\\clearmojo\\gen132\\third_party\\blink\\public\\mojom\\permissions_policy\\permissions_policy.mojom-blink.h", &count);
    //clearMojoMain(L"G:\\test\\temp\\clearmojo\\gen132\\third_party\\blink\\public\\mojom\\script_source_location.mojom-blink.h", &count);
    //clearMojoMain(L"W:\\mycode\\mb132\\gen\\third_party\\blink\\public\\mojom\\conversions\\conversions.mojom.h", & count);
    //clearMojoMain(L"G:\\test\\temp\\clearmojo\\gen132\\services\\network\\public\\mojom\\url_response_head.mojom.h", & count);
    clearMojoMain(L"G:\\test\\temp\\clearmojo\\gen132\\ui\\gfx\\mojom\\hdr_metadata.mojom-shared-internal.h", &count);
}

void findHowMuchLinkError(LPCWSTR filePath)
{
    DebugBreak();
//     std::vector<char> buffer;
//     readFileToBuf(filePath, &buffer);
//     if (buffer.size() == 0)
//         return;
//     buffer.push_back(0);
//     std::string str = buffer.data();
// 
//     std::set<std::string> funcs;
// 
//     std::vector<std::string> lines = splitString(str, '\n');
//     for (size_t i = 0; i < lines.size(); ++i) {
//         std::string line = lines[i];
//         std::string func;
// 
//         if (std::string::npos == line.find(u8"无法解析的外部符号 \"")) {
//             size_t begin = line.find(u8"无法解析的外部符号 ");
//             if (std::string::npos == begin)
//                 continue;
//             size_t end = line.find(u8"，");
//             if (std::string::npos == end)
//                 continue;
//             func = line.substr(begin + 28, end - begin - 28);
//         } else {
//             size_t begin = line.find(" \"");
//             if (begin == std::string::npos)
//                 continue;
//             size_t end = line.find("\" ");
//             if (end == std::string::npos)
//                 continue;
//             func = line.substr(begin + 2, end - begin - 2);
//         }
//         funcs.insert(func);
//     }
// 
//     for (std::set<std::string>::const_iterator it = funcs.begin(); it != funcs.end(); ++it) {
//         std::string output = *it;
//         output += "\n";
//         OutputDebugStringA(output.c_str());
//     }
}

// int main()
// {
//   return 0;
// }
#endif