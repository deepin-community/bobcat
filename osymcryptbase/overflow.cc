#include "osymcryptbase.ih"

int OSymCryptBase::overflow(int ch)
{
    if (d_eoi)
        return EOF;

    evpUpdate();                        // process the so far received chars
                                        // prepare EoiBuf for the next input

    if (ch != EOF)                      // write a character?
    {
        *pptr() = static_cast<char>(ch); // put it into the buffer
        pbump(1);                       // advance the buffer's pointer
    }

    return ch;
}
