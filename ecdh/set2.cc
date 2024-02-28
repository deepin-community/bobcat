
#include "ecdh.ih"

void ECDH::set([[maybe_unused]] ThePeer peer, 
               string const &initPubFname, string const &peerPubFname)
{
    auto in = Exception::factory<ifstream>(initPubFname);
    in >> d_otherPubKey >> d_curveName;

    cptKeys();

    auto out = Exception::factory<ofstream>(peerPubFname);
    out <<  d_pubKey    << '\n';

    cptSharedKey();
}
