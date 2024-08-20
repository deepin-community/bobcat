#include "digestbuf.ih"

DigestBuf::DigestBuf(char const *digestName, size_t bufsize)
:
    EoiBuf(bufsize),
    d_ctx(0)
{
    OpenSSL_add_all_digests();
    d_md = EVP_get_digestbyname(digestName);

    if (!d_md)
    {
        if (digestName == 0)
            digestName = "** unspecified digest digestName **";

        throw Exception{} << "DigestBuf `" << digestName << "' not available";
    }

    reset();
}
