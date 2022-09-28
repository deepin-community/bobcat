#include "datetime.ih"

namespace FBB
{

std::istream &operator>>(std::istream &in, FBB::DateTime &dt)
{
    FBB::DateTime tmp{ in, dt.d_type };
    fswap(dt, tmp);                    // swap the DateTime objects

    return in;
}

}   // FBB
