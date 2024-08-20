#include "proc.ih"

void Proc::checkErrThread()
{
    if (d_admin & THREAD_ERR)
        d_errThread.join();
    endTimerThread();
}
