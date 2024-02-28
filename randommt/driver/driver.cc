#include <iostream>

#include <bobcat/randommt>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "arg[1]: minimum value, arg[2]: maximum value,\n"
                "arg[3]: (optional) seed (or time(0))\n";
        return 0;
    }

    // specify, e.g., RandomMt<double> to generate random double values
    RandomMT<> rmt( stoull(argv[1]), stoull(argv[2]),
                  argc >= 4 ? stoull(argv[3]) : time(0) );

    while (true)
    {
        cout << rmt() << "\n"
                "Enter: next";
        cin.ignore(1000, '\n');
    }

}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}
