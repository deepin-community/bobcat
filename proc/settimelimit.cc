//#define XERR
#include "proc.ih"

size_t Proc::setTimeLimit(size_t timeLimit)
{
    size_t ret = d_timeLimit;
    d_timeLimit = timeLimit;
    pipeSignal(timeLimit == 0);

    return ret;
}
