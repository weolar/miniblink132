// template <int ii>
// struct BindArgument22 {
//
//   struct ForwardedAs22 {
//   };
// };
//
// template <int ii>
// struct ParamCanBeBound22222 {
// private:
//   using UnwrappedParam = template BindArgument22<ii>::/*template*/ ForwardedAs22;
// };

#include "content/browser/BroadcastChannelProviderImpl.h"

#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/common/ThreadCall.h"

#include "third_party/blink/public/web/web_document.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "mojo/public/cpp/bindings/associated_remote.h"
#include "mojo/public/cpp/bindings/associated_receiver.h"
#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"
#include <unordered_map>

namespace content {

class BroadcastChannelItem : public ::blink::mojom::blink::BroadcastChannelClient {
public:
    BroadcastChannelItem()
    {
    }

    ~BroadcastChannelItem() // 一定要在blink线程销毁，别在webworker线程上
    {
        CHECK(WTF::IsMainThread());
    }

    void OnMessage(::blink::BlinkCloneableMessage message) override;
    void OnError();

    std::string m_nameAndOrig;

    scoped_refptr<base::SequencedTaskRunner> m_runner;

    mojo::AssociatedRemote<::blink::mojom::blink::BroadcastChannelClient> m_send;
    mojo::AssociatedReceiver<::blink::mojom::blink::BroadcastChannelClient> m_recv { this };

private:
    void onErrorOnblinkThread();
    void onMessageOnBlinkThread(blink::BlinkCloneableMessage* copyMsg, std::string* nameAndOrig);
    void dispathMsg(blink::BlinkCloneableMessage* copyMsg, std::string* nameAndOrig);
};

using StrToBroadcastChannelItems = std::unordered_map<std::string, std::vector<BroadcastChannelItem*>*>;

class BroadcastChannelMgr {
public:
    static BroadcastChannelMgr* get()
    {
        static BroadcastChannelMgr* s_inst = nullptr;
        if (!s_inst)
            s_inst = new BroadcastChannelMgr();
        return s_inst;
    }

    StrToBroadcastChannelItems& getItemSet()
    {
        return m_items;
    }

