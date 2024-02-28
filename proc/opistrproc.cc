#include "proc.ih"

namespace FBB
{

Proc::Activator operator|(istream &in, Proc &proc)
{
    proc.d_in = &in;
    proc.d_mode |= Proc::CIN;               // see the proc header file
                                            // use the default ERR stream
//    proc.d_mode & ~(Proc::CERR | Proc::IGNORE_CERR);
    return { proc };
}

} // FBB
