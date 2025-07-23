
#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <windows.h>
#include <vector>
#include <Shlwapi.h>
// #include "G:/mycode/mb/wke/wkedefine.h"
// #include "G:/mycode/mb/net/MergeVec.h"
#include <intrin.h>
#include <functional>
#include <algorithm>
#include <set>
//#include "W:/mycode/mb132/build/testdll/test/MiniElectronAsarRes.h"

std::string utf16ToUtf8(LPCWSTR lpszSrc);
std::wstring utf8ToUtf16(const std::string& utf8);
void readFile(const wchar_t* path, std::vector<char>* buffer);
bool saveDumpFile(const std::wstring& url, const char* buffer, unsigned int size);

int g_count = 0;

bool compareStrings(const char* a, const char* b)
{
    return /*std::*/strcmp(a, b) < 0;
}

void sortStr()
{
    const char* aaa[] = {
"_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_EXTENSIVE",
"_LIBCPP_DISABLE_VISIBILITY_ANNOTATIONS",
"CR_LIBCXX_REVISION=8e31ad42561900383e10dbefc1d3e8f38cedfbe9",
"TMP_REBUILD_HACK",
"__STD_C",
"_CRT_RAND_S",
"_CRT_SECURE_NO_DEPRECATE",
"_SCL_SECURE_NO_DEPRECATE",
"_ATL_NO_OPENGL",
"_WINDOWS",
"CERT_CHAIN_PARA_HAS_EXTRA_FIELDS",
"PSAPI_VERSION=2",
"WIN32",
"_SECURE_ATL",
"WINAPI_FAMILY=WINAPI_FAMILY_DESKTOP_APP",
"WIN32_LEAN_AND_MEAN",
"NOMINMAX",
"_UNICODE",
"UNICODE",
"NTDDI_VERSION=NTDDI_WIN10_NI",
"_WIN32_WINNT=0x0A00",
"WINVER=0x0A00",
"NDEBUG",
"NVALGRIND",
"DYNAMIC_ANNOTATIONS_ENABLED=0",
"V8_TYPED_ARRAY_MAX_SIZE_IN_HEAP=64",
"V8_INTL_SUPPORT",
"V8_USE_EXTERNAL_STARTUP_DATA",
"V8_ATOMIC_OBJECT_FIELD_WRITES",
"V8_ENABLE_LAZY_SOURCE_POSITIONS",
"V8_SHARED_RO_HEAP",
"V8_WIN64_UNWINDING_INFO",
"V8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH",
"V8_SHORT_BUILTIN_CALLS",
"V8_EXTERNAL_CODE_SPACE",
"V8_ENABLE_SPARKPLUG",
"V8_ENABLE_MAGLEV",
"V8_ENABLE_TURBOFAN",
"V8_ENABLE_ETW_STACK_WALKING",
"V8_ENABLE_WEBASSEMBLY",
"V8_ENABLE_CONTINUATION_PRESERVED_EMBEDDER_DATA",
"V8_ALLOCATION_FOLDING",
"V8_ALLOCATION_SITE_TRACKING",
"V8_ADVANCED_BIGINT_ALGORITHMS",
"V8_STATIC_ROOTS",
"V8_USE_ZLIB",
"V8_USE_LIBM_TRIG_FUNCTIONS",
"V8_ENABLE_WASM_SIMD256_REVEC",
"V8_ENABLE_BUILTIN_JUMP_TABLE_SWITCH",
"V8_ENABLE_EXTENSIBLE_RO_SNAPSHOT",
"V8_ENABLE_BLACK_ALLOCATED_PAGES",
"V8_ARRAY_BUFFER_INTERNAL_FIELD_COUNT=0",
"V8_ARRAY_BUFFER_VIEW_INTERNAL_FIELD_COUNT=0",
"V8_PROMISE_INTERNAL_FIELD_COUNT=0",
"V8_COMPRESS_POINTERS",
"V8_COMPRESS_POINTERS_IN_SHARED_CAGE",
"V8_31BIT_SMIS_ON_64BIT_ARCH",
"V8_DEPRECATION_WARNINGS",
"V8_USE_PERFETTO",
"V8_HAVE_TARGET_OS",
"V8_TARGET_OS_WIN",
"CPPGC_CAGED_HEAP",
"CPPGC_YOUNG_GENERATION",
"CPPGC_POINTER_COMPRESSION",
"CPPGC_ENABLE_LARGER_CAGE",
"CPPGC_SLIM_WRITE_BARRIER",
"V8_TARGET_ARCH_X64",
"ABSL_ALLOCATOR_NOTHROW=1",
"U_USING_ICU_NAMESPACE=0",
"U_ENABLE_DYLOAD=0",
"USE_CHROMIUM_ICU=1",
"U_ENABLE_TRACING=1",
"U_ENABLE_RESOURCE_TRACING=0",
"U_STATIC_IMPLEMENTATION",
"ICU_UTIL_DATA_IMPL=ICU_UTIL_DATA_FILE",
nullptr
    };

    // 使用 std::sort 进行排序
    std::sort(aaa, aaa + 12, compareStrings);

    // 打印排序后的数组
    std::string output = "sorting:";
    for (int i = 0; aaa[i]; ++i) {
        output += aaa[i];
        output += "\n";
    }
    OutputDebugStringA(output.c_str());
}

// void handleClangFormat(const std::wstring& path)
// {
//     size_t pos = path.rfind(L".");
//     if (std::wstring::npos == pos)
//         return;
// 
//     std::wstring tempPath = path.substr(pos);
// 
//     if (L".h" != tempPath &&
//         //L".c" != tempPath &&
//         L".cpp" != tempPath &&
//         //L".cxx" != tempPath &&
//         L".cc" != tempPath)
//         return;
// 
//     g_count++;
// 
//     std::vector<char> buffer;
//     readFile(path.c_str(), &buffer);
//     if (buffer.size() == 0) {
//         //DebugBreak();
//         return;
//     }
//     if (buffer[buffer.size() - 1] != '\0')
//         buffer.push_back('\0');
// 
//     std::string content(buffer.data());
//     pos = content.find("// clang-format off");
//     if (std::string::npos != pos) {
//         content[pos + 17] = 'n';
//         content[pos + 18] = ' ';
//         saveDumpFile(path.c_str(), content.c_str(), content.size());
//         //DebugBreak();
//     }
// 
//     char output[0x100];
//     sprintf_s(output, 0x99, "\n %d ", g_count);
//     OutputDebugStringA(output);
// 
//     // clang-format.exe -style=webkit -i  M:\test\pipeline.cc
//     std::wstring result = L"M:\\chromium\\cef111\\buildtools\\win\\clang-format.exe -style=file -i ";
//     result += path;
//     OutputDebugStringW(result.c_str());
// 
//     std::vector<WCHAR> cmd(result.length() * 3 + MAX_PATH + 1);
//     memcpy(cmd.data(), result.c_str(), 2 * (result.length()));
// 
//     STARTUPINFO si = { 0 };
//     PROCESS_INFORMATION pi = { 0 };
//     si.dwFlags = STARTF_USESHOWWINDOW;
//     si.wShowWindow = SW_HIDE;
//     ::CreateProcessW(NULL, cmd.data(), NULL, NULL, false, 0, NULL, NULL, &si, &pi);
// 
//     ::WaitForSingleObject(pi.hProcess, -1);
// }
//
// void formatClangImpl(const std::wstring& strPath)
// {
//     DebugBreak();
//     std::wstring clangFormatPath = strPath;
//     clangFormatPath += L"\\.clang-format";
//     BOOL ok = ::CopyFileW(L"G:\\mycode\\mbvip\\testcpp\\.clang-format", clangFormatPath.c_str(), FALSE);
// //     if (!ok)
// //         DebugBreak();
// 
//     WIN32_FIND_DATA findData;
//     std::wstring strTemp = strPath + L"\\*.*";
// 
//     HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
//     while (hFile != INVALID_HANDLE_VALUE) {
//         if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
//             if (findData.cFileName[0] != L'.') { // {排除.和..文件夹
//                 strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径
//                 formatClangImpl(strTemp);//递归查找当前目录的文件
//             }
//         } else {
//             strTemp = strPath + L"\\" + findData.cFileName;
//             handleClangFormat(strTemp);
//             OutputDebugStringA("");
//         }
// 
//         if (!FindNextFile(hFile, &findData)) {
//             break;
//         }
//     }
//     ::FindClose(hFile);
// 
//     ::DeleteFileW(clangFormatPath.c_str());
// }
// 
// void formatClang(const std::wstring& strPath)
// {
//     formatClangImpl(strPath);
// }

