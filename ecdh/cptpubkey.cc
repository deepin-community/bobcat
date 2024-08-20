
#include "ecdh.ih"

void ECDH::cptPubKey()
try
{
    //ERR_clear_error();

    size_t keyLength = 0;

    if (EVP_PKEY_get_octet_string_param(
                                   d_keyPair.get(), "pub", 0, 0, &keyLength) 
        == 0
    )
        throw "EVP_PKEY_get_octet_string_param";

                                                        // Get the key.
    unique_ptr<uint8_t[]> publicKey{ new uint8_t[keyLength] };

    if (EVP_PKEY_get_octet_string_param(
            d_keyPair.get(), "pub", publicKey.get(), keyLength, &keyLength)
      == 0
    ) 
        throw "EVP_PKEY_get_octet_string_param";

    d_pubKey =                           // public key in hex format
            toHex({ reinterpret_cast<char *>(publicKey.get()), keyLength });

}
catch (char const *what)
{
    throw Exception{} << "publicKey: " << what << " failed " <<
                lastErrorString();
}
