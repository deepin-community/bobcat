
#include "omapbuf.ih"

//override
int Omapbuf::sync()
{
    osync();
    return 0;
}
