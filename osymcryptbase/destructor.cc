#include "osymcryptbase.ih"

OSymCryptBase::~OSymCryptBase()
{
    eoi_();
//    EVP_CIPHER_CTX_free(d_ctx);
}
