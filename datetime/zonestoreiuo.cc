#include "datetime.ih"

DateTime::Zone const &DateTime::Zone::storeIUO(
                                string const &name, 
                                string const &shift, string const &dstSpec,
                                string const &dstBegin, string const &dstEnd)
{
    Zone *ret = new Zone{ data(name, shift, dstSpec, dstBegin, dstEnd) };

    (*s_zone)[name] = unique_ptr<Zone>{ret};    // store the pointer 
                                                // in the map.
    return *ret;
}
