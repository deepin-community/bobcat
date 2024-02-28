#include "osymcryptbase.ih"

void OSymCryptBase::evpUpdate()
{
    size_t inBufRead = pptr() - pbase();    // # read chars

    checkOutBufSize(inBufRead);

    int nOutputChars;

    if (not ((*d_evpUpdate)(                // en/decrypt the bytes in d_inBuf
            ctx(),
            uOutBuf(), &nOutputChars,
            ucharPtr(), inBufRead
        ))
    )
        throw Exception{} << "EVP_{En,De}cryptUpdate failed";

    d_outStream.write(outBuf(), nOutputChars);      // write the processed
                                                    // chars to d_outSteam

    setp();
}
