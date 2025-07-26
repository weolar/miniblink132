
#include "mbnet/DefaultLocalStorageDir.h"
#include "third_party/libcurl/include/curl/curl.h"
#include "mbnet/WebURLLoaderManagerUtil.h"
#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"
#include "base/strings/string_util.h"
#include <shlwapi.h>

namespace mbnet {

static base::FilePath* kDefaultLocalStorageDir = nullptr;

void setDefaultLocalStorageDir(const std::string& path)
{
    WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
    WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

    if (path.empty())
        return;

    if (kDefaultLocalStorageDir)
        delete kDefaultLocalStorageDir;
    kDefaultLocalStorageDir = new base::FilePath(base::FilePath::FromUTF8Unsafe(path));

    //     if (kDefaultLocalStorageDir->empty()) {
    //         delete kDefaultLocalStorageDir;
    //         kDefaultLocalStorageDir = nullptr;
    //         return;
    //     }
    //
    //     if (!base::EndsWith(*kDefaultLocalStorageDir, "\\"))
    //         kDefaultLocalStorageDir->push_back('\\');
}

base::FilePath getDefaultLocalStorageDir()
{
    WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
    WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

    if (kDefaultLocalStorageDir)
        return *kDefaultLocalStorageDir;

#if BUILDFLAG(IS_WIN)
    std::vector<WCHAR> path;
    path.resize(2 * (MAX_PATH + 1));
    memset(&path.at(0), 0, sizeof(WCHAR) * (2 * (MAX_PATH + 1)));
    ::GetModuleFileNameW(nullptr, &path.at(0), MAX_PATH);
    ::PathRemoveFileSpecW(&path.at(0));
    ::PathAppendW(&path.at(0), L"LocalStorage");

    size_t size = wcslen(&path.at(0));

    kDefaultLocalStorageDir = new base::FilePath(std::wstring(path.data(), size));
#else
    std::vector<char> buf;
    buf.resize(8025);
    memset(buf.data(), 0, buf.size());
    int n = readlink("/proc/self/exe", buf.data(), buf.size() - 1);
    kDefaultLocalStorageDir = new base::FilePath(base::BasicStringPiece(buf.data()));
    *kDefaultLocalStorageDir = kDefaultLocalStorageDir->DirName();
    *kDefaultLocalStorageDir = kDefaultLocalStorageDir->Append("LocalStorage");

    std::string str = "getDefaultLocalStorageDir:";
    str += kDefaultLocalStorageDir->AsUTF8Unsafe();
    str += "---\n";

    OutputDebugStringA(str.c_str());
#endif
    //     UChar c = kDefaultLocalStorageDir->characters16()[size - 1];
    //     if (L'\\' != c && L'/' != c)
    //         kDefaultLocalStorageDir->append(L'\\');

    return *kDefaultLocalStorageDir;
}

}