void addUtf8HeadImpl(const std::wstring& path)
{
    size_t pos = path.rfind(L".");
    if (std::wstring::npos == pos)
        return;

    std::wstring tempPath = path.substr(pos);

    if (L".h" != tempPath &&
        //L".c" != tempPath &&
        L".cpp" != tempPath &&
        //L".cxx" != tempPath &&
        L".cc" != tempPath)
        return;

    std::vector<char> buffer;
    readFile(path.c_str(), &buffer);
    if (buffer.size() <= 3)
        return;
    if ((unsigned char)buffer[0] == 0xef && (unsigned char)buffer[1] == 0xbb && (unsigned char)buffer[2] == 0xbf)
        return;

    buffer.insert(buffer.begin(), 0xbf);
    buffer.insert(buffer.begin(), 0xbb);
    buffer.insert(buffer.begin(), 0xef);

    saveDumpFile(path.c_str()/*L"C:\\Users\\wang\\Desktop\\新建文件夹\\1.h"*/, buffer.data(), buffer.size());
    std::wstring pathDummy = path + L"\n";
    OutputDebugStringW(pathDummy.c_str());
}

void addUtf8Head(const std::wstring& strPath)
{
    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // {排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;
                addUtf8Head(strTemp);//递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            addUtf8HeadImpl(strTemp);
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}


//                                      pos1                                pos2         pos3
//candidate:3805835391 1 udp 2113937151 aa0e1f7c-4a5c-4272-be1c-dcd47cc6ff15.local 59430 typ host generation 0 ufrag 49yP network-cost 999

void MakeIceCandidateInterfaceNoise(std::string* sdp)
{
    size_t pos_1 = std::string::npos;
    size_t pos_2 = sdp->find(".local ");

    if (std::string::npos == pos_2)
        return;

    pos_1 = sdp->rfind(" ", pos_2);
    if (std::string::npos == pos_1 || pos_2 + 7 >= sdp->size() || pos_1 + 1 >= sdp->size())
        return;

    size_t pos_3 = sdp->find(" ", pos_2 + 7);
    if (std::string::npos == pos_3)
        return;

    std::string temp = sdp->substr(0, pos_1 + 1);
    temp += "192.168.0.107 63776";
    temp += sdp->substr(pos_3);
    *sdp = temp;
}

//////////////////////////////////////////////////////////////////////////
// https://blog.csdn.net/what951006/article/details/77892670
//
#include <stack>

int priority(int state, char a)
{
    // 计算操作符优先级的函数，注意state表示运算符状态：
    // state=1表示还未进栈，state=0表示栈内优先级，注意
    // 这只对‘（’起作用
    int result;
    switch (a) {
    case '+':
    case '-':
        result = 1;
        break;
    case '*':
    case '/':
        result = 2;
        break;
    case '(':
        if (state == 0)
            result = 3;
        else
            result = 0;
        break;
    case '#':
        result = 0;
        break;
    default:
        break;
    }
    return result;
}

double calculate(char op, double op1, double op2)
{
    double result;
    switch (op) {
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op1 - op2;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '/':
        result = op1 / op2;
        break;
    default:
        break;
    }
    return result;
}

