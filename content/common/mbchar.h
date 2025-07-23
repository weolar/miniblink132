#ifndef WTF_MBCHAR_H
#define WTF_MBCHAR_H

#if 1 // !defined(BUILDING_V8_SHARED) && !defined(USING_V8_SHARED)

// ugly hack to make UChar compatible with JSChar in API/JSStringRef.h
#if defined(WIN32) // || defined(Q_OS_WIN) || COMPILER(WINSCW) || (COMPILER(RVCT) && !OS(LINUX))
typedef char16_t UChar;
#define mbu16(x) L##x
#else
#define mbu16(x) u##x
//typedef uint16_t UChar;
typedef char16_t UChar;
#endif // WIN32

#if 1 //!USE(QT_ICU_TEXT_BREAKING)
//typedef uint32_t UChar32;
typedef int32_t UChar32;
#endif

inline size_t u16len(const UChar* s)
{
    size_t i = 0;
    for (; s[i]; ++i) {
    }
    return i;
}
#endif // BUILDING_V8_SHARED
#endif // WTF_MBCHAR_H