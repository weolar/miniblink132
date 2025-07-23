
#define _CRT_SECURE_NO_WARNINGS 1

#include "FastMakeMain.h"

#include "content/common/cJSON.h"
#include "content/common/Util.h"
#include "content/common/StringUtil.h"
#include "CmdHandler.h"
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
#include <unordered_map>
#include <set>
#include <atomic>
#include <ShlObj.h>
#include <time.h>

#include "../patch_code/no_destructor_xp.h"

#pragma optimize("", off)
#pragma clang optimize off

int runQjsTest(const char* rootPath, const char* buf, size_t inputLen);
void qjsRebuild(const std::string& jsonPath, const std::string& jsonName, const std::string& cmd, RebuildOpt opt);

static const int kMaxThreadNum = 16;
HMODULE g_hModule;

const char* blackCmdForC[] = { "-std=c++11", "-std=c++14", "-std=c++17", "-std=c++20", nullptr };

bool g_isWin = false;

void printError(const char* str);

static bool isEndWith(const std::string& str, const std::string& pa)
{
    if (str.size() < pa.size())
        return false;

    std::string temp = str.substr(str.size() - pa.size(), std::string::npos);
    return temp == pa;
}

static std::vector<char> stdStringToBuffer(const std::string& str)
{
    std::vector<char> buffer(str.size());
    memcpy(buffer.data(), str.c_str(), str.size());
    return buffer;
}

static bool reNameFile(const WCHAR* _pFrom, const WCHAR* _pTo)
{
    //     WCHAR pTo[MAX_PATH] = { 0 };
    //     wcscpy(pTo, _pTo);
    //     WCHAR pFrom[MAX_PATH] = { 0 };
    //     wcscpy(pFrom, _pFrom);
    //
    //     SHFILEOPSTRUCT FileOp = { 0 };
    //     FileOp.fFlags = FOF_NOCONFIRMATION | FOF_RENAMEONCOLLISION;
    //     FileOp.pFrom = pFrom;
    //     FileOp.pTo = pTo;
    //     FileOp.wFunc = FO_RENAME;
    //     bool ret = SHFileOperation(&FileOp) == 0;
    //     return ret;

    ::DeleteFileW(_pTo);
    BOOL b = ::MoveFileW(_pFrom, _pTo);
    return !!b;
}

DWORD listAllFileInDrectory(const WCHAR* szPath)
{
    WCHAR szFilePath[MAX_PATH];

    WIN32_FIND_DATAW findFileData;
    HANDLE hListFile;
    WCHAR szFullPath[MAX_PATH];

    // 构造代表子目录和文件夹路径的字符串，使用通配符“*”
    wcscpy(szFilePath, szPath);
    wcscat(szFilePath, L"\\*");
    // 查找第一个文件/目录，获得查找句柄
    hListFile = FindFirstFile(szFilePath, &findFileData);

    if (hListFile == INVALID_HANDLE_VALUE) {
        printf("错误：%d", GetLastError());
        return 1;
    }

    do {
        // 过滤“.”和“..”，不需要遍历
        if (lstrcmp(findFileData.cFileName, TEXT(".")) == 0 || lstrcmp(findFileData.cFileName, TEXT("..")) == 0) {
            continue;
        }
        //构造成全路径
        wsprintf(szFullPath, L"%s\\%s", szPath, findFileData.cFileName);

        //打印
        //printf("\n%d\t%s\t", dwTotalFileNum, szFullPath);

        //如果是目录，则递归调用，列举下级目录
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            listAllFileInDrectory(szFullPath);
        } else {
            if (isEndWith(content::utf16ToUtf8(szFullPath), ".o")) {
                std::wstring newName = szFullPath;
                newName += L"bj";
                reNameFile(szFullPath, newName.c_str());
            }
        }
    } while (FindNextFile(hListFile, &findFileData));

    return 0;
}

// 命令行数组转换成命令行字符串
static std::string appendCmd(const std::vector<std::string>& cmds, bool isCpp)
{
    std::string ret(" ");
    for (size_t i = 0; i < cmds.size(); ++i) {
        bool find = false;
        for (size_t j = 0; !isCpp && blackCmdForC[j]; ++j) {
            if (cmds[i] == blackCmdForC[j]) {
                find = true;
                break;
            }
        }
        if (find)
            continue;
        ret += cmds[i];
        ret += " ";
    }
    return ret;
}

// 路径变成hash
uint32_t strHash(const std::string& str)
{
    //std::string str = pathNormalizeAndToLow(path);
    uint32_t hash = 0;

    for (size_t i = 0; i < str.size(); ++i) {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
    }

    return (hash & 0x7FFFFFFF);
}

// xxx/aaa.cc -> aaa.cc
static std::string getFileName(const std::string& str)
{
    size_t pos = str.rfind("/");
    if (std::string::npos == pos)
        pos = str.rfind("\\");
    if (std::string::npos == pos)
        return str;

    std::string ret = str.substr(pos + 1, std::string::npos);
    return ret;
}

// xxx/aaa.cc -> aaa.o
static std::string fileNameToObjName(const std::string& str, const std::string& postName)
{
    std::string ret = getFileName(str);
    size_t pos = ret.rfind(".");
    if (std::string::npos == pos)
        DebugBreak();
    ret = ret.substr(0, pos);
    return ret + postName;
}

static std::string pathAppend(const std::string& pathA, const std::string& pathB)
{
    if (pathA.empty())
        return pathB;

    std::string path = pathA;
    char c = path[path.size() - 1];
    if (c != '\\' && c != '/')
        path += "/";

    return path + pathB;
}

static std::string pathNormalize(const std::string& path)
{
    std::string ret;
    for (size_t i = 0; i < path.size(); ++i) {
        char c = path[i];
        if (c == '/')
            ret += '\\';
        else
            ret += c;
    }
    return ret;
}
static std::string pathNormalizeAndToLow(const std::string& path)
{
    std::string ret;
    for (size_t i = 0; i < path.size(); ++i) {
        char c = path[i];
        if (c == '/')
            ret += '\\';
        else if ('A' <= c && c <= 'Z')
            ret += c + 'a' - 'A';
        else
            ret += c;
    }
    return ret;
}

static bool isPathEq(const std::string& pathA, const std::string& pathB)
{
    std::string a = pathNormalizeAndToLow(pathA);
    std::string b = pathNormalizeAndToLow(pathB);
    return a == b;
}

const FILETIME kMaxFileTime = { 0xffffffff, 0xffffffff };

static bool getFileTime(const std::string& path, FILETIME* out)
{
    std::u16string pathW = content::utf8ToUtf16(path);
    FILETIME ftCreate, ftModify, ftAccess;
    HANDLE hFile = ::CreateFileW((const WCHAR*)pathW.data(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        *out = kMaxFileTime;
        return false;
    }

    SYSTEMTIME stLocal;
    if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftModify)) {
        *out = kMaxFileTime;
        ::CloseHandle(hFile);
        return false;
    }
    FileTimeToSystemTime(&ftAccess, &stLocal);
    *out = ftModify;
    ::CloseHandle(hFile);
    return true;
}

static bool timeAIsLongThenB(const FILETIME& a, const FILETIME& b)
{
    if (a.dwHighDateTime > b.dwHighDateTime)
        return true;
    else if (a.dwHighDateTime == b.dwHighDateTime)
        return a.dwLowDateTime > b.dwLowDateTime;
    else // a.dwHighDateTime < b.dwHighDateTime
        return false;
}

static std::vector<std::string> splitString(const std::string& str, char tag)
{
    std::vector<std::string> li;
    std::string subStr;

    //遍历字符串，同时将i位置的字符放入到子串中，当遇到tag（需要切割的字符时）完成一次切割
    //遍历结束之后即可得到切割后的字符串数组
    for (size_t i = 0; i < str.length(); i++) {
        if (tag == str[i]) { // 完成一次切割

            if (!subStr.empty()) {
                li.push_back(subStr);
                subStr.clear();
            }
        } else { // 将i位置的字符放入子串
            subStr.push_back(str[i]);
        }
    }

    if (!subStr.empty()) //剩余的子串作为最后的子字符串
        li.push_back(subStr);

    return li;
}

static std::string stringReplaceAll(const std::string& resource_str, const std::string& sub_str, const std::string& new_str)
{
    std::string dst_str = resource_str;
    std::string::size_type pos = 0;

    while ((pos = dst_str.find(sub_str)) != std::string::npos) {
        dst_str.replace(pos, sub_str.length(), new_str);
    }
    return dst_str;
}

static void handleJsonComments(std::vector<char>* buffer)
{
    char* pos = nullptr;
    do {
        pos = strstr(buffer->data(), "//");
        if (!pos)
            break;

        char* pos2 = pos;
        do {
            if ('\n' == *pos2)
                break;
            *pos2 = ' ';
            pos2++;
        } while (*pos2);
    } while (*pos);
}

void getAllFiles(const std::wstring& strPath, std::vector<std::wstring>* result)
{
    WIN32_FIND_DATA findData;
    std::wstring strTemp = strPath + L"\\*.*";

    HANDLE hFile = FindFirstFile(strTemp.c_str(), &findData);
    while (hFile != INVALID_HANDLE_VALUE) {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { // 如果是目录
            if (findData.cFileName[0] != L'.') { // 排除.和..文件夹
                strTemp = strPath + L"\\" + findData.cFileName; // 获得完整路径
                getAllFiles(strTemp, result); // 递归查找当前目录的文件
            }
        } else {
            strTemp = strPath + L"\\" + findData.cFileName;
            //handleClangFormat(strTemp);
            //OutputDebugStringA("");
            result->push_back(strTemp);
        }

        if (!FindNextFile(hFile, &findData)) {
            break;
        }
    }
    ::FindClose(hFile);
}

LPBYTE FindBin(LPBYTE lpBuf, size_t iBufBytes, LPBYTE lpMarkBuf, LPBYTE lpMarkFormat, size_t iMarkBufBytes)
{
    LPBYTE lpdata = lpBuf;
    size_t size = iBufBytes;
    BYTE CmpData = *lpMarkBuf;
    BOOL result = FALSE;

    while (size > 0) {
        // 查找第1个字符
        while ((--size) && (*lpdata != CmpData))
            lpdata++;
        if (*lpdata != CmpData)
            break; // 没有找到

        if (size < iMarkBufBytes)
            break; // 剩余比较的字节不够

        // 比较特征字符
        LPBYTE lp1 = lpdata + 1;
        LPBYTE lp2 = lpMarkBuf + 1;
        LPBYTE lp3 = lpMarkFormat + 1;
        size_t j = iMarkBufBytes - 1;
        while (--j) {
            if ((*lp3 != '?') && (*lp1 != *lp2))
                break;
            lp1++, lp2++, lp3++;
        }
        if (*lp1 == *lp2) { // 找到了
            result = TRUE;
            break;
        }

        lpdata++;
    }

    if (result)
        return lpdata;
    else
        return NULL;
}