    WTF::RecursiveMutex m_lock;

private:
    StrToBroadcastChannelItems m_items;
};

void BroadcastChannelItem::OnError()
{
    BroadcastChannelItem* self = this;
    ThreadCall::callBlinkThreadAsync(FROM_HERE, [self]() { self->onErrorOnblinkThread(); });
}

void BroadcastChannelItem::onErrorOnblinkThread()
{
    WTF::Locker<WTF::RecursiveMutex> locker(BroadcastChannelMgr::get()->m_lock);

    do {
        StrToBroadcastChannelItems& itemSet = BroadcastChannelMgr::get()->getItemSet();
        StrToBroadcastChannelItems::const_iterator it = itemSet.find(m_nameAndOrig);
        if (it == itemSet.end())
            break;

        for (size_t i = 0; i < it->second->size(); ++i) {
            BroadcastChannelItem* item = it->second->at(i);
            if (item == this) {
                it->second->erase(it->second->begin() + i);
                --i;
            }
        }
        if (it->second->empty()) {
            std::vector<BroadcastChannelItem*>* items = it->second;
            delete items;
            itemSet.erase(it);
        }
    } while (false);

    delete this;
}

void BroadcastChannelItem::dispathMsg(blink::BlinkCloneableMessage* message, std::string* nameAndOrig)
{
    if (!m_send.is_bound())
        return;

    blink::BlinkCloneableMessage* msg = new blink::BlinkCloneableMessage();
    std::string* nameAndOrigCopy = new std::string(*nameAndOrig);

    base::span<const uint8_t> wireData = message->message->GetWireData();
    msg->message = blink::SerializedScriptValue::Create(base::span<const uint8_t>(wireData.data(), wireData.size()));
    msg->sender_origin = message->sender_origin;
    msg->sender_stack_trace_id = message->sender_stack_trace_id;
    msg->sender_agent_cluster_id = message->sender_agent_cluster_id;
    msg->locked_to_sender_agent_cluster = message->locked_to_sender_agent_cluster;

    BroadcastChannelItem* self = this;
    if (m_send.runner()->RunsTasksInCurrentSequence()) {
        if (m_send.is_bound() && m_send.is_connected()) {
            ::blink::mojom::blink::BroadcastChannelClient* send = m_send.get();
            send->OnMessage(std::move(*msg));
        }

        delete msg;
        delete nameAndOrigCopy;
    } else {
        m_send.runner()->PostTask(FROM_HERE,
            base::BindOnce(
                [](blink::BlinkCloneableMessage* msg, std::string* nameAndOrigCopy, BroadcastChannelItem* self) {
                    BroadcastChannelMgr::get()->m_lock.lock();
                    if (self->m_send.is_bound() && self->m_send.is_connected())
                        self->m_send->OnMessage(std::move(*msg));
                    BroadcastChannelMgr::get()->m_lock.unlock();
                    delete msg;
                    delete nameAndOrigCopy;
                },
                msg, nameAndOrigCopy, self));
    }
}

void BroadcastChannelItem::onMessageOnBlinkThread(blink::BlinkCloneableMessage* copyMsg, std::string* nameAndOrig)
{
    BroadcastChannelMgr::get()->m_lock.lock();
    do {
        StrToBroadcastChannelItems& itemSet = BroadcastChannelMgr::get()->getItemSet();
        StrToBroadcastChannelItems::const_iterator it = itemSet.find(*nameAndOrig);
        if (it == itemSet.end())
            break;
        for (size_t i = 0; i < it->second->size(); ++i) {
            BroadcastChannelItem* item = it->second->at(i);
            if (item == this)
                continue;

            item->dispathMsg(copyMsg, nameAndOrig);
        }
    } while (false);

    BroadcastChannelMgr::get()->m_lock.unlock();
}

void BroadcastChannelItem::OnMessage(::blink::BlinkCloneableMessage message)
{
    ::blink::BlinkCloneableMessage* copyMsg = new ::blink::BlinkCloneableMessage(std::move(message));
    std::string* nameAndOrig = new std::string(m_nameAndOrig);
    BroadcastChannelItem* self = this;

    ThreadCall::callBlinkThreadAsync(FROM_HERE, [copyMsg, nameAndOrig, self]() {
        self->onMessageOnBlinkThread(copyMsg, nameAndOrig);
        delete nameAndOrig;
        delete copyMsg;
    });
}

BroadcastChannelProviderImpl::BroadcastChannelProviderImpl(WebLocalFrameClientImpl* frameClient)
{
    m_frameClient = frameClient;
}

static std::string getNameAndOrig(const WTF::String& name, WebLocalFrameClientImpl* frameClient)
{
    std::string nameAndOrig = name.Utf8();
    if (!frameClient || !frameClient->m_frame)
        return nameAndOrig;
    blink::WebDocument doc = frameClient->m_frame->GetDocument();
    blink::WebSecurityOrigin orig = doc.GetSecurityOrigin();

    blink::WebString origStr = orig.ToString();
    nameAndOrig += "_";
    nameAndOrig += origStr.Utf8();

    return nameAndOrig;
}

// 本函数可能运行在webwork线程
void BroadcastChannelProviderImpl::ConnectToChannel(const WTF::String& name,
    ::mojo::PendingAssociatedRemote<::blink::mojom::blink::BroadcastChannelClient> client,
    ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::BroadcastChannelClient> connection)
{
    std::string nameAndOrig = getNameAndOrig(name, m_frameClient);

    BroadcastChannelItem* item = new BroadcastChannelItem();
    item->m_nameAndOrig = nameAndOrig;
    item->m_send.Bind(std::move(client));
    item->m_recv.Bind(std::move(connection));
    item->m_send.set_disconnect_handler(base::BindOnce(&BroadcastChannelItem::OnError, base::Unretained(item)));
    item->m_runner = base::SequencedTaskRunner::GetCurrentDefault();

    BroadcastChannelMgr::get()->m_lock.lock();
    StrToBroadcastChannelItems& itemSet = BroadcastChannelMgr::get()->getItemSet();
    StrToBroadcastChannelItems::const_iterator it = itemSet.find(nameAndOrig);
    if (it != itemSet.end()) {
        it->second->push_back(item);
        BroadcastChannelMgr::get()->m_lock.unlock();
        return;
    }

    std::vector<BroadcastChannelItem*>* items = new std::vector<BroadcastChannelItem*>();
    items->push_back(item);
    itemSet[nameAndOrig] = items;
    BroadcastChannelMgr::get()->m_lock.unlock();
}

BroadcastChannelProviderImpl::~BroadcastChannelProviderImpl()
{
    CHECK(WTF::IsMainThread());
}

}
