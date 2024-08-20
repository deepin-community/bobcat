#include <iostream>
#include <fstream>
#include <string>

#include <bobcat/osymcryptstream>

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
    cout << "encryption key ? ";
    cin >> key;
    while (key.size() < 32)
        key += key;
    string iv = " 0123456789ab" "456";

    char cipherName[] =
        "AES-256-GCM"
        //"AES-256-CBC"
    ;

    ifstream in{ argv[2] };
    ofstream out{ argv[3] };

    if (*argv[1] == 'e')
    {
        OSymCryptStream<ENCRYPT> enc{ out, cipherName, key, iv, 100 };
            // comment out the above statement and uncomment the next
            // to use the constructor expecting a string as 1st arg:
//      OSymCryptStream<ENCRYPT> enc{ argv[3], cipherName, key, 
//                                    iv, 100 };

        enc << in.rdbuf() << eoi;
        //in.seekg(0);              // when activated, this won't
        //enc << in.rdbuf();        // be processed due to '<< eoi'
    }
    else
    {
        OSymCryptStream<DECRYPT> decrypt{ out, cipherName, key, 
                                                           iv, 100 };
            // comment out the above statement and uncomment the next
            // to use the constructor expecting a string as 1st arg:
//      OSymCryptStream<DECRYPT> decrypt{ argv[3], cipherName, key, 
//                                        iv, 100 };

        decrypt << in.rdbuf() << eoi;
    }
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}
