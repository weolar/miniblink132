
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/IdLiveDetect.h"
#include "electron/common/NodeBinding.h"
#include "electron/common/NodeThread.h"
#include "electron/common/AtomVersion.h"
#include "electron/common/V8Util.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/EventEmitterCaller.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/error_thrower.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_buffer.h"

// electron\shell\browser\api\electron_api_safe_storage.cc
// components/os_crypt/sync/os_crypt_win.cc

namespace OSCrypt {

const char* kEncryptionKey = "AtomEncryptionKey";

static std::string stringXOR(const std::string& content, const std::string& key)
{
    std::string str = content;
    for (unsigned int i = 0; i < str.length(); i++) {
        str[i] ^= key[i % key.length()];
    }

    return str;
}

bool EncryptString(const std::string& plaintext, std::string* ciphertext)
{
    *ciphertext = stringXOR(plaintext, kEncryptionKey);
    return true;
}

bool DecryptString(const std::string& ciphertext, std::string* plaintext)
{
    *plaintext = stringXOR(ciphertext, kEncryptionKey);
    return true;
}

} // OSCrypt

namespace atom {

const char* kEncryptionVersionPrefixV10 = "v10";
const char* kEncryptionVersionPrefixV11 = "v11";
bool use_password_v10 = false;

static void setUsePasswordV10(bool use)
{
    use_password_v10 = use;
}

static bool isEncryptionAvailable()
{
    // #if BUILDFLAG(IS_LINUX)
    //     // Calling IsEncryptionAvailable() before the app is ready results in a crash
    //     // on Linux.
    //     // Refs: https://github.com/electron/electron/issues/32206.
    //     if (!electron::Browser::Get()->is_ready())
    //         return false;
    //     return OSCrypt::IsEncryptionAvailable() ||
    //         (use_password_v10 &&
    //             static_cast<BrowserProcessImpl*>(g_browser_process)
    //             ->linux_storage_backend() == "basic_text");
    // #else
    //     return OSCrypt::IsEncryptionAvailable();
    // #endif
    return true;
}

static v8::Local<v8::Value> encryptString(v8::Isolate* isolate, const std::string& plaintext)
{
    if (!isEncryptionAvailable()) {
        //         if (!electron::Browser::Get()->is_ready()) {
        //             gin_helper::ErrorThrower(isolate).ThrowError(
        //                 "safeStorage cannot be used before app is ready");
        //             return v8::Local<v8::Value>();
        //         }
        gin_helper::ErrorThrower(isolate).ThrowError("Error while encrypting the text provided to safeStorage.encryptString. Encryption is not available.");
        return v8::Local<v8::Value>();
    }

    std::string ciphertext;
    bool encrypted = OSCrypt::EncryptString(plaintext, &ciphertext);

    if (!encrypted) {
        gin_helper::ErrorThrower(isolate).ThrowError("Error while encrypting the text provided to safeStorage.encryptString.");
        return v8::Local<v8::Value>();
    }

    return node::Buffer::Copy(isolate, ciphertext.c_str(), ciphertext.size()).ToLocalChecked();
}

static std::string decryptString(v8::Isolate* isolate, v8::Local<v8::Value> buffer)
{
    if (!isEncryptionAvailable()) {
        //         if (!electron::Browser::Get()->is_ready()) {
        //             gin_helper::ErrorThrower(isolate).ThrowError(
        //                 "safeStorage cannot be used before app is ready");
        //             return "";
        //         }
        gin_helper::ErrorThrower(isolate).ThrowError("Error while decrypting the ciphertext provided to "
                                                     "safeStorage.decryptString. Decryption is not available.");
        return "";
    }

    if (!node::Buffer::HasInstance(buffer)) {
        gin_helper::ErrorThrower(isolate).ThrowError("Expected the first argument of decryptString() to be a buffer");
        return "";
    }

    // ensures an error is thrown in Mac or Linux on
    // decryption failure, rather than failing silently
    const char* data = node::Buffer::Data(buffer);
    auto size = node::Buffer::Length(buffer);
    std::string ciphertext(data, size);
    if (ciphertext.empty())
        return "";

    if (ciphertext.find(kEncryptionVersionPrefixV10) != 0 && ciphertext.find(kEncryptionVersionPrefixV11) != 0) {
        gin_helper::ErrorThrower(isolate).ThrowError("Error while decrypting the ciphertext provided to "
                                                     "safeStorage.decryptString. Ciphertext does not appear to be encrypted.");
        return "";
    }

    std::string plaintext;
    bool decrypted = OSCrypt::DecryptString(ciphertext, &plaintext);
    if (!decrypted) {
        gin_helper::ErrorThrower(isolate).ThrowError("Error while decrypting the ciphertext provided to safeStorage.decryptString.");
        return "";
    }
    return plaintext;
}

static void initializeApiSafeStorage(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
    v8::Isolate* isolate = context->GetIsolate();
    gin_helper::Dictionary dict(isolate, exports);
    dict.SetMethodT("decryptString", &decryptString);
    dict.SetMethodT("encryptString", &encryptString);
    // #if BUILDFLAG(IS_LINUX)
    //     dict.SetMethod("getSelectedStorageBackend", &GetSelectedLinuxBackend);
    // #endif
    dict.SetMethodT("isEncryptionAvailable", &isEncryptionAvailable);
    dict.SetMethodT("setUsePlainTextEncryption", &setUsePasswordV10);
}

static const char SafeStorageSricpt[] = "exports = {};";

static NodeNative nativeSafeStorageNative { "ApiSafeStorage", SafeStorageSricpt, sizeof(SafeStorageSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_safe_storage, initializeApiSafeStorage, &nativeSafeStorageNative)

} // atom