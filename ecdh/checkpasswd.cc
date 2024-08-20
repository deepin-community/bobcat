//#define XERR
#include "ecdh.ih"

// static
void ECDH::checkPassword(string &passwd)
{
    if (passwd.size() < MIN_PWD_LENGTH)
        throw Exception{} << "private key passwordd length must be >= " <<
                             MIN_PWD_LENGTH << " chars";

    while (passwd.size() < 32)      // AES-256-GCM requires pwd len >= 32
        passwd += passwd;
}
