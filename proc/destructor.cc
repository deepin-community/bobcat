#include "proc.ih"

// overrides
Proc::~Proc()
{
    stop();

    if (localPipes())           // local pipes were closed by finish
        delete d_pipesPtr;
}

