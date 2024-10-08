#include "base64bufbase.ih"

#include <iostream>

bool Base64BufBase::filter(char const **srcBegin, char const **srcEnd)
{
    if (d_allDone)
        return false;

    d_buffer.clear();
    d_allDone = (this->*d_action)() == false;

    *srcBegin = d_buffer.data();
    *srcEnd = *srcBegin + d_buffer.size();

    return d_buffer.size();
}
