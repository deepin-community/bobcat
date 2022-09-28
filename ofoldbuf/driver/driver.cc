#include <iostream>

//#include "../ofoldbuf"
// #include "../../ofoldstream/ofoldstream"

#include <bobcat/ofoldstream>

using namespace std;
using namespace FBB;

int main()
{
    OFoldBuf fb(cout, 4, 40);

//    OFoldBuf fb("fsb.out", 4, 40);
    ostream out(&fb);

//    OFoldStream out("foldstream.nam2", 4, 40, OFoldStream::TABS);

//    int c;
//    int linenr = 0;
//    while ((c = cin.get()) != EOF)
//    {
//        if (c == '\n')
//        {
//            if (++linenr == 5)
//                out << indent(+4);
//        }
//        out << static_cast<char>(c);
//    }

//    out << mlm(-3);

    string line;
    while (getline(cin, line))
        out << line << '\n';
}

