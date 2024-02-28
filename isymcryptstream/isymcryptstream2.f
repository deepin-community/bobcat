template <CryptType cryptType>
ISymCryptStream<cryptType>::ISymCryptStream(
    std::istream &&inStream,
    std::string const &cipherName,
    std::string const &key,
    std::string const &iv,
    size_t inBufSize
)
:
    ISymCryptStreambuf<cryptType>(
//        std::move(inStream),
        inStream,
        cipherName,
        key,
        iv,
        inBufSize
    ),
    std::istream(this)
{
    std::string line;
    std::getline(inStream, line);
    std::cerr << "instream: " << inStream.good() << ": " << line << '\n';
}
