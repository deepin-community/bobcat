template <typename StreamSpec>
inline OSymCryptStreambuf<ENCRYPT>::OSymCryptStreambuf(
                    StreamSpec &streamSpec,
                    std::string const &cipherName,
                    std::string const &key,
                    std::string const &iv,
                    size_t inBufSize
        )
:
    OSymCryptBase(
        streamSpec,
        cipherName,
        key,
        iv,
        inBufSize,
        0,
        &EVP_EncryptInit_ex2,  &EVP_EncryptUpdate, &EVP_EncryptFinal_ex
    )
{}