static const char* memSrch(const char* src, size_t scrSize, const char* sub, size_t subSize)
{
    const char* bp;
    const char* sp;
    size_t restScrSz = scrSize; // 剩余主串的个数
    size_t restSubSz = subSize; // 剩余子串的个数

    if (!scrSize || !subSize) {
        return NULL;
    }

    /* 遍历主字符串 */
    while (restScrSz > 0) {
        /* 用来遍历子串 */
        bp = src;
        sp = sub;

        while (restSubSz > 0) {
            if (*bp == *sp) { // 如果相等两个串指针同时加, 剩余子串个数减一
                bp++;
                sp++;
                restSubSz--;
                if (!restSubSz) { // 如果为0代表子串已经搜索完了
                    return src;
                }
            } else { // 两个串内容不相等, 子串计数值重新开始
                restSubSz = subSize;
                break;
            }
        }

        src++;
        restScrSz--;
    }
    return NULL;
}

static void binFindStr(const std::vector<std::wstring>& files, const std::string& str)
{
    for (size_t i = 0; i < files.size(); ++i) {
        std::wstring path = files[i];
        std::vector<char> buffer;
        if (!common::readFile(path.c_str(), &buffer))
            DebugBreak();

        const char* find = memSrch(buffer.data(), buffer.size(), str.c_str(), str.size());
        if (find) {
            OutputDebugStringW(path.c_str());
            OutputDebugStringW(L"\n");
        }
    }
}

std::string trimString(const std::string& str)
{
    std::string s = str;
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return ch != ' '; //!std::isspace(ch);
    }));

    s.erase(std::find_if(s.rbegin(), s.rend(),
                [](int ch) {
                    return ch != ' '; //!std::isspace(ch);
                })
                .base(),
        s.end());

    return s;
}

uint64_t FILETIMEToINT64(const FILETIME& fileTime)
{
    DWORD dwHight = fileTime.dwHighDateTime;
    DWORD dwLow = fileTime.dwLowDateTime;
    uint64_t nValue, nTmp = 0;

    nTmp = dwHight;
    nValue = (nTmp << 32);
    nTmp = dwLow;

    nValue += nTmp;

    return nValue;
}

//-----

//-----

struct HeadFileToCppItem {
    std::string headFileName;
    FILETIME headFileTime;
    std::set<std::string> cpps;
};

class CompileInfo {
public:
    std::string m_cppcompiler;
    std::string m_ccompiler;
    std::string m_yasm;
    std::vector<std::string> m_includePaths;
    std::vector<std::string> m_srcPaths;
    std::vector<std::string> m_prebuildSrcPaths;
    std::vector<std::string> m_cmds;
    std::vector<std::string> m_asmCmds;
    std::string m_target;
    std::string m_objdir;
    std::string m_outdir;
    std::string m_linker;
    std::vector<std::string> m_linkerCmds;
    std::vector<std::string> m_beginLibs;
    std::vector<std::string> m_endLibs;
    std::vector<std::pair<std::string, std::string>> m_vars;

    mutable std::unique_ptr<std::unordered_map<uint32_t, HeadFileToCppItem>> m_hToCpp;
    bool m_isLib;

    CompileInfo() = default;
    CompileInfo(const CompileInfo&) = default;

    bool checkNeedLinkByTarget() const
    {
        std::string target = pathAppend(m_outdir, m_target);

        FILETIME targetTime;
        if (!getFileTime(target, &targetTime))
            return true;

        std::vector<std::string> errorFile;
        for (size_t i = 0; i < m_srcPaths.size(); ++i) {
            std::string objPath = pathAppend(m_objdir, fileNameToObjName(m_srcPaths[i], ".obj")); // obj文件

            FILETIME objTime;
            if (!getFileTime(objPath, &objTime))
                return true;

            if (timeAIsLongThenB(objTime, targetTime))
                return true;
        }
        return false;
    }

    bool doLink() const;

    std::string stringUnwindVal(const std::string& str) const
    {
        std::string ret = str;
        for (size_t i = 0; i < this->m_vars.size(); ++i) {
            std::pair<std::string, std::string> var = this->m_vars[i];
            std::string key = "${";
            key += var.first;
            key += "}";
            ret = stringReplaceAll(ret, key, var.second);
        }
        return ret;
    }

private:
    void changeLongPath(std::vector<std::string>* paths)
    {
        for (size_t i = 0; i < paths->size(); ++i) {
            std::string path = (*paths)[i];

            bool hasSpacing = false;
            for (size_t j = 0; j < path.size(); ++j) {
                if (' ' == path[j]) {
                    hasSpacing = true;
                    break;
                }
            }

            if (hasSpacing) {
                std::u16string pathW = content::utf8ToUtf16(path);

                std::vector<char16_t> pathBuf(300);
                memset(pathBuf.data(), 0, 300 * 2);
                memcpy(pathBuf.data(), pathW.c_str(), pathW.size() * 2);
                ::GetShortPathNameW((const WCHAR*)(pathW.c_str()), (WCHAR*)pathBuf.data(), pathW.size());

                pathW = pathBuf.data();
                path = content::utf16ToUtf8((const WCHAR*)pathW.c_str());
                (*paths)[i] = path;
            }
        }
    }

    bool parseStringVector(cJSON* parent, const char* name, bool reportErrorIfNeeded, std::vector<std::string>* out)
    {
        cJSON* item = cJSON_GetObjectItem(parent, name);
        if (!item || item->type != cJSON_Array) {
            if (!reportErrorIfNeeded)
                return false;
            OutputDebugStringA(name);
            OutputDebugStringW(L"解析出错\n");
            return false;
        }
        int itemSize = cJSON_GetArraySize(item);
        for (int i = 0; i < itemSize; ++i) {
            cJSON* it = cJSON_GetArrayItem(item, i);
            if (!it || it->type != cJSON_String) {
                if (!reportErrorIfNeeded)
                    return false;
                OutputDebugStringW(L"Item解析出错\n");
                return false;
            }
            out->push_back(this->stringUnwindVal(it->valuestring));
        }
        return true;
    }

    bool parseString(cJSON* parent, const char* name, std::string* out)
    {
        cJSON* item = cJSON_GetObjectItem(parent, name);
        if (!item || item->type != cJSON_String) {
            OutputDebugStringA(name);
            OutputDebugStringW(L"解析出错\n");
            return false;
        }
        *out = this->stringUnwindVal(item->valuestring);
        return true;
    }

public:
    bool parseJson(const std::wstring& path)
    {
        std::vector<char> buffer;
        common::readFile(path.c_str(), &buffer);
        buffer.push_back('\0');
        handleJsonComments(&buffer);

        cJSON* jsonRoot = nullptr;
        jsonRoot = cJSON_Parse(buffer.data());
        if (!jsonRoot) {
            OutputDebugStringW(L"顶层json解析出错\n");
            return false;
        }

        int ruleSize = cJSON_GetArraySize(jsonRoot);
        for (int i = 0; i < ruleSize; ++i) {
            cJSON* ruleRoot = cJSON_GetArrayItem(jsonRoot, i);
            if (!ruleRoot) {
                OutputDebugStringW(L"规则解析出错\n");
                return false;
            }

            cJSON* var = cJSON_GetObjectItem(ruleRoot, "var");
            if (var->type != cJSON_Array) {
                OutputDebugStringW(L"变量类型解析出错\n");
                return false;
            }
            int varSize = cJSON_GetArraySize(var);
            for (int j = 0; j < varSize; ++j) {
                cJSON* varItem = cJSON_GetArrayItem(var, j);
                cJSON* it = varItem->child;
                std::string key;
                std::string value;
                if (it->type == cJSON_String) {
                    key = it->string;
                    value = it->valuestring;
                    this->m_vars.push_back(std::pair<std::string, std::string>(key, value));
                }
            }

            cJSON* compile = cJSON_GetObjectItem(ruleRoot, "compile");

            cJSON* cppcompiler = cJSON_GetObjectItem(compile, "cppcompiler");
            if (cppcompiler && cppcompiler->type == cJSON_String)
                this->m_cppcompiler = this->stringUnwindVal(cppcompiler->valuestring);

            cJSON* ccompiler = cJSON_GetObjectItem(compile, "ccompiler");
            if (ccompiler && ccompiler->type == cJSON_String)
                this->m_ccompiler = this->stringUnwindVal(ccompiler->valuestring);

            cJSON* yasm = cJSON_GetObjectItem(compile, "yasm");
            if (yasm && yasm->type == cJSON_String)
                this->m_yasm = this->stringUnwindVal(yasm->valuestring);

            if (this->m_ccompiler.empty() && this->m_cppcompiler.empty()) {
                OutputDebugStringW(L"cppcompiler解析出错\n");
                return false;
            }

            if (!parseStringVector(compile, "include", true, &m_includePaths))
                return false;

            if (!parseStringVector(compile, "beginLibs", true, &m_beginLibs))
                return false;
            //changeLongPath(&m_beginLibs);

            if (!parseStringVector(compile, "endLibs", true, &m_endLibs))
                return false;
            //changeLongPath(&m_beginLibs);

            if (!parseStringVector(compile, "src", true, &m_srcPaths))
                return false;

            parseStringVector(compile, "prebuildSrc", false, &m_prebuildSrcPaths);

            if (!parseStringVector(compile, "cmd", true, &m_cmds))
                return false;

            if (!parseStringVector(compile, "linkerCmd", true, &m_linkerCmds))
                return false;

            parseStringVector(compile, "asmCmd", false, &m_asmCmds);

            if (!parseString(compile, "target", &m_target))
                return false;

            m_isLib = isEndWith(m_target, ".a") || isEndWith(m_target, ".lib");

            if (!parseString(compile, "linker", &m_linker))
                return false;

            if (!parseString(compile, "objdir", &m_objdir))
                return false;

            if (!parseString(compile, "outdir", &m_outdir))
                return false;
        }

        return true;
    }
};

