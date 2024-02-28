#include <iostream>
#include <streambuf>
#include <fstream>

// This demo is IUO: it illustrates that when overflow returns EOF the ostream
// no longer processes incoming characters

using namespace std;

struct SB: public streambuf
{
    size_t count = 0;

    SB()
    {
        setp(0, 0);
    }

    int overflow(int ch)
    {
        if (count == 10)
            return EOF;

        cerr.put(ch);

        ++count;
        return ch;
    }
};

int main()
{
    SB sb;
    ostream out{ &sb };

    out << "this is a long text, more than 10 chars" << endl;
    cerr << "done\n";

}
