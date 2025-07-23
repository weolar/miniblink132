
#ifndef common_LiveIdDetect_h
#define common_LiveIdDetect_h

#include <set>
#include <map>
#include <windows.h>

namespace common {

class LiveIdDetect {
public:
    LiveIdDetect();

    ~LiveIdDetect()
    {
    }

    int64_t constructed(void* ptr);

    void deconstructed(int64_t id);

    void* getPtr(int64_t id);

    void* getPtrLocked(int64_t id);

    int64_t getIdLocked(void* ptr);

    void unlock(int64_t id, void*);

    static LiveIdDetect* get();

    // 单独为MbWebviews开个，否则
    // 合成线程的MbWebView::delayDoMouseMsgInCompositorThread和blink线程的ResourceLoader-》ReceiverImplBase::ReceiverImplBase
    // 会死锁
    static LiveIdDetect* getMbWebviewIds();

    bool isLive(int64_t id);

    bool isActivating(void* ptr);

private:
    int64_t m_idGen;
    std::map<int64_t, void*> m_liveSelf;
    std::map<void*, int64_t> m_ptrToIdMaps;
    CRITICAL_SECTION m_lock;
    static LiveIdDetect* m_inst;
    static LiveIdDetect* m_mbwebviewIds;
};

}

#endif // common_LiveIdDetect_h