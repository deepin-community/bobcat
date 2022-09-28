#include "cryptbuf.ih"

CryptBuf::CryptBuf(char const *type, size_t bufSize)
:
    EoiBuf(bufSize)
{
    OpenSSL_add_all_ciphers();

    d_md = EVP_get_cipherbyname(type);

    if (!d_md)
    {
        if (type == 0)
            type = "** unspecified cipher type **";

        throw Exception{ 1 } << "CryptBuf `" << type << "' not available";
    }
   
}
