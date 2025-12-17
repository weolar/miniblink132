
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <windows.h>
#include <set>

std::string UTF16ToUTF8(const std::wstring& utf16Str)
{
    // 获取需要的字节数
    int wideCharLen = static_cast<int>(utf16Str.size());
    int sizeRequired = WideCharToMultiByte(CP_UTF8, 0, utf16Str.c_str(), wideCharLen, nullptr, 0, nullptr, nullptr);
    if (sizeRequired <= 0) {
        //std::cerr << "WideCharToMultiByte failed with error code: " << GetLastError() << std::endl;
        return "";
    }

    // 分配内存
    std::string result(sizeRequired, 0);

    // 执行转换
    int converted = WideCharToMultiByte(CP_UTF8, 0, utf16Str.c_str(), wideCharLen, &result[0], sizeRequired, nullptr, nullptr);
    if (converted <= 0) {
        //std::cerr << "WideCharToMultiByte failed with error code: " << GetLastError() << std::endl;
        return "";
    }

    return result;
}

void readFileToBuf(const char* path, std::vector<char>* buffer);

void writeFileToBuf(const char* path, const char* buffer, size_t size)
{
    //createMultiDir(path);

    HANDLE hFile = CreateFileA(path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        DebugBreak();
        return;
    }

    DWORD numberOfBytesWrite = 0;
    BOOL b = ::WriteFile(hFile, buffer, size, &numberOfBytesWrite, nullptr);
    ::CloseHandle(hFile);
    b = b;
}

bool saveDumpFileW(const std::wstring& url, const char* buffer, unsigned int size)
{
    HANDLE hFile = NULL;
    bool   bRet = false;

    hFile = CreateFileW(url.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (!hFile || INVALID_HANDLE_VALUE == hFile)
        return false;

    DWORD numberOfBytesWritten = 0;
    ::WriteFile(hFile, buffer, size, &numberOfBytesWritten, NULL);
    ::CloseHandle(hFile);
    bRet = true;

    return bRet;
}

void readFileW(const wchar_t* path, std::vector<char>* buffer)
{
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        //DebugBreak();
        return;
    }

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (0 == bufferSize || bufferSize > 1000 * 1000 * 100)
        return;

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    b = b;
}

void replaceStr(std::wstring& str, const std::wstring& before, const std::wstring& after)
{
    for (std::wstring::size_type pos(0); pos != std::wstring::npos; pos += after.length()) {
        pos = str.find(before, pos);
        if (pos != std::wstring::npos)
            str.replace(pos, before.length(), after);
        else
            break;
    }
}

void printRepetition()
{
    const char* s_arr[] = {
    "${srcPath}/v8/src/api/api-natives.cc",
    "${srcPath}/v8/src/api/api.cc",
    "${srcPath}/v8/src/api/api-arguments.cc",
    nullptr
    };

    std::set<std::string> arr;
    for (size_t i = 0; s_arr[i]; ++i) {
        std::string str = s_arr[i];
        size_t pos = str.find_last_of("/");
        std::string name = str.substr(pos + 1);
        std::set<std::string>::const_iterator it = arr.find(name);
        if (it != arr.end()) {
            std::string output = str;
            output += "\n";
            OutputDebugStringA(output.c_str());
        }
        arr.insert(name);
    }
}

//参数1：要分割的字符串；参数2：作为分隔符的字符；参数3：存放分割后的字符串的vector向量
void splitToArr(const std::string& src, const std::string& separator, std::vector<std::string>* dest) //字符串分割到数组
{
    std::string str = src;
    std::string substring;
    std::string::size_type start = 0;
    std::string::size_type index = 0;

    dest->clear();
    index = str.find_first_of(separator, start);
    do {
        if (index != std::string::npos) {
            substring = str.substr(start, index - start);
            dest->push_back(substring);
            start = index + separator.size();
            index = str.find(separator, start);
            if (start == std::string::npos) 
                break;
        }
    } while (index != std::string::npos);

    //the last part
    substring = str.substr(start);
    dest->push_back(substring);
}

