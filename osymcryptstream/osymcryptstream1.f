template <CryptType cryptType>
template <typename StreamSpec>
OSymCryptStream<cryptType>::OSymCryptStream(
    StreamSpec &streamSpec,
    std::string const &cipherName,
    std::string const &key,
    std::string const &iv,
    size_t inBufSize
)
:
    OSymCryptStreambuf<cryptType>(
        streamSpec,
        cipherName,
        key,
        iv,
        inBufSize
    ),
    std::ostream(this)
{}
