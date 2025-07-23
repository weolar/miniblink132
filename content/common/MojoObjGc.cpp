
#include "content/common/MojoObjGc.h"

namespace content {

void MojoObjGc::addReceiverObj(MojoObjHead* obj, MojoHandle handle)
{
    base::AutoLock locker(m_lock);
    ReceiverEntry* entry = new ReceiverEntry();
    entry->obj = obj;
    entry->handle = handle;
    m_receiverObjs.insert(entry);
}

void MojoObjGc::runGC()
{
}

}