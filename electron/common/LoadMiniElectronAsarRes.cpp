
#include "electron/common/LoadMiniElectronAsarRes.h"

#include "electron/lib/MiniElectronAsarRes.h"
#include "base/strings/string_util.h"
#include <string>
#include <vector>

namespace atom {

// 把../这种路径简化
static std::string resolvePath(const std::string& path)
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

static void pathToNormal(std::string* str)
{
    for (int i = 0; i < str->size(); ++i) {
        if ((*str)[i] >= 'A' && (*str)[i] <= 'Z') {
            (*str)[i] += 32;
        }
        if ((*str)[i] == '/')
            (*str)[i] = '\\';
    }

    if (base::StartsWith(*str, "\\\\?\\"))
        *str = str->substr(3); // 去掉\\\\.\\

    if (base::StartsWith(*str, "file:\\\\\\"))
        *str = str->substr(8);

    if (base::StartsWith(*str, "file:\\\\"))
        *str = str->substr(7);

    *str = resolvePath(*str);
}

static std::string* s_miniElectronAsarResPath = nullptr;

const std::string& getMiniElectronAsarResPath()
{
    return *s_miniElectronAsarResPath;
}

void setMiniElectronAsarResPath(const std::string& path)
{
    if (!s_miniElectronAsarResPath)
        s_miniElectronAsarResPath = new std::string();
    *s_miniElectronAsarResPath = path;
    pathToNormal(s_miniElectronAsarResPath);
}

// 是否是内部路径开头
bool isAsarResPath(const std::string& path)
{
    std::string pathCopy = path;
    pathToNormal(&pathCopy);
    if (base::StartsWith(pathCopy, "\\\\?\\"))
        pathCopy = pathCopy.substr(3);

    return base::StartsWith(pathCopy, *s_miniElectronAsarResPath);
}

// 两个路径是否相等。
static bool isEquPath(const std::string& pathA, const std::string& pathB)
{
    std::string pathACp = pathA;
    std::string pathBCp = pathB;
    if (pathACp.size() == 0 || pathBCp.size() == 0)
        return false;

    if (pathACp[pathACp.size() - 1] != '\\')
        pathACp += "\\";
    if (pathBCp[pathBCp.size() - 1] != '\\')
        pathBCp += "\\";
    return pathACp == pathBCp;
}

// 根据路径确定是不是asar目录、还是文件。文件返回0，目录返回1。
bool checkMiniElectronAsarResStat(const std::string& path, int* rc, std::string* result)
{
    if (!s_miniElectronAsarResPath)
        return false;

    // 类似Q:\xx\yyy\minielectronasarres这种路径要被判断为目录
    std::string pathNormal = path;
    if (base::StartsWith(pathNormal, "\\\\?\\"))
        pathNormal = pathNormal.substr(3);
    pathToNormal(&pathNormal);

    std::string miniElectronAsarResPath = s_miniElectronAsarResPath->substr(0, s_miniElectronAsarResPath->size() - 3);
    if (base::StartsWith(pathNormal, *s_miniElectronAsarResPath)) {
        pathNormal = pathNormal.substr(s_miniElectronAsarResPath->size() - 3); // 3是“lib”的大小

        for (size_t i = 0; i < sizeof(kMiniElectronAsarResInfo) / sizeof(MiniElectronAsarResInfo); ++i) {
            MiniElectronAsarResInfo& it = kMiniElectronAsarResInfo[i];
            std::string pathIt = it.name;
            pathToNormal(&pathIt);
            //pathIt = pathIt.substr(3); // 去掉"lib\"

            if (pathNormal.size() > pathIt.size())
                continue;

            if (pathNormal == pathIt) { // 是文件result
                *rc = 0;
                if (result)
                    *result = (const char*)(it.res);
                return true;
            }

            if (base::StartsWith(pathIt, pathNormal) && pathIt[pathNormal.size()] == '\\') { // 是目录
                *rc = 1;
                return true;
            }
        }
    } else if (isEquPath(pathNormal, miniElectronAsarResPath)) {
        *rc = 1;
        return true;
    }

    return false;
}

// bool loadMiniElectronAsarRes(const std::string& path, std::string* result)
// {
// //     if (path.find(kMiniElectronAsarPrefix) == std::string::npos)
// //         return false;
//     int rc = 0;
//     if (!checkMiniElectronAsarResStat(path, &rc))
//         return false;
// }

} // atom