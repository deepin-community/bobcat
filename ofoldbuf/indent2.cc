#include "ofoldbuf.ih"

void OFoldBuf::indent()
{
    for (size_t nr = 0; nr < d_indent; ++nr)
        put(d_indentChar);
}
