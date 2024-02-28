#include <iostream>
#include <bobcat/irandstream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    if (argc == 1)
        cout << "\n"
                "Showing one random value between 1 and 1000 (inclusive).\n"
                "If you want more values specify the requested number of\n"
                "values as the program's first argument\n"
                "On repeated calls the same numbers are generated\n\n";

    IRandStream in(1000);

    for (size_t count = argc == 1? 1 : stoul(argv[1]); count--; )
    {
        size_t random;
        in >> random;
        cout << random << endl;
    }
}
