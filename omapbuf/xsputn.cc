#define XERR
#include "omapbuf.ih"

// overrides
streamsize Omapbuf::xsputn(char const *buffer, streamsize nChars)
{
    streamsize nWritten = 0;

    if (append())
        setAbsPos(fileSize(), ios::beg);

    while (nWritten != nChars)
    {
        streamsize avail = epptr() - pptr();

        if (avail == 0)                         // buffer full / not yet set
        {
            overflow(*buffer);                  // reload the buffer
            ++nWritten;                         // one char written by overfl.
            continue;
        }

        streamsize toWrite = min(avail, nChars - nWritten);

        memmove(pptr(), buffer + nWritten, toWrite);
        pbump(toWrite);

        nWritten += toWrite;
    }

    return nChars;    
}


