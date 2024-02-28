#include "readlinehistory.ih"

istream &ReadLineHistory::extract(istream &in)
{
    if (!in)
        return in;

    clear_history();
    
    if (d_timestamps)
        extractTimestamps(in);
    else
        extractLines(in);

    setElements();

    return in;
}
