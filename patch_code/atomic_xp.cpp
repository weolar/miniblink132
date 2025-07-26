
#include <windows.h>
#include <stdio.h>

#if defined(_MSC_VER)

extern "C" uintptr_t MbTlsAlloc()
{
    return (uintptr_t)TlsAlloc();
}

extern "C" LPVOID MbTlsGetValue(uintptr_t dwTlsIndex)
{
    return TlsGetValue((DWORD)dwTlsIndex);
}

extern "C" BOOL MbTlsSetValue(uintptr_t dwTlsIndex, LPVOID lpTlsValue)
{
    return TlsSetValue((DWORD)dwTlsIndex, lpTlsValue);
}

extern "C" BOOL MbTlsFree(uintptr_t dwTlsIndex)
{
    return TlsFree((DWORD)dwTlsIndex);
}

extern "C" long MB_InterlockedIncrement(long volatile* _Target)
{
    return _InterlockedIncrement((long volatile*)_Target);
}

extern "C" long MB_InterlockedExchange(long volatile* _Target, long _Value)
{
    return _InterlockedExchange((long volatile*)_Target, _Value);
}

extern "C" long MB_InterlockedExchangeAdd(long volatile* _Addend, long _Value)
{
    return _InterlockedExchangeAdd((long volatile*)_Addend, _Value);
}

extern "C" long MB_InterlockedDecrement(long volatile* _Target)
{
    return _InterlockedDecrement((long volatile*)_Target);
}

extern "C" long MB_InterlockedCompareExchange(long volatile* _Destination, long _Exchange, long _Comparand)
{
    return _InterlockedCompareExchange((long volatile*)_Destination, _Exchange, _Comparand);
}

#else // linux

uintptr_t MbTlsAlloc()
{
    pthread_key_t key;
    pthread_key_create(&key, NULL);
    return (uintptr_t)key;
}

LPVOID MbTlsGetValue(uintptr_t dwTlsIndex)
{
    return pthread_getspecific((pthread_key_t)dwTlsIndex);
}

BOOL MbTlsSetValue(uintptr_t dwTlsIndex, LPVOID lpTlsValue)
{
    pthread_setspecific((pthread_key_t)dwTlsIndex, lpTlsValue);
    return TRUE;
}

BOOL MbTlsFree(uintptr_t dwTlsIndex)
{
    pthread_key_delete((pthread_key_t)dwTlsIndex);
    return TRUE;
}

extern "C" long MB_InterlockedIncrement(long volatile* _Target)
{
    return _InterlockedIncrement((volatile int*)_Target);
}

extern "C" long MB_InterlockedExchange(long volatile* _Target, long _Value)
{
    return _InterlockedExchange((volatile int*)_Target, _Value);
}

extern "C" long MB_InterlockedExchangeAdd(long volatile* _Addend, long _Value)
{
    return _InterlockedExchangeAdd((volatile int*)_Addend, _Value);
}

extern "C" long MB_InterlockedDecrement(long volatile* _Target)
{
    return _InterlockedDecrement((volatile int*)_Target);
}

extern "C" long MB_InterlockedCompareExchange(long volatile* _Destination, long _Exchange, long _Comparand)
{
    return _InterlockedCompareExchange((volatile int*)_Destination, _Exchange, _Comparand);
}

extern "C" void MB__atomic_load(size_t size, void* ptr, void* ret, int memorder)
{
    do {
#if __SIZEOF_LONG__ == 8
        if (1 == size) {
            *(char*)ret = *(char*)ptr;
            return;
        } else if (2 == size) {
            *(int16_t*)ret = *(int16_t*)ptr;
            return;
        } else if (4 == size) {
            *(int32_t*)ret = *(int32_t*)ptr;
            return;
        } else if (8 == size) {
            *(int64_t*)ret = *(int64_t*)ptr;
            return;
        }
#endif
    } while (false);

    printf("MB__atomic_load fail: %zu\n", size);
    __debugbreak();
}

extern "C" void MB__atomic_store(size_t size, void* dest, const void* src, int memorder)
{
    MB__atomic_load(size, (void*)src, dest, memorder);
}

//extern "C" int64_t _InterlockedExchange64(int64_t volatile* _Target, int64_t _Value);
extern "C" __int32 _InterlockedExchange(__int32 volatile* _Target, __int32 _Value);
extern "C" __int64 InterlockedExchangeAcquire64(__int64 volatile* _Target, __int64 _Value);

extern "C" void MB__atomic_exchange(size_t size, void* ptr, void* val, void* ret, int memorder)
{
    static_assert(sizeof(long) == 8);
    static_assert(sizeof(long long) == 8);
    do {
#if __SIZEOF_LONG__ == 8
        if (2 == size) {
            __int16 retv = _InterlockedExchange16((__int16 volatile*)ptr, *(__int16*)val);
            *(__int16*)ret = (__int16)retv;
            return;
        } else if (4 == size) {
            long retv = _InterlockedExchange((__int32 volatile*)ptr, *(__int32*)val);
            *(int32_t*)ret = (int32_t)retv;
            return;
        } else if (8 == size) {
            int64_t retv = _InterlockedExchange64((int64_t volatile*)ptr, *(int64_t*)val);
            *(int64_t*)ret = (int64_t)retv;
            return;
        }
#endif
    } while (false);

    printf("MB__atomic_exchange fail: %zu\n", size);
    __debugbreak();
}

#endif

#if (defined(_M_X64) || defined(__x86_64__)) && defined(__clang__)
// for BN_mod_word in div.c
extern "C" unsigned __int64 MB__umodti3(unsigned __int64 a, unsigned __int64 b)
{
    return a % b;
}
extern "C" unsigned __int64 MB__udivti3(unsigned __int64 a, unsigned __int64 b)
{
    return a / b;
}
#endif