#include "proc.ih"

void Proc::cerrMode(char const *lab) const
{
    std::cerr << lab << " IOMode: ";

    if (d_mode == NONE)
        std::cerr << "NONE ";
    if (d_mode & CIN)
        std::cerr << "CIN ";
    if (d_mode & COUT)
        std::cerr << "COUT ";
    if (d_mode & CERR)
        std::cerr << "CERR ";
    if (d_mode & IGNORE_COUT)
        std::cerr << "IGNORE_COUT ";
    if (d_mode & IGNORE_CERR)
        std::cerr << "IGNORE_CERR ";
    if (d_mode & MERGE_COUT_CERR)
        std::cerr << "MERGE_COUT_CERR ";
    if (d_mode & REPLACE)
        std::cerr << "REPLACE ";

    std::cerr << '\n';
}
