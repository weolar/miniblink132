
#ifndef content_common_MojoObjGc_h
#define content_common_MojoObjGc_h

#include "mojo/public/c/system/types.h"
#include "base/synchronization/lock.h"
#include <set>

namespace content {

class MojoObjHead {
public:
    virtual void destroy() = 0;
};

class MojoObjGc {
public:
    void addReceiverObj(MojoObjHead* obj, MojoHandle handle); // 添加的都是接收端对象

private:
    void runGC();

    base::Lock m_lock;

    struct ReceiverEntry {
        MojoObjHead* obj = nullptr;
        MojoHandle handle = 0;
    };
    std::set<ReceiverEntry*> m_receiverObjs;
};

}

#endif
