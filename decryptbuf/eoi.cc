#include "decryptbuf.ih"

void DecryptBuf::eoi_()     // overrides
{
    flushBuffer();

    int restLen;
    if (not EVP_DecryptFinal_ex(d_ctx, ucharPtr(d_decrypted), &restLen))
        throw Exception{ 1 } << "DecryptBuf: padding error";

    d_outStream.write(&d_decrypted[0], restLen);

    d_eoi = true;
}
