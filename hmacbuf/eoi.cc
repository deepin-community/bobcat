#include "hmacbuf.ih"

// override
void HMacBuf::eoi_()
{
    d_digest.resize(EVP_MAX_MD_SIZE);

    if (pptr() > pbase())
       HMAC_Update(d_ctx, ucharPtr(d_digest), pptr() - pbase());
         
    unsigned digestbufLen;
    HMAC_Final(d_ctx, ucharPtr(d_digest), &digestbufLen);

    d_digest.resize(digestbufLen);
    HMAC_CTX_free(d_ctx);
    d_ctx = 0;
}
