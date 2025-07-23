// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ELECTRON_SHELL_COMMON_GIN_HELPER_ERROR_THROWER_H_
#define ELECTRON_SHELL_COMMON_GIN_HELPER_ERROR_THROWER_H_

#include <string>

#include "v8/include/v8.h"

namespace gin_helper {

class ErrorThrower {
public:
    explicit ErrorThrower(v8::Isolate* isolate);
    ErrorThrower();
    ~ErrorThrower() = default;

    void ThrowError(const std::string& err_msg) const;
    void ThrowTypeError(const std::string& err_msg) const;
    void ThrowRangeError(const std::string& err_msg) const;
    void ThrowReferenceError(const std::string& err_msg) const;
    void ThrowSyntaxError(const std::string& err_msg) const;

    v8::Isolate* isolate() const
    {
        return m_isolate;
    }

private:
    using ErrorGenerator = v8::Local<v8::Value> (*)(v8::Local<v8::String> err_msg , v8::Local<v8::Value> options);
    void Throw(ErrorGenerator gen, const std::string& err_msg) const;

    v8::Isolate* m_isolate;
};

} // namespace gin_helper

#endif // ELECTRON_SHELL_COMMON_GIN_HELPER_ERROR_THROWER_H_
