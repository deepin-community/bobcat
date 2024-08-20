#define XERR
#include "omapbuf.ih"

std::ios::pos_type Omapbuf::seekpos(ios::pos_type offset, ios::openmode mode)
{
    return seekoff(offset, ios::beg, mode);

//                                            // absPos in the current buffer?
//    if (offset() <= absPos() and absPos() <= offset() + length())
//    {
//        setp(begin(), begin() + length());
//        pbump(absPos() - offset());         // go to the next write position
//    }
//    else                                    // if not in the current buffer
//        map(PROT_READ | PROT|WRITE);        // then mmap
    
}
