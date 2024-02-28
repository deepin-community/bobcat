#include "ecdh.ih"

std::string const &ECDH::sharedKey(std::string const &peerPubFname) 
{
    auto in = Exception::factory<ifstream>(peerPubFname);
    in >> d_otherPubKey;

    cptSharedKey();
    return d_sharedKey;
}
