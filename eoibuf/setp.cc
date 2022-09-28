#include "eoibuf.ih"

void EoiBuf::setp()
{
    streambuf::setp(&*d_buffer.begin(), &*d_buffer.end());
}
