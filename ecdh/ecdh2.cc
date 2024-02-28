
#include "ecdh.ih"

ECDH::ECDH(TheInitiator init, string const &curveName, 
                              string const &initPubFname)
:
    ECDH()
{
    set(init, curveName, initPubFname);
}

