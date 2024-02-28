#include "diffiehellman.ih"

    // given the current user's (initiator or peer) private key and the
    // other party's public key, compute the shared secret

    // initiator computes
    //          initiator-public = generator^initiator-secret % prime
    // and sends initiator-public to the peer
    // peer then computes
    //          common = initiator-public^peer-secret % prime
    // likewise, the initiator computes:
    //          common = peer-public^initator-secret % prime

BigInt const &DiffieHellman::key()
{
    d_common = d_peerPubKey.expModc(d_privKey, d_prime);

    BigInt qValue{(d_prime - 1) >> 1};
                                // (prime - 1) / 2 is also prime, as
                                // d_prime should be a safe prime.
                                // Then qValue, according to
                                // RFC 2631, should be so that p = j * q + 1
                                // is prime. Here j == 2
    if
    (
        d_common == 1 || d_common >= d_prime - 1 ||
        d_common.expModc(qValue, d_prime) != 1
    )
        throw exception() <<
                    "shared key is not resistant to the small group attack";

    return d_common;
}
