
#include "ecdh.ih"

// static
ECDH::ptrOSSL_PARAM ECDH::cptParams(ptrOSSL_PARAM_BLD const &pBuild)
{
    auto ret = ptrOSSL_PARAM{ 
                OSSL_PARAM_BLD_to_param(pBuild.get()), OSSL_PARAM_free };

    if (ret == 0)
        throw "OSSL_PARAM_BLD_to_param";

    return ret;
}
