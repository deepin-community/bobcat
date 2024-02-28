//#define XERR
#include "proc.ih"

    // see also activator1.cc

void Proc::pipes(vector<Pipe> *pipes, size_t nPipes)
{
    d_pipesPtr = pipes;
    d_admin &= ~LOCAL_PIPES;
    d_read = nPipes - 3;
}


