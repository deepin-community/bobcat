template <CryptType type>
IQuotedPrintableStream<type>::IQuotedPrintableStream(std::istream &in, 
                                                     size_t bufSize)
:
    IQuotedPrintableBuf<type>(in, bufSize),
    std::istream(this)
{}
