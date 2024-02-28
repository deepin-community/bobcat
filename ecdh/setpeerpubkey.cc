
#include "ecdh.ih"

// static
void ECDH::setPeerPubKey(ptrOSSL_PARAM_BLD const &paramBuild,
                            string const &otherPubKey)
{
    if (
        OSSL_PARAM_BLD_push_octet_string(
            paramBuild.get(), "pub", &otherPubKey.front(), otherPubKey.length()
        ) 
        != 1
    ) 
        throw "OSSL_PARAM_BLD_push_octet_string";
}
