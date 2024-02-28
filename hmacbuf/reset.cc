#include "hmacbuf.ih"

void HMacBuf::reset()
{
    if (d_ctx != 0 or d_key.empty())
        return;

    //  man evp_mac_fetch:
    // MACs are a bit complex insofar that some of them use other algorithms
    // for actual computation.  HMAC uses a digest, and CMAC uses a cipher.

    EVP_MAC *mac = EVP_MAC_fetch(0, "cmac", 0);

    OSSL_PARAM params[] =
    {
        OSSL_PARAM_construct_utf8_string("cipher", &d_cipher[0], 0),
        OSSL_PARAM_construct_utf8_string("digest", &d_digest[0], 0),
        OSSL_PARAM_construct_end()
    };

    d_ctx = EVP_MAC_CTX_new(mac);

    call(EVP_MAC_init(d_ctx,
                reinterpret_cast<unsigned char const *>(d_key.c_str()),
                d_key.length(), params), "init");

    EVP_MAC_free(mac);

    d_digest.erase();
    setp();
}
