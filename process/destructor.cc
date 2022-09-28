#include "process.ih"

Process::~Process()
{
    stop();

    Signal::instance().remove(SIGCHLD, *this);  
}

