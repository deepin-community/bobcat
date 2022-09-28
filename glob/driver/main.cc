#include "../../stat/stat.ih"

void Stat::init()
{
    d_errno = ::lstat(d_name.c_str(), &d_stat) ? 
                    errno
                :
                    0;
}

#include <iostream>
#include "../glob"

using namespace std;
using namespace FBB;

void files(Glob::Type type, char const *label)
{
    cout << label << ", type: " << type << ":\n";

//    Glob glob{ type, "*" };
    Glob glob{ unordered_set{ type }, "*" };

    cout << "list:\n";
    for (char const *cp: glob )
        cout << cp << '\n';

    cout << "list done\n\n";
}

int main()
{

    cout << hex;

    files(Glob::BLOCK_DEVICE, "BLOCK_DEVICE");
    files(Glob::CHARACTER_DEVICE, "CHARACTER_DEVICE");
    files(Glob::DIRECTORY, "DIRECTORY");
    files(Glob::FIFO, "FIFO");
    files(Glob::REGULAR_FILE, "REGULAR_FILE");
    files(Glob::SOCKET, "SOCKET");
    files(Glob::SYMBOLIC_LINK, "SYMBOLIC_LINK");
}

