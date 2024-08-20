
#include "ecdh.ih"

    // computes secret key as hex-string
void ECDH::cptPrivKey()
try
{
    // ERR_clear_error();

    BIGNUM *privKey = 0;
    if (EVP_PKEY_get_bn_param(d_keyPair.get(), "priv", &privKey) == 0)
        throw " EVP_PKEY_get_bn_param";

    BigInt key{ privKey };
    BN_free(privKey);

    d_privKey = (ostringstream{} << hex << key).str();
    if (d_privKey.empty())
        throw "ostringstream{} << hex << key)";
}
catch (char const *what)
{
    throw Exception{} << "privKey: " << what << " failed " <<
                lastErrorString();
}
