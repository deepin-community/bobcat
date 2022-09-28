#include "readlinebuf.ih"

size_t ReadLineBuf::nextLine(char *buf)      // malloc allocated buf
{
    if (buf == 0)
        d_buffer.clear();
    else
        d_buffer = buf;

    if (d_history && not d_buffer.empty())  // add line (+ maybe a timestamp) 
    {                                       // to the history 
        add_history(buf);
        if (d_timestamp)
            add_history_time((*d_timestamp)().c_str());
    }

    free(buf);                              // done with the malloc-ed buf.

    d_buffer += '\n';

    return d_buffer.length();    
}

