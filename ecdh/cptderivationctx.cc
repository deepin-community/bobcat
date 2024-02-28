
#include "ecdh.ih"

ECDH::ptrEVP_PKEY_CTX ECDH::cptDerivationCtx() const
{
    ptrEVP_PKEY_CTX ctx{ EVP_PKEY_CTX_new(d_keyPair.get(), 0), 
                         EVP_PKEY_CTX_free };
    if (!ctx) 
        throw "EVP_PKEY_CTX_new";

                                // initialize the derivation context.
    if (EVP_PKEY_derive_init(ctx.get()) <= 0) 
        throw "EVP_PKEY_derive_init";

    return ctx;
}
