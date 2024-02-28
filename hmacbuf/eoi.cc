#include "hmacbuf.ih"

// int EVP_MAC_final(EVP_MAC_CTX *ctx,
//                   unsigned char *out, size_t *outl, size_t outsize);
// EVP_MAC_final() does the final computation and stores the result in the
// memory pointed at by out of size outsize, and sets the number of bytes
// written in *outl at.  If out is NULL or outsize is too small, then no
// computation is made.
// To figure out what the output length will be and allocate space for it
// dynamically, simply call with out being NULL and outl pointing at a valid
// location, then allocate space and make a second call with out pointing at
// the allocated space.

// override
void HMacBuf::eoi_()
{
    if (d_ctx == 0)
        return;

    call(EVP_MAC_update(d_ctx, ucharPtr(),  pptr() - pbase()), "update");

    size_t len;
    EVP_MAC_final(d_ctx, 0, &len, 0);           // determine the req. length
    d_digest.resize(len);
    call(EVP_MAC_final(d_ctx, ucharPtr(d_digest), &len, len), "final");

    EVP_MAC_CTX_free(d_ctx);
    d_ctx = 0;
}

