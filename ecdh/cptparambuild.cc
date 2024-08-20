
#include "ecdh.ih"

ECDH::ptrOSSL_PARAM_BLD ECDH::cptParamBuild() const
{
                                            // cpt an OSSL_PARAM_BLD.
    ptrOSSL_PARAM_BLD paramBuild{ OSSL_PARAM_BLD_new(), OSSL_PARAM_BLD_free };
 
    if (paramBuild == 0)
        throw "OSSL_PARAM_BLD_new";

                                // store the curve name in paramBuild
    if (OSSL_PARAM_BLD_push_utf8_string(
                paramBuild.get(),
                "group",                    // OSSL_PKEY_PARAM_GROUP_NAME
                &d_curveName.front(), 0) == 0
    )
        throw "OSSL_PARAM_BLD_push_utf8_string";

    return paramBuild;
}
