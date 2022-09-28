#include "ifilterbuf.ih"

int IFilterBuf::pbackfail(int ch)
{
    if (bufSize() == d_maxSize)                 // the buffer is at its 
        return EOF;                             // max. size: no extensions

    buffer().insert(0, 1, ch);                  // insert ch at the front

    setg(0, bufSize());                         // start reading from the 
                                                // beginning
    return ch;
}
