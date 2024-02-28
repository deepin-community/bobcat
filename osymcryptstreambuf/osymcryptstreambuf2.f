template <typename StreamSpec>
inline OSymCryptStreambuf<DECRYPT>::OSymCryptStreambuf(
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
        &EVP_DecryptInit_ex2, &EVP_DecryptUpdate, &EVP_DecryptFinal_ex
    )
{}
