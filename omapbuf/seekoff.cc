#define XERR
#include "omapbuf.ih"

// called by seekg()/tellg() (tellg using 0, ios::cur)

ios::pos_type Omapbuf::seekoff(ios::off_type pos, ios::seekdir where,
                               ios::openmode mode)
{
//xerr("pos = " << pos << ", where = " << where);

    pos = setAbsPos(pos, where) < 0 ? -1 : absPos();

//xerr("OmapBuf absPos set to " << pos);

    if (pos == -1 or pbase() == 0)  // invalid pos or no buffer
        return pos;                 // then simply return pos

                                    
    size_t newPos = pos;
    pbump(                          // abspos is outside of the buffer ?
        newPos < offset() or offset() + mapLength() <= newPos ?
            epptr() - pptr()        // then the buffer is exhausted
        :                           // or reset gptr()
            newPos - offset() - (pptr() - pbase())
    );

    return pos;
}



