
#include "content/renderer/BlobRegistryImpl.h"

#include "content/renderer/BlobURLStoreImpl.h"
#include "content/common/common.h"
#include "content/common/ThreadCall.h"
#include "content/common/CreateAndBindTempl.h"
#include "third_party/blink/renderer/platform/blob/blob_data.h"
#include "third_party/blink/public/mojom/blob/blob.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/data_element.mojom-forward.h"
#include "third_party/blink/public/mojom/blob/data_element.mojom.h"
#include "services/network/public/mojom/data_pipe_getter.mojom-blink.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "url/url_util.h"
#include "base/files/file.h"
#include "base/files/file_util.h"
#include "base/strings/string_util.h"
#include "base/task/thread_pool.h"
#include <windows.h>

namespace mbnet {
void pushBackToBuffer(std::vector<char>* buf, const char* data, size_t len);
}

bool ::blink::mojom::BlobRegistry::Register(::mojo::PendingReceiver<::blink::mojom::Blob> blob, const std::string& uuid, const std::string& content_type,
    const std::string& content_disposition, std::vector<::blink::mojom::DataElementPtr> elements)
{
    content::printFuncName(__FUNCTION__, true, true);
    return false;
}

bool ::blink::mojom::blink::BlobRegistry::Register(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid,
    const WTF::String& content_type, const WTF::String& content_disposition, WTF::Vector<::blink::mojom::blink::DataElementPtr> elements)
{
    content::printFuncName(__FUNCTION__, true, true);
    return false;
}

// bool ::blink::mojom::blink::BlobRegistry::GetBlobFromUUID(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }
// 
// bool ::blink::mojom::BlobRegistry::GetBlobFromUUID(::mojo::PendingReceiver<::blink::mojom::Blob> blob, const std::string& uuid)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }

bool blink::mojom::blink::Blob::CaptureSnapshot(uint64_t* out_length, absl::optional<::base::Time>* out_modification_time)
{
    content::printFuncName(__FUNCTION__, true, true);
    return false;
}

namespace content {

class BlobReceiver;
class DataElementImpl;

static ::base::FilePath standardizationFilePath(const ::base::FilePath& path)
{
    std::string result = path.AsUTF8Unsafe();
    if (base::StartsWith(result, "file:///", base::CompareCase::INSENSITIVE_ASCII))
        result = result.substr(sizeof("file:///") - 1);

    url::RawCanonOutputT<char16_t> unescaped;
    url::DecodeURLEscapeSequences(std::string_view(result.data(), result.size()), url::DecodeURLMode::kUTF8OrIsomorphic, &unescaped);
    return base::FilePath::FromUTF16Unsafe(std::u16string_view(unescaped.data(), base::checked_cast<wtf_size_t>(unescaped.length())));
}

std::map<std::string, BlobEntry*>* s_blobEntrys = nullptr;

class BlobReceiver : public ::blink::mojom::blink::Blob {
public:
    BlobReceiver(/*BlobEntry* blobEntry*/ const std::string& uuid)
    {
        //m_blobEntry = blobEntry;
        m_uuid = uuid;

        //char output[100] = { 0 };
        //sprintf(output, "BlobReceiver: %p, %d\n", this, s_blobEntrys->size());
        //OutputDebugStringA(output);
    }

    ~BlobReceiver()
    {
        std::map<std::string, BlobEntry*>::const_iterator it = s_blobEntrys->find(m_uuid);
        CHECK(it != s_blobEntrys->end());
        BlobEntry* blobEntry = it->second;
        blobEntry->m_blobReceiverRefCount--;
        if (0 == blobEntry->m_blobReceiverRefCount) {
            s_blobEntrys->erase(it);
            delete blobEntry;
        }

        //char output[100] = { 0 };
        //sprintf(output, "~~BlobReceiver: %p, %d\n", this, s_blobEntrys->size());
        //OutputDebugStringA(output);
    }

    void Clone(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob) override
    {
        //content::printFuncName(__FUNCTION__, true, false);

        BlobEntry* blobEntry = BlobEntry::findByUuid(m_uuid);
        CHECK(blobEntry);
        ++blobEntry->m_blobReceiverRefCount;

        createAndBindInterface<::blink::mojom::blink::Blob, BlobReceiver>(blob.PassPipe(), m_uuid);
    }

    class DataPipeGetterImpl : public ::network::mojom::blink::DataPipeGetter {
    public:
        DataPipeGetterImpl(std::string uuid)
        {
            m_uuid = uuid;
        }

