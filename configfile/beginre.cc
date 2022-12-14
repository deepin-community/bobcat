#include "configfile.ih"

ConfigFile_::const_RE_iterator ConfigFile_::beginRE(string const &re)
{
    if (re != d_re)
        resetVsIter(re);

    return RE_iterator(d_vsIter, 0);
}
