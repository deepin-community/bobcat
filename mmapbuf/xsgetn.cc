#define XERR
#include "mmapbuf.ih"

// override
std::streamsize MmapBuf::xsgetn(char *dest, std::streamsize req)
{
    if (req <= 0)
        return 0;

    size_t request = req;
    size_t nRead = 0;

    while (request)
    {
        size_t nAvail = showmanyc(); 

        if (nAvail == 0)
        {
            if (underflow() == EOF)
                break;
        }
        else 
        {
            size_t nObtained = readn(&dest, min(request , nAvail));
            nRead += nObtained;
            request -= nObtained;
        }
    }

    return nRead;
}