        void Read(::mojo::ScopedDataPipeProducerHandle pipe, ReadCallback callback) override
        {
            BlobEntry* blobEntry = BlobEntry::findByUuid(m_uuid);
            if (!blobEntry) {
                pipe->WriteData(nullptr, 0, MOJO_WRITE_DATA_FLAG_NONE);
                std::move(callback).Run(0, 0);
            } else {
                std::vector<char> buffer;
                int64_t allSize = 0;
                blobEntry->read(&buffer, 0, -1, &allSize);

                uint32_t numBytes = buffer.size();
                pipe->WriteData(buffer.data(), &numBytes, MOJO_WRITE_DATA_FLAG_NONE);
                std::move(callback).Run(numBytes, numBytes);
            }
        }

        void Clone(::mojo::PendingReceiver<DataPipeGetter> receiver) override
        {
            createAndBindInterface<::network::mojom::blink::DataPipeGetter, DataPipeGetterImpl>(receiver.PassPipe(), m_uuid);
        }

    private:
        std::string m_uuid;
    };

    void AsDataPipeGetter(::mojo::PendingReceiver<::network::mojom::blink::DataPipeGetter> dataPipeGetter) override
    {
        content::printFuncName(__FUNCTION__, true, false); // !!!
        CHECK(!m_uuid.empty());
        createAndBindInterface<::network::mojom::blink::DataPipeGetter, DataPipeGetterImpl>(dataPipeGetter.PassPipe(), m_uuid);
    }

    void ReadAll(::mojo::ScopedDataPipeProducerHandle pipe, ::mojo::PendingRemote<::blink::mojom::blink::BlobReaderClient> client/*, bool isSync*/) override;

    void ReadRange(uint64_t offset, uint64_t length, ::mojo::ScopedDataPipeProducerHandle pipe,
        ::mojo::PendingRemote<::blink::mojom::blink::BlobReaderClient> client) override
    {
        content::printFuncName(__FUNCTION__, true, true);
    }

    void Load(::mojo::PendingReceiver<::network::mojom::blink::URLLoader> loader, const WTF::String& request_method, const ::net::HttpRequestHeaders& headers,
        ::mojo::PendingRemote<::network::mojom::blink::URLLoaderClient> client) override
    {
        content::printFuncName(__FUNCTION__, true, true);
    }

    //using ReadSideDataCallback = base::OnceCallback<void(absl::optional<::mojo_base::BigBuffer>)>;
    void ReadSideData(ReadSideDataCallback callback) override;

    bool CaptureSnapshot(uint64_t* out_length, absl::optional<::base::Time>* out_modification_time) override
    {
        content::printFuncName(__FUNCTION__, true, true);
        return false;
    }

    //using CaptureSnapshotCallback = base::OnceCallback<void(uint64_t, absl::optional<::base::Time>)>;
    void CaptureSnapshot(CaptureSnapshotCallback callback) override
    {
        content::printFuncName(__FUNCTION__, true, true);
    }

    //using GetInternalUUIDCallback = base::OnceCallback<void(const WTF::String&)>;
    void GetInternalUUID(GetInternalUUIDCallback callback) override
    {
        content::printFuncName(__FUNCTION__, false, false);
        std::move(callback).Run(WTF::String::FromUTF8(m_uuid));
    }

    void onReadAllFinish(uint64_t totalSize);

    //BlobEntry* m_blobEntry = nullptr;
    std::string m_uuid;
    //BlobReceiver* m_cloneBlob = nullptr;

    ::mojo::ScopedDataPipeProducerHandle m_pipe;
    ::mojo::Remote<::blink::mojom::blink::BlobReaderClient> m_client;

