//#define XERR
#include "ecdh.ih"

// static
BigInt ECDH::privateKey(string const &initSecFname, string password)
{
    auto in = Exception::factory<ifstream>(initSecFname);

    string privKey;

    string type;
    getline(in, type);              // hex or encrypted?
    if (type == "encrypted")
    {
        checkPassword(password);
        ostringstream out;
        OSymCryptStream<DECRYPT>{ out, s_cipherName, password, s_digits } <<
                                                        in.rdbuf() << eoi;
        privKey = out.str();
    }
    else if (type == "hex")
        getline(in, privKey);
    else
        throw Exception{} << initSecFname << ": corrupted";

    return BigInt::fromText(privKey, ios::hex);
}
