#include "encryptbuf.ih"

EncryptBuf::EncryptBuf(ostream &outStream, char const *type,
                       string key, string const &iv, size_t size)
{
    throw Exception{} << "EncryptBuf was removed from Bobcat at Bobcat 6.0.0."
        "Instead of Encryptbuf the class OSymCryptStreamBuf can be used";
}
