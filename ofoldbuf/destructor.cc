#include "ofoldbuf.ih"

OFoldBuf::~OFoldBuf()
{
    s2_buffers.erase(findOFoldBuf(this));

    if (d_mode == NON_WS)
        flush();
    else if (d_mode == WS)
    {
        if (d_handleTrailingBlanks)
        {
            if (length() <= d_rightMargin)
                writeWs();
            else
                put('\n');
        }
    }
    out().rdbuf()->pubsync();
}
