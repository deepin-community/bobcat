#include "readlinehistory.ih"

ReadLineHistory::ReadLineHistory()
:
    d_timestamps(false),    // maybe reset by instance()
    d_elements(0)   //  new HistoryElement[history_length])
{
    setElements();
}
