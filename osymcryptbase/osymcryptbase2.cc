#include "osymcryptbase.ih"

OSymCryptBase::OSymCryptBase(
            string const &outStreamName,

            string const &cipherName,
            string const &key,
            string const &iv,

            size_t inBufSize,

            OSSL_PARAM const *params,

            int (*evpInit)(EVP_CIPHER_CTX *, EVP_CIPHER const *,
                unsigned char const *key, unsigned char const *iv,
                OSSL_PARAM const *param),

            int (*evpUpdate)(EVP_CIPHER_CTX *,
                unsigned char *out, int *outl,
                unsigned char const *in, int inl),

            int (*evpFinal)(EVP_CIPHER_CTX *,
                unsigned char *out, int *outl)
)
:
    SymCryptBase(cipherName, key, iv, params, evpInit),
    EoiBuf(inBufSize < 100 ? 100 : inBufSize),
    d_ofStream(
        new ofstream{ Exception::factory<ofstream>(outStreamName) }
    ),
    d_outStream(*d_ofStream.get()),
    d_evpUpdate(evpUpdate),
    d_evpFinal(evpFinal)
{
    setp();
}
