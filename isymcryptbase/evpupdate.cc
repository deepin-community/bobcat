#include "isymcryptbase.ih"

bool ISymCryptBase::evpUpdate(size_t inBufRead)
{
    checkOutBufSize(inBufRead);

    int nOutputChars;

    if (not ((*d_evpUpdate)(                // en/decrypt the bytes in d_inBuf
            ctx(),
            uOutBuf(), &nOutputChars,
            reinterpret_cast<unsigned char *>(d_inBuf.get()), inBufRead
        ))
    )
        throw Exception{} << "EVP_{En,De}cryptUpdate failed";

    setg(outBuf(), outBuf(), outBuf() + nOutputChars);

    return nOutputChars != 0;
}
