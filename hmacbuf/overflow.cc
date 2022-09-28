#include "hmacbuf.ih"

int HMacBuf::overflow(int ch)
{
    HMAC_Update(d_ctx, ucharPtr(), bufSize());

    setp();

    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }
    return ch;
}
