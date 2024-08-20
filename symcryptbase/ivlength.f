inline size_t SymCryptBase::ivLength(std::string const &cipherName)
{
    return lengthOf(EVP_CIPHER_get_iv_length, cipherName);
}
