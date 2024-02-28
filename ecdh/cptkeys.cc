
#include "ecdh.ih"

void ECDH::cptKeys()
try
{
    ERR_clear_error();

                                // cpt the EC key generation context and set
    auto ctx = keyGenContext(); // the parameters containing the curve name  

 
    EVP_PKEY *keyPair = 0;      // cpt a key pair.
    if (EVP_PKEY_generate(ctx.get(), &keyPair) != 1) 
        throw "EVP_PKEY_generate";
 
    d_keyPair.reset(keyPair);

    cptPubKey();                    // cpt the public hex-key
    cptPrivKey();                    // cpt the private hex-key
}
catch (char const *what)
{
    throw Exception{} << "generateKeys: " << what << " failed " <<
                lastErrorString();
}
