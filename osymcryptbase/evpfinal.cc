#include "osymcryptbase.ih"

void OSymCryptBase::evpFinal()
{
    int outBufSize;
    checkOutBufSize(blockSize());

    if (not ((*d_evpFinal)(             // finalize en/decryption
        ctx(),
        uOutBuf(), &outBufSize
        ))
    )
        throw Exception{} << "EVP_{En,De}cryptFinal failed";

    d_outStream.write(outBuf(), outBufSize);
}
