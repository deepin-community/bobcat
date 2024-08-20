#include "proc.ih"

void Proc::cerrAdmin(char const *lab) const
{
    std::cerr << lab << " Admin: ";

    if (d_admin == 0)
        std::cerr << "empty";
    if (d_admin & ACTIVE)
        std::cerr << "ACTIVE ";
    if (d_admin & LOCAL_PIPES)
        std::cerr << "LOCAL_PIPES ";
    if (d_admin & USE_OUT)
        std::cerr << "USE_OUT ";
    if (d_admin & USE_ERR)
        std::cerr << "USE_ERR ";
    if (d_admin & THREAD_OUT)
        std::cerr << "THREAD_OUT ";
    if (d_admin & THREAD_ERR)
        std::cerr << "THREAD_ERR ";

    std::cerr << '\n';
}

