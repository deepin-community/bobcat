#include <iostream>
#include <ostream>
#include "../ohexbuf"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    OHexBuf ohexbuf(cout, 20, " ");
    ostream out(&ohexbuf);

    string hw("hello world\n");
    out << hw << eoi;
    cout << '\n';

    out << hw;
    cout << '\n';
}
catch(exception const &err)
{
    cout << err.what() << endl;
    return 1;
}

