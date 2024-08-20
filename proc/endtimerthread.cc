#define XERR
#include "proc.ih"

void Proc::endTimerThread()
{
    if (d_timeLimit == 0)
        return;

    d_timerSem.notify();
    d_timerThread.join();
}



