#define XERR
#include "proc.ih"

int Proc::finish(bool endChild)
{
    if (not (d_admin & ACTIVE) or not localPipes())
        return -1;

    if (d_mode & CIN)
        d_oBuf.eoi();
                                            // end the child process if
    endTimerThread();                       // d_timeLimit != 0

    if (d_admin & THREAD_OUT)
        d_outThread.join();

    if (d_admin & THREAD_ERR)
      d_errThread.join();

    if (endChild)
        d_child.ret = Fork::endChild();
    else
        waitForChild();

    d_bufSize = d_forkData.bufSize;            // reset saved data members

    d_mode = d_forkData.mode;

    d_procType = d_forkData.type;

    pipeSignal(d_forkData.pipeSignal);

    return exitStatus();
}




