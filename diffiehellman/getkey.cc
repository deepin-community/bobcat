#include "diffiehellman.ih"

BigInt DiffieHellman::getKey(EVP_PKEY *keys,
                             char const *type) const  // type: "pub" or "priv"
{
    BIGNUM *bignum = 0;

    if (not EVP_PKEY_get_bn_param(keys, type, &bignum))
    {
        EVP_PKEY_free(keys);
        throw exception() << "can't extract the " << type << " key";
    }

    BigInt key{ bignum };
    BN_free(bignum);

    return key;
}