double myEval(const std::string& s)
{
    std::stack<char> operation; // 存放操作符的栈
    std::stack<double> operand; // 存放操作数的栈
    operation.push('#'); // 先将‘#’压栈
    std::string num; // 存放操作数
    for (int i = 0; i < (int)s.length(); i++) {
        if (isdigit(s[i])) { // 出现数字
            while (isdigit(s[i]) || s[i] == '.') { // 将操作数提取完全
                num.push_back(s[i]);
                i++;
            }

            double a = atof(num.c_str()); // string -> double
            operand.push(a); //操作数入栈
            num.clear(); // num清空以备下次使用
            i--; // 位置还原
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(') {//出现运算符
            if (priority(0, s[i]) > priority(1, operation.top())) // 优先级比较
                operation.push(s[i]); // >,直接入栈
            else {
                while (priority(0, s[i]) <= priority(1, operation.top())) { // <,出栈并进行计算直至>
                    char temp = operation.top();
                    operation.pop();
                    double op2 = operand.top();
                    operand.pop();
                    double op1 = operand.top();
                    operand.pop();
                    operand.push(calculate(temp, op1, op2));
                }
                operation.push(s[i]); // 不要忘了最后操作符入栈
            }
        } else if (s[i] == ')') { // 扫描到‘）’
            while (operation.top() != '(') { // 出栈直至‘（’
                char temp = operation.top();
                operation.pop();
                double op2 = operand.top();
                operand.pop();
                double op1 = operand.top();
                operand.pop();
                operand.push(calculate(temp, op1, op2));
            }
            operation.pop(); //‘（’出栈
        } else { // 非法字符的处理
                 //cout << "error!" << endl;
            continue;
        }
    }

    while (operation.top() != '#') { // 扫尾工作
        char temp = operation.top();
        operation.pop();
        double op2 = operand.top();
        operand.pop();
        double op1 = operand.top();
        operand.pop();
        operand.push(calculate(temp, op1, op2));
    }
    //cout << operand.top() << endl;//输出结果
    return operand.top();
}

int testEvalMain()
{
    double ret = myEval("1+(0.4)* 2");

    char* output = (char*)malloc(0x100);
    sprintf_s(output, 0x99, "testEvalMain: %f\n", ret);
    OutputDebugStringA(output);
    free(output);

    return 0;
}

void testWriteScreenLoopCreateProc()
{
    do {
        STARTUPINFO si = { 0 };
        PROCESS_INFORMATION pi = { 0 };
        si.dwFlags = STARTF_USESHOWWINDOW;
        si.wShowWindow = SW_SHOW;
        WCHAR cmd[] = L"G:\\mycode\\mb\\out\\Debug\\wkexe.exe";
        BOOL b = ::CreateProcessW(NULL, cmd, NULL, NULL, false, 0, NULL, NULL, &si, &pi);

        do {
            HWND hwnd = FindWindowW(L"createSignWnd", L"createSignWnd");
            if (hwnd) {
                ::TerminateProcess(pi.hProcess, 0);
                break;
            }
            ::Sleep(10);
        } while (true);

    } while (true);
}

std::wstring FixPathExtByDefalutPath(const std::wstring& path, const std::wstring& default_path)
{
    for (int i = (int)path.size(); i >= 0; --i) {
        if (path[i] == L'.')
            return path;
    }

    std::wstring default_path_ext;
    for (int i = (int)default_path.size(); i >= 0; --i) {
        if (default_path[i] == L'.') {
            default_path_ext = default_path.substr(i, std::wstring::npos);
            if (default_path_ext.empty() || default_path_ext == L".")
                return path;
            break;
        }
    }

    return path + default_path_ext;
}

bool CheckIsReturnDefalutPath(const std::wstring& path, const std::wstring& default_path)
{
    if (path.size() == 0)
        return true;
    if (default_path.size() == 0)
        return false;

    if (path.size() > default_path.size())
        return false;

    size_t i = 0;
    for (; i < path.size(); ++i) {
        WCHAR c1 = path[i];
        WCHAR c2 = default_path[i];
        c1 = (c1 >= 64 && c1 <= 90) ? c1 + 32 : c1;
        c2 = (c2 >= 64 && c2 <= 90) ? c2 + 32 : c2;

        if (c1 != c2)
            return false;
    }

    if (i == default_path.size()) // 如果两边一样，不用管了
        return false;

    std::wstring sub_str = default_path.substr(i, std::wstring::npos);
    std::wstring sub_str_pre = default_path.substr(0, i);
    if (sub_str_pre.size() == 0 || sub_str_pre[sub_str_pre.size() - 1] == L'.') // 如果前半截最后一个是点，直接true
        return true;

    bool has_dot = false;
    bool has_not_dot = false;
    bool end_with_dot = sub_str[sub_str.size() - 1] == L'.';

    for (i = 0; i < sub_str.size(); ++i) {
        if (sub_str[i] != L'.')
            has_not_dot = true;
        else
            has_dot = true;
    }

    if (has_dot && has_not_dot && !end_with_dot)
        return true;

    return false;
}

void readFile(const wchar_t* path, std::vector<char>* buffer);
void writeFile(const wchar_t* path, const std::vector<char>& buffer);

void fileToHex2(const std::wstring& dir)
{
    std::vector<char> buffer;
    readFile(dir.c_str(), &buffer);

    std::string result = "  const unsigned char render_init_native[] = { ";
    for (size_t j = 0; j < buffer.size(); ++j) {
        unsigned char c = buffer[j];

        char* tempFormat = (char*)malloc(0x200);
        sprintf_s(tempFormat, 0x199, "%d,", c);
        result += tempFormat;
        free(tempFormat);
    }

    result += "};";
}

void delEmptyDirs(const std::vector<std::wstring>& emptyDirs)
{
    for (size_t i = 0; i < emptyDirs.size(); ++i) {
        std::wstring path = emptyDirs[i];
        ::RemoveDirectoryW(path.c_str());
    }
}

bool getEmptyDirs(const std::wstring& strPath, std::vector<std::wstring>* result)
{
    bool isEmptyDir = true;

    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // 排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName; // 获得完整路径
                isEmptyDir = getEmptyDirs(strTemp, result); // 递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            //handleClangFormat(strTemp);
            //OutputDebugStringA("");
            isEmptyDir = false;
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);

    if (isEmptyDir)
        result->push_back(strPath);
    return isEmptyDir;
}

void fixGetLogicalProcessorInformation()
{
    std::vector<char> buffer;
    readFile(L"G:\\cef73\\src\\out\\release\\libcef.dll", &buffer);
    const char* str = "GetLogicalProcessorInformation";
    int len = strlen(str);
    for (size_t i = 0; i < buffer.size(); ++i) {
        bool find = true;
        for (int j = 0; j < len; ++j) {
            if (buffer[i + j] != str[j]) {
                find = false;
                break;
            }
        }
        if (find) {
            const char* tem = &buffer[i];
            strcpy(&buffer[i], "Sleep");
            OutputDebugStringA("find\n");
        }
    }
    saveDumpFile(L"G:\\cef73\\src\\out\\release\\libcef.dll", buffer.data(), buffer.size());
    OutputDebugStringA("end\n");
}

void splitsDll()
{
    std::vector<char> buffer;
    readFile(L"G:\\mycode\\mb\\out\\Release_vc6\\node.dll", &buffer);

    const size_t kThrunkSize = 1024 * 1024 * 2;

    //     std::vector<char> buffer(3);
    //     buffer[0] = 0;
    //     buffer[1] = 1;
    //     buffer[2] = 2;
    //     const size_t kThrunkSize = 2;

    int count = 0;

    const char* posA = buffer.data();
    const char* posB = posA + kThrunkSize;
    while (true) {
        int size = (int)(posB - posA);
        if (size <= 0)
            DebugBreak();

        std::vector<char> temp(size);
        memcpy(temp.data(), posA, size);

        char* output = (char*)malloc(900);
        sprintf_s(output, 900 - 2, "G:\\test\\exe_test\\memory_load\\build\\mbsplit\\dlls\\node.dll_%d", count);
        std::wstring path = utf8ToUtf16(output);
        free(output);
        saveDumpFile(path.c_str(), temp.data(), temp.size());

        count++;

        posA = posB;
        posB = posB + kThrunkSize > buffer.data() + buffer.size() ? buffer.data() + buffer.size() : posB + kThrunkSize;

        if (posA == posB)
            break;
    }
    OutputDebugStringA("");
}

std::vector<std::vector<char>> readLine(const WCHAR* path)
{
    std::vector<std::vector<char> > result;

    std::vector<char> buffer;
    readFile(path, &buffer);

    const char* posA = buffer.data();
    const char* posB = posA;
    for (size_t i = 0; i < buffer.size(); ++i) {
        if ('\n' == buffer[i]) {
            posB = &buffer[i];

            if (posB != posA) {
                std::vector<char> temp(posB - posA);
                memcpy(temp.data(), posA, posB - posA);
                result.push_back(temp);
            }
            posA = posB + 1;
        }
    }

    std::vector<char> xx = result[result.size() - 1];
    return result;
}

std::string removeProPostSpacing(const std::string& str)
{
    if (str.size() == 0)
        DebugBreak();

    if (str.size() == 1) {
        if (' ' == str[0])
            DebugBreak();
        return str;
    }

    size_t posA = 0;
    int posB = 0;
    for (; posA < str.size(); ++posA) {
        if (' ' != str[posA]) {
            break;
        }
    }

    if (posA == str.size())
        DebugBreak();

    for (posB = (int)str.size() - 1; posB >= 0; --posB) {
        if (' ' != str[posB]) {
            break;
        }
    }

    if (posB == -1)
        DebugBreak();

    return str.substr(posA, posB - posA + 1);
}

