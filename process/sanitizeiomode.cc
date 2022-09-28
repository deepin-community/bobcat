#include "process.ih"

Process::IOMode Process::sanitizeIOMode(IOMode mode)
{
    if (mode & ~ALL_IOMODES)
        throw invalid_argument("Undefined IOMode");

    if ((mode & DIRECT) && (mode & ~DIRECT))
        throw invalid_argument("IOModes cannot be combined with DIRECT");
 
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

    return d_mode = mode;
}
