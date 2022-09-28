#include "config.ih"

CF_Pimpl::CF_Pimpl(Casing sType, Comment cType)
:
    d_rmComment(cType == NoComment)
{
    setCasing(sType);
}
