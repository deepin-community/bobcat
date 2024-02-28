#include "cryptbuf.ih"

namespace
{
    bool called = false;
}

CryptBuf::CryptBuf(char const *type, size_t bufSize)
:
    EoiBuf(bufSize)
{
    deprecated__(called, "CryptBuf");

    if (type == 0)
        throw Exception{} << "CryptBuf: invalid type";

    d_md = EVP_CIPHER_fetch(0, type, 0);

    if (d_md == 0)
        throw Exception{} << "EVP_CIPHER_fetch " << type << " failed";
}
