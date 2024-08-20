#include "isymcryptbase.ih"

int ISymCryptBase::underflow()
{
    d_inStream.read(d_inBuf.get(), d_inBufSize);    // read d_inStream
    size_t nRead = d_inStream.gcount();             // # chars read

    if (nRead == 0)
    {
        if (evpUpdate(0))
            return static_cast<unsigned char>(*gptr());

        if (evpFinal())
            return static_cast<unsigned char>(*gptr());

        return EOF;
    }

    //setg(d_inBuf.get(), d_inBuf.get(), d_inBuf.get() + nRead);
    evpUpdate(nRead);

    return static_cast<unsigned char>(*gptr());
}