void printVcxproj(const char* path)
{
    std::vector<char> buffer;
    readFileToBuf(path, &buffer);
    buffer.push_back('\0');

    std::vector<std::string> lines;
    splitToArr(std::string(buffer.data()), "\n", &lines);

    std::vector<std::string> resultLines;
    for (size_t i = 0; i < lines.size(); ++i) {
        const std::string line = lines[i];
        if (std::string::npos != line.find("<ClCompile")) {
            resultLines.push_back(line);
            std::string output = line;
            output += "\n";
            OutputDebugStringA(output.c_str());
        }
    }
}

void ssFileToCC(const char* path, const char* outPath)
{
    std::vector<char> buffer;
    readFileToBuf(path, &buffer);
    buffer.push_back('\0');

    std::vector<std::string> lines;
    splitToArr(std::string(buffer.data()), "\n", &lines);

    std::string out = "__asm__(\n";

    for (size_t i = 0; i < lines.size(); ++i) {
        const std::string line = lines[i];
        out += "  \"" + line + "\\n\"\n";
    }
    out += ");\n";

    writeFileToBuf(outPath, out.c_str(), out.size());
}

void genHexFile()
{
    std::vector<char> buffer;
    readFileToBuf("E:\\chroium\\M108\\src\\third_party\\icu\\cast\\icudtl.dat", &buffer);

    std::string output = "unsigned char icudtlData[%d] = {\n";

    char temp[100] = { 0 };
    sprintf(temp, output.c_str(), buffer.size());
    output = temp;

    for (size_t i = 0; i < buffer.size(); ++i) {
        sprintf(temp, "0x%02X, ", (unsigned char)buffer[i]);
        output += temp;
        if (i % 25 == 1)
            output += "\n";
    }
    output += "};\n";
    writeFileToBuf("W:\\mycode\\mb108\\content\\resources\\icudtl2.cpp", output.c_str(), output.size());
}

int g_clangFormatCount = 0;

void handleClangFormat(const std::wstring& path)
{
    if (std::wstring::npos != path.find(L"testdll\\test"))
        return;

    size_t pos = path.rfind(L".");
    if (std::wstring::npos == pos)
        return;

    std::wstring tempPath = path.substr(pos);

    if (L".h" != tempPath &&
        L".hh" != tempPath &&
        L".c" != tempPath &&
        L".cpp" != tempPath &&
        //L".cxx" != tempPath &&
        L".cc" != tempPath)
        return;

    g_clangFormatCount++;

    std::vector<char> buffer;
    readFileW(path.c_str(), &buffer);
    if (buffer.size() == 0) {
        //DebugBreak();
        return;
    }
    if (buffer[buffer.size() - 1] != '\0')
        buffer.push_back('\0');

    std::string content(buffer.data());
    pos = content.find("// clang-format off");
    if (std::string::npos != pos) {
        content[pos + 17] = 'n';
        content[pos + 18] = ' ';
        saveDumpFileW(path.c_str(), content.c_str(), content.size());
        //DebugBreak();
    }

    char output[0x100];
    sprintf_s(output, 0x99, "\n %d ", g_clangFormatCount);
    OutputDebugStringA(output);

    // clang-format.exe -style=webkit -i  M:\test\pipeline.cc
    //std::wstring result = L"M:\\chromium\\cef111\\buildtools\\win\\clang-format.exe -style=file -i ";
    std::wstring result = L"G:\\chromium\\M75\\src\\buildtools\\win\\clang-format.exe -style=file -i ";
    result += path;
    OutputDebugStringW(result.c_str());

    std::vector<WCHAR> cmd(result.length() * 3 + MAX_PATH + 1);
    memcpy(cmd.data(), result.c_str(), 2 * (result.length()));

    STARTUPINFO si = { 0 };
    PROCESS_INFORMATION pi = { 0 };
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;
    ::CreateProcessW(NULL, cmd.data(), NULL, NULL, false, 0, NULL, NULL, &si, &pi);

    ::WaitForSingleObject(pi.hProcess, -1);
}

