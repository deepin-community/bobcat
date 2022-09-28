inline IQuotedPrintableBuf<DECRYPT>::IQuotedPrintableBuf(
            std::istream &in, size_t bufSize)
:
    QPBufBase(in, bufSize)
{
    doDecode();
}
