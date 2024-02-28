#include "ldc.ih"

#include <iostream>

LDC::LDC(LDC &&tmp)
{
    swap(tmp);

    tmp.d_buffer[0] = 0;
    tmp.d_buffer[1] = 0;
}
