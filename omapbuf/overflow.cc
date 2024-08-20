#define XERR
#include "omapbuf.ih"

// overrides
int Omapbuf::overflow(int ch)
{
//xerr("OMapbuf: " << absPos());
    
    sync();                 // write the current mmap buffer to file

//xerr("OMapbuf (2):" << absPos());

    if (not (load()))
        return EOF;

    *pptr() = static_cast<char>(ch);    // put it into the buffer
    pbump(1);                           // advance the buffer's pointer

    return ch;
}
