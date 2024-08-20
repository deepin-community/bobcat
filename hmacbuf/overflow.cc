#include "hmacbuf.ih"

// override
int HMacBuf::overflow(int ch)
{
    EVP_MAC_update(d_ctx, ucharPtr(), bufSize());

    setp();                             // FBB::EoiBuf

    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }

    return ch;
}