    mojo::Receiver<::blink::mojom::blink::Blob> m_receiver { this };
    base::WeakPtrFactory<BlobReceiver> m_weakFactory { this };
};

enum class DataElementType : uint32_t {
    kBytes,
    kFile,
    kBlob,
};

class DataElementBytesImpl {
public:
    uint64_t length; // 按理说这个长度要么=0，要么等于embeddedData的长度。不知道有没反例出现。不确定
    std::vector<uint8_t> embeddedData;
};

class DataElementFileImpl {
public:
    ::base::FilePath path;
    uint64_t offset;
    uint64_t length;
    absl::optional<::base::Time> expectedModificationTime;
};

class DataElementBlobImpl {
public:
    //::mojo::Remote<::blink::mojom::blink::Blob> blob;
    //BlobReceiver* blobReceiver = nullptr;
    ~DataElementBlobImpl();
    std::string uuid;
    uint64_t offset;
    uint64_t length;
};

class DataElementImpl {
public:
    DataElementType tag;
    union {
        DataElementBytesImpl* bytes;
        DataElementFileImpl* file;
        DataElementBlobImpl* blob;
    } u;
};

void BlobReceiver::onReadAllFinish(uint64_t totalSize)
{
    if (m_client.is_bound() && m_client.TryGet())
        m_client->OnCalculatedSize(totalSize, totalSize);

    if (m_client.is_bound() && m_client.TryGet())
        m_client->OnComplete(0, totalSize);

    if (m_client.is_bound())
        m_client.Unbind();
}

void BlobReceiver::ReadAll(::mojo::ScopedDataPipeProducerHandle pipe, ::mojo::PendingRemote<::blink::mojom::blink::BlobReaderClient> client/*, bool isSync*/)
{
    bool isSync = false;
    m_pipe = std::move(pipe);

    bool needBind = false;
    if (m_client.is_bound()) {
        if (client.is_valid() && (client.Pipe().get().value() != m_client.internal_state()->handle().value())) {
            m_client.Unbind();
            needBind = true;
        }
    } else if (client.is_valid()) {
        needBind = true;
    }

    if (needBind)
        m_client.Bind(std::move(client));

    uint64_t totalSize = 0;

    BlobEntry* blobEntry = BlobEntry::findByUuid(m_uuid);

    for (size_t i = 0; blobEntry && i < blobEntry->m_elements.size(); ++i) {
        DataElementImpl* ele = blobEntry->m_elements[i];
        if (ele->tag == DataElementType::kBytes) {
            totalSize += ele->u.bytes->length;

            uint32_t numBytes = ele->u.bytes->embeddedData.size();
            m_pipe->WriteData(ele->u.bytes->embeddedData.data(), &numBytes, 0);
        } else if (ele->tag == DataElementType::kFile) {
            std::string contents;
            if (!base::ReadFileToString(standardizationFilePath(ele->u.file->path), &contents))
                continue;

            uint32_t numBytes = ele->u.file->length;
            if (ele->u.file->offset >= contents.size())
                continue;
            if (ele->u.file->offset + numBytes >= contents.size())
                numBytes = contents.size() - ele->u.file->offset;
            totalSize += numBytes;

            m_pipe->WriteData(contents.c_str(), &numBytes, 0);
        } else if (ele->tag == DataElementType::kBlob) {
            DataElementBlobImpl* blob = ele->u.blob;
            BlobEntry* childBlobEntry = BlobEntry::findByUuid(blob->uuid);
            if (!childBlobEntry)
                continue;
            std::vector<char> buffer;
            int64_t allSize = 0;
            childBlobEntry->read(&buffer, blob->offset, blob->length, &allSize);

            uint32_t numBytes = buffer.size();
            m_pipe->WriteData(buffer.data(), &numBytes, 0);
            totalSize += numBytes;
        } else
            DebugBreak();
    }

    if (isSync)
        onReadAllFinish(totalSize);
    else
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce(&BlobReceiver::onReadAllFinish, m_weakFactory.GetWeakPtr(), totalSize));
}

void BlobReceiver::ReadSideData(ReadSideDataCallback callback)
{
    // 目前只在LocalFrameHostImpl::DownloadURL里用到，所以本函数简化了实现
    uint64_t totalSize = 0;

    BlobEntry* blobEntry = BlobEntry::findByUuid(m_uuid);
    CHECK(blobEntry->m_elements.size() == 1);

    for (size_t i = 0; blobEntry && i < blobEntry->m_elements.size(); ++i) {
        DataElementImpl* ele = blobEntry->m_elements[i];
        if (ele->tag == DataElementType::kBytes) {
            totalSize += ele->u.bytes->length;

            uint32_t numBytes = ele->u.bytes->embeddedData.size();
            ::mojo_base::BigBuffer buf(base::span<const uint8_t>(ele->u.bytes->embeddedData.data(), numBytes));
            std::optional<::mojo_base::BigBuffer> bufOpt(std::move(buf));
            std::move(callback).Run(std::move(bufOpt));
        } else {
            CHECK(false);
        }
    }
}

struct WaitForDataInfo {
    ::mojo::Remote<blink::mojom::blink::BytesProvider> bytesProvider;
    DataElementImpl* dataEle = nullptr;
    bool waitCount = 0;

