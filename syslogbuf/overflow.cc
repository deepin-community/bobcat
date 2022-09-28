#include "syslogbuf.ih"

int SyslogBuf::overflow(int ch)
{
    if (ch != EOF)
        buffer() += ch;
    else
        sync();

    return ch;
}
    
