
#include "electron/common/LoadMiniElectronAsarRes.h"

#include "electron/lib/MiniElectronAsarRes.h"
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

    *str = resolvePath(*str);
}

bool LoadMiniElectronAsarRes(const std::string& path, std::string* result)
{
    if (path.find(kMiniElectronAsarPrefix) == std::string::npos)
        return false;

    for (size_t i = 0; i < sizeof(kMiniElectronAsarResInfo) / sizeof(MiniElectronAsarResInfo); ++i) {
        MiniElectronAsarResInfo& it = kMiniElectronAsarResInfo[i];
        std::string pathIt = it.name;
        pathToNormal(&pathIt);

        std::string pathNormal = path;
        pathToNormal(&pathNormal);
        if (pathNormal.find(pathIt) == std::string::npos)
            continue;
        if (result)
            *result = (const char*)(it.res);
        return true;
    }
    return false;
}

} // atom