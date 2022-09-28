#include "decryptbuf.ih"

DecryptBuf::~DecryptBuf()
{
    if (not d_eoi)
        eoi();

    EVP_CIPHER_CTX_free(d_ctx);
}
