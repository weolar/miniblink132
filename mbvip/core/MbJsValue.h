
#ifndef mbvip_core_MbJsValue_h
#define mbvip_core_MbJsValue_h

#include "mbvip/core/mb.h"
#include "content/common/LiveIdDetect.h"
#include "v8.h"

typedef void* mbWebFrameHandle;

namespace mb {

class MbJsValue {
public:
    static MbJsValue* create();
    void ref();
    void deref();

private:
    MbJsValue();
    ~MbJsValue();

public:
    static MbJsValue* v8ValueToMb(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Value> value);

    int64_t getId() const
    {
        return m_id;
    }
    mbJsType getType() const
    {
        return m_type;
    }

    double getDoubleVal() const
    {
        return m_doubleVal;
    }
    std::string getStrVal() const
    {
        return m_strVal;
    }
    BOOL getBoolVal() const
    {
        return m_boolVal;
    }
    mbWebFrameHandle getWebFrameHandle() const
    {
        return m_webFrameHandle;
    }

private:
    int m_ref = 1;
    int64_t m_id = -1;
    mbJsType m_type = kMbJsTypeUndefined;

    double m_doubleVal = 0;
    std::string m_strVal;
    BOOL m_boolVal = FALSE;
    mbWebFrameHandle m_webFrameHandle = nullptr;
};

}

#endif // mbvip_core_MbJsValue_h