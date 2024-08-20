#include "decryptbuf.ih"

DecryptBuf::DecryptBuf(ostream &outStream, char const *type,
                        string const &key, string const &iv, size_t size)
{
    throw Exception{} << "DecryptBuf was removed from Bobcat at Bobcat 6.0.0."
        "Instead of Decryptbuf the class OSymCryptStreamBuf can be used";
}
