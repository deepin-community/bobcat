#include "decryptbuf.ih"

DecryptBuf::DecryptBuf(ostream &outStream, char const *type, 
                        string const &key, string const &iv, size_t size)
:
    CryptBuf(type, size < EVP_MAX_BLOCK_LENGTH ? 
                        (size = EVP_MAX_BLOCK_LENGTH) : size),
    d_ctx(EVP_CIPHER_CTX_new()),
    d_decrypted(bufSize(), 0),
    d_iv(iv),
    d_key(key),
    d_outStream(outStream)
{
    if (
        not EVP_DecryptInit_ex(d_ctx, md(), 0, ucharPtr(d_key), 
                                               ucharPtr(d_iv))
    )
        throw Exception{ 1 } << "DecryptBuf: initialization failed";

////    d_cipherBlockSize = EVP_CIPHER_CTX_block_size(d_ctx);

    setp();
}







