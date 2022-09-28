#include "digestbuf.ih"

DigestBuf::DigestBuf(char const *type, size_t bufsize)
:
    EoiBuf(bufsize),
    d_ctx(0)
{
    OpenSSL_add_all_digests();
    d_md = EVP_get_digestbyname(type);

    if (!d_md)
    {
        if (type == 0)
            type = "** unspecified digest type **";

        throw Exception{ 1 } << "DigestBuf `" << type << "' not available";
    }

    reset();
}
