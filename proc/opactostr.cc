#include "proc.ih"

namespace FBB
{

void operator|(Proc::Activator &&act, ostream &out)
{
    Proc &proc = *act.d_procPtr.back();

    proc.useOut(out);

    proc.d_mode |= Proc::COUT;
    proc.d_mode &= ~Proc::IGNORE_COUT;          // see the proc header file

//    proc.showMode(__FILE__);
//    proc.d_mode &= ~(Proc::IGNORE_COUT | Proc::CERR | 
}

} // FBB
