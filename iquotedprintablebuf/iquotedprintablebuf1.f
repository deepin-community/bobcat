inline IQuotedPrintableBuf<ENCRYPT>::IQuotedPrintableBuf(
            std::istream &in, size_t bufSize)
:
    QPBufBase(in, bufSize)
{
    doEncode();
}
