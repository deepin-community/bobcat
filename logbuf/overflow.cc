#include "logbuf.ih"

int LogBuf::overflow(int ch)
{
    if (d_active == OFF)            // ignore the char if we're not active 
        return ch;
                                    // if the ch. is not fnl (forced \n)
    if (ch != 1 and d_active == NOT_ACTIVE) 
    {                                   
        if (ch == '\n')
            d_empty = true;

        return ch;
    }

    switch (ch)
    {
        case 0:             // write newline, without considering d_empty true
            d_empty = false;
            ch = '\n';       // also see logbuf/operatorinsert.cc
        break;

        case 1:             // at fnl (forced new line) (re)activate and
            ch = '\n';       // fallthrough (continue) as \n
        [[fallthrough]];

        case '\n':          // at '\n', set d_empty to true. This generates 
                            // a timestamp at the next insertion
            d_empty = true;
        break;
    }

    return 
        d_stream->write(reinterpret_cast<char const *>(&ch), sizeof(char)) ?
            ch
        :
            EOF;
}
