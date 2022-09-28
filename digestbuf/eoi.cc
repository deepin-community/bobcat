#include "digestbuf.ih"

#include <iostream>

void DigestBuf::eoi_()
{
    //cerr << __FILE__"\n";

    if (d_ctx == 0)
        return;

    if (pptr() > pbase())
       EVP_DigestUpdate(d_ctx, ucharPtr(), pptr() - pbase());

    unsigned int digestbufLen;
         
    EVP_DigestFinal_ex(d_ctx, ucharPtr(d_digest), &digestbufLen);
    d_digest.resize(digestbufLen);

    EVP_MD_CTX_free(d_ctx);
    d_ctx = 0;
}
