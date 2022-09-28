#include "ofoldstream.ih"

void OFoldStream::reset(ostream &out, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    OFoldBuf::reset(out);             // = OFilterBuf
    setMargins(leftIndent, rightMargin);
    setTrailingBlanks(tb);
}
