#include "level.ih"

std::ostream &level::insertInto(Log &lp) const
{
    return lp.level(d_level);                 // otherwise set the level.
}
