
#include "content/browser/PageNavController.h"
#include "content/browser/MbWebview.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/common/ThreadCall.h"
#include "third_party/blink/renderer/core/loader/history_item.h"
#include "third_party/blink/renderer/bindings/core/v8/serialization/serialized_script_value.h"
#include "third_party/blink/renderer/platform/network/encoded_form_data.h"
#include "third_party/blink/public/common/page_state/page_state.h"
#include "third_party/blink/public/web/web_local_frame.h"
//#include "wke/wkeGlobalVar.h"

namespace content {

extern bool g_isBackKeyDown;

PageNavController::PageNavController(MbWebView* page)
{
    m_currentOffset = -1;
    m_page = page;
    m_protectReentryBackForwardCommit = false;
}

PageNavController::~PageNavController()
{
}

int PageNavController::historyBackListCount()
{
    return m_currentOffset;
}

int PageNavController::historyForwardListCount()
{
    int result = m_frameHistoryStates.size() - m_currentOffset - 1;
    return result;
}

// We do same-document navigation if going to a different item and if either of the following is true:
// - The other item corresponds to the same document (for history entries created via pushState or fragment changes).
// - The other item corresponds to the same set of documents, including frames (for history entries created via regular navigation)
bool PageNavController::shouldDoSameDocumentNavigationTo(
    const PageNavController::FrameHistoryItem* curItem, const PageNavController::FrameHistoryItem* otherItem)
{
#if 0
    // 这里先注释调用。重现地址：usertest.sztaizhou.com
    // 一共三个item，如果第一个到第二个item是same，第三个不是，那么如果从
    // 第三个后退到第二个，就会因为same导致页面加载失败
    if (otherItem->m_isSameDocument)
        return true;
#endif

    if (curItem == otherItem)
        return false;

    //     String curStateObjectString;
    //     if (!curItem->historyItem.stateObject().isNull())
    //         curStateObjectString = curItem->historyItem.stateObject().toString();
    //
    //     String otherStateObjectString;
    //     if (!otherItem->historyItem.stateObject().isNull())
    //         otherStateObjectString = otherItem->historyItem.stateObject().toString();
    //
    //     if ((!curStateObjectString.isNull() && !curStateObjectString.isEmpty()) || (!otherStateObjectString.isNull() && !otherStateObjectString.isEmpty()))
    //         return curItem->historyItem.documentSequenceNumber() == otherItem->historyItem.documentSequenceNumber();
    //
    //     blink::KURL curUrl(blink::ParsedURLString, curItem->historyItem.urlString());
    //     blink::KURL otherUrl(blink::ParsedURLString, otherItem->historyItem.urlString());
    //     if ((curUrl.hasFragmentIdentifier() || otherUrl.hasFragmentIdentifier()) && equalIgnoringFragmentIdentifier(curUrl, otherUrl))
    //         return curItem->historyItem.documentSequenceNumber() == otherItem->historyItem.documentSequenceNumber();
    //
    //     return false;

    return curItem->historyItem.DocumentSequenceNumber() == otherItem->historyItem.DocumentSequenceNumber();
}

void PageNavController::FrameHistoryItem::loadFromHistoryItem(
    MbWebView* page, PageNavController::FrameHistoryItem* curItem, PageNavController::FrameHistoryItem* newItem)
{
    bool isSameDocument = (shouldDoSameDocumentNavigationTo(curItem, newItem));

    blink::WebLocalFrame* frame = (blink::WebLocalFrame*)blink::WebFrame::FromFrameToken(curItem->uniqueName);
    if (!frame)
        return;
    WebLocalFrameClientImpl* client = (WebLocalFrameClientImpl*)frame->Client();
    if (!client)
        return;
    if (!client->getNavigationControl())
        return;
    WebLocalFrameClientImpl::loadHistoryItem(frame, newItem->historyItem, isSameDocument);

    //     navigationParams->frame_load_type = blink::WebFrameLoadType::kBackForward;
    //     navigationParams->history_item = newItem->historyItem;
    //
    //     navigationParams->response.SetCurrentRequestUrl(m_url);
    //     navigationParams->response.SetMimeType(m_response->MimeType());
    //
    //     if (!isSameDocument)
    //         client->getNavigationControl()->CommitNavigation(std::move(navigationParams), nullptr);
    //     else {
    //         mojom::CommitResult result = client->getNavigationControl()->CommitSameDocumentNavigation(item->Url(), WebFrameLoadType::kBackForward, item.Get(),
    //             ClientRedirectPolicy::kNotClientRedirect, false /* has_transient_user_activation */, /*initiator_origin=*/nullptr,
    //             /*is_synchronously_committed=*/false, mojom::blink::TriggeringEventInfo::kNotFromEvent, true /* is_browser_initiated */);
    //     }
}

void PageNavController::navigate(int offset)
{
    m_protectReentryBackForwardCommit = true;

    int pos = m_currentOffset + offset;
    if (pos < 0 || pos > (int)(m_frameHistoryStates.size() - 1))
        return;
    AllFrameHistoryItemSet* newItems = m_frameHistoryStates[pos];
    AllFrameHistoryItemSet* curItems = nullptr;
    if (m_currentOffset >= 0 && m_currentOffset < (int)m_frameHistoryStates.size())
        curItems = m_frameHistoryStates[m_currentOffset];
    if (!curItems)
        return;

    for (size_t i = 0; i < newItems->m_frameHistoryItems.size(); ++i) {
        FrameHistoryItem* newItem = newItems->m_frameHistoryItems[i];
        for (size_t j = 0; j < curItems->m_frameHistoryItems.size(); ++j) {
            FrameHistoryItem* curItem = curItems->m_frameHistoryItems[j];
            long long newNum = newItem->historyItem.ItemSequenceNumber();
            long long curNum = curItem->historyItem.ItemSequenceNumber();

            // 一样ItemSequenceNumber表示两者是克隆关系
            if (newItem->uniqueName == curItem->uniqueName && newItem->historyItem.ItemSequenceNumber() != curItem->historyItem.ItemSequenceNumber()) {
                PageNavController::FrameHistoryItem::loadFromHistoryItem(m_page, curItem, newItem);
                //                 blink::WebHistoryLoadType type = blink::kWebHistoryDifferentDocumentLoad; // blink::WebFrameLoadType::BackForward;//
                //                 if (shouldDoSameDocumentNavigationTo(curItem, newItem))
                //                     type = blink::WebHistorySameDocumentLoad;
                //
                //                 blink::WebLocalFrame* frame = (blink::WebLocalFrame*)m_page->getWebFrameFromUniqueName(curItem->uniqueName);
                //                 if (frame) {
                //                     blink::WebURLRequest request = frame->requestFromHistoryItem(newItem->historyItem, blink::WebCachePolicy::UseProtocolCachePolicy);
                //                     frame->load(request, blink::WebFrameLoadType::BackForward, newItem->historyItem, type);
                //                 }
            }
        }
    }
}

void PageNavController::navigateBackForwardSoon(int offset)
{
    //     if (g_isBackKeyDown && !wke::g_backKeydownEnable)
    //         return;
    PageNavController* self = this;
    ThreadCall::callBlinkThreadAsync(FROM_HERE, [self, offset] { self->navigate(offset); });
}

void PageNavController::navigateToIndex(int index)
{
    int offset = index - m_currentOffset;
    navigateBackForwardSoon(offset);
}

bool PageNavController::findEntryImpl(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, const AllFrameHistoryItemSet& itemSet) const
{
    // 可能会出现找不到的情况。比如sub frame后退了，然后blink会通知main frame也后退，但
    // 其实main frame只有一个item
    for (size_t i = 0; i < itemSet.m_frameHistoryItems.size(); ++i) {
        FrameHistoryItem* frameItem = itemSet.m_frameHistoryItems[i];
        long long s1 = frameItem->historyItem.ItemSequenceNumber();
        long long s2 = item.ItemSequenceNumber();
        if (s1 == s2)
            return true;
    }

    return false;
}

int PageNavController::findEntry(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item) const
{
    if (m_frameHistoryStates.size() <= 1)
        return 0;

    const AllFrameHistoryItemSet* itemSet = nullptr;
    //     if (m_currentOffset >= 1) {
    //         itemSet = m_frameHistoryStates[m_currentOffset - 1];
    //         if (findEntryImpl(frame, item, *itemSet))
    //             return -1;
    //     }
    //
    //     if (m_currentOffset <= (int)m_frameHistoryStates.size() - 2) {
    //         itemSet = m_frameHistoryStates[m_currentOffset + 1];
    //         if (findEntryImpl(frame, item, *itemSet))
    //             return 1;
    //     }
    for (size_t i = 0; i < m_frameHistoryStates.size(); ++i) {
        itemSet = m_frameHistoryStates[i];
        if (findEntryImpl(frame, item, *itemSet))
            return i - m_currentOffset;
    }
    return 0;
}

void PageNavController::onStandardCommit(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, blink::WebHistoryCommitType type, bool isSameDocument)
{
    AllFrameHistoryItemSet* frameEntrys = nullptr;
    if (m_currentOffset < 0 || m_currentOffset >= (int)m_frameHistoryStates.size())
        frameEntrys = blink::MakeGarbageCollected<AllFrameHistoryItemSet>();
    else
        frameEntrys = m_frameHistoryStates[m_currentOffset]->clone();

    //         if (1) {
    //             for (size_t i = 0; i < frameEntrys->m_frameHistoryItems.size(); ++i) {
    //                 FrameHistoryItem* it = frameEntrys->m_frameHistoryItems[i];
    //
    //                 char* output = (char*)malloc(0x100);
    //                 sprintf_s(output, 0x99, "insertOrReplaceEntry, WebStandardCommit --: %I64d\n", it->historyItem.ItemSequenceNumber());
    //                 OutputDebugStringA(output);
    //                 free(output);
    //             }
    //         }

    frameEntrys->insertOrReplaceEntry(frame, item, type, isSameDocument);
    frameEntrys->clearRemovedFrame(frame);

    //         char* output = (char*)malloc(0x100);
    //         sprintf_s(output, 0x99, "insertOrReplaceEntry, WebStandardCommit: %I64d\n", item.ItemSequenceNumber());
    //         OutputDebugStringA(output);
    //         free(output);

    //         if (0) {
    //             for (size_t i = 0; i < frameEntrys->m_frameHistoryItems.size(); ++i) {
    //                 FrameHistoryItem* it = frameEntrys->m_frameHistoryItems[i];
    //
    //                 output = (char*)malloc(0x100);
    //                 sprintf_s(output, 0x99, "insertOrReplaceEntry, WebStandardCommit ~~~: %I64d\n", it->historyItem.ItemSequenceNumber());
    //                 OutputDebugStringA(output);
    //                 free(output);
    //             }
    //         }

    ++m_currentOffset;
    CHECK(0 <= m_currentOffset && m_currentOffset <= (int)m_frameHistoryStates.size());
    if (m_currentOffset == m_frameHistoryStates.size()) {
        m_frameHistoryStates.push_back(frameEntrys);
    } else {
        m_frameHistoryStates[m_currentOffset] = frameEntrys;
        m_frameHistoryStates.resize(m_currentOffset + 1);
    }
}

void PageNavController::insertOrReplaceEntry(
    blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, blink::WebHistoryCommitType type, bool isSameDocument)
{
    AllFrameHistoryItemSet* frameEntrys = nullptr;
    switch (type) {
    case blink::kWebStandardCommit: {
        onStandardCommit(frame, item, type, isSameDocument);
        break;
    }
    case blink::kWebBackForwardCommit: {
        if (m_protectReentryBackForwardCommit) {
            m_protectReentryBackForwardCommit = false;
            int offset = findEntry(frame, item);
            if (0 == offset) {
                CHECK(false);
                break;
            }
            int entryIndex = m_currentOffset + offset;
            CHECK(entryIndex < (int)m_frameHistoryStates.size());
            if (-1 == entryIndex) {
                CHECK(false);
                break;
            }
            frameEntrys = m_frameHistoryStates[entryIndex];
            frameEntrys->insertOrReplaceEntry(frame, item, type, isSameDocument);
            m_frameHistoryStates[entryIndex] = frameEntrys;

            m_currentOffset = entryIndex;
        } else if (m_currentOffset >= 0 && m_currentOffset < (int)m_frameHistoryStates.size()) {
            frameEntrys = m_frameHistoryStates[m_currentOffset];
            frameEntrys->insertOrReplaceEntry(frame, item, type, isSameDocument);
            m_frameHistoryStates[m_currentOffset] = frameEntrys;
        }

        break;
    }
#if 0
    case blink::kWebInitialCommitInChildFrame: // 子frame初始化时
    {
//         char* output = (char*)malloc(0x100);
//         sprintf_s(output, 0x99, "insertOrReplaceEntry, WebInitialCommitInChildFrame: %I64d\n", item.ItemSequenceNumber());
//         OutputDebugStringA(output);
//         free(output);
    }
#endif
    case blink::kWebHistoryInertCommit: // reload，或replaceState，或者第一次加载的时候。见FrameLoader::HandleInitialEmptyDocumentReplacementIfNeeded
        if (0 == m_frameHistoryStates.size()) {
            onStandardCommit(frame, item, type, isSameDocument);
        } else if (m_frameHistoryStates.size() != 0 && m_currentOffset < (int)m_frameHistoryStates.size()) {
            frameEntrys = m_frameHistoryStates[m_currentOffset];
            frameEntrys->insertOrReplaceEntry(frame, item, type, isSameDocument);
            m_frameHistoryStates[m_currentOffset] = frameEntrys;
        }
        break;
    default:
        break;
    }

    //     char* output = (char*)malloc(0x100);
    //     sprintf_s(output, 0x99, "PageNavController::insertOrReplaceEntry begin: %d\n", m_frameHistoryStates.size());
    //     OutputDebugStringA(output);
    //     free(output);
    //
    //     for (size_t i = 0; i < m_frameHistoryStates.size(); ++i) {
    //         AllFrameHistoryItemSet* states = m_frameHistoryStates[i];
    //
    //         char* output = (char*)malloc(0x100);
    //         sprintf_s(output, 0x99, "PageNavController::insertOrReplaceEntry         i: %d, size:%d\n", i, states->m_frameOffsets.size());
    //         OutputDebugStringA(output);
    //
    //         for (size_t j = 0; j < states->m_frameOffsets.size(); ++j) {
    //             FrameHistoryItemOffset* oneFrame = states->m_frameOffsets[j];
    //
    //             sprintf_s(output, 0x99, "PageNavController::insertOrReplaceEntry           : %s, %d, %d\n", oneFrame->uniqueName.utf8().data(), oneFrame->curNavOffset, type);
    //             OutputDebugStringA(output);
    //         }
    //         free(output);
    //     }
    //
    //     OutputDebugStringA("----end\n");
}

blink::WebHistoryItem PageNavController::historyItemForNewChildFrame(blink::WebFrame* frame)
{
    AllFrameHistoryItemSet* curItem = nullptr;
    if (m_currentOffset >= 0 && m_currentOffset < (int)m_frameHistoryStates.size())
        curItem = m_frameHistoryStates[m_currentOffset];
    if (!curItem)
        return blink::WebHistoryItem();

    for (size_t i = 0; i < curItem->m_frameHistoryItems.size(); ++i) {
        FrameHistoryItem* frameHistory = curItem->m_frameHistoryItems[i];
        if (frameHistory->uniqueName != frame->GetFrameToken())
            continue;
        return frameHistory->historyItem;
    }
    return blink::WebHistoryItem();
}

PageNavController::AllFrameHistoryItemSet::~AllFrameHistoryItemSet()
{
    //     char* output = (char*)malloc(400);
    //     sprintf_s(output, 399, "~AllFrameHistoryItemSet: %p\n", this);
    //     OutputDebugStringA(output);
    //     free(output);
}

void PageNavController::AllFrameHistoryItemSet::clearRemovedFrame(const blink::WebLocalFrame* frame)
{
    std::vector<const blink::WebFrame*> newFrames;
    const blink::WebFrame* cur = frame;
    const blink::WebFrame* rootFrame = frame;
    do {
        rootFrame = cur;
        cur = cur->Parent();
    } while (cur);

    cur = rootFrame;
    do {
        newFrames.push_back(cur);
        cur = cur->TraverseNext();
    } while (cur);

    for (size_t i = 0; i < m_frameHistoryItems.size(); ++i) {
        bool find = false;
        FrameHistoryItem* oldItem = m_frameHistoryItems[i];

        for (size_t j = 0; j < newFrames.size(); ++j) {
            const blink::WebFrame* newItem = newFrames[j];
            if (oldItem->uniqueName == newItem->GetFrameToken()) {
                find = true;
                break;
            }
        }

        if (!find) {
            m_frameHistoryItems.erase(m_frameHistoryItems.begin() + i);
            --i;
        }
    }
}

void PageNavController::FrameHistoryItem::copyHistoryItem(const blink::WebHistoryItem& item)
{
    blink::WebHistoryItem* otherWebItem = (blink::WebHistoryItem*)(&item);
    blink::HistoryItem* otherItem = *otherWebItem; // 这里面有些字段我还没实现拷贝

    blink::PageState pageState = otherItem->ToPageState();
    this->historyItem = blink::WebHistoryItem(pageState);

    blink::HistoryItem* it = this->historyItem;
    blink::HistoryItem* other = otherItem;

    it->SetNavigationApiKey(other->GetNavigationApiKey());
    it->SetNavigationApiId(other->GetNavigationApiId());
    it->SetURLString(other->UrlString());
    it->SetReferrer(other->GetReferrer());
    it->SetReferrerPolicy(other->GetReferrerPolicy());
    //it->SetTarget(other.target());
    it->SetStateObject(other->StateObject());
    it->SetDocumentState(other->GetDocumentState());
    it->SetScrollRestorationType(other->ScrollRestorationType());
    it->CopyViewStateFrom(other);
    it->SetItemSequenceNumber(other->ItemSequenceNumber());
    it->SetDocumentSequenceNumber(other->DocumentSequenceNumber());
    it->SetFormData(other->FormData());
    it->SetFormContentType(other->FormContentType());
}

void PageNavController::AllFrameHistoryItemSet::insertOrReplaceEntry(
    blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, blink::WebHistoryCommitType type, bool isSameDocument)
{
    for (size_t i = 0; i < m_frameHistoryItems.size(); ++i) {
        // 找到同名的frame，插入，再把新frame所属的tree里老tree不存在的节点全删了
        FrameHistoryItem* frameItem = m_frameHistoryItems[i];
        if (frameItem->uniqueName != frame->GetFrameToken())
            continue;
        frameItem->copyHistoryItem(item);
        frameItem->isSameDocument = isSameDocument;
        m_frameHistoryItems[i] = frameItem;
        return;
    }

    FrameHistoryItem* it = blink::MakeGarbageCollected<FrameHistoryItem>(frame->GetFrameToken(), item);
    m_frameHistoryItems.push_back(it);
}

PageNavController::AllFrameHistoryItemSet* PageNavController::AllFrameHistoryItemSet::clone() const
{
    AllFrameHistoryItemSet* result = blink::MakeGarbageCollected<AllFrameHistoryItemSet>();
    for (size_t i = 0; i < m_frameHistoryItems.size(); ++i) {
        FrameHistoryItem* newItem = blink::MakeGarbageCollected<FrameHistoryItem>(*(m_frameHistoryItems[i]));
        result->m_frameHistoryItems.push_back(newItem);
    }
    return result;
}

void PageNavController::Trace(cppgc::Visitor* visitor) const
{
    //     for (size_t i = 0; i < m_frameHistoryStates.size(); ++i) {
    //         AllFrameHistoryItemSet* entry = m_frameHistoryStates[i];
    //         visitor->Trace(*entry);
    //
    //         char* output = (char*)malloc(400);
    //         sprintf_s(output, 399, "~PageNavController::Trace: %p\n", entry);
    //         OutputDebugStringA(output);
    //         free(output);
    //     }
    visitor->Trace(m_frameHistoryStates);
}

void PageNavController::FrameHistoryItem::Trace(cppgc::Visitor* visitor) const
{
    //visitor->trace(historyItem);
}

void PageNavController::AllFrameHistoryItemSet::Trace(cppgc::Visitor* visitor) const
{
    //     for (size_t i = 0; i < m_frameHistoryItems.size(); ++i) {
    //         FrameHistoryItem* entry = m_frameHistoryItems[i];
    //         visitor->Trace(*entry);
    //     }
    visitor->Trace(m_frameHistoryItems);
}

}