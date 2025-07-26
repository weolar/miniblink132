// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ipc_lite/ipc_message_utils.h"

#include "base/files/file_path.h"
#include "base/json/json_writer.h"
//#include "base/memory/scoped_ptr.h"
//#include "base/nullable_string16.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/files/file_path.h"
#include "base/time/time.h"
#include "base/values.h"
#include "base/logging.h"
#include "base/notreached.h"
#include "ipc_lite/ipc_channel_handle.h"

#if defined(OS_POSIX)
#include "ipc_lite/file_descriptor_set_posix.h"
#endif

namespace IPC {

namespace {

const int kMaxRecursionDepth = 100;

template <typename CharType> void LogBytes(const std::vector<CharType>& data, std::string* out)
{
#if defined(OS_WIN)
    // Windows has a GUI for logging, which can handle arbitrary binary data.
    for (size_t i = 0; i < data.size(); ++i)
        out->push_back(data[i]);
#else
    // On POSIX, we log to stdout, which we assume can display ASCII.
    static const size_t kMaxBytesToLog = 100;
    for (size_t i = 0; i < std::min(data.size(), kMaxBytesToLog); ++i) {
        if (isprint(data[i]))
            out->push_back(data[i]);
        else
            out->append(base::StringPrintf("[%02X]", static_cast<unsigned char>(data[i])));
    }
    if (data.size() > kMaxBytesToLog) {
        out->append(base::StringPrintf(" and %u more bytes", static_cast<unsigned>(data.size() - kMaxBytesToLog)));
    }
#endif
}

bool ReadValue(const Message* m, base::PickleIterator* iter, base::Value* value, int recursion);

//void WriteValue(const base::Value& value, int recursion, base::Pickle* pickle);
void WriteValue(Message* m, const base::Value& value, int recursion);

void WriteDictValue(const base::Value::Dict& value, int recursion, Message* m)
{
    WriteParam(m, (int)(base::checked_cast<int>(value.size())));
    for (const auto entry : value) {
        WriteParam(m, entry.first);
        WriteValue(m, entry.second, recursion + 1);
    }
}

void WriteListValue(const base::Value::List& value, int recursion, Message* m)
{
    WriteParam(m, base::checked_cast<int>(value.size()));
    for (const auto& entry : value) {
        WriteValue(m, entry, recursion + 1);
    }
}

void WriteValue(Message* m, const base::Value& value, int recursion)
{
    //bool result;
    if (recursion > kMaxRecursionDepth) {
        LOG(WARNING) << "Max recursion depth hit in WriteValue.";
        return;
    }

    m->WriteInt((int)(value.type()));

    switch (value.type()) {
    case base::Value::Type::NONE:
        break;
    case base::Value::Type::BOOLEAN: {
        //bool val;
        //result = value->GetAsBoolean(&val);
        std::optional<bool> result = value.GetIfBool();
        DCHECK(result.has_value());
        WriteParam(m, result.value());
        break;
    }
    case base::Value::Type::INTEGER: {
        //int val;
        //result = value->GetAsInteger(&val);
        std::optional<int> result = value.GetIfInt();
        DCHECK(result.has_value());
        WriteParam(m, result.value());
        break;
    }
    case base::Value::Type::DOUBLE: {
        //double val;
        //result = value->GetAsDouble(&val);
        std::optional<double> result = value.GetIfDouble();
        DCHECK(result.has_value());
        WriteParam(m, result.value());
        break;
    }
    case base::Value::Type::STRING: {
        //std::string val;
        //result = value->GetAsString(&val);
        const std::string* result = value.GetIfString();
        DCHECK(result);
        WriteParam(m, *result);
        break;
    }
    case base::Value::Type::BINARY: {
        //const base::BinaryValue* binary = static_cast<const base::BinaryValue*>(value);
        //m->WriteData(binary->GetBuffer(), static_cast<int>(binary->GetSize()));
        *(int*)1 = 1;
        break;
    }
    case base::Value::Type::DICT: {
        DCHECK(value.is_dict());
        WriteDictValue(value.GetDict(), recursion, m);
        //             const DictionaryValue* dict = static_cast<const DictionaryValue*>(value);
        //
        //             WriteParam(m, static_cast<int>(dict.size()));
        //
        //             for (DictionaryValue::key_iterator it = dict->begin_keys();
        //                  it != dict->end_keys(); ++it) {
        //                 const base::Value* subval;
        //                 if (dict->GetWithoutPathExpansion(*it, &subval)) {
        //                     WriteParam(m, *it);
        //                     WriteValue(m, subval, recursion + 1);
        //                 } else {
        //                     NOTREACHED() << "DictionaryValue iterators are filthy liars.";
        //                 }
        //             }

        break;
    }
    case base::Value::Type::LIST: {
        DCHECK(value.is_list());
        WriteListValue(value.GetList(), recursion, m);
        //             const ListValue* list = static_cast<const ListValue*>(value);
        //             WriteParam(m, static_cast<int>(list->GetSize()));
        //             for (size_t i = 0; i < list->GetSize(); ++i) {
        //                 const base::Value* subval;
        //                 if (list->Get(i, &subval)) {
        //                     WriteValue(m, subval, recursion + 1);
        //                 } else {
        //                     NOTREACHED() << "ListValue::GetSize is a filthy liar.";
        //                 }
        //             }
        break;
    }
    }
}

// Helper for ReadValue that reads a DictionaryValue into a pre-allocated object.
bool ReadDictionaryValue(const Message* m, base::PickleIterator* iter, base::Value::Dict* value, int recursion)
{
    int size;
    if (!ReadParam(m, iter, &size))
        return false;

    for (int i = 0; i < size; ++i) {
        std::string key;
        base::Value subval;
        if (!ReadParam(m, iter, &key) || !ReadValue(m, iter, &subval, recursion + 1))
            return false;
        //value->SetWithoutPathExpansion(key, subval);
        value->Set(key, std::move(subval));
    }

    return true;
}

// Helper for ReadValue that reads a ReadListValue into a pre-allocated object.
bool ReadListValue(const Message* m, base::PickleIterator* iter, base::Value::List* value, int recursion)
{
    int size;
    if (!ReadParam(m, iter, &size))
        return false;

    for (int i = 0; i < size; ++i) {
        base::Value subval;
        if (!ReadValue(m, iter, &subval, recursion + 1))
            return false;
        value->Append(std::move(subval));
    }

    return true;
}

bool ReadValue(const Message* m, base::PickleIterator* iter, base::Value* value, int recursion)
{
    if (recursion > kMaxRecursionDepth) {
        LOG(WARNING) << "Max recursion depth hit in ReadValue.";
        return false;
    }

    int type;
    if (!ReadParam(m, iter, &type))
        return false;

    constexpr int kMinValueType = static_cast<int>(base::Value::Type::NONE);
    constexpr int kMaxValueType = static_cast<int>(base::Value::Type::LIST);
    if (type > kMaxValueType || type < kMinValueType)
        return false;

    switch ((base::Value::Type)type) {
    case base::Value::Type::NONE:
        *value = base::Value();
        break;
    case base::Value::Type::BOOLEAN: {
        bool val;
        if (!ReadParam(m, iter, &val))
            return false;
        *value = base::Value(val);
        break;
    }
    case base::Value::Type::INTEGER: {
        int val;
        if (!ReadParam(m, iter, &val))
            return false;
        *value = base::Value(val);
        break;
    }
    case base::Value::Type::DOUBLE: {
        double val;
        if (!ReadParam(m, iter, &val))
            return false;
        *value = base::Value(val);
        break;
    }
    case base::Value::Type::STRING: {
        std::string val;
        if (!ReadParam(m, iter, &val))
            return false;
        *value = base::Value(std::move(val));
        break;
    }
    case base::Value::Type::BINARY: {
        std::optional<base::span<const uint8_t>> data = iter->ReadData();
        if (!data.has_value())
            return false;
        *value = base::Value(data.value());
        //             const char* data;
        //             int length;
        //             if (!m->ReadData(iter, &data, &length))
        //                 return false;
        //             *value = base::BinaryValue::CreateWithCopiedBuffer(data, length);
        break;
    }
    case base::Value::Type::DICT: {
        //             scoped_ptr<DictionaryValue> val(new DictionaryValue());
        //             if (!ReadDictionaryValue(m, iter, val.get(), recursion))
        //                 return false;
        //             *value = val.release();
        base::Value::Dict val;
        if (!ReadDictionaryValue(m, iter, &val, recursion))
            return false;
        *value = base::Value(std::move(val));
        break;
    }
    case base::Value::Type::LIST: {
        //             scoped_ptr<ListValue> val(new ListValue());
        //             if (!ReadListValue(m, iter, val.get(), recursion))
        //                 return false;
        //             *value = val.release();
        base::Value::List val;
        if (!ReadListValue(m, iter, &val, recursion))
            return false;
        *value = base::Value(std::move(val));
        break;
    }
    default:
        return false;
    }

    return true;
}

} // namespace

// -----------------------------------------------------------------------------

LogData::LogData()
    : routing_id(0)
    , type(0)
    , sent(0)
    , receive(0)
    , dispatch(0)
{
}

LogData::~LogData()
{
}

MessageIterator::MessageIterator(const Message& m)
    : iter_(m)
{
}

int MessageIterator::NextInt() const
{
    int val = -1;
    if (!iter_.ReadInt(&val))
        NOTREACHED();
    return val;
}

const std::string MessageIterator::NextString() const
{
    std::string val;
    if (!iter_.ReadString(&val))
        NOTREACHED();
    return val;
}

void ParamTraits<bool>::Log(const param_type& p, std::string* l)
{
    l->append(p ? "true" : "false");
}

void ParamTraits<int>::Log(const param_type& p, std::string* l)
{
    l->append(base::NumberToString(p));
}

void ParamTraits<unsigned int>::Log(const param_type& p, std::string* l)
{
    l->append(base::NumberToString(p));
}

void ParamTraits<long>::Log(const param_type& p, std::string* l)
{
    l->append(base::NumberToString(static_cast<long>(p)));
}

void ParamTraits<unsigned long>::Log(const param_type& p, std::string* l)
{
    l->append(base::NumberToString(static_cast<unsigned long>(p)));
}

void ParamTraits<long long>::Log(const param_type& p, std::string* l)
{
    l->append(base::NumberToString(static_cast<long long>(p)));
}

void ParamTraits<unsigned long long>::Log(const param_type& p, std::string* l)
{
    l->append(base::NumberToString(static_cast<unsigned long long>(p)));
}

void ParamTraits<unsigned short>::Write(Message* m, const param_type& p)
{
    m->WriteBytes(&p, sizeof(param_type));
}

bool ParamTraits<unsigned short>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    const char* data;
    //if (!m->ReadBytes(iter, &data, sizeof(param_type)))
    if (!iter->ReadBytes(&data, sizeof(param_type)))
        return false;
    memcpy(r, data, sizeof(param_type));
    return true;
}

