#include "arg.ih"

void Arg__::fillLongOptions(OptStruct *optStruct,
                            std::string const &optString,
                            LongOption const * const begin,
                            LongOption const * const end)
{
        // fill all long options, using their own specifications 
        //  (w/wo/opt args) or the specs from optString
    
    for (LongOption const *it = begin; it != end; ++it, ++optStruct)
        addLongOption(optStruct, optString, *it);       // 2.cc
}
