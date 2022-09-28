#include <iostream>
#include <istream>

#include "../randbuf"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "expect: nruns min max seed\n";
        return 1;
    }

    RandBuf rb(stoi(argv[2]), stoi(argv[3]), stoul(argv[4]));

    istream istr(&rb);

    for (unsigned idx = stoul(argv[1]); idx--; )
    {
        int c;
        if (!(istr >> c))
        {
            cout << "extraction failed\n";
            break;
        }    
        cout << "next: " << c << endl;
    }

    int count = 0;
    while (istr.unget())
        count++;

    cout << "number of successful unget()-calls: " << count << endl;
    istr.clear();
    istr >> count;
    cout << "and read: " << count << endl;
}
