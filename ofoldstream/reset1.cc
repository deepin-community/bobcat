#include "ofoldstream.ih"

void OFoldStream::reset(string const &fname, 
                    size_t leftIndent, size_t rightMargin, TrailingBlanks tb)
{
    OFoldBuf::reset(fname);               // = OFilterBuf::
    setMargins(leftIndent, rightMargin);
    setTrailingBlanks(tb);
}
