#include <unistd.h>

#include <istream>
#include <iostream>

#include <bobcat/ifdbuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
                           // define a streambuf of 20 or argv[1] characters
    IFdBuf buf{ STDIN_FILENO, argc == 1 ? 20 : stoul(argv[1]) };

    istream in{ &buf };

    cout << in.rdbuf();
}
