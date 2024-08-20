#include "diffiehellman.ih"

BigInt const &DiffieHellman::key(istream &peerPublicStream)
{
    BigInt prime;
    BigInt generator;

    if (not(peerPublicStream >> hex >> prime >> generator >> d_peerPubKey))
        throw exception() << "could not read the peer's public key";

    if (prime != d_prime || generator != d_generator)
        throw exception() <<
            "the peer's prime and/or generator differ from "
                                                    "the current values";
    return key();
}
