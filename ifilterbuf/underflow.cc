#include "ifilterbuf.ih"

int IFilterBuf::underflow()
{
    if (d_srcBegin == d_srcEnd)                 // no (more) source bytes:
    {                                           // get some. If none available
        if (not filter(&d_srcBegin, &d_srcEnd)) // return EOF
            return EOF;
    }

    size_t size = d_srcEnd - d_srcBegin;        // #available source bytes
    if (size > d_maxSize)                       // store at most maxSize bytes
        size = d_maxSize;

    buffer().assign(d_srcBegin, size);          // store the chars in the buf.
    setg(0, size);                              // set the buffer ptrs.

    d_srcBegin += size;                         // consumed `size' source
                                                // bytes 

    return static_cast<unsigned char>(*gptr());
}

