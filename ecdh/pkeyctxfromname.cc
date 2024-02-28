
#include "ecdh.ih"

// static
EVP_PKEY_CTX *ECDH::pkeyCtxFromName()
{
    auto ret = EVP_PKEY_CTX_new_from_name(0, "EC", 0);

    if (ret == 0)
         throw "EVP_PKEY_CTX_new_from_name";

    return ret;
}
