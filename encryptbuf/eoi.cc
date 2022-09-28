#include "encryptbuf.ih"

void EncryptBuf::eoi_()         // overrides Eoi::eoi_()
{
    flushBuffer();

    int restLen;
    if (not EVP_EncryptFinal_ex(d_ctx, ucharPtr(d_encrypted), &restLen))
        throw Exception{ 1 } << "Encrypt finalization failed";

    d_outStream.write(&d_encrypted[0], restLen);

    d_eoi = true;
}
