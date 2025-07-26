
#ifndef patch_code_simple_tls_h
#define patch_code_simple_tls_h

#include <windows.h>
#include <stdio.h>

#if defined(__clang__)
#pragma GCC diagnostic ignored "-Wexit-time-destructors"
#pragma GCC diagnostic ignored "-Wglobal-constructors"
#pragma GCC diagnostic ignored "-Wvoid-pointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-void-pointer-cast"
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

long MB_InterlockedCompareExchange(long volatile*, long, long);
long MB_InterlockedExchange(long volatile* _Target, long _Value);
uintptr_t MbTlsAlloc();
LPVOID MbTlsGetValue(uintptr_t dwTlsIndex);
BOOL MbTlsSetValue(uintptr_t dwTlsIndex, LPVOID lpTlsValue);
BOOL MbTlsFree(uintptr_t dwTlsIndex);

#ifdef __cplusplus
}
#endif // __cplusplus

class SimpleTlsPointerImpl {
public:
    typedef uintptr_t TlsKey;

    SimpleTlsPointerImpl()
    {
        slot_ = 0;
        run_once_ = 0;
        default_val_ = nullptr;
    }

    SimpleTlsPointerImpl(void* default_val)
    {
        slot_ = 0;
        run_once_ = 0;
        default_val_ = default_val;
    }
    ~SimpleTlsPointerImpl()
    {
    }

    struct SlotItem {
        void* val;
    };

    void* Get();
    void Set(void* ptr);

    void operator=(void* val)
    {
        Set(val);
    }

    void* operator->()
    {
        return Get();
    }

private:
    SlotItem* GetItem();

    SlotItem* SetDefault()
    {
#if defined(OS_WIN)
        SlotItem* it = (SlotItem*)::HeapAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(SlotItem));
#else
        SlotItem* it = (SlotItem*)malloc(sizeof(SlotItem));
#endif
        it->val = default_val_;
        MbTlsSetValue(slot_, (LPVOID)it);

        return it;
    }

    long run_once_;
    TlsKey slot_;
    void* default_val_;
};

template <typename T> class SimpleTlsPointerXp {
public:
    SimpleTlsPointerXp()
        : impl_()
    {
    }

    SimpleTlsPointerXp(void* default_val)
        : impl_(default_val)
    {
    }

    T* Get()
    {
        return (T*)impl_.Get();
    }
    void Set(T* ptr)
    {
        impl_.Set((void*)ptr);
    }

    void operator=(T* val)
    {
        Set(val);
    }

    T* operator->()
    {
        return Get();
    }

private:
    SimpleTlsPointerImpl impl_;
};

inline SimpleTlsPointerImpl::SlotItem* SimpleTlsPointerImpl::GetItem()
{
    SlotItem* it = nullptr;

    do {
        volatile long old_var = MB_InterlockedCompareExchange((long volatile*)&(run_once_), 2, 0);
        if (0 == old_var) {
            if (0 != slot_)
                DebugBreak();
            slot_ = MbTlsAlloc();
            it = SetDefault();

            MB_InterlockedExchange((long volatile*)&(run_once_), 1);
            break;
        } else if (1 == old_var) {
            if (0 == slot_)
                DebugBreak();
            it = (SlotItem*)MbTlsGetValue(slot_);
            if (!it)
                it = SetDefault();
            break;
        } else if (2 == old_var) {
            continue;
        } else {
            DebugBreak();
        }
    } while (true);

    return it;
}

inline void* SimpleTlsPointerImpl::Get()
{
    SlotItem* it = GetItem();
    return it->val;
}

inline void SimpleTlsPointerImpl::Set(void* ptr)
{
    SlotItem* it = GetItem();
    it->val = ptr;
}

template <typename T> class SimpleTlsValueXp {
public:
    SimpleTlsValueXp()
        : tlp_(nullptr)
    {
    }
    ~SimpleTlsValueXp()
    {
    }

    SimpleTlsValueXp(T v)
        : tlp_((void*)v)
    {
    }

    T Get()
    {
        return (T)tlp_.Get();
    }
    void Set(T val)
    {
        tlp_.Set((void*)val);
    }

    void operator=(T val)
    {
        Set(val);
    }

private:
    SimpleTlsPointerImpl tlp_;
};

