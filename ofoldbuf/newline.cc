#include "ofoldbuf.ih"

void OFoldBuf::newline()
{
    //cerr << "NEWLINE\n";

    put('\n');
    d_next = 0;
}
