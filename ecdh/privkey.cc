//#define XERR
#include "ecdh.ih"

void ECDH::privKey(string const &privKeyFname, string passwd) const
{
    checkPassword(passwd);

    if (passwd.size() < MIN_PWD_LENGTH)
        throw Exception{} << "privKey: passwd length must be >= 5 chars";

    while (passwd.size() < 32)          // AES-256-GCM requires pwd len >= 32
        passwd += passwd;

                                        // prepare the file to contain the
                                        // encrypted key    
    auto out = Exception::factory<ofstream>(privKeyFname);
    out << "encrypted\n";
                                        // using s_digits as IV
    OSymCryptStream<ENCRYPT>{ out, s_cipherName, passwd, s_digits } << 
                                                                d_privKey;
}
