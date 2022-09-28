#include "arg.ih"

void Arg__::setBasename()
{
    string::size_type idx = d_argv0.rfind(s_dirsep);

    d_base = idx == string::npos ? d_argv0 : d_argv0.substr(idx + 1);
}
