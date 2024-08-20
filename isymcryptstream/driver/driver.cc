#include <iostream>
#include <fstream>
#include <string>

#include <bobcat/isymcryptstream>
#include <bobcat/isymcryptstreambuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "arg[1]: e - encrypt, d - decrypt,\n"
                "arg[2]: file to process, arg[3]: processed file\n";
        return 0;
    }

    string key = "0123456789abcdef0123456789abcdef";
    string iv = " 0123456789ab" "456";

    char cipherName[] =
        "AES-256-GCM"
        //"AES-256-CBC"
    ;

    ifstream in = Exception::factory<ifstream>(argv[2]);
    ofstream out{ argv[3] };

    ISymCryptStreambuf<ENCRYPT> encbuf{ in, cipherName, key, iv, 100 };

    if (*argv[1] == 'e')
    {
        ISymCryptStream<ENCRYPT> enc{ in, cipherName, key, iv, 100 };
            // comment out the previous line and uncomment the next
            // to use the constructor expecting a string as 1st arg:
//      ISymCryptStream<ENCRYPT> enc{ argv[2], cipherName, key, 
//                                    iv, 100};

        out << enc.rdbuf();
    }
    else
    {
        ISymCryptStream<DECRYPT> decrypt{ in, cipherName, key, iv, 100 };
            // comment out the previous line and uncomment the next
            // to use the constructor expecting a string as 1st arg:
//      ISymCryptStream<DECRYPT> decrypt{ argv[2], cipherName, key, 
//                                        iv, 100 };
        out << decrypt.rdbuf();
    }
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}




