#include "process.ih"

int Process::waitForChild()
{
    int ret = Fork::waitForChild();
    closePipes();
    return ret;
}
