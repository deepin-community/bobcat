inline OFoldStream::OFoldStream(std::ostream &out, 
                    size_t leftIndent, size_t rightMargin, 
                    TabsOrBlanks tob, TrailingBlanks tb)
:
    OFoldBuf(out, leftIndent, rightMargin, tob, tb),
    std::ostream(this)
{}
