#include "proc.ih"

namespace FBB
{

void operator|(Proc::Activator &&act, string const &fname)
{
    Proc &proc = *act.d_procPtr.back();

    proc.useOut(fname);

    proc.d_mode |= Proc::COUT;
    proc.d_mode &= ~Proc::IGNORE_COUT;          // see the proc header file

//    proc.showMode(__FILE__);
//    proc.d_mode &= ~(Proc::IGNORE_COUT | Proc::CERR | 
}

} // FBB
