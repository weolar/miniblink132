
#ifndef patch_code_std_mutex_xp_h
#define patch_code_std_mutex_xp_h

#include <mutex>

#ifdef SUPPORT_XP_CODE

#ifndef _WINDOWS_

#pragma pack(push, 8)

typedef struct _CRITICAL_SECTION_XP {
#if _WIN64
    char dummy[40];
#else
    char dummy[24];
#endif
} CRITICAL_SECTION_XP;

#pragma pack(pop)

extern "C" void __stdcall InitializeCriticalSection(CRITICAL_SECTION_XP*);
extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION_XP*);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION_XP*);
extern "C" long __cdecl InterlockedCompareExchange(long volatile* Destination, long ExChange, long Comperand);

#else

typedef CRITICAL_SECTION CRITICAL_SECTION_XP;

#endif // _WINBASE_

class std_mutex {
public:
    std_mutex()
    {
        ::InitializeCriticalSection(&m_mu);
    }
    void lock()
    {
        ::EnterCriticalSection(&m_mu);
    }
    void unlock()
    {
        ::LeaveCriticalSection(&m_mu);
    }

    CRITICAL_SECTION_XP* getLock()
    {
        return &m_mu;
    }

private:
    CRITICAL_SECTION_XP m_mu;
};

template <class _Fn, class... _Args> void std_call_once(std::once_flag& onceFlag, _Fn&& fx, _Args&&... args)
{
    for (;;) {
        int32_t previousState = InterlockedCompareExchange((LONG volatile*)&onceFlag._Opaque, // Destination
            1, //  Exchange Value
            0); //  Compare value

        if (previousState == 0) {
            std::invoke(std::forward<_Fn>(fx), std::forward<_Args>(args)...);
            onceFlag._Opaque = (void*)2;
            break; // Caller will next call the init function. Current state == 1.
        } else if (previousState == 2) {
            // Another thread already completed the initialization.
            // We can simply return FALSE, indicating no
            // further action is needed by the caller.
            return;
        } else {
            // Another thread is currently running the initialization.
            // Wait until it completes.
            continue;
        }
    }
}

#else

typedef std::mutex std_mutex;

template <typename... Args> void std_call_once(Args&&... args)
{
    std::call_once(std::forward<Args>(args)...);
}

#endif
#endif