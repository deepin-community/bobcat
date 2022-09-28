#include "decryptbuf.ih"

int DecryptBuf::overflow(int ch)
{
    flushBuffer();

    if (ch != EOF)
    {
        *pptr() = ch;         
        pbump(1);
    }

    return ch;
}