    void waitForData()
    {
        scoped_refptr<base::SequencedTaskRunner> runner = bytesProvider.GetReceiverTaskRunner();
        runner->PostTask(FROM_HERE, base::BindOnce([](WaitForDataInfo* self) { self->waitForDataImpl(); }, this));

        while (waitCount == 0) {
            ::Sleep(1);
        }
    }

private:
    void waitForDataImpl()
    {
        bytesProvider->RequestAsReply(base::BindOnce(
            [](WaitForDataInfo* self, const WTF::Vector<uint8_t>& bytes) {
                self->dataEle->u.bytes->embeddedData.resize(bytes.size());
                memcpy(self->dataEle->u.bytes->embeddedData.data(), bytes.data(), bytes.size());
                self->waitCount = 1;
            },
            this));
    }
};

BlobEntry::BlobEntry(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const std::string& uuid, const std::string& contentType,
    const std::string& contentDisposition, WTF::Vector<::blink::mojom::blink::DataElementPtr> elements)
{
    createAndBindInterface<::blink::mojom::blink::Blob, BlobReceiver>(blob.PassPipe(), uuid);
    m_blobReceiverRefCount++;
    m_uuid = uuid;
    m_contentType = contentType;
    m_contentDisposition = contentDisposition;

    for (size_t i = 0; i < elements.size(); ++i) {
        blink::mojom::blink::DataElementPtr ele(std::move(elements[i]));
        if (ele->is_bytes()) {
            DataElementImpl* dataEle = new DataElementImpl();
            dataEle->tag = DataElementType::kBytes;
            dataEle->u.bytes = new DataElementBytesImpl();
            dataEle->u.bytes->length = ele->get_bytes()->length;

            if (ele->get_bytes()->embedded_data.has_value() && ele->get_bytes()->embedded_data->size() > 0) {
                CHECK(ele->get_bytes()->embedded_data->size() == dataEle->u.bytes->length);
                dataEle->u.bytes->embeddedData.resize(ele->get_bytes()->embedded_data->size());
                memcpy(dataEle->u.bytes->embeddedData.data(), ele->get_bytes()->embedded_data.value().data(), ele->get_bytes()->embedded_data->size());
            } else if (ele->get_bytes()->data.is_valid()) {
                WaitForDataInfo* info = new WaitForDataInfo();
                info->dataEle = dataEle;
                info->bytesProvider.Bind(std::move(ele->get_bytes()->data));
                info->waitForData();
            }
            //CHECK(!(ele->get_bytes()->data.is_valid())); // 这个ele->get_bytes()->data暂时没搞明白有啥用

            m_elements.push_back(dataEle);
        } else if (ele->is_blob()) {
            DataElementImpl* dataEle = new DataElementImpl();
            dataEle->tag = DataElementType::kBlob;
            dataEle->u.blob = new DataElementBlobImpl();

            //BlobReceiver* cloneBlob = new BlobReceiver(nullptr);
            //cloneBlob->m_receiver.Bind(std::move(ele->get_blob()->blob)); // TODO: 内存泄露
            //dataEle->u.blob->blobReceiver = cloneBlob;

            // ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob;
            ::mojo::Remote<::blink::mojom::blink::Blob> blob;
            blob.Bind(std::move(ele->get_blob()->blob));

            blob->GetInternalUUID(base::BindOnce([](DataElementImpl* dataEle, const WTF::String& uid) { dataEle->u.blob->uuid = uid.Ascii(); }, dataEle));

            dataEle->u.blob->offset = ele->get_blob()->offset;
            dataEle->u.blob->length = ele->get_blob()->length;
            m_elements.push_back(dataEle);
        } else if (ele->is_file()) {
            DataElementImpl* dataEle = new DataElementImpl();
            dataEle->tag = DataElementType::kFile;
            dataEle->u.file = new DataElementFileImpl();
            dataEle->u.file->path = ele->get_file()->path;
            dataEle->u.file->offset = ele->get_file()->offset;
            dataEle->u.file->length = ele->get_file()->length;
            dataEle->u.file->expectedModificationTime = ele->get_file()->expected_modification_time;
            m_elements.push_back(dataEle);
        }
    }
}

BlobEntry::~BlobEntry()
{
    for (size_t i = 0; i < m_elements.size(); ++i) {
        DataElementImpl* ele = m_elements[i];
        delete ele;
    }
}

DataElementBlobImpl::~DataElementBlobImpl()
{
    BlobEntry* blob = BlobEntry::findByUuid(uuid);
    if (!blob)
        return;
}

