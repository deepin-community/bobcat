
#include "ecdh.ih"

ECDH::ECDH(ThePeer peer, string const &initPubFname,       
                         string const &peerPubFname)
:
    ECDH()
{
    set(peer, initPubFname, peerPubFname);
}