void ParamTraits<unsigned short>::Log(const param_type& p, std::string* l)
{
    l->append(base::NumberToString(p));
}

void ParamTraits<float>::Write(Message* m, const param_type& p)
{
    m->WriteData(reinterpret_cast<const char*>(&p), sizeof(param_type));
}

bool ParamTraits<float>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    const char* data;
    //size_t data_size;
    //if (!iter->ReadBytes(&data, &data_size) || data_size != sizeof(param_type)) {
    if (!iter->ReadBytes(&data, sizeof(*r))) {
        NOTREACHED();
        return false;
    }
    memcpy(r, data, sizeof(param_type));
    return true;
}

void ParamTraits<float>::Log(const param_type& p, std::string* l)
{
    l->append(base::StringPrintf("%e", p));
}

void ParamTraits<double>::Write(Message* m, const param_type& p)
{
    m->WriteData(reinterpret_cast<const char*>(&p), sizeof(param_type));
}

bool ParamTraits<double>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    const char* data;
    //size_t data_size;
    //if (!iter->ReadBytes(&data, &data_size) || data_size != sizeof(param_type)) {
    if (!iter->ReadBytes(&data, sizeof(*r))) {
        NOTREACHED();
        return false;
    }
    memcpy(r, data, sizeof(param_type));
    return true;
}

