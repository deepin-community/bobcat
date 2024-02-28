#include "proc.ih"

namespace FBB
{

Proc::Activator operator|(Proc::Activator &&lhs, Proc &rhs)
{
    lhs.add(rhs);
    return move(lhs);
}

} // FBB
