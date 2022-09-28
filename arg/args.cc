#include "arg.ih"

vector<string> const &Arg::args() const
{
    return d_ptr->d_argv;
}
