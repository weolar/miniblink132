
#ifndef mbnet_DefaultLocalStorageDir_h
#define mbnet_DefaultLocalStorageDir_h

#include "base/files/file_path.h"

namespace mbnet {

base::FilePath getDefaultLocalStorageDir();
void setDefaultLocalStorageDir(const std::string& path);

}

#endif // mbnet_DefaultLocalStorageDir_h