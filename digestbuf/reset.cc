#include "digestbuf.ih"

void DigestBuf::reset()
{
    if (d_ctx)
        return;

    d_ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(d_ctx, d_md, 0);
    d_digest.resize(EVP_MAX_MD_SIZE);

    setp();
}
