
#include "ecdh.ih"

EVP_PKEY *ECDH::pkeyGenerate(EVP_PKEY_CTX *ctx)
{
    EVP_PKEY *keyPair = 0;      // cpt a key pair.
    if (EVP_PKEY_generate(ctx, &keyPair) != 1) 
        throw "EVP_PKEY_generate";

    return keyPair;
}
