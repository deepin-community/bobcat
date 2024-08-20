#include "ifdbufs.ih"

std::streamsize IFdBufS::xsgetn(char *dest, std::streamsize size)
{
    if (size == 0)
        return 0;

    d_selector.wait();

    return p_xsgetn(dest, size);
//
//    int avail = egptr() - gptr();
//
//    if (avail > size)
//        avail = size;
//
//    memcpy(dest, gptr(), avail);
//    gbump(avail);
//
//    return avail + read(fd(), dest + avail, size - avail);
}
