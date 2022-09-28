#include <iostream>
#include <fstream>
#include <bobcat/exception>
#include <bobcat/ohexbuf>

#include <openssl/evp.h>
#include <openssl/err.h>

#include "../decryptbuf"
#include "../../encryptbuf/encryptbuf"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
        throw Exception(1) << 
                    "1st arg: method, 2nd arg: key, 3rd arg: iv, "
                    "4th arg: file to decrypt (to stdout)";

    // e.g., driver aes-128-cbc somekey iv-from-encryptbuf-driver 
    // /tmp/enc > /tmp/driver.dec

    cerr << "Key: `" << argv[2] << "'\n"
            "IV:  `" << argv[3] << "'\n";

    DecryptBuf decryptbuf(cout, argv[1], argv[2], argv[3]);

    ostream out(&decryptbuf);
    ifstream in(argv[4]);

    if (not in)
        throw Exception{} << "can't read `" << argv[4] << '\n';
    
    out << in.rdbuf() << eoi;
}
catch(exception const &err)
{
    cout << err.what() << endl;
    return 1;
}





