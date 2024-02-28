//#include "process.ih"
//
//void Process::v_childRedirections()
//{
//    if (d_mode & CIN)                               // CHILD PROCESS: reads
//        d_childIn_paWritePipe.readFrom(STDIN_FILENO);   // cin from the pipe
//
//    if (d_mode & MERGE_COUT_CERR)                   //  cout/cerr to 1 pipe
//    {
//        int fd[] = { STDOUT_FILENO, STDERR_FILENO };
//        d_paIn_childCoutPipe.writtenBy(fd, 2);
//    }
//    else
//    {
//        if (d_mode & COUT)                      //  cout writes to a pipe
//            d_paIn_childCoutPipe.writtenBy(STDOUT_FILENO);
//
//        if (d_mode & CERR)                      //  cerr: to another pipe
//            d_paIn_childCerrPipe.writtenBy(STDERR_FILENO);
//
//        if (d_mode & (IGNORE_COUT | IGNORE_CERR))  // ignores cout/cerr
//        {
//            int fd = ::open("/dev/null", O_WRONLY);
//
//            if (fd == -1)
//                throw Exception{} << "Process " << d_command <<
//                                                    ": can't open /dev/null";
//
//            Redirector redirector{ fd };
//
//            if (d_mode & IGNORE_COUT)               //  ignores COUT
//                redirector.swallow(Redirector::STDOUT);
//
//            if (d_mode & IGNORE_CERR)               //  ignores CERR
//                redirector.swallow(Redirector::STDERR);
//        }
//    }
//}
//
