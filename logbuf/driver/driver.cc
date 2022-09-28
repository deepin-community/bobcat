#include <iostream>
#include <iomanip>

#include <bobcat/log>
#include <bobcat/level>

using namespace std;
using namespace FBB;

int main()
{
    LogBuf buffer(cout, FBB::TIMESTAMPS);
    ostream log(&buffer);

    log << "This message is written to cout" << nl <<
           setw(16) << ' ' << "occupying multiple lines\n";

    buffer.setActive(false);

    log << "one line\n";
    log << "more lines ";
    log << fnl;
    log << "another\n";

    buffer.setActive(true);
    log << "and active again\n";
    log << "another log msg\n";
}

