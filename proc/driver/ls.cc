#include <iostream>

#include <bobcat/proc>

using namespace std;
using namespace FBB;

//CODE
int main()
{
    Proc proc("/bin/ls -Fla", Proc::COUT);

    proc.start();
}
//=
