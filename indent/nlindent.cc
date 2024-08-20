#include "indent.ih"

ostream &nlindent(ostream &out)
{
    return out << '\n' << indent;
}
