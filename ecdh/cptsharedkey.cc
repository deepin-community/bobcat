
#include "ecdh.ih"

void ECDH::cptSharedKey()
try
{
    ERR_clear_error();
                                        // the peer public key
    auto peerKey = otherPubKey();

    auto ctx = cptDerivationCtx();      // the derivation context.

                                        // store the peer public key
    if (EVP_PKEY_derive_set_peer(ctx.get(), peerKey.get()) != 1)
        throw "EVP_PKEY_derive_set_peer";

    size_t length = 0;                // determine the shared secret's length
    if (EVP_PKEY_derive(ctx.get(), 0, &length) != 1 or length == 0)
        throw "EVP_PKEY_derive";
  
    std::string sharedSecret(length, 0);    // prepare the shared secret
    if (                                    // cpt the shared secret.
        EVP_PKEY_derive(
            ctx.get(),
            reinterpret_cast<unsigned char *>(&sharedSecret.front()), 
            &length) != 1
    ) 
        throw "EVP_PKEY_derive";

    d_sharedKey = toHex(sharedSecret);  // return the hex shared secret
}
catch (char const *what)
{
    throw Exception{} << "sharedSecret: " << what << " failed " <<
                lastErrorString();
}
