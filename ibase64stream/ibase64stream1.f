template <CryptType type>
IBase64Stream<type>::IBase64Stream(std::istream &in, size_t bufSize)
:
    IBase64Buf<type>(in, bufSize),
    std::istream(this)
{}
