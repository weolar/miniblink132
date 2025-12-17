
#include "content/browser/DomStorageProviderImpl.h"

#include "content/browser/MbWebview.h"
#include "content/common/CreateAndBindTempl.h"
#include "content/common/ThreadCall.h"
#include "content/common/StringConversions.h"
#include "content/renderer/WebViewClientImpl.h"
#include "third_party/blink/renderer/core/page/chrome_client.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/exported/web_view_impl.h"
#include "third_party/blink/renderer/modules/storage/storage_area_map.h"
#include "third_party/blink/renderer/modules/storage/cached_storage_area.h"
#include "third_party/blink/public/mojom/dom_storage/dom_storage.mojom-blink.h"
#include "third_party/blink/public/mojom/dom_storage/storage_area.mojom-blink.h"
#include "third_party/blink/public/mojom/dom_storage/session_storage_namespace.mojom-blink.h"
#include "third_party/blink/public/platform/file_path_conversion.h"
#include "third_party/blink/renderer/platform/wtf/text/string_builder.h"
#include "third_party/blink/renderer/platform/wtf/text/string_buffer.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "base/strings/utf_string_conversions.h"

bool ::blink::mojom::blink::StorageArea::GetAll(
    mojo::PendingRemote<::blink::mojom::blink::StorageAreaObserver>, WTF::Vector<::blink::mojom::blink::KeyValuePtr>*)
{
    DebugBreak();
    return false;
}

namespace content {

class StorageAreaImpl;
//static const char* kLocalStorageExtensionName = ".localstorage";

static const char* kSeparator = "--mb-sep--\n";
static size_t kSeparatorLength = 11;

static const char* kEmptySeprator = "--mb-ept--"; // (char)0x1f;
static size_t kEmptySepratorLength = 10;

class StorageAreaImplMgr {
public:
    static WTF::String buildFileNameStringByStorageKey(bool isLocal, const ::blink::BlinkStorageKey& storageKey)
    {
        WTF::String name = buildFileName(storageKey);
        WTF::String key = storageKey.ToDebugString();
        unsigned hash = WTF::HashTraits<String>::GetHash(key);

        return WTF::String::Format(isLocal ? "local_%s_%d.localsto" : "session_%s_%d.localsto", name.Utf8().c_str(), hash);
    }

    static StorageAreaImplMgr* get();

    StorageAreaImpl* findOrCreateByStorageKey(bool isLocal, const ::blink::BlinkStorageKey& storageKey);

private:
    static String buildFileName(const ::blink::BlinkStorageKey& storageKey)
    {
        const scoped_refptr<const blink::SecurityOrigin>& orig = storageKey.GetSecurityOrigin();

        WTF::StringBuilder builder;
        String origin = orig->Protocol();
        if (orig->Protocol() == "file") {
            return "file";
        }

        builder.Append(orig->Protocol());
        builder.Append("_");
        builder.Append(orig->Host());

        if (true /*orig->HasPort()*/) {
            builder.Append('_');
            builder.Append(String::Number(orig->Port()));
        }
        return builder.ToString();
    }

    WTF::HashMap<String, StorageAreaImpl*> m_areas;
};

class StorageAreaImpl {
public:
    StorageAreaImpl(bool isLocal, const ::blink::BlinkStorageKey& storageKey)
    {
        m_isLocal = isLocal;
        m_storageKey = storageKey;
    }

    bool isLocal() const { return m_isLocal; }

    void setStorageAreaMap(blink::StorageAreaMap* areaMap)
    {
        m_areaMap = areaMap;
    }

    String getItem(const String& key, bool* found) const
    {
        *found = false;
        if (!m_areaMap)
            return g_empty_string;

        *found = true;
        return m_areaMap->GetItem(key);
    }

    unsigned getLength()
    {
        if (!m_areaMap)
            return 0;
        return m_areaMap->GetLength();
    }

