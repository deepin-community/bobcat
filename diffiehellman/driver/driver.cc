
#include <fstream>
#include <iostream>

#include <bobcat/exception>

#include "../diffiehellman"

using namespace FBB;
using namespace std;

int main(int argc, char **argv)
try
{

    if (argc == 1)
    {
        cout << "1: create prime and generator, write to 'params'\n"
                "2: create secret and public parts, arg 2: 0 or 1,\n"
                "   write secret and public parts to <arg 2>.sec and "
                                                     "<arg 2>.pub\n"
                "3: create common key arg 2: 0 or 1,\n"
                "   0: write common0 using 0.pub, 0.sec and 1.pub\n"
                "   1: write common1 using 1.pub, 1.sec and 0.pub\n"
                ;
        return 0;
    }


    switch (*argv[1])                       // using generator == 5
    {
        case '1':
        {
            ofstream out = Exception::factory<ofstream>("params");
            out << hex << DiffieHellman::prime(1024, true, true) << '\n';
        }
        break;

        case '2':
        {
            char *nr = argv[2];

            if (nr == 0 || "01"s.find(*nr) == string::npos)
                throw Exception{} << "mode '2' needs 0 or 1 as 2nd argument";

            ifstream in = Exception::factory<ifstream>("params");
            BigInt prime;
            in >> hex >> prime;

            DiffieHellman dh{ prime };
            dh.save(nr);
        }
        break;

        case '3':
        {
            char *nr = argv[2];

            if (nr == 0 || "01"s.find(*nr) == string::npos)
                throw Exception{} << "mode '3' needs 0 or 1 as 2nd argument";

            DiffieHellman dh{ nr + ".pub"s, nr + ".sec"s };
            cout << "common key computed by " << nr << ":\n" <<
                hex << dh.key((nr[0] == '0' ? '1' : '0') + ".pub"s) << '\n';
        }
        break;

        default:
        throw Exception{} << "undefined action `" << *argv[1] <<'\'';
    }
}
catch (std::exception const &exc)
{
    std::cout << exc.what() << '\n';
}
