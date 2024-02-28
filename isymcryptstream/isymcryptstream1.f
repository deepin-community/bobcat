template <CryptType cryptType>
template <typename StreamSpec>
ISymCryptStream<cryptType>::ISymCryptStream(
    StreamSpec &streamSpec,
    std::string const &cipherName,
    std::string const &key,
    std::string const &iv,
    size_t inBufSize
)
:
    ISymCryptStreambuf<cryptType>(
        streamSpec,
        cipherName,
        key,
        iv,
        inBufSize
    ),
    std::istream(this)
{}
