#include "logbuf.ih"

LogBuf::LogBuf(ostream &stream, TimeStamps timestamps,
                    bool active, char const *delim)
:
    d_stream(&stream),
    d_active(active ? ACTIVE : NOT_ACTIVE),
    d_empty(true)
{
    settimestamp(timestamps, delim);
    setp(0, 0);     // we're not using buffering, so we see every single
                    // character. overflow() may therefore act like a filter,
                    // which decides what to do depending on the booleans.
                    // see overflow() for details.
}