void ParamTraits<double>::Log(const param_type& p, std::string* l)
{
    l->append(base::StringPrintf("%e", p));
}

void ParamTraits<std::string>::Log(const param_type& p, std::string* l)
{
    l->append(p);
}

#ifdef _WIN32
void ParamTraits<std::wstring>::Log(const param_type& p, std::string* l)
{
    l->append(base::WideToUTF8(p));
}
#endif // _WIN32

#if !defined(WCHAR_T_IS_UTF16)
// void ParamTraits<string16>::Log(const param_type& p, std::string* l)
// {
//     l->append(UTF16ToUTF8(p));
// }
#endif

void ParamTraits<std::vector<char>>::Write(Message* m, const param_type& p)
{
    if (p.empty()) {
        m->WriteData(NULL, 0);
    } else {
        m->WriteData(&p.front(), static_cast<int>(p.size()));
    }
}

bool ParamTraits<std::vector<char>>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    const char* data;
    size_t data_size = 0;
    if (!iter->ReadData(&data, &data_size) || data_size < 0)
        return false;
    r->resize(data_size);
    if (data_size)
        memcpy(&r->front(), data, data_size);
    return true;
}

void ParamTraits<std::vector<char>>::Log(const param_type& p, std::string* l)
{
    LogBytes(p, l);
}

