#include "process.ih"

int Process::stop()
{
    if (!d_active)
        return -1;

    d_oChildIn.flush();

    d_oChildInbuf.reset(-1);
    d_iChildOutbuf.reset(-1);
    d_iChildErrbuf.reset(-1);

    closePipes();

    discontinue(d_child);

    d_limit.join();

    d_active = false;

    return d_child.ret;
}
