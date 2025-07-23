
#include "content/browser/WebFrameMain.h"

#include "third_party/blink/public/web/web_document.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/public/mojom/page/page_visibility_state.mojom-shared.h"
#include "base/synchronization/lock.h"
#include "base/no_destructor.h"
#include "content/common/ThreadCall.h"
#include <unordered_map>

namespace content {

intptr_t getFrameIdByWebLocalFrame(blink::WebLocalFrame* frame);

using WebFrameMainIdMap = std::unordered_map<intptr_t, WebFrameMain*>;

struct WebFrameMainMgr {
    //base::Lock m_lock;
    WebFrameMainIdMap m_map;

    void emplace(intptr_t frameId, WebFrameMain* webframeMain)
    {
        //base::AutoLock locker(m_lock);
        m_map.emplace(frameId, webframeMain);
    }

    void erase(intptr_t frameId)
    {
        //base::AutoLock locker(m_lock);
        WebFrameMainIdMap::iterator it = m_map.find(frameId);
        if (it == m_map.end())
            return;
        WebFrameMain* webframeMain = it->second;
        delete webframeMain;
        m_map.erase(it);
    }
};

static WebFrameMainMgr& getWebFrameMainMgr()
{
    static base::NoDestructor<WebFrameMainMgr> instance;
    return *instance;
}

WebFrameMain::WebFrameMain(intptr_t frameId, intptr_t parentFrameId, bool isTop)
{
    m_isTop = isTop;
    m_frameId = frameId;
    m_parentFrameId = parentFrameId;
    m_pageVisibilityState = blink::mojom::blink::PageVisibilityState::kHiddenButPainting;

    WebFrameMain* self = this;
    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [frameId, self]() { getWebFrameMainMgr().emplace(frameId, self); });
}

WebFrameMain::~WebFrameMain()
{
}

void WebFrameMain::destroy(intptr_t frameId)
{
    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [frameId]() { getWebFrameMainMgr().erase(frameId); });
}

WebFrameMain* WebFrameMain::fromFrameId(intptr_t frameId)
{
    WebFrameMainMgr& mgr = getWebFrameMainMgr();
    //base::AutoLock locker(mgr.m_lock);
    WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
    if (it == mgr.m_map.end())
        return nullptr;
    return it->second;
}

void WebFrameMain::updataHiddenOnRenderProcess(blink::WebLocalFrame* frame, bool isHidden)
{
    blink::mojom::PageVisibilityState state = blink::mojom::PageVisibilityState::kHiddenButPainting;
    if (isHidden)
        state = blink::mojom::PageVisibilityState::kHidden;
    else
        state = blink::mojom::PageVisibilityState::kVisible;
    intptr_t frameId = getFrameIdByWebLocalFrame(frame);

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [frameId, state]() {
        WebFrameMainMgr& mgr = getWebFrameMainMgr();
        //base::AutoLock locker(mgr.m_lock);
        WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
        if (it == mgr.m_map.end())
            return;
        WebFrameMain* webframeMain = it->second;
        webframeMain->m_pageVisibilityState = state;
    });
}

void WebFrameMain::updataFrameStateOnRenderProcess(blink::WebLocalFrame* frame)
{
    blink::WebDocument doc = frame->GetDocument();
    GURL url = (GURL)(blink::KURL)(doc.Url());

    WTF::String name = frame->AssignedName();
    std::string nameStr = name.Utf8();

    intptr_t frameId = getFrameIdByWebLocalFrame(frame);
    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [frameId, url, nameStr]() {
        WebFrameMainMgr& mgr = getWebFrameMainMgr();
        //base::AutoLock locker(mgr.m_lock);
        WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
        if (it == mgr.m_map.end())
            return;
        WebFrameMain* webframeMain = it->second;
        webframeMain->m_url = url.possibly_invalid_spec();
        webframeMain->m_name = nameStr;
    });
}

