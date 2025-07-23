// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/asar/Archive.h"

#include <string>
#include <vector>

#include "electron/common/asar/ScopedTemporaryFile.h"

#include "base/files/file.h"
#include "base/logging.h"
#include "base/pickle.h"
#include "base/json/json_reader.h"
#include "base/values.h"

#if defined(OS_WIN)
#include <io.h>
//#include "atom/node/osfhandle.h"
#include "mbvip/core/mb.h"
#endif

namespace asar {

namespace {

#if defined(OS_WIN)
const char kSeparators[] = "\\"; //"\\/";
#else
const char kSeparators[] = "/";
#endif

const base::Value::Dict* GetNodeFromPath(std::string path, const base::Value::Dict* root);

// Gets the "files" from "dir".
const base::Value::Dict* GetFilesNode(const base::Value::Dict* root, const base::Value::Dict* dir)
{
    // Test for symbol linked directory.
    const std::string* link = dir->FindString("link");
    //if (dir->GetStringWithoutPathExpansion("link", &link)) {
    if (link) {
        const base::Value::Dict* linked_node = GetNodeFromPath(*link, root);
        if (!linked_node)
            return nullptr;
        dir = linked_node;
    }

    //return dir->GetDictionaryWithoutPathExpansion("files", out);
    return dir->FindDict("files");
}

// Gets sub-file "name" from "dir".
const base::Value::Dict* GetChildNode(const base::Value::Dict* root, const std::string& name, const base::Value::Dict* dir)
{
    if (name == "") {
        return root;
    }

    const base::Value::Dict* files = nullptr;
    //return GetFilesNode(root, dir, &files) && files->GetDictionaryWithoutPathExpansion(name, out);
    files = GetFilesNode(root, dir);
    if (!files)
        return nullptr;

    return files->FindDict(name);
}

// Gets the node of "path" from "root".
const base::Value::Dict* GetNodeFromPath(std::string path, const base::Value::Dict* root)
{
    if (path == "") {
        return root;
    }

    const base::Value::Dict* dir = root;
    for (size_t delimiter_position = path.find_first_of(kSeparators); delimiter_position != std::string::npos;
         delimiter_position = path.find_first_of(kSeparators)) {
        const base::Value::Dict* child = nullptr;
        //if (!GetChildNode(root, path.substr(0, delimiter_position), dir, &child))
        //    return false;
        child = GetChildNode(root, path.substr(0, delimiter_position), dir);
        if (!child)
            return nullptr;

        dir = child;
        path.erase(0, delimiter_position + 1);
    }

    return GetChildNode(root, path, dir);
}

bool FillFileInfoWithNode(Archive::FileInfo* info, uint32_t header_size, const base::Value::Dict* node)
{
    std::optional<int> sizeOpt = node->FindInt("size");
    if (!sizeOpt.has_value())
        return false;
    info->size = static_cast<uint32_t>(sizeOpt.value());

    //if (node->GetBoolean("unpacked", &info->unpacked) && info->unpacked)
    //    return true;
    std::optional<bool> isUnpacked = node->FindBool("unpacked");
    if (isUnpacked.has_value() && isUnpacked.value()) {
        info->unpacked = true;
        return true;
    }

    const std::string* offset = node->FindString("offset");
    if (!offset)
        return false;

    //   if (!base::StringToUint64(offset, &info->offset))
    //     return false;

    char* endptr = nullptr;
    info->offset = _strtoui64(offset->c_str(), &endptr, 10);

    info->offset += header_size;

    info->executable = false;
    std::optional<bool> isExecutable = node->FindBool("executable");
    if (isExecutable.has_value() && isExecutable.value())
        info->executable = true;

    return true;
}

} // namespace

#if 0
typedef int (MB_CALL_TYPE* mb_open_osfhandle_pfn)(intptr_t osfhandle, int sourceFlags);
static mb_open_osfhandle_pfn mb_open_osfhandle = nullptr;
#endif

Archive::Archive(const base::FilePath& path)
    : path_(path)
    , file_(path_, base::File::FLAG_OPEN | base::File::FLAG_READ)
#if defined(OS_WIN)
    , fd_(_open_osfhandle(reinterpret_cast<intptr_t>(file_.GetPlatformFile()), 0))
#elif defined(OS_POSIX)
    , fd_(file_.GetPlatformFile())
#else
    , fd_(-1)
#endif
    , header_size_(0)
{
#if 0
    // file_.GetPlatformFile()如果是从别的模块来的，则要用对应模块的_open_osfhandle
    if (!mb_open_osfhandle)
        mb_open_osfhandle = (mb_open_osfhandle_pfn)mbGetProcAddr("mb_open_osfhandle");
    fd_ = mb_open_osfhandle(reinterpret_cast<intptr_t>(file_.GetPlatformFile()), 0);
#endif
}

Archive::~Archive()
{
#if defined(OS_WIN)
    if (fd_ != -1) {
        _close(fd_);

        // Don't close the handle since we already closed the fd.
        file_.TakePlatformFile();
    }
#endif
    for (auto it : external_files_) {
        delete it.second;
    }
}

bool Archive::Init()
{
    if (!file_.IsValid()) {
        if (file_.error_details() != base::File::FILE_ERROR_NOT_FOUND) {
            // LOG(WARNING) << "Opening " << path_.value() << ": " << base::File::ErrorToString(file_.error_details());
        }
        return false;
    }

    std::vector<char> buf;
    int len;

    buf.resize(8);
    len = file_.ReadAtCurrentPos(&buf[0], buf.size());
    if (len != static_cast<int>(buf.size())) {
        //PLOG(ERROR) << "Failed to read header size from " << path_.value();
        return false;
    }

    uint32_t size;
    if (!base::PickleIterator(base::Pickle(&buf[0], buf.size())).ReadUInt32(&size)) {
        //LOG(ERROR) << "Failed to parse header size from " << path_.value();
        return false;
    }

    buf.resize(size);
    len = file_.ReadAtCurrentPos(&buf[0], buf.size());
    if (len != static_cast<int>(buf.size())) {
        //PLOG(ERROR) << "Failed to read header from " << path_.value();
        return false;
    }

    std::string header;
    if (!base::PickleIterator(base::Pickle(&buf[0], buf.size())).ReadString(&header)) {
        //LOG(ERROR) << "Failed to parse header from " << path_.value();
        return false;
    }

    std::string error;
    //base::JSONReader reader;
    //std::unique_ptr<base::Value> value(reader.ReadToValue(header));

    base::JSONReader::Result ret = base::JSONReader::ReadAndReturnValueWithError(header);
    if (!ret.has_value() || !ret->is_dict()) {
        //LOG(ERROR) << "Failed to parse header: " << error;
        return false;
    }

    header_size_ = 8 + size;
    //header_.reset(static_cast<base::Value::Dict*>(value.release()));
    header_.reset(new base::Value::Dict(std::move(ret.value().GetDict())));
    return true;
}

bool Archive::GetFileInfo(const base::FilePath& path, FileInfo* info)
{
    if (!header_)
        return false;

    const base::Value::Dict* node = GetNodeFromPath(path.AsUTF8Unsafe(), header_.get());
    if (!node)
        return false;

    const std::string* link = node->FindString("link");
    if (link)
        return GetFileInfo(base::FilePath::FromUTF8Unsafe(*link), info);

    bool b = FillFileInfoWithNode(info, header_size_, node);
    return b;
}

bool Archive::Stat(const base::FilePath& path, Stats* stats)
{
    if (!header_)
        return false;

    const base::Value::Dict* node = GetNodeFromPath(path.AsUTF8Unsafe(), header_.get());
    if (!node)
        return false;

    if (node->contains("link")) {
        stats->is_file = false;
        stats->is_link = true;
        return true;
    }

    if (node->contains("files")) {
        stats->is_file = false;
        stats->is_directory = true;
        return true;
    }

    return FillFileInfoWithNode(stats, header_size_, node);
}

bool Archive::Readdir(const base::FilePath& path, std::vector<base::FilePath>* list)
{
    if (!header_)
        return false;

    const base::Value::Dict* node = GetNodeFromPath(path.AsUTF8Unsafe(), header_.get());
    if (!node)
        return false;

    const base::Value::Dict* files = GetFilesNode(header_.get(), node);
    if (!files)
        return false;

    base::Value::Dict::const_iterator iter = files->begin();
    for (; iter != files->end(); iter++) {
        base::Value::Dict::const_iterator::reference pair = *iter;
        list->push_back(base::FilePath::FromUTF8Unsafe(pair.first));
        ;
    }
    return true;
}

bool Archive::Realpath(const base::FilePath& path, base::FilePath* realpath)
{
    if (!header_)
        return false;

    const base::Value::Dict* node = GetNodeFromPath(path.AsUTF8Unsafe(), header_.get());
    if (!node)
        return false;

    const std::string* link = node->FindString("link");
    if (link) {
        *realpath = base::FilePath::FromUTF8Unsafe(*link);
        return true;
    }

    *realpath = path;
    return true;
}

bool Archive::CopyFileOut(const base::FilePath& path, base::FilePath* out)
{
    std::map<base::FilePath, ScopedTemporaryFile*>::iterator it = external_files_.find(path);
    if (it != external_files_.end()) {
        *out = (*it).second->path();
        return true;
    }

    FileInfo info;
    if (!GetFileInfo(path, &info))
        return false;

    if (info.unpacked) {
        *out = path_.AddExtension(FILE_PATH_LITERAL("unpacked")).Append(path);
        return true;
    }

    ScopedTemporaryFile* temp_file(new ScopedTemporaryFile);
    base::FilePath::StringType ext = path.Extension();
    if (!temp_file->InitFromFile(&file_, ext, info.offset, info.size))
        return false;

#if defined(OS_POSIX)
    if (info.executable) {
        // chmod a+x temp_file;
        base::SetPosixFilePermissions(temp_file->path(), 0755);
    }
#endif

    *out = temp_file->path();
    external_files_.insert(std::pair<base::FilePath, ScopedTemporaryFile*>(path, temp_file));
    return true;
}

int Archive::GetFD() const
{
    return fd_;
}

} // namespace asar
