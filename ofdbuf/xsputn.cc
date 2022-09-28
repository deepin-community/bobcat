#include "ofdbuf.ih"

// override
streamsize OFdBuf::xsputn(char const *buffer, streamsize nChars) 
{
    streamsize pending = nChars;

    while (pending > 0)
    {
        streamsize available = epptr() - pptr();

        if (available == 0)
        {
            sync();
            continue;
        }

        streamsize write = available < pending ? available : pending;

        memcpy(pptr(), buffer, write);
        pbump(write);

        pending -= write;
        buffer += write;
    }

    return nChars;
}



