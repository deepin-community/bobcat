#define XERR
#include "mmapbuf.ih"

std::streamsize MmapBuf::xsputn(char const *buffer, std::streamsize request)
{
    if (request <= 0)
        return 0;

    size_t pending = request;
    size_t nWritten = 0;

    while (pending)
    {
        size_t nAvail = epptr() - pptr(); 
        if (nAvail == 0)
        {
            overflow(*buffer++);
            ++nWritten;
            --pending;
        }
        else 
        {
            size_t wrote = writen(&buffer, min(pending, nAvail));
            nWritten += wrote;
            pending -= wrote;
        }
    }

    return nWritten;
}



