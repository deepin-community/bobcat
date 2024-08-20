#include "log.ih"

namespace FBB
{
    Log &operator<<(Log &log, ios_base &(*fun)(ios_base &base))
    {
        if (log.d_active->levelOK or log.d_active->opfunOK)
            static_cast<std::ostream &>(log) << fun;

        return log;
    }
}


