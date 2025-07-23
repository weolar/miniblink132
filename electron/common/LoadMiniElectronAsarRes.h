
#ifndef electron_common_LoadMiniElectronAsarRes_h
#define electron_common_LoadMiniElectronAsarRes_h

#include <string>
#include <vector>

namespace atom {

#define kMiniElectronAsarPrefix "minielectronasarres"

bool LoadMiniElectronAsarRes(const std::string& path, std::string* result);

}

#endif // electron_common_LoadMiniElectronAsarRes_h