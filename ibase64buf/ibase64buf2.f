inline
IBase64Buf<DECRYPT>::IBase64Buf(std::istream &in, size_t bufSize)
:
    Base64BufBase(in, bufSize)
{
    doDecrypt();
}