void ParamTraits<std::vector<unsigned char>>::Write(Message* m, const param_type& p)
{
    if (p.empty()) {
        m->WriteData(NULL, 0);
    } else {
        m->WriteData(reinterpret_cast<const char*>(&p.front()), static_cast<int>(p.size()));
    }
}

bool ParamTraits<std::vector<unsigned char>>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    const char* data;
    size_t data_size = 0;
    if (!iter->ReadData(&data, &data_size) || data_size < 0)
        return false;
    r->resize(data_size);
    if (data_size)
        memcpy(&r->front(), data, data_size);
    return true;
}

void ParamTraits<std::vector<unsigned char>>::Log(const param_type& p, std::string* l)
{
    LogBytes(p, l);
}

void ParamTraits<std::vector<bool>>::Write(Message* m, const param_type& p)
{
    WriteParam(m, static_cast<int>(p.size()));
    for (size_t i = 0; i < p.size(); i++)
        WriteParam(m, p[i]);
}

bool ParamTraits<std::vector<bool>>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    size_t size;
    // ReadLength() checks for < 0 itself.
    if (!iter->ReadLength(&size))
        return false;
    r->resize(size);
    for (int i = 0; i < size; i++) {
        bool value;
        if (!ReadParam(m, iter, &value))
            return false;
        (*r)[i] = value;
    }
    return true;
}

void ParamTraits<std::vector<bool>>::Log(const param_type& p, std::string* l)
{
    for (size_t i = 0; i < p.size(); ++i) {
        if (i != 0)
            l->push_back(' ');
        LogParam((p[i]), l);
    }
}

void ParamTraits<base::Value::Dict>::Write(Message* m, const param_type& p)
{
    m->WriteInt((int)(base::Value::Type::DICT));
    WriteDictValue(p, 0, m);
}

bool ParamTraits<base::Value::Dict>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    int type;
    if (!ReadParam(m, iter, (&type)) || (base::Value::Type)type != base::Value::Type::DICT)
        return false;

    return ReadDictionaryValue(m, iter, r, 0);
}

void ParamTraits<base::Value::Dict>::Log(const param_type& p, std::string* l)
{
    std::string json;
    base::JSONWriter::Write(p, &json);
    l->append(json);
}

