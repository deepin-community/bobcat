#include "datetime.ih"

// static
DateTime::Zone::Data DateTime::Zone::data(string const &name,
                std::string shift, std::string dstSpec,
                std::string dstBegin, std::string dstEnd)
{
                                // an ":Asia/Calcutta" type of specification
    if (shift[0] == ':')        // dst may never be used, but then tm_isdst
        return { shift, zoneSeconds(shift), 3600 };             // remains 0

    if (dstSpec == "=")
        dstSpec = "1";               // use the default of 1 hr.

    checkDST(dstSpec, dstBegin, dstEnd);

    negate(shift);                      // if specified then [0] is + or -

    string dstName;                     //  -> dstSpec + d

    bool useDST = not dstSpec.empty();  
    if (useDST)                         // dst was specified
    {
        dstName = name;                 // append d, if needed also >
        if (dstName.back() != '>')
            dstName += 'd';
        else
            dstName.replace((dstName.rbegin() + 1).base(), dstName.end(), 
                            "d>");
    }

    int dstSeconds;
    if (dstSpec.empty())                // set the DST seconds
        dstSeconds = 3600;
    else
    {
        negate(dstSpec);
        dstSeconds = add(dstSpec, shift);
    }

                                        // and the spec. (no DST section if
    shift  =  name + shift +            // not specified)
                (useDST ? dstName + dstSpec : "") +
                dstBegin + dstEnd;

    return { shift, zoneSeconds(shift), dstSeconds };
}




