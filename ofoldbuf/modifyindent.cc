#include "ofoldbuf.ih"

void OFoldBuf::modifyIndent(int delta)
{
    d_indent += delta;
    if (static_cast<int>(d_indent) < 0)
        d_indent = 0;
}
