#include "npipe.ih"

void NPipe::reset()
{
    close();
    setDefault();
}