void formatClangImpl(const std::wstring& strPath)
{
    std::wstring clangFormatPath = strPath;
    clangFormatPath += L"\\.clang-format";
    BOOL ok = ::CopyFileW(L"W:\\mycode\\mb108\\.clang-format", clangFormatPath.c_str(), FALSE);
    //     if (!ok)
    //         DebugBreak();

    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // {排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径
                formatClangImpl(strTemp);//递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            handleClangFormat(strTemp);
            OutputDebugStringA("");
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);

    ::DeleteFileW(clangFormatPath.c_str());
}

void formatClang(const std::wstring& strPath)
{
    //DebugBreak();
    formatClangImpl(strPath);
}

static void checkIsPng(const std::wstring& strPath)
{
    std::vector<char> buffer;
    readFileW(strPath.c_str(), &buffer);
//     if (buffer.size() == 1854) {
//         DebugBreak();
//     }

    if (buffer.size() > 1000 * 1000 * 100)
        return;

    unsigned char data[] = {
        0xe6, 0x9c, 0xaa, 0xe6, 0xad, 0xa3, 0xe7, 0xa1, 0xae, 0xe5, 0x85, 0xb3, 0xe9, 0x97
    };
    int len = ((int)buffer.size() - (int)sizeof(data));
    for (int i = 0; i <= len; ++i) {
        if (0 == memcmp(buffer.data() + i, data, sizeof(data))) {
            OutputDebugStringW(strPath.c_str());
            OutputDebugStringW(L"\n");
        }
    }
}

