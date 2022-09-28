#include <sys/select.h>
#include <cstring>
#include <iostream>

using namespace std;

bool isEmpty(fd_set const *fdset)
{
    static fd_set empty;     // initialized to 0 -> empty
    return memcmp(fdset, &empty, sizeof(fd_set)) == 0;
}

int main()
{
    fd_set demo;
    
    cout << isEmpty(&demo) << '\n';

    FD_ZERO(&demo);

    cout << isEmpty(&demo) << '\n';

    FD_SET(1, &demo);

    cout << isEmpty(&demo) << '\n';

    FD_CLR(1, &demo);

    cout << isEmpty(&demo) << '\n';

}
