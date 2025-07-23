
#ifndef INCLUDE_BASE_ELECTRON_MACROS_H_
#define INCLUDE_BASE_ELECTRON_MACROS_H_
#pragma once

#if !defined(arraysize)

// The arraysize(arr) macro returns the # of elements in an array arr.
// The expression is a compile-time constant, and therefore can be
// used in defining new arrays, for example.  If you use arraysize on
// a pointer by mistake, you will get a compile-time error.
//
// One caveat is that arraysize() doesn't accept any array of an
// anonymous type or a type defined inside a function.  In these rare
// cases, you have to use the unsafe ARRAYSIZE_UNSAFE() macro below.  This is
// due to a limitation in C++'s template system.  The limitation might
// eventually be removed, but it hasn't happened yet.

// This template function declaration is used in defining arraysize.
// Note that the function doesn't need an implementation, as we only
// use its type.
template <typename T, size_t N> char (&ArraySizeHelper(T (&array)[N]))[N];

// That gcc wants both of these prototypes seems mysterious. VC, for
// its part, can't decide which to use (another mystery). Matching of
// template overloads: the final frontier.
#ifndef _MSC_VER
template <typename T, size_t N> char (&ArraySizeHelper(const T (&array)[N]))[N];
#endif

#define arraysize(array) (sizeof(ArraySizeHelper(array)))

#endif // !arraysize

//-------

#if !defined(DISALLOW_COPY_AND_ASSIGN)

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName)                                                                                                                     \
    void operator=(const TypeName&) = delete;                                                                                                                  \
    void operator=(TypeName&&) = delete;                                                                                                                       \
    TypeName(const TypeName&) = delete;                                                                                                                        \
    TypeName(TypeName&&) = delete

#endif // !DISALLOW_COPY_AND_ASSIGN

//-------
#if !defined(DISALLOW_ASSIGN)
// Explicitly declare the assignment operator as deleted.
// Note: This macro is deprecated and will be removed soon. Please explicitly
// delete the assignment operator instead.
#define DISALLOW_ASSIGN(TypeName) TypeName& operator=(const TypeName&) = delete
#endif

//-------
#if !defined(DISALLOW_IMPLICIT_CONSTRUCTORS)
// Explicitly declare all implicit constructors as deleted, namely the
// default constructor, copy constructor and operator= functions.
// This is especially useful for classes containing only static methods.
#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName)                                                                                                               \
    TypeName() = delete;                                                                                                                                       \
    TypeName(const TypeName&) = delete;                                                                                                                        \
    DISALLOW_ASSIGN(TypeName)
#endif

#define THREAD_LOCAL_CONSTRUCTOR(name)                                                                                                                         \
    static base::ThreadLocalPointer<v8::Persistent<v8::Function>> s_##name##Constructor;                                                                       \
                                                                                                                                                               \
    static v8::Persistent<v8::Function>& get##name##Constructor()                                                                                              \
    {                                                                                                                                                          \
        v8::Persistent<v8::Function>* constructorPtr = s_##name##Constructor.Get();                                                                            \
        if (!constructorPtr) {                                                                                                                                 \
            constructorPtr = new v8::Persistent<v8::Function>();                                                                                               \
            s_##name##Constructor.Set(constructorPtr);                                                                                                         \
        }                                                                                                                                                      \
        return *constructorPtr;                                                                                                                                \
    }

//-------

#endif