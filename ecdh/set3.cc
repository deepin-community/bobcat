
#include "ecdh.ih"

void ECDH::set(string const &curveName, string const &peerPubFname,
               string const &initSecFname, string const &password)
{
    {
        auto in = Exception::factory<ifstream>(peerPubFname);
        in >> d_otherPubKey;
    }

    d_curveName = curveName;

    auto paramBuild = cptParamBuild();

    auto param = setPrivKey(paramBuild, initSecFname, password);

    auto ctx = cptEvpPkeyCtx();

    d_keyPair = pkeyFromCtx(ctx, param, EVP_PKEY_KEYPAIR);

    cptSharedKey();
}
