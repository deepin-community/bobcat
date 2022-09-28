inline
IBase64Buf<ENCRYPT>::IBase64Buf(std::istream &in, size_t bufSize)
:
    Base64BufBase(in, bufSize)
{
    doEncrypt();
}