    void destroy()
    {
        if (m_isDestroying)
            return;
        m_isDestroying = true;
        StorageAreaImpl* self = this;
        ThreadCall::callBlinkThreadDelayed(FROM_HERE, [self] { delete self; }, 5000);
    }

    void toSave()
    {
        if (m_isSaving || m_isDestroying)
            return;
        m_isSaving = true;
        StorageAreaImpl* self = this;
        ThreadCall::callBlinkThreadDelayed(FROM_HERE, [self] { self->delaySave(); }, 1500);
    }

    void loadFromFile(const base::FilePath& localPathDir, WTF::Vector<::blink::mojom::blink::KeyValuePtr>* outData)
    {
        if (!m_isLocal)
            return;

        if (m_localPath.empty()) {
            String localStorage = StorageAreaImplMgr::buildFileNameStringByStorageKey(m_isLocal, m_storageKey);
            base::FilePath localPath = localPathDir;
            m_localPath = localPath.Append(blink::StringToFilePath(localStorage));
        }

        std::string buffer;
        if (!base::ReadFileToString(m_localPath, &buffer))
            return;

        if (buffer.size() < kSeparatorLength || 0 != strncmp(kSeparator, &buffer[buffer.size() - kSeparatorLength], kSeparatorLength))
            buffer.append(kSeparator, kSeparatorLength);

        loadFromBufferImpl(buffer, outData);
    }

    // look: CachedStorageArea::Uint8VectorToString
    static void StringToUint8Vector(WTF::Vector<uint8_t>* buf)
    {
        //const char* src, size_t src_len, std::u16string* output
        std::u16string output;
        if (base::UTF8ToUTF16((const char*)buf->data(), buf->size(), &output)) {
            buf->clear();
            buf->resize(1 + output.size() * sizeof(char16_t));
            (*buf)[0] = 0; // StorageFormat::UTF16
            memcpy(buf->data() + 1, output.data(), output.size() * sizeof(char16_t));
        }
    }

    static String Uint8VectorToString(const Vector<uint8_t>& input, blink::CachedStorageArea::FormatOption format_option)
    {
        if (input.empty())
            return g_empty_string;
        const wtf_size_t input_size = input.size();
        String result;
        bool corrupt = false;

        /*StorageFormat*/uint8_t format = static_cast<uint8_t>(input[0]);
        const wtf_size_t payload_size = input_size - 1;
        switch (format) {
            case /*StorageFormat::UTF16*/0:
            {
                if (payload_size % sizeof(UChar) != 0) {
                    corrupt = true;
                    break;
                }
                WTF::StringBuffer<UChar> buffer(payload_size / sizeof(UChar));
                std::memcpy(buffer.Characters(), input.data() + 1, payload_size);
                result = String::Adopt(buffer);
                break;
            }
            case /*StorageFormat::Latin1*/1:
                result = String(base::span(input.data(), input.size()).subspan(1));
                break;
            default:
                corrupt = true;
        }
        if (corrupt) {
            // TODO(mek): Better error recovery when corrupt (or otherwise invalid) data
            // is detected.
            return g_empty_string;
        }
        return result;
    }

private:
    void loadFromBufferImpl(const std::string& buffer, WTF::Vector<::blink::mojom::blink::KeyValuePtr>* outData)
    {
        const char* pos = &buffer[0];
        bool isKey = true;
        WTF::Vector<uint8_t> key;
        WTF::Vector<uint8_t> value;
        for (size_t i = 0; i < buffer.size() - kSeparatorLength + 1; ++i) {
            if (0 != strncmp(kSeparator, &buffer[i], kSeparatorLength))
                continue;

            const char* posEnd = &buffer[i];
            WTF::Vector<uint8_t> keyOrValue;
            keyOrValue.resize(posEnd - pos);
            memcpy(keyOrValue.data(), pos, keyOrValue.size());
            if (isKey) {
                key = keyOrValue;
            } else {
                value = keyOrValue;
                if (value.size() == kEmptySepratorLength && 0 == strncmp((const char*)value.data(), kEmptySeprator, kEmptySepratorLength))
                    value.clear();

                if (0 != key.size()) {
                    StringToUint8Vector(&key);
                    StringToUint8Vector(&value);
                    ::blink::mojom::blink::KeyValuePtr keyValue = ::blink::mojom::blink::KeyValue::New(key, value);
                    outData->push_back(std::move(keyValue));
                }
            }
            pos = posEnd + kSeparatorLength;
            isKey = !isKey;
            i += kSeparatorLength;
        }

        //////////////////////////////////////////////////////////////////////////
        //     DOMStorageMap::iterator it1 = m_cachedArea->begin();
        //     for (; it1 != m_cachedArea->end(); ++it1) {
        //         String path = it1->key;
        //         HashMap<String, String>* pageStorageArea2 = it1->value;
        //         HashMap<String, String>::iterator itor2 = pageStorageArea2->begin();
        //         for (; itor2 != pageStorageArea2->end(); ++itor2) {
        //             String keyStr = itor2->key;
        //             String valueStr = itor2->value;
        //
        //             String output = String::format("WebStorageAreaImpl::loadFromBufferImpl: %s , %s , %s\n", path.utf8().data(), keyStr.utf8().data(), valueStr.utf8().data());
        //             OutputDebugStringA(output.utf8().data());
        //         }
        //     }
        //////////////////////////////////////////////////////////////////////////
    }

