#include "hmacbuf.ih"

HMacBuf::HMacBuf(std::string const &key, char const *type, size_t bufsize)
:
    EoiBuf(bufsize),
    d_key(key)
{
    OpenSSL_add_all_digests();
    d_md = EVP_get_digestbyname(type);

    if (!d_md)
    {
        if (type == 0)
            type = "** unspecified hmac-digest type **";

        throw Exception{ 1 } << "HMacBuf `" << type << "' not available";
    }

    reset();
}