// const utf8* partialURL
static void parseParams(const std::string& param, std::vector<std::string>* formParams, std::vector<std::string>* realParams)
{
    std::string paramStr(removeProPostSpacing(param));

    size_t posA = 0;
    size_t posB = 0;
    for (posB = paramStr.size() - 1; posB >= 0; --posB) {
        if (' ' == paramStr[posB]) {
            break;
        }
    }

    std::string formParam = paramStr.substr(posA, posB);
    std::string realParam = paramStr.substr(posB);

    formParams->push_back(removeProPostSpacing(formParam));
    realParams->push_back(removeProPostSpacing(realParam));
}

struct LineInfo {
    std::string returnVal;
    std::string ITERATOR_x;
    std::string name;
    std::vector<std::string> formParams;
    std::vector<std::string> realParams;
};

// ITERATOR3(wkeMemBuf*, wkeCreateMemBuf, wkeWebView webView, void* buf, size_t length, "")
static LineInfo* parseToken(std::string lineStr)
{
    size_t pos = lineStr.find("    ITERATOR");
    size_t size = 0;
    if (pos == std::string::npos)
        return nullptr;

    LineInfo* result = new LineInfo();

    if (lineStr[pos + 13] == '(')
        size = 13;
    else if (lineStr[pos + 14] == '(')
        size = 14;
    else
        DebugBreak();

    result->ITERATOR_x = lineStr.substr(pos + 4, size - (pos + 4));
    bool noParam = ("ITERATOR0" == result->ITERATOR_x);

    pos += size + 1;

    // 获取返回值
    for (size_t j = pos; j < lineStr.size(); ++j) {
        if (',' == lineStr[j]) {
            result->returnVal = lineStr.substr(pos, j - pos);
            result->returnVal = removeProPostSpacing(result->returnVal);
            pos = j + 1;
            break;
        }
    }

    // 获取函数名
    for (size_t j = pos; j < lineStr.size(); ++j) {
        if (',' == lineStr[j]) {
            result->name = lineStr.substr(pos, j - pos);
            result->name = removeProPostSpacing(result->name);
            pos = j + 1;
            break;
        }
    }

    if (noParam)
        return result;

    for (size_t j = pos; j < lineStr.size(); ++j) {
        if (',' == lineStr[j]) {
            std::string temp = lineStr.substr(pos, j - pos);
            parseParams(temp, &(result->formParams), &(result->realParams));
            pos = j + 1;

            if ('\"' == lineStr[j + 2])
                break;
        }
    }

    return result;
}

// ITERATOR3(wkeMemBuf*, wkeCreateMemBuf, wkeWebView webView, void* buf, size_t length, "") ->
// ITERATOR3(wkeMemBuf*, wkeCreateMemBuf, wkeWebView, void*, size_t, webView, buf, length, "") ->
void parseLines()
{
    std::vector<std::vector<char>> lines = readLine(L"G:\\test\\exe_test\\memory_load\\build\\mbsplit\\wke.h-");
    for (size_t i = 0; i < lines.size(); ++i) {
        std::string output;
        std::vector<char> line = lines[i];
        std::string lineStr(line.data(), line.size());
        //    ITERATOR11(void, wkePaint2, wkeWebView webView, void* bits, int bufWid, int bufHei, int xDst, int yDst, int w, int h, int xSrc, int ySrc, bool bCopyAlpha, "")
        LineInfo* info = parseToken(lineStr);
        if (info) {
            output += info->ITERATOR_x;
            output += "(";
            output += info->returnVal;
            output += ", ";
            output += info->name;
            output += ", ";
            for (size_t j = 0; j < info->formParams.size(); ++j) {
                output += info->formParams[j];
                output += ", ";
            }

            for (size_t j = 0; j < info->realParams.size(); ++j) {
                output += info->realParams[j];
                output += ", ";
            }

            output += "\"\") \\\n";
        }
        OutputDebugStringA(output.c_str());
    }
}

int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf, LPNEWTEXTMETRIC lpntm, DWORD nFontType, long lparam)
{
    //   CGetSystemFontDlg* pWnd = (CGetSystemFontDlg*)lparam;//窗口句柄 
    //   if (pWnd->m_font != (lpelf->elfLogFont.lfFaceName)) {
    //     pWnd->m_font = (lpelf->elfLogFont.lfFaceName);
    //     pWnd->m_fontList.AddString(pWnd->m_font);
    //   }
    std::wstring output = lpelf->elfLogFont.lfFaceName;
    output += L"\n";
    OutputDebugStringW(output.c_str());
    return 1;
}

void GetSystemFonts()
{
    LOGFONT lf;
    memset(&lf, 0, sizeof(LOGFONT));
    lf.lfCharSet = DEFAULT_CHARSET;
    lf.lfFaceName[0] = NULL;
    ::EnumFontFamiliesEx(::GetDC(nullptr), &lf, (FONTENUMPROC)EnumFontFamProc, (LPARAM)nullptr, 0);
    OutputDebugStringA("");
}

// void findExeInChromiumImpl(const std::wstring& path)
// {
//     size_t pos = path.rfind(L".");
//     if (std::wstring::npos == pos)
//         return;
// 
//     size_t pos2 =  path.find(L"P:\\chromium\\M87fp\\src\\out\\");
//     if (std::wstring::npos != pos2)
//         return;
// 
//     std::wstring tempPath = path.substr(pos);
//     if (L".exe" != tempPath && L".dll" != tempPath)
//         return;
// 
//     std::wstring pathOther(path);
//     pathOther[0] = L'M'; // M:\chromium\M86xp
//     pathOther[14] = L'6';
//     pathOther[15] = L'x';
//     pathOther[16] = L'p';
//     if (::PathFileExistsW(pathOther.c_str()))
//         return;
// 
//     ::CopyFileW(path.c_str(), pathOther.c_str(), TRUE);
// 
//     pathOther += '\n';
//     OutputDebugStringW(pathOther.c_str());
// }

void findExeInChromiumImpl(const std::wstring& path)
{
    size_t pos = path.rfind(L".");
    if (std::wstring::npos == pos)
        return;

    size_t pos2 = path.find(L"P:\\chromium\\M87fp\\src\\out\\");
    if (std::wstring::npos != pos2)
        return;

    std::wstring tempPath = path.substr(pos);
    if (L".h" == tempPath || L".cc" == tempPath || L".cpp" == tempPath || L".cxx" == tempPath || L".hpp" == tempPath
        || L".png" == tempPath || L".xml" == tempPath || L".java" == tempPath || L".sha1" == tempPath
        || L".md" == tempPath || L".html" == tempPath || L".js" == tempPath || L".svg" == tempPath
        || L".mm" == tempPath || L".ttf" == tempPath || L".xtb" == tempPath || L".grd" == tempPath
        || L".icon" == tempPath || L".gn" == tempPath || L".txt" == tempPath || L".xht" == tempPath
        )
        return;

    std::wstring pathOther(path);
    pathOther[0] = L'M'; // M:\chromium\M86xp
    pathOther[14] = L'6';
    pathOther[15] = L'x';
    pathOther[16] = L'p';
    if (::PathFileExistsW(pathOther.c_str()))
        return;

    //::CopyFileW(path.c_str(), pathOther.c_str(), TRUE);

    pathOther += '\n';
    OutputDebugStringW(pathOther.c_str());
}