    void delaySave()
    {
        if (!m_areaMap || !m_isLocal)
            return;

        std::string buffer;
        const unsigned length = m_areaMap->GetLength();
        for (size_t i = 0; i < length; ++i) {
            String key = m_areaMap->GetKey(i);
            std::string keyBuffer = key.Utf8();
            const String& value = m_areaMap->GetItem(key);
            std::string valueBuffer = value.Utf8();

            if (0 == keyBuffer.size())
                buffer.append(kEmptySeprator, kEmptySepratorLength);
            else
                buffer.append(keyBuffer.data(), keyBuffer.size());
            buffer.append(kSeparator, kSeparatorLength);

            if (0 == valueBuffer.size())
                buffer.append(kEmptySeprator, kEmptySepratorLength);
            else
                buffer.append(valueBuffer.data(), valueBuffer.size());
            buffer.append(kSeparator, kSeparatorLength);
        }

        m_isSaving = false;
        base::FilePath dir = m_localPath.DirName();
        if (!base::DirectoryExists(dir)) {
            base::File::Error error;
            bool b = base::CreateDirectoryAndGetError(dir, &error);
            if (!base::DirectoryExists(dir)) {
                return;
            }
        }
        if (buffer.size() == 0) {
            base::DeleteFile(m_localPath);
            return;
        }
        base::WriteFile(m_localPath, std::string_view(buffer.data(), buffer.size()));
    }