class LinkInfo {
public:
    std::string m_objdir;
    std::string m_outdir;
    std::string m_target; // exp:1.exe
    std::vector<std::string> m_linkerCmds;
    std::vector<std::string> m_asmCmds;
    std::string m_linker;
    std::vector<std::string> m_beginLibs;
    std::vector<std::string> m_endLibs;

    struct FileDeps {
        std::string file;
        std::vector<std::string> deps;
    };

    std::map<uint32_t, FileDeps*> m_cppToDeps; // 一个cpp对应一堆头文件
    std::map<uint32_t, FileDeps*> m_depsToCpp; // 一个头文件对应一堆cpp

private:
    void addCppDeps(cJSON* root, const std::map<uint32_t, FileDeps*>& cppAndDeps, const char* parentName, const char* name1, const char* name2)
    {
        cJSON* cppToDeps = cJSON_CreateArray();
        for (std::map<uint32_t, FileDeps*>::const_iterator it = cppAndDeps.begin(); it != cppAndDeps.end(); ++it) {
            FileDeps* fileDeps = it->second;

            cJSON* item = cJSON_CreateObject();
            cJSON_AddItemToObjectCS(item, name1, cJSON_CreateString(fileDeps->file.c_str()));

            cJSON* deps = cJSON_CreateArray();
            for (size_t i = 0; i < fileDeps->deps.size(); ++i) {
                std::string dep = fileDeps->deps[i];
                cJSON_AddItemToArray(deps, cJSON_CreateString(dep.c_str()));
            }
            cJSON_AddItemToObjectCS(item, name2, deps);

            cJSON_AddItemToArray(cppToDeps, item);
        }
        cJSON_AddItemToObjectCS(root, parentName, cppToDeps);
    }

public:
    void saveToJson()
    {
        cJSON* root = cJSON_CreateObject();
        cJSON_AddItemToObjectCS(root, "objdir", cJSON_CreateString(m_objdir.c_str()));
        cJSON_AddItemToObjectCS(root, "outdir", cJSON_CreateString(m_outdir.c_str()));
        cJSON_AddItemToObjectCS(root, "target", cJSON_CreateString(m_target.c_str()));
        cJSON_AddItemToObjectCS(root, "linker", cJSON_CreateString(m_linker.c_str()));

        cJSON* beginLibs = cJSON_CreateArray();
        for (size_t i = 0; i < m_beginLibs.size(); ++i) {
            cJSON_AddItemToArray(beginLibs, cJSON_CreateString(m_beginLibs[i].c_str()));
        }
        cJSON_AddItemToObjectCS(root, "beginLibs", beginLibs);

        cJSON* endLibs = cJSON_CreateArray();
        for (size_t i = 0; i < m_endLibs.size(); ++i) {
            cJSON_AddItemToArray(endLibs, cJSON_CreateString(m_endLibs[i].c_str()));
        }
        cJSON_AddItemToObjectCS(root, "endLibs", endLibs);

        cJSON* linkerCmd = cJSON_CreateArray();
        for (size_t i = 0; i < m_linkerCmds.size(); ++i) {
            cJSON_AddItemToArray(linkerCmd, cJSON_CreateString(m_linkerCmds[i].c_str()));
        }
        cJSON_AddItemToObjectCS(root, "linkerCmd", linkerCmd);

        cJSON* asmCmd = cJSON_CreateArray();
        for (size_t i = 0; i < m_asmCmds.size(); ++i) {
            cJSON_AddItemToArray(asmCmd, cJSON_CreateString(m_asmCmds[i].c_str()));
        }
        cJSON_AddItemToObjectCS(root, "asmCmd", asmCmd);

        addCppDeps(root, m_cppToDeps, "cppToDeps", "cpp", "deps");
        addCppDeps(root, m_depsToCpp, "depsToCpp", "dep", "cpps");

        const char* json = cJSON_Print(root);
        std::vector<char> saveBuffer(strlen(json));
        strncpy(saveBuffer.data(), json, saveBuffer.size());

        std::string path = pathAppend(m_objdir, "link.json");
        common::writeFile((const WCHAR*)(content::utf8ToUtf16(path).c_str()), saveBuffer);
    }

    // 解析这种格式
    // cppToDeps": [{
    //    "cpp":"c:/1.cpp",
    //    "deps" : ["c:/1.h", "c:/2.h"]
    // }],
    bool jsonToDepsInfo(const cJSON* root, std::map<uint32_t, FileDeps*>* cppAndDeps, const char* name, const char* name1, const char* name2)
    {
        cJSON* cppAndDep = cJSON_GetObjectItem(root, name);
        if (!cppAndDep || cppAndDep->type != cJSON_Array) {
            OutputDebugStringW(L"cppAndDep解析出错\n");
            return false;
        }
        int cppToDepsSize = cJSON_GetArraySize(cppAndDep);
        for (int i = 0; i < cppToDepsSize; ++i) {
            cJSON* cppToDepsItem = cJSON_GetArrayItem(cppAndDep, i);

            cJSON* cpp = cJSON_GetObjectItem(cppToDepsItem, name1);
            if (!cpp || cpp->type != cJSON_String) {
                OutputDebugStringW(L"cpp解析出错\n");
                return false;
            }
            FileDeps* fileDeps = new FileDeps();
            fileDeps->file = cpp->valuestring;
            fileDeps->file = pathNormalizeAndToLow(fileDeps->file);
            uint32_t hash = strHash(fileDeps->file);

            cJSON* deps = cJSON_GetObjectItem(cppToDepsItem, name2);
            if (!deps || deps->type != cJSON_Array) {
                OutputDebugStringW(L"deps解析出错\n");
                return false;
            }

            int depsSize = cJSON_GetArraySize(deps);
            for (int j = 0; j < depsSize; ++j) {
                cJSON* item = cJSON_GetArrayItem(deps, j);
                if (item->type != cJSON_String) {
                    OutputDebugStringW(L"deps解析出错\n");
                    return false;
                }
                fileDeps->deps.push_back(item->valuestring);
            }

            cppAndDeps->insert(std::make_pair(hash, fileDeps));
        }

        return true;
    }

    bool initByJson(const std::u16string& path)
    {
        std::vector<char> buffer;
        if (!common::readFile((const WCHAR*)(path.c_str()), &buffer)) {
            OutputDebugStringW(L"link.json为空\n");
            return false;
        }
        buffer.push_back('\0');
        handleJsonComments(&buffer);

        cJSON* root = nullptr;
        root = cJSON_Parse(buffer.data());
        if (!root) {
            OutputDebugStringW(L"link.json的json解析出错\n");
            return false;
        }

        cJSON* objdir = cJSON_GetObjectItem(root, "objdir");
        if (objdir && objdir->type == cJSON_String)
            this->m_objdir = objdir->valuestring;

        cJSON* outdir = cJSON_GetObjectItem(root, "outdir");
        if (outdir && outdir->type == cJSON_String)
            this->m_outdir = outdir->valuestring;

        cJSON* target = cJSON_GetObjectItem(root, "target");
        if (target && target->type == cJSON_String)
            this->m_target = target->valuestring;

        cJSON* linkerCmd = cJSON_GetObjectItem(root, "linkerCmd");
        if (linkerCmd && linkerCmd->type == cJSON_Array) {
            int linkerCmdSize = cJSON_GetArraySize(linkerCmd);
            for (int i = 0; i < linkerCmdSize; ++i) {
                cJSON* it = cJSON_GetArrayItem(linkerCmd, i);
                if (target && it->type == cJSON_String)
                    this->m_linkerCmds.push_back(it->valuestring);
            }
        }

        cJSON* asmCmd = cJSON_GetObjectItem(root, "asmCmd");
        if (asmCmd && asmCmd->type == cJSON_Array) {
            int asmCmdSize = cJSON_GetArraySize(asmCmd);
            for (int i = 0; i < asmCmdSize; ++i) {
                cJSON* it = cJSON_GetArrayItem(asmCmd, i);
                if (target && it->type == cJSON_String)
                    this->m_asmCmds.push_back(it->valuestring);
            }
        }

        cJSON* libs = cJSON_GetObjectItem(root, "beginLibs");
        if (libs && libs->type == cJSON_Array) {
            int libsSize = cJSON_GetArraySize(libs);
            for (int i = 0; i < libsSize; ++i) {
                cJSON* it = cJSON_GetArrayItem(libs, i);
                if (target && it->type == cJSON_String)
                    this->m_beginLibs.push_back(it->valuestring);
            }
        }

        libs = cJSON_GetObjectItem(root, "endLibs");
        if (libs && libs->type == cJSON_Array) {
            int libsSize = cJSON_GetArraySize(libs);
            for (int i = 0; i < libsSize; ++i) {
                cJSON* it = cJSON_GetArrayItem(libs, i);
                if (target && it->type == cJSON_String)
                    this->m_endLibs.push_back(it->valuestring);
            }
        }

        jsonToDepsInfo(root, &m_cppToDeps, "cppToDeps", "cpp", "deps");
        jsonToDepsInfo(root, &m_depsToCpp, "depsToCpp", "dep", "cpps");
        return true;
    }

    // 同步cpp-deps那堆关系到dep-cpp
    void depsToCpp()
    {
        for (std::map<uint32_t, FileDeps*>::iterator it = m_cppToDeps.begin(); it != m_cppToDeps.end(); ++it) {
            FileDeps* fileDeps = it->second;

            for (size_t i = 0; i < fileDeps->deps.size(); ++i) {
                std::string headFile = fileDeps->deps[i];

                headFile = pathNormalizeAndToLow(headFile);
                uint32_t headFileHash = strHash(headFile);

                std::map<uint32_t, FileDeps*>::iterator j = m_depsToCpp.find(headFileHash);
                if (j == m_depsToCpp.end()) {
                    FileDeps* newFileDeps = new FileDeps();
                    newFileDeps->file = headFile;
                    newFileDeps->deps.push_back(fileDeps->file);
                    m_depsToCpp.insert(std::make_pair(headFileHash, newFileDeps));
                } else {
                    bool find = false;
                    for (size_t k = 0; k < j->second->deps.size(); ++k) {
                        std::string path = j->second->deps[k];
                        if (isPathEq(path, fileDeps->file)) {
                            find = true;
                            break;
                        }
                    }
                    if (!find) {
                        j->second->deps.push_back(fileDeps->file);
                    }
                }
            }
        }
    }
};

