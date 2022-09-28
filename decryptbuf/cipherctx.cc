#include "decryptbuf.ih"

EVP_CIPHER_CTX *DecryptBuf::cipherCtx()
{
    return d_ctx;
}
