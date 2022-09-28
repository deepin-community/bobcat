#include "ofdbuf.ih"

int OFdBuf::overflow(int ch)
{
    sync();                                     
    if (ch != EOF)
    {
        *pptr() = ch;
        pbump(1);
    }
    return ch;
}
    