class CommandEventHandle {
public:
    std::string m_src;
    HRESULT m_state;
    CommandEventHandle()
    {
        m_state = S_OK;
    }

    static void replaceErrorInfoToMSBuilderFormat(std::string* str)
    {
        enum State {
            kNone,
            kFindFirst,
            kFindSecond,
        };
        State state = kNone;

        size_t pos1 = 0;
        size_t pos2 = 0;
        size_t pos3 = 0;
        for (size_t i = 0; i < str->size(); ++i) {
            char c = (*str)[i];
            if (kNone != state && (c < '0' || c > '9') && ':' != c) {
                state = kNone;
                continue;
            }
            if (':' == c) {
                if (kNone == state) {
                    pos1 = i;
                    state = kFindFirst;
                } else if (kFindFirst == state) {
                    pos2 = i;
                    state = kFindSecond;
                } else if (kFindSecond == state) {
                    pos3 = i;
                    (*str)[pos1] = '(';
                    (*str)[pos2] = ')';
                    for (size_t j = pos2 + 1; j < pos3; ++j) {
                        (*str)[j] = ':';
                    }
                    state = kNone;
                }
            }
        }
    }

    static void onCommandEvent(const CHCmdParam* pParam, HRESULT hResultCode, const char* szResult)
    {
        if (!szResult || !szResult[0])
            return;
        if (!pParam || hResultCode != S_OK)
            return;

        if (strlen(szResult) > 200000) {
            OutputDebugStringW(L"onCommandEvent 参数太长\n");
            common::writeFile((const WCHAR*)L"W:\\mycode\\mb108\\build\\testdll\\test\\16.txt", stdStringToBuffer(szResult));
            DebugBreak();
        }

        CommandEventHandle* self = (CommandEventHandle*)pParam->pUserData;

        std::string outStr = "----- begin src:";
        outStr += self->m_src;
        outStr += "\n";
        outStr += szResult;
        outStr += "\n";
        outStr += self->m_src;
        outStr += "----- end -------\n";
        replaceErrorInfoToMSBuilderFormat(&outStr);
        OutputDebugStringA(outStr.c_str());

        //common::writeFile((const WCHAR*)L"W:\\mycode\\mb108\\build\\testdll\\test\\16.txt", stdStringToBuffer(outStr));

        if (std::string::npos != outStr.find("error: ") || std::string::npos != outStr.find("FATAL:")) {
            OutputDebugStringW(L"检查到错误");
            printError("find error!!!\n");
            self->m_state = E_UNEXPECTED;
        }

        //     printf("============== 回调 ==============\n");
        //     std::string echo_data(szResult);
        //     std::string s_ok("S_OK");
        //     std::string::size_type pos = echo_data.find(s_ok);
        //     if (pos != std::string::npos)
        //         printf("命令执行成功\n");
        //     else
        //         printf("命令执行失败\n");
        //     printf("执行返回的结构:\n");
        //     printf("========================================\n");
        //     printf("%s\n", szResult);
    }
};

// 分析clang生成的D文件，变成依赖
static void parseDFile(const std::string& srcPath, const std::string& dPath, std::map<uint32_t, LinkInfo::FileDeps*>* cppToDeps)
{
    std::vector<char> buffer;
    common::readFile((const WCHAR*)(content::utf8ToUtf16(dPath).c_str()), &buffer);
    buffer.push_back('\0');

    LinkInfo::FileDeps* fileDeps = new LinkInfo::FileDeps();
    fileDeps->file = pathNormalizeAndToLow(srcPath);
    uint32_t hash = strHash(fileDeps->file);

    std::vector<std::string> lines = splitString(buffer.data(), '\n');
    if (lines.size() <= 1) {
        OutputDebugStringW(L"parseDFile is empty\n");
    } else {
        for (size_t i = 2; i < lines.size(); ++i) {
            std::string line = lines[i];
            if (line.size() <= 3)
                continue;

            std::string str;
            size_t posBegin = 0;
            size_t posEnd = line.size();
            if (line[0] == ' ' && line[1] == ' ')
                posBegin = 2;
            else
                DebugBreak();

            if (line[posEnd - 1] == '\r' && line[posEnd - 2] == '\\' && line[posEnd - 3] == ' ')
                posEnd -= 3;
            else if (line[posEnd - 1] == '\r')
                posEnd -= 1;
            else
                DebugBreak();
            str = line.substr(posBegin, posEnd - posBegin);
#if 0 // TODO：暂时不存这个东西了。因为头文件太多了，得想办法优化算法
            fileDeps->deps.push_back(pathNormalizeAndToLow(str));
#endif
        }
    }

    cppToDeps->insert(std::make_pair(hash, fileDeps));
}

struct BuildCppsThreadInfo {
    std::string cmd;
    std::string src;
    bool isEnd;

    HRESULT cmdResult;

    BuildCppsThreadInfo()
    {
        cmdResult = S_OK;
        isEnd = false;
    }

    static DWORD __stdcall run(void* param)
    {
        BuildCppsThreadInfo* self = (BuildCppsThreadInfo*)param;

        std::unique_ptr<CHCmdParam> cmdParam(new CHCmdParam());
        std::unique_ptr<CmdHandler> cmdHandler(new CmdHandler());
        cmdParam->iSize = sizeof(CHCmdParam);

        // 这里测试F磁盘Test目录下，命令格式为 cmd.exe /C + 命令
        // TCHAR* szCmd = L"cmd.exe /C dir F:\\Test&& echo S_OK || echo E_FAIL";
        std::wstring cmdW = (const WCHAR*)(content::utf8ToUtf16(self->cmd).c_str());
        if (cmdW.size() > MAX_CMD) {
            OutputDebugStringW(L"cmd 命令行太长\n");
            self->cmdResult = E_UNEXPECTED;
            self->isEnd = true;
            return false;
        }
        wcscpy(cmdParam->szCommand, cmdW.c_str());

        CommandEventHandle commandEventHandle;
        commandEventHandle.m_src = self->src;
        cmdParam->pUserData = &commandEventHandle;
        cmdParam->OnCmdEvent = &CommandEventHandle::onCommandEvent;
        cmdParam->iTimeOut = 3000;

        self->cmdResult = cmdHandler->Initalize();
        if (self->cmdResult != S_OK) {
            OutputDebugStringW(L"cmd handler 初始化失败\n");
            self->isEnd = true;
            return 0;
        }

        self->cmdResult = cmdHandler->HandleCommand(cmdParam.get());
        if (commandEventHandle.m_state < 0) {
            self->cmdResult = E_UNEXPECTED;
        } else {
            self->cmdResult = S_OK;
        }

        self->isEnd = true;
        return 0;
    }
};

// ${CLANG} -MD -MF G:/test/sln_test/firstlinux/testlinux/out/hello.d --target=x86_64-linux-guneabi ${INCL} -c hello.c hello2.c -o G:/test/sln_test/firstlinux/testlinux/out
bool buildCppsLinux(const CompileInfo& compileInfo, const std::vector<std::string>& needCompileCpps, LinkInfo* linkInfo)
{
    linkInfo->m_objdir = compileInfo.m_objdir;
    linkInfo->m_outdir = compileInfo.m_outdir;
    linkInfo->m_target = compileInfo.m_target;
    linkInfo->m_linkerCmds = compileInfo.m_linkerCmds;
    linkInfo->m_asmCmds = compileInfo.m_asmCmds;
    linkInfo->m_linker = compileInfo.m_linker;
    linkInfo->m_beginLibs = compileInfo.m_beginLibs;
    linkInfo->m_endLibs = compileInfo.m_endLibs;

    std::vector<std::string> errorFile;

    for (size_t j = 0; j < needCompileCpps.size(); j += kMaxThreadNum) {
        BuildCppsThreadInfo* infos[kMaxThreadNum] = { nullptr };
        for (size_t i = 0; i < kMaxThreadNum && i + j < needCompileCpps.size(); ++i) {
            infos[i] = new BuildCppsThreadInfo();

            std::string cmd;
            std::string src = needCompileCpps[j + i];

            bool isCpp = !isEndWith(src, ".c");
            if (!isCpp)
                cmd += pathNormalize(compileInfo.m_ccompiler);
            else
                cmd += pathNormalize(compileInfo.m_cppcompiler);
            cmd += " -MD -MF ";
            cmd += pathAppend(compileInfo.m_objdir, fileNameToObjName(src, ".d")); // 生成依赖文件
            cmd += " ";
            cmd += appendCmd(compileInfo.m_cmds, isCpp);
            cmd += " ";
            for (size_t i = 0; i < compileInfo.m_includePaths.size(); ++i) {
                cmd += "-I ";
                cmd += compileInfo.m_includePaths[i];
                cmd += " ";
            }
            cmd += " -c ";
            cmd += src;
            cmd += " -o ";
            cmd += pathAppend(compileInfo.m_objdir, fileNameToObjName(src, ".obj")); // obj文件
            infos[i]->src = src;
            infos[i]->cmd = cmd;

            std::vector<char> message(1000);
            sprintf_s(message.data(), 999, "fmBuild: %d, all:%d\n", j + i, needCompileCpps.size());
            OutputDebugStringA(message.data());

            DWORD threadId = 0;
            HANDLE threadHandle = CreateThread(0, 0, &BuildCppsThreadInfo::run, infos[i], 0, &threadId);
            ::CloseHandle(threadHandle);
        }

        bool needContiun = false;
        do {
            ::Sleep(10);
            needContiun = false;
            for (size_t i = 0; i < kMaxThreadNum && i + j < needCompileCpps.size(); ++i) {
                if (!infos[i])
                    continue;

                if (false == infos[i]->isEnd) {
                    needContiun = true;
                    break;
                } else {
                    std::string dFile = pathAppend(compileInfo.m_objdir, fileNameToObjName(infos[i]->src, ".d"));
                    if (infos[i]->cmdResult < 0) {
                        errorFile.push_back(infos[i]->src);
                        DebugBreak();
                        ::DeleteFileA(dFile.c_str());
                    } else
                        parseDFile(infos[i]->src, dFile, &(linkInfo->m_cppToDeps));

                    delete infos[i];
                    infos[i] = nullptr;
                }
            }
        } while (needContiun);
    }

    // TODO: 暂时不分析cpp对应的头文件依赖了。以后想好优化算法再说
#if 0
    linkInfo->depsToCpp();
#endif
    linkInfo->saveToJson();

    return true;
}

