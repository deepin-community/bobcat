#include "process.ih"

int Process::eoi()
{
    eoi_();                     // *this << FBB::eoi;
    return exitStatus();
}

