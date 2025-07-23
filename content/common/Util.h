
#include <windows.h>
#include <vector>
#include <shlwapi.h>

//#include "base/files/file_util.h"

#ifndef common_Util_h
#define common_Util_h

namespace common {

inline bool readFile(const WCHAR* path, std::vector<char>* buffer)
{
#if defined(OS_WIN)
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
        return false;

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (bufferSize == 0) {
        ::CloseHandle(hFile);
        return true;
    }

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    return !!b;
#else
    //std::string contents;
    //bool base::ReadFileToString(const base::FilePath& path, std::string* contents);
    printf("common::readFile not IMPL\n");
    return false;
#endif
}

// szPathDir结尾如果是目录而不是文件，请带上‘/’或‘\\’
inline BOOL createMultiDir(const WCHAR* pathDir)
{
#if defined(OS_WIN)
    const size_t len = wcslen(pathDir);
    std::vector<WCHAR> temp(len + 1);

    for (size_t i = 0; i < len; i++) {
        WCHAR c = pathDir[i];
        temp[i] = c;
        temp[i + 1] = 0;
        if (L'/' == c || L'\\' == c) {
            if (!::PathFileExistsW(temp.data())) {
                if (!CreateDirectory(temp.data(), NULL))
                    return FALSE;
            }
        }
    }

    return TRUE;
#else
    printf("common::createMultiDir not IMPL\n");
    return FALSE;
#endif
}

inline void writeFile(const WCHAR* path, const std::vector<char>& buffer)
{
    createMultiDir(path);

    HANDLE hFile = CreateFileW(path, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        DebugBreak();
        return;
    }

    DWORD numberOfBytesWrite = 0;
    BOOL b = ::WriteFile(hFile, &buffer.at(0), buffer.size(), &numberOfBytesWrite, nullptr);
    ::CloseHandle(hFile);
}

}

#endif // common_Util_h