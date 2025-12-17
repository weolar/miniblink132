
#ifndef electron_common_LoadMiniElectronAsarRes_h
#define electron_common_LoadMiniElectronAsarRes_h

#include <string>
#include <vector>

namespace atom {

#define kMiniElectronAsarPrefix "minielectronasarres"
#define kMiniElectronAsarPrefixW L"minielectronasarres"

//bool loadMiniElectronAsarRes(const std::string& path, std::string* result);
void setMiniElectronAsarResPath(const std::string& path);
const std::string& getMiniElectronAsarResPath();
//bool isMiniElectronAsarResPath(const std::string& path);
bool checkMiniElectronAsarResStat(const std::string& path, int* rc, std::string* result);

}

#endif // electron_common_LoadMiniElectronAsarRes_h