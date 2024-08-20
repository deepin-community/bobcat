#include <iostream>
#include <bobcat/proc>

using namespace std;
using namespace FBB;

//CODE
int main()
{
    Proc proc("/bin/cat", Proc::CIN | Proc::COUT);
    proc.setTimeLimit(5);

    proc.start();

    while (true)
    {
        cout << "? ";
        string line;
        if (not getline(cin, line))
            return 0;

        proc << line << endl;           // to /bin/cat

        if (not proc.good())
        {
            cout << "child time limit exceeded\n";
            break;
        }
    }

    cout << "/bin/cat time limit of 5 seconds reached: child proc ended\n";
}
//=



