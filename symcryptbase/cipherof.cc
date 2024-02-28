#include "symcryptbase.ih"

// static
EVP_CIPHER *SymCryptBase::cipherOf(string const &cipherName)
{
    EVP_CIPHER *cipher = EVP_CIPHER_fetch(0, &cipherName.front(), 0);

    if (cipher == 0)
        throw Exception{} << "EVP_CIPHER_fetch " << cipherName << " failed";

    return cipher;
}
