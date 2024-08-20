#include "readlinehistory.ih"

namespace FBB
{

std::ostream &operator<<(std::ostream &out, ReadLineHistory const &history)
{
    void (*insert)(ReadLineHistory::HistoryElement const &he, ostream &out) =
                    history.d_timestamps ? 
                        &ReadLineHistory::insertHistoryElement
                    :
                        &ReadLineHistory::insertLine;

    for (auto &he: history)
        (*insert)(he, out);

    return out;
}

} // FBB
