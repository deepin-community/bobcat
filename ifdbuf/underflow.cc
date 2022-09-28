#include "ifdbuf.ih"

int IFdBuf::underflow()
{
//    if (gptr() < egptr())               
//        return static_cast<unsigned char>(*gptr());

    int nread = read(d_fd, &buffer()[0], bufSize());

    if (nread <= 0)
        return EOF;

    setg(0, nread);

            // the static_cast<size_t char> is required to prevent
            // promotions of 0xff characters to -1, thus returning EOF...
    return static_cast<unsigned char>(*gptr());
}
    
