#include "qpbufbase.ih"

void QPBufBase::escape(unsigned char ch)
{
    d_pending.push_back('=');
    d_pending.push_back(s_hexChars[ch >> 4]);
    d_pending.push_back(s_hexChars[ch & 0xf]);
}