void ParamTraits<base::Value::List>::Write(Message* m, const param_type& p)
{
    m->WriteInt((int)(base::Value::Type::LIST));
    WriteListValue(p, 0, m);
}

bool ParamTraits<base::Value::List>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    int type;
    if (!ReadParam(m, iter, &type) || (base::Value::Type)type != base::Value::Type::LIST)
        return false;

    return ReadListValue(m, iter, r, 0);
}

void ParamTraits<base::Value::List>::Log(const param_type& p, std::string* l)
{
    std::string json;
    base::JSONWriter::Write(p, &json);
    l->append(json);
}

#if defined(OS_POSIX)
void ParamTraits<base::FileDescriptor>::Write(Message* m, const param_type& p)
{
    const bool valid = p.fd >= 0;
    WriteParam(m, valid);

    if (valid) {
        if (!m->WriteFileDescriptor(p))
            NOTREACHED();
    }
}

bool ParamTraits<base::FileDescriptor>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    bool valid;
    if (!ReadParam(m, iter, &valid))
        return false;

    if (!valid) {
        r->fd = -1;
        r->auto_close = false;
        return true;
    }

    return m->ReadFileDescriptor(iter, r);
}

void ParamTraits<base::FileDescriptor>::Log(const param_type& p, std::string* l)
{
    if (p.auto_close) {
        l->append(base::StringPrintf("FD(%d auto-close)", p.fd));
    } else {
        l->append(base::StringPrintf("FD(%d)", p.fd));
    }
}
#endif // defined(OS_POSIX)

void ParamTraits<base::FilePath>::Write(Message* m, const param_type& p)
{
    ParamTraits<base::FilePath::StringType>::Write(m, p.value());
}

bool ParamTraits<base::FilePath>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    base::FilePath::StringType value;
    if (!ParamTraits<base::FilePath::StringType>::Read(m, iter, &value))
        return false;
    *r = base::FilePath(value);
    return true;
}

void ParamTraits<base::FilePath>::Log(const param_type& p, std::string* l)
{
    ParamTraits<base::FilePath::StringType>::Log(p.value(), l);
}

// void ParamTraits<NullableString16>::Write(Message* m, const param_type& p)
// {
//     WriteParam(m, p.string());
//     WriteParam(m, p.is_null());
// }
//
// bool ParamTraits<NullableString16>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
// {
//     string16 string;
//     if (!ReadParam(m, iter, &string))
//         return false;
//     bool is_null;
//     if (!ReadParam(m, iter, &is_null))
//         return false;
//     *r = NullableString16(string, is_null);
//     return true;
// }
//
// void ParamTraits<NullableString16>::Log(const param_type& p, std::string* l)
// {
//     l->append("(");
//     LogParam(p.string(), l);
//     l->append(", ");
//     LogParam(p.is_null(), l);
//     l->append(")");
// }
//
// void ParamTraits<base::PlatformFileInfo>::Write(Message* m, const param_type& p)
// {
//     WriteParam(m, p.size);
//     WriteParam(m, p.is_directory);
//     WriteParam(m, p.last_modified.ToDoubleT());
//     WriteParam(m, p.last_accessed.ToDoubleT());
//     WriteParam(m, p.creation_time.ToDoubleT());
// }
//
// bool ParamTraits<base::PlatformFileInfo>::Read(const Message* m, base::PickleIterator* iter, param_type* p)
// {
//     double last_modified;
//     double last_accessed;
//     double creation_time;
//     bool result = ReadParam(m, iter, &p->size) && ReadParam(m, iter, &p->is_directory) && ReadParam(m, iter, &last_modified) && ReadParam(m, iter, &last_accessed) && ReadParam(m, iter, &creation_time);
//     if (result) {
//         p->last_modified = base::Time::FromDoubleT(last_modified);
//         p->last_accessed = base::Time::FromDoubleT(last_accessed);
//         p->creation_time = base::Time::FromDoubleT(creation_time);
//     }
//     return result;
// }
//
// void ParamTraits<base::PlatformFileInfo>::Log(const param_type& p, std::string* l)
// {
//     l->append("(");
//     LogParam(p.size, l);
//     l->append(",");
//     LogParam(p.is_directory, l);
//     l->append(",");
//     LogParam(p.last_modified.ToDoubleT(), l);
//     l->append(",");
//     LogParam(p.last_accessed.ToDoubleT(), l);
//     l->append(",");
//     LogParam(p.creation_time.ToDoubleT(), l);
//     l->append(")");
// }

