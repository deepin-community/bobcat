#include "diffiehellman.ih"

// static
EVP_PKEY_CTX *DiffieHellman::cptDomainContext(OSSL_PARAM *param)
try
{
    EVP_PKEY_CTX *domainCtx = EVP_PKEY_CTX_new_from_name(0, "DHX", 0);
    if (!domainCtx)
         throw exception() << "EVP_PKEY_CTX_new_from_name failed";

                                            // Initialize the context.
    if (EVP_PKEY_fromdata_init(domainCtx) <= 0)
    {
        EVP_PKEY_CTX_free(domainCtx);
        throw Exception{} << "EVP_PKEY_fromdata_init failed";
    }

    return domainCtx;
}
catch (...)
{
    OSSL_PARAM_free(param);
    throw;
}
