#include <iostream>

#include "../../processenums/processenums"
#include "../process"

using namespace std;
using namespace FBB;

int main()
{
    // Nota bene: by default IOMode equals Process::ALL

    Process p1(Process::CIN, "/bin/cat"); 
    Process p2(Process::NONE, "/bin/cat");
    Process p3(Process::NONE, "/bin/cat");

    (p1 | p2 | p3).start();

    p3 << cin.rdbuf() << eoi;
}