    bool m_isLocal;
    bool m_isSaving = false;
    bool m_isDestroying = false;
    base::FilePath m_localPath;
    blink::StorageAreaMap* m_areaMap = nullptr;
    blink::BlinkStorageKey m_storageKey;
};

StorageAreaImplMgr* StorageAreaImplMgr::get()
{
    static StorageAreaImplMgr* s_inst = nullptr;
    if (!s_inst)
        s_inst = new StorageAreaImplMgr();
    return s_inst;
}

StorageAreaImpl* StorageAreaImplMgr::findOrCreateByStorageKey(bool isLocal, const ::blink::BlinkStorageKey& storageKey)
{
    WTF::String key = buildFileNameStringByStorageKey(isLocal, storageKey);
    WTF::HashMap<String, StorageAreaImpl*>::iterator it = m_areas.find(key);
    if (it != m_areas.end())
        return it->value;

    StorageAreaImpl* result = new StorageAreaImpl(isLocal, storageKey);
    m_areas.insert(key, result);
    return result;
}

static base::FilePath getLocalStorageDirByLocalFrameToken(const ::blink::LocalFrameToken& localFrameToken)
{
    base::FilePath result;

    blink::LocalFrame* frame = blink::LocalFrame::FromFrameToken(localFrameToken);
    if (!frame)
        return result;
    blink::LocalFrameView* view = frame->View();
    if (!view)
        return result;
    blink::ChromeClient* chromeClient = view->GetChromeClient();
    if (!chromeClient)
        return result;
    blink::WebViewImpl* webviewimpl = chromeClient->GetWebView();
    if (!webviewimpl)
        return result;
    WebViewClientImpl* client = (WebViewClientImpl*)webviewimpl->Client();
    if (!client)
        return result;
    MbWebView* mbwebview = client->getMbwebview();
    if (!mbwebview)
        return result;

    result = mbwebview->getLocalStorageDir();
    return result;
}

int s_StorageAreaStub = 0;

class StorageAreaStub : public ::blink::mojom::blink::StorageArea {
public:
    StorageAreaStub(bool isLocal, const ::blink::BlinkStorageKey& storageKey, const ::blink::LocalFrameToken& localFrameToken)
    {
        s_StorageAreaStub++;
        m_localStorageDir = getLocalStorageDirByLocalFrameToken(localFrameToken);
        m_impl = StorageAreaImplMgr::get()->findOrCreateByStorageKey(isLocal, storageKey);

        m_impl->loadFromFile(m_localStorageDir, &m_outData);
    }

    ~StorageAreaStub()
    {
        s_StorageAreaStub--;
    }

    void addObserverImpl(::mojo::PendingRemote<::blink::mojom::blink::StorageAreaObserver> observer)
    {
        CHECK(ThreadCall::isBlinkThread());
        mojo::Remote<::blink::mojom::blink::StorageAreaObserver> observerRemote(std::move(observer));

        // 清理掉那些已经失效的
        mojo::RemoteSet<::blink::mojom::blink::StorageAreaObserver> newObservers;
        for (mojo::RemoteSet<::blink::mojom::blink::StorageAreaObserver>::Iterator it = (m_observers.begin()); 
            it != m_observers.end();) {
            ::mojo::Remote<::blink::mojom::blink::StorageAreaObserver>& observer = (::mojo::Remote<::blink::mojom::blink::StorageAreaObserver>&)(*it);
            if (observer.TryGet()) {
                CHECK(observer.is_bound());
                newObservers.Add(std::move(observer));
            } else
                ++((mojo::RemoteSet<::blink::mojom::blink::StorageAreaObserver>::Iterator&)it);
        }
        m_observers.Clear();

        for (mojo::RemoteSet<::blink::mojom::blink::StorageAreaObserver>::Iterator it = (newObservers.begin());
            it != newObservers.end(); ++it) {
            ::mojo::Remote<::blink::mojom::blink::StorageAreaObserver>& observer = (::mojo::Remote<::blink::mojom::blink::StorageAreaObserver>&)(*it);
            m_observers.Add(std::move(observer));
        }

        if (observerRemote.is_bound())
            m_observers.Add(std::move(observerRemote));
    }

    // components/services/storage/dom_storage/storage_area_impl.cc
    void AddObserver(::mojo::PendingRemote<::blink::mojom::blink::StorageAreaObserver> observer) override
    {
        addObserverImpl(std::move(observer));
    }

    void SetStorageAreaMap(void* areaMap) override
    {
        m_impl->setStorageAreaMap((blink::StorageAreaMap*)areaMap);
    }

    enum DelayDispatchObserversType {
        kPut, kDelete, kDeleteAll
    };

