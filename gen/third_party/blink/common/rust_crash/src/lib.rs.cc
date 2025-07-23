#include "third_party/blink/common/rust_crash/rust_crash.h"

namespace blink {
extern "C" {
void blink$cxxbridge1$crash_in_rust() noexcept;

void blink$cxxbridge1$reenter_rust() noexcept;

void blink$cxxbridge1$crash_in_rust_with_overflow() noexcept;

void blink$cxxbridge1$EnterCppForRustCrash() noexcept
{
    void (*EnterCppForRustCrash$)() = ::blink::EnterCppForRustCrash;
    EnterCppForRustCrash$();
}
} // extern "C"

void crash_in_rust() noexcept
{
    blink$cxxbridge1$crash_in_rust();
}

void reenter_rust() noexcept
{
    blink$cxxbridge1$reenter_rust();
}

void crash_in_rust_with_overflow() noexcept
{
    blink$cxxbridge1$crash_in_rust_with_overflow();
}
} // namespace blink
