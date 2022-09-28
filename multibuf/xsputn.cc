#include "multibuf.ih"

std::streamsize MultiBuf::xsputn(char const *buffer, std::streamsize n)
{
    d_buffer.append(buffer, n);
    return n;
}
