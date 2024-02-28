#include "ofdbuf.ih"

int OFdBuf::sync()
{
    int ret = 0;

    if (pptr() > pbase())               // if there are chars in the buffer
    {                                   // then write them to the device
        if (write(d_fd, ucharPtr(), pptr() - pbase()) < 0)
        {
            ret = -1;
            if ((d_mode & WARN) == WARN)
                std::cerr << "[Warning] OFdBuf::sync could not "
                             "write to FD " << d_fd << '\n';
        }
        setp();                         // and reset the stream pointers
    }
    return ret;                         // return OK.
}
