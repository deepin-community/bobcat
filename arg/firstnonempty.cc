#include "arg.ih"

size_t Arg__::firstNonEmpty(size_t *idx, string *value,
                            StringVector const &sv) const
{
    StringVector::const_iterator sit =
        find_if(sv.begin(), sv.end(),
            [&](string const &str)
            {                       // bind2nd(not_equal_to<string>(), ""));
                return not str.empty();
            }
        );

    if (sit == sv.end())
        *idx = sv.size();
    else
    {
        *idx = sit - sv.begin();
        if (value != 0)
            *value = *sit;
    }

    return sv.size();
}
