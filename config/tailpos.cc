//#define XERR
#include "config.ih"

size_t CF_Line::tailPos() const
{
    size_t pos = next(0);                   // beyond the key

    return pos == string::npos?
                pos
            :
                d_line.find_first_not_of(" \t\r", pos);
}
