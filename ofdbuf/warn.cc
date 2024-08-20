#define XERR
#include "ofdbuf.ih"

void OFdBuf::warn(bool on)
{
    unsigned value = d_mode;

    if (on)
        value |= WARN;
    else
        value &= ~WARN;

    d_mode = static_cast<Mode>(value);
}
