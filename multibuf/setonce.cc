#include "multibuf.ih"

void MultiBuf::setOnce() 
{
    for (auto &os: d_os)
        stream::setOnce(os);
}
