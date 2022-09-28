#include "process.ih"

Process &Process::operator<<(std::ostream &(*pf)(std::ostream &))
{
    if (active())
        static_cast<std::ostream &>(*this) << pf;

    return *this;
}

