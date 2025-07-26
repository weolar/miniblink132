
#ifndef patch_code_thread_safe_static_local_h
#define patch_code_thread_safe_static_local_h

// #define DEFINE_NEW_PTR_THREAD_SAFE_STATIC_LOCAL(Type, Name, Arguments) \
//   static long run_once_##Name = 0; \
//   static Type* s_##Name = nullptr; \
//   do { \
//     volatile long old_var##Name = _InterlockedCompareExchange((long volatile *)&(run_once_##Name), 2, 0); \
//     if (0 == old_var##Name) { \
//       s_##Name = new Type Arguments; \
//       _InterlockedExchange((long volatile *)&(run_once_##Name), 1); \
//       break; \
//     } else if (1 == old_var##Name) { \
//       break; \
//     } else if (2 == old_var##Name) { \
//       continue; \
//     } else { \
//       DebugBreak(); \
//     } \
//   } while (true); \
//   if (!(s_##Name)) \
//     DebugBreak(); \
//   Type& Name = *(s_##Name)

#define DEFINE_XP_THREAD_SAFE_STATIC_LOCAL(Type, Name, Arguments)                                                                                              \
    static long run_once_##Name = 0;                                                                                                                           \
    static Type* s_##Name = nullptr;                                                                                                                           \
    do {                                                                                                                                                       \
        volatile long old_var##Name = _InterlockedCompareExchange((long volatile*)&(run_once_##Name), 2, 0);                                                   \
        if (0 == old_var##Name) {                                                                                                                              \
            s_##Name = Arguments;                                                                                                                              \
            _InterlockedExchange((long volatile*)&(run_once_##Name), 1);                                                                                       \
            break;                                                                                                                                             \
        } else if (1 == old_var##Name) {                                                                                                                       \
            break;                                                                                                                                             \
        } else if (2 == old_var##Name) {                                                                                                                       \
            continue;                                                                                                                                          \
        } else {                                                                                                                                               \
            DebugBreak();                                                                                                                                      \
        }                                                                                                                                                      \
    } while (true);                                                                                                                                            \
    if (!(s_##Name))                                                                                                                                           \
        DebugBreak();                                                                                                                                          \
    Type& Name = *(s_##Name)

#endif // patch_code_thread_safe_static_local_h