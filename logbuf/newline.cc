#include "logbuf.ih"

size_t LogBuf::newLine(char const *buffer, size_t begin, size_t n) const
{
    return find_if(buffer + begin, buffer + n, 
                [](char c)
                {
                    return c == '\n' || c == 0 || c == 1;
                }
            ) - buffer;
}
