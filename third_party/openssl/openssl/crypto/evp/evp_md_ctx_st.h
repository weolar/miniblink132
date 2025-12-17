
#ifndef evp_md_ctx_st_h
#define evp_md_ctx_st_h

#define EVP_CTRL_RET_UNSUPPORTED -1

struct evp_md_ctx_st {
    const EVP_MD* reqdigest; /* The original requested digest */
    const EVP_MD* digest;
    ENGINE* engine; /* functional reference if 'digest' is
                                 * ENGINE-provided */
    unsigned long flags;
    void* md_data;
    /* Public key context for sign/verify */
    EVP_PKEY_CTX* pctx;
    /* Update function: usually copied from EVP_MD */
    int (*update)(EVP_MD_CTX* ctx, const void* data, size_t count);

    /*
     * Opaque ctx returned from a providers digest algorithm implementation
     * OSSL_FUNC_digest_newctx()
     */
    void* algctx;
    EVP_MD* fetched_digest;
} /* EVP_MD_CTX */;

struct evp_cipher_ctx_st {
    const EVP_CIPHER* cipher;
    ENGINE* engine; /* functional reference if 'cipher' is
                                 * ENGINE-provided */
    int encrypt; /* encrypt or decrypt */
    int buf_len; /* number we have left */
    unsigned char oiv[EVP_MAX_IV_LENGTH]; /* original iv */
    unsigned char iv[EVP_MAX_IV_LENGTH]; /* working iv */
    unsigned char buf[EVP_MAX_BLOCK_LENGTH]; /* saved partial block */
    int num; /* used by cfb/ofb/ctr mode */
    /* FIXME: Should this even exist? It appears unused */
    void* app_data; /* application stuff */
    int key_len; /* May change for variable length cipher */
    int iv_len; /* IV length */
    unsigned long flags; /* Various flags */
    void* cipher_data; /* per EVP data */
    int final_used;
    int block_mask;
    unsigned char final[EVP_MAX_BLOCK_LENGTH]; /* possible final block */

    /*
     * Opaque ctx returned from a providers cipher algorithm implementation
     * OSSL_FUNC_cipher_newctx()
     */
    void* algctx;
    EVP_CIPHER* fetched_cipher;
} /* EVP_CIPHER_CTX */;

#endif // evp_md_ctx_st_h