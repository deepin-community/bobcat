#include "diffiehellman.ih"

void DiffieHellman::checkKeys(EVP_PKEY *keys)
try
{
    auto *ctx = EVP_PKEY_CTX_new(keys, 0);

    if (ctx == 0)
        throw "EVP_PKEY_CTX_new failed for keys";

    int ret = EVP_PKEY_check(ctx);

    EVP_PKEY_CTX_free(ctx);

    if (ret != 1)
        throw "EVP_PKEY_check failed";
}
catch (char const *msg)
{
    EVP_PKEY_free(keys);
    throw exception() << msg;
}