// yasm -I%(RootDir)%(Directory)\ -f win32 -DXX=1 -o $(IntDir)%(Filename).obj %(FullPath)
//
// clang-cl.exe /nologo /showIncludes:user "-imsvcC:\Program Files (x86)\Microsoft Visual" -D_HAS_NODISCARD
//   -I../../third_party/perfetto/include /Zc:inline /c ../../content/renderer/renderer_main.cc /Foobj/content/renderer/renderer/renderer_main.obj /Fd"obj/content/renderer/renderer_cc.pdb"
bool buildCppsWinCl(const CompileInfo& compileInfo, const std::vector<std::string>& needCompileCpps, LinkInfo* linkInfo)
{
    linkInfo->m_objdir = compileInfo.m_objdir;
    linkInfo->m_outdir = compileInfo.m_outdir;
    linkInfo->m_target = compileInfo.m_target;
    linkInfo->m_linkerCmds = compileInfo.m_linkerCmds;
    linkInfo->m_asmCmds = compileInfo.m_asmCmds;
    linkInfo->m_linker = compileInfo.m_linker;
    linkInfo->m_beginLibs = compileInfo.m_beginLibs;
    linkInfo->m_endLibs = compileInfo.m_endLibs;

    std::vector<std::string> errorFile;
    for (size_t j = 0; j < needCompileCpps.size(); j += kMaxThreadNum) {
        BuildCppsThreadInfo* infos[kMaxThreadNum] = { nullptr };
        for (size_t i = 0; i < kMaxThreadNum && i + j < needCompileCpps.size(); ++i) {
            infos[i] = new BuildCppsThreadInfo();

            std::string cmd;
            std::string src = needCompileCpps[j + i];

            bool isAsm = isEndWith(src, ".asm");
            if (isAsm) {
                cmd += pathNormalize(compileInfo.m_yasm);
                cmd += " ";
                cmd += appendCmd(compileInfo.m_asmCmds, false);
            } else {
                bool isCpp = !isEndWith(src, ".c");
                if (!isCpp)
                    cmd += pathNormalize(compileInfo.m_ccompiler);
                else
                    cmd += pathNormalize(compileInfo.m_cppcompiler);
                cmd += " /nologo ";
                cmd += appendCmd(compileInfo.m_cmds, isCpp);
            }
            cmd += " ";

            for (size_t i = 0; i < compileInfo.m_includePaths.size(); ++i) {
                cmd += "-I ";
                cmd += compileInfo.m_includePaths[i];
                cmd += " ";
            }

            if (!isAsm) {
                cmd += " -c ";
                cmd += src;
                cmd += " /Fo";
                cmd += pathAppend(compileInfo.m_objdir, fileNameToObjName(src, ".obj"));
            } else {
                cmd += " -o ";
                cmd += pathAppend(compileInfo.m_objdir, fileNameToObjName(src, ".obj"));
                cmd += " ";
                cmd += src;
            }
            infos[i]->src = src;
            infos[i]->cmd = cmd;

            std::vector<char> message(1000);
            sprintf_s(message.data(), 999, "fmBuild: %d, all:%d\n", j + i, needCompileCpps.size());
            OutputDebugStringA(message.data());

            DWORD threadId = 0;
            HANDLE threadHandle = CreateThread(0, 0, &BuildCppsThreadInfo::run, infos[i], 0, &threadId);
            ::CloseHandle(threadHandle);
        }

        bool needContiun = false;
        do {
            ::Sleep(10);
            needContiun = false;
            for (size_t i = 0; i < kMaxThreadNum && i + j < needCompileCpps.size(); ++i) {
                if (!infos[i])
                    continue;

                if (false == infos[i]->isEnd) {
                    needContiun = true;
                    break;
                } else {
                    std::string dFile = pathAppend(compileInfo.m_objdir, fileNameToObjName(infos[i]->src, ".d"));
                    if (infos[i]->cmdResult < 0) {
                        errorFile.push_back(infos[i]->src);
                        ::DeleteFileA(dFile.c_str());
                    } else
                        parseDFile(infos[i]->src, dFile, &(linkInfo->m_cppToDeps));

                    delete infos[i];
                    infos[i] = nullptr;
                }
            }
        } while (needContiun);
    }

    // TODO
    //     linkInfo->depsToCpp();
    //     linkInfo->saveToJson();

    return true;
}

bool buildCpps(const CompileInfo& compileInfo, const std::vector<std::string>& needCompileCpps, LinkInfo* linkInfo)
{
    if (g_isWin)
        return buildCppsWinCl(compileInfo, needCompileCpps, linkInfo);
    return buildCppsLinux(compileInfo, needCompileCpps, linkInfo);
}

bool rebuildAll(const CompileInfo& compileInfo, LinkInfo* linkInfo)
{
    return buildCpps(compileInfo, compileInfo.m_srcPaths, linkInfo);
}

bool parseVcxprojfilters()
{
    std::vector<char> buffer;
    common::readFile(L"p:\\mycode\\miniblink57\\fastmake\\build.txt", &buffer);
    buffer.push_back('\0');

    std::string str(buffer.data());
    std::vector<std::string> lines = splitString(str, '\n');
    for (size_t i = 0; i < lines.size(); ++i) {
        std::string line = lines[i];
        if (std::string::npos == line.find(".cpp\"") && std::string::npos == line.find(".c\"") && std::string::npos == line.find(".cc\""))
            continue;

        line += "\n";
        OutputDebugStringA(line.c_str());
    }
    return true;
}

// 根据obj的时间、cpp的时间、h的时间，确定有多少cpp需要编译
static std::vector<std::string> computeHowMuchNeedCompileByObj(const LinkInfo& linkInfo)
{
    std::set<std::string> ret;

    // cpp和obj对比；h找到对应的cpp，再找cpp对应的obj对比。
    for (std::map<uint32_t, LinkInfo::FileDeps*>::const_iterator it = linkInfo.m_cppToDeps.begin(); it != linkInfo.m_cppToDeps.end(); ++it) {
        LinkInfo::FileDeps* fileDeps = it->second;
        std::string cppPathName = fileDeps->file;
        std::string objPathName = pathAppend(linkInfo.m_objdir, fileNameToObjName(cppPathName, ".obj"));

        FILETIME cppTime;
        if (!getFileTime(cppPathName, &cppTime))
            DebugBreak();

        FILETIME objTime;
        if (!getFileTime(objPathName.c_str(), &objTime) || timeAIsLongThenB(cppTime, objTime)) {
            ret.insert(pathNormalizeAndToLow(cppPathName));
        }
    }

    for (std::map<uint32_t, LinkInfo::FileDeps*>::const_iterator it = linkInfo.m_depsToCpp.begin(); it != linkInfo.m_depsToCpp.end(); ++it) {
        LinkInfo::FileDeps* fileDeps = it->second;
        std::string headPathName = fileDeps->file;
        FILETIME headTime;
        if (!getFileTime(headPathName, &headTime))
            DebugBreak();

        for (size_t i = 0; i < fileDeps->deps.size(); ++i) {
            std::string cppPathName = fileDeps->deps[i];
            std::string objPathName = pathAppend(linkInfo.m_objdir, fileNameToObjName(cppPathName, ".obj"));

            FILETIME cppTime;
            if (!getFileTime(cppPathName, &cppTime))
                DebugBreak();

            FILETIME objTime;
            if (!getFileTime(objPathName, &objTime) || timeAIsLongThenB(headTime, objTime)) {
                ret.insert(pathNormalizeAndToLow(cppPathName));
            }
        }
    }

    std::vector<std::string> result;
    for (std::set<std::string>::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        std::string str = *it;
        result.push_back(str);
    }

    return result;
}

enum ComputeDiffResult {
    kComputeDiffResultRebuildAndLink,
    kComputeDiffResultBuildAndLink,
    kComputeDiffResultNotBuildButLink,
    kComputeDiffResultNone,
};

static bool isDifferentStringVector(const std::vector<std::string>& a, std::vector<std::string> b, bool isPath)
{
    for (size_t i = 0; i < a.size(); ++i) {
        std::string aCmd = a[i];
        bool find = false;
        for (size_t j = 0; j < b.size(); ++j) {
            std::string bCmd = b[j];
            if (!isPathEq(aCmd, bCmd)) {
                find = true;
                break;
            }
        }
        if (find)
            return true;
    }
    return false;
}

// 对比link.json看哪些文件是多出来的，哪些是被删掉的。返回值表示是否需要rebuild
ComputeDiffResult computeNeedBuildAndLink(const CompileInfo& compileInfo, const LinkInfo& linkInfo)
{
    bool needLink = false;
    if (!isPathEq(compileInfo.m_objdir, linkInfo.m_objdir))
        return kComputeDiffResultRebuildAndLink;

    if (isDifferentStringVector(compileInfo.m_asmCmds, linkInfo.m_asmCmds, true))
        return kComputeDiffResultRebuildAndLink;

    // 如果是link命令行变了，可以不用rebuild
    if (isDifferentStringVector(compileInfo.m_linkerCmds, linkInfo.m_linkerCmds, true))
        return kComputeDiffResultBuildAndLink;

    if (compileInfo.m_linkerCmds.size() != linkInfo.m_linkerCmds.size())
        return kComputeDiffResultBuildAndLink;

    if (!isPathEq(compileInfo.m_outdir, linkInfo.m_outdir) || !isPathEq(compileInfo.m_target, linkInfo.m_target)
        || !isPathEq(compileInfo.m_linker, linkInfo.m_linker))
        return kComputeDiffResultNotBuildButLink;

    if (isDifferentStringVector(compileInfo.m_beginLibs, linkInfo.m_beginLibs, true))
        return kComputeDiffResultNotBuildButLink;

    if (isDifferentStringVector(compileInfo.m_endLibs, linkInfo.m_endLibs, true))
        return kComputeDiffResultNotBuildButLink;

    return kComputeDiffResultNone;
}

static void stringVecToHashMap(const std::vector<std::string>& paths, std::map<uint32_t, std::string>* hashMap)
{
    hashMap->clear();
    for (size_t i = 0; i < paths.size(); ++i) {
        std::string path = pathNormalizeAndToLow(paths[i]);
        uint32_t hash = strHash(path);

        hashMap->insert(std::make_pair(hash, path));
    }
}

