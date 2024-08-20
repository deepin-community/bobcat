#include "hmacbuf.ih"

HMacBuf::HMacBuf(std::string const &key, char const *digest, size_t bufSize)
:
    HMacBuf(key, "aes-128-cbc", digest, bufSize)
{}
