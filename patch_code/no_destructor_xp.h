// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef patch_code_no_destructor_xp_h
#define patch_code_no_destructor_xp_h

extern "C" long MB_InterlockedCompareExchange(long volatile*, long, long);
extern "C" long MB_InterlockedExchange(long volatile* _Target, long _Value);

#define DEFINE_XP_THREAD_SAFE_STATIC_LOCAL(Type, Name, Arguments)                                                                                              \
    static long run_once_##Name = 0;                                                                                                                           \
    static Type* s_##Name = nullptr;                                                                                                                           \
    do {                                                                                                                                                       \
        long old_var = MB_InterlockedCompareExchange((long volatile*)&(run_once_##Name), 2, 0);                                                                \
        if (0 == old_var) {                                                                                                                                    \
            s_##Name = new Type Arguments;                                                                                                                     \
            MB_InterlockedExchange((long volatile*)&(run_once_##Name), 1);                                                                                     \
            break;                                                                                                                                             \
        } else if (1 == old_var) {                                                                                                                             \
            break;                                                                                                                                             \
        } else if (2 == old_var) {                                                                                                                             \
            continue;                                                                                                                                          \
        } else {                                                                                                                                               \
            *(int*)1 = 1;                                                                                                                                      \
        }                                                                                                                                                      \
    } while (true);                                                                                                                                            \
    if (!(s_##Name))                                                                                                                                           \
        *(int*)1 = 1;                                                                                                                                          \
    Type& Name = *(s_##Name)

#endif // patch_code_no_destructor_xp_h
