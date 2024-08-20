#include "readlinehistory.ih"

ReadLineHistory::HistoryElement 
        &ReadLineHistory::HistoryElement::operator=(HIST_ENTRY const *element)
{
    d_line = element->line;
    d_timestamp = element->timestamp;

    return *this;
}
