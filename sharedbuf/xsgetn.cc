#include "sharedbuf.ih"

streamsize SharedBuf::xsgetn(char *data, streamsize len)
{
    return mode(ios::in) ? d_memory.read(data, len) : EOF;
}
