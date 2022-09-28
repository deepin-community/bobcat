#include "process.ih"

Process::Process(IOMode mode, ProcessType type, std::string const &command)
:
    Process(mode, type, 0, 200, command)
{}
