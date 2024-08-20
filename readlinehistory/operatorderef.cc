#include "readlinehistory.ih"

ReadLineHistory::HistoryElement const
    &ReadLineHistory::const_iterator::operator*() const
{
    return d_elements[d_idx];
}
