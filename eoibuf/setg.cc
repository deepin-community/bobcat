#include "eoibuf.ih"

void EoiBuf::setg(unsigned next, unsigned beyond)
{
    char *begin = &d_buffer[0];

    streambuf::setg(begin, begin + next, begin + beyond);
}
