//#define XERR
#include "config.ih"

void CF_Pimpl::clear()
{
    d_line.clear();                 // clear the vector
    d_CIvect.clear();               // clear iterators to matching lines

    d_rawNumber = 0;                // re-initialize the line-number count
                                    // of the original file
}
