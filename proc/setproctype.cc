//#define XERR
#include "proc.ih"

Proc::ProcType Proc::setProcType(ProcType type)
{
    ProcType ret = d_procType;
    d_procType = type;
    return ret;
}
