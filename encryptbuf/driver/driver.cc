#include <iostream>
#include <iomanip>
#include <fstream>
#include <bobcat/exception>
#include <bobcat/ohexbuf>
#include "../encryptbuf"

#include <openssl/evp.h>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
        throw Exception(1) << 
                    "1st arg: method, 2nd arg: key, 3rd arg:  (opt): iv, "
                    "stdin: file to encrypt (to stdout)\n"
            "e.g., driver aes-128-cbc somekey < driver.cc > /tmp/enc\n";

    string key(argv[2]);
    string iv;

    if (argc > 3)
        iv = argv[3];

    EncryptBuf encryptbuf(cout, argv[1], key, iv, 50);

    ostream out(&encryptbuf);

    size_t ivLength = encryptbuf.iv().length();
    cerr << "Block length: " << encryptbuf.blockLength() << "\n"
            "Key length: " << encryptbuf.keyLength() << "\n"
            "Max Key length: " << EVP_MAX_KEY_LENGTH << "\n"
            "actual IV length: " << ivLength << "\n"
            "IV =\n";

    OHexBuf ohb{ cerr, ivLength << 1 };
    ostream outHex(&ohb);
    outHex << encryptbuf.iv();
    cerr << '\n' << dec;

    out << cin.rdbuf() << eoi;
}
catch(exception const &err)
{
    cerr << err.what() << endl;
    return 1;
}