static void hashMapToStringVec(const std::map<uint32_t, std::string>& hashMap, std::vector<std::string>* paths)
{
    paths->clear();
    std::map<uint32_t, std::string>::const_iterator it = hashMap.begin();
    for (; it != hashMap.end(); ++it) {
        paths->push_back(it->second);
    }
}

// 通过新compileInfo和老linkInfo对比，计算出新增了哪些cpp，删除了哪些cpp
ComputeDiffResult computeDiffOfBuildAndLinkJson(
    const CompileInfo& compileInfo, const LinkInfo& linkInfo, std::map<uint32_t, std::string>* adds, std::map<uint32_t, std::string>* removes)
{
    std::map<uint32_t, LinkInfo::FileDeps*> cppToDeps = linkInfo.m_cppToDeps; // 拷贝出来一份

    for (size_t i = 0; i < compileInfo.m_srcPaths.size(); ++i) {
        std::string src = compileInfo.m_srcPaths[i];
        src = pathNormalizeAndToLow(src);
        uint32_t hash = strHash(src);
        std::map<uint32_t, LinkInfo::FileDeps*>::iterator it = cppToDeps.find(hash);
        if (it == cppToDeps.end()) {
            adds->insert(std::make_pair(hash, src));
        } else {
            cppToDeps.erase(it);
        }
    }

    for (std::map<uint32_t, LinkInfo::FileDeps*>::const_iterator it = cppToDeps.begin(); it != cppToDeps.end(); ++it) {
        LinkInfo::FileDeps* fileDeps = it->second;
        std::string file = pathNormalizeAndToLow(fileDeps->file);
        uint32_t hash = strHash(file);

        removes->insert(std::make_pair(hash, file));
    }

    ComputeDiffResult result = computeNeedBuildAndLink(compileInfo, linkInfo);
    return result;
}

// 在cpps里增加adds的，并且排除removevs的字符串
static void diffCompileCpps(std::vector<std::string>* cpps, const std::map<uint32_t, std::string>& adds, const std::map<uint32_t, std::string>& removes)
{
    std::vector<std::string> addsWithoutRepeat;

    std::map<uint32_t, std::string> cppsMap;
    stringVecToHashMap(*cpps, &cppsMap);
    std::map<uint32_t, std::string>::const_iterator it = adds.begin();
    for (; it != adds.end(); ++it) {
        if (cppsMap.find(it->first) == cppsMap.end()) {
            cpps->push_back(it->second);
        }
    }

    stringVecToHashMap(*cpps, &cppsMap);
    it = removes.begin();
    for (; it != removes.end(); ++it) {
        if (cppsMap.find(it->first) == cppsMap.end()) {
            cppsMap.erase(it->first);
        }
    }
    hashMapToStringVec(cppsMap, cpps);
}

static void printIncCompileCpp(const std::vector<std::string>& needCompileCpps)
{
    OutputDebugStringW(L"增量编译：\n");
    for (size_t i = 0; i < needCompileCpps.size(); ++i) {
        std::string cpp = "  ";
        cpp += needCompileCpps[i];
        cpp += '\n';
        OutputDebugStringA(cpp.c_str());
    }
}

bool CompileInfo::doLink() const
{
    std::string cmd;

    std::string targetFullPath = pathAppend(m_outdir, m_target);
    ::DeleteFileA(targetFullPath.c_str());

    if (m_isLib) {
        cmd += " -s -q ";
        cmd += targetFullPath;
        cmd += ' ';

        for (size_t i = 0; i < m_srcPaths.size(); ++i) {
            cmd += pathAppend(m_objdir, fileNameToObjName(m_srcPaths[i], ".obj"));
            cmd += ' ';
        }
    } else if (!g_isWin) {
        cmd += " -o ";
        cmd += targetFullPath;
        cmd += ' ';

        for (size_t i = 0; i < m_linkerCmds.size(); ++i) {
            cmd += m_linkerCmds[i];
            cmd += ' ';
        }

        for (size_t i = 0; i < m_beginLibs.size(); ++i) {
            cmd += m_beginLibs[i];
            cmd += ' ';
        }

        for (size_t i = 0; i < m_srcPaths.size(); ++i) {
            cmd += pathAppend(m_objdir, fileNameToObjName(m_srcPaths[i], ".obj"));
            cmd += ' ';
        }

        cmd += "--start-group ";
        for (size_t i = 0; i < m_endLibs.size(); ++i) {
            cmd += m_endLibs[i];
            cmd += ' ';
        }
        cmd += "--end-group ";
    } else if (g_isWin) {
        for (size_t i = 0; i < m_linkerCmds.size(); ++i) {
            cmd += m_linkerCmds[i];
            cmd += ' ';
        }

        for (size_t i = 0; i < m_beginLibs.size(); ++i) {
            //cmd += "-defaultlib:";
            cmd += "\"";
            cmd += m_beginLibs[i];
            cmd += "\" ";
        }

        cmd += " /OUT:";
        cmd += targetFullPath;
        cmd += ' ';

        for (size_t i = 0; i < m_srcPaths.size(); ++i) {
            cmd += pathAppend(m_objdir, fileNameToObjName(m_srcPaths[i], ".obj"));
            cmd += ' ';
        }
    } else {
        DebugBreak();
    }

    std::string resposeFile = pathAppend(m_outdir, m_target + "_resposeFile.txt");
    resposeFile = pathNormalizeAndToLow(resposeFile);
    std::u16string resposeFileW = content::utf8ToUtf16(resposeFile);
    ::DeleteFileW((const WCHAR*)resposeFileW.c_str());
    common::writeFile((const WCHAR*)resposeFileW.c_str(), stdStringToBuffer(cmd));

    std::unique_ptr<CHCmdParam> cmdParam(new CHCmdParam());
    std::unique_ptr<CmdHandler> cmdHandler(new CmdHandler());
    cmdParam->iSize = sizeof(CHCmdParam);

    HRESULT cmdResult = S_OK;

    if (resposeFileW.size() > MAX_CMD) {
        OutputDebugStringW(L"cmd 命令行太长\n");
        return false;
    }

    std::string linkCmd = m_linker + " @" + resposeFile;
    //     if (m_isLib) {
    //         linkCmd = m_linker + " -s @" + resposeFile; //-s参数是arm模式下用的，相当于调用ranlib.exe
    //     }

    std::u16string cmdW = content::utf8ToUtf16(linkCmd);
    wcscpy(cmdParam->szCommand, (const WCHAR*)cmdW.c_str());
    OutputDebugStringA("doLink:");
    OutputDebugStringA(m_target.c_str());
    OutputDebugStringA("\n");

    CommandEventHandle commandEventHandle;
    commandEventHandle.m_src = m_target;
    cmdParam->pUserData = &commandEventHandle;
    cmdParam->OnCmdEvent = &CommandEventHandle::onCommandEvent;
    cmdParam->iTimeOut = 3000;

    cmdResult = cmdHandler->Initalize();
    if (cmdResult != S_OK) {
        OutputDebugStringW(L"cmd handler 初始化失败\n");
        return false;
    }

    cmdResult = cmdHandler->HandleCommand(cmdParam.get());
    if (cmdResult != S_OK)
        DebugBreak();
    return true;
}

const char* kCppDepsFileName = "cpp_deps.txt";

class CollectTimeoutFiles {
private:
    SRWLOCK m_collectResultSrw;
    std::set<std::string> m_result;
    const CompileInfo& m_compileInfo;

    SRWLOCK m_fileTimesSrw;
    std::unordered_map<uint32_t, std::pair<std::string, FILETIME>> m_fileTimes;

    int m_currentThreadCount = 0;

    std::unordered_map<uint32_t, HeadFileToCppItem>* m_hToCpp; // 头文件对应的cpp有哪些
    SRWLOCK m_hToCppSrw;

    bool m_isNeedCreateCppDeps = false;

public:
    CollectTimeoutFiles(const CompileInfo& compileInfo)
        : m_compileInfo(compileInfo)
    {
        InitializeSRWLock(&m_collectResultSrw);
        InitializeSRWLock(&m_fileTimesSrw);
        InitializeSRWLock(&m_hToCppSrw);

        m_isNeedCreateCppDeps = m_compileInfo.m_hToCpp.get() ? m_compileInfo.m_hToCpp->empty() : true;

        if (m_isNeedCreateCppDeps) {
            m_compileInfo.m_hToCpp.reset(new std::unordered_map<uint32_t, HeadFileToCppItem>());
            m_hToCpp = m_compileInfo.m_hToCpp.get();

            std::string cppDepsFileNamePath = pathAppend(m_compileInfo.m_objdir, kCppDepsFileName);
            cppDepsFileNamePath = pathNormalizeAndToLow(cppDepsFileNamePath);

            std::vector<char> buffer;
            common::readFile((const WCHAR*)(content::utf8ToUtf16(cppDepsFileNamePath).c_str()), &buffer);
            buffer.push_back('\0');

            deserialization(std::string(buffer.data(), buffer.size()));
        } else
            m_hToCpp = m_compileInfo.m_hToCpp.get();

        m_isNeedCreateCppDeps = m_compileInfo.m_hToCpp.get() ? m_compileInfo.m_hToCpp->empty() : false; // 再判断一次
        m_isNeedCreateCppDeps = true; // 强制执行
    }

    // 把m_hToCpp序列化，方便写入文件
    void serializeToFile() const
    {
        std::string serializeContent = serialize();

        std::string cppDepsFileNamePath = pathAppend(m_compileInfo.m_objdir, kCppDepsFileName);
        cppDepsFileNamePath = pathNormalizeAndToLow(cppDepsFileNamePath);
        std::vector<char> buffer;
        buffer.resize(serializeContent.size());
        memcpy(buffer.data(), serializeContent.c_str(), buffer.size());

        common::writeFile((const WCHAR*)(content::utf8ToUtf16(cppDepsFileNamePath).c_str()), buffer);
    }

    std::string serialize() const
    {
        // name \r headFileTime
        // \r cpp[0]
        // \r cpp[1]
        std::string result;
        for (std::unordered_map<uint32_t, HeadFileToCppItem>::const_iterator it = m_hToCpp->begin(); it != m_hToCpp->end(); ++it) {
            const HeadFileToCppItem& item = it->second;
            result += item.headFileName;
            result += "\t";

            uint64_t time = FILETIMEToINT64(item.headFileTime);
            char temp[100] = { 0 };
            sprintf_s(temp, 99, "%llu\n", time);

            result += temp;

            for (std::set<std::string>::const_iterator it2 = item.cpps.begin(); it2 != item.cpps.end(); ++it2) {
                const std::string& str = *it2;
                result += "\t";
                result += str;
                result += "\n";
            }
        }
        return result;
    }

