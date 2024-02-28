#include "diffiehellman.ih"

    // cpt keys containing the private and public  keys

    // writekey() with "pub" or "priv" used to write the keys
    // getKey() with "pub" or "priv" is used to obtain the public/private keys

void DiffieHellman::cptKeys()
{
                                // Cpt OSSL_PARAM (man ossl_param_bld)
    OSSL_PARAM *param = osslParamBuild();

                                           // Cpt the context.
    EVP_PKEY_CTX *domainCtx = cptDomainContext(param);

    EVP_PKEY *domainKey = cptDomainKey(domainCtx, param);

    EVP_PKEY *keys = keyPair(domainKey);

    EVP_PKEY_free(domainKey);

//    char nr = '0';
//    createKeys(&nr, d_prime, d_generator, domainKey, keys);


    checkKeys(keys);

    d_pubKey = getKey(keys, "pub");
    d_privKey = getKey(keys, "priv");

    EVP_PKEY_free(keys);
}
