#include "readlinehistory.ih"

ReadLineHistory &ReadLineHistory::instance(bool useTimestamps)
{
    s_readLineHistory.reset(new ReadLineHistory);
    s_readLineHistory->setTimestampsIO(useTimestamps);

    return *s_readLineHistory;
}