    // 从文件读取，把m_hToCpp反序列化
    bool deserialization(const std::string& fileContent)
    {
        std::vector<std::string> lines = splitString(fileContent.data(), '\n');
        if (lines.size() <= 1) {
            OutputDebugStringW(L"HeadFileToCpp is empty\n");
            return false;
        }

        std::unique_ptr<HeadFileToCppItem> item;
        for (size_t i = 0; i < lines.size(); ++i) {
            std::string line = lines[i];
            if (line.size() <= 3)
                continue;
            if ('\t' != line[0]) {
                if (item.get() && !item->cpps.empty())
                    m_hToCpp->insert(std::make_pair(strHash(item->headFileName), *(item.get())));

                item.reset(new HeadFileToCppItem());

                std::vector<std::string> nameAndTime = splitString(line, '\t');
                if (nameAndTime.size() != 2)
                    continue;

                item->headFileName = nameAndTime[0];

                char* pEnd;
                uint64_t ui64 = strtoull(nameAndTime[1].c_str(), &pEnd, 16);
                item->headFileTime.dwHighDateTime = (ui64 & 0xffffffff00000000) >> 32;
                item->headFileTime.dwLowDateTime = (ui64 & 0xffffffff);
            } else {
                item->cpps.insert(line.substr(1));
            }
        }
        if (item.get() && !item->cpps.empty())
            m_hToCpp->insert(std::make_pair(strHash(item->headFileName), *(item.get())));

        return true;
    }

    // W:/mycode/mb108/url/url_util.h W:/mycode/mb108/url/url_constants.h w:/1.c
    static std::vector<std::string> splitHeadLine(const std::string& line)
    {
        std::vector<std::string> result;
        size_t posA = 0;
        bool isFirstHeadFile = true;
        int count = 0;
        for (size_t i = 0; i < line.size(); ++i) {
            std::string str;

            if (line[i] == ':')
                count++;

            if (line[i] == ':' || i == line.size() - 1) {
                if (!isFirstHeadFile) {
                    if (i == line.size() - 1)
                        str = line.substr(posA, i - posA + 1);
                    else
                        str = line.substr(posA, i - 1 - posA);
                    str = trimString(str);
                    posA = i - 1;
                    result.push_back(str);
                }
                isFirstHeadFile = false;
            }
        }
        if (result.empty())
            result.push_back(line);
        return result;
    }

private:
    // 分析D文件，变成头文件和对应的编译时间，并判断此cpp文件是否需要编译
    bool parseDFileAndCheckNeedBuild(const std::string& srcPath, const std::string& dPath, const FILETIME& objTime)
    {
        std::vector<char> buffer;
        common::readFile((const WCHAR*)(content::utf8ToUtf16(dPath).c_str()), &buffer);
        buffer.push_back('\0');

        std::vector<std::string> lines = splitString(buffer.data(), '\n');
        if (lines.size() <= 1) {
            OutputDebugStringW(L"parseDFile is empty\n");
            return false;
        }

        bool isNeedBuild = false;
        for (size_t i = 2; i < lines.size(); ++i) {
            std::string line = lines[i];
            if (line.size() <= 3)
                continue;

            std::string str;
            size_t posBegin = 0;
            size_t posEnd = line.size();
            if (line[0] == ' ' && line[1] == ' ')
                posBegin = 2;
            else
                DebugBreak();

            if (line[posEnd - 1] == '\r' && line[posEnd - 2] == '\\' && line[posEnd - 3] == ' ')
                posEnd -= 3;
            else if (line[posEnd - 1] == '\r')
                posEnd -= 1;
            else
                DebugBreak();
            str = line.substr(posBegin, posEnd - posBegin);
            str = pathNormalizeAndToLow(str);

            // 拆开形如W:/mycode/mb108/url/url_util.h W:/mycode/mb108/url/url_constants.h
            std::vector<std::string> strs = splitHeadLine(str);
            for (size_t i = 0; i < strs.size(); ++i) {
                std::string strLine = strs[i];

                uint32_t hash = strHash(strLine);
                ::AcquireSRWLockShared(&m_fileTimesSrw);
                std::unordered_map<uint32_t, std::pair<std::string, FILETIME>>::const_iterator it = m_fileTimes.find(hash);
                if (it != m_fileTimes.end()) {
                    ::ReleaseSRWLockShared(&m_fileTimesSrw);
                    if (timeAIsLongThenB(it->second.second, objTime))
                        isNeedBuild = true;
                    continue;
                }
                ::ReleaseSRWLockShared(&m_fileTimesSrw);

                FILETIME headFileTime = kMaxFileTime;
                if (!getFileTime(strLine, &headFileTime))
                    continue;

                if (timeAIsLongThenB(headFileTime, objTime))
                    isNeedBuild = true;

                genHeadFileToCpp(srcPath, strLine, headFileTime, hash);

                //if (std::string::npos != strLine.find("build\\build_config.h"))
                //    OutputDebugStringA("");

                ::AcquireSRWLockExclusive(&m_fileTimesSrw);
                m_fileTimes.insert(std::make_pair(hash, std::make_pair(strLine, headFileTime)));
                ::ReleaseSRWLockExclusive(&m_fileTimesSrw);
            }
        }
        return isNeedBuild;
    }

    void genHeadFileToCpp(const std::string& cppPath, const std::string& headFileName, const FILETIME& headFileTime, uint32_t hash)
    {
        ::AcquireSRWLockShared(&m_hToCppSrw);
        std::unordered_map<uint32_t, HeadFileToCppItem>::iterator hIt = m_hToCpp->find(hash);
        if (hIt == m_hToCpp->end()) {
            ::ReleaseSRWLockShared(&m_hToCppSrw);
            HeadFileToCppItem item;
            item.headFileName = pathNormalizeAndToLow(headFileName);
            item.headFileTime = headFileTime;
            item.cpps.insert(cppPath);
            ::AcquireSRWLockExclusive(&m_hToCppSrw);
            m_hToCpp->insert(std::make_pair(hash, item));
            ::ReleaseSRWLockExclusive(&m_hToCppSrw);
        } else {
            ::ReleaseSRWLockShared(&m_hToCppSrw);

            ::AcquireSRWLockExclusive(&m_hToCppSrw);
            hIt->second.cpps.insert(cppPath);
            ::ReleaseSRWLockExclusive(&m_hToCppSrw);
        }
    }

    struct ThreadInfo {
        CollectTimeoutFiles* self;
        std::vector<std::string> paths;
    };

    static DWORD __stdcall collect(void* param)
    {
        ThreadInfo* info = (ThreadInfo*)param;

        for (size_t i = 0; i < info->paths.size(); ++i) {
            const std::string path = info->paths[i];
            bool b = info->self->collectImpl(path);

            if (b) {
                AcquireSRWLockExclusive(&info->self->m_collectResultSrw);
                info->self->m_result.insert(path);
                ReleaseSRWLockExclusive(&info->self->m_collectResultSrw);
            }

            _InterlockedDecrement((long volatile*)&(info->self->m_currentThreadCount));
        }

        delete info;
        return 0;
    }

    bool collectImpl(const std::string& path)
    {
        std::string objPath = pathAppend(m_compileInfo.m_objdir, fileNameToObjName(path, ".obj")); // obj文件
        objPath = pathNormalizeAndToLow(objPath);

        if (std::string::npos != path.find("WebLocalFrameClientImpl.cpp"))
            OutputDebugStringA("");

        bool b = false;
        FILETIME objTime;
        do {
            FILETIME cppTime;
            if (!getFileTime(path, &cppTime)) {
                b = true;
                DebugBreak();
                break;
            }

            if (!getFileTime(objPath, &objTime)) {
                objTime = cppTime;
                b = true;
                break;
            }

            if (timeAIsLongThenB(cppTime, objTime)) {
                b = true;
                break;
            }
        } while (false);

        if (m_isNeedCreateCppDeps || b) { // 下面是查头文件是否被修改的，速度有点慢
            SYSTEMTIME time1;
            ::GetLocalTime(&time1);
            uint64_t timelong1 = time1.wHour * 60 * 60 * 1000 + time1.wMinute * 60 * 1000 + time1.wSecond * 1000 + time1.wMilliseconds;

            std::string dFile = pathNormalizeAndToLow(pathAppend(m_compileInfo.m_objdir, fileNameToObjName(path, ".d")));
            b |= (parseDFileAndCheckNeedBuild(path, dFile, objTime));

            SYSTEMTIME time2;
            ::GetLocalTime(&time2);
            uint64_t timelong2 = time2.wHour * 60 * 60 * 1000 + time2.wMinute * 60 * 1000 + time2.wSecond * 1000 + time2.wMilliseconds;

            if (1 == m_currentThreadCount % 51) {
                char* output = (char*)malloc(400);
                sprintf_s(output, 399, "collectTimeoutFiles: Count:%d, time:%lld, %s\n", m_currentThreadCount, (timelong2 - timelong1), path.c_str());
                OutputDebugStringA(output);
                free(output);
            }
        }

        return b;
    }

    // 查找头文件里有哪些文件过时了，根据依赖文件
    bool collectHeadFileTimeout()
    {
#if 0
        std::string result;
        for (std::unordered_map<uint32_t, HeadFileToCppItem>::const_iterator it = m_hToCpp->begin(); it != m_hToCpp->end(); ++it) {
            const HeadFileToCppItem& item = it->second;
            FILETIME nowHeadFileTime;
            if (!getFileTime(item.headFileName, &nowHeadFileTime)) {
                continue;
            }

            if (!timeAIsLongThenB(nowHeadFileTime, item.headFileTime)) {
                for (std::set<std::string>::const_iterator it2 = item.cpps.begin(); it2 != item.cpps.end(); ++it2) {
                    const std::string& str = *it2;
                    m_result.insert(str);
                }
            }
        }
        return true;
#else
        return false;
#endif
    }

public:
    std::set<std::string> run()
    {
        // 1，先看.obj文件是否比cpp新，如果是的话，加到编译列表。如果没有obj也加
        // 2，再看.d文件里的头文件是否有比cpp新。如果是的话，加到编译列表
        size_t allNum = m_compileInfo.m_srcPaths.size();
        m_currentThreadCount = allNum;

        ThreadInfo* infos[kMaxThreadNum] = { 0 };
        for (size_t i = 0; i < kMaxThreadNum; ++i) {
            ThreadInfo* info = new ThreadInfo();
            info->self = this;
            infos[i] = info;
        }

        for (size_t i = 0; i < allNum; ++i) {
            int index = i % kMaxThreadNum;
            ThreadInfo* info = infos[index];
            info->paths.push_back(m_compileInfo.m_srcPaths[i]);
        }

        for (size_t i = 0; i < kMaxThreadNum; ++i) {
            DWORD threadId = 0;
            ThreadInfo* info = infos[i];
            HANDLE threadHandle = ::CreateThread(0, 0, &collect, info, 0, &threadId);
            ::CloseHandle(threadHandle);
        }

        while (m_currentThreadCount != 0) {
            Sleep(10);
        }

        collectHeadFileTimeout();

        // 序列化并存储
        serializeToFile();

        return m_result;
    }
};

