#include "process.ih"

Process::Process(IOMode mode, ProcessType processType, size_t timeLimit, 
                 string const &command)
:
    Process(mode, processType, timeLimit, 200, command)
{}
