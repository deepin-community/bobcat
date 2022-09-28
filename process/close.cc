#include "process.ih"

void Process::close()
{
    d_oChildIn.flush();

    d_oChildInPipe.close();

    if (d_oChildIn.rdbuf() != 0)
        close(d_oChildInbuf.fd());

    d_oChildIn.rdbuf(0);     
}





