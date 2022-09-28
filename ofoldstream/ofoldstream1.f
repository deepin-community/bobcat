inline OFoldStream::OFoldStream(std::string const &fname, 
                    size_t leftIndent, size_t rightMargin, 
                    TabsOrBlanks tob, TrailingBlanks tb)
:
    OFoldBuf(fname, leftIndent, rightMargin, tob, tb),
    std::ostream(this)
{}
