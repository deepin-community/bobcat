/*
                              driver.cc
*/

#include <iostream>
#include <string>

#include "../stat"
#include <bobcat/datetime>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Usage: driver [-l] object [colon-separated searchpath]\n";
        return 1;
    }

    bool lstat = "-l"s == argv[1];
    if (lstat)
    {
        ++argv;
        --argc;
    }

    Stat st;
    if (argc == 2)
    {
        if (lstat)
            st.set(Stat::LStat, argv[1]);
        else
            st.set(argv[1]);
    }
    else if (argc == 3)
    {
        if (lstat)
            st.set(Stat::LStat, argv[1], argv[2]);
        else
            st.set(argv[1], argv[2]);
    }

    if (!st)
    {
        cout << "Can't stat " << argv[1] << ", errno = " << st.error() << endl;
        return 1;
    }

    cout << st.name() << ": access: " << st.lastAccess() << "\n" <<
            st.name() << ": change: " << st.lastChange() << "\n" <<
            st.name() << ": modif:  " << st.lastModification() << "\n"
            "Mode: " << oct << st.mode() <<  " (" << st.modeStr() << ")\n"
            "Type: " << st.type() << " (" << st.typeStr() << ")\n"
            "Full path:  " << st.path()  << endl;
}
