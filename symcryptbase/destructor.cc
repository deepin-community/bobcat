#include "symcryptbase.ih"

SymCryptBase::~SymCryptBase()
{
    EVP_CIPHER_CTX_free(d_ctx);
}
