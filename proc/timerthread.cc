#include "proc.ih"

void Proc::timerThread()
{
                                    // wait until the semaphore's notification
                                    // or the end of the waiting time
    d_timerSem.wait_for(chrono::seconds{ d_timeLimit });

    endChild();                     // Fork::endChild ends the child process
}