// 1、如果没有link.json文件，则rebuild，并生成link.json
// 2、对比*_build.json和link.json文件，如果build比link.json新，重新生成link.json，并且对比下要多编译哪几个文件，少编译哪个文件
// 3、如果link.json文件没有更新，则查找link.json里面哪些cpp时间比obj新，说明需要重新编译
// 4、如果*_build.json里的命令行变化了，要rebuild
void fmBuild(const std::wstring& buildJsonPath)
{
    CompileInfo* compileInfo = new CompileInfo();
    if (!compileInfo->parseJson(buildJsonPath))
        return;

    LinkInfo linkInfo;
    LinkInfo newLinkInfo;
    FILETIME buildJsonTime;
    FILETIME linkJsonTime;

    if (!getFileTime(content::utf16ToUtf8(buildJsonPath.c_str()), &buildJsonTime))
        DebugBreak();

    bool needLink = false;
    do {
        std::string linkJson = pathAppend(compileInfo->m_objdir, "link.json");
        std::u16string linkJsonW = content::utf8ToUtf16(pathNormalize(linkJson));
        if (!linkInfo.initByJson(linkJsonW)) {
            rebuildAll(*compileInfo, &newLinkInfo);
            needLink = true;
            break;
        }

        if (!getFileTime(linkJson, &linkJsonTime)) {
            rebuildAll(*compileInfo, &newLinkInfo);
            needLink = true;
            break;
        }

        // 根据link.json里，obj的时间，和c、h文件对比看哪些文件是需要编译的
        std::vector<std::string> needCompileCpps = computeHowMuchNeedCompileByObj(linkInfo);
        ComputeDiffResult diffResult = kComputeDiffResultNone;
        if (timeAIsLongThenB(buildJsonTime, linkJsonTime)) { // 上次生成的link.json的时间如果比xxx_build.json时间旧，则需要计算xxx_build.json有什么新文件要编译
            // 如果build.json有更新
            // 看哪些文件是多出来的，哪些是被删掉的
            std::map<uint32_t, std::string> adds;
            std::map<uint32_t, std::string> removes;
            diffResult = computeDiffOfBuildAndLinkJson(*compileInfo, linkInfo, &adds, &removes);
            if (kComputeDiffResultRebuildAndLink == diffResult) {
                rebuildAll(*compileInfo, &newLinkInfo);
                needLink = true;
                ;
                break;
            }
            diffCompileCpps(&needCompileCpps, adds, removes);
        }

        if (needCompileCpps.size() > 0) {
            needLink = true;
            printIncCompileCpp(needCompileCpps);
            buildCpps(*compileInfo, needCompileCpps, &linkInfo);
        }
        if (kComputeDiffResultNone != diffResult)
            needLink = true;

        // TODO：如果有*.o文件的时间比exe晚，就要link一次
        if (compileInfo->checkNeedLinkByTarget())
            needLink = true;
    } while (false);

    if (needLink) {
        compileInfo->doLink();
    }
    delete compileInfo;
}

bool buildTimoutCpps(const CompileInfo& compileInfo, LinkInfo* linkInfo)
{
    CollectTimeoutFiles collectTimeoutFiles(compileInfo);
    std::set<std::string> cpps = collectTimeoutFiles.run();

    std::vector<std::string> cppsVec;
    for (std::set<std::string>::const_iterator it = cpps.begin(); it != cpps.end(); ++it) {
        cppsVec.push_back(*it);
    }

    char* output = (char*)malloc(400);
    sprintf_s(output, 399, "buildTimoutCpps: Count:%d\n", cppsVec.size());
    OutputDebugStringA(output);
    free(output);

    return buildCpps(compileInfo, cppsVec, linkInfo);
}

void fmFastBuild(const std::wstring& buildJsonPath, RebuildOpt opt)
{
    CompileInfo* compileInfo = new CompileInfo();
    if (!compileInfo->parseJson(buildJsonPath)) {
        delete compileInfo;
        return;
    }

    LinkInfo linkInfo;
    if (kRebuildOptAll == opt) {
        rebuildAll(*compileInfo, &linkInfo);
    } else if (kRebuildOptPrebuildSrcAndLink == opt) {
        buildCpps(*compileInfo, compileInfo->m_prebuildSrcPaths, &linkInfo);
    } else if (kRebuildOptOnlyLink == opt) {
        ;
    } else if (kRebuildOptCompileTimeOutFile == opt) { // 编译过期文件
        buildTimoutCpps(*compileInfo, &linkInfo);
    }

    compileInfo->doLink();
    delete compileInfo;
}

void printError(const char* str)
{
    DebugBreak();
}

void qjsBuild()
{
    //std::vector<std::string> strs = CollectTimeoutFiles::splitHeadLine("w:\\mycode\\mb108\\ui\\gfx\\geometry\\cubic_bezier.h");

    // compileCfg -> debug|release|releaseSymbol
    std::string cmd;

    //cmd = "{\"compileCfg\":\"linux_release_sym_arm64\", \"isBuildElectronMode\":false, \"v8dir\":\"v8\", \"symbolLevel\":1}"; // arm64版本, 调试符号
    //cmd = "{\"compileCfg\":\"linux_release_arm64\", \"isBuildElectronMode\":false, \"v8dir\":\"v8\", \"symbolLevel\":0}"; // arm64版本, 无调试符号
    //cmd = "{\"compileCfg\":\"linux_release_sym_x64\", \"isBuildElectronMode\":false, \"v8dir\":\"v8\", \"symbolLevel\":0}"; // release版本,带调试符号

    // kRebuildOptPrebuildSrcAndLink
    cmd = "{\"compileCfg\":\"linux_release_x64\", \"isBuildElectronMode\":false, \"v8dir\":\"v8\", \"symbolLevel\":0}"; // release版本, 不带调试符号
    //////qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "webdriver.js", cmd, kRebuildOptAll);

    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "freetype_build.js", cmd, kRebuildOptAll); //
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "openssl_build.js", cmd, kRebuildOptCompileTimeOutFile); //
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "util_build.js", cmd, kRebuildOptAll); //
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "icu_build.js", cmd, kRebuildOptAll); //
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "v8_108_build.js", cmd, kRebuildOptCompileTimeOutFile); //
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "v8_108_gen_build.js", cmd, kRebuildOptCompileTimeOutFile); //

    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "skia_build.js", cmd, kRebuildOptAll); //
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "gen_build.js", cmd, kRebuildOptCompileTimeOutFile); //
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "chromium_build.js", cmd, kRebuildOptCompileTimeOutFile); // kRebuildOptOnlyLink
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "blink_build.js", cmd, kRebuildOptCompileTimeOutFile);
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "wkexe_build.js", cmd, kRebuildOptAll);
    //qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "webdriver_build.js", cmd, kRebuildOptAll);
    qjsRebuild("W:\\mycode\\mb108\\fastmake\\buildcfg\\", "tscurl_build.js", cmd, kRebuildOptCompileTimeOutFile);

    time_t now;
    struct tm* current;

    now = time(NULL);
    current = localtime(&now);

    char output[100] = { 0 };
    sprintf(output, "build finish!!!: %d-%02d-%02d %02d:%02d:%02d\n", current->tm_year + 1900, current->tm_mon + 1, current->tm_mday, current->tm_hour,
        current->tm_min, current->tm_sec);
    OutputDebugStringA(output);
    MessageBoxA(0, output, 0, 0);
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    //     std::atomic<int32_t> capture_mode_;
    //     capture_mode_.store(111, std::memory_order_release);
    //     int32_t xx = capture_mode_.load(std::memory_order_relaxed);

    //buildDebug();
    //buildRelease();
    //------------------------
    //     std::vector<char> buffer;
    //     common::readFile(L"G:\\mycode\\miniblink57\\fastmake\\test_qjs_build.js", &buffer);
    //     buffer.push_back('\0');
    //
    //     runQjsTest("G:\\mycode\\miniblink57\\fastmake\\", buffer.data(), buffer.size());
    //------------
    qjsBuild();
    //------------
    //     listAllFileInDrectory(L"G:\\mycode\\miniblink57\\out\\tmp");
    //     return 0;
    //---
    //     std::vector<std::wstring> files;
    //     getAllFiles(L"G:\\chromium\\M84\\build\\linux\\debian_sid_amd64-sysroot\\usr\\lib", &files);
    //     binFindStr(files, "_byteswap_ulong");
    // //
    // //     getAllFiles(L"C:\\cygwin64\\usr\\local\\x86_64-unknown-linux-gnu", &files);
    // //     binFindStr(files, "_byteswap_ulong");
    //
    //     getAllFiles(L"C:\\cygwin64\\usr\\local\\x86_64-unknown-linux-gnu", &files);
    //     binFindStr(files, "fstat");
    //
    //     return 0;

    //---
    //     parseVcxprojfilters();
    //     return 0;
    //---------
    //     fmBuild(L"G:\\test\\sln_test\\firstlinux\\testlinux\\build.json");
    //     return 0;
    //---

    //     fmFastBuild(L"G:\\mycode\\mb\\third_party\\ffmpeg\\ffmpeg.json", kRebuildOptOnlyLink);
    //     return 0;
    //---

    return 0;
}

extern "C" int __cdecl _CrtDbgReport(int _ReportType, char const* _FileName, int _Linenumber, char const* _ModuleName, char const* _Format, ...)
{
    DebugBreak();
    return 0;
}