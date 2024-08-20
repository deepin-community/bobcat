
#include "ecdh.ih"

void ECDH::set([[maybe_unused]] TheInitiator init, 
               string const &curveName, string const &initPubFname)
{
    d_curveName = curveName;

    cptKeys();

    auto out = Exception::factory<ofstream>(initPubFname);
    out <<  d_pubKey    << '\n' <<
            d_curveName << '\n';
}
