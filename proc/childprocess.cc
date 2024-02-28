#include "proc.ih"

// overrides
void Proc::childProcess()
{
    ExecContext ec;
    if (d_procType != USE_SHELL)
        ec = analyzeCmd();          // No system, so run execl() or execle()
    else
    {
        ec.argv = new char const *[4];
        ec.argv[d_writeOut] = "/bin/sh";
        ec.argv[1] = "-c";
        ec.argv[2] = d_cmd.c_str();
        ec.argv[3] = 0;
    }

    (*(d_procType == USE_PATH ? execvp : execv))
        (ec.argv[0], const_cast<char * const *>(ec.argv));

    throw Exception{} << "Proc: cannot execv[p] " << d_cmd;


}


//    char buffer[100];
//    int nRead;
//
////    int fd = (*d_pipesPtr)[d_read].readFd();
//
//    while (true)
//    {
//        cin.read(buffer, 100);
//        nRead = cin.gcount();
//
//        //nRead = read(fd, buffer, d_bufSize);
//
//        if (nRead == 0)
//            break;
//
//        cout.write(buffer, nRead);
//    }
//
//    cerr << "END\n";
//
//    throw 0;
