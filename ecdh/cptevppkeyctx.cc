
#include "ecdh.ih"

// static
ECDH::ptrEVP_PKEY_CTX ECDH::cptEvpPkeyCtx()
{
    ptrEVP_PKEY_CTX ret{pkeyCtxFromName(), EVP_PKEY_CTX_free };

    if (EVP_PKEY_fromdata_init(ret.get()) != 1)
        throw "EVP_PKEY_fromdata_init";

    return ret;
}
