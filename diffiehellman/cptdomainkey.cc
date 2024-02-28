#include "diffiehellman.ih"

EVP_PKEY *DiffieHellman::cptDomainKey(EVP_PKEY_CTX *domainCtx,
                                      OSSL_PARAM *param)
{
    EVP_PKEY *domainKey = 0;
                                            // Cpt the domain parameter keys.
    bool ok =
        EVP_PKEY_fromdata(domainCtx, &domainKey,
                          EVP_PKEY_KEY_PARAMETERS, param)
        == 1;

    EVP_PKEY_CTX_free(domainCtx);
    OSSL_PARAM_free(param);

    if (not ok)
    {
        EVP_PKEY_free(domainKey);
        throw exception() << "EVP_PKEY_fromdata failed";
    }

    return domainKey;
}
