#include "datetime.ih"

// static
void DateTime::Zone::checkDST(string const &dstSpec,
                               string &dstBegin, string &dstEnd)
try
{
    if (
        (                                   // DST details for std or no DST
            (dstSpec == "=" or dstSpec.empty())
            and
            (dstBegin.length() or dstEnd.length())
        )
        or                                  // or incomplete DST details
            (dstBegin.empty() and not dstEnd.empty())
        or
            (dstEnd.empty() and not dstBegin.empty())
    )
        throw 1;

    if (dstBegin.empty())
        return;

    dstBegin = convert(dstBegin);
    dstEnd = convert(dstEnd);
}
catch (...)
{
    throw Exception{ 1 } << "Zone DST error: `" << dstSpec << "', `" <<
                            dstBegin << "', `" << dstEnd << '\'';
}



