#include <bobcat/selector>
#include <bobcat/exception>

#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    Selector selector;

    selector.setAlarm(5);               // every 5 secs: alarm fires
    selector.addReadFd(STDIN_FILENO);   // look also at cin

    while (true)
    {
        if (!selector.wait())           // 0: alarm fires
            cout << "Are you still there?" << endl;
        else
        {
            string s;
            if (!getline(cin, s) || !s.length())
                return 0;
            cout << "Thank you for: " << s << endl;
        }
    }
}
catch (exception const &e)
{
    cout << e.what() << endl;
}
