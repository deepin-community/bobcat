#define XERR
#include "proc.ih"

void Proc::beginTimerThread()
{
    if (d_timeLimit == 0)
        return;

    d_timerSem.set(0);                      // semaphore: end thread waits
                                            // and start the thread
    d_timerThread = thread{ &Proc::timerThread, this };
}
