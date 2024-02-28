
#include "ecdh.ih"

// static
ECDH::ptrEVP_PKEY_CTX ECDH::keyGenContext() const
{
    ptrEVP_PKEY_CTX ret{ EVP_PKEY_CTX_new_from_name(0, "EC", 0), 
                         EVP_PKEY_CTX_free };
    if (ret == 0)
         throw "EVP_PKEY_CTX_new_from_name";

                                 // Initialize the key generation context.
    if (EVP_PKEY_keygen_init(ret.get()) <= 0) 
         throw "EVP_PKEY_keygen_init";
 
    auto pBuild = cptParamBuild();
                                // Set the params including the curve name
                                // cptParams() converts OSSL_PARAM_BLD to 
                                // OSSL_PARAM.
    if (not EVP_PKEY_CTX_set_params(ret.get(), cptParams(pBuild).get()))
         throw "EVP_PKEY_CTX_set_params";

    return ret;    
}