void findExeInChromium(const std::wstring& strPath)
{
    //std::wstring& strPath = L"P:\chromium\M87fp\src";

    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // {排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径
                findExeInChromium(strTemp);//递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            findExeInChromiumImpl(strTemp);
            OutputDebugStringA("");
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

void findGitInChromium(const std::wstring& strPath)
{
    //std::wstring& strPath = L"P:\chromium\M87fp\src";

    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::wstring fileName = findData.cFileName;
            if (fileName != L"." && fileName != L"..") { // 排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径]

                if (fileName == L".git") {
                    strTemp += L"\n";
                    OutputDebugStringW(strTemp.c_str());
                } else
                    findGitInChromium(strTemp); // 递归查找当前目录的文件
            }
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

std::string StringXORW(const std::string& content, const std::string& strKey)
{
    std::string str = content;
    for (unsigned int i = 0; i < str.length(); i++) {
        str[i] ^= strKey[i % strKey.length()];
    }

    return str;
}

void decryptFpConfig()
{
    std::vector<char> buffer;
    //   const wchar_t* path = L"C:\\Users\\Administrator\\AppData\\Local\\chrome1\\fp_json.json";
    //   readFile(path, &buffer);

    buffer.push_back('1');
    buffer.push_back('2');
    buffer.push_back('3');
    buffer.push_back('4');

    const char* key = "ORDERH7ROJCYNHKXE";

    struct Head {
        int magic;
        int version;
        int size;
        int unuse;
    };

    std::string result = StringXORW(std::string(buffer.data(), buffer.size()), key);
    Head head;
    head.magic = 'fpjm';
    head.version = 1;
    head.size = result.size();
    head.unuse = 0;

    std::vector<char> outBuffer(sizeof(Head) + result.size());
    memcpy(outBuffer.data(), &head, sizeof(Head));
    memcpy(outBuffer.data() + sizeof(Head), result.data(), result.size());
    //saveDumpFile(path, outBuffer.data(), outBuffer.size());

    OutputDebugStringA("");
}

int hashCode(const char* value, int length)
{
    int h = 0;
    for (int i = 0; i < length; i++) {
        h = 31 * h + value[i];
    }
    return h;
}

void replaceRN(std::vector<char>& buffer, const std::wstring& strPath)
{
    int count = 0;
    std::vector<char> result;
    for (size_t i = 0; i < buffer.size(); i++) {
        if (buffer[i] != '\r')
            result.push_back(buffer[i]);
        else
            count++;
    }

    if (count > 0)
        saveDumpFile(strPath.c_str(), result.data(), result.size());
}

void findDiffInV8Gen(const std::wstring& strPath, const std::wstring& strPath2)
{
    //std::wstring& strPath = L"P:\chromium\M87fp\src";

    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::wstring fileName = findData.cFileName;
            if (fileName != L"." && fileName != L"..") { // 排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径
                std::wstring strTemp2 = strPath2 + L"\\" + findData.cFileName;
                findDiffInV8Gen(strTemp, strTemp2); // 递归查找当前目录的文件
            }
        } else {
            std::wstring fileName = findData.cFileName;
            strTemp = strPath + L"\\" + findData.cFileName;
            std::wstring strTemp2 = strPath2 + L"\\" + findData.cFileName;

            if (std::wstring::npos != fileName.find(L".cpp") || std::wstring::npos != fileName.find(L".cc") || std::wstring::npos != fileName.find(L".h")) {
                std::vector<char> buffer1;
                readFile(strTemp.c_str(), &buffer1);

                replaceRN(buffer1, strTemp);

                int hash1 = hashCode(buffer1.data(), buffer1.size());

                std::vector<char> buffer2;
                readFile(strTemp2.c_str(), &buffer2);
                replaceRN(buffer2, strTemp2);

                int hash2 = hashCode(buffer2.data(), buffer2.size());
                if (hash1 != hash2) {
                    OutputDebugStringW(strTemp.c_str());
                    OutputDebugStringW(L"\n");
                }
            }
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

// "(max-width: 700px)"
bool MatchMediaParser(const std::string& query, std::string* key, std::string* val)
{
    std::string str(query);
    size_t pos1 = str.find("(");
    if (std::string::npos == pos1)
        return false;

    size_t pos2 = str.find(":", pos1);
    if (std::string::npos == pos2)
        return false;

    size_t pos3 = str.find(")", pos2);
    if (std::string::npos == pos3)
        return false;

    std::string temp = str.substr(pos1 + 1, pos2 - pos1 - 1);
    if (temp.empty())
        return false;
    *key = removeProPostSpacing(temp);

    temp = str.substr(pos2 + 1, pos3 - pos2 - 1);
    if (temp.empty())
        return false;
    *val = removeProPostSpacing(temp);
    return true;
}

void getGitDirs(const std::wstring& strPath, std::vector<std::wstring>* result)
{
    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            std::wstring fileName = findData.cFileName;
            strTemp = strPath + L"\\" + findData.cFileName; // 获得完整路径

            if (fileName != L"." && fileName != L"..") {
                if (fileName == L".git") {
                    result->push_back(strTemp);
                } else
                    getGitDirs(strTemp, result); // 递归查找当前目录的文件
            }
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

void searchHex()
{
    unsigned char code[] = {
        0x49, 0x8b, 0xf8,
        0x33, 0xf6,
        0x55,
        0x48, 0x89, 0xe5,
        0x6a, 0x2c,
        0x49, 0x8b, 0xb5, 0xc0, 0x47, 0x00, 0x00,
        0x57,
        0x4c, 0x8b, 0x55, 0x00,
        0x49, 0x8b, 0x42, 0x30,
        0x49, 0x8b, 0x5a, 0x38,
        0x49, 0x89, 0xe2,
        0x4d, 0x2b, 0x55, 0x10,
    };

    const wchar_t* path = L"W:\\mycode\\mb108\\out\\win_Release_x64\\electron.exe";
    HMODULE hMod = LoadLibraryW(path);
    //wkeInitialize();

    std::vector<char> buffer;
    readFile(path, &buffer);
    for (size_t i = 0; i < buffer.size(); ++i) {
        //unsigned char* addr = (unsigned char*)buffer.data();
        unsigned char* addr = (unsigned char*)hMod;
        addr += i;

        bool notFind = false;
        for (size_t j = 0; j < sizeof(code); ++j) {
            if (addr[j] != code[j]) {
                notFind = true;
                break;
            }
        }
        if (!notFind) {
            char* output = (char*)malloc(0x100);
            sprintf_s(output, 0x99, "searchHex find: 0x%p\n", (addr));
            OutputDebugStringA(output);
            free(output);
        }
    }
    OutputDebugStringA("searchHex end\n");
}

void copyChromiumCppAndHeadFileImpl(const std::wstring& src)
{
    size_t pos = src.rfind(L".");
    if (std::wstring::npos == pos)
        return;

    std::wstring tempPath = src.substr(pos);
    //   if (L".h" != tempPath && L".cc" != tempPath && L".cpp" != tempPath && L".cxx" != tempPath && L".hpp" != tempPath && L".c" != tempPath)
    //     return;
    if (L".c" != tempPath)
        return;

    // M:\chromium\cef89fp
    std::wstring dest = src;

    dest[0] = 'M';
    BOOL b = ::CopyFileW(src.c_str(), dest.c_str(), FALSE);
    dest += L'\n';
    OutputDebugStringW(dest.c_str());
}

void copyChromiumCppAndHeadFile(const std::wstring& strPath)
{
    //std::wstring& strPath = L"P:\chromium\M87fp\src";

    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // {排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径
                copyChromiumCppAndHeadFile(strTemp);//递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            copyChromiumCppAndHeadFileImpl(strTemp);
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

void testDownloadMain()
{
//   for (int i = 0; i < 1800; ++i) { // https://video.missav.com/bcdn_token=yFyFWB2CIIGEb_qE4Z-WFE0gY9OVaS8xip4h7DYLF-o&expires=1660095926&token_path=%2Fad4f5178-e546-44cc-ab07-fbd98fb2fce6%2F/ad4f5178-e546-44cc-ab07-fbd98fb2fce6/1280x720/video0.ts
//     WCHAR temp[10] = {0};
//     wsprintf(temp, L"video%d.ts", i);
// 
//     std::wstring url = L"https://video.missav.com/bcdn_token=yFyFWB2CIIGEb_qE4Z-WFE0gY9OVaS8xip4h7DYLF-o&expires=1660095926&token_path=%2Fad4f5178-e546-44cc-ab07-fbd98fb2fce6%2F/ad4f5178-e546-44cc-ab07-fbd98fb2fce6/1280x720/";
//     url += temp;
// 
//     std::wstring file = L"G:\\test\\web_test\\ele_test\\download\\";
//     file += temp;
// 
//     HRESULT hresult = URLDownloadToFileW(NULL, url.c_str(), file.c_str(), 0, NULL);
//     hresult = hresult;
//   }
}

// #include "E:/chroium/M108/src/patch_code/no_destructor_xp.h"
// 
// struct MyStruct {
//   MyStruct() {
//     x = 0;
// 
//     char* output = (char*)malloc(0x100);
//     sprintf_s(output, 0x99, "MyStruct: %d\n", ::GetCurrentThreadId());
//     OutputDebugStringA(output);
//     free(output);
//   }
// 
//   ~MyStruct() {
// 
//   }
//   int x;
// };

static DWORD NTAPI TestZcThreadSafeInitFunc(void* param)
{
  return 0;
}

void TestZcThreadSafeInit()
{
  ::CreateThread(0, 0, TestZcThreadSafeInitFunc, nullptr, 0, nullptr);
  ::CreateThread(0, 0, TestZcThreadSafeInitFunc, nullptr, 0, nullptr);
}

#define ALWAYS_INLINE inline

ALWAYS_INLINE uint32_t my__builtin_ctz(uint32_t x)
{
    uint32_t n = 0;
    if (x == 0) return 32;
    if ((x & 0x0000FFFF) == 0) { n += 16; x >>= 16; }
    if ((x & 0x000000FF) == 0) { n += 8; x >>= 8; }
    if ((x & 0x0000000F) == 0) { n += 4; x >>= 4; }
    if ((x & 0x00000003) == 0) { n += 2; x >>= 2; }
    if ((x & 0x00000001) == 0) { n += 1; }
    return n;
}

#define ALWAYS_INLINE inline

ALWAYS_INLINE uint32_t my__builtin_ctzll(uint64_t x)
{
    if (x == 0) {
        return 64;
    }
    uint32_t cnt = 0;
    while ((x & 1) == 0) {
        cnt++;
        x >>= 1;
    }
    return cnt;
}

ALWAYS_INLINE uint32_t my__builtin_clzll(uint64_t x)
{
    uint32_t n = 0;
    if (x == 0) { return 64; }
    if (x <= 0x00000000FFFFFFFFULL) { n += 32; x <<= 32; }
    if (x <= 0x0000FFFFFFFFFFFFULL) { n += 16; x <<= 16; }
    if (x <= 0x00FFFFFFFFFFFFFFULL) { n += 8; x <<= 8; }
    if (x <= 0x0FFFFFFFFFFFFFFFULL) { n += 4; x <<= 4; }
    if (x <= 0x3FFFFFFFFFFFFFFFULL) { n += 2; x <<= 2; }
    if (x <= 0x7FFFFFFFFFFFFFFFULL) { n += 1; }
    return n;
}

// ALWAYS_INLINE uint32_t my__builtin_clz(uint32_t x)
// {
//     if (x == 0)
//         return 32;
// 
//     int n = 0;
//     if (x <= 0x0000FFFF) { n += 16; x <<= 16; }
//     if (x <= 0x00FFFFFF) { n += 8; x <<= 8; }
//     if (x <= 0x0FFFFFFF) { n += 4; x <<= 4; }
//     if (x <= 0x3FFFFFFF) { n += 2; x <<= 2; }
//     if (x <= 0x7FFFFFFF) { n += 1; }
// 
//     return n;
// }

int my__builtin_clz(unsigned int x) {
    if (x == 0)
        return 32; // 没有前导的0，返回32
    int count = 0;
    unsigned int mask = 0x80000000; // 最高位为1，其余位为0
    while ((x & mask) == 0) {
        mask >>= 1;
        count++;
    }
    return count;
}

template <typename T, int bits = sizeof(T) * 8>
constexpr typename std::enable_if<std::is_unsigned<T>::value && sizeof(T) <= 8, int>::type CountLeadingZeroBits(T value)
{
    static_assert(bits > 0, "invalid instantiation");
    return /*LIKELY*/(value)
        ? bits == 64
        ? my__builtin_clzll(static_cast<uint64_t>(value))
        : my__builtin_clz(static_cast<uint32_t>(value)) - (32 - bits)
        : bits;
}

template <typename T, int bits = sizeof(T) * 8>
constexpr typename std::enable_if<std::is_unsigned<T>::value && sizeof(T) <= 8, int>::type CountTrailingZeroBits(T value)
{
    return /*LIKELY*/(value) ? bits == 64
        ? my__builtin_ctzll(static_cast<uint64_t>(value))
        : my__builtin_ctz(static_cast<uint32_t>(value))
        : bits;
}

int IndexOfFirstFlagSet(size_t flag)
{
    return CountTrailingZeroBits(flag);
}

int IndexOfFirstFlagSet2(size_t flag)
{
    return CountLeadingZeroBits(flag);
}

static void ReplaceMidString2(std::string* str, int pos1, int pos2, const std::string& replace)
{
  if (pos1 >= pos2)
    return;
  if (pos2 > (int)str->length())
    return;

  std::string end_str = str->substr(pos2, std::string::npos);
  *str = str->substr(0, pos1);
  str->append(replace);
  str->append(end_str);
}

void ReplaceINIP4(std::string* sdp, const std::string& webrtc_public_ip)
{
  const char kINIP4[] = "IN IP4 ";
  const size_t kLen = sizeof(kINIP4) - 1;
  size_t pos = 0;

  while (true) {
    pos = sdp->find(kINIP4, pos);
    if (std::string::npos == pos)
      break;
    pos += kLen;
    size_t pos2 = sdp->find(" ", pos);

    ReplaceMidString2(sdp, pos, pos2, webrtc_public_ip);
    pos = pos2;
  }
}

void searchHex2(HINSTANCE hInstance)
{
    unsigned char code[] = {
        /*00007FF7A8963E74*/ 0x4C, 0x8D, 0xB4, 0x24, 0x88, 0x00, 0x00, 0x00, // lea         r14,[rsp + 88h]
        /*00007FF7A8963E7C*/ 0x49, 0x89, 0x06, //mov         qword ptr[r14],rax
        /*00007FF7A8963E7F*/ 0x49, 0xC7, 0x46, 0x08, 0x27, 0x00, 0x00, 0x00, // mov         qword ptr[r14 + 8],27h
        /*00007FF7A8963E87*/ 0x48, 0x8B, 0x0B, //mov         rcx,qword ptr[rbx]
        /*00007FF7A8963E8A*/ 0x48, 0x8B, 0x01, //mov         rax,qword ptr[rcx]
        /*00007FF7A8963E8D*/ 0x48, 0x8B, 0x40, 0x30, //mov         rax,qword ptr[rax + 30h]
    };

    const WCHAR* path = L"O:\\chromium\\ele32fp\\out\\rx64\\electron.exe";
    //HMODULE hMod = LoadLibraryW(path);
    //wkeInitialize();
    HMODULE hMod = (HMODULE)hInstance;

    std::vector<char> buffer;
    readFile(path, &buffer);
    for (size_t i = 0; i < buffer.size(); ++i) {
        //unsigned char* addr = (unsigned char*)buffer.data();
        unsigned char* addr = (unsigned char*)hMod;
        addr += i;

        bool notFind = false;
        for (size_t j = 0; j < sizeof(code); ++j) {
            if (addr[j] != code[j]) {
                notFind = true;
                break;
            }
        }
        if (!notFind) {
            char* output = (char*)malloc(0x100);
            sprintf_s(output, 0x99, "searchHex find: 0x%p\n", (addr));
            OutputDebugStringA(output);
            free(output);
        }
    }
    OutputDebugStringA("searchHex end\n");
}

void findFileCommon(const std::wstring& strPath, std::function<void(const std::wstring& strPath)> cb)
{
    //std::wstring& strPath = L"P:\chromium\M87fp\src";

    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // {排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName;//获得完整路径
                findFileCommon(strTemp, cb);//递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            cb(strTemp);
            OutputDebugStringA("");
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

static std::string convertString(const std::string& input)
{
    std::string result = "k";
    bool capitalizeNext = true;

    for (char c : input) {
        if (c == '_' || c == '.') {
            capitalizeNext = true;
        } else {
            if (capitalizeNext) {
                result += std::toupper(c);
                capitalizeNext = false;
            } else {
                result += c;
            }
        }
    }
    return result;
}

static std::string convertToUpperCase(const std::string& input)
{
    std::string result;
    for (char c : input) {
        if (c == '.') {
            result += '_';
        } else {
            result += std::toupper(c);
        }
    }
    return result;
}

void formatFileToCppArray()
{
    std::wstring strPath = L"W:\\mycode\\mb108\\third_party\\blink\\renderer\\core\\html\\forms\\resources";
    std::string result;

    findFileCommon(strPath, [&result](const std::wstring& path) {
        if (std::wstring::npos == path.find(L".js") && std::wstring::npos == path.find(L".css"))
            return;

        std::vector<char> buffer;
        readFile(path.c_str(), &buffer);
        std::wstring fileName = PathFindFileNameW(path.c_str());
        std::string tempStr = "case IDR_" + convertToUpperCase(utf16ToUtf8(fileName.c_str())) + ":\n";
        std::string fileNameA = convertString(utf16ToUtf8(fileName.c_str()));

        tempStr += "    return MAKE_STD_STRING(";
        tempStr += fileNameA;
        tempStr += ");\n";
        OutputDebugStringA(tempStr.c_str());

        std::string output = "const unsigned char " + fileNameA + "[] = {\n";
        for (size_t i = 0; i < buffer.size(); ++i) {
            char temp[64] = { 0 };
            sprintf_s(temp, 63, "0x%x, ", buffer[i]);
            output += temp;

            if (i % 17 == 0)
                output += "\n";
        }
        output += "};\n\n";

        result += output;
    });

    saveDumpFile(L"W:\\mycode\\mb108\\third_party\\blink\\renderer\\core\\html\\forms\\resources\\111.h", result.c_str(), result.size());
}

// 截断后面两个目录的路径
static std::string removeLastDirectories(const std::string& path, int count)
{
    std::string result = path;
    int slashCount = 0;
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        if (*it == '\\') {
            ++slashCount;
            if (slashCount == count) {
                result = result.substr(0, (it.base() - result.begin()));
                break;
            }
        }
    }
    return result;
}

// 把../这种路径简化
std::string resolvePath(const std::string& path)
{
    std::vector<std::string> parts;
    std::string currentPart;

    for (size_t i = 0; i < path.length(); ++i) {
        if (path[i] == '\\') {
            if (currentPart == "..") {
                if (!parts.empty()) {
                    parts.pop_back();
                }
            } else if (!currentPart.empty()) {
                parts.push_back(currentPart);
            }
            currentPart.clear();
        } else {
            currentPart += path[i];
        }
    }

    if (currentPart == "..") {
        if (!parts.empty()) {
            parts.pop_back();
        }
    } else if (!currentPart.empty()) {
        parts.push_back(currentPart);
    }

    std::string resolvedPath;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) {
            resolvedPath += '\\';
        }
        resolvedPath += parts[i];
    }

    return resolvedPath;
}

static void pathNormal(std::string* str)
{
    for (int i = 0; i < str->size(); ++i) {
        if ((*str)[i] >= 'A' && (*str)[i] <= 'Z') {
            (*str)[i] += 32;
        }
        if ((*str)[i] == '/')
            (*str)[i] = '\\';
    }

    *str = resolvePath(*str);
}

std::string addDirectoryToPath(const std::string& path, const std::string& newDirectory)
{
    std::string result = path;
    // 检查路径是否以路径分隔符结尾
    if (!result.empty() && result.back() != '/' && result.back() != '\\') {
#ifdef _WIN32
        result += '\\';
#else
        result += '/';
#endif
    }
    result += newDirectory;
    return result;
}

// 把xxx\yy\dd-dd.cc 变成xxx_yy_dd_dd_cc
static void pathToCppName(std::string* str)
{
//     for (int i = 0; i < str->size(); ++i) {
//         if (!(
//             (*str)[i] >= 'A' && (*str)[i] <= 'Z' 
//             || (*str)[i] >= 'a' && (*str)[i] <= 'z'
//             || (*str)[i] >= '0' && (*str)[i] <= '9')) {
//             (*str)[i] = '_';
//         }
//     }
    for (int i = 0; i < str->size(); ++i) {
        if ((*str)[i] == '\\')
            (*str)[i] = '/';
    }

    if (str->size() > 1 && str->at(0) == '/') {
        str->erase(0, 1);
    }
}

//--
// namespace atom {
// 
// struct MiniElectronAsarResInfo {
//   const char* name;
//   const unsigned char* res;
// };
// 
// struct MiniElectronAsarResInfo kMiniElectronAsarResInfo[] = {
//         {"resource1", (const unsigned char[])"\x12\x22"},
//         {"resource2", (const unsigned char[])"\x12\x22"},
// };
// }
//--

void genMiniElectronAsarRes()
{
//     char buffer[] = { 0xAB, 0xCD, 0xEF };
//     char temp[63];
//     int num_elements = sizeof(buffer) / sizeof(buffer[0]);
// 
//     for (int i = 0; i < num_elements; i++) {
//         // 使用 sprintf_s 将 buffer[i] 转换为 \xXX 形式的字符串
//         char c = buffer[i];
//         int result = sprintf_s(temp, sizeof(temp), "\\x%02X", ( char)c);
//         OutputDebugStringA("");
//     }

    const int bufferSize = MAX_PATH;
    char exePath[bufferSize];

    // 获取当前可执行文件的路径
    ::GetModuleFileNameA(NULL, exePath, bufferSize);

    std::string rootPath = exePath;
    pathNormal(&rootPath);
    rootPath = removeLastDirectories(rootPath, 3);
    rootPath = addDirectoryToPath(rootPath, "electron");

    std::string result = "namespace atom {\n";
    result += "struct MiniElectronAsarResInfo {\n";
    result += "    const char* name;\n";
    result += "    const unsigned char* res;\n";
    result += "};\n";
    result += "MiniElectronAsarResInfo kMiniElectronAsarResInfo[] = {\n";

    findFileCommon(utf8ToUtf16(rootPath), [&result, rootPath](const std::wstring& path) {
        if (std::wstring::npos == path.find(L".js") && std::wstring::npos == path.find(L".html"))
            return;

        std::vector<char> buffer;
        readFile(path.c_str(), &buffer);
//         buffer.push_back('\x12');
//         buffer.push_back('\x12');

        std::string pathU8 = utf16ToUtf8(path.c_str());
        pathNormal(&pathU8);
        std::string fileNameA = pathU8.substr(rootPath.size(), std::string::npos);
        pathToCppName(&fileNameA);

        std::string output = "{\"" + fileNameA + "\", \n(const unsigned char*)\"";
        for (size_t i = 0; i < buffer.size(); ++i) {
            char temp[64] = { 0 };
            sprintf_s(temp, 63, "\\x%02X", (unsigned char)buffer[i]);
            output += temp;

            if (i % 17 == 0)
                output += "\"\n\"";
        }
        output += "\"\n},\n\n";

        result += output;
    });

    result += "}; // MiniElectronAsarResInfo\n";
    result += "} // atom\n";

    std::string resulePath = addDirectoryToPath(rootPath, "lib\\MiniElectronAsarRes.h");
    saveDumpFile(utf8ToUtf16(resulePath), result.c_str(), result.size());
}

void findLinkError()
{
    std::set<std::string> results;
    std::vector<std::vector<char>> lines = readLine(L"W:\\mycode\\mb108\\out\\linux_release_arm32\\link_error.txt");
    for (size_t i = 0; i < lines.size(); ++i) {
        std::string output;
        std::vector<char> line = lines[i];
        std::string lineStr(line.data(), line.size());

        const char kTest[] = "undefined reference to '";
        size_t posA = lineStr.find(kTest);
        if (std::string::npos == posA)
            continue;

        posA += (sizeof(kTest) - 1);
        size_t posB = lineStr.find("'", posA);
        std::string lineRet = lineStr.substr(posA, posB - posA);
        lineRet += "\n";
        results.insert(lineRet);
    }
    for (std::set<std::string>::const_iterator it = results.begin(); it != results.end(); ++it) {
        std::string lineR = *it;
        OutputDebugStringA(lineR.c_str());
    }
}

bool GetFileSize(const wchar_t* filePath, LARGE_INTEGER& fileSize)
{
    HANDLE hFile = CreateFileW(
        filePath,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        return false;
    }

    if (!GetFileSizeEx(hFile, &fileSize)) {
        CloseHandle(hFile);
        return false;
    }

    CloseHandle(hFile);
    return true;
}

void findChromiumIco()
{
    std::wstring strPath = L"W:\\chromium\\M122fp\\";
    std::string result;

    findFileCommon(strPath, [&result](const std::wstring& path) {
        LARGE_INTEGER fileSize;
        GetFileSize(path.c_str(), fileSize);
        if (fileSize.LowPart == 1698) {
            std::wstring out = L"";
            out += path;
            out += L"\n";
            OutputDebugStringW(out.c_str());
        }
    });
    OutputDebugStringA("");
}

// void TestMain()
// {
//   std::string kTest = //"c=IN IP4 0.0.0.0 sdfasdf";
// 
//     "a=extmap-allow-mixed \n"
//     "a=msid-semantic: WMS \n"
//     "m=application 9 UDP/DTLS/SCTP webrtc-datachannel \n"
//     "c=IN IP4 0.0.0.0 \n"
//     "a=ice-ufrag:ui0p \n"
//     "a=ice-pwd:AD6XWsxl88W5B8jqq/XF5vr7 \n";
// 
//   ReplaceINIP4(&kTest, "120.235.22.96");
//   OutputDebugStringA("");
// //     int aa = IndexOfFirstFlagSet2(0x1234);
// //     return;
// // 
// //     TestZcThreadSafeInit();
// //     Sleep(100000);
// 
//     std::vector<int64_t> ranges;
// //     ranges.push_back(net::makeLong64(0, 0x15fef3));
// //     ranges.push_back(net::makeLong64(0x2c717bf, 0x2c717f9));
// //     net::mergeVec(&ranges, 0x00005c16, 0x0000dc15);
// //     ranges.clear();
// 
//     ranges.clear();
//     ranges.push_back(net::makeLong64(0, 10));
//     ranges.push_back(net::makeLong64(30, 40));
//     net::mergeVec(&ranges, 1, 2);
//     ranges.clear();
// 
// //     ranges.push_back(makeLong64(0, 6));
// //     ranges.push_back(makeLong64(7, 15));
// //     mergeTouchVec(&ranges, 0);
// //     ranges.clear();

// 
//     //SearchHex();
//     //copyChromiumCppAndHeadFile(L"P:\\chromium\\cef89fp");
//     return;
// //     std::vector<std::wstring> result;
// //     getGitDirs(L"M:\\chromium\\M86xp\\src", &result);
// // 
// //     for (size_t i = 0; i < result.size(); ++i) {
// //         std::wstring temp = result[i];
// //         temp += L'\n';
// //         OutputDebugStringW(temp.c_str());
// //     }
// //     OutputDebugStringA("");
// }
