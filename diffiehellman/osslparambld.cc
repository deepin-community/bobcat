#include "diffiehellman.ih"

// called from cptdomainkey.cc

                            // Cpt OSSL_PARAM_BLD (man ossl_param_bld)
OSSL_PARAM *DiffieHellman::osslParamBuild()
{
    OSSL_PARAM_BLD *paramBld = OSSL_PARAM_BLD_new();
    if (!paramBld)
        throw exception() << "OSSL_PARAM_BLD_new failed";

    if (                        // Assign d_prime and d_generator.
        not OSSL_PARAM_BLD_push_BN(paramBld, "p", &d_prime.bignum())
        ||
        not OSSL_PARAM_BLD_push_BN(paramBld, "g", &d_generator.bignum())
    )
    {
        OSSL_PARAM_BLD_free(paramBld);
        throw exception() << "OSSL_PARAM_BLD_push_BN failed";
    }

                                            // Convert to OSSL_PARAM.
    OSSL_PARAM *param = OSSL_PARAM_BLD_to_param(paramBld);

    OSSL_PARAM_BLD_free(paramBld);          // see man ossl_param_bld:
                                            // OK after 'to_param'
    if (!param)
        throw exception() << "OSSL_PARAM_BLD_to_param failed";

    return param;
}