    void delayDispatchObservers(DelayDispatchObserversType type,
        const WTF::Vector<uint8_t>& key,
        const WTF::Vector<uint8_t>& value, 
        const absl::optional<WTF::Vector<uint8_t>>& clientOldValue,
        const WTF::String& source, 
        base::OnceCallback<void(bool)> callback)
    {
        if (m_impl->isLocal()) {
            for (const auto& observer : m_observers) {
                if (!observer.TryGet())
                    continue;

                if (type == kPut) {
                    observer->KeyChanged(key, value, clientOldValue, source);
                } else if (type == kDelete) {
                    observer->KeyDeleted(key, std::nullopt, source);
                } else if (type == kDeleteAll) {
                    bool wasNonempty = (m_impl->getLength() == 0);
                    observer->AllDeleted(/*was_nonempty=*/wasNonempty, source);
                }
            }
        }
        std::move(callback).Run(true); // Key already has this value.
    }

    void Put(const WTF::Vector<uint8_t>& key, const WTF::Vector<uint8_t>& value, const absl::optional<WTF::Vector<uint8_t>>& clientOldValue,
        const WTF::String& source, PutCallback callback) override
    {
        CHECK(ThreadCall::isBlinkThread());
        //         char* ptr = (char*)malloc(key.size() + 1);
        //         memcpy(ptr, key.data(), key.size());
        //         ptr[key.size()] = 0;
        //
        //         char* ptr2 = (char*)malloc(value.size() + 1);
        //         memcpy(ptr2, value.data(), value.size());
        //         ptr[value.size()] = 0;

        if (m_impl->isLocal()) {
            base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, 
                base::BindOnce(&StorageAreaStub::delayDispatchObservers, base::Unretained(this), 
                    DelayDispatchObserversType::kPut, key, value, clientOldValue, source, std::move(callback)));
        }
        m_impl->toSave();
    }

    void Delete(const WTF::Vector<uint8_t>& key, const absl::optional<WTF::Vector<uint8_t>>& clientOldValue, const WTF::String& source,
        ::blink::mojom::blink::StorageArea::DeleteCallback callback) override
    {
        CHECK(ThreadCall::isBlinkThread());
        if (m_impl->isLocal()) {
            base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE,
                base::BindOnce(&StorageAreaStub::delayDispatchObservers, base::Unretained(this),
                    DelayDispatchObserversType::kDelete, key, WTF::Vector<uint8_t>(), std::nullopt, source, std::move(callback)));
        }

        m_impl->toSave();
    }

    void DeleteAll(const WTF::String& source, ::mojo::PendingRemote<::blink::mojom::blink::StorageAreaObserver> newObserver,
        ::blink::mojom::blink::StorageArea::DeleteAllCallback callback) override
    {
        CHECK(ThreadCall::isBlinkThread());
        addObserverImpl(std::move(newObserver));

        if (m_impl->isLocal()) {
            base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE,
                base::BindOnce(&StorageAreaStub::delayDispatchObservers, base::Unretained(this),
                    DelayDispatchObserversType::kDeleteAll, WTF::Vector<uint8_t>(), WTF::Vector<uint8_t>(), std::nullopt, source, std::move(callback)));
        }

        m_impl->toSave();
    }

    void Get(const WTF::Vector<uint8_t>& key, ::blink::mojom::blink::StorageArea::GetCallback callback) override
    {
        CHECK(ThreadCall::isBlinkThread());
        DebugBreak();
    }

    bool GetAll(
        ::mojo::PendingRemote<::blink::mojom::blink::StorageAreaObserver> newObserver, WTF::Vector<::blink::mojom::blink::KeyValuePtr>* outData) override
    {
        CHECK(ThreadCall::isBlinkThread());
        addObserverImpl(std::move(newObserver));

        //m_impl->loadFromFile(String("W:\\mycode\\mb108\\out\\Debug\\localstorage\\"), outData);
        //m_impl->loadFromFile(m_localStorageDir, outData); // !!!!!!!!!!!!!!!!
        outData->swap(m_outData);
        return true;
    }

    void GetAll(::mojo::PendingRemote<::blink::mojom::blink::StorageAreaObserver> newObserver, GetAllCallback callback) override
    {
        CHECK(ThreadCall::isBlinkThread());
        addObserverImpl(std::move(newObserver));
        DebugBreak();
    }

    void Checkpoint() override
    {

    }

