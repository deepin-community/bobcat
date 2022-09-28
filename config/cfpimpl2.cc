#include "config.ih"

CF_Pimpl::CF_Pimpl(istream &stream, uint16_t lineNr, 
                   Casing sType, Comment cType)
:
    CF_Pimpl(sType, cType)
{
    load(stream, lineNr);
}
