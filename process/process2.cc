#include "process.ih"

Process::Process(IOMode mode, std::string const &command)
:
    Process(mode, NO_PATH, 0, 200, command)
{}
