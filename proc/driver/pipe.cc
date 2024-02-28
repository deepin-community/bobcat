#include <iostream>
#include <bobcat/proc>

using namespace std;
using namespace FBB;

//CODE
int main()
{
    Proc proc1{ "/bin/cat" };
    Proc proc2{ "/bin/cat" };

    cin | proc1 | proc2;            // By default piping to cout. To do that
                                    // explicitly use '... | proc2 | cout'
}
//=
