#include "logbuf.ih"

streamsize LogBuf::xsputn(char const *buffer, streamsize n) 
{
    if (d_active != ACTIVE)
        return n;

    streamsize begin = 0;
    while (true)
    {
                                            // find the 1st newline pos.
        streamsize end = newLine(buffer, begin, n);    

        if (begin < end)                    // only a timestamp if there's
        {                                   // something to show.
            checkTimestamp();           
            d_stream->write(buffer + begin, end - begin);
        }

        if (end == n)                       // nothing more to do
            break;        

        overflow(buffer[end]);              // handle \n, nl, fnl 
        begin = end + 1;                    // continue beyond end
    }

    return n;
}
