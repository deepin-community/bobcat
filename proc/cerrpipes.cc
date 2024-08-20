#include "proc.ih"

void Proc::cerrPipe(size_t idx) const
{
    cerr << "   Pipe " << idx << ": read = " << (*d_pipesPtr)[idx].readFd() <<
                          ", write = " << (*d_pipesPtr)[idx].writeFd() << '\n';
}

void Proc::cerrPipes(char const *lab) const
{
    cerr << "Proc " << d_id << ". " << lab << '\n';

    for (size_t idx = 0, end = d_pipesPtr->size(); idx != end; ++idx)
        cerrPipe(idx);
}
