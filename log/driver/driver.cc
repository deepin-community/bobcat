#include <iostream>
#include <iomanip>

#include <bobcat/log>
#include <bobcat/level>

using namespace std;
using namespace FBB;

int main()
{
//    Log &log = Log::initialize("&1"); // uses the static Log object
    Log log;                        // explicitly defining a Log object
    log.open("/tmp/out");           // or at once: Log log{ "/tmp/out" }

    log << "This message is written to cout" << nl <<
           setw(16) << ' ' << "occupying multiple lines\n";

    log.off();
    log << "This message is not shown\n";
    log << "This message is not shown\n";
    log << fnl;
    log << "This message is not shown\n";

    log.on(2);
    log << "This message is shown\n";

    log << level(0) << "not shown" << level(2) << "shown at level 2\n";
    log << level(3) << "at level(3)" << level(1) << "not shown" << fnl;

    log << "separate new line\n";

    log << level(2) << "in business again\n";
    log << "final line\n";
}


