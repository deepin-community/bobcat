#include <unistd.h>

#include <ostream>
#include <string>

#include "../ofdbuf"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
                           // define a streambuf of 20 or argv[1] characters
    OFdBuf buf{ STDOUT_FILENO, argc == 1 ? 20 : stoul(argv[1]) };

    ostream out{ &buf };

    out << "First line, just to start the insertions\n" <<
            argv[0] << endl <<          // using an explicit flush
            argc << "\n"
            "a long line to end this multiple-insertions statement\n";
}
