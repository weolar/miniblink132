#pragma once
#include "third_party/blink/common/rust_crash/rust_crash.h"

namespace blink {
void crash_in_rust() noexcept;

void reenter_rust() noexcept;

void crash_in_rust_with_overflow() noexcept;
} // namespace blink
