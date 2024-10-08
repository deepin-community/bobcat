#include <iostream>
#include <istream>

#include <bobcat/iquotedprintablebuf>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Usage: " << argv[0] << " [edb] < infile > outfile\n"
                    "to quoted printable -e-ncode, -d-ecode or -b-oth\n";
        return 0;
    }

    switch (argv[1][0])
    {
        case 'e':
        {
            IQuotedPrintableBuf<ENCODE> encode(cin);
            istream ein(&encode);
            cout << ein.rdbuf();
        }
        break;

        case 'd':
        {
            IQuotedPrintableBuf<DECODE> decode(cin);
            istream din(&decode);
            cout << din.rdbuf();
        }
        break;

        case 'b':
        {
            IQuotedPrintableBuf<ENCODE> encode(cin);
            istream ein(&encode);

            IQuotedPrintableBuf<DECODE> decode(ein);
            istream din(&decode);
            cout << din.rdbuf();
        }
        break;
    }
}
