#include "ofoldbuf.ih"

void OFoldBuf::iniBlankTabs(TabsOrBlanks tob)
{
    if (tob == BLANKS)
        useBlanks();
    else
        useTabs();
}