class SimpleTlsBoolXp {
public:
    SimpleTlsBoolXp()
        : tlp_(nullptr)
    {
    }
    ~SimpleTlsBoolXp()
    {
    }

    SimpleTlsBoolXp(bool val)
        : tlp_(val ? this : nullptr)
    {
    }

    void operator=(bool val)
    {
        Set(val);
    }

    bool Get()
    {
        return !!tlp_.Get();
    }
    void Set(bool val)
    {
        tlp_.Set(val ? this : nullptr);
    }

private:
    SimpleTlsPointerImpl tlp_;
};

class SimpleTlsIntptrXp {
public:
    SimpleTlsIntptrXp()
        : tlp_(nullptr)
    {
    }
    ~SimpleTlsIntptrXp()
    {
    }

    SimpleTlsIntptrXp(intptr_t val)
        : tlp_((void*)val)
    {
    }

    intptr_t Get()
    {
        return (intptr_t)tlp_.Get();
    }
    void Set(intptr_t val)
    {
        tlp_.Set((void*)val);
    }

    void operator=(intptr_t val)
    {
        Set(val);
    }

    void operator++()
    {
        Set(Get() + 1);
    }

    void operator--()
    {
        Set(Get() - 1);
    }

    void operator+=(intptr_t val)
    {
        Set(Get() + val);
    }

    void operator-=(intptr_t val)
    {
        Set(Get() - val);
    }

private:
    SimpleTlsPointerImpl tlp_;
};

class SimpleTlsUint8Xp {
public:
    inline SimpleTlsUint8Xp()
        : tlp_(nullptr)
    {
    }
    inline ~SimpleTlsUint8Xp()
    {
    }

    uint8_t Get()
    {
        return (uint8_t)tlp_.Get();
    }
    void Set(uint8_t val)
    {
        tlp_.Set((void*)val);
    }

    void operator=(uint8_t val)
    {
        Set(val);
    }

    void operator+=(uint8_t val)
    {
        Set(Get() + val);
    }

    void operator-=(uint8_t val)
    {
        Set(Get() - val);
    }

private:
    SimpleTlsPointerImpl tlp_;
};

// class SimpleTlsInt32Xp {
// public:
//   SimpleTlsInt32Xp();
//   ~SimpleTlsInt32Xp();
//
//   int32_t Get() { return (int32_t)tlp_.Get(); }
//   void Set(int32_t val) { tlp_.Set((void*)val); }
//
//   void operator=(int32_t val) {
//     Set(val);
//   }
//
//   void operator+=(int32_t val) {
//     Set(Get() + val);
//   }
//
//   void operator++() {
//     Set(Get() + 1);
//   }
//
//   void operator--() {
//     Set(Get() - 1);
//   }
//
//   void operator-=(int32_t val) {
//     Set(Get() - val);
//   }
// private:
//   SimpleTlsPointerImpl tlp_;
// };

// inline SimpleTlsUint8Xp::SimpleTlsUint8Xp() {}
// inline SimpleTlsUint8Xp::~SimpleTlsUint8Xp() {}

// inline SimpleTlsIntptrXp::SimpleTlsIntptrXp() {}
// inline SimpleTlsIntptrXp::~SimpleTlsIntptrXp() {}

// inline SimpleTlsBoolXp::SimpleTlsBoolXp() {}
// inline SimpleTlsBoolXp::~SimpleTlsBoolXp() {}

// inline SimpleTlsInt32Xp::SimpleTlsInt32Xp() {}
// inline SimpleTlsInt32Xp::~SimpleTlsInt32Xp() {}

// template <typename T>
// inline SimpleTlsValueXp<T>::SimpleTlsValueXp() {}
//
// template <typename T>
// inline SimpleTlsValueXp<T>::~SimpleTlsValueXp(){}

//#pragma GCC diagnostic pop
#endif