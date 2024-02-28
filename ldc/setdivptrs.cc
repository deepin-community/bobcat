#include "ldc.ih"

void LDC::setDivPtrs()
{
                                    // beyond the last byte of the quotient:
                                    // same length as buffer[0]'s value
    d_divEnd = d_buffer[1] + (d_end - d_buffer[0]);

    d_divBegin = d_divEnd;          // so far no div10 value: new bytes are
                                    // stored before d_divBegin, first the
                                    // MSB.
}
