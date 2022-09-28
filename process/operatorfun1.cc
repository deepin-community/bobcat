#include "process.ih"

Process &Process::operator()(IOMode mode, ProcessType type, size_t timeLimit)
{
    return operator()(mode, type, timeLimit, bufSize());
}
