#include <iostream>
#include <ostream>
#include <bobcat/exception>
#include "../digestbuf"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    DigestBuf digestbuf(argv[1]);
    ostream out(&digestbuf);

    string hw("hello world\n");

    out << hw << eoi;
    cout << ">" << digestbuf << "<" << endl;

    digestbuf.reset();
    out.write(hw.c_str(), hw.length()) << eoi;
    cout << ">" << digestbuf << "<" << endl;
}
catch(exception const &err)
{
    cout << err.what() << endl;
    return 1;
}
