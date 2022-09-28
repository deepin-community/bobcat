#include "datetime.ih"

DateTime::Zone::Zone(string const &shift, string const &dstSpec,
                      string const &dstBegin, string const &dstEnd)
:
    d_data( data(s_anon, shift, dstSpec, dstBegin, dstEnd) )
{}
