#include "process.ih"

void Process::closePipes()
{
    d_oChildInPipe.close();
    d_iChildOutPipe.close();
    d_iChildErrPipe.close();
}
