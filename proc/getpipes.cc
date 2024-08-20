#include "proc.ih"

void Proc::getPipes()       // called by start, when (d_admin & LOCAL_PIPES)
{
    delete d_pipesPtr;

    d_pipesPtr = new vector<Pipe>(3);   // see activator1.cc
    d_read = 0;                         // pipe to read, sending to the child
}
