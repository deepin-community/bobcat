#include "arg.ih"

vector<string>::const_iterator Arg::end() const
{
    return d_ptr->d_argv.end();
}