void ParamTraits<base::Time>::Write(Message* m, const param_type& p)
{
    ParamTraits<int64>::Write(m, p.ToInternalValue());
}

bool ParamTraits<base::Time>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    int64 value;
    if (!ParamTraits<int64>::Read(m, iter, &value))
        return false;
    *r = base::Time::FromInternalValue(value);
    return true;
}

void ParamTraits<base::Time>::Log(const param_type& p, std::string* l)
{
    ParamTraits<int64>::Log(p.ToInternalValue(), l);
}

void ParamTraits<base::TimeDelta>::Write(Message* m, const param_type& p)
{
    ParamTraits<int64>::Write(m, p.ToInternalValue());
}

bool ParamTraits<base::TimeDelta>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    int64 value;
    bool ret = ParamTraits<int64>::Read(m, iter, &value);
    if (ret)
        *r = base::TimeDelta::FromInternalValue(value);

    return ret;
}

void ParamTraits<base::TimeDelta>::Log(const param_type& p, std::string* l)
{
    ParamTraits<int64>::Log(p.ToInternalValue(), l);
}

void ParamTraits<base::TimeTicks>::Write(Message* m, const param_type& p)
{
    ParamTraits<int64>::Write(m, p.ToInternalValue());
}

bool ParamTraits<base::TimeTicks>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    int64 value;
    bool ret = ParamTraits<int64>::Read(m, iter, &value);
    if (ret)
        *r = base::TimeTicks::FromInternalValue(value);

    return ret;
}

void ParamTraits<base::TimeTicks>::Log(const param_type& p, std::string* l)
{
    ParamTraits<int64>::Log(p.ToInternalValue(), l);
}

void ParamTraits<IPC::ChannelHandle>::Write(Message* m, const param_type& p)
{
#if defined(OS_WIN)
    // On Windows marshalling pipe handle is not supported.
    DCHECK(p.pipe.handle == NULL);
#endif // defined (OS_WIN)
    WriteParam(m, p.name);
#if defined(OS_POSIX)
    WriteParam(m, p.socket);
#endif
}

bool ParamTraits<IPC::ChannelHandle>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    return ReadParam(m, iter, &r->name)
#if defined(OS_POSIX)
        && ReadParam(m, iter, &r->socket)
#endif
        ;
}

void ParamTraits<IPC::ChannelHandle>::Log(const param_type& p, std::string* l)
{
    l->append(base::StringPrintf("ChannelHandle(%s", p.name.c_str()));
#if defined(OS_POSIX)
    l->append(", ");
    ParamTraits<base::FileDescriptor>::Log(p.socket, l);
#endif
    l->append(")");
}

void ParamTraits<LogData>::Write(Message* m, const param_type& p)
{
    WriteParam(m, p.channel);
    WriteParam(m, p.routing_id);
    WriteParam(m, p.type);
    WriteParam(m, p.flags);
    WriteParam(m, p.sent);
    WriteParam(m, p.receive);
    WriteParam(m, p.dispatch);
    WriteParam(m, p.params);
}

bool ParamTraits<LogData>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    return ReadParam(m, iter, &r->channel) && ReadParam(m, iter, &r->routing_id) && ReadParam(m, iter, &r->type) && ReadParam(m, iter, &r->flags)
        && ReadParam(m, iter, &r->sent) && ReadParam(m, iter, &r->receive) && ReadParam(m, iter, &r->dispatch) && ReadParam(m, iter, &r->params);
}

