
#include "ecdh.ih"

void ECDH::pkeyInit(EVP_PKEY_CTX *ctx)
{
                                 // Initialize the key generation context.
    if (EVP_PKEY_keygen_init(ctx) != 1) 
         throw "EVP_PKEY_keygen_init";
}
