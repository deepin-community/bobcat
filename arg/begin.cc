#include "arg.ih"

vector<string>::const_iterator Arg::begin() const
{
    return d_ptr->d_argv.begin();
}
