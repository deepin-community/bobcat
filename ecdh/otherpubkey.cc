
#include "ecdh.ih"

ECDH::ptrEVP_PKEY ECDH::otherPubKey() const
try
{
    string peerKey = toData(d_otherPubKey);

                                // cpt an OSSL_PARAM_BLD for the used curve
    auto paramBuild = cptParamBuild();
                            
                                            // set the peer public key in
    setPeerPubKey(paramBuild, peerKey);     // paramBuild

                                            
    auto params = cptParams(paramBuild);    // paramBuild to OSSL_PARAM

    auto ctx = cptEvpPkeyCtx();             // cpt an EVP_PKEY context.

                                            // cpt the peer public key's
                                            // EVP_PKEY ptr
    return pkeyFromCtx(ctx, params, EVP_PKEY_PUBLIC_KEY);
}
catch (char const *what)
{
    throw Exception{} << "otherPubKey: " << what << " failed: " <<
                         lastErrorString();
}