void ParamTraits<LogData>::Log(const param_type& p, std::string* l)
{
    // Doesn't make sense to implement this!
}

void ParamTraits<Message>::Write(Message* m, const Message& p)
{
#if defined(OS_POSIX)
    // We don't serialize the file descriptors in the nested message, so there
    // better not be any.
    DCHECK(!p.HasFileDescriptors());
#endif

    // Don't just write out the message. This is used to send messages between
    // NaCl (Posix environment) and the browser (could be on Windows). The message
    // header formats differ between these systems (so does handle sharing, but
    // we already asserted we don't have any handles). So just write out the
    // parts of the header we use.
    //
    // Be careful also to use only explicitly-sized types. The NaCl environment
    // could be 64-bit and the host browser could be 32-bits. The nested message
    // may or may not be safe to send between 32-bit and 64-bit systems, but we
    // leave that up to the code sending the message to ensure.
    m->WriteUInt32(static_cast<uint32>(p.routing_id()));
    m->WriteUInt32(p.type());
    m->WriteUInt32(p.flags());
    m->WriteData(p.payload_bytes());
}

bool ParamTraits<Message>::Read(const Message* m, base::PickleIterator* iter, Message* r)
{
    uint32 routing_id, type, flags;
    if (!iter->ReadUInt32(&routing_id) || !iter->ReadUInt32(&type) || !iter->ReadUInt32(&flags))
        return false;

    size_t payload_size = 0;
    const char* payload;
    if (!iter->ReadData(&payload, &payload_size))
        return false;

    r->SetHeaderValues(static_cast<int32>(routing_id), type, flags);
    r->WriteBytes(payload, payload_size);
    return true;
}

void ParamTraits<Message>::Log(const Message& p, std::string* l)
{
    l->append("<IPC::Message>");
}

#if defined(OS_WIN)
// Note that HWNDs/HANDLE/HCURSOR/HACCEL etc are always 32 bits, even on 64
// bit systems.
void ParamTraits<HANDLE>::Write(Message* m, const param_type& p)
{
    m->WriteUInt32(reinterpret_cast<uint32>(p));
}

bool ParamTraits<HANDLE>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    uint32 temp;
    if (!iter->ReadUInt32(&temp))
        return false;
    *r = reinterpret_cast<HANDLE>(temp);
    return true;
}

void ParamTraits<HANDLE>::Log(const param_type& p, std::string* l)
{
    char output[100] = { 0 };
    sprintf(output, "0x%X", p);
    l->append(output);
}

void ParamTraits<LOGFONT>::Write(Message* m, const param_type& p)
{
    m->WriteData(reinterpret_cast<const char*>(&p), sizeof(LOGFONT));
}

bool ParamTraits<LOGFONT>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    const char* data;
    size_t data_size = 0;
    bool result = iter->ReadData(&data, &data_size);
    if (result && data_size == sizeof(LOGFONT)) {
        memcpy(r, data, sizeof(LOGFONT));
    } else {
        result = false;
        NOTREACHED();
    }

    return result;
}

void ParamTraits<LOGFONT>::Log(const param_type& p, std::string* l)
{
    l->append(base::StringPrintf("<LOGFONT>"));
}

void ParamTraits<MSG>::Write(Message* m, const param_type& p)
{
    m->WriteData(reinterpret_cast<const char*>(&p), sizeof(MSG));
}

bool ParamTraits<MSG>::Read(const Message* m, base::PickleIterator* iter, param_type* r)
{
    const char* data;
    size_t data_size = 0;
    bool result = iter->ReadData(&data, &data_size);
    if (result && data_size == sizeof(MSG)) {
        memcpy(r, data, sizeof(MSG));
    } else {
        result = false;
        NOTREACHED();
    }

    return result;
}

void ParamTraits<MSG>::Log(const param_type& p, std::string* l)
{
    l->append("<MSG>");
}

#endif // OS_WIN

} // namespace IPC
