
#include "ecdh.ih"

// static
ECDH::ptrEVP_PKEY ECDH::pkeyFromCtx(ptrEVP_PKEY_CTX &ctx, 
                                    ptrOSSL_PARAM &params, size_t type)
{
    EVP_PKEY *tmp = 0;
    if (EVP_PKEY_fromdata(ctx.get(), &tmp, type, params.get()) != 1)
        throw "EVP_PKEY_fromdata";

    return { tmp, EVP_PKEY_free };
}
