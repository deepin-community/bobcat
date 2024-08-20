#include "symcryptbase.ih"

// static
size_t SymCryptBase::lengthOf(int (*getLength)(EVP_CIPHER const *),
                                      string const &cipherName)
{
    auto *cipher = cipherOf(cipherName);

    size_t length = (*getLength)(cipher);   // EVP_CIPHER_get_key_length or
                                            // EVP_CIPHER_get_iv_length

    EVP_CIPHER_free(cipher);

    return length;
}
