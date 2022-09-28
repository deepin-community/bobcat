#include "sharedbuf.ih"

std::streamsize SharedBuf::xsputn(char const *buf, std::streamsize len)
{
    return mode(ios::out) ? d_memory.write(buf, len) : EOF;
}
