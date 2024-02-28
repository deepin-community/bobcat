#include "symcryptbase.ih"

SymCryptBase::SymCryptBase(
            string const &cipherName,
            string const &key,
            string const &iv,

            OSSL_PARAM const *params,

            int (*evpInit)(EVP_CIPHER_CTX *, EVP_CIPHER const *,
                unsigned char const *key, unsigned char const *iv,
                OSSL_PARAM const *param)
)
:
    d_cipherName(cipherName)
{
    EVP_CIPHER *cipher = cipherOf(&cipherName.front());
    lengthCheck("key", EVP_CIPHER_get_key_length(cipher), key.length());
    lengthCheck("iv",  EVP_CIPHER_get_iv_length(cipher),  iv.length());

    if ((d_ctx = EVP_CIPHER_CTX_new()) == 0)
        throw Exception{} << "EVP_CIPHER_CTX_new failed";

    if (not ((*evpInit)(d_ctx, cipher,
                reinterpret_cast<unsigned char const *>(key.data()),
                reinterpret_cast<unsigned char const *>(iv.data()),
                params)))
    {
        EVP_CIPHER_CTX_free(d_ctx);
        throw Exception{} << "EVP_{En,De}cryptInit_ex2 failed";
    }

    d_blockSize = EVP_CIPHER_CTX_block_size(d_ctx);

    EVP_CIPHER_free(cipher);
}