BlobEntry* BlobEntry::findByUuid(const std::string& uuid)
{
    BlobEntry* blobEntry = nullptr;
    std::map<std::string, BlobEntry*>::const_iterator it = s_blobEntrys->find(uuid);
    if (it != s_blobEntrys->end())
        blobEntry = it->second;
    return blobEntry;
}

static void calcReadSize(int64_t len, int64_t elementSize, int64_t* readedLen, int64_t* remaindNeedReadLen, int64_t* startIt)
{
    if (len == -1) {
        *readedLen = elementSize - *startIt;
        return;
    }
    if (*startIt + *remaindNeedReadLen >= elementSize) { // 如果超出了本长度
        *readedLen = elementSize - *startIt;
        *remaindNeedReadLen -= *readedLen;
    } else {
        *readedLen = *remaindNeedReadLen;
        *remaindNeedReadLen = 0;
    }
    *startIt = 0;
}

// 返回读了多少
int64_t BlobEntry::read(std::vector<char>* buffer, int64_t start, int64_t len, int64_t* allSize)
{
    // 读了本次以后，有可能所有的bytes还不够len的长度，还需要到下一个element去读。
    // 例如----- ---- ---
    //       ----------
    // len==-1表示全读
    //
    int64_t remaindNeedReadLen = len; // 还剩下多少要读
    int64_t startIt = start;
    int64_t allReadedLen = 0; // 已经读了多少
    for (size_t i = 0; i < m_elements.size(); ++i) {
        int64_t readedLen = 0;
        int64_t startItCopy = startIt;

        if (DataElementType::kBytes == m_elements[i]->tag) {
            DataElementBytesImpl* bytes = m_elements[i]->u.bytes;
            size_t embedSize = bytes->embeddedData.size();
            *allSize += embedSize;
            if (startIt >= embedSize || embedSize == 0) {
                startIt -= embedSize;
                continue;
            }

            calcReadSize(len, embedSize, &readedLen, &remaindNeedReadLen, &startIt);
            mbnet::pushBackToBuffer(buffer, (const char*)(bytes->embeddedData.data()) + startItCopy, readedLen);
            allReadedLen += readedLen;
        } else if (DataElementType::kFile == m_elements[i]->tag) {
            base::File file(standardizationFilePath(m_elements[i]->u.file->path), base::File::FLAG_READ | base::File::FLAG_OPEN);
            if (!file.IsValid())
                continue;
            base::File::Info info;
            if (!file.GetInfo(&info))
                continue;
            *allSize += info.size;
            if (startIt >= info.size) {
                startIt -= info.size;
                continue;
            }

            calcReadSize(len, info.size, &readedLen, &remaindNeedReadLen, &startIt);
            std::vector<char> temp;
            temp.resize((size_t)readedLen);
            file.Seek(base::File::FROM_BEGIN, startItCopy);
            file.ReadAtCurrentPos(temp.data(), (int)temp.size());
            mbnet::pushBackToBuffer(buffer, temp.data(), temp.size());
            allReadedLen += readedLen;
        } else if (DataElementType::kBlob == m_elements[i]->tag) {
            BlobEntry* blobEntry = BlobEntry::findByUuid(m_elements[i]->u.blob->uuid);
            if (!blobEntry)
                continue;
            int64_t blobSize = 0;
            readedLen = blobEntry->read(buffer, startIt, remaindNeedReadLen, &blobSize);
            if (len != -1) {
                allReadedLen += readedLen;
                remaindNeedReadLen -= readedLen;
            }
            if (readedLen > 0) {
                startIt = 0; // 只要读过，循环的下一次的读取位置就是0了
            } else if (blobSize) { // 如果没读过，则减去跳了多少
                CHECK(startIt >= blobSize);
                startIt -= blobSize;
            }
        }

        if (len == -1 || remaindNeedReadLen > 0)
            continue;
        break;
    }
    return allReadedLen;
}

//-----

BlobRegistryImpl::BlobRegistryImpl()
{
    if (!s_blobEntrys)
        s_blobEntrys = new std::map<std::string, BlobEntry*>();
}

BlobRegistryImpl::~BlobRegistryImpl()
{
    //OutputDebugStringA("~BlobRegistryImpl\n");
}

