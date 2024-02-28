//#include "process.ih"
//
//void Process::v_parentRedirections()
//{
//    d_selector = Selector{};                // multiple file IO/alarm handling
//
//    if (d_setMode & CLOSE_ON_EXEC)
//        closeChildInputOnExec();
//
//    if (d_mode & CIN)                       // parent's ostream writes to
//    {                                       // the child's cin stream: the
//                                            // parent writes, the child reads
//        int fd = d_childIn_paWritePipe.writeOnly(); 
//
//        if (not (d_setMode & IN_PIPE))
//        {
//            d_toChildCinBuf.reset(fd, 200); // streambuf to write to the child
//            d_oChild.rdbuf(&d_toChildCinBuf);   // activate the stream to the
//                                                // child process
//        }
//    }
//
//    if ((d_mode & (COUT | MERGE_COUT_CERR)) == NONE)  
//        d_paIn_childCoutPipe.closeWriteFd();
//    else                                            // at COUT
//    {
//        int fd = d_paIn_childCoutPipe.readOnly();   // read the child's cout
//
//        if (not (d_setMode & OUT_PIPE))
//        {
//            d_fmChildCoutBuf.reset(fd, 200);        // streambuf reading the
//                                                    // child's cout
//            d_iChildCout.rdbuf(&d_fmChildCoutBuf);  // active reading the
//                                                    // child's cout stream
//            d_selector.addReadFd(fd);               // react on incoming info
//        }
//    }
//
//    if (d_mode & CERR)                              // if CERR is used
//    {
//        int fd = d_paIn_childCerrPipe.readOnly();   // read the child's cerr
//        d_fmChildCerrBuf.reset(fd, 200);            // activate the buffer
//        d_iChildCerr.rdbuf(&d_fmChildCerrBuf);      // read the child's cerr
//        d_selector.addReadFd(fd);                   // react on incoming info
//    }
//
//    clear();                                    // clears IOStream's streams
//}
//
//
//
