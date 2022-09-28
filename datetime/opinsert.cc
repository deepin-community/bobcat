#include "datetime.ih"

// "Wed Jun 30 21:49:08 1993"

namespace FBB
{

std::ostream &operator<<(std::ostream &out, DateTime const &dt)
{
//    dt.assignTM();
    return out << put_time(&dt.d_tm, "%c");
}

}   // FBB
