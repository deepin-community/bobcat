#define XERR
#include "iomapbuf.ih"

ios::pos_type IOmapbuf::seekoff(ios::off_type pos, ios::seekdir where,
                                ios::openmode mode)
{
    pos = Omapbuf::seekoff(pos, where, mode);

//xerr("IOMapBuf " << pos);

    if (pos == -1 or pbase() == 0)  // invalid pos or no buffer
{
//xerr("seekoff returns: " << pos);
        return pos;                 // then simply return pos
}

//xerr("Next: " << (void *)pbase());

    size_t newPos = pos;
    gbump(                          // abspos is outside of the buffer ?
        newPos < offset() or offset() + mapLength() <= newPos ?
            egptr() - gptr()        // then the buffer is exhausted
        :                           // or reset gptr()
            newPos - offset() - (gptr() - eback())
    );

    return pos;    
}

