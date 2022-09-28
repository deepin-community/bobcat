#include "encryptbuf.ih"

EncryptBuf::EncryptBuf(ostream &outStream, char const *type, 
                       string key, string const &iv, size_t size)
:
    CryptBuf(type, size),
    d_ctx(EVP_CIPHER_CTX_new()),
    d_encrypted(size + EVP_MAX_BLOCK_LENGTH, 0),
    d_iv(iv),
    d_key(key),
    d_outStream(outStream)
{
    prepareIV();

    if (
        not EVP_EncryptInit_ex(d_ctx, md(), 0, ucharPtr(d_key), 
                                               ucharPtr(d_iv))
    )
        throw Exception{ 1 } << "Encrypt initialization failed";

    setp();
}





