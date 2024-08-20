#include "hmacbuf.ih"

HMacBuf::HMacBuf(std::string const &key, char const *cipher,
                 char const *digest, size_t bufSize)
:
    EoiBuf(bufSize),
    d_key(key),
    d_cipher(cipher),
    d_digest(digest)
{
    if (key.empty())
        throw Exception{} << "HMacBuf non-default constructors require "
                             "non-empty keys";
    reset();
}
