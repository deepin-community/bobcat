#include "isymcryptbase.ih"

bool ISymCryptBase::evpFinal()
{
    checkOutBufSize(blockSize());

    int nOutputChars;
    if (not ((*d_evpFinal)(             // finalize en/decryption
        ctx(),
        uOutBuf(), &nOutputChars
        ))
    )
//    {
//        checkEVPerror();
        throw Exception{} << "EVP_{En,De}cryptFinal failed";
//    }

    setg(outBuf(), outBuf(), outBuf() + nOutputChars);

    return nOutputChars != 0;
}
