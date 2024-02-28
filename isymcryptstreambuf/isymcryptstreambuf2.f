template <typename StreamSpec>
inline ISymCryptStreambuf<DECRYPT>::ISymCryptStreambuf(
                    StreamSpec &streamSpec,
                    std::string const &cipherName,
                    std::string const &key,
                    std::string const &iv,
                    size_t inBufSize
        )
:
    ISymCryptBase(
        streamSpec,
        cipherName,
        key,
        iv,
        inBufSize,
        0,
        &EVP_DecryptInit_ex2, &EVP_DecryptUpdate, &EVP_DecryptFinal_ex
    )
{}
