
#include "ecdh.ih"

// static
ECDH::ptrOSSL_PARAM ECDH::setPrivKey(ptrOSSL_PARAM_BLD &paramBuild,
                                    string const &initSecFname, 
                                    string password)
{
    BigInt priv = privateKey(initSecFname, password);

    if (OSSL_PARAM_BLD_push_BN(paramBuild.get(), "priv", &priv.bignum()) != 1)
        throw "OSSL_PARAM_BLD_push_BN";

    return cptParams(paramBuild);
}
