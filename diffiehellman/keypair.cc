#include "diffiehellman.ih"

// static
EVP_PKEY *DiffieHellman::keyPair(EVP_PKEY *domainkey)
{
    EVP_PKEY_CTX *keyCtx = EVP_PKEY_CTX_new_from_pkey(0, domainkey, 0);
    if (!keyCtx)
        throw Exception{} << "EVP_PKEY_CTX_new_from_pkey failed";

    if (EVP_PKEY_keygen_init(keyCtx) <= 0)
        throw Exception{} << "EVP_PKEY_CTX_keygen_init failed";

    EVP_PKEY *keys = 0;
    if (EVP_PKEY_generate(keyCtx, &keys) <= 0)
            throw Exception{} << "EVP_PKEY_generate failed";

    EVP_PKEY_CTX_free(keyCtx);

    BIGNUM *tmp = 0;
    if (not EVP_PKEY_get_bn_param(keys, "pub", &tmp))
        throw Exception{} << "get_bn_param pub fails";
    BN_free(tmp);

    tmp = 0;
    if (not EVP_PKEY_get_bn_param(keys, "priv", &tmp))
        throw Exception{} << "get_bn_param priv fails";
    BN_free(tmp);

    return keys;
}
