#include "ldc.ih"

            // 4       0            // indices in hexNr
            // 1 2 3 4 5            // digits in hexNr
            //
            // converted into buffer:
            //
            // high idx             low idx
            // extra 0-bytes   nexNr's digits
            // 00 00 00 00 00 01 23 45
            //              ^        ^
            //              end      begin
            //
            // Ptr's value contains: 0x12345


void LDC::compress(string const &hexNr)
{
    d_size = hexNr.length();        // prefix an initial 0-byte
                                        // to simulate a div10-result

    d_size = d_size / 2 + (d_size & 1) + SIZE;  // always at least VALUE
                                        // 0-bytes available at the upper end

    prepareBuffers();

    compressDigits(hexNr);          // compress hexNr's digits

    guardBegin();
    setDivPtrs();
}