void findCurrentChannelLogo(const std::wstring& strPath)
{
    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // {排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径
                findCurrentChannelLogo(strTemp);//递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            checkIsPng(strTemp);
            OutputDebugStringA("");
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

void printIfDiff(const std::wstring& strPath)
{
    std::wstring origCefPath = strPath;
    replaceStr(origCefPath, L"P:\\chromium\\cef119\\chromium_git\\chromium\\src", L"W:\\test\\cache\\cef119old");

    std::vector<char> newBuffer; // 被修改过的cef文件
    readFileW(strPath.c_str(), &newBuffer);

    std::vector<char> origBuffer; // 原始的cef文件
    readFileW(origCefPath.c_str(), &origBuffer);

    std::wstring output;

    if (origBuffer.size() > 0 && newBuffer.size() != origBuffer.size()) {
        output += strPath;
        output += L"\n";
    }

    OutputDebugStringW(output.c_str());
}

void findCefDiff(const std::wstring& strPath)
{
    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // {排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径
                findCefDiff(strTemp);//递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            printIfDiff(strTemp);
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

int isGBK(const char* array, int len)
{
    for (int i = 0; i < len; i++) {
        if ((((BYTE) & array[i + 2]) > 0x80 && ((BYTE) & array[i + 2]) < 0xff)
            && (((BYTE) & array[i + 2] + 1) > 0x40 && ((BYTE) & array[i + 2] + 1) < 0xff))
            return 1;
    }
    return 0;
}

bool is_valid_gbk_byte(unsigned char byte) 
{
    return (byte >= 0x40 && byte <= 0x7E) || (byte >= 0x80 && byte <= 0xFE);
}

// 判断是否为合法的GBK字符
bool is_valid_gbk(const unsigned char* str, size_t len, size_t* badPos)
{
    size_t i = 0;
    while (i < len) {
        if (str[i] == 0) {
            *badPos = i;
            return false;
        }

        if (str[i] <= 0x7F) {
            // 单字节字符（ASCII）
            i++;
        } else if (str[i] >= 0x81 && str[i] <= 0xFE) {
            // 双字节字符
            if (is_valid_gbk_byte(*(str + i + 1))) {
                i += 2;
            } else {
                *badPos = i;
                return false;
            }
        } else {
            // 非法字节
            *badPos = i;
            return false;
        }
    }
    return true;
}

int getLastBadChar(const unsigned char* str, size_t len)
{
    size_t i = 0;
    bool isLastChar = false;
    while (i < len) {
        isLastChar = i == len - 1;
        if (str[i] == 0) {
            if (isLastChar)
                return 1;
            i++; // 非法字节
            continue;
        }

        if (str[i] <= 0x7F) {
            if (isLastChar)
                return 0;
            // 单字节字符（ASCII）
            i++;
        } else if (str[i] >= 0x81 && str[i] <= 0xFE) {
            if (isLastChar)
                return 1;
            // 双字节字符
            if (is_valid_gbk_byte(str[i + 1])) {
                i += 2;
            } else {
                
                // 非法字节
                i++;
                continue;
            }
        } else {
            // 非法字节
            i++;
            continue;
        }
    }
    return 0;
}

// int main() 
// {
//     unsigned char test_str[] = { 0x81, 0x40, 0x82, 0x40, 0x7F, 0x00 }; // Example GBK string
//     if (is_valid_gbk(test_str)) {
//         printf("The string is valid GBK.\n");
//     } else {
//         printf("The string is not valid GBK.\n");
//     }
// 
//     return 0;
// }

void copyFiles()
{
    const char* files[] = {
        //"chrome\\browser\\metrics\\chrome_feature_list_creator.cc",
        //"chrome\\browser\\net\\profile_network_context_service.cc",
        "chrome\\browser\\ui\\browser_navigator.cc",
        "content\\browser\\storage_partition_impl.cc",
        "content\\browser\\web_contents\\web_contents_impl.cc",
        "electron\\shell\\browser\\api\\electron_api_session.cc",
        "electron\\shell\\browser\\api\\electron_api_web_contents.cc",
        "electron\\shell\\browser\\electron_browser_context.cc",
        "electron\\shell\\browser\\javascript_environment.cc",
        "electron\\shell\\browser\\net\\system_network_context_manager.cc",
        "net\\base\\proxy_server.cc",
        "net\\base\\proxy_string_util.cc",
        "net\\http\\http_proxy_connect_job.cc",
        "net\\proxy_resolution\\configured_proxy_resolution_service.cc",
        "net\\socket\\connect_job_factory.cc",
        "net\\socket\\socks_connect_job.cc",
        "net\\socket\\socks5_client_socket.cc",
        "net\\socket\\ssl_client_socket_impl.cc",
        "net\\socket\\ssl_server_socket_impl.cc",
        "net\\third_party\\quiche\\src\\quiche\\quic\\core\\crypto\\tls_connection.cc",
        "net\\third_party\\quiche\\src\\quiche\\quic\\core\\tls_chlo_extractor.cc",
        "third_party\\blink\\common\\web_preferences\\web_preferences_mojom_traits.cc",

        nullptr
    };
    for (size_t i = 0; files[i]; ++i) {
        std::string source      = "O:\\chromium\\ele32fp-\\";
        std::string destination = "O:\\chromium\\ele32fp\\";
        source = source + files[i];
        destination = destination + files[i];
        CopyFileA(source.c_str(), destination.c_str(), FALSE);
    }
}

void MByteToWChar(const char* lpcszStr, size_t cbMultiByte, std::vector<WCHAR>* out, unsigned int codePage)
{
    out->clear();
    if (nullptr == lpcszStr || 0 == cbMultiByte)
        return;
    DWORD dwMinSize;
    dwMinSize = MultiByteToWideChar(codePage, 0, lpcszStr, cbMultiByte, NULL, 0);
    if (0 == dwMinSize)
        return;

    out->resize(dwMinSize);

    LPWSTR addr = (LPWSTR)(&out->at(0));
    // Convert headers from ASCII to Unicode.
    MultiByteToWideChar(codePage, 0, lpcszStr, cbMultiByte, addr, dwMinSize);
}

void searchHex();
void searchHex2(HINSTANCE hInstance);

#define MAX_CMD 1024 * 10000
#define PIPE_BUFFER_SIZE 1024 * 10000
#define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))

HRESULT executeCmdWait(const std::wstring& szCommand)
{
    STARTUPINFO m_startupInfo = { 0 };
    PROCESS_INFORMATION m_processInfo = { 0 };
    SECURITY_ATTRIBUTES m_saOutPipe = { 0 };
    DWORD m_dwErrorCode;
    HANDLE m_hPipeRead;
    HANDLE m_hPipeWrite;
    std::vector<char> m_szPipeOut;
    m_szPipeOut.resize(PIPE_BUFFER_SIZE);
    std::vector<WCHAR> szCommandBuffer;
    szCommandBuffer.resize(MAX_CMD);
    wcscpy(szCommandBuffer.data(), szCommand.c_str());

    ZeroMemory(&m_saOutPipe, sizeof(m_saOutPipe));
    m_saOutPipe.nLength = sizeof(SECURITY_ATTRIBUTES);
    m_saOutPipe.lpSecurityDescriptor = NULL;
    m_saOutPipe.bInheritHandle = TRUE;
    ZeroMemory(&m_startupInfo, sizeof(STARTUPINFO));
    ZeroMemory(&m_processInfo, sizeof(PROCESS_INFORMATION));

    if (!CreatePipe(&m_hPipeRead, &m_hPipeWrite, &m_saOutPipe, PIPE_BUFFER_SIZE)) {
        return E_FAIL;
    }

    HRESULT hResult = E_FAIL;
    DWORD dwReadLen = 0;
    DWORD dwStdLen = 0;
    m_startupInfo.cb = sizeof(STARTUPINFO);
    m_startupInfo.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    m_startupInfo.hStdOutput = m_hPipeWrite;
    m_startupInfo.hStdError = m_hPipeWrite;
    m_startupInfo.wShowWindow = SW_HIDE;

    DWORD dTimeOut = (DWORD)-1; // m_CommandParam.iTimeOut >= 3000 ? m_CommandParam.iTimeOut : 5000;
    do {
        if (!CreateProcessW(NULL, szCommandBuffer.data(),
            NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL,
            &m_startupInfo, &m_processInfo)) {
            m_dwErrorCode = GetLastError();
            hResult = E_FAIL;
            break;
        }
        if (WAIT_TIMEOUT == WaitForSingleObject(m_processInfo.hProcess, dTimeOut)) {
            m_dwErrorCode = GetLastError();
            hResult = CO_E_SERVER_START_TIMEOUT;
//             if (m_CommandParam.OnCmdEvent)
//                 m_CommandParam.OnCmdEvent(&m_CommandParam, CO_E_SERVER_START_TIMEOUT, "");
            break;
        }
        // 预览管道中数据的内容
        BOOL b = PeekNamedPipe(m_hPipeRead, m_szPipeOut.data(), PIPE_BUFFER_SIZE, NULL, &dwReadLen, NULL);
        m_dwErrorCode = GetLastError();
        if (b && m_dwErrorCode == 5) {
            return E_FAIL;
        }

        if (strstr(m_szPipeOut.data(), "error: "))
            return E_FAIL;

        if (!b || dwReadLen >= PIPE_BUFFER_SIZE) {
            m_dwErrorCode = GetLastError();
            DebugBreak();
            hResult = E_FAIL;
            break;
        } else if (dwReadLen <= 0) {
            hResult = S_OK;
//             if (m_CommandParam.OnCmdEvent)
//                 m_CommandParam.OnCmdEvent(&m_CommandParam, S_OK, "no data");
            break;
        }

        ZeroMemory(m_szPipeOut.data(), m_szPipeOut.size());
        // 读取管道中的数据
        if (ReadFile(m_hPipeRead, m_szPipeOut.data(), dwReadLen, &dwStdLen, NULL)) {
            hResult = S_OK;
//             if (m_CommandParam.OnCmdEvent)
//                 m_CommandParam.OnCmdEvent(&m_CommandParam, S_OK, m_szPipeOut);
            break;
        }
        else {
            m_dwErrorCode = GetLastError();
            break;
        }
    } while (0);

    if (m_processInfo.hThread) {
        CloseHandle(m_processInfo.hThread);
        m_processInfo.hThread = NULL;
    }
    if (m_processInfo.hProcess) {
        CloseHandle(m_processInfo.hProcess);
        m_processInfo.hProcess = NULL;
    }
    return hResult;
}

//#include "mb_renderer_CppFile.h"
#include "mb_platform_CppFile.h"

void findAllBuildErrorCppFile()
{
    //printVcxproj("W:\\mycode\\mb132\\build\\miniblink108\\mb_platform.vcxproj.filters");

//     const WCHAR* files[] = {
//       L"third_party\\xxx\\xxxx\\web_preferences\\web_preferences_mojom_traits.cc",
//       nullptr
//     };

    for (size_t i = 0; files[i]; ++i) {
        std::wstring cmd = L"/c /IW:\\mycode\\mb132\\build\\../third_party/zlib /IW:\\mycode\\mb132\\build\\../third_party/iccjpeg /IW:\\mycode\\mb132\\build\\../third_party/libjpeg_turbo /IW:\\mycode\\mb132\\build\\../third_party/libwebp/src/src /IW:\\mycode\\mb132\\build\\../third_party/libpng /I\"W:\\mycode\\mb132\\build\\../third_party/harfbuzz-ng/src/src\" /IW:\\mycode\\mb132\\build\\../third_party/khronos /IW:\\mycode\\mb132\\build\\../base/allocator/partition_allocator/src /IW:\\mycode\\mb132\\build\\../gen/base/allocator/partition_allocator/src/ /IW:\\mycode\\mb132\\build\\../ /IW:\\mycode\\mb132\\build\\../gen/ /I\"W:\\mycode\\mb132\\build\\../third_party/abseil-cpp\" /IW:\\mycode\\mb132\\build\\../v8/include /IW:\\mycode\\mb132\\build\\../third_party/skia /IW:\\mycode\\mb132\\build\\../gen/v8/include /IW:\\mycode\\mb132\\build\\../third_party/icu/source/i18n /IW:\\mycode\\mb132\\build\\../third_party/icu/source/common /IW:\\mycode\\mb132\\build\\../third_party/libxml/win32/include /IW:\\mycode\\mb132\\build\\../third_party/libxml/src/include /IW:\\mycode\\mb132\\build\\../third_party/libxslt/src /IW:\\mycode\\mb132\\build\\../third_party/openssl/openssl/include /IW:\\mycode\\mb132\\build\\../third_party/boringssl/src/include /IW:\\mycode\\mb132\\build\\../gpu /Z7 /nologo /W3 /WX- /diagnostics:column /Od /D WIN32 /D _DEBUG /D OS_WIN /D MINIBLINK108_EXPORTS /D _WINDOWS /D NOMINMAX /D WIN32_LEAN_AND_MEAN /D V8_ENABLE_CHECKS /D _USRDLL /D USE_AURA /D SUPPORT_XP_CODE=1 /D U_STATIC_IMPLEMENTATION /D U_DEFINE_FALSE_AND_TRUE /D LIBXML_STATIC /D LIBXSLT_STATIC /D CURL_STATICLIB /D SK_SUPPORT_LEGACY_DRAWLOOPER /D INSIDE_BLINK=1 /D ENABLE_MB=1 /D _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING /D _CRT_SECURE_NO_WARNINGS /D _UNICODE /D UNICODE /GF /MDd /GS /arch:AVX2 /fp:precise /std:c++20 /Fo\"W:\\mycode\\mb132\\build\\..\\out\\tmp\\mb_renderer\\win_Debug_Win32\\\\\" /Gd /TP -m32 \"..\\..\\";
        std::wstring rspCmd = L"\"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\Llvm\\clang+llvm-18.1.8-x86_64\\bin\\clang-cl.exe\" @";

        cmd += files[i];
        cmd += L"\"";

        std::wstring testCmd = L"C:\\Users\\wang\\AppData\\Local\\Temp\\MSBuildTempwang\\tmpc3186fa706c649b383cc1feb2696df23.rsp";
        std::wstring myCmd = L"W:\\mycode\\mb132\\build\\testdll\\test\\1.rsp";
        std::wstring cmdFinal = myCmd;

        rspCmd += cmdFinal;
        ::DeleteFileW(cmdFinal.c_str());

        std::string cmdA =  UTF16ToUTF8(cmd);
        saveDumpFileW(cmdFinal, (const char*)cmdA.c_str(), cmdA.length());

        if (S_OK != executeCmdWait(rspCmd)) {
            std::wstring out = files[i];
            out += L"\n";
            OutputDebugStringW(out.c_str());
        }
    }
}

void clearMojo();
void formatFileToCppArray();
void genMiniElectronAsarRes();
void sortStr();
void findLinkError();
int codeSizeViewmmain();
void findChromiumIco();
std::string genNapiStub();
void testMain()
{
    //genNapiStub();
    //findChromiumIco();
    //codeSizeViewmmain();
    //sortStr();
    //findLinkError();

    //genMiniElectronAsarRes();
    // 
//     size_t text_size = 5u;
//     std::string text(text_size, char());
//     char* buf = (char*)text.data();
//     memcpy(buf, "12345", 5);
//     OutputDebugStringA("");

    //findAllBuildErrorCppFile();

    //copyFiles();
    //searchHex2(nullptr);

//     std::vector<char> buffer;
//     readFileW(L"W:\\mycode\\mb108\\out\\win_Release_Win32\\unicode.txt", &buffer);
// 
//     const unsigned char chars[8] = {0x22, 0xc9, 0xd8, 0xc9, 0xbd, 0xca, 0xd0, 0x22}; // "韶山市"
// 
//     size_t badPos = 0;
//     //int a = is_valid_gbk(chars, 4, &badPos);
//     int a = getLastBadChar(chars, 6);
//     return;

    //std::vector<WCHAR> out;
    //MByteToWChar(buffer.data(), buffer.size(), &out, CP_ACP);
    //MByteToWChar(chars, 4, &out, CP_ACP);

    //findCefDiff(L"P:\\chromium\\cef119\\chromium_git\\chromium\\src");
    //findCurrentChannelLogo(L"E:\\chroium\\C108\\src\\");
    //DebugBreak();
    //ssFileToCC("W:\\mycode\\mb108\\content\\resources\\embedded_linux_x64.S", "W:\\mycode\\mb108\\content\\resources\\embedded_linux_x64.cc");
    //ssFileToCC("W:\\mycode\\mb108\\content\\resources\\embedded_linux_arm64.S", "W:\\mycode\\mb108\\content\\resources\\embedded_linux_arm64.cc");
    //printRepetition();
    //genHexFile();
    //printVcxproj("W:\\mycode\\mb108\\build\\util\\util.vcxproj.filters");
    //printVcxproj("G:\\mycode\\miniblink57\\build\\tassl\\tassl.vcxproj.filters");
    //printVcxproj("G:\\mycode\\miniblink57\\build\\tongsuo\\tongsuo.vcxproj.filters");
    //printVcxproj("W:\\mycode\\mb108\\build\\miniblink108\\gen_2.vcxproj.filters");

    //formatClang(L"W:\\mycode\\mb108\\webdriver\\civetweb");
//     formatClang(L"W:\\mycode\\mb108\\third_party\\libuv");
    //formatClang(L"W:\\mycode\\mb132\\out\\win_Debug_x64\\resources\\app\\node_modules\\@serialport\\bindings-cpp\\src");

    //clearMojo();

    //formatFileToCppArray();
}