bool BlobRegistryImpl::Register(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, const WTF::String& contentType,
    const WTF::String& contentDisposition, WTF::Vector<::blink::mojom::blink::DataElementPtr> elements)
{
    //content::printFuncName(__FUNCTION__, true, false);
    //CHECK(elements.size() == 1 || elements.size() == 0);

    std::map<std::string, BlobEntry*>::const_iterator it = s_blobEntrys->find(uuid.Ascii());
    CHECK(it == s_blobEntrys->end());
    ((*s_blobEntrys)[uuid.Ascii()]) = (new BlobEntry(std::move(blob), uuid.Ascii(), contentType.Ascii(), contentDisposition.Ascii(), std::move(elements)));

    return true;
}

void BlobRegistryImpl::Register(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, const WTF::String& content_type,
    const WTF::String& content_disposition, WTF::Vector<::blink::mojom::blink::DataElementPtr> elements,
    ::blink::mojom::blink::BlobRegistry::RegisterCallback callback)
{
    content::printFuncName(__FUNCTION__, true, true);
}

struct RegisterFromStreamAsyncCall {
    ::blink::mojom::blink::BlobRegistry::RegisterFromStreamCallback callback;
    ::mojo::ScopedDataPipeConsumerHandle data;
    mojo::SimpleWatcher dataPipeCloseWatcher;

    RegisterFromStreamAsyncCall()
        : dataPipeCloseWatcher(FROM_HERE, mojo::SimpleWatcher::ArmingPolicy::AUTOMATIC)
    {
    }

    void start()
    {
        dataPipeCloseWatcher.Watch(data.get(), MOJO_HANDLE_SIGNAL_PEER_CLOSED, MOJO_TRIGGER_CONDITION_SIGNALS_SATISFIED,
            base::BindRepeating(&RegisterFromStreamAsyncCall::OnPeerClosed, base::Unretained(this)));
    }

    void OnPeerClosed(MojoResult result, const mojo::HandleSignalsState& state)
    {
        const char* buffer = nullptr;
        uint32_t bufferNumBytes = 0;
        data->BeginReadData((const void**)(&buffer), &bufferNumBytes, MOJO_READ_DATA_FLAG_NONE); // 不需要end，因为这里把数据都读完了

        std::unique_ptr<blink::BlobData> blobData = base::WrapUnique(new blink::BlobData(blink::BlobData::FileCompositionStatus::kNoUnknownSizeFiles));
        scoped_refptr<blink::RawData> rawData = blink::RawData::Create();
        rawData->MutableData()->Append(buffer, bufferNumBytes);
        blobData->AppendData(rawData);
        scoped_refptr<blink::BlobDataHandle> blobDataHandle = blink::BlobDataHandle::Create(std::move(blobData), bufferNumBytes);

        RegisterFromStreamAsyncCall* self = this;
        std::move(self->callback).Run(blobDataHandle);

        ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self] { // 感觉异步删除比较好一点
            delete self;
        });
    }
};

//using RegisterFromStreamCallback = base::OnceCallback<void(const ::scoped_refptr<::blink::BlobDataHandle>&)>;
void BlobRegistryImpl::RegisterFromStream(const WTF::String& contentType, const WTF::String& contentDisposition, uint64_t lengthHint,
    ::mojo::ScopedDataPipeConsumerHandle data, ::mojo::PendingAssociatedRemote<::blink::mojom::blink::ProgressClient> progressClient,
    RegisterFromStreamCallback callback)
{
    RegisterFromStreamAsyncCall* asyncCall = new RegisterFromStreamAsyncCall();
    asyncCall->callback = std::move(callback);
    asyncCall->data = std::move(data);
    asyncCall->start();
}

// bool BlobRegistryImpl::GetBlobFromUUID(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }
// 
// //using GetBlobFromUUIDCallback = base::OnceCallback<void()>;
// void BlobRegistryImpl::GetBlobFromUUID(
//     ::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, ::blink::mojom::blink::BlobRegistry::GetBlobFromUUIDCallback callback)
// {
//     content::printFuncName(__FUNCTION__, true, true);
// }
// 
// void BlobRegistryImpl::URLStoreForOrigin(
//     const ::scoped_refptr<const ::blink::SecurityOrigin>& origin, ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::BlobURLStore> urlStore)
// {
//     //content::printFuncName(__FUNCTION__, true, true);
// 
//     //m_blobURLStoreReceiver = new mojo::AssociatedReceiver<::blink::mojom::blink::BlobURLStore>(new BlobURLStoreImpl(origin));
//     //m_blobURLStoreReceiver->Bind(std::move(url_store));
// 
//     createAndBindInterface<::blink::mojom::blink::BlobURLStore, BlobURLStoreImpl>(std::move(urlStore.PassPipe()), origin);
// }

}