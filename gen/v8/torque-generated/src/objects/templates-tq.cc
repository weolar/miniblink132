#include "src/objects/templates-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=5&c=1
bool IsTemplateInfo_NonInline(Tagged<HeapObject> o)
{
    return IsTemplateInfo(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTemplateInfo<TemplateInfo, HeapObject>::TemplateInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TemplateInfoVerify(Cast<TemplateInfo>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=44&c=1
bool IsFunctionTemplateInfo_NonInline(Tagged<HeapObject> o)
{
    return IsFunctionTemplateInfo(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedFunctionTemplateInfo<FunctionTemplateInfo, TemplateInfo>::FunctionTemplateInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::FunctionTemplateInfoVerify(Cast<FunctionTemplateInfo>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=13&c=1
bool IsFunctionTemplateRareData_NonInline(Tagged<HeapObject> o)
{
    return IsFunctionTemplateRareData(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedFunctionTemplateRareData<FunctionTemplateRareData, Struct>::FunctionTemplateRareDataVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::FunctionTemplateRareDataVerify(Cast<FunctionTemplateRareData>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=104&c=1
bool IsObjectTemplateInfo_NonInline(Tagged<HeapObject> o)
{
    return IsObjectTemplateInfo(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedObjectTemplateInfo<ObjectTemplateInfo, TemplateInfo>::ObjectTemplateInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::ObjectTemplateInfoVerify(Cast<ObjectTemplateInfo>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/templates.tq?l=110&c=1
bool IsDictionaryTemplateInfo_NonInline(Tagged<HeapObject> o)
{
    return IsDictionaryTemplateInfo(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedDictionaryTemplateInfo<DictionaryTemplateInfo, HeapObject>::DictionaryTemplateInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::DictionaryTemplateInfoVerify(Cast<DictionaryTemplateInfo>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
