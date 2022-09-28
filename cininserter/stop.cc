#include "cininserter.ih"

int CinInserter::stop()
{
    if (d_stopped)
        return ret();

    flush();
    eoi();

    return setRet(waitForChild());
}
