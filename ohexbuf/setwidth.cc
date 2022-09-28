#include "ohexbuf.ih"

void OHexBuf::setWidth(size_t width)
{
    d_width = width;

    d_widthHandler = 
            d_width == 0 ? 
                    &OHexBuf::noWidth 
                : 
                    &OHexBuf::widthHandler;
}
