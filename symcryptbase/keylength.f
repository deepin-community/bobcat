inline size_t SymCryptBase::keyLength(std::string const &cipherName)
{
    return lengthOf(EVP_CIPHER_get_key_length, cipherName);
}
