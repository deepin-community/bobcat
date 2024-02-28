#include "proc.ih"

Proc &Proc::setIn(string const &fname)
{
                                            // access the fname file
    d_in = new ifstream{ Exception::factory<ifstream>(fname) };

    d_mode |= Proc::CIN;
    d_admin |= DELETE_D_IN;

    return *this;
}