std::string WebFrameMain::getUrl(intptr_t frameId)
{
    WebFrameMainMgr& mgr = getWebFrameMainMgr();
    //base::AutoLock locker(mgr.m_lock);
    WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
    if (it == mgr.m_map.end())
        return "";
    WebFrameMain* webframeMain = it->second;
    return webframeMain->m_url;
}

std::string WebFrameMain::getName(intptr_t frameId)
{
    WebFrameMainMgr& mgr = getWebFrameMainMgr();
    //base::AutoLock locker(mgr.m_lock);
    WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
    if (it == mgr.m_map.end())
        return "";
    WebFrameMain* webframeMain = it->second;
    return webframeMain->m_name;
}

blink::mojom::blink::PageVisibilityState WebFrameMain::getPageVisibilityState(intptr_t frameId)
{
    WebFrameMainMgr& mgr = getWebFrameMainMgr();
    //base::AutoLock locker(mgr.m_lock);
    WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
    if (it == mgr.m_map.end())
        return blink::mojom::PageVisibilityState::kHiddenButPainting;
    WebFrameMain* webframeMain = it->second;
    return webframeMain->m_pageVisibilityState;
}

intptr_t WebFrameMain::getParentFrameId(intptr_t frameId)
{
    WebFrameMainMgr& mgr = getWebFrameMainMgr();
    //base::AutoLock locker(mgr.m_lock);
    WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
    if (it == mgr.m_map.end())
        return 0;
    WebFrameMain* webframeMain = it->second;
    return webframeMain->m_parentFrameId;
}

intptr_t WebFrameMain::getTopFrameId(intptr_t frameId)
{
    WebFrameMainMgr& mgr = getWebFrameMainMgr();
    //base::AutoLock locker(mgr.m_lock);
    WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
    if (it == mgr.m_map.end())
        return 0;
    WebFrameMain* webframeMain = it->second;
    WebFrameMain* webframeIt = webframeMain;

    do {
        if (0 == webframeIt->m_parentFrameId)
            return webframeIt->m_frameId;

        it = mgr.m_map.find(webframeIt->m_parentFrameId);
        if (it == mgr.m_map.end()) {
            return webframeIt->m_frameId;
        }
        webframeIt = it->second;
    } while (true);
}

std::vector<WebFrameMain*> WebFrameMain::getChildrenFrames(intptr_t frameId)
{
    WebFrameMainMgr& mgr = getWebFrameMainMgr();
    std::vector<WebFrameMain*> ret;
    //base::AutoLock locker(mgr.m_lock);
    WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
    if (it == mgr.m_map.end())
        return ret;
    WebFrameMain* webframeMain = it->second;

    for (it = mgr.m_map.begin(); it != mgr.m_map.end(); ++it) {
        WebFrameMain* webframeMainIt = it->second;
        if (webframeMainIt->m_parentFrameId == webframeMain->m_frameId) {
            ret.push_back(webframeMainIt);
        }
    }
    return ret;
}

static bool isAncestor(WebFrameMainMgr& mgr, const WebFrameMain* rootFrame, const WebFrameMain* child)
{
    const WebFrameMain* it = child;
    while (it) {
        if (it == rootFrame) // 如果是同一个，也认为是子节点
            return true;
        it = WebFrameMain::fromFrameId(it->m_parentFrameId);
    }

    return false;
}

std::vector<WebFrameMain*> WebFrameMain::getFramesInSubtree(intptr_t frameId)
{
    WebFrameMainMgr& mgr = getWebFrameMainMgr();
    std::vector<WebFrameMain*> ret;
    //base::AutoLock locker(mgr.m_lock);

    WebFrameMainIdMap::iterator it = mgr.m_map.find(frameId);
    if (it == mgr.m_map.end())
        return ret;
    WebFrameMain* webframeMain = it->second;

    for (it = mgr.m_map.begin(); it != mgr.m_map.end(); ++it) {
        if (isAncestor(mgr, webframeMain, it->second))
            ret.push_back(it->second);
    }
    return ret;
}

}