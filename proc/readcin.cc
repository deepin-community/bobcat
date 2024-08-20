#include "proc.ih"

void Proc::readCin()
{                                                   // closes the d_read fd
    int fd = (*d_pipesPtr)[d_read].writeOnlyFd();

    d_oBuf.reset(fd, d_bufSize);   // OK, insertions into *this

    if (d_in != 0)
    {
        *this << d_in->rdbuf();
        if (d_admin & DELETE_D_IN)
        {
            delete d_in;
            d_admin &= ~DELETE_D_IN;
        }
        d_in = 0;
    }

    if (not localPipes())
        *this << eoi;
}




//    OFdStream out{ fd, d_bufSize };               // OK, 
//    out << cin.rdbuf() << std::flush;

//  cerr<<cin.rdbuf()<<std::flush;                  // OK
//  ::close(fd);
//  return;

//    d_oBuf.reset(fd, d_bufSize);                    // OK, start calls close
//    ostream out{ &d_oBuf };
//    out << cin.rdbuf();

//    d_oBuf.reset(fd, d_bufSize);                    // OK, start calls close
//    rdbuf(&d_oBuf);
//    *this << cin.rdbuf();

//    d_oBuf.reset(fd, d_bufSize);            // OK, start calls close
//    *this << cin.rdbuf();                   // d_oBuf is Proc's streambuf 
                                            // set by the constructor

//    d_oBuf.reset(fd, d_bufSize);            // OK, main calls close
//    *this << cin.rdbuf(); 

//    d_oBuf.reset(fd, d_bufSize);                // OK, insertions into *this

