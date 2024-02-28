#include "npipe.ih"

void NPipe::reset(int const *fds)
{
    close();
    NPipe tmp{ fds };
    swap(tmp);
}
