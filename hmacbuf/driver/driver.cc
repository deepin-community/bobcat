#include <fstream>
#include <iostream>
#include <bobcat/hmacbuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
                        // using the default (sha256) digest algorithm
    if (argc == 1)
        throw Exception{} <<
                "Usage: arg1: 16-byte key, arg2: file to process,\n"
                "       arg3 (opt) buf size (default 1024)";

    HMacBuf hmacbuf{ argv[1], "aes-128-cbc", "sha256",
                     argc == 3 ? 1024 : stoul(argv[3]) };

    HMacBuf empty;                              // Demo: an empty HMacBuf
    empty = HMacBuf{ argv[1], "sha256", 100 };  // Demo: move assignmeent

    ostream out(&hmacbuf);              // the ostream receiving the
                                        // input to compute the hmac of

    ifstream in{ argv[2] };             // the file to process

    out << in.rdbuf() << eoi;           // compute the hmac
                                        // and show the hmac value
    cout << "  computed hmac value: >" << hmacbuf << "<\n";

    in.seekg(0);                        // to illustrate 'reset': do it
    hmacbuf.reset();                    // again

    out << in.rdbuf();
    eoi(out);                           // calling eoi as a function
    cout << "recomputed hmac value: >" << hmacbuf << "<\n";
}
catch(exception const &err)
{
    cout << err.what() << endl;
    return errno;
}
