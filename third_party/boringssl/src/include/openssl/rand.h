
#ifndef boringssl_src_include_openssl_rand_h
#define boringssl_src_include_openssl_rand_h

#include "third_party/openssl/openssl/include/openssl/rand.h"

// RAND_get_system_entropy_for_custom_prng writes |len| bytes of random data
// from a system entropy source to |buf|. The maximum length of entropy which
// may be requested is 256 bytes. If more than 256 bytes of data is requested,
// or if sufficient random data can not be obtained, |abort| is called.
// |RAND_bytes| should normally be used instead of this function. This function
// should only be used for seed values or where |malloc| should not be called
// from BoringSSL. This function is not FIPS compliant.
OPENSSL_EXPORT void RAND_get_system_entropy_for_custom_prng(uint8_t* buf, size_t len);

#endif