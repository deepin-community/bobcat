#include "readlinehistory.ih"

void ReadLineHistory::setElements()
{
    delete[] d_elements;

    d_elements = new HistoryElement[history_length];

    for (size_t idx = 0, end = history_length; idx != end; ++idx)
        d_elements[idx] = history_list()[idx];
}
