#define XERR
#include "mapbase.ih"

ios::off_type MapBase::setAbsPos(ios::off_type pos, ios::seekdir where)
{
    d_absolute = true;

    switch (where)
    {
        case ios::beg:
            d_absPos = pos;
        break;
                            // if there's no buffer yet then d_offset == 0,
                            // pptr() == 0, and eback() == 0. In that case use
                            // d_absPos as current position.
            // but what happens if there is a buffer and d_absPos is set?
            // then the current position isn't important anymore and so once
            // d_absPos is explicitly set d_absPos should be used as
            // reference. 
        case ios::cur:
            if (d_absolute)
                d_absPos += pos;
            else
            {
                d_absPos = pos + d_offset + (gptr() - eback());
                d_absolute = false;
            }
        break;

        case ios::end:
            d_absPos = pos + d_fileSize;
        break;
    }

//xerr("absPos: " << d_absPos);

    return d_absPos;             // may be < 0, handled by seek{pos,off}
}

