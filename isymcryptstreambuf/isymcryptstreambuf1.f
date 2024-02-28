template <typename StreamSpec>
inline ISymCryptStreambuf<ENCRYPT>::ISymCryptStreambuf(
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
        &EVP_EncryptInit_ex2,  &EVP_EncryptUpdate, &EVP_EncryptFinal_ex
    )
{}
