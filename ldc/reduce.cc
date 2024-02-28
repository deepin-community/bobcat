#include "ldc.ih"

void LDC::reduce()
{
    while (true)
    {                                       // store value / 10 at d_divEnd
        installDiv(*d_begin.valuePtr / d_radix);

        *d_begin.valuePtr %= d_radix;     // compute the radix value

        if (d_begin.ptr == d_lsb)           // all digits were processed
            break;
                                            // not all digits were processed
                                            // the next value ends at (beyond)
                                            // the byte holding the remainder
        d_end = d_begin.ptr + 1;            // (% 10) of the current value

                                            // ensure that d_begin.ptr points
        guardBegin();                       // at or beyond the value's LSB
    }
                                            // remainder: always < d_modulo:
                                            // add the remainder as the next
    d_converted += d_digits[*d_begin.ptr];  // digit to 'd_converted'
}
