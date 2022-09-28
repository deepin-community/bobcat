#include "logbuf.ih"

void LogBuf::checkTimestamp()
{
    if (d_timestamps == NOTIMESTAMPS)  // no timestamps requested
        return;

    if (d_empty)        // write one if there's nothing on the line
    {
        insertTimestamp();
        d_empty = false;
    }
}
