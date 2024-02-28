#include <iostream>
#include <fstream>
#include <istream>
#include <string>

#include <bobcat/ifilterbuf>

using namespace std;
using namespace FBB;

class CharFilterStreambuf: public IFilterBuf
{
    istream &d_in;         // stream to read from
    string d_rmChars;      // chars to rm
    string d_buffer;       // locally buffered chars
    size_t const d_maxSize = 100;

    public:
        CharFilterStreambuf(istream &in, string const &rmChars);

    private:
        bool filter(char const **srcBegin,
                    char const **srcEnd) override;
};

CharFilterStreambuf::CharFilterStreambuf(istream &in,
                                         string const &rmChars)
:
    d_in(in),
    d_rmChars(rmChars)
{
    setBuffer();        // required if peek() must return the 1st
}                       // available character right from the start

bool CharFilterStreambuf::filter(char const **srcBegin,
                                 char const **srcEnd)
{
    d_buffer.clear();

    while (d_buffer.size() != d_maxSize)
    {
        char ch;
        if (not d_in.get(ch))
            break;
        if (d_rmChars.find(ch) != string::npos) // found char to rm
            continue;
        d_buffer.push_back(ch);
    }

    if (d_buffer.empty())
        return false;

    *srcBegin = d_buffer.data();
    *srcEnd = d_buffer.data() + d_buffer.size();

    return true;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "arg[1]: file to process, arg[2]: processed file\n";
        return 0;
    }

    ifstream in{ argv[1] };
    CharFilterStreambuf buf1(in, "1234567890");
    istream in1(&buf1);

    CharFilterStreambuf buf2(in1, "AEIOUaeiou");
    istream in2(&buf2);

    ofstream out{ argv[2] };
    out << in2.rdbuf();
}