private:
    base::FilePath m_localStorageDir;
    WTF::Vector<::blink::mojom::blink::KeyValuePtr> m_outData;
    StorageAreaImpl* m_impl = nullptr;
    mojo::RemoteSet<::blink::mojom::blink::StorageAreaObserver> m_observers;
};

class SessionStorageNamespaceImpl : public ::blink::mojom::blink::SessionStorageNamespace {
public:
    SessionStorageNamespaceImpl(const WTF::String& namespaceId)
    {
        m_namespaceId = namespaceId;
    }

    void Clone(const WTF::String& cloneToNamespace) override
    {
        // 暂时不实现window.open的拷贝。因为不同浏览器好像处理的还不太一样
        //char* output = (char*)malloc(400);
        //sprintf(output, "SessionStorageNamespaceImpl:Clone: %s, %s\n", m_namespaceId.Utf8().c_str(), cloneToNamespace.Utf8().c_str());
        //OutputDebugStringA(output);
        //free(output);
    }

private:
    WTF::String m_namespaceId;
};

class DomStorageImpl : public ::blink::mojom::blink::DomStorage {
public:
    DomStorageImpl()
    {
    }

    ~DomStorageImpl()
    {
    }

    void OpenLocalStorage(const ::blink::BlinkStorageKey& storageKey, const ::blink::LocalFrameToken& localFrameToken,
        ::mojo::PendingReceiver<::blink::mojom::blink::StorageArea> area) override
    {
        createAndBindBrokerProxy<::blink::mojom::blink::StorageArea, StorageAreaStub>(area.PassPipe(), true, storageKey, localFrameToken);
    }

    // namespaceId是同一个页面就共用，不管是否是frame，也不管是否同源。但blink::StorageAreaMap是sub frame同源就共用
    // window.open的时候，会把那个frame的session storage复制到新的被open的frame里
    void BindSessionStorageNamespace(const WTF::String& namespaceId, ::mojo::PendingReceiver<::blink::mojom::blink::SessionStorageNamespace> receiver) override
    {
        //char* output = (char*)malloc(400);
        //sprintf(output, "BindSessionStorageNamespace: %s,\n", namespaceId.Utf8().c_str());
        //OutputDebugStringA(output);
        //free(output);
        createAndBindBrokerProxy<::blink::mojom::blink::SessionStorageNamespace, SessionStorageNamespaceImpl>(receiver.PassPipe(), namespaceId);
    }

    // 这里绑定的时候，理论上要检测是否要复制来源的frame的session
    void BindSessionStorageArea(const ::blink::BlinkStorageKey& storageKey, const ::blink::LocalFrameToken& localFrameToken, const WTF::String& namespaceId,
        ::mojo::PendingReceiver<::blink::mojom::blink::StorageArea> sessionNamespace) override
    {
        //String key = storageKey.ToDebugString();
        //char* output = (char*)malloc(400);
        //sprintf(output, "BindSessionStorageArea: %s, %s\n", namespaceId.Utf8().c_str(), key.Utf8().c_str());
        //OutputDebugStringA(output);
        //free(output);
        createAndBindBrokerProxy<::blink::mojom::blink::StorageArea, StorageAreaStub>(sessionNamespace.PassPipe(), false, storageKey, localFrameToken);
    }
};

DomStorageProviderImpl::DomStorageProviderImpl()
{
}

void DomStorageProviderImpl::BindDomStorage(
    ::mojo::PendingReceiver<::blink::mojom::blink::DomStorage> receiver, ::mojo::PendingRemote<::blink::mojom::blink::DomStorageClient> client)
{
    createAndBindBrokerProxy<::blink::mojom::blink::DomStorage, DomStorageImpl>(receiver.PassPipe());
}

}