#include "proc.ih"

Proc::IOMode Proc::setIOMode(IOMode mode)
{
    if (mode & ~IOMODES)
        throw invalid_argument("Undefined IOMode");

    if ((mode & REPLACE) && (mode & ~REPLACE))
        throw invalid_argument("IOModes cannot be combined with REPLACE");

    if ((mode & IGNORE_CERR) && (mode & (CERR | MERGE_COUT_CERR)))
        throw invalid_argument(
                    "IOMode IGNORE_CERR cannot be combined with modes "
                    "CERR or MERGE_COUT_CERR");

    if ((mode & IGNORE_COUT) && (mode & (COUT | MERGE_COUT_CERR)))
        throw invalid_argument(
                    "IOMode IGNORE_COUT cannot be combined with modes "
                    "COUT or MERGE_COUT_CERR");

    if ((mode & MERGE_COUT_CERR) && (mode & (CERR | COUT)))
        throw invalid_argument(
                    "IOMode MERGE_COUT_CERR cannot be combined with modes "
                    "COUT or CERR");

    IOMode ret = d_mode;
    d_mode = mode;
    return ret;
}




