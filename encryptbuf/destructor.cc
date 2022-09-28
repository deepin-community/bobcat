#include "encryptbuf.ih"

EncryptBuf::~EncryptBuf()
{
    if (not d_eoi)
        eoi();

    EVP_CIPHER_CTX_free(d_ctx);
}
